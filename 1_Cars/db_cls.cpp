#include "db_cls.h"
#include <fstream>
db_cls::db_cls()
{
	db_list = NULL;
	capacity = 0;
	used = 0;
}

db_cls::~db_cls()
{
	free();
}

void db_cls::free()
{
	delete[]db_list;
}

void db_cls::allocate()
{
	if (capacity == 0)
	{
		try{
			db_list = new info_person[1];
		}
		catch (bad_alloc){
			free();
			throw "No memory";
		}

		capacity = 1;
		return;
	}

	info_person * new_db_list = NULL;
	capacity *= 2;
	try{
	new_db_list = new info_person[capacity];
	}
	catch (bad_alloc){
	free();
	throw "No memory"; }

	for (size_t i = 0; i < used; i++)
	{
		new_db_list[i] = db_list[i];
	}

	free();
	db_list = new_db_list;
	new_db_list = NULL;	
}

void db_cls::add(char name_came[], int id_came, int reg_num_came)
{
	if (existing_reg_num(reg_num_came))
	{
		cout << "Already exist car with that reg num: " << reg_num_came<<std::endl;
		return;
	}
	if (!is_data_valid(id_came, reg_num_came))
	{
		cout << "Data id and reg num are not valid." << "id_came :" << id_came << ", reg_num_came:" << reg_num_came << std::endl;
		return;
	}

	if (used == capacity)
		allocate();

	info_person person(name_came, id_came, reg_num_came);
	db_list[used] = person;
	used++;
	}

bool db_cls::existing_reg_num(int reg_num_came)
{
	for (size_t i = 0; i < used; i++)
		if (db_list[i].reg_num == reg_num_came)
			return true;
	return false;
}

bool db_cls:: is_data_valid(int id_came, int reg_num_came)
{
	if (id_came < 0 || id_came > 3)
		return false;
	if (reg_num_came < 1000 || reg_num_came > 9999)
		return false;
	return true;
}

char* db_cls:: get_car_name(int id)
{
    //no need of default because it's private(work with checked data)
    switch(id)
    {
        case 0:
            return "Lambordgini Murcielago";
        case 1:
            return "Mercedes-AMG";
        case 2:
            return "Pagani Zonda R";
        case 3:
            return "Bugatti Veyron";            
    }
    
}

int db_cls::get_car_power(int id)
{
    switch(id)
    {
        case 0:
            return 670;
        case 1:
            return 503;
        case 2:
            return 740;
        case 3:
            return 1020;            
    }
}

void db_cls:: generate_bin_file()
{
	ofstream file("db-save.dat", ios::binary, ios::trunc);
    if(!file)
    {
        cout<<"ERROR with file";
        return;
    }

	//file.write((const char *)&db_list, used * sizeof(db_list[0]));
	for (int i = 0; i < used && file.good(); i++)
	{
		file.write(db_list[i].name, sizeof(db_list[i].name));
		file.write((const char*)&db_list[i].id, sizeof(db_list[i].id));
		file.write((const char*)&db_list[i].reg_num, sizeof(db_list[i].reg_num));
	}
	file.close(); 
}

void db_cls::read_from_bin()
{ 
	ifstream file("db-save.dat", ios::binary);
	
	if (!file)
	{
		cout << "ERROR with file";
		return;
	}
	info_person current;
	int num;
	//file.read((char*)&current, sizeof(current));
	for (int i = 0; !file.eof(); i++)
	{
		
		file.read(current.name, sizeof(current.name));
		file.read((char *)(&current.id), sizeof(current.id));
		file.read((char *)(&current.reg_num), sizeof(current.reg_num));
		add(current.name, current.id, current.reg_num);
	}
}

void db_cls:: generate_txt()
{
	float power_all = 0;
	for (int i = 0; i < used; i++)
	{
		power_all += float(get_car_power(db_list[i].id));
	}
	float power_res = 0;
	power_res = power_all / used;


	ofstream file("car-report.txt", ios::trunc);
	if (!file)
	{
		cout << "ERROR with file";
		return;
	}
	int popular_car = get_popular_car();
	file << popular_car;
	file  << power_res;
	file << endl;
	for (int f = 0; f < used; f++)
	{
		int power_to_person=0;
		for (int s = 0; s < used; s++)
		{
			if (!strcmp(db_list[s].name, db_list[f].name))
				power_to_person += get_car_power(db_list[s].id);
		}
		if (file.good())
		{
			file.write(db_list[f].name, sizeof(db_list[f].name));
			file << power_to_person;
			file << endl;
		}
	}

	file.close();
}

int db_cls:: get_popular_car()
{
	const int FOUR_ELEM = 4;
	int array[FOUR_ELEM];
	int power_all = 0;
	for (int i = 0; i < FOUR_ELEM; i++)
	{
		array[i] = 0;
	}
	for (int i = 0; i < used; i++)
	{
		if (db_list[i].id == 0)
		{
			array[0] = array[0] + 1;
		}
		if (db_list[i].id == 1)
		{
			array[1] = array[1] + 1;
		}
		if (db_list[i].id == 2)
		{
			array[2] = array[2] + 1;
		}
		if(db_list[i].id == 3)
		{ 
			array[3] = array[3] + 1;
		}
	}
	int max = array[3];
	int popular_car_res = 3;
	for (int i = 0; i < FOUR_ELEM - 1; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
			popular_car_res = i;
		}
	}

	return popular_car_res;
}