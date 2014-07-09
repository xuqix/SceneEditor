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
	m_timer.stop();
	CCDirector::sharedDirector()->end();
	CCDirector::sharedDirector()->mainLoop();
}

Cocos2dxView::Cocos2dxView(QWidget *parent) : QWidget(parent)
{
	initCocos2dx(); m_mouseSprite = NULL;
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

	cocos2d::CCScene *sc = CCDirector::sharedDirector()->getRunningScene();
	//运行一帧，保证当前运行场景不为空
	CCDirector::sharedDirector()->mainLoop();
	
	m_timer.setParent(this);
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(renderCocos2dx()));
	m_timer.start();
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

void Cocos2dxView::enterEvent(QEvent *event)
{
	qDebug("enter");
	cocos2d::CCScene *scene = CCDirector::sharedDirector()->getRunningScene();
	if (scene)
	{
		QRect r = this->geometry();
		m_mouseSprite = cocos2d::CCSprite::create("CloseNormal.png");
		QPoint	pos = mapFromGlobal(QCursor::pos());
		m_mouseSprite->setPosition(ccp(pos.rx(), r.height() - pos.ry()));
		scene->addChild(m_mouseSprite);

		m_mouseTimer.setParent(this);
		connect(&m_mouseTimer, SIGNAL(timeout()), this, SLOT(mouseMoveInView()));
		
		m_mouseTimer.start(20);
	}
}

void Cocos2dxView::leaveEvent(QEvent *event)
{
	qDebug("leave");
	m_mouseTimer.stop();
	if (m_mouseSprite)
		m_mouseSprite->removeFromParent();
}

void Cocos2dxView::mouseMoveInView()
{
	qDebug("set pos");
	QRect r = this->geometry();
	QPoint	pos = mapFromGlobal(QCursor::pos());
	m_mouseSprite->setPosition(ccp(pos.rx(), r.height() - pos.ry()));
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
