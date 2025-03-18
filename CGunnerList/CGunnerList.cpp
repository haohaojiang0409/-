#include "CGunnerList.h"

CGunnerList::CGunnerList()
{
}

CGunnerList::~CGunnerList()
{
	std::list<CGunner*>::iterator ite = m_gunList.begin();
	while (ite != m_gunList.end()) {
		if (*ite) {
			delete (*ite);
			(*ite) = nullptr;
		}
		++ite;
	}
	m_gunList.clear();
}

void CGunnerList::showAll()
{
	for (CGunner* pGun : m_gunList) {
		if (pGun)
			pGun->show();
	}
}

void CGunnerList::moveAll()
{
	std::list<CGunner*>::iterator ite = m_gunList.begin();
	while (ite != m_gunList.end()) {
		if (*ite) {
			(*ite)->move(GUNNER_MOVE_STEP);
			//判断是否出界，出界即删除
			if ((*ite)->m_y <= -GUNNER_H) {
				delete (*ite);
				(*ite) = nullptr;

				//删除节点
				ite = m_gunList.erase(ite);
				continue;
			}
		}
		++ite;
	}
}
