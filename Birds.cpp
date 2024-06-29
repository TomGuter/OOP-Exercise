#include "Birds.h"


Birds::Birds()//set the default color to GRAY and other params to 0
	: Animal(),
	m_incubationTime( 0.f )
{

}

Birds::Birds( const char* color, int childs, float avgLifetime, float incubation )//init the Birds with a given attributes
	: Animal( color, childs, avgLifetime ),
	m_incubationTime( incubation )
{

}

Birds::Birds( ifstream& in_file )//init the Birds from a binary file
	: Animal( in_file )
{
	char c;//to read the '\n' that we wrote
	in_file.read( (char*)&m_incubationTime, sizeof( m_incubationTime ) );
	in_file.read( &c, 1 );
}

Birds::Birds( const Birds& other )
	: Animal( other )
{
	m_incubationTime = other.m_incubationTime;
}

Birds::~Birds()
{

}

void Birds::Load( ifstream& in_file )//load the data from a text file
{
	Animal::Load( in_file );
	in_file >> m_incubationTime;
}

void Birds::Save( ofstream& out_file ) const//saves the data to a text file
{
	Animal::Save( out_file );
	out_file << m_incubationTime << endl;
}

void Birds::SaveBin( ofstream& out_file ) const//saves the data to a binary file
{
	Animal::SaveBin( out_file );
	out_file.write( (char*)&m_incubationTime, sizeof( m_incubationTime ) );
	out_file.write( "\n", 1 );
}
