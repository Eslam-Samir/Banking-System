#include <iostream>
#include "AccountManager.h"
#include "Tree.h"
#include "TreeNode.h"
using namespace std;

AccountManager* AccountManager::accountManagerPtr = nullptr;

void main()
{
	AccountManager * ptr = AccountManager::getAccountManager();
	Client *eslam, *manar, *menna;
	eslam = new Client();
	manar = new Client();
	menna = new Client();
	double acc1, acc2, acc3;
	acc1 = ptr->addAccount(200000,"hi",eslam);
	acc2 = ptr->addAccount(223,"hii",manar);
	acc3 = ptr->addAccount(0.5,"hiii",menna);
	cout << acc1 << endl;
	cout << acc2 << endl;
	cout << acc3 << endl;
	cout << ptr->searchAccount(acc1)->getBalance() << endl;
	cout << ptr->searchAccount(acc2)->getBalance() << endl;
	cout << ptr->searchAccount(acc3)->getBalance() << endl;
	cout << ptr->validateAccount(acc1, "hi") << endl;
	cout << ptr->validateAccount(acc2, "8alat") << endl;
	cout << ptr->validateAccount(acc3, "hiii") << endl;

	ptr->removeAccount(ptr->searchAccount(acc1));
	ptr->removeAccount(ptr->searchAccount(acc2));
	ptr->removeAccount(ptr->searchAccount(acc3));

	system("pause");
}