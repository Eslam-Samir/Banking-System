#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <algorithm>
#include "Transaction.h"
using namespace std;

class Deposit :Transaction {

private:
	double amount;

public:

	Deposit(double x);

	double getAmount();
 
	void setAmount(double x);

	void modify(double getAmount());
	
}; 
