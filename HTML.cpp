#include "HTML.h"
#include <Windows.h>
#include <shellapi.h>
#include "RepositoryExceptions.h"

void HTMLFILE::write_file()
{

	std::ofstream fout(this->filename);

	if (!fout.is_open())
		throw FileException("The file could not be opened!");

	fout << "<!DOCTYPE html>";
	fout << "<html>";	
	fout << "<head>";
	fout << "<title>Movie watch list</title>"; 
	fout << "<style>";
	fout << "body { background-color:MediumSeaGreen;}";
	fout << "</style>";
	fout << "</head>";
	fout << "<body>";
	fout << "<table align=""center"" border=""5"">";
	fout << "<tr>";
	fout << "<td>Title</td>";
	fout << "<td>Year</td>";
	fout << "<td>Genre</td>";
	fout << "<td>Duration</td>";
	fout << "<td>Youtube link</td>";
	fout << "</tr>";

	for (auto e : this->wlist)
	{
		fout << "<tr>";
		fout << "<td>" << e.get_title() << "</td>";
		fout << "<td>" << std::to_string(e.get_year()) << "</td>";
		fout << "<td>" << e.get_genre() << "</td>";
		fout << "<td>" << std::to_string(e.get_duration()) << "</td>";
		std::string aux = " \" ";
		aux+= e.get_trailer();
		aux += "\"";
		fout << "<td> <a href="<<aux<<">Link</a> </td>";
		fout << "</tr>";
	}

	fout << "</table>";
	fout << "</body>";
	fout << "</html>";

	fout.close();
}

void HTMLFILE::display_file() const
{

	ShellExecuteA(NULL, NULL, this->filename.c_str(),NULL, NULL, SW_SHOWMAXIMIZED);
}
