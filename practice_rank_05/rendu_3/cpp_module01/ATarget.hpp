


#ifndef ATARGET_HPP
# define ATARGET_HPP
# include <string>
# include <iostream>

class ATarget
{
	protected:
		std::string _type;
		ATarget(void);

	public:
		ATarget(ATarget &src);
		ATarget	&operator=(ATarget &src);
		ATarget(std::string const &type);
		virtual ~ATarget(void);

		std::string	const &getType(void) const;

		virtual ATarget	*clone() const = 0;

		void getHitBySpell(ASpell const &spell) const;
};

#endif

