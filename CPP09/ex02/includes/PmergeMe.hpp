

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
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
		void	create_list(int argc, char **argv);
		int 	chunked(int beg, int end);
		void	bubble_sort(int beg, int end);
		void	bubble_sort_list(std::deque<int>::iterator beg,std::deque<int>::iterator end);
		int 	merge(int beg, int mid, int end);
		int 	merge_list(std::deque<int>::iterator beg, std::deque<int>::iterator mid, std::deque<int>::iterator end);
		void	print_list(std::deque<int> list);
		int 	chunked_list(std::deque<int>::iterator beg, std::deque<int>::iterator end);
	private:
		std::vector<int> arg;
		std::deque<int> list;

};


#endif
