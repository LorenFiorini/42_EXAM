
/*
ASpell.hpp ASpell.cpp ATarget.hpp ATarget.cpp Fwoosh.hpp Fwoosh.cpp Dummy.hpp Dummy.cpp
*/
#include "cpp_module01/ASpell.hpp"
#include "cpp_module01/ATarget.hpp"
#include "cpp_module01/Fwoosh.hpp"
#include "cpp_module01/Dummy.hpp"
#include "cpp_module01/Warlock.hpp"

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

