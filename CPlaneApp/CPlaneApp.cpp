#include "CPlaneApp.h"
#include <random>
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
	//3.显示炮弹
	m_lstGunner.showAll();
	//4.显示敌人飞机
	m_lstFoe.showAll();
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
		//检测方向键是否按下，如果按下则以告诉频率移动
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
			//用n来确定创建各个敌人飞机的概率
			int n = CFoe::rd() % 101;
			CFoe* pFoe = nullptr;
			//n <= 45创建小飞机
			if (n <= 45) {
				pFoe = new CFoeSma;
			}
			else if (n > 45 && n <= 80) {
				pFoe = new CFoeMid;
			}
			if (n > 80) {
				pFoe = new CFoeBig;
			}
			//45 < n <= 80创建中飞机
			//n > 80 创建大飞机
			//如果创建了飞机，那么就放入敌人飞机链表中
			if (pFoe) {
				pFoe->init();
				m_lstFoe.m_normalFoeList.push_back(pFoe);
			}
		}
		break;
	}
}

void CPlaneApp::setTimer()
{
	//1.2设定背景移动的定时器,定时器每隔80s会发送WM_TIMER的消息，需要某个函数进行接受来进行操作
	::SetTimer(m_hwnd/*窗口句柄：操作窗口资源的标识*/
		, BACK_MOVE_TIMERID/*定时器的id*/
		, BACK_TIMER_INTERVAL/*定时器触发间隔频率*/
		, nullptr);
	//2.1设置检测键盘按下的定时器
	::SetTimer(m_hwnd
		, CHECK_KEYDOWN_TIMERID
		, CHECK_KEYDOWN_INTERVAL
		, nullptr);
	::SetTimer(m_hwnd
		, GUNNER_SEND_TIMERID
		, GUNNER_SEND_INTERVAL
		, nullptr);
	//设置敌人飞机移动的频率
	::SetTimer(m_hwnd
		, FOE_MOVE_TIMERID
		, FOE_MOVE_INTERVAL
		, nullptr);
	//设置创建飞机的频率
	::SetTimer(m_hwnd
		, FOE_CREATE_TIMERID
		, FOE_CREATE_INTERVAL
		, nullptr);
}

void CPlaneApp::killTimer()
{
}

void CPlaneApp::showScore()
{
}
