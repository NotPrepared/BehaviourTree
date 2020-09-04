#pragma once
#include <string>
using namespace std;
class GameObject
{
public:
	GameObject(std::string name, bool active);
	~GameObject();
	bool isActive();
	void setActive(bool newvalue);
	string getName();
protected:
	bool m_isActive;
	string m_name;
};

