#pragma once
#include "../config/config.h"
#include "../CPlayer/CPlayer.h"
#include <random>
class CFoe {
public:

	IMAGE m_img;

	int m_blood;

	int m_x;

	int m_y;

	int m_showIndex;

	static random_device rd;//������ã����������Բ��������

public:
	CFoe();

	virtual ~CFoe();

	virtual void init() = 0;

	virtual void show() = 0;

	virtual bool isHitPlayer(CPlayer* player) = 0;

	void move(int step);

	void reduceBlood(int hurt);
};