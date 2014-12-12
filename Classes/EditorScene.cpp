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
	m_gridview = NULL;

    m_background	= CCSprite::create("HelloWorld.png");
    m_background->setPosition(ccp(frameSize.width/2, frameSize.height/2));
    addChild(m_background, -1);

	//添加对象层
	m_objectLayer = CCLayer::create();
	addChild(m_objectLayer);

	schedule(schedule_selector(EditorScene::adjustBackground), 0.7);

    return true;
}

bool EditorScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint p = pTouch->getLocation();
	return true;
}

void EditorScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint p = pTouch->getLocation();
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

BaseObject* EditorScene::getObjectInPoint(cocos2d::CCPoint pos)
{
	CCArray *object_array = getObjectLayer()->getChildren();
	CCObject *child;
	//优先判断普通对象
	CCARRAY_FOREACH(object_array, child)
	{
		BaseObject *obj = (BaseObject*)child;
		assert(obj);
		if (obj->getObjectType() == ObjectType::COMMON_OBJECT)
		{
			if (obj->containsTouchLocation(pos))
				return obj;
		}
	}
	//判断形状对象
	CCARRAY_FOREACH(object_array, child)
	{
		BaseObject *obj = (BaseObject*)child;
		assert(obj);
		if (obj->getObjectType() != ObjectType::COMMON_OBJECT)
		{
			if (obj->containsTouchLocation(pos))
				return obj;
		}
	}
	return NULL;
}

