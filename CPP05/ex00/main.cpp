#include "./include/Bureaucrat.hpp"

int main()
{

	Bureaucrat i;
	(void)i;
	try
	{
		Bureaucrat a("Jean-Jean", 32);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.setGrade(20);
		std::cout << a << std::endl;
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat a("Bob", 151);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat a("Bob", 0);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat a("Bob", -20);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat a("Bob", 150);
		a.decrementGrade();
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat a("Bob", 1);
		a.incrementGrade();
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("Bob", 1);
		a.setGrade(5222);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}