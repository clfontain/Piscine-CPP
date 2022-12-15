#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>



template <typename T> void iter(T* tab, size_t i, void (*function)(T const & j))
{
    for (size_t j = 0; j < i; j++)
        function(tab[j]);
}

#endif