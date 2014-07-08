#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	CCSprite *spr;

	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
	{
		CCLOG("ssss");
		CCPoint p = pTouch->getLocation();
		CCLOG("%f %f", p.x, p.y);
		return true;
	}
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
	{
		CCPoint p = pTouch->getLocation();
		CCLOG("%f %f", p.x, p.y);
	}
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
	{

	}
    
	void registerWithTouchDispatcher()
	{
		CCLayer::registerWithTouchDispatcher();
		CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	}

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	void update(float dt);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
