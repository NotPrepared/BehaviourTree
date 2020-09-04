#include "stdafx.h"
#include "BTTaskSequence.h"





BTTaskSequence::BTTaskSequence(vector<BTTask*> tasks)
{
	m_childrenTasks = tasks;
}

BTTaskSequence::~BTTaskSequence()
{
}

void BTTaskSequence::addChild(BTTask * child)
{
	m_childrenTasks.push_back(child);
}

bool BTTaskSequence::runTask()
{
	for (size_t i = 0; i < m_childrenTasks.size(); i++)
	{
		if (!m_childrenTasks.at(i)->runTask()) {
			cout << "A Task has stopped the SEQUENCE!" << endl;
			return false;
		}
	}
	cout << "SEQUENCE completed!" << endl;
	return true;
}
