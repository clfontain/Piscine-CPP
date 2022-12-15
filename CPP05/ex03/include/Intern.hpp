#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
		//
		Form *makeForm(std::string form, std::string target);
	private:
		
};

#endif