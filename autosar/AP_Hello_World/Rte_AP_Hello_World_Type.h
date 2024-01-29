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
 *             File:  Rte_AP_Hello_World_Type.h
 *        SW-C Type:  AP_Hello_World
 *  Generation Time:  2023-12-15 09:22:32
 *
 *        Generator:  MICROSAR RTE ContractPhase Generator Version 3.14.22
 *                    RTE Core Version 4.31.0
 *          License:  DVSwcGen
 *
 *      Description:  Application types header file for SW-C <AP_Hello_World> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_AP_HELLO_WORLD_TYPE_H
# define RTE_AP_HELLO_WORLD_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define Int16Constr_LowerLimit (1)
#  define Int16Constr_UpperLimit (10)

#  define Uint8AllConstr_LowerLimit (1U)
#  define Uint8AllConstr_UpperLimit (10U)

#  define CustomFloat_RangeInfMax_LowerLimit (-FLT_MAX)
#  define CustomFloat_RangeInfMax_UpperLimit (99.0F)

#  define doubleConstrInfOpen_LowerLimit (20000.0)
#  define doubleConstrInfOpen_UpperLimit (DBL_MAX)

#  define Uint8Constr_LowerLimit (1U)
#  define Uint8Constr_UpperLimit (10U)

#  define CustomSignedValue_LowerLimit (-42)
#  define CustomSignedValue_UpperLimit (123)

#  define CustomSignedValue_RangeOpen_LowerLimit (1)
#  define CustomSignedValue_RangeOpen_UpperLimit (99)

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_ExplicitModeGroup
#  define RTE_MODETYPE_ExplicitModeGroup
typedef uint8 Rte_ModeType_ExplicitModeGroup;
# endif
# ifndef RTE_MODETYPE_ModeDeclarationGroup
#  define RTE_MODETYPE_ModeDeclarationGroup
typedef uint8 Rte_ModeType_ModeDeclarationGroup;
# endif

# define RTE_MODE_AP_Hello_World_ExplicitModeGroup_Init (0U)
# ifndef RTE_MODE_ExplicitModeGroup_Init
#  define RTE_MODE_ExplicitModeGroup_Init (0U)
# endif
# define RTE_MODE_AP_Hello_World_ExplicitModeGroup_Next (1U)
# ifndef RTE_MODE_ExplicitModeGroup_Next
#  define RTE_MODE_ExplicitModeGroup_Next (1U)
# endif
# define RTE_MODE_AP_Hello_World_ExplicitModeGroup_Last (2U)
# ifndef RTE_MODE_ExplicitModeGroup_Last
#  define RTE_MODE_ExplicitModeGroup_Last (2U)
# endif
# define RTE_TRANSITION_AP_Hello_World_ExplicitModeGroup (4U)
# ifndef RTE_TRANSITION_ExplicitModeGroup
#  define RTE_TRANSITION_ExplicitModeGroup (4U)
# endif

# define RTE_MODE_AP_Hello_World_ModeDeclarationGroup_SomeMode (0U)
# ifndef RTE_MODE_ModeDeclarationGroup_SomeMode
#  define RTE_MODE_ModeDeclarationGroup_SomeMode (0U)
# endif
# define RTE_MODE_AP_Hello_World_ModeDeclarationGroup_SomeOtherMode (1U)
# ifndef RTE_MODE_ModeDeclarationGroup_SomeOtherMode
#  define RTE_MODE_ModeDeclarationGroup_SomeOtherMode (1U)
# endif
# define RTE_TRANSITION_AP_Hello_World_ModeDeclarationGroup (2U)
# ifndef RTE_TRANSITION_ModeDeclarationGroup
#  define RTE_TRANSITION_ModeDeclarationGroup (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_AP_HELLO_WORLD_TYPE_H */
