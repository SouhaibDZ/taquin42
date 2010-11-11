#include <string>
#include <sstream>
#include "debug_aff.h"

size_t count_char(std::string const& str)
{
  size_t max = str.size();
  size_t ret = 0;

  for (size_t i = 0; i < max; ++i)
    {
      if (str.at(i) == ' ')
      ret++;
    }
  return (ret + 1);
}

void					put_in_array(std::string const & str)
{
  int					tab[3][3];
  std::istringstream	is(str);

  for(int i = 0; i < 3; ++i)
  {
     for(int j = 0; j < 3; ++j)
    {
      is >> tab[i][j];
      std::cout << tab[i][j];
    }
    std::cout << std::endl;
  }
}

void aff(std::string const& str)
{
 put_in_array(str);
}
