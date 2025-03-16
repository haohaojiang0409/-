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
//	m_hwnd =::initgraph(width, height);  //��������
//	//�趨���ڱ���ɫ  Ϊ ��ɫ
//	::setbkcolor(RGB(255, 255, 255));
//	cleardevice();//ʹ�趨�İ�ɫ������Ч
//
//	::MoveWindow(m_hwnd, x, y, width, height, true);
//	
//	::SetWindowText(m_hwnd, p);
//
//	//���ô��ڵ�����
//
//	//�󶨴��ڵĻص�����
//	::SetWindowLong(m_hwnd, GWL_WNDPROC,(LONG)& CGameFrame::RunGame);
//
//	ADDMSGMAP();
//	
//	//�󶨴��ڵĻص�����
//	//������Ϸ�ĳ�ʼ��
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
//	::BeginBatchDraw(); //��ʼ������ͼ
//	::cleardevice();
//
//	//������Ϸ�Ļ�ͼ
//	On_Paint();
//
//	::EndBatchDraw();  //����������ͼ
//}
//
//LRESULT CALLBACK CGameFrame::RunGame(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	//if (uMsg == WM_LBUTTONDOWN) {	//��ȡ����ϢΪ����������
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
//			// ���ú���
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
//	return DefWindowProc(hWindow,uMsg,wParam,lParam);//�������������ģ��Ҳ��������Ϣ���� window��Ĭ�ϴ�����ȥ����
//}
//
////void CGameFrame::RunGame()
////{
////	PanitGame(); //����ʾһ��
////	ExMessage msg;
////	//���ϵػ�ȡ����������Ϣ
////	while (1) {
////		msg=getmessage();
////		if (msg.message == WM_LBUTTONDOWN) {  //��ȡ����ϢΪ����������
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
//	//������Ϸ�Ĺر�
//	On_Close();
//
//	::closegraph();  //�رմ���
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
	m_hwnd = ::initgraph(width, height);  //��������
	//�趨���ڱ���ɫ  Ϊ ��ɫ
	 ::setbkcolor(RGB(255, 255, 255));
	::cleardevice();//ʹ�趨�İ�ɫ������Ч
	
	::MoveWindow(m_hwnd, x, y, width, height,true);
	::SetWindowText(m_hwnd, p);//���ô��ڱ���

	//���ô��ڵ�����
	::SetWindowLong(m_hwnd, GWLP_WNDPROC/*��32λ�µĺ�*/, (LONG)&RunGame);  //�󶨴��ڵĻص�����

	AddMsgMap();


	//������Ϸ�ĳ�ʼ��
	On_Init();
}



void CGameFrame::AddMsgMap() {
	
	//�����Ϣ
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
	::BeginBatchDraw(); //��ʼ������ͼ
	::cleardevice();
	//������Ϸ��ʾ
	On_Paint();

	::EndBatchDraw();//����������ͼ
}

//3.��Ϸ���еĺ���

//hWindow ���ھ�� 
//uMSg  ��Ϣid==msg.message
//wParam lParam  ��ϢЯ������Ϣ
CGameFrame* pGame = nullptr;
LRESULT CALLBACK CGameFrame::RunGame(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//if (uMsg == WM_LBUTTONDOWN) {//�жϻ�ȡ��Ϣ�Ƿ�Ϊ����������
	//
	//	pGame->On_WM_LBUTTONDOWN(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
	//}
	//if (uMsg == WM_KEYDOWN) {//WM:Window Message

	//	pGame->On_WM_KEYDOWN(wParam);
	//}
	//if (uMsg == WM_CLOSE) {//���ڵ�xʱ�˳�
	//	pGame->CloseGame();
	//}

	//--------------------------------------
	if (pGame->m_msgMap.count(uMsg)) {  //��Ϣid,�Ƿ������map��
		//ƥ�����,�������,���ú���ָ��

		switch (pGame->m_msgMap[uMsg].MsgType) {
		case EX_MOUSE: //������
		{
			//(����->*ָ��)(����ʵ��);
			(pGame->*pGame->m_msgMap[uMsg].p_fun_EX_MOUSE)(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));

		}
		break;
		case EX_KEY: //�������
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
		//���κε���Ϣ�����,ˢ�´���
		pGame->PaintGame();

	}
	return DefWindowProc(hWindow, uMsg, wParam, lParam);  //��������������,�Ҳ��������Ϣ����window��Ĭ�ϴ�����ȥ����
}

//void CGameFrame::RunGame()
//{
//	PaintGame();//����ʾһ��
//	ExMessage msg;
//	while (1) {
//		//���ϵ��������Ļ�ȡ��Ϣ
//		msg=getmessage();
//
//		if (msg.message == WM_LBUTTONDOWN) {//�жϻ�ȡ��Ϣ�Ƿ�Ϊ����������
//
//			On_WM_LBUTTONDOWN(msg.x,msg.y);
//		}
		//if (msg.message == WM_KEYDOWN) {//WM:Window Message
		//
		//	On_WM_KEYDOWN(msg.vkcode);
		//}
		//if (msg.message == WM_CLOSE) {//���ڵ�xʱ�˳�
		//	CloseGame();
		//	break;
		//}
//
//	}
//}

void CGameFrame::On_WM_CLOSE(WPARAM, LPARAM)
{
	//������Ϸ�Ĺر�
	On_Close();

	closegraph();//�رմ���
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

	pGame->PaintGame();  //Ԥ���ػ�һ��

	//pGame->RunGame();
	while (!pGame->m_isQuit) {
		Sleep(1000);
	}
	delete pGame;
	pGame = nullptr;

	return 0;
}
