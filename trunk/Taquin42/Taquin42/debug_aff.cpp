#include <string>
#include <sstream>
#include <vector>
#include "debug_aff.h"

unsigned int count_char(std::string const& str)
{
	unsigned int	max = str.size();
	unsigned int	ret = 0;
	char			prev = '0';

	for (unsigned int i = 0; i < max; ++i)
	{
		if (prev != ' ' && str.at(i) == ' ')
			ret++;
		prev = str.at(i);
	}
	return (ret + 1);
}

void					put_in_array(std::string const & str)
{
	int								**tab;
	std::istringstream				is(str);
	int								pos = str.find_first_of('\n');
	unsigned int					scale = count_char(str.substr(0, pos));

	tab = new int*[scale];
	for (unsigned int i = 0; i < scale; ++i)
	{
		tab[i] = new int[scale];
		for(unsigned int j = 0; j < scale; ++j)
			is >> tab[i][j];
	}

	for (unsigned int i = 0; i < scale; ++i)
	{
		for (unsigned int j = 0; j < scale; ++j)
			std::cout << tab[i][j] << "\t";
		std::cout << std::endl;
	}

}

void aff(std::string const& str)
{
	put_in_array(str);
}
