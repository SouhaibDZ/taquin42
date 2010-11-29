#include "SolutionGenerator.hpp"
#include <iostream>

SolutionGenerator::SolutionGenerator(const int Scale)
{
	std::cout << "Solution Generating ....." << std::endl;
	this->X_min = 0;
	this->X_max = 0;
	this->X_cur = 0;
	this->Y_min = 0;
	this->Y_max = 0;
	this->Y_cur = 0;
	this->Num = 1;
	this->PuzzleScale = Scale;
}

SolutionGenerator::~SolutionGenerator() {}

void				SolutionGenerator::FillTop()
{
	while (this->X_cur < this->X_max)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->X_cur++;
		this->Num++;
	}
	this->X_cur--;
	this->X_max--;
	this->Y_cur++;
}

void				SolutionGenerator::FillRight()
{
	while (this->Y_cur < this->Y_max)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->Y_cur++;
		this->Num++;
	}
	this->Y_cur--;
	this->Y_max--;
	this->X_cur--;
}

void				SolutionGenerator::FillBottom()
{
	while (this->X_cur > this->X_min - 1)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->X_cur--;
		this->Num++;
	}
	this->X_cur++;
	this->X_min++;
	this->Y_cur--;
}

void				SolutionGenerator::FillLeft()
{
	while (this->Y_cur > this->Y_min)
	{
		this->Witness[this->X_cur][this->Y_cur] = this->Num;
		this->Y_cur--;
		this->Num++;
	}
	this->Y_cur++;
	this->Y_min++;
	this->X_cur++;
}

bool				SolutionGenerator::GenerateSolution()
{
	if (this->PuzzleScale > 100)
	{
		std::cerr << "The taquin is too big" << std::endl;
		return (false);
	}
	this->X_max = this->Y_max = this->PuzzleScale;
	this->Witness = new int*[this->PuzzleScale];
	for (int i = 0; i < this->PuzzleScale; i++)
		this->Witness[i] = new int[this->PuzzleScale];
	while (this->X_min <= this->X_max && this->Y_min <= this->Y_max)
	{
		this->FillTop();
		this->FillRight();
		this->FillBottom();
		this->FillLeft();
	}
	// This part is a debug displaying , can be removed after.
	this->DisplaySolution();
	return (true);
}

void				SolutionGenerator::DisplaySolution() const
{
	for (int i = 0; i < this->PuzzleScale; ++i)
	{
		for (int j = 0; j < this->PuzzleScale; ++j)
		{
			if (this->Witness[i][j] == this->PuzzleScale * this->PuzzleScale)
				this->Witness[i][j] = 0;
			std::cout << this->Witness[j][i] << "\t";
		}
		std::cout << std::endl;
	}
}
