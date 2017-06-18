#include "CriticalSectionStrategy.h"



CCriticalSectionStrategy::CCriticalSectionStrategy()
{
	InitializeCriticalSection(&m_criticalSection);
}

void CCriticalSectionStrategy::Enter()
{
	EnterCriticalSection(&m_criticalSection);
}

void CCriticalSectionStrategy::Release()
{
	LeaveCriticalSection(&m_criticalSection);
}


CCriticalSectionStrategy::~CCriticalSectionStrategy()
{
	DeleteCriticalSection(&m_criticalSection);
}
