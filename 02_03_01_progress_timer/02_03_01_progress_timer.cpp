// 02_03_01_progress_timer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

#include <boost/progress.hpp>

int main()
{
	{
		boost::progress_timer t;
		for (int i = 0; i != 10000; ++i)
		{
		}
		cout << t.elapsed() << endl; //�ֶ����Ҳ����
		//�����Զ����
	}


	stringstream ss;
	{
		boost::progress_timer tt(ss);
	}//���뵽ss������

	cout << ss.str() << endl;

	system("pause");
	return 0;
}
