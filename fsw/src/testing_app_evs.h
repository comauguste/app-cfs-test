#ifndef TESTING_APP_EVS
#define TESTING_APP_EVS

#include "sample_app.h"
#include <time.h> 

extern SAMPLE_APP_Data_t SAMPLE_APP_Data;

void  TESTING_APP_Testing_EVS_Register(void);
void  TESTING_APP_Testing_EVS_SendEvent(void);
void  TESTING_APP_Testing_EVS_SendEventWithAppId(void);


// macro declaration
void TESTING_APP_Testing_EVS_Register(void) {
    int32 status;

    clock_t t; 
    t = clock(); 

    status = CFE_EVS_Register(SAMPLE_APP_Data.EventFilters, SAMPLE_APP_EVENT_COUNTS, CFE_EVS_EventFilter_BINARY);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error Registering Events, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    char message[250] = "Testing App: Successfully registered with EVS. TESTING_APP_Testing_EVS_Register executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_EVS_SendEvent(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    status = CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Testing sending event");

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error sending event, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    char message[250] = "Testing App: Successfully sent an event to EVS. TESTING_APP_Testing_EVS_SendEvent executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_EVS_SendEventWithAppId(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    CFE_ES_ResourceID_t  AppId;
    CFE_ES_GetAppID(&AppId);
    status = CFE_EVS_SendEventWithAppID(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, CFE_ES_ResourceID_ToInteger(AppId), "Testing App: Testing sending event with App ID");

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Failed to send event with App ID");
        return;
    }

    char message[250] = "Testing App: Successfully called SendEventWithAppId. TESTING_APP_Testing_EVS_SendEventWithAppId executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

#endif