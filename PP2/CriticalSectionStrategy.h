#pragma once
#include "IStrategy.h"
#include "stdafx.h"

class CCriticalSectionStrategy :
	public IStrategy
{
public:
	CCriticalSectionStrategy();
	void Enter() override;
	void Release() override;
	~CCriticalSectionStrategy();
private:
	CRITICAL_SECTION m_criticalSection;
};

