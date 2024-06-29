#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds
{
public:
	Flamingo();//set the default color to GRAY and other params to 0
	Flamingo( const char* color, int childs, float avgLifetime, float incubation, float avgHeight );//init the Flamingo with a given attributes
	Flamingo( ifstream& in_file );//init the Flamingo from a binary file
	Flamingo( const Flamingo& other );
	virtual ~Flamingo();

public:
	float		GetHeight() const { return m_avgHeight; }//return the avg height of the flamingo

public:
	virtual void Load( ifstream& in_file );//load the data from a text file
	virtual void Save( ofstream& out_file ) const;//saves the data to a text file

public:
	virtual void SaveBin( ofstream& out_file ) const;//saves the data to a binary file

protected:
	float m_avgHeight;
};

#endif // ifndef