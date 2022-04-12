/*
 * File: AvionicStateFlow_data.c
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

#include "AvionicStateFlow.h"
#include "AvionicStateFlow_private.h"

/* Block parameters (default storage) */
P_AvionicStateFlow_T AvionicStateFlow_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S30>/UD'
   */
  0.0,

  /* Mask Parameter: RepeatingSequenceStair2_OutValu
   * Referenced by: '<S20>/Vector'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: RepeatingSequenceStair1_OutValu
   * Referenced by: '<S19>/Vector'
   */
  { 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S18>/Vector'
   */
  { 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S29>/FixPt Switch'
   */
  9U,

  /* Mask Parameter: LimitedCounter_uplimit_e
   * Referenced by: '<S26>/FixPt Switch'
   */
  7U,

  /* Mask Parameter: LimitedCounter_uplimit_d
   * Referenced by: '<S23>/FixPt Switch'
   */
  7U,

  /* Expression: 0.01
   * Referenced by: '<S1>/Barometer'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S1>/I2C Master Read'
   */
  0.01,

  /* Expression: 30
   * Referenced by: '<S1>/Constant'
   */
  30.0,

  /* Expression: 0.01
   * Referenced by: '<S5>/MPU9250'
   */
  0.01,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S14>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Constant'
   */
  0.0,

  /* Expression: 273.15
   * Referenced by: '<S1>/Constant3'
   */
  273.15,

  /* Expression: 0
   * Referenced by: '<S7>/Rate Transition3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition3'
   */
  0.0,

  /* Expression: 9.806
   * Referenced by: '<S4>/Constant4'
   */
  9.806,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S30>/TSamp'
   */
  5.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S1>/Gain'
   */
  16384,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S23>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S26>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_ou
   * Referenced by: '<S29>/Constant'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S1>/Manual Switch'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S27>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S28>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_c
   * Referenced by: '<S24>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_c
   * Referenced by: '<S25>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition_i
   * Referenced by: '<S21>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value_n
   * Referenced by: '<S22>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
