#pragma once
#include "Repository.h"
#include "Movie.h"

class UndoAction
{


	public:
		virtual ~UndoAction() {};
		virtual void undo() = 0;
};
