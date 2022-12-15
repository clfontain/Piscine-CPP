#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		
		//Getter
		Brain* GetBrain( void ) const;

		void makeSound( void ) const ;
	private:
		Brain *_brain;
};

#endif

// virtual fonction membre permet d'utiliser la fonction a la compilation