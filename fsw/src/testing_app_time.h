#ifndef TESTING_APP_TIME
#define TESTING_APP_TIME

#include "sample_app.h"
#include <time.h> 


void  TESTING_APP_Testing_EVS_Register(void);
void  TESTING_APP_Testing_EVS_SendEvent(void);
void  TESTING_APP_Testing_EVS_SendEventWithAppId(void);


// macro declaration
void TESTING_APP_Testing_TIME_GetTime(void) {
    CFE_TIME_SysTime_t Time;
    clock_t t; 

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Start Testing CFE_TIME_GetTime");

    t = clock(); 
    Time = CFE_TIME_GetTime();
    t = clock() - t; 

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: CFE_TIME_GetTime output: %d", Time.Seconds);


    char message[250] = "TESTING_APP_Testing_TIME_GetTime executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_TIME_GetTAI(void) {
    CFE_TIME_SysTime_t TAI;
    clock_t t; 

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Start Testing CFE_TIME_GetTAI");

    t = clock();    
    TAI = CFE_TIME_GetTAI();
    t = clock() - t; 

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: CFE_TIME_GetTAI output: %d", TAI.Seconds);

    char message[250] = "TESTING_APP_Testing_TIME_GetTAI executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_TIME_GetUTC(void) {
    CFE_TIME_SysTime_t UTC;
    clock_t t;
    
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Start Testing CFE_TIME_GetUTC");

    t = clock();
    UTC = CFE_TIME_GetUTC();
    t = clock() - t; 

    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: CFE_TIME_GetUTC output: %d", UTC.Seconds);

    char message[250] = "TESTING_APP_Testing_TIME_GetUTC executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

#endif