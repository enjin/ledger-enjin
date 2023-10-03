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

#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v)
{
    return _readUInt8(c, v);
}

parser_error_t _readu8(parser_context_t* c, pd_u8_t* v)
{
    return _readUInt8(c, v);
}

parser_error_t _readu16(parser_context_t* c, pd_u16_t* v)
{
    return _readUInt16(c, v);
}

parser_error_t _readu32(parser_context_t* c, pd_u32_t* v)
{
    return _readUInt32(c, v);
}

parser_error_t _readu64(parser_context_t* c, pd_u64_t* v)
{
    return _readUInt64(c, v);
}

parser_error_t _readu128(parser_context_t* c, pd_u128_t* v) {
    GEN_DEF_READARRAY(16)
}

parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v)
{
    return _readUInt32(c, v);
}

parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactu64(parser_context_t* c, pd_Compactu64_t* v)
{
    return _readCompactInt(c, v);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
parser_error_t _readCompactu128(parser_context_t* c, pd_Compactu128_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readu8_array_32(parser_context_t* c, pd_u8_array_32_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readByFork(parser_context_t* c, pd_ByFork_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->blockNumber))
    CHECK_ERROR(_readu8_array_32(c, &v->blockHash))
    return parser_ok;
}

parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);
    return parser_ok;
}

parser_error_t _readOptionBytes(parser_context_t* c, pd_OptionBytes_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBytes(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readAttributeOf(parser_context_t* c, pd_AttributeOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBytes(c, &v->value))
    CHECK_ERROR(_readCompactu128(c, &v->deposit))
    return parser_ok;
}

parser_error_t _readOptionAttributeOf(parser_context_t* c, pd_OptionAttributeOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAttributeOf(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readFraction(parser_context_t* c, pd_Fraction_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->nom))
    CHECK_ERROR(_readCompactu32(c, &v->denom))
    return parser_ok;
}

parser_error_t _readNetworkIdV3(parser_context_t* c, pd_NetworkIdV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // ByGenesis
        CHECK_ERROR(_readu8_array_32(c, &v->byGenesis))
        break;
    case 1: // ByFork
        CHECK_ERROR(_readByFork(c, &v->byFork))
        break;
    case 7: // Ethereum
        CHECK_ERROR(_readCompactu64(c, &v->chainId))
        break;
    case 2: // Polkadot
    case 3: // Kusama
    case 4: // Westend
    case 5: // Rococo
    case 6: // Wococo
    case 8: // BitcoinCore
    case 9: // BitcoinCash
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBodyIdV2(parser_context_t* c, pd_BodyIdV2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unit
        break;
    case 1: // Named
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    case 2: // Index
        CHECK_ERROR(_readCompactu32(c, &v->index))
        break;
    case 3: // Executive
    case 4: // Technical
    case 5: // Legislative
    case 6: // Judicial
    case 7: // Defense
    case 8: // Administration
    case 9: // Treasury
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBodyIdV3(parser_context_t* c, pd_BodyIdV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Unit
        break;
    case 1: // Moniker
        GEN_DEF_READARRAY(4)
        break;
    case 2: // Index
        CHECK_ERROR(_readCompactu32(c, &v->index))
        break;
    case 3: // Executive
    case 4: // Technical
    case 5: // Legislative
    case 6: // Judicial
    case 7: // Defense
    case 8: // Administration
    case 9: // Treasury
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBodyPart(parser_context_t* c, pd_BodyPart_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Voice
        break;
    case 1: // Members
        CHECK_ERROR(_readCompactu32(c, &v->count))
        break;
    case 2: // Fraction
    case 3: // AtleastProportion
    case 4: // MoreThanProportion
        CHECK_ERROR(_readFraction(c, &v->fraction))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readNetworkIdV2(parser_context_t* c, pd_NetworkIdV2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Any
    case 2: // Polkadot
    case 3: // Kusama
        break;
    case 1: // Index
        CHECK_ERROR(_readBytes(c, &v->named))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readu8_array_20(parser_context_t* c, pd_u8_array_20_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readAccountId32V2(parser_context_t* c, pd_AccountId32V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkIdV2(c, &v->networkId))
    CHECK_ERROR(_readu8_array_32(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountId32V3(parser_context_t* c, pd_AccountId32V3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionNetworkIdV3(c, &v->networkId))
    CHECK_ERROR(_readu8_array_32(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountIndex64V2(parser_context_t* c, pd_AccountIndex64V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkIdV2(c, &v->networkId))
    CHECK_ERROR(_readCompactu64(c, &v->index))
    return parser_ok;
}

parser_error_t _readAccountIndex64V3(parser_context_t* c, pd_AccountIndex64V3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionNetworkIdV3(c, &v->networkId))
    CHECK_ERROR(_readCompactu64(c, &v->index))
    return parser_ok;
}

parser_error_t _readAccountKey20V2(parser_context_t* c, pd_AccountKey20V2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNetworkIdV2(c, &v->networkId))
    CHECK_ERROR(_readu8_array_20(c, &v->key))
    return parser_ok;
}

parser_error_t _readAccountKey20V3(parser_context_t* c, pd_AccountKey20V3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionNetworkIdV3(c, &v->networkId))
    CHECK_ERROR(_readu8_array_20(c, &v->key))
    return parser_ok;
}

parser_error_t _readGeneralKeyV3(parser_context_t* c, pd_GeneralKeyV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->length))
    CHECK_ERROR(_readu8_array_32(c, &v->data))
    return parser_ok;
}

parser_error_t _readPluralityV2(parser_context_t* c, pd_PluralityV2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBodyIdV2(c, &v->id))
    CHECK_ERROR(_readBodyPart(c, &v->part))
    return parser_ok;
}

parser_error_t _readPluralityV3(parser_context_t* c, pd_PluralityV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBodyIdV3(c, &v->id))
    CHECK_ERROR(_readBodyPart(c, &v->part))
    return parser_ok;
}

parser_error_t _readJunctionV2(parser_context_t* c, pd_JunctionV2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_readAccountId32V2(c, &v->accountId32))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64V2(c, &v->accountIndex64))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_readAccountKey20V2(c, &v->accountKey20))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_readBytes(c, &v->generalKey))
        break;
    case 7: // OnlyChild
        break;
    case 8: // Plurality
        CHECK_ERROR(_readPluralityV2(c, &v->plurality))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionV3(parser_context_t* c, pd_JunctionV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_readCompactu32(c, &v->parachain))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_readAccountId32V3(c, &v->accountId32))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_readAccountIndex64V3(c, &v->accountIndex64))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_readAccountKey20V3(c, &v->accountKey20))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_readUInt8(c, &v->palletInstance))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_readCompactu128(c, &v->generalIndex))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_readGeneralKeyV3(c, &v->generalKey))
        break;
    case 7: // OnlyChild
        break;
    case 8: // Plurality
        CHECK_ERROR(_readPluralityV3(c, &v->plurality))
        break;
    case 9: // GlobalConsensus
        CHECK_ERROR(_readNetworkIdV3(c, &v->globalConsensus))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionV2X1(parser_context_t* c, pd_JunctionV2X1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV2X2(parser_context_t* c, pd_JunctionV2X2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV2(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV2X3(parser_context_t* c, pd_JunctionV2X3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV2(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV2X4(parser_context_t* c, pd_JunctionV2X4_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV2(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV2X5(parser_context_t* c, pd_JunctionV2X5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV2(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV2X6(parser_context_t* c, pd_JunctionV2X6_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV2(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV2X7(parser_context_t* c, pd_JunctionV2X7_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV2(c, &v->junction5))
    CHECK_ERROR(_readJunctionV2(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV2X8(parser_context_t* c, pd_JunctionV2X8_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV2(c, &v->junction0))
    CHECK_ERROR(_readJunctionV2(c, &v->junction1))
    CHECK_ERROR(_readJunctionV2(c, &v->junction2))
    CHECK_ERROR(_readJunctionV2(c, &v->junction3))
    CHECK_ERROR(_readJunctionV2(c, &v->junction4))
    CHECK_ERROR(_readJunctionV2(c, &v->junction5))
    CHECK_ERROR(_readJunctionV2(c, &v->junction6))
    CHECK_ERROR(_readJunctionV2(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionV3X1(parser_context_t* c, pd_JunctionV3X1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction))
    return parser_ok;
}

parser_error_t _readJunctionV3X2(parser_context_t* c, pd_JunctionV3X2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction0))
    CHECK_ERROR(_readJunctionV3(c, &v->junction1))
    return parser_ok;
}

parser_error_t _readJunctionV3X3(parser_context_t* c, pd_JunctionV3X3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction0))
    CHECK_ERROR(_readJunctionV3(c, &v->junction1))
    CHECK_ERROR(_readJunctionV3(c, &v->junction2))
    return parser_ok;
}

parser_error_t _readJunctionV3X4(parser_context_t* c, pd_JunctionV3X4_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction0))
    CHECK_ERROR(_readJunctionV3(c, &v->junction1))
    CHECK_ERROR(_readJunctionV3(c, &v->junction2))
    CHECK_ERROR(_readJunctionV3(c, &v->junction3))
    return parser_ok;
}

parser_error_t _readJunctionV3X5(parser_context_t* c, pd_JunctionV3X5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction0))
    CHECK_ERROR(_readJunctionV3(c, &v->junction1))
    CHECK_ERROR(_readJunctionV3(c, &v->junction2))
    CHECK_ERROR(_readJunctionV3(c, &v->junction3))
    CHECK_ERROR(_readJunctionV3(c, &v->junction4))
    return parser_ok;
}

parser_error_t _readJunctionV3X6(parser_context_t* c, pd_JunctionV3X6_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction0))
    CHECK_ERROR(_readJunctionV3(c, &v->junction1))
    CHECK_ERROR(_readJunctionV3(c, &v->junction2))
    CHECK_ERROR(_readJunctionV3(c, &v->junction3))
    CHECK_ERROR(_readJunctionV3(c, &v->junction4))
    CHECK_ERROR(_readJunctionV3(c, &v->junction5))
    return parser_ok;
}

parser_error_t _readJunctionV3X7(parser_context_t* c, pd_JunctionV3X7_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction0))
    CHECK_ERROR(_readJunctionV3(c, &v->junction1))
    CHECK_ERROR(_readJunctionV3(c, &v->junction2))
    CHECK_ERROR(_readJunctionV3(c, &v->junction3))
    CHECK_ERROR(_readJunctionV3(c, &v->junction4))
    CHECK_ERROR(_readJunctionV3(c, &v->junction5))
    CHECK_ERROR(_readJunctionV3(c, &v->junction6))
    return parser_ok;
}

parser_error_t _readJunctionV3X8(parser_context_t* c, pd_JunctionV3X8_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readJunctionV3(c, &v->junction0))
    CHECK_ERROR(_readJunctionV3(c, &v->junction1))
    CHECK_ERROR(_readJunctionV3(c, &v->junction2))
    CHECK_ERROR(_readJunctionV3(c, &v->junction3))
    CHECK_ERROR(_readJunctionV3(c, &v->junction4))
    CHECK_ERROR(_readJunctionV3(c, &v->junction5))
    CHECK_ERROR(_readJunctionV3(c, &v->junction6))
    CHECK_ERROR(_readJunctionV3(c, &v->junction7))
    return parser_ok;
}

parser_error_t _readJunctionsV2(parser_context_t* c, pd_JunctionsV2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV2X1(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV2X2(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV2X3(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionV2X4(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV2X5(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV2X6(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV2X7(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV2X8(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readJunctionsV3(parser_context_t* c, pd_JunctionsV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Here
        break;
    case 1: // X1
        CHECK_ERROR(_readJunctionV3X1(c, &v->x1))
        break;
    case 2: // X2
        CHECK_ERROR(_readJunctionV3X2(c, &v->x2))
        break;
    case 3: // X3
        CHECK_ERROR(_readJunctionV3X3(c, &v->x3))
        break;
    case 4: // X4
        CHECK_ERROR(_readJunctionV3X4(c, &v->x4))
        break;
    case 5: // X5
        CHECK_ERROR(_readJunctionV3X5(c, &v->x5))
        break;
    case 6: // X6
        CHECK_ERROR(_readJunctionV3X6(c, &v->x6))
        break;
    case 7: // X7
        CHECK_ERROR(_readJunctionV3X7(c, &v->x7))
        break;
    case 8: // X8
        CHECK_ERROR(_readJunctionV3X8(c, &v->x8))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readAssetInstanceV2(parser_context_t* c, pd_AssetInstanceV2_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Undefined
        // Empty
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactu128(c, &v->index))
        break;
    case 2: // array4
        GEN_DEF_READARRAY(4)
        break;
    case 3: // array8
        GEN_DEF_READARRAY(8)
        break;
    case 4: // array16
        GEN_DEF_READARRAY(16)
        break;
    case 5: // array32
        GEN_DEF_READARRAY(32)
        break;
    case 6: // blob
        CHECK_ERROR(_readBytes(c, &v->blob))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readAssetInstanceV3(parser_context_t* c, pd_AssetInstanceV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Undefined
        // Empty
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactu128(c, &v->index))
        break;
    case 2: // array4
        GEN_DEF_READARRAY(4)
        break;
    case 3: // array8
        GEN_DEF_READARRAY(8)
        break;
    case 4: // array16
        GEN_DEF_READARRAY(16)
        break;
    case 5: // array32
        GEN_DEF_READARRAY(32)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMultiLocationV3(parser_context_t* c, pd_MultiLocationV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->parents))
    CHECK_ERROR(_readJunctionsV3(c, &v->interior))
    return parser_ok;
}

parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v) {
    GEN_DEF_READARRAY(16)
}

parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v)
{
    return _readBalance(c, &v->value);
}

parser_error_t _readCompactAccountIndex(parser_context_t* c, pd_CompactAccountIndex_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readEcdsaPublic(parser_context_t* c, pd_EcdsaPublic_t* v) {
    GEN_DEF_READARRAY(33)
}

parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readEd25519Public(parser_context_t* c, pd_Ed25519Public_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readEd25519Signature(parser_context_t* c, pd_Ed25519Signature_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readH256(parser_context_t* c, pd_H256_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readParaId(parser_context_t* c, pd_ParaId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readOptionPerbill(parser_context_t* c, pd_OptionPerbill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPerbill(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readSr25519Public(parser_context_t* c, pd_Sr25519Public_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readSr25519Signature(parser_context_t* c, pd_Sr25519Signature_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readTupleu32u32(parser_context_t* c, pd_Tupleu32u32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->first))
    CHECK_ERROR(_readUInt32(c, &v->second))
    return parser_ok;
}

parser_error_t _readVote(parser_context_t* c, pd_Vote_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    const uint8_t aye = v->value & 0xF0;
    const uint8_t conviction = v->value & 0x0F;
    if ((aye == 0x80 || aye == 0x00) && conviction <= 0x06) {
        return parser_ok;
    }
    return parser_value_out_of_range;
}

parser_error_t _readAccountIdLookupOfT(parser_context_t* c, pd_AccountIdLookupOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOptionAccountIdLookupOfT(parser_context_t* c, pd_OptionAccountIdLookupOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readCompactPerbill(parser_context_t* c, pd_CompactPerbill_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readConfigOpBalanceOfT(parser_context_t* c, pd_ConfigOpBalanceOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readBalance(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConfigOpPerbill(parser_context_t* c, pd_ConfigOpPerbill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readPerbill(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConfigOpPercent(parser_context_t* c, pd_ConfigOpPercent_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readPercent(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 3) {
        CHECK_ERROR(_readAccountId(c, &v->accountId))
    } else if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readBondValueOfT(parser_context_t* c, pd_BondValueOfT_t * v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 0) {
        CHECK_ERROR(_readCompactBalance(c, &v->amount))
    } else if (v->value > 1) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactPerbill(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v)
{
    compactInt_t clen;
    pd_Call_t dummy;
    CHECK_PARSER_ERR(_readCompactInt(c, &clen));
    CHECK_PARSER_ERR(_getValue(&clen, &v->_len));

    if (v->_len > MAX_CALL_VEC_SIZE) {
        return parser_tx_call_vec_too_large;
    }

    v->_ptr = c->buffer + c->offset;
    v->_lenBuffer = c->offset;
    if (v->_len == 0) {
        return parser_unexpected_buffer_end;
    }

    for (uint64_t i = 0; i < v->_len; i++) {
        c->tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCall(c, &dummy))
    }
    v->_lenBuffer = c->offset - v->_lenBuffer;
    v->callTxVersion = c->tx_obj->transactionVersion;

    return parser_ok;
}

parser_error_t _readStakingInfo(parser_context_t* c, pd_StakingInfo_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readPerbill(c, &v->annual_inflation_rate))
    CHECK_ERROR(_readPerbill(c, &v->collator_payout_cut))
    return parser_ok;
}

parser_error_t _readConfigOpu32(parser_context_t* c, pd_ConfigOpu32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readUInt32(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readEthereumAddress(parser_context_t* c, pd_EthereumAddress_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readVecAccountIdLookupOfT(parser_context_t* c, pd_VecAccountIdLookupOfT_t* v) {
    GEN_DEF_READVECTOR(AccountIdLookupOfT)
}

parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v) {
    GEN_DEF_READVECTOR(AccountId)
}

parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v) {
    GEN_DEF_READVECTOR(u32)
}

parser_error_t _readVecu8(parser_context_t* c, pd_Vecu8_t* v) {
    GEN_DEF_READVECTOR(u8)
}

parser_error_t _readOptionNetworkIdV3(parser_context_t* c, pd_OptionNetworkIdV3_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readNetworkIdV3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu8_array_20(parser_context_t* c, pd_Optionu8_array_20_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu8_array_20(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionAccountId(parser_context_t* c, pd_OptionAccountId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu32(parser_context_t* c, pd_Optionu32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu32(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu64(parser_context_t* c, pd_Optionu64_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu64(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu128(parser_context_t* c, pd_Optionu128_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu128(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readPoolId(parser_context_t* c, pd_PoolId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readVecu128(parser_context_t* c, pd_Vecu128_t* v) {
    GEN_DEF_READVECTOR(u128)
}

parser_error_t _readLiquidityAccountConfigOfT(parser_context_t* c, pd_LiquidityAccountConfigOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
        case 0: // All
            break;
        case 1: // Whitelist
        case 2: // Blocklist
        CHECK_ERROR(_readVecu128(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readCommissionNewCommission(parser_context_t* c, pd_CommissionNewCommission_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
        case 0: // NoMutation
            break;
        case 1: // SomeMutation
            CHECK_ERROR(_readOptionPerbill(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readChangeRate(parser_context_t* c, pd_ChangeRate_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readPerbill(c, &v->maxDelta))
    CHECK_ERROR(_readu32(c, &v->minDelay))
    return parser_ok;
}

parser_error_t _readOptionChangeRate(parser_context_t* c, pd_OptionCommissionChangeRate_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangeRate(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readNewNominatorMutation(parser_context_t* c, pd_NewNominatorMutation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
        case 0: // NoMutation
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_readOptionAccountId(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readNewAdminMutation(parser_context_t* c, pd_NewAdminMutation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
        case 0: // NoMutation
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_readOptionAccountId(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readRolesMutation(parser_context_t* c, pd_RolesMutation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readNewAdminMutation(c, &v->newAdmin))
    CHECK_ERROR(_readNewNominatorMutation(c, &v->newNominator))
    return parser_ok;
}

parser_error_t _readOptionRolesMutation(parser_context_t* c, pd_OptionPoolRolesMutation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRolesMutation(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readPoolMutationOfT(parser_context_t* c, pd_PoolMutationOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionu32(c, &v->duration))
    CHECK_ERROR(_readCommissionNewCommission(c, &v->newCommission))
    CHECK_ERROR(_readOptionPerbill(c, &v->maxCommission))
    CHECK_ERROR(_readOptionChangeRate(c, &v->changeRate))
    CHECK_ERROR(_readOptionRolesMutation(c, &v->roles))
    CHECK_ERROR(_readOptionu128(c, &v->capacity))
    return parser_ok;
}

parser_error_t _readOfferId(parser_context_t* c, pd_OfferId_t* v)
{
    return _readu128(c, &v->value);
}

parser_error_t _readOfferOfT(parser_context_t* c, pd_OfferOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->account))
    CHECK_ERROR(_readu128(c, &v->total))
    CHECK_ERROR(_readu128(c, &v->rate))
    CHECK_ERROR(_readPerbill(c, &v->min_average_commission))
    return parser_ok;
}

parser_error_t _readCollectionId(parser_context_t* c, pd_CollectionId_t* v)
{
    return _readu128(c, &v->value);
}

parser_error_t _readCompactCollectionId(parser_context_t* c, pd_CompactCollectionId_t* v)
{
    return _readCompactu128(c, &v->value);
}

parser_error_t _readCompactTokenId(parser_context_t* c, pd_CompactTokenId_t* v)
{
    return _readCompactu128(c, &v->value);
}

parser_error_t _readOptionTokenId(parser_context_t* c, pd_OptionTokenId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTokenId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readTokenAccountFreezeType(parser_context_t* c, pd_TokenAccountFreezeType_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactTokenId(c, &v->tokenId))
    CHECK_ERROR(_readAccountId(c, &v->accountId))

    return parser_ok;
}

parser_error_t _readFreezeState(parser_context_t* c, pd_FreezeState_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
        case 0: // Permanent
        case 1: // Temporary
        case 2: // Never
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readOptionFreezeState(parser_context_t* c, pd_OptionFreezeState_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readFreezeState(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readTokenFreezeType(parser_context_t* c, pd_TokenFreezeType_t * v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readTokenId(c, &v->tokenId))
    CHECK_ERROR(_readOptionFreezeState(c, &v->freezeState))

    return parser_ok;
}

parser_error_t _readFreezeType(parser_context_t* c, pd_FreezeType_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // Collection
            break;
        case 1: // Token
        CHECK_ERROR(_readTokenFreezeType(c, &v->token))
            break;
        case 2: // CollectionAccount
        CHECK_ERROR(_readAccountId(c, &v->collectionAccount))
            break;
        case 3: // TokenAccount
        CHECK_ERROR(_readTokenAccountFreezeType(c, &v->tokenAccount))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readFreezeOf(parser_context_t* c, pd_FreezeOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->collectionId))
    CHECK_ERROR(_readFreezeType(c, &v->freezeType))
    return parser_ok;
}

parser_error_t _readInsufficientPolicyMintSufficiencyParam(parser_context_t* c, pd_InsufficientPolicyMintSufficiencyParam_t* v)
{
    return _readOptionu128(c, &v->unitPrice);
}

parser_error_t _readSufficientPolicyMintSufficiencyParam(parser_context_t* c, pd_SufficientPolicyMintSufficiencyParam_t* v)
{
    return _readu128(c, &v->minimumBalance);
}

parser_error_t _readPolicyMintSufficiencyParam(parser_context_t* c, pd_PolicyMintSufficiencyParam_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // Insufficient
        CHECK_ERROR(_readInsufficientPolicyMintSufficiencyParam(c, &v->insufficient))
            break;
        case 1: // Sufficient
        CHECK_ERROR(_readSufficientPolicyMintSufficiencyParam(c, &v->sufficient))
            break;
        default:
            return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTokenTokenCap(parser_context_t* c, pd_TokenTokenCap_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // SingleMint
            break;
        case 1: // Supply
        CHECK_ERROR(_readCompactu128(c, &v->supply))
            break;
        case 2: // CollapsingSupply
        CHECK_ERROR(_readCompactu128(c, &v->collapsingSupply))
            break;
        default:
            return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOptionTokenTokenCap(parser_context_t* c, pd_OptionTokenTokenCap_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readTokenTokenCap(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readHasRoyaltyTokenTokenMarketBehavior(parser_context_t* c, pd_HasRoyaltyTokenTokenMarketBehavior * v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->beneficiary))
    CHECK_ERROR(_readCompactPerbill(c, &v->percentage))
    return parser_ok;
}

parser_error_t _readTokenTokenMarketBehavior(parser_context_t* c, pd_TokenTokenMarketBehavior_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // HasRoyalty
        CHECK_ERROR(_readHasRoyaltyTokenTokenMarketBehavior(c, &v->hasRoyalty))
            break;
        case 1: // IsCurrency
            break;
        default:
            return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOptionTokenTokenMarketBehavior(parser_context_t* c, pd_OptionTokenTokenMarketBehavior_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readTokenTokenMarketBehavior(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readAttributeKeyValuePair(parser_context_t* c, pd_AttributeKeyValuePair_t* v) {
    CHECK_INPUT()
    CHECK_ERROR(_readBytes(c, &v->key))
    CHECK_ERROR(_readBytes(c, &v->value))

    return parser_ok;
}

parser_error_t _readVecAttributeKeyValuePair(parser_context_t* c, pd_VecAttributeKeyValuePair_t* v) {
    GEN_DEF_READVECTOR(AttributeKeyValuePair)
}

parser_error_t _readOptionMultiLocationV3(parser_context_t* c, pd_OptionXcmV3MultiLocation* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readMultiLocationV3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readPolicyMintForeignTokenCreationParams(parser_context_t* c, pd_PolicyMintForeignTokenCreationParams_t* v) {
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->decimalCount))
    CHECK_ERROR(_readBytes(c, &v->name))
    CHECK_ERROR(_readBytes(c, &v->symbol))
    CHECK_ERROR(_readOptionMultiLocationV3(c, &v->location))
    CHECK_ERROR(_readOptionu128(c, &v->unitsPerSecond))

    return parser_ok;
}

parser_error_t _readOptionPolicyMintForeignTokenCreationParams(parser_context_t* c, pd_OptionPolicyMintForeignTokenCreationParams_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readPolicyMintForeignTokenCreationParams(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readCreateTokenMintParam(parser_context_t* c, pd_CreateTokenMintParam_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactTokenId(c, &v->tokenId))
    CHECK_ERROR(_readCompactu128(c, &v->initialSupply))
    CHECK_ERROR(_readPolicyMintSufficiencyParam(c, &v->sufficiency))
    CHECK_ERROR(_readOptionTokenTokenCap(c, &v->cap))
    CHECK_ERROR(_readOptionTokenTokenMarketBehavior(c, &v->behavior))
    CHECK_ERROR(_readbool(c, &v->listingForbidden))
    CHECK_ERROR(_readOptionFreezeState(c, &v->freezeState))
    CHECK_ERROR(_readVecAttributeKeyValuePair(c, &v->attributes))
    CHECK_ERROR(_readOptionPolicyMintForeignTokenCreationParams(c, &v->foreignParams))

    return parser_ok;
}

parser_error_t _readMintTokenMintParam(parser_context_t* c, pd_MintTokenMintParam_t * v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactTokenId(c, &v->tokenId))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    CHECK_ERROR(_readOptionu128(c, &v->unitPrice))

    return parser_ok;
}

parser_error_t _readMintParamsOf(parser_context_t* c, pd_MintParamsOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // CreateToken
        CHECK_ERROR(_readCreateTokenMintParam(c, &v->createToken))
            break;
        case 1: // Mint
        CHECK_ERROR(_readMintTokenMintParam(c, &v->mint))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readMintRecipientsOf(parser_context_t* c, pd_MintRecipientsOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->accountId))
    CHECK_ERROR(_readMintParamsOf(c, &v->params))
    return parser_ok;
}

parser_error_t _readVecMintRecipientsOf(parser_context_t* c, pd_VecMintRecipientsOf_t* v)
{
    GEN_DEF_READVECTOR(MintRecipientsOf)
}

parser_error_t _readTransferRecipientsOf(parser_context_t* c, pd_TransferRecipientsOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->accountId))
    CHECK_ERROR(_readTransferParamsOfT(c, &v->params))
    return parser_ok;
}

parser_error_t _readVecTransferRecipientsOf(parser_context_t* c, pd_VecTransferRecipientsOf_t* v)
{
    GEN_DEF_READVECTOR(TransferRecipientsOf)
}

parser_error_t _readMarketPolicyRoyalty(parser_context_t* c, pd_MarketPolicyRoyalty_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->beneficiary))
    CHECK_ERROR(_readCompactPerbill(c, &v->percentage))

    return parser_ok;
}

parser_error_t _readOptionMarketPolicyRoyalty(parser_context_t* c, pd_OptionMarketPolicyRoyalty_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readMarketPolicyRoyalty(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readMarketPolicyDescriptor(parser_context_t* c, pd_MarketPolicyDescriptor_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionMarketPolicyRoyalty(c, &v->royalty))
    return parser_ok;
}

parser_error_t _readMintPolicyDescriptor(parser_context_t* c, pd_MintPolicyDescriptor_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionu64(c, &v->maxTokenCount))
    CHECK_ERROR(_readOptionu128(c, &v->maxTokenSupply))
    CHECK_ERROR(_readbool(c, &v->forceSingleMint))
    return parser_ok;
}

parser_error_t _readCollectionPolicyDescriptor(parser_context_t* c, pd_CollectionPolicyDescriptor_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMintPolicyDescriptor(c, &v->mint))
    CHECK_ERROR(_readMarketPolicyDescriptor(c, &v->market))
    return parser_ok;
}

parser_error_t _readTokenAssetId(parser_context_t* c, pd_TokenAssetId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->collectionId))
    CHECK_ERROR(_readCompactTokenId(c, &v->tokenId))
    return parser_ok;
}

parser_error_t _readVecTokenAssetId(parser_context_t* c, pd_VecTokenAssetId_t* v) {
    GEN_DEF_READVECTOR(TokenAssetId)
}

parser_error_t _readCollectionDescriptor(parser_context_t* c, pd_CollectionDescriptor_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCollectionPolicyDescriptor(c, &v->policy))
    CHECK_ERROR(_readVecTokenAssetId(c, &v->explicitRoyaltyCurrencies))
    CHECK_ERROR(_readVecAttributeKeyValuePair(c, &v->attributes))
    return parser_ok;
}

parser_error_t _readRoyaltyMutation(parser_context_t* c, pd_RoyaltyMutation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // NoMutation
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_readOptionMarketPolicyRoyalty(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readOptionVecTokenAssetId(parser_context_t* c, pd_OptionVecTokenAssetId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readVecTokenAssetId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readCollectionMutation(parser_context_t* c, pd_CollectionMutation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionAccountId(c, &v->owner))
    CHECK_ERROR(_readRoyaltyMutation(c, &v->royalty))
    CHECK_ERROR(_readOptionVecTokenAssetId(c, &v->explicitRoyaltyCurrencies))
    return parser_ok;
}

parser_error_t _readTransferPolicy(parser_context_t* c, pd_TransferPolicy_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readbool(c, &v->isFrozen))
    return parser_ok;
}

parser_error_t _readCollectionPolicy(parser_context_t* c, pd_CollectionPolicy_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMintPolicyDescriptor(c, &v->mint))
    CHECK_ERROR(_readTransferPolicy(c, &v->transfer))
    CHECK_ERROR(_readOptionMarketPolicyRoyalty(c, &v->market))
    return parser_ok;
}

parser_error_t _readCollectionOf(parser_context_t* c, pd_CollectionOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->owner))
    CHECK_ERROR(_readCollectionPolicy(c, &v->policy))
    CHECK_ERROR(_readCompactu64(c, &v->tokenCount))
    CHECK_ERROR(_readCompactu32(c, &v->attributeCount))
    CHECK_ERROR(_readCompactu128(c, &v->totalDeposit))
    CHECK_ERROR(_readOptionBytes(c, &v->explicitRoyaltyCurrencies))
    return parser_ok;
}

parser_error_t _readOptionCollectionOf(parser_context_t* c, pd_OptionCollectionOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readCollectionOf(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readCollectionAccountOf(parser_context_t* c, pd_CollectionAccountOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readbool(c, &v->isFrozen))
    CHECK_ERROR(_readOptionBytes(c, &v->approvals))
    CHECK_ERROR(_readCompactu32(c, &v->accountCount))
    return parser_ok;
}

parser_error_t _readOptionCollectionAccountOf(parser_context_t* c, pd_OptionCollectionAccountOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readCollectionAccountOf(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readShouldMutateBool(parser_context_t* c, pd_ShouldMutateBool_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // NoMutation
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_readbool(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readMutateForeignTokenMetadata(parser_context_t* c, pd_MutateForeignTokenMetadata_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->decimalCount))
    CHECK_ERROR(_readBytes(c, &v->name))
    CHECK_ERROR(_readBytes(c, &v->symbol))
    CHECK_ERROR(_readOptionMultiLocationV3(c, &v->location))
    CHECK_ERROR(_readOptionu128(c, &v->unitsPerSecond))
    CHECK_ERROR(_readCompactu128(c, &v->premintedSupply))

    return parser_ok;
}

parser_error_t _readTokenMetadata(parser_context_t* c, pd_TokenMetadata_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // Native
            break;
        case 1: // Foreign
        CHECK_ERROR(_readMutateForeignTokenMetadata(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readShouldMutateTokenMetadata(parser_context_t* c, pd_ShouldMutateTokenMetadata_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // NoMutation
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_readTokenMetadata(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readInsufficientTokenSufficiency(parser_context_t* c, pd_InsufficientTokenSufficiency_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->unitPrice))
    return parser_ok;
}

parser_error_t _readTokenSufficiency(parser_context_t* c, pd_TokenSufficiency_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // Sufficient
            break;
        case 1: // Insufficient
        CHECK_ERROR(_readInsufficientTokenSufficiency(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readTokenOf(parser_context_t* c, pd_TokenOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->supply))
    CHECK_ERROR(_readOptionTokenTokenCap(c, &v->cap))
    CHECK_ERROR(_readOptionFreezeState(c, &v->freezeState))
    CHECK_ERROR(_readCompactu128(c, &v->minimumBalance))
    CHECK_ERROR(_readTokenSufficiency(c, &v->sufficiency))
    CHECK_ERROR(_readCompactu128(c, &v->mintDeposit))
    CHECK_ERROR(_readCompactu32(c, &v->attributeCount))
    CHECK_ERROR(_readOptionTokenTokenMarketBehavior(c, &v->marketBehavior))
    CHECK_ERROR(_readbool(c, &v->listingForbidden))
    CHECK_ERROR(_readTokenMetadata(c, &v->metadata))
    return parser_ok;
}

parser_error_t _readOptionTokenOf(parser_context_t* c, pd_OptionTokenOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readTokenOf(c, &v->contained))
    }

    return parser_ok;
}

parser_error_t _readTokenAccountOf(parser_context_t* c, pd_TokenAccountOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu128(c, &v->balance))
    CHECK_ERROR(_readCompactu128(c, &v->reservedBalance))
    CHECK_ERROR(_readCompactu128(c, &v->lockedBalance))
    CHECK_ERROR(_readOptionBytes(c, &v->namedReserves))
    CHECK_ERROR(_readOptionBytes(c, &v->locks))
    CHECK_ERROR(_readOptionBytes(c, &v->approvals))
    CHECK_ERROR(_readbool(c, &v->isFrozen))
    return parser_ok;
}

parser_error_t _readOptionTokenAccountOf(parser_context_t* c, pd_OptionTokenAccountOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))

    if (v->some > 0) {
        CHECK_ERROR(_readTokenAccountOf(c, &v->contained))
    }

    return parser_ok;
}

parser_error_t _readShouldMutateTokenMarketBehavior(parser_context_t* c, pd_ShouldMutateTokenMarketBehavior_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // NoMutation
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_readOptionTokenTokenMarketBehavior(c, &v->set))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readTokenMutation(parser_context_t* c, pd_TokenMutation_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readShouldMutateTokenMarketBehavior(c, &v->behavior))
    CHECK_ERROR(_readShouldMutateBool(c, &v->listingForbidden))
    CHECK_ERROR(_readShouldMutateTokenMetadata(c, &v->metadata))
    return parser_ok;
}

parser_error_t _readBurnParamsOfT(parser_context_t* c, pd_BurnParamsOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactTokenId(c, &v->tokenId))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    CHECK_ERROR(_readbool(c, &v->keepAlive))
    CHECK_ERROR(_readbool(c, &v->removeTokenStorage))
    return parser_ok;
}

parser_error_t _readSimpleTransferParams(parser_context_t* c, pd_SimpleTransferParams_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactTokenId(c, &v->tokenId))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    CHECK_ERROR(_readbool(c, &v->keepAlive))
    return parser_ok;
}

parser_error_t _readOperatorTransferParams(parser_context_t* c, pd_OperatorTransferParams_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactTokenId(c, &v->tokenId))
    CHECK_ERROR(_readAccountId(c, &v->source))
    CHECK_ERROR(_readCompactu128(c, &v->amount))
    CHECK_ERROR(_readbool(c, &v->keepAlive))
    return parser_ok;
}

parser_error_t _readTransferParamsOfT(parser_context_t* c, pd_TransferParamsOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0: // Simple
        CHECK_ERROR(_readSimpleTransferParams(c, &v->simple))
            break;
        case 1: // Operator
        CHECK_ERROR(_readOperatorTransferParams(c, &v->operator_))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readTokenId(parser_context_t* c, pd_TokenId_t* v)
{
    return _readu128(c, &v->value);
}

parser_error_t _readTokenIdOf(parser_context_t* c, pd_TokenIdOf_t* v)
{
    return _readTokenId(c, &v->value);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringbool(
    const pd_bool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);

    *pageCount = 1;
    switch (*v) {
    case 0:
        snprintf(outValue, outValueLen, "False");
        return parser_ok;
    case 1:
        snprintf(outValue, outValueLen, "True");
        return parser_ok;
    }

    return parser_not_supported;
}

parser_error_t _toStringu8(
    const pd_u8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[50];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu16(
    const pd_u16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[50];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu32(
    const pd_u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu64(
    const pd_u64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu128(
    const pd_u128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    char bufferUI[200];
    MEMZERO(outValue, outValueLen);
    MEMZERO(bufferUI, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[100];
    const uint16_t bcdOutLen = sizeof(bcdOut);
    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen))
        return parser_unexpected_buffer_end;

    // Format number
    if (intstr_to_fpstr_inplace(bufferUI, sizeof(bufferUI), 0) == 0) {
        return parser_unexpected_value;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringOptionu64(
        const pd_Optionu64_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu64(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringOptionu128(
        const pd_Optionu128_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu128(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(v, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactu128(
    const pd_Compactu128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringu8_array_32(
    const pd_u8_array_32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringByFork(
    const pd_ByFork_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu64(&v->blockNumber, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32(&v->blockHash, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu64(&v->blockNumber, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32(&v->blockHash, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBytes(
    const pd_Bytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(v->_len);
}

parser_error_t _toStringOptionBytes(
        const pd_OptionBytes_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBytes(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringAttributeOf(
        const pd_AttributeOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->deposit, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->deposit, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}


parser_error_t _toStringOptionAttributeOf(
        const pd_OptionAttributeOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAttributeOf(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringFraction(
    const pd_Fraction_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->nom, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu32(&v->denom, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNetworkIdV3(
    const pd_NetworkIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // ByGenesis
        CHECK_ERROR(_toStringu8_array_32(&v->byGenesis, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // ByFork
        CHECK_ERROR(_toStringByFork(&v->byFork, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // Ethereum
        CHECK_ERROR(_toStringCompactu64(&v->chainId, outValue, outValueLen, pageIdx, pageCount))
        break;

    case 2: // Polkadot
        snprintf(outValue, outValueLen, "Polkadot");
        break;
    case 3: // Kusama
        snprintf(outValue, outValueLen, "Kusama");
        break;
    case 4: // Westend
        snprintf(outValue, outValueLen, "Westend");
        break;
    case 5: // Rococo
        snprintf(outValue, outValueLen, "Rococo");
        break;
    case 6: // Wococo
        snprintf(outValue, outValueLen, "Wococo");
        break;
    case 8: // BitcoinCore
        snprintf(outValue, outValueLen, "BitcoinCore");
        break;
    case 9: // BitcoinCash
        snprintf(outValue, outValueLen, "BitcoinCash");
        break;
    default:
        return parser_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringBodyIdV2(
    const pd_BodyIdV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Unit
        snprintf(outValue, outValueLen, "Unit");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Index
        CHECK_ERROR(_toStringCompactu32(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Executive
        snprintf(outValue, outValueLen, "Executive");
        break;
    case 4: // Technical
        snprintf(outValue, outValueLen, "Technical");
        break;
    case 5: // Legislative
        snprintf(outValue, outValueLen, "Legislative");
        break;
    case 6: // Judicial
        snprintf(outValue, outValueLen, "Judicial");
        break;
    case 7: // Defense
        snprintf(outValue, outValueLen, "Defense");
        break;
    case 8: // Administration
        snprintf(outValue, outValueLen, "Administration");
        break;
    case 9: // Treasury
        snprintf(outValue, outValueLen, "Treasury");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBodyIdV3(
    const pd_BodyIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Unit
        snprintf(outValue, outValueLen, "Unit");
        break;
    case 1: // Moniker
        GEN_DEF_TOSTRING_ARRAY(4)
        break;
    case 2: // Index
        CHECK_ERROR(_toStringCompactu32(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Executive
        snprintf(outValue, outValueLen, "Executive");
        break;
    case 4: // Technical
        snprintf(outValue, outValueLen, "Technical");
        break;
    case 5: // Legislative
        snprintf(outValue, outValueLen, "Legislative");
        break;
    case 6: // Judicial
        snprintf(outValue, outValueLen, "Judicial");
        break;
    case 7: // Defense
        snprintf(outValue, outValueLen, "Defense");
        break;
    case 8: // Administration
        snprintf(outValue, outValueLen, "Administration");
        break;
    case 9: // Treasury
        snprintf(outValue, outValueLen, "Treasury");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBodyPart(
    const pd_BodyPart_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Voice
        snprintf(outValue, outValueLen, "Voice");
        break;
    case 1: // Members
        CHECK_ERROR(_toStringCompactu32(&v->count, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Fraction
        CHECK_ERROR(_toStringFraction(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AtLeastProportion
        CHECK_ERROR(_toStringFraction(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // MoreThanProportion
        CHECK_ERROR(_toStringFraction(&v->fraction, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringNetworkIdV2(
    const pd_NetworkIdV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Any
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1: // Named
        CHECK_ERROR(_toStringBytes(&v->named, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Polkadot
        snprintf(outValue, outValueLen, "Polkadot");
        break;
    case 3: // Kusama
        snprintf(outValue, outValueLen, "Kusama");
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringu8_array_20(
    const pd_u8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringAccountId32V2(
    const pd_AccountId32V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkIdV2(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkIdV2(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountId32V3(
    const pd_AccountId32V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringOptionNetworkIdV3(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionNetworkIdV3(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIndex64V2(
    const pd_AccountIndex64V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkIdV2(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkIdV2(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIndex64V3(
    const pd_AccountIndex64V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringOptionNetworkIdV3(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionNetworkIdV3(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountKey20V2(
    const pd_AccountKey20V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNetworkIdV2(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNetworkIdV2(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountKey20V3(
    const pd_AccountKey20V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringOptionNetworkIdV3(&v->networkId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionNetworkIdV3(&v->networkId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_20(&v->key, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringGeneralKeyV3(
    const pd_GeneralKeyV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->length, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_32(&v->data, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8(&v->length, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_32(&v->data, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPluralityV2(
    const pd_PluralityV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBodyIdV2(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBodyPart(&v->part, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBodyIdV2(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBodyPart(&v->part, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPluralityV3(
    const pd_PluralityV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBodyIdV3(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBodyPart(&v->part, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBodyIdV3(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBodyPart(&v->part, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2(
    const pd_JunctionV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_toStringAccountId32V2(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64V2(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20V2(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_toStringBytes(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 8: // Plurality
        CHECK_ERROR(_toStringPluralityV2(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionV3(
    const pd_JunctionV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Parachain
        CHECK_ERROR(_toStringCompactu32(&v->parachain, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // AccountId32
        CHECK_ERROR(_toStringAccountId32V3(&v->accountId32, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // AccountIndex64
        CHECK_ERROR(_toStringAccountIndex64V3(&v->accountIndex64, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // AccountKey20
        CHECK_ERROR(_toStringAccountKey20V3(&v->accountKey20, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // PalletInstance
        CHECK_ERROR(_toStringu8(&v->palletInstance, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // GeneralIndex
        CHECK_ERROR(_toStringCompactu128(&v->generalIndex, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // GeneralKey
        CHECK_ERROR(_toStringGeneralKeyV3(&v->generalKey, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // OnlyChild
        snprintf(outValue, outValueLen, "OnlyChild");
        break;
    case 8: // Plurality
        CHECK_ERROR(_toStringPluralityV3(&v->plurality, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 9: // GlobalConsensus
        CHECK_ERROR(_toStringNetworkIdV3(&v->globalConsensus, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionV2X1(
    const pd_JunctionV2X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2X2(
    const pd_JunctionV2X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2X3(
    const pd_JunctionV2X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2X4(
    const pd_JunctionV2X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2X5(
    const pd_JunctionV2X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2X6(
    const pd_JunctionV2X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2X7(
    const pd_JunctionV2X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV2X8(
    const pd_JunctionV2X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV2(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV2(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X1(
    const pd_JunctionV3X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X2(
    const pd_JunctionV3X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X3(
    const pd_JunctionV3X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X4(
    const pd_JunctionV3X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X5(
    const pd_JunctionV3X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X6(
    const pd_JunctionV3X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction5, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X7(
    const pd_JunctionV3X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction6, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionV3X8(
    const pd_JunctionV3X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction5, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction6, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringJunctionV3(&v->junction7, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction0, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction1, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction2, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction3, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction4, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction5, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction6, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringJunctionV3(&v->junction7, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringJunctionsV2(
    const pd_JunctionsV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Here
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Here");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV2X1(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV2X2(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV2X3(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV2X4(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV2X5(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV2X6(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV2X7(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV2X8(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringJunctionsV3(
    const pd_JunctionsV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Here
        *pageCount = 1;
        snprintf(outValue, outValueLen, "Here");
        break;
    case 1: // X1
        CHECK_ERROR(_toStringJunctionV3X1(&v->x1, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // X2
        CHECK_ERROR(_toStringJunctionV3X2(&v->x2, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // X3
        CHECK_ERROR(_toStringJunctionV3X3(&v->x3, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // X4
        CHECK_ERROR(_toStringJunctionV3X4(&v->x4, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 5: // X5
        CHECK_ERROR(_toStringJunctionV3X5(&v->x5, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 6: // X6
        CHECK_ERROR(_toStringJunctionV3X6(&v->x6, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 7: // X7
        CHECK_ERROR(_toStringJunctionV3X7(&v->x7, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 8: // X8
        CHECK_ERROR(_toStringJunctionV3X8(&v->x8, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}


parser_error_t _toStringMultiLocationV2(
    const pd_MultiLocationV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionsV2(&v->interior, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionsV2(&v->interior, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMultiLocationV3(
    const pd_MultiLocationV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringJunctionsV3(&v->interior, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8(&v->parents, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringJunctionsV3(&v->interior, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBalance(
    const pd_Balance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    char bufferUI[200];
    memset(outValue, 0, outValueLen);
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[100];
    const uint16_t bcdOutLen = sizeof(bcdOut);

    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen)) {
        return parser_unexpected_buffer_end;
    }

    // Format number
    if (intstr_to_fpstr_inplace(bufferUI, sizeof(bufferUI), COIN_AMOUNT_DECIMAL_PLACES) == 0) {
        return parser_unexpected_value;
    }

    number_inplace_trimming(bufferUI, 1);
    number_inplace_trimming(bufferUI, 1);
    if (z_str3join(bufferUI, sizeof(bufferUI), COIN_TICKER, "") != zxerr_ok) {
        return parser_print_not_supported;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBalanceOf(
    const pd_BalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringBalance(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOfferId(
    const pd_OfferId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOfferOfT(
        const pd_OfferOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->account, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu128(&v->total, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu128(&v->rate, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringPerbill(&v->min_average_commission, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->account, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu128(&v->total, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu128(&v->rate, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringPerbill(&v->min_average_commission, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBurnParamsOfT(
        const pd_BurnParamsOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->keepAlive, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->removeTokenStorage, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->keepAlive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringbool(&v->removeTokenStorage, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionTokenId(
        const pd_OptionTokenId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{

    // TODO: Check if wont crash
    pd_Optionu128_t optionu128 = {
            .some = v->some,
            .contained = v->contained.value
    };

    return _toStringOptionu128(&optionu128, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringTokenId(
    const pd_TokenId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu128(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringTokenIdOf(
    const pd_TokenIdOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringTokenId(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringFreezeState(
        const pd_FreezeState_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);
    *pageCount = 1;

    switch (v->value) {
        case 0: // Permanent
            snprintf(outValue, outValueLen, "Permanent");
            break;
        case 1: // Temporary
            snprintf(outValue, outValueLen, "Temporary");
            break;
        case 2: // Never
            snprintf(outValue, outValueLen, "Never");
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringOptionFreezeState(
        const pd_OptionFreezeState_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some == 0) {
        snprintf(outValue, outValueLen, "None");
        return parser_ok;
    }
    return _toStringFreezeState(&v->contained, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringTokenFreezeType(
        const pd_TokenFreezeType_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionFreezeState(&v->freezeState, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionFreezeState(&v->freezeState, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTokenAccountFreezeType(
        const pd_TokenAccountFreezeType_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringFreezeType(
        const pd_FreezeType_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // Collection
            snprintf(outValue, outValueLen, "Collection");
            break;
        case 1: // Token
        CHECK_ERROR(_toStringTokenFreezeType(&v->token, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 2: // CollectionAccount
        CHECK_ERROR(_toStringAccountId(&v->collectionAccount, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 3: // TokenAccount
        CHECK_ERROR(_toStringTokenAccountFreezeType(&v->tokenAccount, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringFreezeOf(
        const pd_FreezeOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu128(&v->collectionId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringFreezeType(&v->freezeType, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu128(&v->collectionId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringFreezeType(&v->freezeType, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMintTokenMintParam(
        const pd_MintTokenMintParam_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionu128(&v->unitPrice, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionu128(&v->unitPrice, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringInsufficientPolicyMintSufficiencyParam(
        const pd_InsufficientPolicyMintSufficiencyParam_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    return _toStringOptionu128(&v->unitPrice, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSufficientPolicyMintSufficiencyParam(
        const pd_SufficientPolicyMintSufficiencyParam_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    return _toStringu128(&v->minimumBalance, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPolicyMintSufficiencyParam(
        const pd_PolicyMintSufficiencyParam_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // Insufficient
        CHECK_ERROR(_toStringInsufficientPolicyMintSufficiencyParam(&v->insufficient, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 1: // Sufficient
        CHECK_ERROR(_toStringSufficientPolicyMintSufficiencyParam(&v->sufficient, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringTokenTokenCap(
        const pd_TokenTokenCap_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // SingleMint
            snprintf(outValue, outValueLen, "SingleMint");
            break;
        case 1: // Supply
        CHECK_ERROR(_toStringCompactu128(&v->supply, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 2: // CollapsingSupply
        CHECK_ERROR(_toStringCompactu128(&v->collapsingSupply, outValue, outValueLen, pageIdx, pageCount))
        break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringOptionTokenTokenCap(
        const pd_OptionTokenTokenCap_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTokenTokenCap(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringHasRoyaltyTokenTokenMarketBehavior(
        const pd_HasRoyaltyTokenTokenMarketBehavior* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->beneficiary, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactPerbill(&v->percentage, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->beneficiary, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactPerbill(&v->percentage, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTokenTokenMarketBehavior(
        const pd_TokenTokenMarketBehavior_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // HasRoyalty
        CHECK_ERROR(_toStringHasRoyaltyTokenTokenMarketBehavior(&v->hasRoyalty, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 1: // IsCurrency
            snprintf(outValue, outValueLen, "IsCurrency");
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringOptionTokenTokenMarketBehavior(
        const pd_OptionTokenTokenMarketBehavior_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTokenTokenMarketBehavior(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringOptionMultiLocationV3(
        const pd_OptionXcmV3MultiLocation* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMultiLocationV3(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringPolicyMintForeignTokenCreationParams(
        const pd_PolicyMintForeignTokenCreationParams_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->decimalCount, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBytes(&v->name, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBytes(&v->symbol, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionMultiLocationV3(&v->location, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionu128(&v->unitsPerSecond, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->decimalCount, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBytes(&v->name, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBytes(&v->symbol, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionMultiLocationV3(&v->location, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionu128(&v->unitsPerSecond, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionPolicyMintForeignTokenCreationParams(
        const pd_OptionPolicyMintForeignTokenCreationParams_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPolicyMintForeignTokenCreationParams(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringAttributeKeyValuePair(
        const pd_AttributeKeyValuePair_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBytes(&v->key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBytes(&v->key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVecAttributeKeyValuePair(
        const pd_VecAttributeKeyValuePair_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AttributeKeyValuePair);
}

parser_error_t _toStringCreateTokenMintParam(
        const pd_CreateTokenMintParam_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9] = { 0 };
    CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->initialSupply, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringPolicyMintSufficiencyParam(&v->sufficiency, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionTokenTokenCap(&v->cap, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionTokenTokenMarketBehavior(&v->behavior, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringbool(&v->listingForbidden, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringOptionFreezeState(&v->freezeState, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringVecAttributeKeyValuePair(&v->attributes, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringOptionPolicyMintForeignTokenCreationParams(&v->foreignParams, outValue, outValueLen, 0, &pages[8]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->initialSupply, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringPolicyMintSufficiencyParam(&v->sufficiency, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionTokenTokenCap(&v->cap, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionTokenTokenMarketBehavior(&v->behavior, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringbool(&v->listingForbidden, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringOptionFreezeState(&v->freezeState, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringVecAttributeKeyValuePair(&v->attributes, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringOptionPolicyMintForeignTokenCreationParams(&v->foreignParams, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMintParamsOf(
        const pd_MintParamsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
        case 0: // CreateToken
        CHECK_ERROR(_toStringCreateTokenMintParam(&v->createToken, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 1: // Mint
        CHECK_ERROR(_toStringMintTokenMintParam(&v->mint, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMintRecipientsOf(
        const pd_MintRecipientsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMintParamsOf(&v->params, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMintParamsOf(&v->params, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVecMintRecipientsOf(
        const pd_VecMintRecipientsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MintRecipientsOf);
}

parser_error_t _toStringTransferRecipientsOf(
        const pd_TransferRecipientsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTransferParamsOfT(&v->params, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTransferParamsOfT(&v->params, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVecTransferRecipientsOf(
        const pd_VecTransferRecipientsOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TransferRecipientsOf);
}

parser_error_t _toStringSimpleTransferParams(
        const pd_SimpleTransferParams_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->keepAlive, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->keepAlive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOperatorTransferParams(
        const pd_OperatorTransferParams_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAccountId(&v->source, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->keepAlive, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAccountId(&v->source, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCompactu128(&v->amount, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringbool(&v->keepAlive, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTransferParamsOfT(
        const pd_TransferParamsOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
        case 0: // Simple
        CHECK_ERROR(_toStringSimpleTransferParams(&v->simple, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 1: // Operator
        CHECK_ERROR(_toStringOperatorTransferParams(&v->operator_, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringCompactCollectionId(
    const pd_CompactCollectionId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactu128(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactTokenId(
        const pd_CompactTokenId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    return _toStringCompactu128(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringTokenAssetId(
        const pd_TokenAssetId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu128(&v->collectionId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu128(&v->collectionId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactTokenId(&v->tokenId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVecTokenAssetId(
        const pd_VecTokenAssetId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TokenAssetId);
}

parser_error_t _toStringMintPolicyDescriptor(
        const pd_MintPolicyDescriptor_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringOptionu64(&v->maxTokenCount, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionu128(&v->maxTokenSupply, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->forceSingleMint, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionu64(&v->maxTokenCount, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionu128(&v->maxTokenSupply, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->forceSingleMint, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMarketPolicyRoyalty(
        const pd_MarketPolicyRoyalty_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->beneficiary, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactPerbill(&v->percentage, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->beneficiary, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactPerbill(&v->percentage, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionMarketPolicyRoyalty(
        const pd_OptionMarketPolicyRoyalty_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMarketPolicyRoyalty(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringMarketPolicyDescriptor(
        const pd_MarketPolicyDescriptor_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringOptionMarketPolicyRoyalty(&v->royalty, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMarketPolicyRoyalty(&v->royalty, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionPerbill(
        const pd_OptionPerbill_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPerbill(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringComissionNewComission(
        const pd_CommissionNewCommission_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;

    switch (v->value) {
        case 0: // NoMutation
            snprintf(outValue, outValueLen, "NoMutation");
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_toStringOptionPerbill(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringComissionChangeRate(
        const pd_ChangeRate_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringPerbill(&v->maxDelta, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->minDelay, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPerbill(&v->maxDelta, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->minDelay, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionCommissionChangeRate(
        const pd_OptionCommissionChangeRate_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringComissionChangeRate(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringNewAdminMutation(
        const pd_NewAdminMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;

    switch (v->value) {
        case 0: // NoMutation
            snprintf(outValue, outValueLen, "NoMutation");
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_toStringOptionAccountId(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringNewNominatorMutation(
        const pd_NewNominatorMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;

    switch (v->value) {
        case 0: // NoMutation
            snprintf(outValue, outValueLen, "NoMutation");
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_toStringOptionAccountId(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringPoolRolesMutation(
        const pd_RolesMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringNewAdminMutation(&v->newAdmin, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringNewNominatorMutation(&v->newNominator, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringNewAdminMutation(&v->newAdmin, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringNewNominatorMutation(&v->newNominator, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionPoolRolesMutation(
        const pd_OptionPoolRolesMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPoolRolesMutation(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringPoolMutationOfT(
        const pd_PoolMutationOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringOptionu32(&v->duration, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringComissionNewComission(&v->newCommission, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionPerbill(&v->maxCommission, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionCommissionChangeRate(&v->changeRate, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionPoolRolesMutation(&v->roles, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringOptionu128(&v->capacity, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionu32(&v->duration, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringComissionNewComission(&v->newCommission, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionPerbill(&v->maxCommission, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionCommissionChangeRate(&v->changeRate, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionPoolRolesMutation(&v->roles, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringOptionu128(&v->capacity, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCollectionPolicyDescriptor(
        const pd_CollectionPolicyDescriptor_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMintPolicyDescriptor(&v->mint, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMarketPolicyDescriptor(&v->market, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMintPolicyDescriptor(&v->mint, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMarketPolicyDescriptor(&v->market, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCollectionDescriptor(
        const pd_CollectionDescriptor_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringCollectionPolicyDescriptor(&v->policy, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecTokenAssetId(&v->explicitRoyaltyCurrencies, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecAttributeKeyValuePair(&v->attributes, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCollectionPolicyDescriptor(&v->policy, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecTokenAssetId(&v->explicitRoyaltyCurrencies, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecAttributeKeyValuePair(&v->attributes, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringRoyaltyMutation(
        const pd_RoyaltyMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // NoMutation
            snprintf(outValue, outValueLen, "NoMutation");
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_toStringOptionMarketPolicyRoyalty(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringOptionVecTokenAssetId(
        const pd_OptionVecTokenAssetId_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTokenAssetId(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringCollectionMutation(
        const pd_CollectionMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringOptionAccountId(&v->owner, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringRoyaltyMutation(&v->royalty, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionVecTokenAssetId(&v->explicitRoyaltyCurrencies, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionAccountId(&v->owner, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringRoyaltyMutation(&v->royalty, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionVecTokenAssetId(&v->explicitRoyaltyCurrencies, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTransferPolicy(
        const pd_TransferPolicy_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
   return _toStringbool(&v->isFrozen, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCollectionPolicy(
        const pd_CollectionPolicy_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringMintPolicyDescriptor(&v->mint, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTransferPolicy(&v->transfer, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionMarketPolicyRoyalty(&v->market, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMintPolicyDescriptor(&v->mint, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTransferPolicy(&v->transfer, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionMarketPolicyRoyalty(&v->market, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCollectionOf(
        const pd_CollectionOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->owner, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCollectionPolicy(&v->policy, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu64(&v->tokenCount, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringCompactu32(&v->attributeCount, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringCompactu128(&v->totalDeposit, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringOptionBytes(&v->explicitRoyaltyCurrencies, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->owner, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCollectionPolicy(&v->policy, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCompactu64(&v->tokenCount, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringCompactu32(&v->attributeCount, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringCompactu128(&v->totalDeposit, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringOptionBytes(&v->explicitRoyaltyCurrencies, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionCollectionOf(
        const pd_OptionCollectionOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringCollectionOf(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringCollectionAccountOf(
        const pd_CollectionAccountOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringbool(&v->isFrozen, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionBytes(&v->approvals, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu32(&v->accountCount, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringbool(&v->isFrozen, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionBytes(&v->approvals, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCompactu32(&v->accountCount, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOptionCollectionAccountOf(
        const pd_OptionCollectionAccountOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringCollectionAccountOf(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;

}

parser_error_t _toStringCompactAccountIndex(
        const pd_CompactAccountIndex_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringShouldMutateBool(
        const pd_ShouldMutateBool_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // NoMutation
            snprintf(outValue, outValueLen, "NoMutation");
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_toStringbool(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringShouldMutateTokenMarketBehavior(
        const pd_ShouldMutateTokenMarketBehavior_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // NoMutation
            snprintf(outValue, outValueLen, "NoMutation");
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_toStringOptionTokenTokenMarketBehavior(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMutateForeignTokenMetadata(
        const pd_MutateForeignTokenMetadata_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->decimalCount, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBytes(&v->name, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBytes(&v->symbol, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionMultiLocationV3(&v->location, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionu128(&v->unitsPerSecond, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringCompactu128(&v->premintedSupply, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->decimalCount, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBytes(&v->name, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBytes(&v->symbol, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionMultiLocationV3(&v->location, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionu128(&v->unitsPerSecond, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringCompactu128(&v->premintedSupply, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTokenMetadata(
        const pd_TokenMetadata_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // Native
            snprintf(outValue, outValueLen, "Native");
            break;
        case 1: // Foreign
        CHECK_ERROR(_toStringMutateForeignTokenMetadata(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringShouldMutateTokenMetadata(
        const pd_ShouldMutateTokenMetadata_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // NoMutation
            snprintf(outValue, outValueLen, "NoMutation");
            break;
        case 1: // SomeMutation
        CHECK_ERROR(_toStringTokenMetadata(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringTokenMutation(
        const pd_TokenMutation_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringShouldMutateTokenMarketBehavior(&v->behavior, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringShouldMutateBool(&v->listingForbidden, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringShouldMutateTokenMetadata(&v->metadata, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringShouldMutateTokenMarketBehavior(&v->behavior, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringShouldMutateBool(&v->listingForbidden, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringShouldMutateTokenMetadata(&v->metadata, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringInsufficientTokenSufficiency(
        const pd_InsufficientTokenSufficiency_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringCompactu128(&v->unitPrice, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu128(&v->unitPrice, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTokenSufficiency(
        const pd_TokenSufficiency_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // Sufficient
            snprintf(outValue, outValueLen, "Sufficient");
            break;
        case 1: // Insufficient
        CHECK_ERROR(_toStringInsufficientTokenSufficiency(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringTokenOf(
        const pd_TokenOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[10] = { 0 };
    CHECK_ERROR(_toStringCompactu128(&v->supply, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionTokenTokenCap(&v->cap, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionFreezeState(&v->freezeState, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringCompactu128(&v->minimumBalance, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTokenSufficiency(&v->sufficiency, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringCompactu128(&v->mintDeposit, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringCompactu32(&v->attributeCount, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringOptionTokenTokenMarketBehavior(&v->marketBehavior, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringbool(&v->listingForbidden, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTokenMetadata(&v->metadata, outValue, outValueLen, 0, &pages[9]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu128(&v->supply, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionTokenTokenCap(&v->cap, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionFreezeState(&v->freezeState, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringCompactu128(&v->minimumBalance, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTokenSufficiency(&v->sufficiency, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringCompactu128(&v->mintDeposit, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringCompactu32(&v->attributeCount, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringOptionTokenTokenMarketBehavior(&v->marketBehavior, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringbool(&v->listingForbidden, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTokenMetadata(&v->metadata, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVecu128(
        const pd_Vecu128_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u128);
}

parser_error_t _toStringLiquidityAccountConfigOfT(
        const pd_LiquidityAccountConfigOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
        case 0: // All
            snprintf(outValue, outValueLen, "All");
            break;
        case 1: // Whitelist
        case 2: // Blocklist
        CHECK_ERROR(_toStringVecu128(&v->set, outValue, outValueLen, pageIdx, pageCount))
            break;
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringOptionTokenOf(
        const pd_OptionTokenOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTokenOf(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringTokenAccountOf(
        const pd_TokenAccountOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringCompactu128(&v->balance, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu128(&v->reservedBalance, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu128(&v->lockedBalance, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionBytes(&v->namedReserves, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionBytes(&v->locks, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringOptionBytes(&v->approvals, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringbool(&v->isFrozen, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu128(&v->balance, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu128(&v->reservedBalance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCompactu128(&v->lockedBalance, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionBytes(&v->namedReserves, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionBytes(&v->locks, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringOptionBytes(&v->approvals, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringbool(&v->isFrozen, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPercent(
        const pd_Percent_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    char bufferUI[50];
    char bufferRatio[50];

    uint64_to_str(bufferRatio, sizeof(bufferRatio), v->value);

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", bufferRatio);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringOptionTokenAccountOf(
        const pd_OptionTokenAccountOf_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTokenAccountOf(
                &v->contained,
                outValue, outValueLen,
                pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }

    return parser_ok;
}

parser_error_t _toStringEcdsaPublic(
    const pd_EcdsaPublic_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(33)
}

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringEd25519Public(
    const pd_Ed25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringEd25519Signature(
    const pd_Ed25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringH256(
    const pd_H256_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(32);
}

parser_error_t _toStringPerbill(
    const pd_Perbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100] = { 0 };
    char ratioBuffer[80] = { 0 };
    memset(outValue, 0, outValueLen);
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringSr25519Public(
    const pd_Sr25519Public_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringSr25519Signature(
    const pd_Sr25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringAccountIdLookupOfT(
        const pd_AccountIdLookupOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
        case 0: // Id
        CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex(&v->index, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 3: // Address32
        {
            GEN_DEF_TOSTRING_ARRAY(32)
        }
        case 4: // Address20
        {
            GEN_DEF_TOSTRING_ARRAY(20)
        }
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringOptionAccountIdLookupOfT(
        const pd_OptionAccountIdLookupOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    if (v->some == 0) {
        snprintf(outValue, outValueLen, "None");
        return parser_ok;
    }
    return _toStringAccountIdLookupOfT(&v->contained, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerbill(
    const pd_CompactPerbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, false, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringConfigOpBalanceOfT(
    const pd_ConfigOpBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringBalance(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpPerbill(
    const pd_ConfigOpPerbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringPerbill(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpPercent(
    const pd_ConfigOpPercent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringPercent(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Staked");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Stash");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Controller");
        break;
    case 3:
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringBondValueOfT(
        const pd_BondValueOfT_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
        case 0:
        CHECK_ERROR(_toStringCompactBalance(&v->amount, outValue, outValueLen, pageIdx, pageCount));
            break;
        case 1:
            snprintf(outValue, outValueLen, "Fill");
            break;
        default:
            return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactPerbill(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerbill(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringStakingInfo(
        const pd_StakingInfo_t* v,
        char* outValue,
        uint16_t outValueLen,
        uint8_t pageIdx,
        uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringPerbill(&v->annual_inflation_rate, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPerbill(&v->collator_payout_cut, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPerbill(&v->annual_inflation_rate, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPerbill(&v->collator_payout_cut, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringConfigOpu32(
    const pd_ConfigOpu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringu32(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress(
    const pd_EthereumAddress_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringPoolId(
    const pd_PoolId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecAccountIdLookupOfT(
    const pd_VecAccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountIdLookupOfT);
}

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId);
}

parser_error_t _toStringVecu32(
    const pd_Vecu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u32);
}

parser_error_t _toStringVecu8(
    const pd_Vecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u8);
}

parser_error_t _toStringOptionNetworkIdV3(
    const pd_OptionNetworkIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringNetworkIdV3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu8_array_20(
    const pd_Optionu8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu8_array_20(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionAccountId(
    const pd_OptionAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu32(
    const pd_Optionu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu32(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
