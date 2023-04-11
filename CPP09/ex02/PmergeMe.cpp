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
void PmergeMe::copy_vec()
{
	for(size_t i = 0; i < v_pair.size(); i++)
	{
		v_sort.push_back(v_pair[i].first);
	}
}

int PmergeMe::insertion_sort( void)
{
	for (size_t i = 0; i < v_pair.size(); i++)
	{
		int elem = v_pair[i].second;
		int pos = binary_search(elem, 0, v_sort.size());
		std::vector<int>::iterator it = v_sort.begin();
		v_sort.insert(it + pos, elem);
	}
	if (this->odd != -1)
	{
		std::cout << this->odd << std::endl;
		int elem = odd;
		int pos = binary_search(elem, 0, v_sort.size());
		std::vector<int>::iterator it = v_sort.begin();
		v_sort.insert(it + pos, elem);
	}

	print_vector(v_sort);
	return (0);

}

int PmergeMe::binary_search(int elem, int beg, int end)
{
	if (end <= beg)
	{
		if (beg < (int)v_sort.size() && elem > v_sort[beg])
			return (beg + 1);
		else
			return (beg);
	}
	int mid = (beg + end) / 2;
	if (elem == v_sort[mid])
		return (mid + 1);
	 if (elem > v_sort[mid])
		return (binary_search(elem, mid + 1, end));
	return binary_search(elem, beg,mid - 1);
}

int	PmergeMe::process_arg()
{
	int beg;
	int end;
	print_vector(arg);
	make_pair();
	sort_pair();
	beg = 0;
	end = v_pair.size();
	merge_sort(beg, end - 1);
	copy_vec();
	insertion_sort();
	gettimeofday(&v_time_end, NULL);
	long long elapsed_time = (v_time_end.tv_sec - v_time.tv_sec) * CLOCKS_PER_SEC + (v_time_end.tv_usec - v_time.tv_usec);
	this->v_time_print = elapsed_time / 1000.0;
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
	
	//printf ("Time to process a range of %zu elements with std::[vector] : %f us.\n", this->v_sort.size() ,((float)v_time)/CLOCKS_PER_SEC);
	//std::cout.precision(7);
	std::cout << std::fixed << std::setprecision(6)<< "CPU time used: " << this->v_time_print<< std::endl;
	
}

void PmergeMe::print_res_list()
{

}


int PmergeMe::merge(int beg, int mid, int end)
{
	std::vector<int> v_beg;
	std::vector<int> v_end;
	for (int i = 0; i < (mid - beg + 1); i++)
		v_beg.push_back(v_pair[beg + i].first);
	for (int j = 0; j < (end - mid); j++)
		v_end.push_back(v_pair[mid + 1 + j].first);
	int i = 0;
	int j = 0;
	int k = beg;
	while (i < (mid - beg + 1) && j < (end - mid))
	{
		if (v_beg[i] <= v_end[j])
		{
			v_pair[k].first = v_beg[i];
			i++;
		}
		else 
		{
			v_pair[k].first = v_end[j];
			j++;
		}
		k++;
	}
	while (i < (mid - beg + 1))
	{
		v_pair[k].first = v_beg[i];
		i++;
		k++;
	}
	while (j < (end - mid))
	{
		v_pair[k].first = v_end[j];
		j++;
		k++;
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


void PmergeMe::sort_pair( void )
{
	int tmp;
	for (size_t i = 0; i < v_pair.size(); i++)
	{
		if (v_pair[i].first < v_pair[i].second)
		{
			tmp = v_pair[i].first;
			v_pair[i].first = v_pair[i].second;
			v_pair[i].second = tmp;
		}	
		//std::cout<< "A : " << v_pair[i].first << " B : " << v_pair[i].second << " ";
	}
}

int PmergeMe::make_pair( void )
{
	this->odd = -1;
	size_t size = arg.size();
	if (size % 2 != 0)
	{
		size--;
		std::cout << size <<" size : "<< arg[size] << std::endl;
		odd = arg[size];
		std::cout << odd << std::endl;
	}	
	//std::cout <<" arg size : "<< size << std::endl;
	for (size_t i = 0; i < size; i+= 2)
		v_pair.push_back(std::pair<int, int> (arg[i], arg[i + 1]));
	return (0);
}

int PmergeMe::merge_sort(int beg, int end)
{

	if (beg >= end)
		return (0);
	int len = beg + (end - beg) / 2;
	
	merge_sort(beg, len);
	merge_sort(len + 1, end);
	merge(beg, len, end);
	return (0);
}

int PmergeMe::create_arg(int argc, char **argv)
{
	bool is_sorted = true;
	gettimeofday(&v_time, NULL);
	//std::cout << v_time << std::endl;
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
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (i < (arg.size() - 1) && arg[i] > arg[i + 1])
			is_sorted = false;
	}	
	if (is_sorted == true)
	{
		std::cout << "Error\nALREADY SORTED\n"; 
		return (1);
	}	
	process_arg();
	return (0);	
}

int PmergeMe::create_list(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	d_time = clock();/*
	//std::cout << d_time << std::endl;
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
	process_list();*/
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
	std::cout << "[";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout<< v[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void	PmergeMe::print_vector_pair(std::vector<std::pair<int, int> > v)
{
	std::cout << "[";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout<< "A : " << v[i].first << " B : " << v[i].second << " ";
	}
	std::cout << "]" << std::endl;
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
	//std::cout << "[" << str  << "]" << std::endl;
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
