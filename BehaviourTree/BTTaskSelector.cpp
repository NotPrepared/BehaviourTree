#include "stdafx.h"
#include "BTTaskSelector.h"
#include <iostream>
using namespace std;


BTTaskSelector::BTTaskSelector(vector<BTTask*> tasks)
{
	m_childrenTasks = tasks;
}

BTTaskSelector::~BTTaskSelector()
{
}

void BTTaskSelector::addChild(BTTask * child)
{
	m_childrenTasks.push_back(child);
}

bool BTTaskSelector::runTask()
{
	for (size_t i = 0; i < m_childrenTasks.size(); i++)
	{
		if (m_childrenTasks.at(i)->runTask()) {
			cout << "A Task could be SELECTED!" << endl;
			return true;
		}
	}
	cout << "No Task could be SELECTED!" << endl;
	return false;
}
