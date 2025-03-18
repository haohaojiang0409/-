#pragma once
#include "../config/config.h"
#include "../CBack/CBack.h"
#include "../CPlayer/CPlayer.h"
#include "../CGameFrame/CGameFrame.h"
#include "../CPlaneApp/CPlaneApp.h"
#include "../CGunnerList/CGunner.h"
#include "../CGunnerList/CGunnerList.h"
#include "../CFoeList/CFoeList.h"


class CPlaneApp : public CGameFrame {
public:

	CBack m_back;

	CPlayer m_player;

	CGunnerList m_lstGunner;

	CFoeList m_lstFoe;

	int m_score;

	IMAGE m_scoreImg;
public:
	CPlaneApp();

	~CPlaneApp();

	void On_Init();

	void On_Paint();

	void On_Close();

	void AddMsgMap();

	void On_WM_KEYDOWN(int);

	void On_WM_TIMER(WPARAM, LPARAM);

	void setTimer();

	void killTimer();

	void showScore();
};