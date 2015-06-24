#include <iostream>
using namespace std;

const int SIZE_NAME = 23;
class db_cls
{
private:
	struct info_person{
		char name[SIZE_NAME];//to 23
		int id;//0 to 3
		int reg_num;

		info_person(){
			for (size_t i = 0; i < SIZE_NAME; i++)
			{
				name[i] = 0;
			}
			id = 0;
			reg_num = 0;
		}

		info_person(char name_came[], int id_came, int reg_num_came)
		{
			for (size_t i = 0; i < SIZE_NAME; i++)
			{
				name[i] = 0;
			}
			int len_name = strlen(name_came);
			for (int i = 0; i < len_name; i++)
			{
				name[i] = name_came[i];
			}
			id = id_came;
			reg_num = reg_num_came;
		}
	};

	info_person * db_list;
	int capacity;
	int used;

	void free();
	void allocate();
	bool existing_reg_num(int reg_num_came);
	bool is_data_valid(int id_came, int reg_num_came);
        
    char* get_car_name(int id);
    int get_car_power(int id);
	int get_popular_car();

public:
	db_cls();
	~db_cls();
	void add(char name_came[], int id_came, int reg_num_came);
        
	void generate_txt();
    void generate_bin_file();
	void read_from_bin();

};