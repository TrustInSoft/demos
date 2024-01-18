/**************************************************************************/
/*                                                                        */
/*  This file is part of TrustInSoft Analyzer.                            */
/*                                                                        */
/*    Copyright (C) 2023 TrustInSoft                                      */
/*                                                                        */
/*  All rights reserved.                                                  */
/*                                                                        */
/**************************************************************************/

#ifndef COMPILER_H
#define COMPILER_H

// The following come from the specification of [Compiler.h] which was removed
// in the release R22-11.

#include "Compiler_Cfg.h"

#define AUTOMATIC

#define TYPEDEF

#define INLINE inline

#define LOCAL_INLINE static inline

#define FUNC(rettype, memclass) rettype

#define FUNC_P2VAR(rettype, ptrclass, memclass) rettype *

#define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype *

#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)

#define CONST(type, memclass) const type

#define VAR(type, memclass) type

#endif // COMPILER_H