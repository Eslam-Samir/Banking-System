#pragma once
#include <iostream>
#include "Transaction.h"
using namespace std;

class CheckBalance :public Transaction {

private:
	double check();

public:
	void modify();

};
