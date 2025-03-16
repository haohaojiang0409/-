#pragma once
#include "../config/config.h"
class CPlayer {
public:

	IMAGE m_img;

	IMAGE m_maskImg;

	int m_x;

	int m_y;
public:
	void init(int back_w, int back_h);

	CGunner* sendGun();

	void show();

	void move(int direct, int step);
};