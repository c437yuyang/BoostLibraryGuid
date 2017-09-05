// 02_06_01_date_time.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include <boost/date_time.hpp>
using namespace boost::gregorian;

int main()
{
#pragma region date类

	date d1;
	date d2(2010, 1, 1);
	date d3(2010, Jan, 1);
	date d4(d2);

	assert(d1 == date(not_a_date_time));
	assert(d2 == d4);

	cout << d1 << endl; //输出not_a_date_time
	cout << d2 << endl;

	cout << d2.end_of_month() << endl; //31日

	d2 = from_string("2005-12-08");
	//d2 = from_string("2005-13-08"); //报异常
	cout << d2 << endl;


	cout << d2.year() << endl;

	cout << d2.week_number() << endl;

	cout << to_simple_string(d2) << endl;
	cout << to_iso_string(d2) << endl;
	cout << to_iso_extended_string(d2) << endl;

#pragma endregion

#pragma region date_duration

	date d5(2010, 2, 13);
	date d6(2011, 3, 11);

	cout << d6 - d5 << endl;
	d5 += days(10);
	cout << d5 << endl;

	date_duration dd = d6 - d5;
	cout << dd << endl;
#pragma endregion

#pragma region date_period，表示一段时间
	date_period dp(date(2014, 1, 1), days(20));

	dp.shift(days(3));

	cout << dp.begin().day() << endl;
	cout << dp.length() << endl;
	cout << dp.length().days() << endl;

	cout << dp.contains(date(2014, 1, 10)) << endl; //1
	cout << dp.is_before(date(2014, 1, 10)) << endl; //0
#pragma endregion

#pragma region iterator

	date d(2016, 11, 26);
	day_iterator d_iter(d);

	cout << *(d_iter) << endl;
	cout << *(++d_iter) << endl;
	cout << d_iter->day() << endl;


#pragma endregion

#pragma region 其他功能

	cout << "year 2014 is" << (gregorian_calendar::is_leap_year(2014) ? "" : " not") <<
		" a leap year." << endl;


#pragma endregion



	system("pause");
	return 0;
}
