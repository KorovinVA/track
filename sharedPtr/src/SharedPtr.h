#define ONE_PTR 1

template <typename T>
struct ControllBlock
{
	T * ptr_;
	size_t count_;
	ControllBlock()
	{
		ptr_ = nullptr;
		count_ = 0;
	}
	ControllBlock(T * ptr):
		ptr_(ptr),
		count_(ONE_PTR)
	{}
};

template <typename T>
class SharedPtr
{
	template<class U>
	friend class shared_ptr;
public:
	ControllBlock<T> * controll_;
public:
	SharedPtr();
	explicit SharedPtr(T * ptr);
	SharedPtr(const SharedPtr<T> & other);
	~SharedPtr();

	void reset();
	size_t use_count() const;
	T * get() const;

	SharedPtr& operator=(const SharedPtr& other);
	T * operator->();
	T & operator*();

	template<typename T, typename U>
	friend bool operator!=(const SharedPtr<T> & rhs, const SharedPtr<U> & lhs);
};

template<typename T>
inline SharedPtr<T>::SharedPtr()
{
	controll_ = new ControllBlock<T>;
}

template<typename T>
inline SharedPtr<T>::SharedPtr(T * ptr)
{
	controll_ = new ControllBlock<T>(ptr);
}

template<typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr<T>& other): controll_(other.controll_)
{
	++controll_->count_;
}

template<typename T>
inline SharedPtr<T>::~SharedPtr()
{
	if (controll_->count_ != ONE_PTR)
		controll_->count_--;
	else if (controll_->count_ == ONE_PTR)
	{
		delete controll_->ptr_;
		delete controll_;
	}
	else if (controll_->count_ == 0)
	{
		delete controll_;
	}
}

template<typename T>
inline void SharedPtr<T>::reset()
{
	if (controll_->count_ == ONE_PTR)
	{
		delete controll_->ptr_;
		delete controll_;
		controll_ = new ControllBlock<T>();
	}
	else
	{
		--controll_->count_;
		controll_ = new ControllBlock<T>();
	}
}

template<typename T>
inline size_t SharedPtr<T>::use_count() const
{
	return controll_->count_;
}

template<typename T>
inline T * SharedPtr<T>::get() const
{
	return controll_->ptr_;
}

template<typename T>
inline SharedPtr<T> & SharedPtr<T>::operator=(const SharedPtr & other)
{
	if (other != *this)
	{
		reset();
		delete controll_;
		controll_ = other.controll_;
		controll_->count_++;
	}
	return *this;
}

template<typename T>
inline T * SharedPtr<T>::operator->()
{
	return controll_->ptr_;
}

template<typename T>
inline T & SharedPtr<T>::operator*()
{
	return *(controll_->ptr_);
}

template<typename T, typename U>
inline bool operator!=(const SharedPtr<T>& rhs, const SharedPtr<U>& lhs)
{
	return !(rhs.get() == lhs.get() && rhs.use_count() == lhs.use_count());
}
