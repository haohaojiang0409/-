#pragma once 
#include "../config/config.h"
class CGunner {
public:

	IMAGE m_img;

	int m_x;

	int m_y;
public:
	CGunner();

	~CGunner();

	void init(int x, int y);

	void show();

	void move(int step);

	//bool isHitFoe(CFoe* pFoe);




};