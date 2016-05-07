#include "Employee.h"
namespace BankingSystem 
{
	
Employee:: Employee(int id, std::string Name, std::string Username, std::string Password, EmployeeType Type)
{
	(*this).Id=id;
	(*this).Username=Username;
	(*this).Password=Password;
	(*this).Type=Type;
}
int Employee::getID()
{
	return Id;
}
std::string Employee::getName()
{
	return Name;
}
std::string Employee::getPassword()
{
	return Password;
}
std::string Employee::getUsername()
{
	return Username;
}
EmployeeType Employee::getType()
{
	return Type;
}
void Employee::setPassword(std::string Password)
{
	(*this).Password=Password;
}

}