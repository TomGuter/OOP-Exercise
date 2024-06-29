#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public:
	Horse();//set the default color to GRAY and other params to 0
	Horse( const char* color, int childs, float avgLifetime, float preg, float milk, const char* type );//init the Horse with a given attributes
	Horse( ifstream& in_file );//init the Horse from a binary file
	Horse( const Horse& other );
	virtual ~Horse();

public:
	const char*		GetType() const { return m_type; }//return the type of the horse

public:
	virtual void Load( ifstream& in_file );//load the data from a text file
	virtual void Save( ofstream& out_file ) const;//saves the data to a text file

public:
	virtual void SaveBin( ofstream& out_file ) const;//saves the data to a binary file

protected:
	char*	m_type;
};

#endif // ifndef