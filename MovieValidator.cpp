#include "MovieValidator.h"

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> MovieException::get_errors() const
{
	return this->errors;
}

void MovieValidator::validate(const Movie & M)
{
	std::vector<std::string> errors;


	if (M.get_title().size() < 3)
		errors.push_back("The title name cannot be less than 2 characters!\n");
	if (M.get_genre().size() < 3)
		errors.push_back("The genre name cannot be less than 2 characters!\n");
	if (M.get_year()<1000)
		errors.push_back("The year cannot be less than 1000!\n");
	if(M.get_duration()<1)
		errors.push_back("The duration cannot be less than 1!\n");
	if(M.get_trailer().size()<9)
		errors.push_back("The trailer cannot be less than 9 characters!\n");

	
	if (errors.size() > 0)
		throw MovieException(errors);
}