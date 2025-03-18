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
			//�ж��Ƿ���磬���缴ɾ��
			if ((*ite)->m_y <= -GUNNER_H) {
				delete (*ite);
				(*ite) = nullptr;

				//ɾ���ڵ�
				ite = m_gunList.erase(ite);
				continue;
			}
		}
		++ite;
	}
}
