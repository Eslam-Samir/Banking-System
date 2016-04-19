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
	cout << ptr->addAccount(200000,"hi",eslam) << endl;
	cout << ptr->addAccount(223,"hii",manar) << endl;
	cout << ptr->addAccount(0.5,"hiii",menna) << endl;
	cout << ptr->searchAccount(0)->getBalance() << endl;
	cout << ptr->searchAccount(1)->getBalance() << endl;
	cout << ptr->searchAccount(2)->getBalance() << endl;
	cout << ptr->validateAccount(0, "hi") << endl;
	cout << ptr->validateAccount(1, "8alat") << endl;
	cout << ptr->validateAccount(3, "hiii") << endl;

	ptr->removeAccount(ptr->searchAccount(0));
	ptr->removeAccount(ptr->searchAccount(1));
	ptr->removeAccount(ptr->searchAccount(2));

	system("pause");
}