#ifndef __MANAGER__
#define __MANAGER__

#include "Employee.h"
#include <iostream>

namespace BankingSystem 
{

class Manager : public Employee
{
private:

public:
	Manager(int id, std::string name, std::string Username, std::string Password);
	Permission AccessPermitions();
};

}

#endif // __MANAGER__