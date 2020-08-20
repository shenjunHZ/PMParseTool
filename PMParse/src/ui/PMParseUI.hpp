#pragma once
#include <memory>
#include <thread>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtGui/QKeyEvent>

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
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void onSelectDir();
    void onClearDir();
    void onReadData();
    void onStatisticWidget();
    void onParseDatas();

signals:
    void sgnalStatistic();
    void sgnalDatasChange(const App::IDataManagement& datas);
    void sgnParseDatas();

private:
    std::unique_ptr<Ui::PMParseUI> ui_{ nullptr };
    std::unique_ptr<App::IDataManagement> dataManagement_{ nullptr };
    std::unique_ptr<WaitingWidget> waitingWidget_{ nullptr };
    QLabel* m_msgLabel{ nullptr };
    std::string lastPath_;
    std::unique_ptr<std::thread> parseThread_{ nullptr };
};

} // namespace ui
