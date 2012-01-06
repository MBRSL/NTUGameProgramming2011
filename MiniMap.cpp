#include "MiniMap.h"
#include "Lyubu.h"
#include "TheFlyWin32.h"

MiniMap::MiniMap(WORLDid gID, SCENEid sMiniID, Lyubu *lyubu, int x_pos, int y_pos, int width, int height )
{
	FnWorld gw;
	FnScene scene;
	FnViewport vp;
	FnCamera camera;
	FnObject camStand;
	FnTerrain terrain;
	//adr_turn = this->turn;
	/*
	pos_begin[0]=3569.0;
	pos_begin[1]=-3208.0;
	pos_begin[2]=1000.0f;
	*/
	gw.Object(gID);

	//miniMap
	gw.SetObjectPath("Data\\NTU4\\Scenes");
	FnScene miniScene;
	miniScene.Object(sMiniID);
	miniTerrainID = miniScene.CreateObject(ROOT);
	FnObject miniTerrain;
	miniTerrain.Object(miniTerrainID);
	miniTerrain.Load("terrain");
	miniTerrain.SetOpacity(0.8f);

	// create a camera stand for minimap
	miniMapStandID = miniScene.CreateObject(ROOT);

	gw.SetObjectPath("Data\\NTU4\\Characters");
	anchorID = miniScene.CreateObject(miniMapStandID);
	FnObject anchor;
	anchor.Object(anchorID);
	anchor.Load("arrowGreen");
	float pos[]={0,0,10};
	anchor.SetPosition(pos);

   // create a camera for minimap
	miniMapCameraID = miniScene.CreateCamera(miniMapStandID);
	FnCamera miniCamera;
	miniCamera.Object(miniMapCameraID);
	miniCamera.Translate(0.0f, 0.0f, 5000.0f, REPLACE);
	miniCamera.SetNear(5.0f);
	miniCamera.SetFar(100000.0f);
	miniCamera.Rotate(Z_AXIS, 180.0f, LOCAL);

	// create a light for minimap camera
	FnLight miniLight;
	miniLight.Object(miniScene.CreateLight(miniMapCameraID));
	miniLight.SetIntensity(1.0f);
	miniLight.SetRange(9500.0f);

	vpMiniMapID = gw.CreateViewport(x_pos, y_pos, width, height);
}

void MiniMap::render(OBJECTid fronterID, Lyubu* lyubu, OurEnemyActor **enemyActor, int enemy_num)
{
	//render miniMap
	FnObject miniMapStand, mapRef, anchor_lyubu;

	float pos[3];
	lyubu->actor.GetWorldDirection(pos,NULL);
	anchor_lyubu.Object(anchorID);
	anchor_lyubu.SetWorldDirection(pos,NULL);
	miniMapStand.Object(miniMapStandID);
	mapRef.Object(fronterID);
	miniMapStand.SetMatrix(mapRef.GetMatrix(FALSE), REPLACE);

	for(int i = 0; i < enemy_num; i++)
	{
		FnObject base, anchor;
		OBJECTid baseID = enemyActor[i]->actor.GetBaseObject();
		base.Object(baseID);
		anchor.Object(enemyActor[i]->anchorID);
		anchor.SetMatrix(base.GetMatrix(FALSE), REPLACE);
	}
	

	FnViewport vp;
	vp.Object(vpMiniMapID);
	//vp.Render(miniMapCameraID, FALSE, FALSE);
	vp.Render(miniMapCameraID, FALSE, TRUE);
}