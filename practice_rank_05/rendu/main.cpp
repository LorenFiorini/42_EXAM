
#include "cpp_module02/ASpell.hpp"
#include "cpp_module02/ATarget.hpp"
#include "cpp_module02/Fwoosh.hpp"
#include "cpp_module02/Dummy.hpp"
#include "cpp_module02/Fireball.hpp"
#include "cpp_module02/Polymorph.hpp"
#include "cpp_module02/BrickWall.hpp"
#include "cpp_module02/SpellBook.hpp"
#include "cpp_module02/TargetGenerator.hpp"
#include "cpp_module02/Warlock.hpp"

int main()
{
    // {
    //     Warlock const richard("Richard", "Mistress of Magma");
    //     richard.introduce();
    //     std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

    //     Warlock* jack = new Warlock("Jack", "the Long");
    //     jack->introduce();
    //     jack->setTitle("the Mighty");
    //     jack->introduce();

    //     delete jack;
    // }

    // {
    //     Warlock richard("Richard", "the Titled");

    //     Dummy bob;
    //     Fwoosh* fwoosh = new Fwoosh();

    //     richard.learnSpell(fwoosh);

    //     richard.introduce();
    //     richard.launchSpell("Fwoosh", bob);

    //     richard.forgetSpell("Fwoosh");
    //     richard.launchSpell("Fwoosh", bob);
    // }

    {
        Warlock richard("Richard", "foo");
        richard.setTitle("Hello, I'm Richard the Warlock!");
        BrickWall model1;

        Polymorph* polymorph = new Polymorph();
        TargetGenerator tarGen;

        tarGen.learnTargetType(&model1);
        richard.learnSpell(polymorph);

        Fireball* fireball = new Fireball();

        richard.learnSpell(fireball);

        ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

        richard.introduce();
        richard.launchSpell("Polymorph", *wall);
        richard.launchSpell("Fireball", *wall);
    }
    return (0);
}


/*
c++ -Wall -Wextra -Werror main.cpp cpp_module00/Warlock.cpp

 ASpell.hpp ASpell.cpp ATarget.hpp ATarget.cpp Fwoosh.hpp Fwoosh.cpp Dummy.hpp Dummy.cpp

c++ -Wall -Wextra -Werror main.cpp  cpp_module01/ASpell.cpp cpp_module01/ATarget.cpp cpp_module01/Fwoosh.cpp cpp_module01/Dummy.cpp cpp_module01/Warlock.cpp

				   Fireball.hpp Fireball.cpp
				   Polymorph.hpp Polymorph.cpp
				   BrickWall.hpp BrickWall.cpp
				   SpellBook.hpp SpellBook.cpp
				   TargetGenerator.hpp TargetGenerator.cpp


c++ -Wall -Wextra -Werror main.cpp  cpp_module02/ASpell.cpp cpp_module02/ATarget.cpp cpp_module02/Fwoosh.cpp cpp_module02/Dummy.cpp cpp_module02/Warlock.cpp cpp_module02/Fireball.cpp cpp_module02/Polymorph.cpp cpp_module02/BrickWall.cpp cpp_module02/SpellBook.cpp cpp_module02/TargetGenerator.cpp

*/

