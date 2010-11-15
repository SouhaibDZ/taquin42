#ifndef __FILELOADER_H__
#define __FILELOADER_H__

#include <iostream>
#include <fstream>
#include <string>

class				FileLoader
{
public:
	FileLoader();
	~FileLoader();

private:
	FileLoader(const FileLoader &);
	FileLoader &	operator=(const FileLoader &);

public:
	void				LoadFile(const std::string &, std::string&);
	void				OpenFile(const std::string &);
	void				CloseFile(void);

private:
	std::fstream		Infile;
};

#endif //__FILELOADER_H__