#include "TheFlyWin32.h"
#include "OurActor.h"
#define PI 3.14159265

enum Direction{LEFT,RIGHT,FORWARD,BACK};
class Lyubu : public OurActor{
	private:
		WORLDid gID;
		SCENEid sID;

		//new
		//�ȩw�����̪�5�ӫ���
		char pressed_key[5];
		//�ثe�ʧ@�A��flag���
		enum ActFlag{NORMAL_ATTACK1,NORMAL_ATTACK2,NORMAL_ATTACK3,NORMAL_ATTACK4};
		ActFlag actFlag;

		void dealFlag();
		void dealKey();
	public:
		FnActor actor;

		ACTORid aID;
		ACTIONid waiting_pose, running_pose;
		float pos_begin[3];
		float MOVE_SPEED, MOVE_ANGLE;

		Lyubu( WORLDid , SCENEid );
		void movement(Direction);
		void Rotate(int degree, float cameraPos[]);
};