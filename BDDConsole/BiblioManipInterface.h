#pragma once
#include <string>

/// \brief interface pour la manipulation de la bibliothèque
class BiblioInterface
{
public:
	virtual bool createBiblio() = 0;
	virtual bool addBook(const std::string &book) = 0;
	virtual bool addBook(const std::string& book, const std::string& author) = 0;
	virtual bool addAuthor(const std::string& author) = 0;
	virtual bool listBook() = 0;
	virtual bool listAuthor() = 0;
	virtual bool findBook(const std::string& author) = 0;
	virtual bool findAuthor(const std::string& book) = 0;
};