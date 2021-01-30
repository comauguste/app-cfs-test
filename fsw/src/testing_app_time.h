#ifndef TESTING_APP_TIME
#define TESTING_APP_TIME

#include "sample_app.h"
#include <time.h> 
#include "testing_custom_time_utility.h"

void  TESTING_APP_Testing_EVS_Register(void);
void  TESTING_APP_Testing_EVS_SendEvent(void);
void  TESTING_APP_Testing_EVS_SendEventWithAppId(void);


// macro declaration
void TESTING_APP_Testing_TIME_GetTime(void) {
    CFE_TIME_SysTime_t Time;

    TIME_TRACKER tracker;

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Start Testing CFE_TIME_GetTime");

    START_TIME_TRACKER(&tracker);
    Time = CFE_TIME_GetTime();
    STOP_TIME_TRACKER(&tracker);

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: CFE_TIME_GetTime output: %d", Time.Seconds);

    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_TIME_GetTime");
}

void TESTING_APP_Testing_TIME_GetTAI(void) {
    CFE_TIME_SysTime_t TAI;
    TIME_TRACKER tracker;

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Start Testing CFE_TIME_GetTAI");

    START_TIME_TRACKER(&tracker);   
    TAI = CFE_TIME_GetTAI();
    STOP_TIME_TRACKER(&tracker);

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: CFE_TIME_GetTAI output: %d", TAI.Seconds);

    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_TIME_GetTAI");
}

void TESTING_APP_Testing_TIME_GetUTC(void) {
    CFE_TIME_SysTime_t UTC;
    TIME_TRACKER tracker;
    
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Start Testing CFE_TIME_GetUTC");

    START_TIME_TRACKER(&tracker);
    UTC = CFE_TIME_GetUTC();
    STOP_TIME_TRACKER(&tracker);

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: CFE_TIME_GetUTC output: %d", UTC.Seconds);

    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_TIME_GetUTC");
}

#endif