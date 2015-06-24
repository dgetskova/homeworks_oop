#include "Biscuit.h"


void Biscuit::allocate(char**matrix, uint row_m)
{
	row = row_m;

	try	{ content = new char*[row]; }
	catch (std::bad_alloc)	{ throw std::exception("Failed to allocate biscuit memory"); std::cout << "Memory error";  delete[]content; }

	for (uint i = 0; i < row; i++)
		content[i] = NULL;

	for (uint i = 0; i < row; i++)
	{
		int len = strlen(matrix[i]) + 1;
		try		{ content[i] = new char[len]; }
		catch (std::bad_alloc)	{ std::cout << "Memory error";	free(); }
	}
	for (size_t i = 0; i < row; i++)
	{
		strncpy_s(content[i], strlen(matrix[i]) + 1, (const char*)matrix[i], strlen(matrix[i]) + 1);
	}
}

Biscuit::Biscuit()
{
	row = 0;
	content = NULL;
}

Biscuit::Biscuit(char ** matrix, uint row_m)
{
	allocate(matrix, row_m);

}

void Biscuit::free()
{
	if (content != NULL)
		for (int i = 0; i < row; i++)
			delete[] content[i];
	delete[] content;
	row = 0;
}

Biscuit :: ~Biscuit()
{
	free();
}

char*Biscuit::get_content(uint i)const
{
	return content[i];
}

int Biscuit::get_row()const
{
	return row;
}

Biscuit::Biscuit(const Biscuit &came)
{
	allocate(came.content, came.row);
}

Biscuit& Biscuit::operator=(const Biscuit& other)
{
	if (this != &other)
	{
		free();
		allocate(other.content, other.row);
	}
	return *this;
}

void Biscuit::set_row(uint row_came)
{
	free();
	row = row_came;
	try{
		content = new char*[row];
	}
	catch (std::bad_alloc){ delete[]content; throw; }
	for (size_t i = 0; i < row; i++)
	{
		content[i] = NULL;
	}
}

void Biscuit::set_content(char*content_came, int index)
{

	if (index >= row)
	{
		return;
	}

	int size_elem = strlen(content_came) + 1;
	try{
		this->content[index] = new char[size_elem];
	}
	catch (std::bad_alloc){ free(); throw; }
	strncpy_s(this->content[index], size_elem, content_came, size_elem);

}