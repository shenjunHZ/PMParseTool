#include <QtGui/QPixmap>
#include <QtGui/QBitmap>
#include "ui/WaitingWidget.hpp"

namespace
{
const std::string LOADING_GIF = "./skin/DustyBlue/WaitingWidget/loading.gif";
} // namespace 

namespace ui
{

    WaitingWidget::WaitingWidget(QWidget *parent /*= Q_NULLPTR*/)
        : QDialog(parent)
    {
        initWidget();
    }

    WaitingWidget::~WaitingWidget()
    {
        timer_->stop();
    }

    void WaitingWidget::startWaiting()
    {
        label_->setGeometry(this->rect());
        label_->show();
        movie_->start();

        if (secTime_ > 0)
        {
            timer_->start(secTime_ * 1000);
        }
        setAttribute(Qt::WA_Moved, false);
        exec();
    }

    void WaitingWidget::stopWaiting()
    {
        movie_->stop();
        label_->hide();

        timer_->stop();
        close();
    }

    void WaitingWidget::setTimeout(int time)
    {
        secTime_ = time;
    }

    void WaitingWidget::initWidget()
    {
        label_ = std::make_unique<QLabel>(this);
        movie_ = std::make_unique<QMovie>(LOADING_GIF.c_str());
        timer_ = std::make_unique<QTimer>(this);
        connect(timer_.get(), SIGNAL(timeout()), this, SLOT(onTimeout()));

        QPixmap bkImg(LOADING_GIF.c_str());
        this->setMinimumSize(bkImg.size());
        this->setMaximumSize(bkImg.size());

        QPixmap p(LOADING_GIF.c_str(), "gif");
        this->setMask(p.mask());

        label_->setMovie(movie_.get());
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    }

    void WaitingWidget::onTimeout()
    {
        stopWaiting();
    }

} // namespace ui