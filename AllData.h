#ifndef _ALLDATA_H_
#define _ALLDATA_H_
#include "TheFlyWin32.h"
#include "FyFx.h"

void loadAll( WORLDid gID );

class AllAudio
{
public:
	static AUDIOid s01_pose05;
	static AUDIOid s01_pose07;
	static AUDIOid s01_pose12;
	static AUDIOid s01_pose16;
	static AUDIOid s02_pose07;
	static AUDIOid s02_pose10;
	static AUDIOid s02_pose22;
	static AUDIOid s02_pose25;
	static AUDIOid s02_pose26;
	static AUDIOid s03_pose18;
	static AUDIOid s03_pose22;
	static AUDIOid s03_pose25;
	static AUDIOid eat;
	static AUDIOid se_select;
};

class AllFx
{
public:
	static WORLDid gID;
	static eF3DFX* getFX(char *filename, SCENEid sid);
	static char* Attack01;
	static char* LyubuWeapon1;
	static char* SmallHurt01;
	static char* BigHurt01;
	static char* BigHurt02;
	static char* WeaponDefense01;
	static char* WeaponSmoke;
	static char* Eatneck;
	static char* MagicMode01;
	static char* MagicMode02;
	static char* smoke;
	static char* smoke1;
	static char* WeaponThounder;
	static char* blood2;
private:
	
};

class FXcenter
{
public:
	//var
	static const int QUEUE_MAX = 1000;
	static eF3DFX **queue;
	static int queue_start, queue_end;
	//method
	static void initial();
	static void playFX( eF3DFX* fx );
	static void playAllFX( float skip );
};

class AllImg
{
public:
	static char* ImgDirAddr;
};
#endif