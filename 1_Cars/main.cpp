#include <cstdlib>
# include "db_cls.h"

int main()
{
	db_cls a;
	//when we generate binary file we can load info from this file
	//a.read_from_bin();
	a.add("zero", 0, 1111);
	a.add("one", 1, 1987);
	a.add("two", 2, 2345);
	a.add("three", 3, 9870);
	a.add("four", 0, 1687);
	a.add("five", 1, 1999);
	a.generate_bin_file();
	a.generate_txt();
}
