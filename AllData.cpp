#include "AllData.h"

//AUDIO
AUDIOid AllAudio::s01_pose05 = 0;
AUDIOid AllAudio::s01_pose07 = 0;
AUDIOid AllAudio::s01_pose12 = 0;
AUDIOid AllAudio::s01_pose16 = 0;
AUDIOid AllAudio::s02_pose07 = 0;
AUDIOid AllAudio::s02_pose10 = 0;
AUDIOid AllAudio::s02_pose22 = 0;
AUDIOid AllAudio::s02_pose25 = 0;
AUDIOid AllAudio::s02_pose26 = 0;
AUDIOid AllAudio::s03_pose18 = 0;
AUDIOid AllAudio::s03_pose22 = 0;
AUDIOid AllAudio::s03_pose25 = 0;
AUDIOid AllAudio::eat = 0;
AUDIOid AllAudio::se_select = 0;

//Img
char* AllImg::ImgDirAddr = 0;

//FX
char* AllFx::Attack01 = "Attack01";
char* AllFx::LyubuWeapon1 = "LyubuWeapon1";
char* AllFx::LyubuWeapon2 = "LyubuWeapon2";
char* AllFx::LyubuWeapon3 = "LyubuWeapon3";
char* AllFx::LyubuHeavy2 = "LyubuHeavy2";
char* AllFx::LyubuHeavy3 = "LyubuHeavy3";
char* AllFx::SmallHurt01 = "SmallHurt01";
char* AllFx::BigHurt01 = "BigHurt01";
char* AllFx::BigHurt02 = "BigHurt02";
char* AllFx::WeaponDefense01 = "WeaponDefense01";
char* AllFx::WeaponSmoke = "WeaponSmoke";
char* AllFx::Eatneck = "Eatneck";
char* AllFx::MagicMode01 = "MagicMode01";
char* AllFx::MagicMode02 = "MagicMode02";
char* AllFx::smoke = "smoke";
char* AllFx::smoke1 = "smoke1";
char* AllFx::WeaponThunder = "WeaponThunder";
char* AllFx::blood2 = "blood2";
char* AllFx::DonzoNormal1 = "DonzoNormal1";
char* AllFx::DonzoHeavy3 = "DonzoHeavy3";
char* AllFx::DonzoDamageRight = "DonzoDamageRight";
WORLDid AllFx::gID = 0;

eF3DFX* AllFx::getFX(char*filename, SCENEid sID){
	FnWorld gw;
	eF3DFX* fx = new eF3DFX(sID);
	gw.Object(gID);

	gw.SetTexturePath("Data\\NTU4\\FXs\\Textures");
	gw.SetObjectPath("Data\\NTU4\\FXs\\Models");
	fx->SetWorkPath("Data\\NTU4\\FXs");
	BOOL beOK = fx->Load(filename);

	return fx;
}

//FXcenter
int FXcenter::queue_start = 0;
int FXcenter::queue_end = 0;
eF3DFX** FXcenter::queue = NULL;
void FXcenter::initial()
{
	queue_start = 0;
	queue_end = 0;
	queue = new eF3DFX*[QUEUE_MAX];
	for( int i=0 ; i<QUEUE_MAX ; i++ )
	{
		queue[i] = NULL;
	}
	
}
void FXcenter::playFX( eF3DFX* fx )
{
	if( queue[queue_end] != NULL )
		return;
	queue[queue_end] = fx;
	queue_end = (queue_end+1) % QUEUE_MAX;
}

void FXcenter::playAllFX( float skip )
{
	if( queue_start == queue_end && queue[queue_end]==NULL )
		return;

	bool beOK;

	if( queue_start < queue_end )
	{
		for( int i=queue_start ; i<queue_end ; i++ )
		{
			beOK = queue[i]->Play(skip);
			if( beOK == FALSE )
			{
				delete queue[i];
				queue[i] = queue[queue_end-1];
				queue[queue_end-1] = NULL;
				queue_end--;
				i--;
			}
		}
	}
}

//music
char* AllMusic::BgmDirAddr = "Data\\NTU4\\Media";
FnMedia* AllMusic::mP = NULL;
MEDIAid AllMusic::current_music = 0;
MEDIAid AllMusic::stage = 0;
MEDIAid AllMusic::warning = 0;
MEDIAid AllMusic::win = 0;
void AllMusic::initial( WORLDid gID )
{
	FnWorld gw;
	gw.Object(gID);

	HWND hwnd = FyGetWindowHandle(gw.Object());
	mP = new FnMedia;

	FyBeginMedia(BgmDirAddr, 1);
	stage = FyCreateMediaPlayer(0, "stage", 0, 0, 0, 0);
	warning = FyCreateMediaPlayer(0, "warning", 0, 0, 0, 0);
	win = FyCreateMediaPlayer(0, "win", 0, 0, 0, 0);
}

void AllMusic::play( MEDIAid bgm, int type )
{
	mP->Stop();
	current_music = bgm;
	mP->Object(bgm);
	mP->Play(type);
}

//method
void loadAll( WORLDid gID )
{
	FnWorld gw;
	FnAudio audio;
	gw.Object(gID);
	gw.SetAudioPath("Data\\NTU4\\Audio");

	AllAudio::s01_pose05 = gw.CreateAudio();
	audio.Object(AllAudio::s01_pose05);
	audio.Load("01_pose05");

	AllAudio::s01_pose07 = gw.CreateAudio();
	audio.Object(AllAudio::s01_pose07);
	audio.Load("01_pose07");

	AllAudio::s01_pose12 = gw.CreateAudio();
	audio.Object(AllAudio::s01_pose12);
	audio.Load("01_pose12");

	AllAudio::s01_pose16 = gw.CreateAudio();
	audio.Object(AllAudio::s01_pose16);
	audio.Load("01_pose16");

	AllAudio::s02_pose07 = gw.CreateAudio();
	audio.Object(AllAudio::s02_pose07);
	audio.Load("02_pose07");

	AllAudio::s02_pose10 = gw.CreateAudio();
	audio.Object(AllAudio::s02_pose10);
	audio.Load("02_pose10");

	AllAudio::s02_pose22 = gw.CreateAudio();
	audio.Object(AllAudio::s02_pose22);
	audio.Load("02_pose22");

	AllAudio::s02_pose25 = gw.CreateAudio();
	audio.Object(AllAudio::s02_pose25);
	audio.Load("02_pose25");

	AllAudio::s02_pose26 = gw.CreateAudio();
	audio.Object(AllAudio::s02_pose26);
	audio.Load("02_pose26");

	AllAudio::s03_pose18 = gw.CreateAudio();
	audio.Object(AllAudio::s03_pose18);
	audio.Load("03_pose18");

	AllAudio::s03_pose22 = gw.CreateAudio();
	audio.Object(AllAudio::s03_pose22);
	audio.Load("03_pose22");

	AllAudio::s03_pose25 = gw.CreateAudio();
	audio.Object(AllAudio::s03_pose25);
	audio.Load("03_pose25");

	AllAudio::eat = gw.CreateAudio();
	audio.Object(AllAudio::eat);
	audio.Load("eat");

	AllAudio::se_select = gw.CreateAudio();
	audio.Object(AllAudio::se_select);
	audio.Load("se_select");
	//fx
	AllFx::gID = gID;
	FXcenter::initial();
	//img
	AllImg::ImgDirAddr = "Data\\NTU4\\Image";
	//music
	AllMusic::initial(gID);
}