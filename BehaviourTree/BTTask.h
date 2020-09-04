#pragma once
#include <vector>
using namespace std;
class BTTask
{
public:
	BTTask(vector<BTTask*>);
	BTTask();
	~BTTask();
	virtual bool runTask() = 0;
	virtual void terminateTask();
protected:
	vector<BTTask*> m_childrenTasks;
};