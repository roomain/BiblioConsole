#pragma once
#include <regex>
#include <memory>
#include "BiblioManipInterface.h"

class BiblioCommands
{
private:
	static std::regex m_regexCMDAddBook;
	static std::regex m_regexCMDAddAuthor;
	static std::regex m_regexCMDListBook;
	static std::regex m_regexCMDListAuthor;
	static std::regex m_regexCMDFindBook;
	static std::regex m_regexCMDFindAuthor;
	static std::regex m_regexCMDParam;
	static std::regex m_regexExit;
	static std::regex m_regexHelp;

	std::shared_ptr<BiblioInterface> m_pManipulator;
	static std::vector<std::string> extractValues(const std::string& svalue);
	static void displayHelp();
	
public:
	BiblioCommands(const std::shared_ptr<BiblioInterface> &manipulator);
	bool request();
};

