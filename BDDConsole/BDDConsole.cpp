// BDDConsole.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "BiblioCommands.h"
#include <map>
using BookList = std::vector<std::string>;

class BiblioManipulator : public BiblioInterface
{

private:
	std::map<std::string, BookList> m_Biblio;

public:
	bool createBiblio()final
	{
		return true;
	}

	bool addBook(const std::string& book)final
	{
		m_Biblio[""].push_back(book);
		return true;
	}

	bool addBook(const std::string& book, const std::string& author)final
	{
		m_Biblio[author].push_back(book);
		return true;
	}

	bool addAuthor(const std::string& author)final
	{
		m_Biblio[author];
		return true;
	}

	bool listBook()final
	{
		for (auto pair : m_Biblio)
		{
			for (auto book : pair.second)
				std::cout << book << std::endl;
		}
		return true;
	}

	bool listAuthor()final
	{
		for (auto pair : m_Biblio)
			std::cout << pair.first << std::endl;
		return true;
	}

	bool findBook(const std::string& author)final
	{
		auto pair = m_Biblio.find(author);
		if (pair != m_Biblio.end())
		{
			for (auto book : pair->second)
				std::cout << book << std::endl;
		}
		else
		{
			std::cout << "No book found." << std::endl;
		}
		return true;
	}

	bool findAuthor(const std::string& book)final
	{
		for (auto pair : m_Biblio)
		{
			if(std::find(pair.second.begin(), pair.second.end(), book) != pair.second.end())
				std::cout << pair.first << std::endl;
		}
		return true;
	}
};

int main()
{
    std::cout << "Bibliothèque" << std::endl;
	std::shared_ptr<BiblioInterface> pManipulator = std::make_shared<BiblioManipulator>();
	BiblioCommands cmd{ pManipulator };
    while (!cmd.request());
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
