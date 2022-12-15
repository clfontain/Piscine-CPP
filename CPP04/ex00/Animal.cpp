#include "./include/Animal.hpp"

// Getters

const std::string&  Animal::GetType( void ) const
{
	return (_type);
}

// Constructors
Animal::Animal() : _type("Animal")
{
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "\e[0;33mString Constructor called of Animal\e[0m" << std::endl;
	_type = type;
}

Animal::Animal(const Animal &copy) 
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	this->_type = assign._type;
	return *this;
}

void Animal::makeSound( void )  const
{
	std::cout << "Abstract animal noise" << std::endl;
}