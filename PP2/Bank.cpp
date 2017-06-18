#include "Bank.h"

CBank::CBank(IStrategy* currentPrimitive)
{
	m_clients = std::vector<CBankClient>();
	m_primitive = currentPrimitive;
	m_totalBalance = 0;
}


CBankClient* CBank::CreateClient()
{
	unsigned clientId = unsigned(m_clients.size());
	CBankClient* client = new CBankClient(this, clientId);
	m_clients.push_back(*client);
	m_threads.push_back(client->m_handle);
	return client;
}


void CBank::UpdateClientBalance(CBankClient &client, int value)
{
	m_primitive->Enter();

	int totalBalance = GetTotalBalance();
	std::cout << "Client " << client.GetId() << " initiates reading total balance. Total = " << totalBalance << "." << std::endl;
	
	SomeLongOperations();
	totalBalance += value;

	std::cout
		<< "Client " << client.GetId() << " updates his balance with " << value
		<< " and initiates setting total balance to " << totalBalance
		<< ". Must be: " << GetTotalBalance() + value << "." << std::endl;

	// Check correctness of transaction through actual total balance
	if (totalBalance != GetTotalBalance() + value) {
		std::cout << "! ERROR !" << std::endl;
	}

	SetTotalBalance(totalBalance);

	m_primitive->Release();
}

void CBank::Wait()
{
	WaitForMultipleObjects(m_threads.size(), m_threads.data(), true, INFINITE);
}

CBank::~CBank()
{
	for (auto thread : m_threads)
	{
		CloseHandle(thread);
	}
}


int CBank::GetTotalBalance()
{
	return m_totalBalance;
}


void CBank::SetTotalBalance(int value)
{
	m_totalBalance = value;
}

void CBank::SomeLongOperations()
{
	Sleep(2000);
}