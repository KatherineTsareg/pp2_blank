#include "SemaphoreStrategy.h"



CSemaphoreStrategy::CSemaphoreStrategy()
{
	m_semaphore = CreateSemaphore(NULL, 1, 1, NULL);
}

void CSemaphoreStrategy::Enter()
{
	WaitForSingleObject(m_semaphore, INFINITE);
}

void CSemaphoreStrategy::Release()
{
	WaitForSingleObject(m_semaphore, INFINITE);
}


CSemaphoreStrategy::~CSemaphoreStrategy()
{
	CloseHandle(m_semaphore);
}
