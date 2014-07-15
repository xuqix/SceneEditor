#include "BaseObject.h"

USING_NS_CC;
BaseObject::BaseObject(CCSprite *sprite)
{
    m_sprite = NULL;
    if(m_sprite)
        bindSprite(sprite);
}

BaseObject::~BaseObject()
{
    
}

bool BaseObject::init()
{
	setObjectType(ObjectType::BASE_OBJECT);
	return true;
}

void BaseObject::bindSprite(CCSprite *sprite)
{
    if(m_sprite) this->removeChild(m_sprite);
    m_sprite = sprite;
    this->addChild(m_sprite);
}

//对象是否被触摸
bool BaseObject::containsTouchLocation(cocos2d::CCTouch *touch)
{
	CCSize size = getSprite()->getContentSize();
	CCRect rect = CCRect(-size.width / 2.0, -size.height / 2.0, size.width, size.height);
	return rect.containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool BaseObject::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return containsTouchLocation(pTouch);
}
void BaseObject::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	setPosition(getPosition() + pTouch->getDelta());
}
void BaseObject::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	setPosition(getPosition() + pTouch->getDelta());
}
