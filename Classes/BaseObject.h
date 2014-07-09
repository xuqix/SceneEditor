#ifndef BubbleGame_Entity_h
#define BubbleGame_Entity_h

#include "cocos2d.h"

//面向对象原则:对类的功能的扩展多用组合，少用继承
//游戏中的实体
class BaseObject : public cocos2d::CCNode
{
public:
    BaseObject(cocos2d::CCSprite *sprite = NULL);
    ~BaseObject();
    
    //绑定精灵对象
    void bindSprite(cocos2d::CCSprite *sprite);
    
    //获取精灵对象
    cocos2d::CCSprite* getSprite() { return m_sprite; }
    
protected:
    cocos2d::CCSprite *m_sprite;
};

#endif
