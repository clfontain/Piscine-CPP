#include "./include/Data.hpp"

int main()
{
    Data data;
    Data *ptr_data;
    uintptr_t stock;
    
    std::cout << "string test         :" << data._test << std::endl;
    std::cout  << "adress string test  :"<< &data._test << std::endl;

    std::cout << "adress data         :" << &data << std::endl;
    stock = data.serialize(&data);
    std::cout << "convert value       :"<<stock << std::endl;
    ptr_data =  data.deserialize(stock);
    std::cout << "adress pointer data :"<< ptr_data << std::endl;
    std::cout << "adress data         :" << &data << std::endl;
    std::cout  << "adress string test  :"<< &data._test << std::endl;
}