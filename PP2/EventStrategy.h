#pragma once
#include "IStrategy.h"
#include "stdafx.h"

class CEventStrategy :
	public IStrategy
{
public:
	CEventStrategy();
	void Enter() override;
	void Release() override;
	~CEventStrategy();
private:
	HANDLE m_event;
};

