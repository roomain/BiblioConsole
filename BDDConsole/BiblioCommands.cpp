#include "BiblioCommands.h"
#include <iostream>

std::regex BiblioCommands::m_regexCMDAddBook{"add (-B \".+\")|(-B \".+\" -A \".+\")", std::regex::icase };
std::regex BiblioCommands::m_regexCMDAddAuthor{ "add -A \".+\"", std::regex::icase };
std::regex BiblioCommands::m_regexCMDListBook{"list -B", std::regex::icase };
std::regex BiblioCommands::m_regexCMDListAuthor{"list -A", std::regex::icase };
std::regex BiblioCommands::m_regexCMDFindBook{"find -B \".+\"", std::regex::icase };
std::regex BiblioCommands::m_regexCMDFindAuthor{ "find -A \".+\"", std::regex::icase };
std::regex BiblioCommands::m_regexCMDParam{ "\"(.+)\"", std::regex::icase };
std::regex BiblioCommands::m_regexExit{ "exit", std::regex::icase };
std::regex BiblioCommands::m_regexHelp{ "help", std::regex::icase };

void BiblioCommands::displayHelp()
{
	std::cout << "-------- HELP" << std::endl;
	std::cout << "add -b \"<book name>\" [-a \"<author name>\"]" << "\t Add new book" << std::endl;
	std::cout << "add -a \"<author name>\"                     " << "\t Add new author" << std::endl;
	std::cout << "find -b \"<author name>\"                    " << "\t find book by author name" << std::endl;
	std::cout << "find -a \"<book name>\"                      " << "\t find author by bookname" << std::endl;
	std::cout << "list -a                                      " << "\t list book" << std::endl;
	std::cout << "list -a                                      " << "\t list author" << std::endl;
	std::cout << "help                                         " << "\t help" << std::endl;
	std::cout << "exit                                         " << "\t exit application" << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

std::vector<std::string> BiblioCommands::extractValues(const std::string& svalue)
{
	std::vector<std::string> vTitle;

	int iIndex = 0;
	std::vector<int> vQuotePos;
	for (auto character : svalue)
	{
		if (character == '\"')
			vQuotePos.push_back(iIndex);

		iIndex++;
	}
	const int iCount = vQuotePos.size();

	for (int i = 0; i < iCount; i += 2)// suppose iCount>=2
	{
		vTitle.push_back(svalue.substr(vQuotePos[i] + 1, vQuotePos[i + 1] - vQuotePos[i] -1));
	}
	return vTitle;
}

BiblioCommands::BiblioCommands(const std::shared_ptr<BiblioInterface>& pManipulator) : m_pManipulator{ pManipulator }
{
	if (m_pManipulator)
		m_pManipulator->createBiblio();
	displayHelp();
}

bool BiblioCommands::request()
{
	bool bExit = false;
	std::string sCommands;
	std::cout << "Biblio commands >";
	std::getline(std::cin, sCommands);

	if (std::regex_match(sCommands, BiblioCommands::m_regexCMDAddBook))
	{
		std::cout << "----add book----" << std::endl;
		if (m_pManipulator)
		{
			std::vector<std::string> vParam = BiblioCommands::extractValues(sCommands);
			switch (vParam.size())
			{
			case 1:
				m_pManipulator->addBook(vParam[0]);
				break;

			case 2:
				m_pManipulator->addBook(vParam[0], vParam[1]);
				break;

			default:
				break;
			}
		}
	}
	else if (std::regex_match(sCommands, BiblioCommands::m_regexCMDAddAuthor))
	{
		std::cout << "----add author----" << std::endl;
		if (m_pManipulator)
		{
			std::vector<std::string> vParam = BiblioCommands::extractValues(sCommands);
			if(vParam.size() == 1)
				m_pManipulator->addAuthor(vParam[0]);
		}
	}
	else if (std::regex_match(sCommands, BiblioCommands::m_regexCMDListBook))
	{
		std::cout << "----list book----" << std::endl;
		if (m_pManipulator)
		{
			m_pManipulator->listBook();
		}
	}
	else if (std::regex_match(sCommands, BiblioCommands::m_regexCMDListAuthor))
	{
		std::cout << "----list author----" << std::endl;
		if (m_pManipulator)
		{
			m_pManipulator->listAuthor();
		}
	}
	else if (std::regex_match(sCommands, BiblioCommands::m_regexCMDFindBook))
	{
		std::cout << "----find book----" << std::endl;
		if (m_pManipulator)
		{
			std::vector<std::string> vParam = BiblioCommands::extractValues(sCommands);
			if (vParam.size() == 1)
				m_pManipulator->findBook(vParam[0]);
		}
	}
	else if (std::regex_match(sCommands, BiblioCommands::m_regexCMDFindAuthor))
	{
		std::cout << "----find author----" << std::endl;
		if (m_pManipulator)
		{
			std::vector<std::string> vParam = BiblioCommands::extractValues(sCommands);
			if (vParam.size() == 1)
				m_pManipulator->findAuthor(vParam[0]);
		}
	}
	else if (std::regex_match(sCommands, BiblioCommands::m_regexExit))
	{
		std::cout << "----exit----" << std::endl;
		bExit = true;
	}
	else if (std::regex_match(sCommands, BiblioCommands::m_regexHelp))
	{
		displayHelp();
	}
	else
	{
		std::cout << "wrong command!" << std::endl;
	}

	return bExit;
}