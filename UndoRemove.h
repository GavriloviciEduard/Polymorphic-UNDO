#pragma once
#include "UndoAction.h"

class UndoRemove :	public UndoAction
{
	private:
		Repository& repo;
		Movie movie;

	public:
		UndoRemove(Repository& r, Movie m) :repo{ r }, movie{ m } {}
		void undo() override;
};

