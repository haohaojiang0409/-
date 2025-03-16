#include "CGunner.h"

CGunner::CGunner():m_x(0),m_y(0)
{
}

CGunner::~CGunner()
{
}

void CGunner::init(int x, int y)
{
	::loadimage(&m_img, L"./res/gunner.jpg");

	m_x = x;

	m_y = y;
}

void CGunner::show()
{
	//1.先贴屏蔽图，利用位或
	::putimage(m_x, m_y/*显示到目标窗口的那个位置*/
				, GUNNER_W, GUNNER_H/*显示的大小*/
				, &m_img, 0, 0/*从原图的哪个位置开始显示*/, SRCPAINT);
	//2.再贴原图，位与
	::putimage(m_x, m_y/*显示到目标窗口的那个位置*/
		, GUNNER_W, GUNNER_H/*显示的大小*/
		, &m_img, 0, 0/*从原图的哪个位置开始显示*/, SRCAND);
}

void CGunner::move(int step)
{
	m_y -= step;
}

//bool CGunner::isHitFoe(CFoe* pFoe)
//{
//	return false;
//}
