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
 *             File:  Rte_AP_Hello_World.h
 *        SW-C Type:  AP_Hello_World
 *  Generation Time:  2023-12-15 09:22:32
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.22
 *                    RTE Core Version 4.31.0
 *          License:  DVSwcGen
 *
 *      Description:  Application header file for SW-C <AP_Hello_World> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_AP_HELLO_WORLD_H
# define RTE_AP_HELLO_WORLD_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_AP_Hello_World_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_AP_Hello_World
{
  /* Data Handles section */
  P2VAR(Rte_DE_IntArrayImpl, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ArrayRunnable_ArraySRInterface_INone;
  P2VAR(Rte_DES_IntArrayImpl, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ArrayRunnable_ArraySRInterface_Iconstraint;
  P2VAR(Rte_DES_multiArrayThreeImpl, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit;
  P2VAR(Rte_DE_customFloat64, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) DoubleRunnable_DoubleSRPort_implicitElem;
  P2VAR(Rte_DES_sint8, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImplicitReadRunnable_SimpleReadProto_ReadElementOpenRange;
  P2VAR(Rte_DE_customDouble32, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImplicitReadRunnable_SimpleReadProto_ReadElementRangeInfMax;
  P2VAR(Rte_DES_sint16, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImplicitReadRunnable_SimpleReadProto_SimpleReadElement;
  P2VAR(Rte_DE_uint64, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImplicitReadRunnable_SimpleReadTimeout_SimpleReadNeverReceived;
  P2VAR(Rte_DES_NvM_RequestResultType, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImpliciteWrite_ComplexPortTest_ComplexElement;
  P2VAR(Rte_DE_uint64, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImpliciteWrite_ComplexPortTest_ConstrainedElement;
  P2VAR(Rte_DES_uint64, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImpliciteWrite_ComplexPortTest_HandleInvalidElement;
  P2VAR(Rte_DES_sint8, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImpliciteWrite_SimpleWritePort_ReadElementOpenRange;
  P2VAR(Rte_DE_customDouble32, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax;
  P2VAR(Rte_DE_sint16, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImpliciteWrite_SimpleWritePort_SimpleReadElement;
  P2VAR(Rte_DE_uint64, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived;
  P2VAR(Rte_DE_ComplexStructImpl, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) StructRunnable_StructSRInterface_IElement;
  P2VAR(Rte_DE_unionImpl, TYPEDEF, RTE_AP_HELLO_WORLD_APPL_VAR) UnionRunnable_UnionSRInterface_implicitElem;
  /* PIM Handles section */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_PerInstanceMemory;
  /* IRV Handles section */
  P2VAR(ComplexStructImpl, TYPEDEF, RTE_VAR_NOINIT) Irv_InterVariableRunnable_ImplicitInterRunnableStruct;
  P2VAR(customUInt8, TYPEDEF, RTE_VAR_NOINIT) Irv_InterVariableRunnable_ImplicitInterRunnableValue;
  /* Vendor specific section */
};
typedef struct Rte_CDS_AP_Hello_World Rte_CDS_AP_Hello_World;

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONSTP2CONST(struct Rte_CDS_AP_Hello_World, RTE_CONST, RTE_CONST) Rte_Inst_AP_Hello_World;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

typedef RTE_INSTANCECONSTP2CONST(struct Rte_CDS_AP_Hello_World, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 1507 */ /* MD_Rte_1507 */


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_Hello_World_port_Hello_World_Element (FALSE)
# define Rte_InitValue_SimpleReadProto_SimpleReadElement (12345)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_AP_Hello_World_ComplexElementRx_QueuedElement(P2VAR(uint64, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_acknowlegdement(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_acknowlegdement(P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_constraint(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_constraint(P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_errorHandling(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_errorHandling(P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_handleKeep(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_handleKeep(P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_init(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_init(P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_initConstraint(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ArraySRInterface_initConstraint(P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_BooleanSR_isElement(P2VAR(boolean, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ComplexElementRx_ComplexElement(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ComplexElementRx_ConstrainedElement(P2VAR(uint64, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ComplexElementRx_HandleInvalidElement(P2VAR(uint64, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_AllConstr(P2VAR(UintConstrImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_ApplicationTypeAllConstr(P2VAR(UintConstrImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_ApplicationTypeConstr(P2VAR(customUInt8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_ApplicationTypeImplConstr(P2VAR(UintConstrImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_DataProtypeApplConstr(P2VAR(customUInt8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_DataProtypeConstr(P2VAR(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_DataProtypeImplConstr(P2VAR(UintConstrImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_ImplementationTypeConstr(P2VAR(UintConstrImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_InfFloatConstr(P2VAR(float32, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DataConstraintInterface_NoConstr(P2VAR(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_DoubleSRPort_explicitElem(P2VAR(customFloat64, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint64, RTE_CODE) Rte_DRead_AP_Hello_World_IsUpdatedByValuePrototype_IdUpdatedByValueElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement(P2VAR(uint64, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_MultiArraySRInterface_multiArray(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_MultiArraySRInterface_multiArray(P2VAR(multiArrayThreeImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_MultiArraySRInterface_multiArrayConstraint(P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_MultiArraySRInterface_multiArrayConstraint(P2VAR(multiArrayThreeImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(sint8, RTE_CODE) Rte_DRead_AP_Hello_World_ReadWithErrorHandler_ReadElementOpenRange(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_ReadWithErrorHandler_SimpleReadElement(P2VAR(sint16, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint64, RTE_CODE) Rte_DRead_AP_Hello_World_SimpleNvDataPort_element_OneToTen(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_SimpleReadProto_ReadElementOpenRange(P2VAR(sint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_SimpleReadProto_ReadElementRangeInfMax(P2VAR(customDouble32, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_SimpleReadProto_SimpleReadElement(P2VAR(sint16, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(sint8, RTE_CODE) Rte_DRead_AP_Hello_World_SimpleReadTimeout_ReadElementOpenRange(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_SimpleReadTimeout_SimpleReadElement(P2VAR(sint16, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_SimpleReadTimeout_SimpleReadNeverReceived(P2VAR(uint64, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_StructSRInterface_Element(P2VAR(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AP_Hello_World_UnionSRInterface_explicitElem(P2VAR(unionImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(boolean, RTE_CODE) Rte_IsUpdated_AP_Hello_World_IsUpdatedByValuePrototype_IdUpdatedByValueElement(void);
FUNC(boolean, RTE_CODE) Rte_IsUpdated_AP_Hello_World_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_AP_Hello_World_ComplexPortTest_QueuedElement(uint64 data, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_AcknowledgmentInterface_nonWaitElement(uint64 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_AcknowledgmentInterface_waitElement(uint64 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_acknowlegdement(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_acknowlegdement(P2CONST(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_constraint(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_constraint(P2CONST(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_errorHandling(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_errorHandling(P2CONST(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_handleKeep(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_handleKeep(P2CONST(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_init(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_init(P2CONST(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_initConstraint(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_ArraySRInterface_initConstraint(P2CONST(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_AllConstr(UintConstrImpl data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_ApplicationTypeAllConstr(UintConstrImpl data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_ApplicationTypeConstr(customUInt8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_ApplicationTypeImplConstr(UintConstrImpl data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_DataProtypeApplConstr(customUInt8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_DataProtypeConstr(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_DataProtypeImplConstr(UintConstrImpl data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_ImplementationTypeConstr(UintConstrImpl data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DataConstraintInterface_NoConstr(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_DoubleSRPort_explicitElem(customFloat64 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_Hello_World_port_Hello_World_Element(boolean data, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_MultiArraySRInterface_multiArray(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_MultiArraySRInterface_multiArray(P2CONST(multiArrayThreeImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_MultiArraySRInterface_multiArrayConstraint(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_MultiArraySRInterface_multiArrayConstraint(P2CONST(multiArrayThreeImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_StructSRInterface_Element(P2CONST(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AP_Hello_World_UnionSRInterface_explicitElem(P2CONST(unionImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CODE) Rte_Trigger_AP_Hello_World_TriggerInterface_SomeTriggerElement(void);
FUNC(void, RTE_CODE) Rte_Trigger_AP_Hello_World_TriggerInterfaceError_SomeTriggerElement(P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError);
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_AP_Hello_World_ArraySRInterface_acknowlegdement(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_AP_Hello_World_ArraySRInterface_constraint(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_AP_Hello_World_ArraySRInterface_errorHandling(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_AP_Hello_World_ArraySRInterface_handleKeep(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_AP_Hello_World_ArraySRInterface_init(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_AP_Hello_World_ArraySRInterface_initConstraint(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Invalidate_AP_Hello_World_Hello_World_port_Hello_World_Element(P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError);
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_AP_Hello_World_AcknowledgmentInterface_nonWaitElement(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_AP_Hello_World_AcknowledgmentInterface_waitElement(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_AP_Hello_World_ArraySRInterface_acknowlegdement(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_AP_Hello_World_ComplexPortTest_QueuedElement(void);
FUNC(uint8, RTE_CODE) Rte_Mode_AP_Hello_World_EnhancedPortInterface_Mode(P2VAR(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) nextMode);
FUNC(uint8, RTE_CODE) Rte_Mode_AP_Hello_World_Mode_Port_Interface_ModeGroup(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_AP_Hello_World_Mode_Port_Interface_ModeGroup(uint8 nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_AP_Hello_World_Mode_Port_Interface_ModeGroup(void);
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_ArrayCSPort_sumArray(P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) arg, P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg_1, P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg_2); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_ArrayCSPort_sumArray(P2CONST(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) arg, P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg_1, P2VAR(IntArrayImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg_2); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_CallPortInterface_InOutOperation(sint16 int_var, P2CONST(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) struct_var, P2CONST(Rte_DT_FloatArrayImplementation_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) array_var); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_CallPortInterface_InOutOperation(sint16 int_var, P2CONST(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) struct_var, P2CONST(FloatArrayImplementation, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) array_var); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_CallPortInterface_SimpleIntOperation(sint16 arg, P2VAR(customDouble32, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg_1); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_DoubleCS_f(customFloat64 arg, P2VAR(customFloat64, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg_1); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvMService_service_client_GetErrorStatus(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMAdministration_client_SetBlockProtection(boolean ProtectionEnabled); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMNotifyInitBlock_client_InitBlock(P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) ErrorStatus, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_RestoreBlockDefaults(dtRef_VOID DstPtr, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus(boolean RamBlockStatus, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock(dtRef_const_VOID SrcPtr, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_client_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) ErrorStatus, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_client_ReadBlock(dtRef_VOID DstPtr, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_client_WriteBlock(dtRef_const_VOID SrcPtr, P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_NvSWC_NvMService_client_GetErrorStatus(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_StructCSInterface_cloneStruct(P2CONST(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) arg, P2VAR(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg_1); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AP_Hello_World_UnionCInterface_f(P2VAR(unionImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Result_AP_Hello_World_CallPortInterface_InOutOperation(P2VAR(sint16, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) int_var, P2VAR(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) struct_var, P2VAR(Rte_DT_FloatArrayImplementation_0, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) array_var); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Result_AP_Hello_World_CallPortInterface_InOutOperation(P2VAR(sint16, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) int_var, P2VAR(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) struct_var, P2VAR(FloatArrayImplementation, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) array_var); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Result_AP_Hello_World_NvMService_service_client_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Result_AP_Hello_World_NvSWC_NvMAdministration_client_SetBlockProtection(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Result_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus(P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Result_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock(P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Result_AP_Hello_World_NvSWC_NvMService_client_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(customFloat64, RTE_CODE) Rte_Prm_AP_Hello_World_DoubleCalibration_doubleElem(void);
FUNC(uint16, RTE_CODE) Rte_Prm_AP_Hello_World_CalibrationPortInterface_CalibrationElement(void);
FUNC(uint8, RTE_CODE) Rte_Prm_AP_Hello_World_CalibrationPrimitiveType_notAccessibleElement(void);
FUNC(uint8, RTE_CODE) Rte_Prm_AP_Hello_World_CalibrationPrimitiveType_readOnlyElement(void);
FUNC(uint8, RTE_CODE) Rte_Prm_AP_Hello_World_CalibrationPrimitiveType_readWriteElement(void);
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC_P2CONST(Rte_DT_IntArrayImpl_0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_ArrayCalibration_arrayElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC_P2CONST(IntArrayImpl, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_ArrayCalibration_arrayElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC_P2CONST(Rte_DT_variableArrayImpl_0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_ArrayCalibration_variableArrayElem(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC_P2CONST(variableArrayImpl, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_ArrayCalibration_variableArrayElem(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC_P2CONST(Rte_DT_IntArrayImpl_0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_MultiArrayCalibration_multiArrayElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC_P2CONST(multiArrayThreeImpl, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_MultiArrayCalibration_multiArrayElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC_P2CONST(Rte_DT_CharArrayImplementation_0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_RefTypeCalibration_notAccessibleElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC_P2CONST(CharArrayImplementation, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_RefTypeCalibration_notAccessibleElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC_P2CONST(Rte_DT_CharArrayImplementation_0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_RefTypeCalibration_readOnlyElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC_P2CONST(CharArrayImplementation, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_RefTypeCalibration_readOnlyElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC_P2CONST(Rte_DT_CharArrayImplementation_0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_RefTypeCalibration_readWriteElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC_P2CONST(CharArrayImplementation, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_RefTypeCalibration_readWriteElement(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC_P2CONST(ComplexStructImpl, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_AP_Hello_World_StructCalibration_Element(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CODE) Rte_IrvRead_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableStruct(P2VAR(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) data);
FUNC(customUInt8, RTE_CODE) Rte_IrvRead_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableValue(void);
FUNC(void, RTE_CODE) Rte_IrvWrite_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableStruct(P2CONST(ComplexStructImpl, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) data);
FUNC(void, RTE_CODE) Rte_IrvWrite_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableValue(customUInt8 data);

FUNC(void, RTE_CODE) Rte_Enter_AP_Hello_World_TestExclusiveArea(void);
FUNC(void, RTE_CODE) Rte_Exit_AP_Hello_World_TestExclusiveArea(void);

FUNC(customUInt8, RTE_CODE) Rte_CData_AP_Hello_World_PerInstanceInternalCalibrationParameter(void);
FUNC(customUInt8, RTE_CODE) Rte_CData_AP_Hello_World_SharedInternalCalibrationParameter(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IFeedback_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IRead_ArrayRunnable_ArraySRInterface_INone() \
  (*&Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_INone->value)
# else
#  define Rte_IRead_ArrayRunnable_ArraySRInterface_INone() \
  (&Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_INone->value)
# endif


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IRead_ArrayRunnable_ArraySRInterface_Iconstraint() \
  (*&Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->value)
# else
#  define Rte_IRead_ArrayRunnable_ArraySRInterface_Iconstraint() \
  (&Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->value)
# endif


# define Rte_IStatus_ArrayRunnable_ArraySRInterface_Iconstraint() \
  (Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->status)


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IWrite_ArrayRunnable_ArraySRInterface_INone(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA)) (data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_INone->value; \
    uint32_least i; \
    for (i = 0; i < sizeof(IntArrayImpl) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# else
#  define Rte_IWrite_ArrayRunnable_ArraySRInterface_INone(data) \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA)) *(data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_INone->value; \
    uint32_least i; \
    for (i = 0; i < sizeof(IntArrayImpl) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# endif


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IWriteRef_ArrayRunnable_ArraySRInterface_INone() \
  (Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_INone->value)
# else
#  define Rte_IWriteRef_ArrayRunnable_ArraySRInterface_INone() \
  (&Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_INone->value)
# endif


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IWrite_ArrayRunnable_ArraySRInterface_Iconstraint(data) \
  Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->status = RTE_E_OK; \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA)) (data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->value; \
    uint32_least i; \
    for (i = 0; i < sizeof(IntArrayImpl) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# else
#  define Rte_IWrite_ArrayRunnable_ArraySRInterface_Iconstraint(data) \
  Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->status = RTE_E_OK; \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA)) *(data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->value; \
    uint32_least i; \
    for (i = 0; i < sizeof(IntArrayImpl) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# endif


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IWriteRef_ArrayRunnable_ArraySRInterface_Iconstraint() \
  (Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->value)
# else
#  define Rte_IWriteRef_ArrayRunnable_ArraySRInterface_Iconstraint() \
  (&Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->value)
# endif


# define Rte_IInvalidate_ArrayRunnable_ArraySRInterface_Iconstraint() \
  (Rte_Inst_AP_Hello_World->ArrayRunnable_ArraySRInterface_Iconstraint->status = RTE_E_INVALID)


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IRead_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit() \
  ((P2CONST(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_VAR_NOINIT)) *&Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->value)
# else
#  define Rte_IRead_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit() \
  (&Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->value)
# endif


# define Rte_IStatus_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit() \
  (Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->status)


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IWrite_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(data) \
  Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->status = RTE_E_OK; \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA)) (data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->value; \
    uint32_least i; \
    for (i = 0; i < sizeof(multiArrayThreeImpl) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# else
#  define Rte_IWrite_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(data) \
  Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->status = RTE_E_OK; \
  { \
    P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_DATA)) *(data); \
    P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->value; \
    uint32_least i; \
    for (i = 0; i < sizeof(multiArrayThreeImpl) ; i++) \
    { \
      dst[i] = src[i]; \
    } \
  }
# endif


# ifndef RTE_PTR2ARRAYTYPE_PASSING
#  define Rte_IWriteRef_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit() \
  ((P2VAR(Rte_DT_IntArrayImpl_0, AUTOMATIC, RTE_VAR_NOINIT)) Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->value)
# else
#  define Rte_IWriteRef_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit() \
  (&Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->value)
# endif


# define Rte_IInvalidate_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit() \
  (Rte_Inst_AP_Hello_World->ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit->status = RTE_E_INVALID)


# define Rte_IRead_DoubleRunnable_DoubleSRPort_implicitElem() \
  (Rte_Inst_AP_Hello_World->DoubleRunnable_DoubleSRPort_implicitElem->value)


# define Rte_IWrite_DoubleRunnable_DoubleSRPort_implicitElem(data) \
  ( \
    Rte_Inst_AP_Hello_World->DoubleRunnable_DoubleSRPort_implicitElem->value = (data) \
  )


# define Rte_IWriteRef_DoubleRunnable_DoubleSRPort_implicitElem() \
  (&Rte_Inst_AP_Hello_World->DoubleRunnable_DoubleSRPort_implicitElem->value)


# define Rte_IRead_ImplicitReadRunnable_SimpleReadProto_ReadElementOpenRange() \
  (Rte_Inst_AP_Hello_World->ImplicitReadRunnable_SimpleReadProto_ReadElementOpenRange->value)


# define Rte_IStatus_ImplicitReadRunnable_SimpleReadProto_ReadElementOpenRange() \
  (Rte_Inst_AP_Hello_World->ImplicitReadRunnable_SimpleReadProto_ReadElementOpenRange->status)


# define Rte_IRead_ImplicitReadRunnable_SimpleReadProto_ReadElementRangeInfMax() \
  (Rte_Inst_AP_Hello_World->ImplicitReadRunnable_SimpleReadProto_ReadElementRangeInfMax->value)


# define Rte_IRead_ImplicitReadRunnable_SimpleReadProto_SimpleReadElement() \
  (Rte_Inst_AP_Hello_World->ImplicitReadRunnable_SimpleReadProto_SimpleReadElement->value)


# define Rte_IStatus_ImplicitReadRunnable_SimpleReadProto_SimpleReadElement() \
  (Rte_Inst_AP_Hello_World->ImplicitReadRunnable_SimpleReadProto_SimpleReadElement->status)


# define Rte_IRead_ImplicitReadRunnable_SimpleReadTimeout_SimpleReadNeverReceived() \
  (Rte_Inst_AP_Hello_World->ImplicitReadRunnable_SimpleReadTimeout_SimpleReadNeverReceived->value)

# define Rte_IFeedback_ImpliciteWrite_ComplexPortTest_ComplexElement() \
   (Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_ComplexElement->status)


# define Rte_IWrite_ImpliciteWrite_ComplexPortTest_ComplexElement(data) \
  ( \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_ComplexElement->value = (data) \
  )


# define Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_ComplexElement() \
  (&Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_ComplexElement->value)


# define Rte_IWrite_ImpliciteWrite_ComplexPortTest_ConstrainedElement(data) \
  ( \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_ConstrainedElement->value = (data) \
  )


# define Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_ConstrainedElement() \
  (&Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_ConstrainedElement->value)


# define Rte_IWrite_ImpliciteWrite_ComplexPortTest_HandleInvalidElement(data) \
  ( \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_HandleInvalidElement->status = RTE_E_OK, \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_HandleInvalidElement->value = (data) \
  )


# define Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_HandleInvalidElement() \
  (&Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_HandleInvalidElement->value)


# define Rte_IInvalidate_ImpliciteWrite_ComplexPortTest_HandleInvalidElement() \
  (Rte_Inst_AP_Hello_World->ImpliciteWrite_ComplexPortTest_HandleInvalidElement->status = RTE_E_INVALID)


# define Rte_IWrite_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange(data) \
  ( \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_ReadElementOpenRange->status = RTE_E_OK, \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_ReadElementOpenRange->value = (data) \
  )


# define Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange() \
  (&Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_ReadElementOpenRange->value)


# define Rte_IInvalidate_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange() \
  (Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_ReadElementOpenRange->status = RTE_E_INVALID)


# define Rte_IWrite_ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax(data) \
  ( \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax->value = (data) \
  )


# define Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax() \
  (&Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax->value)


# define Rte_IWrite_ImpliciteWrite_SimpleWritePort_SimpleReadElement(data) \
  ( \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_SimpleReadElement->value = (data) \
  )


# define Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_SimpleReadElement() \
  (&Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_SimpleReadElement->value)


# define Rte_IWrite_ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived(data) \
  ( \
    Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived->value = (data) \
  )


# define Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived() \
  (&Rte_Inst_AP_Hello_World->ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived->value)


# define Rte_IRead_StructRunnable_StructSRInterface_IElement() \
  (&Rte_Inst_AP_Hello_World->StructRunnable_StructSRInterface_IElement->value)


# define Rte_IWrite_StructRunnable_StructSRInterface_IElement(data) \
  ( \
    Rte_Inst_AP_Hello_World->StructRunnable_StructSRInterface_IElement->value = *(data) \
  )


# define Rte_IWriteRef_StructRunnable_StructSRInterface_IElement() \
  (&Rte_Inst_AP_Hello_World->StructRunnable_StructSRInterface_IElement->value)


# define Rte_IRead_UnionRunnable_UnionSRInterface_implicitElem() \
  (&Rte_Inst_AP_Hello_World->UnionRunnable_UnionSRInterface_implicitElem->value)


# define Rte_IWrite_UnionRunnable_UnionSRInterface_implicitElem(data) \
  ( \
    Rte_Inst_AP_Hello_World->UnionRunnable_UnionSRInterface_implicitElem->value = *(data) \
  )


# define Rte_IWriteRef_UnionRunnable_UnionSRInterface_implicitElem() \
  (&Rte_Inst_AP_Hello_World->UnionRunnable_UnionSRInterface_implicitElem->value)


/**********************************************************************************************************************
 * Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
# define Rte_Receive_ComplexElementRx_QueuedElement Rte_Receive_AP_Hello_World_ComplexElementRx_QueuedElement


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_ArraySRInterface_acknowlegdement Rte_Read_AP_Hello_World_ArraySRInterface_acknowlegdement
# define Rte_Read_ArraySRInterface_constraint Rte_Read_AP_Hello_World_ArraySRInterface_constraint
# define Rte_Read_ArraySRInterface_errorHandling Rte_Read_AP_Hello_World_ArraySRInterface_errorHandling
# define Rte_Read_ArraySRInterface_handleKeep Rte_Read_AP_Hello_World_ArraySRInterface_handleKeep
# define Rte_Read_ArraySRInterface_init Rte_Read_AP_Hello_World_ArraySRInterface_init
# define Rte_Read_ArraySRInterface_initConstraint Rte_Read_AP_Hello_World_ArraySRInterface_initConstraint
# define Rte_Read_BooleanSR_isElement Rte_Read_AP_Hello_World_BooleanSR_isElement
# define Rte_Read_ComplexElementRx_ComplexElement Rte_Read_AP_Hello_World_ComplexElementRx_ComplexElement
# define Rte_Read_ComplexElementRx_ConstrainedElement Rte_Read_AP_Hello_World_ComplexElementRx_ConstrainedElement
# define Rte_Read_ComplexElementRx_HandleInvalidElement Rte_Read_AP_Hello_World_ComplexElementRx_HandleInvalidElement
# define Rte_Read_DataConstraintInterface_AllConstr Rte_Read_AP_Hello_World_DataConstraintInterface_AllConstr
# define Rte_Read_DataConstraintInterface_ApplicationTypeAllConstr Rte_Read_AP_Hello_World_DataConstraintInterface_ApplicationTypeAllConstr
# define Rte_Read_DataConstraintInterface_ApplicationTypeConstr Rte_Read_AP_Hello_World_DataConstraintInterface_ApplicationTypeConstr
# define Rte_Read_DataConstraintInterface_ApplicationTypeImplConstr Rte_Read_AP_Hello_World_DataConstraintInterface_ApplicationTypeImplConstr
# define Rte_Read_DataConstraintInterface_DataProtypeApplConstr Rte_Read_AP_Hello_World_DataConstraintInterface_DataProtypeApplConstr
# define Rte_Read_DataConstraintInterface_DataProtypeConstr Rte_Read_AP_Hello_World_DataConstraintInterface_DataProtypeConstr
# define Rte_Read_DataConstraintInterface_DataProtypeImplConstr Rte_Read_AP_Hello_World_DataConstraintInterface_DataProtypeImplConstr
# define Rte_Read_DataConstraintInterface_ImplementationTypeConstr Rte_Read_AP_Hello_World_DataConstraintInterface_ImplementationTypeConstr
# define Rte_Read_DataConstraintInterface_InfFloatConstr Rte_Read_AP_Hello_World_DataConstraintInterface_InfFloatConstr
# define Rte_Read_DataConstraintInterface_NoConstr Rte_Read_AP_Hello_World_DataConstraintInterface_NoConstr
# define Rte_Read_DoubleSRPort_explicitElem Rte_Read_AP_Hello_World_DoubleSRPort_explicitElem
# define Rte_DRead_IsUpdatedByValuePrototype_IdUpdatedByValueElement Rte_DRead_AP_Hello_World_IsUpdatedByValuePrototype_IdUpdatedByValueElement
# define Rte_Read_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement Rte_Read_AP_Hello_World_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement
# define Rte_Read_MultiArraySRInterface_multiArray Rte_Read_AP_Hello_World_MultiArraySRInterface_multiArray
# define Rte_Read_MultiArraySRInterface_multiArrayConstraint Rte_Read_AP_Hello_World_MultiArraySRInterface_multiArrayConstraint
# define Rte_DRead_ReadWithErrorHandler_ReadElementOpenRange Rte_DRead_AP_Hello_World_ReadWithErrorHandler_ReadElementOpenRange
# define Rte_Read_ReadWithErrorHandler_SimpleReadElement Rte_Read_AP_Hello_World_ReadWithErrorHandler_SimpleReadElement
# define Rte_DRead_SimpleNvDataPort_element_OneToTen Rte_DRead_AP_Hello_World_SimpleNvDataPort_element_OneToTen
# define Rte_Read_SimpleReadProto_ReadElementOpenRange Rte_Read_AP_Hello_World_SimpleReadProto_ReadElementOpenRange
# define Rte_Read_SimpleReadProto_ReadElementRangeInfMax Rte_Read_AP_Hello_World_SimpleReadProto_ReadElementRangeInfMax
# define Rte_Read_SimpleReadProto_SimpleReadElement Rte_Read_AP_Hello_World_SimpleReadProto_SimpleReadElement
# define Rte_DRead_SimpleReadTimeout_ReadElementOpenRange Rte_DRead_AP_Hello_World_SimpleReadTimeout_ReadElementOpenRange
# define Rte_Read_SimpleReadTimeout_SimpleReadElement Rte_Read_AP_Hello_World_SimpleReadTimeout_SimpleReadElement
# define Rte_Read_SimpleReadTimeout_SimpleReadNeverReceived Rte_Read_AP_Hello_World_SimpleReadTimeout_SimpleReadNeverReceived
# define Rte_Read_StructSRInterface_Element Rte_Read_AP_Hello_World_StructSRInterface_Element
# define Rte_Read_UnionSRInterface_explicitElem Rte_Read_AP_Hello_World_UnionSRInterface_explicitElem


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_IsUpdatedByValuePrototype_IdUpdatedByValueElement Rte_IsUpdated_AP_Hello_World_IsUpdatedByValuePrototype_IdUpdatedByValueElement
# define Rte_IsUpdated_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement Rte_IsUpdated_AP_Hello_World_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
# define Rte_Send_ComplexPortTest_QueuedElement Rte_Send_AP_Hello_World_ComplexPortTest_QueuedElement


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_AcknowledgmentInterface_nonWaitElement Rte_Write_AP_Hello_World_AcknowledgmentInterface_nonWaitElement
# define Rte_Write_AcknowledgmentInterface_waitElement Rte_Write_AP_Hello_World_AcknowledgmentInterface_waitElement
# define Rte_Write_ArraySRInterface_acknowlegdement Rte_Write_AP_Hello_World_ArraySRInterface_acknowlegdement
# define Rte_Write_ArraySRInterface_constraint Rte_Write_AP_Hello_World_ArraySRInterface_constraint
# define Rte_Write_ArraySRInterface_errorHandling Rte_Write_AP_Hello_World_ArraySRInterface_errorHandling
# define Rte_Write_ArraySRInterface_handleKeep Rte_Write_AP_Hello_World_ArraySRInterface_handleKeep
# define Rte_Write_ArraySRInterface_init Rte_Write_AP_Hello_World_ArraySRInterface_init
# define Rte_Write_ArraySRInterface_initConstraint Rte_Write_AP_Hello_World_ArraySRInterface_initConstraint
# define Rte_Write_DataConstraintInterface_AllConstr Rte_Write_AP_Hello_World_DataConstraintInterface_AllConstr
# define Rte_Write_DataConstraintInterface_ApplicationTypeAllConstr Rte_Write_AP_Hello_World_DataConstraintInterface_ApplicationTypeAllConstr
# define Rte_Write_DataConstraintInterface_ApplicationTypeConstr Rte_Write_AP_Hello_World_DataConstraintInterface_ApplicationTypeConstr
# define Rte_Write_DataConstraintInterface_ApplicationTypeImplConstr Rte_Write_AP_Hello_World_DataConstraintInterface_ApplicationTypeImplConstr
# define Rte_Write_DataConstraintInterface_DataProtypeApplConstr Rte_Write_AP_Hello_World_DataConstraintInterface_DataProtypeApplConstr
# define Rte_Write_DataConstraintInterface_DataProtypeConstr Rte_Write_AP_Hello_World_DataConstraintInterface_DataProtypeConstr
# define Rte_Write_DataConstraintInterface_DataProtypeImplConstr Rte_Write_AP_Hello_World_DataConstraintInterface_DataProtypeImplConstr
# define Rte_Write_DataConstraintInterface_ImplementationTypeConstr Rte_Write_AP_Hello_World_DataConstraintInterface_ImplementationTypeConstr
# define Rte_Write_DataConstraintInterface_NoConstr Rte_Write_AP_Hello_World_DataConstraintInterface_NoConstr
# define Rte_Write_DoubleSRPort_explicitElem Rte_Write_AP_Hello_World_DoubleSRPort_explicitElem
# define Rte_Write_Hello_World_port_Hello_World_Element Rte_Write_AP_Hello_World_Hello_World_port_Hello_World_Element
# define Rte_Write_MultiArraySRInterface_multiArray Rte_Write_AP_Hello_World_MultiArraySRInterface_multiArray
# define Rte_Write_MultiArraySRInterface_multiArrayConstraint Rte_Write_AP_Hello_World_MultiArraySRInterface_multiArrayConstraint
# define Rte_Write_StructSRInterface_Element Rte_Write_AP_Hello_World_StructSRInterface_Element
# define Rte_Write_UnionSRInterface_explicitElem Rte_Write_AP_Hello_World_UnionSRInterface_explicitElem


/**********************************************************************************************************************
 * Rte_Trigger_<p>_<o> (external event trigger communication)
 *********************************************************************************************************************/
# define Rte_Trigger_TriggerInterface_SomeTriggerElement Rte_Trigger_AP_Hello_World_TriggerInterface_SomeTriggerElement
# define Rte_Trigger_TriggerInterfaceError_SomeTriggerElement Rte_Trigger_AP_Hello_World_TriggerInterfaceError_SomeTriggerElement


/**********************************************************************************************************************
 * Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Invalidate_ArraySRInterface_acknowlegdement Rte_Invalidate_AP_Hello_World_ArraySRInterface_acknowlegdement
# define Rte_Invalidate_ArraySRInterface_constraint Rte_Invalidate_AP_Hello_World_ArraySRInterface_constraint
# define Rte_Invalidate_ArraySRInterface_errorHandling Rte_Invalidate_AP_Hello_World_ArraySRInterface_errorHandling
# define Rte_Invalidate_ArraySRInterface_handleKeep Rte_Invalidate_AP_Hello_World_ArraySRInterface_handleKeep
# define Rte_Invalidate_ArraySRInterface_init Rte_Invalidate_AP_Hello_World_ArraySRInterface_init
# define Rte_Invalidate_ArraySRInterface_initConstraint Rte_Invalidate_AP_Hello_World_ArraySRInterface_initConstraint
# define Rte_Invalidate_Hello_World_port_Hello_World_Element Rte_Invalidate_AP_Hello_World_Hello_World_port_Hello_World_Element


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<d> (explicit S/R communication status handling)
 *********************************************************************************************************************/
# define Rte_Feedback_AcknowledgmentInterface_nonWaitElement Rte_Feedback_AP_Hello_World_AcknowledgmentInterface_nonWaitElement
# define Rte_Feedback_AcknowledgmentInterface_waitElement Rte_Feedback_AP_Hello_World_AcknowledgmentInterface_waitElement
# define Rte_Feedback_ArraySRInterface_acknowlegdement Rte_Feedback_AP_Hello_World_ArraySRInterface_acknowlegdement
# define Rte_Feedback_ComplexPortTest_QueuedElement Rte_Feedback_AP_Hello_World_ComplexPortTest_QueuedElement


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_EnhancedPortInterface_Mode Rte_Mode_AP_Hello_World_EnhancedPortInterface_Mode
# define Rte_Mode_Mode_Port_Interface_ModeGroup Rte_Mode_AP_Hello_World_Mode_Port_Interface_ModeGroup


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Switch_Mode_Port_Interface_ModeGroup Rte_Switch_AP_Hello_World_Mode_Port_Interface_ModeGroup


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
# define Rte_SwitchAck_Mode_Port_Interface_ModeGroup Rte_SwitchAck_AP_Hello_World_Mode_Port_Interface_ModeGroup


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_ArrayCSPort_sumArray Rte_Call_AP_Hello_World_ArrayCSPort_sumArray
# define Rte_Call_CallPortInterface_InOutOperation Rte_Call_AP_Hello_World_CallPortInterface_InOutOperation
# define Rte_Call_CallPortInterface_SimpleIntOperation Rte_Call_AP_Hello_World_CallPortInterface_SimpleIntOperation
# define Rte_Call_DoubleCS_f Rte_Call_AP_Hello_World_DoubleCS_f
# define Rte_Call_NvMService_service_client_GetErrorStatus Rte_Call_AP_Hello_World_NvMService_service_client_GetErrorStatus
# define Rte_Call_NvSWC_NvMAdministration_client_SetBlockProtection Rte_Call_AP_Hello_World_NvSWC_NvMAdministration_client_SetBlockProtection
# define Rte_Call_NvSWC_NvMNotifyInitBlock_client_InitBlock Rte_Call_AP_Hello_World_NvSWC_NvMNotifyInitBlock_client_InitBlock
# define Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_GetErrorStatus Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_GetErrorStatus
# define Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_RestoreBlockDefaults Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_RestoreBlockDefaults
# define Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus
# define Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock
# define Rte_Call_NvSWC_NvMService_AC2_client_GetErrorStatus Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_client_GetErrorStatus
# define Rte_Call_NvSWC_NvMService_AC2_client_ReadBlock Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_client_ReadBlock
# define Rte_Call_NvSWC_NvMService_AC2_client_WriteBlock Rte_Call_AP_Hello_World_NvSWC_NvMService_AC2_client_WriteBlock
# define Rte_Call_NvSWC_NvMService_client_GetErrorStatus Rte_Call_AP_Hello_World_NvSWC_NvMService_client_GetErrorStatus
# define Rte_Call_StructCSInterface_cloneStruct Rte_Call_AP_Hello_World_StructCSInterface_cloneStruct
# define Rte_Call_UnionCInterface_f Rte_Call_AP_Hello_World_UnionCInterface_f


/**********************************************************************************************************************
 * Rte_Result_<p>_<o> (asynchronous C/S result)
 *********************************************************************************************************************/
# define Rte_Result_CallPortInterface_InOutOperation Rte_Result_AP_Hello_World_CallPortInterface_InOutOperation
# define Rte_Result_NvMService_service_client_GetErrorStatus Rte_Result_AP_Hello_World_NvMService_service_client_GetErrorStatus
# define Rte_Result_NvSWC_NvMAdministration_client_SetBlockProtection Rte_Result_AP_Hello_World_NvSWC_NvMAdministration_client_SetBlockProtection
# define Rte_Result_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus Rte_Result_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus
# define Rte_Result_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock Rte_Result_AP_Hello_World_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock
# define Rte_Result_NvSWC_NvMService_client_GetErrorStatus Rte_Result_AP_Hello_World_NvSWC_NvMService_client_GetErrorStatus


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_TestExclusiveArea Rte_Enter_AP_Hello_World_TestExclusiveArea /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
# define Rte_Exit_TestExclusiveArea Rte_Exit_AP_Hello_World_TestExclusiveArea /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvRead_InterVariableRunnable_ExplicitInterRunnableStruct(data) \
  Rte_IrvRead_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableStruct(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvRead_InterVariableRunnable_ExplicitInterRunnableValue() \
  Rte_IrvRead_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableValue()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableStruct(data) \
  Rte_IrvWrite_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableStruct(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableValue(data) \
  Rte_IrvWrite_AP_Hello_World_InterVariableRunnable_ExplicitInterRunnableValue(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableStruct() \
  (Rte_Inst_AP_Hello_World->Irv_InterVariableRunnable_ImplicitInterRunnableStruct)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableValue() \
  (*(Rte_Inst_AP_Hello_World->Irv_InterVariableRunnable_ImplicitInterRunnableValue))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableStruct(data) \
  (*(Rte_Inst_AP_Hello_World->Irv_InterVariableRunnable_ImplicitInterRunnableStruct) = *(data))
# define Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableStruct() \
  (Rte_Inst_AP_Hello_World->Irv_InterVariableRunnable_ImplicitInterRunnableStruct)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableValue(data) \
  (*(Rte_Inst_AP_Hello_World->Irv_InterVariableRunnable_ImplicitInterRunnableValue) = (data))
# define Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableValue() \
  (Rte_Inst_AP_Hello_World->Irv_InterVariableRunnable_ImplicitInterRunnableValue)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_PerInstanceInternalCalibrationParameter Rte_CData_AP_Hello_World_PerInstanceInternalCalibrationParameter

# define Rte_CData_SharedInternalCalibrationParameter Rte_CData_AP_Hello_World_SharedInternalCalibrationParameter

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_DoubleCalibration_doubleElem Rte_Prm_AP_Hello_World_DoubleCalibration_doubleElem

# define Rte_Prm_CalibrationPortInterface_CalibrationElement Rte_Prm_AP_Hello_World_CalibrationPortInterface_CalibrationElement

# define Rte_Prm_CalibrationPrimitiveType_notAccessibleElement Rte_Prm_AP_Hello_World_CalibrationPrimitiveType_notAccessibleElement

# define Rte_Prm_CalibrationPrimitiveType_readOnlyElement Rte_Prm_AP_Hello_World_CalibrationPrimitiveType_readOnlyElement

# define Rte_Prm_CalibrationPrimitiveType_readWriteElement Rte_Prm_AP_Hello_World_CalibrationPrimitiveType_readWriteElement

# define Rte_Prm_ArrayCalibration_arrayElement Rte_Prm_AP_Hello_World_ArrayCalibration_arrayElement

# define Rte_Prm_ArrayCalibration_variableArrayElem Rte_Prm_AP_Hello_World_ArrayCalibration_variableArrayElem

# define Rte_Prm_MultiArrayCalibration_multiArrayElement Rte_Prm_AP_Hello_World_MultiArrayCalibration_multiArrayElement

# define Rte_Prm_RefTypeCalibration_notAccessibleElement Rte_Prm_AP_Hello_World_RefTypeCalibration_notAccessibleElement

# define Rte_Prm_RefTypeCalibration_readOnlyElement Rte_Prm_AP_Hello_World_RefTypeCalibration_readOnlyElement

# define Rte_Prm_RefTypeCalibration_readWriteElement Rte_Prm_AP_Hello_World_RefTypeCalibration_readWriteElement

# define Rte_Prm_StructCalibration_Element Rte_Prm_AP_Hello_World_StructCalibration_Element

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Rte_Pim_PerInstanceMemory() (Rte_Inst_AP_Hello_World->Pim_PerInstanceMemory)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint16 *Rte_Pim_PerInstanceMemory(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   customUInt8 Rte_CData_PerInstanceInternalCalibrationParameter(void)
 *   customUInt8 Rte_CData_SharedInternalCalibrationParameter(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   customFloat64 Rte_Prm_DoubleCalibration_doubleElem(void)
 *   uint16 Rte_Prm_CalibrationPortInterface_CalibrationElement(void)
 *   uint8 Rte_Prm_CalibrationPrimitiveType_notAccessibleElement(void)
 *   uint8 Rte_Prm_CalibrationPrimitiveType_readOnlyElement(void)
 *   uint8 Rte_Prm_CalibrationPrimitiveType_readWriteElement(void)
 *   Rte_DT_IntArrayImpl_0 *Rte_Prm_ArrayCalibration_arrayElement(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Rte_DT_variableArrayImpl_0 *Rte_Prm_ArrayCalibration_variableArrayElem(void)
 *     Returnvalue: Rte_DT_variableArrayImpl_0* is of type variableArrayImpl
 *   Rte_DT_IntArrayImpl_0 *Rte_Prm_MultiArrayCalibration_multiArrayElement(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *   Rte_DT_CharArrayImplementation_0 *Rte_Prm_RefTypeCalibration_notAccessibleElement(void)
 *     Returnvalue: Rte_DT_CharArrayImplementation_0* is of type CharArrayImplementation
 *   Rte_DT_CharArrayImplementation_0 *Rte_Prm_RefTypeCalibration_readOnlyElement(void)
 *     Returnvalue: Rte_DT_CharArrayImplementation_0* is of type CharArrayImplementation
 *   Rte_DT_CharArrayImplementation_0 *Rte_Prm_RefTypeCalibration_readWriteElement(void)
 *     Returnvalue: Rte_DT_CharArrayImplementation_0* is of type CharArrayImplementation
 *   ComplexStructImpl *Rte_Prm_StructCalibration_Element(void)
 *
 *********************************************************************************************************************/


# define AP_Hello_World_START_SEC_CODE
# include "AP_Hello_World_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ArrayRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ArraySRInterface_acknowlegdement(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Read_ArraySRInterface_constraint(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Read_ArraySRInterface_errorHandling(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Read_ArraySRInterface_handleKeep(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Read_ArraySRInterface_init(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Read_ArraySRInterface_initConstraint(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *
 *   Implicit S/R API:
 *   -----------------
 *   Rte_DT_IntArrayImpl_0 *Rte_IRead_ArrayRunnable_ArraySRInterface_INone(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Rte_DT_IntArrayImpl_0 *Rte_IRead_ArrayRunnable_ArraySRInterface_Iconstraint(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ArraySRInterface_acknowlegdement(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Write_ArraySRInterface_constraint(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Write_ArraySRInterface_errorHandling(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Write_ArraySRInterface_handleKeep(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Write_ArraySRInterface_init(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Write_ArraySRInterface_initConstraint(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Std_ReturnType Rte_Invalidate_ArraySRInterface_acknowlegdement(void)
 *   Std_ReturnType Rte_Invalidate_ArraySRInterface_constraint(void)
 *   Std_ReturnType Rte_Invalidate_ArraySRInterface_errorHandling(void)
 *   Std_ReturnType Rte_Invalidate_ArraySRInterface_handleKeep(void)
 *   Std_ReturnType Rte_Invalidate_ArraySRInterface_init(void)
 *   Std_ReturnType Rte_Invalidate_ArraySRInterface_initConstraint(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ArrayRunnable_ArraySRInterface_INone(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Rte_DT_IntArrayImpl_0 *Rte_IWriteRef_ArrayRunnable_ArraySRInterface_INone(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   void Rte_IWrite_ArrayRunnable_ArraySRInterface_Iconstraint(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   Rte_DT_IntArrayImpl_0 *Rte_IWriteRef_ArrayRunnable_ArraySRInterface_Iconstraint(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *   void Rte_IInvalidate_ArrayRunnable_ArraySRInterface_Iconstraint(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ArrayCSPort_sumArray(const Rte_DT_IntArrayImpl_0 *arg, Rte_DT_IntArrayImpl_0 *arg_1, Rte_DT_IntArrayImpl_0 *arg_2)
 *     Argument arg: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *     Argument arg_1: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *     Argument arg_2: Rte_DT_IntArrayImpl_0* is of type IntArrayImpl
 *     Synchronous Server Invocation. Timeout: None
 *
 * Status Interfaces:
 * ==================
 *   Tx Acknowledge:
 *   ----------------
 *   Std_ReturnType Rte_Feedback_ArraySRInterface_acknowlegdement(void)
 *
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_ArrayRunnable_ArraySRInterface_Iconstraint(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ArrayRunnable ArrayRunnable
FUNC(void, AP_Hello_World_CODE) ArrayRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BooleanRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BooleanSR_isElement(boolean *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BooleanRunnable BooleanRunnable
FUNC(void, AP_Hello_World_CODE) BooleanRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComplexArrayRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MultiArraySRInterface_multiArray(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *   Std_ReturnType Rte_Read_MultiArraySRInterface_multiArrayConstraint(Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *
 *   Implicit S/R API:
 *   -----------------
 *   Rte_DT_IntArrayImpl_0 *Rte_IRead_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MultiArraySRInterface_multiArray(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *   Std_ReturnType Rte_Write_MultiArraySRInterface_multiArrayConstraint(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(const Rte_DT_IntArrayImpl_0 *data)
 *     Argument data: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *   Rte_DT_IntArrayImpl_0 *Rte_IWriteRef_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(void)
 *     Returnvalue: Rte_DT_IntArrayImpl_0* is of type multiArrayThreeImpl
 *   void Rte_IInvalidate_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(void)
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ComplexArrayRunnable ComplexArrayRunnable
FUNC(void, AP_Hello_World_CODE) ComplexArrayRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComplexRxRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 42ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_ComplexElementRx_QueuedElement(uint64 *data)
 *   Std_ReturnType Rte_Read_ComplexElementRx_ComplexElement(NvM_RequestResultType *data)
 *   Std_ReturnType Rte_Read_ComplexElementRx_ConstrainedElement(uint64 *data)
 *   Std_ReturnType Rte_Read_ComplexElementRx_HandleInvalidElement(uint64 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ComplexRxRunnable ComplexRxRunnable
FUNC(void, AP_Hello_World_CODE) ComplexRxRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DReadRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   sint8 Rte_DRead_ReadWithErrorHandler_ReadElementOpenRange(void)
 *   uint64 Rte_DRead_SimpleNvDataPort_element_OneToTen(void)
 *   sint8 Rte_DRead_SimpleReadTimeout_ReadElementOpenRange(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DReadRunnable DReadRunnable
FUNC(void, AP_Hello_World_CODE) DReadRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DTCServiceRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DTCServiceRunnable DTCServiceRunnable
FUNC(void, AP_Hello_World_CODE) DTCServiceRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataConstraintRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DataConstraintInterface_AllConstr(UintConstrImpl *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_ApplicationTypeAllConstr(UintConstrImpl *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_ApplicationTypeConstr(customUInt8 *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_ApplicationTypeImplConstr(UintConstrImpl *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_DataProtypeApplConstr(customUInt8 *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_DataProtypeConstr(uint8 *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_DataProtypeImplConstr(UintConstrImpl *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_ImplementationTypeConstr(UintConstrImpl *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_InfFloatConstr(float32 *data)
 *   Std_ReturnType Rte_Read_DataConstraintInterface_NoConstr(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DataConstraintInterface_AllConstr(UintConstrImpl data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_ApplicationTypeAllConstr(UintConstrImpl data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_ApplicationTypeConstr(customUInt8 data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_ApplicationTypeImplConstr(UintConstrImpl data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_DataProtypeApplConstr(customUInt8 data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_DataProtypeConstr(uint8 data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_DataProtypeImplConstr(UintConstrImpl data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_ImplementationTypeConstr(UintConstrImpl data)
 *   Std_ReturnType Rte_Write_DataConstraintInterface_NoConstr(uint8 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DataConstraintRunnable DataConstraintRunnable
FUNC(void, AP_Hello_World_CODE) DataConstraintRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DoubleRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DoubleSRPort_explicitElem(customFloat64 *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   customFloat64 Rte_IRead_DoubleRunnable_DoubleSRPort_implicitElem(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DoubleSRPort_explicitElem(customFloat64 data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_DoubleRunnable_DoubleSRPort_implicitElem(customFloat64 data)
 *   customFloat64 *Rte_IWriteRef_DoubleRunnable_DoubleSRPort_implicitElem(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_DoubleCS_f(customFloat64 arg, customFloat64 *arg_1)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DoubleRunnable DoubleRunnable
FUNC(void, AP_Hello_World_CODE) DoubleRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ExplicitReadByValue
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 45ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReadWithErrorHandler_SimpleReadElement(sint16 *data)
 *   Std_ReturnType Rte_Read_SimpleReadProto_ReadElementOpenRange(sint8 *data)
 *   Std_ReturnType Rte_Read_SimpleReadProto_ReadElementRangeInfMax(customDouble32 *data)
 *   Std_ReturnType Rte_Read_SimpleReadProto_SimpleReadElement(sint16 *data)
 *   Std_ReturnType Rte_Read_SimpleReadTimeout_SimpleReadElement(sint16 *data)
 *   Std_ReturnType Rte_Read_SimpleReadTimeout_SimpleReadNeverReceived(uint64 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ExplicitReadByValue ExplicitReadByValue
FUNC(void, AP_Hello_World_CODE) ExplicitReadByValue(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FeedbackRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AcknowledgmentInterface_nonWaitElement(uint64 data)
 *   Std_ReturnType Rte_Write_AcknowledgmentInterface_waitElement(uint64 data)
 *
 * Status Interfaces:
 * ==================
 *   Tx Acknowledge:
 *   ----------------
 *   Std_ReturnType Rte_Feedback_AcknowledgmentInterface_nonWaitElement(void)
 *   Std_ReturnType Rte_Feedback_AcknowledgmentInterface_waitElement(void)
 *     Blocking Tx Acknowledge Access. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FeedbackRunnable FeedbackRunnable
FUNC(void, AP_Hello_World_CODE) FeedbackRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Hello_World_Runnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by ExternalTriggerOccurredEvent for TriggerElement <SomeTriggerElement> of PortPrototype <TriggerInterface>
 *   - triggered by ExternalTriggerOccurredEvent for TriggerElement <SomeTriggerElement> of PortPrototype <TriggerInterfaceError>
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_ComplexPortTest_QueuedElement(uint64 data, Std_TransformerError *transformerError)
 *   Std_ReturnType Rte_Write_Hello_World_port_Hello_World_Element(boolean data, Std_TransformerError *transformerError)
 *   Std_ReturnType Rte_Invalidate_Hello_World_port_Hello_World_Element(P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError)
 *
 * Trigger Interfaces:
 * ===================
 *   void Rte_Trigger_TriggerInterface_SomeTriggerElement(void)
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Mode_Port_Interface_ModeGroup(uint8 mode)
 *   Modes of Rte_ModeType_ModeDeclarationGroup:
 *   - RTE_MODE_ModeDeclarationGroup_SomeMode
 *   - RTE_MODE_ModeDeclarationGroup_SomeOtherMode
 *   - RTE_TRANSITION_ModeDeclarationGroup
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_client_GetErrorStatus(void)
 *     Asynchronous Server Invocation
 *
 *   Server Result:
 *   --------------
 *   Std_ReturnType Rte_Result_NvSWC_NvMService_client_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Blocking Result. Timeout: 3s
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Mode Switch Acknowledge:
 *   -------------------------
 *   Std_ReturnType Rte_SwitchAck_Mode_Port_Interface_ModeGroup(void)
 *     Blocking Mode Switch Acknowledge Access. Timeout: 42s
 *
 *   Tx Acknowledge:
 *   ----------------
 *   Std_ReturnType Rte_Feedback_ComplexPortTest_QueuedElement(void)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TestExclusiveArea(void)
 *   void Rte_Exit_TestExclusiveArea(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Hello_World_Runnable Hello_World_Runnable
FUNC(void, AP_Hello_World_CODE) Hello_World_Runnable(P2CONST(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError); /* PRQA S 3451 */ /* MD_Rte_3451 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ImplicitReadRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 123ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   sint8 Rte_IRead_ImplicitReadRunnable_SimpleReadProto_ReadElementOpenRange(void)
 *   customDouble32 Rte_IRead_ImplicitReadRunnable_SimpleReadProto_ReadElementRangeInfMax(void)
 *   sint16 Rte_IRead_ImplicitReadRunnable_SimpleReadProto_SimpleReadElement(void)
 *   uint64 Rte_IRead_ImplicitReadRunnable_SimpleReadTimeout_SimpleReadNeverReceived(void)
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_ImplicitReadRunnable_SimpleReadProto_ReadElementOpenRange(void)
 *   Std_ReturnType Rte_IStatus_ImplicitReadRunnable_SimpleReadProto_SimpleReadElement(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ImplicitReadRunnable ImplicitReadRunnable
FUNC(void, AP_Hello_World_CODE) ImplicitReadRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ImpliciteWrite
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ImpliciteWrite_ComplexPortTest_ComplexElement(NvM_RequestResultType data)
 *   NvM_RequestResultType *Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_ComplexElement(void)
 *   void Rte_IWrite_ImpliciteWrite_ComplexPortTest_ConstrainedElement(uint64 data)
 *   uint64 *Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_ConstrainedElement(void)
 *   void Rte_IWrite_ImpliciteWrite_ComplexPortTest_HandleInvalidElement(uint64 data)
 *   uint64 *Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_HandleInvalidElement(void)
 *   void Rte_IInvalidate_ImpliciteWrite_ComplexPortTest_HandleInvalidElement(void)
 *   void Rte_IWrite_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange(sint8 data)
 *   sint8 *Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange(void)
 *   void Rte_IInvalidate_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange(void)
 *   void Rte_IWrite_ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax(customDouble32 data)
 *   customDouble32 *Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax(void)
 *   void Rte_IWrite_ImpliciteWrite_SimpleWritePort_SimpleReadElement(sint16 data)
 *   sint16 *Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_SimpleReadElement(void)
 *   void Rte_IWrite_ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived(uint64 data)
 *   uint64 *Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ImpliciteWrite ImpliciteWrite
FUNC(void, AP_Hello_World_CODE) ImpliciteWrite(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: InterVariableRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   void Rte_IrvRead_InterVariableRunnable_ExplicitInterRunnableStruct(ComplexStructImpl *data)
 *   customUInt8 Rte_IrvRead_InterVariableRunnable_ExplicitInterRunnableValue(void)
 *
 *   Implicit Read Access:
 *   ---------------------
 *   ComplexStructImpl * Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableStruct(void)
 *   customUInt8 Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableValue(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableStruct(ComplexStructImpl *data)
 *   void Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableValue(customUInt8 data)
 *
 *   Implicit Write Access:
 *   ----------------------
 *   void Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableStruct(ComplexStructImpl *data)
 *   ComplexStructImpl *Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableStruct(void)
 *
 *   void Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableValue(customUInt8 data)
 *   customUInt8 *Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableValue(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_InterVariableRunnable InterVariableRunnable
FUNC(void, AP_Hello_World_CODE) InterVariableRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IsUpdatedRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   uint64 Rte_DRead_IsUpdatedByValuePrototype_IdUpdatedByValueElement(void)
 *   Std_ReturnType Rte_Read_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement(uint64 *data)
 *   boolean Rte_IsUpdated_IsUpdatedByValuePrototype_IdUpdatedByValueElement(void)
 *   boolean Rte_IsUpdated_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement(void)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_IsUpdatedRunnable IsUpdatedRunnable
FUNC(void, AP_Hello_World_CODE) IsUpdatedRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ModeRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_EnhancedPortInterface_Mode(Rte_ModeType_ExplicitModeGroup *previousMode, Rte_ModeType_ExplicitModeGroup *nextMode)
 *   Modes of Rte_ModeType_ExplicitModeGroup:
 *   - RTE_MODE_ExplicitModeGroup_Init
 *   - RTE_MODE_ExplicitModeGroup_Last
 *   - RTE_MODE_ExplicitModeGroup_Next
 *   - RTE_TRANSITION_ExplicitModeGroup
 *   uint8 Rte_Mode_Mode_Port_Interface_ModeGroup(void)
 *   Modes of Rte_ModeType_ModeDeclarationGroup:
 *   - RTE_MODE_ModeDeclarationGroup_SomeMode
 *   - RTE_MODE_ModeDeclarationGroup_SomeOtherMode
 *   - RTE_TRANSITION_ModeDeclarationGroup
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ModeRunnable ModeRunnable
FUNC(void, AP_Hello_World_CODE) ModeRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MultipleInstanciationRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 132ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SimpleReadProto_SimpleReadElement(sint16 *data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MultipleInstanciationRunnable MultipleInstanciationRunnable
FUNC(void, AP_Hello_World_CODE) MultipleInstanciationRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReceiveRecordRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ReceiveRecordRunnable ReceiveRecordRunnable
FUNC(void, AP_Hello_World_CODE) ReceiveRecordRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ServiceRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 42ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CallPortInterface_InOutOperation(sint16 int_var, const ComplexStructImpl *struct_var, const Rte_DT_FloatArrayImplementation_0 *array_var)
 *     Argument array_var: Rte_DT_FloatArrayImplementation_0* is of type FloatArrayImplementation
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_CallPortInterface_SimpleIntOperation(sint16 arg, customDouble32 *arg_1)
 *     Synchronous Server Invocation. Timeout: 10ms
 *   Std_ReturnType Rte_Call_NvSWC_NvMAdministration_client_SetBlockProtection(boolean ProtectionEnabled)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_NvSWC_NvMNotifyInitBlock_client_InitBlock(Std_TransformerError *transformerError)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_GetErrorStatus(NvM_RequestResultType *ErrorStatus, Std_TransformerError *transformerError)
 *     Synchronous Server Invocation. Timeout: 10us
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_RestoreBlockDefaults(dtRef_VOID DstPtr, Std_TransformerError *transformerError)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus(boolean RamBlockStatus, Std_TransformerError *transformerError)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock(dtRef_const_VOID SrcPtr, Std_TransformerError *transformerError)
 *     Asynchronous Server Invocation
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_AC2_client_GetErrorStatus(NvM_RequestResultType *ErrorStatus, Std_TransformerError *transformerError)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_AC2_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_AC2_client_ReadBlock(dtRef_VOID DstPtr, Std_TransformerError *transformerError)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_AC2_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvSWC_NvMService_AC2_client_WriteBlock(dtRef_const_VOID SrcPtr, Std_TransformerError *transformerError)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_AC2_E_NOT_OK
 *
 *   Server Result:
 *   --------------
 *   Std_ReturnType Rte_Result_CallPortInterface_InOutOperation(sint16 *int_var, ComplexStructImpl *struct_var, Rte_DT_FloatArrayImplementation_0 *array_var)
 *     Argument array_var: Rte_DT_FloatArrayImplementation_0* is of type FloatArrayImplementation
 *     Blocking Result. Timeout: None
 *   Std_ReturnType Rte_Result_NvSWC_NvMAdministration_client_SetBlockProtection(void)
 *     Blocking Result. Timeout: 2s
 *     Returned Application Errors: RTE_E_NvSWC_NvMAdministration_E_NOT_OK
 *   Std_ReturnType Rte_Result_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus(Std_TransformerError *transformerError)
 *     Blocking Result. Timeout: 2s
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Result_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock(Std_TransformerError *transformerError)
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_AC2_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Result_NvSWC_NvMService_client_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Blocking Result. Timeout: 3s
 *     Returned Application Errors: RTE_E_NvSWC_NvMService_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_service_client_GetErrorStatus(void)
 *     Asynchronous Service Invocation
 *
 *   Service Result:
 *   ---------------
 *   Std_ReturnType Rte_Result_NvMService_service_client_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Returned Application Errors: RTE_E_NvMService_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ServiceRunnable ServiceRunnable
FUNC(void, AP_Hello_World_CODE) ServiceRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StructRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_StructSRInterface_Element(ComplexStructImpl *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   ComplexStructImpl *Rte_IRead_StructRunnable_StructSRInterface_IElement(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_StructSRInterface_Element(const ComplexStructImpl *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StructRunnable_StructSRInterface_IElement(const ComplexStructImpl *data)
 *   ComplexStructImpl *Rte_IWriteRef_StructRunnable_StructSRInterface_IElement(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_StructCSInterface_cloneStruct(const ComplexStructImpl *arg, ComplexStructImpl *arg_1)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_StructRunnable StructRunnable
FUNC(void, AP_Hello_World_CODE) StructRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TriggerRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Trigger Interfaces:
 * ===================
 *   void Rte_Trigger_TriggerInterface_SomeTriggerElement(void)
 *   void Rte_Trigger_TriggerInterfaceError_SomeTriggerElement(P2VAR(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError)
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TriggerRunnable TriggerRunnable
FUNC(void, AP_Hello_World_CODE) TriggerRunnable(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: UnionRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_UnionSRInterface_explicitElem(unionImpl *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   unionImpl *Rte_IRead_UnionRunnable_UnionSRInterface_implicitElem(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_UnionSRInterface_explicitElem(const unionImpl *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_UnionRunnable_UnionSRInterface_implicitElem(const unionImpl *data)
 *   unionImpl *Rte_IWriteRef_UnionRunnable_UnionSRInterface_implicitElem(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_UnionCInterface_f(unionImpl *arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_UnionRunnable UnionRunnable
FUNC(void, AP_Hello_World_CODE) UnionRunnable(void);

# define AP_Hello_World_STOP_SEC_CODE
# include "AP_Hello_World_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NvMService_E_NOT_OK (1U)

# define RTE_E_NvSWC_NvMAdministration_E_NOT_OK (1U)

# define RTE_E_NvSWC_NvMService_E_NOT_OK (1U)

# define RTE_E_NvSWC_NvMService_AC2_E_NOT_OK (1U)

# define RTE_E_NvSWC_NvMService_AC2_SRBS_Defs_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_AP_HELLO_WORLD_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_1507:  MISRA rule: Rule5.6
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
