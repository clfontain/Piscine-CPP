#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"

int main()
{
	try
	{
		Form a22("A22", 25, 3);
		std::cout << a22 << std::endl;
		Bureaucrat bob("Bob", 25);
		bob.signForm(a22);
		std::cout << a22 << std::endl;
		Bureaucrat Gerard("Gerard", 26);
		Gerard.signForm(a22);
		Form a38("A38", 1, 2);
		Gerard.signForm(a38);
		Form a12("a12", 150, 150);
		Gerard.signForm(a12);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}