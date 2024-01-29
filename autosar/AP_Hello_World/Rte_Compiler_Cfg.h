/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Contract phase header
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This implementation is neither intended nor qualified for use in series production
 *                without applying suitable quality measures. The implementation as well as any of its modifications
 *                must be tested with diligent care and must comply with all quality requirements which are necessary
 *                according to the state of the art before its use.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Compiler_Cfg.h
 *        SW-C Type:  AP_Hello_World
 *  Generation Time:  2023-12-15 09:22:32
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.22
 *                    RTE Core Version 4.31.0
 *          License:  DVSwcGen
 *
 *      Description:  RTE Compiler Abstraction header file (Contract Phase)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMPILER_CFG_H
# define RTE_COMPILER_CFG_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CODE
 *********************************************************************************************************************/

/* used for code */
# define RTE_CODE

/* used for all global or static variables that are not initialized by the startup code of the compiler */
# define RTE_VAR_NOINIT

/* used for global or static constants */
# define RTE_CONST

/* used for references on application data (variables or constants) */
# define RTE_APPL_DATA

/* used for references on application variables */
# define RTE_APPL_VAR

/* used for references on application functions */
# define RTE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_INSTANCECONSTP2CONST
 *********************************************************************************************************************/

/* In AUTOSAR 4.1.3 [SWS_Rte_06810] was introduced that breaks compatibility with MICROSAR.
   Define the following define to P2CONST to get the old behavior. */
# define RTE_INSTANCECONSTP2CONST CONSTP2CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HELLO_WORLD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HELLO_WORLD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HELLO_WORLD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HELLO_WORLD_APPL_CODE

/* used for references on application constants */
# define RTE_AP_HELLO_WORLD_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AP_Hello_World_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define AP_Hello_World_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AP_Hello_World_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define AP_Hello_World_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AP_Hello_World_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define AP_Hello_World_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define AP_Hello_World_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define AP_Hello_World_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Calibration Parameter specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CONST_DEFAULT_RTE_CDATA_GROUP
 *********************************************************************************************************************/

# define RTE_CONST_DEFAULT_RTE_CDATA_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CONST_DEFAULT_RTE_CALPRM_GROUP
 *********************************************************************************************************************/

# define RTE_CONST_DEFAULT_RTE_CALPRM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Per-Instance Memory specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* RTE_COMPILER_CFG_H */
