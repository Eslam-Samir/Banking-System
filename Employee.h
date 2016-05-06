#include <string>
class Employee
{
private:
	int Id;
	std::string Username;
	std::string Password;


public:
	Employee();
	Employee(std:: string Username,std::string Password);
	
	std::string getUsername();
	std::string getPassword();
	void setUsername(std::string Username);
	void setPassword(std::string Password);
protected:
	virtual void AccessPermitions() = 0;

};

