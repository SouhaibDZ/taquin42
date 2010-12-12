#include "FileLoader.h"

FileLoader::FileLoader()
{
}

FileLoader::~FileLoader()
{
}

void				FileLoader::LoadFile(const std::string & Filename, std::string & out)
{
	std::string		tmp;

	out = "";
	this->OpenFile(Filename.c_str());
	while (std::getline(this->Infile, tmp))
		out += tmp + "\n";
	std::cout << "1- File Loaded !" << std::endl;
}

void				FileLoader::OpenFile(const std::string & Filename)
{
	this->Infile.open(Filename.c_str());
	if (! (this->Infile.is_open()))
		std::cerr << Filename << " : No such file or directory" << std::endl;
}

void				FileLoader::CloseFile(void)
{
	this->Infile.close();
}