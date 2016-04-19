#pragma once
#include <iostream>
#include "Transaction.h"
using namespace std;

class Deposit :public Transaction {

private:
	double amount;
	void DepositAmount();

public:

	Deposit(double x);

	double getAmount();
 
	void setAmount(double x);

	void modify();
	
}; 
