#include "CommonObject.h"

USING_NS_CC;

bool CommonObject::init()
{
	setObjectType(ObjectType::COMMON_OBJECT);
	setTypeName("");
	registerWithTouchDispatcher();
	return true;
}