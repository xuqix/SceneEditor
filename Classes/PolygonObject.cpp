#include "PolygonObject.h"

USING_NS_CC;

bool PolygonObject::init()
{
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

void PolygonObject::drawPolygon()
{
	if (m_points.empty())	return;
	m_drawnode->clear();
	if (m_points.size() == 2)	m_drawnode->drawSegment(m_points[0], m_points[1], 1, m_borderColor);
	if (m_points.size() > 2)
	{
		CCPoint	points[128];
		for (size_t i = 0; i < m_points.size(); i++)
			points[i] = m_points[i];
		m_drawnode->drawPolygon(points, m_points.size(), m_fillColor, 1, m_borderColor);
	}
	for (int i = 0; i < m_points.size(); i++)
	{
		m_drawnode->drawDot(m_points[i], 3, m_vertexColor);
	}
}
