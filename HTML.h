#pragma once
#include "FileBase.h"

class HTMLFILE : public FileBase
{


	public:

		HTMLFILE() { this->filename = "movieWL.html"; }

		void  write_file() override;
		void display_file() const override;


};
