#include "stdafx.h"
#include "BTTaskActionAnimation.h"
#include <iostream>
#include <thread>
using namespace std;

BTTaskActionAnimation::BTTaskActionAnimation(string atext, int duration)
{
	m_text = atext;
	m_durationmilliseconds = duration;
}

BTTaskActionAnimation::~BTTaskActionAnimation()
{
}

bool BTTaskActionAnimation::runTask()
{
	bool result = true;
	int maxwidth = 50;
	for (size_t x = 0; x < maxwidth - m_text.length(); x++)
	{
		system("cls");
		for (size_t j = 0; j < x; j++)
		{
			cout << "_";
		}
		cout << m_text;
		for (size_t j = x + m_text.length() + 1; j < maxwidth; j++)
		{
			cout << "_";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(m_durationmilliseconds));
	}
	return result;
}
