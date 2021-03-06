#include <Windows.h>
#include "UI.h"
#include "HTML.h"
#include "CSV.h"

int main()
{
	system("color 02");
	FileBase* p = nullptr;

	try
	{

		Repository r{ "data_in.txt" };
		std::string aux;
		std::cout << "CSV or HTML?:";
		std::cin >> aux;

		if (aux == "CSV")
			p = new CSVFILE{};

		else
			p = new HTMLFILE{};


		MovieValidator v;
		Controller cr{ r,p,v };
		UI ui{ cr };


		std::cin.get();
		ui.start();
	}

	catch (FileException&)
	{
		std::cout << "Repository file could not be opened! The application will terminate." << '\n';
		return 1;
	}


	return 0;
}

