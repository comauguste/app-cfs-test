#ifndef TESTING_APP_SB
#define TESTING_APP_SB

#include "sample_app.h"
#include <time.h> 
#include "testing_custom_time_utility.h"

extern SAMPLE_APP_Data_t SAMPLE_APP_Data;

// function declaration
void  TESTING_APP_Testing_CFE_MSG_Init(void);
void  TESTING_APP_Testing_CFE_SB_CreatePipe(void);
void  TESTING_APP_Testing_SB_Subscribe(void);


// macro declaration
void TESTING_APP_Testing_CFE_MSG_Init(void) {
    int32 status;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_MSG_Init(&SAMPLE_APP_Data.HkTlm.TlmHeader.Msg, SAMPLE_APP_HK_TLM_MID, sizeof(SAMPLE_APP_Data.HkTlm));
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error calling CFE_MSG_Init, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }
    
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully called CFE_MSG_Init");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_CFE_MSG_Init");
}

void TESTING_APP_Testing_CFE_SB_CreatePipe(void) {
    int32 status;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_SB_CreatePipe(&SAMPLE_APP_Data.CommandPipe, SAMPLE_APP_Data.PipeDepth, SAMPLE_APP_Data.PipeName);
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Sample App: Error creating pipe, RC = 0x%08lX\n", (unsigned long)status);
        return ;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully created message pipe");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_CFE_SB_CreatePipe");
}

void TESTING_APP_Testing_SB_Subscribe(void) {
    int32 status;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_SB_Subscribe(SAMPLE_APP_SEND_HK_MID, SAMPLE_APP_Data.CommandPipe);
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Sample App: Error Subscribing to HK request, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully subscribed");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_SB_Subscribe");
}

#endif