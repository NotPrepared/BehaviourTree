#include "stdafx.h"
#include "BTTaskDecoratorUntilFail.h"



BTTaskDecoratorUntilFail::BTTaskDecoratorUntilFail(BTTask * child)
{
	m_child = child;
}

BTTaskDecoratorUntilFail::~BTTaskDecoratorUntilFail()
{
}

bool BTTaskDecoratorUntilFail::runTask()
{
	bool result = true;
	do {
		result = m_child->runTask();
	} while (result);
	return true;
}
