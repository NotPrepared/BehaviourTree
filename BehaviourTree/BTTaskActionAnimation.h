#pragma once
#include "BTTask.h"
#include <string>
using namespace std;
class BTTaskActionAnimation :
	public BTTask
{
public:
	BTTaskActionAnimation(string atext, int duration);
	~BTTaskActionAnimation();
	bool runTask();
protected:
	string m_text;
	int m_durationmilliseconds;
};

