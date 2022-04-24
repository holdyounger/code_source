#include "widget.h"
#include "ui_widget.h"

#include <QLatin1String>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFileInfo info(":/Win11.png");

    List2Print = new QStringList;
    List2Print->append("1");
    List2Print->append("2");
    List2Print->append("3");
    List2Print->append("4");


    QPixmap img(":/Win11");

    ui->label->setPixmap(img);
    ui->label->setScaledContents(true);


    ui->label->setToolTip(QString("壁纸《Win11.png》"));
    ui->pushButton->setToolTip(QString("隐藏或显示图片"));

    QIcon icon = QApplication::style()->standardIcon((QStyle::StandardPixmap)0);
    QIcon icon1 = QApplication::style()->standardIcon((QStyle::StandardPixmap)9);


    //设置通知栏的图标
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);

    //设置通知栏的单击事件
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(stTrayIconActive(QSystemTrayIcon::ActivationReason)));

    //设置通知栏的右键菜单
    QMenu * menu = new QMenu();
    //设置菜单项目

    QAction *actionHide = new QAction(icon, "Hide", menu);

    menu->addAction(actionHide);
    trayIcon->setContextMenu(menu);
    // 设置Action的响应
    connect(actionHide, SIGNAL(triggered()), this, SLOT(stActionHide()));
    trayIcon->show();

    //托盘的消息提示
    trayIcon->showMessage("title", "this is a message", icon1);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::stTrayIconActive(QSystemTrayIcon::ActivationReason acReason)
{
    switch (acReason)
    {
    case QSystemTrayIcon::Trigger:
    {
        showNormal();
        break;
    }
    default:
        ;
    }

}
void Widget::on_pushButton_clicked()
{
    QIcon icon = QApplication::style()->standardIcon((QStyle::StandardPixmap)0);
    QIcon icon1 = QApplication::style()->standardIcon((QStyle::StandardPixmap)9);

    if(ui->label->isVisible())
    {
        trayIcon->showMessage("提醒", "隐藏图片", icon1);
        ui->label->hide();
    }
    else
    {
        trayIcon->showMessage("提醒", "显示图片", icon1);
        ui->label->setVisible(true);
    }

    QTimer *timer = new QTimer;
    timer->start(1000);

    int i = List2Print->length() - 1;
    connect(timer, &QTimer::timeout, this, [=]() mutable {
      qDebug() << List2Print->at(i--) << endl;
      if(i < 0)
          i = List2Print->length() - 1;
    });
    //timer->deleteLater();
}

