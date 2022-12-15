#include "./include/Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

Form * Intern::makeForm(std::string form, std::string target)
{
	int i;
	Form *tmp = NULL;
	std::string choice[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (i = 0; i < 3; i++)
	{
		if (form == choice[i])
			break;
	}
	switch (i)
	{
		case 0 :
			tmp = new PresidentialPardonForm(target);
			break;
		case 1 :
			tmp = new RobotomyRequestForm(target);
			break;
		case 2 :
			tmp = new ShrubberyCreationForm(target);
			break;
		default :
			std::cout << "Invalid form name, try : <presidential pardon>, <robotomy request>, <shrubbery creation>." << std::endl;
			
	}
	return (tmp);
}
