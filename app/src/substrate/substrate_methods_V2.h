/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V2.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_BALANCES_V2 6

#define PD_CALL_BALANCES_TRANSFER_ALL_V2 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V2_t;

typedef union {
    pd_balances_transfer_all_V2_t balances_transfer_all_V2;
} pd_MethodBasic_V2_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V2 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V2_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V2 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V2_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V2 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V2_t;

#define PD_CALL_BALANCES_TRANSFER_V2 7
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V2_t;

typedef union {
    pd_balances_transfer_allow_death_V2_t balances_transfer_allow_death_V2;
    pd_balances_force_transfer_V2_t balances_force_transfer_V2;
    pd_balances_transfer_keep_alive_V2_t balances_transfer_keep_alive_V2;
    pd_balances_transfer_V2_t balances_transfer_V2;
} pd_MethodNested_V2_t;

typedef union {
    pd_MethodBasic_V2_t basic;
    pd_MethodNested_V2_t nested;
} pd_Method_V2_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
