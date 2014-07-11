#ifndef _OPERATION_H_
#define _OPERATION_H_
#include "CommonObject.h"

//操作基类
class Operation
{
public:
	virtual bool exec() = 0;	//执行操作
	virtual bool undo() = 0;	//撤销操作
	virtual ~Operation() {}
};

//普通编辑操作
class CommonEditOper : public Operation
{
public:
	CommonEditOper(cocos2d::CCNode *node, cocos2d::CCPoint point, std::string path):pos(point),layer(node),file_path(path) {}
	bool exec()
	{
		sprite_object = CommonObject::create(CCSprite::create(file_path.c_str()));
		sprite_object->setPosition(pos);
		layer->addChild(sprite_object);
		return true;
	}

	bool undo()
	{
		sprite_object->removeFromParent();
		return true;
	}
private:
	std::string  file_path;			
	cocos2d::CCNode *layer;			//添加到的层
	cocos2d::CCPoint pos;			//添加位置
	CommonObject *sprite_object;	//操作的精灵对象

	CommonEditOper(const CommonEditOper&);
};

#endif