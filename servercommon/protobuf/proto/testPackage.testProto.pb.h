// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/testPackage.testProto.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2ftestPackage_2etestProto_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_proto_2ftestPackage_2etestProto_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_proto_2ftestPackage_2etestProto_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2ftestPackage_2etestProto_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_proto_2ftestPackage_2etestProto_2eproto;
class SearchRequest;
class SearchRequestDefaultTypeInternal;
extern SearchRequestDefaultTypeInternal _SearchRequest_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::SearchRequest* Arena::CreateMaybeMessage<::SearchRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class SearchRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SearchRequest) */ {
 public:
  inline SearchRequest() : SearchRequest(nullptr) {};
  virtual ~SearchRequest();

  SearchRequest(const SearchRequest& from);
  SearchRequest(SearchRequest&& from) noexcept
    : SearchRequest() {
    *this = ::std::move(from);
  }

  inline SearchRequest& operator=(const SearchRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SearchRequest& operator=(SearchRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SearchRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SearchRequest* internal_default_instance() {
    return reinterpret_cast<const SearchRequest*>(
               &_SearchRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SearchRequest& a, SearchRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SearchRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SearchRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SearchRequest* New() const final {
    return CreateMaybeMessage<SearchRequest>(nullptr);
  }

  SearchRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SearchRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SearchRequest& from);
  void MergeFrom(const SearchRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SearchRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SearchRequest";
  }
  protected:
  explicit SearchRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_proto_2ftestPackage_2etestProto_2eproto);
    return ::descriptor_table_proto_2ftestPackage_2etestProto_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCurTimeFieldNumber = 1,
  };
  // string cur_time = 1;
  void clear_cur_time();
  const std::string& cur_time() const;
  void set_cur_time(const std::string& value);
  void set_cur_time(std::string&& value);
  void set_cur_time(const char* value);
  void set_cur_time(const char* value, size_t size);
  std::string* mutable_cur_time();
  std::string* release_cur_time();
  void set_allocated_cur_time(std::string* cur_time);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_cur_time();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_cur_time(
      std::string* cur_time);
  private:
  const std::string& _internal_cur_time() const;
  void _internal_set_cur_time(const std::string& value);
  std::string* _internal_mutable_cur_time();
  public:

  // @@protoc_insertion_point(class_scope:SearchRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr cur_time_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_proto_2ftestPackage_2etestProto_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SearchRequest

// string cur_time = 1;
inline void SearchRequest::clear_cur_time() {
  cur_time_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& SearchRequest::cur_time() const {
  // @@protoc_insertion_point(field_get:SearchRequest.cur_time)
  return _internal_cur_time();
}
inline void SearchRequest::set_cur_time(const std::string& value) {
  _internal_set_cur_time(value);
  // @@protoc_insertion_point(field_set:SearchRequest.cur_time)
}
inline std::string* SearchRequest::mutable_cur_time() {
  // @@protoc_insertion_point(field_mutable:SearchRequest.cur_time)
  return _internal_mutable_cur_time();
}
inline const std::string& SearchRequest::_internal_cur_time() const {
  return cur_time_.Get();
}
inline void SearchRequest::_internal_set_cur_time(const std::string& value) {
  
  cur_time_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void SearchRequest::set_cur_time(std::string&& value) {
  
  cur_time_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:SearchRequest.cur_time)
}
inline void SearchRequest::set_cur_time(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  cur_time_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:SearchRequest.cur_time)
}
inline void SearchRequest::set_cur_time(const char* value,
    size_t size) {
  
  cur_time_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:SearchRequest.cur_time)
}
inline std::string* SearchRequest::_internal_mutable_cur_time() {
  
  return cur_time_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* SearchRequest::release_cur_time() {
  // @@protoc_insertion_point(field_release:SearchRequest.cur_time)
  return cur_time_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SearchRequest::set_allocated_cur_time(std::string* cur_time) {
  if (cur_time != nullptr) {
    
  } else {
    
  }
  cur_time_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), cur_time,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:SearchRequest.cur_time)
}
inline std::string* SearchRequest::unsafe_arena_release_cur_time() {
  // @@protoc_insertion_point(field_unsafe_arena_release:SearchRequest.cur_time)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return cur_time_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void SearchRequest::unsafe_arena_set_allocated_cur_time(
    std::string* cur_time) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (cur_time != nullptr) {
    
  } else {
    
  }
  cur_time_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      cur_time, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:SearchRequest.cur_time)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_proto_2ftestPackage_2etestProto_2eproto