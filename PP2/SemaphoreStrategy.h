#pragma once
#include "IStrategy.h"
#include "stdafx.h"

class CSemaphoreStrategy :
	public IStrategy
{
public:
	CSemaphoreStrategy();
	void Enter() override;
	void Release() override;
	~CSemaphoreStrategy();
private:
	HANDLE m_semaphore;
};

