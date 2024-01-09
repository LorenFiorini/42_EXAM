
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

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
};

#endif
