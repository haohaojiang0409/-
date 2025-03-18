#include "CFoeMid.h"

void CFoeMid::init()
{
	::loadimage(&m_img, L"./res/foemid.jpg");

	m_blood = FOEMID_BLOOD;

	m_x = rd() % (BACK_W - FOEMID_W + 1);

	m_y = -FOEMID_H;

	m_showIndex = MIDINIT_SHOWID;

}

void CFoeMid::show()
{
	::putimage(m_x, m_y, FOEMID_W, FOEMID_H,
		&m_img, FOEMID_W, (MIDINIT_SHOWID - m_showIndex) * FOEMID_H, SRCPAINT);
	::putimage(m_x, m_y, FOEMID_W, FOEMID_H,
		&m_img, 0, (MIDINIT_SHOWID - m_showIndex) * FOEMID_H, SRCAND);
}

bool CFoeMid::isHitPlayer(CPlayer* player)
{
	//1.判断player是否为空
	if (player) {
		//2.取三个点，分别是玩家飞机头和飞机两侧
		int x1 = player->m_x + PLAYER_W / 2;
		int y1 = m_y;
		if (m_x <= x1 && x1 <= m_x + FOEMID_W &&
			m_y <= player->m_y && player->m_y <= m_y + FOEMID_H) {
			return true;
		}
		int x2 = player->m_x;
		int y2 = player->m_y + PLAYER_H / 2;
		if (m_x <= x2 && x2 <= m_x + FOEMID_W &&
			m_y <= y2 && y2 <= m_y + FOEMID_H) {
			return true;
		}
		int x3 = player->m_x + PLAYER_W;
		int y3 = player->m_y;
		if (m_x <= x3 && x3 <= m_x + FOEMID_W &&
			m_y <= y3 && y3 <= m_y + FOEMID_H) {
			return true;
		}
	}
	return false;
}
