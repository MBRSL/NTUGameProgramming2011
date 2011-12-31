#include"Donzo.h"
Donzo::Donzo( WORLDid gID, SCENEid sID )
{
	FnWorld gw;
	FnScene scene;

	HP_MAX = 900;
	HP = HP_MAX;

	pos_begin[0]=3469.0;
	pos_begin[1]=-3208.0;
	pos_begin[2]=1000.0f;

	this->gID = gID;
	this->sID = sID;

	gw.Object(gID);
	scene.Object(sID);

	gw.SetObjectPath("Data\\NTU4\\Characters");
	gw.SetTexturePath("Data\\NTU4\\Characters");
	gw.SetCharacterPath("Data\\NTU4\\Characters");
	gw.SetShaderPath( "Data\\NTU4\\Shaders" );

	aID = scene.LoadActor("Donzo");
	actor.Object(aID);


	//-------action---------
	//IDLE
	ourIdleAction = new OurAction();
	ourIdleAction->actID = actor.GetBodyAction(NULL, "CombatIdle");
	ourIdleAction->frames_num = 0;
	ourIdleAction->play_speed = 1;
	ourIdleAction->priority = 0;
	ourIdleAction->type.value = DonzoAction::ACTION_IDLE();

	current_OurAction = ourIdleAction;
	actor.MakeCurrentAction(0, NULL, ourIdleAction->actID);

	ourCombatIdleAction = ourIdleAction;
	
	//Run
	ourRunAction = new OurAction();
	ourRunAction->actID = actor.GetBodyAction(NULL, "Run");
	ourRunAction->frames_num = 0;
	ourRunAction->play_speed = 1;
	ourRunAction->priority = 0;
	ourRunAction->type.value = Action_type::ACTION_WALK();

	//DamageL
	ourDamageLAction = new OurAction();
	ourDamageLAction->actID = actor.GetBodyAction(NULL, "DamageL");
	ourDamageLAction->frames_num = 0;
	ourDamageLAction->play_speed = 1;
	ourDamageLAction->priority = 100;
	ourDamageLAction->type.value = DonzoAction::ACTION_DAMAGED();
	//fx
	ourDamageLAction->numOfFxFrames = 1;
	ourDamageLAction->fxFrames = new OurFxFrame*[1];
	ourDamageLAction->fxFrames[0] = new OurFxFrame;
	ourDamageLAction->fxFrames[0]->frameNO = 1;
	ourDamageLAction->fxFrames[0]->fxName = AllFx::SmallHurt01;

	//DamageH
	ourDamageHAction = new OurAction();
	ourDamageHAction->actID = actor.GetBodyAction(NULL, "DamageH");
	ourDamageHAction->frames_num = 0;
	ourDamageHAction->play_speed = 1;
	ourDamageHAction->priority = 100;
	ourDamageHAction->type.value = DonzoAction::ACTION_DAMAGED();
	//fx
	ourDamageHAction->numOfFxFrames = 1;
	ourDamageHAction->fxFrames = new OurFxFrame*[1];
	ourDamageHAction->fxFrames[0] = new OurFxFrame;
	ourDamageHAction->fxFrames[0]->frameNO = 1;
	ourDamageHAction->fxFrames[0]->fxName = AllFx::BigHurt01;

	//Die
	ourDieAction = new OurAction();
	ourDieAction->actID = actor.GetBodyAction(NULL, "Die");
	ourDieAction->frames_num = 0;
	ourDieAction->play_speed = 1;
	ourDieAction->priority = 1000;
	ourDieAction->type.value = DonzoAction::ACTION_DIE();
	//fx
	ourDieAction->numOfFxFrames = 1;
	ourDieAction->fxFrames = new OurFxFrame*[1];
	ourDieAction->fxFrames[0] = new OurFxFrame;
	ourDieAction->fxFrames[0]->frameNO = 1;
	ourDieAction->fxFrames[0]->fxName = AllFx::blood2;

	//blood
	{
		FnObject blood;
		float pos[3], size[2], color[3];
		blood_length = 50;
		blood_width = 2;

		bloodID = scene.CreateObject(ROOT);
		blood.Object(bloodID);
		
		pos[0] = 0.0f;
		pos[1] = 0.0f;
		pos[2] = 100.0f;
		size[0] = blood_length;
		size[1] = blood_width;
		color[0] = 1.0f; color[1] = 0.8; color[2] = 0.2f;

		blood.Billboard(pos, size, NULL, 0, color);
		blood.SetParent(actor.GetBaseObject());
	}
	this->blood.Object(bloodID,0);
}

void Donzo::AI(ACTORid enemy, EnemyTeam **team,  int teamCount)
{
	if(HP > 0)
	{
		detectEnemy(enemy);
		walkingAgent(enemy, team, teamCount);
	}
}
void Donzo::attackAgent(ACTORid enemyID)
{
}
void Donzo::damaged( int attack_pt, ACTORid attacker, float angle )
{
	HP -= attack_pt;
	bloodAdjust();
	if( HP < 0 )
		sendAction(ourDieAction);
	else{
		if( angle < 180 )
			sendAction(ourDamageHAction);
		else
			sendAction(ourDamageLAction);
	}
}