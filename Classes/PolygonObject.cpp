#include "PolygonObject.h"
#include <cmath>

USING_NS_CC;

bool PolygonObject::init()
{
	registerWithTouchDispatcher();
	setIsDrag(false);
	setObjectType(ObjectType::POLYGON_OBJECT);
	setTypeName("PolygonObject");
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
	if (m_points.size() == 2)	m_drawnode->drawSegment(m_points[0], m_points[1], 1.2, m_borderColor);
	if (m_points.size() > 2)
	{
		CCPoint	points[128];
		for (size_t i = 0; i < m_points.size(); i++)
			points[i] = m_points[i];
		m_drawnode->drawPolygon(points, m_points.size(), fill_color, 1.2, m_borderColor);
	}
	for (int i = 0; i < m_points.size(); i++)
	{
		m_drawnode->drawDot(m_points[i], 3, m_vertexColor);
	}
}

bool PolygonObject::containsInDot(cocos2d::CCPoint world_point)
{
	//将点假想成一个很小的园
	return m_points[0].getDistance(world_point) < 8;
}

bool PolygonObject::containsInLine(cocos2d::CCPoint world_point)
{
	CCPoint &pos = world_point;

	//将直线假想成一个宽很小的矩形
	CCPoint norm;
	//求垂直于直线向量的单位向量
	float a = m_points[1].x - m_points[0].x, b = m_points[1].y - m_points[0].y;
	norm.x = sqrt((b*b) / (a*a + b*b));
	norm.y = (-a*norm.x) / b;
	//矩形四个角
	const int size = 4;
	CCPoint points[size];
	points[0] = m_points[0] + norm * 8;
	points[1] = m_points[1] + norm * 8;
	points[2] = m_points[1] - norm * 8;
	points[3] = m_points[0] - norm * 8;

	int i, j;
	bool isTouch = false;
	for (i = 0, j = size - 1; i < size; j = i++) 
	{
		CCPoint a = points[i];
		CCPoint b = points[j];
		if (((a.y>pos.y) != (b.y > pos.y)) && (pos.x< (b.x - a.x) * (pos.y- a.y) / (b.y - a.y) + a.x))
			isTouch = !isTouch;
	}
	return isTouch;
}

bool PolygonObject::containsTouchLocation(cocos2d::CCPoint world_point)
{
	CCPoint pos = world_point;//touch->getLocation();
	int nvert = m_points.size();
	if (nvert == 1) return containsInDot(world_point);
	if (nvert == 2) return containsInLine(world_point);
	int i, j;
	bool isTouch = false;
	for (i = 0, j = nvert - 1; i < nvert; j = i++) 
	{
		CCPoint a = m_points[i];
		CCPoint b = m_points[j];
		if (((a.y>pos.y) != (b.y > pos.y)) && (pos.x< (b.x - a.x) * (pos.y- a.y) / (b.y - a.y) + a.x))
			isTouch = !isTouch;
	}
	return isTouch;
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

