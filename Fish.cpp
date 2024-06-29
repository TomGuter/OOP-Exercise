#include "Fish.h"

Fish::Fish() // set the default color to GRAY and other params to 0
	: Animal(),
	  m_finCount(0),
	  m_gillsCount(0)
{
}

Fish::Fish(const char *color, int childs, float avgLifetime, int fin, int gills) // init the Fish with a given attributes
	: Animal(color, childs, avgLifetime),
	  m_finCount(fin),
	  m_gillsCount(gills)
{
}

Fish::Fish(ifstream &in_file) // init the Fish from a binary file
	: Animal(in_file)
{
	char c; // to read the '\n' that we wrote
	in_file.read((char *)&m_finCount, sizeof(m_finCount));
	in_file.read(&c, 1);
	in_file.read((char *)&m_gillsCount, sizeof(m_gillsCount));
	in_file.read(&c, 1);
}

Fish::Fish(const Fish &other)
	: Animal(other)
{
	m_finCount = other.m_finCount;
	m_gillsCount = other.m_gillsCount;
}

Fish::~Fish()
{
}

void Fish::Load(ifstream &in_file) // load the data from a text file
{
	Animal::Load(in_file);
	load(in_file);
}

void Fish::Save(ofstream &out_file) const // saves the data to a text file
{
	Animal::Save(out_file);
	save(out_file);
}

void Fish::SaveBin(ofstream &out_file) const // saves the data to a binary file
{
	Animal::SaveBin(out_file);
	saveBin(out_file);
}

void Fish::load(ifstream &in_file)
{
	in_file >> m_finCount;
	in_file >> m_gillsCount;
}

void Fish::save(ofstream &out_file) const
{
	out_file << m_finCount << endl;
	out_file << m_gillsCount << endl;
}

void Fish::saveBin(ofstream &out_file) const
{
	out_file.write((char *)&m_finCount, sizeof(m_finCount));
	out_file.write("\n", 1);
	out_file.write((char *)&m_gillsCount, sizeof(m_gillsCount));
	out_file.write("\n", 1);
}
