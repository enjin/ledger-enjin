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

#include <stddef.h>
#include <stdint.h>

// Common read functions

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v);
parser_error_t _readu8(parser_context_t* c, pd_u8_t* v);
parser_error_t _readu16(parser_context_t* c, pd_u16_t* v);
parser_error_t _readu32(parser_context_t* c, pd_u32_t* v);
parser_error_t _readu64(parser_context_t* c, pd_u64_t* v);
parser_error_t _readu128(parser_context_t* c, pd_u128_t* v);
parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v);
parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v);
parser_error_t _readCompactu64(parser_context_t* c, pd_Compactu64_t* v);
parser_error_t _readCallImpl(parser_context_t* c, pd_Call_t* v, pd_MethodNested_t* m);
parser_error_t _readu8_array_32(parser_context_t* c, pd_u8_array_32_t* v);
parser_error_t _readByFork(parser_context_t* c, pd_ByFork_t* v);
parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v);
parser_error_t _readOptionBytes(parser_context_t* c, pd_OptionBytes_t* v);
parser_error_t _readOptionAttributeOf(parser_context_t* c, pd_OptionAttributeOf_t* v);
parser_error_t _readVecAttributeKeyValuePair(parser_context_t* c, pd_VecAttributeKeyValuePair_t* v);
parser_error_t _readVecMintRecipientsOf(parser_context_t* c, pd_VecMintRecipientsOf_t* v);
parser_error_t _readVecTransferRecipientsOf(parser_context_t* c, pd_VecTransferRecipientsOf_t* v);
parser_error_t _readFraction(parser_context_t* c, pd_Fraction_t* v);
parser_error_t _readNetworkIdV3(parser_context_t* c, pd_NetworkIdV3_t* v);
parser_error_t _readBodyIdV2(parser_context_t* c, pd_BodyIdV2_t* v);
parser_error_t _readBodyIdV3(parser_context_t* c, pd_BodyIdV3_t* v);
parser_error_t _readBodyPart(parser_context_t* c, pd_BodyPart_t* v);
parser_error_t _readNetworkIdV2(parser_context_t* c, pd_NetworkIdV2_t* v);
parser_error_t _readOptionNetworkIdV3(parser_context_t* c, pd_OptionNetworkIdV3_t* v);
parser_error_t _readu8_array_20(parser_context_t* c, pd_u8_array_20_t* v);
parser_error_t _readAccountId32V2(parser_context_t* c, pd_AccountId32V2_t* v);
parser_error_t _readAccountId32V3(parser_context_t* c, pd_AccountId32V3_t* v);
parser_error_t _readAccountIndex64V2(parser_context_t* c, pd_AccountIndex64V2_t* v);
parser_error_t _readAccountIndex64V3(parser_context_t* c, pd_AccountIndex64V3_t* v);
parser_error_t _readAccountKey20V2(parser_context_t* c, pd_AccountKey20V2_t* v);
parser_error_t _readAccountKey20V3(parser_context_t* c, pd_AccountKey20V3_t* v);
parser_error_t _readCompactu128(parser_context_t* c, pd_Compactu128_t* v);
parser_error_t _readGeneralKeyV3(parser_context_t* c, pd_GeneralKeyV3_t* v);
parser_error_t _readPluralityV2(parser_context_t* c, pd_PluralityV2_t* v);
parser_error_t _readPluralityV3(parser_context_t* c, pd_PluralityV3_t* v);
parser_error_t _readJunctionV2(parser_context_t* c, pd_JunctionV2_t* v);
parser_error_t _readJunctionV3(parser_context_t* c, pd_JunctionV3_t* v);
parser_error_t _readJunctionV2X1(parser_context_t* c, pd_JunctionV2X1_t* v);
parser_error_t _readJunctionV2X2(parser_context_t* c, pd_JunctionV2X2_t* v);
parser_error_t _readJunctionV2X3(parser_context_t* c, pd_JunctionV2X3_t* v);
parser_error_t _readJunctionV2X4(parser_context_t* c, pd_JunctionV2X4_t* v);
parser_error_t _readJunctionV2X5(parser_context_t* c, pd_JunctionV2X5_t* v);
parser_error_t _readJunctionV2X6(parser_context_t* c, pd_JunctionV2X6_t* v);
parser_error_t _readJunctionV2X7(parser_context_t* c, pd_JunctionV2X7_t* v);
parser_error_t _readJunctionV2X8(parser_context_t* c, pd_JunctionV2X8_t* v);
parser_error_t _readJunctionV3X1(parser_context_t* c, pd_JunctionV3X1_t* v);
parser_error_t _readJunctionV3X2(parser_context_t* c, pd_JunctionV3X2_t* v);
parser_error_t _readJunctionV3X3(parser_context_t* c, pd_JunctionV3X3_t* v);
parser_error_t _readJunctionV3X4(parser_context_t* c, pd_JunctionV3X4_t* v);
parser_error_t _readJunctionV3X5(parser_context_t* c, pd_JunctionV3X5_t* v);
parser_error_t _readJunctionV3X6(parser_context_t* c, pd_JunctionV3X6_t* v);
parser_error_t _readJunctionV3X7(parser_context_t* c, pd_JunctionV3X7_t* v);
parser_error_t _readJunctionV3X8(parser_context_t* c, pd_JunctionV3X8_t* v);
parser_error_t _readJunctionsV2(parser_context_t* c, pd_JunctionsV2_t* v);
parser_error_t _readJunctionsV3(parser_context_t* c, pd_JunctionsV3_t* v);
parser_error_t _readAssetInstanceV2(parser_context_t* c, pd_AssetInstanceV2_t* v);
parser_error_t _readAssetInstanceV3(parser_context_t* c, pd_AssetInstanceV3_t* v);
parser_error_t _readMultiLocationV2(parser_context_t* c, pd_MultiLocationV2_t* v);
parser_error_t _readOfferId(parser_context_t* c, pd_OfferId_t* v);
parser_error_t _readOfferOfT(parser_context_t* c, pd_OfferOfT_t* v);
parser_error_t _readTokenId(parser_context_t* c, pd_TokenId_t* v);
parser_error_t _readTransferParamsOfT(parser_context_t* c, pd_TransferParamsOfT_t* v);
parser_error_t _readFreezeOf(parser_context_t* c, pd_FreezeOf_t* v);
parser_error_t _readMintParamsOf(parser_context_t* c, pd_MintParamsOf_t* v);
parser_error_t _readOptionTokenId(parser_context_t* c, pd_OptionTokenId_t* v);
parser_error_t _readCollectionId(parser_context_t* c, pd_CollectionId_t* v);
parser_error_t _readCollectionDescriptor(parser_context_t* c, pd_CollectionDescriptor_t* v);
parser_error_t _readOptionCollectionOf(parser_context_t* c, pd_OptionCollectionOf_t* v);
parser_error_t _readOptionCollectionAccountOf(parser_context_t* c, pd_OptionCollectionAccountOf_t* v);
parser_error_t _readCompactCollectionId(parser_context_t* c, pd_CompactCollectionId_t* v);
parser_error_t _readCollectionMutation(parser_context_t* c, pd_CollectionMutation_t* v);
parser_error_t _readTokenMutation(parser_context_t* c, pd_TokenMutation_t* v);
parser_error_t _readCompactTokenId(parser_context_t* c, pd_CompactTokenId_t* v);
parser_error_t _readTokenIdOf(parser_context_t* c, pd_TokenIdOf_t* v);
parser_error_t _readOptionTokenOf(parser_context_t* c, pd_OptionTokenOf_t* v);
parser_error_t _readOptionTokenAccountOf(parser_context_t* c, pd_OptionTokenAccountOf_t* v);
parser_error_t _readMultiLocationV3(parser_context_t* c, pd_MultiLocationV3_t* v);
parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v);
parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v);
parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v);
parser_error_t _readCompactAccountIndex(parser_context_t* c, pd_CompactAccountIndex_t* v);
parser_error_t _readEcdsaPublic(parser_context_t* c, pd_EcdsaPublic_t* v);
parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v);
parser_error_t _readEd25519Public(parser_context_t* c, pd_Ed25519Public_t* v);
parser_error_t _readEd25519Signature(parser_context_t* c, pd_Ed25519Signature_t* v);
parser_error_t _readH256(parser_context_t* c, pd_H256_t* v);
parser_error_t _readParaId(parser_context_t* c, pd_ParaId_t* v);
parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v);
parser_error_t _readSr25519Public(parser_context_t* c, pd_Sr25519Public_t* v);
parser_error_t _readSr25519Signature(parser_context_t* c, pd_Sr25519Signature_t* v);
parser_error_t _readTupleu32u32(parser_context_t* c, pd_Tupleu32u32_t* v);
parser_error_t _readVote(parser_context_t* c, pd_Vote_t* v);
parser_error_t _readAccountIdLookupOfT(parser_context_t* c, pd_AccountIdLookupOfT_t* v);
parser_error_t _readOptionAccountIdLookupOfT(parser_context_t* c, pd_OptionAccountIdLookupOfT_t* v);
parser_error_t _readCall(parser_context_t* c, pd_Call_t* v);
parser_error_t _readCompactPerbill(parser_context_t* c, pd_CompactPerbill_t* v);
parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v);
parser_error_t _readConfigOpBalanceOfT(parser_context_t* c, pd_ConfigOpBalanceOfT_t* v);
parser_error_t _readConfigOpPerbill(parser_context_t* c, pd_ConfigOpPerbill_t* v);
parser_error_t _readConfigOpPercent(parser_context_t* c, pd_ConfigOpPercent_t* v);
parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v);
parser_error_t _readBondValueOfT(parser_context_t* c, pd_BondValueOfT_t* v);
parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v);
parser_error_t _readVecAccountIdLookupOfT(parser_context_t* c, pd_VecAccountIdLookupOfT_t* v);
parser_error_t _readStakingInfo(parser_context_t* c, pd_StakingInfo_t* v);
parser_error_t _readLiquidityAccountConfigOfT(parser_context_t* c, pd_LiquidityAccountConfigOfT_t * v);
parser_error_t _readBurnParamsOfT(parser_context_t* c, pd_BurnParamsOfT_t * v);
parser_error_t _readConfigOpu32(parser_context_t* c, pd_ConfigOpu32_t* v);
parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v);
parser_error_t _readEthereumAddress(parser_context_t* c, pd_EthereumAddress_t* v);
parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v);
parser_error_t _readOptionAccountId(parser_context_t* c, pd_OptionAccountId_t* v);
parser_error_t _readOptionu32(parser_context_t* c, pd_Optionu32_t* v);
parser_error_t _readOptionu128(parser_context_t* c, pd_Optionu128_t* v);
parser_error_t _readPoolId(parser_context_t* c, pd_PoolId_t* v);
parser_error_t _readPoolMutationOfT(parser_context_t* c, pd_PoolMutationOfT_t* v);
parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v);
parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v);
parser_error_t _readVecu8(parser_context_t* c, pd_Vecu8_t* v);

// Common toString functions

parser_error_t _toStringu8(
    const pd_u8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu16(
    const pd_u16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu32(
    const pd_u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu64(
    const pd_u64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu128(
        const pd_u128_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringbool(
    const pd_bool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32(
    const pd_u8_array_32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringByFork(
    const pd_ByFork_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBytes(
    const pd_Bytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);


parser_error_t _toStringOptionBytes(
        const pd_OptionBytes_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringOptionAttributeOf(
        const pd_OptionAttributeOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringVecAttributeKeyValuePair(
        const pd_VecAttributeKeyValuePair_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringFraction(
    const pd_Fraction_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkIdV3(
    const pd_NetworkIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyIdV2(
    const pd_BodyIdV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyIdV3(
    const pd_BodyIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart(
    const pd_BodyPart_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkIdV2(
    const pd_NetworkIdV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionNetworkIdV3(
    const pd_OptionNetworkIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_20(
    const pd_u8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32V2(
    const pd_AccountId32V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32V3(
    const pd_AccountId32V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64V2(
    const pd_AccountIndex64V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64V3(
    const pd_AccountIndex64V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20V2(
    const pd_AccountKey20V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20V3(
    const pd_AccountKey20V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu128(
    const pd_Compactu128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGeneralKeyV3(
    const pd_GeneralKeyV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPluralityV2(
    const pd_PluralityV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPluralityV3(
    const pd_PluralityV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2(
    const pd_JunctionV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3(
    const pd_JunctionV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X1(
    const pd_JunctionV2X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X2(
    const pd_JunctionV2X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X3(
    const pd_JunctionV2X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X4(
    const pd_JunctionV2X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X5(
    const pd_JunctionV2X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X6(
    const pd_JunctionV2X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X7(
    const pd_JunctionV2X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X8(
    const pd_JunctionV2X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X1(
    const pd_JunctionV3X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X2(
    const pd_JunctionV3X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X3(
    const pd_JunctionV3X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X4(
    const pd_JunctionV3X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X5(
    const pd_JunctionV3X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X6(
    const pd_JunctionV3X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X7(
    const pd_JunctionV3X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X8(
    const pd_JunctionV3X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV2(
    const pd_JunctionsV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV3(
    const pd_JunctionsV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstanceV2(
    const pd_AssetInstanceV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstanceV3(
    const pd_AssetInstanceV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV2(
    const pd_MultiLocationV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV3(
    const pd_MultiLocationV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalance(
    const pd_Balance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOf(
    const pd_BalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex(
    const pd_CompactAccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaPublic(
    const pd_EcdsaPublic_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Public(
    const pd_Ed25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature(
    const pd_Ed25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringH256(
    const pd_H256_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill(
    const pd_Perbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Public(
    const pd_Sr25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature(
    const pd_Sr25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT(
    const pd_AccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountIdLookupOfT(
        const pd_OptionAccountIdLookupOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringCall(
    const pd_Call_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerbill(
    const pd_CompactPerbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent(
    const pd_Percent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT(
    const pd_ConfigOpBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill(
    const pd_ConfigOpPerbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent(
    const pd_ConfigOpPercent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBondValueOfT(
        const pd_BondValueOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountIdLookupOfT(
    const pd_VecAccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStakingInfo(
        const pd_StakingInfo_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringBurnParamsOfT(
        const pd_BurnParamsOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringLiquidityAccountConfigOfT(
        const pd_LiquidityAccountConfigOfT_t * v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringConfigOpu32(
    const pd_ConfigOpu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress(
    const pd_EthereumAddress_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId(
    const pd_OptionAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionu32(
    const pd_Optionu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolId(
    const pd_PoolId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPoolMutationOfT(
        const pd_PoolMutationOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringOfferId(
        const pd_OfferId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringOfferOfT(
        const pd_OfferOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringCompactCollectionId(
        const pd_CompactCollectionId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringCollectionMutation(
        const pd_CollectionMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringOptionCollectionOf(
        const pd_OptionCollectionOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringOptionCollectionAccountOf(
        const pd_OptionCollectionAccountOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringCompactTokenId(
        const pd_CompactTokenId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringOptionTokenId(
        const pd_OptionTokenId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringTokenId(
        const pd_TokenId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringTransferParamsOfT(
        const pd_TransferParamsOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringFreezeOf(
        const pd_FreezeOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringCollectionDescriptor(
        const pd_CollectionDescriptor_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringMintParamsOf(
        const pd_MintParamsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringVecMintRecipientsOf(
        const pd_VecMintRecipientsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringVecTransferRecipientsOf(
        const pd_VecTransferRecipientsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringTokenIdOf(
        const pd_TokenIdOf_t * v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);


parser_error_t _toStringOptionTokenOf(
        const pd_OptionTokenOf_t * v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringOptionTokenAccountOf(
        const pd_OptionTokenAccountOf_t * v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringTokenMutation(
        const pd_TokenMutation_t * v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount);

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu32(
    const pd_Vecu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu8(
    const pd_Vecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
