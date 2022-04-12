/*
 * File: AvionicStateFlow_types.h
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

#ifndef RTW_HEADER_AvionicStateFlow_types_h_
#define RTW_HEADER_AvionicStateFlow_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S5>/MPU9250' */
#include "MW_SVD.h"
#include "MW_I2C.h"
#ifndef struct_tag_oH2PxaXVLCzd6lwdaSR6p
#define struct_tag_oH2PxaXVLCzd6lwdaSR6p

struct tag_oH2PxaXVLCzd6lwdaSR6p
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_oH2PxaXVLCzd6lwdaSR6p */

#ifndef typedef_f_beagleboneblue_bbblueI2CMas_T
#define typedef_f_beagleboneblue_bbblueI2CMas_T

typedef struct tag_oH2PxaXVLCzd6lwdaSR6p f_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_f_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_AVxjDeyQkunEdpGYBzp3BE
#define struct_tag_AVxjDeyQkunEdpGYBzp3BE

struct tag_AVxjDeyQkunEdpGYBzp3BE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  real_T SampleTime;
  f_beagleboneblue_bbblueI2CMas_T i2cObj;
  uint16_T dig_T1;
  int16_T dig_T2;
  int16_T dig_T3;
  uint16_T dig_P1;
  int16_T dig_P2;
  int16_T dig_P3;
  int16_T dig_P4;
  int16_T dig_P5;
  int16_T dig_P6;
  int16_T dig_P7;
  int16_T dig_P8;
  int16_T dig_P9;
  boolean_T BMPConnect;
};

#endif                                 /* struct_tag_AVxjDeyQkunEdpGYBzp3BE */

#ifndef typedef_beagleboneblue_bbblueBaromete_T
#define typedef_beagleboneblue_bbblueBaromete_T

typedef struct tag_AVxjDeyQkunEdpGYBzp3BE beagleboneblue_bbblueBaromete_T;

#endif                             /* typedef_beagleboneblue_bbblueBaromete_T */

#ifndef struct_tag_p5fy1GZKLrNf1h57A2FJaE
#define struct_tag_p5fy1GZKLrNf1h57A2FJaE

struct tag_p5fy1GZKLrNf1h57A2FJaE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_p5fy1GZKLrNf1h57A2FJaE */

#ifndef typedef_beagleboneblue_bbblueI2CMaste_T
#define typedef_beagleboneblue_bbblueI2CMaste_T

typedef struct tag_p5fy1GZKLrNf1h57A2FJaE beagleboneblue_bbblueI2CMaste_T;

#endif                             /* typedef_beagleboneblue_bbblueI2CMaste_T */

#ifndef struct_tag_xLdvsTzAcwQ23cLj0I6KhF
#define struct_tag_xLdvsTzAcwQ23cLj0I6KhF

struct tag_xLdvsTzAcwQ23cLj0I6KhF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_xLdvsTzAcwQ23cLj0I6KhF */

#ifndef typedef_beagleboneblue_bbblueDigitalW_T
#define typedef_beagleboneblue_bbblueDigitalW_T

typedef struct tag_xLdvsTzAcwQ23cLj0I6KhF beagleboneblue_bbblueDigitalW_T;

#endif                             /* typedef_beagleboneblue_bbblueDigitalW_T */

#ifndef struct_tag_oH2PxaXVLCzd6lwdaSR6p
#define struct_tag_oH2PxaXVLCzd6lwdaSR6p

struct tag_oH2PxaXVLCzd6lwdaSR6p
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_oH2PxaXVLCzd6lwdaSR6p */

#ifndef typedef_h_beagleboneblue_bbblueI2CMas_T
#define typedef_h_beagleboneblue_bbblueI2CMas_T

typedef struct tag_oH2PxaXVLCzd6lwdaSR6p h_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_h_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_s0kXae1yCOw6kF09CPTiMB
#define struct_tag_s0kXae1yCOw6kF09CPTiMB

struct tag_s0kXae1yCOw6kF09CPTiMB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_s0kXae1yCOw6kF09CPTiMB */

#ifndef typedef_i_beagleboneblue_bbblueI2CMas_T
#define typedef_i_beagleboneblue_bbblueI2CMas_T

typedef struct tag_s0kXae1yCOw6kF09CPTiMB i_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_i_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_A4EdOul8eEsRYmBAaIUDRF
#define struct_tag_A4EdOul8eEsRYmBAaIUDRF

struct tag_A4EdOul8eEsRYmBAaIUDRF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  h_beagleboneblue_bbblueI2CMas_T i2cObjmpu;
  i_beagleboneblue_bbblueI2CMas_T i2cObjak8963;
};

#endif                                 /* struct_tag_A4EdOul8eEsRYmBAaIUDRF */

#ifndef typedef_beagleboneblue_bbblueMPU9250__T
#define typedef_beagleboneblue_bbblueMPU9250__T

typedef struct tag_A4EdOul8eEsRYmBAaIUDRF beagleboneblue_bbblueMPU9250__T;

#endif                             /* typedef_beagleboneblue_bbblueMPU9250__T */

#ifndef struct_tag_fYOEcv5C5Uqf6zenXgF1HG
#define struct_tag_fYOEcv5C5Uqf6zenXgF1HG

struct tag_fYOEcv5C5Uqf6zenXgF1HG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_fYOEcv5C5Uqf6zenXgF1HG */

#ifndef typedef_beagleboneblue_bbblueLED_Avio_T
#define typedef_beagleboneblue_bbblueLED_Avio_T

typedef struct tag_fYOEcv5C5Uqf6zenXgF1HG beagleboneblue_bbblueLED_Avio_T;

#endif                             /* typedef_beagleboneblue_bbblueLED_Avio_T */

/* Parameters (default storage) */
typedef struct P_AvionicStateFlow_T_ P_AvionicStateFlow_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_AvionicStateFlow_T RT_MODEL_AvionicStateFlow_T;

#endif                                /* RTW_HEADER_AvionicStateFlow_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
