#pragma once
#include <regex>

class BiblioCommands
{
private:
	static std::regex m_regexCMDAddBook;
	static std::regex m_regexCMDAddAuthor;
	static std::regex m_regexCMDListBook;
	static std::regex m_regexCMDListAuthor;
	static std::regex m_regexCMDFindBook;
	static std::regex m_regexCMDFindAuthor;

	//
	
public:
	BiblioCommands();

};

