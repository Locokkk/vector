#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

//类名vector,构造函数
//类型vector<>
void test_vector1()
{
	//无参构造
	vector<int> v1;//类模板的类型要自己指定,int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";//可以像数组的方式遍历，v1相当于一个数组，在这里是解引用
	}
	cout << endl;

	vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//构造并初始化n个val,10个5
	//vector<int> v2(10);
	vector<int> v2(10, 5);

	vector<int> v4(v1.begin(), v1.end());//1,2,3,4
	vector<int> v5(++v1.begin(), --v1.end());//2,3没有1,4左闭右开，end是最后一个的下一个，begin++，end--
}

template<class T>
void func()
{
	cout << T() << endl;
}

int main()
{
	test_vector1();
	//在C++中，内置类型有构造函数
	func<string>();//打印空串
	func<int>();//0
	func<int*>();//空指针00000000
	cout << int() << endl;//在C++中，int有构造函数，为了兼容模板
	system("pause");
	return 0;
}


void test_vector2()
{
	vector<int> v;//类模板的类型要自己指定,int
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//反向迭代器，在底层通过调用正向迭代器实现，正向的begin是反向的end，正向的end是反向的begin.
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;//++相当于正向的--
	}
	cout << endl;

}

void test_vector3()
{
	size_t sz;
	std::vector<int> foo;
	foo.reserve(100);
	foo.resize(100);
	foo.resize(100, 5);
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector4()
{
	vector<int> v;
	v.reserve(10);
	v.reserve(20);
	v.reserve(10);//reserve不会缩
	            //size capacity 
	v.resize(10);//10 10
	v.resize(20);//20 20
	v.resize(10);//10 20 结论：capacity不会缩

	//头插头删不推荐使用vector和string,是O(n)的算法，可使用string. 另外，vector的头插可用insert
	v[0] = 100;
	v.insert(v.begin(), -1);

}

void test_vector5()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	typedef int* iterator;//指针是天然的迭代器，支持如下方式的初始化

	/*iterator it = a;
	while (it != a + sizeof(a) / sizeof(int))
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/
	//v.push_back(5);

	//find算法体现，反省层面代码复用
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//auto pos=find(v.begin(),v.end,3);
	v.insert(pos, 30);//在3的位置插入30

	//迭代器失效
	//insert的增容可能会导致迭代器失效，参考：push_back一个数据不会失效,因为尾插也会增容，可以使pos位置不失效
	v.erase(pos);//删除3
	//erase也可能导致迭代器失效

	cout << *pos << endl;//vs下会报错，pj版本会自动检查，更严格，Linux下不会报错，没有检查，但是还是认为失效
}

void test_vector6()
{
	vector<int> v1(10, 5);
	vector<int> v2(5, 10);

	swap(v1, v2);//代价大，拷贝构造开辟新空间
	v1.swap(v2);//指向两个空间的指针直接交换
}

#include"vector.h"

int main()
{
	czy::test_vector1();
	system("pause");
	return 0;
}
