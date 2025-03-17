#include "CFoeBig.h"
void CFoeBig::init()
{

	::loadimage(&m_img, L"./res/foebig.jpg");

	m_blood = FOEBIG_BLOOD;

	m_x = rd() % (BACK_W - FOEBIG_W + 1);

	m_y = -FOEBIG_H;
	//切换爆炸效果的变量
	m_showIndex = BIGINIT_SHOWID;
}

void CFoeBig::show()
{
	//由于是五层贴图，渐变的爆炸效果，所以需要进行showId的改变
	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H,
		&m_img, FOEBIG_W, (BIGINIT_SHOWID - m_showIndex) * FOEBIG_H, SRCPAINT);
	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H,
		&m_img, 0, (BIGINIT_SHOWID - m_showIndex) * FOEBIG_H, SRCAND);
}

bool CFoeBig::isHitPlayer(CPlayer* player)
{
	return false;
}
