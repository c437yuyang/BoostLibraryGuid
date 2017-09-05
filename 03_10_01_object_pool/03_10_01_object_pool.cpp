// 03_09_01_pool.cpp : �������̨Ӧ�ó������ڵ㡣
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

		Widget *pw1 = opl.malloc(); //����ԭʼ�ڴ�
		//��ʱage��Ϊ��ʼ����
		pw1->age = 20;
		pw1 = opl.construct(10); //ֱ�ӹ�����һ������

		{
			//Ҳ����ֱ�ӹ�������
			for (int i = 0; i != 3; ++i)
			{
				opl.construct(i);
			}
		} //���Կ����������������û���ͷţ�����opl���ڳ���ν�����Ż��ͷ�
	}




	system("pause");
	return 0;
}

