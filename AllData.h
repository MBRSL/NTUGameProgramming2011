#ifndef _ALLDATA_H_
#define _ALLDATA_H_
#include "TheFlyWin32.h"
#include "FyFx.h"
#include "FyMedia.h"

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
	static char* LyubuWeapon2;
	static char* LyubuWeapon3;
	static char* LyubuUtiAttack;
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
	static char* DonzoNormal1;
	static char* DonzoHeavy3;
	static char* DonzoDamageRight;
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