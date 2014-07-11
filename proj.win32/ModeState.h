#ifndef _EDITMODE_H_
#define _EDITMODE_H_

#include "Singleton.h"

//编辑器的模式设置
class ModeState : public Singleton<ModeState>
{
public:
	//0xffffffff表示未设置
	//主编辑模式
	enum PrimaryMode
	{
		NoMode		= 0xffffffff,
		BrowseMode	= 0x1,	//浏览模式
		EditMode	= 0x2	//编辑模式
	};
	//子模式
	enum SubMode
	{
		NoSubMode	= 0xffffffff,
		//浏览模式无子模式

		//编辑子模式
		CircleEdit	= 0x1,	//圆形编辑
		PolygonEdit	= 0x2,	//多边形编辑
		CommonEdit	= 0x3,	//普通编辑
		ChoiceEdit	= 0x4	//选取编辑
	};

	PrimaryMode getPrimaryMode()	{ return primary_mode; }
	SubMode		getSubMode()	{ return sub_mod; }
	void setPrimaryMode(PrimaryMode mode) { primary_mode = mode; }
	void setSubMode(SubMode smode)	{ sub_mod = smode; }

private:
	PrimaryMode	primary_mode;	//主模式
	SubMode		sub_mod;		//子模式
};

#define ModeStateX (ModeState::getInstance())

#endif