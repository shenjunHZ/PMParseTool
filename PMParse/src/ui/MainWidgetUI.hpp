#pragma once
#include <QtWidgets/QDialog>
#include <QtGui/QMouseEvent>

namespace Ui
{
    class MainWidgetUI;
} // namespace Ui

namespace ui
{
class MainWidgetUI : public QDialog
{
    Q_OBJECT

public:
    MainWidgetUI(QWidget *parent = Q_NULLPTR);
    ~MainWidgetUI() = default;

    void initUI();

private:
    void initConnect();
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void moveEvent(QMoveEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);

private slots:
    void onBtnQuit();
    void onStatistic();
    void onDatas();

private:
    std::unique_ptr<Ui::MainWidgetUI> ui_{ nullptr };
    QPoint mousePos_;
    bool mousePressed_{ false };
    bool maxNormal_{ false };

};
} // namespace ui
