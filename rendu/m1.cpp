
// #include "cpp_module01/Warlock.cpp"
#include "cpp_module01/ASpell.hpp"
#include "cpp_module01/ATarget.hpp"
#include "cpp_module01/Fwoosh.hpp"
#include "cpp_module01/Dummy.hpp"


// int main2()
// {
// 	Warlock richard("Richard", "the Titled");	

// 	Dummy bob;
// 	Fwoosh* fwoosh = new Fwoosh();	

// 	richard.learnSpell(fwoosh);	

// 	richard.introduce();
// 	richard.launchSpell("Fwoosh", bob);	

// 	richard.forgetSpell("Fwoosh");
// 	richard.launchSpell("Fwoosh", bob);
// 	return (0);
// }

int main1()
{
	Fwoosh a;
	Dummy b;

	// a.launch(b);

	return (0);
}

int main()
{
	main1();
	// main2();
	return (0);
}

/*
c++ -Wall -Wextra -Werror m1.cpp cpp_module01/Warlock.cpp cpp_module01/ASpell.cpp cpp_module01/ATarget.cpp cpp_module01/Fwoosh.cpp cpp_module01/Dummy.cpp

Warlock.cpp Warlock.hpp
ASpell.hpp  ATarget.hpp  Fwoosh.hpp  Dummy.hpp 


*/
