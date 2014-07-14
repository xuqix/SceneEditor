#include "CircleObject.h"

USING_NS_CC;

bool CircleObject::init()
{
	setObjectType(ObjectType::CIRCLE_OBJECT);
	m_drawnode = CCDrawNode::create();
	addChild(m_drawnode);

	setBorderColor(ccc4f(0.5, 0.5, 0.5, 1));
	setFillColor(ccc4f(0.5, 0.5, 0.5, 0.5));
	m_radius = 10;
	return true;
}

void CircleObject::drawCircle()
{
	m_drawnode->clear();
	m_drawnode->drawDot(m_center, m_radius, m_fillColor);
}

void CircleObject::setRadius(float radius)
{
	if (radius < 10) return;
	m_radius = radius;
	drawCircle();
}
