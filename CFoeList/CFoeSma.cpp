#include "CFoeSma.h"

void CFoeSma::init()
{
	::loadimage(&m_img, L"./res/foesma.jpg");

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
	//1.判断player是否为空
	if (player) {
		//2.取三个点，分别是玩家飞机头和飞机两侧
		int x1 = player->m_x + PLAYER_W / 2;
		int y1 = m_y;
		if (m_x <= x1 && x1 <= m_x + FOESMA_W &&
			m_y <= player->m_y && player->m_y <= m_y + FOESMA_H) {
			return true;
		}
		int x2 = player->m_x;
		int y2 = player->m_y + PLAYER_H / 2;
		if (m_x <= x2 && x2 <= m_x + FOESMA_W &&
			m_y <= y2 && y2 <= m_y + FOESMA_H) {
			return true;
		}
		int x3 = player->m_x + PLAYER_W;
		int y3 = player->m_y;
		if (m_x <= x3 && x3 <= m_x + FOESMA_W &&
			m_y <= y3 && y3 <= m_y + FOESMA_H) {
			return true;
		}
	}
	return false;
}
