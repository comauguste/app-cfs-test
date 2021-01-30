#ifndef TESTING_APP_SB
#define TESTING_APP_SB

#include "sample_app.h"
#include <time.h> 

extern SAMPLE_APP_Data_t SAMPLE_APP_Data;

// function declaration
void  TESTING_APP_Testing_CFE_MSG_Init(void);
void  TESTING_APP_Testing_CFE_SB_CreatePipe(void);
void  TESTING_APP_Testing_SB_Subscribe(void);


// macro declaration
void TESTING_APP_Testing_CFE_MSG_Init(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    status = CFE_MSG_Init(&SAMPLE_APP_Data.HkTlm.TlmHeader.Msg, SAMPLE_APP_HK_TLM_MID, sizeof(SAMPLE_APP_Data.HkTlm));
    
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error calling CFE_MSG_Init, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    char message[250] = "TESTING_APP_Testing_CFE_MSG_Init executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");
    
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully called CFE_MSG_Init");
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_CFE_SB_CreatePipe(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    status = CFE_SB_CreatePipe(&SAMPLE_APP_Data.CommandPipe, SAMPLE_APP_Data.PipeDepth, SAMPLE_APP_Data.PipeName);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Sample App: Error creating pipe, RC = 0x%08lX\n", (unsigned long)status);
        return ;
    }

    char message[250] = "TESTING_APP_Testing_CFE_SB_CreatePipe executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully created message pipe");
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_SB_Subscribe(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    status = CFE_SB_Subscribe(SAMPLE_APP_SEND_HK_MID, SAMPLE_APP_Data.CommandPipe);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Sample App: Error Subscribing to HK request, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }
    char message[250] = "TESTING_APP_Testing_SB_Subscribe executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully subscribed");
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

#endif