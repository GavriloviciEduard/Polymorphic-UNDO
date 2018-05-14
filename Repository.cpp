#include "Repository.h"

std::ofstream fout("data_out.txt");


Repository::Repository(const std::string& f_i)
{
	this->filename_in = f_i;
	this->read_file();
}

int Repository::add_repo(const Movie& mv)
{
	int indx = find_repo(mv.get_title(),mv.get_year());

	if (indx == -1)
	{
		this->list.push_back(mv);
		return 1;
	}

	else
	{
		throw DuplicateMovieException();
		std::cout << '\n';
		return 0;
	}

	
}

int Repository::remove_repo(const std::string& title,const int& year_r)
{
	int indx = find_repo(title,year_r);

	if (indx != -1)
	{
		this->list.erase(this->list.begin() + indx);
		return 1;
	}

	else
	{
		throw NonMovieException();
		std::cout << '\n';
		return 0;
	}

	
}

int Repository::update_repo(const std::string& title, const int& year_ofr, const Movie& new_mv)
{
	int indx = find_repo(title,year_ofr);

	if (indx != -1)
	{
		this->list[indx] = new_mv;
		return 1;
	}

	else
	{
		throw NonMovieException();
		std::cout << '\n';
		return 0;
	}

	

}

int Repository::find_repo(const std::string title,const int& year)
{

	auto it = std::find_if(this->list.begin(), this->list.end(), [title, year](const Movie& M) {  return M.get_title() == title && M.get_year() == year; });
	int index = std::distance(this->list.begin(), it);

	if (index < (int)this->list.size())
		return index;

	else
		return -1;
}

void Repository::increment_likes_repo(const std::string& title, const int& year)
{
	int indx = find_repo(title, year);

	if (indx != -1)
		this->list[indx].increment_likes();
	
	else
	{
		throw NonMovieException();
		std::cout << '\n';
	}
}

std::vector<Movie>Repository::filter_genre_repo(const std::string& genre)
{
	std::vector<Movie> mv_genre;

	if (genre.empty())
		mv_genre = this->list;

	else
		std::copy_if(this->list.begin(), this->list.end(), std::back_inserter(mv_genre), [genre](const Movie& m) {return m.get_genre() == genre; });

	return mv_genre;

}

std::vector<Movie> Repository::filter_duration_repo(const int& dur)
{
	std::vector<Movie> mv_duration;

	std::copy_if(this->list.begin(), this->list.end(), std::back_inserter(mv_duration), [dur](const Movie& m) {return m.get_duration() < dur; });

	return mv_duration;
}

void Repository::read_file()
{
	std::ifstream fin(this->filename_in);

	if (!fin.is_open())
		throw FileException("The file could not be opened!");

	Movie M;
	while (fin >> M)
		this->list.push_back(M);

	fin.close();
}

Movie Repository::return_movie(const std::string& title, const int& year_ofr)
{
	int indx = find_repo(title, year_ofr);

	if(indx!=-1)
		return this->list[indx];
	

	else
	{
		Movie M;
		return M;
	}
}

void Repository::write_file()
{
	int i = 0;



	for (Movie M : this->list)
	{
		fout << ++i << ".";
		fout << M;
		fout << '\n' << '\n';
	}

	if (!this->list.size())
	{
		fout << "EMPTY";
		fout << '\n' << '\n';
	}

	fout << '\n' << "**********************************************************************************************************************" << '\n';

}
