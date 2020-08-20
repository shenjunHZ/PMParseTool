#include <QtWidgets/QFileDialog>
#include "ui/PMParseUI.hpp"
#include "ui/WaitingWidget.hpp"
#include "GeneratedFiles/ui_PMParseUI.hpp"
#include "config/commonControl.hpp"
#include "App/DataManagement.hpp"

namespace
{
constexpr int TIMEOUT_WIDGET = 1 * 60 * 60;
} // namespace
namespace ui
{
PMParseUI::PMParseUI(QWidget *parent /*= Q_NULLPTR*/)
    : QWidget(parent, Qt::FramelessWindowHint)
    , waitingWidget_{ std::make_unique<WaitingWidget>(this) }
{
    initDialog();
    initConnect();
    waitingWidget_->setTimeout(TIMEOUT_WIDGET);

    SET_MODULE_STYLE_BY_PATH("PMParseUI");
}

void PMParseUI::initUI()
{
    ui_->comboBox->clear();
}

void PMParseUI::initDialog()
{
    ui_.reset(new Ui::PMParseUI);
    ui_->setupUi(this);

    m_msgLabel = ui_->msgLabel;
    m_msgLabel->setObjectName("msgLabel");
    m_msgLabel->hide();
    ui_->statisticsBtn->setDisabled(true);
    ui_->readBtn->setDisabled(true);
}

void PMParseUI::initConnect()
{
    connect(ui_->selectBtn,     SIGNAL(clicked()), this, SLOT(onSelectDir()));
    connect(ui_->clearBtn,      SIGNAL(clicked()), this, SLOT(onClearDir()));
    connect(ui_->readBtn,       SIGNAL(clicked()), this, SLOT(onReadData()));
    connect(this,               SIGNAL(sgnParseDatas()), this, SLOT(onParseDatas()));
    connect(ui_->statisticsBtn, SIGNAL(clicked()), this, SLOT(onStatisticWidget()));
}

void PMParseUI::onSelectDir()
{
    QString directory = "";
    if (lastPath_.empty())
    {
        directory = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("PM Data Path"), QDir::currentPath()));
    }
    else
    {
        directory = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("PM Data Path"), QString::fromStdString(lastPath_)));
    }
    if (! directory.isEmpty() && -1 == ui_->comboBox->findText(directory))
    {
        ui_->comboBox->addItem(directory);
        ui_->comboBox->setCurrentIndex(ui_->comboBox->findText(directory));
        lastPath_ = directory.toStdString();
        ui_->statisticsBtn->setDisabled(true);
        ui_->readBtn->setDisabled(false);
    }
}

void PMParseUI::onClearDir()
{
    ui_->comboBox->clear();
    ui_->statisticsBtn->setDisabled(true);
}

void PMParseUI::onReadData()
{
    parseThread_ = std::make_unique<std::thread>( [this]()
        {
            QString currentDir = ui_->comboBox->currentText();
            dataManagement_ = std::make_unique<App::DataManagement>(currentDir.toStdString());
            emit sgnParseDatas();
            ui_->statisticsBtn->setDisabled(false);
        });

    int x = (this->width() - waitingWidget_->width()) / 2;
    int y = (this->height() - waitingWidget_->height()) / 2;
    waitingWidget_->move(x, y);
    waitingWidget_->startWaiting();
}

void PMParseUI::onStatisticWidget()
{
    emit sgnalStatistic();
}

void PMParseUI::onParseDatas()
{
    emit sgnalDatasChange(*dataManagement_);
    if(parseThread_->joinable())
    {
        parseThread_->join();
    }

    waitingWidget_->stopWaiting();
}

void PMParseUI::setErrorMsg(const QString& tipMsg)
{
    m_msgLabel->setText(tipMsg);
    if (tipMsg.isEmpty())
    {
        m_msgLabel->hide();
    }
    else
    {
        m_msgLabel->setText(tipMsg);
        m_msgLabel->show();
    }
}

void PMParseUI::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        if (parseThread_ && parseThread_->joinable())
        {
            parseThread_.reset();
        }
        waitingWidget_->stopWaiting();
        ui_->readBtn->setDisabled(false);
        return;
    }
    QWidget::keyPressEvent(event);
}

} // namespace ui