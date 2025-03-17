#pragma once
#include <list>
#include "../config/config.h"
#include "CFoe.h"
#include "CFoeBig.h"
#include "CFoeMid.h"
#include "CFoeSma.h"
using namespace std;

class CFoeList {
public:

	list<CFoe*> m_normalFoeList;

	list<CFoe*> m_boomFoeList;
public:
	CFoeList();

	
	~CFoeList();

	void showAll();

	void moveAll();
};