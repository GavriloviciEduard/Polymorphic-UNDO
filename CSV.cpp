#include "CSV.h"
#include <Windows.h>
#include "RepositoryExceptions.h"


void CSVFILE::write_file()
{

	std::ofstream fout(this->filename);
	
	if(!fout.is_open())
		throw FileException("The file could not be opened!");

	for (auto e : this->wlist)
		fout << e<<'\n';

	fout.close();
}

void CSVFILE::display_file() const
{
	std::string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\Office16\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
