#include "Kinect.h"

#define LAYER_0 0
#define LAYER_1 1
#define LAYER_2 2
#define LAYER_3 3
#define LAYER_4 4

Kinect::Kinect(){
	gesture = new Gestures();	
	if(NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON) == S_OK){
		connection = 0;
	}else{
		connection = 1;
	}
}

void Kinect::ioOperation(){
	NUI_SKELETON_FRAME ourframe;
	NuiSkeletonGetNextFrame(0, &ourframe);
				for(int i=0; i<6; i++){
					if(ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
					
						gesture->setGesture(
							gesture->decodeGesture(
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].x,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].y,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].z,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_CENTER].x,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_CENTER].y,
							ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_CENTER].z
							)
							);
					}
				}
}