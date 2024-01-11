
#include "cpp_module01/Warlock.hpp"
#include "cpp_module01/ASpell.hpp"
#include "cpp_module01/ATarget.hpp"
#include "cpp_module01/Fwoosh.hpp"
#include "cpp_module01/Dummy.hpp"

/*
ASpell.hpp ASpell.cpp ATarget.hpp ATarget.cpp Fwoosh.hpp Fwoosh.cpp Dummy.hpp Dummy.cpp

Warlock.hpp: 7 + 4
ASpell.hpp: 5 + 4
ATarget.hpp: 2 + 4
Fwoosh.hpp: 2 + 4
Dummy.hpp: 3 + 4

*/

int main()
{
	Warlock richard("Richard", "the Titled");

	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();

	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);
	return (0);
}