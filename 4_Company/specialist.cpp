#include"specialist.h"

void Specialist::free()
{
	std::cout << "destr na spec";
	delete[] specialty;
}

void  Specialist::allocate(char * specialty_came)
{
	int size_specialty = strlen(specialty_came) + 1;

	specialty = NULL;
	try 
	{
		specialty = new char[size_specialty];
	}
	catch (std::bad_alloc)
	{
		delete[]specialty;
		throw "No allocate object Specialist.";
	}

	strncpy_s(specialty, size_specialty, specialty_came, size_specialty);
}

Specialist::Specialist(char * name_came, char * address_came,char*section_came, unsigned long long id_came, double salary_came, char* specialty_came)
	: Servant(name_came, address_came, section_came, id_came, salary_came)
{
	allocate(specialty_came);
}

Specialist::Specialist(const Specialist &other) : Servant(other)
{
	allocate(other.specialty);
}

Specialist& Specialist::operator = (const Specialist& other)
{	
	if (this != &other)
	{
		Servant::operator=(other);
		free();
		allocate(other.specialty);
	}
	return *this;

}
Specialist::~Specialist()
{
	free();
}
char* Specialist::get_specialty()const
{
	return specialty;
}

int Specialist::get_type()const
{
	return 2;
}