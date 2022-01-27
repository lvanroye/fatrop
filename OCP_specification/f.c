/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) f_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_f1 CASADI_PREFIX(f1)
#define casadi_f10 CASADI_PREFIX(f10)
#define casadi_f11 CASADI_PREFIX(f11)
#define casadi_f12 CASADI_PREFIX(f12)
#define casadi_f13 CASADI_PREFIX(f13)
#define casadi_f2 CASADI_PREFIX(f2)
#define casadi_f3 CASADI_PREFIX(f3)
#define casadi_f4 CASADI_PREFIX(f4)
#define casadi_f5 CASADI_PREFIX(f5)
#define casadi_f6 CASADI_PREFIX(f6)
#define casadi_f7 CASADI_PREFIX(f7)
#define casadi_f8 CASADI_PREFIX(f8)
#define casadi_f9 CASADI_PREFIX(f9)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)
#define casadi_s6 CASADI_PREFIX(s6)
#define casadi_s7 CASADI_PREFIX(s7)
#define casadi_s8 CASADI_PREFIX(s8)
#define casadi_s9 CASADI_PREFIX(s9)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_sq(casadi_real x) { return x*x;}

static const casadi_int casadi_s0[7] = {3, 1, 0, 3, 0, 1, 2};
static const casadi_int casadi_s1[6] = {2, 1, 0, 2, 0, 1};
static const casadi_int casadi_s2[24] = {6, 3, 0, 6, 12, 18, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};
static const casadi_int casadi_s3[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s4[4] = {0, 1, 0, 0};
static const casadi_int casadi_s5[38] = {6, 5, 0, 6, 12, 18, 24, 30, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};
static const casadi_int casadi_s6[9] = {5, 1, 0, 5, 0, 1, 2, 3, 4};
static const casadi_int casadi_s7[18] = {4, 3, 0, 4, 8, 12, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
static const casadi_int casadi_s8[3] = {6, 0, 0};
static const casadi_int casadi_s9[3] = {4, 0, 0};

/* BAbt:(i0[3],i1[3],i2[2])->(o0[6x3]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2, a3, a4;
  a0=1.;
  if (res[0]!=0) res[0][0]=a0;
  a1=0.;
  if (res[0]!=0) res[0][1]=a1;
  if (res[0]!=0) res[0][2]=a0;
  if (res[0]!=0) res[0][3]=a1;
  if (res[0]!=0) res[0][4]=a1;
  a2=arg[0]? arg[0][0] : 0;
  a3=arg[1]? arg[1][0] : 0;
  a4=arg[2]? arg[2][0] : 0;
  a3=(a3+a4);
  a2=(a2-a3);
  if (res[0]!=0) res[0][5]=a2;
  if (res[0]!=0) res[0][6]=a1;
  if (res[0]!=0) res[0][7]=a0;
  if (res[0]!=0) res[0][8]=a1;
  if (res[0]!=0) res[0][9]=a0;
  if (res[0]!=0) res[0][10]=a1;
  a2=arg[0]? arg[0][1] : 0;
  a3=arg[1]? arg[1][1] : 0;
  a4=arg[2]? arg[2][1] : 0;
  a3=(a3+a4);
  a2=(a2-a3);
  if (res[0]!=0) res[0][11]=a2;
  if (res[0]!=0) res[0][12]=a1;
  if (res[0]!=0) res[0][13]=a1;
  if (res[0]!=0) res[0][14]=a1;
  if (res[0]!=0) res[0][15]=a1;
  if (res[0]!=0) res[0][16]=a0;
  a0=arg[0]? arg[0][2] : 0;
  a1=arg[1]? arg[1][2] : 0;
  a0=(a0-a1);
  if (res[0]!=0) res[0][17]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int BAbt(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int BAbt_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int BAbt_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void BAbt_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int BAbt_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void BAbt_release(int mem) {
}

CASADI_SYMBOL_EXPORT void BAbt_incref(void) {
}

CASADI_SYMBOL_EXPORT void BAbt_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int BAbt_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int BAbt_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real BAbt_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* BAbt_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* BAbt_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* BAbt_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* BAbt_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int BAbt_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* bk:(i0[3],i1[3],i2[2])->(o0[3]) */
static int casadi_f1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[1]? arg[1][0] : 0;
  a2=arg[2]? arg[2][0] : 0;
  a1=(a1+a2);
  a0=(a0-a1);
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[0]? arg[0][1] : 0;
  a1=arg[1]? arg[1][1] : 0;
  a2=arg[2]? arg[2][1] : 0;
  a1=(a1+a2);
  a0=(a0-a1);
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[0]? arg[0][2] : 0;
  a1=arg[1]? arg[1][2] : 0;
  a0=(a0-a1);
  if (res[0]!=0) res[0][2]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int bk(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f1(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int bk_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int bk_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void bk_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int bk_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void bk_release(int mem) {
}

CASADI_SYMBOL_EXPORT void bk_incref(void) {
}

CASADI_SYMBOL_EXPORT void bk_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int bk_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int bk_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real bk_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* bk_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* bk_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* bk_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* bk_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int bk_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* RSQrqtI:(i0,i1[3],i2[2],i3[3],i4[0])->(o0[6x5]) */
static int casadi_f2(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1;
  a0=0.;
  if (res[0]!=0) res[0][0]=a0;
  if (res[0]!=0) res[0][1]=a0;
  if (res[0]!=0) res[0][2]=a0;
  if (res[0]!=0) res[0][3]=a0;
  if (res[0]!=0) res[0][4]=a0;
  if (res[0]!=0) res[0][5]=a0;
  if (res[0]!=0) res[0][6]=a0;
  if (res[0]!=0) res[0][7]=a0;
  if (res[0]!=0) res[0][8]=a0;
  if (res[0]!=0) res[0][9]=a0;
  if (res[0]!=0) res[0][10]=a0;
  if (res[0]!=0) res[0][11]=a0;
  if (res[0]!=0) res[0][12]=a0;
  if (res[0]!=0) res[0][13]=a0;
  if (res[0]!=0) res[0][14]=a0;
  if (res[0]!=0) res[0][15]=a0;
  if (res[0]!=0) res[0][16]=a0;
  a1=arg[0]? arg[0][0] : 0;
  if (res[0]!=0) res[0][17]=a1;
  if (res[0]!=0) res[0][18]=a0;
  if (res[0]!=0) res[0][19]=a0;
  if (res[0]!=0) res[0][20]=a0;
  if (res[0]!=0) res[0][21]=a0;
  if (res[0]!=0) res[0][22]=a0;
  if (res[0]!=0) res[0][23]=a0;
  if (res[0]!=0) res[0][24]=a0;
  if (res[0]!=0) res[0][25]=a0;
  if (res[0]!=0) res[0][26]=a0;
  if (res[0]!=0) res[0][27]=a0;
  if (res[0]!=0) res[0][28]=a0;
  if (res[0]!=0) res[0][29]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int RSQrqtI(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f2(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int RSQrqtI_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int RSQrqtI_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void RSQrqtI_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int RSQrqtI_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void RSQrqtI_release(int mem) {
}

CASADI_SYMBOL_EXPORT void RSQrqtI_incref(void) {
}

CASADI_SYMBOL_EXPORT void RSQrqtI_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int RSQrqtI_n_in(void) { return 5;}

CASADI_SYMBOL_EXPORT casadi_int RSQrqtI_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real RSQrqtI_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* RSQrqtI_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    case 4: return "i4";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* RSQrqtI_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* RSQrqtI_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    case 3: return casadi_s0;
    case 4: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* RSQrqtI_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s5;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int RSQrqtI_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 5;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* rqI:(i0,i1[3],i2[2])->(o0[5]) */
static int casadi_f3(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1;
  a0=0.;
  if (res[0]!=0) res[0][0]=a0;
  if (res[0]!=0) res[0][1]=a0;
  a1=arg[0]? arg[0][0] : 0;
  if (res[0]!=0) res[0][2]=a1;
  if (res[0]!=0) res[0][3]=a0;
  if (res[0]!=0) res[0][4]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int rqI(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f3(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int rqI_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int rqI_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void rqI_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int rqI_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void rqI_release(int mem) {
}

CASADI_SYMBOL_EXPORT void rqI_incref(void) {
}

CASADI_SYMBOL_EXPORT void rqI_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int rqI_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int rqI_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real rqI_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* rqI_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* rqI_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* rqI_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* rqI_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s6;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int rqI_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* RSQrqt:(i0,i1[3],i2[2],i3[3],i4[0])->(o0[6x5]) */
static int casadi_f4(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1;
  a0=0.;
  if (res[0]!=0) res[0][0]=a0;
  if (res[0]!=0) res[0][1]=a0;
  if (res[0]!=0) res[0][2]=a0;
  if (res[0]!=0) res[0][3]=a0;
  if (res[0]!=0) res[0][4]=a0;
  if (res[0]!=0) res[0][5]=a0;
  if (res[0]!=0) res[0][6]=a0;
  if (res[0]!=0) res[0][7]=a0;
  if (res[0]!=0) res[0][8]=a0;
  if (res[0]!=0) res[0][9]=a0;
  if (res[0]!=0) res[0][10]=a0;
  if (res[0]!=0) res[0][11]=a0;
  if (res[0]!=0) res[0][12]=a0;
  if (res[0]!=0) res[0][13]=a0;
  if (res[0]!=0) res[0][14]=a0;
  if (res[0]!=0) res[0][15]=a0;
  if (res[0]!=0) res[0][16]=a0;
  a1=arg[0]? arg[0][0] : 0;
  if (res[0]!=0) res[0][17]=a1;
  if (res[0]!=0) res[0][18]=a0;
  if (res[0]!=0) res[0][19]=a0;
  if (res[0]!=0) res[0][20]=a0;
  if (res[0]!=0) res[0][21]=a0;
  if (res[0]!=0) res[0][22]=a0;
  if (res[0]!=0) res[0][23]=a0;
  if (res[0]!=0) res[0][24]=a0;
  if (res[0]!=0) res[0][25]=a0;
  if (res[0]!=0) res[0][26]=a0;
  if (res[0]!=0) res[0][27]=a0;
  if (res[0]!=0) res[0][28]=a0;
  if (res[0]!=0) res[0][29]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int RSQrqt(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f4(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int RSQrqt_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int RSQrqt_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void RSQrqt_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int RSQrqt_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void RSQrqt_release(int mem) {
}

CASADI_SYMBOL_EXPORT void RSQrqt_incref(void) {
}

CASADI_SYMBOL_EXPORT void RSQrqt_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int RSQrqt_n_in(void) { return 5;}

CASADI_SYMBOL_EXPORT casadi_int RSQrqt_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real RSQrqt_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* RSQrqt_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    case 4: return "i4";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* RSQrqt_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* RSQrqt_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    case 3: return casadi_s0;
    case 4: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* RSQrqt_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s5;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int RSQrqt_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 5;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* rqk:(i0,i1[3],i2[2])->(o0[5]) */
static int casadi_f5(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1;
  a0=0.;
  if (res[0]!=0) res[0][0]=a0;
  if (res[0]!=0) res[0][1]=a0;
  a1=arg[0]? arg[0][0] : 0;
  if (res[0]!=0) res[0][2]=a1;
  if (res[0]!=0) res[0][3]=a0;
  if (res[0]!=0) res[0][4]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int rqk(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f5(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int rqk_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int rqk_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void rqk_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int rqk_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void rqk_release(int mem) {
}

CASADI_SYMBOL_EXPORT void rqk_incref(void) {
}

CASADI_SYMBOL_EXPORT void rqk_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int rqk_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int rqk_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real rqk_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* rqk_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* rqk_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* rqk_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* rqk_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s6;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int rqk_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* Lk:(i0,i1[3],i2[2])->(o0) */
static int casadi_f6(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[1]? arg[1][0] : 0;
  a0=(a0*a1);
  if (res[0]!=0) res[0][0]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int Lk(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f6(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int Lk_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int Lk_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Lk_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int Lk_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Lk_release(int mem) {
}

CASADI_SYMBOL_EXPORT void Lk_incref(void) {
}

CASADI_SYMBOL_EXPORT void Lk_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int Lk_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int Lk_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real Lk_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Lk_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Lk_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Lk_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Lk_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int Lk_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* RSQrqtF:(i0,i1[3],i2[2],i3[3],i4[0])->(o0[4x3]) */
static int casadi_f7(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2, a3;
  a0=2.;
  a1=arg[0]? arg[0][0] : 0;
  a2=(a0*a1);
  if (res[0]!=0) res[0][0]=a2;
  a2=0.;
  if (res[0]!=0) res[0][1]=a2;
  if (res[0]!=0) res[0][2]=a2;
  a3=arg[1]? arg[1][0] : 0;
  a3=(a3+a3);
  a3=(a3*a1);
  if (res[0]!=0) res[0][3]=a3;
  if (res[0]!=0) res[0][4]=a2;
  a3=(a0*a1);
  if (res[0]!=0) res[0][5]=a3;
  if (res[0]!=0) res[0][6]=a2;
  a3=arg[1]? arg[1][1] : 0;
  a3=(a3+a3);
  a3=(a3*a1);
  if (res[0]!=0) res[0][7]=a3;
  if (res[0]!=0) res[0][8]=a2;
  if (res[0]!=0) res[0][9]=a2;
  a0=(a0*a1);
  if (res[0]!=0) res[0][10]=a0;
  a0=arg[1]? arg[1][2] : 0;
  a0=(a0+a0);
  a0=(a0*a1);
  if (res[0]!=0) res[0][11]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int RSQrqtF(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f7(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int RSQrqtF_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int RSQrqtF_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void RSQrqtF_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int RSQrqtF_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void RSQrqtF_release(int mem) {
}

CASADI_SYMBOL_EXPORT void RSQrqtF_incref(void) {
}

CASADI_SYMBOL_EXPORT void RSQrqtF_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int RSQrqtF_n_in(void) { return 5;}

CASADI_SYMBOL_EXPORT casadi_int RSQrqtF_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real RSQrqtF_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* RSQrqtF_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    case 4: return "i4";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* RSQrqtF_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* RSQrqtF_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    case 3: return casadi_s0;
    case 4: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* RSQrqtF_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s7;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int RSQrqtF_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 5;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* rqF:(i0,i1[3],i2[2])->(o0[3]) */
static int casadi_f8(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1;
  a0=arg[1]? arg[1][0] : 0;
  a0=(a0+a0);
  a1=arg[0]? arg[0][0] : 0;
  a0=(a0*a1);
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[1]? arg[1][1] : 0;
  a0=(a0+a0);
  a0=(a0*a1);
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[1]? arg[1][2] : 0;
  a0=(a0+a0);
  a0=(a0*a1);
  if (res[0]!=0) res[0][2]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int rqF(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f8(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int rqF_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int rqF_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void rqF_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int rqF_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void rqF_release(int mem) {
}

CASADI_SYMBOL_EXPORT void rqF_incref(void) {
}

CASADI_SYMBOL_EXPORT void rqF_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int rqF_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int rqF_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real rqF_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* rqF_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* rqF_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* rqF_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* rqF_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int rqF_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* LF:(i0,i1[3],i2[2])->(o0) */
static int casadi_f9(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2;
  a0=arg[0]? arg[0][0] : 0;
  a1=arg[1]? arg[1][0] : 0;
  a1=casadi_sq(a1);
  a2=arg[1]? arg[1][1] : 0;
  a2=casadi_sq(a2);
  a1=(a1+a2);
  a2=arg[1]? arg[1][2] : 0;
  a2=casadi_sq(a2);
  a1=(a1+a2);
  a0=(a0*a1);
  if (res[0]!=0) res[0][0]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int LF(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f9(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int LF_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int LF_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void LF_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int LF_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void LF_release(int mem) {
}

CASADI_SYMBOL_EXPORT void LF_incref(void) {
}

CASADI_SYMBOL_EXPORT void LF_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int LF_n_in(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_int LF_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real LF_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* LF_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* LF_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* LF_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* LF_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int LF_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 3;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* GgtI:(i0[3],i1[2])->(o0[6x0]) */
static int casadi_f10(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT int GgtI(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f10(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int GgtI_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int GgtI_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void GgtI_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int GgtI_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void GgtI_release(int mem) {
}

CASADI_SYMBOL_EXPORT void GgtI_incref(void) {
}

CASADI_SYMBOL_EXPORT void GgtI_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int GgtI_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int GgtI_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real GgtI_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* GgtI_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* GgtI_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* GgtI_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* GgtI_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s8;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int GgtI_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* gI:(i0[3],i1[2])->(o0[0]) */
static int casadi_f11(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT int gI(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f11(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int gI_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int gI_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void gI_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int gI_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void gI_release(int mem) {
}

CASADI_SYMBOL_EXPORT void gI_incref(void) {
}

CASADI_SYMBOL_EXPORT void gI_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int gI_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int gI_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real gI_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* gI_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* gI_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* gI_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* gI_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int gI_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* GgtF:(i0[3],i1[2])->(o0[4x0]) */
static int casadi_f12(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT int GgtF(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f12(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int GgtF_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int GgtF_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void GgtF_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int GgtF_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void GgtF_release(int mem) {
}

CASADI_SYMBOL_EXPORT void GgtF_incref(void) {
}

CASADI_SYMBOL_EXPORT void GgtF_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int GgtF_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int GgtF_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real GgtF_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* GgtF_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* GgtF_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* GgtF_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* GgtF_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s9;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int GgtF_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}

/* gF:(i0[3],i1[2])->(o0[0]) */
static int casadi_f13(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT int gF(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f13(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int gF_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int gF_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void gF_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int gF_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void gF_release(int mem) {
}

CASADI_SYMBOL_EXPORT void gF_incref(void) {
}

CASADI_SYMBOL_EXPORT void gF_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int gF_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int gF_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real gF_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* gF_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* gF_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* gF_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* gF_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int gF_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
