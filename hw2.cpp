#pragma comment(lib, "TheFlyLibD.lib")
#include "TheFlyWin32.h"
#include <windows.h>
#include "function.h"
#include "Camera3rd.h"
#include "robber02.h" 
#include "FyMedia.h"
#include "FyFx.h"
#include <math.h>

float debug[6] = {0,0,0,0};

WORLDid gID = FAILED_ID;
SCENEid sID;
OBJECTid nID, lID;
OBJECTid terrainID;
SHUFAid saID;

Lyubu *lyubu;
Donzo *donzo;
Robber02 *robber, *robber2, *robber3, *robber4;
Camera3rd *camera3rd;
int enemy_num = 5;
OurEnemyActor *enemyActor[5];

void QuitGame(WORLDid, BYTE, BOOL);
void GameAI(int);

void main(int argc, char **argv)
{
	debug[0] = debug[1] = debug[2] = debug[3] = debug[4] = debug[5] = 0;
	FnWorld gw;
	FnScene scene;
	FnTerrain terrain;
	FnViewport vp;
	FnCamera camera;
	bool check;

	// create a new world
	gID = FyWin32CreateWorld("Hello TheFly !", 0, 0, 800, 600, 32, FALSE);
	gw.Object(gID);

	// create a 3D scene & the 3D entities
	sID = gw.CreateScene(10);

	saID = gw.CreateShuFa("新細明體",12);


	//load scenes
	gw.SetObjectPath("Data\\NTU4\\Scenes");
	gw.SetTexturePath("Data\\NTU4\\Scenes\\Textures");
	gw.SetScenePath("Data\\NTU4\\Scenes");
	gw.SetShaderPath( "Data\\NTU4\\Shaders" );
	scene.Object(sID);
	scene.Load("scene2");


	//load terrain
	terrainID = scene.CreateTerrain(ROOT);
	gw.SetObjectPath("Data\\NTU4\\Scenes");
	gw.SetTexturePath("Data\\NTU4\\Scenes");
	terrain.Object(terrainID);
	terrain.Load( "terrain" );
	terrain.GenerateTerrainData();

	 // play lab.mp3
   FyBeginMedia("Data\\Media", 1);
   HWND hwnd = FyGetWindowHandle(gw.Object());
   MEDIAid mmID = FyCreateMediaPlayer(0, "menu", 0, 0, 0, 0);
   FnMedia mP;
   mP.Object(mmID);
   mP.Play(ONCE);

	//Lyubu
	lyubu = new Lyubu( gID, sID );
	//Put an actor on terrain
	lyubu->actor.SetPosition(lyubu->pos_begin);
	check = lyubu->actor.PutOnTerrain(terrainID, false, 0.0f);

	//Donzo
	donzo = new Donzo( gID, sID );
	//Put an actor on terrain
	donzo->actor.SetPosition(donzo->pos_begin);
	check = donzo->actor.PutOnTerrain(terrainID, false, 0.0f);
	enemyActor[0] = donzo;
	
	//Robber02
	robber = new Robber02( gID, sID );
	//Put an actor on terrain
	robber->actor.SetPosition(robber->pos_begin);
	check = robber->actor.PutOnTerrain(terrainID, false, 0.0f);
	enemyActor[1] = robber;

	robber2 = new Robber02( gID, sID );
	//Put an actor on terrain
	float pos_t2[3] = {robber2->pos_begin[0]+10, robber2->pos_begin[1]+10, robber2->pos_begin[2]};
	robber2->actor.SetPosition(robber2->pos_begin);
	check = robber2->actor.PutOnTerrain(terrainID, false, 0.0f);
	enemyActor[2] = robber2;

	robber3 = new Robber02( gID, sID );
	//Put an actor on terrain
	float pos_t3[3] = {robber3->pos_begin[0]+20, robber3->pos_begin[1]+20, robber3->pos_begin[2]};
	robber3->actor.SetPosition(robber3->pos_begin);
	check = robber3->actor.PutOnTerrain(terrainID, false, 0.0f);
	enemyActor[3] = robber3;

	robber4 = new Robber02( gID, sID );
	//Put an actor on terrain
	float pos_t4[3] = {robber4->pos_begin[0]+30, robber4->pos_begin[1]+30, robber4->pos_begin[2]};
	robber4->actor.SetPosition(robber4->pos_begin);
	check = robber4->actor.PutOnTerrain(terrainID, false, 0.0f);
	enemyActor[4] = robber4;

	/*3rd looker*/
	camera3rd = new Camera3rd(gID, sID, terrainID, lyubu);
	check = camera3rd->fronter.PutOnTerrain(terrainID, false, 20);

	float actPos[3];
	lyubu->actor.GetPosition(actPos);
	camera3rd->SetPosition(actPos, lyubu->aID);


	nID = scene.CreateObject(ROOT);
	lID = scene.CreateLight(ROOT);
	// translate the light
	FnLight light;
	light.Object(lID);
	light.SetName("MainLight");
	//light.Translate(-50.0f, -50.0f, 50.0f, GLOBAL);

	// set Hotkeys
	FyDefineHotKey(FY_ESCAPE, QuitGame, FALSE);

	/* bind a timer, frame rate = 30 fps */
	FyBindTimer(0, 30.0f, GameAI, TRUE);
	// invoke the system
	FyInvokeTheFly(TRUE);

	
	
  
}



void dealAllAttack()
{
	int i;
	OurAction* action;
	OurFrame* keyFrame;
	
	//main actor attacks enemy
	action = lyubu->getCurrentAction();
	if( action->isAttack){
		keyFrame = lyubu->getKeyFrame();
		if( keyFrame != NULL ){
			for( i=0 ; i<enemy_num ; i++ ){
				float angle = twoObjectAngle( lyubu->actor.GetBaseObject(), enemyActor[i]->actor.GetBaseObject() );
				if( ::beenHit(lyubu->aID, enemyActor[i]->aID, *keyFrame, angle) ){

					enemyActor[i]->damaged( keyFrame->damage_pt, lyubu->aID, angle );
				}
			}
		}
	}

	/*
	//enemy attacks main
	//todo: cut:enemy is aware?
	for( i=0 ; i<enemy_num ; i++ )
	{
		action = enemyActor[i]->getCurrentAction();
		if( action->type == ACTION_ATTACK ){
			keyFrame = enemyActor[i]->getKeyFrame();
			if( keyFrame != null ){
				if( function::beenHit(enemyActor[i]->aid, mainActor->aid, keyFrame) ){
					mainActor->damaged( keyFrame->damage_pt, enemyActor[i]->aid );
				}
			}
		}
	}
	*/
}

void runAllEnemyAI()
{
	int i;
	ACTORid *friends = new ACTORid[enemy_num];
	for( i=0 ; i<enemy_num ; i++ )
	{
		friends[i] = enemyActor[i]->aID;
	}
	for( i=0 ; i<enemy_num ; i++ )
	{
		enemyActor[i]->AI(lyubu->aID, friends, enemy_num, false);
	}
}

void playAllAction()
{
	int i;
	lyubu->ourPlayAction();
	for( i=0 ; i<enemy_num ; i++ )
	{
		enemyActor[i]->ourPlayAction();
	}
}
//------------------------------------------------------------------------------------
// timer callback function which will be invoked by TheFly3D System every 1/30 second
// C.Wang 0308, 2004
//------------------------------------------------------------------------------------
void GameAI(int skip)
{
	FnWorld gw;

	//faceToTest
	float pos[3];
	lyubu->actor.GetWorldPosition(pos);
	for( int i=0 ; i<enemy_num ; i++ ){
		actorFaceTo(enemyActor[i]->aID, pos[0], pos[1], pos[2]);
	}
	//faceToTest over

	runAllEnemyAI();
	camera3rd->movement();
	lyubu->dealKey();
	playAllAction();
	dealAllAttack();
	camera3rd->render();

	FnShuFa sa;
	sa.Object(saID);
	sa.Begin(camera3rd->vID);
	char debugStr[100];
	sprintf(debugStr, "angle: %.2f\ndista: %.2f\ncross: %.2f\n%.2f\n%.2f\n%.2f", debug[0],debug[1],debug[2],debug[3],debug[4],debug[5]);
	sa.Write(debugStr, 10, 10, 255,0,0);
	sa.End();

	gw.Object(gID);
	gw.SwapBuffers();
}


//-------------------
// quit the demo
// C.Wang 0304, 2004
//-------------------
void QuitGame(WORLDid gID, BYTE code, BOOL value)
{
   if (code == FY_ESCAPE ) {
      if (value) {
         FyWin32EndWorld(gID);
      }
   }
}