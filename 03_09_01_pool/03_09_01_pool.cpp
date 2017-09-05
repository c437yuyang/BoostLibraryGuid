// 03_09_01_pool.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include <boost/pool/pool.hpp>
using namespace boost;

//pool只能分配内存，不调用构造函数，所以只能用于基本类型
int main()
{
	
	pool <>p1(sizeof(int));

	int *p = static_cast<int *>(p1.malloc());
	*p = 1;
	
	assert(p != NULL);
	assert(p1.is_from(p)); //判断分配的p是否来自内存池
	p1.free(p); //free就是delete了，但是还没有另p==null
	assert(p1.is_from(p));

	for (int i = 0; i != 100; ++i) {
		p1.ordered_malloc(10);
	}


	system("pause");
    return 0;
}

