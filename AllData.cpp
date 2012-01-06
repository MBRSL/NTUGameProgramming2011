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


AUDIOid AllAudio::lyubu_attack_light = 0;
AUDIOid AllAudio::lyubu_attack_medium = 0;
AUDIOid AllAudio::lyubu_attack_heavy1 = 0;
AUDIOid AllAudio::lyubu_attack_heavy2 = 0;
AUDIOid AllAudio::lyubu_attack_heavy3 = 0;
AUDIOid AllAudio::lyubu_mousou1 = 0;
AUDIOid AllAudio::lyubu_mousou2 = 0;
AUDIOid AllAudio::lyubu_mousou3 = 0;
AUDIOid AllAudio::lyubu_damaged_light = 0;
AUDIOid AllAudio::lyubu_damaged_medium = 0;
AUDIOid AllAudio::lyubu_damaged_heavy = 0;
AUDIOid AllAudio::lyubu_damaged_miserable = 0;

AUDIOid AllAudio::donzo_attack_light = 0;
AUDIOid AllAudio::donzo_attack_medium = 0;
AUDIOid AllAudio::donzo_attack_heavy1 = 0;
AUDIOid AllAudio::donzo_attack_heavy2 = 0;
AUDIOid AllAudio::donzo_mousou1 = 0;
AUDIOid AllAudio::donzo_mousou2 = 0;
AUDIOid AllAudio::donzo_damaged_light = 0;
AUDIOid AllAudio::donzo_damaged_medium = 0;
AUDIOid AllAudio::donzo_damaged_heavy = 0;
AUDIOid AllAudio::donzo_damaged_miserable = 0;


AUDIOid AllAudio::weapon_attack = 0;
AUDIOid AllAudio::weapon_charge_attack = 0;
AUDIOid AllAudio::Swing02 = 0;
AUDIOid AllAudio::Swing03  = 0;
AUDIOid AllAudio::Swing04  = 0;

AUDIOid AllAudio::Attack06 = 0;
AUDIOid AllAudio::Attack07 = 0;
AUDIOid AllAudio::Attack10 = 0;
AUDIOid AllAudio::Attack12 = 0;
AUDIOid AllAudio::Attack16 = 0;

AUDIOid AllAudio::Thunder01 = 0;
AUDIOid AllAudio::Thunder02 = 0;
AUDIOid AllAudio::Thunder03 = 0;
AUDIOid AllAudio::Explosion03 = 0;
AUDIOid AllAudio::Light03 = 0;
AUDIOid AllAudio::Darkness02 = 0;


AUDIOid AllAudio::charge_voice1 = 0;

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
	//mP->SetVolume(0.8);
	//mP->Play(type);
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

		//lyubu voice
	AllAudio::lyubu_attack_light = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_attack_light);
	audio.Load("lyubu_attack_light");
	//audio.SetVolume(300);

	AllAudio::lyubu_attack_medium = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_attack_medium);
	audio.Load("lyubu_attack_medium");

	AllAudio::lyubu_attack_heavy1 = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_attack_heavy1);
	audio.Load("lyubu_attack_heavy1");

	AllAudio::lyubu_attack_heavy2 = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_attack_heavy2);
	audio.Load("lyubu_attack_heavy2");

	AllAudio::lyubu_attack_heavy3 = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_attack_heavy3);
	audio.Load("lyubu_attack_heavy3");

	AllAudio::lyubu_mousou1 = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_mousou1);
	audio.Load("lyubu_mousou1");

	AllAudio::lyubu_mousou2 = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_mousou2);
	audio.Load("lyubu_mousou2");

	AllAudio::lyubu_mousou3 = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_mousou3);
	audio.Load("lyubu_mousou3");

	AllAudio::lyubu_damaged_light = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_damaged_light);
	audio.Load("lyubu_damaged_light");

	AllAudio::lyubu_damaged_medium = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_damaged_medium);
	audio.Load("lyubu_damaged_medium");

	AllAudio::lyubu_damaged_heavy = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_damaged_heavy);
	audio.Load("lyubu_damaged_heavy");

	AllAudio::lyubu_damaged_miserable = gw.CreateAudio();
	audio.Object(AllAudio::lyubu_damaged_miserable);
	audio.Load("lyubu_damaged_miserable");
	
		//donzo voice
	AllAudio::donzo_attack_light = gw.CreateAudio();
	audio.Object(AllAudio::donzo_attack_light);
	audio.Load("donzo_attack_light");

	AllAudio::donzo_attack_medium = gw.CreateAudio();
	audio.Object(AllAudio::donzo_attack_medium);
	audio.Load("donzo_attack_medium");

	AllAudio::donzo_attack_heavy1 = gw.CreateAudio();
	audio.Object(AllAudio::donzo_attack_heavy1);
	audio.Load("donzo_attack_heavy1");

	AllAudio::donzo_attack_heavy2 = gw.CreateAudio();
	audio.Object(AllAudio::donzo_attack_heavy2);
	audio.Load("donzo_attack_heavy2");

	AllAudio::donzo_mousou1 = gw.CreateAudio();
	audio.Object(AllAudio::donzo_mousou1);
	audio.Load("donzo_mousou1");

	AllAudio::donzo_mousou2 = gw.CreateAudio();
	audio.Object(AllAudio::donzo_mousou2);
	audio.Load("donzo_mousou2");

	AllAudio::donzo_damaged_light = gw.CreateAudio();
	audio.Object(AllAudio::donzo_damaged_light);
	audio.Load("donzo_damaged_light");

	AllAudio::donzo_damaged_medium = gw.CreateAudio();
	audio.Object(AllAudio::donzo_damaged_medium);
	audio.Load("donzo_damaged_medium");

	AllAudio::donzo_damaged_heavy = gw.CreateAudio();
	audio.Object(AllAudio::donzo_damaged_heavy);
	audio.Load("donzo_damaged_heavy");

	AllAudio::donzo_damaged_miserable = gw.CreateAudio();
	audio.Object(AllAudio::donzo_damaged_miserable);
	audio.Load("donzo_damaged_miserable");


		//weapon
	AllAudio::weapon_attack = gw.CreateAudio();
	audio.Object(AllAudio::weapon_attack);
	audio.Load("weapon_attack");

	AllAudio::weapon_charge_attack = gw.CreateAudio();
	audio.Object(AllAudio::weapon_charge_attack);
	audio.Load("weapon_charge_attack");

	AllAudio::Swing02 = gw.CreateAudio();
	audio.Object(AllAudio::Swing02);
	audio.Load("063-Swing02");

	AllAudio::Swing03 = gw.CreateAudio();
	audio.Object(AllAudio::Swing03);
	audio.Load("064-Swing03");

	AllAudio::Swing04 = gw.CreateAudio();
	audio.Object(AllAudio::Swing04);
	audio.Load("065-Swing04");

	AllAudio::Attack06 = gw.CreateAudio();
	audio.Object(AllAudio::Attack06);
	audio.Load("094-Attack06");

	AllAudio::Attack07 = gw.CreateAudio();
	audio.Object(AllAudio::Attack07);
	audio.Load("095-Attack07");
	
	AllAudio::Attack10 = gw.CreateAudio();
	audio.Object(AllAudio::Attack10);
	audio.Load("098-Attack10");

	AllAudio::Attack12 = gw.CreateAudio();
	audio.Object(AllAudio::Attack12);
	audio.Load("100-Attack12");

	AllAudio::Attack16 = gw.CreateAudio();
	audio.Object(AllAudio::Attack16);
	audio.Load("104-Attack16");

		//fx sound
	AllAudio::Thunder01 = gw.CreateAudio();
	audio.Object(AllAudio::Thunder01);
	audio.Load("123-Thunder01");

	AllAudio::Thunder02 = gw.CreateAudio();
	audio.Object(AllAudio::Thunder02);
	audio.Load("124-Thunder02");

	AllAudio::Thunder03 = gw.CreateAudio();
	audio.Object(AllAudio::Thunder03);
	audio.Load("125-Thunder03");
	
	AllAudio::Explosion03 = gw.CreateAudio();
	audio.Object(AllAudio::Explosion03);
	audio.Load("050-Explosion03");
	
	AllAudio::Light03 = gw.CreateAudio();
	audio.Object(AllAudio::Light03);
	audio.Load("137-Light03");

	AllAudio::Darkness02 = gw.CreateAudio();
	audio.Object(AllAudio::Darkness02);
	audio.Load("139-Darkness02");
	
		//mix
	AllAudio::charge_voice1 = gw.CreateAudio();
	audio.Object(AllAudio::charge_voice1);
	audio.Load("charge_voice1");

	//fx
	AllFx::gID = gID;
	FXcenter::initial(gID, sID);
	//img
	AllImg::ImgDirAddr = "Data\\NTU4\\Image";
	//music
	AllMusic::initial(gID);
}