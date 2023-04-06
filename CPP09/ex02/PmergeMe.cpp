#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	(void)cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
	(void)cpy;
	return (*this);
}


int	PmergeMe::process_arg()
{
	int beg;
	int end;
	beg = 0;
	end = arg.size();
	chunked(beg, end);
	v_time_end = clock();
	double test =  ((double) (v_time_end - v_time) / CLOCKS_PER_SEC) * 1000000;
	std::cout << test << std::endl;
	print_res_arg();
	return (0);
}

int PmergeMe::process_list()
{
	std::deque<int>::iterator it = list.begin(); 
	std::deque<int>::iterator it2 = list.end();
	chunked_list(it, it2);
	print_res_list();
	//print_list(list);
	//std::cout << "Is sorted "<< std::is_sorted(list.begin(), list.end()) << std::endl;
	return (0);
}

void PmergeMe::print_res_arg()
{
	
	//printf ("Time to process a range of %zu elements with std::[vector] : %f us.\n", this->arg.size() ,((float)v_time)/CLOCKS_PER_SEC);
	//std::cout.precision(7);
	//std::cout << std::fixed << std::setprecision(6) << "CPU time used: " << ((double) (v_time_end - v_time) / CLOCKS_PER_SEC) * 1000000 << std::endl;
	
}

void PmergeMe::print_res_list()
{

}

void PmergeMe::bubble_sort(int beg, int end)
{
 	int i = beg;
	int tmp;
	for (; i < end; i++)
	{
		int j = i + 1;
		for(;j < end; j++)
		{
			if (arg[j] < arg[i])
			{
				tmp = arg[i];
				arg[i] = arg[j];
				arg[j] = tmp;
			}
		}
	}
}


int PmergeMe::merge(int beg, int mid, int end)
{
	std::vector<int> v_beg;
	std::vector<int> v_end;
	for (int i = beg; i < mid; i++)
		v_beg.push_back(arg[i]);
	for (int i = mid; i < end; i++)
		v_end.push_back(arg[i]);
	
	size_t j = 0;
	size_t k = 0;
	for (size_t i = beg; i < (size_t)end; i++)
	{
		if (v_beg[j] < v_end[k])
		{
			if (j < v_beg.size())
			{
				arg[i] = v_beg[j];
				j++;
			}
			else if (k < v_end.size())
			{
				arg[i] = v_end[k];
				k++;
			}
		}	
		else if (k < v_end.size())
		{
			arg[i] = v_end[k];
			k++;
		}
		else
		{
			arg[i] = v_beg[j];
			j++;
		}
	}
	return (0);
}

void PmergeMe::bubble_sort_list(std::deque<int>::iterator beg, std::deque<int>::iterator end)
{
	std::deque<int>::iterator it;
	std::deque<int>::iterator it2;
	
	int swap;
	it = beg;
	for (; it != end; it++)
	{
		it2 = it;
		for(; it2 != end; it2++)
		{
			if (*it2 < *it)
			{
				swap = *it;
				*it = *it2;
				*it2 = swap;
			}
		}
	}
}

int 	PmergeMe::merge_list(std::deque<int>::iterator beg, std::deque<int>::iterator mid, std::deque<int>::iterator end)
{
	std::deque<int> tmp;
	std::deque<int>::iterator it = beg;
	std::deque<int>::iterator it2 = mid;
	//print_list(list);
	while (it != mid && it2 != end)
	{
		if (*it < *it2)
		{
			tmp.push_back(*it);
			it++;
		}
		else
		{
			tmp.push_back(*it2);
			it2++;
		}
	}
	while (it != mid)
	{
		tmp.push_back(*it);
			it++;
	}
	while (it2 != end)
	{
		tmp.push_back(*it2);
			it2++;
	}
	it = beg;
	it2 = tmp.begin();
	while (it != end)
	{
		*it = *it2;
		it++;
		it2++;
	}

	//print_list(list);
	//std::cout << "Is sorted "<< std::is_sorted(tmp.begin(), tmp.end()) << std::endl;
	return (0);
}

int PmergeMe::chunked_list(std::deque<int>::iterator beg, std::deque<int>::iterator end)
{
	int len = std::distance(beg, end);
	//std::cout << "chunked_list : len = " << len << "\n";
	if (len > CHUNK)
	{
		std::deque<int>::iterator mid;
		mid = beg;
		std::advance(mid, (std::distance(beg, end) / 2));
		chunked_list(beg, mid);
		chunked_list(mid, end);
		merge_list(beg, mid, end);
	}
	else
	{
		bubble_sort_list(beg, end);
	}
	return (0);
}

int PmergeMe::chunked(int beg, int end)
{
	int len = (end + beg) / 2;
	if (end - beg > CHUNK)
	{
		chunked(beg, len);
		chunked(len, end);
		merge(beg, len, end);
	}
	else
		bubble_sort(beg, end);
	return (0);
}

int PmergeMe::create_arg(int argc, char **argv)
{
	v_time = clock();
	std::cout << v_time << std::endl;
	if (parsing(argc, argv) == 1)
		return (1);
	for (int i = 1; i < argc; i++)
	{
		long long tmp = atoll(argv[i]);
		if (tmp > __INT_MAX__ || tmp == 0)
		{
			std::cout << "Error: " << tmp << " Not a valid number\n";
			return (1);
		}
		arg.push_back(tmp);
	}
	process_arg();
	return (0);	
}

int PmergeMe::create_list(int argc, char **argv)
{
	d_time = clock();
	std::cout << d_time << std::endl;
	if (parsing(argc, argv) == 1)
		return (1);
	for (int i = 1; i < argc; i++)
	{
		long long tmp = atoll(argv[i]);
		if (tmp > __INT_MAX__ || tmp == 0)
		{
			std::cout << "Error: " << tmp << " Not a valid number\n";
			return (1);
		}
		list.push_back(tmp);
	}
	process_list();
	return (0);
}

void	PmergeMe::print_list(std::deque<int> list)
{
	std::deque<int>::iterator it;

	for (it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


void	PmergeMe::print_vector(std::vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

int PmergeMe::parsing(int argc, char **argv)
{
	std::string str;
	int i = 1;
	while (i < argc)
	{
		str += argv[i];
		if (i < argc - 1)
			str += ' ';
		i++;
	}
	std::cout << "[" << str  << "]" << std::endl;
	for (size_t i = 0; i < str.size(); i++)
	{
		//std::cout <<"is isspace " <<isspace(str[i]) <<" digit : " << isdigit(str[i]) << std::endl;
		if (!isspace(str[i]) && !isdigit(str[i]))
		{
			std::cout << "Error: " << str[i] << " Not a valid char\n";
			return (1);
		}	
	}
	return (0);
}
