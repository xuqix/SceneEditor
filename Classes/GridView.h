#ifndef _GRIDVIEW_H_
#define _GRIDVIEW_H_

#include "cocos2d.h"

class GridView : public cocos2d::CCLayerColor
{
public:
	CREATE_FUNC(GridView);

	bool init() override;

	void draw() override;

private:
	void drawGrid();

	//ÐéÏßÍø¸ñ¼ä¸ô
	CC_SYNTHESIZE(int, m_gap, GridGap);
	cocos2d::CCSize m_frameSize;
};

#endif
