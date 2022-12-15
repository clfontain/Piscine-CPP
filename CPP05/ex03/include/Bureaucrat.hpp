#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string.h>
#include <iostream>

class Form;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &cpy);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &cpy);

    // Getters
    std::string getName( void ) const;
    int getGrade( void ) const;

    // Setters
    void setGrade(const int grade);

    void incrementGrade( void );
    void decrementGrade( void );

    //
    void signForm(Form &e);
    void executeForm(Form const & Form);
    
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Bureaucrat : Grade too high");
            }
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Bureaucrat : Grade too low");
            }
    };
private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);

#endif