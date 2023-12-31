# Ledger Enjin Blockchain App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-polkadot/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-polkadot/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Enjin Blockchain app (https://enjin.io) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

# Enjin Blockchain 2.101.x

## Balances

| Name                   | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                  |
| ---------------------- |--------------------| ------------------ | ------------------ |---------| ------------------------------------------------------------------------------------------ |
| Transfer allow death   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Force transfer         |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Transfer               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Force unreserve        |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |
| Upgrade accounts       |                    | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`who<br/>                                                                     |
| Force set balance      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                                  |

## StakeExchange

| Name                        | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                            |
|-----------------------------|--------------------|--------------------|--------------------|---------|----------------------------------------------------------------------|
| Add liquidity               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `OfferId`offer_id<br/>`BalanceOf`amount<br/>                         |
| Buy                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `OfferId`offer_id<br/>`BalanceOf`amount<br/>`TokenIdOf`token_id<br/> |
| Cancel offer                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `OfferId`offer_id<br/>                                               |
| Configure liquidity account | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `LiquidityAccountConfigOf`config<br/>                                |
| Create offer                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `OfferOf`offer<br/>                                                  |
| Withdraw liquidity          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `OfferId`offer_id<br/>`BalanceOf`amount<br/>                         |

## Staking

| Name                       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                                                                                 |
|----------------------------|--------------------|--------------------|--------------------|---------| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bond                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`RewardDestination`payee<br/>                                                                                                                                                                                  |
| Bond extra                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Unbond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Withdraw Unbonded          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `u32`num_slashing_spans<br/>                                                                                                                                                                                                              |
| Validate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `ValidatorPrefs`prefs<br/>                                                                                                                                                                                                                |
| Nominate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountIdLookupOfT`targets<br/>                                                                                                                                                                                                       |
| Chill                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                                                                                                                           |
| Set payee                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `RewardDestination`payee<br/>                                                                                                                                                                                                             |
| Set controller             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                                                                                                                           |
| Set validator count        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`new\_<br/>                                                                                                                                                                                                                    |
| Increase validator count   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`additional<br/>                                                                                                                                                                                                               |
| Scale validator count      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Percent`factor<br/>                                                                                                                                                                                                                      |
| Force no eras              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                                                                                                                           |
| Force new era              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                                                                                                                           |
| Set invulnerables          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`invulnerables<br/>                                                                                                                                                                                                          |
| Force unstake              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Force new era always       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                                                                                                                           |
| Cancel deferred slash      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                                                                                                                              |
| Payout stakers             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                                                                                         |
| Rebond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Reap stash                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Kick                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountIdLookupOfT`who<br/>                                                                                                                                                                                                           |
| Set staking configs        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `ConfigOpBalanceOfT`min_nominator_bond<br/>`ConfigOpBalanceOfT`min_validator_bond<br/>`ConfigOpu32`max_nominator_count<br/>`ConfigOpu32`max_validator_count<br/>`ConfigOpPercent`chill_threshold<br/>`ConfigOpPerbill`min_commission<br/> |
| Chill other                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`controller<br/>                                                                                                                                                                                                                |
| Force apply min commission | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`validator_stash<br/>                                                                                                                                                                                                           |
| Set min commission         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Perbill`new\_<br/>                                                                                                                                                                                                                       |

## MultiTokens

| Name                         | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                           |
|------------------------------|--------------------|--------------------|--------------------|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Approve collection           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountId`operator<br/>`Expiration`expiration<br/>                                                                                 |
| Approve token                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`AccountId`operator<br/>`TokenBalance`amount<br/>`Expiration`expiration<br/>`TokenBalance`current_amount<br/> |
| Batch mint                   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`VecMintRecipientsOf`recipients<br/>                                                                                                |
| Batch set attribute          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`VecAttributesOf`attributes<br/>                                                                              |
| Batch transfer               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`VecTransferRecipientsOf`recipients<br/>                                                                                            |
| Burn                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`BurnParamsOf`params<br/>                                                                                                           |
| Claim collections            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`destination<br/>`SpCoreEcdsaSignature`ethereum_signature<br/>`H160`ethereum_address<br/>                                                                 |
| Claim tokens                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`destination<br/>`SpCoreEcdsaSignature`ethereum_signature<br/>`H160`ethereum_address<br/>                                                                 |
| Create collection            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionDescriptor`descriptor<br/>                                                                                                                               |
| Destroy collection           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>                                                                                                                                    |
| Force approve collection     |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountId`operator<br/>`Expiration`expiration<br/>                                                                                 |
| Force burn                   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`BurnParamsOf`params<br/>                                                                                                           |
| Force create collection      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionDescriptor`descriptor<br/>                                                                                                                               |
| Force freeze                 |                    | :heavy_check_mark: | :heavy_check_mark: |         | `FreezeOf`info                                                                                                                                                      |
| Force mint                   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`recipient<br/>`CollectionId`collectionId<br/>`MintParamsOf`params<br/>                                                                         |
| Force mutate collection      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`CollectionMutation`mutation<br/>                                                                                                   |
| Force set attribute          |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`Bytes`key<br/>`Bytes`value<br/>                                                                              |
| Force set collection         |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`CollectionOf`value<br/>                                                                                                            |
| Force set collection account |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountIdLookupOfT`account_id<br/>`CollectionAccountOf`value<br/>                                                                  |
| Force set next collection id |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`value<br/>                                                                                                                                            |
| Force set token              |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`TokenOf`value<br/>                                                                                           |
| Force set token account      |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`AccountIdLookupOfT`account_id<br/>`TokenAccountOf`value<br/>                                                 |
| Force transfer               |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`destination<br/>`CollectionId`collectionId<br/>`TransferParamsOf`params<br/>                                    |
| Freeze                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `FreezeOf`info                                                                                                                                                      |
| Mint                         |                    | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`recipient<br/>`CollectionId`collectionId<br/>`MintParamsOf`params<br/>                                                                         |
| Mutate collection            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`CollectionMutation`mutation<br/>                                                                                                   |
| Mutate token                 |                    | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`TokenMutation`mutation<br/>                                                                                  |
| Remove all attributes        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`u32`attribute_count<br/>                                                                                     |
| Remove attribute             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`Bytes`key<br/>                                                                                               |
| Set attribute                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`Bytes`key<br/>`Bytes`value<br/>                                                                              |
| Thaw                         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `FreezeOf`info<br/>                                                                                                                                                 |
| Transfer                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`recipient<br/>`CollectionId`collectionId<br/>`TransferParamsOf`params<br/>                                                                     |
| Unapprove collection         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`AccountId`operator<br/>                                                                                                            |
| Unapprove token              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collectionId<br/>`TokenId`token_id<br/>`AccountId`operator<br/>                                                                                      |

## NominationPools

| Name                        | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                           |
|-----------------------------|--------------------|--------------------|--------------------|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Bond                        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>`BondValueOf`amount<br/>                                                                                                                        |
| Chill                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>                                                                                                                                                |
| Create                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `TokenIdOf`token_id<br/>`CompactBalance`deposit<br/>`CompactBalance`capacity<br/>`EraIndex`duration<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`nominator<br/> |
| Destroy                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>                                                                                                                                                |
| Distribute early bird bonus | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `u32`transfer_count<br/>                                                                                                                                            |
| Mutate                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>`PoolMutationOf`mutation                                                                                                                        |
| Nominate                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>`VecAccountId`validators<br/>                                                                                                                   |
| Payout rewards              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                   |
| Pool withdraw unbonded      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>`u32`num_slashing_spans<br/>                                                                                                                    |
| Queue early bird bonus      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                                                     |
| Set configs                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `ConfigOpBalance`min_join_bond<br/>`ConfigOpBalance`min_create_bond<br/>`ConfigOpPerbill`global_max_comission<br/>                                                        |
| Set staking info            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `StakingInfo`info<br/>                                                                                                                                              |
| Unbond                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>`AccountIdLookupOfT`member_account<br/>`CompactBalance`unbonding_points<br/>                                                                    |
| Unbond deposit              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>                                                                                                                                                |
| Withdraw deposit            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>                                                                                                                                                |
| Withdraw unbonded           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `PoolId`pool_id<br/>`AccountIdLookupOfT`member_account<br/>`u32`num_slashing_spans<br/>                                                                             |
