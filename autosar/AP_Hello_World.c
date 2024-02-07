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
 *  Implementation template
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This implementation is incomplete and is neither intended nor qualified for use in series production
 *                without applying suitable quality measures. The implementation as well as any of its modifications
 *                must be tested with diligent care and must comply with all quality requirements which are necessary
 *                according to the state of the art before its use.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  AP_Hello_World.c
 *        SW-C Type:  AP_Hello_World
 *  Generation Time:  2023-12-15 09:22:57
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.22
 *                    RTE Core Version 4.31.0
 *          License:  DVSwcGen
 *
 *      Description:  C-Code implementation template for SW-C <AP_Hello_World>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *
 * Data Element Prototypes:
 * ========================
 * QueuedElement of Port Interface ComplexPortTest
 *   uint64 with uint32_DataConstr data constraint.
 *
 *
 *********************************************************************************************************************/

#include "Rte_AP_Hello_World.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Types_Typedefs.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * NvM_RequestResultType: Integer in interval [0...255]
 * Rte_DT_CharArrayImplementation_0: Integer in interval [0...255]
 * Rte_DT_ComplexStructImpl_0: Integer in interval [-32768...32767]
 * Rte_DT_ComplexStructImpl_1: Real in interval [-FLT_MAX...99] with single precision
 * Rte_DT_FloatArrayImplementation_0: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * Rte_DT_IntArrayImpl_0: Integer in interval [-32768...32767]
 * Rte_DT_SimpleStructImpl_0: Boolean
 * Rte_DT_unionImpl_0: Integer in interval [1...99]
 * Rte_DT_unionImpl_1_0: Integer in interval [1...10]
 * Rte_DT_unionImpl_2_0: Integer in interval [1...10]
 * Rte_DT_variableArrayImpl_0: Integer in interval [0...255]
 * UintConstrImpl: Integer in interval [1...20]
 * boolean: Boolean (standard type)
 * customDouble32: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * customFloat64: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * customUInt8: Integer in interval [0...255]
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * CharArrayImplementation: Array with 30 element(s) of type Rte_DT_CharArrayImplementation_0
 * FloatArrayImplementation: Array with 15 element(s) of type Rte_DT_FloatArrayImplementation_0
 * IntArrayImpl: Array with 10 element(s) of type Rte_DT_IntArrayImpl_0
 * Rte_DT_unionImpl_1: Array with 5 element(s) of type Rte_DT_unionImpl_1_0
 * multiArrayThreeImpl: Array with 2 element(s) of type multiArrayTwoImpl
 * multiArrayTwoImpl: Array with 3 element(s) of type IntArrayImpl
 * variableArrayImpl: Array with 10 element(s) of type Rte_DT_variableArrayImpl_0
 *
 * Record Types:
 * =============
 * ComplexStructImpl: Record with elements
 *   intElement of type Rte_DT_ComplexStructImpl_0
 *   floatElement of type Rte_DT_ComplexStructImpl_1
 *   arrrayElement of type IntArrayImpl
 *   structElement of type SimpleStructImpl
 * Rte_DT_unionImpl_2: Record with elements
 *   intElem of type Rte_DT_unionImpl_2_0
 * SimpleStructImpl: Record with elements
 *   boolElement of type Rte_DT_SimpleStructImpl_0
 *   constrElement of type sint8
 *
 * Union Types:
 * =============
 * unionImpl: Union with elements
 *   valueElem of type Rte_DT_unionImpl_0
 *   arrayElem of type Rte_DT_unionImpl_1
 *   structElem of type Rte_DT_unionImpl_2
 *
 *********************************************************************************************************************/


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


#define AP_Hello_World_START_SEC_CODE
#include "AP_Hello_World_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ArrayRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ArrayRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ArrayRunnable
 *********************************************************************************************************************/

  Std_ReturnType rt;
#ifdef RTE_PTR2ARRAYTYPE_PASSING
  IntArrayImpl arr;
  IntArrayImpl *data = &arr;
  rt = Rte_Read_ArraySRInterface_acknowlegdement(data);
  if (rt == RTE_E_OK) {
  } else {
  }
  rt = Rte_Read_ArraySRInterface_constraint(data);
  if (rt == RTE_E_OK) {
  } else {
  }
  data = Rte_IRead_ArrayRunnable_ArraySRInterface_INone();
  data = Rte_IRead_ArrayRunnable_ArraySRInterface_Iconstraint();
  rt = Rte_Write_ArraySRInterface_acknowlegdement(data);
  rt = Rte_Invalidate_ArraySRInterface_acknowlegdement();
  Rte_IWrite_ArrayRunnable_ArraySRInterface_INone(data);
  data = Rte_IWriteRef_ArrayRunnable_ArraySRInterface_INone();
  Rte_IInvalidate_ArrayRunnable_ArraySRInterface_Iconstraint();
  rt = Rte_Feedback_ArraySRInterface_acknowlegdement();
  rt = Rte_IStatus_ArrayRunnable_ArraySRInterface_Iconstraint();
  data = Rte_Prm_ArrayCalibration_arrayElement();
#else
  Rte_DT_IntArrayImpl_0 arr[10];
  Rte_DT_IntArrayImpl_0 *data = &arr;
  rt = Rte_Read_ArraySRInterface_acknowlegdement(data);
  if (rt == RTE_E_OK) {
  } else {
  }
  rt = Rte_Read_ArraySRInterface_constraint(data);
  if (rt == RTE_E_OK) {
  } else {
  }
  data = Rte_IRead_ArrayRunnable_ArraySRInterface_INone();
  data = Rte_IRead_ArrayRunnable_ArraySRInterface_Iconstraint();
  rt = Rte_Write_ArraySRInterface_acknowlegdement(data);
  rt = Rte_Invalidate_ArraySRInterface_acknowlegdement();
  Rte_IWrite_ArrayRunnable_ArraySRInterface_INone(data);
  data = Rte_IWriteRef_ArrayRunnable_ArraySRInterface_INone();
  Rte_IInvalidate_ArrayRunnable_ArraySRInterface_Iconstraint();
  rt = Rte_Feedback_ArraySRInterface_acknowlegdement();
  rt = Rte_IStatus_ArrayRunnable_ArraySRInterface_Iconstraint();
  data = Rte_Prm_ArrayCalibration_arrayElement();
#endif // RTE_PTR2ARRAY_PASSING

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BooleanRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) BooleanRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BooleanRunnable
 *********************************************************************************************************************/

  Std_ReturnType rt;
  boolean data;
  rt = Rte_Read_BooleanSR_isElement(&data);
  if(rt == RTE_E_OK)
  {
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComplexArrayRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ComplexArrayRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComplexArrayRunnable
 *********************************************************************************************************************/

  Std_ReturnType rt;
#ifdef RTE_PTR2ARRAYTYPE_PASSING
  {
    multiArrayThreeImpl arr;
    rt = Rte_Read_MultiArraySRInterface_multiArray(&arr);
    if (rt == RTE_E_OK) {
    } else {
    }
  }
  {
    multiArrayThreeImpl arr;
    rt = Rte_Read_MultiArraySRInterface_multiArrayConstraint(&arr);
    if (rt == RTE_E_OK) {
      Rte_Write_MultiArraySRInterface_multiArrayConstraint(&arr);
    } else {
    }
  }
  {
    multiArrayThreeImpl *data;
    data = Rte_IRead_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
    rt = Rte_Write_MultiArraySRInterface_multiArray(data);
    Rte_IWrite_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(data);
  }
  {
    multiArrayThreeImpl *data;
    data = Rte_IWriteRef_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
  }
  Rte_IInvalidate_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
  rt = Rte_IStatus_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
  {
    multiArrayThreeImpl *data;
    data = Rte_Prm_MultiArrayCalibration_multiArrayElement();
  }
#else
  {
    Rte_DT_IntArrayImpl_0 arr[2][3][10];
    rt = Rte_Read_MultiArraySRInterface_multiArray(&arr);
    if (rt == RTE_E_OK) {
    } else {
    }
  }
  {
    Rte_DT_IntArrayImpl_0 arr[2][3][10];
    rt = Rte_Read_MultiArraySRInterface_multiArrayConstraint(&arr);
    if (rt == RTE_E_OK) {
      Rte_Write_MultiArraySRInterface_multiArrayConstraint(&arr);
    } else {
    }
  }
  {
    Rte_DT_IntArrayImpl_0 *data;
    data = Rte_IRead_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
    rt = Rte_Write_MultiArraySRInterface_multiArray(data);
    Rte_IWrite_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit(data);
  }
  {
    Rte_DT_IntArrayImpl_0 *data;
    data = Rte_IWriteRef_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
  }
  Rte_IInvalidate_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
  rt = Rte_IStatus_ComplexArrayRunnable_MultiArraySRInterface_multiArrayConstraintImplicit();
  {
    Rte_DT_IntArrayImpl_0 *data;
    data = Rte_Prm_MultiArrayCalibration_multiArrayElement();
  }
#endif // RTE_PTR2ARRAY_PASSING

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComplexRxRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ComplexRxRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComplexRxRunnable
 *********************************************************************************************************************/

  Std_ReturnType ret;
  uint64 data;
  ret = Rte_Receive_ComplexElementRx_QueuedElement(&data);
  if (ret == RTE_E_OK)
  {
  }
  else
  {
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DReadRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) DReadRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DReadRunnable
 *********************************************************************************************************************/

  sint8 data;
  data = Rte_DRead_ReadWithErrorHandler_ReadElementOpenRange();
  uint64 data64 = Rte_DRead_SimpleNvDataPort_element_OneToTen();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DTCServiceRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DTCServiceRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) DTCServiceRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DTCServiceRunnable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataConstraintRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) DataConstraintRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataConstraintRunnable
 *********************************************************************************************************************/

  Std_ReturnType rt;
  uint8 data;
  rt = Rte_Read_DataConstraintInterface_DataProtypeConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_DataProtypeApplConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_DataProtypeImplConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_ApplicationTypeConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_ApplicationTypeImplConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_ApplicationTypeAllConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_ImplementationTypeConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_AllConstr(&data);
  if (rt == RTE_E_OK) {
  }
  rt = Rte_Read_DataConstraintInterface_NoConstr(&data);
  if (rt == RTE_E_OK) {
  }

  float32 f_data;
  rt = Rte_Read_DataConstraintInterface_InfFloatConstr(&f_data);
  if (rt == RTE_E_OK) {
  }

  data = tis_interval(1, 99);
  Rte_Write_DataConstraintInterface_DataProtypeConstr(data);
  data = tis_interval(1, 99);
  Rte_Write_DataConstraintInterface_DataProtypeApplConstr(data);
  data = tis_interval(1, 99);
  Rte_Write_DataConstraintInterface_DataProtypeImplConstr(data);
  data = tis_interval(1, 10);
  Rte_Write_DataConstraintInterface_ApplicationTypeConstr(data);
  data = tis_interval(1, 20);
  Rte_Write_DataConstraintInterface_ApplicationTypeImplConstr(data);
  data = tis_interval(1, 20);
  Rte_Write_DataConstraintInterface_ApplicationTypeAllConstr(data);
  data = tis_interval(1, 20);
  Rte_Write_DataConstraintInterface_ImplementationTypeConstr(data);
  data = tis_interval(1, 99);
  Rte_Write_DataConstraintInterface_AllConstr(data);
  data = tis_interval(0, 256);
  Rte_Write_DataConstraintInterface_NoConstr(data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DoubleRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) DoubleRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DoubleRunnable
 *********************************************************************************************************************/

#ifdef RTE_INIT_IMPLICIT_BUFFERS
  Rte_IWrite_DoubleRunnable_DoubleSRPort_implicitElem(Rte_InitValue_DoubleSRPort_implicitElem);
#endif

  customFloat64 data;
  customFloat64 data2;
  Std_ReturnType res;
  res = Rte_Read_DoubleSRPort_explicitElem(&data);
  if(res == RTE_E_OK){
    Rte_Write_DoubleSRPort_explicitElem(data);
  }
  data = Rte_IRead_DoubleRunnable_DoubleSRPort_implicitElem();
  Rte_IWrite_DoubleRunnable_DoubleSRPort_implicitElem(data);
  res = Rte_Call_DoubleCS_f(data, &data2);
  if(res == RTE_E_OK){
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ExplicitReadByValue_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ExplicitReadByValue(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ExplicitReadByValue
 *********************************************************************************************************************/

  sint16 out;
  Std_ReturnType rt;
  rt = Rte_Read_SimpleReadProto_SimpleReadElement(&out);
  if (rt == RTE_E_OK) {
  } else {
  }

  float32 out_f;
  rt = Rte_Read_SimpleReadProto_ReadElementRangeInfMax(&out_f);
  if (rt == RTE_E_OK) {
  }

  rt = Rte_Read_ReadWithErrorHandler_SimpleReadElement(&out);
  if (rt == RTE_E_OK)
  {
  }

   sint8 out_s;
   rt = Rte_Read_SimpleReadProto_ReadElementOpenRange(&out_s);
   if (rt == RTE_E_OK)
   {
   }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: FeedbackRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) FeedbackRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FeedbackRunnable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Hello_World_Runnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by ExternalTriggerOccurredEvent of PortPrototype <TriggerInterface>
 *   - triggered by ExternalTriggerOccurredEvent of PortPrototype <TriggerInterfaceError>
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
 *   Std_ReturnType Rte_Invalidate_Hello_World_port_Hello_World_Element(Std_TransformerError *transformerError)
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Hello_World_Runnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) Hello_World_Runnable(P2CONST(Std_TransformerError, AUTOMATIC, RTE_AP_HELLO_WORLD_APPL_VAR) transformerError) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Hello_World_Runnable
 *********************************************************************************************************************/
  Std_TransformerError err;
  Std_ReturnType ret = Rte_Write_Hello_World_port_Hello_World_Element(0, &err);

  ret = Rte_Send_ComplexPortTest_QueuedElement(123, &err);

  ret = Rte_Feedback_ComplexPortTest_QueuedElement();

  ret = Rte_Invalidate_Hello_World_port_Hello_World_Element(&err);

  uint8 res_u8 = Rte_Prm_CalibrationPrimitiveType_notAccessibleElement();

  res_u8 = Rte_CData_SharedInternalCalibrationParameter();

  ret = 0;
  ret = Rte_SwitchAck_Mode_Port_Interface_ModeGroup();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ImplicitReadRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ImplicitReadRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ImplicitReadRunnable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
 * Status Interfaces:
 * ==================
 *   Tx Status:
 *   ----------
 *   Std_ReturnType Rte_IFeedback_ImpliciteWrite_ComplexPortTest_ComplexElement(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ImpliciteWrite_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ImpliciteWrite(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ImpliciteWrite
 *********************************************************************************************************************/

  Rte_IWrite_ImpliciteWrite_ComplexPortTest_ComplexElement(0);
  Rte_IWrite_ImpliciteWrite_ComplexPortTest_ConstrainedElement(0);
  Rte_IWrite_ImpliciteWrite_ComplexPortTest_HandleInvalidElement(0);
  Rte_IWrite_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange(0);
  Rte_IWrite_ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax(0);
  Rte_IWrite_ImpliciteWrite_SimpleWritePort_SimpleReadElement(0);
  Rte_IWrite_ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived(0);
  NvM_RequestResultType *complex_element =
    Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_ComplexElement();
  uint64 *constrained_element =
    Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_ConstrainedElement();
  uint64 *handle_invalid_element =
    Rte_IWriteRef_ImpliciteWrite_ComplexPortTest_HandleInvalidElement();
  sint8 *read_element_open_range =
    Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange();
  float32 *read_element_range_inf_max =
    Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_ReadElementRangeInfMax();
  sint16 *simple_read_element =
    Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_SimpleReadElement();
  uint64 *simple_read_never_received =
    Rte_IWriteRef_ImpliciteWrite_SimpleWritePort_SimpleReadNeverReceived();
  Rte_IInvalidate_ImpliciteWrite_SimpleWritePort_ReadElementOpenRange();
  Std_ReturnType feedback =
    Rte_IFeedback_ImpliciteWrite_ComplexPortTest_ComplexElement();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
 *   ComplexStructImpl *Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableStruct(void)
 *   customUInt8 Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableValue(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableStruct(const ComplexStructImpl *data)
 *   void Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableValue(customUInt8 data)
 *
 *   Implicit Write Access:
 *   ----------------------
 *   void Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableStruct(const ComplexStructImpl *data)
 *   ComplexStructImpl *Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableStruct(void)
 *
 *   void Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableValue(customUInt8 data)
 *   customUInt8 *Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableValue(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: InterVariableRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) InterVariableRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: InterVariableRunnable
 *********************************************************************************************************************/

  {
    uint8 res_uint8 = Rte_IrvRead_InterVariableRunnable_ExplicitInterRunnableValue();
    Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableValue(res_uint8);
  }
  {
    uint8 res_uint8 = Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableValue();
    Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableValue(res_uint8);
    uint8 *write_uint8 = Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableValue();
  }

  {
    ComplexStructImpl res_struct;
    Rte_IrvRead_InterVariableRunnable_ExplicitInterRunnableStruct(&res_struct);
    Rte_IrvWrite_InterVariableRunnable_ExplicitInterRunnableStruct(&res_struct);
  }
  {
    ComplexStructImpl res_struct;
    res_struct = *Rte_IrvIRead_InterVariableRunnable_ImplicitInterRunnableStruct();
    Rte_IrvIWrite_InterVariableRunnable_ImplicitInterRunnableStruct(&res_struct);
    ComplexStructImpl *write_struct = Rte_IrvIWriteRef_InterVariableRunnable_ImplicitInterRunnableStruct();
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IsUpdatedRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) IsUpdatedRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IsUpdatedRunnable
 *********************************************************************************************************************/

  boolean is_updated = Rte_IsUpdated_IsUpdatedByValuePrototype_IdUpdatedByValueElement();

  is_updated = Rte_IsUpdated_IsUpdatedByValuePrototype_IsUpdatedByArgumentElement();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
 *   uint8 Rte_Mode_EnhancedPortInterface_Mode(uint8 *previousMode, uint8 *nextMode)
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ModeRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ModeRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ModeRunnable
 *********************************************************************************************************************/

  uint8 res;
  res = Rte_Mode_Mode_Port_Interface_ModeGroup();
  uint8 prevMode;
  uint8 nextMode;
  res = Rte_Mode_EnhancedPortInterface_Mode(&prevMode, &nextMode);
  // Previous and next mode can't be the transition mode.

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MultipleInstanciationRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) MultipleInstanciationRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MultipleInstanciationRunnable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReceiveRecordRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ReceiveRecordRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ReceiveRecordRunnable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) ServiceRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ServiceRunnable
 *********************************************************************************************************************/
  sint16 i;
  ComplexStructImpl cs;
  Rte_DT_FloatArrayImplementation_0 float_array;
  Std_ReturnType rt = Rte_Call_CallPortInterface_InOutOperation(i, &cs, &float_array);
  // Test the return values of the asynchronous type.

  customDouble32 d;
  rt = Rte_Call_CallPortInterface_SimpleIntOperation(i, &d);

  // in these cases, the output variable should not be touched.
  if (rt == RTE_E_LIMIT || rt == RTE_E_TIMEOUT) {
  } else {
  }

  NvM_RequestResultType nvm_result;
  rt = Rte_Result_NvSWC_NvMService_client_GetErrorStatus(&nvm_result);

  Std_TransformerError te;
  rt = Rte_Result_NvSWC_NvMService_AC2_SRBS_Defs_client_WriteBlock(&te);
  if (rt == RTE_E_HARD_TRANSFORMER_ERROR || RTE_E_SOFT_TRANSFORMER_ERROR) {
  }

  NvM_RequestResultType nvm_result2;
  rt = Rte_Result_NvMService_service_client_GetErrorStatus(&nvm_result2);
  if (rt == RTE_E_NO_DATA || rt == RTE_E_TIMEOUT || rt == RTE_E_COM_STOPPED)
  {
  }
  else
  {
  }

  rt = Rte_Result_NvSWC_NvMService_AC2_SRBS_Defs_client_SetRamBlockStatus(&te);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StructRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) StructRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StructRunnable
 *********************************************************************************************************************/

  Std_ReturnType rt;
  {
    ComplexStructImpl data;
    rt = Rte_Read_StructSRInterface_Element(&data);
    if (rt == RTE_E_OK) {
            data.structElement.boolElement == 0 ||
            data.structElement.boolElement == 1;
      Rte_Write_StructSRInterface_Element(&data);
    } else {
    }
  }
  {
    ComplexStructImpl *data;
    data = Rte_IRead_StructRunnable_StructSRInterface_IElement();
            data->structElement.boolElement == 0 ||
            data->structElement.boolElement == 1;
    rt = Rte_Write_StructSRInterface_Element(data);
    Rte_IWrite_StructRunnable_StructSRInterface_IElement(data);
  }
  {
    ComplexStructImpl *data;
    data = Rte_IWriteRef_StructRunnable_StructSRInterface_IElement();
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TriggerRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) TriggerRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TriggerRunnable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: UnionRunnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AP_Hello_World_CODE) UnionRunnable(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: UnionRunnable
 *********************************************************************************************************************/

#ifdef RTE_INIT_IMPLICIT_BUFFERS
  Rte_IWrite_UnionRunnable_UnionSRInterface_implicitElem(&);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AP_Hello_World_STOP_SEC_CODE
#include "AP_Hello_World_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: runnable implementation:ServerCallRunnable)  *****************************/
  float32 out;
  Std_ReturnType ret = Rte_Call_CallPortInterface_SimpleIntOperation(32, &out);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:ServerCallRunnable_doc)  ******************************/


/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
