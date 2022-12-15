#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
	std::string _type;

	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		Animal(std::string type);
		// Destructor
		virtual ~Animal();
		
		// Operators
		Animal & operator=(const Animal &assign);
		
		// Getters
		const std::string& GetType( void ) const; 

		virtual void makeSound( void ) const ;
		
};

#endif