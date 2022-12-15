#include "./include/Iter.hpp"


 
template <typename T> 
void print_elem(T const & elem)
{
	std::cout << elem;
	return;
}


int main(int, char**)
{
	char str[] = "Bonjour Paris";
	int tab[] = { 0, 1, 2, 3, 4, -42, 88  }; 

	iter(str, 13, print_elem<char>);
	std::cout << std::endl;
	iter(tab, 7, print_elem<int>);
	std::cout << std::endl;
	std::cout << str << std::endl;
	return 0;
}

