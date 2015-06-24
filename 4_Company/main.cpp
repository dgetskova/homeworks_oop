#include "Manager.h"
#include "Company.h"
#include "Director.h"

int main()
{
	//create servants
	Servant serv0("first", "str. first","it", 1234567890, 10);
	Servant serv10(serv0);
	Servant serv20("second", "str. second", "farma", 123, 213);
	serv10 = serv20;

	//create spec
	Specialist spec0("before", "street 1","it", 1234567890, 1000.50, "barman");
	Specialist spec10(spec0);
	Specialist spec20("after", "str.2","section", 123, 213, "sportist");
	spec20 = spec10;

	//Create company
	Servant ** firma = new Servant*[4];
	firma[0] = &serv0;
	firma[1] = &serv20;
	firma[2] = &spec0;
	firma[3] = &spec20;
	
	//create managers
	Manager manag("emo", "blg-street 1","emo_section", 1234567890, 1000.50, "emo_dev", "it", firma, 4);
	Manager manag1("m1", "adress1","m1_section", 123, 321, "m1-spec", "m1-otdel", firma, 3);
	manag1 = manag;
	Manager manag_cop(manag);

	//create secretary
	char* languages[] = { "angl", "bg", "spanish" };
	Secretary asen(languages,3);

	//create company
	Servant serv("a", "street a", "it", 1234567890, 10);
	Servant serv1("a", "street a", "it", 1234567890, 10);
	Servant serv2("a", "street a", "it", 1234567890, 10);
	Servant serv3("a", "street a", "no", 1234567890, 10);
	Specialist spec("b", "street b", "it", 1234567890, 100, "dev");
	Specialist spec1("b", "street b", "it", 1234567890, 100, "dev");
	Specialist spec2("b", "street b", "it", 1234567890, 100, "dev");
	Specialist spec3("b", "street b", "it", 1234567890, 100, "dev");
	Manager manag_("emo", "blg-street 1", "emo_section", 1234567890, 1000, "dev", "it", firma, 4);

	Servant ** company_servants = new Servant*[9];

	company_servants[0] = &serv;
	company_servants[1] = &serv1;
	company_servants[2] = &serv2;
	company_servants[3] = &serv3;
	company_servants[4] = &spec;
	company_servants[5] = &spec1;
	company_servants[6] = &spec2;
	company_servants[7] = &spec3;
	company_servants[8] = &manag_;

	Company company(company_servants,9);
	bool truee = company.can_make_company(2, 3, "dev", 1, "it");
	bool falsee = company.can_make_company(2, 3, "dev", 5, "it");

	Director  dir(asen, company_servants, 9);
	int money = dir.get_all_salary();

	delete[]company_servants;
	delete[]firma;

	return 0;
}
