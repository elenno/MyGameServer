// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/testPackage.testProto.proto

#include "proto/testPackage.testProto.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class CS_SearchRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CS_SearchRequest> _instance;
} _CS_SearchRequest_default_instance_;
class SC_SearchRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SC_SearchRequest> _instance;
} _SC_SearchRequest_default_instance_;
static void InitDefaultsscc_info_CS_SearchRequest_proto_2ftestPackage_2etestProto_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_CS_SearchRequest_default_instance_;
    new (ptr) ::CS_SearchRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::CS_SearchRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CS_SearchRequest_proto_2ftestPackage_2etestProto_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_CS_SearchRequest_proto_2ftestPackage_2etestProto_2eproto}, {}};

static void InitDefaultsscc_info_SC_SearchRequest_proto_2ftestPackage_2etestProto_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_SC_SearchRequest_default_instance_;
    new (ptr) ::SC_SearchRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SC_SearchRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SC_SearchRequest_proto_2ftestPackage_2etestProto_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SC_SearchRequest_proto_2ftestPackage_2etestProto_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_proto_2ftestPackage_2etestProto_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_proto_2ftestPackage_2etestProto_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_proto_2ftestPackage_2etestProto_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_proto_2ftestPackage_2etestProto_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::CS_SearchRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::CS_SearchRequest, cur_time_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::SC_SearchRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::SC_SearchRequest, answer_msg_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::CS_SearchRequest)},
  { 6, -1, sizeof(::SC_SearchRequest)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_CS_SearchRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_SC_SearchRequest_default_instance_),
};

const char descriptor_table_protodef_proto_2ftestPackage_2etestProto_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n!proto/testPackage.testProto.proto\"$\n\020C"
  "S_SearchRequest\022\020\n\010cur_time\030\001 \001(\t\"&\n\020SC_"
  "SearchRequest\022\022\n\nanswer_msg\030\001 \001(\tb\006proto"
  "3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_proto_2ftestPackage_2etestProto_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_proto_2ftestPackage_2etestProto_2eproto_sccs[2] = {
  &scc_info_CS_SearchRequest_proto_2ftestPackage_2etestProto_2eproto.base,
  &scc_info_SC_SearchRequest_proto_2ftestPackage_2etestProto_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_proto_2ftestPackage_2etestProto_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2ftestPackage_2etestProto_2eproto = {
  false, false, descriptor_table_protodef_proto_2ftestPackage_2etestProto_2eproto, "proto/testPackage.testProto.proto", 121,
  &descriptor_table_proto_2ftestPackage_2etestProto_2eproto_once, descriptor_table_proto_2ftestPackage_2etestProto_2eproto_sccs, descriptor_table_proto_2ftestPackage_2etestProto_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_proto_2ftestPackage_2etestProto_2eproto::offsets,
  file_level_metadata_proto_2ftestPackage_2etestProto_2eproto, 2, file_level_enum_descriptors_proto_2ftestPackage_2etestProto_2eproto, file_level_service_descriptors_proto_2ftestPackage_2etestProto_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_proto_2ftestPackage_2etestProto_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_proto_2ftestPackage_2etestProto_2eproto)), true);

// ===================================================================

void CS_SearchRequest::InitAsDefaultInstance() {
}
class CS_SearchRequest::_Internal {
 public:
};

CS_SearchRequest::CS_SearchRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:CS_SearchRequest)
}
CS_SearchRequest::CS_SearchRequest(const CS_SearchRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  cur_time_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_cur_time().empty()) {
    cur_time_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_cur_time(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:CS_SearchRequest)
}

void CS_SearchRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CS_SearchRequest_proto_2ftestPackage_2etestProto_2eproto.base);
  cur_time_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

CS_SearchRequest::~CS_SearchRequest() {
  // @@protoc_insertion_point(destructor:CS_SearchRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void CS_SearchRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  cur_time_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CS_SearchRequest::ArenaDtor(void* object) {
  CS_SearchRequest* _this = reinterpret_cast< CS_SearchRequest* >(object);
  (void)_this;
}
void CS_SearchRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CS_SearchRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CS_SearchRequest& CS_SearchRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CS_SearchRequest_proto_2ftestPackage_2etestProto_2eproto.base);
  return *internal_default_instance();
}


void CS_SearchRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:CS_SearchRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cur_time_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CS_SearchRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string cur_time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_cur_time();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "CS_SearchRequest.cur_time"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CS_SearchRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CS_SearchRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string cur_time = 1;
  if (this->cur_time().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_cur_time().data(), static_cast<int>(this->_internal_cur_time().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "CS_SearchRequest.cur_time");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_cur_time(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CS_SearchRequest)
  return target;
}

size_t CS_SearchRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CS_SearchRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string cur_time = 1;
  if (this->cur_time().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_cur_time());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CS_SearchRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:CS_SearchRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const CS_SearchRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CS_SearchRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:CS_SearchRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:CS_SearchRequest)
    MergeFrom(*source);
  }
}

void CS_SearchRequest::MergeFrom(const CS_SearchRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CS_SearchRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.cur_time().size() > 0) {
    _internal_set_cur_time(from._internal_cur_time());
  }
}

void CS_SearchRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:CS_SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_SearchRequest::CopyFrom(const CS_SearchRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CS_SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_SearchRequest::IsInitialized() const {
  return true;
}

void CS_SearchRequest::InternalSwap(CS_SearchRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  cur_time_.Swap(&other->cur_time_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata CS_SearchRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void SC_SearchRequest::InitAsDefaultInstance() {
}
class SC_SearchRequest::_Internal {
 public:
};

SC_SearchRequest::SC_SearchRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:SC_SearchRequest)
}
SC_SearchRequest::SC_SearchRequest(const SC_SearchRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  answer_msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_answer_msg().empty()) {
    answer_msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_answer_msg(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:SC_SearchRequest)
}

void SC_SearchRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SC_SearchRequest_proto_2ftestPackage_2etestProto_2eproto.base);
  answer_msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

SC_SearchRequest::~SC_SearchRequest() {
  // @@protoc_insertion_point(destructor:SC_SearchRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SC_SearchRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  answer_msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void SC_SearchRequest::ArenaDtor(void* object) {
  SC_SearchRequest* _this = reinterpret_cast< SC_SearchRequest* >(object);
  (void)_this;
}
void SC_SearchRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SC_SearchRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SC_SearchRequest& SC_SearchRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SC_SearchRequest_proto_2ftestPackage_2etestProto_2eproto.base);
  return *internal_default_instance();
}


void SC_SearchRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:SC_SearchRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  answer_msg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SC_SearchRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string answer_msg = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_answer_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "SC_SearchRequest.answer_msg"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SC_SearchRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:SC_SearchRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string answer_msg = 1;
  if (this->answer_msg().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_answer_msg().data(), static_cast<int>(this->_internal_answer_msg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "SC_SearchRequest.answer_msg");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_answer_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SC_SearchRequest)
  return target;
}

size_t SC_SearchRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SC_SearchRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string answer_msg = 1;
  if (this->answer_msg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_answer_msg());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SC_SearchRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SC_SearchRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const SC_SearchRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SC_SearchRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SC_SearchRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SC_SearchRequest)
    MergeFrom(*source);
  }
}

void SC_SearchRequest::MergeFrom(const SC_SearchRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SC_SearchRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.answer_msg().size() > 0) {
    _internal_set_answer_msg(from._internal_answer_msg());
  }
}

void SC_SearchRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SC_SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_SearchRequest::CopyFrom(const SC_SearchRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SC_SearchRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_SearchRequest::IsInitialized() const {
  return true;
}

void SC_SearchRequest::InternalSwap(SC_SearchRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  answer_msg_.Swap(&other->answer_msg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata SC_SearchRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::CS_SearchRequest* Arena::CreateMaybeMessage< ::CS_SearchRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CS_SearchRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::SC_SearchRequest* Arena::CreateMaybeMessage< ::SC_SearchRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::SC_SearchRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
