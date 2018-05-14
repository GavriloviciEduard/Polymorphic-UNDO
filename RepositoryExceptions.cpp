#include "RepositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{""}
{
}

RepositoryException::RepositoryException(const std::string & msg): message{msg}
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateMovieException::what()
{
	return "There is another movie with the same title and year of release!";
}

const char * NonMovieException::what()
{
	return "The movie does not exist in the repository";
}

const char * EmptyUndo::what()
{
	return "The undo list is empty! Nothing to undo.";
}