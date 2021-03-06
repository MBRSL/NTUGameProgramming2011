#pragma comment(lib, "TheFlyLibD.lib")
#include "TheFlyWin32.h"
#include <windows.h>
#include "function.h"
#include "Camera3rd.h"
#include "robber02.h" 
#include "FyMedia.h"
#include "FyFx.h"
#include <math.h>
#include <time.h>
#include "AllData.h"
#include "FPSview.h"
#include "MiniMap.h"

float debug[6] = {0,0,0,0};

WORLDid gID = FAILED_ID;
SCENEid sID;                // the main 3D scene
SCENEid sMiniID;             // the 3D scene for displaying the minimap
OBJECTid lID;				// light in main scene
OBJECTid terrainID;
SHUFAid saID;

EnemyTeam *team[11];
int teamCount = 0;
int enemyCount = 0;
Lyubu *lyubu;
Donzo *donzo;
Camera3rd *camera3rd;
const int team_num = 11;
int enemy_num = 5;
OurEnemyActor *enemyActor[100];

const float cpu_deal_dis = 900;
bool enemy_be_deal[100];

FPSview *fpsview;
MiniMap *miniMap;

void QuitGame(WORLDid, BYTE, BOOL);
void GameAI(int);

void main(int argc, char **argv)
{
	srand(time(NULL));
	debug[0] = debug[1] = debug[2] = debug[3] = debug[4] = debug[5] = 0;
	bool check;

	// create a new world
	FnWorld gw;
	//gID = FyWin32CreateWorld("Team 21: Donzo Vs Lyubu", 0, 0, 800, 600, 32, TRUE);
	gID = FyWin32CreateWorld("Team 21: Donzo Vs Lyubu", 0, 0, 1024, 768, 32, TRUE);
	gw.Object(gID);

	// create a 3D scene & the 3D entities
	sID = gw.CreateScene(5);
	sMiniID = gw.CreateScene(11);
	saID = gw.CreateShuFa("新細明體",12);

	//load Audio
	::loadAll( gID, sID );

	//load scenes
	gw.SetObjectPath("Data\\NTU4\\Scenes");
	gw.SetTexturePath("Data\\NTU4\\Scenes\\Textures");
	gw.SetScenePath("Data\\NTU4\\Scenes");
	gw.SetShaderPath( "Data\\NTU4\\Shaders" );
	FnScene scene;
	scene.Object(sID);
	scene.Load("scene2");

	//load terrain
	terrainID = scene.CreateTerrain(ROOT);
	gw.SetObjectPath("Data\\NTU4\\Scenes");
	gw.SetTexturePath("Data\\NTU4\\Scenes");
	FnTerrain terrain;
	terrain.Object(terrainID);
	terrain.Load( "terrain" );
	terrain.GenerateTerrainData();

	//Lyubu
	lyubu = new Lyubu( gID, sID );
	//Put an actor on terrain
	lyubu->actor.SetPosition(lyubu->pos_begin);
	//lyubu->actor.TurnRight(180);
	check = lyubu->actor.PutOnTerrain(terrainID, false, 0.0f);




  float **enemy_start_pos = new float*[team_num];
  enemy_start_pos[0] = new float[3];
  enemy_start_pos[0][0] = 520;
  enemy_start_pos[0][1] = 3000;
  enemy_start_pos[0][2] = 1000;
  enemy_start_pos[1] = new float[2];
  enemy_start_pos[1][0] = 3420;
  enemy_start_pos[1][1] = -2770;
  enemy_start_pos[2] = new float[2];
  enemy_start_pos[2][0] = 2523;
  enemy_start_pos[2][1] = -2350;
  enemy_start_pos[3] = new float[2];
  enemy_start_pos[3][0] = 1540;
  enemy_start_pos[3][1] = -2770;
  enemy_start_pos[4] = new float[2];
  enemy_start_pos[4][0] = 193;
  enemy_start_pos[4][1] = -2248;
  enemy_start_pos[5] = new float[2];
  enemy_start_pos[5][0] = -750;
  enemy_start_pos[5][1] = -2600;
  enemy_start_pos[6] = new float[2];
  enemy_start_pos[6][0] = -1700;
  enemy_start_pos[6][1] = -3200;
  enemy_start_pos[7] = new float[2];
  enemy_start_pos[7][0] = -2800;
  enemy_start_pos[7][1] = -1800;
  enemy_start_pos[8] = new float[2];
  enemy_start_pos[8][0] = -1757;
  enemy_start_pos[8][1] = -242;
  enemy_start_pos[9] = new float[2];
  enemy_start_pos[9][0] = 527;
  enemy_start_pos[9][1] = 2850;
  enemy_start_pos[10] = new float[2];
  enemy_start_pos[10][0] = 527;
  enemy_start_pos[10][1] = 2850;
 
  int *team_members_num = new int[team_num];
  team_members_num[0] = 1;
  team_members_num[1] = 6;
  team_members_num[2] = 4;
  team_members_num[3] = 4;
  team_members_num[4] = 3;
  team_members_num[5] = 6;
  team_members_num[6] = 8;
  team_members_num[7] = 3;
  team_members_num[8] = 7;
  team_members_num[9] = 4;
  team_members_num[10] = 4;
 
  //Donzo
  donzo = new Donzo( gID, sID );
  //Put an actor on terrain
  team[teamCount] = new EnemyTeam(teamCount, 1);
  team[teamCount]->members = new OurEnemyActor*[1];
  team[teamCount]->members[0] = donzo;
  donzo->actor.SetPosition(enemy_start_pos[0]);
  donzo->team = team[teamCount];
  check = donzo->actor.PutOnTerrain(terrainID, false, 0.0f);
  enemyActor[enemyCount++] = donzo;
  teamCount++;
 
  //ACTORid robberID = Robber02::getTemplateID(gID, sID);
  for(int i = 1; i < team_num; i++)
  {
    team[teamCount] = new EnemyTeam(teamCount, team_members_num[i]);
    team[teamCount]->members = new OurEnemyActor*[team_members_num[i]];
 
    for(int j = 0; j < team_members_num[i]; j++)
    {
      //Robber02
      //Robber02 *robber = new Robber02( gID, sID, robberID );
      Robber02 *robber = new Robber02( gID, sID);
      //Put an actor on terrain
      float pos[3];
      pos[0] = enemy_start_pos[i][0] + rand()%160;
      pos[1] = enemy_start_pos[i][1] + rand()%160;
      pos[2] = 1000;
      robber->actor.SetPosition(pos);
      robber->team = team[teamCount];
      check = robber->actor.PutOnTerrain(terrainID, false, 0.0f);
      enemyActor[enemyCount++] = robber;
 
      team[teamCount]->members[j] = robber;
    }
	teamCount++;
  }
  
  enemy_num = enemyCount;


	/*3rd looker*/
	//camera Ref
	camera3rd = new Camera3rd(gID, sID, terrainID, lyubu);
	check = camera3rd->fronter.PutOnTerrain(terrainID, false, 20);

	miniMap = new MiniMap(gID, sMiniID, lyubu, 800, 40, 200, 200);

	fpsview = new FPSview(gID, sID, terrainID, 800, 0, 1300-800, 600);
	FPSview::setClsNow(fpsview);
	FyBindMouseMoveFunction( FPSview::turn );

	float actPos[3];
	lyubu->actor.GetPosition(actPos);
	camera3rd->SetPosition(actPos, lyubu->aID);

	lID = scene.CreateLight(ROOT);
	// translate the light
	FnLight light;
	light.Object(lID);
	light.SetName("MainLight");
	light.SetLightType(PARALLEL_LIGHT);
	float pos[3];
	pos[0]=650;pos[1]=4200;pos[2]=1000;
	light.SetPosition(pos);
	light.SetColor(1, 0.4, 0.1);
	//light.SetIntensity(1);
	//light.Translate(-50.0f, -50.0f, 50.0f, GLOBAL);
	light.SetRange(3000);
	// set Hotkeys
	FyDefineHotKey(FY_ESCAPE, QuitGame, FALSE);

	/* bind a timer, frame rate = 30 fps */
	FyBindTimer(0, 30.0f, GameAI, TRUE, FALSE);

	AllMusic::play(AllMusic::stage,LOOP);

	// invoke the system
	FyInvokeTheFly(TRUE);
}

void enemy_deal_detect()
{
	for( int i=0 ; i<enemy_num ; i++ )
	{
		enemy_be_deal[i] = false;
		if( ::twoActorDis( lyubu->aID, enemyActor[i]->aID ) < cpu_deal_dis )
			enemy_be_deal[i] = true;
	}
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
				if( enemy_be_deal[i] ){
					if( enemyActor[i]->team->aware && enemyActor[i]->current_OurAction->type != Action_type::ACTION_DIE() )
					{
						float angle = twoObjectAngle( lyubu->actor.GetBaseObject(), enemyActor[i]->actor.GetBaseObject() );
						if( ::beenHit(lyubu->aID, enemyActor[i]->aID, *keyFrame, angle) ){

							enemyActor[i]->damaged( keyFrame->damage_pt, lyubu->aID, angle );
						}
					}
				}
			}
		}
	}

	//enemy attacks main
	//todo: cut:enemy is aware?
	for( i=0 ; i<enemy_num ; i++ )
	{
		if( enemy_be_deal[i] )
		{
			if( enemyActor[i]->team->aware )
			{
				action = enemyActor[i]->getCurrentAction();
				if( action->isAttack ){
					keyFrame = enemyActor[i]->getKeyFrame();
					if( keyFrame != NULL ){
						float angle = twoObjectAngle( enemyActor[i]->actor.GetBaseObject(), lyubu->actor.GetBaseObject() );
						if( ::beenHit(enemyActor[i]->aID, lyubu->aID, *keyFrame, angle) ){
							lyubu->damaged( keyFrame->damage_pt, enemyActor[i]->aID, angle);
						}
					}
				}
			}
		}
	}
}

void runAllEnemyAI()
{
	int i;
	for( i=0 ; i<enemy_num ; i++ )
	{
		if( enemy_be_deal[i] )
		{
			if( enemyActor[i]->getCurrentAction()->type != Action_type::ACTION_DIE() 
				&& enemyActor[i]->getCurrentAction()->type != Action_type::ACTION_ATTACK() )
				enemyActor[i]->AI(lyubu->aID, team, teamCount);
		}
	}
}

void playAllAction()
{
	int i;
	lyubu->ourPlayAction();
	for( i=0 ; i<enemy_num ; i++ )
	{
		if( enemy_be_deal[i] )
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
	static int orz=0;

	FXcenter::playAllFX( skip );
	enemy_deal_detect();
	
	camera3rd->movement();
	lyubu->dealKey();
	lyubu->renderKillnum();
	playAllAction();
	dealAllAttack();
	camera3rd->render();
	camera3rd->vp.Render2D(lyubu->s2D, FALSE, TRUE);
	//fpsview->move();
	//fpsview->render();
	miniMap->render(camera3rd->fronterID, lyubu, enemyActor, enemy_num);
	AllMusic::deal_loop();
	if(lyubu->dieFlag==1){
		FnLight light;
		light.Object(lID);
		light.SetColor(1,0,0);
	}
	else if(donzo->winFlag==1)
	{
		FnLight light;
		light.Object(lID);
		light.SetColor(0,0,1);
		lyubu->winDeal();
	}
	else
		runAllEnemyAI();

	/*
	FnShuFa sa;
	sa.Object(saID);
	sa.Begin(camera3rd->vID);
	//sa.Begin(fpsview->vID);
	char debugStr[100];
	sprintf(debugStr, "(x, y, z): (%.2f, %.2f, %.2f)\n%.2f\n%.2f\n%.2f", debug[0],debug[1],debug[2],debug[3],debug[4],debug[5]);
	sa.Write(debugStr, 10, 10, 255,0,0);
	sa.End();
	*/
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