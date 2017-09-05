// 02_03_01_progress_timer.cpp : 定义控制台应用程序的入口点。
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
		cout << t.elapsed() << endl; //手动输出也可以
		//析构自动输出
	}


	stringstream ss;
	{
		boost::progress_timer tt(ss);
	}//导入到ss流里面

	cout << ss.str() << endl;

	system("pause");
	return 0;
}
