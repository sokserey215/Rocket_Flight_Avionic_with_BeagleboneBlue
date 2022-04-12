/*
 * File: AvionicStateFlow.c
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
#include "AvionicStateFlow_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define AvionicStateFlo_IN_ApogeeDetect (1U)
#define AvionicStateFlo_IN_LaunchDetect (3U)
#define AvionicStateFlow_IN_Droping    (2U)
#define AvionicStateFlow_IN_OnLaunchPad (4U)
#define AvionicStateFlow_IN_TouchDown  (5U)

/* Block signals (default storage) */
B_AvionicStateFlow_T AvionicStateFlow_B;

/* Block states (default storage) */
DW_AvionicStateFlow_T AvionicStateFlow_DW;

/* Real-time model */
static RT_MODEL_AvionicStateFlow_T AvionicStateFlow_M_;
RT_MODEL_AvionicStateFlow_T *const AvionicStateFlow_M = &AvionicStateFlow_M_;

/* Forward declaration for local functions */
static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1);
static int64m_T AvionicStateFlow_i64ddiv(real_T x, const int64m_T y);
static uint64m_T AvionicSta_eml_mixed_uint64_mul(const uint64m_T nv, real_T y);
static int64m_T AvionicStateFlow_times(real_T x, const int64m_T y);
static real_T Avioni_bbblueBarometer_stepImpl(const
  beagleboneblue_bbblueBaromete_T *obj);
static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj);
static void AvionicStateFl_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj);
static void AvionicState_SystemCore_setup_e(beagleboneblue_bbblueMPU9250__T *obj);
static void rate_monotonic_scheduler(void);
void sMultiWord2sMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n)
{
  int32_T i;
  int32_T nm1;
  uint32_T ys;
  boolean_T doSaturation = false;
  nm1 = n - 1;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (n1 > n) {
    doSaturation = (((u1[n1 - 1] ^ u1[n - 1]) & 2147483648U) != 0U);
    i = n1 - 1;
    while ((!doSaturation) && (i >= n)) {
      doSaturation = (u1[i] != ys);
      i--;
    }
  }

  if (doSaturation) {
    ys = ~ys;
    for (i = 0; i < nm1; i++) {
      y[i] = ys;
    }

    y[i] = ys ^ 2147483648U;
  } else {
    nm1 = n1 < n ? n1 : n;
    for (i = 0; i < nm1; i++) {
      y[i] = u1[i];
    }

    while (i < n) {
      y[i] = ys;
      i++;
    }
  }
}

void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T borrow = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i - u2[i]) - borrow;
    y[i] = yi;
    borrow = borrow != 0U ? (uint32_T)(yi >= u1i) : (uint32_T)(yi > u1i);
  }
}

void sMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  int32_T i;
  int32_T nm;
  uint32_T u1i;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    u1i = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
    for (i = nm; i < n; i++) {
      y[i] = u1i;
    }
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T carry = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T i1;
  int32_T nb;
  int32_T nc;
  uint32_T nr;
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  uint32_T yi;
  y[0] = (uint32_T)u;
  yi = u < 0 ? MAX_uint32_T : 0U;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

void sMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T nb;
  int32_T nc;
  uint32_T nl;
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0U;
  }
}

boolean_T sMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) == 0;
}

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T i;
  int32_T y;
  uint32_T su1;
  uint32_T u2i;
  su1 = u1[n - 1] & 2147483648U;
  if ((u2[n - 1] & 2147483648U) != su1) {
    y = su1 != 0U ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) < 0;
}

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0;
}

boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) > 0;
}

void MultiWordNeg(const uint32_T u1[], uint32_T y[], int32_T n)
{
  int32_T i;
  uint32_T carry = 1U;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    yi = ~u1[i] + carry;
    y[i] = yi;
    carry = (uint32_T)(yi < carry);
  }
}

boolean_T uMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) == 0;
}

int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T i;
  int32_T y;
  uint32_T u1i;
  uint32_T u2i;
  y = 0;
  i = n;
  while ((y == 0) && (i > 0)) {
    i--;
    u1i = u1[i];
    u2i = u2[i];
    if (u1i != u2i) {
      y = u1i > u2i ? 1 : -1;
    }
  }

  return y;
}

void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  real_T yd;
  real_T yn;
  int32_T currExp;
  int32_T i;
  int32_T msl;
  int32_T prevExp;
  uint32_T cb;
  uint32_T u1i;
  boolean_T isNegative;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : div_s32(currExp - 1, 32);
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = 32 * msl;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)(cb < u1i);
    }
  }
}

boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) > 0;
}

void uMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T i1;
  int32_T nb;
  int32_T nc;
  uint32_T nr;
  uint32_T u1i;
  uint32_T yi;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (32U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0U;
    i++;
  }
}

void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T nb;
  int32_T nc;
  uint32_T nl;
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void MultiWordAnd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  for (i = 0; i < n; i++) {
    y[i] = u1[i] & u2[i];
  }
}

boolean_T uMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) >= 0;
}

boolean_T uMultiWordNe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) != 0;
}

void uMultiWordDivZero(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y1[], int32_T m1, uint32_T y2[], int32_T m2, uint32_T t1[],
  int32_T l1, uint32_T t2[], int32_T l2)
{
  uMultiWord2MultiWord(u1, n1, t1, l1);
  uMultiWord2MultiWord(u2, n2, t2, l2);
  if (uMultiWordDiv(t1, l1, t2, l2, y1, m1, y2, m2) < 0) {
    MultiWordSetUnsignedMax(y1, m1);
  }
}

void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  int32_T i;
  int32_T nm;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0U;
    }
  }
}

void MultiWordSetUnsignedMax(uint32_T y[], int32_T n)
{
  int32_T i;
  for (i = 0; i < n; i++) {
    y[i] = MAX_uint32_T;
  }
}

int32_T uMultiWordDiv(uint32_T a[], int32_T na, uint32_T b[], int32_T nb,
                      uint32_T q[], int32_T nq, uint32_T r[], int32_T nr)
{
  int32_T ka;
  int32_T kr;
  int32_T na1;
  int32_T nb1;
  int32_T nza;
  int32_T nzb;
  int32_T tpi;
  int32_T y;
  uint32_T ak;
  uint32_T bk;
  uint32_T kba;
  uint32_T kbb;
  uint32_T mask;
  uint32_T nba;
  uint32_T nbb;
  uint32_T nbq;
  uint32_T t;
  uint32_T tnb;
  nzb = nb;
  tpi = nb - 1;
  while ((nzb > 0) && (b[tpi] == 0U)) {
    nzb--;
    tpi--;
  }

  if (nzb > 0) {
    nza = na;
    for (tpi = 0; tpi < nq; tpi++) {
      q[tpi] = 0U;
    }

    tpi = na - 1;
    while ((nza > 0) && (a[tpi] == 0U)) {
      nza--;
      tpi--;
    }

    if ((nza > 0) && (nza >= nzb)) {
      nb1 = nzb - 1;
      na1 = nza - 1;
      for (kr = 0; kr < nr; kr++) {
        r[kr] = 0U;
      }

      /* Quick return if dividend and divisor fit into single word. */
      if (nza == 1) {
        ak = a[0];
        bk = b[0];
        nbq = ak / bk;
        q[0] = nbq;
        r[0] = ak - nbq * bk;
        y = 7;
      } else {
        /* Remove leading zeros from both, dividend and divisor. */
        kbb = 1U;
        t = b[nzb - 1] >> 1U;
        while (t != 0U) {
          kbb++;
          t >>= 1U;
        }

        kba = 1U;
        t = a[nza - 1] >> 1U;
        while (t != 0U) {
          kba++;
          t >>= 1U;
        }

        /* Quick return if quotient is zero. */
        if ((nza > nzb) || (kba >= kbb)) {
          nba = ((uint32_T)(nza - 1) << 5) + kba;
          nbb = ((uint32_T)(nzb - 1) << 5) + kbb;

          /* Normalize b. */
          if (kbb != 32U) {
            bk = b[nzb - 1];
            for (kr = nzb - 1; kr > 0; kr--) {
              t = bk << (32U - kbb);
              bk = b[kr - 1];
              t |= bk >> kbb;
              b[kr] = t;
            }

            b[kr] = bk << (32U - kbb);
            mask = ~((1U << (32U - kbb)) - 1U);
          } else {
            mask = MAX_uint32_T;
          }

          /* Initialize quotient to zero. */
          tnb = 0U;
          y = 0;

          /* Until exit conditions have been met, do */
          do {
            /* Normalize a */
            if (kba != 32U) {
              tnb = (tnb - kba) + 32U;
              ak = a[na1];
              for (ka = na1; ka > 0; ka--) {
                t = ak << (32U - kba);
                ak = a[ka - 1];
                t |= ak >> kba;
                a[ka] = t;
              }

              a[ka] = ak << (32U - kba);
            }

            /* Compare b against the a. */
            ak = a[na1];
            bk = b[nzb - 1];
            if (((nzb - 1 == 0 ? mask : MAX_uint32_T) & ak) == bk) {
              tpi = 0;
              ka = na1;
              kr = nzb - 1;
              while ((tpi == 0) && (kr > 0)) {
                ka--;
                ak = a[ka];
                kr--;
                bk = b[kr];
                if (((kr == 0 ? mask : MAX_uint32_T) & ak) != bk) {
                  tpi = ak > bk ? 1 : -1;
                }
              }
            } else {
              tpi = ak > bk ? 1 : -1;
            }

            /* If the remainder in a is still greater or equal to b, subtract normalized divisor from a. */
            if ((tpi >= 0) || (nba > nbb)) {
              nbq = nba - nbb;

              /* If the remainder and the divisor are equal, set remainder to zero. */
              if (tpi == 0) {
                ka = na1;
                for (kr = nzb - 1; kr > 0; kr--) {
                  a[ka] = 0U;
                  ka--;
                }

                a[ka] -= b[kr];
              } else {
                /* Otherwise, subtract the divisor from the remainder */
                if (tpi < 0) {
                  ak = a[na1];
                  kba = 31U;
                  for (ka = na1; ka > 0; ka--) {
                    t = ak << 1U;
                    ak = a[ka - 1];
                    t |= ak >> 31U;
                    a[ka] = t;
                  }

                  a[ka] = ak << 1U;
                  tnb++;
                  nbq--;
                }

                bk = 0U;
                ka = (na1 - nzb) + 1;
                for (kr = 0; kr < nzb; kr++) {
                  t = a[ka];
                  ak = (t - b[kr]) - bk;
                  bk = bk != 0U ? (uint32_T)(ak >= t) : (uint32_T)(ak > t);
                  a[ka] = ak;
                  ka++;
                }
              }

              /* Update the quotient. */
              tpi = (int32_T)(nbq >> 5);
              q[tpi] |= 1U << (nbq - ((uint32_T)tpi << 5));

              /* Remove leading zeros from the remainder and check whether the exit conditions have been met. */
              tpi = na1;
              while ((nza > 0) && (a[tpi] == 0U)) {
                nza--;
                tpi--;
              }

              if (nza >= nzb) {
                na1 = nza - 1;
                kba = 1U;
                t = a[nza - 1] >> 1U;
                while (t != 0U) {
                  kba++;
                  t >>= 1U;
                }

                nba = (((uint32_T)(nza - 1) << 5) + kba) - tnb;
                if (nba < nbb) {
                  y = 2;
                }
              } else if (nza == 0) {
                y = 1;
              } else {
                na1 = nza - 1;
                y = 4;
              }
            } else {
              y = 3;
            }
          } while (y == 0);

          /* Return the remainder. */
          if (y == 1) {
            r[0] = a[0];
          } else {
            tpi = (int32_T)(tnb >> 5);
            nbq = tnb - ((uint32_T)tpi << 5);
            if (nbq == 0U) {
              ka = tpi;
              for (kr = 0; kr <= nb1; kr++) {
                r[kr] = a[ka];
                ka++;
              }
            } else {
              ak = a[tpi];
              kr = 0;
              for (ka = tpi + 1; ka <= na1; ka++) {
                t = ak >> nbq;
                ak = a[ka];
                t |= ak << (32U - nbq);
                r[kr] = t;
                kr++;
              }

              r[kr] = ak >> nbq;
            }
          }

          /* Restore b. */
          if (kbb != 32U) {
            bk = b[0];
            for (kr = 0; kr < nb1; kr++) {
              t = bk >> (32U - kbb);
              bk = b[kr + 1];
              t |= bk << kbb;
              b[kr] = t;
            }

            b[kr] = bk >> (32U - kbb);
          }
        } else {
          for (kr = 0; kr < nr; kr++) {
            r[kr] = a[kr];
          }

          y = 6;
        }
      }
    } else {
      for (kr = 0; kr < nr; kr++) {
        r[kr] = a[kr];
      }

      y = 5;
    }
  } else {
    y = -1;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

boolean_T uMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) <= 0;
}

int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    tempAbsQuotient = (numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
                       numerator) / (denominator < 0 ? ~(uint32_T)denominator +
      1U : (uint32_T)denominator);
    quotient = (numerator < 0) != (denominator < 0) ? -(int32_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void AvionicStateFlow_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(AvionicStateFlow_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(AvionicStateFlow_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2 */
  AvionicStateFlow_M->Timing.RateInteraction.TID0_1 =
    (AvionicStateFlow_M->Timing.TaskCounters.TID[1] == 0);
  AvionicStateFlow_M->Timing.RateInteraction.TID0_2 =
    (AvionicStateFlow_M->Timing.TaskCounters.TID[2] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (AvionicStateFlow_M->Timing.TaskCounters.TID[1])++;
  if ((AvionicStateFlow_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    AvionicStateFlow_M->Timing.TaskCounters.TID[1] = 0;
  }

  (AvionicStateFlow_M->Timing.TaskCounters.TID[2])++;
  if ((AvionicStateFlow_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.2s, 0.0s] */
    AvionicStateFlow_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1)
{
  int32_T i;
  uint8_T output_raw[6];
  uint8_T Data;
  uint8_T SwappedDataBytes;
  Data = 247U;
  memcpy((void *)&SwappedDataBytes, (void *)&Data, (uint32_T)((size_t)1 * sizeof
          (uint8_T)));
  *varargout_1 = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
    &SwappedDataBytes, 1U, true, false);
  if (0 == *varargout_1) {
    *varargout_1 = MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U,
      &output_raw[0], 6U, false, true);
    memcpy((void *)&RegisterValue[0], (void *)&output_raw[0], (uint32_T)((size_t)
            6 * sizeof(uint8_T)));
  } else {
    for (i = 0; i < 6; i++) {
      RegisterValue[i] = 0U;
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static int64m_T AvionicStateFlow_i64ddiv(real_T x, const int64m_T y)
{
  int64m_T z;
  uint64m_T tmp;
  int32_T firstbitn;
  int32_T shiftAmount;
  int32_T xexp;
  boolean_T b_isQuotNegative;
  boolean_T b_p;
  static const uint64m_T tmp_0 = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_1 = { { 1U, 0U }/* chunks */
  };

  static const int64m_T tmp_2 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_3 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const uint64m_T tmp_4 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_5 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const int64m_T tmp_6 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_7 = { { 0U, 2147483648U }/* chunks */
  };

  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T guard1 = false;
  boolean_T guard11 = false;
  boolean_T guard2 = false;
  if (x == 0.0) {
    memcpy((void *)&AvionicStateFlow_B.ux[0], (void *)&x, (uint32_T)((size_t)2 *
            sizeof(uint32_T)));
    if ((AvionicStateFlow_B.ux[0] != 0U) || (AvionicStateFlow_B.ux[1] != 0U)) {
      b_p = true;
    } else {
      b_p = false;
    }
  } else {
    b_p = false;
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x >= 0.0) && (!b_p))
      || (sMultiWordGe(&y.chunks[0U], &tmp_2.chunks[0U], 2) && ((x < 0.0) || b_p)))
  {
    b_isQuotNegative = true;
  } else {
    b_isQuotNegative = false;
  }

  if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
    if (sMultiWordGt(&y.chunks[0U], &tmp_7.chunks[0U], 2)) {
      AvionicStateFlow_B.r25 = y;
      MultiWordNeg(&y.chunks[0U], &AvionicStateFlow_B.r24.chunks[0U], 2);
      sMultiWord2MultiWord(&AvionicStateFlow_B.r24.chunks[0U], 2,
                           &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2);
    } else {
      AvionicStateFlow_B.nk_unsgn = tmp_0;
    }
  } else {
    sMultiWord2MultiWord(&y.chunks[0U], 2, &AvionicStateFlow_B.nk_unsgn.chunks
                         [0U], 2);
  }

  if ((x < 0.0) || b_p) {
    AvionicStateFlow_B.x_unsgn = -x;
  } else {
    AvionicStateFlow_B.x_unsgn = x;
  }

  if (uMultiWordEq(&AvionicStateFlow_B.nk_unsgn.chunks[0U], &tmp_4.chunks[0U], 2))
  {
    if (AvionicStateFlow_B.x_unsgn > 0.0) {
      AvionicStateFlow_B.res = tmp_5;
    } else {
      AvionicStateFlow_B.res = tmp_4;
    }
  } else if ((AvionicStateFlow_B.x_unsgn <= 0.0) || rtIsNaN
             (AvionicStateFlow_B.x_unsgn)) {
    AvionicStateFlow_B.res = tmp_4;
  } else if (rtIsInf(AvionicStateFlow_B.x_unsgn)) {
    AvionicStateFlow_B.res = tmp_5;
  } else {
    AvionicStateFlow_B.x_unsgn = frexp(AvionicStateFlow_B.x_unsgn, &shiftAmount);
    Double2MultiWord(rt_roundd_snf(AvionicStateFlow_B.x_unsgn *
      9.007199254740992E+15), &AvionicStateFlow_B.xint.chunks[0U], 2);
    xexp = shiftAmount - 53;
    firstbitn = 63;
    do {
      exitg1 = 0;
      uMultiWordShr(&AvionicStateFlow_B.nk_unsgn.chunks[0U], 2, (uint32_T)
                    firstbitn, &AvionicStateFlow_B.res.chunks[0U], 2);
      if (uMultiWordGt(&AvionicStateFlow_B.res.chunks[0U], &tmp_4.chunks[0U], 2))
      {
        exitg1 = 1;
      } else {
        firstbitn--;
      }
    } while (exitg1 == 0);

    if (shiftAmount - 53 < firstbitn - 53) {
      AvionicStateFlow_B.res = tmp_4;
    } else if (shiftAmount - 53 > firstbitn + 12) {
      AvionicStateFlow_B.res = tmp_5;
    } else {
      AvionicStateFlow_B.res = tmp_4;
      guard1 = false;
      guard2 = false;
      if (firstbitn < 63) {
        uMultiWordDivZero(&AvionicStateFlow_B.xint.chunks[0U], 2,
                          &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2,
                          &AvionicStateFlow_B.res.chunks[0U], 2,
                          &AvionicStateFlow_B.r26.chunks[0U], 2,
                          &AvionicStateFlow_B.r27.chunks[0U], 2,
                          &AvionicStateFlow_B.r28.chunks[0U], 2);
        if (!uMultiWordEq(&AvionicStateFlow_B.nk_unsgn.chunks[0U],
                          &tmp_4.chunks[0U], 2)) {
          uMultiWordDivZero(&AvionicStateFlow_B.xint.chunks[0U], 2,
                            &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2,
                            &AvionicStateFlow_B.r28.chunks[0U], 2,
                            &AvionicStateFlow_B.r29.chunks[0U], 2,
                            &AvionicStateFlow_B.r30.chunks[0U], 2,
                            &AvionicStateFlow_B.r31.chunks[0U], 2);
          uMultiWordMul(&AvionicStateFlow_B.r28.chunks[0U], 2,
                        &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2,
                        &AvionicStateFlow_B.r2.chunks[0U], 4);
          uMultiWord2MultiWord(&AvionicStateFlow_B.r2.chunks[0U], 4,
                               &AvionicStateFlow_B.r27.chunks[0U], 2);
          MultiWordSub(&AvionicStateFlow_B.xint.chunks[0U],
                       &AvionicStateFlow_B.r27.chunks[0U],
                       &AvionicStateFlow_B.r28.chunks[0U], 2);
          AvionicStateFlow_B.xint = AvionicStateFlow_B.r28;
        }

        if (shiftAmount - 53 < 0) {
          uMultiWordShr(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)(53 -
            shiftAmount), &tmp.chunks[0U], 2);
          uMultiWordShr(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)(52 -
            shiftAmount), &AvionicStateFlow_B.r39.chunks[0U], 2);
          MultiWordAnd(&AvionicStateFlow_B.r39.chunks[0U], &tmp_1.chunks[0U],
                       &AvionicStateFlow_B.r38.chunks[0U], 2);
          MultiWordAdd(&tmp.chunks[0U], &AvionicStateFlow_B.r38.chunks[0U],
                       &AvionicStateFlow_B.res.chunks[0U], 2);
        } else {
          do {
            exitg2 = 0;
            if (xexp > 0) {
              if (63 - firstbitn > xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              uMultiWordShr(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)(64
                - shiftAmount), &AvionicStateFlow_B.r29.chunks[0U], 2);
              if (uMultiWordGt(&AvionicStateFlow_B.r29.chunks[0U],
                               &tmp_4.chunks[0U], 2)) {
                AvionicStateFlow_B.res = tmp_5;
                exitg2 = 1;
              } else {
                uMultiWordShl(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &AvionicStateFlow_B.r32.chunks[0U], 2);
                xexp -= shiftAmount;
                uMultiWordShl(&AvionicStateFlow_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &AvionicStateFlow_B.r33.chunks[0U], 2);
                AvionicStateFlow_B.xint = AvionicStateFlow_B.r33;
                uMultiWordDivZero(&AvionicStateFlow_B.r33.chunks[0U], 2,
                                  &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2,
                                  &AvionicStateFlow_B.nIsOdd.chunks[0U], 2,
                                  &AvionicStateFlow_B.r34.chunks[0U], 2,
                                  &AvionicStateFlow_B.r35.chunks[0U], 2,
                                  &AvionicStateFlow_B.r36.chunks[0U], 2);
                AvionicStateFlow_B.r35 = tmp_5;
                MultiWordSub(&tmp_5.chunks[0U],
                             &AvionicStateFlow_B.nIsOdd.chunks[0U],
                             &AvionicStateFlow_B.r34.chunks[0U], 2);
                if (uMultiWordLe(&AvionicStateFlow_B.r34.chunks[0U],
                                 &AvionicStateFlow_B.r32.chunks[0U], 2)) {
                  AvionicStateFlow_B.res = tmp_5;
                  exitg2 = 1;
                } else {
                  MultiWordAdd(&AvionicStateFlow_B.r32.chunks[0U],
                               &AvionicStateFlow_B.nIsOdd.chunks[0U],
                               &AvionicStateFlow_B.r35.chunks[0U], 2);
                  AvionicStateFlow_B.res = AvionicStateFlow_B.r35;
                  AvionicStateFlow_B.r36 = tmp_4;
                  if (!uMultiWordEq(&AvionicStateFlow_B.nk_unsgn.chunks[0U],
                                    &tmp_4.chunks[0U], 2)) {
                    uMultiWordDivZero(&AvionicStateFlow_B.r33.chunks[0U], 2,
                                      &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2,
                                      &AvionicStateFlow_B.r37.chunks[0U], 2,
                                      &AvionicStateFlow_B.r38.chunks[0U], 2,
                                      &AvionicStateFlow_B.r39.chunks[0U], 2,
                                      &AvionicStateFlow_B.r40.chunks[0U], 2);
                    uMultiWordMul(&AvionicStateFlow_B.r37.chunks[0U], 2,
                                  &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2,
                                  &AvionicStateFlow_B.r2.chunks[0U], 4);
                    uMultiWord2MultiWord(&AvionicStateFlow_B.r2.chunks[0U], 4,
                                         &tmp.chunks[0U], 2);
                    MultiWordSub(&AvionicStateFlow_B.r33.chunks[0U],
                                 &tmp.chunks[0U],
                                 &AvionicStateFlow_B.r37.chunks[0U], 2);
                    AvionicStateFlow_B.xint = AvionicStateFlow_B.r37;
                  }
                }
              }
            } else {
              uMultiWordShl(&AvionicStateFlow_B.xint.chunks[0U], 2, 1U,
                            &AvionicStateFlow_B.r27.chunks[0U], 2);
              if (uMultiWordGe(&AvionicStateFlow_B.r27.chunks[0U],
                               &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2)) {
                MultiWordAdd(&AvionicStateFlow_B.res.chunks[0U], &tmp_1.chunks
                             [0U], &AvionicStateFlow_B.r30.chunks[0U], 2);
                AvionicStateFlow_B.res = AvionicStateFlow_B.r30;
              }

              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }
      } else if (shiftAmount - 53 > 10) {
        uMultiWordShl(&AvionicStateFlow_B.xint.chunks[0U], 2, 11U,
                      &AvionicStateFlow_B.r26.chunks[0U], 2);
        AvionicStateFlow_B.xint = AvionicStateFlow_B.r26;
        xexp = shiftAmount - 64;
        AvionicStateFlow_B.r26 = tmp_1;
        MultiWordAnd(&AvionicStateFlow_B.nk_unsgn.chunks[0U], &tmp_1.chunks[0U],
                     &AvionicStateFlow_B.nIsOdd.chunks[0U], 2);
        if (uMultiWordGe(&AvionicStateFlow_B.xint.chunks[0U],
                         &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2)) {
          AvionicStateFlow_B.res = tmp_1;
          MultiWordSub(&AvionicStateFlow_B.xint.chunks[0U],
                       &AvionicStateFlow_B.nk_unsgn.chunks[0U],
                       &AvionicStateFlow_B.r27.chunks[0U], 2);
          AvionicStateFlow_B.xint = AvionicStateFlow_B.r27;
        } else if (shiftAmount - 64 > 0) {
          xexp = shiftAmount - 65;
          AvionicStateFlow_B.res = tmp_1;
          uMultiWordShr(&AvionicStateFlow_B.nk_unsgn.chunks[0U], 2, 1U,
                        &AvionicStateFlow_B.r27.chunks[0U], 2);
          MultiWordSub(&AvionicStateFlow_B.xint.chunks[0U],
                       &AvionicStateFlow_B.r27.chunks[0U],
                       &AvionicStateFlow_B.r26.chunks[0U], 2);
          uMultiWordShl(&AvionicStateFlow_B.r26.chunks[0U], 2, 1U,
                        &AvionicStateFlow_B.xint.chunks[0U], 2);
          if (uMultiWordNe(&AvionicStateFlow_B.nIsOdd.chunks[0U], &tmp_4.chunks
                           [0U], 2)) {
            MultiWordSub(&AvionicStateFlow_B.xint.chunks[0U], &tmp_1.chunks[0U],
                         &AvionicStateFlow_B.r28.chunks[0U], 2);
            AvionicStateFlow_B.xint = AvionicStateFlow_B.r28;
          }
        }

        do {
          exitg1 = 0;
          if (xexp > 0) {
            if (uMultiWordEq(&AvionicStateFlow_B.xint.chunks[0U], &tmp_4.chunks
                             [0U], 2)) {
              uMultiWordShr(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)(64
                - xexp), &AvionicStateFlow_B.r40.chunks[0U], 2);
              if (uMultiWordGt(&AvionicStateFlow_B.r40.chunks[0U],
                               &tmp_4.chunks[0U], 2)) {
                AvionicStateFlow_B.res = tmp_5;
                exitg1 = 1;
              } else {
                uMultiWordShl(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)
                              xexp, &tmp.chunks[0U], 2);
                AvionicStateFlow_B.res = tmp;
                xexp = 0;
              }
            } else {
              firstbitn = 63;
              do {
                exitg3 = 0;
                uMultiWordShr(&AvionicStateFlow_B.xint.chunks[0U], 2, (uint32_T)
                              firstbitn, &AvionicStateFlow_B.r32.chunks[0U], 2);
                if (uMultiWordGt(&AvionicStateFlow_B.r32.chunks[0U],
                                 &tmp_4.chunks[0U], 2)) {
                  exitg3 = 1;
                } else {
                  firstbitn--;
                }
              } while (exitg3 == 0);

              if (63 - firstbitn >= xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              guard11 = false;
              if (shiftAmount != 0) {
                uMultiWordShr(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)
                              (64 - shiftAmount),
                              &AvionicStateFlow_B.r33.chunks[0U], 2);
                if (uMultiWordGt(&AvionicStateFlow_B.r33.chunks[0U],
                                 &tmp_4.chunks[0U], 2)) {
                  AvionicStateFlow_B.res = tmp_5;
                  exitg1 = 1;
                } else {
                  guard11 = true;
                }
              } else {
                guard11 = true;
              }

              if (guard11) {
                uMultiWordShl(&AvionicStateFlow_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &AvionicStateFlow_B.r34.chunks[0U], 2);
                AvionicStateFlow_B.res = AvionicStateFlow_B.r34;
                xexp -= shiftAmount;
                uMultiWordShl(&AvionicStateFlow_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &AvionicStateFlow_B.r35.chunks[0U], 2);
                AvionicStateFlow_B.xint = AvionicStateFlow_B.r35;
                if (uMultiWordGt(&AvionicStateFlow_B.xint.chunks[0U],
                                 &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2)) {
                  AvionicStateFlow_B.r26 = tmp_1;
                  MultiWordAdd(&AvionicStateFlow_B.r34.chunks[0U],
                               &tmp_1.chunks[0U],
                               &AvionicStateFlow_B.r39.chunks[0U], 2);
                  AvionicStateFlow_B.res = AvionicStateFlow_B.r39;
                  MultiWordSub(&AvionicStateFlow_B.xint.chunks[0U],
                               &AvionicStateFlow_B.nk_unsgn.chunks[0U],
                               &AvionicStateFlow_B.r26.chunks[0U], 2);
                  AvionicStateFlow_B.xint = AvionicStateFlow_B.r26;
                } else if (xexp > 0) {
                  xexp--;
                  uMultiWordShr(&AvionicStateFlow_B.r34.chunks[0U], 2, 63U,
                                &AvionicStateFlow_B.r36.chunks[0U], 2);
                  if (uMultiWordGt(&AvionicStateFlow_B.r36.chunks[0U],
                                   &tmp_4.chunks[0U], 2)) {
                    AvionicStateFlow_B.res = tmp_5;
                    exitg1 = 1;
                  } else {
                    uMultiWordShl(&AvionicStateFlow_B.r34.chunks[0U], 2, 1U,
                                  &AvionicStateFlow_B.r37.chunks[0U], 2);
                    AvionicStateFlow_B.r26 = tmp_1;
                    MultiWordAdd(&AvionicStateFlow_B.r37.chunks[0U],
                                 &tmp_1.chunks[0U],
                                 &AvionicStateFlow_B.res.chunks[0U], 2);
                    uMultiWordShr(&AvionicStateFlow_B.nk_unsgn.chunks[0U], 2, 1U,
                                  &AvionicStateFlow_B.r26.chunks[0U], 2);
                    MultiWordSub(&AvionicStateFlow_B.xint.chunks[0U],
                                 &AvionicStateFlow_B.r26.chunks[0U],
                                 &AvionicStateFlow_B.r37.chunks[0U], 2);
                    uMultiWordShl(&AvionicStateFlow_B.r37.chunks[0U], 2, 1U,
                                  &AvionicStateFlow_B.xint.chunks[0U], 2);
                    AvionicStateFlow_B.r37 = tmp_4;
                    if (uMultiWordNe(&AvionicStateFlow_B.nIsOdd.chunks[0U],
                                     &tmp_4.chunks[0U], 2)) {
                      MultiWordSub(&AvionicStateFlow_B.xint.chunks[0U],
                                   &tmp_1.chunks[0U],
                                   &AvionicStateFlow_B.r38.chunks[0U], 2);
                      AvionicStateFlow_B.xint = AvionicStateFlow_B.r38;
                    }
                  }
                }
              }
            }
          } else {
            guard2 = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        uMultiWordShl(&AvionicStateFlow_B.xint.chunks[0U], 2, 10U,
                      &AvionicStateFlow_B.r26.chunks[0U], 2);
        AvionicStateFlow_B.xint = AvionicStateFlow_B.r26;
        guard2 = true;
      }

      if (guard2) {
        MultiWordAnd(&AvionicStateFlow_B.xint.chunks[0U], &tmp_0.chunks[0U],
                     &AvionicStateFlow_B.r29.chunks[0U], 2);
        if (uMultiWordNe(&AvionicStateFlow_B.r29.chunks[0U], &tmp_4.chunks[0U],
                         2)) {
          guard1 = true;
        } else {
          uMultiWordShl(&AvionicStateFlow_B.xint.chunks[0U], 2, 1U,
                        &AvionicStateFlow_B.r30.chunks[0U], 2);
          if (uMultiWordGe(&AvionicStateFlow_B.r30.chunks[0U],
                           &AvionicStateFlow_B.nk_unsgn.chunks[0U], 2)) {
            guard1 = true;
          }
        }
      }

      if (guard1) {
        MultiWordAdd(&AvionicStateFlow_B.res.chunks[0U], &tmp_1.chunks[0U],
                     &AvionicStateFlow_B.r31.chunks[0U], 2);
        AvionicStateFlow_B.res = AvionicStateFlow_B.r31;
      }
    }
  }

  if (b_isQuotNegative) {
    if (uMultiWordLe(&AvionicStateFlow_B.res.chunks[0U], &tmp_3.chunks[0U], 2))
    {
      uMultiWord2MultiWord(&AvionicStateFlow_B.res.chunks[0U], 2,
                           &AvionicStateFlow_B.r25.chunks[0U], 2);
      MultiWordNeg(&AvionicStateFlow_B.r25.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp_7;
    }
  } else if (uMultiWordLe(&AvionicStateFlow_B.res.chunks[0U], &tmp_3.chunks[0U],
              2)) {
    uMultiWord2MultiWord(&AvionicStateFlow_B.res.chunks[0U], 2,
                         &AvionicStateFlow_B.r24.chunks[0U], 2);
    z = AvionicStateFlow_B.r24;
  } else {
    z = tmp_6;
  }

  return z;
}

static uint64m_T AvionicSta_eml_mixed_uint64_mul(const uint64m_T nv, real_T y)
{
  uint64m_T tmp_3;
  uint64m_T z;
  int32_T ex_t;
  int32_T tmp_2;
  int16_T tmp;
  int16_T tmp_0;
  int16_T tmp_1;
  static const uint64m_T tmp_4 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_5 = { { MAX_uint32_T, 0U }/* chunks */
  };

  static const uint64m_T tmp_6 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_7 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  boolean_T guard1 = false;
  if (rtIsNaN(y) || (y <= 0.0)) {
    z = tmp_4;
  } else {
    AvionicStateFlow_B.yd = frexp(y, &ex_t);
    if ((int16_T)ex_t <= -64) {
      z = tmp_4;
    } else {
      Double2MultiWord(rt_roundd_snf(AvionicStateFlow_B.yd *
        9.007199254740992E+15), &AvionicStateFlow_B.yint.chunks[0U], 2);
      uMultiWordShr(&AvionicStateFlow_B.yint.chunks[0U], 2, 32U,
                    &AvionicStateFlow_B.b_y1.chunks[0U], 2);
      MultiWordAnd(&AvionicStateFlow_B.yint.chunks[0U], &tmp_5.chunks[0U],
                   &AvionicStateFlow_B.b_y0.chunks[0U], 2);
      if (uMultiWordEq(&nv.chunks[0U], &tmp_4.chunks[0U], 2)) {
        z = tmp_4;
      } else if (rtIsInf(y)) {
        z = tmp_7;
      } else if ((int16_T)((int16_T)ex_t - 53) > 64) {
        z = tmp_7;
      } else {
        uMultiWordShr(&nv.chunks[0U], 2, 32U, &AvionicStateFlow_B.n1.chunks[0U],
                      2);
        AvionicStateFlow_B.r44 = nv;
        AvionicStateFlow_B.r45 = tmp_5;
        MultiWordAnd(&nv.chunks[0U], &tmp_5.chunks[0U],
                     &AvionicStateFlow_B.n0.chunks[0U], 2);
        uMultiWordMul(&AvionicStateFlow_B.n0.chunks[0U], 2,
                      &AvionicStateFlow_B.b_y0.chunks[0U], 2,
                      &AvionicStateFlow_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&AvionicStateFlow_B.r3.chunks[0U], 4,
                             &AvionicStateFlow_B.yint.chunks[0U], 2);
        uMultiWordMul(&AvionicStateFlow_B.n0.chunks[0U], 2,
                      &AvionicStateFlow_B.b_y1.chunks[0U], 2,
                      &AvionicStateFlow_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&AvionicStateFlow_B.r3.chunks[0U], 4,
                             &AvionicStateFlow_B.n0.chunks[0U], 2);
        uMultiWordMul(&AvionicStateFlow_B.n1.chunks[0U], 2,
                      &AvionicStateFlow_B.b_y0.chunks[0U], 2,
                      &AvionicStateFlow_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&AvionicStateFlow_B.r3.chunks[0U], 4,
                             &AvionicStateFlow_B.b_y0.chunks[0U], 2);
        AvionicStateFlow_B.r46 = tmp_5;
        MultiWordAnd(&AvionicStateFlow_B.n0.chunks[0U], &tmp_5.chunks[0U],
                     &AvionicStateFlow_B.r45.chunks[0U], 2);
        uMultiWordShr(&AvionicStateFlow_B.yint.chunks[0U], 2, 32U,
                      &AvionicStateFlow_B.r46.chunks[0U], 2);
        MultiWordAdd(&AvionicStateFlow_B.r45.chunks[0U],
                     &AvionicStateFlow_B.r46.chunks[0U],
                     &AvionicStateFlow_B.r44.chunks[0U], 2);
        AvionicStateFlow_B.r46 = tmp_5;
        MultiWordAnd(&AvionicStateFlow_B.b_y0.chunks[0U], &tmp_5.chunks[0U],
                     &AvionicStateFlow_B.r45.chunks[0U], 2);
        MultiWordAdd(&AvionicStateFlow_B.r44.chunks[0U],
                     &AvionicStateFlow_B.r45.chunks[0U],
                     &AvionicStateFlow_B.temp.chunks[0U], 2);
        AvionicStateFlow_B.r45 = tmp_5;
        MultiWordAnd(&AvionicStateFlow_B.yint.chunks[0U], &tmp_5.chunks[0U],
                     &AvionicStateFlow_B.r44.chunks[0U], 2);
        uMultiWordShl(&AvionicStateFlow_B.temp.chunks[0U], 2, 32U,
                      &AvionicStateFlow_B.r45.chunks[0U], 2);
        MultiWordAdd(&AvionicStateFlow_B.r44.chunks[0U],
                     &AvionicStateFlow_B.r45.chunks[0U],
                     &AvionicStateFlow_B.yint.chunks[0U], 2);
        uMultiWordMul(&AvionicStateFlow_B.n1.chunks[0U], 2,
                      &AvionicStateFlow_B.b_y1.chunks[0U], 2,
                      &AvionicStateFlow_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&AvionicStateFlow_B.r3.chunks[0U], 4,
                             &AvionicStateFlow_B.r46.chunks[0U], 2);
        uMultiWordShr(&AvionicStateFlow_B.n0.chunks[0U], 2, 32U,
                      &AvionicStateFlow_B.r47.chunks[0U], 2);
        MultiWordAdd(&AvionicStateFlow_B.r46.chunks[0U],
                     &AvionicStateFlow_B.r47.chunks[0U],
                     &AvionicStateFlow_B.r45.chunks[0U], 2);
        uMultiWordShr(&AvionicStateFlow_B.b_y0.chunks[0U], 2, 32U,
                      &AvionicStateFlow_B.r46.chunks[0U], 2);
        MultiWordAdd(&AvionicStateFlow_B.r45.chunks[0U],
                     &AvionicStateFlow_B.r46.chunks[0U],
                     &AvionicStateFlow_B.r44.chunks[0U], 2);
        uMultiWordShr(&AvionicStateFlow_B.temp.chunks[0U], 2, 32U,
                      &AvionicStateFlow_B.r45.chunks[0U], 2);
        MultiWordAdd(&AvionicStateFlow_B.r44.chunks[0U],
                     &AvionicStateFlow_B.r45.chunks[0U],
                     &AvionicStateFlow_B.b_y1.chunks[0U], 2);
        if ((int16_T)((int16_T)ex_t - 53) >= 0) {
          if (uMultiWordGt(&AvionicStateFlow_B.b_y1.chunks[0U], &tmp_4.chunks[0U],
                           2)) {
            z = tmp_7;
          } else {
            guard1 = false;
            if ((int16_T)(117 - (int16_T)ex_t) < 64) {
              tmp = (int16_T)(117 - (int16_T)ex_t);
              if ((int16_T)(117 - (int16_T)ex_t) < 0) {
                tmp = 0;
              } else if ((int16_T)(117 - (int16_T)ex_t) > 255) {
                tmp = 255;
              }

              uMultiWordShr(&AvionicStateFlow_B.yint.chunks[0U], 2, (uint32_T)
                            tmp, &tmp_3.chunks[0U], 2);
              if (uMultiWordGt(&tmp_3.chunks[0U], &tmp_4.chunks[0U], 2)) {
                z = tmp_7;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              tmp = (int16_T)((int16_T)ex_t - 53);
              if ((int16_T)((int16_T)ex_t - 53) < 0) {
                tmp = 0;
              } else if ((int16_T)((int16_T)ex_t - 53) > 255) {
                tmp = 255;
              }

              uMultiWordShl(&AvionicStateFlow_B.yint.chunks[0U], 2, (uint32_T)
                            tmp, &z.chunks[0U], 2);
            }
          }
        } else if ((int16_T)((int16_T)ex_t - 53) > -64) {
          tmp_2 = -(int16_T)((int16_T)ex_t - 53);
          if (-(int16_T)((int16_T)ex_t - 53) > 32767) {
            tmp_2 = 32767;
          }

          tmp = (int16_T)tmp_2;
          if ((int16_T)tmp_2 < 0) {
            tmp = 0;
          } else if ((int16_T)tmp_2 > 255) {
            tmp = 255;
          }

          uMultiWordShr(&AvionicStateFlow_B.b_y1.chunks[0U], 2, (uint32_T)tmp,
                        &AvionicStateFlow_B.r44.chunks[0U], 2);
          if (uMultiWordGt(&AvionicStateFlow_B.r44.chunks[0U], &tmp_4.chunks[0U],
                           2)) {
            z = tmp_7;
          } else {
            tmp = (int16_T)(53 - (int16_T)ex_t);
            if ((int16_T)(53 - (int16_T)ex_t) < 0) {
              tmp = 0;
            } else if ((int16_T)(53 - (int16_T)ex_t) > 255) {
              tmp = 255;
            }

            tmp_0 = (int16_T)((int16_T)ex_t + 11);
            if ((int16_T)((int16_T)ex_t + 11) < 0) {
              tmp_0 = 0;
            } else if ((int16_T)((int16_T)ex_t + 11) > 255) {
              tmp_0 = 255;
            }

            tmp_1 = (int16_T)(52 - (int16_T)ex_t);
            if ((int16_T)(52 - (int16_T)ex_t) < 0) {
              tmp_1 = 0;
            } else if ((int16_T)(52 - (int16_T)ex_t) > 255) {
              tmp_1 = 255;
            }

            uMultiWordShr(&AvionicStateFlow_B.yint.chunks[0U], 2, (uint32_T)tmp,
                          &tmp_3.chunks[0U], 2);
            uMultiWordShl(&AvionicStateFlow_B.b_y1.chunks[0U], 2, (uint32_T)
                          tmp_0, &z.chunks[0U], 2);
            MultiWordAdd(&tmp_3.chunks[0U], &z.chunks[0U],
                         &AvionicStateFlow_B.r48.chunks[0U], 2);
            uMultiWordShr(&AvionicStateFlow_B.yint.chunks[0U], 2, (uint32_T)
                          tmp_1, &z.chunks[0U], 2);
            MultiWordAnd(&z.chunks[0U], &tmp_6.chunks[0U], &tmp_3.chunks[0U], 2);
            MultiWordAdd(&AvionicStateFlow_B.r48.chunks[0U], &tmp_3.chunks[0U],
                         &z.chunks[0U], 2);
          }
        } else if ((int16_T)((int16_T)ex_t - 53) == -64) {
          uMultiWordShr(&AvionicStateFlow_B.yint.chunks[0U], 2, 63U,
                        &AvionicStateFlow_B.r45.chunks[0U], 2);
          MultiWordAnd(&AvionicStateFlow_B.r45.chunks[0U], &tmp_6.chunks[0U],
                       &AvionicStateFlow_B.r44.chunks[0U], 2);
          MultiWordAdd(&AvionicStateFlow_B.b_y1.chunks[0U],
                       &AvionicStateFlow_B.r44.chunks[0U],
                       &AvionicStateFlow_B.r45.chunks[0U], 2);
          z = AvionicStateFlow_B.r45;
        } else {
          tmp = (int16_T)-(int16_T)((int16_T)ex_t + 11);
          if ((int16_T)-(int16_T)((int16_T)ex_t + 11) < 0) {
            tmp = 0;
          } else if ((int16_T)-(int16_T)((int16_T)ex_t + 11) > 255) {
            tmp = 255;
          }

          tmp_0 = (int16_T)-(int16_T)((int16_T)ex_t + 12);
          if ((int16_T)-(int16_T)((int16_T)ex_t + 12) < 0) {
            tmp_0 = 0;
          } else if ((int16_T)-(int16_T)((int16_T)ex_t + 12) > 255) {
            tmp_0 = 255;
          }

          uMultiWordShr(&AvionicStateFlow_B.b_y1.chunks[0U], 2, (uint32_T)tmp,
                        &AvionicStateFlow_B.r44.chunks[0U], 2);
          uMultiWordShr(&AvionicStateFlow_B.b_y1.chunks[0U], 2, (uint32_T)tmp_0,
                        &AvionicStateFlow_B.r46.chunks[0U], 2);
          MultiWordAnd(&AvionicStateFlow_B.r46.chunks[0U], &tmp_6.chunks[0U],
                       &AvionicStateFlow_B.r45.chunks[0U], 2);
          MultiWordAdd(&AvionicStateFlow_B.r44.chunks[0U],
                       &AvionicStateFlow_B.r45.chunks[0U],
                       &AvionicStateFlow_B.r46.chunks[0U], 2);
          z = AvionicStateFlow_B.r46;
        }
      }
    }
  }

  return z;
}

static int64m_T AvionicStateFlow_times(real_T x, const int64m_T y)
{
  int64m_T z;
  boolean_T isProdNegative;
  static const int64m_T tmp = { { 0U, 2147483648U }/* chunks */
  };

  static const int64m_T tmp_0 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const uint64m_T tmp_1 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_2 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_3 = { { 0U, 2147483648U }/* chunks */
  };

  if ((sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x > 0.0)) ||
      (sMultiWordGt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x < 0.0))) {
    isProdNegative = true;
  } else {
    isProdNegative = false;
  }

  if (x < 0.0) {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        AvionicStateFlow_B.r43 = y;
        MultiWordNeg(&y.chunks[0U], &AvionicStateFlow_B.r42.chunks[0U], 2);
        sMultiWord2MultiWord(&AvionicStateFlow_B.r42.chunks[0U], 2,
                             &AvionicStateFlow_B.prod_unsgn.chunks[0U], 2);
      } else {
        AvionicStateFlow_B.prod_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2,
                           &AvionicStateFlow_B.prod_unsgn.chunks[0U], 2);
    }

    AvionicStateFlow_B.prod_unsgn = AvionicSta_eml_mixed_uint64_mul
      (AvionicStateFlow_B.prod_unsgn, -x);
  } else {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &AvionicStateFlow_B.r41.chunks[0U], 2);
        sMultiWord2MultiWord(&AvionicStateFlow_B.r41.chunks[0U], 2,
                             &AvionicStateFlow_B.prod_unsgn.chunks[0U], 2);
      } else {
        AvionicStateFlow_B.prod_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2,
                           &AvionicStateFlow_B.prod_unsgn.chunks[0U], 2);
    }

    AvionicStateFlow_B.prod_unsgn = AvionicSta_eml_mixed_uint64_mul
      (AvionicStateFlow_B.prod_unsgn, x);
  }

  if (isProdNegative) {
    if (uMultiWordLe(&AvionicStateFlow_B.prod_unsgn.chunks[0U], &tmp_1.chunks[0U],
                     2)) {
      uMultiWord2MultiWord(&AvionicStateFlow_B.prod_unsgn.chunks[0U], 2,
                           &AvionicStateFlow_B.r43.chunks[0U], 2);
      MultiWordNeg(&AvionicStateFlow_B.r43.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp;
    }
  } else if (uMultiWordLe(&AvionicStateFlow_B.prod_unsgn.chunks[0U],
                          &tmp_1.chunks[0U], 2)) {
    uMultiWord2MultiWord(&AvionicStateFlow_B.prod_unsgn.chunks[0U], 2,
                         &AvionicStateFlow_B.r42.chunks[0U], 2);
    z = AvionicStateFlow_B.r42;
  } else {
    z = tmp_0;
  }

  return z;
}

static real_T Avioni_bbblueBarometer_stepImpl(const
  beagleboneblue_bbblueBaromete_T *obj)
{
  real_T y;
  int32_T rawT;
  uint8_T data[6];
  uint8_T a__3;
  static const int64m_T tmp = { { 0U, 32768U }/* chunks */
  };

  static const int64m_T tmp_0 = { { 128000U, 0U }/* chunks */
  };

  static const int64m_T tmp_1 = { { 3125U, 0U }/* chunks */
  };

  static const int64m_T tmp_2 = { { 0U, 0U }/* chunks */
  };

  bbblueBarometer_BMP_ReadRegiste(obj, data, &a__3);
  rawT = data[3] << 12 | data[4] << 4 | data[5] >> 4;
  sLong2MultiWord(rawT, &AvionicStateFlow_B.r17.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r17.chunks[0U], 2, 3U,
                &AvionicStateFlow_B.r16.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r16.chunks[0U], 2,
                       &AvionicStateFlow_B.r9.chunks[0U], 3);
  uLong2MultiWord(obj->dig_T1, &AvionicStateFlow_B.r17.chunks[0U], 2);
  sMultiWordShl(&AvionicStateFlow_B.r17.chunks[0U], 2, 1U,
                &AvionicStateFlow_B.r16.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r16.chunks[0U], 2,
                       &AvionicStateFlow_B.r10.chunks[0U], 3);
  MultiWordSub(&AvionicStateFlow_B.r9.chunks[0U],
               &AvionicStateFlow_B.r10.chunks[0U],
               &AvionicStateFlow_B.r8.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r8.chunks[0U], 3,
    &AvionicStateFlow_B.r15.chunks[0U], 2);
  sLong2MultiWord(obj->dig_T2, &AvionicStateFlow_B.r16.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.r15.chunks[0U], 2,
                &AvionicStateFlow_B.r16.chunks[0U], 2,
                &AvionicStateFlow_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
    &AvionicStateFlow_B.r14.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r14.chunks[0U], 2, 11U,
                &AvionicStateFlow_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r13.chunks[0U], 2,
                       &AvionicStateFlow_B.r7.chunks[0U], 3);
  sLong2MultiWord(rawT, &AvionicStateFlow_B.r19.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r19.chunks[0U], 2, 4U,
                &AvionicStateFlow_B.r18.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r18.chunks[0U], 2,
                       &AvionicStateFlow_B.r10.chunks[0U], 3);
  uLong2MultiWord(obj->dig_T1, &AvionicStateFlow_B.r18.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r18.chunks[0U], 2,
                       &AvionicStateFlow_B.r11.chunks[0U], 3);
  MultiWordSub(&AvionicStateFlow_B.r10.chunks[0U],
               &AvionicStateFlow_B.r11.chunks[0U],
               &AvionicStateFlow_B.r9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r9.chunks[0U], 3,
    &AvionicStateFlow_B.r17.chunks[0U], 2);
  sLong2MultiWord(rawT, &AvionicStateFlow_B.r20.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r20.chunks[0U], 2, 4U,
                &AvionicStateFlow_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r19.chunks[0U], 2,
                       &AvionicStateFlow_B.r10.chunks[0U], 3);
  uLong2MultiWord(obj->dig_T1, &AvionicStateFlow_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r19.chunks[0U], 2,
                       &AvionicStateFlow_B.r11.chunks[0U], 3);
  MultiWordSub(&AvionicStateFlow_B.r10.chunks[0U],
               &AvionicStateFlow_B.r11.chunks[0U],
               &AvionicStateFlow_B.r9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r9.chunks[0U], 3,
    &AvionicStateFlow_B.r18.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.r17.chunks[0U], 2,
                &AvionicStateFlow_B.r18.chunks[0U], 2,
                &AvionicStateFlow_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r1.chunks[0U], 4,
    &AvionicStateFlow_B.r16.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r16.chunks[0U], 2, 12U,
                &AvionicStateFlow_B.r15.chunks[0U], 2);
  sLong2MultiWord(obj->dig_T3, &AvionicStateFlow_B.r16.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.r15.chunks[0U], 2,
                &AvionicStateFlow_B.r16.chunks[0U], 2,
                &AvionicStateFlow_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
    &AvionicStateFlow_B.r14.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r14.chunks[0U], 2, 14U,
                &AvionicStateFlow_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r13.chunks[0U], 2,
                       &AvionicStateFlow_B.r8.chunks[0U], 3);
  MultiWordAdd(&AvionicStateFlow_B.r7.chunks[0U], &AvionicStateFlow_B.r8.chunks
               [0U], &AvionicStateFlow_B.r6.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r6.chunks[0U], 3,
    &AvionicStateFlow_B.r12.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r12.chunks[0U], 2,
                       &AvionicStateFlow_B.r5.chunks[0U], 3);
  AvionicStateFlow_B.r12 = tmp_0;
  sMultiWord2MultiWord(&tmp_0.chunks[0U], 2, &AvionicStateFlow_B.r6.chunks[0U],
                       3);
  MultiWordSub(&AvionicStateFlow_B.r5.chunks[0U], &AvionicStateFlow_B.r6.chunks
               [0U], &AvionicStateFlow_B.r4.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r4.chunks[0U], 3,
    &AvionicStateFlow_B.val3.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.val3.chunks[0U], 2,
                &AvionicStateFlow_B.val3.chunks[0U], 2,
                &AvionicStateFlow_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r1.chunks[0U], 4,
    &AvionicStateFlow_B.r14.chunks[0U], 2);
  sLong2MultiWord(obj->dig_P6, &AvionicStateFlow_B.r15.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.r14.chunks[0U], 2,
                &AvionicStateFlow_B.r15.chunks[0U], 2,
                &AvionicStateFlow_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
    &AvionicStateFlow_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r13.chunks[0U], 2,
                       &AvionicStateFlow_B.r7.chunks[0U], 3);
  sLong2MultiWord(obj->dig_P5, &AvionicStateFlow_B.r15.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.val3.chunks[0U], 2,
                &AvionicStateFlow_B.r15.chunks[0U], 2,
                &AvionicStateFlow_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
    &AvionicStateFlow_B.r14.chunks[0U], 2);
  sMultiWordShl(&AvionicStateFlow_B.r14.chunks[0U], 2, 17U,
                &AvionicStateFlow_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r13.chunks[0U], 2,
                       &AvionicStateFlow_B.r8.chunks[0U], 3);
  MultiWordAdd(&AvionicStateFlow_B.r7.chunks[0U], &AvionicStateFlow_B.r8.chunks
               [0U], &AvionicStateFlow_B.r6.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r6.chunks[0U], 3,
    &AvionicStateFlow_B.r12.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r12.chunks[0U], 2,
                       &AvionicStateFlow_B.r5.chunks[0U], 3);
  sLong2MultiWord(obj->dig_P4, &AvionicStateFlow_B.r13.chunks[0U], 2);
  sMultiWordShl(&AvionicStateFlow_B.r13.chunks[0U], 2, 35U,
                &AvionicStateFlow_B.r12.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r12.chunks[0U], 2,
                       &AvionicStateFlow_B.r6.chunks[0U], 3);
  MultiWordAdd(&AvionicStateFlow_B.r5.chunks[0U], &AvionicStateFlow_B.r6.chunks
               [0U], &AvionicStateFlow_B.r4.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r4.chunks[0U], 3,
    &AvionicStateFlow_B.val4.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.val3.chunks[0U], 2,
                &AvionicStateFlow_B.val3.chunks[0U], 2,
                &AvionicStateFlow_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r1.chunks[0U], 4,
    &AvionicStateFlow_B.r13.chunks[0U], 2);
  sLong2MultiWord(obj->dig_P3, &AvionicStateFlow_B.r14.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.r13.chunks[0U], 2,
                &AvionicStateFlow_B.r14.chunks[0U], 2,
                &AvionicStateFlow_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
    &AvionicStateFlow_B.r12.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r12.chunks[0U], 2, 8U,
                &AvionicStateFlow_B.c.chunks[0U], 2);
  sLong2MultiWord(obj->dig_P2, &AvionicStateFlow_B.r13.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.val3.chunks[0U], 2,
                &AvionicStateFlow_B.r13.chunks[0U], 2,
                &AvionicStateFlow_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
    &AvionicStateFlow_B.r12.chunks[0U], 2);
  sMultiWordShl(&AvionicStateFlow_B.r12.chunks[0U], 2, 12U,
                &AvionicStateFlow_B.val3.chunks[0U], 2);
  AvionicStateFlow_B.r14 = tmp;
  sMultiWord2MultiWord(&tmp.chunks[0U], 2, &AvionicStateFlow_B.r5.chunks[0U], 3);
  sMultiWord2MultiWord(&AvionicStateFlow_B.c.chunks[0U], 2,
                       &AvionicStateFlow_B.r8.chunks[0U], 3);
  sMultiWord2MultiWord(&AvionicStateFlow_B.val3.chunks[0U], 2,
                       &AvionicStateFlow_B.r9.chunks[0U], 3);
  MultiWordAdd(&AvionicStateFlow_B.r8.chunks[0U], &AvionicStateFlow_B.r9.chunks
               [0U], &AvionicStateFlow_B.r7.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r7.chunks[0U], 3,
    &AvionicStateFlow_B.r14.chunks[0U], 2);
  sMultiWord2MultiWord(&AvionicStateFlow_B.r14.chunks[0U], 2,
                       &AvionicStateFlow_B.r6.chunks[0U], 3);
  MultiWordAdd(&AvionicStateFlow_B.r5.chunks[0U], &AvionicStateFlow_B.r6.chunks
               [0U], &AvionicStateFlow_B.r4.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r4.chunks[0U], 3,
    &AvionicStateFlow_B.r13.chunks[0U], 2);
  uLong2MultiWord(obj->dig_P1, &AvionicStateFlow_B.r14.chunks[0U], 2);
  sMultiWordMul(&AvionicStateFlow_B.r13.chunks[0U], 2,
                &AvionicStateFlow_B.r14.chunks[0U], 2,
                &AvionicStateFlow_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
    &AvionicStateFlow_B.r12.chunks[0U], 2);
  sMultiWordShr(&AvionicStateFlow_B.r12.chunks[0U], 2, 33U,
                &AvionicStateFlow_B.val3.chunks[0U], 2);
  if (sMultiWordEq(&AvionicStateFlow_B.val3.chunks[0U], &tmp_2.chunks[0U], 2)) {
    y = 0.0;
  } else {
    sLong2MultiWord(1048576 - (data[0] << 12 | data[1] << 4 | data[2] >> 4),
                    &AvionicStateFlow_B.r16.chunks[0U], 2);
    sMultiWordShl(&AvionicStateFlow_B.r16.chunks[0U], 2, 31U,
                  &AvionicStateFlow_B.r15.chunks[0U], 2);
    sMultiWord2MultiWord(&AvionicStateFlow_B.r15.chunks[0U], 2,
                         &AvionicStateFlow_B.r5.chunks[0U], 3);
    sMultiWord2MultiWord(&AvionicStateFlow_B.val4.chunks[0U], 2,
                         &AvionicStateFlow_B.r6.chunks[0U], 3);
    MultiWordSub(&AvionicStateFlow_B.r5.chunks[0U],
                 &AvionicStateFlow_B.r6.chunks[0U],
                 &AvionicStateFlow_B.r4.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r4.chunks[0U], 3,
      &AvionicStateFlow_B.r14.chunks[0U], 2);
    AvionicStateFlow_B.r15 = tmp_1;
    sMultiWordMul(&AvionicStateFlow_B.r14.chunks[0U], 2, &tmp_1.chunks[0U], 2,
                  &AvionicStateFlow_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
      &AvionicStateFlow_B.r13.chunks[0U], 2);
    AvionicStateFlow_B.val4 = AvionicStateFlow_i64ddiv(sMultiWord2Double
      (&AvionicStateFlow_B.r13.chunks[0U], 2, 0), AvionicStateFlow_B.val3);
    AvionicStateFlow_B.c = AvionicStateFlow_times((real_T)obj->dig_P8,
      AvionicStateFlow_B.val4);
    sMultiWord2MultiWord(&AvionicStateFlow_B.val4.chunks[0U], 2,
                         &AvionicStateFlow_B.r9.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P9, &AvionicStateFlow_B.r20.chunks[0U], 2);
    sMultiWordShr(&AvionicStateFlow_B.val4.chunks[0U], 2, 13U,
                  &AvionicStateFlow_B.r22.chunks[0U], 2);
    sMultiWordShr(&AvionicStateFlow_B.val4.chunks[0U], 2, 13U,
                  &AvionicStateFlow_B.r23.chunks[0U], 2);
    sMultiWordMul(&AvionicStateFlow_B.r22.chunks[0U], 2,
                  &AvionicStateFlow_B.r23.chunks[0U], 2,
                  &AvionicStateFlow_B.r1.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r1.chunks[0U], 4,
      &AvionicStateFlow_B.r21.chunks[0U], 2);
    sMultiWordMul(&AvionicStateFlow_B.r20.chunks[0U], 2,
                  &AvionicStateFlow_B.r21.chunks[0U], 2,
                  &AvionicStateFlow_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r.chunks[0U], 4,
      &AvionicStateFlow_B.r19.chunks[0U], 2);
    sMultiWordShr(&AvionicStateFlow_B.r19.chunks[0U], 2, 25U,
                  &AvionicStateFlow_B.r18.chunks[0U], 2);
    sMultiWord2MultiWord(&AvionicStateFlow_B.r18.chunks[0U], 2,
                         &AvionicStateFlow_B.r10.chunks[0U], 3);
    MultiWordAdd(&AvionicStateFlow_B.r9.chunks[0U],
                 &AvionicStateFlow_B.r10.chunks[0U],
                 &AvionicStateFlow_B.r8.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r8.chunks[0U], 3,
      &AvionicStateFlow_B.r17.chunks[0U], 2);
    sMultiWord2MultiWord(&AvionicStateFlow_B.r17.chunks[0U], 2,
                         &AvionicStateFlow_B.r7.chunks[0U], 3);
    sMultiWordShr(&AvionicStateFlow_B.c.chunks[0U], 2, 19U,
                  &AvionicStateFlow_B.r17.chunks[0U], 2);
    sMultiWord2MultiWord(&AvionicStateFlow_B.r17.chunks[0U], 2,
                         &AvionicStateFlow_B.r8.chunks[0U], 3);
    MultiWordAdd(&AvionicStateFlow_B.r7.chunks[0U],
                 &AvionicStateFlow_B.r8.chunks[0U],
                 &AvionicStateFlow_B.r6.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r6.chunks[0U], 3,
      &AvionicStateFlow_B.r16.chunks[0U], 2);
    sMultiWordShr(&AvionicStateFlow_B.r16.chunks[0U], 2, 8U,
                  &AvionicStateFlow_B.r15.chunks[0U], 2);
    sMultiWord2MultiWord(&AvionicStateFlow_B.r15.chunks[0U], 2,
                         &AvionicStateFlow_B.r5.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P7, &AvionicStateFlow_B.r16.chunks[0U], 2);
    sMultiWordShl(&AvionicStateFlow_B.r16.chunks[0U], 2, 4U,
                  &AvionicStateFlow_B.r15.chunks[0U], 2);
    sMultiWord2MultiWord(&AvionicStateFlow_B.r15.chunks[0U], 2,
                         &AvionicStateFlow_B.r6.chunks[0U], 3);
    MultiWordAdd(&AvionicStateFlow_B.r5.chunks[0U],
                 &AvionicStateFlow_B.r6.chunks[0U],
                 &AvionicStateFlow_B.r4.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&AvionicStateFlow_B.r4.chunks[0U], 3,
      &AvionicStateFlow_B.r14.chunks[0U], 2);
    y = sMultiWord2Double(&AvionicStateFlow_B.r14.chunks[0U], 2, 0) / 256.0;
  }

  return y;
}

static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj)
{
  beagleboneblue_bbblueBaromete_T *b_obj;
  obj->dig_T1 = 0U;
  obj->dig_T2 = 0;
  obj->dig_T3 = 0;
  obj->dig_P1 = 0U;
  obj->dig_P2 = 0;
  obj->dig_P3 = 0;
  obj->dig_P4 = 0;
  obj->dig_P5 = 0;
  obj->dig_P6 = 0;
  obj->dig_P7 = 0;
  obj->dig_P8 = 0;
  obj->dig_P9 = 0;
  obj->isInitialized = 0;
  obj->SampleTime = -1.0;
  b_obj = obj;
  obj->i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
  obj->i2cObj.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void AvionicStateFl_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  int32_T i;
  uint16_T c;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regVal;
  uint8_T status;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObj.MW_I2C_HANDLE, obj->i2cObj.BusSpeed);
  regVal = 182U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 224U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (uint32_T)
         ((size_t)2 * sizeof(uint8_T)));
  MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                     false, false);
  MW_usleep(1000);
  status = 208U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
    &SwappedDataBytes_0, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U, &status, 1U, false, true);
    memcpy((void *)&regVal, (void *)&status, (uint32_T)((size_t)1 * sizeof
            (uint8_T)));
  } else {
    regVal = 0U;
  }

  obj->BMPConnect = (regVal == 88);
  if (obj->BMPConnect) {
    MW_usleep(150);
    regVal = 87U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 244U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                       false, false);
    MW_usleep(150);
    regVal = 16U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (uint32_T)((size_t)1
            * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 245U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
           (uint32_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                       false, false);
    MW_usleep(150);
    regVal = 1U;
    while ((regVal & 1U) != 0U) {
      MW_usleep(20000);
      status = 243U;
      memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
              sizeof(uint8_T)));
      status = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
        &SwappedDataBytes_0, 1U, true, false);
      if (0 == status) {
        MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U, &status, 1U, false,
                          true);
        memcpy((void *)&regVal, (void *)&status, (uint32_T)((size_t)1 * sizeof
                (uint8_T)));
      } else {
        regVal = 0U;
      }
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
    status = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes_0, 1U, true, false);
    if (0 == status) {
      MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U,
                        &AvionicStateFlow_B.output_raw[0], 24U, false, true);
      memcpy((void *)&AvionicStateFlow_B.b_RegisterValue[0], (void *)
             &AvionicStateFlow_B.output_raw[0], (uint32_T)((size_t)24 * sizeof
              (uint8_T)));
    } else {
      for (i = 0; i < 24; i++) {
        AvionicStateFlow_B.b_RegisterValue[i] = 0U;
      }
    }

    obj->dig_T1 = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[1] << 8 |
      AvionicStateFlow_B.b_RegisterValue[0]);
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[3] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[2]);
    memcpy((void *)&obj->dig_T2, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[5] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[4]);
    memcpy((void *)&obj->dig_T3, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    obj->dig_P1 = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[7] << 8 |
      AvionicStateFlow_B.b_RegisterValue[6]);
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[9] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[8]);
    memcpy((void *)&obj->dig_P2, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[11] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[10]);
    memcpy((void *)&obj->dig_P3, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[13] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[12]);
    memcpy((void *)&obj->dig_P4, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[15] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[14]);
    memcpy((void *)&obj->dig_P5, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[17] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[16]);
    memcpy((void *)&obj->dig_P6, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[19] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[18]);
    memcpy((void *)&obj->dig_P7, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[21] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[20]);
    memcpy((void *)&obj->dig_P8, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    c = (uint16_T)(AvionicStateFlow_B.b_RegisterValue[23] << 8 |
                   AvionicStateFlow_B.b_RegisterValue[22]);
    memcpy((void *)&obj->dig_P9, (void *)&c, (uint32_T)((size_t)1 * sizeof
            (int16_T)));
  }
}

static void AvionicState_SystemCore_setup_e(beagleboneblue_bbblueMPU9250__T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  obj->isInitialized = 1;
  MW_IMU_DMP_isAccel_Calibrated();
  MW_IMU_DMP_isGyro_Calibrated();
  MW_IMU_DMP_isMag_Calibrated();
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  MW_Init_IMU_DMP(200);
  obj->TunablePropsChanged = false;
}

/* Model step function for TID0 */
void AvionicStateFlow_step0(void)      /* Sample time: [0.01s, 0.0s] */
{
  int32_T b_tmp;
  int32_T r1;
  int32_T r2;
  int16_T output;
  int8_T B_tmp[6];
  uint8_T b_x[2];
  uint8_T output_raw[2];
  uint8_T rtb_DataTypeConversion2;
  static const int8_T d[3] = { 0, 0, 1 };

  static const int8_T a[9] = { 0, 0, 0, 1, 0, 0, 0, 1, 0 };

  static const int8_T b[6] = { 1, 0, 0, 0, 1, 0 };

  static const int8_T b_a[6] = { 1, 0, 0, 1, 0, 0 };

  static const real_T tmp[4] = { 1.0, 0.0, 0.0, 0.5 };

  static const real_T tmp_0[9] = { 1.0E-8, 0.0, 0.0, 0.0, 1.0E-8, 0.0, 0.0, 0.0,
    1.0E-6 };

  int32_T wk_tmp_tmp;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(AvionicStateFlow_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AvionicStateFlow_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AvionicStateFlow_DW.IfActionSubsystem3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AvionicStateFlow_DW.IfActionSubsystem4_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AvionicStateFlow_DW.IfActionSubsystem2_SubsysRanBC);

  /* MATLABSystem: '<S1>/Barometer' */
  if (AvionicStateFlow_DW.obj.SampleTime !=
      AvionicStateFlow_P.Barometer_SampleTime) {
    AvionicStateFlow_DW.obj.SampleTime = AvionicStateFlow_P.Barometer_SampleTime;
  }

  /* MATLABSystem: '<S1>/Barometer' */
  AvionicStateFlow_B.Barometer = Avioni_bbblueBarometer_stepImpl
    (&AvionicStateFlow_DW.obj);

  /* MATLABSystem: '<S1>/I2C Master Read' */
  if (AvionicStateFlow_DW.obj_i.SampleTime !=
      AvionicStateFlow_P.I2CMasterRead_SampleTime) {
    AvionicStateFlow_DW.obj_i.SampleTime =
      AvionicStateFlow_P.I2CMasterRead_SampleTime;
  }

  MW_I2C_MasterRead(AvionicStateFlow_DW.obj_i.MW_I2C_HANDLE, 72U, &output_raw[0],
                    2U, false, false);
  memcpy((void *)&output, (void *)&output_raw[0], (uint32_T)((size_t)1 * sizeof
          (int16_T)));
  memcpy((void *)&output_raw[0], (void *)&output, (uint32_T)((size_t)2 * sizeof
          (uint8_T)));
  b_x[0] = output_raw[1];
  b_x[1] = output_raw[0];
  memcpy((void *)&output, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof(int16_T)));

  /* ManualSwitch: '<S1>/Manual Switch' */
  if (AvionicStateFlow_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Gain: '<S1>/Gain'
     *  MATLABSystem: '<S1>/I2C Master Read'
     */
    AvionicStateFlow_B.ManualSwitch = (real32_T)AvionicStateFlow_P.Gain_Gain *
      2.38418579E-7F * (real32_T)output;
  } else {
    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant'
     */
    AvionicStateFlow_B.ManualSwitch = AvionicStateFlow_P.Constant_Value;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Plus'
   */
  AvionicStateFlow_B.rho = 0.0289644 * AvionicStateFlow_B.Barometer /
    ((AvionicStateFlow_B.ManualSwitch + AvionicStateFlow_P.Constant3_Value) *
     8.31432);

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  AvionicStateFlow_B.h_AGL = (AvionicStateFlow_B.Barometer - 101325.0) /
    -(AvionicStateFlow_B.rho * 9.80665) - 14.3256;

  /* RateTransition: '<S7>/Rate Transition3' */
  if (AvionicStateFlow_M->Timing.RateInteraction.TID0_2) {
    /* RateTransition: '<S7>/Rate Transition3' */
    AvionicStateFlow_B.RateTransition3 =
      AvionicStateFlow_DW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S7>/Rate Transition3' */

  /* MATLABSystem: '<S5>/MPU9250' */
  if (AvionicStateFlow_DW.obj_f.SampleTime !=
      AvionicStateFlow_P.MPU9250_SampleTime) {
    AvionicStateFlow_DW.obj_f.SampleTime = AvionicStateFlow_P.MPU9250_SampleTime;
  }

  if (AvionicStateFlow_DW.obj_f.TunablePropsChanged) {
    AvionicStateFlow_DW.obj_f.TunablePropsChanged = false;
  }

  MW_Read_Accel(&AvionicStateFlow_B.MPU9250_o1[0]);

  /* MATLABSystem: '<S5>/MPU9250' */
  AvionicStateFlow_B.MPU9250_o2[0] = 0.0;
  AvionicStateFlow_B.MPU9250_o2[1] = 0.0;
  AvionicStateFlow_B.MPU9250_o2[2] = 0.0;

  /* MATLABSystem: '<S5>/MPU9250' */
  MW_Read_Euler(&AvionicStateFlow_B.MPU9250_o2[0]);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  MATLABSystem: '<S5>/MPU9250'
   */
  AvionicStateFlow_B.b1 = AvionicStateFlow_B.MPU9250_o2[0] * 3.1415926535897931 /
    180.0;
  AvionicStateFlow_B.b2 = AvionicStateFlow_B.MPU9250_o2[1] * 3.1415926535897931 /
    180.0;
  AvionicStateFlow_B.b3 = AvionicStateFlow_B.MPU9250_o2[2] * 3.1415926535897931 /
    180.0;
  AvionicStateFlow_B.a21 = sin(AvionicStateFlow_B.b1);
  AvionicStateFlow_B.b1 = cos(AvionicStateFlow_B.b1);
  AvionicStateFlow_B.acc_tmp_k = sin(AvionicStateFlow_B.b2);
  AvionicStateFlow_B.b2 = cos(AvionicStateFlow_B.b2);
  AvionicStateFlow_B.acc_tmp_c = sin(AvionicStateFlow_B.b3);
  AvionicStateFlow_B.b3 = cos(AvionicStateFlow_B.b3);
  AvionicStateFlow_B.Ak[1] = 0.0;
  AvionicStateFlow_B.Ak[4] = AvionicStateFlow_B.b1;
  AvionicStateFlow_B.Ak[7] = AvionicStateFlow_B.a21;
  AvionicStateFlow_B.Ak[2] = 0.0;
  AvionicStateFlow_B.Ak[5] = -AvionicStateFlow_B.a21;
  AvionicStateFlow_B.Ak[8] = AvionicStateFlow_B.b1;
  AvionicStateFlow_B.acc_tmp[0] = AvionicStateFlow_B.b2;
  AvionicStateFlow_B.acc_tmp[3] = 0.0;
  AvionicStateFlow_B.acc_tmp[6] = -AvionicStateFlow_B.acc_tmp_k;
  AvionicStateFlow_B.Ak[0] = 1.0;
  AvionicStateFlow_B.acc_tmp[1] = 0.0;
  AvionicStateFlow_B.Ak[3] = 0.0;
  AvionicStateFlow_B.acc_tmp[4] = 1.0;
  AvionicStateFlow_B.Ak[6] = 0.0;
  AvionicStateFlow_B.acc_tmp[7] = 0.0;
  AvionicStateFlow_B.acc_tmp[2] = AvionicStateFlow_B.acc_tmp_k;
  AvionicStateFlow_B.acc_tmp[5] = 0.0;
  AvionicStateFlow_B.acc_tmp[8] = AvionicStateFlow_B.b2;
  AvionicStateFlow_B.acc_tmp_m[0] = AvionicStateFlow_B.b3;
  AvionicStateFlow_B.acc_tmp_m[3] = AvionicStateFlow_B.acc_tmp_c;
  AvionicStateFlow_B.acc_tmp_m[6] = 0.0;
  AvionicStateFlow_B.acc_tmp_m[1] = -AvionicStateFlow_B.acc_tmp_c;
  AvionicStateFlow_B.acc_tmp_m[4] = AvionicStateFlow_B.b3;
  AvionicStateFlow_B.acc_tmp_m[7] = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = r1 + 3 * r2;
      AvionicStateFlow_B.b[b_tmp] = 0.0;
      AvionicStateFlow_B.b[b_tmp] += AvionicStateFlow_B.acc_tmp[3 * r2] *
        AvionicStateFlow_B.Ak[r1];
      AvionicStateFlow_B.b[b_tmp] += AvionicStateFlow_B.acc_tmp[3 * r2 + 1] *
        AvionicStateFlow_B.Ak[r1 + 3];
      AvionicStateFlow_B.b[b_tmp] += AvionicStateFlow_B.acc_tmp[3 * r2 + 2] *
        AvionicStateFlow_B.Ak[r1 + 6];
    }

    AvionicStateFlow_B.acc_tmp_m[3 * r1 + 2] = d[r1];
  }

  for (r1 = 0; r1 < 3; r1++) {
    AvionicStateFlow_B.acc[r1] = 0.0;
    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = r1 + 3 * r2;
      AvionicStateFlow_B.Ak[b_tmp] = 0.0;
      AvionicStateFlow_B.Ak[b_tmp] += AvionicStateFlow_B.acc_tmp_m[3 * r1] *
        AvionicStateFlow_B.b[r2];
      AvionicStateFlow_B.Ak[b_tmp] += AvionicStateFlow_B.acc_tmp_m[3 * r1 + 1] *
        AvionicStateFlow_B.b[r2 + 3];
      AvionicStateFlow_B.Ak[b_tmp] += AvionicStateFlow_B.acc_tmp_m[3 * r1 + 2] *
        AvionicStateFlow_B.b[r2 + 6];
      AvionicStateFlow_B.acc[r1] += AvionicStateFlow_B.Ak[b_tmp] *
        AvionicStateFlow_B.MPU9250_o1[r2];
    }
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function1'
   */
  memset(&AvionicStateFlow_B.Ak[0], 0, 9U * sizeof(real_T));
  AvionicStateFlow_B.Ak[0] = 1.0;
  AvionicStateFlow_B.Ak[4] = 1.0;
  AvionicStateFlow_B.Ak[8] = 1.0;
  for (r1 = 0; r1 < 9; r1++) {
    AvionicStateFlow_B.Ak[r1] += (real_T)a[r1] * 0.01;
  }

  for (r1 = 0; r1 < 6; r1++) {
    AvionicStateFlow_B.wk[r1] = b[r1];
  }

  for (r1 = 0; r1 < 2; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = r2 + 3 * r1;
      AvionicStateFlow_B.y[b_tmp] = 0.0;
      AvionicStateFlow_B.y[b_tmp] += AvionicStateFlow_B.wk[3 * r1] *
        AvionicStateFlow_DW.P[r2];
      AvionicStateFlow_B.y[b_tmp] += AvionicStateFlow_B.wk[3 * r1 + 1] *
        AvionicStateFlow_DW.P[r2 + 3];
      AvionicStateFlow_B.y[b_tmp] += AvionicStateFlow_B.wk[3 * r1 + 2] *
        AvionicStateFlow_DW.P[r2 + 6];
    }
  }

  for (r1 = 0; r1 < 6; r1++) {
    B_tmp[r1] = b_a[r1];
  }

  for (r1 = 0; r1 < 2; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = r1 + (r2 << 1);
      AvionicStateFlow_B.B_tmp[b_tmp] = 0.0;
      AvionicStateFlow_B.B_tmp[b_tmp] += AvionicStateFlow_DW.P[3 * r2] * (real_T)
        B_tmp[r1];
      AvionicStateFlow_B.B_tmp[b_tmp] += AvionicStateFlow_DW.P[3 * r2 + 1] *
        (real_T)B_tmp[r1 + 2];
      AvionicStateFlow_B.B_tmp[b_tmp] += AvionicStateFlow_DW.P[3 * r2 + 2] *
        (real_T)B_tmp[r1 + 4];
    }

    for (r2 = 0; r2 < 2; r2++) {
      b_tmp = (r2 << 1) + r1;
      AvionicStateFlow_B.B[b_tmp] = ((AvionicStateFlow_B.wk[3 * r2 + 1] *
        AvionicStateFlow_B.B_tmp[r1 + 2] + AvionicStateFlow_B.wk[3 * r2] *
        AvionicStateFlow_B.B_tmp[r1]) + AvionicStateFlow_B.wk[3 * r2 + 2] *
        AvionicStateFlow_B.B_tmp[r1 + 4]) + tmp[b_tmp];
    }
  }

  if (fabs(AvionicStateFlow_B.B[1]) > fabs(AvionicStateFlow_B.B[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  AvionicStateFlow_B.a21 = AvionicStateFlow_B.B[r2] / AvionicStateFlow_B.B[r1];
  AvionicStateFlow_B.b3 = AvionicStateFlow_B.B[r1 + 2];
  AvionicStateFlow_B.b1 = AvionicStateFlow_B.B[r2 + 2] - AvionicStateFlow_B.b3 *
    AvionicStateFlow_B.a21;
  AvionicStateFlow_B.wk[3 * r1] = AvionicStateFlow_B.y[0] /
    AvionicStateFlow_B.B[r1];
  AvionicStateFlow_B.wk[3 * r2] = (AvionicStateFlow_B.y[3] -
    AvionicStateFlow_B.wk[3 * r1] * AvionicStateFlow_B.b3) /
    AvionicStateFlow_B.b1;
  AvionicStateFlow_B.wk[3 * r1] -= AvionicStateFlow_B.wk[3 * r2] *
    AvionicStateFlow_B.a21;
  b_tmp = 3 * r1 + 1;
  AvionicStateFlow_B.wk[b_tmp] = AvionicStateFlow_B.y[1] /
    AvionicStateFlow_B.B[r1];
  wk_tmp_tmp = 3 * r2 + 1;
  AvionicStateFlow_B.wk[wk_tmp_tmp] = (AvionicStateFlow_B.y[4] -
    AvionicStateFlow_B.wk[b_tmp] * AvionicStateFlow_B.b3) /
    AvionicStateFlow_B.b1;
  AvionicStateFlow_B.wk[b_tmp] -= AvionicStateFlow_B.wk[wk_tmp_tmp] *
    AvionicStateFlow_B.a21;
  b_tmp = 3 * r1 + 2;
  AvionicStateFlow_B.wk[b_tmp] = AvionicStateFlow_B.y[2] /
    AvionicStateFlow_B.B[r1];
  wk_tmp_tmp = 3 * r2 + 2;
  AvionicStateFlow_B.wk[wk_tmp_tmp] = (AvionicStateFlow_B.y[5] -
    AvionicStateFlow_B.wk[b_tmp] * AvionicStateFlow_B.b3) /
    AvionicStateFlow_B.b1;
  AvionicStateFlow_B.wk[b_tmp] -= AvionicStateFlow_B.wk[wk_tmp_tmp] *
    AvionicStateFlow_B.a21;
  AvionicStateFlow_B.dv1[0] = AvionicStateFlow_B.h_AGL;
  AvionicStateFlow_B.dv1[1] = AvionicStateFlow_B.RateTransition3;
  for (r1 = 0; r1 < 2; r1++) {
    AvionicStateFlow_B.dv2[r1] = AvionicStateFlow_B.dv1[r1] - ((real_T)B_tmp[r1
      + 4] * AvionicStateFlow_DW.x_est_p[2] + ((real_T)B_tmp[r1 + 2] *
      AvionicStateFlow_DW.x_est_p[1] + (real_T)B_tmp[r1] *
      AvionicStateFlow_DW.x_est_p[0]));
  }

  for (r1 = 0; r1 < 3; r1++) {
    AvionicStateFlow_B.a21 = AvionicStateFlow_B.wk[r1 + 3];
    AvionicStateFlow_B.x[r1] = (AvionicStateFlow_B.a21 * AvionicStateFlow_B.dv2
      [1] + AvionicStateFlow_B.wk[r1] * AvionicStateFlow_B.dv2[0]) +
      AvionicStateFlow_DW.x_est_p[r1];
    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = r1 + 3 * r2;
      AvionicStateFlow_B.acc_tmp[b_tmp] = 0.0;
      wk_tmp_tmp = r2 << 1;
      AvionicStateFlow_B.acc_tmp[b_tmp] += (real_T)B_tmp[wk_tmp_tmp] *
        AvionicStateFlow_B.wk[r1];
      AvionicStateFlow_B.acc_tmp[b_tmp] += (real_T)B_tmp[wk_tmp_tmp + 1] *
        AvionicStateFlow_B.a21;
    }

    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = 3 * r2 + r1;
      AvionicStateFlow_B.b[b_tmp] = AvionicStateFlow_DW.P[b_tmp] -
        ((AvionicStateFlow_DW.P[3 * r2 + 1] * AvionicStateFlow_B.acc_tmp[r1 + 3]
          + AvionicStateFlow_DW.P[3 * r2] * AvionicStateFlow_B.acc_tmp[r1]) +
         AvionicStateFlow_DW.P[3 * r2 + 2] * AvionicStateFlow_B.acc_tmp[r1 + 6]);
    }
  }

  memcpy(&AvionicStateFlow_DW.P[0], &AvionicStateFlow_B.b[0], 9U * sizeof(real_T));
  for (r1 = 0; r1 < 3; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = r2 + 3 * r1;
      AvionicStateFlow_B.acc_tmp[b_tmp] = 0.0;
      AvionicStateFlow_B.acc_tmp[b_tmp] += AvionicStateFlow_DW.P[3 * r1] *
        AvionicStateFlow_B.Ak[r2];
      AvionicStateFlow_B.acc_tmp[b_tmp] += AvionicStateFlow_DW.P[3 * r1 + 1] *
        AvionicStateFlow_B.Ak[r2 + 3];
      AvionicStateFlow_B.acc_tmp[b_tmp] += AvionicStateFlow_DW.P[3 * r1 + 2] *
        AvionicStateFlow_B.Ak[r2 + 6];
    }
  }

  AvionicStateFlow_B.dv[0] = 5.0E-5 * AvionicStateFlow_B.acc[2];
  AvionicStateFlow_B.dv[1] = 0.01 * AvionicStateFlow_B.acc[2];
  AvionicStateFlow_B.dv[2] = 0.0 * AvionicStateFlow_B.acc[2];
  for (r1 = 0; r1 < 3; r1++) {
    AvionicStateFlow_B.Ak_c[r1] = 0.0;
    for (r2 = 0; r2 < 3; r2++) {
      b_tmp = 3 * r2 + r1;
      AvionicStateFlow_DW.P[b_tmp] = ((AvionicStateFlow_B.acc_tmp[r1 + 3] *
        AvionicStateFlow_B.Ak[r2 + 3] + AvionicStateFlow_B.acc_tmp[r1] *
        AvionicStateFlow_B.Ak[r2]) + AvionicStateFlow_B.acc_tmp[r1 + 6] *
        AvionicStateFlow_B.Ak[r2 + 6]) + tmp_0[b_tmp];
      AvionicStateFlow_B.Ak_c[r1] += AvionicStateFlow_B.Ak[b_tmp] *
        AvionicStateFlow_B.x[r2];
    }

    AvionicStateFlow_DW.x_est_p[r1] = AvionicStateFlow_B.Ak_c[r1] +
      AvionicStateFlow_B.dv[r1];
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function2' */

  /* RateTransition: '<Root>/Rate Transition1' */
  AvionicStateFlow_B.RateTransition1 = AvionicStateFlow_B.h_AGL;

  /* Chart: '<Root>/Chart' */
  if (AvionicStateFlow_DW.temporalCounter_i1 < 511U) {
    AvionicStateFlow_DW.temporalCounter_i1++;
  }

  if (AvionicStateFlow_DW.is_active_c3_AvionicStateFlow == 0U) {
    AvionicStateFlow_DW.is_active_c3_AvionicStateFlow = 1U;
    AvionicStateFlow_DW.is_c3_AvionicStateFlow = AvionicStateFlow_IN_OnLaunchPad;
    r1 = 0;
  } else {
    switch (AvionicStateFlow_DW.is_c3_AvionicStateFlow) {
     case AvionicStateFlo_IN_ApogeeDetect:
      if (AvionicStateFlow_DW.temporalCounter_i1 >= 300U) {
        AvionicStateFlow_DW.is_c3_AvionicStateFlow = AvionicStateFlow_IN_Droping;
        r1 = 3;
      } else {
        r1 = 2;
      }
      break;

     case AvionicStateFlow_IN_Droping:
      if (fabs(AvionicStateFlow_B.acc[2]) > 49.050000000000004) {
        AvionicStateFlow_DW.is_c3_AvionicStateFlow =
          AvionicStateFlow_IN_TouchDown;
        r1 = 4;
      } else {
        r1 = 3;
      }
      break;

     case AvionicStateFlo_IN_LaunchDetect:
      if ((AvionicStateFlow_B.x[1] <= 0.5) && (AvionicStateFlow_B.x[0] > 20.0))
      {
        AvionicStateFlow_DW.is_c3_AvionicStateFlow =
          AvionicStateFlo_IN_ApogeeDetect;
        AvionicStateFlow_DW.temporalCounter_i1 = 0U;
        r1 = 2;
      } else {
        r1 = 1;
      }
      break;

     case AvionicStateFlow_IN_OnLaunchPad:
      if (AvionicStateFlow_B.acc[2] > 29.43) {
        AvionicStateFlow_DW.is_c3_AvionicStateFlow =
          AvionicStateFlo_IN_LaunchDetect;
        r1 = 1;
      } else {
        r1 = 0;
      }
      break;

     default:
      /* case IN_TouchDown: */
      r1 = 4;
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* RateTransition: '<S6>/Rate Transition1' */
  if (AvionicStateFlow_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<S6>/Rate Transition1' */
    AvionicStateFlow_B.RateTransition1_l =
      AvionicStateFlow_DW.RateTransition1_Buffer0;

    /* RateTransition: '<S6>/Rate Transition2' */
    AvionicStateFlow_B.RateTransition2 =
      AvionicStateFlow_DW.RateTransition2_Buffer0;

    /* RateTransition: '<S6>/Rate Transition3' */
    AvionicStateFlow_B.RateTransition3_l =
      AvionicStateFlow_DW.RateTransition3_Buffer0_i;
  }

  /* End of RateTransition: '<S6>/Rate Transition1' */

  /* If: '<S6>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Inport: '<S13>/Input'
   *  Inport: '<S14>/In1'
   *  Inport: '<S14>/Input'
   *  Inport: '<S16>/In1'
   *  Inport: '<S17>/In1'
   */
  if (r1 == 1) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    AvionicStateFlow_B.a21 = AvionicStateFlow_B.RateTransition3_l;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Update for If: '<S6>/If' incorporates:
     *  Inport: '<S13>/Input'
     */
    srUpdateBC(AvionicStateFlow_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem' */
  } else if (r1 == 2) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    AvionicStateFlow_B.Input = AvionicStateFlow_P.Constant1_Value;
    AvionicStateFlow_B.a21 = AvionicStateFlow_B.RateTransition2;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Update for If: '<S6>/If' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Inport: '<S14>/In1'
     *  Inport: '<S14>/Input'
     */
    srUpdateBC(AvionicStateFlow_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem1' */
  } else if (r1 == 3) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    AvionicStateFlow_B.a21 = AvionicStateFlow_B.RateTransition1_l;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem3' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Update for If: '<S6>/If' incorporates:
     *  Inport: '<S16>/In1'
     */
    srUpdateBC(AvionicStateFlow_DW.IfActionSubsystem3_SubsysRanBC);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem3' */
  } else if (r1 == 4) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    AvionicStateFlow_B.a21 = AvionicStateFlow_P.Constant_Value_ov;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem4' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Update for If: '<S6>/If' incorporates:
     *  Constant: '<S6>/Constant'
     *  Inport: '<S17>/In1'
     */
    srUpdateBC(AvionicStateFlow_DW.IfActionSubsystem4_SubsysRanBC);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* SignalConversion generated from: '<S15>/Out1' incorporates:
     *  Constant: '<S15>/Constant'
     */
    AvionicStateFlow_B.a21 = AvionicStateFlow_P.Constant_Value_o;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem2' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Update for If: '<S6>/If' */
    srUpdateBC(AvionicStateFlow_DW.IfActionSubsystem2_SubsysRanBC);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem2' */
  }

  /* End of If: '<S6>/If' */

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  AvionicStateFlow_B.b3 = floor(AvionicStateFlow_B.Input);
  if (rtIsNaN(AvionicStateFlow_B.b3) || rtIsInf(AvionicStateFlow_B.b3)) {
    AvionicStateFlow_B.b3 = 0.0;
  } else {
    AvionicStateFlow_B.b3 = fmod(AvionicStateFlow_B.b3, 256.0);
  }

  /* MATLABSystem: '<Root>/Digital Write1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   */
  MW_digitalIO_write(AvionicStateFlow_DW.obj_k.MW_DIGITALIO_HANDLE,
                     (AvionicStateFlow_B.b3 < 0.0 ? (int32_T)(uint8_T)-(int8_T)
                      (uint8_T)-AvionicStateFlow_B.b3 : (int32_T)(uint8_T)
                      AvionicStateFlow_B.b3) != 0);

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S4>/Constant4'
   */
  AvionicStateFlow_B.Sum = AvionicStateFlow_B.acc[2] -
    AvionicStateFlow_P.Constant4_Value;

  /* RateTransition: '<S7>/Rate Transition' */
  if (AvionicStateFlow_M->Timing.RateInteraction.TID0_2) {
    AvionicStateFlow_DW.RateTransition_Buffer = AvionicStateFlow_B.h_AGL;
  }

  /* End of RateTransition: '<S7>/Rate Transition' */
  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  AvionicStateFlow_B.b3 = floor(AvionicStateFlow_B.a21);
  if (rtIsNaN(AvionicStateFlow_B.b3) || rtIsInf(AvionicStateFlow_B.b3)) {
    AvionicStateFlow_B.b3 = 0.0;
  } else {
    AvionicStateFlow_B.b3 = fmod(AvionicStateFlow_B.b3, 256.0);
  }

  rtb_DataTypeConversion2 = (uint8_T)(AvionicStateFlow_B.b3 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-AvionicStateFlow_B.b3 : (int32_T)(uint8_T)
    AvionicStateFlow_B.b3);

  /* End of DataTypeConversion: '<S6>/Data Type Conversion2' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(AvionicStateFlow_DW.obj_n.MW_DIGITALIO_HANDLE,
                     rtb_DataTypeConversion2 != 0);

  /* MATLABSystem: '<Root>/Red LED' */
  rc_led_set(1, rtb_DataTypeConversion2);

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(0, (real_T)AvionicStateFlow_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(AvionicStateFlow_M)!=-1) &&
        !((rtmGetTFinal(AvionicStateFlow_M)-AvionicStateFlow_M->Timing.taskTime0)
          > AvionicStateFlow_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(AvionicStateFlow_M, "Simulation finished");
    }

    if (rtmGetStopRequested(AvionicStateFlow_M)) {
      rtmSetErrorStatus(AvionicStateFlow_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  AvionicStateFlow_M->Timing.taskTime0 =
    ((time_T)(++AvionicStateFlow_M->Timing.clockTick0)) *
    AvionicStateFlow_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void AvionicStateFlow_step1(void)      /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Output;
  uint8_T rtb_FixPtSum1;

  /* MultiPortSwitch: '<S20>/Output' incorporates:
   *  Constant: '<S20>/Vector'
   *  UnitDelay: '<S27>/Output'
   */
  rtb_Output =
    AvionicStateFlow_P.RepeatingSequenceStair2_OutValu[AvionicStateFlow_DW.Output_DSTATE];

  /* RateTransition: '<S6>/Rate Transition3' */
  AvionicStateFlow_DW.RateTransition3_Buffer0_i = rtb_Output;

  /* Sum: '<S28>/FixPt Sum1' incorporates:
   *  Constant: '<S28>/FixPt Constant'
   *  UnitDelay: '<S27>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)AvionicStateFlow_DW.Output_DSTATE +
    AvionicStateFlow_P.FixPtConstant_Value);

  /* Switch: '<S29>/FixPt Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  UnitDelay: '<S27>/Output'
   */
  if (rtb_FixPtSum1 > AvionicStateFlow_P.LimitedCounter_uplimit) {
    AvionicStateFlow_DW.Output_DSTATE = AvionicStateFlow_P.Constant_Value_ou;
  } else {
    AvionicStateFlow_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S29>/FixPt Switch' */

  /* MultiPortSwitch: '<S19>/Output' incorporates:
   *  Constant: '<S19>/Vector'
   *  UnitDelay: '<S24>/Output'
   */
  rtb_Output =
    AvionicStateFlow_P.RepeatingSequenceStair1_OutValu[AvionicStateFlow_DW.Output_DSTATE_a];

  /* RateTransition: '<S6>/Rate Transition1' */
  AvionicStateFlow_DW.RateTransition1_Buffer0 = rtb_Output;

  /* Sum: '<S25>/FixPt Sum1' incorporates:
   *  Constant: '<S25>/FixPt Constant'
   *  UnitDelay: '<S24>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)AvionicStateFlow_DW.Output_DSTATE_a +
    AvionicStateFlow_P.FixPtConstant_Value_c);

  /* Switch: '<S26>/FixPt Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  UnitDelay: '<S24>/Output'
   */
  if (rtb_FixPtSum1 > AvionicStateFlow_P.LimitedCounter_uplimit_e) {
    AvionicStateFlow_DW.Output_DSTATE_a = AvionicStateFlow_P.Constant_Value_c;
  } else {
    AvionicStateFlow_DW.Output_DSTATE_a = rtb_FixPtSum1;
  }

  /* End of Switch: '<S26>/FixPt Switch' */

  /* MultiPortSwitch: '<S18>/Output' incorporates:
   *  Constant: '<S18>/Vector'
   *  UnitDelay: '<S21>/Output'
   */
  rtb_Output =
    AvionicStateFlow_P.RepeatingSequenceStair_OutValue[AvionicStateFlow_DW.Output_DSTATE_c];

  /* RateTransition: '<S6>/Rate Transition2' */
  AvionicStateFlow_DW.RateTransition2_Buffer0 = rtb_Output;

  /* Sum: '<S22>/FixPt Sum1' incorporates:
   *  Constant: '<S22>/FixPt Constant'
   *  UnitDelay: '<S21>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint32_T)AvionicStateFlow_DW.Output_DSTATE_c +
    AvionicStateFlow_P.FixPtConstant_Value_n);

  /* Switch: '<S23>/FixPt Switch' incorporates:
   *  Constant: '<S23>/Constant'
   *  UnitDelay: '<S21>/Output'
   */
  if (rtb_FixPtSum1 > AvionicStateFlow_P.LimitedCounter_uplimit_d) {
    AvionicStateFlow_DW.Output_DSTATE_c = AvionicStateFlow_P.Constant_Value_g;
  } else {
    AvionicStateFlow_DW.Output_DSTATE_c = rtb_FixPtSum1;
  }

  /* End of Switch: '<S23>/FixPt Switch' */
  rtExtModeUpload(1, (real_T)((AvionicStateFlow_M->Timing.clockTick1) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  AvionicStateFlow_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void AvionicStateFlow_step2(void)      /* Sample time: [0.2s, 0.0s] */
{
  real_T rtb_Uk1;

  /* UnitDelay: '<S30>/UD'
   *
   * Block description for '<S30>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Uk1 = AvionicStateFlow_DW.UD_DSTATE;

  /* SampleTimeMath: '<S30>/TSamp' incorporates:
   *  RateTransition: '<S7>/Rate Transition'
   *  UnitDelay: '<S30>/UD'
   *
   * About '<S30>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S30>/UD':
   *
   *  Store in Global RAM
   */
  AvionicStateFlow_DW.UD_DSTATE = AvionicStateFlow_DW.RateTransition_Buffer *
    AvionicStateFlow_P.TSamp_WtEt;

  /* RateTransition: '<S7>/Rate Transition3' incorporates:
   *  Sum: '<S30>/Diff'
   *  UnitDelay: '<S30>/UD'
   *
   * Block description for '<S30>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S30>/UD':
   *
   *  Store in Global RAM
   */
  AvionicStateFlow_DW.RateTransition3_Buffer0 = AvionicStateFlow_DW.UD_DSTATE -
    rtb_Uk1;
  rtExtModeUpload(2, (real_T)((AvionicStateFlow_M->Timing.clockTick2) * 0.2));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  AvionicStateFlow_M->Timing.clockTick2++;
}

/* Model wrapper function for compatibility with a static main program */
void AvionicStateFlow_step(int_T tid)
{
  switch (tid) {
   case 0 :
    AvionicStateFlow_step0();
    break;

   case 1 :
    AvionicStateFlow_step1();
    break;

   case 2 :
    AvionicStateFlow_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void AvionicStateFlow_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(AvionicStateFlow_M, -1);
  AvionicStateFlow_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  AvionicStateFlow_M->Sizes.checksums[0] = (329668525U);
  AvionicStateFlow_M->Sizes.checksums[1] = (3846635709U);
  AvionicStateFlow_M->Sizes.checksums[2] = (655668396U);
  AvionicStateFlow_M->Sizes.checksums[3] = (770457555U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[23];
    AvionicStateFlow_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)
      &AvionicStateFlow_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &AvionicStateFlow_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &AvionicStateFlow_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &AvionicStateFlow_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &AvionicStateFlow_DW.IfActionSubsystem4_SubsysRanBC;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AvionicStateFlow_M->extModeInfo,
      &AvionicStateFlow_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AvionicStateFlow_M->extModeInfo,
                        AvionicStateFlow_M->Sizes.checksums);
    rteiSetTPtr(AvionicStateFlow_M->extModeInfo, rtmGetTPtr(AvionicStateFlow_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AvionicStateFlow_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    MW_I2C_Mode_Type ModeType;
    uint32_T i2cname;
    beagleboneblue_bbblueDigitalW_T *obj_0;
    beagleboneblue_bbblueI2CMaste_T *obj;

    /* Start for RateTransition: '<S7>/Rate Transition3' */
    AvionicStateFlow_B.RateTransition3 =
      AvionicStateFlow_P.RateTransition3_InitialConditio;

    /* Start for RateTransition: '<S6>/Rate Transition1' */
    AvionicStateFlow_B.RateTransition1_l =
      AvionicStateFlow_P.RateTransition1_InitialConditio;

    /* Start for RateTransition: '<S6>/Rate Transition2' */
    AvionicStateFlow_B.RateTransition2 =
      AvionicStateFlow_P.RateTransition2_InitialConditio;

    /* Start for RateTransition: '<S6>/Rate Transition3' */
    AvionicStateFlow_B.RateTransition3_l =
      AvionicStateFlow_P.RateTransition3_InitialCondit_h;

    /* InitializeConditions for RateTransition: '<S7>/Rate Transition3' */
    AvionicStateFlow_DW.RateTransition3_Buffer0 =
      AvionicStateFlow_P.RateTransition3_InitialConditio;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition1' */
    AvionicStateFlow_DW.RateTransition1_Buffer0 =
      AvionicStateFlow_P.RateTransition1_InitialConditio;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition2' */
    AvionicStateFlow_DW.RateTransition2_Buffer0 =
      AvionicStateFlow_P.RateTransition2_InitialConditio;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition3' */
    AvionicStateFlow_DW.RateTransition3_Buffer0_i =
      AvionicStateFlow_P.RateTransition3_InitialCondit_h;

    /* InitializeConditions for UnitDelay: '<S27>/Output' */
    AvionicStateFlow_DW.Output_DSTATE =
      AvionicStateFlow_P.Output_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S24>/Output' */
    AvionicStateFlow_DW.Output_DSTATE_a =
      AvionicStateFlow_P.Output_InitialCondition_c;

    /* InitializeConditions for UnitDelay: '<S21>/Output' */
    AvionicStateFlow_DW.Output_DSTATE_c =
      AvionicStateFlow_P.Output_InitialCondition_i;

    /* InitializeConditions for UnitDelay: '<S30>/UD'
     *
     * Block description for '<S30>/UD':
     *
     *  Store in Global RAM
     */
    AvionicStateFlow_DW.UD_DSTATE =
      AvionicStateFlow_P.DiscreteDerivative_ICPrevScaled;

    /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function2' */
    memset(&AvionicStateFlow_DW.P[0], 0, 9U * sizeof(real_T));
    AvionicStateFlow_DW.P[0] = 1.0;
    AvionicStateFlow_DW.P[4] = 1.0;
    AvionicStateFlow_DW.P[8] = 1.0;

    /* SystemInitialize for IfAction SubSystem: '<S6>/If Action Subsystem1' */
    /* SystemInitialize for Outport: '<S14>/Outport' incorporates:
     *  Inport: '<S14>/Input'
     */
    AvionicStateFlow_B.Input = AvionicStateFlow_P.Outport_Y0;

    /* End of SystemInitialize for SubSystem: '<S6>/If Action Subsystem1' */

    /* Start for MATLABSystem: '<S1>/Barometer' */
    AvionicStateFlow_DW.obj.i2cObj.matlabCodegenIsDeleted = true;
    AvionicStateFlow_DW.obj.matlabCodegenIsDeleted = true;
    bbblueBarometer_bbblueBarometer(&AvionicStateFlow_DW.obj);
    AvionicStateFlow_DW.obj.SampleTime = AvionicStateFlow_P.Barometer_SampleTime;
    AvionicStateFl_SystemCore_setup(&AvionicStateFlow_DW.obj);

    /* Start for MATLABSystem: '<S1>/I2C Master Read' */
    AvionicStateFlow_DW.obj_i.matlabCodegenIsDeleted = true;
    AvionicStateFlow_DW.obj_i.DefaultMaximumBusSpeedInHz = 400000.0;
    AvionicStateFlow_DW.obj_i.isInitialized = 0;
    AvionicStateFlow_DW.obj_i.SampleTime = -1.0;
    AvionicStateFlow_DW.obj_i.matlabCodegenIsDeleted = false;
    AvionicStateFlow_DW.obj_i.SampleTime =
      AvionicStateFlow_P.I2CMasterRead_SampleTime;
    obj = &AvionicStateFlow_DW.obj_i;
    AvionicStateFlow_DW.obj_i.isSetupComplete = false;
    AvionicStateFlow_DW.obj_i.isInitialized = 1;
    ModeType = MW_I2C_MASTER;
    i2cname = 1;
    obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
    AvionicStateFlow_DW.obj_i.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(AvionicStateFlow_DW.obj_i.MW_I2C_HANDLE,
                       AvionicStateFlow_DW.obj_i.BusSpeed);
    AvionicStateFlow_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/MPU9250' */
    AvionicStateFlow_DW.obj_f.isInitialized = 0;
    AvionicStateFlow_DW.obj_f.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
    AvionicStateFlow_DW.obj_f.i2cObjmpu.matlabCodegenIsDeleted = false;
    AvionicStateFlow_DW.obj_f.i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
    AvionicStateFlow_DW.obj_f.i2cObjak8963.matlabCodegenIsDeleted = false;
    AvionicStateFlow_DW.obj_f.matlabCodegenIsDeleted = false;
    AvionicStateFlow_DW.obj_f.SampleTime = AvionicStateFlow_P.MPU9250_SampleTime;
    AvionicState_SystemCore_setup_e(&AvionicStateFlow_DW.obj_f);

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    AvionicStateFlow_DW.obj_k.matlabCodegenIsDeleted = true;
    AvionicStateFlow_DW.obj_k.isInitialized = 0;
    AvionicStateFlow_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &AvionicStateFlow_DW.obj_k;
    AvionicStateFlow_DW.obj_k.isSetupComplete = false;
    AvionicStateFlow_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(98, 1);
    AvionicStateFlow_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    AvionicStateFlow_DW.obj_n.matlabCodegenIsDeleted = true;
    AvionicStateFlow_DW.obj_n.isInitialized = 0;
    AvionicStateFlow_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &AvionicStateFlow_DW.obj_n;
    AvionicStateFlow_DW.obj_n.isSetupComplete = false;
    AvionicStateFlow_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(57, 1);
    AvionicStateFlow_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Red LED' */
    AvionicStateFlow_DW.obj_d.matlabCodegenIsDeleted = false;
    AvionicStateFlow_DW.obj_d.isInitialized = 1;
    AvionicStateFlow_DW.obj_d.isSetupComplete = true;
  }
}

/* Model terminate function */
void AvionicStateFlow_terminate(void)
{
  f_beagleboneblue_bbblueI2CMas_T *obj;
  h_beagleboneblue_bbblueI2CMas_T *obj_1;
  i_beagleboneblue_bbblueI2CMas_T *obj_0;

  /* Terminate for MATLABSystem: '<S1>/Barometer' */
  if (!AvionicStateFlow_DW.obj.matlabCodegenIsDeleted) {
    AvionicStateFlow_DW.obj.matlabCodegenIsDeleted = true;
  }

  obj = &AvionicStateFlow_DW.obj.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Barometer' */

  /* Terminate for MATLABSystem: '<S1>/I2C Master Read' */
  if (!AvionicStateFlow_DW.obj_i.matlabCodegenIsDeleted) {
    AvionicStateFlow_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((AvionicStateFlow_DW.obj_i.isInitialized == 1) &&
        AvionicStateFlow_DW.obj_i.isSetupComplete) {
      MW_I2C_Close(AvionicStateFlow_DW.obj_i.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/I2C Master Read' */

  /* Terminate for MATLABSystem: '<S5>/MPU9250' */
  if (!AvionicStateFlow_DW.obj_f.matlabCodegenIsDeleted) {
    AvionicStateFlow_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  obj_0 = &AvionicStateFlow_DW.obj_f.i2cObjak8963;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }

  obj_1 = &AvionicStateFlow_DW.obj_f.i2cObjmpu;
  if (!obj_1->matlabCodegenIsDeleted) {
    obj_1->matlabCodegenIsDeleted = true;
    if (obj_1->isInitialized == 1) {
      obj_1->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/MPU9250' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!AvionicStateFlow_DW.obj_k.matlabCodegenIsDeleted) {
    AvionicStateFlow_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((AvionicStateFlow_DW.obj_k.isInitialized == 1) &&
        AvionicStateFlow_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(AvionicStateFlow_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!AvionicStateFlow_DW.obj_n.matlabCodegenIsDeleted) {
    AvionicStateFlow_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((AvionicStateFlow_DW.obj_n.isInitialized == 1) &&
        AvionicStateFlow_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(AvionicStateFlow_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Red LED' */
  if (!AvionicStateFlow_DW.obj_d.matlabCodegenIsDeleted) {
    AvionicStateFlow_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((AvionicStateFlow_DW.obj_d.isInitialized == 1) &&
        AvionicStateFlow_DW.obj_d.isSetupComplete) {
      rc_led_cleanup();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Red LED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
