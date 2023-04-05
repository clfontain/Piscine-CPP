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


int	PmergeMe::process()
{
	int beg;
	int end;
	beg = 0;
	end = arg.size();
	chunked(beg, end);
	return (0);
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

void PmergeMe::create_arg(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		arg.push_back(atoi(argv[i]));
	}	
}

void	PmergeMe::print_vector(std::vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}
