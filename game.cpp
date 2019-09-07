#include<iostream>
#include<Windows.h>
#include"mystring.h"
#include<stdlib.h>
#include<cstdio>
#include<ctime>
#include<conio.h>

using namespace std;

#define test4

#ifdef test1
int main() {
	mystring s("general string");
	mystring s1;
	cout << s.getstring() << endl;
	cout << s1.getstring() << endl;
	cout << "hello world!" << endl;
	s.setstring("123456");
	cout << s.getstring() << endl;
	MessageBoxA(NULL, "hello world!", "yes", MB_OK);
	system("pause");
	return 0;
}
#endif //test1//类代码

#ifdef test2

int main() {
	POINT mouse;
	HWND window;
	while (1) {
		GetCursorPos(&mouse);
		window = WindowFromPoint(mouse);
		/*SendMessage(窗口句柄,消息类型,消息附带内容,消息附带内容)
		比如我这里选定的消息类型是WM_CHAR
		消息附带内容为WPARAM('a')
		所以消息附带内容就是模拟键盘向窗口输入a*/
		SendMessage(window, WM_CHAR, WPARAM('a'), 0);
		Sleep(100);
	}
	return 0;
}
#endif // test2//windows 测试

#ifdef test3
#define stop Sleep(2000)
#define CLS system("cls")
int main() {
	int big, time; printf("请输入两个数字，分别代表方块的大小(<=15)，移动次数(<=20)，按回车键开始。\n");
	while (cin >> big >> time) {
		stop;
		CLS;
		cout << "Are you aready , boy ?" << endl;
		stop;
		cout << "1  2  3" << endl;
		Sleep(900);
		CLS;
		cout << "Are you aready , boy ?" << endl;
		cout << "1  2" << endl;
		Sleep(900);
		CLS;
		cout << "Are you aready , boy ?" << endl;
		cout << "1" << endl;
		Sleep(900);


		system("cls");
		for (int t = 0; t <= time; t++) {
			for (int i = 1; i <= big; i++) {
				for (int j = 1; j <= t; j++)cout << "    ";
				for (int j = 1; j <= big; j++) {
					cout << 'O' << ' ';
				}cout << endl;
			}
			Sleep(500);
			system("cls");
		}
		cout << "Are you have fun ?" << endl; stop;
		cout << "If you are , press 1 before enter key , and else press 2 . " << endl;
		cout << "If you press 3 , play again ! " << endl;
		int fun; cin >> fun; stop;
		if (fun == 1) {
			cout << "I'm glad that you are happy like a donky ." << endl; Sleep(1900); CLS;
			cout << "What did I just say ?" << endl; stop;
			cout << "Do you know ?" << endl; stop;
			cout << "I'm sorry . I forgot ." << endl; stop;
			cout << "So ," << endl; stop;
			cout << "Have fun again !" << endl; stop;
		}
		else if (fun == 2) {
			cout << "Nothing so have fun can make you happy ?" << endl; stop;
			cout << "Maybe try again and you will have fun ." << endl; stop;
		}
		else;
		CLS;
		printf("请输入两个数字，分别代表方块的大小，移动次数，按回车键开始。\n"); Sleep(1000);
	}
}

#endif // test3//模块小游戏

#ifdef test4
#define H 25
#define L 14
//这个里要判断它下一步是否会重叠，如果会则表示已经到底

int arr[H][L];    //进行方块组合的地方
//28中变形
int to_change[7][4][4][2] = { {{{0,0},{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0},{0,0}}},
			  {{{2,1},{1,0},{0,1},{-1,0}},{{-2,-1},{-1,0},{0,-1},{1,0}},{{2,1},{1,0},{0,1},{-1,0}},{{-2,-1},{-1,0},{0,-1},{1,0}}},
			  {{{1,2},{0,1},{1,0},{0,-1}},{{-1,-2},{0,-1},{-1,0},{0,1}},{{1,2},{0,1},{1,0},{0,-1}},{{-1,-2},{0,-1},{-1,0},{0,1}}},
			  {{{-1,2},{-2,1},{-1,0},{0,-1}},{{2,0},{1,1},{0,0},{-1,-1}},{{0,-1},{1,0},{0,1},{-1,2}},{{-1,-1},{0,-2},{1,-1},{2,0}}},
			  {{{1,0},{0,-1},{-1,0},{-2,1}},{{0,-2},{-1,-1},{0,0},{1,1}},{{-2,1},{-1,2},{0,1},{1,0}},{{1,1},{2,0},{1,-1},{0,-2}}},
			  {{{-3,2},{-2,-1},{-1,0},{0,1}},{{3,-2},{2,1},{1,0},{0,-1}},{{-3,2},{-2,-1},{-1,0},{0,1}},{{3,-2},{2,1},{1,0},{0,-1}}},
			  {{{0,1},{-2,1},{-1,0},{0,-1}},{{1,-1},{1,1},{0,0},{-1,-1}},{{-1,0},{1,0},{0,1},{-1,2}},{{0,0},{0,-2},{1,-1},{2,0}}} };
//7个图形
int block[7][4][2] = { {{2,6},{2,7},{3,6},{3,7}},
					{{1,7},{2,7},{2,6},{3,6}},
					{{1,6},{2,6},{2,7},{3,7}},
					{{2,6},{3,6},{3,7},{3,8}},
					{{2,8},{3,8},{3,7},{3,6}},
					{{3,5},{3,8},{3,7},{3,6}},
					{{2,7},{3,6},{3,7},{3,8}} };
int picture;//图形的序号
int now;  //当前图形的变化号
int graph[4][2];//图形的坐标
char control;
int start;

void Change();
void Move(char M);  //根据输入的AD判断左右移动
int See();         //判断是否到底
void New();         //开新
void Go();          //向下走一格
void Begin();       //一切值初始化
int Elimination(); //把完整行的消去
void Cout();        //输出矩阵
int main()
{

	Begin();
	Cout();
	while (1) {

		if (GetTickCount() - start >= 500) {

			start = GetTickCount();
			if (!See())Go();
			else {
				if (Elimination())break;
				New();
			}
			system("cls");
			Cout();
		}
		if (_kbhit()) {
			control = _getch();
			if (control == 'W' || control == 'w')Change();
			else Move(control);
			system("cls");
			Cout();
		}
	}
	//虽然背景板的高度为25，但显示时只显示后20格
}

void Change()
{
	for (int i = 0; i < 4; i++)
		arr[graph[i][0]][graph[i][1]] = 0;
	now = (now + 1) % 4;
	for (int i = 0; i < 4; i++) {
		graph[i][0] += to_change[picture][now][i][0];
		graph[i][1] += to_change[picture][now][i][1];
	}
	for (int i = 0; i < 4; i++) {
		if (graph[i][1] < 0) {
			int temp = 0 - graph[i][1];
			for (int j = 0; j < 4; j++)graph[j][1] += temp;
		}
		if (graph[i][1] > L - 1) {
			int temp = graph[i][1] - (L - 1);
			for (int j = 0; j < 4; j++)graph[j][1] -= temp;
		}
	}
	for (int i = 0; i < 4; i++)
		arr[graph[i][0]][graph[i][1]] = 2;
}
void Move(char M)
{
	for (int i = 0; i < 4; i++)
		arr[graph[i][0]][graph[i][1]] = 0;

	if ((M == 'a' || M == 'A') && graph[0][1] && graph[1][1] && graph[2][1] && graph[3][1])
		if (arr[graph[0][0]][graph[0][1] - 1] != 1 && arr[graph[1][0]][graph[1][1] - 1] != 1 && arr[graph[2][0]][graph[2][1] - 1] != 1 && arr[graph[3][0]][graph[3][1] - 1] != 1) {
			graph[0][1]--;
			graph[1][1]--;
			graph[2][1]--;
			graph[3][1]--;
		}
	if ((M == 'd' || M == 'D') && graph[0][1] < L - 1 && graph[1][1] < L - 1 && graph[2][1] < L - 1 && graph[3][1] < L - 1)
		if (arr[graph[0][0]][graph[0][1] + 1] != 1 && arr[graph[1][0]][graph[1][1] + 1] != 1 && arr[graph[2][0]][graph[2][1] + 1] != 1 && arr[graph[3][0]][graph[3][1] + 1] != 1) {
			graph[0][1]++;
			graph[1][1]++;
			graph[2][1]++;
			graph[3][1]++;
		}
	for (int i = 0; i < 4; i++)
		arr[graph[i][0]][graph[i][1]] = 2;
}
int See()
{
	for (int i = 0; i < 4; i++)
		if (graph[i][0] + 1 == H)return 1;
	for (int i = 0; i < 4; i++)
		if (arr[graph[i][0] + 1][graph[i][1]] == 1)return 1;
	return 0;
}
void New()
{
	picture = rand() % 7;
	now = -1;
	for (int i = 0; i < 4; i++) {
		graph[i][0] = block[picture][i][0];
		graph[i][1] = block[picture][i][1];
		arr[graph[i][0]][graph[i][1]] = 2;
	}
}
void Go()
{
	for (int i = 0; i < 4; i++) {
		arr[graph[i][0]][graph[i][1]] = 0;
		graph[i][0]++;
	}
	for (int i = 0; i < 4; i++)
		arr[graph[i][0]][graph[i][1]] = 2;
}
void Begin()
{
	srand(time(NULL));
	start = GetTickCount();//开始的时间
	for (int i = 0; i < H; i++)
		for (int j = 0; j < L; j++)
			arr[i][j] = 0;
	picture = rand() % 7;
	now = -1;
	for (int i = 0; i < 4; i++) {
		graph[i][0] = block[picture][i][0];
		graph[i][1] = block[picture][i][1];
		arr[graph[i][0]][graph[i][1]] = 2;
	}
}
int Elimination()
{
	for (int i = 0; i < 4; i++) {
		arr[graph[i][0]][graph[i][1]] = 1;
		if (graph[i][0] < 4)return 1;
	}
	for (int i = H - 1; i >= 0; ) {
		int j;
		for (j = 0; j < L; j++)
			if (arr[i][j] != 1)break;
		if (j == L) {
			for (int k = i; k > 0; k--)
				for (int l = 0; l < L; l++)
					arr[k][l] = arr[k - 1][l];
		}
		else i--;
	}
	return 0;
}
void Cout()
{
	for (int i = 5; i < H; i++) {
		for (int j = 0; j < L; j++) {
			if (arr[i][j] == 0)printf(".");
			else if (arr[i][j] == 1) {
				printf("#");
			}
			else printf("o");
		}
		printf("\n");
	}
}
#endif // test4//俄罗斯方块

#ifdef test5
	
#endif // test5//测试代码

