#include"Manager.h"

void Manager::free()
{
	delete[] servants;
	delete[]info_section;
	servants = NULL;
}
void Manager::allocate(char * section_came, Servant** servants_came, int size_servants_came)
{
	servants = NULL;
	size_servants = 0;
	//count of specialist from section_came
	int count_servants_from_this_section=0;
	for (size_t i = 0; i < size_servants_came; i++)
	{
		if (!strcmp(servants_came[i]->get_section(), section_came))
			count_servants_from_this_section++;
	}
	size_servants = count_servants_from_this_section;
	int size_section = strlen(section_came) + 1;
	try
	{
		info_section = new char[size_section];
		servants = new Servant*[size_servants];
	}
	catch (std::bad_alloc)
	{
		free();
		throw "No allocate manager object.";
	}

	int index = 0;
	for (size_t i = 0; i < size_servants_came; i++)
	{
		if (!strcmp(servants_came[i]->get_section(), section_came))
		{
			servants[index] = servants_came[i];
			index++;
		}
	}
	strncpy_s(info_section, size_section, section_came, size_section);

}

Manager& Manager::operator=(const Manager& other)
{
	if (this != &other)
	{
		Specialist::operator=(other);
		free();
		allocate(other.info_section, other.servants, other.size_servants);
	}
	return *this;
}

Manager::Manager(char * name_came, char * address_came,char* section_came, unsigned long long id_came, double salary_came, char* specialty_came,
	char* info_section_came, Servant** servants_came, int size_servants_came)
	: Specialist(name_came, address_came,section_came, id_came, salary_came, specialty_came)
{
	allocate(info_section_came, servants_came, size_servants_came);
}

Manager::~Manager()
{
	free();
}
Manager::Manager(const Manager&other) : Specialist(other)
{
	allocate(other.info_section, other.servants, other.size_servants);
}


int Manager::get_type()const//return 3
{
	return 3;
}
char* Manager::get_section()const
{
	return info_section;
}
