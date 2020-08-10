#pragma once
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtGui/QMovie>
#include <QtCore/QTimer>

namespace ui
{
class WaitingWidget : public QDialog
{
    Q_OBJECT

public:
    WaitingWidget(QWidget *parent = Q_NULLPTR);
    ~WaitingWidget();

    void startWaiting();
    void stopWaiting();
    void setTimeout(int time);

private:
    void initWidget();

private slots:
    void onTimeout();

private:
    std::unique_ptr<QLabel> label_{ nullptr };
    std::unique_ptr<QMovie> movie_{ nullptr };
    std::unique_ptr<QTimer> timer_{ nullptr };
    int secTime_{0};
};
} // namespace ui