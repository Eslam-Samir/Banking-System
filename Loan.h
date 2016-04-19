#pragma once
#include <iostream>
#include "Transaction.h"
using namespace std;

class Loan :public Transaction {
private:
	double amount;
	void loanAmount(bool t);

public:

	Loan(double x);
	
	double getAmount();
	
	void setAmount(double x);
	

	void modify();
	
}; 
