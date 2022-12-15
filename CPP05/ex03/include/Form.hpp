#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form 
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
       	Form(const std::string name, const int GradeSigned, const int GradeExec);
        
		// Destructor
		virtual ~Form();
		
        Form &operator=(const Form &e);
        // Getter

        std::string getName( void ) const;
        bool getState( void ) const;
		int getSigned( void ) const;
        int getExec( void ) const;

        // Member function
        void beSigned(const Bureaucrat &e) ;
        void execute(Bureaucrat const & executor) const;
        virtual void to_execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Form : Grade too high");
            }
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Form : Grade too low");
            }
    };
    class AlreadySigned : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Form : is already signed");
            }
    };
    class IsnotSigned : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Form : is not signed");
            }
    };
    class FilenotOpen : public std::exception
    {
        public:
            virtual const char * what() const throw()
            {
                return ("Form : File not open");
            }
    };	
	private:
	const std::string _name;
	bool _state;
	const int _GradeSigned;
	const int _GradeExec;
};

std::ostream &operator<<(std::ostream &out, const Form &c);

#endif