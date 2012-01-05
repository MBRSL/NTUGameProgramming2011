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
/*
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
*/
eF3DFX* AllFx::Attack01 = NULL;
eF3DFX* AllFx::LyubuWeapon1 = NULL;
eF3DFX* AllFx::LyubuWeapon2 = NULL;
eF3DFX* AllFx::LyubuWeapon3 = NULL;
eF3DFX* AllFx::LyubuHeavy2 = NULL;
eF3DFX* AllFx::LyubuHeavy3 = NULL;
eF3DFX* AllFx::SmallHurt01 = NULL;
eF3DFX* AllFx::BigHurt01 = NULL;
eF3DFX* AllFx::BigHurt02 = NULL;
eF3DFX* AllFx::WeaponDefense01 = NULL;
eF3DFX* AllFx::WeaponSmoke = NULL;
eF3DFX* AllFx::Eatneck = NULL;
eF3DFX* AllFx::MagicMode01 = NULL;
eF3DFX* AllFx::MagicMode02 = NULL;
eF3DFX* AllFx::smoke = NULL;
eF3DFX* AllFx::smoke1 = NULL;
eF3DFX* AllFx::WeaponThunder = NULL;
eF3DFX* AllFx::blood2 = NULL;
eF3DFX* AllFx::DonzoNormal1 = NULL;
eF3DFX* AllFx::DonzoHeavy3 = NULL;
eF3DFX* AllFx::DonzoDamageRight = NULL;
WORLDid AllFx::gID = 0;

eF3DFX* AllFx::getFX(eF3DFX* fx, SCENEid sID){
	/*
	FnWorld gw;
	eF3DFX* fx = new eF3DFX(sID);
	gw.Object(gID);

	gw.SetTexturePath("Data\\NTU4\\FXs\\Textures");
	gw.SetObjectPath("Data\\NTU4\\FXs\\Models");
	fx->SetWorkPath("Data\\NTU4\\FXs");
	BOOL beOK = fx->Load(filename);
	return fx;
	*/
	eF3DFX* fx2 = fx->Clone();
	int numFX = fx->NumberFXs();
	eF3DBaseFX *fx_sub;
	for (int i = 0; i < numFX; i++) {
		fx_sub = fx->GetFX(i);
		fx2->GetFX(i)->SetParentName( fx_sub->GetParentName() );
	}
	return fx2;
}

//FXcenter
int FXcenter::queue_start = 0;
int FXcenter::queue_end = 0;
eF3DFX** FXcenter::queue = NULL;
void FXcenter::initial(WORLDid gID, SCENEid sID)
{
	queue_start = 0;
	queue_end = 0;
	queue = new eF3DFX*[QUEUE_MAX];
	for( int i=0 ; i<QUEUE_MAX ; i++ )
	{
		queue[i] = NULL;
	}

	//allfx
	FnWorld gw;
	gw.Object(gID);
	gw.SetTexturePath("Data\\NTU4\\FXs\\Textures");
	gw.SetObjectPath("Data\\NTU4\\FXs\\Models");

	AllFx::Attack01 = new eF3DFX(sID);
	AllFx::Attack01->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::Attack01->Load("Attack01");

	AllFx::LyubuWeapon1 =  new eF3DFX(sID);
	AllFx::LyubuWeapon1->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::LyubuWeapon1->Load("LyubuWeapon1");

	AllFx::LyubuWeapon2 =  new eF3DFX(sID);
	AllFx::LyubuWeapon2->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::LyubuWeapon2->Load("LyubuWeapon2");

	AllFx::LyubuWeapon3 =  new eF3DFX(sID);
	AllFx::LyubuWeapon3->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::LyubuWeapon3->Load("LyubuWeapon3");

	AllFx::LyubuHeavy2 =  new eF3DFX(sID);
	AllFx::LyubuHeavy2->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::LyubuHeavy2->Load("LyubuHeavy2");

	AllFx::LyubuHeavy3 =  new eF3DFX(sID);
	AllFx::LyubuHeavy3->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::LyubuHeavy3->Load("LyubuHeavy3");

	AllFx::SmallHurt01 =  new eF3DFX(sID);
	AllFx::SmallHurt01->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::SmallHurt01->Load("SmallHurt01");

	AllFx::BigHurt01 =  new eF3DFX(sID);
	AllFx::BigHurt01->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::BigHurt01->Load("BigHurt01");

	AllFx::BigHurt02 =  new eF3DFX(sID);
	AllFx::BigHurt02->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::BigHurt02->Load("BigHurt02");

	AllFx::WeaponDefense01 =  new eF3DFX(sID);
	AllFx::WeaponDefense01->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::WeaponDefense01->Load("WeaponDefense01");

	AllFx::WeaponSmoke =  new eF3DFX(sID);
	AllFx::WeaponSmoke->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::WeaponSmoke->Load("WeaponSmoke");

	AllFx::Eatneck =  new eF3DFX(sID);
	AllFx::Eatneck->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::Eatneck->Load("Eatneck");

	AllFx::MagicMode01 =  new eF3DFX(sID);
	AllFx::MagicMode01->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::MagicMode01->Load("MagicMode01");

	AllFx::MagicMode02 =  new eF3DFX(sID);
	AllFx::MagicMode02->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::MagicMode02->Load("MagicMode02");

	AllFx::smoke =  new eF3DFX(sID);
	AllFx::smoke->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::smoke->Load("smoke");

	AllFx::smoke1 =  new eF3DFX(sID);
	AllFx::smoke1->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::smoke1->Load("smoke1");

	AllFx::WeaponThunder =  new eF3DFX(sID);
	AllFx::WeaponThunder->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::WeaponThunder->Load("WeaponThunder");

	AllFx::blood2 =  new eF3DFX(sID);
	AllFx::blood2 ->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::blood2 ->Load("blood2 ");

	AllFx::DonzoNormal1 =  new eF3DFX(sID);
	AllFx::DonzoNormal1->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::DonzoNormal1->Load("DonzoNormal1");

	AllFx::DonzoHeavy3 =  new eF3DFX(sID);
	AllFx::DonzoHeavy3->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::DonzoHeavy3->Load("DonzoHeavy3");

	AllFx::DonzoDamageRight =  new eF3DFX(sID);
	AllFx::DonzoDamageRight->SetWorkPath("Data\\NTU4\\FXs");
	AllFx::DonzoDamageRight->Load("DonzoDamageRight");
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
void loadAll( WORLDid gID, SCENEid sID )
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
	FXcenter::initial(gID, sID);
	//img
	AllImg::ImgDirAddr = "Data\\NTU4\\Image";
	//music
	AllMusic::initial(gID);
}