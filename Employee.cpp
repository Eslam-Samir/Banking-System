#include "Employee.h"
namespace BankingSystem 
{
Employee:: Employee()
{
	Username="";
	Password="";
}
Employee::Employee(std:: string Username,std::string Password)
{
	(*this).Username=Username;
	(*this).Password=Password;
}
std::string Employee::getPassword()
{
	return Password;
}
std::string Employee::getUsername()
{
	return Username;
}
void Employee::setPassword(std::string Password)
{
	(*this).Password=Password;
}
void Employee::setUsername(std::string Username)
{
	(*this).Username=Username;
}
}