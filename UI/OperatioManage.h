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
private:
	std::deque<Operation*> list;
};

#define OperationManageX  (OperationManage::getInstance())

#endif