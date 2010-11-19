#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include <iostream>
#include <string>
#include <vector>

class										Puzzle
{
public:
	Puzzle();
	~Puzzle();

private:
	Puzzle(const Puzzle &);
	Puzzle &								operator=(const Puzzle &);

public:
	const std::vector<std::vector <int> > &	GetMap(void) const;
	void									CreatePuzzle(const std::string &);
	bool									GenerateSolution(int PuzzleScale);

private:
	unsigned int							CountScales(const std::string &) const;

private:
	std::vector<std::vector <int> >			PuzzleMap;
};

#endif //__PUZZLE_H__
