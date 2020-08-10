#pragma once
#include <memory>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

namespace Ui
{
class PMParseUI;
} // namespace Ui
namespace App
{
class IDataManagement;
} // namespace FileRead
namespace DSGUI
{
class DSWaitDialog;
} // namespace DSGUI

namespace ui
{
class WaitingWidget;
class PMParseUI : public QWidget
{
    Q_OBJECT

public:
    PMParseUI(QWidget *parent = Q_NULLPTR);
    ~PMParseUI() = default;

    void initUI();

private:
    void initDialog();
    void initConnect();
    void setErrorMsg(const QString& tipMsg);

private slots:
    void onSelectDir();
    void onClearDir();
    void onReadData();
    void onStatisticWidget();

signals:
    void sgnalStatistic();
    void sgnalDatasChange(const App::IDataManagement& datas);

private:
    std::unique_ptr<Ui::PMParseUI> ui_{ nullptr };
    std::unique_ptr<App::IDataManagement> dataManagement_{ nullptr };
    std::unique_ptr<WaitingWidget> waitingWidget_{ nullptr };
    QLabel* m_msgLabel{ nullptr };
    std::string lastPath_;
};

} // namespace ui
