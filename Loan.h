#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <algorithm>
#include "Transaction.h"
using namespace std;

class Loan :Transaction {
private:
	double amount;

public:

	Loan(double x);
	
	double getAmount();
	
	void setAmount(double x);
	

	void modify(double getAmount());
	
}; 
