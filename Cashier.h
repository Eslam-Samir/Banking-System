#ifndef __CASHIER__
#define __CASHIER__

#include "Employee.h"
#include <iostream>

namespace BankingSystem 
{
	class Cashier:public Employee
	{
	public:
		Cashier(int id, std::string name, std::string Username, std::string Password);
		Permission AccessPermitions();
		
	

	};

	

}
#endif // __CASHIER__