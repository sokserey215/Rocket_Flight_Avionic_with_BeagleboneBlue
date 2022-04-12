/*
 * File: AvionicStateFlow_private.h
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

#ifndef RTW_HEADER_AvionicStateFlow_private_h_
#define RTW_HEADER_AvionicStateFlow_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern real_T rt_roundd_snf(real_T u);
extern void sMultiWord2sMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T
  y[], int32_T n);
extern void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void sMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n);
extern void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n);
extern void sMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
extern boolean_T sMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
extern real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern void MultiWordNeg(const uint32_T u1[], uint32_T y[], int32_T n);
extern boolean_T uMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern void uMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void MultiWordAnd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern boolean_T uMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern boolean_T uMultiWordNe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern void uMultiWordDivZero(const uint32_T u1[], int32_T n1, const uint32_T
  u2[], int32_T n2, uint32_T y1[], int32_T m1, uint32_T y2[], int32_T m2,
  uint32_T t1[], int32_T l1, uint32_T t2[], int32_T l2);
extern void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n);
extern void MultiWordSetUnsignedMax(uint32_T y[], int32_T n);
extern int32_T uMultiWordDiv(uint32_T a[], int32_T na, uint32_T b[], int32_T nb,
  uint32_T q[], int32_T nq, uint32_T r[], int32_T nr);
extern void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern boolean_T uMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern int32_T div_s32(int32_T numerator, int32_T denominator);

#endif                              /* RTW_HEADER_AvionicStateFlow_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
