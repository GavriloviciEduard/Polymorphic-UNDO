#pragma once
#include "UndoAction.h"

class UndoAdd :	public UndoAction
{
	private:
		Repository& repo;
		Movie movie;

	public:
		UndoAdd(Repository& r, Movie m) :repo{ r }, movie{ m } {}
		void undo() override;

};

