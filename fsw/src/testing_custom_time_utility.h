#ifndef TESTING_APP_TIME_TRACKER
#define TESTING_APP_TIME_TRACKER

#include <time.h> 
#include "sample_app.h"

typedef struct
{
   clock_t start;
   clock_t end;
   double time_spent;
   char execution_time[12];
} TIME_TRACKER;


// function declaration
void  START_TIME_TRACKER(TIME_TRACKER* tracker);
void  STOP_TIME_TRACKER(TIME_TRACKER* tracker);
const char *  GET_TIME_IN_SECONDS(TIME_TRACKER* tracker);
void REPORT_EXECUTION_TIME(TIME_TRACKER* tracker, const char* function_name);

// macro declaration
void START_TIME_TRACKER(TIME_TRACKER* tracker) {
  tracker->start = clock();
}

void STOP_TIME_TRACKER(TIME_TRACKER* tracker) {
    tracker->end = clock();
    tracker->time_spent = (double)(tracker->end - tracker->start) / CLOCKS_PER_SEC;
}

const char * GET_TIME_IN_SECONDS(TIME_TRACKER* tracker) {
    snprintf(tracker->execution_time, 12, "%f", tracker->time_spent);
    return tracker->execution_time;
}

void REPORT_EXECUTION_TIME(TIME_TRACKER* tracker, const char* function_name) {
    char message[100] = "";

    snprintf(tracker->execution_time, 12, "%f", tracker->time_spent);

    strcat(message, function_name);
    strcat(message, " executed in ");
    strcat(message, tracker->execution_time);
    strcat(message, " seconds");

    CFE_EVS_SendEvent(SAMPLE_APP_TESTING_INFO, CFE_EVS_EventType_INFORMATION, "%s", message);
}

#endif