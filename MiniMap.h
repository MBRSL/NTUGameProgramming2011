#ifndef _MINIMAP_H_
#define _MINIMAP_H_
#include <TheFlyWin32.h>
#include "Lyubu.h"
#include "OurEnemyActor.h"

class MiniMap
{
	private:
		VIEWPORTid vpMiniMapID;         // the mini-map viewport
		OBJECTid miniMapStandID;       // the camera stand for minimap camera
		OBJECTid miniMapCameraID;   // the main camera and the camera for minimap rendering
		OBJECTid miniTerrainID;                   // the terrain for displaying on the minimap
		
		OBJECTid anchorID;		// self indication

	public:
		MiniMap( WORLDid , SCENEid , Lyubu*, int , int , int , int );
		void render(OBJECTid, Lyubu*, OurEnemyActor **, int);
		//must set before bind "turn()" with mouse
};
#endif