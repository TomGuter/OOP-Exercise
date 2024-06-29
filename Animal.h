#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected://so that it will not be possible to create Animal type
	Animal();//set the default color to GRAY and other params to 0
	Animal( const char* color, int childs, float avgLifetime );//init the Animal with a given attributes
	Animal( ifstream& in_file );//init the Animal from a binary file
	Animal( const Animal& other );

public:
	virtual ~Animal();

public:
	const char* GetColor() const { return m_color; }//return the color of the animal
	int			GetChildCount() const { return m_childCount; }//return the child count of the animal
	float		GetLifetime() const { return m_avgLifetime; }//return the life time of the animal

public:
	virtual void Load( ifstream& in_file );//load the data from a text file
	virtual void Save( ofstream& out_file ) const;//saves the data to a text file
	void SaveType( ofstream& out_file ) const;//saves the type to a text file

public:
	virtual void SaveBin( ofstream& out_file ) const;//saves the data to a binary file
	void SaveTypeBin( ofstream& out_file ) const;//saves the type to a binary file

public:
	char* GetTypeName() const;

protected:
	char*	m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

char* readTextFromFile( ifstream& in_file );
char* fixTypeName( char* name );

#endif // ifndef