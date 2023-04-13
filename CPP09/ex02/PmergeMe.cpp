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

void PmergeMe::copy_list()
{
	for(size_t i = 0; i < l_pair.size(); i++)
	{
		l_sort.push_back(l_pair[i].first);
	}
}

int PmergeMe::insertion_list_sort( void)
{
	for (size_t i = 0; i < l_pair.size(); i++)
	{
		int elem = l_pair[i].second;
		int pos = binary_search_list(elem, 0, l_sort.size());
		std::deque<int>::iterator it = l_sort.begin();
		l_sort.insert(it + pos, elem);
	}
	if (this->v_odd != -1)
	{
		int elem = v_odd;
		int pos = binary_search_list(elem, 0, l_sort.size());
		std::deque<int>::iterator it = l_sort.begin();
		l_sort.insert(it + pos, elem);
	}
	return (0);

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
	if (this->v_odd != -1)
	{
		int elem = v_odd;
		int pos = binary_search(elem, 0, v_sort.size());
		std::vector<int>::iterator it = v_sort.begin();
		v_sort.insert(it + pos, elem);
	}
	return (0);

}

int PmergeMe::binary_search_list(int elem, int beg, int end)
{
	if (end <= beg)
	{
		if (beg < (int)l_sort.size() && elem > l_sort[beg])
			return (beg + 1);
		else
			return (beg);
	}
	int mid = (beg + end) / 2;
	if (elem == l_sort[mid])
		return (mid + 1);
	 if (elem > l_sort[mid])
		return (binary_search_list(elem, mid + 1, end));
	return binary_search_list(elem, beg,mid - 1);
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
	make_pair();
	sort_pair();
	int end = v_pair.size();
	merge_sort(0, end - 1);
	copy_vec();
	insertion_sort();


	gettimeofday(&v_time_end, NULL);
	long long elapsed_time = (v_time_end.tv_sec - v_time.tv_sec) * 1000000LL + (v_time_end.tv_usec - v_time.tv_usec);
	this->v_time_print = elapsed_time / 1000.0;
	print_res_arg();

	//std::cout << "is sorted ? " << std::is_sorted(v_sort.begin(), v_sort.end()) << std::endl;
	return (0);
}

int PmergeMe::process_list()
{
	make_pair_list();
	sort_pair_list();
	std::deque<std::pair<int, int> >::iterator it = l_pair.begin(); 
	std::deque<std::pair<int, int> >::iterator it2 = l_pair.begin();
	std::advance(it2, l_pair.size() - 1);
	merge_sort_list(it, it2);
	copy_list();
	insertion_list_sort();


	gettimeofday(&l_time_end, NULL);
	long long elapsed_time = (l_time_end.tv_sec - l_time.tv_sec) * 1000000LL + (l_time_end.tv_usec - l_time.tv_usec);
	this->l_time_print = elapsed_time / 1000.0;
	print_res_list();

	//std::cout << "is sorted ? " << std::is_sorted(l_sort.begin(), l_sort.end()) << std::endl;
	return (0);
}

void PmergeMe::print_res_arg()
{
	std::cout << "Before:  ";
	print_vector(arg);
	std::cout << "After:   ";
	print_vector(v_sort);
	std::cout << std::fixed << std::setprecision(6)<< "Time to process a range of "<< this->arg.size() << " elements with std::[vector] : " << this->v_time_print << " us."<< std::endl;
}

void PmergeMe::print_res_list()
{
	std::cout << "Before:  ";
	print_list(list);
	std::cout << "After:   ";
	print_list(l_sort);
	std::cout << std::fixed << std::setprecision(6)<< "Time to process a range of "<< this->list.size() << " elements with std::[deque] : " << this->l_time_print << " us."<< std::endl;
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


int 	PmergeMe::merge_list(int beg, int mid, int end)
{
	std::deque<int> l_beg;
	std::deque<int> l_end;
	for (int i = 0; i < (mid - beg + 1); i++)
		l_beg.push_back(l_pair[beg + i].first);
	for (int j = 0; j < (end - mid); j++)
		l_end.push_back(l_pair[mid + 1 + j].first);
	int i = 0;
	int j = 0;
	int k = beg;
	while (i < (mid - beg + 1) && j < (end - mid))
	{
		if (l_beg[i] <= l_end[j])
		{
			l_pair[k].first = l_beg[i];
			i++;
		}
		else 
		{
			l_pair[k].first = l_end[j];
			j++;
		}
		k++;
	}
	while (i < (mid - beg + 1))
	{
		l_pair[k].first = l_beg[i];
		i++;
		k++;
	}
	while (j < (end - mid))
	{
		l_pair[k].first = l_end[j];
		j++;
		k++;
	}
	return (0);
}

void PmergeMe::sort_pair_list( void )
{
	int tmp;
	for (size_t i = 0; i < l_pair.size(); i++)
	{
		if (l_pair[i].first < l_pair[i].second)
		{
			tmp = l_pair[i].first;
			l_pair[i].first = l_pair[i].second;
			l_pair[i].second = tmp;
		}	
	}
}

int PmergeMe::make_pair_list( void )
{
	this->l_odd = -1;
	size_t size = list.size();
	if (size % 2 != 0)
	{
		size--;
		l_odd = list[size];
	}	
	for (size_t i = 0; i < size; i+= 2)
		l_pair.push_back(std::pair<int, int> (list[i], list[i + 1]));
	return (0);
}

int PmergeMe::merge_sort_list(std::deque<std::pair<int, int> >::iterator beg, std::deque<std::pair<int, int> >::iterator end)
{
	int first, last;

	first = std::distance(l_pair.begin(), beg);
	last = std::distance(l_pair.begin(), end);
	int len = first + (last - first) / 2;
	if (beg >= end)
		return (0);
	std::deque<std::pair<int, int> >::iterator mid = l_pair.begin();
	std::advance(mid, len);
	merge_sort_list(beg, mid);
	std::advance(mid, 1);
	merge_sort_list(mid, end);
	merge_list(first, len, last);
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
	}
}

int PmergeMe::make_pair( void )
{
	this->v_odd = -1;
	size_t size = arg.size();
	if (size % 2 != 0)
	{
		size--;
		v_odd = arg[size];
	}	
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

	gettimeofday(&l_time, NULL);
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

	for (it = list.begin(); it != list.end() && std::distance(list.begin(), it) < 4; it++)
	{
		std::cout << *it << " ";
	}
	if (list.size() > 4)
		std::cout << "[...]";
	std::cout << std::endl;
}


void	PmergeMe::print_vector(std::vector<int> v)
{
	for (size_t i = 0; i < v.size() && i < 4; i++)
	{
		std::cout<< v[i] << " ";
	}
	if (v.size() > 4)
		std::cout << "[...]";
	std::cout << std::endl;
}

void	PmergeMe::print_list_pair(std::deque<std::pair<int, int> > v)
{
	std::cout << "[";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout<< "A : " << v[i].first << " B : " << v[i].second << " ";
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
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isspace(str[i]) && !isdigit(str[i]))
		{
			std::cout << "Error: " << str[i] << " Not a valid char\n";
			return (1);
		}	
	}
	return (0);
}
