#include "CFoeMid.h"

void CFoeMid::init()
{
	::loadimage(&m_img, L"./res/foebig.jpg");

	m_blood = FOEMID_BLOOD;

	m_x = rd() % (BACK_W - FOEMID_W + 1);

	m_y = -FOEMID_H;

	m_showIndex = MIDINIT_SHOWID;

}

void CFoeMid::show()
{
	::putimage(m_x, m_y, FOEMID_W, FOEBIG_H,
		&m_img, FOEMID_W, (MIDINIT_SHOWID - m_showIndex) * FOEMID_H, SRCPAINT);
	::putimage(m_x, m_y, FOEMID_W, FOEBIG_H,
		&m_img, 0, (MIDINIT_SHOWID - m_showIndex) * FOEMID_H, SRCAND);
}

bool CFoeMid::isHitPlayer(CPlayer* player)
{
	return false;
}
