
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

	int age;

};

int main()
{
	{
		scoped_array<Widget> sw(new Widget[3]); //一样不能拷贝赋值，只能swap,!=等几个操作
		cout << sw[0].age << endl;

	}

	{
		scoped_array<Widget> sw(new Widget[3]); //一样不能拷贝赋值，只能swap,!=等几个操作
		sw.reset(); //显示释放，delete
		cout << "===" << endl;
	}

	{
		std::unique_ptr<int[]> up(new int[10]); //unique_ptr必须类型设置为int[]
		std::unique_ptr<Widget[]> upw = std::make_unique<Widget[]>(10);
	}


	//建议还是不使用这个scoped_array,就用vector是最好的
	system("pause");
	return 0;
}

