#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <NuiApi.h>
#include "Gestures.h"
#include "Action.h"
#include "Robot.h"
#include "SerialPort.h"
#include "Dynamixel.h"
#include "GetterState.h"
#include "SelectionState.h"
#include "TraductionState.h"
#include "TransformationState.h"
#include "Kinect.h"

#define LAYER_0 0
#define LAYER_1 1
#define LAYER_2 2
#define LAYER_3 3
#define LAYER_4 4

int type_of_robot;
int error;
Robot *robbie;
Gestures *gestures;
Action *action;
Getter *getter;
Selection *selection;
Traduction *traduction;
Transformation *transformation;

using namespace::std;
int main()
{
	Kinect *kinect = new Kinect();
	if(kinect->connection == 1){
		cout << "Kinect not connected" << endl;
		system("pause");
		return 0;
	}

	do{
		error = 0;
		cout << "Introduce a type of robot:"  << endl;
		cout << "\t1)Mobile" << endl;
		cout << "\t2)Humanoid" <<endl;
		cout << endl;
		cout << "Option: ";cin >> type_of_robot;
		if(cin.fail() || type_of_robot < 1 || type_of_robot > 2){
			cout << "Please, enter a valid target number" << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
			system("pause");
			system("cls");
		}
	}while(error == 1);
		
	robbie = new Robot(type_of_robot);
	int layer = LAYER_1;
	gestures = new Gestures();
	action = new Action();
	getter = new Getter();
	selection = new Selection();
	traduction = new Traduction();
	transformation = new Transformation();

	while(1){
		if(layer == LAYER_1){
			kinect->ioOperation();	
			gestures->setGesture(kinect->gesture->getGesture());
			
			switch(gestures->getGesture()){
				case HANDS_UP:
					layer = LAYER_2;
					break;
				case HANDS_DOWN:
					layer = LAYER_2;
					break;
				case HORIZONTAL_HANDS:
					layer = LAYER_2;
					break;
				case VERTICAL_HANDS:
					layer = LAYER_2;
					break;
				case DOWN_L_RIGHT_HANDS:
					layer = LAYER_2;
					break;
				case DOWN_L_LEFT_HANDS:
					layer = LAYER_2;
					break;
				default:
					//cout << "Gesture not defined" << endl;
					break;
			}
			if(layer == LAYER_2){
				//Generar acciones
				//Recibe layer
				//Regresa accion
				selection->handleState();
				action->decodeGesture(gestures->getGesture());
				layer = LAYER_3;
			}
			if(layer == LAYER_3){
				//Se obtiene un tipo de robot
				//Recibe accion
				//Regresa instrucciones
				traduction->handleState();
				robbie->setActionRobot(action->getAction());
				robbie->decodeAction();
				robbie->getInstructions();
				layer = LAYER_4;

			}
			if(layer == LAYER_4){
				//Recibe instrucciones
				//Introduce las intrucciones al robot
				transformation->handleState();
				robbie->executeInstructionSet();		
				layer = LAYER_1;
			}
		}
	}

	/*
	if(NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON) == S_OK){
		
		do{
			error = 0;
			cout << "Introduce a type of robot:"  << endl;
			cout << "\t1)Mobile" << endl;
			cout << "\t2)Humanoid" <<endl;
			cout << endl;
			cout << "Option: ";cin >> type_of_robot;
			if(cin.fail() || type_of_robot < 1 || type_of_robot > 2){
				cout << "Please, enter a valid target number" << endl;
				error = 1;
				cin.clear();
				cin.ignore(80, '\n');
				system("pause");
				system("cls");
			}
		}while(error == 1);
		
		robbie = new Robot(type_of_robot);
		int layer = LAYER_1;
		gestures = new Gestures();
		action = new Action();
		getter = new Getter();
		selection = new Selection();
		traduction = new Traduction();
		transformation = new Transformation();
		//Lectura del Kinect
		//Gesture Recognition
		NUI_SKELETON_FRAME ourframe;

		while(1){
			if(layer == LAYER_0){
				//printf("LAYER 1\n");
				//cout << "SET THE FIRST INSTRUCTION"  << endl;
				NuiSkeletonGetNextFrame(0, &ourframe);
				for(int i=0; i<6; i++){
					if(ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
					
						gestures->setGesture(
							gestures->decodeGesture(
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
						switch(gestures->getGesture()){
							case EQUAL_RIGHT_HANDS:
								//cout << "EQUAL RIGHT HANDS"  << endl;
								layer = LAYER_1;
								break;
							case EQUAL_LEFT_HANDS:
								//cout << "EQUAL LEFT HANDS"  << endl;
								layer = LAYER_1;
								break;
						}
					}
				}
			}
			if(layer == LAYER_1){
				//printf("LAYER 1\n");
				//getter->handleState();
				NuiSkeletonGetNextFrame(0, &ourframe);
				for(int i=0; i<6; i++){
					if(ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
					
						gestures->setGesture(
							gestures->decodeGesture(
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
						switch(gestures->getGesture()){
							case HANDS_UP:
								//cout << "HANDS UP"  << endl;
								layer = LAYER_2;
								break;
							case HANDS_DOWN:
								//cout << "HANDS DOWN"  << endl;
								layer = LAYER_2;
								break;
							case HORIZONTAL_HANDS:
								//cout << "HORIZONTAL HANDS"  << endl;
								layer = LAYER_2;
								break;
							case VERTICAL_HANDS:
								//cout << "VERTICAL HANDS"  << endl;
								layer = LAYER_2;
								break;
							case EQUAL_RIGHT_HANDS:
								//cout << "EQUAL RIGHT HANDS"  << endl;
								//layer = LAYER_2;
								break;
							case EQUAL_LEFT_HANDS:
								//cout << "EQUAL LEFT HANDS"  << endl;
								//layer = LAYER_2;
								break;
							case CROSS_HANDS:
								//cout << "CROSS HANDS" << endl;
								//layer = LAYER_2;
								break;
							case DOWN_L_RIGHT_HANDS:
								//cout << "DOWN L RIGHT HANDS"  << endl;
								layer = LAYER_2;
								break;
							case DOWN_L_LEFT_HANDS:
								//cout << "DOWN L LEFT HANDS"  << endl;
								layer = LAYER_2;
								break;
							default:
								//cout << "Gesture not defined" << endl;
								break;
						}
					}
				}
			}
			if(layer == LAYER_2){
				//Generar acciones
				//Recibe layer
				//Regresa accion
				//selection->handleState();
				action->decodeGesture(gestures->getGesture());
				layer = LAYER_3;
			}
			if(layer == LAYER_3){
				//Se obtiene un tipo de robot
				//Recibe accion
				//Regresa instrucciones
				//transformation->handleState();
				robbie->setActionRobot(action->getAction());
				robbie->decodeAction();
				robbie->getInstructions();
				layer = LAYER_4;

			}
			if(layer == LAYER_4){
				//Recibe instrucciones
				//Introduce las intrucciones al robot
				//transformation->handleState();
				robbie->executeInstructionSet();		
				layer = LAYER_1;
			}
		}
		NuiShutdown();
	}else{
		cout << "Kinect not connected" << endl;
		system("pause");
	}
	*/

	return 0;
}