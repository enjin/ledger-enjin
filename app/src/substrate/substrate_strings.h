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
extern "C" {
#endif

// Modules names
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_STAKING = "Staking";
static const char* STR_MO_NOMINATIONPOOLS = "Nominationpools";
static const char* STR_MO_STAKEEXCHANGE = "Stakeexchange";
static const char* STR_MO_MULTITOKENS = "Multitokens";

// Methods names
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_FREEZE = "Freeze";
static const char* STR_ME_TRANSFER_ALLOW_DEATH = "Transfer allow death";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_UPGRADE_ACCOUNTS = "Upgrade accounts";
static const char* STR_ME_FORCE_SET_BALANCE = "Force set balance";
static const char* STR_ME_BOND = "Bond";
static const char* STR_ME_BOND_EXTRA = "Bond extra";
static const char* STR_ME_UNBOND = "Unbond";
static const char* STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char* STR_ME_VALIDATE = "Validate";
static const char* STR_ME_NOMINATE = "Nominate";
static const char* STR_ME_CHILL = "Chill";
static const char* STR_ME_SET_PAYEE = "Set payee";
static const char* STR_ME_SET_CONTROLLER = "Set controller";
static const char* STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char* STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char* STR_ME_SCALE_VALIDATOR_COUNT = "Scale validator count";
static const char* STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char* STR_ME_FORCE_NEW_ERA = "Force new era";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char* STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char* STR_ME_CANCEL_DEFERRED_SLASH = "Cancel deferred slash";
static const char* STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char* STR_ME_REBOND = "Rebond";
static const char* STR_ME_REAP_STASH = "Reap stash";
static const char* STR_ME_KICK = "Kick";
static const char* STR_ME_SET_STAKING_CONFIGS = "Set staking configs";
static const char* STR_ME_CHILL_OTHER = "Chill other";
static const char* STR_ME_FORCE_APPLY_MIN_COMMISSION = "Force apply min commission";
static const char* STR_ME_SET_MIN_COMMISSION = "Set min commission";
static const char* STR_ME_CREATE_OFFER = "Create offer";
static const char* STR_ME_CANCEL_OFFER = "Cancel offer";
static const char* STR_ME_CONFIGURE_LIQUIDITY_ACCOUNT = "Configure liquidity account";
static const char* STR_ME_WITHDRAW_LIQUIDITY = "Withdraw liquidity";
static const char* STR_ME_ADD_LIQUIDITY = "Add liquidity";
static const char* STR_ME_BUY = "Buy";
static const char* STR_ME_MUTATE = "Mutate";
static const char* STR_ME_POOL_WITHDRAW_UNBONDED = "Pool withdraw unbonded";
static const char* STR_ME_CREATE = "Create";
static const char* STR_ME_DESTROY = "Destroy";
static const char* STR_ME_UNBOND_DEPOSIT = "Unbond deposit";
static const char* STR_ME_SET_STAKING_INFO = "Set staking info";
static const char* STR_ME_PAYOUT_REWARDS = "Payout rewards";
static const char* STR_ME_SET_CONFIGS = "Set configs";
static const char* STR_ME_WITHDRAW_DEPOSIT = "Withdraw deposit";
static const char* STR_ME_QUEUE_EARLY_BIRD_BONUS = "Queue early bird bonus";
static const char* STR_ME_DISTRIBUTE_EARLY_BIRD_BONUS = "Distribute early bird bonus";
static const char* STR_ME_CREATE_COLLECTION = "Create collection";
static const char* STR_ME_DESTROY_COLLECTION = "Destroy collection";
static const char* STR_ME_MUTATE_COLLECTION = "Mutate collection";
static const char* STR_ME_MUTATE_TOKEN = "Mutate token";
static const char* STR_ME_MINT = "Mint";
static const char* STR_ME_BURN = "Burn";
static const char* STR_ME_THAW = "Thaw";
static const char* STR_ME_SET_ATTRIBUTE = "Set attribute";
static const char* STR_ME_REMOVE_ATTRIBUTE = "Remove attribute";
static const char* STR_ME_REMOVE_ALL_ATTRIBUTES = "Remove all attributes";
static const char* STR_ME_BATCH_TRANSFER = "Batch transfer";
static const char* STR_ME_BATCH_MINT = "Batch mint";
static const char* STR_ME_BATCH_SET_ATTRIBUTE = "Batch set attribute";
static const char* STR_ME_APPROVE_COLLECTION = "Approve collection";
static const char* STR_ME_UNAPPROVE_COLLECTION = "Unapprove collection";
static const char* STR_ME_APPROVE_TOKEN = "Approve token";
static const char* STR_ME_UNAPPROVE_TOKEN = "Unapprove token";
static const char* STR_ME_FORCE_MUTATE_COLLECTION = "Force mutate collection";
static const char* STR_ME_FORCE_SET_COLLECTION = "Force set collection";
static const char* STR_ME_FORCE_SET_TOKEN = "Force set token";
static const char* STR_ME_FORCE_SET_ATTRIBUTE = "Force set attribute";
static const char* STR_ME_FORCE_SET_COLLECTION_ACCOUNT = "Force set collection account";
static const char* STR_ME_FORCE_SET_TOKEN_ACCOUNT = "Force set token account";
static const char* STR_ME_FORCE_CREATE_COLLECTION = "Force create collection";
static const char* STR_ME_FORCE_MINT = "Force mint";
static const char* STR_ME_FORCE_BURN = "Force burn";
static const char* STR_ME_FORCE_APPROVE_COLLECTION = "Force approve collection";
static const char* STR_ME_FORCE_FREEZE = "Force freeze";
static const char* STR_ME_FORCE_SET_NEXT_COLLECTION_ID = "Force set next collection id";
static const char* STR_ME_CLAIM_COLLECTIONS = "Claim collections";
static const char* STR_ME_CLAIM_TOKENS = "Claim tokens";

// Items names
static const char* STR_IT_new_ = "New";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_payee = "Payee";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_factor = "Factor";
static const char* STR_IT_invulnerables = "Invulnerables";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_slash_indices = "Slash indices";
static const char* STR_IT_validator_stash = "Validator stash";
static const char* STR_IT_min_nominator_bond = "Min nominator bond";
static const char* STR_IT_min_validator_bond = "Min validator bond";
static const char* STR_IT_max_nominator_count = "Max nominator count";
static const char* STR_IT_max_validator_count = "Max validator count";
static const char* STR_IT_chill_threshold = "Chill threshold";
static const char* STR_IT_min_commission = "Min commission";
static const char* STR_IT_token_id = "Token id";
static const char* STR_IT_deposit = "Deposit";
static const char* STR_IT_capacity = "Capacity";
static const char* STR_IT_admin = "Admin";
static const char* STR_IT_mutation = "Mutation";
static const char* STR_IT_transfer_count = "Transfer count";
static const char* STR_IT_offer = "Offer";
static const char* STR_IT_offer_id = "Offer id";
static const char* STR_IT_owner = "Owner";
static const char* STR_IT_ethereum_signature = "Ethereum signature";
static const char* STR_IT_info = "Info";
static const char* STR_IT_pool_id = "Pool id";
static const char* STR_IT_member_account = "Member account";
static const char* STR_IT_unbonding_points = "Unbonding points";
static const char* STR_IT_nominator = "Nominator";
static const char* STR_IT_validators = "Validators";
static const char* STR_IT_min_join_bond = "Min join bond";
static const char* STR_IT_min_create_bond = "Min create bond";
static const char* STR_IT_global_max_commission = "Global max commission";
static const char* STR_IT_duration = "Duration";
static const char* STR_IT_value = "Value";
static const char* STR_IT_descriptor = "Descriptor";
static const char* STR_IT_collection_id = "Collection id";
static const char* STR_IT_recipient = "Recipient";
static const char* STR_IT_params = "Params";
static const char* STR_IT_key = "Key";
static const char* STR_IT_attribute_count = "Attribute count";
static const char* STR_IT_attributes = "Attributes";
static const char* STR_IT_operator = "Operator";
static const char* STR_IT_expiration = "Expiration";
static const char* STR_IT_current_amount = "Current amount";
static const char* STR_IT_destination = "Destination";
static const char* STR_IT_account_id = "Account id";
static const char* STR_IT_caller = "Caller";
static const char* STR_IT_deposit_backer = "Deposit backer";
static const char* STR_IT_ethereum_address = "Ethereum address";
static const char* STR_IT_recipients = "Recipients";
static const char* STR_IT_config = "Config";

#ifdef __cplusplus
}
#endif
