

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <algorithm>  
#include <stdio.h>
#include <time.h>
#include <limits>
#include <iomanip>


#define CHUNK 8

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cpy);
		PmergeMe&operator=(const PmergeMe &cpy);
		void	print_vector(std::vector<int> v);
		int		create_arg(int argc, char **argv);
		int		create_list(int argc, char **argv);
		int		process_arg();
		int		process_list();
		void	print_res_arg();
		void	print_res_list();
		int 	chunked(int beg, int end);
		void	bubble_sort(int beg, int end);
		void	bubble_sort_list(std::deque<int>::iterator beg,std::deque<int>::iterator end);
		int 	merge(int beg, int mid, int end);
		int 	merge_list(std::deque<int>::iterator beg, std::deque<int>::iterator mid, std::deque<int>::iterator end);
		void	print_list(std::deque<int> list);
		int 	chunked_list(std::deque<int>::iterator beg, std::deque<int>::iterator end);
		int 	parsing(int argc, char **argv);
	private:
		std::vector<int> arg;
		std::deque<int> list;
		clock_t v_time;
		clock_t v_time_end;
		clock_t d_time;
};


#endif
