#include "CommonObject.h"

USING_NS_CC;

bool CommonObject::init()
{
	setObjectType(ObjectType::COMMON_OBJECT);
	setTypeName("");
	setFileName("");
	setIsDrag(true);
	registerWithTouchDispatcher();
	return true;
}