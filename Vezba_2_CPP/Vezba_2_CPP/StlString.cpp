
// order for std::string as key in unorderd collection
//#include <iostream>
//#include <map>
//#include <unordered_map>
//#include <string>
//#include <functional>


#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include <windows.h>
#include <functional>
#include <time.h>
#include "Array.h"
#include "NodeWeight.h"



using namespace std; 

void mainStringHash() // StringHash
{ 
	map<unsigned long, string> employer; 
	unordered_map<unsigned long, unsigned> salary;

	employer[2014021701] = "Celine Dion"; 
	employer[2014021702] = "Whitney Houston"; 
	
	for(auto e: employer) 
		cout << "name: " << e.second << "\t id: " << e.first << endl; 
	unsigned total_payroll = 0; 
	
	salary[2014021702] = 654321; 
	salary[2014021701] = 123456; 
	
	for(auto s: salary) 
		total_payroll += s.second; 
	
	cout << "total payrolls $" << total_payroll << endl;

	std::unordered_map<std::string, float, std::hash<string>> sf;	// std::hash<std::string>

	sf.insert(make_pair("Celine Dion", 1.0f));
	sf.insert(make_pair("Whitney Houston", 2.0f));
	cout << "    unordered map: " << endl;
	for (auto s : sf)
		cout << "name: " << s.first << "\t value: " << s.second << endl;
	sf["Celine Dion"] += 10.0f; sf["Whitney Houston"] += 10.0f;
	for (auto s : sf)
		cout << "name: " << s.first << "\t value: " << s.second << endl;
	std::unordered_set<std::string, std::hash<string>> sets;	// std::hash<std::string>

	sets.insert("Celine Dion");
	sets.insert("Whitney Houston");
	cout << "    set: " << endl;
	for (auto s : sets)
		cout << "name: " << s << endl;





}