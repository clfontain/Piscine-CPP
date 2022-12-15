#include "./include/Cat.hpp"

// Constructors
Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	delete this->_brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->_type = assign._type;
	this->_brain = assign._brain;
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat sounds..." << std::endl;
}

Brain* Cat::GetBrain( void ) const
{
	return(this->_brain);
}