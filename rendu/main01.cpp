
#include "cpp_module01/Warlock.hpp"
#include "cpp_module01/ASpell.hpp"
#include "cpp_module01/ATarget.hpp"
#include "cpp_module01/Fwoosh.hpp"
#include "cpp_module01/Dummy.hpp"

/* 
ASpell.hpp ASpell.cpp ATarget.hpp ATarget.cpp Fwoosh.hpp Fwoosh.cpp Dummy.hpp Dummy.cpp
*/


// int main()
// {
//   Warlock richard("Richard", "the Titled");

//   Dummy bob;
//   Fwoosh* fwoosh = new Fwoosh();

//   richard.learnSpell(fwoosh);

//   richard.introduce();
//   richard.launchSpell("Fwoosh", bob);

//   richard.forgetSpell("Fwoosh");
//   richard.launchSpell("Fwoosh", bob);
// }

int main()
{
	Fwoosh a;
	Dummy b;
	Fwoosh *c;
	Dummy *d;

	c = new Fwoosh();
	d = new Dummy();

	delete c;
	delete d;
	return (0);
}

/*

c++ -Wall -Wextra -Werror main01.cpp cpp_module01/Warlock.cpp cpp_module01/ASpell.cpp cpp_module01/ATarget.cpp cpp_module01/Fwoosh.cpp cpp_module01/Dummy.cpp -I./cpp_module01

*/
