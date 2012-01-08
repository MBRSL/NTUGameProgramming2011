#ifndef _LYUBU_H_
#define _LYUBU_H_
#include "TheFlyWin32.h"
#include "OurActor.h"
#include "OurAction.h"
#include "AllData.h"
#define PI 3.14159265

enum Direction{LEFT,RIGHT,FORWARD,BACK};
class LyubuAction : public Action_type
{
public:
	static char*	ACTION_NORMAL_ATTACK1(){	return "LYUBU_NORMAL_ATTACK1"; }
	static char*	ACTION_NORMAL_ATTACK2(){	return "LYUBU_NORMAL_ATTACK2"; }
	static char*	ACTION_NORMAL_ATTACK3(){	return "LYUBU_NORMAL_ATTACK3"; }
	static char*	ACTION_NORMAL_ATTACK4(){	return "LYUBU_NORMAL_ATTACK4"; }
	static char*	ACTION_HEAVY_ATTACK1(){	return "LYUBU_HEAVY_ATTACK1"; }
	static char*	ACTION_HEAVY_ATTACK2(){	return "LYUBU_HEAVY_ATTACK2"; }
	static char*	ACTION_HEAVY_ATTACK3(){	return "LYUBU_HEAVY_ATTACK3"; }
};

class Lyubu : public OurActor{
	private:
		//new
		//暫定紀錄最近5個按鍵
		char pressed_key[5];
		//目前動作，用flag表示
		enum ActFlag{NORMAL_ATTACK1,NORMAL_ATTACK2,NORMAL_ATTACK3,NORMAL_ATTACK4,OTHERS};
		ActFlag actFlag;
		//呂布有的動作

		void dealFlag();
	public:
		FnWorld gw;
		//the fly
		//FnActor actor;
		//vars
		OurAction *ourRunAction;
		OurAction *ourAttack1Action;
		OurAction *ourAttack2Action;
		OurAction *ourAttack3Action;
		OurAction *ourAttack4Action;
		OurAction *ourHeavyAttack1Action;
		OurAction *ourHeavyAttack2Action;
		OurAction *ourHeavyAttack3Action;
		OurAction *ourHeavyDamagedAction;
		OurAction *ourLeftDamagedAction;
		OurAction *ourRightDamagedAction;
		OurAction *ourDieAction;
		float pos_begin[3];
		float angle_begin;
		float MOVE_SPEED, MOVE_ANGLE;
		int dieFlag;
		//method
		Lyubu( WORLDid , SCENEid );
		void damaged(int , ACTORid , float );
		void renderKillnum();
		void dealKey();
		void Rotate(int degree, float cameraPos[]);
		void actionChangeSignal( OurAction *last_action, OurAction *current_action );
		void winDeal();
		//2D
		SCENEid s2D;
		FnSprite lifebar, skill, face, killnum0, killnum1, killnum2, killword, gameover, gamewin;
		OBJECTid lifebar_frameID, lifebarID, faceID, skillID, killnum0ID, killnum1ID, killnum2ID, killwordID, gameoverID, gamewinID;
		int lifebar_x, lifebar_y;
		int skill_x, skill_y;
		int face_x, face_y;
		int killnum_x, killnum_y;
		int killword_x,killword_y;
		int gameover_x,gameover_y;
		int gamewin_x,gamewin_y;

		float lifebar_length, lifebar_height;
		float skill_length, skill_height;
		float face_length, face_height;
		float killnum_length, killnum_height;
		float killword_length, killword_height;
		float gameover_length, gameover_height;
		float gamewin_length, gamewin_height;
		
		
		
		
};
#endif