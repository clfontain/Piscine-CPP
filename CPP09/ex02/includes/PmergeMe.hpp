

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
#include <sys/time.h>


class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cpy);
		PmergeMe& operator=(const PmergeMe &cpy);
		void	print_vector(std::vector<int> v);
		int		create_arg(int argc, char **argv);
		int		create_list(int argc, char **argv);
		int		process_arg();
		int		process_list();
		void	print_res_arg();
		void	print_res_list();
		void	sort_pair( void );
		void	copy_vec();
		int		binary_search(int elem, int beg, int end);
		int		binary_search_list(int elem, int beg, int end);
		int 	insertion_sort( void);
		int		insertion_list_sort( void);
		int 	merge(int beg, int mid, int end);
		int 	merge_list(int beg, int mid, int end);
		void	print_list(std::deque<int> list);
		void	print_list_pair(std::deque<std::pair<int, int> > v);
		void	print_vector_pair(std::vector<std::pair<int, int> > v);
		int 	merge_sort_list(std::deque<std::pair<int, int> >::iterator beg, std::deque<std::pair<int, int> >::iterator end);
		int 	parsing(int argc, char **argv);
		int		merge_sort(int beg, int end);
		int 	make_pair( void );
		int 	make_pair_list( void );
		void	sort_pair_list( void );
		void 	copy_list();

	private:
		std::vector<int> arg;
		std::vector<std::pair<int, int> > v_pair;
		std::vector<int> v_sort;
		std::deque<int> list;
		std::deque<std::pair<int, int> > l_pair;
		std::deque<int> l_sort;
		timeval v_time;
		timeval v_time_end;
		timeval l_time;
		timeval l_time_end;
		double v_time_print;
		double l_time_print;
		int v_odd;
		int l_odd;
};


#endif
