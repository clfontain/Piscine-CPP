#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe bail;
	std::vector<int> a;
	std::cout << argc << std::endl;
	if (argc == 1)
		return (1);
	if (bail.create_arg(argc, argv) ==  1 || bail.create_list(argc, argv) == 1)
		return (1);
	return (0);
}
