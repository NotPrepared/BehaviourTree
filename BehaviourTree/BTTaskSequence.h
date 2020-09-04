#pragma once
#include "BTTask.h"
#include <vector>
#include <iostream>
using namespace std;

class BTTaskSequence :
	public BTTask
{
public:
	BTTaskSequence(vector<BTTask*> tasks);
	~BTTaskSequence();
	void addChild(BTTask* child);
	bool runTask();


protected:
	vector<BTTask*> m_childrenTasks;
};

