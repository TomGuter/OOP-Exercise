#ifndef MAMMALS_H
#define MAMMALS_H

#include "Animal.h"

class Mammals : virtual public Animal
{
public:
	Mammals();//set the default color to GRAY and other params to 0
	Mammals( const char* color, int childs, float avgLifetime, float preg, float milk );//init the Mammals with a given attributes
	Mammals( ifstream& in_file );//init the Mammals from a binary file
	Mammals( const Mammals& other );
	virtual ~Mammals();

public:
	float		GetPregnanceTime() const { return m_pregnancyTime; }//return the pregnance time of the animal
	float		GetMilk() const { return m_milkLiters; }//return the milk liters of the animal

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
	float m_pregnancyTime;
	float m_milkLiters;
};

#endif // ifndef