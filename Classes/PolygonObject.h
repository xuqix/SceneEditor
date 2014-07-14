#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "BaseObject.h"
#include <iostream>
#include <vector>
USING_NS_CC;
class PolygonObject : public BaseObject
{
public:
	CREATE_OBJECT(PolygonObject);

	bool init() override;
	/*
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
	{
		CCLOG("ssss");
		CCPoint p = pTouch->getLocation();
		CCLOG("%f %f", p.x, p.y);
		return true;
	}
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
	{
		CCPoint p = pTouch->getLocation();
		CCLOG("%f %f", p.x, p.y);
	}
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
	{

	}
    
	void registerWithTouchDispatcher()
	{
		CCNode::registerWithTouchDispatcher();
		cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	}*/


	//添加多边形顶点
	bool pushPoint(cocos2d::CCPoint p);
	//删除最近添加的顶点
	bool popPoint();
	//绘制多边形
	void drawPolygon();

	//多边形的顶点数组
	std::vector<cocos2d::CCPoint> m_points;

	//绘制多边形的节点
	cocos2d::CCDrawNode *m_drawnode;
	//多边形的边框色
	CC_SYNTHESIZE(cocos2d::ccColor4F, m_borderColor, BorderColor);
	//多边形的填充色
	CC_SYNTHESIZE(cocos2d::ccColor4F, m_fillColor, FillColor);
	//多边形顶点颜色
	CC_SYNTHESIZE(cocos2d::ccColor4F, m_vertexColor, VertexColor);
};

#endif
