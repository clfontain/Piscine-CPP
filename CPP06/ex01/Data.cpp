#include "./include/Data.hpp"

// Constructors
Data::Data() : _test("string test")
{
	std::cout << "\e[0;33mDefault Constructor called of Data\e[0m" << std::endl;
}

Data::Data(const Data &copy) : _test(copy._test)
{

	std::cout << "\e[0;33mCopy Constructor called of Data\e[0m" << std::endl;
}


// Destructor
Data::~Data()
{
	std::cout << "\e[0;31mDestructor called of Data\e[0m" << std::endl;
}

// Operators
Data & Data::operator=(const Data &assign)
{
	this->_test = assign._test;
	return *this;
}

uintptr_t Data::serialize(Data* ptr)
{
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data* Data::deserialize(uintptr_t raw)
{
	Data * ret = reinterpret_cast<Data*>(raw);
	return (ret);
}
