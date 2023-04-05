
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\nNo args\n";
		return (1);
	}	
	Rpn test;
	if (test.process(argv[1]) == 1)
		return (1);
	else
		std::cout << test.getTop() << std::endl;
	return (0);
}
