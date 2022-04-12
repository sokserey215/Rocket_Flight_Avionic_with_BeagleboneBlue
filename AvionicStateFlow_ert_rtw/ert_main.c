/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'AvionicStateFlow'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Apr  5 13:52:32 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "AvionicStateFlow.h"
#include "AvionicStateFlow_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "MW_bbblue_init.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[2];
int taskId[2];
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[2];
int subratePriority[2];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    AvionicStateFlow_step(subRateId);

    /* Get model outputs here */
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  int_T i;
  runModel = (rtmGetErrorStatus(AvionicStateFlow_M) == (NULL)) &&
    !rtmGetStopRequested(AvionicStateFlow_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    for (i = 1
         ; i <= 2; i++) {
      if (rtmStepTask(AvionicStateFlow_M, i)
          ) {
        sem_post(&subrateTaskSem[ i - 1
                 ]);
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(AvionicStateFlow_M->extModeInfo, 3, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(AvionicStateFlow_M, true);
      }

      if (rtmGetStopRequested(AvionicStateFlow_M) == true) {
        rtmSetErrorStatus(AvionicStateFlow_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(AvionicStateFlow_M->extModeInfo, 3, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(AvionicStateFlow_M, true);
      }
    }

    AvionicStateFlow_step(0);

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(AvionicStateFlow_M) == (NULL)) &&
                      !rtmGetStopRequested(AvionicStateFlow_M));
    runModel = !stopRequested;
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(AvionicStateFlow_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<2; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<2; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  MW_bbblue_terminate();

  /* Disable rt_OneStep() here */

  /* Terminate model */
  AvionicStateFlow_terminate();
  rtExtModeShutdown(3);
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  subratePriority[0] = 39;
  subratePriority[1] = 38;
  MW_bbblue_init();
  rtmSetErrorStatus(AvionicStateFlow_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  AvionicStateFlow_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(AvionicStateFlow_M));
  rtExtModeCheckInit(3);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(AvionicStateFlow_M->extModeInfo, 3, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(AvionicStateFlow_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  myRTOSInit(0.01, 2);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
