constexpr auto DEFAULT_CAPACITY = 2;

template<typename T>
class vector
{
private:
	T * data_;
	size_t size_;
	size_t capacity_;
public:
	vector();
	vector(const vector & other);
	vector(vector && other);
	explicit vector(size_t n, const T & val = T());

	vector& operator=(vector && other); 
	vector& operator=(const vector & other);
	bool operator==(const vector & other);
	bool operator!=(const vector & other);
	T & operator[](size_t pos);


	bool empty() const;
	size_t size() const;

	void clear();
	void push_back(T && value);
	void push_back(const T& value);
	void pop_back();

	~vector();
};

template<typename T>
inline vector<T>::vector():
	data_(new T[DEFAULT_CAPACITY]),
	size_(0),
	capacity_(DEFAULT_CAPACITY)
{}

template<typename T>
inline vector<T>::vector(const vector & other):
	data_(new T[other.capacity_]),
	size_(other.size_),
	capacity_(other.capacity_)
{
	std::memcpy(data_, other.data_, other.size_ * sizeof other.data_);
}

template<typename T>
inline vector<T>::vector(vector && other)
{
	std::swap(data_, other.data_);
	std::swap(size_, other.size_);
	std::swap(capacity_, other.capacity_);
}

template<typename T>
inline vector<T>::vector(size_t n, const T& val):
	capacity_(2 * n),
	data_(new T[2 * n]),
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
	std::swap(capacity_, other.capacity_);
	return *this;
}

template<typename T>
inline vector<T> & vector<T>::operator=(const vector & other)
{
	size_ = other.size_;
	capacity_ = other.capacity_;
	delete[] data_;
	data_ = new T[capacity_];
	std::memcpy(data_, other.data_, other.capacity_ * sizeof other.data_);
	return *this;
}

template<typename T>
inline bool vector<T>::operator==(const vector & other)
{
	if (size_ != other.size_)
		return false;
	for (size_t i = 0; i < size_; ++i)
	{
		if (data_[i] != other.data_[i])
			return false;
	}
	return true;
}

template<typename T>
inline bool vector<T>::operator!=(const vector & other)
{
	if (size_ != other.size_)
		return true;
	for (size_t i = 0; i < size_; ++i)
	{
		if (data_[i] != other.data_[i])
			return true;
	}
	return false;
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
	capacity_ = 0;
	delete[] data_;
}

template<typename T>
inline void vector<T>::push_back(T && value)
{
	if (size_ >= capacity_)
	{
		capacity_ *= 2;
		T * temporal = new T[capacity_];
		std::memcpy(temporal, data_, size_ * sizeof data_);
		delete[] data_;
		std::swap(data_, temporal);
	}
	std::swap(data_[size_++], value);
}

template<typename T>
inline void vector<T>::push_back(const T & value)
{
	if (size_ >= capacity_)
	{
		capacity_ *= 2;
		T * temporal = new T[capacity_];
		std::memcpy(temporal, data_, size_ * sizeof data_);
		delete[] data_;
		std::swap(data_, temporal);
	}
	this->data_[size_++] = value;
}

template<typename T>
inline void vector<T>::pop_back()
{
	if (size_ != 0)
		--size_;
}

template<typename T>
inline vector<T>::~vector()
{
	clear();
}
