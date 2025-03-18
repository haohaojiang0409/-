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
	//1.�ж�player�Ƿ�Ϊ��
	if (player) {
		//2.ȡ�����㣬�ֱ�����ҷɻ�ͷ�ͷɻ�����
		int x1 = player->m_x + PLAYER_W / 2;
		int y1 = m_y;
		if (m_x <= x1 && x1 <= m_x + FOEBIG_W &&
			m_y <= player->m_y && player->m_y <= m_y + FOEBIG_H) {
			return true;
		}
		int x2 = player->m_x;
		int y2 = player->m_y + PLAYER_H / 2;
		if (m_x <= x2 && x2 <= m_x + FOEBIG_W &&
			m_y <= y2 && y2 <= m_y + FOEBIG_H) {
			return true;
		}
		int x3 = player->m_x + PLAYER_W;
		int y3 = player->m_y;
		if (m_x <= x3 && x3 <= m_x + FOEBIG_W &&
			m_y <= y3 && y3 <= m_y + FOEBIG_H) {
			return true;
		}
	}
	return false;
}
