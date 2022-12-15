#include "./include/Brain.hpp"

// Constructors
Brain::Brain()
{
	for (int i = 0 ; i < 100; i++)
	{
		if (i % 3 == 0)
			this->_ideas[i] = "Hello !";
		if (i % 3 == 1)
			this->_ideas[i] = "I'm Hungry";
		if (i % 3 == 2)
			this->_ideas[i] = "DUUUUUUUUU";
	}
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	for (int i = 0 ; i < 100; i++)
	{
		_ideas[i] = assign._ideas[i];
	}
	return *this;
}

// Getter
const std:: string &Brain::GetIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cerr << "Error invalid index, valid range is < 0 to 99 >, the first string of brain is return" << std::endl;
		return (this->_ideas[0]);
	}	
	return(this->_ideas[index]);
}
