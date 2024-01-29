/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*
*                This software is copyright protected and proprietary to Vector Informatik GmbH.
*                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
*                All other rights remain with Vector Informatik GmbH.
*  -------------------------------------------------------------------------------------------------------------------
*********************************************************************************************************************/

#pragma once

#include <chrono>

#include "TypeSystem.h"

class ArgRefView;

/** Describes an AUTOSAR port interface */
class IPortInterface
{
public:
  virtual ~IPortInterface() = default;

  /** Bit field for defining interface characteristics */
  enum InterfaceFlags : bitfield32
  {
    None = 0,

    /** Service interface? Can be combined with all other flags. */
    IsService = 0x1,

    /** Sender/receiver interface. Cannot be combined with other flags (despite IsService). */
    IsSenderReceiver = 0x2,

    /** Client/server interface. Cannot be combined with other flags (despite IsService). */
    IsClientServer = 0x4,

    /** Mode switch interface. Cannot be combined with other flags (despite IsService). */
    IsMode = 0x8,

    /** Nv data interface. Cannot be combined with other flags (despite IsService). */
    IsNvData = 0x10,

    /** Parameter interface. Cannot be combined with other flags (despite IsService). */
    IsParameter = 0x20,

    /** Trigger interface. Cannot be combined with other flags (despite IsService). */
    IsTrigger = 0x30
  };

  /** @return the AUTOSAR short-name of the described interface */
  virtual const char* GetName() const = 0;

  /** @return the interface characteristics flags */
  virtual InterfaceFlags GetFlags() const = 0;

  /** @return the number of data elements, if this is any interface other than client/server.
    * (otherwise 0). */
  virtual size_t GetNumDataElements() const = 0;

  /** @return the number of operations, if this is a client/server interface.
  * (otherwise 0). */
  virtual size_t GetNumOperations() const = 0;

  /** @return the data element at 0 <= index < GetNumDataElements(). */
  virtual const IDataElement* GetDataElement(unsigned int index) const = 0;

  /** @return the operation at 0 <= index < GetNumOperations(). */
  virtual const IOperation* GetOperation(unsigned int index) const = 0;

  /** @return the initial and transitional mode value */
  virtual void GetModeInfo(unsigned int index, MaxModeType* initialValue, MaxModeType* transitValue) const = 0;

  /** @return whether the data element in question is configured for queued communication */
  virtual bool UsesQueuedCommunication(unsigned int index) const = 0;
};


/** Describes an AUTOSAR port instance.
 *  Note that a port instance is more special than a port prototype:
 *  If a port prototype belongs to an SWC prototype which is instantiated
 *  multiple times, we'll get a dedicated port instance for each prototype.
 */
class IPortInstance
{
public:
  virtual ~IPortInstance() = default;

  /** Bit field */
  enum PortFlags : bitfield32
  {
    Undefined = 0x0,

    /** Provided port prototype */
    IsProvided = 0x1,

    /** Required port prototype */
    IsRequired = 0x2,

    /** Provided and required port prototype */
    IsProvidedAndRequired = 0x3
  };

  /** @return unique name describing this instance. 
    * The name may be composed of the SWC hierarchy names plus prototype name. */
  virtual const char* GetName() const = 0;

  /** @return the characteristics of this instance */
  virtual PortFlags GetFlags() const = 0;

  /** @return port interface description. If signal degradation occurs, this is this port instance's degraded interface */
  virtual IPortInterface* GetInterface() const = 0;

  /** @return the set of ports this port is connected with */
  virtual unsigned int GetIncidentPortSet() const = 0;

  virtual unsigned int GetQueueLength(unsigned int index) const = 0;

  virtual const unsigned int* GetPortDefinedArguments() const = 0;

  virtual void* GetInitValue(unsigned int index) const = 0;
  
  virtual void* GetInvalidValue(unsigned int index) const = 0;
  
  virtual unsigned int GetDataElementInvalidationPolicy(unsigned int index) const = 0;

  virtual unsigned int GetDataElementFlags(unsigned int index) const = 0;

  virtual std::chrono::microseconds GetDataElementAliveTimeout(unsigned int index) const = 0;

  virtual unsigned int GetMemberIndex(unsigned int index) const = 0;
};

/** Describes how a port set instance will be created */
class IObjectType
{
public:
  enum class EObjectType
  {
    InternalCommunication,
    SystemVariable,
    CommunicationObject,
    DistributedObject
  };
};

/** Describes an AUTOSAR inter-runnable variable instance. */
class IInterRunnableVariable
{
public:
  virtual ~IInterRunnableVariable() = default;

  /** @return unique name describing this instance.
  * Might be a composed name. */
  virtual const char* GetName() = 0;

  /*bind memory*/
  virtual void Bind() = 0;

  /** @return the variable type. */
  virtual const IType* GetType() const = 0;
 
  /** @return pointer to irv data */
  virtual void* GetData() = 0;
  
  /** @return pointer init value*/
  virtual void* GetInitValue() = 0;

};

/** Describes an access to an inter-runnable variable instance. */
class IInterRunnableVariableAccess
{
public:
  virtual ~IInterRunnableVariableAccess() = default;

  /** Bit field describing how the variable is accessed. */
  enum AccessFlags : bitfield32
  {
    /** Read access */
    NoAccess = 0x0,

    /** Read access */
    Read = 0x1,

    /** Write access */
    Write = 0x2,

    /** ReadWrite access */
    ReadWrite = 0x3
  };

  /** @return identifying index of the accessed variable with respect to the
  * IApplicationModel ordering. */
  virtual unsigned int GetAccessedVariable() = 0;

  /** @return kind of access. */
  virtual AccessFlags GetAccessFlags() = 0;
};

/** Describes an AUTOSAR runnable instance. */
class IRunnableDescriptor
{
public:
  virtual ~IRunnableDescriptor() = default;

  /** @return unique name describing this instance.
    * Might be composed. */
  virtual const char* GetName() = 0;

  /** @return operational signature of this runnable instance. */
  virtual IOperation* GetSignature() = 0;

  /** @return value of AUTOSAR canBeInvokedConcurrently attribute.
    * E.g. refer to AUTOSAR_SWS_RTE r4.2.1, section 4.2.6 */
  virtual bool CanBeInvokedConcurrently() = 0;

  /** @return value of AUTOSAR minimumStartInterval attribute in [us].
    * E.g. refer to AUTOSAR_SWS_RTE r4.2.1, section 4.2.3 
    * MinimumStartInterval > 0 implies that CanBeInvokedConcurrently == false [SWS_Rte_02733] */
  virtual unsigned int GetMinimumStartInterval() = 0;

  /** @return the number of accessed inter-runnable variables */
  virtual size_t GetNumAccessedInterRunnableVariables() = 0;

  /** @return information on the accessed inter-runnable variables at 
    * 0 <= index < GetNumAccessedInterRunnableVariables() */
  virtual IInterRunnableVariableAccess* GetInterRunnableVariableAccess(unsigned int index) = 0;

  /** @return the estimated computation time [µs] of this runnable on the (hypothetical) real target. 
    * The framework will impress the specified runtime at the end of each runnable execution.
    * It is up to the user to make more fine-grained time annotations inside the runnable's body.
    * 0 is allowed and valid. */
  virtual unsigned int GetComputationTime() = 0;

  /** pre-execution phase: allows the runnable to gather data for implicit RTE operations in a non-interruptible 
    * context. */
  virtual void PreExecute() = 0;

  /** Executes the runnable */
  virtual void Execute(unsigned int activationReason, IPortInstance* triggeringPort, const ArgRefView& argRefs) = 0;

  /** post-execution phase: allows the runnable to dispatch data from implicit RTE operations in a non-interruptible
    * context. */
  virtual void PostExecute() = 0;
};

/** Describes the activation of a runnable due to a trigger event. */
class ITriggeredRunnable
{
public:
  virtual ~ITriggeredRunnable() = default;

  /** @return unique runnable index with respect to the application model. */
  virtual unsigned int GetRunnableIndex() = 0;

  /** @return returns 32bit mask with reasons for activation, or 0 if there is none */
  virtual unsigned int GetActivationBit() = 0;
};

/** Describes a mode disabling */
class IModeDisabling
{
public:
  virtual ~IModeDisabling() = default;

  /** @return the mode port which this disabling refers to */
  virtual unsigned int GetPort() const = 0;

  /** @return the mode which this disabling refers to */
  virtual MaxModeType GetMode() const = 0;
};

/** Describes a runnable trigger instance. */
class IRunnableTrigger
{
public:
  virtual ~IRunnableTrigger() = default;

  /** Kind of trigger */
  enum TriggerKind
  {
    /** Initialization trigger */
    InitTrigger = 1,

    /** RunnableTrigger due to queued or non-queued data reception. */
    DataReceptionTrigger = 2,

    /** RunnableTrigger due to data reception error. */
    DataReceptionErrorTrigger = 3,

    /** Periodical trigger. */
    CyclicTrigger = 4,

    /** RunnableTrigger due to async function call. */
    AsyncFunctionCallTrigger = 5,

    /** RunnableTrigger due to sync function call. */
    SyncFunctionCallTrigger = 6,

    /** RunnableTrigger due to async function call return. */
    FunctionCallReturnTrigger = 7,

    /** RunnableTrigger due to data send completed event. */
    DataSendCompletedTrigger = 8,

    /** RunnableTrigger due to data write completed event. */
    DataWriteCompletedTrigger = 9,

    /** RunnableTrigger due to background event. */
    BackgroundTrigger = 10,

    /** RunnableTrigger due to mode exit event on a mode switch provided port. */
    ModeExitTrigger = 11,

    /** RunnableTrigger due to mode transition event on a mode switch provided port. */
    ModeTransitionTrigger = 12,

    /** RunnableTrigger due to mode entry event on a mode provided port. */
    ModeEntryTrigger = 13,

    /** RunnableTrigger due to mode entry event on a mode switch required port. */
    ModeSwitchAckTrigger = 14,

    /** Explicit internal runnable triggering. */
    InternalTrigger = 15,

    /** Explicit external runnable triggering. */
    ExternalTrigger = 16
  };

  /** @return the kind of trigger */
  virtual TriggerKind GetKind() = 0;

  /** @return trigger cycle time [us] (if applicable) */
  virtual unsigned int GetCycleTime() = 0;

  /** @return trigger time offset [us] (if applicable) */
  virtual unsigned int GetTimeOffset() = 0;

  /** @return triggering port instance (if applicable) */
  virtual unsigned int GetTriggerPort() = 0;

  /** @return triggering port element (if applicable) */
  virtual unsigned int GetTriggerElementOfPort() = 0;

  /** @return number of triggered runnables */
  virtual size_t GetNumTriggeredRunnables() = 0;

  /** @return information on triggered runnable instance 0 <= n < GetNumTriggeredRunnables() */
  virtual ITriggeredRunnable* GetTriggeredRunnable(unsigned int n) = 0;

  virtual size_t GetNumModeDisablings() = 0;

  virtual IModeDisabling* GetModeDisabling(unsigned int index) = 0;

  virtual void GetModeInfo(MaxModeType* oldMode, MaxModeType* newMode) = 0;  
};

/** Describes a net of interconnected port instances. */
class IConnectedPortSet
{
public:
  virtual ~IConnectedPortSet() = default;

  /** @return unique name identifying this net. */
  virtual const char* GetName() = 0;

  /** @return port interface description. If signal degradation occurs, this is the undegraded interface if available. */
  virtual IPortInterface* GetInterface() = 0;

  /** @return ObjectType of ConnectedPortSet  */
  virtual IObjectType::EObjectType GetObjectType() = 0;

  /** @return number of connected port instances */
  virtual size_t GetNumIncidentPorts() = 0;

  /** Fills the supplied buffer with the indices (with respect to the IApplicationModel
    * ordering) of interconnected ports. The buffer must provide space for GetNumIncidentPorts() elements. */
  virtual void GetIncidentPorts(unsigned int* pIndexBuffer) = 0;

  /** @return n-th connected port instance where n = 0..GetNumIncidentPorts() - 1. */
  virtual unsigned int GetIncidentPort(unsigned int index) = 0;

  virtual unsigned int GetQueueLength(unsigned int index) = 0;
};

/** Describes a calibration parameter instance. */
class ICalibrationParameter
{
public:
  virtual ~ICalibrationParameter() = default;

  enum AccessMode
  {
    ReadOnly,
    NotAccessible,
    ReadWrite
  };

  /* allocate memory of right size*/
  virtual void Bind() = 0;

  /** @return name of the swc. */
  virtual const char* GetSwcName()  const = 0;

  /** @return unique name identifying this calibration parameter. */
  virtual const char* GetName()  const = 0;

  /* @return type needs to be defined correctly */
  virtual IType* GetType() const = 0;
  
  virtual void* GetInitValue() = 0;

  /*@return The defined read/write access mode*/
  virtual AccessMode GetAccessMode() const = 0;
};

class IPerInstanceMemory; 

/** Describes a NvM Block Need */
class INvMBlock
{
public:
  virtual ~INvMBlock() = default;

  /** Enum for defining interface characteristics */
  enum BlockStatusControl
  {
    NvRAMManager,
    API
  };

  enum BooleanFlag
  {
    False,
    True,
    NotSet
  };


  /** @return unique name identifying this BlockNeed. */
  virtual const char* GetName() const = 0;

  /** @return unique name of Service Need. */
  virtual const char* GetServiceNeedName() const = 0;

  /** @return who controls the NvM Block */
  virtual BlockStatusControl GetBlockStatusControl() const = 0;

  virtual BooleanFlag IsReadOnly() const = 0;

  virtual BooleanFlag RestoreAtStartup() const = 0;

  virtual BooleanFlag StoreAtShutdown() const = 0;

  virtual BooleanFlag WriteOnlyOnce() const = 0;

  virtual BooleanFlag StoreEmergency() const = 0;

  virtual BooleanFlag StoreImmediate() const = 0;

  /** @return trigger cycle time [us] (if applicable) */
  virtual double GetCycleTime() const = 0;

  /** @return connected PIM if existent */
  virtual IPerInstanceMemory* GetConnectedPIM() const = 0;

  virtual ICalibrationParameter* GetDefaultValue() const = 0;

  /** @return Assigned port instance including role assignment */
  virtual IPortInstance* GetAssignedPort(unsigned int index) const = 0;

  virtual size_t GetNumAssignedPorts() const = 0;
};

/** Describes a PerInstanceMemory */
class IPerInstanceMemory
{
public:
  virtual ~IPerInstanceMemory() = default;

  /** @return unique name identifying this PIM. */
  virtual const char* GetName() const = 0;

  //* @return ASR4 datatype */
  virtual IType* GetType() const = 0;

  virtual void SetConnectedNvMBlock(INvMBlock* nvMBlock) = 0;

  virtual INvMBlock* GetConnectedNvMBlock()const = 0;

  virtual void* GetMemory() const = 0;

  virtual const void* GetInitValue() const = 0;
};

/** Describes the overall SUT. 
  * An instance of this interface provides the entry point to the interaction model. */
class IApplicationModel
{
public:
  virtual ~IApplicationModel() = default;

  /** @return the SUT name. */
  virtual const char* GetName() = 0;

  /** @return the overall number of runnable instances. */
  virtual size_t GetNumRunnables() = 0;

  /** @return the overall number of port instances. */
  virtual size_t GetNumPorts() = 0;

  /** @return the overall number of inter-runnable instances. */
  virtual size_t GetNumInterRunnableVariables() = 0;

  /** @return the overall number of runnable trigger instances */
  virtual size_t GetNumRunnableTriggers() = 0;

  /** @return the overall number of port connection nets */
  virtual size_t GetNumConnectedPortSets() = 0;

  virtual size_t GetNumModeDisablings() = 0;
  
  /** @return the overall number of shared calibration parameters*/
  virtual size_t GetNumSharedCalibrationParams() = 0;

  /** @return the overall number of calibration parameters per SWC instance*/
  virtual size_t GetNumPerInstanceCalibrationParams() = 0;

  /** @return the overall number of per instance memories*/
  virtual size_t GetNumPIMs() = 0;

  /** @return the overall number of non volatile memory blocks*/
  virtual size_t GetNumNvMBlocks() = 0;

  /** @return the runnable instance at 0 <= index < GetNumRunnables() */
  virtual IRunnableDescriptor* GetRunnable(unsigned int index) = 0;

  /** @return the port instance at 0 <= index < GetNumPorts() */
  virtual IPortInstance* GetPort(unsigned int index) = 0;

  /** @return the inter-runnable variable instance at 0 <= index < GetNumInterRunnableVariables() */
  virtual IInterRunnableVariable* GetInterRunnableVariable(unsigned int index) = 0;

  /** @return the runnable trigger instance at 0 <= index < GetNumRunnableTriggers() */
  virtual IRunnableTrigger* GetRunnableTrigger(unsigned int index) = 0;

  /** @return the port connection network at 0 <= index < GetNumConnectedPortSets() */
  virtual IConnectedPortSet* GetConnectedPortSet(unsigned int index) = 0;

  /** @return the per instance parameter at 0 <= index < GetNumPerInstanceCalibrationParams() */
  virtual ICalibrationParameter* GetPerInstanceCalibrationParam(unsigned int index) = 0;

  /** @return the shared calibration parameter at 0 <= index < GetNumSharedCalibrationParams() */
  virtual ICalibrationParameter* GetSharedCalibrationParam(unsigned int index) = 0;

  /** @return the per instance memory at 0 <= index < GetNumPIMs() */
  virtual IPerInstanceMemory* GetPerInstanceMemory(unsigned int index) = 0;

  /** @return the NvM Block instance at 0 <= index < GetNumNvMBlocks() */
  virtual INvMBlock* GetNvMBlock(unsigned int index) = 0;
};
