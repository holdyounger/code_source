#ifndef QT_ENTERKEY_H
#define QT_ENTERKEY_H

#include <QtGui/QMainWindow>
#include "ui_qt_enterkey.h"
#include <QLabel>
class qt_EnterKey : public QMainWindow
{
	Q_OBJECT

public:
	qt_EnterKey(QWidget *parent = 0, Qt::WFlags flags = 0);
	~qt_EnterKey();
	void initTreeWidget();

private:
	Ui::qt_EnterKeyClass ui;
};

#endif // QT_ENTERKEY_H
