#pragma once
class IStrategy
{
public:
	virtual ~IStrategy() = default;
	virtual void Enter() = 0;
	virtual void Release() = 0;
};

