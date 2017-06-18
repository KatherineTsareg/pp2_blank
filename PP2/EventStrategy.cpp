#include "EventStrategy.h"

CEventStrategy::CEventStrategy()
{
	m_event = CreateEvent(NULL, false, true , NULL);
}

void CEventStrategy::Enter()
{
	WaitForSingleObject(m_event, INFINITE);
}

void CEventStrategy::Release()
{
	SetEvent(m_event);
}


CEventStrategy::~CEventStrategy()
{
	CloseHandle(m_event);
}
