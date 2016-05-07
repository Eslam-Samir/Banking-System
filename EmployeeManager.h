#ifndef __EMPLOYEEMANAGER__
#define __EMPLOYEEMANAGER__

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include "Cashier.h"
#include "Clerk.h"
#include "Manager.h"
#include "Employee.h"

namespace BankingSystem 
{

class EmployeeManager 
{
private:
	EmployeeManager();
	void createEmployeesXml(std::ofstream & outFile);
	void loadEmployeesXml(std::ifstream & inFile);
	std::string XmlParseTag(std::string & line, std::string TagName, std::stack<std::string> & s);

	std::map<std::string, Employee*> employees; // key-> employee id, value -> employee ptr
	static EmployeeManager * employeeManagerPtr; // singleton
	static int EmployeesCount;
	static int nextID;
public:
	static EmployeeManager * getEmployeeManager();
	static int getNumberOfEmployees();
	Employee* EmployeeLogin(std::string username, std::string password);
	int addEmployee(std::string name, std::string Username, std::string password, EmployeeType type);
	bool removeEmployee(std::string Username, std::string password);

	bool saveEmployees(std::string filename);
	bool loadEmployees(std::string filename);

};

}

#endif // __EMPLOYEEMANAGER__