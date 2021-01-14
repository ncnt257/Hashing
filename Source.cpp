#include "Header.h"
unsigned long long m = pow(10, 9) + 9;
int p = 31;
vector<Company> readCompanyList(string file_name)
{
	ifstream f;
	f.open(file_name, ifstream::in);
	vector<Company> data;
	Company comp;
	string line;
	string delemiter = "|";
	getline(f, line);
	int pos;
	while (getline(f, line))
	{
		comp.name = line.substr(0, line.find(delemiter));
		pos = comp.name.length() + 1;
		comp.profit_tax = line.substr(pos, line.find(delemiter, pos)-pos);
		pos += comp.profit_tax.length() + 1;
		comp.address= line.substr(pos, line.find(delemiter, pos)-pos);
		data.push_back(comp);

	}
	return data;
}
long long hashString(string company_name)
{
	long long sum = 0;
	long m = pow(10, 9) + 9;

	if (company_name.length() < 20)
	{
		for (int i = 0; i < company_name.length(); i++)
		{
			int acNum = (int)company_name[i];
			unsigned long long l = (unsigned long long)(acNum * pow(31, i)) % m;
			sum = (sum + l) % m;

		}		
	}
	else
	{
		for (int i = company_name.length() - 20; i < company_name.length(); i++)
		{
			int acNum = (int)company_name[i];
			unsigned long long l = (unsigned long long)(acNum * pow(31, i - (company_name.length() - 20))) % m;
			sum = (sum+l)%m;
			
		}
	}
	return sum;
}

Company* createHashTable(vector<Company> list_company) {
	
	int m = 2000;
	Company* hashTable = new Company[m];
	for (int i = 0; i < m; i++)
	{
		hashTable[i].name = "This index is empty";
	}
	for (int i = 0; i < list_company.size(); i++)
	{
		int pos = hashString(list_company[i].name) % m;
		while (hashTable[pos].name != "This index is empty")
		{
			pos++;
			if (pos >= m)
			{
				pos = pos % m;
			}
		}
		hashTable[pos]= list_company[i];
	}
	return hashTable;
}
void insert(Company* hash_table, Company company)
{
	long long hashCode = hashString(company.name);
	int pos = hashCode % 2000;
	while (hash_table[pos].name != "This index is empty")
	{
		pos++;
		if (pos >= 2000)
		{
			pos = pos % 2000;
		}
	}
	hash_table[pos] = company;
}
Company* search(Company* hash_table, string company_name)
{
	long long hashCode = hashString(company_name);
	int pos = hashCode % 2000;
	while (hash_table[pos].name != company_name)
	{
		if (hash_table[pos].name == "This index is empty")
		{
			return NULL;
		}
		pos++;
		if (pos >= 2000)
		{
			pos = pos % 2000;
		}
	}
	return &hash_table[pos];
}
Company* search1(Company* hash_table, string company_name)
{
	unsigned long long hash = hashString1(company_name);
	int idx = hash % 2000;
	Company* cp = new Company;
	if (hash_table[idx].name == "")
		return nullptr;
	else if (hash_table[idx].name == company_name) {
		cp->address = hash_table[idx].address;
		cp->name = hash_table[idx].name;
		cp->profit_tax = hash_table[idx].profit_tax;
		return cp;
	}
	else {
		int stone = idx;
		while (hash_table[idx].name != company_name && idx != stone - 1)idx = (idx++) % 2000;
		if (idx == stone - 1)
			return nullptr;
		else {
			cp->address = hash_table[idx].address;
			cp->name = hash_table[idx].name;
			cp->profit_tax = hash_table[idx].profit_tax;
			return cp;
		}
	}
}
unsigned long long hashString1(string company_name)
{
	unsigned long long hash = 1;
	int length = company_name.length();
	string new_cp_name; int idx = 0;

	if (length > 20)
		new_cp_name = company_name.substr(length - 20, length - 1);
	else
		new_cp_name = company_name;

	unsigned long long temp = 0;
	for (int i = 0; i < new_cp_name.length(); i++) {
		int d = i % 10;
		int n = i / 10;
		unsigned long long temp1 = pow(p, d) * int(new_cp_name[i]);
		hash = hash * (temp1 % m);

		unsigned long long temp2 = 1;
		for (int a = 0; a < n; a++) {
			temp2 = pow(p, 10);
			hash = hash * (temp2 % m);
		}
	}
	return (unsigned long long)hash % m;
}
