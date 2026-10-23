
template <typename T>
Array<T>::Array(void) : _elements(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(Array const &other) : _elements(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_elements = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = other._elements[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		delete[] _elements;
		_elements = NULL;
		_size = other._size;
		if (_size > 0)
		{
			_elements = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = other._elements[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _elements;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n)
{
	if (n > 0)
		_elements = new T[n]();
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_elements[index]);
}

template <typename T>
T const	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_elements[index]);
}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("index out of bounds");
}
