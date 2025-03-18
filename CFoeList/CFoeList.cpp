#include "CFoeList.h"
#include <typeinfo>

CFoeList::CFoeList()
{
}

CFoeList::~CFoeList()
{
	list<CFoe*>::iterator ite = m_normalFoeList.begin();
	while (ite != m_normalFoeList.begin()) {
		if ((*ite)) {
			delete (*ite);
			(*ite) = nullptr;
		}
		++ite;
	}
	for (CFoe*& pFoe : m_boomFoeList) {
		if (pFoe) {
			delete pFoe;
			pFoe = nullptr;
		}
	}
}

void CFoeList::showAll()
{
	for (CFoe*& pFoe : m_normalFoeList) {
		if (pFoe) {
			pFoe->show();
		}
	}
	for (CFoe* cf : m_boomFoeList) {
		if (cf) {
			cf->show();
		}
	}
}

void CFoeList::moveAll()
{
	list<CFoe*>::iterator ite = m_normalFoeList.begin();
	while (ite != m_normalFoeList.end()) {
		if ((*ite)) {
			//RTTI 运行时识别
			//typeid(类型,表达式,变量) 包含该类型的信息的变量，可用 == != 进行比较
			if (typeid(**ite) == typeid(CFoeBig)) {
				(*ite)->move(FOEBIG_MOVE_STEP);
			}
			if (typeid(**ite) == typeid(CFoeMid)) {
				(*ite)->move(FOEMID_MOVE_STEP);
			}
			if (typeid(**ite) == typeid(CFoeSma)) {
				(*ite)->move(FOESMA_MOVE_STEP);
			}
		}
		if ((*ite)->m_y >= BACK_H) {
			//删除敌人飞机
			delete (*ite);
			(*ite) = nullptr;
			//删除节点
			ite = m_normalFoeList.erase(ite);
			continue;
		}
		++ite;
	}
}
