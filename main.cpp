#include "Header.h"

int main()
{
	vector<Company> list= readCompanyList("MST.txt");
	Company* hashTable;
	hashTable =createHashTable(list);
	for (int i = 0; i < 100; i++)
	{
		cout << i << "\t";
		cout << hashTable[i].name;
		cout << endl;
	}
	string C;
	Company* comp;
	while(true)
	{
		cout << "Nhap cong ty can tim: ";
		getline(cin,C);
		comp = search1(hashTable, C);
		if (comp == NULL)
		{
			cout << "Hong co!";
		}
		else
		{

			cout << "Cong ty can tim:\n" << comp->name << endl << comp->address << endl << comp->profit_tax;
		}
		cout << endl;
	}
	
}
