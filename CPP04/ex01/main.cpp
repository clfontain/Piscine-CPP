
#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/WrongAnimal.hpp"
#include "./include/WrongCat.hpp"

int main()
{
   {
        const Animal* j[30];
        for (int i = 0; i < 30; i++)
        {
            if (i < 15)
                j[i] = new Dog();
            else
                j[i] = new Cat();
        }

        for (int i = 0; i< 30; i++)
            j[i]->makeSound();
        for (int i = 0; i< 30; i++)
            delete j[i];
    }
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    {
        const Dog *e = new Dog();
        const Dog *f = new Dog(*e);
        std::cout << e->GetBrain()->GetIdea(0) << std::endl;
        std::cout << e->GetBrain()->GetIdea(4) << std::endl;
        std::cout << e->GetBrain()->GetIdea(5) << std::endl;
        std::cout << f->GetBrain()->GetIdea(0) << std::endl;
        std::cout << f->GetBrain()->GetIdea(4) << std::endl;
        std::cout << f->GetBrain()->GetIdea(5) << std::endl;
        std::cout << &e->GetBrain()->GetIdea(20) << std::endl;
        std::cout << &f->GetBrain()->GetIdea(20) << std::endl;
        e->GetBrain()->setIdea(20, "Alllooooo");
        std::cout << e->GetBrain()->GetIdea(20) << std::endl;
        std::cout << f->GetBrain()->GetIdea(20) << std::endl;
        delete e;
        delete f;
    }
    {
        const Cat *e = new Cat();
        const Cat *f = new Cat(*e);
        std::cout << e->GetBrain()->GetIdea(0) << std::endl;
        std::cout << f->GetBrain()->GetIdea(0) << std::endl;
        std::cout << &e->GetBrain()->GetIdea(50) << std::endl;
        std::cout << &f->GetBrain()->GetIdea(50) << std::endl;
        delete e;
        delete f;
    }
    return (0);
}