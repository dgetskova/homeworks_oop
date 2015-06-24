#include "Servant.h"


void Servant::allocate(char * name_came, char * address_came, char* section_came)
{
	int size_name = strlen(name_came) + 1;
	int size_address = strlen(address_came) + 1;
	int size_section = strlen(section_came) + 1;
	try
	{
		name = new char[size_name];
		address = new char[size_address];
		section = new char[size_section];
	}
	catch (std::bad_alloc)
	{
		free();
		throw "no created object.";
	}
	strncpy_s(name, size_name, name_came, size_name);
	strncpy_s(address, size_address, address_came, size_address);
	strncpy_s(section, size_section, section_came, size_section);
}

void Servant::free()
{
	delete[]name;
	delete[]address;
	delete[]section;
	name = NULL;
	address = NULL;
	section = NULL;
}

Servant::Servant()
{
	name = NULL;
	address = NULL;
	section = NULL;
	id = 0;
	salary = 0;
}

Servant::Servant(char * name_came, char * address_came, char* section_came, unsigned long long id_came, double salary_came)
{
	name = NULL;
	address = NULL;
	section = NULL;
	id = id_came;
	salary = salary_came;

	allocate(name_came, address_came, section_came);
}

Servant :: ~Servant()
{
	free();
}

Servant::Servant(const Servant & other)
{
	name = NULL;
	address = NULL;
	section = NULL;
	id = other.id;
	salary = other.salary;

	allocate(other.name, other.address, other.section);
}

Servant& Servant::operator=(const Servant &other)
{
	if (this != &other)
	{
		free();
		allocate(other.name, other.address, other.section);
		id = other.id;
		salary = other.salary;
	}
	return *this;
}

double  Servant::get_salary()const
{
	std::cout << "servant " << std::endl;
	return this->salary;
}
int Servant::get_type() const
{
	return 1;
}
char* Servant::get_section()const
{
	return section;
}