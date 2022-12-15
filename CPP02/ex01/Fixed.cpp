#include "./includes/Fixed.hpp"

float Fixed::toFloat( void ) const
{
	return((float)this->_fix / (1 << _bit)); // Cela revient au meme que d'ecrire ça = this->_fix = i / (1  * pow(2, _bit));, c'est a dire i / 256
}

int Fixed::toInt( void ) const
{
	return(this->_fix >> _bit); // revient au meme que diviser par 256
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return (out);
}

Fixed &Fixed::operator=(const Fixed &p)
{
	std::cout << "Copy assignement operation called" << std::endl;
	if (this != &p)
		this->_fix = p._fix;
	return (*this);
}

Fixed::Fixed(const int i) 
{
	std::cout << "Integer constructor called" << std::endl;
	this->_fix = i << _bit;
}

Fixed::Fixed(const float i) 
{
	std::cout << "Float constructor called" << std::endl;
	this->_fix = roundf(i * (1 << _bit));	// Cela revient au meme que d'ecrire ça = this->_fix = roundf(i * (1  * pow(2, _bit)));, c'est a dire i * 256
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