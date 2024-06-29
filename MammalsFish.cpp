#include "MammalsFish.h"

//--------------------------------------------------------------------------------------------//
MammalsFish::MammalsFish()//set the default color to GRAY and other params to 0
	: Animal(),
	Mammals(),
	Fish()
{

}
//--------------------------------------------------------------------------------------------//
MammalsFish::MammalsFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills )//init the MammalsFish with a given attributes
	: Animal( color, childs, avgLifetime ),
	Mammals( color, childs, avgLifetime, preg, milk ),
	Fish( color, childs, avgLifetime, fin, gills )
{

}
//--------------------------------------------------------------------------------------------//
MammalsFish::MammalsFish( ifstream& in_file )//init the MammalsFish from a binary file
	: Animal( in_file ),
	Mammals( in_file ),
	Fish( in_file )
{

}
//--------------------------------------------------------------------------------------------//
MammalsFish::MammalsFish( const MammalsFish& other )
	: Animal( other ),
	Mammals( other ),
	Fish( other )
{

}
//--------------------------------------------------------------------------------------------//
MammalsFish::~MammalsFish()
{

}
//--------------------------------------------------------------------------------------------//
void MammalsFish::Load( ifstream& in_file )//load the data from a text file
{
	Animal::Load( in_file );
	load( in_file );
}
//--------------------------------------------------------------------------------------------//
void MammalsFish::Save( ofstream& out_file ) const//saves the data to a text file
{
	Animal::Save( out_file );
	save( out_file );
}
//--------------------------------------------------------------------------------------------//
void MammalsFish::SaveBin( ofstream& out_file ) const//saves the data to a binary file
{
	Animal::SaveBin( out_file );
	saveBin( out_file );
}
//--------------------------------------------------------------------------------------------//
void MammalsFish::load( ifstream& in_file )
{
	Mammals::load( in_file );
	Fish::load( in_file );
}
//--------------------------------------------------------------------------------------------//
void MammalsFish::save( ofstream& out_file ) const
{
	Mammals::save( out_file );
	Fish::save( out_file );
}
//--------------------------------------------------------------------------------------------//
void MammalsFish::saveBin( ofstream& out_file ) const
{
	Mammals::saveBin( out_file );
	Fish::saveBin( out_file );
}
//--------------------------------------------------------------------------------------------//