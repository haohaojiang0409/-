#include "CPlaneApp.h"

void CPlaneApp::On_Init()
{
	//��Ϸ��ʼ
	//1.���ñ������غ���
	m_back.init();
	//1.2�趨��ʱ��
	setTimer();
}

void CPlaneApp::On_Paint()
{
	//1.���ñ�����ͼ����
	m_back.show();
}

void CPlaneApp::On_Close()
{
}

void CPlaneApp::InitMsgMap()
{
	//1.3���ܶ�ʱ����Ϣ����
	INIT_MSGMAP();
}

void CPlaneApp::setTimer()
{
	//1.2�趨�����ƶ��Ķ�ʱ��,��ʱ��ÿ��80s�ᷢ��WM_TIMER����Ϣ����Ҫĳ���������н��������в���
	::SetTimer(m_hwnd/*���ھ��������������Դ�ı�ʶ*/
		, TIMER_ID/*��ʱ����id*/
		, TIMER_INTERVAL/*��ʱ���������Ƶ��*/
		, nullptr);
}

void CPlaneApp::killTimer()
{
}

void CPlaneApp::showScore()
{
}
