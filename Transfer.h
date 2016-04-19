#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <algorithm>
#include "Transaction.h"
using namespace std;

class Transfer :Transaction {
private:
	double amount;

public:

	Transfer(double x);
	

	double getAmount();
	
	void setAmount(double x);
	

	void modify(double getAmount());
	


};