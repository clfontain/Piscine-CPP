#ifndef Fixed_HPP
#define Fixed_HPP

#include <string.h>
#include <iostream>
#include <math.h>

class Fixed
{

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &p);
        Fixed(const int i);
        Fixed(const float i);
        Fixed &operator=(const Fixed &p);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
    private:
        int _fix;
        static const int _bit = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif