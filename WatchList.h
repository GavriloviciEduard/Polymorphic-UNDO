#pragma once
#include "vector"
#include "Movie.h"
#include <algorithm>


class WatchList
{

protected:
	std::vector<Movie> wlist;

public:



	int add_wlist(const Movie& mv);
	int remove_wlist(const std::string& title, const int& year);
	int find_wlist(const std::string title, const int& year);

	int get_sizeWL() { return (int)this->wlist.size(); }
	std::vector<Movie> get_WL() { return this->wlist; }

	virtual ~WatchList() {}

		
};
