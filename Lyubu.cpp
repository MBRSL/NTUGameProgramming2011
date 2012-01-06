#include "Lyubu.h"
#include "function.h"
#include "AllData.h"

Lyubu::Lyubu( WORLDid gID, SCENEid sID )
{
	FnScene scene;

	HP_MAX = 1000;
	HP = HP_MAX;

	pos_begin[0]=3569.0;
	pos_begin[1]=-3208.0;
	pos_begin[2]=1000.0f;
	MOVE_SPEED=10.0;
	MOVE_ANGLE=5.0;
	this->gID = gID;
	this->sID = sID;

	gw.Object(gID);
	scene.Object(sID);

	//2D
	FnSprite sp;
	FnScene scene2D;
	gw.SetTexturePath(AllImg::ImgDirAddr);

	s2D = gw.CreateScene(1);
	scene2D.Object(s2D);
	scene2D.SetSpriteWorldSize(800, 600);
		//face img
	face_img = scene2D.CreateSprite();
	sp.Object(face_img);
	sp.SetRectArea(NULL, 200, 200, NULL, "597_2", 0, TRUE, 0, 0, 0);   // load an image & resize it
	sp.SetRectPosition(10, 10, 0);   // put at (200, 200) position
		//lifebar img
	lifebar_x = 180;
	lifebar_y = 50;
	lifebar_length = 500;
	lifebar_height = 25;

	lifebar_frameID = scene2D.CreateSprite();
	sp.Object(lifebar_frameID);
	sp.SetRectArea(NULL, lifebar_length, lifebar_height, NULL, "lifebar2", 0, TRUE, 13, 0, 0);
	sp.SetRectPosition(lifebar_x, lifebar_y, 0);

	lifebarID = scene2D.CreateSprite();
	sp.Object(lifebarID);
	sp.SetRectArea(NULL, lifebar_length, lifebar_height, NULL, "lifebar1", 0, TRUE, 0, 0, 0);
	sp.SetRectPosition(lifebar_x, lifebar_y, 0);

	lifebar.Object(lifebarID);
		//skill
	skill_length=400;
	skill_height=140;
	skill_x=200;
	skill_y=450;
	skillID = scene2D.CreateSprite();
	sp.Object(skillID);
	//sp.SetRectArea(NULL, skill_length, skill_height, NULL, "skill1", 0, TRUE, 0, 0, 0);
	//sp.SetRectPosition(skill_x, skill_y, 0);
	
	skill.Object(skillID);
	//2D


	gw.SetObjectPath("Data\\NTU4\\Characters");
	gw.SetTexturePath("Data\\NTU4\\Characters");
	gw.SetCharacterPath("Data\\NTU4\\Characters");
	gw.SetShaderPath( "Data\\NTU4\\Shaders" );

	aID = scene.LoadActor("Lyubu");
	actor.Object(aID);

	//呂布特有動作
	FnActor actor;
	actor.Object( aID );
	//IDLE
	ourIdleAction = new OurAction();
	ourIdleAction->actID = actor.GetBodyAction(NULL, "CombatIdle");
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
		//sound
		ourRunAction->numOfAudioFrames = 1;
		ourRunAction->audioFrames = new OurAudioFrame*[1];
		ourRunAction->audioFrames[0] = new OurAudioFrame;
		ourRunAction->audioFrames[0]->frameNO = 0;
		ourRunAction->audioFrames[0]->audioID = AllAudio::s01_pose05;
		//fx
		ourRunAction->numOfFxFrames = 1;
		ourRunAction->fxFrames = new OurFxFrame*[1];
		ourRunAction->fxFrames[0] = new OurFxFrame;
		ourRunAction->fxFrames[0]->frameNO = 1;
		ourRunAction->fxFrames[0]->fxName = AllFx::WeaponSmoke;


	//ATTACKS
	ourAttack1Action = new OurAction();
	ourAttack1Action->actID = actor.GetBodyAction(NULL, "NormalAttack1");
	ourAttack1Action->isAttack = true;
	ourAttack1Action->frames_num = 24;
	ourAttack1Action->play_speed = 1.5;
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
	ourAttack1Action->keyFrames[0]->valid_dis = 260;
	ourAttack1Action->keyFrames[0]->damage_pt = 50;
		//sound
		ourAttack1Action->numOfAudioFrames = 2;
		ourAttack1Action->audioFrames = new OurAudioFrame*[2];
		ourAttack1Action->audioFrames[0] = new OurAudioFrame;
		ourAttack1Action->audioFrames[0]->frameNO = 7;
		ourAttack1Action->audioFrames[0]->audioID = AllAudio::lyubu_attack_light;
		ourAttack1Action->audioFrames[1] = new OurAudioFrame;
		ourAttack1Action->audioFrames[1]->frameNO = 8;
		ourAttack1Action->audioFrames[1]->audioID = AllAudio::weapon_attack;
		//fx
		ourAttack1Action->numOfFxFrames = 1;
		ourAttack1Action->fxFrames = new OurFxFrame*[1];
		ourAttack1Action->fxFrames[0] = new OurFxFrame;
		ourAttack1Action->fxFrames[0]->frameNO = 1;
		ourAttack1Action->fxFrames[0]->fxName = AllFx::WeaponSmoke;

	ourAttack2Action = new OurAction();
	ourAttack2Action->actID = actor.GetBodyAction(NULL, "NormalAttack2");
	ourAttack2Action->isAttack = true;
	ourAttack2Action->frames_num = 47;
	ourAttack2Action->play_speed = 1.2;
	ourAttack2Action->priority = 6;
	ourAttack2Action->type.value = LyubuAction::ACTION_NORMAL_ATTACK2();
	ourAttack2Action->combo_able_frame_start = 25;
	ourAttack2Action->combo_able_frame_end = 40;
		//key
		ourAttack2Action->numOfKeyFrames = 2;
		ourAttack2Action->keyFrames = new OurFrame*[2];
		ourAttack2Action->keyFrames[0] = new OurFrame;
		ourAttack2Action->keyFrames[0]->frameNO = 22;
		ourAttack2Action->keyFrames[0]->start_angle = 135;
		ourAttack2Action->keyFrames[0]->plus_angle = 270;
		ourAttack2Action->keyFrames[0]->valid_dis = 250;
		ourAttack2Action->keyFrames[0]->damage_pt = 40;
		ourAttack2Action->keyFrames[1] = new OurFrame;
		ourAttack2Action->keyFrames[1]->frameNO = 25;
		ourAttack2Action->keyFrames[1]->start_angle = 0;
		ourAttack2Action->keyFrames[1]->plus_angle = 135;
		ourAttack2Action->keyFrames[1]->valid_dis = 270;
		ourAttack2Action->keyFrames[1]->damage_pt = 30;
		//sound
		ourAttack2Action->numOfAudioFrames = 3;
		ourAttack2Action->audioFrames = new OurAudioFrame*[3];
		ourAttack2Action->audioFrames[0] = new OurAudioFrame;
		ourAttack2Action->audioFrames[0]->frameNO = 20;
		ourAttack2Action->audioFrames[0]->audioID = AllAudio::lyubu_attack_heavy2;
		ourAttack2Action->audioFrames[1] = new OurAudioFrame;
		ourAttack2Action->audioFrames[1]->frameNO = 18;
		ourAttack2Action->audioFrames[1]->audioID = AllAudio::weapon_attack;
		ourAttack2Action->audioFrames[2] = new OurAudioFrame;
		ourAttack2Action->audioFrames[2]->frameNO = 5;
		ourAttack2Action->audioFrames[2]->audioID = AllAudio::Thunder01;
		//fx
		ourAttack2Action->numOfFxFrames = 1;
		ourAttack2Action->fxFrames = new OurFxFrame*[1];
		ourAttack2Action->fxFrames[0] = new OurFxFrame;
		ourAttack2Action->fxFrames[0]->frameNO = 1;
		ourAttack2Action->fxFrames[0]->fxName = AllFx::LyubuWeapon1;

	ourAttack3Action = new OurAction();
	ourAttack3Action->actID = actor.GetBodyAction(NULL, "NormalAttack3");
	ourAttack3Action->isAttack = true;
	ourAttack3Action->frames_num = 45;
	ourAttack3Action->play_speed = 1.2;
	ourAttack3Action->priority = 7;
	ourAttack3Action->type.value = LyubuAction::ACTION_NORMAL_ATTACK3();
	ourAttack3Action->combo_able_frame_start = 25;
	ourAttack3Action->combo_able_frame_end = 45;
		//key
		ourAttack3Action->numOfKeyFrames = 1;
		ourAttack3Action->keyFrames = new OurFrame*[1];
		ourAttack3Action->keyFrames[0] = new OurFrame;
		ourAttack3Action->keyFrames[0]->frameNO = 23;
		ourAttack3Action->keyFrames[0]->start_angle = 270;
		ourAttack3Action->keyFrames[0]->plus_angle = 270;
		ourAttack3Action->keyFrames[0]->valid_dis = 250;
		ourAttack3Action->keyFrames[0]->damage_pt = 40;
		//sound
		ourAttack3Action->numOfAudioFrames = 2;
		ourAttack3Action->audioFrames = new OurAudioFrame*[2];
		ourAttack3Action->audioFrames[0] = new OurAudioFrame;
		ourAttack3Action->audioFrames[0]->frameNO = 0;
		ourAttack3Action->audioFrames[0]->audioID = AllAudio::charge_voice1;
		ourAttack3Action->audioFrames[1] = new OurAudioFrame;
		ourAttack3Action->audioFrames[1]->frameNO = 20;
		ourAttack3Action->audioFrames[1]->audioID = AllAudio::weapon_attack;
		//fx
		ourAttack3Action->numOfFxFrames = 1;
		ourAttack3Action->fxFrames = new OurFxFrame*[1];
		ourAttack3Action->fxFrames[0] = new OurFxFrame;
		ourAttack3Action->fxFrames[0]->frameNO = 1;
		ourAttack3Action->fxFrames[0]->fxName = AllFx::WeaponThunder;

	ourAttack4Action = new OurAction();
	ourAttack4Action->actID = actor.GetBodyAction(NULL, "NormalAttack4");
	ourAttack4Action->isAttack = true;
	ourAttack4Action->frames_num = 0;
	ourAttack4Action->play_speed = 1.2;
	ourAttack4Action->priority = 8;
	ourAttack4Action->type.value = LyubuAction::ACTION_NORMAL_ATTACK4();
	ourAttack4Action->combo_able_frame_start = 25;
	ourAttack4Action->combo_able_frame_end = 48;
		//key
		ourAttack4Action->numOfKeyFrames = 1;
		ourAttack4Action->keyFrames = new OurFrame*[1];
		ourAttack4Action->keyFrames[0] = new OurFrame;
		ourAttack4Action->keyFrames[0]->frameNO = 25;
		ourAttack4Action->keyFrames[0]->start_angle = 340;
		ourAttack4Action->keyFrames[0]->plus_angle = 40;
		ourAttack4Action->keyFrames[0]->valid_dis = 200;
		ourAttack4Action->keyFrames[0]->damage_pt = 50;
		//sound
		ourAttack4Action->numOfAudioFrames = 4;
		ourAttack4Action->audioFrames = new OurAudioFrame*[4];
		ourAttack4Action->audioFrames[0] = new OurAudioFrame;
		ourAttack4Action->audioFrames[0]->frameNO = 5;
		ourAttack4Action->audioFrames[0]->audioID = AllAudio::lyubu_attack_heavy3;
		ourAttack4Action->audioFrames[1] = new OurAudioFrame;
		ourAttack4Action->audioFrames[1]->frameNO = 6;
		ourAttack4Action->audioFrames[1]->audioID = AllAudio::weapon_attack;
		ourAttack4Action->audioFrames[2] = new OurAudioFrame;
		ourAttack4Action->audioFrames[2]->frameNO = 20;
		ourAttack4Action->audioFrames[2]->audioID = AllAudio::lyubu_attack_heavy1;
		ourAttack4Action->audioFrames[3] = new OurAudioFrame;
		ourAttack4Action->audioFrames[3]->frameNO = 21;
		ourAttack4Action->audioFrames[3]->audioID = AllAudio::weapon_attack;

	ourHeavyAttack1Action = new OurAction();
	ourHeavyAttack1Action->actID = actor.GetBodyAction(NULL, "HeavyAttack1");
	ourHeavyAttack1Action->isAttack = true;
	ourHeavyAttack1Action->frames_num = 72;
	ourHeavyAttack1Action->play_speed = 1;
	ourHeavyAttack1Action->priority = ourAttack1Action->priority + 10;
	ourHeavyAttack1Action->type.value = LyubuAction::ACTION_HEAVY_ATTACK1();
	ourHeavyAttack1Action->combo_able_frame_start = 40;
	ourHeavyAttack1Action->combo_able_frame_end = 60;
	ourHeavyAttack1Action->numOfKeyFrames = 2;
		//key
		ourHeavyAttack1Action->keyFrames = new OurFrame*[2];
		ourHeavyAttack1Action->keyFrames[0] = new OurFrame;
		ourHeavyAttack1Action->keyFrames[0]->frameNO = 21;
		ourHeavyAttack1Action->keyFrames[0]->start_angle = 0;
		ourHeavyAttack1Action->keyFrames[0]->plus_angle = 100;
		ourHeavyAttack1Action->keyFrames[0]->valid_dis = 200;
		ourHeavyAttack1Action->keyFrames[0]->damage_pt = 70;
		ourHeavyAttack1Action->keyFrames[1] = new OurFrame;
		ourHeavyAttack1Action->keyFrames[1]->frameNO = 40;
		ourHeavyAttack1Action->keyFrames[1]->start_angle = 320;
		ourHeavyAttack1Action->keyFrames[1]->plus_angle = 80;
		ourHeavyAttack1Action->keyFrames[1]->valid_dis = 260;
		ourHeavyAttack1Action->keyFrames[1]->damage_pt = 80;
		//sound
		ourHeavyAttack1Action->numOfAudioFrames = 4;
		ourHeavyAttack1Action->audioFrames = new OurAudioFrame*[4];
		ourHeavyAttack1Action->audioFrames[0] = new OurAudioFrame;
		ourHeavyAttack1Action->audioFrames[0]->frameNO = 0;
		ourHeavyAttack1Action->audioFrames[0]->audioID = AllAudio::lyubu_mousou3;
		ourHeavyAttack1Action->audioFrames[1] = new OurAudioFrame;
		ourHeavyAttack1Action->audioFrames[1]->frameNO = 18;
		ourHeavyAttack1Action->audioFrames[1]->audioID = AllAudio::weapon_attack;
		ourHeavyAttack1Action->audioFrames[2] = new OurAudioFrame;
		ourHeavyAttack1Action->audioFrames[2]->frameNO = 38;
		ourHeavyAttack1Action->audioFrames[2]->audioID = AllAudio::weapon_attack;
		ourHeavyAttack1Action->audioFrames[3] = new OurAudioFrame;
		ourHeavyAttack1Action->audioFrames[3]->frameNO = 10;
		ourHeavyAttack1Action->audioFrames[3]->audioID = AllAudio::Light03;

		//fx
		ourHeavyAttack1Action->numOfFxFrames = 1;
		ourHeavyAttack1Action->fxFrames = new OurFxFrame*[1];
		ourHeavyAttack1Action->fxFrames[0] = new OurFxFrame;
		ourHeavyAttack1Action->fxFrames[0]->frameNO = 1;
		ourHeavyAttack1Action->fxFrames[0]->fxName = AllFx::LyubuWeapon3;
		//img
		ourHeavyAttack1Action->hasImg = true;
		ourHeavyAttack1Action->Img = "skill1";
	
	ourHeavyAttack2Action = new OurAction();
	ourHeavyAttack2Action->actID = actor.GetBodyAction(NULL, "HeavyAttack2");
	ourHeavyAttack2Action->isAttack = true;
	ourHeavyAttack2Action->frames_num = 72;
	ourHeavyAttack2Action->play_speed = 1.2;
	ourHeavyAttack2Action->priority = ourAttack2Action->priority + 10;
	ourHeavyAttack2Action->type.value = LyubuAction::ACTION_HEAVY_ATTACK2();
	ourHeavyAttack2Action->combo_able_frame_start = 22;
	ourHeavyAttack2Action->combo_able_frame_end = 40;
		//key
		ourHeavyAttack2Action->numOfKeyFrames = 2;
		ourHeavyAttack2Action->keyFrames = new OurFrame*[2];
		ourHeavyAttack2Action->keyFrames[0] = new OurFrame;
		ourHeavyAttack2Action->keyFrames[0]->frameNO = 22;
		ourHeavyAttack2Action->keyFrames[0]->start_angle = 0;
		ourHeavyAttack2Action->keyFrames[0]->plus_angle = 180;
		ourHeavyAttack2Action->keyFrames[0]->valid_dis = 270;
		ourHeavyAttack2Action->keyFrames[0]->damage_pt = 60;
		ourHeavyAttack2Action->keyFrames[1] = new OurFrame;
		ourHeavyAttack2Action->keyFrames[1]->frameNO = 19;
		ourHeavyAttack2Action->keyFrames[1]->start_angle = 180;
		ourHeavyAttack2Action->keyFrames[1]->plus_angle = 180;
		ourHeavyAttack2Action->keyFrames[1]->valid_dis = 270;
		ourHeavyAttack2Action->keyFrames[1]->damage_pt = 60;
		//sound
		ourHeavyAttack2Action->numOfAudioFrames = 4;
		ourHeavyAttack2Action->audioFrames = new OurAudioFrame*[4];
		ourHeavyAttack2Action->audioFrames[0] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[0]->frameNO = 0;
		ourHeavyAttack2Action->audioFrames[0]->audioID = AllAudio::lyubu_mousou1;
		ourHeavyAttack2Action->audioFrames[1] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[1]->frameNO = 19;
		ourHeavyAttack2Action->audioFrames[1]->audioID = AllAudio::weapon_attack;
		ourHeavyAttack2Action->audioFrames[2] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[2]->frameNO = 3;
		ourHeavyAttack2Action->audioFrames[2]->audioID = AllAudio::Thunder02;
		ourHeavyAttack2Action->audioFrames[3] = new OurAudioFrame;
		ourHeavyAttack2Action->audioFrames[3]->frameNO = 4;
		ourHeavyAttack2Action->audioFrames[3]->audioID = AllAudio::Darkness02;
		//fx
		ourHeavyAttack2Action->numOfFxFrames = 1;
		ourHeavyAttack2Action->fxFrames = new OurFxFrame*[1];
		ourHeavyAttack2Action->fxFrames[0] = new OurFxFrame;
		ourHeavyAttack2Action->fxFrames[0]->frameNO = 1;
		ourHeavyAttack2Action->fxFrames[0]->fxName = AllFx::LyubuHeavy2;
		//img
		ourHeavyAttack2Action->hasImg = true;
		ourHeavyAttack2Action->Img = "skill2";

	ourHeavyAttack3Action = new OurAction();
	ourHeavyAttack3Action->actID = actor.GetBodyAction(NULL, "HeavyAttack3");
	ourHeavyAttack3Action->isAttack = true;
	ourHeavyAttack3Action->frames_num = 72;
	ourHeavyAttack3Action->play_speed = 1.2;
	ourHeavyAttack3Action->priority = ourAttack3Action->priority + 10;
	ourHeavyAttack3Action->type.value = LyubuAction::ACTION_HEAVY_ATTACK3();
	ourHeavyAttack3Action->combo_able_frame_start = 24;
	ourHeavyAttack3Action->combo_able_frame_end = 40;
		//key
		ourHeavyAttack3Action->numOfKeyFrames = 2;
		ourHeavyAttack3Action->keyFrames = new OurFrame*[2];
		ourHeavyAttack3Action->keyFrames[0] = new OurFrame;
		ourHeavyAttack3Action->keyFrames[0]->frameNO = 24;
		ourHeavyAttack3Action->keyFrames[0]->start_angle = 270;
		ourHeavyAttack3Action->keyFrames[0]->plus_angle = 180;
		ourHeavyAttack3Action->keyFrames[0]->valid_dis = 190;
		ourHeavyAttack3Action->keyFrames[0]->damage_pt = 60;
		ourHeavyAttack3Action->keyFrames[1] = new OurFrame;
		ourHeavyAttack3Action->keyFrames[1]->frameNO = 39;
		ourHeavyAttack3Action->keyFrames[1]->start_angle = 0;
		ourHeavyAttack3Action->keyFrames[1]->plus_angle = 360;
		ourHeavyAttack3Action->keyFrames[1]->valid_dis = 300;
		ourHeavyAttack3Action->keyFrames[1]->damage_pt = 30;
		//sound
		ourHeavyAttack3Action->numOfAudioFrames = 3;
		ourHeavyAttack3Action->audioFrames = new OurAudioFrame*[3];
		ourHeavyAttack3Action->audioFrames[0] = new OurAudioFrame;
		ourHeavyAttack3Action->audioFrames[0]->frameNO = 0;
		ourHeavyAttack3Action->audioFrames[0]->audioID = AllAudio::lyubu_mousou2;
		ourHeavyAttack3Action->audioFrames[1] = new OurAudioFrame;
		ourHeavyAttack3Action->audioFrames[1]->frameNO = 24;
		ourHeavyAttack3Action->audioFrames[1]->audioID = AllAudio::weapon_attack;
		ourHeavyAttack3Action->audioFrames[2] = new OurAudioFrame;
		ourHeavyAttack3Action->audioFrames[2]->frameNO = 15;
		ourHeavyAttack3Action->audioFrames[2]->audioID = AllAudio::Thunder03;

		//fx
		ourHeavyAttack3Action->numOfFxFrames = 1;
		ourHeavyAttack3Action->fxFrames = new OurFxFrame*[1];
		ourHeavyAttack3Action->fxFrames[0] = new OurFxFrame;
		ourHeavyAttack3Action->fxFrames[0]->frameNO = 1;
		ourHeavyAttack3Action->fxFrames[0]->fxName = AllFx::LyubuHeavy3;
		//img
		ourHeavyAttack3Action->hasImg = true;
		ourHeavyAttack3Action->Img = "skill3";

	//Damaged
	ourHeavyDamagedAction = new OurAction();
	ourHeavyDamagedAction->actID = actor.GetBodyAction(NULL, "HeavyDamaged");
	ourHeavyDamagedAction->frames_num = 0;
	ourHeavyDamagedAction->play_speed = 1;
	ourHeavyDamagedAction->priority = 100;
	ourHeavyDamagedAction->type.value = LyubuAction::ACTION_DAMAGED();
		//sound
		ourHeavyDamagedAction->numOfAudioFrames = 2;
		ourHeavyDamagedAction->audioFrames = new OurAudioFrame*[2];
		ourHeavyDamagedAction->audioFrames[0] = new OurAudioFrame;
		ourHeavyDamagedAction->audioFrames[0]->frameNO = 3;
		ourHeavyDamagedAction->audioFrames[0]->audioID = AllAudio::lyubu_damaged_heavy;
		ourHeavyDamagedAction->audioFrames[1] = new OurAudioFrame;
		ourHeavyDamagedAction->audioFrames[1]->frameNO = 0;
		ourHeavyDamagedAction->audioFrames[1]->audioID = AllAudio::Attack12;



	ourLeftDamagedAction = new OurAction();
	ourLeftDamagedAction->actID = actor.GetBodyAction(NULL, "LeftDamaged");
	ourLeftDamagedAction->frames_num = 0;
	ourLeftDamagedAction->play_speed = 1;
	ourLeftDamagedAction->priority = 100;
	ourLeftDamagedAction->type.value = LyubuAction::ACTION_DAMAGED();
		//sound
		ourLeftDamagedAction->numOfAudioFrames = 2;
		ourLeftDamagedAction->audioFrames = new OurAudioFrame*[2];
		ourLeftDamagedAction->audioFrames[0] = new OurAudioFrame;
		ourLeftDamagedAction->audioFrames[0]->frameNO = 3;
		ourLeftDamagedAction->audioFrames[0]->audioID = AllAudio::lyubu_damaged_light;
		ourLeftDamagedAction->audioFrames[1] = new OurAudioFrame;
		ourLeftDamagedAction->audioFrames[1]->frameNO = 0;
		ourLeftDamagedAction->audioFrames[1]->audioID = AllAudio::Attack16;
	//ourLeftDamagedAction->audioFrames[1] = new OurAudioFrame;
	//ourLeftDamagedAction->audioFrames[1]->frameNO = 10;
	//ourLeftDamagedAction->audioFrames[1]->audioID = AllAudio::eat;

	ourRightDamagedAction = new OurAction();
	ourRightDamagedAction->actID = actor.GetBodyAction(NULL, "RightDamaged");
	ourRightDamagedAction->frames_num = 0;
	ourRightDamagedAction->play_speed = 1;
	ourRightDamagedAction->priority = 100;
	ourRightDamagedAction->type.value = LyubuAction::ACTION_DAMAGED();
		//sound
		ourRightDamagedAction->numOfAudioFrames = 2;
		ourRightDamagedAction->audioFrames = new OurAudioFrame*[2];
		ourRightDamagedAction->audioFrames[0] = new OurAudioFrame;
		ourRightDamagedAction->audioFrames[0]->frameNO = 3;
		ourRightDamagedAction->audioFrames[0]->audioID = AllAudio::lyubu_damaged_medium;
		ourRightDamagedAction->audioFrames[1] = new OurAudioFrame;
		ourRightDamagedAction->audioFrames[1]->frameNO = 0;
		ourRightDamagedAction->audioFrames[1]->audioID = AllAudio::Attack16;

	ourDieAction = new OurAction();
	ourDieAction->actID = actor.GetBodyAction(NULL, "Die");
	ourDieAction->frames_num = 0;
	ourDieAction->play_speed = 1;
	ourDieAction->priority = 1000;
	ourDieAction->type.value = LyubuAction::ACTION_DIE();
		//sound
		ourDieAction->numOfAudioFrames = 3;
		ourDieAction->audioFrames = new OurAudioFrame*[3];
		ourDieAction->audioFrames[0] = new OurAudioFrame;
		ourDieAction->audioFrames[0]->frameNO = 1;
		ourDieAction->audioFrames[0]->audioID = AllAudio::lyubu_damaged_miserable;
		ourDieAction->audioFrames[1] = new OurAudioFrame;
		ourDieAction->audioFrames[1]->frameNO = 0;
		ourDieAction->audioFrames[1]->audioID = AllAudio::Attack10;
		ourDieAction->audioFrames[2] = new OurAudioFrame;
		ourDieAction->audioFrames[2]->frameNO = 75;
		ourDieAction->audioFrames[2]->audioID = AllAudio::Attack16;

	

	actor.MakeCurrentAction(0, NULL, ourIdleAction->actID);
}
void Lyubu::dealKey()
{
	static bool Zpressed=false, Xpressed=false;
	if (FyCheckHotKeyStatus(FY_Z) ) {
		if(!Zpressed)
		{
			//表示是攻擊動作，且在接招範圍
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
		Xpressed=false;
	}
	else if (FyCheckHotKeyStatus(FY_X) )
	{
		if(!Xpressed)
		{
			//表示是攻擊動作，且在接招範圍
			if(current_OurAction
				&&	current_frame > current_OurAction->combo_able_frame_start && current_frame <= current_OurAction->combo_able_frame_end)
			{
				if(	current_OurAction->type == LyubuAction::ACTION_NORMAL_ATTACK1())
					sendAction(ourHeavyAttack1Action);
				else if(current_OurAction->type == LyubuAction::ACTION_NORMAL_ATTACK2())
					sendAction(ourHeavyAttack2Action);
				else if(current_OurAction->type == LyubuAction::ACTION_NORMAL_ATTACK3())
					sendAction(ourHeavyAttack3Action);
			}
		}
		Xpressed=true;
		Zpressed=false;
	}
	else
	{
		Xpressed=false;
		Zpressed=false;
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
}

void Lyubu::damaged( int attack_pt, ACTORid attacker, float angle )
{
	HP -= attack_pt;
	if( HP <= HP_MAX/2 && AllMusic::current_music == AllMusic::stage )
	{
		AllMusic::play( AllMusic::warning, LOOP );
	}
	else if( HP <= 0 )
	{
		sendAction(ourDieAction);
		HP = 0;
	}
	else if(attack_pt > 100)
	{
		sendAction(ourHeavyDamagedAction);
	}
	else
	{
		if( angle < 180 )
			sendAction(ourLeftDamagedAction);
		else
			sendAction(ourRightDamagedAction);
	}

	//lifebar
	{
		gw.SetTexturePath(AllImg::ImgDirAddr);
		lifebar.SetRectArea(NULL, lifebar_length*HP/HP_MAX, lifebar_height, NULL, "lifebar1", 0, TRUE, 0, 0, 0);  
	}
}

void Lyubu::actionChangeSignal( OurAction *last_action, OurAction *current_action )
{
	if( !current_action->hasImg )
	{
		skill.Show(FALSE);
	}
	else
	{
		gw.SetTexturePath(AllImg::ImgDirAddr);
		skill.SetRectArea(NULL, skill_length, skill_height, NULL, current_action->Img, 0, TRUE, 1, 0, 0);
		skill.SetRectPosition(skill_x, skill_y, 0);
		skill.Show(TRUE);
	}
}