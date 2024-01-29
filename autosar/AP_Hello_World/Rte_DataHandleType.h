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
 *             File:  Rte_DataHandleType.h
 *        SW-C Type:  AP_Hello_World
 *  Generation Time:  2023-12-15 09:22:32
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.22
 *                    RTE Core Version 4.31.0
 *          License:  DVSwcGen
 *
 *      Description:  Header file containing Data Handle type declarations for component data structures (ContractPhase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DATA_HANDLE_TYPE_H
# define RTE_DATA_HANDLE_TYPE_H


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  IntArrayImpl value;
} Rte_DE_IntArrayImpl;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  IntArrayImpl value;
  Std_ReturnType status;
} Rte_DES_IntArrayImpl;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  multiArrayThreeImpl value;
  Std_ReturnType status;
} Rte_DES_multiArrayThreeImpl;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  customFloat64 value;
} Rte_DE_customFloat64;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  sint8 value;
  Std_ReturnType status;
} Rte_DES_sint8;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  customDouble32 value;
} Rte_DE_customDouble32;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  sint16 value;
  Std_ReturnType status;
} Rte_DES_sint16;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  uint64 value;
} Rte_DE_uint64;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  NvM_RequestResultType value;
  Std_ReturnType status;
} Rte_DES_NvM_RequestResultType;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  uint64 value;
  Std_ReturnType status;
} Rte_DES_uint64;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  sint16 value;
} Rte_DE_sint16;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  ComplexStructImpl value;
} Rte_DE_ComplexStructImpl;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  unionImpl value;
} Rte_DE_unionImpl;
/* PRQA L:L1 */

#endif /* RTE_DATA_HANDLE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

*/
