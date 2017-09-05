// 02_07_01_posix_time.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include <boost\date_time\posix_time\posix_time.hpp>
#include <boost\date_time\date.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;

int main() 
{
	time_duration td(1, 10, 30, 1000);
	
	td += hours(1) + minutes(1);

	cout << td << endl;

	{
		ptimer t;
	}


	system("pause");
	return 0;
}
