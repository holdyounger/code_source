#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>
#include <QAction>
#include <QFileInfo>
#include <QStringList>
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public:
    QSystemTrayIcon *trayIcon;
private slots:
    void stTrayIconActive(QSystemTrayIcon::ActivationReason acReason);
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

private:
    QStringList *List2Print;
};
#endif // WIDGET_H
