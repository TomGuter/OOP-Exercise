#include "Mammals.h"

//--------------------------------------------------------------------------------------------//
Mammals::Mammals()//set the default color to GRAY and other params to 0
	: Animal(),
	m_pregnancyTime( 0.f ),
	m_milkLiters( 0.f )
{

}
//--------------------------------------------------------------------------------------------//
Mammals::Mammals( const char* color, int childs, float avgLifetime, float preg, float milk )//init the Mammals with a given attributes
	: Animal( color, childs, avgLifetime ),
	m_pregnancyTime( preg ),
	m_milkLiters( milk )
{

}
//--------------------------------------------------------------------------------------------//
Mammals::Mammals( ifstream& in_file )//init the Mammals from a binary file
	: Animal( in_file )
{
	char c;//to read the '\n' that we wrote
	in_file.read( (char*)&m_pregnancyTime, sizeof( m_pregnancyTime ) );
	in_file.read( &c, 1 );
	in_file.read( (char*)&m_milkLiters, sizeof( m_milkLiters ) );
	in_file.read( &c, 1 );
}
//--------------------------------------------------------------------------------------------//
Mammals::Mammals( const Mammals& other )
	: Animal( other )
{
	m_pregnancyTime = other.m_pregnancyTime;
	m_milkLiters = other.m_milkLiters;
}
//--------------------------------------------------------------------------------------------//
Mammals::~Mammals()
{

}
//--------------------------------------------------------------------------------------------//
void Mammals::Load( ifstream& in_file )//load the data from a text file
{
	Animal::Load( in_file );
	load( in_file );
}
//--------------------------------------------------------------------------------------------//
void Mammals::Save( ofstream& out_file ) const//saves the data to a text file
{
	Animal::Save( out_file );
	save( out_file );
}
//--------------------------------------------------------------------------------------------//
void Mammals::SaveBin( ofstream& out_file ) const//saves the data to a binary file
{
	Animal::SaveBin( out_file );
	saveBin( out_file );
}
//--------------------------------------------------------------------------------------------//
void Mammals::load( ifstream& in_file )
{
	in_file >> m_pregnancyTime;
	in_file >> m_milkLiters;
}
//--------------------------------------------------------------------------------------------//
void Mammals::save( ofstream& out_file ) const
{
	out_file << m_pregnancyTime << endl;
	out_file << m_milkLiters << endl;
}
//--------------------------------------------------------------------------------------------//
void Mammals::saveBin( ofstream& out_file ) const
{
	out_file.write( (char*)&m_pregnancyTime, sizeof( m_pregnancyTime ) );
	out_file.write( "\n", 1 );
	out_file.write( (char*)&m_milkLiters, sizeof( m_milkLiters ) );
	out_file.write( "\n", 1 );
}
//--------------------------------------------------------------------------------------------//