// 03_02_01_smart_ptr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/make_unique.hpp>
using namespace boost;

class Widget {
public:
	~Widget() { cout << "dtor" << endl; }
};

int main()
{

	scoped_ptr<int> sp(new int); //禁止拷贝等操作，看源码可知只有==和！=null的操作
	if (sp)
		cout << *sp << endl;


	{
		unique_ptr<int> ip(new int);
		unique_ptr<Widget> ip2 = make_unique<Widget>();
	}


	system("pause");
    return 0;
}

