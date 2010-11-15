#include "debug_aff.h"

int main()
{
	std::cout << "Taquin A1:" << std::endl;
	aff("1 2\n0 3");

	std::cout << std::endl << "Taquin A2:" << std::endl;
	aff("1 2 3\n8 0 4\n7 6 5\n");
	std::cout << std::endl << "Taquin A3:" << std::endl;
	aff("1  2  3  4  5\n16 17 18 19 6\n15 24 0  20 7\n14 23 22 21 8\n13 12 11 10 9\n");
}
