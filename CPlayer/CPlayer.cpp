#include "CPlayer.h"

CPlayer::CPlayer():m_x(0),m_y(0)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::init(int back_w, int back_h)
{
	::loadimage(&m_img, L"./res/player.jpg");
	::loadimage(&m_maskImg, L"./res/player_mask.jpg");

	m_x = (BACK_W - PLAYER_W) / 2;
	m_y = BACK_H - PLAYER_H;
}

void CPlayer::show()
{
	::putimage(m_x, m_y, &m_maskImg, SRCPAINT);	//屏蔽图，位或方式传输
	::putimage(m_x, m_y, &m_img, SRCAND);		//原图，位于方式传输
}

void CPlayer::move(int direct, int step)
{
    switch (direct) {
    case VK_LEFT:
        m_x - step >= 0 ? m_x -= step : m_x = 0;
        break;
    case VK_UP:
        m_y - step >= 0 ? m_y -= step : m_y = 0;
        break;
    case VK_DOWN:
        m_y + step <= (BACK_H - PLAYER_H) ? m_y += step : m_y = (BACK_H - PLAYER_H);
        break;
    case VK_RIGHT:
        m_x + step <= (BACK_W - PLAYER_W) ? m_x += step : m_x = (BACK_W - PLAYER_W);
        break;
    }
}