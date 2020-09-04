#pragma once
#include "BTTask.h"
class BTTaskDecoratorUntilFail :
	public BTTask
{
public:
	BTTaskDecoratorUntilFail(BTTask* child);
	~BTTaskDecoratorUntilFail();
	bool runTask();
protected:
	BTTask * m_child;
};

