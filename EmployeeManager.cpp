#include "EmployeeManager.h"

namespace BankingSystem 
{

EmployeeManager* EmployeeManager::employeeManagerPtr = nullptr;
int EmployeeManager::EmployeesCount = 0;
int EmployeeManager::nextID = 0;

EmployeeManager::EmployeeManager(){}

EmployeeManager * EmployeeManager::getEmployeeManager()
{
	if(employeeManagerPtr == nullptr)
	{
		employeeManagerPtr = new EmployeeManager();
	}
	return employeeManagerPtr;
}
int EmployeeManager::getNumberOfEmployees()
{
	return EmployeesCount;
}
Employee* EmployeeManager::EmployeeLogin(std::string username, std::string password)
{
	std::map<std::string, Employee*>::iterator it = employees.find(username);
	if(it == employees.end())
	{
		std::cout<< "Username Doesn't Exist" << std::endl;
		return nullptr;
	}
	else
	{
		if(password == it->second->getPassword())
		{
			std::cout<< "Login Succeeded" << std::endl;
			return it->second;
		}
		else
		{
			std::cout<< "Wrong Username or Password" << std::endl;
			return nullptr;
		}
	}
}
int EmployeeManager::addEmployee(std::string name, std::string Username, std::string password, EmployeeType type)
{
	std::map<std::string, Employee*>::iterator it = employees.find(Username);
	if(it != employees.end())
	{
		std::cout<< "Username already exists" << std::endl;
		return -1;
	}
	Employee *employee = nullptr;
	switch(type)
	{
	case EmployeeType::cashier:
		employee = new Cashier(nextID, name, Username, password);
		break;
	case EmployeeType::clerk:
		employee = new Clerk(nextID, name, Username, password);
		break;
	case EmployeeType::manager:
		employee = new Manager(nextID, name, Username, password);
		break;
	default:
		std::cout<< "Wrong Employee Type" << std::endl;
		return -1;
	}
	EmployeesCount++;
	std::cout<< "Added a new employee with the id: " << nextID++ << std::endl;
	employees[Username] = employee;
	return employee->getID();
}
bool EmployeeManager::removeEmployee(std::string Username, std::string password)
{
	std::map<std::string, Employee*>::iterator it = employees.find(Username);
	if(it == employees.end())
	{
		return false;
	}
	else
	{
		if(password != it->second->getPassword())
			return false;

		EmployeesCount--;
		int id = it->second->getID();
		employees.erase(it);
		std::cout<< "Removed the employee with the id: " << id << std::endl;
		return true;
	}
	return false;
}

void EmployeeManager::createEmployeesXml(std::ofstream & outFile)
{
	std::map<std::string, Employee*>::iterator it = employees.begin();
	while(it != employees.end())
	{
		Employee * employee = it->second;
		EmployeeType type = employee->getType();
		switch(type)
		{
		case EmployeeType::cashier:
			outFile << "<Cashier>\n";
			break;
		case EmployeeType::clerk:
			outFile << "<Clerk>\n";
			break;
		case EmployeeType::manager:
			outFile << "<Manager>\n";
			break;
		}
		outFile << "<EmployeeID>" << employee->getID() << "</EmployeeID>\n";
		outFile << "<Name>" << employee->getName() << "</Name>\n";
		outFile << "<Username>" << employee->getUsername() << "</Username>\n";
		outFile << "<Password>" << employee->getPassword() << "</Password>\n";
		
		switch(type)
		{
		case EmployeeType::cashier:
			outFile << "</Cashier>\n";
			break;
		case EmployeeType::clerk:
			outFile << "</Clerk>\n";
			break;
		case EmployeeType::manager:
			outFile << "</Manager>\n";
			break;
		}
		it++;
	}
}
void EmployeeManager::loadEmployeesXml(std::ifstream & inFile)
{
	std::stack<std::string> s;
	std::string line, name, username, password;
	int id;
	Employee* employee=nullptr;

	if(!std::getline(inFile, line))
		return;

	if(!std::getline(inFile, line))
		return;
	EmployeesCount = stoi(XmlParseTag(line, "<NumberOfEmployees>", s));

	if(!std::getline(inFile, line))
		return;
	nextID = stoi(XmlParseTag(line, "<NextID>", s));

	while(std::getline(inFile, line))
	{
		std::string type = line.substr(1, line.length()-2);
		s.push(line); // Employee tag <Clerk>, <Cashier>, or <Manager>

		if(!std::getline(inFile, line))
			return;
		id = stoi(XmlParseTag(line, "<EmployeeID>", s));

		if(!std::getline(inFile, line))
			return;
		name = XmlParseTag(line, "<Name>", s);

		if(!std::getline(inFile, line))
			return;
		username = XmlParseTag(line, "<Username>", s);

		if(!std::getline(inFile, line))
			return;
		password = XmlParseTag(line, "<Password>", s);

		if(type == "Cashier")
		{
			employee = new Cashier(id, name, username, password);
		}
		else if(type == "Clerk")
		{
			employee = new Clerk(id, name, username, password);
		}
		else if(type == "Manager")
		{
			employee = new Manager(id, name, username, password);
		}
		
		employees[username] = employee;
		if(!std::getline(inFile, line))
			return;

		if(line.size() > 2 && line.substr(2) == s.top().substr(1))
			s.pop(); // pop employee tag
		else
		{
			std::cout << "Error loading file" << std::endl;
			return;
		}
	}
}
bool EmployeeManager::saveEmployees(std::string filename)
{
	if(employees.empty())
		return false;
	if((filename.length() < 5) || (filename.substr(filename.length() - 4, 4) != ".xml"))
	{
		std::cout << "Wrong file extension \"must be an xml file\"" << std::endl;
		return false;
	}

	std::ofstream outFile(filename);
	if(!outFile.is_open())
		return false;

	outFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	outFile << "<NumberOfEmployees>" << getNumberOfEmployees() << "</NumberOfEmployees>\n";
	outFile << "<NextID>" << nextID << "</NextID>\n";
	createEmployeesXml(outFile);
	outFile.close();
	return true;
}
bool EmployeeManager::loadEmployees(std::string filename)
{
	if((filename.length() < 5) || (filename.substr(filename.length() - 4, 4) != ".xml"))
	{
		std::cout << "Wrong file extension \"must be an xml file\"" << std::endl;
		return false;
	}

	std::ifstream inFile(filename);
	if(!inFile.is_open())
		return false;

	loadEmployeesXml(inFile);
	inFile.close();
	return true;
}

std::string EmployeeManager::XmlParseTag(std::string & line, std::string TagName, std::stack<std::string> & s)
{
	std::string temp;
	s.push(TagName);
	line = line.substr(TagName.length(), line.length()-TagName.length());
	temp = line.substr(0, line.find("</"));
	line = line.substr(temp.length(), line.length()-temp.length());

	if(line.size() < 2 || line.substr(2) != s.top().substr(1))
		return "";

	s.pop();
	return temp;
}

}