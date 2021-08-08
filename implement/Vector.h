namespace hsy
{

	template<class T>
	class vector
	{
	public:

		// Vector的迭代器是一个原生指针

		typedef T* iterator；

			typedef const T* const_iterator；

			iterator begin()
		    {
				return _start;
			}

			iterator end()
			{
				return _finish;
			}

			const_iterator cbegin()
			{
				return _start;
			}

			const_iterator cend() const
			{
				return _finish;
			}



			// construct and destroy

			vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
					

			vector(int n, const T& value = T())
				: _start(nullptr)
				, _finish(nullptr)
				, _endOfStorage(nullptr)
			{
				resize(n, value);
			}

			template<class InputIterator>

			vector(InputIterator first, InputIterator last)
				: _start(nullptr)
				, _finish(nullptr)
				, _endOfStorage(nullptr)
			{
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			vector(const vector<T>& v)
				: _start(nullptr)
				, _finish(nullptr)
				, _endOfStorage(nullptr)
		    {
				this->reserve(v.capacity()); 
				for (auto e : v)
				{
					push_back(e);
				}
			}

		vector<T>& operator= (vector<T> v)
		{
			swap(v);

			return *this;
		}

			~vector()
			{
				if (_start)
				{
					delete[] _start;
				}
				_start = _finish = _endOfStorage = nullptr;
			}

			// capacity

			size_t size() const
			{
				return _finish - _start;
			}

			size_t capacity() const
			{
				return _endOfStorage - _start;
			}

			void reserve(size_t n)
			{
				if (n > capacity())
				{
					size_t sz = size();
					T* tmp = new T[n];
					if (_start)
					{
						for (size_t i = 0; i < sz; i++)
						{
							_start[i] = _start[i];
						}
						delete[] _start;
					}
					_start = tmp;
					_finish = _start + sz;
					_endOfStorage = _start + n;
				}
			}

			void resize(size_t n, const T& value = T())
			{
				if (n < size())
				{
					_finish = _start + n;
				}
				else
				{
					if (n > capacity())
					{
						reserve(n);
					}
					
					while (_finish < _start + n)
					{
						*_finish = value;
						_finish++;
					}
					
				}
			}



			///////////////access///////////////////////////////

			T& operator[](size_t pos)
			{
				assert(pos < size());

				return _start[pos];
			}

			const T& operator[](size_t pos)const
			{
				assert(pos < size());

				return _start[pos];
			}



			///////////////modify/////////////////////////////

			void push_back(const T& x)
			{
				if (_finish == _endOfStorage)
				{
					sizeof newCapacity = capacity() == 0 ? 4 : capacity() * 2;
					reserve(newCapacity);
				}
				*_finish = x;
				_finish++;
			}

			void pop_back()
			{
				assert(size() > 0);
				_finish--;
			}

			void swap(vector<T>& v)
			{
				::swap(_start, v._start);
				::swap(_finish, v._finish);
				::swap(_enOfStorage, v._endOfStorage);
			}

			iterator insert(iterator pos, const T& x)
			{
				if (_finish == _endOfStorage)
				{
					size_t len = pos - start;

					size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
					reserve(newCapacity);

					pos = _start + len;
				}
				iterator end = _finish - 1;
				while (end >= pos)
				{
					*(end + 1) = *end;
					end--;
				}
				*pos = x;
				_finish++;
			}

			iterator erase(iterator pos)
			{
				iterator it = pos + 1;
				while (it != _finish)
				{
					*(it - 1) = *it;
					++it;
				}
				_finish--;

				return pos;
			}

	private:

		iterator _start; // 指向数据块的开始

		iterator _finish; // 指向有效数据的尾

		iterator _endOfStorage; // 指向存储容量的尾

	};

}