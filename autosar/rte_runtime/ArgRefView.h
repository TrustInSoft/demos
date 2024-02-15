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
#include <vector>
#include <cassert>

template<size_t N>
class ArgRefArray;
class ArgBuffer;

class ArgRefView
{
public:
  // ----------------------------------------
  // Public Data Types

public:
  // ----------------------------------------
  // Constructors and Destructor
  ArgRefView() = default;
  ArgRefView(const ArgRefView&) = default;
  inline ArgRefView(ArgRefView&& other) noexcept;

public:
  // ----------------------------------------
  // Operator Implementations
  ArgRefView& operator=(const ArgRefView& other) = default;
  inline ArgRefView& operator=(ArgRefView&&) noexcept;
  inline bool operator==(const ArgRefView& other) const;

public:
  // ----------------------------------------
  // Public Methods
  inline size_t size() const;
  inline void* operator[](size_t pos) const;
  inline void*const* begin() const;
  inline void*const* end() const;

  inline char Result() const;
  inline void SetResult(char result) const;

private:
  // ----------------------------------------
  // private constructors
  template<size_t N>
  inline ArgRefView(const std::array<void*, N>& argRefs, char* resultPtr);
  inline ArgRefView(const std::vector<void*>& argRefs, char* resultPtr);

  template<size_t N>
  friend class ArgRefArray;
  friend ArgBuffer;

private:
  // ----------------------------------------
  // private members
  void*const* m_ref_begin  = nullptr;
  size_t      m_ref_size   = 0;
  char*       m_result_ptr = nullptr;
};



// ================================================================================
//  Inline Implementations
// ================================================================================
ArgRefView::ArgRefView(ArgRefView&& other) noexcept
  : m_ref_begin(std::move(other.m_ref_begin)),
  m_ref_size(std::move(other.m_ref_size)),
  m_result_ptr(std::move(other.m_result_ptr))
{
}

template<size_t N>
ArgRefView::ArgRefView(const std::array<void*, N>& argRefs, char* resultPtr)
  : m_ref_begin{argRefs.data()},
    m_ref_size{N},
    m_result_ptr{ resultPtr }
{
}

ArgRefView::ArgRefView(const std::vector<void*>& argRefs, char* resultPtr)
  : m_ref_begin{ argRefs.data() },
    m_ref_size{ argRefs.size() },
    m_result_ptr{ resultPtr }
{
}

ArgRefView& ArgRefView::operator=(ArgRefView&& other) noexcept
{
  m_ref_begin = std::move(other.m_ref_begin);
  m_ref_size = std::move(other.m_ref_size);
  m_result_ptr = std::move(other.m_result_ptr);
  return *this;
}

bool ArgRefView::operator==(const ArgRefView& other) const
{
  return ((m_ref_begin == other.m_ref_begin)
       && (m_ref_size == other.m_ref_size)
       && (m_result_ptr == other.m_result_ptr));
}


size_t ArgRefView::size() const
{
  return m_ref_size;
}


void* ArgRefView::operator[](size_t pos) const
{
  assert(pos < m_ref_size);
  return m_ref_begin[pos];
}

void*const* ArgRefView::begin() const
{
  return m_ref_begin;
}

void*const* ArgRefView::end() const
{
  return m_ref_begin + m_ref_size;
}

char ArgRefView::Result() const
{
  assert(m_result_ptr);
  return *m_result_ptr;
}

void ArgRefView::SetResult(char result) const
{
  assert(m_result_ptr);
  *m_result_ptr = result;
}
