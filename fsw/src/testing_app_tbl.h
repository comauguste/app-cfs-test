#ifndef TESTING_APP_TBL
#define TESTING_APP_TBL

#include "sample_app.h"
#include <time.h> 

extern SAMPLE_APP_Data_t SAMPLE_APP_Data;

// function declaration
void  TESTING_APP_Testing_TBL_Register(void);
void  TESTING_APP_Testing_TBL_Load(void);
void  TESTING_APP_Testing_TBL_GetInfo(void);


// macro declaration
void TESTING_APP_Testing_TBL_Register(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    status = CFE_TBL_Register(&SAMPLE_APP_Data.TblHandles[0], "SampleAppTable", sizeof(SAMPLE_APP_Table_t),
                              CFE_TBL_OPT_DEFAULT, SAMPLE_APP_TblValidationFunc);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error Registering Table, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }
    char message[250] = "TESTING_APP_Testing_TBL_Register executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully registered table SampleAppTable");
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_TBL_Load(void) {
    int32 status;
    clock_t t; 
    t = clock(); 

    status = CFE_TBL_Load(SAMPLE_APP_Data.TblHandles[0], CFE_TBL_SRC_FILE, SAMPLE_APP_TABLE_FILE);

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error Loading Table, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }
    char message[250] = "TESTING_APP_Testing_TBL_Load executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully loaded table");
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

void TESTING_APP_Testing_TBL_GetInfo(void) {
    int32 status;
    CFE_TBL_Info_t TblInfoPtr;
    clock_t t; 
    t = clock(); 

    status = CFE_TBL_GetInfo(&TblInfoPtr, "SAMPLE_APP.SampleAppTable");

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    char execution_time[50];
    snprintf(execution_time, 50, "%f", time_taken);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error getting info for table, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }
    char message[250] = "TESTING_APP_Testing_TBL_Load executed in ";
    strcat(message, execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully got table info: size is: %ld", TblInfoPtr.Size);
    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

#endif