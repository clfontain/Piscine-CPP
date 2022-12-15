#include "./include/Dog.hpp"

// Constructors
Dog::Dog() : Animal("Dog") , _brain(new Brain())
{
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	delete this->_brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->_type = assign._type;
	this->_brain = assign._brain;
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog sounds...  " << std::endl;
}

Brain* Dog::GetBrain( void ) const
{
	return(this->_brain);
}