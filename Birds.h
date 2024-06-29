#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : virtual public Animal
{
public:
	Birds();//set the default color to GRAY and other params to 0
	Birds( const char* color, int childs, float avgLifetime, float incubation );//init the Birds with a given attributes
	Birds( ifstream& in_file );//init the Birds from a binary file
	Birds( const Birds& other );
	virtual ~Birds();

public:
	float		GetIncubationTime() const { return m_incubationTime; }//return the incubation time of the animal

public:
	virtual void Load( ifstream& in_file );//load the data from a text file
	virtual void Save( ofstream& out_file ) const;//saves the data to a text file

public:
	virtual void SaveBin( ofstream& out_file ) const;//saves the data to a binary file

protected:
	float m_incubationTime;
};

#endif // ifndef