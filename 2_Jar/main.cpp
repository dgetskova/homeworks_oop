#include "Jar.h"

int main()
{
	Jar des;
	//des.deserialize(); // before deserialize you need to create serializa
	
	char **content = new char*[5];

	content[0] = new char[strlen("first")];
	content[0] = "first";
	content[1] = new char[strlen("second")];
	content[1] = "second";
	content[2] = new char[strlen("third")];
	content[2] = "third";
	content[3] = new char[strlen("fourth")];
	content[3] = "fourth";
	content[4] = new char[strlen("f")];
	content[4] = "f";

	char **contentee = new char*[4];

	contentee[0] = new char[strlen("one")];
	contentee[0] = "one";
	contentee[1] = new char[strlen("two")];
	contentee[1] = "two";
	contentee[2] = new char[strlen("three")];
	contentee[2] = "three";
	contentee[3] = new char[strlen("four")];
	contentee[3] = "four";


	Biscuit a( content, 5);
	Biscuit b(contentee, 4);
	Jar jary_empty;
	jary_empty.add_biscuit(a);
	jary_empty.add_biscuit(a);
	jary_empty.add_biscuit(b);

	Jar jary(5);

	jary.add_biscuit(a);
	jary.add_biscuit(a);
	jary.add_biscuit(a);
	jary.remove_biscuit();
	jary.add_biscuit(b);

	jary.serialize();

	delete []content;
	delete[]contentee;

}