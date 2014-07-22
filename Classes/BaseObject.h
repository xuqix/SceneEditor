#ifndef _BASEOBJECT_H_
#define _BASEOBJECT_H_
#include "cocos2d.h"

//对象类型
enum class ObjectType
{
	BASE_OBJECT,
	COMMON_OBJECT,
	POLYGON_OBJECT,
	CIRCLE_OBJECT
};

//编辑对象创建宏

#define CREATE_OBJECT(__TYPE__) \
static __TYPE__* create(cocos2d::CCSprite *sprite)\
{\
	__TYPE__ *obj = new __TYPE__(); \
	if (obj && obj->init())\
	{\
		obj->autorelease(); \
		obj->bindSprite(sprite); \
		return obj; \
	}\
	CC_SAFE_RELEASE(obj); \
	return NULL; \
}

//编辑器基本编辑对象

class BaseObject : public cocos2d::CCNode, public cocos2d::CCTargetedTouchDelegate
{
public:
    BaseObject(cocos2d::CCSprite *sprite = NULL);
    virtual ~BaseObject();

	CREATE_OBJECT(BaseObject);

	bool init() override;

	//设置精灵闪烁
	void setBlink(bool blink);
	CC_SYNTHESIZE(bool, m_isBlink, isBlink);
    
    //绑定精灵对象
    void bindSprite(cocos2d::CCSprite *sprite);
    
    //获取精灵对象
    cocos2d::CCSprite* getSprite() { return m_sprite; }

	//注册启用触摸功能
	void registerWithTouchDispatcher()
	{
		cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	}

	//对象是否被触摸,可重写
	virtual bool containsTouchLocation(cocos2d::CCPoint world_point);
//	virtual bool containsTouchLocation(cocos2d::CCTouch *touch);
	//默认实现了触摸拖拽功能
	bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) override;
	void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) override;
	void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) override;
    
protected:
	//是否启用拖拽功能
	CC_SYNTHESIZE(bool, m_isDrag, IsDrag);
	CC_SYNTHESIZE(ObjectType, m_type, ObjectType);
	//类型名，不是指上面的对象类型的类型名
	CC_SYNTHESIZE(std::string, m_TypeName, TypeName);
    cocos2d::CCSprite *m_sprite;
};

#endif
