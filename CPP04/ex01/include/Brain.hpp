#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);

		// Getter
		const std:: string &GetIdea(int index) const;
		
		// Setter
		void setIdea(int index, const std::string idea);
	private:
		std::string _ideas[100];
};

#endif