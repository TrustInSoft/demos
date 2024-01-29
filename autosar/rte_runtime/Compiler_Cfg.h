/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2015 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Compiler_Cfg.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This is a VTT.pro-specific version of the MICROSAR _Compiler_Cfg.h template.
 *                USE ONLY IN VTT.pro PROJECTS!
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* Package Merger: Start Section CompilerCfgIncludes */


#include <Rte_Compiler_Cfg.h>

/* Package Merger: Stop Section CompilerCfgIncludes */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE  REGSPACE

/* Configurable memory class for pointers to registers (e.g. static volatile CONSTP2VAR(uint16, PWM_CONST, REGSPACE)). */
#define REGSPACE


/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/* Package Merger: Start Section CompilerCfgModuleList */

#define V_SUPPRESS_EXTENDED_VERSION_CHECK
/* #define V_EXTENDED_BUILD_LIB_CHECK */
#define V_USE_DUMMY_STATEMENT  STD_ON



/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

#define COMM_CODE

#define COMM_CONST
#define COMM_PBCFG

#define COMM_VAR_NOINIT
#define COMM_VAR_ZERO_INIT
#define COMM_VAR_PBCFG

#define COMM_APPL_VAR
#define COMM_NVM_DATA

/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CanSM START
 *********************************************************************************************************************/

#define CANSM_CODE

#define CANSM_CONST


#define CANSM_APPL_CODE

#define CANSM_VAR_NOINIT
#define CANSM_VAR_ZERO_INIT

#define CANSM_APPL_VAR


/**********************************************************************************************************************
 *  CanSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FrSM START
 *********************************************************************************************************************/

#define FRSM_CODE
#define FRSM_APPL_CODE

#define FRSM_CONST
#define FRSM_PBCFG

#define FRSM_VAR_NOINIT
#define FRSM_VAR_ZERO_INIT

#define FRSM_APPL_VAR


/**********************************************************************************************************************
 *  FrSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LINSM START 
 *********************************************************************************************************************/

#define LINSM_CODE
#define LINSM_CONST
#define LINSM_PBCFG
#define LINSM_VAR_NOINIT
#define LINSM_VAR_ZERO_INIT
#define LINSM_APPL_DATA


/**********************************************************************************************************************
 *  LINSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSM START 
 *********************************************************************************************************************/

#define ETHSM_CODE

#define ETHSM_CONST
#define ETHSM_APPL_CONST
#define ETHSM_PBCFG
#define ETHSM_APPL_DATA

#define ETHSM_VAR_NOINIT

/**********************************************************************************************************************
 *  ETHSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Cdd_AsrCdd START 
 *********************************************************************************************************************/

/* Copy the compiler abstraction defines for each of your configured CDDs and replace the prefix _CDD with the MSN of your configured CDD as higher case. */

#define _CDD_CODE
#define _CDD_APPL_DATA

/* Add additional compiler abstraction defines for each of you configured CDDs here. */

/**********************************************************************************************************************
 *  Cdd_AsrCdd END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

#define XCP_CONST
#define XCP_CODE
#define XCP_APPL_DATA
#define XCP_MTA_DATA
#define XCP_DAQ_DATA
#define XCP_VAR_NOINIT


/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANXCP START 
 *********************************************************************************************************************/

#define CANXCP_VAR_NOINIT
#define CANXCP_CONST
#define CANXCP_PBCFG
#define CANXCP_CODE
#define CANXCP_APPL_VAR

/*-------------------------------------------------------------------------------------------------------------------*/
/* CANXCP END                                                                                                        */
/*-------------------------------------------------------------------------------------------------------------------*/




/**********************************************************************************************************************
 *  FRXCP START 
 *********************************************************************************************************************/

#define FRXCP_PBCFG
#define FRXCP_CONST
#define FRXCP_CODE
#define FRXCP_APPL_DATA
#define FRXCP_VAR_NOINIT

/**********************************************************************************************************************
 *  FRXCP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  TCPIPXCP START 
 *********************************************************************************************************************/

#define TCPIPXCP_VAR_NOINIT
#define TCPIPXCP_CONST
#define TCPIPXCP_PBCFG
#define TCPIPXCP_CODE
#define TCPIPXCP_APPL_VAR
#define TCPIPXCP_APPL_DATA

/*-------------------------------------------------------------------------------------------------------------------*/
/* TCPIPXCP END                                                                                                        */
/*-------------------------------------------------------------------------------------------------------------------*/



#define DCM_CODE                /* code */
#define DCM_CONST               /* global/static constants */
#define DCM_CAL_PRM             /* calibrateable constants */
#define DCM_APPL_CODE           /* callback functions outside of Dcm */
#define DCM_APPL_CONST          /* constants outside Dcm */ 
#define DCM_APPL_DATA           /* variables/buffers outside of Dcm */
#define DCM_CALLOUT_CODE        /* callback functions outside of Dcm but part of Dcm (callouts) */
#define DCM_VAR_INIT            /* initialized global/static variables */
#define DCM_VAR_NOINIT          /* uninitialized global/static variables */
#define DCM_VAR_PBCFG           /* global/static variable for PostBuildLoadable */
#define DCM_PBCFG               /* global/static constants for PostBuildLoadable */



/*==== DEM ==================================================================*/
#define DEM_CODE                /* code */
#define DEM_VAR_INIT            /* initialized global/static variables */
#define DEM_VAR_NOINIT          /* uninitialized global/static variables */
#define DEM_CONST               /* global/static constants */
#define DEM_CONST_ROOT          /* global/static constants */
#define DEM_PBCFG               /* global/static constants for PostBuild */
#define DEM_PBCFG_ROOT          /* global/static constants for PostBuild */
#define DEM_DCM_DATA            /* variables/buffers passed by Dcm to Dem */
#define DEM_J1939DCM_DATA       /* variables/buffers passed by J1939Dcm to Dem */
#define DEM_DLT_DATA            /* variables/buffers passed by Dlt to Dem */
#define DEM_NVM_DATA            /* variables/buffers managed by NvM */
#define DEM_APPL_CODE           /* callback functions outside of Dem */
#define DEM_APPL_DATA           /* variables/buffers outside of Dem */
#define DEM_APPL_CONST          /* constants outside Dem */
#define DEM_SHARED_DATA         /* variables/buffers shared by all */
#define DEM_CAL_PRM             /* calibrateable constants */
#define DEM_NVM_DATA_NOINIT     DEM_NVM_DATA
/*===========================================================================*/



/**********************************************************************************************************************
 *  J1939DCM START
 *********************************************************************************************************************/
#define J1939DCM_CODE

#define J1939DCM_CONST
#define J1939DCM_PBCFG

#define J1939DCM_VAR_INIT
#define J1939DCM_VAR_NOINIT

#define J1939DCM_APPL_DATA


/**********************************************************************************************************************
 *  J1939DCM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvAdc_VttCanoe01Asr START
 **********************************************************************************************************************/

#define ADC_APPL_DATA
#define ADC_CONST
#define ADC_CODE
#define ADC_APPL_CONST
#define ADC_PBCFG
#define ADC_APPL_VAR
#define ADC_VAR
#define ADC_APPL_CODE

/**********************************************************************************************************************
 *  DrvAdc_VttCanoe01Asr END
 **********************************************************************************************************************/



/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */


/**********************************************************************************************************************
 *  Can START 
 *********************************************************************************************************************/

#define CAN_CODE                                   /* CAN modules code qualifier               */ /* PRQA S 0883 */ /* Appears only while testing */
#define CAN_STATIC_CODE                            /* CAN local code qualifier                 */
#define CAN_CONST                                  /* constant memory                          */
#define CAN_CONST_PBCFG                            /* postbuild generated constant/flash       */
#define CAN_VAR_NOINIT                             /* none initialized variables               */
#define CAN_VAR_INIT                               /* initialized variables                    */
#define CAN_VAR_PBCFG                              /* postbuild generated variables/dynamic RAM (CFG5 only) */
#define CAN_INT_CTRL                               /* access to Interrupt controller registers */
#define CAN_REG_CANCELL                            /* CAN cell register qualifier              */
#define CAN_RX_TX_DATA        CAN_REG_CANCELL      /* pointer width >= CAN_REG_CANCELL  / CAN rx/tx data / RAM or SFR    (rx data pointer for Indication and PreCopy functions to higher layers / tx data pointers / sdu  from application)   */
#define CAN_APPL_CODE                              /* Application code qualifier               */
#define CAN_APPL_CONST                             /* Application constant memory              */
#define CAN_APPL_VAR                               /* Application variables                    */

/**********************************************************************************************************************
 *  Can END
 *********************************************************************************************************************/
#define CAN_PBCFG  CAN_CONST_PBCFG                 /* used for compatibility (used by upper layer EcuM) */

/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */
/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 475 */




/**********************************************************************************************************************
 *  DrvDio_VTTCanoe01Asr START 
 **********************************************************************************************************************/

#define DIO_APPL_DATA
#define DIO_CONST
#define DIO_CODE
#define DIO_APPL_CONST

/**********************************************************************************************************************
 *  DrvDio_VTTCanoe01Asr END
 **********************************************************************************************************************/




/**********************************************************************************************************************
 *  DrvEep_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define EEP_APPL_CODE
#define EEP_CONST
#define EEP_APPL_DATA
#define EEP_APPL_CONST
#define EEP_PBCFG
#define EEP_CODE
#define EEP_VAR

/**********************************************************************************************************************
 *  DrvEep_VttCanoe01Asr END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETH START 
 *********************************************************************************************************************/

#define ETH_CODE
#define ETH_CODE_ISR

#define ETH_CONST
#define ETH_APPL_CONST
#define ETH_PBCFG
#define ETH_APPL_DATA

#define ETH_APPL_VAR
#define ETH_VAR_NOINIT
#define ETH_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETH END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvFls_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define FLS_APPL_CODE
#define FLS_CONST
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_CODE
#define FLS_VAR

/**********************************************************************************************************************
 *  DrvFls_VttCanoe01Asr END
 **********************************************************************************************************************/




/**********************************************************************************************************************
 *  FR START 
 *********************************************************************************************************************/

#define FR_CODE                                                       /* FR modules code qualifier */
#define FR_CODE_ISR                                                   /* module interrupt service routines */

#define FR_CONST                                                      /* FR constant memory */
#define FR_APPL_CONST                                                 /* Application constant memory, coming from outside of the module */
#define FR_PBCFG                                                      /* postbuild generated constant/flash */
#define FR_APPL_DATA                                                  /* memory class for pointers to application data (expected to be in RAM or ROM) passed via API */
#define FR_VAR_FRM_DATA                                               /* memory class for pointers to Flexray memory data in RAM */
#define FR_APPL_CODE                                                  /* memory class for pointers to application functions (e.g. call back function pointers) */

#define FR_VAR_NOINIT                                                 /* none initialized variables. To be used for all global or static variables that are never initialized */
#define FR_VAR_NOINIT_FAST                                            /* like FR_VAR_NOINIT, optimized access */
#define FR_VAR_ZERO_INIT




/**********************************************************************************************************************
 *  FR END
 *********************************************************************************************************************/






/**********************************************************************************************************************
 *  DrvGpt_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define GPT_APPL_DATA
#define GPT_CONST
#define GPT_CODE
#define GPT_PBCFG
#define GPT_APPL_CONST
#define GPT_VAR


/**********************************************************************************************************************
 *  DrvGpt_VttCanoe01Asr END
 **********************************************************************************************************************/




/**********************************************************************************************************************
 *  DrvIcu_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define ICU_CODE
#define ICU_APPL_CODE
#define ICU_APPL_CONST
#define ICU_APPL_DATA
#define ICU_VAR

/**********************************************************************************************************************
 *  DrvIcu_VttCanoe01Asr END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  LIN DRIVER START
 *********************************************************************************************************************/

#define LIN_CODE
#define LIN_CODE_FAST
#define LIN_CODE_ISR

#define LIN_CONST
#define LIN_CONST_FAST
#define LIN_PBCFG

#define LIN_VAR_PBCFG
#define LIN_VAR_INIT
#define LIN_VAR_NOINIT
#define LIN_VAR_ZERO_INIT
#define LIN_VAR_INIT_FAST
#define LIN_VAR_NOINIT_FAST
#define LIN_VAR_ZERO_INIT_FAST

#define LIN_VAR_INIT_NOCACHE
#define LIN_VAR_NOINIT_NOCACHE
#define LIN_VAR_ZERO_INIT_NOCACHE

#define LIN_APPL_VAR
#define LIN_VAR_REGS

/**********************************************************************************************************************
 *  LIN DRIVER END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  DrvMcu_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define MCU_APPL_DATA
#define MCU_CONST
#define MCU_CODE
#define MCU_APPL_CONST
#define MCU_VAR


/**********************************************************************************************************************
 *  DrvMcu_VttCanoe01Asr END
 **********************************************************************************************************************/




/**********************************************************************************************************************
 *  DrvPort_VttCanoe01Asr START 
 *********************************************************************************************************************/

#define PORT_CODE
#define PORT_VAR
#define PORT_CONST
#define PORT_APPL_CODE
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_PBCFG
#define PORT_REGISTER

/**********************************************************************************************************************
 *  DrvPort_VttCanoe01Asr END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvPwm_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define PWM_CODE
#define PWM_APPL_CODE
#define PWM_APPL_CONST
#define PWM_APPL_DATA
#define PWM_VAR

/**********************************************************************************************************************
 *  DrvPwm_VttCanoe01Asr END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvSpi_VttCanoe01Asr START
 **********************************************************************************************************************/

#define SPI_APPL_DATA
#define SPI_CODE
#define SPI_APPL_CONST
#define SPI_VAR

/**********************************************************************************************************************
 *  DrvSpi_VttCanoe01Asr END
 **********************************************************************************************************************/


#define CANTRCV_30___YOUR_TRCV___CONST /* PRQA S 0883 */ /* Appears only while testing */
#define CANTRCV_30___YOUR_TRCV___VAR
#define CANTRCV_30___YOUR_TRCV___VAR_NOINIT
#define CANTRCV_30___YOUR_TRCV___APPL_VAR
#define CANTRCV_30___YOUR_TRCV___CODE
#define CANTRCV_30___YOUR_TRCV___APPL_CODE
#define CANTRCV_30___YOUR_TRCV___PBCFG



/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

#define FRTRCV_CONST
#define FRTRCV_30___YOUR_TRCV___CONST
#define FRTRCV_30___YOUR_TRCV___VAR_NOINIT
#define FRTRCV_30___YOUR_TRCV___CODE
#define FRTRCV_30___YOUR_TRCV___APPL_DATA
#define FRTRCV_30___YOUR_TRCV___APPL_CODE

/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/


#define LINTRCV_30___YOUR_TRCV___VAR
#define LINTRCV_30___YOUR_TRCV___VAR_ZERO_INIT
#define LINTRCV_30___YOUR_TRCV___APPL_VAR
#define LINTRCV_30___YOUR_TRCV___CONST
#define LINTRCV_30___YOUR_TRCV___CODE
#define LINTRCV_30___YOUR_TRCV___APPL_CODE
#define LINTRCV_30___YOUR_TRCV___VAR_NOINIT



/**********************************************************************************************************************
 *  ETHTRCV 30 VTT START 
 *********************************************************************************************************************/

#define ETHTRCV_30_VTT_CODE

#define ETHTRCV_30_VTT_CONST
#define ETHTRCV_30_VTT_APPL_CONST
#define ETHTRCV_30_VTT_PBCFG
#define ETHTRCV_30_VTT_APPL_DATA

#define ETHTRCV_30_VTT_VAR_NOINIT
#define ETHTRCV_30_VTT_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETHTRCV 30 VTT END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvWd_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define WDG_CODE
#define WDG_APPL_CONST
#define WDG_VAR

/**********************************************************************************************************************
 *  DrvWd_VttCanoe01Asr END
 **********************************************************************************************************************/




/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

#define IOHWAB_CODE

#define IOHWAB_VAR

#define IOHWAB_APPL_DATA
#define IOHWAB_APPL_CODE

#define IOHWAB_CONST

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

#define PDUR_CODE
#define PDUR_VAR_NOINIT
#define PDUR_VAR_ZERO_INIT
#define PDUR_VAR
#define PDUR_CONST
#define PDUR_PBCFG
#define PDUR_VAR_PBCFG
#define PDUR_APPL_DATA
#define PDUR_APPL_CODE

/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LIN INTERFACE START
 *********************************************************************************************************************/

#define LINIF_CODE
#define LINIF_CONST
#define LINIF_VAR_NOINIT
#define LINIF_VAR_ZERO_INIT
#define LINIF_VAR_PBCFG
#define LINIF_APPL_DATA
#define LINIF_APPL_VAR
#define LINIF_PBCFG
#define LINIF_APPL_PBCFG
#define LINIF_CBK_TRCV_CODE

/**********************************************************************************************************************
 *  LIN INTERFACE END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LIN TP START
 *********************************************************************************************************************/

#define LINTP_CODE
#define LINTP_CONST
#define LINTP_VAR_NOINIT
#define LINTP_VAR_ZERO_INIT
#define LINTP_VAR_PBCFG
#define LINTP_APPL_DATA
#define LINTP_APPL_VAR
#define LINTP_PBCFG
#define LINTP_APPL_PBCFG

/**********************************************************************************************************************
 *  LIN TP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANIF START 
 *********************************************************************************************************************/

#define CANIF_CODE
#define CANIF_CODE_FAST
#define CANIF_CODE_ISR


#define CANIF_CONST
#define CANIF_CONST_FAST
#define CANIF_PBCFG

#define CANIF_VAR_PBCFG /* ESCAN00065502 */

#define CANIF_VAR_INIT
#define CANIF_VAR_NOINIT
#define CANIF_VAR_ZERO_INIT

#define CANIF_VAR_INIT_FAST
#define CANIF_VAR_NOINIT_FAST
#define CANIF_VAR_ZERO_INIT_FAST

#define CANIF_VAR_INIT_NOCACHE
#define CANIF_VAR_NOINIT_NOCACHE
#define CANIF_VAR_ZERO_INIT_NOCACHE


#define CANIF_APPL_CODE
#define CANIF_APPL_VAR
#define CANIF_APPL_PBCFG


/*-------------------------------------------------------------------------------------------------------------------*/

/* Has to be kept in default section -> Default access */
#define CANIF_VAR_STACK


/* VAR section of higher layers (TP / NM / PduR / CanSM / EcuM) automatically mapped to APPL_VAR */
#define CANIF_APPL_STATE_VAR   CANIF_APPL_VAR
#define CANIF_APPL_MSG_VAR     CANIF_APPL_VAR

/* VAR section of lower layers (CAN Driver / Transceiver Driver) automatically mapped to APPL_VAR */
#define CANIF_CBK_VAR          CANIF_APPL_VAR

/* #define CANIF_CBK_TRCV_VAR     CANIF_CBK_VAR    not used yet */
#define CANIF_CBK_DRV_VAR      CANIF_CBK_VAR

/* Code sections - DO NOT MODIFY */
#define CANIF_CBK_TRCV_CODE     CANIF_APPL_CODE
#define CANIF_CBK_CANDRV_CODE   CANIF_APPL_CODE
#define CANIF_APPL_STATE_CODE   CANIF_APPL_CODE
#define CANIF_APPL_MSG_CODE     CANIF_APPL_CODE


/* Upper layer data pointer */
#define CANIF_UL_STANDARD_VAR    CANIF_APPL_VAR
#define CANIF_UL_ADVANCED_VAR    CANIF_APPL_VAR
#define CANIF_UL_OSEKNM_VAR      CANIF_APPL_VAR

/**********************************************************************************************************************
 *  CANIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  If_AsrIfEa START 
 *********************************************************************************************************************/

#define EA_PUBLIC_CODE
#define EA_PRIVATE_CODE

#define EA_APPL_DATA
#define EA_FAST_DATA

#define EA_PRIVATE_CONST
#define EA_PUBLIC_CONST

#define EA_NVM_CODE

/* In ASR4 SchM/RTE declares Ea_MainFunction, using EA_CODE *
 * It MUST be defined to EA_PUBLIC_CODE!                     */
#define EA_CODE EA_PUBLIC_CODE

/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHIF START 
 *********************************************************************************************************************/

#define ETHIF_CODE
#define ETHIF_CODE_ISR

#define ETHIF_CONST

#define ETHIF_PBCFG

#define ETHIF_APPL_CONST
#define ETHIF_APPL_VAR
#define ETHIF_APPL_DATA

#define ETHIF_VAR_NOINIT
#define ETHIF_VAR_NOINIT_FAST

/**********************************************************************************************************************
 *  ETHIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FEE START 
 *********************************************************************************************************************/

#define FEE_API_CODE
#define FEE_APPL_CODE
#define FEE_APPL_CONFIG
#define FEE_APPL_DATA
#define FEE_CONST
#define FEE_PRIVATE_CODE
#define FEE_PRIVATE_CONST
#define FEE_PRIVATE_DATA
#define FEE_VAR
#define FEE_VAR_NOINIT

/* In ASR4 SchM/RTE declares NvM_MainFunction, using FEE_CODE *
 * It MUST be defined to FEE_API_CODE!                     */
#define FEE_CODE FEE_API_CODE

/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRIF START 
 *********************************************************************************************************************/

#define FRIF_CODE
#define FRIF_CODE_FAST
#define FRIF_CODE_ISR

#define FRIF_CONST
#define FRIF_CONST_FAST
#define FRIF_PBCFG
#define FRIF_PBCFG_ROOT

#define FRIF_VAR_INIT
#define FRIF_VAR_NOINIT
#define FRIF_VAR_ZERO_INIT
#define FRIF_VAR_INIT_FAST
#define FRIF_VAR_NOINIT_FAST
#define FRIF_VAR_PBCFG
#define FRIF_VAR_ZERO_INIT_FAST

#define FRIF_APPL_DATA
#define FRIF_APPL_CODE

/**********************************************************************************************************************
 *  FRIF END
 *********************************************************************************************************************/


#define MEMIF_CODE
#define MEMIF_CONST
#define MEMIF_APPL_DATA


/**********************************************************************************************************************
 *  SOAD START 
 *********************************************************************************************************************/

#define SOAD_CODE

#define SOAD_APPL_CONST
#define SOAD_APPL_DATA
#define SOAD_APPL_VAR
#define SOAD_CONST
#define SOAD_PBCFG

#define SOAD_VAR_NOINIT   SOAD_APPL_VAR
#define SOAD_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  SOAD END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  If_AsrIfWd START
 *********************************************************************************************************************/

#define WDGIF_CODE
#define WDGIF_CONST
#define WDGIF_WDG_CODE
#define WDGIF_APPL_DATA

/**********************************************************************************************************************
 *  If_AsrIfWd END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define COM_CONST
/* Module Constant Data of the Postbuild Configuration */
#define COM_PBCFG
/* Module Var Data of the Postbuild Configuration */
#define COM_VAR_PBCFG


/* Module Implementation */
#define COM_CODE

/* Module Variables which are initialized by the startup code or by the call of Com_InitMemory() */
#define COM_VAR_NOINIT
/* Module Variables which are initialized by call of Com_Init() */
#define COM_VAR_ZERO_INIT
/* Module Variables which are initialized by call of Com_Init() */
#define COM_VAR_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define COM_APPL_CODE
/* Application Buffer which is located in RAM */
#define COM_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define COM_APPL_DATA

/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  IpduM START 
 *********************************************************************************************************************/

#define IPDUM_CODE
#define IPDUM_CONST
#define IPDUM_PBCFG
#define IPDUM_VAR_PBCFG
#define IPDUM_VAR_INIT
#define IPDUM_VAR_ZERO_INIT
#define IPDUM_VAR_NOINIT
#define IPDUM_APPL_DATA

/**********************************************************************************************************************
 *  IpduM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LDCOM START
 *********************************************************************************************************************/
/* Module Implementation */
#define LDCOM_CODE

/* Module Constant Data */
#define LDCOM_CONST
/* Module Constant Data of the Postbuild Configuration */
#define LDCOM_PBCFG
/* Module Var Data of the Postbuild Configuration */
#define LDCOM_VAR_PBCFG

/* Module Variables which are initialized by call of LdCom_Init() */
#define LDCOM_VAR_INIT
/* Module Variables which are initialized by the startup code or by the call of LdCom_InitMemory() */
#define LDCOM_VAR_NOINIT
/* Module Variables which are initialized by call of LdCom_Init() */
#define LDCOM_VAR_ZERO_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define LDCOM_APPL_CODE
/* Application Buffer which is located in RAM */
#define LDCOM_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define LDCOM_APPL_DATA

/**********************************************************************************************************************
 *  LDCOM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SECOC START 
 *********************************************************************************************************************/
/* Module Implementation */
#define SECOC_CODE

/* Module Constant Data */
#define SECOC_CONST
/* Module Constant Data of the Postbuild Configuration */
#define SECOC_PBCFG
/* Module Var Data of the Postbuild Configuration */
#define SECOC_VAR_PBCFG


/* Module Variables which are initialized by call of SecOC_Init() */
#define SECOC_VAR_INIT
/* Module Variables which are initialized by the startup code or by the call of SecOC_InitMemory() */
#define SECOC_VAR_NOINIT
/* Module Variables which are initialized by call of SecOC_Init() */
#define SECOC_VAR_ZERO_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define SECOC_APPL_CODE
/* Application Buffer which is located in RAM */
#define SECOC_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define SECOC_APPL_DATA

/**********************************************************************************************************************
 *  SECOC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  J1939RM START
 *********************************************************************************************************************/

#define J1939RM_CODE
#define J1939RM_APPL_CODE

#define J1939RM_CONST
#define J1939RM_PBCFG
#define J1939RM_APPL_DATA

#define J1939RM_VAR_NOINIT
#define J1939RM_VAR_ZERO_INIT
#define J1939RM_VAR_PBCFG

/**********************************************************************************************************************
 *  J1939RM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

#define NVM_APPL_DATA
#define NVM_APPL_CODE
#define NVM_APPL_CONST

#define NVM_CRC_APPL_DATA

#define NVM_CONFIG_DATA
#define NVM_CONFIG_CONST

#define NVM_FAST_DATA

#define NVM_PRIVATE_CODE
#define NVM_PRIVATE_CONST
#define NVM_PRIVATE_DATA

#define NVM_PUBLIC_CODE
#define NVM_PUBLIC_CONST

/* SchM/RTE declares NvM_MainFunction, using NVM_CODE *
 * It MUST be defined to NVM_PUBLIC_CODE!             */
#define NVM_CODE NVM_PUBLIC_CODE

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DBG START 
 *********************************************************************************************************************/


#define DBG_CODE

#define DBG_CONST

#define DBG_VAR_INIT
#define DBG_VAR_NOINIT
#define DBG_VAR_ZERO_INIT

#define DBG_APPL_VAR
#define DBG_PBCFG


/**********************************************************************************************************************
 *  DBG END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  RTM START 
 *********************************************************************************************************************/

#define RTM_CONST
#define RTM_CODE
#define RTM_VAR_INIT
#define RTM_VAR_NOINIT
#define RTM_VAR_ZERO_INIT
#define RTM_APPL_VAR

/**********************************************************************************************************************
 *  RTM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DLT START 
 *********************************************************************************************************************/


#define DLT_CODE

#define DLT_CONST

#define DLT_VAR_INIT
#define DLT_VAR_NOINIT
#define DLT_VAR_ZERO_INIT

#define DLT_APPL_VAR
#define DLT_PBCFG


#define DLTCOM_CODE

#define DLTCOM_CONST

#define DLTCOM_VAR_INIT
#define DLTCOM_VAR_NOINIT
#define DLTCOM_VAR_ZERO_INIT

#define DLTCOM_APPL_DATA
#define DLTCOM_APPL_VAR
#define DLTCOM_PBCFG


/**********************************************************************************************************************
 *  DLT END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  J1939NM START
 *********************************************************************************************************************/

#define J1939NM_CODE
#define J1939NM_APPL_CODE

#define J1939NM_CONST
#define J1939NM_PBCFG
#define J1939NM_APPL_VAR
#define J1939NM_APPL_DATA

#define J1939NM_VAR_NOINIT
#define J1939NM_VAR_ZERO_INIT
#define J1939NM_VAR_PBCFG

/**********************************************************************************************************************
 *  J1939NM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANNM START 
 *********************************************************************************************************************/

#define CANNM_CODE

#define CANNM_CONST
#define CANNM_PBCFG

#define CANNM_VAR_NOINIT
#define CANNM_VAR_INIT
#define CANNM_VAR_PBCFG
#define CANNM_APPL_VAR

/**********************************************************************************************************************
 *  CANNM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRNM START
 *********************************************************************************************************************/

#define FRNM_CODE

#define FRNM_CONST
#define FRNM_PBCFG

#define FRNM_VAR_NOINIT
#define FRNM_VAR_INIT
#define FRNM_VAR_PBCFG
#define FRNM_APPL_VAR

/**********************************************************************************************************************
 *  FRNM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  NM START 
 *********************************************************************************************************************/
 
#define NM_CODE

#define NM_CONST

#define NM_VAR_NOINIT
#define NM_VAR_INIT
#define NM_APPL_VAR

/**********************************************************************************************************************
 *  NM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LINNM START
 *********************************************************************************************************************/

#define LINNM_CODE

#define LINNM_CONST
#define LINNM_PBCFG
#define LINNM_PBCFG_ROOT

#define LINNM_VAR_NOINIT
#define LINNM_VAR_NOINIT_FAST
#define LINNM_VAR_ZERO_INIT_FAST
#define LINNM_APPL_VAR

/**********************************************************************************************************************
 *  LINNM END
 *********************************************************************************************************************/
 



/**********************************************************************************************************************
 *  UDPNM START
 *********************************************************************************************************************/

#define UDPNM_CODE

#define UDPNM_CONST
#define UDPNM_APPL_DATA
#define UDPNM_APPL_VAR

#define UDPNM_VAR_NOINIT

/**********************************************************************************************************************
 *  UDPNM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  BSWM START 
 *********************************************************************************************************************/

#define BSWM_CODE
#define BSWM_CONST
#define BSWM_PBCFG
#define BSWM_VAR_ZERO_INIT
#define BSWM_APPL_DATA
#define BSWM_VAR_NOINIT
#define BSWM_VAR_PBCFG

/**********************************************************************************************************************
 *  BSWM END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM START 
 *********************************************************************************************************************/
#define ECUM_APPL_DATA 
#define ECUM_CODE
#define ECUM_CONST
#define ECUM_PBCFG
#define ECUM_VAR_NOINIT 

/**********************************************************************************************************************
 *  SYSSERVICE_ASR4ECUM END
 *********************************************************************************************************************/


/* -------------------- FiM Compiler Abstraction -------------------- */
#define FIM_CODE
#define FIM_CONST
#define FIM_PBCFG
#define FIM_PBCFG_ROOT
#define FIM_VAR_NOINIT
#define FIM_APPL_DATA
#define FIM_CAL_PRM



/**********************************************************************************************************************
 *  SYSSERVICE_ASRCAL START
 *********************************************************************************************************************/

#define CAL_CODE
#define CAL_APPL_DATA
#define CAL_CONST
#define CAL_APPL_CODE

/**********************************************************************************************************************
 *  CSYSSERVICE_ASRCAL END
 *********************************************************************************************************************/
















/**********************************************************************************************************************
 *  CPL START
 *********************************************************************************************************************/

#define CPL_CODE

#define CPL_CONST
#define CPL_APPL_DATA

/**********************************************************************************************************************
 *  CPL END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC START
 *********************************************************************************************************************/

#define CRC_APPL_DATA
#define CRC_CODE
#define CRC_CONST

/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CRY START
 *********************************************************************************************************************/

#define CRY_CODE

#define CRY_CONST
#define CRY_VAR_NOINIT
#define CRY_APPL_VAR


/**********************************************************************************************************************
 *  CRY END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CSM START 
 *********************************************************************************************************************/

#define CSM_CODE

#define CSM_CONST

#define CSM_VAR_NOINIT
#define CSM_VAR_ZERO_INIT
#define CSM_APPL_VAR


/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/


# define DET_CODE
# define DET_VAR
# define DET_APPL_DATA
# define DET_APPL_CODE




/**********************************************************************************************************************
 *  SysService_AsrRamTst START
 *********************************************************************************************************************/

#define RAMTST_APPL_DATA
#define RAMTST_CODE
#define RAMTST_VAR
#define RAMTST_CONST
#define RAMTST_PBCFG

/**********************************************************************************************************************
 *  SysService_AsrRamTst END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SD START 
 *********************************************************************************************************************/

#define SD_CODE

#define SD_APPL_CODE
#define SD_APPL_CONST
#define SD_APPL_DATA
#define SD_APPL_VAR
#define SD_CONST

#define SD_VAR_NOINIT
#define SD_VAR_INIT
#define SD_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  SD END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  STBM START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define STBM_CONST

/* Module Implementation */
#define STBM_CODE

/* Module Variables which are initialized by the startup code */
#define STBM_VAR_ZERO_INIT
/* Module Variables which are initialized by call of StbM_Init() */
#define STBM_VAR_NOINIT

/* Application Code Implementation (e.g. Callbacks) */
#define STBM_APPL_CODE
/* Application Buffer which is located in RAM */
#define STBM_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define STBM_APPL_DATA

/**********************************************************************************************************************
 *  STBM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANTSYN START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define CANTSYN_CONST

/* Module Implementation */
#define CANTSYN_CODE

/* Module Variables which are initialized by the startup code */
#define CANTSYN_VAR_ZERO_INIT
/* Module Variables which are initialized by call of CanTSyn_Init() */
#define CANTSYN_VAR_NOINIT

/* Application Buffer which is located in RAM */
#define CANTSYN_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define CANTSYN_APPL_DATA

/**********************************************************************************************************************
 *  CANTSYN END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHTSYN START 
 *********************************************************************************************************************/

#define ETHTSYN_CODE
#define ETHTSYN_CODE_ISR

#define ETHTSYN_APPL_CODE
#define ETHTSYN_APPL_CONST
#define ETHTSYN_APPL_DATA
#define ETHTSYN_APPL_VAR
#define ETHTSYN_CONST

#define ETHTSYN_VAR_NOINIT
#define ETHTSYN_VAR_INIT
#define ETHTSYN_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETHTSYN END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRTSYN START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define FRTSYN_CONST

/* Module Implementation */
#define FRTSYN_CODE

/* Module Variables which are initialized by the startup code */
#define FRTSYN_VAR_ZERO_INIT
/* Module Variables which are initialized by call of FrTSyn_Init() */
#define FRTSYN_VAR_NOINIT

/* Application Buffer which is located in RAM */
#define FRTSYN_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define FRTSYN_APPL_DATA

/**********************************************************************************************************************
 *  FRTSYN END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM START 
 *********************************************************************************************************************/

#define WDGM_CODE

#define WDGM_VAR
#define WDGM_VAR_NOINIT
#define WDGM_DATA

#define WDGM_APPL_DATA
#define WDGM_APPL_CODE

#define WDGM_CONST
#define WDGM_PBCFG

/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYPTO START 
 *********************************************************************************************************************/

#define CRYPTO_CODE

#define CRYPTO_CONST
#define CRYPTO_APPL_CONST
#define CRYPTO_PBCFG
#define CRYPTO_APPL_DATA
#define CRYPTO_APPL_VAR

#define CRYPTO_VAR_NOINIT
#define CRYPTO_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  CRYPTO END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CRYPTOCV START
 *********************************************************************************************************************/

#define CRYPTOCV_CODE
#define CRYPTOCV_APPL_CONST
#define CRYPTOCV_APPL_VAR

/**********************************************************************************************************************
 *  CRYPTOCV END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  E2E START 
 *********************************************************************************************************************/


#define E2E_CODE
#define E2E_VAR_NOINIT
#define E2E_VAR_POWER_ON_INIT
#define E2E_VAR_FAST
#define E2E_VAR
#define E2E_CONST
#define E2E_APPL_DATA
#define E2E_APPL_CONST
#define E2E_APPL_CODE

/**********************************************************************************************************************
 *  E2E END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  E2E START 
 *********************************************************************************************************************/


#define E2EPW_CODE
#define E2EPW_VAR_NOINIT
#define E2EPW_VAR_INIT
#define E2EPW_VAR_POWER_ON_INIT
#define E2EPW_VAR_FAST
#define E2EPW_VAR
#define E2EPW_CONST
#define E2EPW_APPL_DATA
#define E2EPW_APPL_CONST
#define E2EPW_APPL_CODE
#define E2EPW_APPL_VAR


/**********************************************************************************************************************
 *  E2E END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  IPBASE START 
 *********************************************************************************************************************/

#define IPBASE_CODE

#define IPBASE_CONST
#define IPBASE_APPL_CONST
#define IPBASE_PBCFG
#define IPBASE_APPL_DATA

#define IPBASE_VAR_NOINIT

/**********************************************************************************************************************
 *  IPBASE END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  J1939TP START
 *********************************************************************************************************************/

#define J1939TP_CODE

#define J1939TP_CONST
#define J1939TP_PBCFG
#define J1939TP_APPL_DATA

#define J1939TP_VAR_NOINIT
#define J1939TP_VAR_ZERO_INIT
#define J1939TP_VAR_PBCFG

/**********************************************************************************************************************
 *  J1939TP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTP START 
 *********************************************************************************************************************/

#define CANTP_CODE
#define CANTP_CONST

#define CANTP_PBCFG
#define CANTP_VAR_PBCFG

#define CANTP_VAR_INIT
#define CANTP_VAR_NOINIT

#define CANTP_APPL_DATA

/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DOIP START 
 *********************************************************************************************************************/

#define DOIP_CODE

#define DOIP_APPL_CONST
#define DOIP_APPL_DATA
#define DOIP_APPL_VAR
#define DOIP_CONST
#define DOIP_PBCFG

#define DOIP_VAR_NOINIT   DOIP_APPL_VAR
#define DOIP_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  DOIP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  IPV4 START 
 *********************************************************************************************************************/

#define IPV4_CODE

#define IPV4_CONST
#define IPV4_PBCFG
#define IPV4_PBCFG_ROOT

#define IPV4_VAR_INIT
#define IPV4_VAR_ZERO_INIT
#define IPV4_VAR_NOINIT

#define IPV4_APPL_CODE
#define IPV4_APPL_DATA
#define IPV4_APPL_CONST
#define IPV4_APPL_PBCFG
#define IPV4_APPL_VAR

/**********************************************************************************************************************
 *  IPV4 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  IPV6 START 
 *********************************************************************************************************************/

#define IPV6_CODE

#define IPV6_CONST
#define IPV6_PBCFG
#define IPV6_PBCFG_ROOT

#define IPV6_VAR_INIT
#define IPV6_VAR_ZERO_INIT
#define IPV6_VAR_NOINIT

#define IPV6_APPL_CODE
#define IPV6_APPL_DATA
#define IPV6_APPL_CONST
#define IPV6_APPL_PBCFG
#define IPV6_APPL_VAR

/**********************************************************************************************************************
 *  IPV6 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  TP_ISO10681 START 
 *********************************************************************************************************************/

#define FRTP_CODE
 
#define TP_ISO10681_CODE
#define TP_ISO10681_CONST

#define TP_ISO10681_APPL_DATA 
#define TP_ISO10681_APPL_CODE

#define TP_ISO10681_VAR_NOINIT 
#define TP_ISO10681_VAR_ZERO_INIT

#define TP_ISO10681_VAR_PBCFG

#define TP_ISO10681_PBCFG
#define TP_ISO10681_PBCFG_ROOT

/**********************************************************************************************************************
 *  TP_ISO10681 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TCPIP START 
 *********************************************************************************************************************/

#define TCPIP_CODE
#define TCPIP_CODE_ISR

#define TCPIP_CONST
#define TCPIP_PBCFG

#define TCPIP_APPL_CONST
#define TCPIP_APPL_DATA
#define TCPIP_APPL_VAR

#define TCPIP_VAR_INIT
#define TCPIP_VAR_ZERO_INIT
#define TCPIP_VAR_NOINIT

/**********************************************************************************************************************
 *  TCPIP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SYSSERVICE_ASRE2EXF START
 *********************************************************************************************************************/

#define E2EXF_CODE
#define E2EXF_CONST
#define E2EXF_APPL_DATA
#define E2EXF_APPL_CONST

/**********************************************************************************************************************
 *  SYSSERVICE_ASRE2EXF END
 *********************************************************************************************************************/


/*-------------------------------------------------------------------------------------------------------------------*/
/* VStdLib start compiler_cfg                                                                                        */
/*-------------------------------------------------------------------------------------------------------------------*/

#define VSTDLIB_CODE                               /* CAN modules code qualifier                                                                            */ /* PRQA S 0883 *//* Appears only while testing */
#define VSTDLIB_CONST                              /* constant memory                                                                                       */
#define VSTDLIB_VAR_NEAR                           /* near variables: this is the pointer clas for "pOldState" parameter of VStdLL_GlobalInterruptDisable() */
#define VSTDLIB_CONST_FAR                          /* far constant memory: can remain empty if the application is not using FAR data (neither ROM nor RAM)  */
#define VSTDLIB_VAR_FAR                            /* far variables: can remain empty if the application is not using FAR data (neither ROM nor RAM)        */
#define VSTDLIB_VAR_NOINIT

/*-------------------------------------------------------------------------------------------------------------------*/
/* VStdLib end compiler_cfg                                                                                          */
/*-------------------------------------------------------------------------------------------------------------------*/




/**********************************************************************************************************************
 *  VttCntrl START
 **********************************************************************************************************************/

#define VTTCNTRL_APPL_DATA
#define VTTCNTRL_CONST
#define VTTCNTRL_CODE
#define VTTCNTRL_APPL_CONST
#define VTTCNTRL_PBCFG
#define VTTCNTRL_APPL_VAR
#define VTTCNTRL_VAR
#define VTTCNTRL_APPL_CODE

/**********************************************************************************************************************
 *  VttCntrl END
 **********************************************************************************************************************/




/* Package Merger: Stop Section CompilerCfgModuleList */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/
