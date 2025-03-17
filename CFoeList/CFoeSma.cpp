#include "CFoeSma.h"

void CFoeSma::init()
{
	::loadimage(&m_img, L"./res/foebig.jpg");

	m_blood = FOESMA_BLOOD;

	m_x = rd() % (BACK_W - FOESMA_W + 1);

	m_y = -FOESMA_H;

	m_showIndex = SMAINIT_SHOWID;

}

void CFoeSma::show()
{
	::putimage(m_x, m_y, FOESMA_W, FOESMA_H,
		&m_img, FOESMA_W, (SMAINIT_SHOWID - m_showIndex) * FOESMA_H, SRCPAINT);
	::putimage(m_x, m_y, FOESMA_W, FOESMA_H,
		&m_img, 0, (SMAINIT_SHOWID - m_showIndex) * FOESMA_H, SRCAND);
}

bool CFoeSma::isHitPlayer(CPlayer* player)
{
	return false;
}
