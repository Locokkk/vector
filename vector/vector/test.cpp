#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

//����vector,���캯��
//����vector<>
void test_vector1()
{
	//�޲ι���
	vector<int> v1;//��ģ�������Ҫ�Լ�ָ��,int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";//����������ķ�ʽ������v1�൱��һ�����飬�������ǽ�����
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

	//���첢��ʼ��n��val,10��5
	//vector<int> v2(10);
	vector<int> v2(10, 5);

	vector<int> v4(v1.begin(), v1.end());//1,2,3,4
	vector<int> v5(++v1.begin(), --v1.end());//2,3û��1,4����ҿ���end�����һ������һ����begin++��end--
}

template<class T>
void func()
{
	cout << T() << endl;
}

int main()
{
	test_vector1();
	//��C++�У����������й��캯��
	func<string>();//��ӡ�մ�
	func<int>();//0
	func<int*>();//��ָ��00000000
	cout << int() << endl;//��C++�У�int�й��캯����Ϊ�˼���ģ��
	system("pause");
	return 0;
}


void test_vector2()
{
	vector<int> v;//��ģ�������Ҫ�Լ�ָ��,int
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//������������ڵײ�ͨ���������������ʵ�֣������begin�Ƿ����end�������end�Ƿ����begin.
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;//++�൱�������--
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
	v.reserve(10);//reserve������
	            //size capacity 
	v.resize(10);//10 10
	v.resize(20);//20 20
	v.resize(10);//10 20 ���ۣ�capacity������

	//ͷ��ͷɾ���Ƽ�ʹ��vector��string,��O(n)���㷨����ʹ��string. ���⣬vector��ͷ�����insert
	v[0] = 100;
	v.insert(v.begin(), -1);

}

void test_vector5()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	typedef int* iterator;//ָ������Ȼ�ĵ�������֧�����·�ʽ�ĳ�ʼ��

	/*iterator it = a;
	while (it != a + sizeof(a) / sizeof(int))
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;*/
	//v.push_back(5);

	//find�㷨���֣���ʡ������븴��
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//auto pos=find(v.begin(),v.end,3);
	v.insert(pos, 30);//��3��λ�ò���30

	//������ʧЧ
	//insert�����ݿ��ܻᵼ�µ�����ʧЧ���ο���push_backһ�����ݲ���ʧЧ,��Ϊβ��Ҳ�����ݣ�����ʹposλ�ò�ʧЧ
	v.erase(pos);//ɾ��3
	//eraseҲ���ܵ��µ�����ʧЧ

	cout << *pos << endl;//vs�»ᱨ��pj�汾���Զ���飬���ϸ�Linux�²��ᱨ��û�м�飬���ǻ�����ΪʧЧ
}

void test_vector6()
{
	vector<int> v1(10, 5);
	vector<int> v2(5, 10);

	swap(v1, v2);//���۴󣬿������쿪���¿ռ�
	v1.swap(v2);//ָ�������ռ��ָ��ֱ�ӽ���
}

#include"vector.h"

int main()
{
	czy::test_vector1();
	system("pause");
	return 0;
}
