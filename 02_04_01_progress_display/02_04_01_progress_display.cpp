// 02_04_01_progress_display.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//cout << std::flush << endl; //�����沢û�������Ļ
	system("cls"); //�������ʵ������


	system("pause");
	return 0;
}
