#ifndef MERMAID_H
#define MERMAID_H

#include "MammalsFish.h"

class Mermaid : public MammalsFish
{
public:
	Mermaid();//set the default color to GRAY and other params to 0
	Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName );//init the Mermaid with a given attributes
	Mermaid( ifstream& in_file );//init the Mermaid from a binary file
	Mermaid( const Mermaid& other );
	virtual ~Mermaid();

public:
	const char*		GetFirstName() const { return m_firstName; }//return the first name of the mermaid
	const char*		GetLastName() const { return m_lastName; }//return the last name of the mermaid

public:
	virtual void Load( ifstream& in_file );//load the data from a text file
	virtual void Save( ofstream& out_file ) const;//saves the data to a text file

public:
	virtual void SaveBin( ofstream& out_file ) const;//saves the data to a binary file

protected:
	char* m_firstName;
	char* m_lastName;
};

#endif // ifndef