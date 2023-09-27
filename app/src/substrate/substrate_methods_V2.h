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
#define PD_CALL_STAKING_V2 9
#define PD_CALL_NOMINATIONPOOLS_V2 18
#define PD_CALL_STAKEEXCHANGE_V2 19
#define PD_CALL_MULTITOKENS_V2 253

#define PD_CALL_BALANCES_TRANSFER_ALL_V2 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V2_t;

#define PD_CALL_NOMINATIONPOOLS_PAYOUT_REWARDS_V2 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_nominationpools_payout_rewards_V2_t;

#define PD_CALL_NOMINATIONPOOLS_QUEUE_EARLY_BIRD_BONUS_V2 23
typedef struct {
} pd_nominationpools_queue_early_bird_bonus_V2_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_UNBONDED_V2 5
typedef struct {
    pd_PoolId_t pool_id;
    pd_AccountIdLookupOfT_t member_account;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_withdraw_unbonded_V2_t;

#define PD_CALL_NOMINATIONPOOLS_DISTRIBUTE_EARLY_BIRD_BONUS_V2 24
typedef struct {
    pd_u32_t transfer_count;
} pd_nominationpools_distribute_early_bird_bonus_V2_t;

#define PD_CALL_STAKEEXCHANGE_ADD_LIQUIDITY_V2 4
typedef struct {
    pd_OfferId_t offer_id;
    pd_BalanceOf_t amount;
} pd_stakeexchange_add_liquidity_V2_t;

#define PD_CALL_STAKEEXCHANGE_BUY_V2 5
typedef struct {
    pd_OfferId_t offer_id;
    pd_BalanceOf_t amount;
    pd_TokenIdOf_t token_id;
} pd_stakeexchange_buy_V2_t;

#define PD_CALL_STAKEEXCHANGE_CANCEL_OFFER_V2 1
typedef struct {
    pd_OfferId_t offer_id;
} pd_stakeexchange_cancel_offer_V2_t;

#define PD_CALL_STAKEEXCHANGE_CONFIGURE_LIQUIDITY_ACCOUNT_V2 4
typedef struct {
    pd_OfferId_t offer_id;
} pd_stakeexchange_configure_liquidity_account_V2_t;

#define PD_CALL_STAKEEXCHANGE_CREATE_OFFER_V2 4
typedef struct {
    pd_OfferId_t offer_id;
} pd_stakeexchange_create_offer_V2_t;

#define PD_CALL_STAKEEXCHANGE_WITHDRAW_LIQUIDITY_V2 4
typedef struct {
    pd_OfferId_t offer_id;
    pd_BalanceOf_t amount;
} pd_stakeexchange_withdraw_liquidity_V2_t;

//#define PD_CALL_MULTITOKENS_CREATE_COLLECTION_V2 0
//typedef struct {
//    pd_CollectionDescriptor_t descriptor;
//} pd_multitokens_create_collection_V2_t;

#define PD_CALL_MULTITOKENS_DESTROY_COLLECTION_V2 1
typedef struct {
    pd_CompactCollectionId_t collection_id;
} pd_multitokens_destroy_collection_V2_t;

//#define PD_CALL_MULTITOKENS_MUTATE_COLLECTION_V2 2
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_CollectionMutation_t mutation;
//} pd_multitokens_mutate_collection_V2_t;

//#define PD_CALL_MULTITOKENS_MUTATE_TOKEN_V2 3
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_TokenId_t token_id;
//    pd_TokenMutatetion_t mutation;
//} pd_multitokens_mutate_token_V2_t;

//#define PD_CALL_MULTITOKENS_MINT_V2 4
//typedef struct {
//    pd_AccountId_t recipient;
//    pd_CompactCollectionId_t collection_id;
//    pd_MintParams_t params;
//} pd_multitokens_mint_V2_t;

//#define PD_CALL_MULTITOKENS_BURN_V2 5
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_TokenId_t token_id;
//    pd_BurnParams_t params;
//} pd_multitokens_burn_V2_t;

//#define PD_CALL_MULTITOKENS_TRANSFER_V2 6
//typedef struct {
//    pd_AccountId_t recipient;
//    pd_CompactCollectionId_t collection_id;
//    pd_TokenId_t token_id;
//    pd_TransferParams_t params;
//} pd_multitokens_transfer_V2_t;
//
//#define PD_CALL_MULTITOKENS_FREEZE_V2 7
//typedef struct {
//    pd_FreezeInfo_t info;
//} pd_multitokens_freeze_V2_t;
//
//#define PD_CALL_MULTITOKENS_THAW_V2 8
//typedef struct {
//    pd_FreezeInfo_t info;
//} pd_multitokens_thaw_V2_t;

#define PD_CALL_MULTITOKENS_SET_ATTRIBUTE_V2 9
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_Bytes_t key;
    pd_Bytes_t value;
} pd_multitokens_set_attribute_V2_t;

#define PD_CALL_MULTITOKENS_REMOVE_ATTRIBUTE_V2 10
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_Bytes_t key;
} pd_multitokens_remove_attribute_V2_t;

#define PD_CALL_MULTITOKENS_REMOVE_ALL_ATTRIBUTES_V2 11
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_u32_t attribute_count;
} pd_multitokens_remove_all_attributes_V2_t;

//#define PD_CALL_MULTITOKENS_BATCH_TRANSFER_V2 12
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_VecTransferRecipients_t recipients;
//} pd_multitokens_batch_transfer_V2_t;
//
//#define PD_CALL_MULTITOKENS_BATCH_MINT_V2 13
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_VecMintRecipients_t recipients;
//} pd_multitokens_batch_mint_V2_t;
//
//#define PD_CALL_MULTITOKENS_BATCH_SET_ATTRIBUTE_V2 14
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_TokenId_t  token_id;
//    pd_VecSetAttribute_t attributes;
//} pd_multitokens_batch_set_attribute_V2_t;

#define PD_CALL_MULTITOKENS_APPROVE_COLLECTION_V2 15
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_AccountId_t operator_;
    pd_Optionu32_t expiration;
} pd_multitokens_approve_collection_V2_t;

#define PD_CALL_MULTITOKENS_UNAPPROVE_COLLECTION_V2 16
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_AccountId_t operator_;
} pd_multitokens_unapprove_collection_V2_t;

#define PD_CALL_MULTITOKENS_APPROVE_TOKEN_V2 17
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_AccountId_t operator_;
    pd_CompactBalance_t amount;
    pd_Optionu32_t expiration;
    pd_CompactBalance_t current_amount;
} pd_multitokens_approve_token_V2_t;

#define PD_CALL_MULTITOKENS_UNAPPROVE_TOKEN_V2 18
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_AccountId_t operator_;
} pd_multitokens_unapprove_token_V2_t;

//#define PD_CALL_MULTITOKENS_FORCE_MUTATE_COLLECTION_V2 19
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_CollectionMutation_t mutation;
//} pd_multitokens_force_mutate_collection_V2_t;
//
//#define PD_CALL_MULTITOKENS_FORCE_TRANSFER_V2 20
//typedef struct {
//    pd_AccountId_t source;
//    pd_AccountId_t destination;
//    pd_CompactCollectionId_t collection_id;
//    pd_TransferParams_t params;
//} pd_multitokens_force_transfer_V2_t;
//
//#define PD_CALL_MULTITOKENS_FORCE_SET_COLLECTION_V2 21
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_CollectionDescriptor_t value;
//} pd_multitokens_force_set_collection_V2_t;
//
//#define PD_CALL_MULTITOKENS_FORCE_SET_TOKEN_V2 22
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_TokenId_t token_id;
//    pd_TokenDescriptor_t value;
//} pd_multitokens_force_set_token_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_ATTRIBUTE_V2 23
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_Bytes_t key;
    pd_OptionBytes_t value;
} pd_multitokens_force_set_attribute_V2_t;

//#define PD_CALL_MULTITOKENS_FORCE_SET_COLLECTION_ACCOUNT_V2 24
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_AccountId_t account_id;
//    pd_CollectionAccount_t value;
//} pd_multitokens_force_set_collection_account_V2_t;
//
//#define PD_CALL_MULTITOKENS_FORCE_SET_TOKEN_ACCOUNT_V2 25
//typedef struct {
//    pd_CompactCollectionId_t collection_id;
//    pd_TokenId_t token_id;
//    pd_AccountId_t account_id;
//    pd_TokenAccount_t value;
//} pd_multitokens_force_set_token_account_V2_t;
//
//#define PD_CALL_MULTITOKENS_FORCE_CREATE_COLLECTION_V2 26
//typedef struct {
//    pd_AccountId_t owner;
//    pd_CompactCollectionId_t collection_id;
//    pd_CollectionDescriptor_t descriptor;
//} pd_multitokens_force_create_collection_V2_t;

//#define PD_CALL_MULTITOKENS_FORCE_MINT_V2 27
//typedef struct {
//    pd_AccountId_t caller;
//    pd_AccountId_t recipient;
//    pd_CompactCollectionId_t collection_id;
//    pd_MintParams_t params;
//    pd_u32_t deposit_backer;
//} pd_multitokens_force_mint_V2_t;
//
//#define PD_CALL_MULTITOKENS_FORCE_BURN_V2 28
//typedef struct {
//    pd_AccountId_t caller;
//    pd_CompactCollectionId_t collection_id;
//    pd_BurnParams_t params;
//} pd_multitokens_force_burn_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_APPROVE_COLLECTION_V2 29
typedef struct {
    pd_AccountIdLookupOfT_t caller;
    pd_CompactCollectionId_t collection_id;
    pd_AccountId_t operator_;
    pd_Optionu32_t expiration;
} pd_multitokens_force_approve_collection_V2_t;

//#define PD_CALL_MULTITOKENS_FORCE_FREEZE_V2 30
//typedef struct {
//    pd_FreezeInfo_t info;
//} pd_multitokens_force_freeze_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_NEXT_COLLECTION_ID_V2 31
typedef struct {
    pd_CompactCollectionId_t value;
} pd_multitokens_force_set_next_collection_id_V2_t;

#define PD_CALL_MULTITOKENS_CLAIM_COLLECTIONS_V2 32
typedef struct {
    pd_AccountId_t destination;
    pd_EcdsaSignature_t ethereum_signature;
    pd_EthereumAddress_t ethereum_address;
} pd_multitokens_claim_collections_V2_t;

#define PD_CALL_MULTITOKENS_CLAIM_TOKENS_V2 33
typedef struct {
    pd_AccountId_t destination;
    pd_EcdsaSignature_t ethereum_signature;
    pd_EthereumAddress_t ethereum_address;
} pd_multitokens_claim_tokens_V2_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_BALANCES_FORCE_UNRESERVE_V2 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V2_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V2 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V2_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V2 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V2_t;

#define PD_CALL_STAKING_VALIDATE_V2 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V2_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V2 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V2_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V2 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V2_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V2 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V2_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V2 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V2_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V2 12
typedef struct {
} pd_staking_force_no_eras_V2_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V2 13
typedef struct {
} pd_staking_force_new_era_V2_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V2 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V2_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V2 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V2_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V2 16
typedef struct {
} pd_staking_force_new_era_always_V2_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V2 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V2_t;

#define PD_CALL_STAKING_REAP_STASH_V2 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V2_t;

#define PD_CALL_STAKING_KICK_V2 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V2_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V2 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V2_t;

#define PD_CALL_STAKING_CHILL_OTHER_V2 23
typedef struct {
    pd_AccountId_t controller;
} pd_staking_chill_other_V2_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V2 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V2_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V2 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V2_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CONFIGS_V2 11
typedef struct {
    pd_ConfigOpBalanceOfT_t min_join_bond;
    pd_ConfigOpBalanceOfT_t min_create_bond;
    pd_ConfigOpPerbill_t global_max_commission;
} pd_nominationpools_set_configs_V2_t;
#endif

 #define PD_CALL_NOMINATIONPOOLS_SET_STAKING_INFO_V2 22
 typedef struct {
     pd_StakingInfo_t info;
 } pd_nominationpools_set_staking_info_V2_t;

typedef union {
    pd_balances_transfer_all_V2_t balances_transfer_all_V2;
    pd_nominationpools_payout_rewards_V2_t nominationpools_payout_rewards_V2;
    pd_nominationpools_queue_early_bird_bonus_V2_t nominationpools_queue_early_bird_bonus_V2;
    pd_nominationpools_withdraw_unbonded_V2_t nominationpools_withdraw_unbonded_V2;
    pd_nominationpools_distribute_early_bird_bonus_V2_t nominationpools_distribute_early_bird_bonus_V2;
    pd_stakeexchange_add_liquidity_V2_t stakeexchange_add_liquidity_V2;
    pd_stakeexchange_buy_V2_t stakeexchange_buy_V2;
    pd_stakeexchange_cancel_offer_V2_t stakeexchange_cancel_offer_V2;
    pd_stakeexchange_configure_liquidity_account_V2_t stakeexchange_configure_liquidity_account_V2;
    pd_stakeexchange_create_offer_V2_t stakeexchange_create_offer_V2;
    pd_stakeexchange_withdraw_liquidity_V2_t stakeexchange_withdraw_liquidity_V2;
//    pd_multitokens_create_collection_V2_t multitokens_create_collection_V2;
    pd_multitokens_destroy_collection_V2_t multitokens_destroy_collection_V2;
//    pd_multitokens_mutate_collection_V2_t multitokens_mutate_collection_V2;
//    pd_multitokens_mutate_token_V2_t multitokens_mutate_token_V2;
//    pd_multitokens_mint_V2_t multitokens_mint_V2;
//    pd_multitokens_burn_V2_t multitokens_burn_V2;
//    pd_multitokens_transfer_V2_t multitokens_transfer_V2;
//    pd_multitokens_freeze_V2_t multitokens_freeze_V2;
//    pd_multitokens_thaw_V2_t multitokens_thaw_V2;
    pd_multitokens_set_attribute_V2_t multitokens_set_attribute_V2;
    pd_multitokens_remove_attribute_V2_t multitokens_remove_attribute_V2;
    pd_multitokens_remove_all_attributes_V2_t multitokens_remove_all_attributes_V2;
//    pd_multitokens_batch_transfer_V2_t multitokens_batch_transfer_V2;
//    pd_multitokens_batch_mint_V2_t multitokens_batch_mint_V2;
//    pd_multitokens_batch_set_attribute_V2_t multitokens_batch_set_attribute_V2;
    pd_multitokens_approve_collection_V2_t multitokens_approve_collection_V2;
    pd_multitokens_unapprove_collection_V2_t multitokens_unapprove_collection_V2;
    pd_multitokens_approve_token_V2_t multitokens_approve_token_V2;
    pd_multitokens_unapprove_token_V2_t multitokens_unapprove_token_V2;
//    pd_multitokens_force_mutate_collection_V2_t multitokens_force_mutate_collection_V2;
//    pd_multitokens_force_transfer_V2_t multitokens_force_transfer_V2;
//    pd_multitokens_force_set_collection_V2_t multitokens_force_set_collection_V2;
//    pd_multitokens_force_set_token_V2_t multitokens_force_set_token_V2;
    pd_multitokens_force_set_attribute_V2_t multitokens_force_set_attribute_V2;
//    pd_multitokens_force_set_collection_account_V2_t multitokens_force_set_collection_account_V2;
//    pd_multitokens_force_set_token_account_V2_t multitokens_force_set_token_account_V2;
//    pd_multitokens_force_create_collection_V2_t multitokens_force_create_collection_V2;
//    pd_multitokens_force_mint_V2_t multitokens_force_mint_V2;
//    pd_multitokens_force_burn_V2_t multitokens_force_burn_V2;
    pd_multitokens_force_approve_collection_V2_t multitokens_force_approve_collection_V2;
//    pd_multitokens_force_freeze_V2_t multitokens_force_freeze_V2;
    pd_multitokens_force_set_next_collection_id_V2_t multitokens_force_set_next_collection_id_V2;
    pd_multitokens_claim_collections_V2_t multitokens_claim_collections_V2;
    pd_multitokens_claim_tokens_V2_t multitokens_claim_tokens_V2;
#ifdef SUBSTRATE_PARSER_FULL
    pd_balances_force_unreserve_V2_t balances_force_unreserve_V2;
    pd_balances_upgrade_accounts_V2_t balances_upgrade_accounts_V2;
    pd_balances_force_set_balance_V2_t balances_force_set_balance_V2;
    pd_staking_validate_V2_t staking_validate_V2;
    pd_staking_payout_stakers_V2_t staking_payout_stakers_V2;
    pd_staking_set_validator_count_V2_t staking_set_validator_count_V2;
    pd_staking_increase_validator_count_V2_t staking_increase_validator_count_V2;
    pd_staking_scale_validator_count_V2_t staking_scale_validator_count_V2;
    pd_staking_force_no_eras_V2_t staking_force_no_eras_V2;
    pd_staking_force_new_era_V2_t staking_force_new_era_V2;
    pd_staking_set_invulnerables_V2_t staking_set_invulnerables_V2;
    pd_staking_force_unstake_V2_t staking_force_unstake_V2;
    pd_staking_force_new_era_always_V2_t staking_force_new_era_always_V2;
    pd_staking_cancel_deferred_slash_V2_t staking_cancel_deferred_slash_V2;
    pd_staking_reap_stash_V2_t staking_reap_stash_V2;
    pd_staking_kick_V2_t staking_kick_V2;
    pd_staking_set_staking_configs_V2_t staking_set_staking_configs_V2;
    pd_staking_chill_other_V2_t staking_chill_other_V2;
    pd_staking_force_apply_min_commission_V2_t staking_force_apply_min_commission_V2;
    pd_staking_set_min_commission_V2_t staking_set_min_commission_V2;
    pd_nominationpools_set_configs_V2_t nominationpools_set_configs_V2;
    pd_nominationpools_set_staking_info_V2_t nominationpools_set_staking_info_V2;
#endif
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

#define PD_CALL_NOMINATIONPOOLS_BOND_V2 0
typedef struct {
    pd_PoolId_t pool_id;
    pd_BondValueOfT_t amount;
} pd_nominationpools_bond_V2_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_V2 3
typedef struct {
    pd_PoolId_t pool_id;
    pd_AccountIdLookupOfT_t member_account;
    pd_CompactBalance_t unbonding_points;
} pd_nominationpools_unbond_V2_t;

#define PD_CALL_NOMINATIONPOOLS_POOL_WITHDRAW_UNBONDED_V2 4
typedef struct {
    pd_PoolId_t pool_id;
    pd_u32_t num_slashing_spans;
} pd_nominationpools_pool_withdraw_unbonded_V2_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_V2 6
typedef struct {
    pd_TokenIdOf_t token_id;
    pd_CompactBalance_t deposit;
    pd_CompactBalance_t capacity;
    pd_EraIndex_t duration;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t nominator;
} pd_nominationpools_create_V2_t;

#define PD_CALL_NOMINATIONPOOLS_NOMINATE_V2 8
typedef struct {
    pd_PoolId_t pool_id;
    pd_VecAccountId_t validators;
} pd_nominationpools_nominate_V2_t;

#define PD_CALL_NOMINATIONPOOLS_UNBOND_DEPOSIT_V2 10
typedef struct {
    pd_PoolId_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_unbond_deposit_V2_t;

#define PD_CALL_NOMINATIONPOOLS_WITHDRAW_DEPOSIT_V2 21
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_withdraw_deposit_V2_t;

#define PD_CALL_NOMINATIONPOOLS_CHILL_V2 13
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_chill_V2_t;

#define PD_CALL_NOMINATIONPOOLS_DESTROY_V2 14
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_destroy_V2_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_OTHER_V2 16
typedef struct {
    pd_AccountId_t other;
} pd_nominationpools_claim_payout_other_V2_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_V2 17
typedef struct {
    pd_PoolId_t pool_id;
    pd_OptionTuplePerbillAccountId_t new_commission;
} pd_nominationpools_set_commission_V2_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_MAX_V2 18
typedef struct {
    pd_PoolId_t pool_id;
    pd_Perbill_t max_commission;
} pd_nominationpools_set_commission_max_V2_t;

#define PD_CALL_NOMINATIONPOOLS_SET_COMMISSION_CHANGE_RATE_V2 19
typedef struct {
    pd_PoolId_t pool_id;
    pd_CommissionChangeRateBlockNumber_t change_rate;
} pd_nominationpools_set_commission_change_rate_V2_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_COMMISSION_V2 20
typedef struct {
    pd_PoolId_t pool_id;
} pd_nominationpools_claim_commission_V2_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_STAKING_BOND_V2 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V2_t;

#define PD_CALL_STAKING_BOND_EXTRA_V2 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V2_t;

#define PD_CALL_STAKING_UNBOND_V2 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V2_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V2 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V2_t;

#define PD_CALL_STAKING_NOMINATE_V2 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V2_t;

#define PD_CALL_STAKING_CHILL_V2 6
typedef struct {
} pd_staking_chill_V2_t;

#define PD_CALL_STAKING_SET_PAYEE_V2 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V2_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V2 8
typedef struct {
} pd_staking_set_controller_V2_t;

#define PD_CALL_STAKING_REBOND_V2 19
typedef struct {
    pd_CompactBalance_t value;
} pd_staking_rebond_V2_t;
#endif


typedef union {
    pd_balances_transfer_allow_death_V2_t balances_transfer_allow_death_V2;
    pd_balances_force_transfer_V2_t balances_force_transfer_V2;
    pd_balances_transfer_keep_alive_V2_t balances_transfer_keep_alive_V2;
    pd_balances_transfer_V2_t balances_transfer_V2;
    pd_nominationpools_bond_V2_t nominationpools_bond_V2;
    // pd_nominationpools_mutate_V2_t nominationpools_mutate_V2;
    pd_nominationpools_pool_withdraw_unbonded_V2_t nominationpools_pool_withdraw_unbonded_V2;
    pd_nominationpools_create_V2_t nominationpools_create_V2;
    pd_nominationpools_nominate_V2_t nominationpools_nominate_V2;
    pd_nominationpools_unbond_V2_t nominationpools_unbond_V2;
    pd_nominationpools_unbond_deposit_V2_t nominationpools_unbond_deposit_V2;
    pd_nominationpools_withdraw_deposit_V2_t nominationpools_withdraw_deposit_V2;
    pd_nominationpools_chill_V2_t nominationpools_chill_V2;
    pd_nominationpools_destroy_V2_t nominationpools_destroy_V2;
    pd_nominationpools_claim_payout_other_V2_t nominationpools_claim_payout_other_V2;
    pd_nominationpools_set_commission_V2_t nominationpools_set_commission_V2;
    pd_nominationpools_set_commission_max_V2_t nominationpools_set_commission_max_V2;
    pd_nominationpools_set_commission_change_rate_V2_t nominationpools_set_commission_change_rate_V2;
    pd_nominationpools_claim_commission_V2_t nominationpools_claim_commission_V2;
#ifdef SUBSTRATE_PARSER_FULL
    pd_staking_bond_V2_t staking_bond_V2;
    pd_staking_bond_extra_V2_t staking_bond_extra_V2;
    pd_staking_unbond_V2_t staking_unbond_V2;
    pd_staking_withdraw_unbonded_V2_t staking_withdraw_unbonded_V2;
    pd_staking_nominate_V2_t staking_nominate_V2;
    pd_staking_chill_V2_t staking_chill_V2;
    pd_staking_set_payee_V2_t staking_set_payee_V2;
    pd_staking_set_controller_V2_t staking_set_controller_V2;
    pd_staking_rebond_V2_t staking_rebond_V2;
#endif
} pd_MethodNested_V2_t;

typedef union {
    pd_MethodBasic_V2_t basic;
    pd_MethodNested_V2_t nested;
} pd_Method_V2_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
