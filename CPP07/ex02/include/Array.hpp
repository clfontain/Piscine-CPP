#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
#include <stdexcept>
#include <ctime>
#include <time.h>
#include <cstdlib>

template <typename T >
class Array
{
	public:
		// Constructors
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		
		// Destructor
		~Array();
		
		// Operators
		Array& operator=(const Array &assign);
		//size_t size() const;
		
		size_t size( void) const;

		T & operator[]( size_t position) const;
	private:
		size_t _size;
		T *_RawArray;
};

template <typename T >
Array<T>::Array() : _size(0), _RawArray(new T[0])
{

}

template <typename T >
Array<T>::Array(const Array &copy) : _size(copy._size), _RawArray(new T[copy._size])
{
	for(size_t i = 0; i < _size; i++)
		this->_RawArray[i] = copy._RawArray[i];
}

template <typename T >
Array<T>::Array(unsigned int n) : _size(n), _RawArray( new T[n])
{
	for(size_t i = 0; i < _size; i++)
		this->_RawArray[i] = T();
}

template <typename T >
Array<T>::~Array()
{
	delete [] _RawArray;
}

template <typename T >
size_t Array<T>::size( void) const
{
	return (this->_size);
}

template <typename T >
T & Array<T>::operator[]( size_t position) const
{
	if (position >= this->_size)
		throw std::out_of_range("Index out of range");
	else
		return(this->_RawArray[position]);
}

template <typename T >
Array<T> & Array<T>::operator=(const Array<T> & array)
{
	if (this != &array)
	{
		this->~Array();
		this->_size = array._size;
		this->_RawArray = new T[_size];
		for(size_t i = 0; i < _size; i++)
			this->_RawArray[i] = array._RawArray[i];

	}
	return *this;
}

template <typename T >
std::ostream & operator<<(std::ostream & out, const Array<T> & array)
{
	for (size_t i = 0; i < array.size(); i++)
		out << array[i];
	return (out);
}
#endif