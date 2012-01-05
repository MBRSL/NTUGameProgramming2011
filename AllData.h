#ifndef _ALLDATA_H_
#define _ALLDATA_H_
#include "TheFlyWin32.h"
#include "FyFx.h"
#include "FyMedia.h"

void loadAll( WORLDid gID, SCENEid sID );

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
	static eF3DFX* getFX(eF3DFX* fx, SCENEid sID);
	static eF3DFX* Attack01;
	static eF3DFX* LyubuWeapon1;
	static eF3DFX* LyubuWeapon2;
	static eF3DFX* LyubuWeapon3;
	static eF3DFX* LyubuHeavy2;
	static eF3DFX* LyubuHeavy3;
	static eF3DFX* SmallHurt01;
	static eF3DFX* BigHurt01;
	static eF3DFX* BigHurt02;
	static eF3DFX* WeaponDefense01;
	static eF3DFX* WeaponSmoke;
	static eF3DFX* Eatneck;
	static eF3DFX* MagicMode01;
	static eF3DFX* MagicMode02;
	static eF3DFX* smoke;
	static eF3DFX* smoke1;
	static eF3DFX* WeaponThunder;
	static eF3DFX* blood2;
	static eF3DFX* DonzoNormal1;
	static eF3DFX* DonzoHeavy3;
	static eF3DFX* DonzoDamageRight;
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
	static void initial(WORLDid gID, SCENEid sID);
	static void playFX( eF3DFX* fx );
	static void playAllFX( float skip );
};

class AllImg
{
public:
	static char* ImgDirAddr;
};

class AllMusic
{
public:
	static FnMedia *mP;
	static char* BgmDirAddr;
	static MEDIAid current_music;
	//music
	static MEDIAid stage;
	static MEDIAid warning;
	static MEDIAid win;

	static void play( MEDIAid bgm, int type );
	static void initial( WORLDid gID );
};
#endif