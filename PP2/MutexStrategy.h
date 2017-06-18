#pragma once
#include "IStrategy.h"
#include "stdafx.h"

class CMutexStrategy :
	public IStrategy
{
public:
	CMutexStrategy();
	void Enter() override;
	void Release() override;
	~CMutexStrategy();
private:
	HANDLE m_mutex;
};

