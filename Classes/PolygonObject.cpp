#include "PolygonObject.h"

USING_NS_CC;

bool PolygonObject::init()
{
	registerWithTouchDispatcher();
	setObjectType(ObjectType::POLYGON_OBJECT);
	m_drawnode = CCDrawNode::create();
	addChild(m_drawnode);

	setBorderColor(ccc4f(0.5, 0.5, 0.5, 1));
	setFillColor(ccc4f(0.5, 0.5, 0.5, 0.3));
	setVertexColor(ccc4f(1, 0, 0, 1));

	return true;
}

bool PolygonObject::pushPoint(cocos2d::CCPoint p)
{
	for (int i = 0; i < m_points.size(); i++)
		if ((m_points[i].x == p.x) && (m_points[i].y == p.y))
			return false;
	
	m_points.push_back(p);
	drawPolygon();
	return true;
}

bool PolygonObject::popPoint()
{
	if (m_points.empty())
	{
		drawPolygon();
		return false;
	}
	m_points.pop_back();
	drawPolygon();
	return true;
}

void PolygonObject::drawPolygon(bool solid)
{
	ccColor4F fill_color = solid ? m_fillColor : ccc4f(0, 0, 0, 0);

	if (m_points.empty())	return;
	m_drawnode->clear();
	if (m_points.size() == 2)	m_drawnode->drawSegment(m_points[0], m_points[1], 1, m_borderColor);
	if (m_points.size() > 2)
	{
		CCPoint	points[128];
		for (size_t i = 0; i < m_points.size(); i++)
			points[i] = m_points[i];
		m_drawnode->drawPolygon(points, m_points.size(), fill_color, 1, m_borderColor);
	}
	for (int i = 0; i < m_points.size(); i++)
	{
		m_drawnode->drawDot(m_points[i], 2, m_vertexColor);
	}
}

bool PolygonObject::containsTouchLocation(cocos2d::CCPoint world_point)
{
	CCPoint pos = world_point;//touch->getLocation();
	int nvert = m_points.size();
	int i, j, c = 0;
	for (i = 0, j = nvert - 1; i < nvert; j = i++) 
	{
		CCPoint a = m_points[i];
		CCPoint b = m_points[j];
		if (((a.y>pos.y) != (b.y > pos.y)) && (pos.x< (b.x - a.x) * (pos.y- a.y) / (b.y - a.y) + a.x))
			c = !c;
	}
	return c;
}

void PolygonObject::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCPoint diff = pTouch->getDelta();
	for (auto &p : m_points)
		p = p + diff;
	drawPolygon();
}

void PolygonObject::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCPoint diff = pTouch->getDelta();
	for (auto &p : m_points)
		p = p + diff;
	drawPolygon(false);
}

