#pragma once
#include "../config/config.h"
#include "CGunner.h"
#include <list>

class CGunnerList {
public:
	std::list<CGunner*> m_gunList;
public:
	CGunnerList();

	~CGunnerList();

	void showAll();

	void moveAll();
};