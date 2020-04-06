/*
@author: SeaFever
@功能：模拟加载进度条
@说明：goto函数被删除，所以需要自己写
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>

class ProgressBar {
public:
	ProgressBar() = default;
	void index();
private:
	void gotoxy(int x, int y);
};
void ProgressBar::index()
{
	char a[4] = { '|','/','-','\\' };	//存储相关的字符
	int i, j, x = 2, y = 1;	//声明变量
	std::cout << "*******加载进度条模拟*******" << std::endl;	//输出顶框
	putchar('\n');	//为接下来的进度条保留空位
	std::cout << "****************************" << std::endl;	//输出底框
	gotoxy(x, y);	//调用函数控制光标位置
	for (i = 0;i <= 100;i++) {	//进度条总进度控制
		std::cout << " [";	//进度条左边框
		for (j = 0;j < i / 10;j++) {	//控制加载进度的显示
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);	//设置加载条样式配置
			std::cout << "_";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//恢复原配置
		for (j = 0;j < (10 - (i / 10));j++) { printf("%c", '.'); }	//未加载进度显示
		std::cout << "] ";	//进度条右边框
		std::cout << a[i % 4] << "正在加载中";	//显示和程序进行中提示和“正在加载”字样提示
		for (j = 0;j < (i % 4);j++) { std::cout << "."; }	//实现动态显示
		for (j = 0;j < (4 - i % 4);j++) { printf("%c", ' '); }
		Sleep(100);	//控制程序运行速度
		putchar('\r');	//回车
	}
	std::cout << "( ゜- ゜)つロBiliBili干杯~\n" << std::endl;	//防覆盖
}

void ProgressBar::gotoxy(int x, int y)	//自定义 gotoxy 函数
{
	COORD c;
	c.X = x;c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
