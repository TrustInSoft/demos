/**************************************************************************/
/*                                                                        */
/*  This file is part of TrustInSoft Analyzer.                            */
/*                                                                        */
/*    Copyright (C) 2023 TrustInSoft                                      */
/*                                                                        */
/*  All rights reserved.                                                  */
/*                                                                        */
/**************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"
#include "Compiler.h"

/***********************************************************************************************************************
 *  PLATFORM INFORMATION MACRO
 **********************************************************************************************************************/

#if AUTOSAR_VERSION <= 41
/* AUTOSAR release R4-2 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION (2u)
#define STD_TYPES_AR_RELEASE_REVISION_VERSION (2u)
#elif 42 <= AUTOSAR_VERSION <= 45
/* AUTOSAR release R4-3 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION (3u)
#define STD_TYPES_AR_RELEASE_REVISION_VERSION (1u)
#elif 46 <= AUTOSAR_VERSION <= 47
/* AUTOSAR release R4-4 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 48
/* AUTOSAR release R19-11 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION (5u)
#define STD_TYPES_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 49
/* AUTOSAR release R20-11 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION (6u)
#define STD_TYPES_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 50
/* AUTOSAR release R21-11 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION (7u)
#define STD_TYPES_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 51
/* AUTOSAR release R22-11 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION (4u)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION (8u)
#define STD_TYPES_AR_RELEASE_REVISION_VERSION (0u)
#endif // AUTOSAR VERSION

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

typedef uint8 Std_ReturnType;

typedef struct Std_VersionInfoType
{
  uint16 vendorID;
  uint16 moduleID;
  uint8 sw_major_version;
  uint8 sw_minor_version;
  uint8 sw_patch_version;
} Std_VersionInfoType;

typedef uint8 Std_TransformerErrorCode;

typedef uint8 Std_TransformerClass;

#define STD_TRANSFORMER_UNSPECIFIED 0x00
#define STD_TRANSFORMER_SERIALIZER 0x01
#define STD_TRANSFORMER_SAFETY 0x02
#define STD_TRANSFORMER_SECURITY 0x03
#define STD_TRANSFORMER_CUSTOM 0xFF

typedef struct Std_TransformerError
{
  Std_TransformerErrorCode errorCode;
  Std_TransformerClass transformerClass;
} Std_TransformerError;

#if AUTOSAR_VERSION >= 49 // AUTOSAR_R20_11
typedef uint8 Std_MessageTypeType;

#define STD_MESSAGETYPE_REQUEST 0x00
#define STD_MESSAGETYPE_RESPONSE 0x01

typedef uint8 Std_MessageResultType;

#define STD_MESSAGERESULT_OK 0x00
#define STD_MESSAGERESULT_ERROR 0x01
#endif // AUTOSAR_VERSION >= 49

/***********************************************************************************************************************
 *  FUNCTIONS POINTERS
 **********************************************************************************************************************/

#if AUTOSAR_VERSION >= 49 // AUTOSAR_R20_11
Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType)(
    const uint8 *buffer,
    uint32 bufferLength,
    Std_MessageTypeType *messageType,
    Std_MessageResultType *messageResult);
#endif // AUTOSAR_VERSION >= 49

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACRO
 **********************************************************************************************************************/

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u

#define STD_HIGH 0x01u /* Physical state 5V or 3.3V */
#define STD_LOW 0x00u  /* Physical state 0V */

#define STD_ACTIVE 0x01u /* Logical state active */
#define STD_IDLE 0x00u   /* Logical state idle */

#define STD_ON 0x01u
#define STD_OFF 0x00u

#if AUTOSAR_VERSION >= 50 // AUTOSAR_R21_11
#define NULL_PTR ((void *)0)
#endif // AUTOSAR_VERSION >= 50

#endif /* STD_TYPES_H */