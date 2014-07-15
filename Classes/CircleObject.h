#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "BaseObject.h"

class CircleObject : public BaseObject
{
public:
	CREATE_OBJECT(CircleObject);

	bool init() override;

	//绘制多边形
	void drawCircle(bool solid = true);

	//绘制多边形的节点
	cocos2d::CCDrawNode *m_drawnode;

	//圆心
	CC_SYNTHESIZE(cocos2d::CCPoint, m_center, CenterPoint);
	//半径
	float m_radius;
	void setRadius(float radius);
	float getRadius() { return m_radius; }

	//边框色
	CC_SYNTHESIZE(cocos2d::ccColor4F, m_borderColor, BorderColor);
	//填充色
	CC_SYNTHESIZE(cocos2d::ccColor4F, m_fillColor, FillColor);


	//圆形的触摸判断
	bool containsTouchLocation(cocos2d::CCTouch *touch) override;
	//重写部分触摸拖拽功能
	void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) override;
	void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) override;

	void draw() override;
};

#endif
