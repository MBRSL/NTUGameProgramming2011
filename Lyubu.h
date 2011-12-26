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
};

class Lyubu : public OurActor{
	private:
		WORLDid gID;
		SCENEid sID;

		//new
		//�ȩw�����̪�5�ӫ���
		char pressed_key[5];
		//�ثe�ʧ@�A��flag���
		enum ActFlag{NORMAL_ATTACK1,NORMAL_ATTACK2,NORMAL_ATTACK3,NORMAL_ATTACK4,OTHERS};
		ActFlag actFlag;
		//�f�������ʧ@

		void dealFlag();
	public:
		//the fly
		//FnActor actor;
		//vars
		OurAction *ourRunAction;
		OurAction *ourAttack1Action;
		OurAction *ourAttack2Action;
		OurAction *ourAttack3Action;
		OurAction *ourAttack4Action;
		float pos_begin[3];
		float MOVE_SPEED, MOVE_ANGLE;
		//method
		Lyubu( WORLDid , SCENEid );
		void damaged(int , ACTORid , float );
		void dealKey();
		void Rotate(int degree, float cameraPos[]);
};
#endif