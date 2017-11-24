// Copyright 2006-2017 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// -------------------------------------------------------------------
// THIS FILE IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// 
// You are free to use/modify/distribute this file for whatever purpose!
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.4.0 rev. 1 on April 5th 2017

// Make sure to have the server side running in V-REP!
// Start the server from a child script with following command:
// simExtRemoteApiStart(portNumber) -- starts a remote API server service on the specified port

#include <stdio.h>
#include <stdlib.h>

extern "C" {
    #include "extApi.h"
}

int main(int argc,char* argv[])
{
    int sphereHandle;
    int pathHandle;
    int cameraHandle;
    int jhHandle;
    int jvHandle;
    int g;

	printf("Laczenie z serwerem V-REP Remote Api...\n");
    int clientID=simxStart("127.0.0.1",20000,true,true,2000,5);

    if (clientID == -1)
    {
            printf("Blad laczenia\n");
            return 0;
    }

    int ret1 = simxGetObjectHandle(clientID, "Dummy", &sphereHandle, simx_opmode_blocking);
    int ret2 = simxGetObjectHandle(clientID, "Path", &pathHandle, simx_opmode_blocking);
    int ret3 = simxGetObjectHandle(clientID, "Vision_sensor", &cameraHandle, simx_opmode_blocking);
    int ret4 = simxGetObjectHandle(clientID, "jh", &jhHandle, simx_opmode_blocking);
    int ret5 = simxGetObjectHandle(clientID, "jv", &jvHandle, simx_opmode_blocking);
    simxGetObjectHandle(clientID, "Graph", &g, simx_opmode_blocking);

    if (ret1 != simx_return_ok || ret2 != simx_return_ok || ret3 != simx_return_ok || ret4 != simx_return_ok || ret5 != simx_return_ok)
    {
            printf("Blad komunikacji (1)\n");
            //printf("ret1=%d; ret2=%d; ret3=%d\n", ret1, ret2, ret3);
            simxFinish(clientID);
            return 0;
    }

    printf("Uchwyt sphereHandle = %d\n", sphereHandle);
    printf("Uchwyt pathHandle = %d\n", pathHandle);
    printf("Uchwyt cuboidHandle = %d\n", cameraHandle);



    simxSetJointTargetVelocity(clientID, jhHandle,0, simx_opmode_blocking);
    simxSetJointTargetVelocity(clientID, jvHandle,0, simx_opmode_blocking);


    simxFloat** auxValues=(simxFloat**)simxCreateBuffer(4 * sizeof(simxFloat*));
    simxInt** auxValuesCount=(simxInt**)simxCreateBuffer(4 * sizeof(simxInt*));

    for (int i = 0; i < 4; i++ )
    {
      auxValues[i] = (simxFloat*)simxCreateBuffer(35 * sizeof(simxFloat));
      auxValuesCount[i] = (simxInt*)simxCreateBuffer(35 * sizeof(simxInt));
    }



    while (simxGetConnectionId(clientID)!=-1)
    {
        simxUChar *visionTrigger=NULL;
        //simxFloat** auxValues=(simxFloat**) calloc (4,sizeof(simxFloat*));
        //simxInt** auxValuesCount=(simxInt**) calloc (4,sizeof(simxInt*));
        //simxFloat *a[2];
//        for (int i = 0; i < 4; i++ )
  //      {
    //      if (( auxValues[i] = (simxFloat*) calloc(35,sizeof(simxFloat))) == NULL )
      //    { /* error */ }
        //  if (( auxValuesCount[i] = (simxInt*) calloc(15,sizeof(simxInt))) == NULL )
//          { /* error */ }
  //      }

        int ret = simxReadVisionSensor (clientID,cameraHandle,visionTrigger, auxValues,auxValuesCount,simx_opmode_blocking);
        //printf("ret = %d\n", auxValues[1]);
        if(ret == simx_return_ok){
            /*printf("PAKIET = %d %d %d %d\n", auxValuesCount[0][0],auxValuesCount[0][1],auxValuesCount[0][2],auxValuesCount[0][3]);
            printf("A ");
            for (int i = 0; i < 15; i++ )
            {
                printf("%.2f ", auxValues[0][i]);
            }
            printf("\nB ");
            for (int i = 15; i < 25; i++ )
                printf("%.2f ", auxValues[0][i]);
            printf("\nB ");
            for (int i = 0; i < 25; i++ )
                printf("%.2f ", auxValues[2][i]);*/
            printf(" \n");
            printf("WARTOSC = %f\n", auxValues[0][19]);
            printf("WARTOSC = %f\n", auxValues[0][20]);
            printf("\n");
            float ox=auxValues[0][19];
            float oy=auxValues[0][20];
            simxSetJointTargetVelocity(clientID,jhHandle,1*(0.5-ox),simx_opmode_blocking);
            simxSetJointTargetVelocity(clientID,jvHandle,(-0.1)*(0.5-oy),simx_opmode_blocking);

            //simSetGraphUserData(g, "x",ox);
            //simSetGraphUserData(g, "y",oy);
            /**--simAddStatusbarMessage("Obiekty "..p2[1])
            simAddStatusbarMessage(string.format("ox=%.2f; oy=%.2f",ox,oy))

            simSetJointTargetVelocity(jh,5*(0.5-ox))
            simSetJointTargetVelocity(jv,(-1)*(0.5-oy))**/
       }
/*

        //FREE
        for (int i = 0; i < 3; i++ )
        {
         free(auxValues[i] );
         free(auxValuesCount[i]);
         }
        free(auxValues);
        free(auxValuesCount);
*/
    }



    /**
    int driveBackStartTime=-99000;
    float motorSpeeds[2];

	motorSpeeds[0] = -3.1415f*0.5f;
	motorSpeeds[1] = -3.1415f*0.25f;
	simxSetJointTargetVelocity(clientID, leftMotorHandle, motorSpeeds[0], simx_opmode_oneshot);
	simxSetJointTargetVelocity(clientID, rightMotorHandle, motorSpeeds[1], simx_opmode_oneshot);
	extApi_sleepMs(5000);


    while (simxGetConnectionId(clientID)!=-1)
    {
		printf(".");
		fflush(stdout);
		
		//
		
        simxUChar sensorTrigger=0;
        if (simxReadProximitySensor(clientID,sensorHandle,&sensorTrigger,NULL,NULL,NULL,simx_opmode_streaming)==simx_return_ok)
        { // We succeeded at reading the proximity sensor
            int simulationTime=simxGetLastCmdTime(clientID);
            if (simulationTime-driveBackStartTime<3000)
            { // driving backwards while slightly turning:
                motorSpeeds[0]=-3.1415f*0.5f;
                motorSpeeds[1]=-3.1415f*0.25f;
            }
            else
            { // going forward:
                motorSpeeds[0]=3.1415f;
                motorSpeeds[1]=3.1415f;
                if (sensorTrigger)
                    driveBackStartTime=simulationTime; // We detected something, and start the backward mode
            }
            simxSetJointTargetVelocity(clientID,leftMotorHandle,motorSpeeds[0],simx_opmode_oneshot);            
            simxSetJointTargetVelocity(clientID,rightMotorHandle,motorSpeeds[1],simx_opmode_oneshot);           
        }
        extApi_sleepMs(5);
    }
    **/
    simxFinish(clientID);
}

