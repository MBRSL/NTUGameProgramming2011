#ifndef _OURACTOR_H_
#define _OURACTOR_H_
#include "TheFlyWin32.h"
#include "OurAction.h"
class OurActor{
public:
	//var
	FnActor actor;
	ACTORid aID;
	float current_frame;
	OurAction* current_OurAction;
	OurAction* ourIdleAction;

	//method
	OurActor();

	virtual void damaged( int attack_pt, ACTORid attacker, float angle ) = 0;
	void ourPlayAction();
	bool sendAction(OurAction*);
	OurAction* getCurrentAction();
	OurFrame* getKeyFrame();
	float getCurrentFrame();
};
#endif