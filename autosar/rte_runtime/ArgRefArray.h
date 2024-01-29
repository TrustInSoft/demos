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

#include <array>
#include <cassert>
#include <algorithm>

#include "ArgRefView.h"

template<size_t N>
class ArgRefArray
{
public:
  // ----------------------------------------
  // Public Data Types

public:
  // ----------------------------------------
  // Constructors and Destructor
  ArgRefArray(const std::initializer_list<const void*>& argRefs);
  ArgRefArray() = default;
  ArgRefArray(const ArgRefArray&) = delete;
  inline ArgRefArray(ArgRefArray&&) = delete;

public:
  // ----------------------------------------
  // Operator Implementations
  ArgRefArray& operator=(ArgRefArray& other) = delete;
  ArgRefArray& operator=(ArgRefArray&& other) = delete;

public:
  // ----------------------------------------
  // Public Methods
  ArgRefView GetArgRefView();
  operator ArgRefView();

private:
  // ----------------------------------------
  // private methods

private:
  // ----------------------------------------
  // private members
  std::array<void*, N> m_refs;
  char                 m_result = '0';
};


// ================================================================================
//  Inline Implementations
// ================================================================================
template<size_t N>
ArgRefArray<N>::ArgRefArray(const std::initializer_list<const void*>& argRefs)
{
  assert(N == argRefs.size());
  auto& nonConstRefs = reinterpret_cast<const std::initializer_list<void*>&>(argRefs);
  std::copy_n(nonConstRefs.begin(), N, m_refs.begin());
}


template<size_t N>
ArgRefView ArgRefArray<N>::GetArgRefView()
{
  return ArgRefView(m_refs, &m_result);
}

template<size_t N>
ArgRefArray<N>::operator ArgRefView()
{
  return ArgRefView(m_refs, &m_result);
}