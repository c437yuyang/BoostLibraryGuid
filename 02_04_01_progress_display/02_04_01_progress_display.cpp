// 02_04_01_progress_display.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <boost/progress.hpp>
using namespace boost;

#include <windows.h>

int main()
{
	const int n = 30;
	progress_display pd(n);
	for (int i=0;i!= n;++i)
	{
		
		++pd;
		/*if(i==n/2)
			pd.restart(n);*/
		Sleep(100);
		
	}

	//cout << std::flush << endl; //这里面并没有清空屏幕
	system("cls"); //这个可以实现清屏


	system("pause");
	return 0;
}
