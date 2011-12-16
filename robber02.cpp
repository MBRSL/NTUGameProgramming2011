#include "robber02.h"
#include "function.h"
#include "OurActor.h"
#include "OurAction.h" 

Robber02::Robber02( WORLDid gID, SCENEid sID )
{
	FnWorld gw;
	FnScene scene;

	pos_begin[0]=3550.0;
	pos_begin[1]=-3216.0;
	pos_begin[2]=1000.0f;
	this->gID = gID;
	this->sID = sID;

	gw.Object(gID);
	scene.Object(sID);

	gw.SetObjectPath("Data\\NTU4\\Characters");
	gw.SetTexturePath("Data\\NTU4\\Characters");
	gw.SetCharacterPath("Data\\NTU4\\Characters");
	gw.SetShaderPath( "Data\\NTU4\\Shaders" );

	aID = scene.LoadActor("Robber02");
	actor.Object(aID);

	//-------action---------
	//IDLE
	ourIdleAction = new OurAction();
	ourIdleAction->actID = actor.GetBodyAction(NULL, "CombatIdle");
	ourIdleAction->frames_num = 0;
	ourIdleAction->play_speed = 1;
	ourIdleAction->priority = 0;
	ourIdleAction->type.value = Action_type::ACTION_IDLE();

	current_OurAction = ourIdleAction;
	actor.MakeCurrentAction(0, NULL, ourIdleAction->actID);
	//DamageL
	ourDamageLAction = new OurAction();
	ourDamageLAction->actID = actor.GetBodyAction(NULL, "Damage1");
	ourDamageLAction->frames_num = 0;
	ourDamageLAction->play_speed = 1;
	ourDamageLAction->priority = 100;
	ourDamageLAction->type.value = Action_type::ACTION_DAMAGED();


}

void Robber02::AI()
{

}

void Robber02::damaged( int attack_pt, ACTORid attacker )
{
	sendAction(ourDamageLAction);
}
