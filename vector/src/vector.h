#include <iostream>

template<typename T>
class vector
{
public:
	T * data_;
	size_t size_;
public:
	vector();
	vector(const vector & other);
	vector(vector && other);
	vector(size_t n, const T & val = T());

	vector& operator=(vector && other);
	vector& operator=(const vector & other);
	bool operator==(const vector & other);
	T & operator[](size_t pos);


	bool empty() const;
	size_t size() const;

	void clear();
	void push_back(T && value);
	void push_back(const T& value);

	~vector();
};

template<typename T>
inline vector<T>::vector():
	data_(nullptr),
	size_(0)
{}

template<typename T>
inline vector<T>::vector(const vector & other):
	data_(new T[other.size_]),
	size_(other.size_)
{
	std::memcpy(data_, other.data_, other.size_ * sizeof other.data_);
}

template<typename T>
inline vector<T>::vector(vector && other)
{
	std::swap(*this, other);
}

template<typename T>
inline vector<T>::vector(size_t n, const T& val):
	data_(new T[n]),
	size_(n)
{
	for (size_t i = 0; i < n; ++i) 
	{
		data_[i] = val;
	}
}

template<typename T>
inline vector<T> & vector<T>::operator=(vector && other)
{
	std::swap(data_, other.data_);
	std::swap(size_, other.size_);
	return *this;
}

template<typename T>
inline vector<T> & vector<T>::operator=(const vector & other)
{
	size_ = other.size_;
	delete[] data_;
	data_ = new T[size_];
	memcpy(data_, other.data_, other.size_ * sizeof other.data_);
	return *this;
}

template<typename T>
inline bool vector<T>::operator==(const vector & other)
{
	if (size_ != other.size_)
		return false;
	for (int i = 0; i < size_; ++i)
	{
		if (data_[i] != other.data_[i])
			return false;
	}
	return true;
}

template<typename T>
inline T & vector<T>::operator[](size_t pos)
{
	return data_[pos];
}

template<typename T>
inline bool vector<T>::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

template<typename T>
inline size_t vector<T>::size() const
{
	return size_;
}

template<typename T>
inline void vector<T>::clear()
{
	size_ = 0;
	delete[] data_;
}

template<typename T>
inline void vector<T>::push_back(T && value)
{
	size_ += 1;
	//data_ = std::resize(data_, size_)
}

template<typename T>
inline vector<T>::~vector()
{
	size_ = 0;
	delete[] data_;
}