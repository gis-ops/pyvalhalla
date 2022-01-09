// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sign.proto

#include "sign.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_tripcommon_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Pronunciation_tripcommon_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_sign_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_TripSignElement_sign_2eproto;
namespace valhalla {
class TripSignElementDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TripSignElement> _instance;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
  bool is_route_number_;
  ::PROTOBUF_NAMESPACE_ID::uint32 consecutive_count_;
} _TripSignElement_default_instance_;
class TripSignDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TripSign> _instance;
} _TripSign_default_instance_;
}  // namespace valhalla
static void InitDefaultsscc_info_TripSign_sign_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::valhalla::_TripSign_default_instance_;
    new (ptr) ::valhalla::TripSign();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::valhalla::TripSign::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_TripSign_sign_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_TripSign_sign_2eproto}, {
      &scc_info_TripSignElement_sign_2eproto.base,}};

static void InitDefaultsscc_info_TripSignElement_sign_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::valhalla::_TripSignElement_default_instance_;
    new (ptr) ::valhalla::TripSignElement();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::valhalla::TripSignElement::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_TripSignElement_sign_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_TripSignElement_sign_2eproto}, {
      &scc_info_Pronunciation_tripcommon_2eproto.base,}};

namespace valhalla {

// ===================================================================

void TripSignElement::InitAsDefaultInstance() {
  ::valhalla::_TripSignElement_default_instance_._instance.get_mutable()->pronunciation_ = const_cast< ::valhalla::Pronunciation*>(
      ::valhalla::Pronunciation::internal_default_instance());
}
class TripSignElement::_Internal {
 public:
  static const ::valhalla::Pronunciation& pronunciation(const TripSignElement* msg);
};

const ::valhalla::Pronunciation&
TripSignElement::_Internal::pronunciation(const TripSignElement* msg) {
  return *msg->pronunciation_;
}
void TripSignElement::clear_pronunciation() {
  if (GetArena() == nullptr && pronunciation_ != nullptr) {
    delete pronunciation_;
  }
  pronunciation_ = nullptr;
}
TripSignElement::TripSignElement(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:valhalla.TripSignElement)
}
TripSignElement::TripSignElement(const TripSignElement& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  if (from._internal_has_pronunciation()) {
    pronunciation_ = new ::valhalla::Pronunciation(*from.pronunciation_);
  } else {
    pronunciation_ = nullptr;
  }
  clear_has_has_text();
  switch (from.has_text_case()) {
    case kText: {
      _internal_set_text(from._internal_text());
      break;
    }
    case HAS_TEXT_NOT_SET: {
      break;
    }
  }
  clear_has_has_is_route_number();
  switch (from.has_is_route_number_case()) {
    case kIsRouteNumber: {
      _internal_set_is_route_number(from._internal_is_route_number());
      break;
    }
    case HAS_IS_ROUTE_NUMBER_NOT_SET: {
      break;
    }
  }
  clear_has_has_consecutive_count();
  switch (from.has_consecutive_count_case()) {
    case kConsecutiveCount: {
      _internal_set_consecutive_count(from._internal_consecutive_count());
      break;
    }
    case HAS_CONSECUTIVE_COUNT_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:valhalla.TripSignElement)
}

void TripSignElement::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TripSignElement_sign_2eproto.base);
  pronunciation_ = nullptr;
  clear_has_has_text();
  clear_has_has_is_route_number();
  clear_has_has_consecutive_count();
}

TripSignElement::~TripSignElement() {
  // @@protoc_insertion_point(destructor:valhalla.TripSignElement)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void TripSignElement::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete pronunciation_;
  if (has_has_text()) {
    clear_has_text();
  }
  if (has_has_is_route_number()) {
    clear_has_is_route_number();
  }
  if (has_has_consecutive_count()) {
    clear_has_consecutive_count();
  }
}

void TripSignElement::ArenaDtor(void* object) {
  TripSignElement* _this = reinterpret_cast< TripSignElement* >(object);
  (void)_this;
}
void TripSignElement::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TripSignElement::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TripSignElement& TripSignElement::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TripSignElement_sign_2eproto.base);
  return *internal_default_instance();
}


void TripSignElement::clear_has_text() {
// @@protoc_insertion_point(one_of_clear_start:valhalla.TripSignElement)
  switch (has_text_case()) {
    case kText: {
      has_text_.text_.Destroy(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
      break;
    }
    case HAS_TEXT_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = HAS_TEXT_NOT_SET;
}

void TripSignElement::clear_has_is_route_number() {
// @@protoc_insertion_point(one_of_clear_start:valhalla.TripSignElement)
  switch (has_is_route_number_case()) {
    case kIsRouteNumber: {
      // No need to clear
      break;
    }
    case HAS_IS_ROUTE_NUMBER_NOT_SET: {
      break;
    }
  }
  _oneof_case_[1] = HAS_IS_ROUTE_NUMBER_NOT_SET;
}

void TripSignElement::clear_has_consecutive_count() {
// @@protoc_insertion_point(one_of_clear_start:valhalla.TripSignElement)
  switch (has_consecutive_count_case()) {
    case kConsecutiveCount: {
      // No need to clear
      break;
    }
    case HAS_CONSECUTIVE_COUNT_NOT_SET: {
      break;
    }
  }
  _oneof_case_[2] = HAS_CONSECUTIVE_COUNT_NOT_SET;
}


void TripSignElement::Clear() {
// @@protoc_insertion_point(message_clear_start:valhalla.TripSignElement)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && pronunciation_ != nullptr) {
    delete pronunciation_;
  }
  pronunciation_ = nullptr;
  clear_has_text();
  clear_has_is_route_number();
  clear_has_consecutive_count();
  _internal_metadata_.Clear<std::string>();
}

const char* TripSignElement::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string text = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_text();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, nullptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool is_route_number = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _internal_set_is_route_number(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 consecutive_count = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _internal_set_consecutive_count(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .valhalla.Pronunciation pronunciation = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_pronunciation(), ptr);
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
            _internal_metadata_.mutable_unknown_fields<std::string>(),
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

::PROTOBUF_NAMESPACE_ID::uint8* TripSignElement::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:valhalla.TripSignElement)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string text = 1;
  if (_internal_has_text()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_text().data(), static_cast<int>(this->_internal_text().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "valhalla.TripSignElement.text");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_text(), target);
  }

  // bool is_route_number = 2;
  if (_internal_has_is_route_number()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(2, this->_internal_is_route_number(), target);
  }

  // uint32 consecutive_count = 3;
  if (_internal_has_consecutive_count()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_consecutive_count(), target);
  }

  // .valhalla.Pronunciation pronunciation = 4;
  if (this->has_pronunciation()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::pronunciation(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:valhalla.TripSignElement)
  return target;
}

size_t TripSignElement::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:valhalla.TripSignElement)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .valhalla.Pronunciation pronunciation = 4;
  if (this->has_pronunciation()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *pronunciation_);
  }

  switch (has_text_case()) {
    // string text = 1;
    case kText: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_text());
      break;
    }
    case HAS_TEXT_NOT_SET: {
      break;
    }
  }
  switch (has_is_route_number_case()) {
    // bool is_route_number = 2;
    case kIsRouteNumber: {
      total_size += 1 + 1;
      break;
    }
    case HAS_IS_ROUTE_NUMBER_NOT_SET: {
      break;
    }
  }
  switch (has_consecutive_count_case()) {
    // uint32 consecutive_count = 3;
    case kConsecutiveCount: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_consecutive_count());
      break;
    }
    case HAS_CONSECUTIVE_COUNT_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TripSignElement::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const TripSignElement*>(
      &from));
}

void TripSignElement::MergeFrom(const TripSignElement& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:valhalla.TripSignElement)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_pronunciation()) {
    _internal_mutable_pronunciation()->::valhalla::Pronunciation::MergeFrom(from._internal_pronunciation());
  }
  switch (from.has_text_case()) {
    case kText: {
      _internal_set_text(from._internal_text());
      break;
    }
    case HAS_TEXT_NOT_SET: {
      break;
    }
  }
  switch (from.has_is_route_number_case()) {
    case kIsRouteNumber: {
      _internal_set_is_route_number(from._internal_is_route_number());
      break;
    }
    case HAS_IS_ROUTE_NUMBER_NOT_SET: {
      break;
    }
  }
  switch (from.has_consecutive_count_case()) {
    case kConsecutiveCount: {
      _internal_set_consecutive_count(from._internal_consecutive_count());
      break;
    }
    case HAS_CONSECUTIVE_COUNT_NOT_SET: {
      break;
    }
  }
}

void TripSignElement::CopyFrom(const TripSignElement& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:valhalla.TripSignElement)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TripSignElement::IsInitialized() const {
  return true;
}

void TripSignElement::InternalSwap(TripSignElement* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  swap(pronunciation_, other->pronunciation_);
  swap(has_text_, other->has_text_);
  swap(has_is_route_number_, other->has_is_route_number_);
  swap(has_consecutive_count_, other->has_consecutive_count_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
  swap(_oneof_case_[1], other->_oneof_case_[1]);
  swap(_oneof_case_[2], other->_oneof_case_[2]);
}

std::string TripSignElement::GetTypeName() const {
  return "valhalla.TripSignElement";
}


// ===================================================================

void TripSign::InitAsDefaultInstance() {
}
class TripSign::_Internal {
 public:
};

TripSign::TripSign(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena),
  exit_numbers_(arena),
  exit_onto_streets_(arena),
  exit_toward_locations_(arena),
  exit_names_(arena),
  guide_onto_streets_(arena),
  guide_toward_locations_(arena),
  junction_names_(arena),
  guidance_view_junctions_(arena),
  guidance_view_signboards_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:valhalla.TripSign)
}
TripSign::TripSign(const TripSign& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(),
      exit_numbers_(from.exit_numbers_),
      exit_onto_streets_(from.exit_onto_streets_),
      exit_toward_locations_(from.exit_toward_locations_),
      exit_names_(from.exit_names_),
      guide_onto_streets_(from.guide_onto_streets_),
      guide_toward_locations_(from.guide_toward_locations_),
      junction_names_(from.junction_names_),
      guidance_view_junctions_(from.guidance_view_junctions_),
      guidance_view_signboards_(from.guidance_view_signboards_) {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:valhalla.TripSign)
}

void TripSign::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TripSign_sign_2eproto.base);
}

TripSign::~TripSign() {
  // @@protoc_insertion_point(destructor:valhalla.TripSign)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void TripSign::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void TripSign::ArenaDtor(void* object) {
  TripSign* _this = reinterpret_cast< TripSign* >(object);
  (void)_this;
}
void TripSign::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void TripSign::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TripSign& TripSign::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TripSign_sign_2eproto.base);
  return *internal_default_instance();
}


void TripSign::Clear() {
// @@protoc_insertion_point(message_clear_start:valhalla.TripSign)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  exit_numbers_.Clear();
  exit_onto_streets_.Clear();
  exit_toward_locations_.Clear();
  exit_names_.Clear();
  guide_onto_streets_.Clear();
  guide_toward_locations_.Clear();
  junction_names_.Clear();
  guidance_view_junctions_.Clear();
  guidance_view_signboards_.Clear();
  _internal_metadata_.Clear<std::string>();
}

const char* TripSign::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .valhalla.TripSignElement exit_numbers = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_exit_numbers(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement exit_onto_streets = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_exit_onto_streets(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement exit_toward_locations = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_exit_toward_locations(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement exit_names = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_exit_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement guide_onto_streets = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_guide_onto_streets(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement guide_toward_locations = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_guide_toward_locations(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<50>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement junction_names = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_junction_names(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement guidance_view_junctions = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_guidance_view_junctions(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<66>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .valhalla.TripSignElement guidance_view_signboards = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_guidance_view_signboards(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<74>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
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

::PROTOBUF_NAMESPACE_ID::uint8* TripSign::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:valhalla.TripSign)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .valhalla.TripSignElement exit_numbers = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_exit_numbers_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_exit_numbers(i), target, stream);
  }

  // repeated .valhalla.TripSignElement exit_onto_streets = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_exit_onto_streets_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_exit_onto_streets(i), target, stream);
  }

  // repeated .valhalla.TripSignElement exit_toward_locations = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_exit_toward_locations_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_exit_toward_locations(i), target, stream);
  }

  // repeated .valhalla.TripSignElement exit_names = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_exit_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_exit_names(i), target, stream);
  }

  // repeated .valhalla.TripSignElement guide_onto_streets = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_guide_onto_streets_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, this->_internal_guide_onto_streets(i), target, stream);
  }

  // repeated .valhalla.TripSignElement guide_toward_locations = 6;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_guide_toward_locations_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(6, this->_internal_guide_toward_locations(i), target, stream);
  }

  // repeated .valhalla.TripSignElement junction_names = 7;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_junction_names_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(7, this->_internal_junction_names(i), target, stream);
  }

  // repeated .valhalla.TripSignElement guidance_view_junctions = 8;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_guidance_view_junctions_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(8, this->_internal_guidance_view_junctions(i), target, stream);
  }

  // repeated .valhalla.TripSignElement guidance_view_signboards = 9;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_guidance_view_signboards_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(9, this->_internal_guidance_view_signboards(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:valhalla.TripSign)
  return target;
}

size_t TripSign::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:valhalla.TripSign)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .valhalla.TripSignElement exit_numbers = 1;
  total_size += 1UL * this->_internal_exit_numbers_size();
  for (const auto& msg : this->exit_numbers_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement exit_onto_streets = 2;
  total_size += 1UL * this->_internal_exit_onto_streets_size();
  for (const auto& msg : this->exit_onto_streets_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement exit_toward_locations = 3;
  total_size += 1UL * this->_internal_exit_toward_locations_size();
  for (const auto& msg : this->exit_toward_locations_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement exit_names = 4;
  total_size += 1UL * this->_internal_exit_names_size();
  for (const auto& msg : this->exit_names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement guide_onto_streets = 5;
  total_size += 1UL * this->_internal_guide_onto_streets_size();
  for (const auto& msg : this->guide_onto_streets_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement guide_toward_locations = 6;
  total_size += 1UL * this->_internal_guide_toward_locations_size();
  for (const auto& msg : this->guide_toward_locations_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement junction_names = 7;
  total_size += 1UL * this->_internal_junction_names_size();
  for (const auto& msg : this->junction_names_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement guidance_view_junctions = 8;
  total_size += 1UL * this->_internal_guidance_view_junctions_size();
  for (const auto& msg : this->guidance_view_junctions_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // repeated .valhalla.TripSignElement guidance_view_signboards = 9;
  total_size += 1UL * this->_internal_guidance_view_signboards_size();
  for (const auto& msg : this->guidance_view_signboards_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TripSign::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const TripSign*>(
      &from));
}

void TripSign::MergeFrom(const TripSign& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:valhalla.TripSign)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  exit_numbers_.MergeFrom(from.exit_numbers_);
  exit_onto_streets_.MergeFrom(from.exit_onto_streets_);
  exit_toward_locations_.MergeFrom(from.exit_toward_locations_);
  exit_names_.MergeFrom(from.exit_names_);
  guide_onto_streets_.MergeFrom(from.guide_onto_streets_);
  guide_toward_locations_.MergeFrom(from.guide_toward_locations_);
  junction_names_.MergeFrom(from.junction_names_);
  guidance_view_junctions_.MergeFrom(from.guidance_view_junctions_);
  guidance_view_signboards_.MergeFrom(from.guidance_view_signboards_);
}

void TripSign::CopyFrom(const TripSign& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:valhalla.TripSign)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TripSign::IsInitialized() const {
  return true;
}

void TripSign::InternalSwap(TripSign* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  exit_numbers_.InternalSwap(&other->exit_numbers_);
  exit_onto_streets_.InternalSwap(&other->exit_onto_streets_);
  exit_toward_locations_.InternalSwap(&other->exit_toward_locations_);
  exit_names_.InternalSwap(&other->exit_names_);
  guide_onto_streets_.InternalSwap(&other->guide_onto_streets_);
  guide_toward_locations_.InternalSwap(&other->guide_toward_locations_);
  junction_names_.InternalSwap(&other->junction_names_);
  guidance_view_junctions_.InternalSwap(&other->guidance_view_junctions_);
  guidance_view_signboards_.InternalSwap(&other->guidance_view_signboards_);
}

std::string TripSign::GetTypeName() const {
  return "valhalla.TripSign";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace valhalla
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::valhalla::TripSignElement* Arena::CreateMaybeMessage< ::valhalla::TripSignElement >(Arena* arena) {
  return Arena::CreateMessageInternal< ::valhalla::TripSignElement >(arena);
}
template<> PROTOBUF_NOINLINE ::valhalla::TripSign* Arena::CreateMaybeMessage< ::valhalla::TripSign >(Arena* arena) {
  return Arena::CreateMessageInternal< ::valhalla::TripSign >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>