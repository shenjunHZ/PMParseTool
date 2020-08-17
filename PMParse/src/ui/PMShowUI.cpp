#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QDateTimeAxis>
#include <QDateTime>
#include <QtWidgets/QCompleter>
#include <QStringList>
#include "ui/PMShowUI.hpp"
#include "GeneratedFiles/ui_PMShowUI.hpp"
#include "App/DataManagement.hpp"
#include "common/PmDatas.hpp"
#include "algorithm/ShowCountersAlgorithm.hpp"
#include "config/commonControl.hpp"

namespace
{
constexpr int FIRST_ITEM = 0;
} // namespace
namespace ui
{
    PMShowUI::PMShowUI(QWidget *parent /*= Q_NULLPTR*/)
        : QDialog(parent, Qt::FramelessWindowHint)
    {
        initDialog();
        initConnect();
        SET_MODULE_STYLE_BY_PATH("PMShowUI");
    }

    void PMShowUI::staticsShow()
    {
        onStatisticsShow();
    }

    void PMShowUI::initDialog()
    {
        ui_.reset(new Ui::PMShowUI);
        ui_->setupUi(this);
        this->setModal(true);
        this->activateWindow();

        initChart();
    }

    void PMShowUI::initChart()
    {
        series_ = std::make_unique<QtCharts::QLineSeries>();
        //series_->setUseOpenGL(true);
        series_->setPen(QPen(Qt::yellow, 1, Qt::SolidLine));
        series_->setVisible(true);
        series_->setPointsVisible(true);
        series_->setPointLabelsVisible(true);
        series_->setPointLabelsClipping(false);
        series_->setPointLabelsFormat(QStringLiteral("(@yPoint)"));
 
        seriesB_ = std::make_unique<QtCharts::QLineSeries>();
        seriesB_->setPen(QPen(Qt::blue, 1, Qt::SolidLine));
        seriesB_->setVisible(true);
        seriesB_->setPointsVisible(true);
        seriesB_->setPointLabelsVisible(true);
        seriesB_->setPointLabelsClipping(false);
        seriesB_->setPointLabelsFormat(QStringLiteral("(@yPoint)"));

        chart_ = std::make_unique<QtCharts::QChart>();
        chart_->legend()->hide();
        chart_->setAnimationOptions(QtCharts::QChart::SeriesAnimations);
        chart_->setTheme(QtCharts::QChart::ChartThemeDark);

        axisY_ = std::make_unique<QtCharts::QValueAxis>();
        axisY_->setTitleText("Counter Value");
        axisY_->setGridLineVisible(true);
        axisY_->setTickCount(8);

        axisX_ = std::make_unique<QtCharts::QDateTimeAxis>();
        axisX_->setFormat("yyyy-M-d HH::mm::ss");
        axisX_->setLabelsAngle(60);
        axisX_->setTitleText("Report Time");
        axisX_->setTickCount(12);
        //chart_->createDefaultAxes();

        // chart should add axis before series attach axis
        chart_->addAxis(axisY_.get(), Qt::AlignLeft);
        chart_->addAxis(axisX_.get(), Qt::AlignBottom);
        chart_->addSeries(series_.get());
        series_->attachAxis(axisY_.get());
        series_->attachAxis(axisX_.get());
        chart_->addSeries(seriesB_.get());
        seriesB_->attachAxis(axisY_.get());
        seriesB_->attachAxis(axisX_.get());

        ui_->counterView->setChart(chart_.get());
        ui_->counterView->setRenderHint(QPainter::Antialiasing);
        ui_->counterView->setRubberBand(QtCharts::QChartView::HorizontalRubberBand);
    }

    void PMShowUI::initConnect()
    {
        connect(ui_->unitComboBox,   SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onUnitComboBoxChanged(const QString &)));
        connect(ui_->statisticsBtn,  SIGNAL(clicked()),                            this, SLOT(onStatisticsShow()));
        connect(ui_->statisticsBtnB, SIGNAL(clicked()),                            this, SLOT(onStatisticsShowB()));
        connect(ui_->dataBtn,        SIGNAL(clicked()),                            this, SLOT(onDatasWidget()));
    }

    void PMShowUI::onUnitComboBoxChanged(const QString& unitId)
    {
        ui_->counterComboBox->clear();
        ui_->counterComboBoxB->clear();
        if (! datas_)
        {
            return;
        }
        const auto& pmDatas = datas_->getPmDatas();
        const auto& targets = pmDatas.getPmTarget(unitId.toStdString());
//         QCompleter *unitCompleter = new QCompleter(ui_->unitComboBox->model(), this);
//         ui_->unitComboBox->setCompleter(unitCompleter);
        if (targets.size() < 1)
        {
            return;
        }
        for (const auto& target : targets)
        {
            for (const auto& counter : target.counters)
            {
                ui_->counterComboBox->addItem(QString::fromStdString(counter.first));
                ui_->counterComboBoxB->addItem(QString::fromStdString(counter.first));
            }
        }
        ui_->counterComboBox->setCurrentIndex(FIRST_ITEM);
        QCompleter *counterCompleter = new QCompleter(ui_->counterComboBox->model(), this);
        ui_->counterComboBox->setCompleter(counterCompleter);

        ui_->counterComboBoxB->setCurrentIndex(FIRST_ITEM);
        QCompleter *counterCompleterB = new QCompleter(ui_->counterComboBoxB->model(), this);
        ui_->counterComboBoxB->setCompleter(counterCompleterB);
    }

    void PMShowUI::onStatisticsShow()
    {
        const std::string unitId = ui_->unitComboBox->currentText().toStdString();
        const std::string counter = ui_->counterComboBox->currentText().toStdString();
        series_->removePoints(0, series_->count());
        std::string title = "PM Counter: " + counter;
        chart_->setTitle(QString::fromStdString(title));

        if (counterAlgorithm_)
        {
            const auto& counterValues = counterAlgorithm_->getCounterValues(unitId, counter);
            if ( counterValues.size() > 0 )
            {
                uint timeMin = 0xffffffff;
                uint timeMax = 0;
                uint valueMin = 0;
                uint valueMax = 10;
                for (const auto& counterValue : counterValues)
                {
                    std::string strTime = "";
                    std::size_t posT = counterValue.first.find('T');
                    if (std::string::npos != posT)
                    {
                        strTime = counterValue.first.substr(0, posT);
                        strTime += " ";
                    }
                    std::size_t posZ = counterValue.first.find('.');
                    strTime += counterValue.first.substr(posT + 1, posZ - posT - 1);
                    QDateTime dataTime = QDateTime::fromString(QString::fromStdString(strTime), "yyyy-MM-dd hh:mm:ss");

                    if (dataTime.toTime_t() < timeMin)
                    {
                        timeMin = dataTime.toTime_t();
                        axisX_->setMin(QDateTime::fromTime_t(timeMin));
                    }
                    if (dataTime.toTime_t() > timeMax)
                    {
                        timeMax = dataTime.toTime_t();
                        if (timeMax == timeMin)
                        {
                            timeMax += 1;
                        }
                        axisX_->setMax(QDateTime::fromTime_t(timeMax));
                    }

                    axisY_->setMax(valueMax);
                    axisY_->setMin(valueMin);
                    uint value = QString::fromStdString(counterValue.second).toInt();
                    if (value > valueMax)
                    {
                        axisY_->setMax(value + 1);
                        valueMax = value;
                    }
                    series_->append(dataTime.toMSecsSinceEpoch(), value);
                }
                series_->show();
            }
        }
    }

    void PMShowUI::onStatisticsShowB()
    {
        const std::string unitId = ui_->unitComboBox->currentText().toStdString();
        const std::string counter = ui_->counterComboBoxB->currentText().toStdString();
        seriesB_->removePoints(0, seriesB_->count());
        std::string title = "PM Counter: " + counter;

        if (counterAlgorithm_)
        {
            const auto& counterValues = counterAlgorithm_->getCounterValues(unitId, counter);
            if (counterValues.size() > 0)
            {
                uint valueMin = 0;
                uint valueMax = 10;
                for (const auto& counterValue : counterValues)
                {
                    std::string strTime = "";
                    std::size_t posT = counterValue.first.find('T');
                    if (std::string::npos != posT)
                    {
                        strTime = counterValue.first.substr(0, posT);
                        strTime += " ";
                    }
                    std::size_t posZ = counterValue.first.find('.');
                    strTime += counterValue.first.substr(posT + 1, posZ - posT - 1);
                    QDateTime dataTime = QDateTime::fromString(QString::fromStdString(strTime), "yyyy-MM-dd hh:mm:ss");

                    axisY_->setMax(valueMax);
                    axisY_->setMin(valueMin);
                    uint value = QString::fromStdString(counterValue.second).toInt();
                    if (value > valueMax)
                    {
                        axisY_->setMax(value + 1);
                        valueMax = value;
                    }
                    seriesB_->append(dataTime.toMSecsSinceEpoch(), value);
                }
                seriesB_->show();
                series_->show();
            }
        }
    }

    void PMShowUI::onDatasWidget()
    {
        emit sgnalDatas();
    }

    void PMShowUI::onDatasChange(const App::IDataManagement& datas)
    {
        ui_->counterComboBox->clear();
        ui_->unitComboBox->clear();
        datas_ = datas;
        const auto& pmDatas = datas.getPmDatas();
        const auto& unitIds = pmDatas.getAllPmTargetUnits();
        for (const auto& unitId : unitIds)
        {
            ui_->unitComboBox->addItem(QString::fromStdString(unitId));
        }
        ui_->unitComboBox->setCurrentIndex(FIRST_ITEM);
        QCompleter *unitCompleter = new QCompleter(ui_->unitComboBox->model(), this);
        ui_->unitComboBox->setCompleter(unitCompleter);
        counterAlgorithm_ = std::make_unique<algorithm::ShowCountersAlgorithm>(datas);
    }

} // namespace ui