#include "./includes/Fixed.hpp"

int Fixed::getRawBits( void ) const
{
	std::cout << "GetRawBits member function called" << std::endl;
	return (this->_fix);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fix = raw;
}

Fixed &Fixed::operator=(const Fixed &p)
{
	std::cout << "Copy assignement operation called" << std::endl;
	this->_fix = p.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &p)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = p;
}

Fixed::Fixed()
{
	_fix = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}