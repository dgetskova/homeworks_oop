#pragma once
#include <iostream>

typedef unsigned int uint;


class Biscuit
{
private:
	char **content;
	uint row;
private:
	void allocate(char**, uint);
	void free();
public:
	Biscuit();
	Biscuit(char **, uint);
	Biscuit(const Biscuit &);
	Biscuit& operator=(const Biscuit& other);
	~Biscuit();
public:
	char* get_content(uint)const;
	int get_row()const;
	void set_row(uint);
	void set_content(char*content_came, int index);
};
