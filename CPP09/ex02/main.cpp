#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe bail;
	std::vector<int> a;
	if (argc == 1)
		return (1);
	bail.create_arg(argc, argv);
	bail.process();
	
	return (0);
}
