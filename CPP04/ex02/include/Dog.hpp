#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);
	
		// Getter
		Brain* GetBrain( void ) const; 

		void makeSound( void ) const ;
	private:
		Brain *_brain;
};

#endif