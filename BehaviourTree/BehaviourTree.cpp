// BehaviourTree.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <string>
#include "GameObject.h"
#include "BTTaskCondition.h"
#include "BTTaskSelector.h"
#include "BTTaskSequence.h"
#include "BTTaskActionAnimation.h"
#include "BTTaskDecoratorUntilFail.h"
#include <iostream>
#include <thread>
using namespace std;


int main()
{
	//Modellierter Baum
	//GameObjects Basically Knowledge
	GameObject* mensa = new GameObject("Mensa", true);
	GameObject* geniessbar = new GameObject("Geniessbar", false);

	//Conditions
	BTTaskCondition* mensaoffen = new BTTaskCondition(mensa);
	BTTaskCondition* essengeniessbar = new BTTaskCondition(geniessbar);

	//Actions
	BTTaskActionAnimation* essenwaelen = new BTTaskActionAnimation("Waehle Essen", 100);
	BTTaskActionAnimation* kochen = new BTTaskActionAnimation("Koche Essen", 600);
	BTTaskActionAnimation* essen = new BTTaskActionAnimation("Guten Hunger", 200);
	BTTaskActionAnimation* weinen = new BTTaskActionAnimation("Weine", 20);

	//Baum mithilfe von Selections und Sequences von unten nach oben aufbauen
	vector<BTTask*> vectorfuermensaessen;
	vectorfuermensaessen.push_back(mensaoffen);
	vectorfuermensaessen.push_back(essenwaelen);
	BTTaskSequence* mensasequence = new BTTaskSequence(vectorfuermensaessen);

	vector<BTTask*> vectorfuerkochen;
	vectorfuerkochen.push_back(kochen);
	vectorfuerkochen.push_back(essengeniessbar);
	BTTaskSequence* kochensequence = new BTTaskSequence(vectorfuerkochen);

	vector<BTTask*> vectorfueressensauswahl;
	vectorfueressensauswahl.push_back(mensasequence);
	vectorfueressensauswahl.push_back(kochensequence);
	BTTaskSelector* essensauswahl = new BTTaskSelector(vectorfueressensauswahl);

	vector<BTTask*> vectorfueressprozess;
	vectorfueressprozess.push_back(essensauswahl);
	vectorfueressprozess.push_back(essen);
	BTTaskSequence* esssequence = new BTTaskSequence(vectorfueressprozess);

	vector<BTTask*> vectorfuerweinauswahl;
	vectorfuerweinauswahl.push_back(esssequence);
	vectorfuerweinauswahl.push_back(weinen);
	BTTaskSelector* root = new BTTaskSelector(vectorfuerweinauswahl);

	root->runTask();
	
	cout << "Nächster Tag" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	mensa->setActive(false);
	root->runTask();
	
	cout << "Nächster Tag" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	geniessbar->setActive(true);
	root->runTask();
	
	//Mit Dekorator
	GameObject* doener = new GameObject("Doener",false);
	BTTaskCondition* doenerInHand = new BTTaskCondition(doener);
	BTTaskActionAnimation* essenmitdecorator = new BTTaskActionAnimation("Essen", 300);
	BTTaskActionAnimation* schlafen = new BTTaskActionAnimation("Schlafen", 600);
	BTTaskDecoratorUntilFail* doenerDecorator = new BTTaskDecoratorUntilFail(doenerInHand);
	vector<BTTask*> vectorfuerroot2;
	vectorfuerroot2.push_back(doenerDecorator);
	vectorfuerroot2.push_back(essenmitdecorator);
	vectorfuerroot2.push_back(schlafen);
	BTTaskSequence* rootmitdecorator = new BTTaskSequence(vectorfuerroot2);
	rootmitdecorator->runTask();
	
	return 0;
}

