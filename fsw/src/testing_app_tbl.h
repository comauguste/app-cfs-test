#ifndef TESTING_APP_TBL
#define TESTING_APP_TBL

#include "sample_app.h"
#include <time.h> 
#include "testing_custom_time_utility.h"

extern SAMPLE_APP_Data_t SAMPLE_APP_Data;

// function declaration
void  TESTING_APP_Testing_TBL_Register(void);
void  TESTING_APP_Testing_TBL_Load(void);
void  TESTING_APP_Testing_TBL_GetInfo(void);


// macro declaration
void TESTING_APP_Testing_TBL_Register(void) {
    int32 status;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_TBL_Register(&SAMPLE_APP_Data.TblHandles[0], "SampleAppTable", sizeof(SAMPLE_APP_Table_t),
                              CFE_TBL_OPT_DEFAULT, SAMPLE_APP_TblValidationFunc);
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error Registering Table, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully registered table SampleAppTable");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_TBL_Register");
}

void TESTING_APP_Testing_TBL_Load(void) {
    int32 status;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_TBL_Load(SAMPLE_APP_Data.TblHandles[0], CFE_TBL_SRC_FILE, SAMPLE_APP_TABLE_FILE);
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error Loading Table, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully loaded table");
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_TBL_Load");
}

void TESTING_APP_Testing_TBL_GetInfo(void) {
    int32 status;
    CFE_TBL_Info_t TblInfoPtr;
    TIME_TRACKER tracker;

    START_TIME_TRACKER(&tracker);
    status = CFE_TBL_GetInfo(&TblInfoPtr, "SAMPLE_APP.SampleAppTable");
    STOP_TIME_TRACKER(&tracker);

    if (status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("Testing App: Error getting info for table, RC = 0x%08lX\n", (unsigned long)status);
        return;
    }

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "Testing App: Successfully got table info: size is: %ld", TblInfoPtr.Size);
    REPORT_EXECUTION_TIME(&tracker, "TESTING_APP_Testing_TBL_GetInfo");
}

#endif