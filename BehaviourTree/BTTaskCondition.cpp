#include "stdafx.h"
#include "BTTaskCondition.h"
#include <iostream>


BTTaskCondition::BTTaskCondition(GameObject * aTargetGO)
{
	m_targetGO = aTargetGO;
}

BTTaskCondition::~BTTaskCondition()
{
}

bool BTTaskCondition::runTask()
{
	if (m_targetGO == NULL)
		return false;
	if (!m_targetGO->isActive())
		return false;
	std::cout << "Target " << m_targetGO->getName() << " is available!" << std::endl;
	return true;
}
