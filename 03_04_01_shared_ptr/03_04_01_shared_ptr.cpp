
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

//�Զ���ɾ����
void debugDelete(Widget *w)
{
	cout << "deleting..." << endl;
	delete w;
}

int main()
{
	
	{
		Widget *p = new Widget(10);
		
		if (p) //֧����ʽת��bool
			cout << "p is not null" << endl;
		std::shared_ptr<Widget> sw(p);
		cout << sw.unique() << endl;
		cout << sw.use_count() << endl;
		std::shared_ptr<Widget> sw1 = sw; //�������캯�����Ż����ü�����һ
		//std::shared_ptr<Widget> sw1(p); //�����Ļ���sw���ü�����������,��Ϊsw1��ȫû�нӴ���sw��
		cout << sw.unique() << endl;

		cout << sw->age << endl;

	}

	
	{
		//��������
		std::shared_ptr<Widget> sw = std::make_shared<Widget>(10);
		cout << sw->age << endl;

		sw.reset();
		cout << "==" << endl;
	}
	
	{
		std::shared_ptr<vector<int>> sw = std::make_shared<vector<int>>(10, 2);//֧�ֿɱ����
	}


	{
		//�Զ���ɾ������shared_ptrֱ����һ���������ɣ�unique_ptrҪ����һ������Ȼ���дOperator()����
		std::shared_ptr<Widget> pw(new Widget(10), debugDelete);

	}


	system("pause");
	return 0;
}

