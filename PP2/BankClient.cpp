#include "BankClient.h"
#include "Bank.h"


CBankClient::CBankClient(CBank *bank, unsigned id)
	: m_bank(bank)
	, m_id(id)
{
	m_handle = CreateThread(NULL, 0, ThreadFunction, this, 0, NULL);
}


unsigned CBankClient::GetId()
{
	return m_id;
}


DWORD WINAPI CBankClient::ThreadFunction(LPVOID lpParam)
{
	CBankClient *client = (CBankClient*)lpParam;
	srand(client->m_id);
	client->m_bank->UpdateClientBalance(*client, GetBalanceChangeValue());
	return 0;
}


unsigned CBankClient::GetBalanceChangeValue()
{
	// -100 .. 100
	return rand() % 201 - 100;
}