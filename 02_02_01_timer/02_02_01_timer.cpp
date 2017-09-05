// 02_02_01_timer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <boost/timer.hpp>
using namespace boost;

#include <string>

int main()
{
	timer t; //生命对象并且开始计时
	cout << t.elapsed_max() / 3600 << "h" << endl; //可度量的最大时间

	cout << t.elapsed_min()<< "s" << endl; //可度量的最小时间,可以看到是1ms

	cout <<"已经过了" << t.elapsed() << "s" << endl; //输出已流逝的时间

	//timer.hpp里面有不少值得学习的跟时间相关的
	cout << std::numeric_limits<int>::max() << endl; //这样也可以取最大值
	cout << std::numeric_limits<std::string>::max() << endl; //string取到的是空


	system("pause");
	return 0;
}
