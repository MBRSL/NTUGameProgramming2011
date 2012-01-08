#ifndef _OURACTOR_H_
#define _OURACTOR_H_
#include "TheFlyWin32.h"
#include "OurAction.h"
class OurActor{
public:
	//var
	WORLDid gID;
	SCENEid sID;
	FnActor actor;
	ACTORid aID;
	int HP_MAX;
	int HP;
	static int KILLNUM;

	//method
	OurActor();
	virtual void damaged( int attack_pt, ACTORid attacker, float angle ) = 0;
	
	//action center
	float current_frame;
	OurAction* current_OurAction;
	OurAction* ourIdleAction;
	OurAction* ourCombatIdleAction;
	OurAction* ourRunAction;

	void ourPlayAction();
	bool sendAction(OurAction*);
	OurAction* getCurrentAction();
	virtual void actionChangeSignal( OurAction *last_action, OurAction *current_action ) = 0;
	//attack key
	OurFrame* getKeyFrame();
	float getCurrentFrame();
	//fx & audio
	bool playActionAudio();
	bool playActionFx();
};
#endif