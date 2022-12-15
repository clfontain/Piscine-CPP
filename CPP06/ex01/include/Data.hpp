#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
#include <stdint.h>
class Data
{
	public:
		// Constructors
		Data();
		Data(const Data &copy);
		
		// Destructor
		~Data();
		
		// Operators
		Data & operator=(const Data &assign);
		
		//
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
		std::string _test;

};

#endif