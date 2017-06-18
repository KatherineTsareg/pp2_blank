#pragma once
#include <iostream>
#include <vector>
#include "BankClient.h"
#include "IStrategy.h"

class CBank
{
public:
	CBank(IStrategy* currentPrimitive);
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	void Wait();
	~CBank();

private:
	std::vector<CBankClient> m_clients;
	int m_totalBalance;
	IStrategy *m_primitive;
	std::vector<HANDLE> m_threads;

	int GetTotalBalance();
	void SetTotalBalance(int value);
	void SomeLongOperations();
};