#include "GridView.h"

USING_NS_CC;

bool GridView::init()
{
	setGridGap(10);
	return true;
}

void GridView::draw()
{
	m_frameSize = CCEGLView::sharedOpenGLView()->getFrameSize();
	drawGrid();
}

void GridView::drawGrid()
{
	//启用虚线绘制
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xaaaa);

	float width_gap = m_frameSize.width / m_gap;
	float height_gap = m_frameSize.height / m_gap;
	//绘制竖网格
	for (float pos_x = width_gap; pos_x <= m_frameSize.width ; pos_x += width_gap)
		ccDrawLine(ccp(pos_x, 0), ccp(pos_x, m_frameSize.height));
	//绘制横网格
	for (float pos_y = height_gap; pos_y <= m_frameSize.height ; pos_y += height_gap)
		ccDrawLine(ccp(0,pos_y), ccp(m_frameSize.width,pos_y));

	glDisable(GL_LINE_STIPPLE);
}

