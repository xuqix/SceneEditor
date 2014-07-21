#include "CircleObject.h"

USING_NS_CC;

bool CircleObject::init()
{
	setObjectType(ObjectType::CIRCLE_OBJECT);
	setTypeName("CircleObject");
	m_drawnode = CCDrawNode::create();
	addChild(m_drawnode);

	registerWithTouchDispatcher();

	setBorderColor(ccc4f(1, 0, 0, 1));
	setFillColor(ccc4f(0.5, 0.5, 0.5, 0.5));
	m_radius = 10;
	return true;
}

void CircleObject::drawCircle(bool solid)
{
	m_drawnode->clear();
	if (solid)
		m_drawnode->drawDot(m_center, m_radius, m_fillColor);
}

void CircleObject::setRadius(float radius)
{
	if (radius < 10) return;
	m_radius = radius;
	drawCircle();
}

bool CircleObject::containsTouchLocation(cocos2d::CCPoint world_point)
{
	return (m_radius * m_radius) >(m_center.getDistanceSq(world_point));
}

void CircleObject::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	setCenterPoint(getCenterPoint() + pTouch->getDelta());
	drawCircle();
}

void CircleObject::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	setCenterPoint(getCenterPoint() + pTouch->getDelta());
	drawCircle(false);
}


void CircleObject::draw()
{
	glLineWidth(2.0);
	ccDrawColor4B(128, 128, 128, 255);
	ccDrawCircle(m_center, m_radius, 0, 100, 0);
}