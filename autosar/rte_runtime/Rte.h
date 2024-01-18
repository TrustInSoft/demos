/**************************************************************************/
/*                                                                        */
/*  This file is part of TrustInSoft Analyzer.                            */
/*                                                                        */
/*    Copyright (C) 2023 TrustInSoft                                      */
/*                                                                        */
/*  All rights reserved.                                                  */
/*                                                                        */
/**************************************************************************/

#ifndef RTE_H
#define RTE_H

#include "Std_Types.h"

/***********************************************************************************************************************
 *  PLATFORM INFORMATION MACRO
 **********************************************************************************************************************/

#if AUTOSAR_VERSION <= 41
/* AUTOSAR release R4-2 */
#define RTE_AR_RELEASE_MAJOR_VERSION (4u)
#define RTE_AR_RELEASE_MINOR_VERSION (2u)
#define RTE_AR_RELEASE_REVISION_VERSION (2u)
#elif 42 <= AUTOSAR_VERSION <= 45
/* AUTOSAR release R4-3 */
#define RTE_AR_RELEASE_MAJOR_VERSION (4u)
#define RTE_AR_RELEASE_MINOR_VERSION (3u)
#define RTE_AR_RELEASE_REVISION_VERSION (1u)
#elif 46 <= AUTOSAR_VERSION <= 47
/* AUTOSAR release R4-4 */
#define RTE_AR_RELEASE_MAJOR_VERSION (4u)
#define RTE_AR_RELEASE_MINOR_VERSION (4u)
#define RTE_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 48
/* AUTOSAR release R19-11 */
#define RTE_AR_RELEASE_MAJOR_VERSION (4u)
#define RTE_AR_RELEASE_MINOR_VERSION (5u)
#define RTE_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 49
/* AUTOSAR release R20-11 */
#define RTE_AR_RELEASE_MAJOR_VERSION (4u)
#define RTE_AR_RELEASE_MINOR_VERSION (6u)
#define RTE_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 50
/* AUTOSAR release R21-11 */
#define RTE_AR_RELEASE_MAJOR_VERSION (4u)
#define RTE_AR_RELEASE_MINOR_VERSION (7u)
#define RTE_AR_RELEASE_REVISION_VERSION (0u)
#elif AUTOSAR_VERSION == 51
/* AUTOSAR release R22-11 */
#define RTE_AR_RELEASE_MAJOR_VERSION (4u)
#define RTE_AR_RELEASE_MINOR_VERSION (8u)
#define RTE_AR_RELEASE_REVISION_VERSION (0u)
#endif // AUTOSAR VERSION

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACRO
 **********************************************************************************************************************/

/* Common errors. */
#define RTE_E_OK (0U)
#define RTE_E_INVALID (1U)

/* Immediate infrastructure errors. */
#define RTE_E_COM_STOPPED (128U)
#define RTE_E_TIMEOUT (129U)
#define RTE_E_LIMIT (130U)
#define RTE_E_NO_DATA (131U)
#define RTE_E_TRANSMIT_ACK (132U)
#define RTE_E_NEVER_RECEIVED (133U)
#define RTE_E_UNCONNECTED (134U)
#define RTE_E_IN_EXCLUSIVE_AREA (135U)
#define RTE_E_SEG_FAULT (136U)
#define RTE_E_OUT_OF_RANGE (137U)
#define RTE_E_SERIALIZATION_ERROR (138U)
#define RTE_E_HARD_TRANSFORMER_ERROR (138U)
#define RTE_E_SERIALIZATION_LIMIT (139U)
#define RTE_E_TRANSFORMER_LIMIT (139U)
#define RTE_E_SOFT_TRANSFORMER_ERROR (140U)
#define RTE_E_COM_BUSY (141U)
#ifdef AUTOSAR_VERSION >= 49 // AUTOSAR_R20_11
#define RTE_E_RAM_UNCHANGED (142U)
#endif // AUTOSAR_VERSION >= 49

/* Overlayed errors. */
#define RTE_E_LOST_DATA (64U)
#define RTE_E_MAX_AGE_EXCEEDED (64U)

#endif // RTE_H