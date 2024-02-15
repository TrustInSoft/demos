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

#include <cstdint>
#include <cstddef>

class IDataElement;
class IStructMember;

typedef std::uint32_t bitfield32;
typedef std::uint64_t MaxModeType;

class ISymbolicValue
{
public:
  virtual ~ISymbolicValue() = default;
  virtual long long GetRawValue() = 0;
  virtual const char* GetSymbolicValue() = 0;
};

class IType
{
public:
  enum TypeKind : bitfield32
  {
    PrimitiveType = 0x1,
    StructType = 0x2,
    ArrayType = 0x4
  };

  enum PrimitiveKind
  {
    Undefined = 0,
    Bool,
    SInt8,
    UInt8,
    SInt16,
    UInt16,
    SInt32,
    UInt32,
    SInt64,
    UInt64,
    Float32,
    Float64,
    String
  };

  virtual ~IType() = default;
  virtual const char* GetName() const = 0;
  virtual TypeKind GetKind() const = 0;
  virtual PrimitiveKind GetPrimitiveType() const = 0;
  virtual size_t GetSize() const = 0;
  virtual void GetArrayBounds(unsigned int& minElements, unsigned int& maxElements) const = 0;
  virtual const IType* GetElementType() const = 0;
  virtual size_t GetNumDataElements() const = 0;
  virtual const IStructMember* GetDataElement(size_t index) const = 0;
  virtual size_t GetNumSymbolicValues() const = 0;
  virtual const ISymbolicValue* GetSymbolicValue(unsigned int n) const = 0;
  virtual bool IsDegraded() const = 0;
  virtual size_t GetUpgradedMemberIndex(size_t n) const = 0;
};

class IDataElement
{
public:
  virtual ~IDataElement() = default;
  virtual const char* GetName() const = 0;
  virtual const IType* GetType() const = 0;
};

class IOperationArgument : public IDataElement
{
public:
  enum Direction : bitfield32
  {
    In = 0x1,
    Out = 0x2,
    InOut = In | Out,
  };

  virtual ~IOperationArgument() = default;
  virtual Direction GetDirection() const = 0;
};

class IStructMember : public IDataElement
{
public:
  virtual ~IStructMember() = default;
  virtual size_t GetOffset() const = 0;
};

class IOperation
{
public:
  virtual ~IOperation() = default;
  virtual const char* GetName() const = 0;
  virtual bool HasReturn() const = 0;
  virtual size_t GetNumArgs() const = 0;
  virtual const IOperationArgument* GetArg(size_t index) const = 0;
};
