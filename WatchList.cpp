#include "WatchList.h"



int WatchList::find_wlist(const std::string title, const int& year)
{
	auto it = std::find_if (this->wlist.begin(), this->wlist.end(), [title, year](const Movie& M) {return M.get_title() == title && M.get_year() == year; });
	int index = std::distance(this->wlist.begin(), it);

	if (index < (int)this->wlist.size())
		return index;

	else
		return -1;
}


int WatchList::add_wlist(const Movie& mv)
{
	int indx = find_wlist(mv.get_title(), mv.get_year());

	if (indx == -1)
	{
		this->wlist.push_back(mv);
		return 1;
	}

	return 0;
}

int WatchList::remove_wlist(const std::string& title, const int& year)
{
	int indx = find_wlist(title, year);

	if (indx != -1)
	{
		this->wlist.erase(this->wlist.begin() + indx);
		return 1;
	}

	return 0;
}

