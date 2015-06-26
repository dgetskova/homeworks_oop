#include <iostream>
using namespace std;

const int BOUND = 31;

class BoolVector
{
private:
	unsigned int number;
public:
	BoolVector(unsigned int came = 0){ number = came; }
	unsigned int get_number()
	{
		return number;
	}
	bool is_in_bound(unsigned int index)
	{
		return (index >= 0 && index <= BOUND);
	}

	unsigned int operator[](unsigned int index)
	{
		if (!is_in_bound(index))
			return -1;

		unsigned int copy_number = number;
		copy_number = copy_number << index;
		copy_number = copy_number >> BOUND;


		//cout << "two" << (1 << 1);
		//unsigned int one = 1;
		//cout << "normal" << (one << 24);
		//cout << "index 25 - problem - "<< (one << index);
		return copy_number; // 0 or 1

	}

	bool set(unsigned int index)
	{
		if (!is_in_bound(index))
			return false;
		if (this->operator[](index))
			return true; 

		//it's zero and it have to be change
		unsigned int copy_number = ~number;
		//1.)makes elem 1

		//2.) makes all elem zero except the callable elem
		copy_number = copy_number << index;
		copy_number = copy_number >> BOUND;
		copy_number = copy_number << BOUND - index;

		number = number | copy_number;

		return true;
	}

	//make it from  1-->0
	bool get(unsigned int index)
	{
		if (!is_in_bound(index))
			return false;
		if (!(this->operator[](index)))
			return true;


		unsigned int copy_number = number;

		//2.) makes all elem zero except the callable elem
		copy_number = copy_number << index;
		copy_number = copy_number >> BOUND;
		copy_number = copy_number << BOUND - index;

		//XNOR - izkliuchvashto ili 
		unsigned int all_one_in_binary = 4294967295;
		copy_number = copy_number ^ all_one_in_binary;

		number = number & copy_number;

		return true;
	}

};