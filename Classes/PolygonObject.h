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

	//对点的特殊处理
	bool containsInDot(cocos2d::CCPoint world_point);
	
	//对直线的特殊处理
	bool containsInLine(cocos2d::CCPoint world_point);

	bool containsTouchLocation(cocos2d::CCPoint world_point) override;

	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	//添加多边形顶点
	bool pushPoint(cocos2d::CCPoint p);
	//删除最近添加的顶点
	bool popPoint();
	//绘制多边形
	void drawPolygon(bool solid = true);

	//多边形的顶点数组
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::vector<cocos2d::CCPoint>, m_points, PolyPoints);

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
