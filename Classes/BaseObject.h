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

class BaseObject : public cocos2d::CCNode
{
public:
    BaseObject(cocos2d::CCSprite *sprite = NULL);
    virtual ~BaseObject();

	CREATE_OBJECT(BaseObject);

	bool init() override;
    
    //绑定精灵对象
    void bindSprite(cocos2d::CCSprite *sprite);
    
    //获取精灵对象
    cocos2d::CCSprite* getSprite() { return m_sprite; }
    
protected:
	CC_SYNTHESIZE(ObjectType, m_type, ObjectType);
    cocos2d::CCSprite *m_sprite;
};

#endif
