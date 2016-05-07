#ifndef __CLERK__
#define __CLERK__

#include "Employee.h"
#include <iostream>

namespace BankingSystem 
{
	class Clerk : public Employee
	{
	public:
		Clerk(int id, std::string name, std::string Username, std::string Password);
		Permission AccessPermitions();
		
	

	};

	

}
#endif // __CLERK__