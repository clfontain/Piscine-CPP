#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
#include <vector>
#include <algorithm>

class Span
{
	public:
		// Constructors
		Span();
		Span(unsigned int size);
		Span(const Span &copy);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);


		void addNumber(int number);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator	end);
		unsigned int shortestSpan( void );
		unsigned int longestSpan( void );
		void print(void);

	class Not_Inside : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Int not found");
            }
    };
	class Full : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Span full");
            }
    };
	class Not_Enough : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Need more numbers in Span (min 2)");
            }
    };

	private:
		unsigned int _size;
		std::vector<int>	_tab;
};

#endif