/*
 * AvionicStateFlow_dt.h
 *
 * Code generation for model "AvionicStateFlow".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Apr  5 13:52:32 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(void*),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int16_T),
  sizeof(beagleboneblue_bbblueBaromete_T),
  sizeof(beagleboneblue_bbblueI2CMaste_T),
  sizeof(beagleboneblue_bbblueDigitalW_T),
  sizeof(beagleboneblue_bbblueMPU9250__T),
  sizeof(beagleboneblue_bbblueLED_Avio_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "int16_T",
  "beagleboneblue_bbblueBaromete_T",
  "beagleboneblue_bbblueI2CMaste_T",
  "beagleboneblue_bbblueDigitalW_T",
  "beagleboneblue_bbblueMPU9250__T",
  "beagleboneblue_bbblueLED_Avio_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&AvionicStateFlow_B.ManualSwitch), 0, 0, 23 }
  ,

  { (char_T *)(&AvionicStateFlow_DW.obj), 15, 0, 1 },

  { (char_T *)(&AvionicStateFlow_DW.obj_f), 18, 0, 1 },

  { (char_T *)(&AvionicStateFlow_DW.obj_i), 16, 0, 1 },

  { (char_T *)(&AvionicStateFlow_DW.obj_k), 17, 0, 2 },

  { (char_T *)(&AvionicStateFlow_DW.obj_d), 19, 0, 1 },

  { (char_T *)(&AvionicStateFlow_DW.UD_DSTATE), 0, 0, 18 },

  { (char_T *)(&AvionicStateFlow_DW.Scope_PWORK.LoggedData[0]), 11, 0, 10 },

  { (char_T *)(&AvionicStateFlow_DW.is_c3_AvionicStateFlow), 7, 0, 1 },

  { (char_T *)(&AvionicStateFlow_DW.temporalCounter_i1), 5, 0, 1 },

  { (char_T *)(&AvionicStateFlow_DW.Output_DSTATE), 3, 0, 3 },

  { (char_T *)(&AvionicStateFlow_DW.IfActionSubsystem2_SubsysRanBC), 2, 0, 5 },

  { (char_T *)(&AvionicStateFlow_DW.is_active_c3_AvionicStateFlow), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&AvionicStateFlow_P.DiscreteDerivative_ICPrevScaled), 0, 0, 27 },

  { (char_T *)(&AvionicStateFlow_P.LimitedCounter_uplimit), 3, 0, 3 },

  { (char_T *)(&AvionicStateFlow_P.Barometer_SampleTime), 0, 0, 15 },

  { (char_T *)(&AvionicStateFlow_P.Gain_Gain), 14, 0, 1 },

  { (char_T *)(&AvionicStateFlow_P.Constant_Value_g), 3, 0, 10 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] AvionicStateFlow_dt.h */
