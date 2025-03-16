#include "CPlaneApp.h"

void CPlaneApp::On_Init()
{
	//游戏开始
	//1.调用背景加载函数
	m_back.init();
	//1.2设定定时器
	setTimer();
}

void CPlaneApp::On_Paint()
{
	//1.调用背景贴图函数
	m_back.show();
}

void CPlaneApp::On_Close()
{
}

void CPlaneApp::InitMsgMap()
{
	//1.3接受定时器消息函数
	INIT_MSGMAP();
}

void CPlaneApp::setTimer()
{
	//1.2设定背景移动的定时器,定时器每隔80s会发送WM_TIMER的消息，需要某个函数进行接受来进行操作
	::SetTimer(m_hwnd/*窗口句柄：操作窗口资源的标识*/
		, TIMER_ID/*定时器的id*/
		, TIMER_INTERVAL/*定时器触发间隔频率*/
		, nullptr);
}

void CPlaneApp::killTimer()
{
}

void CPlaneApp::showScore()
{
}
