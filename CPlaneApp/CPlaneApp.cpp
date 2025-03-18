#include "CPlaneApp.h"
#include <random>
WND_PARAM(600 + 16, 800 + 39, 500, 100 ,L"�ɻ���ս");

CREATE_OBJECT(CPlaneApp)


CPlaneApp::CPlaneApp():m_score(0)
{
}

CPlaneApp::~CPlaneApp()
{
}

void CPlaneApp::On_Init()
{
	//��Ϸ��ʼ
	::loadimage(&m_scoreImg, L"./res/card.png", 100, 40);
	//1.���ñ������غ���
	m_back.init();
	//2.������ҷɻ���ʼ������
	m_player.init(BACK_W, BACK_H);
	//1.2�趨��ʱ��
	setTimer();
}

void CPlaneApp::On_Paint()
{
	//1.���ñ�����ͼ����
	m_back.show();
	//2.������ҷɻ���ͼ����
	m_player.show();
	//3.��ʾ�ڵ�
	m_lstGunner.showAll();
	//4.��ʾ���˷ɻ�
	m_lstFoe.showAll();
	//5.��ʾ����
	showScore();
}

void CPlaneApp::On_Close()
{
}

void CPlaneApp::AddMsgMap()
{
	//1.3���ܶ�ʱ����Ϣ����
	ADD_MSG_MAP(WM_TIMER, EX_WINDOW, CPlaneApp)//����������������ǣ���������Ϣ�ʹ�����
	//1.3���ܼ��̰�����Ϣ����
	ADD_MSG_MAP(WM_KEYDOWN, EX_KEY, CPlaneApp)
}

void CPlaneApp::On_WM_KEYDOWN(int key) {
	//m_player.move(key, PLAYER_MOVE_STEP);
	if (key == VK_SPACE) {
		m_lstGunner.m_gunList.push_back(m_player.sendGun());
	}
}

void CPlaneApp::On_WM_TIMER(WPARAM w, LPARAM l) {
	switch (w) {
		case BACK_MOVE_TIMERID:
		{
			m_back.move(BACK_MOVE_STEP);
		}
		break;
		//��ⷽ����Ƿ��£�����������Ը���Ƶ���ƶ�
		case CHECK_KEYDOWN_TIMERID:
		{
			if (::GetAsyncKeyState(VK_UP)) {
				m_player.move(VK_UP, PLAYER_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_DOWN)) {
				m_player.move(VK_DOWN, PLAYER_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_LEFT)) {
				m_player.move(VK_LEFT, PLAYER_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_RIGHT)) {
				m_player.move(VK_RIGHT, PLAYER_MOVE_STEP);
			}
		}
		break;
		case GUNNER_SEND_TIMERID:
		{
			m_lstGunner.moveAll();
		}
		break;
		case FOE_MOVE_TIMERID: {
			m_lstFoe.moveAll();
		}
		break;
		case FOE_CREATE_TIMERID: {
			//��n��ȷ�������������˷ɻ��ĸ���
			int n = CFoe::rd() % 101;
			CFoe* pFoe = nullptr;
			//n <= 45����С�ɻ�
			if (n <= 45) {
				pFoe = new CFoeSma;
			}
			else if (n > 45 && n <= 80) {
				pFoe = new CFoeMid;
			}
			if (n > 80) {
				pFoe = new CFoeBig;
			}
			//45 < n <= 80�����зɻ�
			//n > 80 ������ɻ�
			//��������˷ɻ�����ô�ͷ�����˷ɻ�������
			if (pFoe) {
				pFoe->init();
				m_lstFoe.m_normalFoeList.push_back(pFoe);
			}
		}
		break;
		case FOE_HIT_TIMERID:
		{
			//��ʼĬ�ϲ���ը
			bool isBoom = false;
			//��ʼ�������˷ɻ�����
			std::list<CFoe*>::iterator iteFoe = m_lstFoe.m_normalFoeList.begin();
			while (iteFoe != m_lstFoe.m_normalFoeList.end()) {
				//�ж��Ƿ����ҷɻ���ײ
				if ((*iteFoe)->isHitPlayer(&m_player)) {
					//��ײ����Ϸ����
					killTimer();
					//������������ʾ��Ϸ����
					::MessageBox(m_hwnd, L"��Ϸ����", L"��ʾ", MB_OK);
					//�����˳���ͨ����Ϣ��ģ����ֶ����x�Ĺ���
					::PostMessage(m_hwnd, WM_CLOSE/*���ڹرյĹ���*/, 0, 0);
					return;
				}
				//�ж��Ƿ���ڵ���ײ
				//1.�Ƚ����ڵ��ĵ���������
				std::list<CGunner*>::iterator iteGun = m_lstGunner.m_gunList.begin();
				while (iteGun != m_lstGunner.m_gunList.end()) {
					//2.�ڽ��м���Ƿ�ײ���˵��˷ɻ�
					if ((*iteGun)->isHitFoe(*iteFoe)) {
						//3.ɾ���ڵ�
						delete (*iteGun);
						(*iteGun) = nullptr;

						iteGun = m_lstGunner.m_gunList.erase(iteGun);
						//4.���˷ɻ���Ѫ
						(*iteFoe)->reduceBlood(GUNNER_BLOOD);
						//5.�ж�Ѫ���Ƿ�Ϊ0
						if ((*iteFoe)->m_blood <= 0) {
							m_lstFoe.m_boomFoeList.push_back((*iteFoe));
							iteFoe = m_lstFoe.m_normalFoeList.erase(iteFoe);
							isBoom = true;
							break;
						}
						continue;
					}
					iteGun++;
				}
				if (isBoom) isBoom = false;
				else iteFoe++;
			}
		}
	}
}

void CPlaneApp::setTimer()
{
	//1.2�趨�����ƶ��Ķ�ʱ��,��ʱ��ÿ��80s�ᷢ��WM_TIMER����Ϣ����Ҫĳ���������н��������в���
	::SetTimer(m_hwnd/*���ھ��������������Դ�ı�ʶ*/
		, BACK_MOVE_TIMERID/*��ʱ����id*/
		, BACK_TIMER_INTERVAL/*��ʱ���������Ƶ��*/
		, nullptr);
	//2.1���ü����̰��µĶ�ʱ��
	::SetTimer(m_hwnd
		, CHECK_KEYDOWN_TIMERID
		, CHECK_KEYDOWN_INTERVAL
		, nullptr);
	::SetTimer(m_hwnd
		, GUNNER_SEND_TIMERID
		, GUNNER_SEND_INTERVAL
		, nullptr);
	//���õ��˷ɻ��ƶ���Ƶ��
	::SetTimer(m_hwnd
		, FOE_MOVE_TIMERID
		, FOE_MOVE_INTERVAL
		, nullptr);
	//���ô����ɻ���Ƶ��
	::SetTimer(m_hwnd
		, FOE_CREATE_TIMERID
		, FOE_CREATE_INTERVAL
		, nullptr);
	//���÷ɻ�ײ����ʱ��
	::SetTimer(m_hwnd
		, FOE_HIT_TIMERID
		, FOE_HIT_INTERVAL
		, nullptr);
}

void CPlaneApp::killTimer()
{
	//1.2�趨�����ƶ��Ķ�ʱ��,��ʱ��ÿ��80s�ᷢ��WM_TIMER����Ϣ����Ҫĳ���������н��������в���
	::KillTimer(m_hwnd/*���ھ��������������Դ�ı�ʶ*/
		, BACK_MOVE_TIMERID);
	//2.1���ü����̰��µĶ�ʱ��
	::KillTimer(m_hwnd
		, CHECK_KEYDOWN_TIMERID);
	::KillTimer(m_hwnd
		, GUNNER_SEND_TIMERID);
	//���õ��˷ɻ��ƶ���Ƶ��
	::KillTimer(m_hwnd
		, FOE_MOVE_TIMERID);
	//���ô����ɻ���Ƶ��
	::KillTimer(m_hwnd
		, FOE_CREATE_TIMERID);
	//���÷ɻ�ײ����ʱ��
	::KillTimer(m_hwnd
		, FOE_HIT_TIMERID);
}

void CPlaneApp::showScore()
{
	//1.����ͼƬ
	::putimage(0, 0, &m_scoreImg);
	//2.��ʾ����
	wstring ws = L"����Ϊ";
	wchar_t sc[10] = { 0 };
	_itow_s(m_score, sc, 10);
	ws += sc;
	RECT rect = { 0,0,100,40 };
	settextcolor(RGB(45, 200, 100));
	drawtext(ws.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
