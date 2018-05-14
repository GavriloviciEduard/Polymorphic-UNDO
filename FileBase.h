#pragma once
#include "WatchList.h"

class FileBase : public WatchList
{

protected:
	std::string filename;

public:

	FileBase() :filename{ "" }{ }
	virtual ~FileBase() {}


	virtual void write_file() = 0;
	virtual void display_file() const = 0;
	void set_name(const std::string s) { this->filename = s; }
};
