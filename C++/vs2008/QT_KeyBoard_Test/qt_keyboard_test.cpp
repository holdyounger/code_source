#include "qt_keyboard_test.h"

QT_KeyBoard_Test::QT_KeyBoard_Test(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	ui.lineEdit_2->setEchoMode(QLineEdit::NoEcho);
	ui.lineEdit_3->setEchoMode(QLineEdit::Password);

	ui.lineEdit_2->installEventFilter(this);
	connect(ui.lineEdit, SIGNAL(selectionChanged()), this, SLOT(slot_call_osk()));
}

QT_KeyBoard_Test::~QT_KeyBoard_Test()
{
	
}

void QT_KeyBoard_Test::slot_call_osk()
{
	
		//win8.1   win10 ��ʹ��
		PVOID OldValue = NULL;
		bool bRet = Wow64DisableWow64FsRedirection(&OldValue);
		QString csProcess = "C:\\Windows\\System32\\osk.exe";
		QString params="";
		ShellExecute(NULL, L"open", (LPCWSTR)csProcess.utf16(), (LPCWSTR)params.utf16(), NULL, SW_SHOWNORMAL);
		if (bRet)
		{
			Wow64RevertWow64FsRedirection(OldValue);
		}
}

bool QT_KeyBoard_Test::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type()==QEvent::MouseButtonPress)     //Ȼ�����жϿؼ��ľ����¼� (����ָ��ý����¼�)
	{
		QMouseEvent *me = (QMouseEvent*)event;
		if(me->button() == Qt::LeftButton )
		{
				//win8.1   win10 ��ʹ��
				PVOID OldValue = NULL;
				bool bRet = Wow64DisableWow64FsRedirection(&OldValue);
				QString csProcess = "C:\\Windows\\System32\\osk.exe";
				QString params="";
				ShellExecute(NULL, L"open", (LPCWSTR)csProcess.utf16(), (LPCWSTR)params.utf16(), NULL, SW_SHOWNORMAL);
				if (bRet)
				{
					Wow64RevertWow64FsRedirection(OldValue);
				}
		}

	}
	return QWidget::eventFilter(obj,event);     // ����¼������ϲ�Ի���
}
