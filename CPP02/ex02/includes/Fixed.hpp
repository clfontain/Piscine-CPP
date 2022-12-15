#ifndef Fixed_HPP
#define Fixed_HPP

#include <string.h>
#include <iostream>
#include <math.h>

class Fixed
{

    public:

        // ******** Constructors and Destructor ******** //
        
        Fixed();
        ~Fixed();
        Fixed(const Fixed &p);
        Fixed(const int i);
        Fixed(const float i);

        Fixed &operator=(const Fixed &p);
        // ******** Comparison operators ******** //
        
        bool operator<(const Fixed &p) const;
        bool operator<=(const Fixed &p) const;
        bool operator>=(const Fixed &p) const;
        bool operator!=(const Fixed &p) const;
        bool operator==(const Fixed &p) const;
        bool operator>(const Fixed &p) const;
        // ******** Arithmetic operators ******** //

        Fixed operator+(const Fixed &p) const;
        Fixed operator-(const Fixed &p) const;
        Fixed operator*(const Fixed &p) const;
        Fixed operator/(const Fixed &p) const;

        // ******** Increment operators ******** //

        Fixed &operator++( void );
        Fixed operator++( int );
        Fixed &operator--( void );
        Fixed operator--( int );

        // ******** Static overload ******** //

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        // ******** Member functions ******** //
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