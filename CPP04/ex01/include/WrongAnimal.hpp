#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
	std::string _type;

	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal(std::string type);
		// Destructor
		virtual ~WrongAnimal();
		
		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);
		
		// Getters
		const std::string& GetType( void ) const; 

		void makeSound( void ) const ;
		
};

#endif