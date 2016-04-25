#pragma once
#include <iostream>
#include "Transaction.h"
using namespace std;

class Loan :public Transaction {
private:
	double amount;

public:

	Loan(double x);
	
	double getAmount();
	
	void setAmount(double x);
	

	void modify();
	
}; 
