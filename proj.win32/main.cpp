#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;
#if 0
int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("q-test");
    eglView->setFrameSize(480, 320);
    return CCApplication::sharedApplication()->run(true);
}
#else
#include "main.h"

#include "../Classes/AppDelegate.h"
#include "../Classes/JsonX.h"
#include <QtWidgets\QApplication>
#include <QtCore/QTextCodec>
#include "UI/mainwindow.h"

USING_NS_CC;

QString qss = "QToolButton:pressed{background-color: #800000;} QToolButton:released{background-color: #008000;}";

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR    lpCmdLine,
	int       nCmdShow)
	//int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(editor);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));

	int argc = 1; char **argv = NULL;
	QApplication app(argc, argv);
	app.setOrganizationName("QtProject");
	app.setApplicationName("SceneEditor by xiaok");//"Application Example");
	MainWindow mainWin;
	mainWin.show();

	QFile f("vstyle.qss"); f.open(QFile::ReadOnly);
	app.setStyleSheet(f.readAll());

	return app.exec(); 
} 

#endif