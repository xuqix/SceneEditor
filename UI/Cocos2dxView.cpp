#include "Cocos2dxView.h"
#include <QtWidgets\QtWidgets>
#include <QtWidgets\QScrollArea>

USING_NS_CC;

//for cocos2dx3.0
//#define GLFW_EXPOSE_NATIVE_WIN32
//#define GLFW_EXPOSE_NATIVE_WGL
//#include "glfw3\include\win32\glfw3native.h"

Cocos2dxView::~Cocos2dxView()
{
	killTimer(m_timer->timerId());
	CCDirector::sharedDirector()->end();
	CCDirector::sharedDirector()->mainLoop();
}

Cocos2dxView::Cocos2dxView(QWidget *parent) : QWidget(parent)
{
	initCocos2dx();
	return;
}

void Cocos2dxView::initCocos2dx()
{
	HWND hwnd = (HWND)this->winId();
	
	CCEGLView *eglView = CCEGLView::sharedOpenGLView(hwnd);
	eglView->setViewName("cocos2dx_view");
	eglView->setFrameSize(defaultSizeX, defaultSizeY);
	this->setGeometry(0, 0, defaultSizeX, defaultSizeY);

	CCApplication::sharedApplication()->run(false);
	
	m_timer = new QTimer(this); 
	connect(m_timer, SIGNAL(timeout()), this, SLOT(renderCocos2dx()));
	m_timer->start();
}

void Cocos2dxView::setViewGeometry(const QRect &rect)
{
	setGeometry(rect);
	CCEGLView::sharedOpenGLView()->setFrameSize(rect.width(), rect.height());
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(rect.width(), rect.height(), kResolutionShowAll);
}

void Cocos2dxView::renderCocos2dx()
{
	CCApplication::sharedApplication()->renderWorld();
}

void Cocos2dxView::mousePressEvent(QMouseEvent *event) 
{
	CCLOG("begin");
	QPointF	pos = event->localPos();
	//CCLOG("%lf %lf", pos.rx(), pos.ry());
	//组装windows消息
	UINT message  = WM_LBUTTONDOWN;
	WPARAM wparam = MK_LBUTTON;
	LPARAM lparam = MAKELPARAM(pos.rx(), pos.ry());
	CCEGLView::sharedOpenGLView()->WindowProc(message, wparam, lparam);
}

void Cocos2dxView::mouseMoveEvent(QMouseEvent *event) 
{
	CCLOG("move");
	QPointF	pos = event->localPos();
	CCLOG("qt %lf %lf", pos.rx(), pos.ry());
	//组装windows消息
	UINT  message = WM_MOUSEMOVE;
	WPARAM wparam = MK_LBUTTON;
	LPARAM lparam = MAKELPARAM(pos.rx(), pos.ry());
	CCEGLView::sharedOpenGLView()->WindowProc(message, wparam, lparam);
}

void Cocos2dxView::mouseReleaseEvent(QMouseEvent *event) 
{
	CCLOG("end");
	QPointF	pos = event->localPos();
	//CCLOG("%lf %lf", pos.rx(), pos.ry());
	//组装windows消息
	UINT message  = WM_LBUTTONUP;
	WPARAM wparam = MK_LBUTTON;
	LPARAM lparam = MAKELPARAM(pos.rx(), pos.ry());
	CCEGLView::sharedOpenGLView()->WindowProc(message, wparam, lparam);
}
