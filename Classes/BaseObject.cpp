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

void BaseObject::bindSprite(CCSprite *sprite)
{
    if(m_sprite) this->removeChild(m_sprite);
    m_sprite = sprite;
    this->addChild(m_sprite);
}
