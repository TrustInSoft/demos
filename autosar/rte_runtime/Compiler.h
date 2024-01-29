/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015-2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Compiler.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This file provides the AUTOSAR compiler abstraction for the Visual C compiler
 *                   Supported compiler:           Microsoft VisualC
 *                   Supported compiler version:   6.0 .. 10.0
 *
 * THIS FILE IS PART OF vVIRTUALtarget AND CONTAINS PRODUCT-SPECIFIC MODIFICATIONS! 
 * IT IS NOT INTENDED FOR USE WITH MICROSAR STACKS / REAL ECU CODE!
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *      
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Patrick Markl                  visml        Vector Informatik GmbH
 *  Wladimir Gerber                viswge       Vector Informatik GmbH
 *  Damian Philipp                 visdap       Vector Informatik GmbH
 *  Max-Ferdinand Suffel           vismsl       Vector Informatik GmbH
 *  Christian Köllner              vikakch      Vector Informatik GmbH
 *  Nico König                     vikahno      Vector Informatik GmbH
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2014-03-17  visml                 Creation based on template V1.05.00
 *  01.00.01  2014-08-19  viswge                Removed memclass attribute of macros to keep Compiler_Cfg.h simple.
 *  01.00.02  2014-09-12  viswge                Added _MICROSOFT_C_CANOE_, some upper layer BSWs use this define.
 *  01.00.03  2015-02-19  viswge                Added _MICROSOFT_C_VTT_; Set correct version number.
 *  01.00.04  2015-09-29  visdap                Added (commented) pragmas to move stack memory to .vbss/.vdata sections 
 *  01.00.05  2015-11-30  vismsl                Maintenance (Version incremented)
 *  02.00.00  2017-01-27  vikakch               VTT Pro adaption: Getting rid of memclass and ptrclass
 *  03.00.00  2019-11-22  vikakch               .vbss/.vdata sections, so CANoe can perform a proper reset of the ECU
 *  03.00.01  2020-10-19  vikahno               Rename .vbss/.vdata sections to vttbss/vttdata
 *  03.00.02  2020-11-04  vikahno               Use angle-bracket include for Compiler_Cfg.h
 *  03.00.03  2021-02-02  vikahno               Add VTTCURRENTMEMORYSECTION to support ECU reset also for GCC
 *********************************************************************************************************************/

#ifndef COMPILER_H
# define COMPILER_H

/* PRQA S 3453 COMPILER_3453_TAG */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include <Compiler_Cfg.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Vtt CQComponent : Impl_CompAbstract_Ansi */
# define COMMONASR_VTT_IMPL_COMPABSTRACT_ANSI_VERSION         0x0100
# define COMMONASR_VTT_IMPL_COMPABSTRACT_ANSI_RELEASE_VERSION 0x03

# define COMPILER_VENDOR_ID    30u  /* SREQ00015523 */
# define COMPILER_MODULE_ID    198u /* SREQ00015523 */
 
/* AUTOSAR Software Specification Release Version Information */
/*            AUTOSAR Release 4.0 R3                          */
#   define COMPILER_AR_RELEASE_MAJOR_VERSION       (4u)
#   define COMPILER_AR_RELEASE_MINOR_VERSION       (0u)
#   define COMPILER_AR_RELEASE_REVISION_VERSION    (3u)

/* Component Version Information */
# define COMPILER_SW_MAJOR_VERSION       (1u)
# define COMPILER_SW_MINOR_VERSION       (0u)
# define COMPILER_SW_PATCH_VERSION       (5u) 


# ifndef VTTCURRENTMEMORYSECTION
#  define VTTCURRENTMEMORYSECTION
# endif

# ifdef _MSC_VER
#  define _MICROSOFT_C_VTT_
#  define _MICROSOFT_C_CANOE_
# elif defined(__MINGW32__) || defined(__MINGW64__)
#  define _MINGW_C_VTT_
#  define _MINGW_C_CANOE_
# elif defined(__clang__)
#  define _CLANG_C_VTT_
#  define _CLANG_C_CANOE_
# endif

/* Move Stack memory to .vbss/.vdata sections, so CANoe can perform a proper reset of the ECU */
# if !defined(BSWDLL_EXPORTS) && defined(_MSC_VER)
#  pragma section("vttbss",read,write)
#  pragma section("vttdata",read,write)
#  pragma bss_seg("vttbss")
#  pragma data_seg("vttdata")
# endif

/* AUTOMATIC used for the declaration of local pointers */
# define AUTOMATIC

/* TYPEDEF shall be used within type definitions, where no memory qualifier can be specified.*/
# define TYPEDEF

/* NULL_PTR define with a void pointer to zero definition*/
# ifndef NULL_PTR
#  ifdef __cplusplus
#   define NULL_PTR  0
#  else
#   define NULL_PTR  ((void *)0)
#  endif
# endif

/* INLINE  define for abstraction of the keyword inline*/
# ifdef _MSC_VER
#  define INLINE _inline
# else
#  define INLINE inline
# endif 

/* LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope.
   Different compilers may require a different sequence of the keywords "static" and "inline" 
   if this is supported at all. */
# ifdef _MSC_VER
#  define LOCAL_INLINE static _inline
# else
#  define LOCAL_INLINE static inline
# endif

/* FUNC macro for the declaration and definition of functions, that ensures correct syntax of function declarations
   rettype     return type of the function
   memclass    classification of the function itself*/
# define FUNC(rettype, memclass) rettype

/* FUNC_P2CONST macro for declaration and definition of functions returning a pointer to a constant, that ensures 
     correct syntax of function declarations.
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
# define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype * 

/* FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable, that ensures
     correct syntax of function declarations
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
# define FUNC_P2VAR(rettype, ptrclass, memclass) rettype * 

/* P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables
   ptrtype     type of the referenced variable memclass
   memclass    classification of the pointer’s variable itself
   ptrclass    defines the classification of the pointer’s distance
 */
# define P2VAR(ptrtype, memclass, ptrclass) ptrtype * VTTCURRENTMEMORYSECTION

/* P2CONST macro for the declaration and definition of pointers in RAM pointing to constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define P2CONST(ptrtype, memclass, ptrclass) const ptrtype * VTTCURRENTMEMORYSECTION

/* CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/* CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/* P2FUNC macro for the type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectivly name of the defined type
 */
# define P2FUNC(rettype, ptrclass, fctname) rettype (* fctname)

/* CONST macro for the declaration and definition of constants
   type        type of the constant
   memclass    classification of the constant itself
 */
# define CONST(type, memclass) const type

/* VAR macro for the declaration and definition of variables
   vartype        type of the variable
   memclass    classification of the variable itself
 */
# define VAR(vartype, memclass) vartype VTTCURRENTMEMORYSECTION

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

/* PRQA L:COMPILER_3453_TAG */

/****************************************************************************/
/*  MISRA deviations                                                        */
/****************************************************************************/
/* Justification for module-specific MISRA deviations:

MD_Compiler_19.10:
  Reason: Macro used in structures, which depend on used compiler and which do not allow brackets e.g. declaration of functions and variables.
  Risk: None atomic parameter lead to compile errors.
  Prevention: Used parameter is always atomic.

*/

#endif  /* COMPILER_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler.h
 *********************************************************************************************************************/
