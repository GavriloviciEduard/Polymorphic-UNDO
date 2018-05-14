#include "UndoAdd.h"


void UndoAdd::undo()
{
	this->repo.remove_repo(this->movie.get_title(), this->movie.get_year());
}
