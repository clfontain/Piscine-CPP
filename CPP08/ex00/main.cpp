#include "./include/EasyFind.hpp"

int main()
{
    int res;
    int myints[] = { 10, 20, 30, 40 };
    int myints2[] = {};
    int myints3[] = {42};

    std::deque<int> d;
    d.push_front(2);
	d.push_front(7);
    std::vector<int> myvector (myints,myints+4);
    std::vector<int> myvector2 (myints2,myints2);
    std::vector<int> myvector3 (myints3,myints3+1);

    std::cout << "******** VECTOR TEST ********" << std::endl;
    res = easyfind(myvector, 20);
    std::cout << res << std::endl;
    try
    {
        res = easyfind(myvector, 32);
        std::cout << res << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << "Cannot find this value !" << std::endl;
    }
    try
    {
        res = easyfind(myvector2, 0);
        std::cout << res << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << "Cannot find this value !" << std::endl;
    }
    try
    {
        res = easyfind(myvector3, 42);
        std::cout << res << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << "Cannot find this value !" << std::endl;
    }



    std::cout << "******** DEQUE TEST ********" << std::endl;
    try
    {
        res = easyfind(d, 7);
        std::cout << res << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << "Cannot find this value !" << std::endl;
    }
    try
    {
        res = easyfind(d, 42);
        std::cout << res << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << "Cannot find this value !" << std::endl;
    }
    return (0);
}