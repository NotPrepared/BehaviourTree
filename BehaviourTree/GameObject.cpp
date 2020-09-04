#include "stdafx.h"
#include "GameObject.h"



GameObject::GameObject(std::string name, bool active)
{
	m_name = name;
	m_isActive = active;
}

GameObject::~GameObject()
{
}

bool GameObject::isActive()
{
	return m_isActive;
}

void GameObject::setActive(bool newvalue)
{
	m_isActive = newvalue;
}

string GameObject::getName()
{
	return m_name;
}
