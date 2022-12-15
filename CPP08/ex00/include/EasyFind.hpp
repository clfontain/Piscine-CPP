#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include <stdexcept>
# include <list>
#include <vector>
#include <deque>

template <typename T> 
int  easyfind(T container, int i)
{
	int res;
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::exception();
	res = *it;
	return (res);
}

#endif