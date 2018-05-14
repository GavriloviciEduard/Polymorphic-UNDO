#include "DataStruct.h"

/*
DynamicVector::DynamicVector(int capacity)
{
	this->len = 0;
	this->capacity = capacity;
	this->movies = new Movie[capacity];
}


DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->len = v.len;
	this->capacity = v.capacity;
	this->movies = new Movie[capacity];

	for (int i = 0; i < this->len; i++)
		this->movies[i] = v.movies[i];
}


DynamicVector::~DynamicVector()
{
	delete[] this->movies;
}


DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;

	this->len = v.len;
	this->capacity = v.capacity;

	delete[] this->movies;

	this->movies = new Movie[this->capacity];
	for (int i = 0; i < this->len; i++)
		this->movies[i] = v.movies[i];

	return *this;
}



DynamicVector& DynamicVector::operator+(const Movie& mv)
{

	if (this->len == this->capacity)
		this->resize();

	this->movies[this->len++] = mv;

	return *this; 

}



void DynamicVector::resize(int cap)
{
	this->capacity *= cap;

	Movie* mov = new Movie[this->capacity];

	for (int i = 0; i < this->len; i++)
		mov[i] = this->movies[i];

	delete[] this->movies;

	this->movies = mov;
}



void DynamicVector::remove(int indx)
{
	//memory leak??

	for (int i = indx; i < this->len - 1; i++)
		this->movies[i] = this->movies[i + 1];

	this->len--;
}



void DynamicVector::update(int indx, const Movie& mn)
{
	this->movies[indx] = mn;
}

*/
