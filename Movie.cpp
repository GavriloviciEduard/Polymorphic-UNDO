#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>

Movie::Movie() :title{ "" }, genre{ "" }, year_release{ 0 }, nr_likes{ 0 }, trailer{ "" }, duration{0} {}

Movie::Movie(const std::string& title, const std::string& genre, const int& year_release, const int& nr_likes, const std::string& trailer,const int& duration)
{
	this->title = title;
	this->genre = genre;
	this->year_release = year_release;
	this->nr_likes = nr_likes;
	this->trailer = trailer;
	this->duration = duration;
}



bool Movie::operator==(const Movie& mv)
{
	return this->title == mv.title && this->genre == mv.genre && this->year_release == mv.year_release && this->trailer == mv.trailer && mv.nr_likes == this->nr_likes;
}



bool Movie::operator<(const int& nr)
{
	return this->duration < nr;
}


std::string Movie::to_string()
{
	std::string str= "Title: " + this->title + " ----- " + "Genre: " + this->genre + " ----- " + "Year of release: " + std::to_string(this->year_release) + " ----- "
		+ "Number of likes: " + std::to_string(this->nr_likes) + " ----- " + "Duration: " + std::to_string(this->duration) + " minutes";

	return str;
}


void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_trailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::istream & operator>>(std::istream& is, Movie & M)
{
	std::string str;

	std::getline(is, str);

	
	if (str.size())
	{
		std::vector<std::string> v = split(str, ",");

		M.title = v[0];
		M.genre = v[1];
		M.year_release = std::stoi(v[2]);
		M.nr_likes = std::stoi(v[3]);
		M.trailer = v[4];
		M.duration = std::stoi(v[5]);
	}
	

	return is;
}

std::ostream & operator<<(std::ostream& os, const Movie& M)
{
	os << "Title: " << M.get_title() << "," << "Genre: " << M.get_genre() << "," << "Year of release: " << std::to_string(M.get_year()) << ","
		<< "Number of likes: " << std::to_string(M.get_likes()) << "," << "Duration: " << std::to_string(M.get_duration()) << " minutes";

	return os;
}
