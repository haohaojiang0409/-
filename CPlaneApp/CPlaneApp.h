#pragma once
#include "../config/config.h"
class CPlaneApp : public CGameFrame {
public:

	CBack m_back;

	CPlayer m_player;

	CGunnerList m_lstGunner;

	CFoeList m_lstFoe;

	int m_score;

	IMAGE m_scoreImg;
public:
	void On_Init();

	void On_Paint();

	void On_Close();

	void InitMsgMap();

	void On_WM_KEYDOWN(int);

	void On_WM_TIMER(WPARAM, LPARAM);

	void setTimer();

	void killTimer();

	void showScore();
};