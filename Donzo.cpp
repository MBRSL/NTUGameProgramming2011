#include "Donzo.h"
#include "function.h"
const float Donzo::ATTACK_RATE = 0.50f;
Donzo::Donzo( WORLDid gID, SCENEid sID )
{
	FnWorld gw;
	FnScene scene;

	HP_MAX = 1000;
	HP = HP_MAX;
	winFlag = 0;
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

	//arrow
	FnObject arrow;
	arrow.Object(arrowID);
	arrow.Load("arrowRed");

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

	//Attack
	ourAttack1Action = new OurAction();
	ourAttack1Action->actID = actor.GetBodyAction(NULL, "AttackL1");
	ourAttack1Action->isAttack = true;
	ourAttack1Action->frames_num = 0;
	ourAttack1Action->play_speed = 1;
	ourAttack1Action->priority = 5;
	ourAttack1Action->type.value = Action_type::ACTION_ATTACK();
		//key
		ourAttack1Action->numOfKeyFrames = 1;
		ourAttack1Action->keyFrames = new OurFrame*[1];
		ourAttack1Action->keyFrames[0] = new OurFrame;
		ourAttack1Action->keyFrames[0]->frameNO = 10;
		ourAttack1Action->keyFrames[0]->start_angle = 320;
		ourAttack1Action->keyFrames[0]->plus_angle = 80;
		ourAttack1Action->keyFrames[0]->valid_dis = 200;
		ourAttack1Action->keyFrames[0]->damage_pt = 100;
		//sound
		ourAttack1Action->numOfAudioFrames = 2;
		ourAttack1Action->audioFrames = new OurAudioFrame*[2];
		ourAttack1Action->audioFrames[0] = new OurAudioFrame;
		ourAttack1Action->audioFrames[0]->frameNO = 7;
		ourAttack1Action->audioFrames[0]->audioID = AllAudio::donzo_attack_light;
		ourAttack1Action->audioFrames[1] = new OurAudioFrame;
		ourAttack1Action->audioFrames[1]->frameNO = 8;
		ourAttack1Action->audioFrames[1]->audioID = AllAudio::Thunder01;
		//fx
		ourAttack1Action->numOfFxFrames = 1;
		ourAttack1Action->fxFrames = new OurFxFrame*[1];
		ourAttack1Action->fxFrames[0] = new OurFxFrame;
		ourAttack1Action->fxFrames[0]->frameNO = 1;
		ourAttack1Action->fxFrames[0]->fxName = AllFx::DonzoNormal1;

	ourHeavyAttack1Action = new OurAction();
	ourHeavyAttack1Action->actID = actor.GetBodyAction(NULL, "AttackH");
	ourHeavyAttack1Action->isAttack = true;
	ourHeavyAttack1Action->frames_num = 0;
	ourHeavyAttack1Action->play_speed = 1;
	ourHeavyAttack1Action->priority = ourAttack1Action->priority + 10;
	ourHeavyAttack1Action->type.value = Action_type::ACTION_ATTACK();
		//key
		ourHeavyAttack1Action->numOfKeyFrames = 3;
		ourHeavyAttack1Action->keyFrames = new OurFrame*[3];
		ourHeavyAttack1Action->keyFrames[0] = new OurFrame;
		ourHeavyAttack1Action->keyFrames[0]->frameNO = 23;
		ourHeavyAttack1Action->keyFrames[0]->start_angle = 270;
		ourHeavyAttack1Action->keyFrames[0]->plus_angle = 100;
		ourHeavyAttack1Action->keyFrames[0]->valid_dis = 200;
		ourHeavyAttack1Action->keyFrames[0]->damage_pt = 40;
		ourHeavyAttack1Action->keyFrames[1] = new OurFrame;
		ourHeavyAttack1Action->keyFrames[1]->frameNO = 42;
		ourHeavyAttack1Action->keyFrames[1]->start_angle = 270;
		ourHeavyAttack1Action->keyFrames[1]->plus_angle = 180;
		ourHeavyAttack1Action->keyFrames[1]->valid_dis = 200;
		ourHeavyAttack1Action->keyFrames[1]->damage_pt = 50;
		ourHeavyAttack1Action->keyFrames[2] = new OurFrame;
		ourHeavyAttack1Action->keyFrames[2]->frameNO = 70;
		ourHeavyAttack1Action->keyFrames[2]->start_angle = 0;
		ourHeavyAttack1Action->keyFrames[2]->plus_angle = 360;
		ourHeavyAttack1Action->keyFrames[2]->valid_dis = 200;
		ourHeavyAttack1Action->keyFrames[2]->damage_pt = 80;
		//sound
		ourHeavyAttack1Action->numOfAudioFrames = 3;
		ourHeavyAttack1Action->audioFrames = new OurAudioFrame*[3];
		ourHeavyAttack1Action->audioFrames[0] = new OurAudioFrame;
		ourHeavyAttack1Action->audioFrames[0]->frameNO = 23;
		ourHeavyAttack1Action->audioFrames[0]->audioID = AllAudio::donzo_attack_medium;
		ourHeavyAttack1Action->audioFrames[1] = new OurAudioFrame;
		ourHeavyAttack1Action->audioFrames[1]->frameNO = 42;
		ourHeavyAttack1Action->audioFrames[1]->audioID = AllAudio::donzo_attack_heavy1;
		ourHeavyAttack1Action->audioFrames[2] = new OurAudioFrame;
		ourHeavyAttack1Action->audioFrames[2]->frameNO = 70;
		ourHeavyAttack1Action->audioFrames[2]->audioID = AllAudio::donzo_attack_heavy1;
		//fx
		ourHeavyAttack1Action->numOfFxFrames = 1;
		ourHeavyAttack1Action->fxFrames = new OurFxFrame*[1];
		ourHeavyAttack1Action->fxFrames[0] = new OurFxFrame;
		ourHeavyAttack1Action->fxFrames[0]->frameNO = 1;
		ourHeavyAttack1Action->fxFrames[0]->fxName = AllFx::DonzoAttackH;



	//ourHeavyAttack2Action
	ourHeavyAttack2Action = new OurAction();
	ourHeavyAttack2Action->actID = actor.GetBodyAction(NULL, "HeavyAttack");
	ourHeavyAttack2Action->isAttack = true;
	ourHeavyAttack2Action->frames_num = 0;
	ourHeavyAttack2Action->play_speed = 1;
	ourHeavyAttack2Action->priority = ourAttack1Action->priority + 10;
	ourHeavyAttack2Action->type.value = Action_type::ACTION_ATTACK();
		//key
		ourHeavyAttack2Action->numOfKeyFrames = 2;
		ourHeavyAttack2Action->keyFrames = new OurFrame*[2];
		ourHeavyAttack2Action->keyFrames[0] = new OurFrame;
		ourHeavyAttack2Action->keyFrames[0]->frameNO = 31;
		ourHeavyAttack2Action->keyFrames[0]->start_angle = 0;
		ourHeavyAttack2Action->keyFrames[0]->plus_angle = 270;
		ourHeavyAttack2Action->keyFrames[0]->valid_dis = 190;
		ourHeavyAttack2Action->keyFrames[0]->damage_pt = 70;
		ourHeavyAttack2Action->keyFrames[1] = new OurFrame;
		ourHeavyAttack2Action->keyFrames[1]->frameNO = 41;
		ourHeavyAttack2Action->keyFrames[1]->start_angle = 270;
		ourHeavyAttack2Action->keyFrames[1]->plus_angle = 180;
		ourHeavyAttack2Action->keyFrames[1]->valid_dis = 200;
		ourHeavyAttack2Action->keyFrames[1]->damage_pt = 80;
		//sound
		ourHeavyAttack2Action->numOfAudioFrames = 4;
		ourHeavyAttack2Action->audioFrames = new OurAudioFrame*[4];
		ourHeavyAttack2Action->audioFrames[0] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[0]->frameNO = 28;
		ourHeavyAttack2Action->audioFrames[0]->audioID = AllAudio::donzo_attack_medium;
		ourHeavyAttack2Action->audioFrames[1] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[1]->frameNO = 39;
		ourHeavyAttack2Action->audioFrames[1]->audioID = AllAudio::donzo_attack_heavy2;
		ourHeavyAttack2Action->audioFrames[2] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[2]->frameNO = 0;
		ourHeavyAttack2Action->audioFrames[2]->audioID = AllAudio::donzo_mousou2;
		ourHeavyAttack2Action->audioFrames[3] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[3]->frameNO = 3;
		ourHeavyAttack2Action->audioFrames[3]->audioID = AllAudio::Explosion03;
		//fx
		ourHeavyAttack2Action->numOfFxFrames = 1;
		ourHeavyAttack2Action->fxFrames = new OurFxFrame*[1];
		ourHeavyAttack2Action->fxFrames[0] = new OurFxFrame;
		ourHeavyAttack2Action->fxFrames[0]->frameNO = 1;
		ourHeavyAttack2Action->fxFrames[0]->fxName = AllFx::DonzoHeavy3;

	//DamageL
	ourDamageLAction = new OurAction();
	ourDamageLAction->actID = actor.GetBodyAction(NULL, "DamageL");
	ourDamageLAction->frames_num = 0;
	ourDamageLAction->play_speed = 1.0;
	ourDamageLAction->priority = 100;
	ourDamageLAction->type.value = DonzoAction::ACTION_DAMAGED();
		//fx
		ourDamageLAction->numOfFxFrames = 1;
		ourDamageLAction->fxFrames = new OurFxFrame*[1];
		ourDamageLAction->fxFrames[0] = new OurFxFrame;
		ourDamageLAction->fxFrames[0]->frameNO = 1;
		ourDamageLAction->fxFrames[0]->fxName = AllFx::BigHurt01;
		//sound
		ourDamageLAction->numOfAudioFrames = 2;
		ourDamageLAction->audioFrames = new OurAudioFrame*[2];
		ourDamageLAction->audioFrames[0] = new OurAudioFrame;
		ourDamageLAction->audioFrames[0]->frameNO = 0;
		ourDamageLAction->audioFrames[0]->audioID = AllAudio::donzo_damaged_light;
		ourDamageLAction->audioFrames[1] = new OurAudioFrame;
		ourDamageLAction->audioFrames[1]->frameNO = 1;
		ourDamageLAction->audioFrames[1]->audioID = AllAudio::Attack06;


	//DamageH
	ourDamageHAction = new OurAction();
	ourDamageHAction->actID = actor.GetBodyAction(NULL, "DamageH");
	ourDamageHAction->frames_num = 0;
	ourDamageHAction->play_speed = 1.0;
	ourDamageHAction->priority = 100;
	ourDamageHAction->type.value = DonzoAction::ACTION_DAMAGED();
		//fx
		ourDamageHAction->numOfFxFrames = 1;
		ourDamageHAction->fxFrames = new OurFxFrame*[1];
		ourDamageHAction->fxFrames[0] = new OurFxFrame;
		ourDamageHAction->fxFrames[0]->frameNO = 1;
		ourDamageHAction->fxFrames[0]->fxName = AllFx::BigHurt02;
		//ourDamageHAction->fxFrames[0]->fxName = AllFx::DonzoDamageRight;
		//sound
		ourDamageHAction->numOfAudioFrames = 2;
		ourDamageHAction->audioFrames = new OurAudioFrame*[2];
		ourDamageHAction->audioFrames[0] = new OurAudioFrame;
		ourDamageHAction->audioFrames[0]->frameNO = 0;
		ourDamageHAction->audioFrames[0]->audioID = AllAudio::donzo_damaged_heavy;
		ourDamageHAction->audioFrames[1] = new OurAudioFrame;
		ourDamageHAction->audioFrames[1]->frameNO = 1;
		ourDamageHAction->audioFrames[1]->audioID = AllAudio::Attack12;

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
		ourDieAction->fxFrames[0]->fxName = AllFx::smoke;
		//sound
		ourDieAction->numOfAudioFrames = 4;
		ourDieAction->audioFrames = new OurAudioFrame*[3];
		ourDieAction->audioFrames[0] = new OurAudioFrame;
		ourDieAction->audioFrames[0]->frameNO = 20;
		ourDieAction->audioFrames[0]->audioID = AllAudio::donzo_damaged_miserable;
		ourDieAction->audioFrames[1] = new OurAudioFrame;
		ourDieAction->audioFrames[1]->frameNO = 1;
		ourDieAction->audioFrames[1]->audioID = AllAudio::Attack10;
		ourDieAction->audioFrames[2] = new OurAudioFrame;
		ourDieAction->audioFrames[2]->frameNO = 100;
		ourDieAction->audioFrames[2]->audioID = AllAudio::donzo_damaged_miserable;
		ourDieAction->audioFrames[3] = new OurAudioFrame;
		ourDieAction->audioFrames[3]->frameNO = 160;
		ourDieAction->audioFrames[3]->audioID = AllAudio::Attack16;
	
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
		if(!attackAgent(enemy))
			walkingAgent(enemy, team, teamCount);
	}
}
bool Donzo::attackAgent(ACTORid enemyID)
{
	if(twoActorDis(enemyID, aID) < COMBAT_DISTANCE)
	{
		if(rand()%10000 < Donzo::ATTACK_RATE*10000/30)
		{
			int r = rand()%100;
			if(r < 33)
				sendAction(this->ourAttack1Action);
			else if(r < 66)
				sendAction(this->ourHeavyAttack1Action);
			else
				sendAction(this->ourHeavyAttack2Action);

			return true;
		}
		else
			return false;
	}
	else
		return false;
}
void Donzo::damaged( int attack_pt, ACTORid attacker, float angle )
{
	HP -= attack_pt;
	bloodAdjust();
	if( HP < 0 && current_OurAction->type!=Action_type::ACTION_DIE() )
	{
		HP = 0;
		sendAction(ourDieAction);
		KILLNUM++;
		AllMusic::play( AllMusic::win, ONCE );
		winFlag = 1;
	}
	else{
		if( angle < 180 )
			sendAction(ourDamageHAction);
		else
			sendAction(ourDamageLAction);
	}
}