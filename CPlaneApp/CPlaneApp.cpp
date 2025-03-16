#include "CPlaneApp.h"

WND_PARAM(600 + 16, 800 + 39, 500, 100 ,L"飞机大战");

CREATE_OBJECT(CPlaneApp)

void CPlaneApp::On_Init()
{
	//游戏开始
	//1.调用背景加载函数
	m_back.init();
	//2.调用玩家飞机初始化函数
	m_player.init(BACK_W, BACK_H);
	//1.2设定定时器
	setTimer();
}

void CPlaneApp::On_Paint()
{
	//1.调用背景贴图函数
	m_back.show();
	//2.调用玩家飞机贴图函数
	m_player.show();
}

void CPlaneApp::On_Close()
{
}

void CPlaneApp::AddMsgMap()
{
	//1.3接受定时器消息函数
	ADD_MSG_MAP(WM_TIMER, EX_WINDOW, CPlaneApp)//添加这条程序作用是：用来绑定消息和处理函数
	//1.3接受键盘按键消息函数
	ADD_MSG_MAP(WM_KEYDOWN, EX_KEY, CPlaneApp)
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
		//检测方向键是否按下，如果按下则以告诉频率移动
		case CHECK_KEYDOWN_TIMERID:
		{
			if (::GetAsyncKeyState(VK_UP)) {
				cout << "按下上键" << endl;
				m_player.move(VK_UP, PLAYER_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_DOWN)) {
				cout << "按下下键" << endl;
				m_player.move(VK_DOWN, PLAYER_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_LEFT)) {
				cout << "按下左键" << endl;
				m_player.move(VK_LEFT, PLAYER_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_RIGHT)) {
				cout << "按下右键" << endl;
				m_player.move(VK_RIGHT, PLAYER_MOVE_STEP);
			}
		}
		break;
	}
}

void CPlaneApp::setTimer()
{
	//1.2设定背景移动的定时器,定时器每隔80s会发送WM_TIMER的消息，需要某个函数进行接受来进行操作
	if (::SetTimer(m_hwnd/*窗口句柄：操作窗口资源的标识*/
		, BACK_MOVE_TIMERID/*定时器的id*/
		, BACK_TIMER_INTERVAL/*定时器触发间隔频率*/
		, nullptr)) {
		cout << "设置背景移动定时器成功" << endl;
	}
	//2.1设置检测键盘按下的定时器
	if (::SetTimer(m_hwnd
		, CHECK_KEYDOWN_TIMERID
		, CHECK_KEYDOWN_INTERVAL
		, nullptr)) {
		cout << "设置键盘定时器成功" << endl;
	}
}

void CPlaneApp::killTimer()
{
}

void CPlaneApp::showScore()
{
}
