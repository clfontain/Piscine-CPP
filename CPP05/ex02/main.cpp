#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat e("Bob", 130);
		//e.signForm(Form &a("A", 1));
		ShrubberyCreationForm i("test");
		Bureaucrat f("Joe", 2);
		e.signForm(i);
		f.executeForm(i);
		RobotomyRequestForm a("oui");
		f.signForm(a);
		f.executeForm(a);
		PresidentialPardonForm b("Albert");
		f.signForm(b);
		f.executeForm(b);
		Bureaucrat nul("Le nullos", 150);
		PresidentialPardonForm c("Roger");
		nul.executeForm(c);

	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}