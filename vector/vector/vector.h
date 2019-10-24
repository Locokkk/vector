#pragma once

namespace czy
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		vector(const vector<T>& v)
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_end_of_storage = _start_ + v.size();
		}

		//v1=v2
		vector<T>& operator=(vector<T> v)
		{
			//this->swap(v);
			swap(v);

			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		//v1.swap(v2)
		void swap(vector<T>& v)
		{
			swap(_stzrt, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		void resize(size_t n, const T& val = T())
		{
			if (n<size())//空间足够，直接处理
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())//空间不够
			{
				reserve(n);
			}

			while (_finish != _start + n)//填数据
			{
				*_finish = val;
				++_finish;
			}
		}

		void reserve(size_t n)//增容
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];//开新空间

				if (_start)//memcpy的时候_start可能为空，导致程序崩溃
				{
					memcpy(tmp, _start, sizeof(T)*size());//拷数据
					delete[] _start;
				}
				
				_start = tmp;
				_finish = _start + sz;//size();
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& x)
		{
			if (_dinish = _end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? : 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

		void insert(iterator& pos, const T& x)//pos传引用，防止迭代器失效
		{
			if (_finish = _end_of_storage)
			{
				size_t n = pos - _start;//防止扩容后pos失效，先保存元素个数，再重新计算pos
				size_t newcapacity = capacity() == 0 ? : 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;//重置pos
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

		void erase(iterator pos)
		{
			assert(pos < _finish&&pos >= _start);
			iterator begin = pos + 1;
			while (begin<_finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		const T& operator[](size_t pos)
		{
			return _start[pos];
		}

	private:
		T* _a;
		size_t size;
		size_t capacity;

		iterator _start;//指向数组的开始
		iterator _finish;//指向数组的结束
		iterator _end_of_storage;//指向容器的结束
	};


	void test_vector()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		/*v.pop_back();
		v.pop_back();
		v.pop_back();*/
		auto it = v.begin();
		v.insert(it, 0);
		*it = 10;

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator iter = v.begin();
		while (it != v.end())
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}

