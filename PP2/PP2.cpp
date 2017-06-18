#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"
#include "CriticalSectionStrategy.h"
#include "MutexStrategy.h"
#include "SemaphoreStrategy.h"
#include "EventStrategy.h"
#include "stdafx.h"

std::unique_ptr<IStrategy> GetPrimitivePtr(std::string const& namePrimitive)
{
	if (namePrimitive == "criticalSection")
	{
		return std::make_unique<CCriticalSectionStrategy>();
	}
	else if (namePrimitive == "event")
	{
		return std::make_unique<CEventStrategy>();
	}
	else if (namePrimitive == "mutex")
	{
		return std::make_unique<CMutexStrategy>();
	}
	else if(namePrimitive == "semaphore");
	{
		return std::make_unique<CSemaphoreStrategy>();
	}
	throw std::exception("Cannot find type of primitive");
}

int main(int argc, char* argv[])
{
	if (argc != 3 || *argv[1] == '?')
	{
		std::cout << "Enter type of primitive (mutex/criticalSection/semaphore/event) and clients number." << std::endl;
		return 1;
	}
	std::unique_ptr<IStrategy> primitive;
	try
	{
		primitive = GetPrimitivePtr(argv[1]);
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
		return 1;
	}
	int clientsNumber = atoi(argv[2]);

	CBank* bank = new CBank(primitive.get());

	for (int i = 0; i < clientsNumber; i++) 
	{
		bank->CreateClient();
	}

	bank->Wait();
	delete bank;
    return 0;
}