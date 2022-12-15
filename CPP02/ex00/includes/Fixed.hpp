#ifndef Fixed_HPP
#define Fixed_HPP

#include <string.h>
#include <iostream>

class Fixed
{
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &p);
    Fixed &operator=(const Fixed &p);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int _fix;
    static const int _bit = 8;
};

#endif