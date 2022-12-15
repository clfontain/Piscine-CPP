#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack(void) { return ; };
		MutantStack(MutantStack<T> const &src) : std::stack<T>(src) { return ; };
		~MutantStack() { return ; };
		MutantStack & operator=(MutantStack const &rhs) { (void)rhs; return *this; };


		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin( void)
		{
			return (this->c.begin());
		}

		iterator end(  void )
		{
			return (this->c.end());
		}

		typedef typename MutantStack<T>::stack::container_type::reverse_iterator r_iterator;
		r_iterator rbegin( void)
		{
			return (this->c.rbegin());
		}

		r_iterator rend(  void )
		{
			return (this->c.rend());
		}

		typedef typename MutantStack<T>::stack::container_type::const_iterator c_iterator;
		c_iterator begin( void) const
		{
			return (this->c.cbegin());
		}

		c_iterator end(  void ) const
		{
			return (this->c.cend());
		}

		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator c_r_iterator;
		c_r_iterator rbegin( void) const
		{
			return (this->c.crbegin());
		}

		c_r_iterator rend(  void ) const
		{
			return (this->c.crend());
		}
	private:
		
};

#endif