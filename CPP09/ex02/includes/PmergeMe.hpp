

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <algorithm>  


#define CHUNK 8

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cpy);
		PmergeMe&operator=(const PmergeMe &cpy);
		int	process();
		void	print_vector(std::vector<int> v);
		void	create_arg(int argc, char **argv);
		int 	chunked(int beg, int end);
		void	bubble_sort(int beg, int end);
		int 	merge(int beg, int mid, int end);
	private:
		std::vector<int> arg;


};


#endif
