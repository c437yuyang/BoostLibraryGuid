
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
		scoped_array<Widget> sw(new Widget[3]); //һ�����ܿ�����ֵ��ֻ��swap,!=�ȼ�������
		cout << sw[0].age << endl;

	}

	{
		scoped_array<Widget> sw(new Widget[3]); //һ�����ܿ�����ֵ��ֻ��swap,!=�ȼ�������
		sw.reset(); //��ʾ�ͷţ�delete
		cout << "===" << endl;
	}

	{
		std::unique_ptr<int[]> up(new int[10]); //unique_ptr������������Ϊint[]
		std::unique_ptr<Widget[]> upw = std::make_unique<Widget[]>(10);
	}


	//���黹�ǲ�ʹ�����scoped_array,����vector����õ�
	system("pause");
	return 0;
}

