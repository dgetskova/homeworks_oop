#include "Biscuit.h"
#include <fstream>
using namespace std;

class Jar
{
private:
	Biscuit * jar;
	uint used;
	uint size;
private:
	void allocate();
	void free();
public:
	Jar();
	Jar(uint);
	~Jar();

	void add_biscuit(Biscuit);
	void remove_biscuit();
	void serialize();
	void deserialize();
};

Jar::Jar()
{
	jar = NULL;
	used = 0;
	size = 0;
}
Jar::Jar(uint came_size)
{
	used = 0;
	size = came_size;
	jar = new Biscuit[size];
}


void Jar::add_biscuit(Biscuit bisc)
{
	if (used >= size)
		allocate();
	try{
		jar[used] = Biscuit(bisc);
	}catch (std::bad_alloc){ std::cout << "ERROR"; }
	used++;
}

void Jar::allocate()
{
	if (size == 0)
		size = 1;
	size *= 2;

	Biscuit * temp;
	try{
		temp = new Biscuit[size];
	}
	catch (std::bad_alloc){ std::cout << "ERROR"; throw "no obj temp in allocate"; }


	for (size_t i = 0; i < used; i++)
	{
		temp[i] = jar[i];
	}
	jar = temp;
}


Jar::~Jar()
{
	free();
}


void Jar:: free()
{
	delete[] jar;
}

void Jar:: remove_biscuit()
{
	// destructora na biscuit shte se izvika za vsichkata zadelena pamet
	used--;
}

void Jar::serialize()
{
	ofstream file("serialize.bin", ios::binary);
	if (!file.good())
		return;

	file.write((const char*)&used,sizeof(used));
	int elem_size = 0;
	for (size_t i = 0; i < used; i++)
	{
		uint bisc_row = jar[i].get_row();
		file.write((const char*)&bisc_row, sizeof(jar[i].get_row()));
		for (size_t b = 0; b < bisc_row; b++)
		{
			//writing how long is the name(how many bytes)
			elem_size = strlen(jar[i].get_content(b)) + 1;
			file.write((const char *)&elem_size, sizeof(elem_size));
			file.write((const char*)jar[i].get_content(b), (sizeof(char) * elem_size)); // 
		}
	}
	file.close();
}

void Jar::deserialize()
{
	ifstream file("serialize.bin", ios::binary);
	if (!file.good())
		return;

	//jar size
	uint check_used = 0;
	file.read((char*)&check_used, sizeof(uint));

	free();
	jar = new Biscuit[check_used];
	used = check_used;
	size = check_used;

	int elem_content_size = 0;
	char*elem_content = NULL;
	for (size_t i = 0; i < used; i++)
	{
		if (file.good())
		{
			uint bisc_row = 0;
			file.read((char*)&bisc_row, sizeof(bisc_row)); // read count of rows in biscuit
			jar[i].set_row(bisc_row);
			for (size_t cont = 0; cont < bisc_row; cont++)
			{
				file.read((char*)&elem_content_size, sizeof(elem_content_size));
				try{
					elem_content = new char[elem_content_size];
				}
				catch (bad_alloc & e){ free(); throw e; }

				file.read(elem_content, (sizeof(char) * elem_content_size));
				jar[i].set_content(elem_content, cont);
				delete[]elem_content;
				elem_content = NULL;
			}
		}
	}
	file.close();
}
