#pragma once
#include <iostream>
#include <string>
#include "Utils.h"
#include <fstream>



class Movie
{
	private:
		
		std::string title;
		std::string genre;
		int year_release;
		int nr_likes;
		int duration;
		std::string trailer;


	public:

		Movie();
		Movie(const std::string& title, const std::string& genre, const int& year_release, const int& nr_likes, const std::string& trailer,const int& duration);

		std::string get_title() const { return title; }
		std::string get_genre() const { return genre; }
		int get_year() const{ return year_release; }
		int get_likes() const { return nr_likes; }
		void increment_likes() { this->nr_likes++; }
		std::string get_trailer() const { return trailer; }
		bool operator==(const Movie& mv);
		int get_duration() const { return this->duration; }
		std::string to_string();
		bool operator<(const int& nr);

		void play();


		friend std::istream& operator>>(std::istream& is, Movie& M);
		friend std::ostream& operator<<(std::ostream& os, const Movie& M);



};