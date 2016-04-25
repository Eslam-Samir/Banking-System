#pragma once
#include <iostream>
#include "Transaction.h"
using namespace std;

class Withdraw :public Transaction {

private:
	double amount;


public:

	Withdraw(double x);
	
	double getAmount();
	
	void setAmount(double x);
	

	void modify();
	
};
