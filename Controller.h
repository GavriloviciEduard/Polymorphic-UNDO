#pragma once
#include "Repository.h"
#include "FileBase.h"
#include "MovieValidator.h"
#include "UndoAction.h"
#include "UndoAdd.h"
#include "UndoRemove.h"


class Controller
{
	private:
		Repository repo;
		FileBase* watch_list;
		MovieValidator validator;
		std::vector<UndoAction*> undos;

	public:
		
		Controller(const Repository& r, FileBase* w, MovieValidator v) : repo{ r }, watch_list{ w }, validator{v} {}

		int add_controller(const std::string& title, const std::string& genre, const int& year_release, const int& nr_likes, const std::string& trailer,const int& duration);
		int remove_controller(const std::string& title, const int& year_release);
		int update_controller(const std::string& title, const int& year_release,const std::string& new_title,const std::string& new_genre,const int& new_year_release,const int& new_nr_likes,const std::string& new_trailer,const int& duration);
	

		int add_controller_wlst(const Movie& mv);
		int remove_controller_wlst(const std::string& title, const int& year_release);
		void increment_likes_cn(const std::string& title, const int& year_release);

		std::vector<Movie> filter_genre(const std::string& genre);
		std::vector<Movie> filter_duration_cn(const int& dr);

		int get_sizeWL() { return this->watch_list->get_sizeWL(); }
		std::vector<Movie> get_WL() { return this->watch_list->get_WL(); }

		int get_sizeRE() { return this->repo.get_sizeRE(); }
		std::vector<Movie> get_repo() { return this->repo.get_repo(); }

		void writeF_repo() { this->repo.write_file(); }
		
		void writeF_wl() { this->watch_list->write_file(); }
		void openF() { this->watch_list->display_file(); }

		void undo_controller();
};