#pragma once
#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct Company
{
	string name;
	string profit_tax;
	string address;
};
vector<Company> readCompanyList(string file_name);
long long hashString(string company_name);

Company* createHashTable(vector<Company> list_company);
void insert(Company* hash_table, Company company);
Company* search(Company* hash_table, string company_name);
Company* search1(Company* hash_table, string company_name);
unsigned long long hashString1(string company_name);
#endif // !Header_h
