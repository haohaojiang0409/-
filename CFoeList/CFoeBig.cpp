#include "CFoeBig.h"
void CFoeBig::init()
{

	::loadimage(&m_img, L"./res/foebig.jpg");

	m_blood = FOEBIG_BLOOD;

	m_x = rd() % (BACK_W - FOEBIG_W + 1);

	m_y = -FOEBIG_H;
	//�л���ըЧ���ı���
	m_showIndex = BIGINIT_SHOWID;
}

void CFoeBig::show()
{
	//�����������ͼ������ı�ըЧ����������Ҫ����showId�ĸı�
	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H,
		&m_img, FOEBIG_W, (BIGINIT_SHOWID - m_showIndex) * FOEBIG_H, SRCPAINT);
	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H,
		&m_img, 0, (BIGINIT_SHOWID - m_showIndex) * FOEBIG_H, SRCAND);
}

bool CFoeBig::isHitPlayer(CPlayer* player)
{
	return false;
}
