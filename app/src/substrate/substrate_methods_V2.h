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

#define PD_CALL_SYSTEM_V2 0
#define PD_CALL_PREIMAGE_V2 10
#define PD_CALL_TIMESTAMP_V2 3
#define PD_CALL_INDICES_V2 4
#define PD_CALL_BALANCES_V2 5
#define PD_CALL_STAKING_V2 7
#define PD_CALL_SESSION_V2 9
#define PD_CALL_DEMOCRACY_V2 14
#define PD_CALL_COUNCIL_V2 15
#define PD_CALL_TECHNICALCOMMITTEE_V2 16
#define PD_CALL_PHRAGMENELECTION_V2 17
#define PD_CALL_TECHNICALMEMBERSHIP_V2 18
#define PD_CALL_TREASURY_V2 19
#define PD_CALL_CONVICTIONVOTING_V2 20
#define PD_CALL_REFERENDA_V2 21
#define PD_CALL_WHITELIST_V2 23
#define PD_CALL_CLAIMS_V2 24
#define PD_CALL_VESTING_V2 25
#define PD_CALL_UTILITY_V2 26
#define PD_CALL_IDENTITY_V2 28
#define PD_CALL_PROXY_V2 29
#define PD_CALL_MULTISIG_V2 30
#define PD_CALL_BOUNTIES_V2 34
#define PD_CALL_CHILDBOUNTIES_V2 38
#define PD_CALL_TIPS_V2 35
#define PD_CALL_VOTERLIST_V2 37
#define PD_CALL_NOMINATIONPOOLS_V2 39
#define PD_CALL_FASTUNSTAKE_V2 40
#define PD_CALL_CONFIGURATION_V2 51
#define PD_CALL_INITIALIZER_V2 57
#define PD_CALL_PARASDISPUTES_V2 62
#define PD_CALL_AUCTIONS_V2 72
#define PD_CALL_CROWDLOAN_V2 73
#define PD_CALL_XCMPALLET_V2 99

    ///////////////


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

#define PD_CALL_NOMINATIONPOOLS_MUTATE_V2 19
typedef struct {
    pd_PoolId_t pool_id;
    pd_PoolMutationOfT_t mutation;
} pd_nominationpools_mutate_V2_t;

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

#define PD_CALL_STAKEEXCHANGE_CONFIGURE_LIQUIDITY_ACCOUNT_V2 2
typedef struct {
    pd_LiquidityAccountConfigOfT_t config;
} pd_stakeexchange_configure_liquidity_account_V2_t;

#define PD_CALL_STAKEEXCHANGE_CREATE_OFFER_V2 0
typedef struct {
    pd_OfferOfT_t offer;
} pd_stakeexchange_create_offer_V2_t;

#define PD_CALL_STAKEEXCHANGE_WITHDRAW_LIQUIDITY_V2 3
typedef struct {
    pd_OfferId_t offer_id;
    pd_BalanceOf_t amount;
} pd_stakeexchange_withdraw_liquidity_V2_t;

#define PD_CALL_MULTITOKENS_CREATE_COLLECTION_V2 0
typedef struct {
    pd_CollectionDescriptor_t descriptor;
} pd_multitokens_create_collection_V2_t;

#define PD_CALL_MULTITOKENS_DESTROY_COLLECTION_V2 1
typedef struct {
    pd_CompactCollectionId_t collection_id;
} pd_multitokens_destroy_collection_V2_t;

#define PD_CALL_MULTITOKENS_MUTATE_COLLECTION_V2 2
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CollectionMutation_t mutation;
} pd_multitokens_mutate_collection_V2_t;

#define PD_CALL_MULTITOKENS_BURN_V2 5
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_BurnParamsOfT_t params;
} pd_multitokens_burn_V2_t;

#define PD_CALL_MULTITOKENS_TRANSFER_V2 6
typedef struct {
    pd_AccountIdLookupOfT_t recipient;
    pd_CompactCollectionId_t collection_id;
    pd_TransferParamsOfT_t params;
} pd_multitokens_transfer_V2_t;

#define PD_CALL_MULTITOKENS_FREEZE_V2 7
typedef struct {
    pd_FreezeOf_t info;
} pd_multitokens_freeze_V2_t;

#define PD_CALL_MULTITOKENS_THAW_V2 8
typedef struct {
    pd_FreezeOf_t info;
} pd_multitokens_thaw_V2_t;

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

#define PD_CALL_MULTITOKENS_BATCH_TRANSFER_V2 12
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_VecTransferRecipientsOf_t recipients;
} pd_multitokens_batch_transfer_V2_t;

#define PD_CALL_MULTITOKENS_BATCH_SET_ATTRIBUTE_V2 14
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t  token_id;
    pd_VecAttributeKeyValuePair_t attributes;
} pd_multitokens_batch_set_attribute_V2_t;

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
    pd_CompactIndex_t duration;
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
#ifndef TARGET_NANOS

#define PD_CALL_MULTITOKENS_MUTATE_TOKEN_V2 3
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_TokenMutation_t mutation;
} pd_multitokens_mutate_token_V2_t;

#define PD_CALL_MULTITOKENS_MINT_V2 4
typedef struct {
    pd_AccountIdLookupOfT_t recipient;
    pd_CompactCollectionId_t collection_id;
    pd_MintParamsOf_t params;
} pd_multitokens_mint_V2_t;

#define PD_CALL_MULTITOKENS_BATCH_MINT_V2 13
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_VecMintRecipientsOf_t recipients;
} pd_multitokens_batch_mint_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_MUTATE_COLLECTION_V2 19
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CollectionMutation_t mutation;
} pd_multitokens_force_mutate_collection_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_TRANSFER_V2 20
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t destination;
    pd_CompactCollectionId_t collection_id;
    pd_TransferParamsOfT_t params;
} pd_multitokens_force_transfer_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_COLLECTION_V2 21
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionCollectionOf_t value;
} pd_multitokens_force_set_collection_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_TOKEN_V2 22
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_OptionTokenOf_t value;
} pd_multitokens_force_set_token_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_ATTRIBUTE_V2 23
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_OptionTokenId_t token_id;
    pd_Bytes_t key;
    pd_OptionAttributeOf_t value;
} pd_multitokens_force_set_attribute_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_COLLECTION_ACCOUNT_V2 24
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_AccountIdLookupOfT_t account_id;
    pd_OptionCollectionAccountOf_t value;
} pd_multitokens_force_set_collection_account_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_TOKEN_ACCOUNT_V2 25
typedef struct {
    pd_CompactCollectionId_t collection_id;
    pd_CompactTokenId_t token_id;
    pd_AccountIdLookupOfT_t account_id;
    pd_OptionTokenAccountOf_t value;
} pd_multitokens_force_set_token_account_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_CREATE_COLLECTION_V2 26
typedef struct {
    pd_AccountId_t owner;
    pd_CompactCollectionId_t collection_id;
    pd_CollectionDescriptor_t descriptor;
} pd_multitokens_force_create_collection_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_MINT_V2 27
typedef struct {
    pd_AccountIdLookupOfT_t caller;
    pd_AccountIdLookupOfT_t recipient;
    pd_CompactCollectionId_t collection_id;
    pd_MintParamsOf_t params;
    pd_OptionAccountIdLookupOfT_t deposit_backer;
} pd_multitokens_force_mint_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_BURN_V2 28
typedef struct {
    pd_AccountIdLookupOfT_t caller;
    pd_CompactCollectionId_t collection_id;
    pd_BurnParamsOfT_t params;
} pd_multitokens_force_burn_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_APPROVE_COLLECTION_V2 29
typedef struct {
    pd_AccountIdLookupOfT_t caller;
    pd_CompactCollectionId_t collection_id;
    pd_AccountId_t operator_;
    pd_Optionu32_t expiration;
} pd_multitokens_force_approve_collection_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_FREEZE_V2 30
typedef struct {
    pd_FreezeOf_t info;
} pd_multitokens_force_freeze_V2_t;

#define PD_CALL_MULTITOKENS_FORCE_SET_NEXT_COLLECTION_ID_V2 31
typedef struct {
    pd_CompactCollectionId_t value;
} pd_multitokens_force_set_next_collection_id_V2_t;

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

#endif
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

#define PD_CALL_NOMINATIONPOOLS_SET_STAKING_INFO_V2 22
typedef struct {
    pd_StakingInfo_t info;
} pd_nominationpools_set_staking_info_V2_t;

/////////////

#define PD_CALL_SESSION_SET_KEYS_V2 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V2_t;

#define PD_CALL_SESSION_PURGE_KEYS_V2 1
typedef struct {
} pd_session_purge_keys_V2_t;

#define PD_CALL_UTILITY_BATCH_V2 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V2_t;

#define PD_CALL_UTILITY_BATCH_ALL_V2 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V2_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V2 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V2_t;

#define PD_CALL_CROWDLOAN_CREATE_V2 0
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_t verifier;
} pd_crowdloan_create_V2_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_V2 1
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t amount;
    pd_OptionMultiSignature_t signature;
} pd_crowdloan_contribute_V2_t;

#define PD_CALL_CROWDLOAN_WITHDRAW_V2 2
typedef struct {
    pd_AccountId_t who;
    pd_Compactu32_t index;
} pd_crowdloan_withdraw_V2_t;

#define PD_CALL_CROWDLOAN_REFUND_V2 3
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_refund_V2_t;

#define PD_CALL_CROWDLOAN_DISSOLVE_V2 4
typedef struct {
    pd_Compactu32_t index;
} pd_crowdloan_dissolve_V2_t;

#define PD_CALL_CROWDLOAN_EDIT_V2 5
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t cap;
    pd_Compactu32_t first_period;
    pd_Compactu32_t last_period;
    pd_Compactu32_t end;
    pd_OptionMultiSigner_t verifier;
} pd_crowdloan_edit_V2_t;

#define PD_CALL_CROWDLOAN_ADD_MEMO_V2 6
typedef struct {
    pd_ParaId_t index;
    pd_Vecu8_t memo;
} pd_crowdloan_add_memo_V2_t;

#define PD_CALL_CROWDLOAN_POKE_V2 7
typedef struct {
    pd_ParaId_t index;
} pd_crowdloan_poke_V2_t;

#define PD_CALL_CROWDLOAN_CONTRIBUTE_ALL_V2 8
typedef struct {
    pd_Compactu32_t index;
    pd_OptionMultiSignature_t signature;
} pd_crowdloan_contribute_all_V2_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#define PD_CALL_XCMPALLET_TELEPORT_ASSETS_V2 1
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_xcmpallet_teleport_assets_V2_t;
#define PD_CALL_XCMPALLET_RESERVE_TRANSFER_ASSETS_V2 2
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_xcmpallet_reserve_transfer_assets_V2_t;
#define PD_CALL_XCMPALLET_LIMITED_RESERVE_TRANSFER_ASSETS_V2 8
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_xcmpallet_limited_reserve_transfer_assets_V2_t;
#define PD_CALL_XCMPALLET_LIMITED_TELEPORT_ASSETS_V2 9
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_xcmpallet_limited_teleport_assets_V2_t;
#endif

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V2 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V2_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V2 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V2_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V2 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V2_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V2 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V2_t;

#define PD_CALL_TIMESTAMP_SET_V2 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V2_t;

#define PD_CALL_INDICES_CLAIM_V2 0
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_claim_V2_t;

#define PD_CALL_INDICES_TRANSFER_V2 1
typedef struct {
    pd_AccountIdLookupOfT_t new_;
    pd_AccountIndex_t index;
} pd_indices_transfer_V2_t;

#define PD_CALL_INDICES_FREE_V2 2
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_free_V2_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V2 3
typedef struct {
    pd_AccountIdLookupOfT_t new_;
    pd_AccountIndex_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V2_t;

#define PD_CALL_INDICES_FREEZE_V2 4
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_freeze_V2_t;

#define PD_CALL_DEMOCRACY_BLACKLIST_V2 16
typedef struct {
    pd_H256_t proposal_hash;
    pd_OptionReferendumIndex_t maybe_ref_index;
} pd_democracy_blacklist_V2_t;

#define PD_CALL_DEMOCRACY_SET_METADATA_V2 18
typedef struct {
    pd_MetadataOwner_t owner;
    pd_OptionPreimageHash_t maybe_hash;
} pd_democracy_set_metadata_V2_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V2 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_council_set_members_V2_t;

#define PD_CALL_COUNCIL_EXECUTE_V2 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V2_t;

#define PD_CALL_COUNCIL_PROPOSE_V2 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V2_t;

#define PD_CALL_COUNCIL_VOTE_V2 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V2_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V2 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V2_t;

#define PD_CALL_COUNCIL_CLOSE_V2 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V2 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_technicalcommittee_set_members_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V2 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V2 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V2 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V2 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V2_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V2 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V2_t;

#define PD_CALL_PHRAGMENELECTION_VOTE_V2 0
typedef struct {
    pd_VecAccountId_t votes;
    pd_CompactBalance_t amount;
} pd_phragmenelection_vote_V2_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V2 1
typedef struct {
} pd_phragmenelection_remove_voter_V2_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V2 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V2_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V2 4
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_bool_t slash_bond;
    pd_bool_t rerun_election;
} pd_phragmenelection_remove_member_V2_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V2 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_phragmenelection_clean_defunct_voters_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V2 0
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_add_member_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V2 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_remove_member_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V2 2
typedef struct {
    pd_AccountIdLookupOfT_t remove;
    pd_AccountIdLookupOfT_t add;
} pd_technicalmembership_swap_member_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V2 3
typedef struct {
    pd_VecAccountId_t members;
} pd_technicalmembership_reset_members_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V2 4
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_technicalmembership_change_key_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V2 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_set_prime_V2_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V2 6
typedef struct {
} pd_technicalmembership_clear_prime_V2_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V2 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_propose_spend_V2_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V2 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V2_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V2 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V2_t;

#define PD_CALL_TREASURY_SPEND_V2 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_spend_V2_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V2 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V2_t;

#define PD_CALL_REFERENDA_SUBMIT_V2 0
typedef struct {
    pd_BoxPalletsOriginOfT_t proposal_origin;
    pd_BoundedCallOfT_t proposal;
    pd_DispatchTimeBlockNumber_t enactment_moment;
} pd_referenda_submit_V2_t;

#define PD_CALL_REFERENDA_PLACE_DECISION_DEPOSIT_V2 1
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_place_decision_deposit_V2_t;

#define PD_CALL_REFERENDA_REFUND_DECISION_DEPOSIT_V2 2
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_refund_decision_deposit_V2_t;

#define PD_CALL_REFERENDA_CANCEL_V2 3
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_cancel_V2_t;

#define PD_CALL_REFERENDA_KILL_V2 4
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_kill_V2_t;

#define PD_CALL_REFERENDA_NUDGE_REFERENDUM_V2 5
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_nudge_referendum_V2_t;

#define PD_CALL_REFERENDA_ONE_FEWER_DECIDING_V2 6
typedef struct {
    pd_TrackIdOf_t track;
} pd_referenda_one_fewer_deciding_V2_t;

#define PD_CALL_REFERENDA_REFUND_SUBMISSION_DEPOSIT_V2 7
typedef struct {
    pd_ReferendumIndex_t index;
} pd_referenda_refund_submission_deposit_V2_t;

#define PD_CALL_REFERENDA_SET_METADATA_V2 8
typedef struct {
    pd_ReferendumIndex_t index;
    pd_OptionPreimageHash_t maybe_hash;
} pd_referenda_set_metadata_V2_t;

#define PD_CALL_WHITELIST_WHITELIST_CALL_V2 0
typedef struct {
    pd_PreimageHash_t call_hash;
} pd_whitelist_whitelist_call_V2_t;

#define PD_CALL_WHITELIST_REMOVE_WHITELISTED_CALL_V2 1
typedef struct {
    pd_PreimageHash_t call_hash;
} pd_whitelist_remove_whitelisted_call_V2_t;

#define PD_CALL_WHITELIST_DISPATCH_WHITELISTED_CALL_V2 2
typedef struct {
    pd_PreimageHash_t call_hash;
    pd_u32_t call_encoded_len;
    pd_Weight_t call_weight_witness;
} pd_whitelist_dispatch_whitelisted_call_V2_t;

#define PD_CALL_WHITELIST_DISPATCH_WHITELISTED_CALL_WITH_PREIMAGE_V2 3
typedef struct {
    pd_Call_t call;
} pd_whitelist_dispatch_whitelisted_call_with_preimage_V2_t;

#define PD_CALL_CLAIMS_CLAIM_V2 0
typedef struct {
    pd_AccountId_t dest;
    pd_EcdsaSignature_t ethereum_signature;
} pd_claims_claim_V2_t;

#define PD_CALL_CLAIMS_CLAIM_ATTEST_V2 2
typedef struct {
    pd_AccountId_t dest;
    pd_EcdsaSignature_t ethereum_signature;
    pd_Bytes_t statement;
} pd_claims_claim_attest_V2_t;

#define PD_CALL_CLAIMS_ATTEST_V2 3
typedef struct {
    pd_Bytes_t statement;
} pd_claims_attest_V2_t;

#define PD_CALL_CLAIMS_MOVE_CLAIM_V2 4
typedef struct {
    pd_EthereumAddress_t old;
    pd_EthereumAddress_t new_;
    pd_OptionAccountId_t maybe_preclaim;
} pd_claims_move_claim_V2_t;

#define PD_CALL_VESTING_VEST_V2 0
typedef struct {
} pd_vesting_vest_V2_t;

#define PD_CALL_VESTING_VEST_OTHER_V2 1
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_vesting_vest_other_V2_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V2 2
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_vested_transfer_V2_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V2 3
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t target;
    pd_VestingInfo_t schedule;
} pd_vesting_force_vested_transfer_V2_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V2 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V2_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V2 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V2_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V2 0
typedef struct {
    pd_AccountIdLookupOfT_t account;
} pd_identity_add_registrar_V2_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V2 1
typedef struct {
    pd_IdentityInfo_t info;
} pd_identity_set_identity_V2_t;

#define PD_CALL_IDENTITY_SET_SUBS_V2 2
typedef struct {
    pd_VecTupleAccountIdData_t subs;
} pd_identity_set_subs_V2_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V2 3
typedef struct {
} pd_identity_clear_identity_V2_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V2 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V2_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V2 5
typedef struct {
    pd_RegistrarIndex_t reg_index;
} pd_identity_cancel_request_V2_t;

#define PD_CALL_IDENTITY_SET_FEE_V2 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V2_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V2 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountIdLookupOfT_t new_;
} pd_identity_set_account_id_V2_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V2 9
typedef struct {
    pd_Compactu32_t reg_index;
    pd_AccountIdLookupOfT_t target;
    pd_JudgementBalanceOfT_t judgement;
    pd_Hash_t identity;
} pd_identity_provide_judgement_V2_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V2 10
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_identity_kill_identity_V2_t;

#define PD_CALL_IDENTITY_ADD_SUB_V2 11
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V2_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V2 12
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V2_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V2 13
typedef struct {
    pd_AccountIdLookupOfT_t sub;
} pd_identity_remove_sub_V2_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V2 14
typedef struct {
} pd_identity_quit_sub_V2_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V2 3
typedef struct {
} pd_proxy_remove_proxies_V2_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V2 9
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V2_t;

#define PD_CALL_BOUNTIES_PROPOSE_BOUNTY_V2 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_Bytes_t description;
} pd_bounties_propose_bounty_V2_t;

#define PD_CALL_BOUNTIES_APPROVE_BOUNTY_V2 1
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_approve_bounty_V2_t;

#define PD_CALL_BOUNTIES_PROPOSE_CURATOR_V2 2
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_t curator;
    pd_CompactBalance_t fee;
} pd_bounties_propose_curator_V2_t;

#define PD_CALL_BOUNTIES_UNASSIGN_CURATOR_V2 3
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_unassign_curator_V2_t;

#define PD_CALL_BOUNTIES_ACCEPT_CURATOR_V2 4
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_accept_curator_V2_t;

#define PD_CALL_BOUNTIES_AWARD_BOUNTY_V2 5
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_bounties_award_bounty_V2_t;

#define PD_CALL_BOUNTIES_CLAIM_BOUNTY_V2 6
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_claim_bounty_V2_t;

#define PD_CALL_BOUNTIES_CLOSE_BOUNTY_V2 7
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_bounties_close_bounty_V2_t;

#define PD_CALL_BOUNTIES_EXTEND_BOUNTY_EXPIRY_V2 8
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t remark;
} pd_bounties_extend_bounty_expiry_V2_t;

#define PD_CALL_CHILDBOUNTIES_ADD_CHILD_BOUNTY_V2 0
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_CompactBalance_t amount;
    pd_Vecu8_t description;
} pd_childbounties_add_child_bounty_V2_t;

#define PD_CALL_CHILDBOUNTIES_PROPOSE_CURATOR_V2 1
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_t curator;
    pd_CompactBalance_t fee;
} pd_childbounties_propose_curator_V2_t;

#define PD_CALL_CHILDBOUNTIES_ACCEPT_CURATOR_V2 2
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_accept_curator_V2_t;

#define PD_CALL_CHILDBOUNTIES_UNASSIGN_CURATOR_V2 3
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_unassign_curator_V2_t;

#define PD_CALL_CHILDBOUNTIES_AWARD_CHILD_BOUNTY_V2 4
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_childbounties_award_child_bounty_V2_t;

#define PD_CALL_CHILDBOUNTIES_CLAIM_CHILD_BOUNTY_V2 5
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_claim_child_bounty_V2_t;

#define PD_CALL_CHILDBOUNTIES_CLOSE_CHILD_BOUNTY_V2 6
typedef struct {
    pd_Compactu32_t parent_bounty_id;
    pd_Compactu32_t child_bounty_id;
} pd_childbounties_close_child_bounty_V2_t;

#define PD_CALL_TIPS_REPORT_AWESOME_V2 0
typedef struct {
    pd_Bytes_t reason;
    pd_AccountIdLookupOfT_t who;
} pd_tips_report_awesome_V2_t;

#define PD_CALL_TIPS_RETRACT_TIP_V2 1
typedef struct {
    pd_Hash_t hash;
} pd_tips_retract_tip_V2_t;

#define PD_CALL_TIPS_TIP_NEW_V2 2
typedef struct {
    pd_Bytes_t reason;
    pd_AccountIdLookupOfT_t who;
    pd_Compactu128_t tip_value;
} pd_tips_tip_new_V2_t;

#define PD_CALL_TIPS_TIP_V2 3
typedef struct {
    pd_Hash_t hash;
    pd_Compactu128_t tip_value;
} pd_tips_tip_V2_t;

#define PD_CALL_TIPS_CLOSE_TIP_V2 4
typedef struct {
    pd_Hash_t hash;
} pd_tips_close_tip_V2_t;

#define PD_CALL_TIPS_SLASH_TIP_V2 5
typedef struct {
    pd_Hash_t hash;
} pd_tips_slash_tip_V2_t;

#define PD_CALL_VOTERLIST_REBAG_V2 0
typedef struct {
    pd_AccountIdLookupOfT_t dislocated;
} pd_voterlist_rebag_V2_t;

#define PD_CALL_VOTERLIST_PUT_IN_FRONT_OF_V2 1
typedef struct {
    pd_AccountIdLookupOfT_t lighter;
} pd_voterlist_put_in_front_of_V2_t;

#define PD_CALL_NOMINATIONPOOLS_CREATE_WITH_POOL_ID_V2 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t root;
    pd_AccountIdLookupOfT_t nominator;
    pd_AccountIdLookupOfT_t bouncer;
    pd_PoolId_t pool_id;
} pd_nominationpools_create_with_pool_id_V2_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_OTHER_V2 14
typedef struct {
    pd_AccountIdLookupOfT_t member;
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_other_V2_t;

#define PD_CALL_FASTUNSTAKE_CONTROL_V2 2
typedef struct {
    pd_EraIndex_t eras_to_check;
} pd_fastunstake_control_V2_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_COOLDOWN_V2 0
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_cooldown_V2_t;

#define PD_CALL_CONFIGURATION_SET_VALIDATION_UPGRADE_DELAY_V2 1
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_validation_upgrade_delay_V2_t;

#define PD_CALL_CONFIGURATION_SET_CODE_RETENTION_PERIOD_V2 2
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_code_retention_period_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_CODE_SIZE_V2 3
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_code_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_POV_SIZE_V2 4
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_pov_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_HEAD_DATA_SIZE_V2 5
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_head_data_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_CORES_V2 6
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_cores_V2_t;

#define PD_CALL_CONFIGURATION_SET_PARATHREAD_RETRIES_V2 7
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_parathread_retries_V2_t;

#define PD_CALL_CONFIGURATION_SET_GROUP_ROTATION_FREQUENCY_V2 8
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_group_rotation_frequency_V2_t;

#define PD_CALL_CONFIGURATION_SET_CHAIN_AVAILABILITY_PERIOD_V2 9
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_chain_availability_period_V2_t;

#define PD_CALL_CONFIGURATION_SET_THREAD_AVAILABILITY_PERIOD_V2 10
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_thread_availability_period_V2_t;

#define PD_CALL_CONFIGURATION_SET_SCHEDULING_LOOKAHEAD_V2 11
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_scheduling_lookahead_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_PER_CORE_V2 12
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_per_core_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_VALIDATORS_V2 13
typedef struct {
    pd_Optionu32_t new_;
} pd_configuration_set_max_validators_V2_t;

#define PD_CALL_CONFIGURATION_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD_V2 15
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_dispute_post_conclusion_acceptance_period_V2_t;

#define PD_CALL_CONFIGURATION_SET_NO_SHOW_SLOTS_V2 18
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_no_show_slots_V2_t;

#define PD_CALL_CONFIGURATION_SET_N_DELAY_TRANCHES_V2 19
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_n_delay_tranches_V2_t;

#define PD_CALL_CONFIGURATION_SET_ZEROTH_DELAY_TRANCHE_WIDTH_V2 20
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_zeroth_delay_tranche_width_V2_t;

#define PD_CALL_CONFIGURATION_SET_NEEDED_APPROVALS_V2 21
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_needed_approvals_V2_t;

#define PD_CALL_CONFIGURATION_SET_RELAY_VRF_MODULO_SAMPLES_V2 22
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_relay_vrf_modulo_samples_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_COUNT_V2 23
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_count_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_QUEUE_SIZE_V2 24
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_queue_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_DOWNWARD_MESSAGE_SIZE_V2 25
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_downward_message_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_SIZE_V2 27
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE_V2 28
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_max_upward_message_num_per_candidate_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_OPEN_REQUEST_TTL_V2 29
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_open_request_ttl_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_SENDER_DEPOSIT_V2 30
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_sender_deposit_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_RECIPIENT_DEPOSIT_V2 31
typedef struct {
    pd_Balance_t new_;
} pd_configuration_set_hrmp_recipient_deposit_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_CAPACITY_V2 32
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_capacity_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE_V2 33
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_total_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS_V2 34
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_inbound_channels_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS_V2 35
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_inbound_channels_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE_V2 36
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_channel_max_message_size_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS_V2 37
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parachain_outbound_channels_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS_V2 38
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_parathread_outbound_channels_V2_t;

#define PD_CALL_CONFIGURATION_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE_V2 39
typedef struct {
    pd_u32_t new_;
} pd_configuration_set_hrmp_max_message_num_per_candidate_V2_t;

#define PD_CALL_CONFIGURATION_SET_PVF_CHECKING_ENABLED_V2 41
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_pvf_checking_enabled_V2_t;

#define PD_CALL_CONFIGURATION_SET_PVF_VOTING_TTL_V2 42
typedef struct {
    pd_SessionIndex_t new_;
} pd_configuration_set_pvf_voting_ttl_V2_t;

#define PD_CALL_CONFIGURATION_SET_MINIMUM_VALIDATION_UPGRADE_DELAY_V2 43
typedef struct {
    pd_BlockNumber_t new_;
} pd_configuration_set_minimum_validation_upgrade_delay_V2_t;

#define PD_CALL_CONFIGURATION_SET_BYPASS_CONSISTENCY_CHECK_V2 44
typedef struct {
    pd_bool_t new_;
} pd_configuration_set_bypass_consistency_check_V2_t;

#define PD_CALL_INITIALIZER_FORCE_APPROVE_V2 0
typedef struct {
    pd_BlockNumber_t up_to;
} pd_initializer_force_approve_V2_t;

#define PD_CALL_PARASDISPUTES_FORCE_UNFREEZE_V2 0
typedef struct {
} pd_parasdisputes_force_unfreeze_V2_t;

#define PD_CALL_AUCTIONS_NEW_AUCTION_V2 0
typedef struct {
    pd_Compactu32_t duration;
    pd_Compactu32_t lease_period_index;
} pd_auctions_new_auction_V2_t;

#define PD_CALL_AUCTIONS_BID_V2 1
typedef struct {
    pd_Compactu32_t para;
    pd_Compactu32_t auction_index;
    pd_Compactu32_t first_slot;
    pd_Compactu32_t last_slot;
    pd_CompactBalance_t amount;
} pd_auctions_bid_V2_t;

#define PD_CALL_AUCTIONS_CANCEL_AUCTION_V2 2
typedef struct {
} pd_auctions_cancel_auction_V2_t;

#endif

typedef union {
    pd_balances_transfer_all_V2_t balances_transfer_all_V2;
    pd_balances_transfer_allow_death_V2_t balances_transfer_allow_death_V2;
    pd_balances_force_transfer_V2_t balances_force_transfer_V2;
    pd_balances_transfer_keep_alive_V2_t balances_transfer_keep_alive_V2;
    pd_balances_transfer_V2_t balances_transfer_V2;
    pd_crowdloan_create_V2_t crowdloan_create_V2;
    pd_crowdloan_contribute_V2_t crowdloan_contribute_V2;
    pd_crowdloan_withdraw_V2_t crowdloan_withdraw_V2;
    pd_crowdloan_refund_V2_t crowdloan_refund_V2;
    pd_crowdloan_dissolve_V2_t crowdloan_dissolve_V2;
    pd_crowdloan_edit_V2_t crowdloan_edit_V2;
    pd_crowdloan_add_memo_V2_t crowdloan_add_memo_V2;
    pd_crowdloan_poke_V2_t crowdloan_poke_V2;
    pd_crowdloan_contribute_all_V2_t crowdloan_contribute_all_V2;
    pd_multitokens_create_collection_V2_t multitokens_create_collection_V2;
    pd_multitokens_destroy_collection_V2_t multitokens_destroy_collection_V2;
    pd_multitokens_mutate_collection_V2_t multitokens_mutate_collection_V2;
    pd_multitokens_burn_V2_t multitokens_burn_V2;
    pd_multitokens_transfer_V2_t multitokens_transfer_V2;
    pd_multitokens_freeze_V2_t multitokens_freeze_V2;
    pd_multitokens_thaw_V2_t multitokens_thaw_V2;
    pd_multitokens_set_attribute_V2_t multitokens_set_attribute_V2;
    pd_multitokens_remove_attribute_V2_t multitokens_remove_attribute_V2;
    pd_multitokens_remove_all_attributes_V2_t multitokens_remove_all_attributes_V2;
    pd_multitokens_batch_transfer_V2_t multitokens_batch_transfer_V2;
    pd_multitokens_batch_set_attribute_V2_t multitokens_batch_set_attribute_V2;
    pd_multitokens_approve_collection_V2_t multitokens_approve_collection_V2;
    pd_multitokens_unapprove_collection_V2_t multitokens_unapprove_collection_V2;
    pd_multitokens_approve_token_V2_t multitokens_approve_token_V2;
    pd_multitokens_unapprove_token_V2_t multitokens_unapprove_token_V2;
    pd_multitokens_claim_collections_V2_t multitokens_claim_collections_V2;
    pd_multitokens_claim_tokens_V2_t multitokens_claim_tokens_V2;
    pd_nominationpools_bond_V2_t nominationpools_bond_V2;
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
    pd_nominationpools_payout_rewards_V2_t nominationpools_payout_rewards_V2;
    pd_nominationpools_queue_early_bird_bonus_V2_t nominationpools_queue_early_bird_bonus_V2;
    pd_nominationpools_withdraw_unbonded_V2_t nominationpools_withdraw_unbonded_V2;
    pd_nominationpools_distribute_early_bird_bonus_V2_t nominationpools_distribute_early_bird_bonus_V2;
    pd_nominationpools_mutate_V2_t nominationpools_mutate_V2;
    pd_session_set_keys_V2_t session_set_keys_V2;
    pd_session_purge_keys_V2_t session_purge_keys_V2;
    pd_stakeexchange_add_liquidity_V2_t stakeexchange_add_liquidity_V2;
    pd_stakeexchange_buy_V2_t stakeexchange_buy_V2;
    pd_stakeexchange_cancel_offer_V2_t stakeexchange_cancel_offer_V2;
    pd_stakeexchange_configure_liquidity_account_V2_t stakeexchange_configure_liquidity_account_V2;
    pd_stakeexchange_create_offer_V2_t stakeexchange_create_offer_V2;
    pd_stakeexchange_withdraw_liquidity_V2_t stakeexchange_withdraw_liquidity_V2;
    pd_staking_validate_V2_t staking_validate_V2;
    pd_staking_payout_stakers_V2_t staking_payout_stakers_V2;
    pd_utility_batch_V2_t utility_batch_V2;
    pd_utility_batch_all_V2_t utility_batch_all_V2;
    pd_utility_force_batch_V2_t utility_force_batch_V2;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_balances_force_unreserve_V2_t balances_force_unreserve_V2;
    pd_balances_upgrade_accounts_V2_t balances_upgrade_accounts_V2;
    pd_balances_force_set_balance_V2_t balances_force_set_balance_V2;
    pd_multitokens_mutate_token_V2_t multitokens_mutate_token_V2;
    pd_multitokens_mint_V2_t multitokens_mint_V2;
    pd_multitokens_batch_mint_V2_t multitokens_batch_mint_V2;
    pd_multitokens_force_mutate_collection_V2_t multitokens_force_mutate_collection_V2;
    pd_multitokens_force_transfer_V2_t multitokens_force_transfer_V2;
    pd_multitokens_force_set_collection_V2_t multitokens_force_set_collection_V2;
    pd_multitokens_force_set_token_V2_t multitokens_force_set_token_V2;
    pd_multitokens_force_set_attribute_V2_t multitokens_force_set_attribute_V2;
    pd_multitokens_force_set_collection_account_V2_t multitokens_force_set_collection_account_V2;
    pd_multitokens_force_set_token_account_V2_t multitokens_force_set_token_account_V2;
    pd_multitokens_force_create_collection_V2_t multitokens_force_create_collection_V2;
    pd_multitokens_force_mint_V2_t multitokens_force_mint_V2;
    pd_multitokens_force_burn_V2_t multitokens_force_burn_V2;
    pd_multitokens_force_approve_collection_V2_t multitokens_force_approve_collection_V2;
    pd_multitokens_force_freeze_V2_t multitokens_force_freeze_V2;
    pd_multitokens_force_set_next_collection_id_V2_t multitokens_force_set_next_collection_id_V2;
    pd_xcmpallet_teleport_assets_V2_t xcmpallet_teleport_assets_V2;
    pd_xcmpallet_reserve_transfer_assets_V2_t xcmpallet_reserve_transfer_assets_V2;
    pd_xcmpallet_limited_reserve_transfer_assets_V2_t xcmpallet_limited_reserve_transfer_assets_V2;
    pd_xcmpallet_limited_teleport_assets_V2_t xcmpallet_limited_teleport_assets_V2;
#endif
    pd_auctions_new_auction_V2_t auctions_new_auction_V2;
    pd_auctions_bid_V2_t auctions_bid_V2;
    pd_auctions_cancel_auction_V2_t auctions_cancel_auction_V2;
    pd_bounties_propose_bounty_V2_t bounties_propose_bounty_V2;
    pd_bounties_approve_bounty_V2_t bounties_approve_bounty_V2;
    pd_bounties_propose_curator_V2_t bounties_propose_curator_V2;
    pd_bounties_unassign_curator_V2_t bounties_unassign_curator_V2;
    pd_bounties_accept_curator_V2_t bounties_accept_curator_V2;
    pd_bounties_award_bounty_V2_t bounties_award_bounty_V2;
    pd_bounties_claim_bounty_V2_t bounties_claim_bounty_V2;
    pd_bounties_close_bounty_V2_t bounties_close_bounty_V2;
    pd_bounties_extend_bounty_expiry_V2_t bounties_extend_bounty_expiry_V2;
    pd_childbounties_add_child_bounty_V2_t childbounties_add_child_bounty_V2;
    pd_childbounties_propose_curator_V2_t childbounties_propose_curator_V2;
    pd_childbounties_accept_curator_V2_t childbounties_accept_curator_V2;
    pd_childbounties_unassign_curator_V2_t childbounties_unassign_curator_V2;
    pd_childbounties_award_child_bounty_V2_t childbounties_award_child_bounty_V2;
    pd_childbounties_claim_child_bounty_V2_t childbounties_claim_child_bounty_V2;
    pd_childbounties_close_child_bounty_V2_t childbounties_close_child_bounty_V2;
    pd_claims_claim_V2_t claims_claim_V2;
    pd_claims_claim_attest_V2_t claims_claim_attest_V2;
    pd_claims_attest_V2_t claims_attest_V2;
    pd_claims_move_claim_V2_t claims_move_claim_V2;
    pd_configuration_set_validation_upgrade_cooldown_V2_t configuration_set_validation_upgrade_cooldown_V2;
    pd_configuration_set_validation_upgrade_delay_V2_t configuration_set_validation_upgrade_delay_V2;
    pd_configuration_set_code_retention_period_V2_t configuration_set_code_retention_period_V2;
    pd_configuration_set_max_code_size_V2_t configuration_set_max_code_size_V2;
    pd_configuration_set_max_pov_size_V2_t configuration_set_max_pov_size_V2;
    pd_configuration_set_max_head_data_size_V2_t configuration_set_max_head_data_size_V2;
    pd_configuration_set_parathread_cores_V2_t configuration_set_parathread_cores_V2;
    pd_configuration_set_parathread_retries_V2_t configuration_set_parathread_retries_V2;
    pd_configuration_set_group_rotation_frequency_V2_t configuration_set_group_rotation_frequency_V2;
    pd_configuration_set_chain_availability_period_V2_t configuration_set_chain_availability_period_V2;
    pd_configuration_set_thread_availability_period_V2_t configuration_set_thread_availability_period_V2;
    pd_configuration_set_scheduling_lookahead_V2_t configuration_set_scheduling_lookahead_V2;
    pd_configuration_set_max_validators_per_core_V2_t configuration_set_max_validators_per_core_V2;
    pd_configuration_set_max_validators_V2_t configuration_set_max_validators_V2;
    pd_configuration_set_dispute_post_conclusion_acceptance_period_V2_t configuration_set_dispute_post_conclusion_acceptance_period_V2;
    pd_configuration_set_no_show_slots_V2_t configuration_set_no_show_slots_V2;
    pd_configuration_set_n_delay_tranches_V2_t configuration_set_n_delay_tranches_V2;
    pd_configuration_set_zeroth_delay_tranche_width_V2_t configuration_set_zeroth_delay_tranche_width_V2;
    pd_configuration_set_needed_approvals_V2_t configuration_set_needed_approvals_V2;
    pd_configuration_set_relay_vrf_modulo_samples_V2_t configuration_set_relay_vrf_modulo_samples_V2;
    pd_configuration_set_max_upward_queue_count_V2_t configuration_set_max_upward_queue_count_V2;
    pd_configuration_set_max_upward_queue_size_V2_t configuration_set_max_upward_queue_size_V2;
    pd_configuration_set_max_downward_message_size_V2_t configuration_set_max_downward_message_size_V2;
    pd_configuration_set_max_upward_message_size_V2_t configuration_set_max_upward_message_size_V2;
    pd_configuration_set_max_upward_message_num_per_candidate_V2_t configuration_set_max_upward_message_num_per_candidate_V2;
    pd_configuration_set_hrmp_open_request_ttl_V2_t configuration_set_hrmp_open_request_ttl_V2;
    pd_configuration_set_hrmp_sender_deposit_V2_t configuration_set_hrmp_sender_deposit_V2;
    pd_configuration_set_hrmp_recipient_deposit_V2_t configuration_set_hrmp_recipient_deposit_V2;
    pd_configuration_set_hrmp_channel_max_capacity_V2_t configuration_set_hrmp_channel_max_capacity_V2;
    pd_configuration_set_hrmp_channel_max_total_size_V2_t configuration_set_hrmp_channel_max_total_size_V2;
    pd_configuration_set_hrmp_max_parachain_inbound_channels_V2_t configuration_set_hrmp_max_parachain_inbound_channels_V2;
    pd_configuration_set_hrmp_max_parathread_inbound_channels_V2_t configuration_set_hrmp_max_parathread_inbound_channels_V2;
    pd_configuration_set_hrmp_channel_max_message_size_V2_t configuration_set_hrmp_channel_max_message_size_V2;
    pd_configuration_set_hrmp_max_parachain_outbound_channels_V2_t configuration_set_hrmp_max_parachain_outbound_channels_V2;
    pd_configuration_set_hrmp_max_parathread_outbound_channels_V2_t configuration_set_hrmp_max_parathread_outbound_channels_V2;
    pd_configuration_set_hrmp_max_message_num_per_candidate_V2_t configuration_set_hrmp_max_message_num_per_candidate_V2;
    pd_configuration_set_pvf_checking_enabled_V2_t configuration_set_pvf_checking_enabled_V2;
    pd_configuration_set_pvf_voting_ttl_V2_t configuration_set_pvf_voting_ttl_V2;
    pd_configuration_set_minimum_validation_upgrade_delay_V2_t configuration_set_minimum_validation_upgrade_delay_V2;
    pd_configuration_set_bypass_consistency_check_V2_t configuration_set_bypass_consistency_check_V2;
    pd_council_set_members_V2_t council_set_members_V2;
    pd_council_execute_V2_t council_execute_V2;
    pd_council_propose_V2_t council_propose_V2;
    pd_council_vote_V2_t council_vote_V2;
    pd_council_disapprove_proposal_V2_t council_disapprove_proposal_V2;
    pd_council_close_V2_t council_close_V2;
    pd_democracy_blacklist_V2_t democracy_blacklist_V2;
    pd_democracy_set_metadata_V2_t democracy_set_metadata_V2;
    pd_fastunstake_control_V2_t fastunstake_control_V2;
    pd_identity_add_registrar_V2_t identity_add_registrar_V2;
    pd_identity_set_identity_V2_t identity_set_identity_V2;
    pd_identity_set_subs_V2_t identity_set_subs_V2;
    pd_identity_clear_identity_V2_t identity_clear_identity_V2;
    pd_identity_request_judgement_V2_t identity_request_judgement_V2;
    pd_identity_cancel_request_V2_t identity_cancel_request_V2;
    pd_identity_set_fee_V2_t identity_set_fee_V2;
    pd_identity_set_account_id_V2_t identity_set_account_id_V2;
    pd_identity_provide_judgement_V2_t identity_provide_judgement_V2;
    pd_identity_kill_identity_V2_t identity_kill_identity_V2;
    pd_identity_add_sub_V2_t identity_add_sub_V2;
    pd_identity_rename_sub_V2_t identity_rename_sub_V2;
    pd_identity_remove_sub_V2_t identity_remove_sub_V2;
    pd_identity_quit_sub_V2_t identity_quit_sub_V2;
    pd_indices_claim_V2_t indices_claim_V2;
    pd_indices_transfer_V2_t indices_transfer_V2;
    pd_indices_free_V2_t indices_free_V2;
    pd_indices_force_transfer_V2_t indices_force_transfer_V2;
    pd_indices_freeze_V2_t indices_freeze_V2;
    pd_initializer_force_approve_V2_t initializer_force_approve_V2;
    pd_nominationpools_set_configs_V2_t nominationpools_set_configs_V2;
    pd_nominationpools_set_staking_info_V2_t nominationpools_set_staking_info_V2;
    pd_nominationpools_create_with_pool_id_V2_t nominationpools_create_with_pool_id_V2;
    pd_nominationpools_bond_extra_other_V2_t nominationpools_bond_extra_other_V2;
    pd_parasdisputes_force_unfreeze_V2_t parasdisputes_force_unfreeze_V2;
    pd_phragmenelection_vote_V2_t phragmenelection_vote_V2;
    pd_phragmenelection_remove_voter_V2_t phragmenelection_remove_voter_V2;
    pd_phragmenelection_submit_candidacy_V2_t phragmenelection_submit_candidacy_V2;
    pd_phragmenelection_remove_member_V2_t phragmenelection_remove_member_V2;
    pd_phragmenelection_clean_defunct_voters_V2_t phragmenelection_clean_defunct_voters_V2;
    pd_preimage_note_preimage_V2_t preimage_note_preimage_V2;
    pd_preimage_unnote_preimage_V2_t preimage_unnote_preimage_V2;
    pd_preimage_request_preimage_V2_t preimage_request_preimage_V2;
    pd_preimage_unrequest_preimage_V2_t preimage_unrequest_preimage_V2;
    pd_proxy_remove_proxies_V2_t proxy_remove_proxies_V2;
    pd_proxy_proxy_announced_V2_t proxy_proxy_announced_V2;
    pd_referenda_submit_V2_t referenda_submit_V2;
    pd_referenda_place_decision_deposit_V2_t referenda_place_decision_deposit_V2;
    pd_referenda_refund_decision_deposit_V2_t referenda_refund_decision_deposit_V2;
    pd_referenda_cancel_V2_t referenda_cancel_V2;
    pd_referenda_kill_V2_t referenda_kill_V2;
    pd_referenda_nudge_referendum_V2_t referenda_nudge_referendum_V2;
    pd_referenda_one_fewer_deciding_V2_t referenda_one_fewer_deciding_V2;
    pd_referenda_refund_submission_deposit_V2_t referenda_refund_submission_deposit_V2;
    pd_referenda_set_metadata_V2_t referenda_set_metadata_V2;
    pd_staking_kick_V2_t staking_kick_V2;
    pd_staking_set_staking_configs_V2_t staking_set_staking_configs_V2;
    pd_staking_chill_other_V2_t staking_chill_other_V2;
    pd_staking_force_apply_min_commission_V2_t staking_force_apply_min_commission_V2;
    pd_staking_set_min_commission_V2_t staking_set_min_commission_V2;
    pd_staking_bond_V2_t staking_bond_V2;
    pd_staking_bond_extra_V2_t staking_bond_extra_V2;
    pd_staking_unbond_V2_t staking_unbond_V2;
    pd_staking_withdraw_unbonded_V2_t staking_withdraw_unbonded_V2;
    pd_staking_nominate_V2_t staking_nominate_V2;
    pd_staking_chill_V2_t staking_chill_V2;
    pd_staking_set_payee_V2_t staking_set_payee_V2;
    pd_staking_set_controller_V2_t staking_set_controller_V2;
    pd_staking_rebond_V2_t staking_rebond_V2;
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
    pd_technicalcommittee_set_members_V2_t technicalcommittee_set_members_V2;
    pd_technicalcommittee_execute_V2_t technicalcommittee_execute_V2;
    pd_technicalcommittee_propose_V2_t technicalcommittee_propose_V2;
    pd_technicalcommittee_vote_V2_t technicalcommittee_vote_V2;
    pd_technicalcommittee_disapprove_proposal_V2_t technicalcommittee_disapprove_proposal_V2;
    pd_technicalcommittee_close_V2_t technicalcommittee_close_V2;
    pd_technicalmembership_add_member_V2_t technicalmembership_add_member_V2;
    pd_technicalmembership_remove_member_V2_t technicalmembership_remove_member_V2;
    pd_technicalmembership_swap_member_V2_t technicalmembership_swap_member_V2;
    pd_technicalmembership_reset_members_V2_t technicalmembership_reset_members_V2;
    pd_technicalmembership_change_key_V2_t technicalmembership_change_key_V2;
    pd_technicalmembership_set_prime_V2_t technicalmembership_set_prime_V2;
    pd_technicalmembership_clear_prime_V2_t technicalmembership_clear_prime_V2;
    pd_tips_report_awesome_V2_t tips_report_awesome_V2;
    pd_tips_retract_tip_V2_t tips_retract_tip_V2;
    pd_tips_tip_new_V2_t tips_tip_new_V2;
    pd_tips_tip_V2_t tips_tip_V2;
    pd_tips_close_tip_V2_t tips_close_tip_V2;
    pd_tips_slash_tip_V2_t tips_slash_tip_V2;
    pd_treasury_propose_spend_V2_t treasury_propose_spend_V2;
    pd_treasury_reject_proposal_V2_t treasury_reject_proposal_V2;
    pd_treasury_approve_proposal_V2_t treasury_approve_proposal_V2;
    pd_treasury_spend_V2_t treasury_spend_V2;
    pd_treasury_remove_approval_V2_t treasury_remove_approval_V2;
    pd_timestamp_set_V2_t timestamp_set_V2;
    pd_utility_with_weight_V2_t utility_with_weight_V2;
    pd_vesting_vest_V2_t vesting_vest_V2;
    pd_vesting_vest_other_V2_t vesting_vest_other_V2;
    pd_vesting_vested_transfer_V2_t vesting_vested_transfer_V2;
    pd_vesting_force_vested_transfer_V2_t vesting_force_vested_transfer_V2;
    pd_vesting_merge_schedules_V2_t vesting_merge_schedules_V2;
    pd_voterlist_rebag_V2_t voterlist_rebag_V2;
    pd_voterlist_put_in_front_of_V2_t voterlist_put_in_front_of_V2;
    pd_whitelist_whitelist_call_V2_t whitelist_whitelist_call_V2;
    pd_whitelist_remove_whitelisted_call_V2_t whitelist_remove_whitelisted_call_V2;
    pd_whitelist_dispatch_whitelisted_call_V2_t whitelist_dispatch_whitelisted_call_V2;
    pd_whitelist_dispatch_whitelisted_call_with_preimage_V2_t whitelist_dispatch_whitelisted_call_with_preimage_V2;
#endif
} pd_MethodBasic_V2_t;



#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V2 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V2_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V2 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V2_t;

#define PD_CALL_SYSTEM_SET_CODE_V2 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V2_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V2 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V2_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V2 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V2_t;

#define PD_CALL_BALANCES_SET_BALANCE_DEPRECATED_V2 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t old_reserved;
} pd_balances_set_balance_deprecated_V2_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V2 0
typedef struct {
    pd_BoundedCallOfT_t proposal;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V2_t;

#define PD_CALL_DEMOCRACY_SECOND_V2 1
typedef struct {
    pd_Compactu32_t proposal;
} pd_democracy_second_V2_t;

#define PD_CALL_DEMOCRACY_VOTE_V2 2
typedef struct {
    pd_Compactu32_t ref_index;
    pd_AccountVote_t vote;
} pd_democracy_vote_V2_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V2 3
typedef struct {
    pd_ReferendumIndex_t ref_index;
} pd_democracy_emergency_cancel_V2_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V2 4
typedef struct {
    pd_BoundedCallOfT_t proposal;
} pd_democracy_external_propose_V2_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V2 5
typedef struct {
    pd_BoundedCallOfT_t proposal;
} pd_democracy_external_propose_majority_V2_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V2 6
typedef struct {
    pd_BoundedCallOfT_t proposal;
} pd_democracy_external_propose_default_V2_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V2 7
typedef struct {
    pd_H256_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V2_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V2 8
typedef struct {
    pd_H256_t proposal_hash;
} pd_democracy_veto_external_V2_t;

#define PD_CALL_DEMOCRACY_CANCEL_REFERENDUM_V2 9
typedef struct {
    pd_Compactu32_t ref_index;
} pd_democracy_cancel_referendum_V2_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V2 10
typedef struct {
    pd_AccountIdLookupOfT_t to;
    pd_Conviction_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V2_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V2 11
typedef struct {
} pd_democracy_undelegate_V2_t;

#define PD_CALL_DEMOCRACY_CLEAR_PUBLIC_PROPOSALS_V2 12
typedef struct {
} pd_democracy_clear_public_proposals_V2_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V2 13
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_democracy_unlock_V2_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V2 14
typedef struct {
    pd_ReferendumIndex_t index;
} pd_democracy_remove_vote_V2_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V2 15
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_ReferendumIndex_t index;
} pd_democracy_remove_other_vote_V2_t;

#define PD_CALL_DEMOCRACY_CANCEL_PROPOSAL_V2 17
typedef struct {
    pd_Compactu32_t prop_index;
} pd_democracy_cancel_proposal_V2_t;

#define PD_CALL_CONVICTIONVOTING_VOTE_V2 0
typedef struct {
    pd_Compactu32_t poll_index;
    pd_AccountVote_t vote;
} pd_convictionvoting_vote_V2_t;

#define PD_CALL_CONVICTIONVOTING_DELEGATE_V2 1
typedef struct {
    pd_ClassOf_t class_;
    pd_AccountIdLookupOfT_t to;
    pd_Conviction_t conviction;
    pd_BalanceOf_t balance;
} pd_convictionvoting_delegate_V2_t;

#define PD_CALL_CONVICTIONVOTING_UNDELEGATE_V2 2
typedef struct {
    pd_ClassOf_t class_;
} pd_convictionvoting_undelegate_V2_t;

#define PD_CALL_CONVICTIONVOTING_UNLOCK_V2 3
typedef struct {
    pd_ClassOf_t class_;
    pd_AccountIdLookupOfT_t target;
} pd_convictionvoting_unlock_V2_t;

#define PD_CALL_CONVICTIONVOTING_REMOVE_VOTE_V2 4
typedef struct {
    pd_OptionClassOf_t class_;
    pd_PollIndexOf_t index;
} pd_convictionvoting_remove_vote_V2_t;

#define PD_CALL_CONVICTIONVOTING_REMOVE_OTHER_VOTE_V2 5
typedef struct {
    pd_AccountIdLookupOfT_t target;
    pd_ClassOf_t class_;
    pd_PollIndexOf_t index;
} pd_convictionvoting_remove_other_vote_V2_t;

#define PD_CALL_PROXY_PROXY_V2 0
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V2_t;

#define PD_CALL_PROXY_ADD_PROXY_V2 1
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V2_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V2 2
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V2_t;

#define PD_CALL_PROXY_CREATE_PURE_V2 4
typedef struct {
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_create_pure_V2_t;

#define PD_CALL_PROXY_KILL_PURE_V2 5
typedef struct {
    pd_AccountIdLookupOfT_t spawner;
    pd_ProxyType_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_pure_V2_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V2 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V2_t;

#define PD_CALL_MULTISIG_AS_MULTI_V2 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V2_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V2 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V2_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V2 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V2_t;

#define PD_CALL_NOMINATIONPOOLS_JOIN_V2 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_PoolId_t pool_id;
} pd_nominationpools_join_V2_t;

#define PD_CALL_NOMINATIONPOOLS_BOND_EXTRA_V2 1
typedef struct {
    pd_BondExtraBalanceOfT_t extra;
} pd_nominationpools_bond_extra_V2_t;

#define PD_CALL_NOMINATIONPOOLS_CLAIM_PAYOUT_V2 2
typedef struct {
} pd_nominationpools_claim_payout_V2_t;

#define PD_CALL_NOMINATIONPOOLS_SET_STATE_V2 9
typedef struct {
    pd_PoolId_t pool_id;
    pd_PoolState_t state;
} pd_nominationpools_set_state_V2_t;

#define PD_CALL_NOMINATIONPOOLS_SET_METADATA_V2 10
typedef struct {
    pd_PoolId_t pool_id;
    pd_Vecu8_t metadata;
} pd_nominationpools_set_metadata_V2_t;

#define PD_CALL_NOMINATIONPOOLS_UPDATE_ROLES_V2 12
typedef struct {
    pd_PoolId_t pool_id;
    pd_ConfigOpAccountId_t new_root;
    pd_ConfigOpAccountId_t new_nominator;
    pd_ConfigOpAccountId_t new_bouncer;
} pd_nominationpools_update_roles_V2_t;

#define PD_CALL_NOMINATIONPOOLS_SET_CLAIM_PERMISSION_V2 15
typedef struct {
    pd_ClaimPermission_t permission;
} pd_nominationpools_set_claim_permission_V2_t;

#define PD_CALL_FASTUNSTAKE_REGISTER_FAST_UNSTAKE_V2 0
typedef struct {
} pd_fastunstake_register_fast_unstake_V2_t;

#define PD_CALL_FASTUNSTAKE_DEREGISTER_V2 1
typedef struct {
} pd_fastunstake_deregister_V2_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V2_t balances_transfer_allow_death_V2;
    pd_balances_force_transfer_V2_t balances_force_transfer_V2;
    pd_balances_transfer_keep_alive_V2_t balances_transfer_keep_alive_V2;
    pd_balances_transfer_V2_t balances_transfer_V2;
    pd_staking_bond_V2_t staking_bond_V2;
    pd_staking_bond_extra_V2_t staking_bond_extra_V2;
    pd_staking_unbond_V2_t staking_unbond_V2;
    pd_staking_withdraw_unbonded_V2_t staking_withdraw_unbonded_V2;
    pd_staking_nominate_V2_t staking_nominate_V2;
    pd_staking_chill_V2_t staking_chill_V2;
    pd_staking_set_payee_V2_t staking_set_payee_V2;
    pd_staking_set_controller_V2_t staking_set_controller_V2;
    pd_staking_rebond_V2_t staking_rebond_V2;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_balances_set_balance_deprecated_V2_t balances_set_balance_deprecated_V2;
    pd_convictionvoting_vote_V2_t convictionvoting_vote_V2;
    pd_convictionvoting_delegate_V2_t convictionvoting_delegate_V2;
    pd_convictionvoting_undelegate_V2_t convictionvoting_undelegate_V2;
    pd_convictionvoting_unlock_V2_t convictionvoting_unlock_V2;
    pd_convictionvoting_remove_vote_V2_t convictionvoting_remove_vote_V2;
    pd_convictionvoting_remove_other_vote_V2_t convictionvoting_remove_other_vote_V2;
    pd_democracy_propose_V2_t democracy_propose_V2;
    pd_democracy_second_V2_t democracy_second_V2;
    pd_democracy_vote_V2_t democracy_vote_V2;
    pd_democracy_emergency_cancel_V2_t democracy_emergency_cancel_V2;
    pd_democracy_external_propose_V2_t democracy_external_propose_V2;
    pd_democracy_external_propose_majority_V2_t democracy_external_propose_majority_V2;
    pd_democracy_external_propose_default_V2_t democracy_external_propose_default_V2;
    pd_democracy_fast_track_V2_t democracy_fast_track_V2;
    pd_democracy_veto_external_V2_t democracy_veto_external_V2;
    pd_democracy_cancel_referendum_V2_t democracy_cancel_referendum_V2;
    pd_democracy_delegate_V2_t democracy_delegate_V2;
    pd_democracy_undelegate_V2_t democracy_undelegate_V2;
    pd_democracy_clear_public_proposals_V2_t democracy_clear_public_proposals_V2;
    pd_democracy_unlock_V2_t democracy_unlock_V2;
    pd_democracy_remove_vote_V2_t democracy_remove_vote_V2;
    pd_democracy_remove_other_vote_V2_t democracy_remove_other_vote_V2;
    pd_democracy_cancel_proposal_V2_t democracy_cancel_proposal_V2;
    pd_fastunstake_register_fast_unstake_V2_t fastunstake_register_fast_unstake_V2;
    pd_fastunstake_deregister_V2_t fastunstake_deregister_V2;
    pd_multisig_as_multi_threshold_1_V2_t multisig_as_multi_threshold_1_V2;
    pd_multisig_as_multi_V2_t multisig_as_multi_V2;
    pd_multisig_approve_as_multi_V2_t multisig_approve_as_multi_V2;
    pd_multisig_cancel_as_multi_V2_t multisig_cancel_as_multi_V2;
    pd_nominationpools_join_V2_t nominationpools_join_V2;
    pd_nominationpools_bond_extra_V2_t nominationpools_bond_extra_V2;
    pd_nominationpools_claim_payout_V2_t nominationpools_claim_payout_V2;
    pd_nominationpools_unbond_V2_t nominationpools_unbond_V2;
    pd_nominationpools_withdraw_unbonded_V2_t nominationpools_withdraw_unbonded_V2;
    pd_nominationpools_create_V2_t nominationpools_create_V2;
    pd_nominationpools_nominate_V2_t nominationpools_nominate_V2;
    pd_nominationpools_set_state_V2_t nominationpools_set_state_V2;
    pd_nominationpools_set_metadata_V2_t nominationpools_set_metadata_V2;
    pd_nominationpools_update_roles_V2_t nominationpools_update_roles_V2;
    pd_nominationpools_chill_V2_t nominationpools_chill_V2;
    pd_nominationpools_set_claim_permission_V2_t nominationpools_set_claim_permission_V2;
    pd_nominationpools_claim_payout_other_V2_t nominationpools_claim_payout_other_V2;
    pd_nominationpools_set_commission_V2_t nominationpools_set_commission_V2;
    pd_nominationpools_set_commission_max_V2_t nominationpools_set_commission_max_V2;
    pd_nominationpools_set_commission_change_rate_V2_t nominationpools_set_commission_change_rate_V2;
    pd_nominationpools_claim_commission_V2_t nominationpools_claim_commission_V2;
    pd_proxy_proxy_V2_t proxy_proxy_V2;
    pd_proxy_add_proxy_V2_t proxy_add_proxy_V2;
    pd_proxy_remove_proxy_V2_t proxy_remove_proxy_V2;
    pd_proxy_create_pure_V2_t proxy_create_pure_V2;
    pd_proxy_kill_pure_V2_t proxy_kill_pure_V2;
    pd_system_remark_V2_t system_remark_V2;
    pd_system_set_heap_pages_V2_t system_set_heap_pages_V2;
    pd_system_set_code_V2_t system_set_code_V2;
    pd_system_set_code_without_checks_V2_t system_set_code_without_checks_V2;
    pd_system_remark_with_event_V2_t system_remark_with_event_V2;
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
