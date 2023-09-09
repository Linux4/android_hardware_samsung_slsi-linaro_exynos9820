//------------------------------------------------------------------------------
/// @file  sc_pimpl_base.h
/// @ingroup  include
///
/// @brief  Declaration of base class for implementing PIMPL
///
/// SCore SDK PIMPL definitions are use naming conventions from Qt library:
/// d-pointer - public class ScFoo stores a pointer to private class ScFooPrivate
/// q-pointer - private class ScFooPrivate stores a pointer to the public class ScFoo
/// Every class derived from ScPimplBase must contain:
///  private:
///   SC_DECLARE_PRIVATE(ScClassName)
///
/// @author  Aleksiej Chrabrow<a.chrabrow@partner.samsung.com>
///
/// @section changelog Change Log
/// 2017/09/27  Aleksiej Chrabrow  created
////
/// @section copyright_section Copyright
/// &copy; 2017, Samsung Electronics Co., Ltd.
///
/// @section license_section License
//------------------------------------------------------------------------------

#ifndef SCORE_HOST_PLATFORM_INCLUDE_SC_PIMPL_BASE_H_
#define SCORE_HOST_PLATFORM_INCLUDE_SC_PIMPL_BASE_H_

#include "sc_platform_global.h"

namespace score {

/// @brief  Create private data access methods in public class
#define SC_DECLARE_PRIVATE(Class)                           \
  inline Class##Private * d_func() {                        \
    return reinterpret_cast<Class##Private *>(d_ptr);       \
  }                                                         \
  inline const Class##Private * d_func() const {            \
    return reinterpret_cast<const Class##Private *>(d_ptr); \
  }                                                         \
  friend class Class##Private;

/// @brief  Create public class access methods in private class
#define SC_DECLARE_PUBLIC(Class)              \
  inline Class * q_func() {                   \
    return static_cast<Class *>(q_ptr);       \
  }                                           \
  inline const Class * q_func() const {       \
    return static_cast<const Class *>(q_ptr); \
  }                                           \
  friend class Class;

/// @brief  Create d-pointer for accessing private data
#define SC_D(Class) Class##Private * const d = d_func()

/// @brief  Create q-pointer for accessing public class
#define SC_Q(Class) Class * const q = q_func()

class ScPimplBasePrivate;

/// @brief  Base class for PIMPL. Every class implementing
///         PIMPL idiom must derive from ScPimplBase.
class SC_PUBLIC_API ScPimplBase {
 public:
  /// @brief  Default constructor of ScPimplBase
  ScPimplBase();

#if __cplusplus > 199711L
  /// @brief  Move constructor
  ScPimplBase(ScPimplBase &&src);
  /// @brief  Move assignment
  ScPimplBase& operator=(ScPimplBase &&src);
#endif

  /// @brief  Destructor of ScPimplBase
  virtual ~ScPimplBase();

 protected:
  /// @brief  Internal constructor of ScPimplBase
  ///
  /// Every class derived from ScPimplBase that
  /// implements own ScPimplBasePrivate-derived
  /// private data must call this construtor.
  ScPimplBase(ScPimplBasePrivate &d);

  /// @brief  Pointer to implementation aka PIMPL
  ScPimplBasePrivate *d_ptr;

 private:
  // disable copy constructor and copy assignment
#if __cplusplus <= 199711L
  ScPimplBase(const ScPimplBase &);
  ScPimplBase& operator=(const ScPimplBase &);
#else
  ScPimplBase(const ScPimplBase &) = delete;
  ScPimplBase& operator=(const ScPimplBase &) = delete;
#endif
};

} // namespace score

#endif
