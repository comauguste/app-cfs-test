#ifndef TESTING_APP_EVS
#define TESTING_APP_EVS

#include "sample_app.h"
#include <time.h> 
#include "testing_custom_time_utility.h"

extern SAMPLE_APP_Data_t SAMPLE_APP_Data;

void  TESTING_APP_Testing_EVS_Register(void);
void  TESTING_APP_Testing_EVS_SendEvent(void);
void  TESTING_APP_Testing_EVS_SendEventWithAppId(void);


// macro declaration
void TESTING_APP_Testing_EVS_Register(void) {
    int32 status;

    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_EVS_Register(SAMPLE_APP_Data.EventFilters, SAMPLE_APP_EVENT_COUNTS, CFE_EVS_EventFilter_BINARY);
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error Registering Events, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s",  "Testing App: Successfully registered with EVS.");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_EVS_Register");
}

void TESTING_APP_Testing_EVS_SendEvent(void) {
    int32 status;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Testing sending event");
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing app: Error sending event, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully sent an event to EVS.");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_EVS_SendEvent");
}

void TESTING_APP_Testing_EVS_SendEventWithAppId(void) {
    int32 status;
    TIME_TRACKER tracker;

    CFE_ResourceId_t  AppId;
    CFE_ES_GetAppID(&AppId);

    START_TIME_TRACKER(&tracker);
    status = CFE_EVS_SendEventWithAppID(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, CFE_ResourceId_ToInteger(AppId), "Testing App: Testing sending event with App ID");
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Failed to send event with App ID");
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", "Testing App: Successfully called SendEventWithAppId.");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_EVS_SendEventWithAppId");
}

#endif