/*-----------------------------------------------------------------------------
Module: vVIRTUALtarget Pro Runtime
Interfaces: -
-------------------------------------------------------------------------------
Implements AUTOSAR-compliant communication (signals, services, modes, ...).
Used by the auto-generated RTE model.
-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/
#pragma once

#include "TypeSystem.h"
#include "ArgRefView.h"

#include <time.h>
#include <stdint.h>

// Forward declarations

namespace VttProTestFramework { class ApplicationModel; }

// General types

typedef unsigned int RunnableHandle;
typedef unsigned int PortHandle;
typedef unsigned int OperationIndex;
typedef unsigned int ElementIndex;
typedef unsigned int XaHandle;
typedef unsigned int IrvHandle;
typedef unsigned int VfbVersion;
typedef unsigned int InvalidationPolicy;
typedef time_t VfbTime;

enum VfbResult : uint8_t;
struct VfbTransformerError;

// Interface declarations

class IInteractionModel
{
public:
  virtual ~IInteractionModel() = default;

  virtual VfbVersion GetVersion() = 0;

  // Make an asynchronous operation call, i.e., return immediately.
  virtual VfbResult CallOperation(PortHandle handle, OperationIndex operationIndex, unsigned int timeoutInUs, const ArgRefView& argRefs) = 0;
  // Poll or await the result of an asynchronous operation call.
  virtual VfbResult GetCallResult(PortHandle handle, OperationIndex operationIndex, bool blocking, const ArgRefView& argRefs) = 0;
  // Make a synchronous operation call.
  virtual VfbResult CallOperationSynchronously(PortHandle handle, OperationIndex operationIndex, const ArgRefView& argRefs) = 0;

  // Explicitly read the value of a signal port.
  virtual VfbResult ReadData(PortHandle handle, ElementIndex elementIndex, void* data, VfbTransformerError* transformerError = nullptr) = 0;
  // Explicitly update the value of a signal port.
  virtual VfbResult WriteData(PortHandle handle, ElementIndex elementIndex, const void* data, VfbTransformerError* transformerError = nullptr) = 0;
  // Find out if data has been updated since last read
  virtual bool IsDataUpdated(PortHandle handle, ElementIndex elementIndex) = 0;
  virtual bool IsDataOutdated(PortHandle handle, ElementIndex elementIndex) = 0;
  virtual VfbResult GetFeedback(PortHandle handle, ElementIndex elementIndex, unsigned int timeout) = 0;
  virtual VfbResult InvalidateData(PortHandle handle, ElementIndex elementIndex, VfbTransformerError* transformerError = nullptr) = 0;

  virtual VfbResult ReceiveData(PortHandle handle, ElementIndex elementIndex, void* data, bool blocking, unsigned int timeout) = 0;
  virtual VfbResult SendData(PortHandle handle, ElementIndex elementIndex, const void* data) = 0;

  virtual VfbResult SendModeSwitch(PortHandle handle, ElementIndex elementIndex, MaxModeType mode) = 0;
  virtual VfbResult GetModeSwitchAck(PortHandle handle, ElementIndex elementIndex, bool blocking, unsigned int timeout) = 0;
  virtual MaxModeType GetMode(PortHandle handle, ElementIndex element, MaxModeType* prevMode, MaxModeType* curMode) = 0;

  virtual void EnterExclusiveArea(XaHandle handle, const char* eaName) = 0;
  virtual void ExitExclusiveArea(XaHandle handle, const char* eaName) = 0;

  virtual void Trigger(PortHandle handle, ElementIndex elementIndex, VfbTransformerError* transformerError = nullptr) = 0;

  virtual VfbResult ReadIrv(IrvHandle handle, void* data) = 0;
  virtual VfbResult WriteIrv(IrvHandle handle, const void* data) = 0;

  virtual VfbResult ReadCalibParam(char* swcName, char* paramName, void* data) = 0;
  
  // CANoeAPI: Consume time in microseconds
  virtual void ConsumeTime(unsigned int timeInUs) = 0;
  // CANoeAPI: Consume time in quantum ticks (default is 100ns per tick)
  virtual void ConsumeTicks(VfbTime numQuanta) = 0;
  // CANoeAPI: Current clock time in nanoseconds
  virtual VfbTime Now() = 0;
  

private:
  friend class VttProTestFramework::ApplicationModel;

  // API intended for internal use only.
  virtual void* GetTestHelpersAccess() = 0;
};

enum HandleInvalid : uint8_t 
{
  DontInvalidate = 0,
  Keep = 1,
  Replace = 2,
  ExternalReplacement = 3 // not supported yet
};

enum DataElementFlags : uint8_t
{
  None = 0x0,
  HandleNeverReceived = 0x1,
  AliveTimeout = 0x2
  // To be extended for use cases: enable update, alive timeout, e2e, out-of-range handling
};

// Common RTE-compliant error codes
enum VfbResult : uint8_t
{
  /** No error occurred. */
  RTE_E_OK = 0,

  /** Generic application error indicated by signal invalidation in sender receiver
  * communication with data semantics on the receiver side. */
  RTE_E_INVALID = 1,

  /* An IPDU group was disabled while the application was waiting for the transmission acknowledgment.
  * No value is available. This is not considered a fault, since
  * the IPDU group is switched off on purpose. */
  RTE_E_COM_STOPPED = 128,

  /** A blocking API call returned due to expiry of a local timeout rather than the in-
  * tended result. OUT buffers are not modified. The interpretation of this being an
  * error depends on the application. */
  RTE_E_TIMEOUT = 129,

  /** A internal RTE limit has been exceeded. Request could not be handled.
  * OUT buffers are not modified. */
  RTE_E_LIMIT = 130,

  /** An explicit read API call returned no data. (This is no error.) */
  RTE_E_NO_DATA = 131,

  /** Transmission acknowledgment received. */
  RTE_E_TRANSMIT_ACK = 132,

  /** No data received for the corresponding unqueued data element since system
  * start or partition restart. */
  RTE_E_NEVER_RECEIVED = 133,

  /** The port used for communication is not connected. */
  RTE_E_UNCONNECTED = 134,

  /** The error is returned by a blocking API and indicates that the runnable
  * could not enter a wait state, because one ExecutableEntity of the current
  * task's call stack has entered an ExclusiveArea. */
  RTE_E_IN_EXCLUSIVE_AREA = 135,

  /** The error can be returned by an RTE API, if the parameters contain a direct or
  * indirect reference to memory that is not accessible from the callers partition. */
  RTE_E_SEG_FAULT = 136,

  /** The received data is out of range. */
  RTE_E_OUT_OF_RANGE = 137,

  /** An error during transformation occurred. */
  RTE_E_SERIALIZATION_ERROR = 138,
  RTE_E_HARD_TRANSFORMER_ERROR = 138,

  /** Buffer for transformation operation could not be created. */
  RTE_E_SERIALIZATION_LIMIT = 139,
  RTE_E_TRANSFORMER_LIMIT = 139,

  /** An error during transformation occurred which shall be notified to the SWC but
  * still produces valid data as output (comparable to a warning). */
  RTE_E_SOFT_TRANSFORMER_ERROR = 140,

  /** The transmission/reception could not be performed due to another 
  *   transmission/reception currently ongoing for the same signal. */
  RTE_E_COM_BUSY = 141,

  /** An API call for reading received data with event semantics indicates that some
  * incoming data has been lost due to an overflow of the receive queue or due to
  * an error of the underlying communication stack. */
  RTE_E_LOST_DATA = 64,

  /** An API call for reading received data with data semantics indicates that
  * the available data has exceeded the aliveTimeout limit. A COM signal out-
  * dated callback will result in this error. */
  RTE_E_MAX_AGE_EXCEEDED = 64
};

// RTE-compliant transformer types (see AUTOSAR_SWS_RTE.pdf, §5.5.3)
enum VfbTransformerClass : uint8_t
{
  /** Transformer of an unspecified transformer class. */
  RTE_TRANSFORMER_UNSPECIFIED = 0,

  /** Transformer of a serializer class. */
  RTE_TRANSFORMER_SERIALIZER = 1,

  /** Transformer of a safety class. */
  RTE_TRANSFORMER_SAFETY = 2,

  /** Transformer of a security class. */
  RTE_TRANSFORMER_SECURITY = 3,

  /** Transformer of a custom class not standardized by AUTOSAR. */
  RTE_TRANSFORMER_CUSTOM = 255,
};
// Selection of transformer specific error codes (see AUTOSAR_ASWS_TransformerGeneral.pdf for more)
enum VfbTransformerErrorCode : uint8_t
{
  /** No error occured (custom transformer). 
   * Serialization was successful (Serializer transformer). 
   * The communication is safe/secure (Safety/Security transformer). */
  RTE_TRANSFORMER_E_OK = RTE_E_OK,

  /** A generic not precisely detailed error occured. */
  RTE_TRANSFORMER_E_SER_GENERIC_ERROR = 0x81,

  /** Safety transformers: A runtime error occured, safety properties could 
   * not be checked and no output data could be produced. */
  RTE_TRANSFORMER_E_SAFETY_HARD_RUNTIMEERROR = 0xff,

  /** Security transformers: The data was not authenticated correctly. */
  RTE_TRANSFORMER_E_SEC_NOT_AUTH = 0x01,

  /** Custom transformers: A transformer specific soft error occured. */
  RTE_TRANSFORMER_E_CUSTOM_SOFTERROR1 = 0x01,
};
struct VfbTransformerError
{
  VfbTransformerErrorCode errorCode;
  VfbTransformerClass transformerClass;
};
