#include "MiniMap.h"
#include "TheFlyWin32.h"

MiniMap::MiniMap(WORLDid gID, SCENEid sMiniID, int x_pos, int y_pos, int width, int height )
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
	FnScene miniScene;
	miniScene.Object(sMiniID);
	miniTerrainID = miniScene.CreateObject(ROOT);
	FnObject miniTerrain;
	miniTerrain.Object(miniTerrainID);
	gw.SetObjectPath("Data\\NTU4\\Scenes");
	miniTerrain.Load("terrain");
	miniTerrain.SetOpacity(0.5f);

	// create a camera stand for minimap
	miniMapStandID = miniScene.CreateObject(ROOT);
	FnObject miniMapStand;
	miniMapStand.Object(miniMapStandID);

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

void MiniMap::render(OBJECTid fronterID)
{
	//render miniMap
	FnObject miniMapStand, mapRef;
	miniMapStand.Object(miniMapStandID);
	mapRef.Object(fronterID);
	miniMapStand.SetMatrix(mapRef.GetMatrix(FALSE), REPLACE);
	FnViewport vp;
	vp.Object(vpMiniMapID);
	//vp.Render(miniMapCameraID, FALSE, FALSE);
	vp.Render(miniMapCameraID, FALSE, TRUE);
}