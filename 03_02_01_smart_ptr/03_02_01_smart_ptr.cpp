// 03_02_01_smart_ptr.cpp : �������̨Ӧ�ó������ڵ㡣
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

	scoped_ptr<int> sp(new int); //��ֹ�����Ȳ�������Դ���ֻ֪��==�ͣ�=null�Ĳ���
	if (sp)
		cout << *sp << endl;


	{
		unique_ptr<int> ip(new int);
		unique_ptr<Widget> ip2 = make_unique<Widget>();
	}


	system("pause");
    return 0;
}

