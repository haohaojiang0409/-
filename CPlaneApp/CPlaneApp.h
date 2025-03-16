#pragma once
#include "../config/config.h"
class CPlaneApp {
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

	void setTimer();

	void killTimer();

	void showScore();
};