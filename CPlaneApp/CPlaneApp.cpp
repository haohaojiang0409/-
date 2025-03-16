#include "CPlaneApp.h"

void CPlaneApp::On_Init()
{
	//��Ϸ��ʼ
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
}

void CPlaneApp::On_Close()
{
}

void CPlaneApp::InitMsgMap()
{
	//1.3���ܶ�ʱ����Ϣ����
	INIT_MSGMAP(WM_TIMER, EX_WINDOW, CPlaneApp)//����������������ǣ���������Ϣ�ʹ�����
	//1.3���ܼ��̰�����Ϣ����
	INIT_MSGMAP(WM_KEYDOWN, EX_KEY, CPlaneApp)
}

void CPlaneApp::On_WM_KEYDOWN(int key) {
	m_player.move(key, PLAYER_MOVE_STEP);
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
}

void CPlaneApp::killTimer()
{
}

void CPlaneApp::showScore()
{
}
