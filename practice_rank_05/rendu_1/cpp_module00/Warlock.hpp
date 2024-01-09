
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

<<<<<<< HEAD
class Warlock {
private:
	std::string	_name;
	std::string	_title;

	Warlock(void);
	Warlock(Warlock &src);
	Warlock& operator=(Warlock &src);

public:
	const std::string &getName(void) const;
	const std::string &getTitle(void) const;

	void setTitle(const std::string &title);

	Warlock(const std::string &name, const std::string &title);
	~Warlock(void);

	void introduce(void) const;
=======
class Warlock
{
    private:
        std::string _name;
        std::string _title;
        Warlock(void);                  // private default constructor
        Warlock(Warlock const &src);    // private copy constructor
    public:
        Warlock(std::string const &name, std::string const &title); // public constructor
        ~Warlock();                                            // public destructor 
        
        // Getters and setters
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);

        // Member functions
        void introduce() const;    
>>>>>>> my_main
};

#endif
