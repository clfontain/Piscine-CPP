
#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/WrongAnimal.hpp"
#include "./include/WrongCat.hpp"

int main()
{
    //const Animal* i = new Animal();
    const Animal* j = new Dog();
    j->makeSound();
    delete j;
    return (0);
}