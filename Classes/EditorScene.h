#ifndef __EDITOR_SCENE_H__
#define __EDITOR_SCENE_H__

#include "cocos2d.h"
#include "GridView.h"

USING_NS_CC;

static const int view_tag = 100;

class EditorScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    bool init() override;  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();


	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
	void registerWithTouchDispatcher()
	{
		CCLayer::registerWithTouchDispatcher();
		CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	}

	//自动置背景位置于视图中心
	void adjustBackground(float dt);
    
    // implement the "static node()" method manually
    CREATE_FUNC(EditorScene);

	CC_SYNTHESIZE_READONLY(CCSprite*, m_background, Background);

	//设置是否显示网格及网格数grid_gap * grid_gap
	void setGridView(bool isShow, int grid_gap = 10);
	CC_SYNTHESIZE_READONLY(GridView*, m_gridview, GridView);

	CCSize  frameSize = CCEGLView::sharedOpenGLView()->getFrameSize();
	CCSize  visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
};

#endif 
