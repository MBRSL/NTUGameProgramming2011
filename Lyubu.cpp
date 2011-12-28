#include "Lyubu.h"
#include "function.h"
#include "AllData.h"

extern float debug[4];
Lyubu::Lyubu( WORLDid gID, SCENEid sID )
{
	FnWorld gw;
	FnScene scene;

	pos_begin[0]=3569.0;
	pos_begin[1]=-3208.0;
	pos_begin[2]=1000.0f;
	MOVE_SPEED=10.0;
	MOVE_ANGLE=5.0;
	this->gID = gID;
	this->sID = sID;

	gw.Object(gID);
	scene.Object(sID);

	gw.SetObjectPath("Data\\NTU4\\Characters");
	gw.SetTexturePath("Data\\NTU4\\Characters");
	gw.SetCharacterPath("Data\\NTU4\\Characters");
	gw.SetShaderPath( "Data\\NTU4\\Shaders" );

	aID = scene.LoadActor("Lyubu");
	actor.Object(aID);

	//�f���S���ʧ@
	FnActor actor;
	actor.Object( aID );
	//IDLE
	ourIdleAction = new OurAction();
	ourIdleAction->actID = actor.GetBodyAction(NULL, "Idle");
	ourIdleAction->frames_num = 0;
	ourIdleAction->play_speed = 1;
	ourIdleAction->priority = 0;
	ourIdleAction->type.value = LyubuAction::ACTION_IDLE();

	current_OurAction = ourIdleAction;
	//RUN
	/*
	ourRunAction = new OurAction::Builder()	->actID(actor.GetBodyAction(NULL, "Run"))
											->defense_pt(0)
											->frames_num(0)
											->play_speed(1)
											->priority(0)
											->type(LyubuAction::ACTION_WALK())
											->build();
	*/
	ourRunAction = new OurAction();
	ourRunAction->actID = actor.GetBodyAction(NULL, "Run");
	ourRunAction->frames_num = 0;
	ourRunAction->play_speed = 1;
	ourRunAction->priority = 0;
	ourRunAction->type.value = LyubuAction::ACTION_WALK();
	//ATTACKS
	ourAttack1Action = new OurAction();
	ourAttack1Action->actID = actor.GetBodyAction(NULL, "NormalAttack1");
	ourAttack1Action->isAttack = true;
	ourAttack1Action->frames_num = 0;
	ourAttack1Action->play_speed = 0.8;
	ourAttack1Action->priority = 5;
	ourAttack1Action->type.value = LyubuAction::ACTION_NORMAL_ATTACK1();
	ourAttack1Action->combo_able_frame_start = 10;
	ourAttack1Action->combo_able_frame_end = 20;
	ourAttack1Action->numOfKeyFrames = 1;
	ourAttack1Action->keyFrames = new OurFrame*[1];
	ourAttack1Action->keyFrames[0] = new OurFrame;
	ourAttack1Action->keyFrames[0]->frameNO = 7;
	ourAttack1Action->keyFrames[0]->start_angle = 340;
	ourAttack1Action->keyFrames[0]->plus_angle = 40;
	ourAttack1Action->keyFrames[0]->valid_dis = 160;
	ourAttack1Action->keyFrames[0]->damage_pt = 50;
	//sound
	ourAttack1Action->numOfAudioFrames = 2;
	ourAttack1Action->audioFrames = new OurAudioFrame*[2];
	ourAttack1Action->audioFrames[0] = new OurAudioFrame;
	ourAttack1Action->audioFrames[0]->frameNO = 0;
	ourAttack1Action->audioFrames[0]->audioID = AllAudio::s01_pose07;

	ourAttack1Action->audioFrames[1] = new OurAudioFrame;
	ourAttack1Action->audioFrames[1]->frameNO = 15;
	ourAttack1Action->audioFrames[1]->audioID = AllAudio::eat;

	ourAttack2Action = new OurAction();
	ourAttack2Action->actID = actor.GetBodyAction(NULL, "NormalAttack2");
	ourAttack2Action->isAttack = true;
	ourAttack2Action->frames_num = 0;
	ourAttack2Action->play_speed = 0.8;
	ourAttack2Action->priority = 6;
	ourAttack2Action->type.value = LyubuAction::ACTION_NORMAL_ATTACK2();
	ourAttack2Action->combo_able_frame_start = 15;
	ourAttack2Action->combo_able_frame_end = 35;
	ourAttack2Action->numOfKeyFrames = 2;
	ourAttack2Action->keyFrames = new OurFrame*[2];
	ourAttack2Action->keyFrames[0] = new OurFrame;
	ourAttack2Action->keyFrames[0]->frameNO = 22;
	ourAttack2Action->keyFrames[0]->start_angle = 180;
	ourAttack2Action->keyFrames[0]->plus_angle = 180;
	ourAttack2Action->keyFrames[0]->valid_dis = 150;
	ourAttack2Action->keyFrames[0]->damage_pt = 30;
	ourAttack2Action->keyFrames[1] = new OurFrame;
	ourAttack2Action->keyFrames[1]->frameNO = 25;
	ourAttack2Action->keyFrames[1]->start_angle = 0;
	ourAttack2Action->keyFrames[1]->plus_angle = 90;
	ourAttack2Action->keyFrames[1]->valid_dis = 170;
	ourAttack2Action->keyFrames[1]->damage_pt = 30;
	//sound
	ourAttack2Action->numOfAudioFrames = 1;
	ourAttack2Action->audioFrames = new OurAudioFrame*[1];
	ourAttack2Action->audioFrames[0] = new OurAudioFrame;
	ourAttack2Action->audioFrames[0]->frameNO = 5;
	ourAttack2Action->audioFrames[0]->audioID = AllAudio::s02_pose10;

	ourAttack3Action = new OurAction();
	ourAttack3Action->actID = actor.GetBodyAction(NULL, "NormalAttack3");
	ourAttack3Action->isAttack = true;
	ourAttack3Action->frames_num = 0;
	ourAttack3Action->play_speed = 0.8;
	ourAttack3Action->priority = 7;
	ourAttack3Action->type.value = LyubuAction::ACTION_NORMAL_ATTACK3();
	ourAttack3Action->combo_able_frame_start = 25;
	ourAttack3Action->combo_able_frame_end = 45;
	ourAttack3Action->numOfKeyFrames = 1;
	ourAttack3Action->keyFrames = new OurFrame*[1];
	ourAttack3Action->keyFrames[0] = new OurFrame;
	ourAttack3Action->keyFrames[0]->frameNO = 23;
	ourAttack3Action->keyFrames[0]->start_angle = 90;
	ourAttack3Action->keyFrames[0]->plus_angle = 180;
	ourAttack3Action->keyFrames[0]->valid_dis = 80;
	ourAttack3Action->keyFrames[0]->damage_pt = 30;

	ourAttack4Action = new OurAction();
	ourAttack4Action->actID = actor.GetBodyAction(NULL, "NormalAttack4");
	ourAttack4Action->isAttack = true;
	ourAttack4Action->frames_num = 0;
	ourAttack4Action->play_speed = 0.8;
	ourAttack4Action->priority = 8;
	ourAttack4Action->type.value = LyubuAction::ACTION_NORMAL_ATTACK4();
	ourAttack4Action->combo_able_frame_start = 25;
	ourAttack4Action->combo_able_frame_end = 48;
	ourAttack4Action->numOfKeyFrames = 1;
	ourAttack4Action->keyFrames = new OurFrame*[1];
	ourAttack4Action->keyFrames[0] = new OurFrame;
	ourAttack4Action->keyFrames[0]->frameNO = 25;
	ourAttack4Action->keyFrames[0]->start_angle = 340;
	ourAttack4Action->keyFrames[0]->plus_angle = 40;
	ourAttack4Action->keyFrames[0]->valid_dis = 100;
	ourAttack4Action->keyFrames[0]->damage_pt = 50;

	actor.MakeCurrentAction(0, NULL, ourIdleAction->actID);
}
void Lyubu::dealKey()
{
	static bool Zpressed=false;
	if (FyCheckHotKeyStatus(FY_Z) ) {
		if(!Zpressed)
		{
			//��ܬO�����ʧ@�A�B�b���۽d��
			if(current_OurAction
				&&	current_frame > current_OurAction->combo_able_frame_start && current_frame <= current_OurAction->combo_able_frame_end)
			{
				if(	current_OurAction->type == LyubuAction::ACTION_NORMAL_ATTACK1())
					sendAction(ourAttack2Action);
				else if(current_OurAction->type == LyubuAction::ACTION_NORMAL_ATTACK2())
					sendAction(ourAttack3Action);
				else if(current_OurAction->type == LyubuAction::ACTION_NORMAL_ATTACK3())
					sendAction(ourAttack4Action);
			}
			sendAction(ourAttack1Action);
		}
		Zpressed=true;
	}
	else
	{
		Zpressed = false;
	}
}
void Lyubu::Rotate(int degree, float cameraPos[])
{
	float rad = degree*2*PI/360;
	float distanceToOrigin[3];
	float actPos[3];
	actor.GetPosition(actPos);
	distanceToOrigin[0] = cameraPos[0];
	distanceToOrigin[1] = cameraPos[1];
	distanceToOrigin[2] = cameraPos[2];

	float M[12] = {	cos(rad), sin(rad), 0,
					-sin(rad), cos(rad), 0,
					0,	0,	1,
					-distanceToOrigin[0]*cos(rad)+distanceToOrigin[1]*sin(rad)+distanceToOrigin[0],-distanceToOrigin[0]*sin(rad)-distanceToOrigin[1]*cos(rad)+distanceToOrigin[1], 0
	};
	FnObject actObj;
	actObj.Object(actor.GetBaseObject());
	actObj.SetMatrix(M, GLOBAL);
	actor.GetPosition(actPos);
	debug[0] = actPos[0];
	debug[1] = actPos[1];
	debug[2] = actPos[2];
}

void Lyubu::damaged( int attack_pt, ACTORid attacker, float angle )
{

}