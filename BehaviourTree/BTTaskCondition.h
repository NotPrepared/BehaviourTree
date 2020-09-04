#pragma once
#include "BTTask.h"
#include "GameObject.h"

class BTTaskCondition :
	public BTTask
{
public:
	BTTaskCondition(GameObject* aTargetGO);
	~BTTaskCondition();
	bool runTask();
protected:
	GameObject * m_targetGO;
};

