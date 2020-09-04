#pragma once
#include "BTTask.h"
#include <vector>
using namespace std;

class BTTaskSelector :
	public BTTask
{
public:
	BTTaskSelector(vector<BTTask*> tasks);
	~BTTaskSelector();
	void addChild(BTTask* child);
	bool runTask();
protected:
	vector<BTTask*> m_childrenTasks;
};

