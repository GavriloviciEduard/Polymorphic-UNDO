#pragma once
#include "Movie.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include "RepositoryExceptions.h"




class Repository
{
	
	private:
		std::vector<Movie> list;
		std::string filename_in;


	public:

		Repository(const std::string& f_i);

		int add_repo(const Movie& mv);
		int remove_repo(const std::string& title,const int& year_ofr);
		int update_repo(const std::string& title,const int& year_ofr, const Movie& new_mv);
		int find_repo(const std::string title, const int& year_ofr);
		

		void increment_likes_repo(const std::string& title, const int& year_ofr);
		std::vector<Movie> filter_genre_repo(const std::string& genre);
		std::vector<Movie> filter_duration_repo(const int& dur);


		int get_sizeRE() { return (int)this->list.size(); }
		std::vector<Movie> get_repo() { return this->list; }
		void write_file();
		void read_file();

		Movie return_movie(const std::string& title, const int& year_ofr);


};