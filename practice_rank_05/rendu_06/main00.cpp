
#include "./cpp_module00/Warlock.hpp"
#include <iostream>
#include <string>

// int main(void) {
// 	// Warlock bob;                            //Does not compile
// 	Warlock bob("Bob", "the magnificent");  //Compiles
// 	Warlock jim("Jim", "the nauseating");   //Compiles
// 	// bob = jim;                              //Does not compile
// 	// Warlock jack(jim);                      //Does not compile
// 	return 0;
// }


int main()
{
	// Warlock bob;                            //Does not compile
	// bob = jim;                              //Does not compile
	// Warlock jack(jim);                      //Does not compile
	// Warlock bob("Bob", "the magnificent");  //Compiles
	// Warlock jim("Jim", "the nauseating");   //Compiles

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
