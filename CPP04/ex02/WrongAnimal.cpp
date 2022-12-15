#include "./include/WrongAnimal.hpp"

// Getters

const std::string&  WrongAnimal::GetType( void ) const
{
	return (_type);
}

// Constructors
WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "\e[0;33mString Constructor called of WrongAnimal\e[0m" << std::endl;
	_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) 
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->_type = assign._type;
	return *this;
}

void WrongAnimal::makeSound( void )  const
{
	std::cout << "WrongAnimal sounds..." << std::endl;
}