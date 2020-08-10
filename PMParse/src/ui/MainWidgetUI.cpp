#include <QtWidgets/QDesktopWidget>
#include "ui/MainWidgetUI.hpp"
#include "GeneratedFiles/ui_MainWidgetUI.hpp"
#include "config/commonControl.hpp"

namespace ui
{
    MainWidgetUI::MainWidgetUI(QWidget *parent /*= Q_NULLPTR*/)
        : QDialog(parent, Qt::FramelessWindowHint)
    {
        ui_.reset(new Ui::MainWidgetUI);
        ui_->setupUi(this);

        setWindowFlags(Qt::Window | Qt::FramelessWindowHint | 
            Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
        SET_MODULE_STYLE_BY_PATH("MainWidgetUI");
    }

    void MainWidgetUI::initUI()
    {
        setAttribute(Qt::WA_DeleteOnClose, false);
        setAttribute(Qt::WA_TranslucentBackground, true);
        // move to middle of the desktop
        QDesktopWidget* pDeskWidget = QApplication::desktop();
        int iScreen = pDeskWidget->primaryScreen();
        QWidget* pPrimaryScreen = pDeskWidget->screen(iScreen);

        int iWidth = pPrimaryScreen->width();
        int iHeight = pPrimaryScreen->height();
        this->move((iWidth - width()) / 2, (iHeight - height()) / 2);
        QString oemAppname = "PM Parser Tool";
        this->setWindowTitle(oemAppname);

        ui_->stackedWidget->setCurrentWidget(ui_->parsePage);
        ui_->mainBg->installEventFilter(this);
        ui_->mainBg->setFocus();
        this->setModal(true);
        this->activateWindow();
        initConnect();
    }

    void MainWidgetUI::initConnect()
    {
        connect(ui_->btnQuit,   SIGNAL(clicked()),        this, SLOT(onBtnQuit()));
        connect(ui_->parsePage, SIGNAL(sgnalStatistic()), this, SLOT(onStatistic()));
        connect(ui_->showPage,  SIGNAL(sgnalDatas()),     this, SLOT(onDatas()));
        connect(ui_->parsePage, SIGNAL(sgnalDatasChange(const App::IDataManagement&)), ui_->showPage, SLOT(onDatasChange(const App::IDataManagement&)));
    }

    void MainWidgetUI::onBtnQuit()
    {
        this->accept();
    }

    void MainWidgetUI::onStatistic()
    {
        ui_->stackedWidget->setCurrentWidget(ui_->showPage);
        ui_->showPage->staticsShow();
    }

    void MainWidgetUI::onDatas()
    {
        ui_->stackedWidget->setCurrentWidget(ui_->parsePage);
    }

    bool MainWidgetUI::eventFilter(QObject *obj, QEvent *event)
    {
        if (obj == ui_->mainBg)
        {
            if (event->type() == QEvent::MouseButtonPress)
            {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                if (mouseEvent->button() == Qt::LeftButton)
                {
                    mousePos_ = mouseEvent->globalPos();
                    mousePressed_ = true;
                    return true;
                }
            }
            else if (event->type() == QEvent::MouseMove)
            {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                if ((mouseEvent->buttons() & Qt::LeftButton) && mousePressed_)
                {
                    int xDis = mouseEvent->globalPos().x() - mousePos_.x();
                    int yDis = mouseEvent->globalPos().y() - mousePos_.y();
                    mousePos_ = mouseEvent->globalPos();
                    QPoint pos = mapToGlobal(QPoint(0, 0));
                    move(pos.x() + xDis, pos.y() + yDis);
                    return true;
                }
            }
            else if (event->type() == QEvent::MouseButtonRelease)
            {
                if (mousePressed_)
                {
                    ui_->mainBg->setFocus();
                }
                mousePressed_ = false;

                QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
                if (mouseEvent->button() == Qt::LeftButton)
                {
                    return true;
                }
            }
        }

        return QDialog::eventFilter(obj, event);
    }

    void MainWidgetUI::moveEvent(QMoveEvent *event)
    {
        const int margin = 20;
        QPoint pt = event->pos();
        QRect rtWnd = QApplication::desktop()->availableGeometry(pt);
        if (pt.x() + this->width() <= margin)
        {
            pt = QPoint(-this->width() + margin, pt.y());
        }
        if (pt.x() > rtWnd.right() - margin)
        {
            pt = QPoint(rtWnd.right() - margin, pt.y());
        }
        if (pt.y() + this->height() <= margin)
        {
            pt = QPoint(pt.x(), -this->height() + margin);
        }
        if (pt.y() > rtWnd.bottom() - margin)
        {
            pt = QPoint(pt.x(), rtWnd.bottom() - margin);
        }
        move(pt);
    }

    void MainWidgetUI::mouseDoubleClickEvent(QMouseEvent* event)
    {
        if (event->button() == Qt::LeftButton)
        {
            if (maxNormal_)
            {
                this->showNormal();
                maxNormal_ = !maxNormal_;
            }
            else
            {
                this->showMaximized();
                maxNormal_ = !maxNormal_;

            }
        }
    }

} // namespace ui