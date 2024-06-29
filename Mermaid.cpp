#include "Mermaid.h"

//--------------------------------------------------------------------------------------------//
Mermaid::Mermaid()//set the default color to GRAY and other params to 0
	: Animal(),
	MammalsFish(),
	m_firstName( NULL ),
	m_lastName( NULL )
{

}
//--------------------------------------------------------------------------------------------//
Mermaid::Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName )//init the Mermaid with a given attributes
	: Animal( color, childs, avgLifetime ),
	MammalsFish( color, childs, avgLifetime, preg, milk, fin, gills )
{
	m_firstName = strdup( firstName );
	m_lastName = strdup( lastName );
}
//--------------------------------------------------------------------------------------------//
Mermaid::Mermaid( ifstream& in_file )//init the Mermaid from a binary file
	: Animal( in_file ),
	MammalsFish( in_file )
{
	m_firstName = readTextFromFile( in_file );
	m_lastName = readTextFromFile( in_file );
}
//--------------------------------------------------------------------------------------------//
Mermaid::Mermaid( const Mermaid& other )
	: Animal( other ),
	MammalsFish( other )
{
	m_firstName = strdup( other.m_firstName );
	m_lastName = strdup( other.m_lastName );
}
//--------------------------------------------------------------------------------------------//
Mermaid::~Mermaid()
{
	if( m_firstName )
		delete m_firstName;

	m_firstName = NULL;

	if( m_lastName )
		delete m_lastName;

	m_lastName = NULL;
}
//--------------------------------------------------------------------------------------------//
void Mermaid::Load( ifstream& in_file )//load the data from a text file
{
	MammalsFish::Load( in_file );

	m_firstName = readTextFromFile( in_file );
	m_lastName = readTextFromFile( in_file );
}
//--------------------------------------------------------------------------------------------//
void Mermaid::Save( ofstream& out_file ) const//saves the data to a text file
{
	MammalsFish::Save( out_file );
	out_file << m_firstName << endl;
	out_file << m_lastName << endl;
}
//--------------------------------------------------------------------------------------------//
void Mermaid::SaveBin( ofstream& out_file ) const//saves the data to a binary file
{
	MammalsFish::SaveBin( out_file );
	out_file.write( m_firstName, strlen( m_firstName ) );
	out_file.write( "\n", 1 );
	out_file.write( m_lastName, strlen( m_lastName ) );
	out_file.write( "\n", 1 );
}
//--------------------------------------------------------------------------------------------//