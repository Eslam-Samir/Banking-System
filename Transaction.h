#pragma once
#include <iostream>
using namespace std;

class Transaction {
private:
	double TransactionId;
	double AccountNumber;
	//date

public:
	//constructor
	//Transaction();
	Transaction(double id = 0, double number = 0);

	//setters and getters
	double getTransactionId();
	void setTransactionId(double x);
	
	double getAccountNumber();
	void setTAccountNumber(double x);
	
	virtual void modify();
	

};