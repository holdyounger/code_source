#ifndef QT_KEYBOARD_TEST_H
#define QT_KEYBOARD_TEST_H

#include <QtGui/QMainWindow>
#include <QDebug>
#include <QLineEdit>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>
#include <QDialog>
#include <Windows.h>

#include "ui_qt_keyboard_test.h"

class QT_KeyBoard_Test : public QMainWindow
{
	Q_OBJECT

public:
	QT_KeyBoard_Test(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QT_KeyBoard_Test();

public slots:
	void slot_call_osk();

private:
	Ui::QT_KeyBoard_TestClass ui;
	bool eventFilter(QObject *,QEvent *);    //注意这里软件盘相关

};

#endif // QT_KEYBOARD_TEST_H
