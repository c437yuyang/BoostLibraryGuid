// 03_09_01_pool.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <boost/pool/pool.hpp>
using namespace boost;

//poolֻ�ܷ����ڴ棬�����ù��캯��������ֻ�����ڻ�������
int main()
{
	
	pool <>p1(sizeof(int));

	int *p = static_cast<int *>(p1.malloc());
	*p = 1;
	
	assert(p != NULL);
	assert(p1.is_from(p)); //�жϷ����p�Ƿ������ڴ��
	p1.free(p); //free����delete�ˣ����ǻ�û����p==null
	assert(p1.is_from(p));

	for (int i = 0; i != 100; ++i) {
		p1.ordered_malloc(10);
	}


	system("pause");
    return 0;
}

