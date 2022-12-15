
#include "./include/MutantStack.hpp"

int main()
{
    {
		std::cout << "====== STACK ======" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size : " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << "====== PRINT STACK ======" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
        std::cout << "====== REVERSE STACK ITERATOR ======" << std::endl;
        MutantStack<int>::c_r_iterator rit = mstack.rbegin();
        MutantStack<int>::c_r_iterator rite = mstack.rend();
        while (rit != rite)
		{
			std::cout << *rit++ << std::endl;
		}
		std::stack<int> s(mstack);
		std::cout << "====== TEST CONST ITERATOR ======" << std::endl;
		*it = 42;
		std::cout << *it << std::endl;
		//*rit = 42;
	}
	{
		std::cout << "====== LIST ======" << std::endl;
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << mlist.back() << std::endl;

		mlist.pop_back();

		std::cout  << "Size : " << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;
		std::cout << "====== PRINT LIST ======" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::cout << "====== REVERSE LIST ITERATOR ======" << std::endl;
        std::list<int>::const_reverse_iterator rit = mlist.rbegin();
        std::list<int>::const_reverse_iterator rite = mlist.rend();
        while (rit != rite)
		{
			std::cout << *rit++ << std::endl;
		}
		std::cout << "====== TEST CONST ITERATOR ======" << std::endl;
		*it = 42;
		std::cout << *it << std::endl;
		//*rit = 42;
	}
    return 0;
}