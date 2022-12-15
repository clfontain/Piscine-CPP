#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class PresidentialPardonForm : public Form
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
		void to_execute(Bureaucrat const & executor) const;
	private:
	const std::string _target;
};

#endif