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

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V2(
        parser_context_t* c, pd_balances_transfer_allow_death_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
        parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(
        parser_context_t* c, pd_balances_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V2(
        parser_context_t* c, pd_balances_transfer_all_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(
        parser_context_t* c, pd_balances_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_approve_collection_V2(
        parser_context_t* c, pd_multitokens_approve_collection_V2_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_approve_token_V2(
        parser_context_t* c, pd_multitokens_approve_token_V2_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    CHECK_ERROR(_readCompactBalance(c, &m->current_amount))
    return parser_ok;
}

//__Z_INLINE parser_error_t _readMethod_multitokens_batch_mint_V2(
//        parser_context_t* c, pd_multitokens_batch_mint_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_batch_set_attribute_V2(
//        parser_context_t* c, pd_multitokens_batch_set_attribute_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_batch_transfer_V2(
//        parser_context_t* c, pd_multitokens_batch_transfer_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_burn_V2(
//        parser_context_t* c, pd_multitokens_burn_V2_t* m)
//{
//    return parser_ok;
//}

__Z_INLINE parser_error_t _readMethod_multitokens_claim_collections_V2(
        parser_context_t* c, pd_multitokens_claim_collections_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_claim_tokens_V2(
        parser_context_t* c, pd_multitokens_claim_tokens_V2_t* m)
{
    return parser_ok;
}

//__Z_INLINE parser_error_t _readMethod_multitokens_create_collection_V2(
//        parser_context_t* c, pd_multitokens_create_collection_V2_t* m)
//{
//    return parser_ok;
//}

__Z_INLINE parser_error_t _readMethod_multitokens_destroy_collection_V2(
        parser_context_t* c, pd_multitokens_destroy_collection_V2_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    return parser_ok;
}

// TODO: Check because is crashing
__Z_INLINE parser_error_t _readMethod_multitokens_force_approve_collection_V2(
        parser_context_t* c, pd_multitokens_force_approve_collection_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->caller))
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    CHECK_ERROR(_readOptionu32(c, &m->expiration))
    return parser_ok;
}

//__Z_INLINE parser_error_t _readMethod_multitokens_force_burn_V2(
//        parser_context_t* c, pd_multitokens_force_burn_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_force_create_collection_V2(
//        parser_context_t* c, pd_multitokens_force_create_collection_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_force_freeze_V2(
//        parser_context_t* c, pd_multitokens_force_freeze_V2_t* m)
//{
//    return parser_ok;
//}

//__Z_INLINE parser_error_t _readMethod_multitokens_force_mint_V2(
//        parser_context_t* c, pd_multitokens_force_mint_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_force_mutate_collection_V2(
//        parser_context_t* c, pd_multitokens_force_mutate_collection_V2_t* m)
//{
//    return parser_ok;
//}

// TODO: Crashing
__Z_INLINE parser_error_t _readMethod_multitokens_force_set_attribute_V2(
        parser_context_t* c, pd_multitokens_force_set_attribute_V2_t* m)
{
     CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
     CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
     CHECK_ERROR(_readBytes(c, &m->key))
     CHECK_ERROR(_readOptionBytes(c, &m->value))
    return parser_ok;
}

//__Z_INLINE parser_error_t _readMethod_multitokens_force_set_collection_V2(
//        parser_context_t* c, pd_multitokens_force_set_collection_V2_t* m)
//{
//    return parser_ok;
//}

//__Z_INLINE parser_error_t _readMethod_multitokens_force_set_collection_account_V2(
//        parser_context_t* c, pd_multitokens_force_set_collection_account_V2_t* m)
//{
//    return parser_ok;
//}

// TODO: Check no more data
__Z_INLINE parser_error_t _readMethod_multitokens_force_set_next_collection_id_V2(
        parser_context_t* c, pd_multitokens_force_set_next_collection_id_V2_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->value))
    return parser_ok;
}

//__Z_INLINE parser_error_t _readMethod_multitokens_force_set_token_V2(
//        parser_context_t* c, pd_multitokens_force_set_token_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_force_set_token_account_V2(
//        parser_context_t* c, pd_multitokens_force_set_token_account_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_force_transfer_V2(
//        parser_context_t* c, pd_multitokens_force_transfer_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_freeze_V2(
//        parser_context_t* c, pd_multitokens_freeze_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_mint_V2(
//        parser_context_t* c, pd_multitokens_mint_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_mutate_collection_V2(
//        parser_context_t* c, pd_multitokens_mutate_collection_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_mutate_token_V2(
//        parser_context_t* c, pd_multitokens_mutate_token_V2_t* m)
//{
//    return parser_ok;
//}

// TODO: Crashing
__Z_INLINE parser_error_t _readMethod_multitokens_remove_all_attributes_V2(
        parser_context_t* c, pd_multitokens_remove_all_attributes_V2_t* m)
{
     CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
     CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
     CHECK_ERROR(_readu32(c, &m->attribute_count))
    return parser_ok;
}

// TODO: Crashing
__Z_INLINE parser_error_t _readMethod_multitokens_remove_attribute_V2(
        parser_context_t* c, pd_multitokens_remove_attribute_V2_t* m)
{
     CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
     CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
     CHECK_ERROR(_readBytes(c, &m->key))
    return parser_ok;
}

// TODO: Crashing
__Z_INLINE parser_error_t _readMethod_multitokens_set_attribute_V2(
        parser_context_t* c, pd_multitokens_set_attribute_V2_t* m)
{
     CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
     CHECK_ERROR(_readOptionTokenId(c, &m->token_id))
     CHECK_ERROR(_readBytes(c, &m->key))
     CHECK_ERROR(_readBytes(c, &m->value))
    return parser_ok;
}

//__Z_INLINE parser_error_t _readMethod_multitokens_thaw_V2(
//        parser_context_t* c, pd_multitokens_thaw_V2_t* m)
//{
//    return parser_ok;
//}
//
//__Z_INLINE parser_error_t _readMethod_multitokens_transfer_V2(
//        parser_context_t* c, pd_multitokens_transfer_V2_t* m)
//{
//    return parser_ok;
//}

__Z_INLINE parser_error_t _readMethod_multitokens_unapprove_collection_V2(
        parser_context_t* c, pd_multitokens_unapprove_collection_V2_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multitokens_unapprove_token_V2(
        parser_context_t* c, pd_multitokens_unapprove_token_V2_t* m)
{
    CHECK_ERROR(_readCompactCollectionId(c, &m->collection_id))
    CHECK_ERROR(_readCompactTokenId(c, &m->token_id))
    CHECK_ERROR(_readAccountId(c, &m->operator_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_V2(
        parser_context_t* c, pd_nominationpools_bond_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readCompactBalance(c, &m->amount)) // TODO: Probably wrong
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_chill_V2(
        parser_context_t* c, pd_nominationpools_chill_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_create_V2(
        parser_context_t* c, pd_nominationpools_create_V2_t* m)
{
    // CHECK_ERROR(_readMultiAssetIdV3(c, &m->token_id))
    // CHECK_ERROR(_readCompactBalance(c, &m->deposit))
    // CHECK_ERROR(_readCompactBalance(c, &m->capacity))
    // CHECK_ERROR(_readEraIndex(c, &m->duration))
    // CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    // CHECK_ERROR(_readAccountIdLookupOfT(c, &m->nominator))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_destroy_V2(
        parser_context_t* c, pd_nominationpools_destroy_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_distribute_early_bird_bonus_V2(
        parser_context_t* c, pd_nominationpools_distribute_early_bird_bonus_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->transfer_count))
    return parser_ok;
}

// __Z_INLINE parser_error_t _readMethod_nominationpools_mutate_V2(
//         parser_context_t* c, pd_nominationpools_mutate_V2_t* m)
// {
//     CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account)) // TODO: Check
//     CHECK_ERROR(_readCompactBalance(c, &m->unbonding_points))
//     return parser_ok;
// }

__Z_INLINE parser_error_t _readMethod_nominationpools_nominate_V2(
        parser_context_t* c, pd_nominationpools_nominate_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readVecAccountId(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_payout_rewards_V2(
        parser_context_t* c, pd_nominationpools_payout_rewards_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_pool_withdraw_unbonded_V2(
        parser_context_t* c, pd_nominationpools_pool_withdraw_unbonded_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_queue_early_bird_bonus_V2(
        parser_context_t* c, pd_nominationpools_queue_early_bird_bonus_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_V2(
        parser_context_t* c, pd_nominationpools_unbond_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readCompactBalance(c, &m->unbonding_points))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_deposit_V2(
        parser_context_t* c, pd_nominationpools_unbond_deposit_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_deposit_V2(
        parser_context_t* c, pd_nominationpools_withdraw_deposit_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_unbonded_V2(
        parser_context_t* c, pd_nominationpools_withdraw_unbonded_V2_t* m)
{
    CHECK_ERROR(_readPoolId(c, &m->pool_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member_account))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_add_liquidity_V2(
        parser_context_t* c, pd_stakeexchange_add_liquidity_V2_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_buy_V2(
        parser_context_t* c, pd_stakeexchange_buy_V2_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readTokenIdOf(c, &m->token_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakeexchange_cancel_offer_V2(
        parser_context_t* c, pd_stakeexchange_cancel_offer_V2_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    return parser_ok;
}

// __Z_INLINE parser_error_t _readMethod_stakeexchange_configure_liquidity_account_V2(
//         parser_context_t* c, pd_stakeexchange_configure_liquidity_account_V2_t* m)
// {
//     CHECK_ERROR(_readAccountIdLookupOfT(c, &m->member))
//     CHECK_ERROR(_readBondExtraBalanceOfT(c, &m->extra))
//     return parser_ok;
// }

// __Z_INLINE parser_error_t _readMethod_stakeexchange_create_offer_V2(
//         parser_context_t* c, pd_stakeexchange_create_offer_V2_t* m)
// {
//     CHECK_ERROR(_readAccountIdLookupOfT(c, &m->offer))
//     return parser_ok;
// }

__Z_INLINE parser_error_t _readMethod_stakeexchange_withdraw_liquidity_V2(
        parser_context_t* c, pd_stakeexchange_withdraw_liquidity_V2_t* m)
{
    CHECK_ERROR(_readOfferId(c, &m->offer_id))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V2(
        parser_context_t* c, pd_balances_force_unreserve_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V2(
        parser_context_t* c, pd_balances_upgrade_accounts_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V2(
        parser_context_t* c, pd_balances_force_set_balance_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V2(
        parser_context_t* c, pd_staking_bond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V2(
        parser_context_t* c, pd_staking_bond_extra_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V2(
        parser_context_t* c, pd_staking_unbond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V2(
        parser_context_t* c, pd_staking_withdraw_unbonded_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V2(
        parser_context_t* c, pd_staking_validate_V2_t* m)
{
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V2(
        parser_context_t* c, pd_staking_nominate_V2_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V2(
        parser_context_t* c, pd_staking_chill_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V2(
        parser_context_t* c, pd_staking_set_payee_V2_t* m)
{
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V2(
        parser_context_t* c, pd_staking_set_controller_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V2(
        parser_context_t* c, pd_staking_payout_stakers_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V2(
        parser_context_t* c, pd_staking_rebond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V2(
        parser_context_t* c, pd_staking_set_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V2(
        parser_context_t* c, pd_staking_increase_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V2(
        parser_context_t* c, pd_staking_scale_validator_count_V2_t* m)
{
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V2(
        parser_context_t* c, pd_staking_force_no_eras_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V2(
        parser_context_t* c, pd_staking_force_new_era_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V2(
        parser_context_t* c, pd_staking_set_invulnerables_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V2(
        parser_context_t* c, pd_staking_force_unstake_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V2(
        parser_context_t* c, pd_staking_force_new_era_always_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V2(
        parser_context_t* c, pd_staking_cancel_deferred_slash_V2_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V2(
        parser_context_t* c, pd_staking_reap_stash_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V2(
        parser_context_t* c, pd_staking_kick_V2_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V2(
        parser_context_t* c, pd_staking_set_staking_configs_V2_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V2(
        parser_context_t* c, pd_staking_chill_other_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V2(
        parser_context_t* c, pd_staking_force_apply_min_commission_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_commission_V2(
        parser_context_t* c, pd_staking_set_min_commission_V2_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

// __Z_INLINE parser_error_t _readMethod_nominationpools_set_staking_info_V2(
//         parser_context_t* c, pd_nominationpools_set_staking_info_V2_t* m)
// {
//     CHECK_ERROR(_readPoolId(c, &m->info)) // TODO: Come back here
//     return parser_ok;
// }

__Z_INLINE parser_error_t _readMethod_nominationpools_set_configs_V2(
        parser_context_t* c, pd_nominationpools_set_configs_V2_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_join_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_create_bond))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->global_max_commission))
    return parser_ok;
}
#endif

parser_error_t _readMethod_V2(
        parser_context_t* c,
        uint8_t moduleIdx,
        uint8_t callIdx,
        pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

        case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V2(c, &method->nested.balances_transfer_allow_death_V2))
            break;
        case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
            break;
        case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V2(c, &method->nested.balances_transfer_keep_alive_V2))
            break;
        case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V2(c, &method->basic.balances_transfer_all_V2))
            break;
        case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
            break;
        case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_nominationpools_bond_V2(c, &method->nested.nominationpools_bond_V2))
            break;
        case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_nominationpools_unbond_V2(c, &method->nested.nominationpools_unbond_V2))
            break;
        case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_nominationpools_pool_withdraw_unbonded_V2(c,
                                                                          &method->nested.nominationpools_pool_withdraw_unbonded_V2))
            break;
        case 4613: /* module 18 call 5 */
        CHECK_ERROR(
                _readMethod_nominationpools_withdraw_unbonded_V2(c, &method->basic.nominationpools_withdraw_unbonded_V2))
            break;
        case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_nominationpools_create_V2(c, &method->nested.nominationpools_create_V2))
            break;
        case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_nominationpools_nominate_V2(c, &method->nested.nominationpools_nominate_V2))
            break;
        case 4621: /* module 18 call 13 */
        CHECK_ERROR(_readMethod_nominationpools_chill_V2(c, &method->nested.nominationpools_chill_V2))
            break;
        case 4622: /* module 18 call 14 */
        CHECK_ERROR(_readMethod_nominationpools_destroy_V2(c, &method->nested.nominationpools_destroy_V2))
            break;
        case 4626: /* module 18 call 18 */
        CHECK_ERROR(_readMethod_nominationpools_payout_rewards_V2(c,
                                                                  &method->basic.nominationpools_payout_rewards_V2))
            break;
        // case 4627: /* module 18 call 19 */
        // CHECK_ERROR(_readMethod_nominationpools_mutate_V2(c, &method->nested.nominationpools_mutate_V2))
        //     break;
        case 4628: /* module 18 call 20 */
        CHECK_ERROR(_readMethod_nominationpools_unbond_deposit_V2(c, &method->nested.nominationpools_unbond_deposit_V2))
            break;
        case 4629: /* module 18 call 21 */
        CHECK_ERROR(_readMethod_nominationpools_withdraw_deposit_V2(c, &method->nested.nominationpools_withdraw_deposit_V2))
            break;
        case 4631: /* module 18 call 23 */
        CHECK_ERROR(_readMethod_nominationpools_queue_early_bird_bonus_V2(c,
                                                                          &method->basic.nominationpools_queue_early_bird_bonus_V2))
            break;
        case 4632: /* module 18 call 24 */
        CHECK_ERROR(_readMethod_nominationpools_distribute_early_bird_bonus_V2(c,
                                                                               &method->basic.nominationpools_distribute_early_bird_bonus_V2))
            break;
        // case 4864: /* module 19 call 0 */
        // CHECK_ERROR(_readMethod_stakeexchange_create_offer_V2(c, &method->basic.stakeexchange_create_offer_V2))
        //     break;
        case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_stakeexchange_cancel_offer_V2(c, &method->basic.stakeexchange_cancel_offer_V2))
            break;
        // case 4866: /* module 19 call 2 */
        // CHECK_ERROR(_readMethod_stakeexchange_configure_liquidity_account_V2(c, &method->basic.stakeexchange_configure_liquidity_account_V2))
        //     break;
        case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_stakeexchange_withdraw_liquidity_V2(c, &method->basic.stakeexchange_withdraw_liquidity_V2))
            break;
        case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_stakeexchange_add_liquidity_V2(c, &method->basic.stakeexchange_add_liquidity_V2))
            break;
        case 4869: /* module 19 call 5 */
        CHECK_ERROR(_readMethod_stakeexchange_buy_V2(c, &method->basic.stakeexchange_buy_V2))
            break;
//        case 64768: /* module 253 call 0 */
//        CHECK_ERROR(_readMethod_multitokens_create_collection_V2(c, &method->basic.multitokens_create_collection_V2))
//            break;
        case 64769: /* module 253 call 1 */
        CHECK_ERROR(_readMethod_multitokens_destroy_collection_V2(c, &method->basic.multitokens_destroy_collection_V2))
            break;
//        case 64770: /* module 253 call 2 */
//        CHECK_ERROR(_readMethod_multitokens_mutate_collection_V2(c, &method->basic.multitokens_mutate_collection_V2))
//            break;
//        case 64771: /* module 253 call 3 */
//        CHECK_ERROR(_readMethod_multitokens_mutate_token_V2(c, &method->basic.multitokens_mutate_token_V2))
//            break;
//        case 64772: /* module 253 call 4 */
//        CHECK_ERROR(_readMethod_multitokens_mint_V2(c, &method->basic.multitokens_mint_V2))
//            break;
//        case 64773: /* module 253 call 5 */
//        CHECK_ERROR(_readMethod_multitokens_burn_V2(c, &method->basic.multitokens_burn_V2))
//            break;
//        case 64774: /* module 253 call 6 */
//        CHECK_ERROR(_readMethod_multitokens_transfer_V2(c, &method->basic.multitokens_transfer_V2))
//            break;
//        case 64775: /* module 253 call 7 */
//        CHECK_ERROR(_readMethod_multitokens_freeze_V2(c, &method->basic.multitokens_freeze_V2))
//            break;
//        case 64776: /* module 253 call 8 */
//        CHECK_ERROR(_readMethod_multitokens_thaw_V2(c, &method->basic.multitokens_thaw_V2))
//            break;
        case 64777: /* module 253 call 9 */
        CHECK_ERROR(_readMethod_multitokens_set_attribute_V2(c, &method->basic.multitokens_set_attribute_V2))
            break;
        case 64778: /* module 253 call 10 */
        CHECK_ERROR(_readMethod_multitokens_remove_attribute_V2(c, &method->basic.multitokens_remove_attribute_V2))
            break;
        case 64779: /* module 253 call 11 */
        CHECK_ERROR(_readMethod_multitokens_remove_all_attributes_V2(c, &method->basic.multitokens_remove_all_attributes_V2))
            break;
//        case 64780: /* module 253 call 12 */
//        CHECK_ERROR(_readMethod_multitokens_batch_transfer_V2(c, &method->basic.multitokens_batch_transfer_V2))
//            break;
//        case 64781: /* module 253 call 13 */
//        CHECK_ERROR(_readMethod_multitokens_batch_mint_V2(c, &method->basic.multitokens_batch_mint_V2))
//            break;
//        case 64782: /* module 253 call 14 */
//        CHECK_ERROR(_readMethod_multitokens_batch_set_attribute_V2(c, &method->basic.multitokens_batch_set_attribute_V2))
//            break;
        case 64783: /* module 253 call 15 */
        CHECK_ERROR(_readMethod_multitokens_approve_collection_V2(c, &method->basic.multitokens_approve_collection_V2))
            break;
        case 64784: /* module 253 call 16 */
        CHECK_ERROR(_readMethod_multitokens_unapprove_collection_V2(c, &method->basic.multitokens_unapprove_collection_V2))
            break;
        case 64785: /* module 253 call 17 */
        CHECK_ERROR(_readMethod_multitokens_approve_token_V2(c, &method->basic.multitokens_approve_token_V2))
            break;
        case 64786: /* module 253 call 18 */
        CHECK_ERROR(_readMethod_multitokens_unapprove_token_V2(c, &method->basic.multitokens_unapprove_token_V2))
            break;
//        case 64787: /* module 253 call 19 */
//        CHECK_ERROR(_readMethod_multitokens_force_mutate_collection_V2(c, &method->basic.multitokens_force_mutate_collection_V2))
//            break;
//        case 64788: /* module 253 call 20 */
//        CHECK_ERROR(_readMethod_multitokens_force_transfer_V2(c, &method->basic.multitokens_force_transfer_V2))
//            break;
//        case 64789: /* module 253 call 21 */
//        CHECK_ERROR(_readMethod_multitokens_force_set_collection_V2(c, &method->basic.multitokens_force_set_collection_V2))
//            break;
//        case 64790: /* module 253 call 22 */
//        CHECK_ERROR(_readMethod_multitokens_force_set_token_V2(c, &method->basic.multitokens_force_set_token_V2))
//            break;
        case 64791: /* module 253 call 23 */
        CHECK_ERROR(_readMethod_multitokens_force_set_attribute_V2(c, &method->basic.multitokens_force_set_attribute_V2))
            break;
//        case 64792: /* module 253 call 24 */
//        CHECK_ERROR(_readMethod_multitokens_force_set_collection_account_V2(c, &method->basic.multitokens_force_set_collection_account_V2))
//            break;
//        case 64793: /* module 253 call 25 */
//        CHECK_ERROR(_readMethod_multitokens_force_set_token_account_V2(c, &method->basic.multitokens_force_set_token_account_V2))
//            break;
//        case 64794: /* module 253 call 26 */
//        CHECK_ERROR(_readMethod_multitokens_force_create_collection_V2(c, &method->basic.multitokens_force_create_collection_V2))
//            break;
//        case 64795: /* module 253 call 27 */
//        CHECK_ERROR(_readMethod_multitokens_force_mint_V2(c, &method->basic.multitokens_force_mint_V2))
//            break;
//        case 64796: /* module 253 call 28 */
//        CHECK_ERROR(_readMethod_multitokens_force_burn_V2(c, &method->basic.multitokens_force_burn_V2))
//            break;
        case 64797: /* module 253 call 29 */
        CHECK_ERROR(_readMethod_multitokens_force_approve_collection_V2(c, &method->basic.multitokens_force_approve_collection_V2))
            break;
//        case 64798: /* module 253 call 30 */
//        CHECK_ERROR(_readMethod_multitokens_force_freeze_V2(c, &method->basic.multitokens_force_freeze_V2))
//            break;
        case 64799: /* module 253 call 31 */
        CHECK_ERROR(_readMethod_multitokens_force_set_next_collection_id_V2(c, &method->basic.multitokens_force_set_next_collection_id_V2))
            break;
        case 64800: /* module 253 call 32 */
        CHECK_ERROR(_readMethod_multitokens_claim_collections_V2(c, &method->basic.multitokens_claim_collections_V2))
            break;
        case 64801: /* module 253 call 33 */
        CHECK_ERROR(_readMethod_multitokens_claim_tokens_V2(c, &method->basic.multitokens_claim_tokens_V2))
            break;
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V2(c, &method->basic.balances_force_unreserve_V2))
            break;
        case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V2(c, &method->basic.balances_upgrade_accounts_V2))
            break;
        case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V2(c, &method->basic.balances_force_set_balance_V2))
            break;
        case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V2(c, &method->nested.staking_bond_V2))
            break;
        case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V2(c, &method->nested.staking_bond_extra_V2))
            break;
        case 2306: /* module 9 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V2(c, &method->nested.staking_unbond_V2))
            break;
        case 2307: /* module 9 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V2(c, &method->nested.staking_withdraw_unbonded_V2))
            break;
        case 2308: /* module 9 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V2(c, &method->basic.staking_validate_V2))
            break;
        case 2309: /* module 9 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V2(c, &method->nested.staking_nominate_V2))
            break;
        case 2310: /* module 9 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V2(c, &method->nested.staking_chill_V2))
            break;
        case 2311: /* module 9 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V2(c, &method->nested.staking_set_payee_V2))
            break;
        case 2312: /* module 9 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V2(c, &method->nested.staking_set_controller_V2))
            break;
        case 2313: /* module 9 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V2(c, &method->basic.staking_set_validator_count_V2))
            break;
        case 2314: /* module 9 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V2(c, &method->basic.staking_increase_validator_count_V2))
            break;
        case 2315: /* module 9 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V2(c, &method->basic.staking_scale_validator_count_V2))
            break;
        case 2316: /* module 9 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V2(c, &method->basic.staking_force_no_eras_V2))
            break;
        case 2317: /* module 9 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V2(c, &method->basic.staking_force_new_era_V2))
            break;
        case 2318: /* module 9 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V2(c, &method->basic.staking_set_invulnerables_V2))
            break;
        case 2319: /* module 9 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V2(c, &method->basic.staking_force_unstake_V2))
            break;
        case 2320: /* module 9 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V2(c, &method->basic.staking_force_new_era_always_V2))
            break;
        case 2321: /* module 9 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V2(c, &method->basic.staking_cancel_deferred_slash_V2))
            break;
        case 2322: /* module 9 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V2(c, &method->basic.staking_payout_stakers_V2))
            break;
        case 2323: /* module 9 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V2(c, &method->nested.staking_rebond_V2))
            break;
        case 2324: /* module 9 call 20 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V2(c, &method->basic.staking_reap_stash_V2))
            break;
        case 2325: /* module 9 call 21 */
        CHECK_ERROR(_readMethod_staking_kick_V2(c, &method->basic.staking_kick_V2))
            break;
        case 2326: /* module 9 call 22 */
        CHECK_ERROR(_readMethod_staking_set_staking_configs_V2(c, &method->basic.staking_set_staking_configs_V2))
            break;
        case 2327: /* module 9 call 23 */
        CHECK_ERROR(_readMethod_staking_chill_other_V2(c, &method->basic.staking_chill_other_V2))
            break;
        case 2328: /* module 9 call 24 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V2(c, &method->basic.staking_force_apply_min_commission_V2))
            break;
        case 2329: /* module 9 call 25 */
        CHECK_ERROR(_readMethod_staking_set_min_commission_V2(c, &method->basic.staking_set_min_commission_V2))
            break;
        case 4619: /* module 18 call 11 */
        CHECK_ERROR(_readMethod_nominationpools_set_configs_V2(c, &method->basic.nominationpools_set_configs_V2))
            break;
        // case 4630: /* module 18 call 22 */
        // CHECK_ERROR(_readMethod_nominationpools_set_staking_info_V2(c, &method->basic.nominationpools_set_staking_info_V2))
        //     break;
#endif
        default:
            return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
{
    switch (moduleIdx) {
        case 6:
            return STR_MO_BALANCES;
        case 18:
            return STR_MO_NOMINATIONPOOLS;
        case 19:
            return STR_MO_STAKEEXCHANGE;
        case 253:
            return STR_MO_MULTITOKENS;
#ifdef SUBSTRATE_PARSER_FULL
        case 9:
            return STR_MO_STAKING;
#endif
        default:
            return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            return STR_ME_TRANSFER_ALLOW_DEATH;
        case 1538: /* module 6 call 2 */
            return STR_ME_FORCE_TRANSFER;
        case 1539: /* module 6 call 3 */
            return STR_ME_TRANSFER_KEEP_ALIVE;
        case 1540: /* module 6 call 4 */
            return STR_ME_TRANSFER_ALL;
        case 1543: /* module 6 call 7 */
            return STR_ME_TRANSFER;
        case 4608: /* module 18 call 0 */
            return STR_ME_BOND;
        case 4611: /* module 18 call 3 */
            return STR_ME_UNBOND;
        case 4612: /* module 18 call 4 */
            return STR_ME_POOL_WITHDRAW_UNBONDED;
        case 4613: /* module 18 call 5 */
            return STR_ME_WITHDRAW_UNBONDED;
        case 4614: /* module 18 call 6 */
            return STR_ME_CREATE;
        case 4616: /* module 18 call 8 */
            return STR_ME_NOMINATE;
        case 4621: /* module 18 call 13 */
            return STR_ME_CHILL;
        case 4622: /* module 18 call 14 */
            return STR_ME_DESTROY;
        case 4626: /* module 18 call 18 */
            return STR_ME_PAYOUT_REWARDS;
        case 4627: /* module 18 call 19 */
            return STR_ME_MUTATE;
        case 4628: /* module 18 call 20 */
            return STR_ME_UNBOND_DEPOSIT;
        case 4629: /* module 18 call 21 */
            return STR_ME_WITHDRAW_DEPOSIT;
        case 4631: /* module 18 call 23 */
            return STR_ME_QUEUE_EARLY_BIRD_BONUS;
        case 4632: /* module 18 call 24 */
            return STR_ME_DISTRIBUTE_EARLY_BIRD_BONUS;
        case 4864: /* module 19 call 0 */
            return STR_ME_CREATE_OFFER;
        case 4865: /* module 19 call 1 */
            return STR_ME_CANCEL_OFFER;
        case 4866: /* module 19 call 2 */
            return STR_ME_CONFIGURE_LIQUIDITY_ACCOUNT;
        case 4867: /* module 19 call 3 */
            return STR_ME_WITHDRAW_LIQUIDITY;
        case 4868: /* module 19 call 4 */
            return STR_ME_ADD_LIQUIDITY;
        case 4869: /* module 19 call 5 */
            return STR_ME_BUY;
        case 64768: /* module 253 call 0 */
            return STR_ME_CREATE_COLLECTION;
        case 64769: /* module 253 call 1 */
            return STR_ME_DESTROY_COLLECTION;
        case 64770: /* module 253 call 2 */
            return STR_ME_MUTATE_COLLECTION;
        case 64771: /* module 253 call 3 */
            return STR_ME_MUTATE_TOKEN;
        case 64772: /* module 253 call 4 */
            return STR_ME_MINT;
        case 64773: /* module 253 call 5 */
            return STR_ME_BURN;
        case 64774: /* module 253 call 6 */
            return STR_ME_TRANSFER;
        case 64775: /* module 253 call 7 */
            return STR_ME_FREEZE;
        case 64776: /* module 253 call 8 */
            return STR_ME_THAW;
        case 64777: /* module 253 call 9 */
            return STR_ME_SET_ATTRIBUTE;
        case 64778: /* module 253 call 10 */
            return STR_ME_REMOVE_ATTRIBUTE;
        case 64779: /* module 253 call 11 */
            return STR_ME_REMOVE_ALL_ATTRIBUTES;
        case 64780: /* module 253 call 12 */
            return STR_ME_BATCH_TRANSFER;
        case 64781: /* module 253 call 13 */
            return STR_ME_BATCH_MINT;
        case 64782: /* module 253 call 14 */
            return STR_ME_BATCH_SET_ATTRIBUTE;
        case 64783: /* module 253 call 15 */
            return STR_ME_APPROVE_COLLECTION;
        case 64784: /* module 253 call 16 */
            return STR_ME_UNAPPROVE_COLLECTION;
        case 64785: /* module 253 call 17 */
            return STR_ME_APPROVE_TOKEN;
        case 64786: /* module 253 call 18 */
            return STR_ME_UNAPPROVE_TOKEN;
        case 64787: /* module 253 call 19 */
            return STR_ME_FORCE_MUTATE_COLLECTION;
        case 64788: /* module 253 call 20 */
            return STR_ME_FORCE_TRANSFER;
        case 64789: /* module 253 call 21 */
            return STR_ME_FORCE_SET_COLLECTION;
        case 64790: /* module 253 call 22 */
            return STR_ME_FORCE_SET_TOKEN;
        case 64791: /* module 253 call 23 */
            return STR_ME_FORCE_SET_ATTRIBUTE;
        case 64792: /* module 253 call 24 */
            return STR_ME_FORCE_SET_COLLECTION_ACCOUNT;
        case 64793: /* module 253 call 25 */
            return STR_ME_FORCE_SET_TOKEN_ACCOUNT;
        case 64794: /* module 253 call 26 */
            return STR_ME_FORCE_CREATE_COLLECTION;
        case 64795: /* module 253 call 27 */
            return STR_ME_FORCE_MINT;
        case 64796: /* module 253 call 28 */
            return STR_ME_FORCE_BURN;
        case 64797: /* module 253 call 29 */
            return STR_ME_FORCE_APPROVE_COLLECTION;
        case 64798: /* module 253 call 30 */
            return STR_ME_FORCE_FREEZE;
        case 64799: /* module 253 call 31 */
            return STR_ME_FORCE_SET_NEXT_COLLECTION_ID;
        case 64800: /* module 253 call 32 */
            return STR_ME_CLAIM_COLLECTIONS;
        case 64801: /* module 253 call 33 */
            return STR_ME_CLAIM_TOKENS;
        default:
            return _getMethod_Name_V2_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V2_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
            return STR_ME_FORCE_UNRESERVE;
        case 1542: /* module 6 call 6 */
            return STR_ME_UPGRADE_ACCOUNTS;
        case 1544: /* module 6 call 8 */
            return STR_ME_FORCE_SET_BALANCE;
        case 2304: /* module 9 call 0 */
            return STR_ME_BOND;
        case 2305: /* module 9 call 1 */
            return STR_ME_BOND_EXTRA;
        case 2306: /* module 9 call 2 */
            return STR_ME_UNBOND;
        case 2307: /* module 9 call 3 */
            return STR_ME_WITHDRAW_UNBONDED;
        case 2308: /* module 9 call 4 */
            return STR_ME_VALIDATE;
        case 2309: /* module 9 call 5 */
            return STR_ME_NOMINATE;
        case 2310: /* module 9 call 6 */
            return STR_ME_CHILL;
        case 2311: /* module 9 call 7 */
            return STR_ME_SET_PAYEE;
        case 2312: /* module 9 call 8 */
            return STR_ME_SET_CONTROLLER;
        case 2313: /* module 9 call 9 */
            return STR_ME_SET_VALIDATOR_COUNT;
        case 2314: /* module 9 call 10 */
            return STR_ME_INCREASE_VALIDATOR_COUNT;
        case 2315: /* module 9 call 11 */
            return STR_ME_SCALE_VALIDATOR_COUNT;
        case 2316: /* module 9 call 12 */
            return STR_ME_FORCE_NO_ERAS;
        case 2317: /* module 9 call 13 */
            return STR_ME_FORCE_NEW_ERA;
        case 2318: /* module 9 call 14 */
            return STR_ME_SET_INVULNERABLES;
        case 2319: /* module 9 call 15 */
            return STR_ME_FORCE_UNSTAKE;
        case 2320: /* module 9 call 16 */
            return STR_ME_FORCE_NEW_ERA_ALWAYS;
        case 2321: /* module 9 call 17 */
            return STR_ME_CANCEL_DEFERRED_SLASH;
        case 2322: /* module 9 call 18 */
            return STR_ME_PAYOUT_STAKERS;
        case 2323: /* module 9 call 19 */
            return STR_ME_REBOND;
        case 2324: /* module 9 call 20 */
            return STR_ME_REAP_STASH;
        case 2325: /* module 9 call 21 */
            return STR_ME_KICK;
        case 2326: /* module 9 call 22 */
            return STR_ME_SET_STAKING_CONFIGS;
        case 2327: /* module 9 call 23 */
            return STR_ME_CHILL_OTHER;
        case 2328: /* module 9 call 24 */
            return STR_ME_FORCE_APPLY_MIN_COMMISSION;
        case 2329: /* module 9 call 25 */
            return STR_ME_SET_MIN_COMMISSION;
        case 4619: /* module 18 call 11 */
            return STR_ME_SET_CONFIGS;
        // case 4630: /* module 18 call 22 */
        //     return STR_ME_SET_STAKING_INFO;
#endif
        default:
            return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            return 2;
        case 1538: /* module 6 call 2 */
            return 3;
        case 1539: /* module 6 call 3 */
            return 2;
        case 1540: /* module 6 call 4 */
            return 2;
        case 1543: /* module 6 call 7 */
            return 2;
        case 4608: /* module 18 call 0 */
            return 2;
        case 4611: /* module 18 call 3 */
            return 3;
        case 4612: /* module 18 call 4 */
            return 2;
        case 4613: /* module 18 call 5 */
            return 3;
        case 4614: /* module 18 call 6 */
            return 6;
        case 4616: /* module 18 call 8 */
            return 2;
        case 4621: /* module 18 call 13 */
            return 1;
        case 4622: /* module 18 call 14 */
            return 1;
        case 4626: /* module 18 call 18 */
            return 2;
            // TODO: Check not sure
        case 4627: /* module 18 call 19 */
            return 1;
        case 4628: /* module 18 call 20 */
            return 1;
        case 4629: /* module 18 call 21 */
            return 1;
        case 4631: /* module 18 call 23 */
            return 0;
        case 4632: /* module 18 call 24 */
            return 1;
        case 4864: /* module 19 call 0 */
            return 1;
        case 4865: /* module 19 call 1 */
            return 1;
        case 4866: /* module 19 call 2 */
            return 1;
        case 4867: /* module 19 call 3 */
            return 2;
        case 4868: /* module 19 call 4 */
            return 2;
        case 4869: /* module 19 call 5 */
            return 3;
        case 64768: /* module 253 call 0 */
            return 1;
        case 64769: /* module 253 call 1 */
            return 1;
        case 64770: /* module 253 call 2 */
            return 2;
        case 64771: /* module 253 call 3 */
            return 3;
        case 64772: /* module 253 call 4 */
            return 3;
        case 64773: /* module 253 call 5 */
            return 2;
        case 64774: /* module 253 call 6 */
            return 3;
        case 64775: /* module 253 call 7 */
            return 1;
        case 64776: /* module 253 call 8 */
            return 1;
        case 64777: /* module 253 call 9 */
            return 4;
        case 64778: /* module 253 call 10 */
            return 3;
        case 64779: /* module 253 call 11 */
            return 3;
        case 64780: /* module 253 call 12 */
            return 2;
        case 64781: /* module 253 call 13 */
            return 2;
        case 64782: /* module 253 call 14 */
            return 3;
        case 64783: /* module 253 call 15 */
            return 3;
        case 64784: /* module 253 call 16 */
            return 2;
        case 64785: /* module 253 call 17 */
            return 6;
        case 64786: /* module 253 call 18 */
            return 3;
        case 64787: /* module 253 call 19 */
            return 2;
        case 64788: /* module 253 call 20 */
            return 4;
        case 64789: /* module 253 call 21 */
            return 2;
        case 64790: /* module 253 call 22 */
            return 3;
        case 64791: /* module 253 call 23 */
            return 4;
        case 64792: /* module 253 call 24 */
            return 3;
        case 64793: /* module 253 call 25 */
            return 4;
        case 64794: /* module 253 call 26 */
            return 3;
        case 64795: /* module 253 call 27 */
            return 3;
        case 64796: /* module 253 call 28 */
            return 3;
        case 64797: /* module 253 call 29 */
            return 4;
        case 64798: /* module 253 call 30 */
            return 1;
        case 64799: /* module 253 call 31 */
            return 1;
        case 64800: /* module 253 call 32 */
            return 3;
        case 64801: /* module 253 call 33 */
            return 3;
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
            return 2;
        case 1542: /* module 6 call 6 */
            return 1;
        case 1544: /* module 6 call 8 */
            return 2;
        case 2304: /* module 9 call 0 */
            return 2;
        case 2305: /* module 9 call 1 */
            return 1;
        case 2306: /* module 9 call 2 */
            return 1;
        case 2307: /* module 9 call 3 */
            return 1;
        case 2308: /* module 9 call 4 */
            return 1;
        case 2309: /* module 9 call 5 */
            return 1;
        case 2310: /* module 9 call 6 */
            return 0;
        case 2311: /* module 9 call 7 */
            return 1;
        case 2312: /* module 9 call 8 */
            return 0;
        case 2313: /* module 9 call 9 */
            return 1;
        case 2314: /* module 9 call 10 */
            return 1;
        case 2315: /* module 9 call 11 */
            return 1;
        case 2316: /* module 9 call 12 */
            return 0;
        case 2317: /* module 9 call 13 */
            return 0;
        case 2318: /* module 9 call 14 */
            return 1;
        case 2319: /* module 7 call 15 */
            return 2;
        case 2320: /* module 9 call 16 */
            return 0;
        case 2321: /* module 9 call 17 */
            return 2;
        case 2322: /* module 9 call 18 */
            return 2;
        case 2324: /* module 9 call 19 */
            return 1;
        case 2325: /* module 9 call 20 */
            return 2;
        case 2326: /* module 9 call 21 */
            return 1;
        case 2327: /* module 9 call 22 */
            return 6;
        case 2328: /* module 9 call 23 */
            return 1;
        case 2329: /* module 9 call 24 */
            return 1;
        case 2330: /* module 9 call 25 */
            return 1;
        case 4619: /* module 18 call 11 */
            return 3;
        // case 4630: /* module 18 call 22 */
        //     return 1;
#endif
        default:
            return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1538: /* module 6 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_source;
                case 1:
                    return STR_IT_dest;
                case 2:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1539: /* module 6 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1540: /* module 6 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_keep_alive;
                default:
                    return NULL;
            }
        case 1543: /* module 6 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 4608: /* module 18 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1: // TODO: Check as this is now an enum
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 4611: /* module 18 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_member_account;
                case 2:
                    return STR_IT_unbonding_points;
                default:
                    return NULL;
            }
        case 4612: /* module 18 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 4613: /* module 18 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_member_account;
                case 2:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 4614: /* module 18 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_token_id;
                case 1:
                    return STR_IT_deposit;
                case 2:
                    return STR_IT_capacity;
                case 3:
                    return STR_IT_duration;
                case 4:
                    return STR_IT_admin;
                case 5:
                    return STR_IT_nominator;
                default:
                    return NULL;
            }
        case 4616: /* module 18 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1:
                    return STR_IT_validators;
                default:
                    return NULL;
            }
        case 4621: /* module 18 call 13 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 4622: /* module 18 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 4626: /* module 18 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                case 1:
                    return STR_IT_era;
                default:
                    return NULL;
            }
        case 4627: /* module 18 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                case 1: // TODO: Mutate // Check
                    return STR_IT_mutation;
                default:
                    return NULL;
            }
        case 4628: /* module 18 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 4629: /* module 18 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pool_id;
                default:
                    return NULL;
            }
        case 4631: /* module 18 call 23 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 4632: /* module 18 call 24 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_transfer_count;
                default:
                    return NULL;
            }
        case 4864: /* module 19 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_offer;
                default:
                    return NULL;
            }
        case 4865: /* module 19 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_offer_id;
                default:
                    return NULL;
            }
        // case 4866: /* module 19 call 2 */
        //     switch (itemIdx) {
        //         case 0:
        //             return STR_IT_config;
        //         default:
        //             return NULL;
        //     }
        case 4867: /* module 19 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_offer_id;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 4868: /* module 19 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_offer_id;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 4869: /* module 19 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_offer_id;
                case 1:
                    return STR_IT_amount;
                case 2:
                    return STR_IT_token_id;
                default:
                    return NULL;
            }
        case 64768: /* module 253 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_descriptor;
                default:
                    return NULL;
            }
        case 64769: /* module 253 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                default:
                    return NULL;
            }
        case 64770: /* module 253 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_mutation;
                default:
                    return NULL;
            }
        case 64771: /* module 253 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_mutation;
                default:
                    return NULL;
            }
        case 64772: /* module 253 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_recipient;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64773: /* module 253 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64774: /* module 253 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_recipient;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64775: /* module 253 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_info;
                default:
                    return NULL;
            }
        case 64776: /* module 253 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_info;
                default:
                    return NULL;
            }
        case 64777: /* module 253 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_key;
                case 3:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64778: /* module 253 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_key;
                default:
                    return NULL;
            }
        case 64779: /* module 253 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_attribute_count;
                default:
                    return NULL;
            }
        case 64780: /* module 253 call 12 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_recipients;
                default:
                    return NULL;
            }
        case 64781: /* module 253 call 13 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_recipients;
                default:
                    return NULL;
            }
        case 64782: /* module 253 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_attributes;
                default:
                    return NULL;
            }
        case 64783: /* module 253 call 15 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_operator;
                case 2:
                    return STR_IT_expiration;
                default:
                    return NULL;
            }
        case 64784: /* module 253 call 16 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_operator;
                default:
                    return NULL;
            }
        case 64785: /* module 253 call 17 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_operator;
                case 3:
                    return STR_IT_amount;
                case 4:
                    return STR_IT_expiration;
                case 5:
                    return STR_IT_current_amount;
                default:
                    return NULL;
            }
        case 64786: /* module 253 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_operator;
                default:
                    return NULL;
            }
        case 64787: /* module 253 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_mutation;
                default:
                    return NULL;
            }
        case 64788: /* module 253 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_source;
                case 1:
                    return STR_IT_destination;
                case 2:
                    return STR_IT_collection_id;
                case 3:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64789: /* module 253 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64790: /* module 253 call 22 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64791: /* module 253 call 23 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_key;
                case 3:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64792: /* module 253 call 24 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_account_id;
                case 2:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64793: /* module 253 call 25 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_token_id;
                case 2:
                    return STR_IT_account_id;
                case 3:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64794: /* module 253 call 26 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_owner;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_descriptor;
                default:
                    return NULL;
            }
        case 64795: /* module 253 call 27 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_caller;
                case 1:
                    return STR_IT_recipient;
                case 2:
                    return STR_IT_collection_id;
                case 3:
                    return STR_IT_params;
                case 4:
                    return STR_IT_deposit_backer;
                default:
                    return NULL;
            }
        case 64796: /* module 253 call 28 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_caller;
                case 1:
                    return STR_IT_collection_id;
                case 2:
                    return STR_IT_params;
                default:
                    return NULL;
            }
        case 64797: /* module 253 call 29 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_collection_id;
                case 1:
                    return STR_IT_operator;
                case 2:
                    return STR_IT_expiration;
                default:
                    return NULL;
            }
        case 64798: /* module 253 call 30 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_info;
                default:
                    return NULL;
            }
        case 64799: /* module 253 call 31 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 64800: /* module 253 call 32 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_destination;
                case 1:
                    return STR_IT_ethereum_signature;
                case 2:
                    return STR_IT_ethereum_address;
                default:
                    return NULL;
            }
        case 64801: /* module 253 call 33 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_destination;
                case 1:
                    return STR_IT_ethereum_signature;
                case 2:
                    return STR_IT_ethereum_address;
                default:
                    return NULL;
            }
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1542: /* module 6 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 1544: /* module 6 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_new_free;
                default:
                    return NULL;
            }
        case 2304: /* module 9 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                case 1:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 2305: /* module 9 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2306: /* module 9 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2307: /* module 9 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2308: /* module 9 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_prefs;
                default:
                    return NULL;
            }
        case 2309: /* module 9 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_targets;
                default:
                    return NULL;
            }
        case 2310: /* module 9 call 6 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2311: /* module 9 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 2312: /* module 9 call 8 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2313: /* module 9 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 2314: /* module 9 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_additional;
                default:
                    return NULL;
            }
        case 2315: /* module 9 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_factor;
                default:
                    return NULL;
            }
        case 2316: /* module 9 call 12 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2317: /* module 9 call 13 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2318: /* module 9 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_invulnerables;
                default:
                    return NULL;
            }
        case 2319: /* module 9 call 15 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2320: /* module 9 call 16 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2321: /* module 9 call 17 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_era;
                case 1:
                    return STR_IT_slash_indices;
                default:
                    return NULL;
            }
        case 2322: /* module 9 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                case 1:
                    return STR_IT_era;
                default:
                    return NULL;
            }
        case 2323: /* module 9 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_value;
                default:
                    return NULL;
            }
        case 2324: /* module 9 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2325: /* module 9 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 2326: /* module 9 call 22 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_min_nominator_bond;
                case 1:
                    return STR_IT_min_validator_bond;
                case 2:
                    return STR_IT_max_nominator_count;
                case 3:
                    return STR_IT_max_validator_count;
                case 4:
                    return STR_IT_chill_threshold;
                case 5:
                    return STR_IT_min_commission;
                default:
                    return NULL;
            }
        case 2327: /* module 9 call 23 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_controller;
                default:
                    return NULL;
            }
        case 2328: /* module 9 call 24 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                default:
                    return NULL;
            }
        case 2329: /* module 9 call 25 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 4619: /* module 18 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_min_join_bond;
                case 1:
                    return STR_IT_min_create_bond;
                case 2:
                    return STR_IT_global_max_commission;
                default:
                    return NULL;
            }
        // case 4630: /* module 18 call 22 */
        //     switch (itemIdx) {
        //         case 0: 
        //             return STR_IT_info;
        //         default:
        //             return NULL;
        //     }
#endif
        default:
            return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
        pd_Method_V2_t* m,
        uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
        char* outValue, uint16_t outValueLen,
        uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            switch (itemIdx) {
                case 0: /* balances_transfer_allow_death_V2 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->nested.balances_transfer_allow_death_V2.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_allow_death_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->nested.balances_transfer_allow_death_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1538: /* module 6 call 2 */
            switch (itemIdx) {
                case 0: /* balances_force_transfer_V2 - source */;
                    return _toStringAccountIdLookupOfT(
                            &m->nested.balances_force_transfer_V2.source,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_force_transfer_V2 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->nested.balances_force_transfer_V2.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* balances_force_transfer_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->nested.balances_force_transfer_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1539: /* module 6 call 3 */
            switch (itemIdx) {
                case 0: /* balances_transfer_keep_alive_V2 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->nested.balances_transfer_keep_alive_V2.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_keep_alive_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->nested.balances_transfer_keep_alive_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1540: /* module 6 call 4 */
            switch (itemIdx) {
                case 0: /* balances_transfer_all_V2 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_transfer_all_V2.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_all_V2 - keep_alive */;
                    return _toStringbool(
                            &m->basic.balances_transfer_all_V2.keep_alive,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1543: /* module 6 call 7 */
            switch (itemIdx) {
                case 0: /* balances_transfer_V2 - dest */;
                    return _toStringAccountIdLookupOfT(
                            &m->nested.balances_transfer_V2.dest,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_transfer_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->nested.balances_transfer_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4608: /* module 18 call 0 */
            switch (itemIdx) {
                case 0: /* nominationpools_bond_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_bond_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* nominationpools_bond_V2 - amount */; // TODO; Check as this is an enum now
                    return _toStringCompactBalance(
                            &m->nested.nominationpools_bond_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4611: /* module 18 call 3 */
            switch (itemIdx) {
                case 0: /* nominationpools_unbond_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_unbond_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* nominationpools_unbond_V2 - member_account */;
                    return _toStringAccountIdLookupOfT(
                            &m->nested.nominationpools_unbond_V2.member_account,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* nominationpools_unbond_V2 - unbonding_points */;
                    return _toStringCompactBalance(
                            &m->nested.nominationpools_unbond_V2.unbonding_points,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4612: /* module 18 call 4 */
            switch (itemIdx) {
                case 0: /* nominationpools_pool_withdraw_unbonded_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_pool_withdraw_unbonded_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* nominationpools_pool_withdraw_unbonded_V2 - num_slashing_spans */;
                    return _toStringu32(
                            &m->nested.nominationpools_pool_withdraw_unbonded_V2.num_slashing_spans,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4613: /* module 18 call 5 */
            switch (itemIdx) {
                case 0: /* nominationpools_withdraw_unbonded_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->basic.nominationpools_withdraw_unbonded_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* nominationpools_withdraw_unbonded_V2 - member_account */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.nominationpools_withdraw_unbonded_V2.member_account,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* nominationpools_withdraw_unbonded_V2 - num_slashing_spans */;
                    return _toStringu32(
                            &m->basic.nominationpools_withdraw_unbonded_V2.num_slashing_spans,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        // case 4614: /* module 18 call 6 */
        //     switch (itemIdx) {
        //         case 0: /* nominationpools_create_V2 - token_id */;
        //             return _toStringu64(
        //                     &m->basic.nominationpools_create_V2.token_id,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         case 1: /* nominationpools_create_V2 - deposit */;
        //             return _toStringCompactBalance(
        //                     &m->basic.nominationpools_create_V2.deposit,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         case 2: /* nominationpools_create_V2 - capacity */;
        //             return _toStringCompactBalance(
        //                     &m->basic.nominationpools_create_V2.capacity,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         case 3: /* nominationpools_create_V2 - duration */;
        //             return _toStringCompactu32(
        //                     &m->basic.nominationpools_create_V2.duration,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         case 4: /* nominationpools_create_V2 - admin */;
        //             return _toStringAccountIdLookupOfT(
        //                     &m->basic.nominationpools_create_V2.admin,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         case 5: /* nominationpools_create_V2 - nominator */;
        //             return _toStringAccountIdLookupOfT(
        //                     &m->basic.nominationpools_create_V2.nominator,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         default:
        //             return parser_no_data;
        //     }
        case 4616: /* module 18 call 8 */
            switch (itemIdx) {
                case 0: /* nominationpools_nominate_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_nominate_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* nominationpools_nominate_V2 - validators */;
                    return _toStringVecAccountIdLookupOfT(
                            &m->nested.nominationpools_nominate_V2.validators,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4621: /* module 18 call 13 */
            switch (itemIdx) {
                case 0: /* nominationpools_chill_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_chill_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4622: /* module 18 call 14 */
            switch (itemIdx) {
                case 0: /* nominationpools_destroy_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_destroy_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4626: /* module 18 call 18 */
            switch (itemIdx) {
                case 0: /* nominationpools_payout_rewards_V2 - validator_stash */;
                    return _toStringAccountId(
                            &m->basic.nominationpools_payout_rewards_V2.validator_stash,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* nominationpools_payout_rewards_V2 - era */;
                    return _toStringEraIndex(
                            &m->basic.nominationpools_payout_rewards_V2.era,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        // case 4627: /* module 18 call 19 */ // TODO: Check, probably wrong
        //     switch (itemIdx) {
        //         case 0: /* nominationpools_mutate_V2 - pool_id */;
        //             return _toStringPoolId(
        //                     &m->nested.nominationpools_mutate_V2.pool_id,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         case 1: /* nominationpools_mutate_V2 - mutation */;
        //             return _toStringPoolMutation(
        //                     &m->nested.nominationpools_mutate_V2.mutation,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         default:
        //             return parser_no_data;
        //     }
        case 4628: /* module 18 call 20 */
            switch (itemIdx) {
                case 0: /* nominationpools_unbond_deposit_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_unbond_deposit_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4629: /* module 18 call 21 */
            switch (itemIdx) {
                case 0: /* nominationpools_withdraw_deposit_V2 - pool_id */;
                    return _toStringPoolId(
                            &m->nested.nominationpools_withdraw_deposit_V2.pool_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4631: /* module 18 call 23 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 4632: /* module 18 call 24 */
            switch (itemIdx) {
                case 0: /* nominationpools_distribute_early_bird_bonus_V2 - transfer_count */;
                    return _toStringu32(
                            &m->basic.nominationpools_distribute_early_bird_bonus_V2.transfer_count,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        // case 4864: /* module 19 call 0 */
        //     switch (itemIdx) {
        //         case 0: /* stakeexchange_create_offer_V2 - offer */;
        //             return _toStringOffer(
        //                     &m->basic.stakeexchange_create_offer_V2.offer,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         default:
        //             return parser_no_data;
        //     }
        case 4865: /* module 19 call 1 */
            switch (itemIdx) {
                case 0: /* stakeexchange_cancel_offer_V2 - offer_id */;
                    return _toStringOfferId(
                            &m->basic.stakeexchange_cancel_offer_V2.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        // case 4866: /* module 19 call 2 */
        //     switch (itemIdx) {
        //         case 0: /* stakeexchange_configure_liquidity_account_V2 - config */;
        //             return _toStringOfferConfig(
        //                     &m->basic.stakeexchange_configure_liquidity_account_V2.config,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         default:
        //             return parser_no_data;
        //     }
        case 4867: /* module 19 call 3 */
            switch (itemIdx) {
                case 0: /* stakeexchange_withdraw_liquidity_V2 - offer_id */;
                    return _toStringOfferId(
                            &m->basic.stakeexchange_withdraw_liquidity_V2.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* stakeexchange_withdraw_liquidity_V2 - amount */;
                    return _toStringBalanceOf(
                            &m->basic.stakeexchange_withdraw_liquidity_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4868: /* module 19 call 4 */
            switch (itemIdx) {
                case 0: /* stakeexchange_add_liquidity_V2 - offer_id */;
                    return _toStringOfferId(
                            &m->basic.stakeexchange_add_liquidity_V2.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* stakeexchange_add_liquidity_V2 - amount */;
                    return _toStringBalanceOf(
                            &m->basic.stakeexchange_add_liquidity_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4869: /* module 19 call 5 */
            switch (itemIdx) {
                case 0: /* stakeexchange_buy_V2 - offer_id */;
                    return _toStringOfferId(
                            &m->basic.stakeexchange_buy_V2.offer_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* stakeexchange_buy_V2 - amount */;
                    return _toStringBalanceOf(
                            &m->basic.stakeexchange_buy_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* stakeexchange_buy_V2 - token_id */;
                    return _toStringTokenIdOf(
                            &m->basic.stakeexchange_buy_V2.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64768: /* module 253 call 0 */
            switch (itemIdx) {
//                case 0: /* multitokens_create_collection_V2 - descriptor */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_create_collection_V2.descriptor,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64769: /* module 253 call 1 */
            switch (itemIdx) {
                case 0: /* multitokens_destroy_collection_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_destroy_collection_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64770: /* module 253 call 2 */
            switch (itemIdx) {
//                case 0: /* multitokens_mutate_collection_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_mutate_collection_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_mutate_collection_V2 - mutation */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_mutate_collection_V2.mutation,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64771: /* module 253 call 3 */
            switch (itemIdx) {
//                case 0: /* multitokens_mutate_token_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_mutate_token_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_mutate_token_V2 - token_id */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_mutate_token_V2.token_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_mutate_token_V2 - mutation */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_mutate_token_V2.mutation,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64772: /* module 253 call 4 */
            switch (itemIdx) {
//                case 0: /* multitokens_mint_V2 - recipient */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_mint_V2.recipient,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_mint_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_mint_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_mint_V2 - params */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_mint_V2.params,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64773: /* module 253 call 5 */
            switch (itemIdx) {
//                case 0: /* multitokens_burn_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_burn_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_burn_V2 - params */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_burn_V2.token_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64774: /* module 253 call 6 */
            switch (itemIdx) {
//                case 0: /* multitokens_transfer_V2 - recipient */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_transfer_V2.recipient,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_transfer_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_transfer_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_transfer_V2 - params */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_transfer_V2.token_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64775: /* module 253 call 7 */
            switch (itemIdx) {
//                case 0: /* multitokens_freeze_V2 - info */;
//                    return _toStringFreezeInfo(
//                            &m->basic.multitokens_freeze_V2.info,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64776: /* module 253 call 8 */
            switch (itemIdx) {
//                case 0: /* multitokens_thaw_V2 - info */;
//                    return _toStringFreezeInfo(
//                            &m->basic.multitokens_thaw_V2.info,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64777: /* module 253 call 9 */
            switch (itemIdx) {
                case 0: /* multitokens_set_attribute_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_set_attribute_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_set_attribute_V2 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_set_attribute_V2.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_set_attribute_V2 - key */;
                    return _toStringBytes(
                            &m->basic.multitokens_set_attribute_V2.key,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_set_attribute_V2 - value */;
                    return _toStringBytes(
                            &m->basic.multitokens_set_attribute_V2.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64778: /* module 253 call 10 */
            switch (itemIdx) {
                case 0: /* multitokens_remove_attribute_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_remove_attribute_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_remove_attribute_V2 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_remove_attribute_V2.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_remove_attribute_V2 - key */;
                    return _toStringBytes(
                            &m->basic.multitokens_remove_attribute_V2.key,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64779: /* module 253 call 11 */
            switch (itemIdx) {
                case 0: /* multitokens_remove_all_attributes_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_remove_all_attributes_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_remove_all_attributes_V2 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_remove_all_attributes_V2.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_remove_all_attributes_V2 - attribute_count */;
                    return _toStringu32(
                            &m->basic.multitokens_remove_all_attributes_V2.attribute_count,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64780: /* module 253 call 12 */
            switch (itemIdx) {
//                case 0: /* multitokens_batch_transfer_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_batch_transfer_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_batch_transfer_V2 - recipients */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_batch_transfer_V2.recipients,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64781: /* module 253 call 13 */
            switch (itemIdx) {
//                case 0: /* multitokens_batch_mint_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_batch_mint_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_batch_mint_V2 - recipients */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_batch_mint_V2.recipients,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64782: /* module 253 call 14 */
            switch (itemIdx) {
//                case 0: /* multitokens_batch_set_attribute_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_batch_set_attribute_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_batch_set_attribute_V2 - token_id */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_batch_set_attribute_V2.token_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_batch_set_attribute_V2 - attributes */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_batch_set_attribute_V2.attributes,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64783: /* module 253 call 15 */
            switch (itemIdx) {
                case 0: /* multitokens_approve_collection_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_approve_collection_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_approve_collection_V2 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_approve_collection_V2.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_approve_collection_V2 - expiration */;
                    return _toStringOptionu32(
                            &m->basic.multitokens_approve_collection_V2.expiration,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64784: /* module 253 call 16 */
            switch (itemIdx) {
                case 0: /* multitokens_unapprove_collection_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_unapprove_collection_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_unapprove_collection_V2 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_unapprove_collection_V2.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64785: /* module 253 call 17 */
            switch (itemIdx) {
                case 0: /* multitokens_approve_token_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_approve_token_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_approve_token_V2 - token_id */;
                    return _toStringCompactTokenId(
                            &m->basic.multitokens_approve_token_V2.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_approve_token_V2 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_approve_token_V2.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_approve_token_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->basic.multitokens_approve_token_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 4: /* multitokens_approve_token_V2 - expiration */;
                    return _toStringOptionu32(
                            &m->basic.multitokens_approve_token_V2.expiration,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 5: /* multitokens_approve_token_V2 - current_amount */;
                    return _toStringCompactBalance(
                            &m->basic.multitokens_approve_token_V2.current_amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64786: /* module 253 call 18 */
            switch (itemIdx) {
                case 0: /* multitokens_unapprove_token_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_unapprove_token_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_unapprove_token_V2 - token_id */;
                    return _toStringCompactTokenId(
                            &m->basic.multitokens_unapprove_token_V2.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_unapprove_token_V2 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_unapprove_token_V2.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64787: /* module 253 call 19 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_mutate_collection_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_mutate_collection_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_mutate_collection_V2 - mutation */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_force_mutate_collection_V2.mutation,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64788: /* module 253 call 20 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_transfer_V2 - source */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_transfer_V2.source,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_transfer_V2 - destination */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_transfer_V2.destination,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_force_transfer_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_transfer_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 3: /* multitokens_force_transfer_V2 - params */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_force_transfer_V2.params,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64789: /* module 253 call 21 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_set_collection_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_set_collection_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_set_collection_V2 - value */;
//                    return _toStringCollectionProperties(
//                            &m->basic.multitokens_force_set_collection_V2.value,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64790: /* module 253 call 22 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_set_token_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_set_token_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_set_token_V2 - token_id */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_force_set_token_V2.token_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_force_set_token_V2 - value */;
//                    return _toStringTokenProperties(
//                            &m->basic.multitokens_force_set_token_V2.value,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64791: /* module 253 call 23 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_attribute_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_attribute_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_set_attribute_V2 - token_id */;
                    return _toStringOptionTokenId(
                            &m->basic.multitokens_force_set_attribute_V2.token_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_set_attribute_V2 - key */;
                    return _toStringBytes(
                            &m->basic.multitokens_force_set_attribute_V2.key,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_force_set_attribute_V2 - value */;
                    return _toStringOptionBytes(
                            &m->basic.multitokens_force_set_attribute_V2.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64792: /* module 253 call 24 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_set_collection_account_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_set_collection_account_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_set_collection_account_V2 - account_id */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_set_collection_account_V2.account_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_force_set_collection_account_V2 - value */;
//                    return _toStringCollectionAccountData(
//                            &m->basic.multitokens_force_set_collection_account_V2.value,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64793: /* module 253 call 25 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_set_token_account_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_set_token_account_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_set_token_account_V2 - token_id */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_force_set_token_account_V2.token_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_force_set_token_account_V2 - account_id */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_set_token_account_V2.account_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 3: /* multitokens_force_set_token_account_V2 - value */;
//                    return _toStringTokenAccountData(
//                            &m->basic.multitokens_force_set_token_account_V2.value,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64794: /* module 253 call 26 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_create_collection_V2 - owner */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_create_collection_V2.owner,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_create_collection_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_create_collection_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_force_create_collection_V2 - descriptor */;
//                    return _toStringVecu8(
//                            &m->basic.multitokens_force_create_collection_V2.descriptor,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64795: /* module 253 call 27 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_mint_V2 - caller */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_mint_V2.caller,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_mint_V2 - recipient */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_mint_V2.recipient,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_force_mint_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_mint_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 3: /* multitokens_force_mint_V2 - params */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_force_mint_V2.params,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 4: /* multitokens_force_mint_V2 - deposit_backer */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_mint_V2.deposit_backer,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64796: /* module 253 call 28 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_burn_V2 - caller */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_force_burn_V2.caller,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_force_burn_V2 - collection_id */;
//                    return _toStringCompactCollectionId(
//                            &m->basic.multitokens_force_burn_V2.collection_id,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_force_burn_V2 - params */;
//                    return _toStringTokenIdOf(
//                            &m->basic.multitokens_force_burn_V2.params,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64797: /* module 253 call 29 */
            switch (itemIdx) {
                case 0: /* multitokens_force_approve_collection_V2 - caller */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.multitokens_force_approve_collection_V2.caller,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* multitokens_force_approve_collection_V2 - collection_id */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_approve_collection_V2.collection_id,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* multitokens_force_approve_collection_V2 - operator */;
                    return _toStringAccountId(
                            &m->basic.multitokens_force_approve_collection_V2.operator_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* multitokens_force_approve_collection_V2 - expiration */;
                    return _toStringOptionu32(
                            &m->basic.multitokens_force_approve_collection_V2.expiration,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64798: /* module 253 call 30 */
            switch (itemIdx) {
//                case 0: /* multitokens_force_freeze_V2 - info */;
//                    return _toStringFreezeInfo(
//                            &m->basic.multitokens_force_freeze_V2.info,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64799: /* module 253 call 31 */
            switch (itemIdx) {
                case 0: /* multitokens_force_set_next_collection_id_V2 - value */;
                    return _toStringCompactCollectionId(
                            &m->basic.multitokens_force_set_next_collection_id_V2.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64800: /* module 253 call 32 */
            switch (itemIdx) {
//                case 0: /* multitokens_claim_collections_V2 - destination */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_claim_collections_V2.destination,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_claim_collections_V2 - ethereum_signature */;
//                    return _toStringEthereumSignature(
//                            &m->basic.multitokens_claim_collections_V2.ethereum_signature,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_claim_collections_V2 - ethereum_address */;
//                    return _toStringEthereumAddress(
//                            &m->basic.multitokens_claim_collections_V2.ethereum_address,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 64801: /* module 253 call 33 */
            switch (itemIdx) {
//                case 0: /* multitokens_claim_tokens_V2 - destination */;
//                    return _toStringAccountId(
//                            &m->basic.multitokens_claim_tokens_V2.destination,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 1: /* multitokens_claim_tokens_V2 - ethereum_signature */;
//                    return _toStringEthereumSignature(
//                            &m->basic.multitokens_claim_tokens_V2.ethereum_signature,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
//                case 2: /* multitokens_claim_tokens_V2 - ethereum_address */;
//                    return _toStringEthereumAddress(
//                            &m->basic.multitokens_claim_tokens_V2.ethereum_address,
//                            outValue, outValueLen,
//                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
#ifdef SUBSTRATE_PARSER_FULL
        case 1541: /* module 6 call 5 */
            switch (itemIdx) {
                case 0: /* balances_force_unreserve_V24 - who */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_unreserve_V2.who,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_force_unreserve_V24 - amount */;
                    return _toStringBalance(
                            &m->basic.balances_force_unreserve_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1542: /* module 6 call 6 */
            switch (itemIdx) {
                case 0: /* balances_upgrade_accounts_V24 - who */;
                    return _toStringVecAccountId(
                            &m->basic.balances_upgrade_accounts_V2.who,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1544: /* module 6 call 8 */
            switch (itemIdx) {
                case 0: /* balances_force_set_balance_V24 - who */;
                    return _toStringAccountIdLookupOfT(
                            &m->basic.balances_force_set_balance_V2.who,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* balances_force_set_balance_V24 - new_free */;
                    return _toStringCompactBalance(
                            &m->basic.balances_force_set_balance_V2.new_free,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2304: /* module 9 call 0 */
            switch (itemIdx) {
                case 0: /* staking_bond_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->nested.staking_bond_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* staking_bond_V2 - payee */;
                    return _toStringRewardDestination(
                            &m->nested.staking_bond_V2.payee,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2305: /* module 9 call 1 */
            switch (itemIdx) {
                case 0: /* staking_bond_extra_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->nested.staking_bond_extra_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2306: /* module 9 call 2 */
            switch (itemIdx) {
                case 0: /* staking_unbond_V2 - amount */;
                    return _toStringCompactBalance(
                            &m->nested.staking_unbond_V2.amount,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2307: /* module 9 call 3 */
            switch (itemIdx) {
                case 0: /* staking_withdraw_unbonded_V2 - num_slashing_spans */;
                    return _toStringu32(
                            &m->nested.staking_withdraw_unbonded_V2.num_slashing_spans,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2308: /* module 9 call 4 */
            switch (itemIdx) {
                case 0: /* staking_validate_V2 - prefs */;
                    return _toStringValidatorPrefs(
                            &m->basic.staking_validate_V2.prefs,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2309: /* module 9 call 5 */
            switch (itemIdx) {
                case 0: /* staking_nominate_V2 - targets */;
                    return _toStringVecAccountIdLookupOfT(
                            &m->nested.staking_nominate_V2.targets,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2310: /* module 9 call 6 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2311: /* module 9 call 7 */
            switch (itemIdx) {
                case 0: /* staking_set_payee_V2 - payee */;
                    return _toStringRewardDestination(
                            &m->nested.staking_set_payee_V2.payee,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2312: /* module 9 call 8 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2313: /* module 9 call 9 */
            switch (itemIdx) {
                case 0: /* staking_set_validator_count_V2 - new_ */;
                    return _toStringCompactu32(
                            &m->basic.staking_set_validator_count_V2.new_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2314: /* module 9 call 10 */
            switch (itemIdx) {
                case 0: /* staking_increase_validator_count_V2 - additional */;
                    return _toStringCompactu32(
                            &m->basic.staking_increase_validator_count_V2.additional,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2315: /* module 9 call 11 */
            switch (itemIdx) {
                case 0: /* staking_scale_validator_count_V2 - factor */;
                    return _toStringPercent(
                            &m->basic.staking_scale_validator_count_V2.factor,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2316: /* module 9 call 12 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2317: /* module 9 call 13 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2318: /* module 9 call 14 */
            switch (itemIdx) {
                case 0: /* staking_set_invulnerables_V2 - invulnerables */;
                    return _toStringVecAccountId(
                            &m->basic.staking_set_invulnerables_V2.invulnerables,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2319: /* module 9 call 15 */
            switch (itemIdx) {
                case 0: /* staking_force_unstake_V2 - stash */;
                    return _toStringAccountId(
                            &m->basic.staking_force_unstake_V2.stash,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* staking_force_unstake_V2 - num_slashing_spans */;
                    return _toStringu32(
                            &m->basic.staking_force_unstake_V2.num_slashing_spans,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2320: /* module 9 call 16 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2321: /* module 9 call 17 */
            switch (itemIdx) {
                case 0: /* staking_cancel_deferred_slash_V2 - era */;
                    return _toStringEraIndex(
                            &m->basic.staking_cancel_deferred_slash_V2.era,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* staking_cancel_deferred_slash_V2 - slash_indices */;
                    return _toStringVecu32(
                            &m->basic.staking_cancel_deferred_slash_V2.slash_indices,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2322: /* module 9 call 18 */
            switch (itemIdx) {
                case 0: /* staking_payout_stakers_V2 - validator_stash */;
                    return _toStringAccountId(
                            &m->basic.staking_payout_stakers_V2.validator_stash,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* staking_payout_stakers_V2 - era */;
                    return _toStringEraIndex(
                            &m->basic.staking_payout_stakers_V2.era,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2323: /* module 9 call 19 */
            switch (itemIdx) {
                case 0: /* staking_rebond_V2 - value */;
                    return _toStringCompactBalance(
                            &m->nested.staking_rebond_V2.value,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2324: /* module 9 call 20 */
            switch (itemIdx) {
                case 0: /* staking_reap_stash_V2 - stash */;
                    return _toStringAccountId(
                            &m->basic.staking_reap_stash_V2.stash,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* staking_reap_stash_V2 - num_slashing_spans */;
                    return _toStringu32(
                            &m->basic.staking_reap_stash_V2.num_slashing_spans,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2325: /* module 9 call 21 */
            switch (itemIdx) {
                case 0: /* staking_kick_V2 - who */;
                    return _toStringVecAccountIdLookupOfT(
                            &m->basic.staking_kick_V2.who,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2326: /* module 9 call 22 */
            switch (itemIdx) {
                case 0: /* staking_set_staking_configs_V2 - min_nominator_bond */;
                    return _toStringConfigOpBalanceOfT(
                            &m->basic.staking_set_staking_configs_V2.min_nominator_bond,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* staking_set_staking_configs_V2 - min_validator_bond */;
                    return _toStringConfigOpBalanceOfT(
                            &m->basic.staking_set_staking_configs_V2.min_validator_bond,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* staking_set_staking_configs_V2 - max_nominator_count */;
                    return _toStringConfigOpu32(
                            &m->basic.staking_set_staking_configs_V2.max_nominator_count,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 3: /* staking_set_staking_configs_V2 - max_validator_count */;
                    return _toStringConfigOpu32(
                            &m->basic.staking_set_staking_configs_V2.max_validator_count,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 4: /* staking_set_staking_configs_V2 - chill_threshold */;
                    return _toStringConfigOpPercent(
                            &m->basic.staking_set_staking_configs_V2.chill_threshold,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 5: /* staking_set_staking_configs_V2 - min_commission */;
                    return _toStringConfigOpPerbill(
                            &m->basic.staking_set_staking_configs_V2.min_commission,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2327: /* module 9 call 23 */
            switch (itemIdx) {
                case 0: /* staking_chill_other_V2 - controller */;
                    return _toStringAccountId(
                            &m->basic.staking_chill_other_V2.controller,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2328: /* module 9 call 24 */
            switch (itemIdx) {
                case 0: /* staking_force_apply_min_commission_V2 - validator_stash */;
                    return _toStringAccountId(
                            &m->basic.staking_force_apply_min_commission_V2.validator_stash,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2329: /* module 9 call 25 */
            switch (itemIdx) {
                case 0: /* staking_set_min_commission_V2 - new_ */;
                    return _toStringPerbill(
                            &m->basic.staking_set_min_commission_V2.new_,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 4619: /* module 18 call 11 */
            switch (itemIdx) {
                case 0: /* nominationpools_set_configs_V2 - min_join_bond */;
                    return _toStringCompactBalance(
                            &m->basic.nominationpools_set_configs_V2.min_join_bond,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 1: /* nominationpools_set_configs_V2 - min_create_bond */;
                    return _toStringCompactBalance(
                            &m->basic.nominationpools_set_configs_V2.min_create_bond,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                case 2: /* nominationpools_set_configs_V2 - global_max_commission */;
                    return _toStringPerbill(
                            &m->basic.nominationpools_set_configs_V2.global_max_commission,
                            outValue, outValueLen,
                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        // case 4630: /* module 18 call 22 */ //TODO: Probably wrong
        //     switch (itemIdx) {
        //         case 0: /* nominationpools_set_staking_info_V2 - info */;
        //             return _toStringStakingInfo(
        //                     &m->basic.nominationpools_set_staking_info_V2.info,
        //                     outValue, outValueLen,
        //                     pageIdx, pageCount);
        //         default:
        //             return parser_no_data;
        //     }
#endif
        default:
            return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1795: // Staking:Withdraw Unbonded
            switch (itemIdx) {
                case 0: // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 1807: // Staking:Force unstake
            switch (itemIdx) {
                case 1: // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 1812: // Staking:Reap stash
            switch (itemIdx) {
                case 1: // Num slashing spans
                    return true;
                default:
                    return false;
            }
        default:
            return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2308: // Staking:Validate
        case 2313: // Staking:Set validator count
        case 2314: // Staking:Increase validator count
        case 2315: // Staking:Scale validator count
        case 2316: // Staking:Force no eras
        case 2317: // Staking:Force new era
        case 2318: // Staking:Set invulnerables
        case 2319: // Staking:Force unstake
        case 2320: // Staking:Force new era always
        case 2321: // Staking:Cancel deferred slash
        case 2322: // Staking:Payout stakers
        case 2324: // Staking:Reap stash
        case 2325: // Staking:Kick
        case 2328: // Staking:Force apply min commission
        case 2329: // Staking:Set min commission
        case 4611: // NominationPools:Unbond
        case 4612: // NominationPools:Pool withdraw unbonded
//        case 4608: // NominationPools:Create with pool id // TODO: Doesn't exists, only create
        // case 4616: // NominationPools:Nominate
        case 4621: // NominationPools:Chill
        case 4622: // NominationPools:Destroy
        case 4628: // NominationPools:Unbond deposit
        case 4629: // NominationPools:Withdraw deposit
//        case 4608: // NominationPools:Bond extra other // TODO: Doesnt exists, only bond

        default:
            return true;
    }
}
