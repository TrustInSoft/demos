/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*
*                This software is copyright protected and proprietary to Vector Informatik GmbH.
*                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
*                All other rights remain with Vector Informatik GmbH.
*  -------------------------------------------------------------------------------------------------------------------
*********************************************************************************************************************/

#include "InteractionModel.h"
#include "ApplicationModel.h"

#if defined(_WIN32) && (defined(_MSC_VER) || defined(__MINGW32__))
#  ifdef VTTDLL_EXPORTS
#    define VTTDLL_API __declspec(dllexport)
#  else
#    define VTTDLL_API __declspec(dllimport)
#  endif
#elif defined(__linux__) && (defined (__clang__) || defined (__GNUC__))
#  ifdef VTTDLL_EXPORTS
#    define VTTDLL_API __attribute__((visibility("default")))
#  else
#    define VTTDLL_API
#  endif
#else
#  error "Unknown Compiler"
#endif

typedef void(*VTT_Init_Func)(IInteractionModel* pInteractionModel, IApplicationModel** ppApplicationModel);

void VTT_Init(IInteractionModel* pInteractionModel, IApplicationModel** ppApplicationModel);
VTTDLL_API void VTT_DynInit(IInteractionModel* pInteractionModel, IApplicationModel** ppApplicationModel);
