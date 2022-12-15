#include "./includes/Fixed.hpp"

// ******** Member functions ******** //

float Fixed::toFloat( void ) const
{
	return((float)this->_fix / (1 << _bit));
}

int Fixed::toInt( void ) const
{
	return(this->_fix >> _bit);
}

int Fixed::getRawBits( void ) const
{

	return (this->_fix);
}

void Fixed::setRawBits( int const raw )
{
	this->_fix = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return (out);
}

// ******** Comparison operators ******** //

Fixed &Fixed::operator=(const Fixed &p)
{
	this->_fix = p._fix;
	return (*this);
}

bool Fixed::operator<(const Fixed &p) const
{
	return (this->getRawBits() < p.getRawBits());
}

bool Fixed::operator>(const Fixed &p) const
{
	return (this->getRawBits() > p.getRawBits());
}

bool Fixed::operator<=(const Fixed &p) const
{
	return (this->getRawBits() <= p.getRawBits());
}

bool Fixed::operator>=(const Fixed &p) const
{
	return (this->getRawBits() >= p.getRawBits());
}

bool Fixed::operator!=(const Fixed &p) const
{
	return (this->getRawBits() != p.getRawBits());
}

bool Fixed::operator==(const Fixed &p) const
{
	return (this->getRawBits() == p.getRawBits());
}

// ******** Arithmetic operators ******** //

Fixed Fixed::operator+(const Fixed &p) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + p.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed &p) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - p.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed &p) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() * p.getRawBits() >> _bit);
	return (res);
}

Fixed Fixed::operator/(const Fixed &p) const
{
	Fixed res;
	if (p.getRawBits() == 0)
		return (Fixed());
	res.setRawBits((this->_fix * (1 << _bit)) / p._fix);
	return (res);
}

// ******** Increment operators ******** //

Fixed &Fixed::operator++(void)
{
	++_fix;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++_fix;
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	--_fix;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--_fix;
	return (temp);
}

// ******** Static overload ******** //

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fix <= b._fix)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
	if (a._fix <= b._fix)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fix >= b._fix)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
	if (a._fix >= b._fix)
		return (a);
	else
		return (b);
}
// ******** Constructors and Destructor ******** //

Fixed::Fixed(const int i) 
{
	this->_fix = i << _bit;
}

Fixed::Fixed(const float i) 
{
	this->_fix = roundf(i * (1 << _bit));
}

Fixed::Fixed(const Fixed &p) : _fix(p._fix)
{

}

Fixed::Fixed()
{
	_fix = 0;
}

Fixed::~Fixed()
{
}