
// #include "cpp_module00/Warlock.hpp"

// int main00()
// {
// 	Warlock const richard("Richard", "Mistress of Magma");
// 	richard.introduce();
// 	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

// 	Warlock* jack = new Warlock("Jack", "the Long");
// 	jack->introduce();
// 	jack->setTitle("the Mighty");
// 	jack->introduce();

// 	delete jack;

// 	return (0);
// }

/* ASpell.hpp ASpell.cpp ATarget.hpp ATarget.cpp Fwoosh.hpp Fwoosh.cpp Dummy.hpp Dummy.cpp
 
cpp_module01/ASpell.cpp cpp_module01/ATarget.cpp cpp_module01/Fwoosh.cpp cpp_module01/Dummy.cpp cpp_module01/Warlock.cpp
*/


#include "cpp_module01/ASpell.hpp"
#include "cpp_module01/ATarget.hpp"
#include "cpp_module01/Fwoosh.hpp"
#include "cpp_module01/Dummy.hpp"
#include "cpp_module01/Warlock.hpp"

int main01()
{
	Warlock richard("Richard", "the Titled");

	{
		// ASpell a("Fwoosh", "fwooshed");
		// ATarget b("ATarget");
	}
	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();

	// richard.learnSpell(fwoosh);

	richard.introduce();
	// richard.launchSpell("Fwoosh", bob);

	// richard.forgetSpell("Fwoosh");
	// richard.launchSpell("Fwoosh", bob);
	return (0);

}



int main() {
	// main00();
	main01();

	return (0);
}
