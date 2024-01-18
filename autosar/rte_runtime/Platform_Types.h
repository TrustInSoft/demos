/**************************************************************************/
/*                                                                        */
/*  This file is part of TrustInSoft Analyzer.                            */
/*                                                                        */
/*    Copyright (C) 2023 TrustInSoft                                      */
/*                                                                        */
/*  All rights reserved.                                                  */
/*                                                                        */
/**************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#include <stdbool.h>

/***********************************************************************************************************************
 *  PLATFORM INFORMATION MACRO
 **********************************************************************************************************************/

#if AUTOSAR_VERSION <= 41
/* AUTOSAR release R4-2 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (2u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION (2u)
#elif 42 <= AUTOSAR_VERSION <= 45
/* AUTOSAR release R4-3 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (3u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION (1u)
#elif 46 <= AUTOSAR_VERSION <= 47
/* AUTOSAR release R4-4 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 48
/* AUTOSAR release R19-11 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (5u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 49
/* AUTOSAR release R20-11 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (6u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 50
/* AUTOSAR release R21-11 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (7u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 51
/* AUTOSAR release R22-11 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (8u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION (0u)
#endif // AUTOSAR VERSION

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACRO
 **********************************************************************************************************************/

#define CPU_TYPE_8 (8u)
#define CPU_TYPE_16 (16u)
#define CPU_TYPE_32 (32u)
#if AUTOSAR_VERSION >= 42 // AUTOSAR R4_3_0 (not a final revision).
#define CPU_TYPE_64 (64u)
#endif // AUTOSAR_VERSION >= 42

#define MSB_FIRST (0u) /* Big endian bit ordering. */
#define LSB_FIRST (1u) /* Little endian bit ordering. */

#define HIGH_BYTE_FIRST (0u) /* Big endian byte ordering. */
#define LOW_BYTE_FIRST (1u)  /* Little endian byte ordering. */

#ifndef TRUE
#define TRUE true
#endif

#ifndef FALSE
#define FALSE false
#endif

#if defined(__TIS_MACHDEP_X86_16) ||      \
    defined(__TIS_MACHDEP_X86_16_GCC) ||  \
    defined(__TIS_MACHDEP_X86_16_HUGE) || \
    defined(__TIS_MACHDEP_X86_16_HUGE_GCC)
#define CPU_TYPE CPU_TYPE_16
#elif defined(__TIS_MACHDEP_X86_32) ||       \
    defined(__TIS_MACHDEP_X86_32_GCC) ||     \
    defined(__TIS_MACHDEP_X86_WIN32) ||      \
    defined(__TIS_MACHDEP_PPC_32) ||         \
    defined(__TIS_MACHDEP_PPC_32_GCC) ||     \
    defined(__TIS_MACHDEP_APPLE_PPC_32) ||   \
    defined(__TIS_MACHDEP_ARM_EABI) ||       \
    defined(__TIS_MACHDEP_ARM_EABI_GCC) ||   \
    defined(__TIS_MACHDEP_ARMEB_EABI) ||     \
    defined(__TIS_MACHDEP_ARMEB_EABI_GCC) || \
    defined(__TIS_MACHDEP_SPARC_32) ||       \
    defined(__TIS_MACHDEP_SPARC_32_GCC) ||   \
    defined(__TIS_MACHDEP_MIPS_O32) ||       \
    defined(__TIS_MACHDEP_MIPS_O32_GCC) ||   \
    defined(__TIS_MACHDEP_MIPSEL_O32) ||     \
    defined(__TIS_MACHDEP_MIPSEL_O32_GCC) || \
    defined(__TIS_MACHDEP_MIPS_N32) ||       \
    defined(__TIS_MACHDEP_MIPS_N32_GCC) ||   \
    defined(__TIS_MACHDEP_MIPSEL_N32) ||     \
    defined(__TIS_MACHDEP_MIPSEL_N32_GCC) || \
    defined(__TIS_MACHDEP_RV32IFDQ) ||       \
    defined(__TIS_MACHDEP_RV32IFDQ_GCC)
#define CPU_TYPE CPU_TYPE_32
#elif AUTOSAR_VERSION >= 42 &&               \
    (defined(__TIS_MACHDEP_X86_64) ||        \
     defined(__TIS_MACHDEP_X86_64_GCC) ||    \
     defined(__TIS_MACHDEP_X86_WIN64) ||     \
     defined(__TIS_MACHDEP_PPC_64) ||        \
     defined(__TIS_MACHDEP_PPC_64_GCC) ||    \
     defined(__TIS_MACHDEP_AARCH64) ||       \
     defined(__TIS_MACHDEP_AARCH64_GCC) ||   \
     defined(__TIS_MACHDEP_AARCH64EB) ||     \
     defined(__TIS_MACHDEP_AARCH64EB_GCC) || \
     defined(__TIS_MACHDEP_SPARC_64) ||      \
     defined(__TIS_MACHDEP_SPARC_64_GCC) ||  \
     defined(__TIS_MACHDEP_MIPS_64) ||       \
     defined(__TIS_MACHDEP_MIPS_64_GCC) ||   \
     defined(__TIS_MACHDEP_MIPSEL_64) ||     \
     defined(__TIS_MACHDEP_MIPSEL_64_GCC) || \
     defined(__TIS_MACHDEP_RV64IFDQ) ||      \
     defined(__TIS_MACHDEP_RV64IFDQ_GCC))
#define CPU_TYPE CPU_TYPE_64
#else
#error "Unknown processor architecture"
#endif /* CPU_TYPE. */

// This as an impact only on the hardware level, which can be ignored in this
// context.
#define CPU_BIT_ORDER LSB_FIRST /* Little endian bit ordering. */

#if defined(__TIS_MACHDEP_X86_16) ||          \
    defined(__TIS_MACHDEP_X86_16_GCC) ||      \
    defined(__TIS_MACHDEP_X86_16_HUGE) ||     \
    defined(__TIS_MACHDEP_X86_16_HUGE_GCC) || \
    defined(__TIS_MACHDEP_X86_32) ||          \
    defined(__TIS_MACHDEP_X86_32_GCC) ||      \
    defined(__TIS_MACHDEP_X86_WIN32) ||       \
    defined(__TIS_MACHDEP_ARM_EABI) ||        \
    defined(__TIS_MACHDEP_ARM_EABI_GCC) ||    \
    defined(__TIS_MACHDEP_MIPSEL_O32) ||      \
    defined(__TIS_MACHDEP_MIPSEL_O32_GCC) ||  \
    defined(__TIS_MACHDEP_MIPSEL_N32) ||      \
    defined(__TIS_MACHDEP_MIPSEL_N32_GCC) ||  \
    defined(__TIS_MACHDEP_RV32IFDQ) ||        \
    defined(__TIS_MACHDEP_RV32IFDQ_GCC) ||    \
    defined(__TIS_MACHDEP_X86_64) ||          \
    defined(__TIS_MACHDEP_X86_64_GCC) ||      \
    defined(__TIS_MACHDEP_X86_WIN64) ||       \
    defined(__TIS_MACHDEP_AARCH64) ||         \
    defined(__TIS_MACHDEP_AARCH64_GCC) ||     \
    defined(__TIS_MACHDEP_MIPSEL_64) ||       \
    defined(__TIS_MACHDEP_MIPSEL_64_GCC) ||   \
    defined(__TIS_MACHDEP_RV64IFDQ) ||        \
    defined(__TIS_MACHDEP_RV64IFDQ_GCC)

#define CPU_BYTE_ORDER LOW_BYTE_FIRST /* Little endian byte ordering. */

#else

#define CPU_BYTE_ORDER HIGH_BYTE_FIRST /* Big endian byte ordering. */

#endif /* Endian definition. */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if 41 <= AUTOSAR_VERSION <= 50 // Between AUTOSAR_R4_2 and AUTOSAR_R21_11.
#define Rte_TypeDef_boolean
typedef unsigned char boolean;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#elif AUTOSAR_VERSION >= 51 // AUTOSAR_R22_11
// [SRS_BSW_00378].
#define Rte_TypeDef_boolean
typedef _Bool boolean; /*        TRUE .. FALSE           */

#ifndef TRUE
#define TRUE true
#endif
#ifndef FALSE
#define FALSE false
#endif
#endif // AUTOSAR VERSION

#define Rte_TypeDef_sint8
typedef signed char sint8; /*        -127 .. +127            */

#define Rte_TypeDef_uint8
typedef unsigned char uint8; /*           0 .. 255             */

#define Rte_TypeDef_sint16
typedef signed short sint16; /*      -32767 .. +32767          */

#define Rte_TypeDef_uint16
typedef unsigned short uint16; /*           0 .. 65535           */

#define Rte_TypeDef_sint32
#if CPU_TYPE == CPU_TYPE_16
typedef signed long sint32; /* -2147483647 .. +2147483647     */
#else
typedef signed int sint32; /* -2147483647 .. +2147483647     */
#endif

#define Rte_TypeDef_uint32
#if CPU_TYPE == CPU_TYPE_16
typedef unsigned long uint32; /*           0 .. 4294967295      */
#else
typedef unsigned int uint32; /*           0 .. 4294967295      */
#endif

#define Rte_TypeDef_sint8_least
typedef signed char sint8_least; /* At least 7 bit + 1 bit sign    */

#define Rte_TypeDef_uint8_least
typedef unsigned char uint8_least; /* At least 8 bit                 */

#define Rte_TypeDef_sint16_least
typedef signed short sint16_least; /* At least 15 bit + 1 bit sign   */

#define Rte_TypeDef_uint16_least
typedef unsigned short uint16_least; /* At least 16 bit                */

#define Rte_TypeDef_sint32_least
#if CPU_TYPE == CPU_TYPE_16
typedef signed long sint32_least; /* At least 31 bit + 1 bit sign   */
#else
typedef signed int sint32_least; /* At least 31 bit + 1 bit sign   */
#endif

#define Rte_TypeDef_uint32_least
#if CPU_TYPE == CPU_TYPE_16
typedef unsigned long uint32_least; /* At least 32 bit                */
#else
typedef unsigned int uint32_least; /* At least 32 bit                */
#endif

#define Rte_TypeDef_float32
typedef float float32;

#define Rte_TypeDef_float64
typedef double float64;

#define Rte_TypeDef_sint64
#if defined(__TIS_MACHDEP_X86_WIN64) || CPU_TYPE != CPU_TYPE_64
typedef signed long long sint64; /* -9223372036854775808 .. 9223372036854775807 */
#else
typedef signed long sint64; /* -9223372036854775808 .. 9223372036854775807 */
#endif

#define Rte_TypeDef_uint64
#if defined(__TIS_MACHDEP_X86_WIN64) || CPU_TYPE != CPU_TYPE_64
typedef unsigned long long uint64; /* 0 .. 18446744073709551615 */
#else
typedef unsigned long uint64; /* 0 .. 18446744073709551615 */
#endif

#if AUTOSAR_VERSION >= 49 // AUTOSAR_R20_11
#define Rte_TypeDef_VoidPtr
typedef void *VoidPtr;

#define Rte_TypeDef_ConstVoidPtr
typedef const void *ConstVoidPtr;
#endif // AUTOSAR_VERSION >= 49

#endif /* PLATFORM_TYPES_H */