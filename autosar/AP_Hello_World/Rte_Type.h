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
 *             File:  Rte_Type.h
 *        SW-C Type:  AP_Hello_World
 *  Generation Time:  2023-12-15 09:22:32
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.22
 *                    RTE Core Version 4.31.0
 *          License:  DVSwcGen
 *
 *      Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"

/**********************************************************************************************************************
 * Type definitions for transformer error handling
 *********************************************************************************************************************/

# define RTE_TRANSFORMER_UNSPECIFIED 0x00U
# define RTE_TRANSFORMER_SERIALIZER  0x01U
# define RTE_TRANSFORMER_SAFETY      0x02U

# ifdef STD_TRANSFORMER_UNSPECIFIED

typedef Std_TransformerError Rte_TransformerError;
typedef Std_TransformerClass Rte_TransformerClass;
typedef Std_TransformerErrorCode Rte_TransformerErrorCode;

# else

typedef uint8 Rte_TransformerClass;
typedef Rte_TransformerClass Std_TransformerClass;
typedef Std_ReturnType Rte_TransformerErrorCode;
typedef Rte_TransformerErrorCode Std_TransformerErrorCode;

#  define STD_TRANSFORMER_UNSPECIFIED RTE_TRANSFORMER_UNSPECIFIED
#  define STD_TRANSFORMER_SERIALIZER RTE_TRANSFORMER_SERIALIZER
#  define STD_TRANSFORMER_SAFETY RTE_TRANSFORMER_SAFETY

typedef struct
{
  Rte_TransformerErrorCode errorCode;
  Rte_TransformerClass transformerClass;
} Rte_TransformerError;

typedef Rte_TransformerError Std_TransformerError;

# endif


/* PRQA S 1039 EOF */ /* MD_Rte_1039 */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Rte_DT_CharArrayImplementation_0
typedef uint8 Rte_DT_CharArrayImplementation_0;

# define Rte_TypeDef_Rte_DT_ComplexStructImpl_0
typedef sint16 Rte_DT_ComplexStructImpl_0;

# define Rte_TypeDef_Rte_DT_ComplexStructImpl_1
typedef float32 Rte_DT_ComplexStructImpl_1;

# define Rte_TypeDef_Rte_DT_FloatArrayImplementation_0
typedef float32 Rte_DT_FloatArrayImplementation_0;

# define Rte_TypeDef_Rte_DT_IntArrayImpl_0
typedef sint16 Rte_DT_IntArrayImpl_0;

# define Rte_TypeDef_Rte_DT_SimpleStructImpl_0
typedef boolean Rte_DT_SimpleStructImpl_0;

# define Rte_TypeDef_Rte_DT_unionImpl_0
typedef uint8 Rte_DT_unionImpl_0;

# define Rte_TypeDef_Rte_DT_unionImpl_1_0
typedef uint8 Rte_DT_unionImpl_1_0;

# define Rte_TypeDef_Rte_DT_unionImpl_2_0
typedef uint8 Rte_DT_unionImpl_2_0;

# define Rte_TypeDef_Rte_DT_variableArrayImpl_0
typedef uint8 Rte_DT_variableArrayImpl_0;

# define Rte_TypeDef_UintConstrImpl
typedef uint8 UintConstrImpl;

# define Rte_TypeDef_customDouble32
typedef float32 customDouble32;

# define Rte_TypeDef_customFloat64
typedef float64 customFloat64;

# define Rte_TypeDef_customUInt8
typedef uint8 customUInt8;

# define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

# define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# define Rte_TypeDef_CharArrayImplementation
typedef Rte_DT_CharArrayImplementation_0 CharArrayImplementation[30];

# define Rte_TypeDef_FloatArrayImplementation
typedef Rte_DT_FloatArrayImplementation_0 FloatArrayImplementation[15];

# define Rte_TypeDef_IntArrayImpl
typedef Rte_DT_IntArrayImpl_0 IntArrayImpl[10];

# define Rte_TypeDef_Rte_DT_unionImpl_1
typedef Rte_DT_unionImpl_1_0 Rte_DT_unionImpl_1[5];

# define Rte_TypeDef_variableArrayImpl
typedef Rte_DT_variableArrayImpl_0 variableArrayImpl[10];

# define Rte_TypeDef_Rte_DT_unionImpl_2
typedef struct
{
  Rte_DT_unionImpl_2_0 intElem;
} Rte_DT_unionImpl_2;

# define Rte_TypeDef_SimpleStructImpl
typedef struct
{
  Rte_DT_SimpleStructImpl_0 boolElement;
  sint8 constrElement;
} SimpleStructImpl;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_multiArrayTwoImpl
typedef IntArrayImpl multiArrayTwoImpl[3];

# define Rte_TypeDef_ComplexStructImpl
typedef struct
{
  Rte_DT_ComplexStructImpl_0 intElement;
  Rte_DT_ComplexStructImpl_1 floatElement;
  IntArrayImpl arrrayElement;
  SimpleStructImpl structElement;
} ComplexStructImpl;

# define Rte_TypeDef_unionImpl
typedef union
{
  Rte_DT_unionImpl_0 valueElem;
  Rte_DT_unionImpl_1 arrayElem;
  Rte_DT_unionImpl_2 structElem;
} unionImpl;

# define Rte_TypeDef_multiArrayThreeImpl
typedef multiArrayTwoImpl multiArrayThreeImpl[2];


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_Rte_DT_VariableStringImplementation_0
typedef uint16 Rte_DT_VariableStringImplementation_0;

#  define Rte_TypeDef_Rte_DT_VariableStringImplementation_1_0
typedef uint8 Rte_DT_VariableStringImplementation_1_0;

#  define Rte_TypeDef_Rte_DT_VariableStringImplementation_1
typedef Rte_DT_VariableStringImplementation_1_0 Rte_DT_VariableStringImplementation_1[70];

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

#  define Rte_TypeDef_VariableStringImplementation
typedef struct
{
  Rte_DT_VariableStringImplementation_0 SizeElement;
  Rte_DT_VariableStringImplementation_1 DataElement;
} VariableStringImplementation;

# endif

#endif /* RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

*/
