#ifndef SCALE_HPP
# define SCALE_HPP

# include <iostream>
# include <string>
#include <stdlib.h>
#include <limits.h>
#include <limits>
#include <cmath>

class Scale
{
	public:
		// Constructors
		Scale();
		Scale(const Scale &copy);
		
		// Destructor
		~Scale();
		
		// Operators
		Scale & operator=(const Scale &assign);

		// Getters
		char getChar( void) const;
		int getInt( void) const;
		float getFloat( void) const;
		double getDouble( void) const;
		bool getOf( void) const;
		bool getNan( void) const;

		//
		void parsing(std::string str);
		void is_a_number(std::string str);
		void cast_type(void);
		void check_type(std::string str);
		void convert_float(std::string str);
		void convert_double(std::string str);
		void convert_int(std::string str);
		void convert_char(std::string str);

	class FormatNumberException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("ERROR : FORMAT NUMBER");
            }
    };	
	class NotDigitException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("ERROR : NOT DIGIT CHARACTER");
            }
    };

	private:
		bool _f;
		bool _point;
		bool _of;
		bool _nan;
		float _fval;
		double _dval;
		int	_ival;
		char _cval;

};

std::ostream &operator<<(std::ostream &out, const Scale &c);

#endif