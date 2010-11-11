#include <string>
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

void aff(std::string const& str)
{
  size_t len = count_char(str.getline());
  
  
}

int main()
{
  aff("1 2 3\n8 0 4\n7 6 5\n");
}
