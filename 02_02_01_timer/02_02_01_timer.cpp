// 02_02_01_timer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <boost/timer.hpp>
using namespace boost;

#include <string>

int main()
{
	timer t; //���������ҿ�ʼ��ʱ
	cout << t.elapsed_max() / 3600 << "h" << endl; //�ɶ��������ʱ��

	cout << t.elapsed_min()<< "s" << endl; //�ɶ�������Сʱ��,���Կ�����1ms

	cout <<"�Ѿ�����" << t.elapsed() << "s" << endl; //��������ŵ�ʱ��

	//timer.hpp�����в���ֵ��ѧϰ�ĸ�ʱ����ص�
	cout << std::numeric_limits<int>::max() << endl; //����Ҳ����ȡ���ֵ
	cout << std::numeric_limits<std::string>::max() << endl; //stringȡ�����ǿ�


	system("pause");
	return 0;
}
