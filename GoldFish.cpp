#include "GoldFish.h"

GoldFish::GoldFish() // set the default color to GRAY and other params to 0
	: Animal(),
	  MammalsFish(),
	  m_avgWeight(0),
	  m_avgLength(0)
{
}

GoldFish::GoldFish(const char *color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) // init the GoldFish with a given attributes
	: Animal(color, childs, avgLifetime),
	  MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills),
	  m_avgWeight(avgW),
	  m_avgLength(avgL)
{
}

GoldFish::GoldFish(ifstream &in_file) // init the GoldFish from a binary file
	: Animal(in_file),
	  MammalsFish(in_file)
{
	char c; // to read the '\n' that we wrote
	in_file.read((char *)&m_avgWeight, sizeof(m_avgWeight));
	in_file.read(&c, 1);
	in_file.read((char *)&m_avgLength, sizeof(m_avgLength));
	in_file.read(&c, 1);
}

GoldFish::GoldFish(const GoldFish &other)
	: Animal(other),
	  MammalsFish(other)
{
	m_avgWeight = other.m_avgWeight;
	m_avgLength = other.m_avgLength;
}

GoldFish::~GoldFish()
{
}

void GoldFish::Load(ifstream &in_file) // load the data from a text file
{
	MammalsFish::Load(in_file);
	in_file >> m_avgWeight;
	in_file >> m_avgLength;
}

void GoldFish::Save(ofstream &out_file) const // saves the data to a text file
{
	MammalsFish::Save(out_file);
	out_file << m_avgWeight << endl;
	out_file << m_avgLength << endl;
}

void GoldFish::SaveBin(ofstream &out_file) const // saves the data to a binary file
{
	MammalsFish::SaveBin(out_file);
	out_file.write((char *)&m_avgWeight, sizeof(m_avgWeight));
	out_file.write("\n", 1);
	out_file.write((char *)&m_avgLength, sizeof(m_avgLength));
	out_file.write("\n", 1);
}
