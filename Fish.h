#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : virtual public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish( const char* color, int childs, float avgLifetime, int fin, int gills );//init the Fish with a given attributes
	Fish( ifstream& in_file );//init the Fish from a binary file
	Fish( const Fish& other );
	virtual ~Fish();

public:
	int		GetFinCount() const { return m_finCount; }//return the fin count of the animal
	int		GetGillsCount() const { return m_gillsCount; }//return the gills count of the animal

public:
	virtual void Load( ifstream& in_file );//load the data from a text file
	virtual void Save( ofstream& out_file ) const;//saves the data to a text file

public:
	virtual void SaveBin( ofstream& out_file ) const;//saves the data to a binary file

protected:
	virtual void load( ifstream& in_file );
	virtual void save( ofstream& out_file ) const;
	virtual void saveBin( ofstream& out_file ) const;

protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef