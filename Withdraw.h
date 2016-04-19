#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <algorithm>
#include "Transaction.h"
using namespace std;

class Withdraw :Transaction {

private:
	double amount;

public:

	Withdraw(double x);
	
	double getAmount();
	
	void setAmount(double x);
	

	void modify(double getAmount());
	
};
