/*
 * File: AvionicStateFlow.h
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

#ifndef RTW_HEADER_AvionicStateFlow_h_
#define RTW_HEADER_AvionicStateFlow_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef AvionicStateFlow_COMMON_INCLUDES_
#define AvionicStateFlow_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "MW_bbblue_driver.h"
#include "MW_digitalIO.h"
#include "MW_MPU9250.h"
#endif                                 /* AvionicStateFlow_COMMON_INCLUDES_ */

#include "AvionicStateFlow_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Ak[9];
  real_T acc_tmp[9];
  real_T b[9];
  real_T acc_tmp_m[9];
  real_T wk[6];
  real_T y[6];
  real_T B_tmp[6];
  real_T B[4];
  uint8_T b_RegisterValue[24];
  uint8_T output_raw[24];
  real_T Ak_c[3];
  real_T dv[3];
  real_T dv1[2];
  real_T dv2[2];
  int128m_T r;
  int128m_T r1;
  uint128m_T r2;
  uint128m_T r3;
  int96m_T r4;
  int96m_T r5;
  int96m_T r6;
  int96m_T r7;
  int96m_T r8;
  int96m_T r9;
  int96m_T r10;
  int96m_T r11;
  real_T ManualSwitch;                 /* '<S1>/Manual Switch' */
  real_T RateTransition3;              /* '<S7>/Rate Transition3' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T RateTransition1_l;            /* '<S6>/Rate Transition1' */
  real_T RateTransition2;              /* '<S6>/Rate Transition2' */
  real_T RateTransition3_l;            /* '<S6>/Rate Transition3' */
  real_T Sum;                          /* '<S4>/Sum' */
  real_T Input;                        /* '<S14>/Input' */
  real_T MPU9250_o1[3];                /* '<S5>/MPU9250' */
  real_T MPU9250_o2[3];                /* '<S5>/MPU9250' */
  real_T x[3];                         /* '<S4>/MATLAB Function2' */
  real_T acc[3];                       /* '<S3>/MATLAB Function' */
  real_T h_AGL;                        /* '<S1>/MATLAB Function1' */
  real_T rho;                          /* '<S1>/MATLAB Function' */
  real_T Barometer;                    /* '<S1>/Barometer' */
  real_T b1;
  real_T b2;
  real_T b3;
  real_T a21;
  real_T acc_tmp_k;
  real_T acc_tmp_c;
  real_T x_unsgn;
  real_T yd;
  uint32_T ux[2];
  int64m_T val3;
  int64m_T val4;
  int64m_T c;
  int64m_T r12;
  int64m_T r13;
  int64m_T r14;
  int64m_T r15;
  int64m_T r16;
  int64m_T r17;
  int64m_T r18;
  int64m_T r19;
  int64m_T r20;
  int64m_T r21;
  int64m_T r22;
  int64m_T r23;
  int64m_T r24;
  int64m_T r25;
  int64m_T r41;
  int64m_T r42;
  int64m_T r43;
  uint64m_T nk_unsgn;
  uint64m_T xint;
  uint64m_T res;
  uint64m_T nIsOdd;
  uint64m_T r26;
  uint64m_T r27;
  uint64m_T r28;
  uint64m_T r29;
  uint64m_T r30;
  uint64m_T r31;
  uint64m_T r32;
  uint64m_T r33;
  uint64m_T r34;
  uint64m_T r35;
  uint64m_T r36;
  uint64m_T r37;
  uint64m_T r38;
  uint64m_T r39;
  uint64m_T r40;
  uint64m_T prod_unsgn;
  uint64m_T yint;
  uint64m_T b_y1;
  uint64m_T b_y0;
  uint64m_T n1;
  uint64m_T n0;
  uint64m_T temp;
  uint64m_T r44;
  uint64m_T r45;
  uint64m_T r46;
  uint64m_T r47;
  uint64m_T r48;
} B_AvionicStateFlow_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueBaromete_T obj; /* '<S1>/Barometer' */
  beagleboneblue_bbblueMPU9250__T obj_f;/* '<S5>/MPU9250' */
  beagleboneblue_bbblueI2CMaste_T obj_i;/* '<S1>/I2C Master Read' */
  beagleboneblue_bbblueDigitalW_T obj_k;/* '<Root>/Digital Write1' */
  beagleboneblue_bbblueDigitalW_T obj_n;/* '<Root>/Digital Write' */
  beagleboneblue_bbblueLED_Avio_T obj_d;/* '<Root>/Red LED' */
  real_T UD_DSTATE;                    /* '<S30>/UD' */
  real_T RateTransition3_Buffer0;      /* '<S7>/Rate Transition3' */
  real_T RateTransition1_Buffer0;      /* '<S6>/Rate Transition1' */
  real_T RateTransition2_Buffer0;      /* '<S6>/Rate Transition2' */
  real_T RateTransition3_Buffer0_i;    /* '<S6>/Rate Transition3' */
  real_T RateTransition_Buffer;        /* '<S7>/Rate Transition' */
  real_T x_est_p[3];                   /* '<S4>/MATLAB Function2' */
  real_T P[9];                         /* '<S4>/MATLAB Function2' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S4>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S4>/Scope2' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_c;                     /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    /* '<S1>/Scope1' */

  uint32_T is_c3_AvionicStateFlow;     /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T Output_DSTATE;               /* '<S27>/Output' */
  uint8_T Output_DSTATE_a;             /* '<S24>/Output' */
  uint8_T Output_DSTATE_c;             /* '<S21>/Output' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S6>/If Action Subsystem2' */
  int8_T IfActionSubsystem4_SubsysRanBC;/* '<S6>/If Action Subsystem4' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S6>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S6>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S6>/If Action Subsystem' */
  uint8_T is_active_c3_AvionicStateFlow;/* '<Root>/Chart' */
} DW_AvionicStateFlow_T;

/* Parameters (default storage) */
struct P_AvionicStateFlow_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S30>/UD'
                               */
  real_T RepeatingSequenceStair2_OutValu[10];
                              /* Mask Parameter: RepeatingSequenceStair2_OutValu
                               * Referenced by: '<S20>/Vector'
                               */
  real_T RepeatingSequenceStair1_OutValu[8];
                              /* Mask Parameter: RepeatingSequenceStair1_OutValu
                               * Referenced by: '<S19>/Vector'
                               */
  real_T RepeatingSequenceStair_OutValue[8];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S18>/Vector'
                               */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S29>/FixPt Switch'
                                        */
  uint8_T LimitedCounter_uplimit_e;  /* Mask Parameter: LimitedCounter_uplimit_e
                                      * Referenced by: '<S26>/FixPt Switch'
                                      */
  uint8_T LimitedCounter_uplimit_d;  /* Mask Parameter: LimitedCounter_uplimit_d
                                      * Referenced by: '<S23>/FixPt Switch'
                                      */
  real_T Barometer_SampleTime;         /* Expression: 0.01
                                        * Referenced by: '<S1>/Barometer'
                                        */
  real_T I2CMasterRead_SampleTime;     /* Expression: 0.01
                                        * Referenced by: '<S1>/I2C Master Read'
                                        */
  real_T Constant_Value;               /* Expression: 30
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T MPU9250_SampleTime;           /* Expression: 0.01
                                        * Referenced by: '<S5>/MPU9250'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S14>/Outport'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 273.15
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T RateTransition3_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S7>/Rate Transition3'
                                          */
  real_T Constant_Value_ov;            /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T RateTransition1_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition1'
                                          */
  real_T RateTransition2_InitialConditio;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition2'
                                          */
  real_T RateTransition3_InitialCondit_h;/* Expression: 0
                                          * Referenced by: '<S6>/Rate Transition3'
                                          */
  real_T Constant4_Value;              /* Expression: 9.806
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S30>/TSamp'
                                        */
  int16_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint8_T Constant_Value_g;            /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S23>/Constant'
                                        */
  uint8_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S26>/Constant'
                                        */
  uint8_T Constant_Value_ou;           /* Computed Parameter: Constant_Value_ou
                                        * Referenced by: '<S29>/Constant'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S27>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S28>/FixPt Constant'
                                       */
  uint8_T Output_InitialCondition_c;
                                /* Computed Parameter: Output_InitialCondition_c
                                 * Referenced by: '<S24>/Output'
                                 */
  uint8_T FixPtConstant_Value_c;    /* Computed Parameter: FixPtConstant_Value_c
                                     * Referenced by: '<S25>/FixPt Constant'
                                     */
  uint8_T Output_InitialCondition_i;
                                /* Computed Parameter: Output_InitialCondition_i
                                 * Referenced by: '<S21>/Output'
                                 */
  uint8_T FixPtConstant_Value_n;    /* Computed Parameter: FixPtConstant_Value_n
                                     * Referenced by: '<S22>/FixPt Constant'
                                     */
};

/* Real-time Model Data Structure */
struct tag_RTM_AvionicStateFlow_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_AvionicStateFlow_T AvionicStateFlow_P;

/* Block signals (default storage) */
extern B_AvionicStateFlow_T AvionicStateFlow_B;

/* Block states (default storage) */
extern DW_AvionicStateFlow_T AvionicStateFlow_DW;

/* External function called from main */
extern void AvionicStateFlow_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void AvionicStateFlow_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void AvionicStateFlow_initialize(void);
extern void AvionicStateFlow_step0(void);
extern void AvionicStateFlow_step1(void);
extern void AvionicStateFlow_step2(void);
extern void AvionicStateFlow_step(int_T tid);
extern void AvionicStateFlow_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AvionicStateFlow_T *const AvionicStateFlow_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S22>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S27>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Out' : Eliminate redundant signal conversion block
 * Block '<S19>/Out' : Eliminate redundant signal conversion block
 * Block '<S20>/Out' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AvionicStateFlow'
 * '<S1>'   : 'AvionicStateFlow/ALTITUDE '
 * '<S2>'   : 'AvionicStateFlow/Chart'
 * '<S3>'   : 'AvionicStateFlow/Global acceleration'
 * '<S4>'   : 'AvionicStateFlow/Kalman filter'
 * '<S5>'   : 'AvionicStateFlow/MPU9250'
 * '<S6>'   : 'AvionicStateFlow/Subsystem'
 * '<S7>'   : 'AvionicStateFlow/Velocity_pres'
 * '<S8>'   : 'AvionicStateFlow/ALTITUDE /MATLAB Function'
 * '<S9>'   : 'AvionicStateFlow/ALTITUDE /MATLAB Function1'
 * '<S10>'  : 'AvionicStateFlow/Global acceleration/MATLAB Function'
 * '<S11>'  : 'AvionicStateFlow/Kalman filter/MATLAB Function1'
 * '<S12>'  : 'AvionicStateFlow/Kalman filter/MATLAB Function2'
 * '<S13>'  : 'AvionicStateFlow/Subsystem/If Action Subsystem'
 * '<S14>'  : 'AvionicStateFlow/Subsystem/If Action Subsystem1'
 * '<S15>'  : 'AvionicStateFlow/Subsystem/If Action Subsystem2'
 * '<S16>'  : 'AvionicStateFlow/Subsystem/If Action Subsystem3'
 * '<S17>'  : 'AvionicStateFlow/Subsystem/If Action Subsystem4'
 * '<S18>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair'
 * '<S19>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair1'
 * '<S20>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair2'
 * '<S21>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair/LimitedCounter'
 * '<S22>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S23>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S24>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair1/LimitedCounter'
 * '<S25>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S26>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 * '<S27>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair2/LimitedCounter'
 * '<S28>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair2/LimitedCounter/Increment Real World'
 * '<S29>'  : 'AvionicStateFlow/Subsystem/Repeating Sequence Stair2/LimitedCounter/Wrap To Zero'
 * '<S30>'  : 'AvionicStateFlow/Velocity_pres/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_AvionicStateFlow_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
