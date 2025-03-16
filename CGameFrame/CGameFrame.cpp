//#include "CGameFrame.h"
//
//CGameFrame::CGameFrame():m_hwnd(nullptr), m_isquit(false)
//{
//}
//
//CGameFrame::~CGameFrame()
//{
//}
//
//void CGameFrame::InitGame(int width, int height, int x, int y, const WCHAR* p)
//{
//	m_hwnd =::initgraph(width, height);  //创建窗口
//	//设定窗口背景色  为 白色
//	::setbkcolor(RGB(255, 255, 255));
//	cleardevice();//使设定的白色背景生效
//
//	::MoveWindow(m_hwnd, x, y, width, height, true);
//	
//	::SetWindowText(m_hwnd, p);
//
//	//设置窗口的属性
//
//	//绑定窗口的回调函数
//	::SetWindowLong(m_hwnd, GWL_WNDPROC,(LONG)& CGameFrame::RunGame);
//
//	ADDMSGMAP();
//	
//	//绑定窗口的回调函数
//	//具体游戏的初始化
//	On_Init();
//}
//CGameFrame* game = nullptr;
//
//
//
//
//void CGameFrame::ADDMSGMAP() {
//	/*m_msgMap[WM_LBUTTONDOWN].MsgType = EX_MOUSE;
//	m_msgMap[WM_LBUTTONDOWN].p_fun_EX_MOUSE = &CGameFrame::On_WM_LBUTTONDOWN;
//
//	m_msgMap[WM_KEYDOWN].MsgType = EX_KEY;
//	m_msgMap[WM_KEYDOWN].p_fun_EX_KEY = &CGameFrame::On_WM_KEYDOWN;
//
//	m_msgMap[WM_CLOSE].MsgType = EX_WINDOW;
//	m_msgMap[WM_CLOSE].p_fun_EX_WINDOW = &CGameFrame::CloseGame;*/
//
//	MSGMAP(WM_CLOSE, EX_WINDOW, CGameFrame)
//		 
//}
//
//void CGameFrame::PanitGame()
//{
//	::BeginBatchDraw(); //开始批量绘图
//	::cleardevice();
//
//	//具体游戏的绘图
//	On_Paint();
//
//	::EndBatchDraw();  //结束批量绘图
//}
//
//LRESULT CALLBACK CGameFrame::RunGame(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	//if (uMsg == WM_LBUTTONDOWN) {	//获取的消息为鼠标左键按下
//
//	//	game->On_WM_LBUTTONDOWN(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
//	//}
//
//	//if (uMsg == WM_KEYDOWN) //WM:window message
//	//{
//	//	game->On_WM_KEYDOWN(wParam);
//	//}
//
//	//if (uMsg == WM_CLOSE) {
//	//	game->On_WM_CLOSE();
//	//}
//
//	if (game->m_msgMap.count(uMsg))
//	{
//		switch (game->m_msgMap[uMsg].MsgType)
//		{
//		case EX_MOUSE: {
//			// 调用函数
//			(game->*game->m_msgMap[uMsg].p_fun_EX_MOUSE)(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
//		}
//					 break;
//		case EX_KEY: {
//			(game->*game->m_msgMap[uMsg].p_fun_EX_KEY)(wParam);
//		}
//				   break;
//		case EX_WINDOW: {
//		    (game->*game->m_msgMap[uMsg].p_fun_EX_WINDOW)(wParam, lParam);
//		}	
//		break;
//		}
//	}
//
//	return DefWindowProc(hWindow,uMsg,wParam,lParam);//对于其他不关心，我不处理的消息交给 window的默认处理函数去处理
//}
//
////void CGameFrame::RunGame()
////{
////	PanitGame(); //先显示一下
////	ExMessage msg;
////	//不断地获取所有类别的消息
////	while (1) {
////		msg=getmessage();
////		if (msg.message == WM_LBUTTONDOWN) {  //获取的消息为鼠标左键按下
////			On_WM_LBUTTONDOWN(msg.x,msg.y);
////		}
////		if (msg.message == WM_KEYDOWN) //WM:window message
////		{
////			On_WM_KEYDOWN(msg.vkcode);
////		}
//		/*if (msg.message == WM_CLOSE) {
//			On_WM_CLOSE();
//		}*/
////	}
////
////
////}
//
//void CGameFrame::On_WM_CLOSE(int, int)
//{
//	//具体游戏的关闭
//	On_Close();
//
//	::closegraph();  //关闭窗口
//	
//	m_isquit = true;
//
//}
//
//extern int width;
//extern int height;
//extern int x ;
//extern int y;
//extern const WCHAR* p;
//
//CGameFrame* CreatObject();
//
//
//int main() {
//
//	game = CreatObject();
//	game->InitGame(width,height,x,y,p);
//	//game->RunGame();
//
//	game->PanitGame();
//	while (!game->m_isquit) {
//		Sleep(1000);
//	}
//
//
//	delete game;
//	game = nullptr;
//}

#include "CGameFrame.h"
#include<easyx.h>
void CGameFrame::InitGame(int width, int height, int x, int y, const WCHAR* p)
{
	m_hwnd = ::initgraph(width, height);  //创建窗口
	//设定窗口背景色  为 白色
	 ::setbkcolor(RGB(255, 255, 255));
	::cleardevice();//使设定的白色背景生效
	
	::MoveWindow(m_hwnd, x, y, width, height,true);
	::SetWindowText(m_hwnd, p);//设置窗口标题

	//设置窗口的属性
	::SetWindowLong(m_hwnd, GWLP_WNDPROC/*是32位下的宏*/, (LONG)&RunGame);  //绑定窗口的回调函数

	AddMsgMap();


	//具体游戏的初始化
	On_Init();
}



void CGameFrame::AddMsgMap() {
	
	//添加消息
	/*m_msgMap[WM_LBUTTONDOWN].MsgType = EX_MOUSE;
	m_msgMap[WM_LBUTTONDOWN].p_fun_EX_MOUSE = &CGameFrame::On_WM_LBUTTONDOWN;


	m_msgMap[WM_KEYDOWN].MsgType = EX_KEY;
	m_msgMap[WM_KEYDOWN].p_fun_EX_KEY = &CGameFrame::On_WM_KEYDOWN;

	m_msgMap[WM_CLOSE].MsgType = EX_WINDOW;
	m_msgMap[WM_CLOSE].p_fun_EX_WINDOW = &CGameFrame::CloseGame;*/
	
	ADD_MSG_MAP(WM_CLOSE, EX_WINDOW,CGameFrame)
	
}


CGameFrame::CGameFrame():m_hwnd(NULL),m_isQuit(false) {

}

CGameFrame::~CGameFrame()
{
}


void CGameFrame::PaintGame()
{
	::BeginBatchDraw(); //开始批量绘图
	::cleardevice();
	//具体游戏显示
	On_Paint();

	::EndBatchDraw();//结束批量绘图
}

//3.游戏运行的函数

//hWindow 窗口句柄 
//uMSg  消息id==msg.message
//wParam lParam  消息携带的信息
CGameFrame* pGame = nullptr;
LRESULT CALLBACK CGameFrame::RunGame(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//if (uMsg == WM_LBUTTONDOWN) {//判断获取消息是否为鼠标左键按下
	//
	//	pGame->On_WM_LBUTTONDOWN(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
	//}
	//if (uMsg == WM_KEYDOWN) {//WM:Window Message

	//	pGame->On_WM_KEYDOWN(wParam);
	//}
	//if (uMsg == WM_CLOSE) {//窗口点x时退出
	//	pGame->CloseGame();
	//}

	//--------------------------------------
	if (pGame->m_msgMap.count(uMsg)) {  //消息id,是否存在于map中
		//匹配类别,根据类别,调用函数指针

		switch (pGame->m_msgMap[uMsg].MsgType) {
		case EX_MOUSE: //鼠标类别
		{
			//(对象->*指针)(传递实参);
			(pGame->*pGame->m_msgMap[uMsg].p_fun_EX_MOUSE)(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		}
		break;
		case EX_KEY: //键盘类别
		{
			(pGame->*pGame->m_msgMap[uMsg].p_fun_EX_KEY)(wParam);
		}
		break;

		case EX_WINDOW:
		{
			(pGame->*pGame->m_msgMap[uMsg].p_fun_EX_WINDOW)(wParam, lParam);
		}
		break;
		
		}
		//有任何的消息处理后,刷新窗口
		pGame->PaintGame();

	}
	return DefWindowProc(hWindow, uMsg, wParam, lParam);  //对于其他不关心,我不处理的消息交给window的默认处理函数去处理
}

//void CGameFrame::RunGame()
//{
//	PaintGame();//先显示一下
//	ExMessage msg;
//	while (1) {
//		//不断地所有类别的获取消息
//		msg=getmessage();
//
//		if (msg.message == WM_LBUTTONDOWN) {//判断获取消息是否为鼠标左键按下
//
//			On_WM_LBUTTONDOWN(msg.x,msg.y);
//		}
		//if (msg.message == WM_KEYDOWN) {//WM:Window Message
		//
		//	On_WM_KEYDOWN(msg.vkcode);
		//}
		//if (msg.message == WM_CLOSE) {//窗口点x时退出
		//	CloseGame();
		//	break;
		//}
//
//	}
//}

void CGameFrame::On_WM_CLOSE(WPARAM, LPARAM)
{
	//具体游戏的关闭
	On_Close();

	closegraph();//关闭窗口
	m_isQuit = true;
}



extern int width ;
extern int height;
extern int pos_x ;
extern int pos_y ;
extern const WCHAR* pTitle;

CGameFrame* CreatObject();

int main() {

	pGame = CreatObject();

	pGame->InitGame(width, height, pos_x, pos_y, pTitle);

	pGame->PaintGame();  //预先重绘一下

	//pGame->RunGame();
	while (!pGame->m_isQuit) {
		Sleep(1000);
	}
	delete pGame;
	pGame = nullptr;

	return 0;
}
