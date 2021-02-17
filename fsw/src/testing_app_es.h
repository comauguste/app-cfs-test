#ifndef TESTING_APP_ES
#define TESTING_APP_ES

#include "sample_app.h"
#include <time.h> 
#include "testing_custom_time_utility.h"

// function declaration

void  TESTING_APP_TESTING_ES_RegisterApp(void);
void  TESTING_APP_TESTING_ES_GetAppID(void);


// macro declaration
void TESTING_APP_TESTING_ES_RegisterApp(void) {
    int32 status;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_ES_RegisterApp();
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error in CFE_ES_RegisterApp(): %08lx\n", (unsigned long)status);
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully regestered test application");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_TESTING_ES_RegisterApp");
}

void TESTING_APP_TESTING_ES_GetAppID(void) {
    int32 status;
    CFE_ResourceId_t  AppId;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_ES_GetAppID(&AppId);
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error sending event, status = 0x%08lX\n", (unsigned long)status);
        return;
    }
    
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully got App ID from Executive Service, App ID is: %ld", CFE_ResourceId_ToInteger(AppId));
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_TESTING_ES_GetAppID");
}

#endif