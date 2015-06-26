#include "bool_vector.h"
#include "double_vector.h"

const int SIZE_ar = 6, SIZE_ar2 = 9;
int main()
{
	double ar[SIZE_ar] = { 0, 1, 2, 3, 4, 5 };
	double ar2[SIZE_ar2] = { 8,7,6,5,4,3,2,1,0};

	DoubleVector dv1(SIZE_ar, ar);
	DoubleVector dv2(SIZE_ar2, ar2);

	DoubleVector dv3;
	dv3 = dv1;

	double p = dv1[1];

	DoubleVector v;
	v =  dv2 + dv1 + dv1 - dv2 - dv1;
	v.print();

	dv1 += dv3 += dv2 -= dv2;
	dv1.print();

	dv1 = dv3 * 2 * 4 ;
	dv1 *= 2;
	dv3 = dv1 / 2;
	dv3 /= 2;
	double scalar = dv3% dv1;

	BoolVector a(2);
	cout<<"number in binary ...00000010 --> in array pos[31] bit is "<<a[31]
		<<endl<<"in array pos[3] - bit is "<<a[30]<<endl;
	a.set(30);
	cout << "Nothing changes because in pos 30 it has 1. The number is the same (2) :" << a.get_number()<<endl;
	a.set(31);
	cout << "Change on pos 31 from 0 to 1. The new number is 3:" << a.get_number()<<endl;
	
	BoolVector b(55);
	b.set(28);
	cout << "We are working with this number 00..110111 in binary (decimal 55)."<<endl
		<<"We want to make it 00.. 111111 exacly 63 in decimal : " << b.get_number() << endl;
	b.get(28);
	cout << "We are working with 00.. 111111 decimal 63 changing into  00..110111  decimal 55:" << b.get_number() << endl;
}