#ifndef TESTING_APP_ES
#define TESTING_APP_ES

#include "sample_app.h"
#include <time.h> 

// function declaration

void  TESTING_APP_TESTING_ES_RegisterApp(void);
void  TESTING_APP_TESTING_ES_PerfLogEntry(void);
void  TESTING_APP_TESTING_ES_GetAppID(void);


// macro declaration
void TESTING_APP_TESTING_ES_RegisterApp(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    status = CFE_ES_RegisterApp();

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken); 

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error in CFE_ES_RegisterApp(): %08lx\n", (unsigned long)status);
        return;
    }

    char message[250] = "Testing App: CFE_ES_RegisterApp executed Successfully. CFE_ES_RegisterApp executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_TESTING_ES_GetAppID(void) {
    int32 status;
    CFE_ES_ResourceID_t  AppId;
    clock_t t; 
    t = clock(); 

    status = CFE_ES_GetAppID(&AppId);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error sending event, status = 0x%08lX\n", (unsigned long)status);
        return;
    }

    char message[250] = "TESTING_APP_TESTING_ES_GetAppID executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");
    
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully got App ID from Executive Service, App ID is: %ld", CFE_ES_ResourceID_ToInteger(AppId));
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);

}

#endif