#include "EditorScene.h"
#include "GridView.h"

USING_NS_CC;

CCScene* EditorScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    EditorScene *layer = EditorScene::create();

    // add layer as a child to scene
	scene->addChild(layer); 
	layer->setTag(view_tag);

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
	m_gridview = NULL;

    m_background	= CCSprite::create("HelloWorld.png");
    m_background->setPosition(ccp(frameSize.width/2, frameSize.height/2));
    addChild(m_background, -1);

	//Ìí¼Ó¶ÔÏó²ã
	m_objectLayer = CCLayer::create();
	addChild(m_objectLayer);

	schedule(schedule_selector(EditorScene::adjustBackground), 0.7);

    return true;
}

bool EditorScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint p = pTouch->getLocation();
//	CCLOG("%f %f", p.x, p.y);
	return true;
}

void EditorScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint p = pTouch->getLocation();
//	CCLOG("%f %f", p.x, p.y);
}

void EditorScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}

void EditorScene::setGridView(bool isShow, int grid_gap)
{
	if (!m_gridview)
	{
		m_gridview = GridView::create();
		this->addChild(m_gridview, 100);
	}
	m_gridview->setGridGap(grid_gap);
	if (isShow)
		m_gridview->setVisible(true);
	else
		m_gridview->setVisible(false);
}
