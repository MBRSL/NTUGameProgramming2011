#include "robber02.h"
#include "function.h"
#include "OurActor.h"
#include "OurAction.h"

const float Robber02::ATTACK_RATE = 0.10f;

Robber02::Robber02( WORLDid gID, SCENEid sID )
{
	FnWorld gw;
	FnScene scene;

	HP_MAX = 400;
	HP = HP_MAX;

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

	//arrow
	FnObject arrow;
	arrow.Object(arrowID);
	arrow.Load("arrowYellow");


	

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

	ourCombatIdleAction = ourIdleAction;

	//Run
	ourRunAction = new OurAction();
	ourRunAction->actID = actor.GetBodyAction(NULL, "Run");
	ourRunAction->frames_num = 0;
	ourRunAction->play_speed = 1;
	ourRunAction->priority = 0;
	ourRunAction->type.value = Action_type::ACTION_WALK();
	//sound
		ourRunAction->numOfAudioFrames = 1;
		ourRunAction->audioFrames = new OurAudioFrame*[1];
		ourRunAction->audioFrames[0] = new OurAudioFrame;
		ourRunAction->audioFrames[0]->frameNO = 0;
		ourRunAction->audioFrames[0]->audioID = AllAudio::s01_pose05;
	//Attack
	ourAttack1Action = new OurAction();
	ourAttack1Action->actID = actor.GetBodyAction(NULL, "NormalAttack1");
	ourAttack1Action->isAttack = true;
	ourAttack1Action->frames_num = 0;
	ourAttack1Action->play_speed = 1;
	ourAttack1Action->priority = 5;
	ourAttack1Action->type.value = Action_type::ACTION_ATTACK();
	ourAttack1Action->numOfKeyFrames = 1;
	ourAttack1Action->keyFrames = new OurFrame*[1];
	ourAttack1Action->keyFrames[0] = new OurFrame;
	ourAttack1Action->keyFrames[0]->frameNO = 17;
	ourAttack1Action->keyFrames[0]->start_angle = 340;
	ourAttack1Action->keyFrames[0]->plus_angle = 40;
	ourAttack1Action->keyFrames[0]->valid_dis = 170;
	ourAttack1Action->keyFrames[0]->damage_pt = 40;
	//sound
		ourAttack1Action->numOfAudioFrames = 1;
		ourAttack1Action->audioFrames = new OurAudioFrame*[2];
		ourAttack1Action->audioFrames[0] = new OurAudioFrame;
		ourAttack1Action->audioFrames[0]->frameNO = 7;
		ourAttack1Action->audioFrames[0]->audioID = AllAudio::Swing02;

	ourAttack2Action = new OurAction();
	ourAttack2Action->actID = actor.GetBodyAction(NULL, "NormalAttack2");
	ourAttack2Action->isAttack = true;
	ourAttack2Action->frames_num = 0;
	ourAttack2Action->play_speed = 1;
	ourAttack2Action->priority = 6;
	ourAttack2Action->type.value = Action_type::ACTION_ATTACK();
	ourAttack2Action->numOfKeyFrames = 1;
	ourAttack2Action->keyFrames = new OurFrame*[1];
	ourAttack2Action->keyFrames[0] = new OurFrame;
	ourAttack2Action->keyFrames[0]->frameNO = 8;
	ourAttack2Action->keyFrames[0]->start_angle = 290;
	ourAttack2Action->keyFrames[0]->plus_angle = 250;
	ourAttack2Action->keyFrames[0]->valid_dis = 160;
	ourAttack2Action->keyFrames[0]->damage_pt = 30;
	//sound
		ourAttack2Action->numOfAudioFrames = 1;
		ourAttack2Action->audioFrames = new OurAudioFrame*[2];
		ourAttack2Action->audioFrames[0] = new OurAudioFrame;
		ourAttack2Action->audioFrames[0]->frameNO = 20;
		ourAttack2Action->audioFrames[0]->audioID = AllAudio::Swing03;


	ourHeavyAttackAction = new OurAction();
	ourHeavyAttackAction->actID = actor.GetBodyAction(NULL, "HeavyAttack1");
	ourHeavyAttackAction->isAttack = true;
	ourHeavyAttackAction->frames_num = 0;
	ourHeavyAttackAction->play_speed = 1;
	ourHeavyAttackAction->priority = ourAttack1Action->priority + 10;
	ourHeavyAttackAction->type.value = Action_type::ACTION_ATTACK();
	ourHeavyAttackAction->numOfKeyFrames = 1;
	ourHeavyAttackAction->keyFrames = new OurFrame*[1];
	ourHeavyAttackAction->keyFrames[0] = new OurFrame;
	ourHeavyAttackAction->keyFrames[0]->frameNO = 16;
	ourHeavyAttackAction->keyFrames[0]->start_angle = 330;
	ourHeavyAttackAction->keyFrames[0]->plus_angle = 120;
	ourHeavyAttackAction->keyFrames[0]->valid_dis = 130;
	ourHeavyAttackAction->keyFrames[0]->damage_pt = 60;
	//sound
		ourHeavyAttackAction->numOfAudioFrames = 2;
		ourHeavyAttackAction->audioFrames = new OurAudioFrame*[2];
		ourHeavyAttackAction->audioFrames[0] = new OurAudioFrame;
		ourHeavyAttackAction->audioFrames[0]->frameNO = 0;
		ourHeavyAttackAction->audioFrames[0]->audioID = AllAudio::s02_pose07;
		ourHeavyAttackAction->audioFrames[1] = new OurAudioFrame;
		ourHeavyAttackAction->audioFrames[1]->frameNO = 15;
		ourHeavyAttackAction->audioFrames[1]->audioID = AllAudio::Swing04;


	
	//Damage1
	ourDamage1Action = new OurAction();
	ourDamage1Action->actID = actor.GetBodyAction(NULL, "Damage1");
	ourDamage1Action->frames_num = 0;
	ourDamage1Action->play_speed = 1.0;
	ourDamage1Action->priority = 100;
	ourDamage1Action->type.value = Action_type::ACTION_DAMAGED();
	ourDamage1Action->numOfFxFrames = 1;
	ourDamage1Action->fxFrames = new OurFxFrame*[1];
	ourDamage1Action->fxFrames[0] = new OurFxFrame;
	ourDamage1Action->fxFrames[0]->frameNO = 1;
	ourDamage1Action->fxFrames[0]->fxName = AllFx::SmallHurt01;
		ourDamage1Action->numOfAudioFrames = 1;
		ourDamage1Action->audioFrames = new OurAudioFrame*[2];
		ourDamage1Action->audioFrames[0] = new OurAudioFrame;
		ourDamage1Action->audioFrames[0]->frameNO = 1;
		ourDamage1Action->audioFrames[0]->audioID = AllAudio::Attack07;
	
	//Damage2
	ourDamage2Action = new OurAction();
	ourDamage2Action->actID = actor.GetBodyAction(NULL, "Damage2");
	ourDamage2Action->frames_num = 0;
	ourDamage2Action->play_speed = 1.0;
	ourDamage2Action->priority = 100;
	ourDamage2Action->type.value = Action_type::ACTION_DAMAGED();
	ourDamage2Action->numOfFxFrames = 1;
	ourDamage2Action->fxFrames = new OurFxFrame*[1];
	ourDamage2Action->fxFrames[0] = new OurFxFrame;
	ourDamage2Action->fxFrames[0]->frameNO = 1;
	ourDamage2Action->fxFrames[0]->fxName = AllFx::BigHurt01;
	ourDamage2Action->numOfAudioFrames =2;
	ourDamage2Action->audioFrames = new OurAudioFrame*[2];
		ourDamage2Action->audioFrames[0] = new OurAudioFrame;
		ourDamage2Action->audioFrames[0]->frameNO = 0;
		ourDamage2Action->audioFrames[0]->audioID = AllAudio::s03_pose18;
		ourDamage2Action->audioFrames[1] = new OurAudioFrame;
		ourDamage2Action->audioFrames[1]->frameNO = 0;
		ourDamage2Action->audioFrames[1]->audioID = AllAudio::Attack06;
	

	//Die
	ourDieAction = new OurAction();
	ourDieAction->actID = actor.GetBodyAction(NULL, "Dead");
	ourDieAction->frames_num = 0;
	ourDieAction->play_speed = 1;
	ourDieAction->priority = 100;
	ourDieAction->type.value = Action_type::ACTION_DIE();
	ourDieAction->numOfAudioFrames = 3;
	ourDieAction->audioFrames = new OurAudioFrame*[3];
	ourDieAction->audioFrames[0] = new OurAudioFrame;
	ourDieAction->audioFrames[0]->frameNO = 1;
	ourDieAction->audioFrames[0]->audioID = AllAudio::s03_pose25;
	ourDieAction->audioFrames[1] = new OurAudioFrame;
	ourDieAction->audioFrames[1]->frameNO = 0;
	ourDieAction->audioFrames[1]->audioID = AllAudio::Attack10;
	ourDieAction->audioFrames[2] = new OurAudioFrame;
	ourDieAction->audioFrames[2]->frameNO = 28;
	ourDieAction->audioFrames[2]->audioID = AllAudio::Attack16;

	//blood
	{
		FnObject blood;
		float pos[3], size[2], color[3];
		blood_length = 15;
		blood_width = 1.5;

		bloodID = scene.CreateObject(ROOT);
		blood.Object(bloodID);
		
		pos[0] = 0.0f;
		pos[1] = 0.0f;
		pos[2] = 70.0f;
		size[0] = blood_length;
		size[1] = blood_width;
		color[0] = 1.0f; color[1] = color[2] = 0.0f;

		blood.Billboard(pos, size, NULL, 0, color);
		blood.SetParent(actor.GetBaseObject());
	}
	this->blood.Object(bloodID,0);
}

void Robber02::AI(ACTORid enemy, EnemyTeam **team,  int teamCount)
{
	if(HP > 0)
	{
		detectEnemy(enemy);
		if(!attackAgent(enemy))
			walkingAgent(enemy, team, teamCount);
	}
}
bool Robber02::attackAgent(ACTORid enemyID)
{
	if(twoActorDis(enemyID, aID) < COMBAT_DISTANCE)
	{
		if(rand()%10000 < Robber02::ATTACK_RATE*10000/30)
		{
			int r = rand()%100;
			if(r < 33)
				sendAction(this->ourAttack1Action);
			else if(r < 66)
				sendAction(this->ourAttack2Action);
			else
				sendAction(this->ourHeavyAttackAction);

			return true;
		}
		else
			return false;
	}
	else
		return false;
}
void Robber02::damaged( int attack_pt, ACTORid attacker, float angle )
{
	HP -= attack_pt;

	bloodAdjust();

	if( HP <= 0 )
	{
		sendAction(ourDieAction);
		KILLNUM++;
	}
	else
	{
		if( angle < 180 )
			sendAction(ourDamage1Action);
		else
			sendAction(ourDamage2Action);
	}
}
