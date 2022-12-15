#include "./include/Base.hpp"


void identify(Base *p)
{
    A *ptr1;
    B *ptr2;
    C *ptr3;

    std::cout << "******** Pointer function *********" << std::endl;
    ptr1 = dynamic_cast<A*>(p);
    if (ptr1 != NULL)
        std::cout << "Base is A" << std::endl;
    ptr2 = dynamic_cast<B*>(p);
    if (ptr2 != NULL)
        std::cout << "Base is B" << std::endl;
    ptr3 = dynamic_cast<C*>(p);
    if (ptr3 != NULL)
        std::cout << "Base is C" << std::endl;        
}

void identify(Base &p)
{
    std::cout << "******** Reference function *********" << std::endl;
    try
    {
        A &ptr1 = dynamic_cast<A&>(p);
        (void)ptr1;
        std::cout << "Base is A" << std::endl;
        return ;
    }
    catch(...)
    {

    }
    try
    {
        B &ptr1 = dynamic_cast<B&>(p);
        (void)ptr1;
        std::cout << "Base is B" << std::endl;
        return ;
    }
    catch(...)
    {

    }
    try
    {
        C &ptr1 = dynamic_cast<C&>(p);
        (void)ptr1;
        std::cout << "Base is C" << std::endl;
    }
    catch(...)
    {

    }
}

Base * generate(void)
{
	std::srand(std::time(0));
    int rand = std::rand();
    Base *ptr;
    ptr = NULL;
	if (rand % 3 == 0)
        ptr = new A;
	else if (rand % 3 == 1)
		ptr = new B;
    else if (rand % 3 == 2)
        ptr = new C;
    return (ptr);
}

int main()
{
    Base *ptr;
    ptr = generate();
    identify(ptr);
    identify(*ptr);
}