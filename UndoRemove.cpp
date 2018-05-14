#include "UndoRemove.h"



void UndoRemove::undo()
{
	this->repo.add_repo(this->movie);
}