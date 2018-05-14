#include "Controller.h"

int Controller::add_controller(const std::string& title, const std::string& genre, const int& year_release, const int& nr_likes, const std::string& trailer,const int& duration)
{
	Movie m{ title,  genre, year_release,  nr_likes,  trailer,duration };

	this->validator.validate(m);
	int ok=this->repo.add_repo(m);


	UndoAction* a = new UndoAdd{this->repo,m};
	this->undos.push_back(a);

	return ok;
}

int Controller::remove_controller(const std::string& title, const int& year_release)
{
	Movie m = this->repo.return_movie(title, year_release);
	int ok=this->repo.remove_repo(title,year_release);
	

	if (ok)
	{
		UndoAction* a = new UndoRemove{ this->repo,m};
		this->undos.push_back(a);
	}

	return ok;
}

void Controller::undo_controller()
{
	
	if (this->undos.size())
	{
		this->undos[this->undos.size() - 1]->undo();
		this->undos.pop_back();
	}

	else
		throw EmptyUndo();
	
}

int Controller::update_controller(const std::string& title, const int& year_release, const std::string& new_title, const std::string& new_genre, const int& new_year_release, const int& new_nr_likes, const std::string& new_trailer,const int& new_duration)
{
	Movie new_m{new_title,new_genre,new_year_release,new_nr_likes,new_trailer,new_duration};


	this->validator.validate(new_m);
	return this->repo.update_repo(title,year_release,new_m);
}

int Controller::add_controller_wlst(const Movie& mv)
{
	return this->watch_list->add_wlist(mv);
}

int Controller::remove_controller_wlst(const std::string& title, const int& year_release)
{
	return this->watch_list->remove_wlist(title, year_release);
}

void Controller::increment_likes_cn(const std::string& title, const int& year_release)
{
	this->repo.increment_likes_repo(title,year_release);
}

std::vector<Movie> Controller::filter_genre(const std::string& genre)
{
	
		return this->repo.filter_genre_repo(genre);
}


std::vector<Movie> Controller::filter_duration_cn(const int & dr)
{
	return this->repo.filter_duration_repo(dr);
}

