#include "./include/Span.hpp"

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "====== MANDATORY TEST ======" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        Span span(6);
        span.addNumber(-214);
        span.addNumber(316);
        span.addNumber(12);
        std::cout << "====== OTHER TEST ======" << std::endl;
        std::cout << span.shortestSpan() << std::endl;
        std::cout << span.longestSpan() << std::endl;
    }

    {
        std::cout << "====== MASSIVE SPAN 10000 INT TEST ======" << std::endl;
        srand(time(NULL));
        Span massiveSpan(10000);
        std::vector<int>	v;
        for (int i = 0; i < 10000; i++)
        {
            
            const int value = rand();
            v.push_back(value);
        }
        massiveSpan.addRange(v.begin(), v.end());
        std::cout << massiveSpan.shortestSpan() << std::endl;
        std::cout << massiveSpan.longestSpan() << std::endl;
        //massiveSpan.print(); 
    }
    {
	    Span test(7);
	    std::vector<int>	v;
	    int	arr[]= {2, 23, 87, 534, 12};
        std::cout << "====== ADD ONE INT TEST ======" << std::endl;
	    test.addNumber(-42);
        test.print();
        std::cout << "====== NOT ENOUGH INT TEST ======" << std::endl;
        try
        {
            std::cout <<test.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout <<test.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
	    std::cout << "====== ADDRANGE TEST ======" << std::endl;
	    v.insert(v.end(), arr, arr + 5);
	    
	    std::cout << "======" << std::endl;
	    test.addRange(v.begin(), v.end());
	    test.print();
	    std::cout << "======" << std::endl;
        std::cout << "====== LONGEST TEST ======" << std::endl;
        std::cout <<test.longestSpan() << std::endl;
        std::cout << "====== SHORTEST TEST ======" << std::endl;
        std::cout <<test.shortestSpan() << std::endl;
        test.addNumber(12);
        std::cout << "====== FULL SPAN TEST ======" << std::endl;
        try
        {
            test.addNumber(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            test.addRange(v.begin(), v.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    {
        Span test(7);
	    std::vector<int>	v;
	    int	arr[]= {2, 23, 87, 534, 12};
        v.insert(v.end(), arr, arr + 5);
        test.addRange(v.begin(), v.end());
        std::vector<int>	v2;
	    int	arr2[]= {2, 23, 42};
        v2.insert(v2.end(), arr2, arr2 + 3);
        
        try
        {
            test.addRange(v2.begin(), v2.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}