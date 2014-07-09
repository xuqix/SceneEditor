#include "EditorScene.h"

USING_NS_CC;

CCScene* EditorScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    EditorScene *layer = EditorScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void EditorScene::adjustBackground(float dt)
{
	frameSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    m_background->setPosition(ccp(frameSize.width/2, frameSize.height/2));
}

bool EditorScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
	this->setTouchEnabled(true);

    m_background	= CCSprite::create("HelloWorld.png");
    m_background->setPosition(ccp(frameSize.width/2, frameSize.height/2));
    this->addChild(m_background, -1);

	schedule(schedule_selector(EditorScene::adjustBackground), 0.7);

    return true;
}

bool EditorScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLOG("ssss");
	CCPoint p = pTouch->getLocation();
	CCLOG("%f %f", p.x, p.y);
	return true;
}

void EditorScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint p = pTouch->getLocation();
	CCLOG("%f %f", p.x, p.y);
}

void EditorScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}