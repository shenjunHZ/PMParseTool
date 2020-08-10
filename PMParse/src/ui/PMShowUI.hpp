#pragma once
#include <QtWidgets/QDialog>
#include <boost/optional.hpp>

namespace algorithm
{
class IShowCountersAlgorithm;
} // namespace algorithm
namespace App
{
class IDataManagement;
} // namespace App
namespace Ui
{
class PMShowUI;
} // namespace Ui
namespace QtCharts
{
class QLineSeries;
class QChart;
class QValueAxis;
class QDateTimeAxis;
} // namespace QtCharts

namespace ui
{
class PMShowUI : public QDialog
{
    Q_OBJECT

public:
    PMShowUI(QWidget *parent = Q_NULLPTR);
    ~PMShowUI() = default;

    void staticsShow();

private:
    void initDialog();
    void initConnect();
    void initChart();

private slots:
    void onUnitComboBoxChanged(const QString& unitId);
    void onPmParseDataChanged();
    void onStatisticsShow();
    void onDatasWidget();
    void onDatasChange(const App::IDataManagement& datas);

signals:
    void sgnalDatas();

private:
    std::unique_ptr<algorithm::IShowCountersAlgorithm> counterAlgorithm_;
    std::unique_ptr<Ui::PMShowUI> ui_{ nullptr };
    std::unique_ptr<QtCharts::QLineSeries> series_{ nullptr };
    std::unique_ptr<QtCharts::QChart> chart_{ nullptr };
    boost::optional<const App::IDataManagement&> datas_{boost::none};
    std::unique_ptr<QtCharts::QValueAxis> axisY_{ nullptr };
    std::unique_ptr<QtCharts::QDateTimeAxis> axisX_{ nullptr };
};
} // namespace ui
