#pragma once
#include "FileBase.h"


class CSVFILE : public FileBase
{


	public:

		CSVFILE () { this->filename = "movieWL.csv"; }

		void write_file() override;
		void display_file() const override;

};