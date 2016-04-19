#pragma once
#include <iostream>
#include "Transaction.h"
using namespace std;

class Transfer :public Transaction {
private:
	double amount;
	void transferAmount();
public:

	Transfer(double x);
	

	double getAmount();
	
	void setAmount(double x);
	

	void modify();
	


};