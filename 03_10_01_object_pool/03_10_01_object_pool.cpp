// 03_09_01_pool.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <boost/pool/object_pool.hpp>
using namespace boost;


class Widget {
public:
	Widget(int i) :age(i) {}
	~Widget() { cout << "dtor age:" << age << endl; }

	int age;

};

int main()
{
	{
		object_pool<Widget> opl;

		Widget *pw1 = opl.malloc(); //分配原始内存
		//此时age是为初始化的
		pw1->age = 20;
		pw1 = opl.construct(10); //直接构建另一个对象

		{
			//也可以直接构建对象
			for (int i = 0; i != 3; ++i)
			{
				opl.construct(i);
			}
		} //可以看到这个程序块结束后并没有释放，而是opl所在程序段结束后才会释放
	}




	system("pause");
	return 0;
}

