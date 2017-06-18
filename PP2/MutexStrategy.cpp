#include "MutexStrategy.h"



CMutexStrategy::CMutexStrategy()
{
	m_mutex = CreateMutex(NULL, false, NULL);
}

void CMutexStrategy::Enter()
{
	WaitForSingleObject(m_mutex, INFINITE);
}

void CMutexStrategy::Release()
{
	ReleaseMutex(m_mutex);
}


CMutexStrategy::~CMutexStrategy()
{
	CloseHandle(m_mutex);
}
