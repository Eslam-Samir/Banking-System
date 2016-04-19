#pragma once
#include <iostream>
#include <queue>
#include "Client.h"
using namespace std;

class TransactionManager 
{
private:
	queue<Client> withdraw;
	queue<Client> deposit;
	queue<Client> transfer;
	queue<Client> loans;
	queue<Client> checkbalance;

public:



};