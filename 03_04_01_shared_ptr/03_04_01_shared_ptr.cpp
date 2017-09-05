
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <boost/smart_ptr.hpp>
#include <vector>
using namespace boost;

class Widget {
public:
	Widget(int i) :age(i) {}
	~Widget() { cout << "dtor" << endl; }

	int age;

};

//自定义删除器
void debugDelete(Widget *w)
{
	cout << "deleting..." << endl;
	delete w;
}

int main()
{
	
	{
		Widget *p = new Widget(10);
		
		if (p) //支持隐式转型bool
			cout << "p is not null" << endl;
		std::shared_ptr<Widget> sw(p);
		cout << sw.unique() << endl;
		cout << sw.use_count() << endl;
		std::shared_ptr<Widget> sw1 = sw; //拷贝构造函数，才会引用计数加一
		//std::shared_ptr<Widget> sw1(p); //这样的话，sw引用计数不会增加,因为sw1完全没有接触到sw啊
		cout << sw.unique() << endl;

		cout << sw->age << endl;

	}

	
	{
		//工厂函数
		std::shared_ptr<Widget> sw = std::make_shared<Widget>(10);
		cout << sw->age << endl;

		sw.reset();
		cout << "==" << endl;
	}
	
	{
		std::shared_ptr<vector<int>> sw = std::make_shared<vector<int>>(10, 2);//支持可变参数
	}


	{
		//自定义删除器，shared_ptr直接用一个函数即可，unique_ptr要定义一个类型然后改写Operator()才行
		std::shared_ptr<Widget> pw(new Widget(10), debugDelete);

	}


	system("pause");
	return 0;
}

