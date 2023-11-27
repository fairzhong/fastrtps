// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TYPES_BASE_H
#define TYPES_BASE_H

#include <fastdds/dds/core/ReturnCode.hpp>
#include <fastdds/dds/core/Types.hpp>
#include <fastdds/dds/xtypes/Types.hpp>

namespace eprosima {
namespace fastrtps {
namespace types {

//! A special value indicating an unlimited quantity
using eprosima::fastdds::dds::BOUND_UNLIMITED;

using eprosima::fastrtps::rtps::octet;

using OctetSeq = std::vector<octet>;

OctetSeq& operator ++(
        OctetSeq&);

OctetSeq operator ++(
        OctetSeq&,
        int);

size_t to_size_t(
        const OctetSeq&);

inline namespace xtypes_names {

using eprosima::fastdds::dds::CONST_TRUE;
using eprosima::fastdds::dds::CONST_FALSE;

using eprosima::fastdds::dds::ANNOTATION_KEY_ID;
using eprosima::fastdds::dds::ANNOTATION_EPKEY_ID;
using eprosima::fastdds::dds::ANNOTATION_TOPIC_ID;
using eprosima::fastdds::dds::ANNOTATION_EXTENSIBILITY_ID;
using eprosima::fastdds::dds::ANNOTATION_FINAL_ID;
using eprosima::fastdds::dds::ANNOTATION_APPENDABLE_ID;
using eprosima::fastdds::dds::ANNOTATION_MUTABLE_ID;
using eprosima::fastdds::dds::ANNOTATION_NESTED_ID;
using eprosima::fastdds::dds::ANNOTATION_OPTIONAL_ID;
using eprosima::fastdds::dds::ANNOTATION_MUST_UNDERSTAND_ID;
using eprosima::fastdds::dds::ANNOTATION_NON_SERIALIZED_ID;
using eprosima::fastdds::dds::ANNOTATION_BIT_BOUND_ID;
using eprosima::fastdds::dds::ANNOTATION_DEFAULT_ID;
using eprosima::fastdds::dds::ANNOTATION_DEFAULT_LITERAL_ID;
using eprosima::fastdds::dds::ANNOTATION_VALUE_ID;
using eprosima::fastdds::dds::ANNOTATION_POSITION_ID;
using eprosima::fastdds::dds::ANNOTATION_EXTERNAL_ID;

using eprosima::fastdds::dds::EXTENSIBILITY_FINAL;
using eprosima::fastdds::dds::EXTENSIBILITY_APPENDABLE;
using eprosima::fastdds::dds::EXTENSIBILITY_MUTABLE;

using eprosima::fastdds::dds::TKNAME_BOOLEAN;
using eprosima::fastdds::dds::TKNAME_INT16;
using eprosima::fastdds::dds::TKNAME_UINT16;
using eprosima::fastdds::dds::TKNAME_INT32;
using eprosima::fastdds::dds::TKNAME_UINT32;
using eprosima::fastdds::dds::TKNAME_INT64;
using eprosima::fastdds::dds::TKNAME_UINT64;
using eprosima::fastdds::dds::TKNAME_CHAR8;
using eprosima::fastdds::dds::TKNAME_BYTE;
using eprosima::fastdds::dds::TKNAME_UINT8;
using eprosima::fastdds::dds::TKNAME_CHAR16;
using eprosima::fastdds::dds::TKNAME_CHAR16T;
using eprosima::fastdds::dds::TKNAME_FLOAT32;
using eprosima::fastdds::dds::TKNAME_FLOAT64;
using eprosima::fastdds::dds::TKNAME_FLOAT128;

using eprosima::fastdds::dds::TKNAME_STRING8;
using eprosima::fastdds::dds::TKNAME_STRING16;
using eprosima::fastdds::dds::TKNAME_ALIAS;
using eprosima::fastdds::dds::TKNAME_ENUM;
using eprosima::fastdds::dds::TKNAME_BITMASK;
using eprosima::fastdds::dds::TKNAME_ANNOTATION;
using eprosima::fastdds::dds::TKNAME_STRUCTURE;
using eprosima::fastdds::dds::TKNAME_UNION;
using eprosima::fastdds::dds::TKNAME_BITSET;
using eprosima::fastdds::dds::TKNAME_SEQUENCE;
using eprosima::fastdds::dds::TKNAME_ARRAY;
using eprosima::fastdds::dds::TKNAME_MAP;

} // namespace xtypes_names

// ---------- TypeKinds (begin) ------------------

using TypeKind = eprosima::fastrtps::rtps::octet;

// invalid
const TypeKind TK_NONE = 0x00;

// Primitive TKs
const TypeKind TK_BOOLEAN = 0x01;
const TypeKind TK_BYTE = 0x02;
const TypeKind TK_INT16 = 0x03;
const TypeKind TK_INT32 = 0x04;
const TypeKind TK_INT64 = 0x05;
const TypeKind TK_UINT16 = 0x06;
const TypeKind TK_UINT32 = 0x07;
const TypeKind TK_UINT64 = 0x08;
const TypeKind TK_FLOAT32 = 0x09;
const TypeKind TK_FLOAT64 = 0x0A;
const TypeKind TK_FLOAT128 = 0x0B;
const TypeKind TK_CHAR8 = 0x10;
const TypeKind TK_CHAR16 = 0x11;

// String TKs
const TypeKind TK_STRING8 = 0x20;
const TypeKind TK_STRING16 = 0x21;

// Constructed/Named types
const TypeKind TK_ALIAS = 0x30;

// Enumerated TKs
const TypeKind TK_ENUM = 0x40;
const TypeKind TK_BITMASK = 0x41;

// Structured TKs
const TypeKind TK_ANNOTATION = 0x50;
const TypeKind TK_STRUCTURE = 0x51;
const TypeKind TK_UNION = 0x52;
const TypeKind TK_BITSET = 0x53;

// Collection TKs
const TypeKind TK_SEQUENCE = 0x60;
const TypeKind TK_ARRAY = 0x61;
const TypeKind TK_MAP = 0x62;

// TypeIdentifiers
const TypeKind TI_STRING8_SMALL = 0x70;
const TypeKind TI_STRING8_LARGE = 0x71;
const TypeKind TI_STRING16_SMALL = 0x72;
const TypeKind TI_STRING16_LARGE = 0x73;
const TypeKind TI_PLAIN_SEQUENCE_SMALL = 0x80;
const TypeKind TI_PLAIN_SEQUENCE_LARGE = 0x81;
const TypeKind TI_PLAIN_ARRAY_SMALL = 0x90;
const TypeKind TI_PLAIN_ARRAY_LARGE = 0x91;
const TypeKind TI_PLAIN_MAP_SMALL = 0xA0;
const TypeKind TI_PLAIN_MAP_LARGE = 0xA1;
const TypeKind TI_STRONGLY_CONNECTED_COMPONENT = 0xB0;

// Equivalence Kinds
const TypeKind EK_MINIMAL = 0xF1; // 0x1111 0001
const TypeKind EK_COMPLETE = 0xF2; // 0x1111 0010
const TypeKind EK_BOTH = 0xF3; // 0x1111 0011

// ---------- TypeKinds (end) ------------------

// Auxiliary metadata

template<TypeKind kind>
using is_primitive = std::conditional<(kind > TK_NONE && kind <= TK_CHAR16), std::true_type,
                std::false_type>;

template<TypeKind kind>
using is_primitive_t = typename is_primitive<kind>::type;

// The name of some element (e.g. type, type member, module)
// Valid characters are alphanumeric plus the "_" cannot start with digit

using eprosima::fastdds::dds::MEMBER_NAME_MAX_LENGTH;
using eprosima::fastdds::dds::MemberName;

// Qualified type name includes the name of containing modules
// using "::" as separator. No leading "::". E.g. "MyModule::MyType"
using eprosima::fastdds::dds::TYPE_NAME_MAX_LENGTH;
using eprosima::fastdds::dds::QualifiedTypeName;

// Every type has an ID. Those of the primitive types are pre-defined.
using eprosima::fastdds::dds::PrimitiveTypeId;

// First 4 bytes of MD5 of of a member name converted to bytes
// using UTF-8 encoding and without a 'nul' terminator.
// Example: the member name "color" has NameHash {0x70, 0xDD, 0xA5, 0xDF}
using eprosima::fastdds::dds::NameHash;

// Mask used to remove the flags that do no affect assignability
// Selects  T1, T2, O, M, K, D
using eprosima::fastdds::dds::MemberFlagMinimalMask;

using ReturnCode_t = eprosima::fastdds::dds::ReturnCode_t;
const ReturnCode_t RETCODE_OK =  eprosima::fastdds::dds::RETCODE_OK;
const ReturnCode_t RETCODE_ERROR =  eprosima::fastdds::dds::RETCODE_ERROR;
const ReturnCode_t RETCODE_UNSUPPORTED =  eprosima::fastdds::dds::RETCODE_UNSUPPORTED;
const ReturnCode_t RETCODE_BAD_PARAMETER =  eprosima::fastdds::dds::RETCODE_BAD_PARAMETER;
const ReturnCode_t RETCODE_PRECONDITION_NOT_MET = eprosima::fastdds::dds::RETCODE_PRECONDITION_NOT_MET;
const ReturnCode_t RETCODE_OUT_OF_RESOURCES =  eprosima::fastdds::dds::RETCODE_OUT_OF_RESOURCES;
const ReturnCode_t RETCODE_NOT_ENABLED =  eprosima::fastdds::dds::RETCODE_NOT_ENABLED;
const ReturnCode_t RETCODE_IMMUTABLE_POLICY =  eprosima::fastdds::dds::RETCODE_IMMUTABLE_POLICY;
const ReturnCode_t RETCODE_INCONSISTENT_POLICY =  eprosima::fastdds::dds::RETCODE_INCONSISTENT_POLICY;
const ReturnCode_t RETCODE_ALREADY_DELETED =  eprosima::fastdds::dds::RETCODE_ALREADY_DELETED;
const ReturnCode_t RETCODE_TIMEOUT =  eprosima::fastdds::dds::RETCODE_TIMEOUT;
const ReturnCode_t RETCODE_NO_DATA =  eprosima::fastdds::dds::RETCODE_NO_DATA;
const ReturnCode_t RETCODE_ILLEGAL_OPERATION = eprosima::fastdds::dds::RETCODE_ILLEGAL_OPERATION;

using eprosima::fastdds::dds::MAX_BITMASK_LENGTH;
using eprosima::fastdds::dds::MAX_ELEMENTS_COUNT;
using eprosima::fastdds::dds::MAX_STRING_LENGTH;

// Long Bound of a collection type
using eprosima::fastdds::dds::LBound;
using eprosima::fastdds::dds::LBoundSeq;
using eprosima::fastdds::dds::INVALID_LBOUND;

// Short Bound of a collection type
using eprosima::fastdds::dds::SBound;
using eprosima::fastdds::dds::SBoundSeq;
using eprosima::fastdds::dds::INVALID_SBOUND;

// Auxiliar function to compare sequences (std::vector)
template<class T>
bool compareSequence(
        const std::vector<T>& a,
        const std::vector<T>& b)
{
    if (a.size() == b.size())
    {
        auto aIt = a.begin();
        auto bIt = b.begin();
        while (aIt != a.end() && bIt != b.end())
        {
            if (*aIt == *bIt)
            {
                ++aIt;
                ++bIt;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

// Flags that apply to struct/union/collection/enum/bitmask/bitset
// members/elements and DO affect type assignability
// Depending on the flag it may not apply to members of all types
using eprosima::fastdds::dds::MemberFlag;
using eprosima::fastdds::dds::CollectionElementFlag;   // T1, T2, X
using eprosima::fastdds::dds::StructMemberFlag;        // T1, T2, O, M, K, X
using eprosima::fastdds::dds::UnionMemberFlag;         // T1, T2, D, X
using eprosima::fastdds::dds::UnionDiscriminatorFlag;  // T1, T2, K
using eprosima::fastdds::dds::EnumeratedLiteralFlag;   // D
using eprosima::fastdds::dds::AnnotationParameterFlag; // Unused. No flags apply
using eprosima::fastdds::dds::AliasMemberFlag;         // Unused. No flags apply
using eprosima::fastdds::dds::BitflagFlag;             // Unused. No flags apply
using eprosima::fastdds::dds::BitsetMemberFlag;        // Unused. No flags apply

// Flags that apply to type declarationa and DO affect assignability
// Depending on the flag it may not apply to all types
// When not all, the applicable  types are listed
using eprosima::fastdds::dds::TypeFlag;
using eprosima::fastdds::dds::StructTypeFlag;        // All flags apply
using eprosima::fastdds::dds::UnionTypeFlag;         // All flags apply
using eprosima::fastdds::dds::CollectionTypeFlag;    // Unused. No flags apply
using eprosima::fastdds::dds::AnnotationTypeFlag;    // Unused. No flags apply
using eprosima::fastdds::dds::AliasTypeFlag;         // Unused. No flags apply
using eprosima::fastdds::dds::EnumTypeFlag;          // Unused. No flags apply
using eprosima::fastdds::dds::BitmaskTypeFlag;       // Unused. No flags apply
using eprosima::fastdds::dds::BitsetTypeFlag;        // Unused. No flags apply

// Mask used to remove the flags that do no affect assignability
using eprosima::fastdds::dds::TypeFlagMinimalMask; // Selects  M, A, F

// --- Annotation usage: ----------------------------------------------

// ID of a type member
using eprosima::fastdds::dds::ANNOTATION_STR_VALUE_MAX_LEN;
using eprosima::fastdds::dds::ANNOTATION_OCTETSEC_VALUE_MAX_LEN;

using eprosima::fastdds::dds::MemberId;
using eprosima::fastdds::dds::MEMBER_ID_INVALID;

} // namespace types
} // namespace fastrtps
} // namespace eprosima

#endif // TYPES_BASE_H
