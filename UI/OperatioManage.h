#ifndef _OPERATION_MANAGE_H_
#define _OPERATION_MANAGE_H_

#include <iostream>
#include <deque>
#include "Operation.h"
#include "../proj.win32/Singleton.h"

//全局操作列表

class OperationManage : public Singleton<OperationManage>
{
public:
	bool exec(Operation *oper, bool canUndo = true)
	{
		if(!oper->exec()) return false;
		if(canUndo)	list.push_back(oper);
		if (list.size() > 100)
			list.erase(list.begin(), list.begin() + 10);
	}
	bool undo()
	{
		if (list.size() == 0) return false;
		Operation *oper = list.back();
		if(!oper->undo()) return false;
		delete oper;
		list.pop_back();
		return true;
	}
	bool undo(BaseObject *obj)
	{
		assert(obj);
		//查找对象属于哪个操作
		for (auto oper : list)
		{
			BaseObject *oper_obj = NULL;
			switch (oper->getOperType())
			{
			case OperType::COMMON_EDIT: oper_obj = ((CommonEditOper*)oper)->getCommonObject(); break;
			case OperType::CIRCLE_EDIT: oper_obj = ((CircleEditOper*)oper)->getCircleObject(); break;
			case OperType::POLYGON_EDIT:oper_obj = ((PolygonEditOper*)oper)->getPolyObject();  break;
			}
			if (obj == oper_obj)
			{
				if(!oper->undo()) return false;
				delete oper;
				list.erase(std::find(list.begin(), list.end(), oper));
				return true;
			}
		}
		return false;
	}
	//返回当前最新的操作指针
	Operation* lastOperation() { return list.back(); }
private:
	std::deque<Operation*> list;
};

#define OperationManageX  (OperationManage::getInstance())

#endif