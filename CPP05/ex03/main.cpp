#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Form* ptr;
	Bureaucrat a("Robert", 1);
	{
		try
		{
			ptr = someRandomIntern.makeForm("robotomy request", "Bender");

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (ptr != NULL)
		{
			a.signForm(*ptr);
			a.executeForm(*ptr);
		}
		delete ptr;
	}
	{
		try
		{
			ptr = someRandomIntern.makeForm("robotomy assa", "Bender");

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		if (ptr != NULL)
		{
			a.signForm(*ptr);
			a.executeForm(*ptr);
		}
		delete ptr;
	}	
	return (0);
}