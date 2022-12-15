#include "./include/Span.hpp"

// Constructors
Span::Span() :_size(0)
{
}

Span::Span(unsigned int size) : _size(size)
{
}

Span::Span(const Span &copy) : _size(copy._size), _tab(copy._tab)
{
}


// Destructor
Span::~Span()
{

}

// Operators
Span & Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		this->_size = assign._size;
		this->_tab = assign._tab;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_tab.size() == _size)
		throw Span::Full();
	this->_tab.push_back(number);
}

void Span::addRange(std::vector<int>::iterator	begin, std::vector<int>::iterator end)
{
	if ((end - begin) + _tab.size() > _size)
		throw Span::Full();
	this->_tab.insert(_tab.end(), begin, end);
}

unsigned int Span::shortestSpan( void )
{
	if (_tab.size() <= 1)
		throw Span::Not_Enough();
	std::vector<int> path = this->_tab;
	std::sort(path.begin(), path.end());
	unsigned int stock;
	unsigned int res;

	stock = (-1 * (path[0] - path[0 + 1]));
	for (unsigned int i = 0; i < (_tab.size() - 1); i++)
	{
		res = (-1 * (path[i] - path[i + 1]));
		if (res < stock)
			stock = res;
	}
	return (stock);
}

unsigned int Span::longestSpan( void )
{
	if (_tab.size() <= 1)
		throw Span::Not_Enough();
	std::vector<int> path = this->_tab;
	std::sort(path.begin(), path.end());

	unsigned stock = path.back() - path.front();
	return (stock);
}

void	Span::print(void)
{
	std::vector<int>::iterator	it = this->_tab.begin();
	for (this->_tab.begin(); it != this->_tab.end(); it++)
		std::cout << *it << std::endl;
}
