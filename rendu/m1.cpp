

#include "cpp_module01/ASpell.hpp"
#include "cpp_module01/ATarget.hpp"
#include "cpp_module01/Fwoosh.hpp"
#include "cpp_module01/Dummy.hpp"
#include "cpp_module01/Warlock.hpp"

/*
Warlock.cpp Warlock.hpp

ASpell.hpp ASpell.cpp ATarget.hpp ATarget.cpp Fwoosh.hpp Fwoosh.cpp Dummy.hpp Dummy.cpp

c++ -Wall -Wextra -Werror m1.cpp cpp_module01/ASpell.cpp cpp_module01/ATarget.cpp cpp_module01/Fwoosh.cpp cpp_module01/Dummy.cpp cpp_module01/Warlock.cpp

*/


int main()
{
	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;
	Warlock* jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();
	delete jack;
	return (0);
}
