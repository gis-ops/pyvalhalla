// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: api.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "api.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)

namespace valhalla {

void protobuf_ShutdownFile_api_2eproto() {
  delete Api::default_instance_;
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
void protobuf_AddDesc_api_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#else
void protobuf_AddDesc_api_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_api_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#endif
  ::valhalla::protobuf_AddDesc_options_2eproto();
  ::valhalla::protobuf_AddDesc_trip_2eproto();
  ::valhalla::protobuf_AddDesc_directions_2eproto();
  ::valhalla::protobuf_AddDesc_info_2eproto();
  ::valhalla::protobuf_AddDesc_status_2eproto();
  Api::default_instance_ = new Api();
  Api::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_api_2eproto);
}

#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_api_2eproto_once_);
void protobuf_AddDesc_api_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_api_2eproto_once_,
                 &protobuf_AddDesc_api_2eproto_impl);
}
#else
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_api_2eproto {
  StaticDescriptorInitializer_api_2eproto() {
    protobuf_AddDesc_api_2eproto();
  }
} static_descriptor_initializer_api_2eproto_;
#endif

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Api::kOptionsFieldNumber;
const int Api::kTripFieldNumber;
const int Api::kDirectionsFieldNumber;
const int Api::kStatusFieldNumber;
const int Api::kInfoFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Api::Api()
  : ::google::protobuf::MessageLite(), _arena_ptr_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:valhalla.Api)
}

void Api::InitAsDefaultInstance() {
  _is_default_instance_ = true;
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  options_ = const_cast< ::valhalla::Options*>(
      ::valhalla::Options::internal_default_instance());
#else
  options_ = const_cast< ::valhalla::Options*>(&::valhalla::Options::default_instance());
#endif
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  trip_ = const_cast< ::valhalla::Trip*>(
      ::valhalla::Trip::internal_default_instance());
#else
  trip_ = const_cast< ::valhalla::Trip*>(&::valhalla::Trip::default_instance());
#endif
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  directions_ = const_cast< ::valhalla::Directions*>(
      ::valhalla::Directions::internal_default_instance());
#else
  directions_ = const_cast< ::valhalla::Directions*>(&::valhalla::Directions::default_instance());
#endif
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  status_ = const_cast< ::valhalla::Status*>(
      ::valhalla::Status::internal_default_instance());
#else
  status_ = const_cast< ::valhalla::Status*>(&::valhalla::Status::default_instance());
#endif
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  info_ = const_cast< ::valhalla::Info*>(
      ::valhalla::Info::internal_default_instance());
#else
  info_ = const_cast< ::valhalla::Info*>(&::valhalla::Info::default_instance());
#endif
}

Api::Api(const Api& from)
  : ::google::protobuf::MessageLite(),
    _arena_ptr_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:valhalla.Api)
}

void Api::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  options_ = NULL;
  trip_ = NULL;
  directions_ = NULL;
  status_ = NULL;
  info_ = NULL;
}

Api::~Api() {
  // @@protoc_insertion_point(destructor:valhalla.Api)
  SharedDtor();
}

void Api::SharedDtor() {
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  if (this != &default_instance()) {
  #else
  if (this != default_instance_) {
  #endif
    delete options_;
    delete trip_;
    delete directions_;
    delete status_;
    delete info_;
  }
}

void Api::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Api& Api::default_instance() {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_AddDesc_api_2eproto();
#else
  if (default_instance_ == NULL) protobuf_AddDesc_api_2eproto();
#endif
  return *default_instance_;
}

Api* Api::default_instance_ = NULL;

Api* Api::New(::google::protobuf::Arena* arena) const {
  Api* n = new Api;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Api::Clear() {
// @@protoc_insertion_point(message_clear_start:valhalla.Api)
  if (GetArenaNoVirtual() == NULL && options_ != NULL) delete options_;
  options_ = NULL;
  if (GetArenaNoVirtual() == NULL && trip_ != NULL) delete trip_;
  trip_ = NULL;
  if (GetArenaNoVirtual() == NULL && directions_ != NULL) delete directions_;
  directions_ = NULL;
  if (GetArenaNoVirtual() == NULL && status_ != NULL) delete status_;
  status_ = NULL;
  if (GetArenaNoVirtual() == NULL && info_ != NULL) delete info_;
  info_ = NULL;
}

bool Api::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:valhalla.Api)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .valhalla.Options options = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_trip;
        break;
      }

      // optional .valhalla.Trip trip = 2;
      case 2: {
        if (tag == 18) {
         parse_trip:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_trip()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_directions;
        break;
      }

      // optional .valhalla.Directions directions = 3;
      case 3: {
        if (tag == 26) {
         parse_directions:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_directions()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_status;
        break;
      }

      // optional .valhalla.Status status = 4;
      case 4: {
        if (tag == 34) {
         parse_status:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_status()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(162)) goto parse_info;
        break;
      }

      // optional .valhalla.Info info = 20;
      case 20: {
        if (tag == 162) {
         parse_info:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_info()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:valhalla.Api)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:valhalla.Api)
  return false;
#undef DO_
}

void Api::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:valhalla.Api)
  // optional .valhalla.Options options = 1;
  if (this->has_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      1, *this->options_, output);
  }

  // optional .valhalla.Trip trip = 2;
  if (this->has_trip()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      2, *this->trip_, output);
  }

  // optional .valhalla.Directions directions = 3;
  if (this->has_directions()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, *this->directions_, output);
  }

  // optional .valhalla.Status status = 4;
  if (this->has_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      4, *this->status_, output);
  }

  // optional .valhalla.Info info = 20;
  if (this->has_info()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      20, *this->info_, output);
  }

  // @@protoc_insertion_point(serialize_end:valhalla.Api)
}

int Api::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:valhalla.Api)
  int total_size = 0;

  // optional .valhalla.Options options = 1;
  if (this->has_options()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->options_);
  }

  // optional .valhalla.Trip trip = 2;
  if (this->has_trip()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->trip_);
  }

  // optional .valhalla.Directions directions = 3;
  if (this->has_directions()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->directions_);
  }

  // optional .valhalla.Status status = 4;
  if (this->has_status()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->status_);
  }

  // optional .valhalla.Info info = 20;
  if (this->has_info()) {
    total_size += 2 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->info_);
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Api::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Api*>(&from));
}

void Api::MergeFrom(const Api& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:valhalla.Api)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.has_options()) {
    mutable_options()->::valhalla::Options::MergeFrom(from.options());
  }
  if (from.has_trip()) {
    mutable_trip()->::valhalla::Trip::MergeFrom(from.trip());
  }
  if (from.has_directions()) {
    mutable_directions()->::valhalla::Directions::MergeFrom(from.directions());
  }
  if (from.has_status()) {
    mutable_status()->::valhalla::Status::MergeFrom(from.status());
  }
  if (from.has_info()) {
    mutable_info()->::valhalla::Info::MergeFrom(from.info());
  }
}

void Api::CopyFrom(const Api& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:valhalla.Api)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Api::IsInitialized() const {

  return true;
}

void Api::Swap(Api* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Api::InternalSwap(Api* other) {
  std::swap(options_, other->options_);
  std::swap(trip_, other->trip_);
  std::swap(directions_, other->directions_);
  std::swap(status_, other->status_);
  std::swap(info_, other->info_);
  _unknown_fields_.Swap(&other->_unknown_fields_);
  std::swap(_cached_size_, other->_cached_size_);
}

::std::string Api::GetTypeName() const {
  return "valhalla.Api";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Api

// optional .valhalla.Options options = 1;
bool Api::has_options() const {
  return !_is_default_instance_ && options_ != NULL;
}
void Api::clear_options() {
  if (GetArenaNoVirtual() == NULL && options_ != NULL) delete options_;
  options_ = NULL;
}
const ::valhalla::Options& Api::options() const {
  // @@protoc_insertion_point(field_get:valhalla.Api.options)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return options_ != NULL ? *options_ : *default_instance().options_;
#else
  return options_ != NULL ? *options_ : *default_instance_->options_;
#endif
}
::valhalla::Options* Api::mutable_options() {
  
  if (options_ == NULL) {
    options_ = new ::valhalla::Options;
  }
  // @@protoc_insertion_point(field_mutable:valhalla.Api.options)
  return options_;
}
::valhalla::Options* Api::release_options() {
  // @@protoc_insertion_point(field_release:valhalla.Api.options)
  
  ::valhalla::Options* temp = options_;
  options_ = NULL;
  return temp;
}
void Api::set_allocated_options(::valhalla::Options* options) {
  delete options_;
  options_ = options;
  if (options) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:valhalla.Api.options)
}

// optional .valhalla.Trip trip = 2;
bool Api::has_trip() const {
  return !_is_default_instance_ && trip_ != NULL;
}
void Api::clear_trip() {
  if (GetArenaNoVirtual() == NULL && trip_ != NULL) delete trip_;
  trip_ = NULL;
}
const ::valhalla::Trip& Api::trip() const {
  // @@protoc_insertion_point(field_get:valhalla.Api.trip)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return trip_ != NULL ? *trip_ : *default_instance().trip_;
#else
  return trip_ != NULL ? *trip_ : *default_instance_->trip_;
#endif
}
::valhalla::Trip* Api::mutable_trip() {
  
  if (trip_ == NULL) {
    trip_ = new ::valhalla::Trip;
  }
  // @@protoc_insertion_point(field_mutable:valhalla.Api.trip)
  return trip_;
}
::valhalla::Trip* Api::release_trip() {
  // @@protoc_insertion_point(field_release:valhalla.Api.trip)
  
  ::valhalla::Trip* temp = trip_;
  trip_ = NULL;
  return temp;
}
void Api::set_allocated_trip(::valhalla::Trip* trip) {
  delete trip_;
  trip_ = trip;
  if (trip) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:valhalla.Api.trip)
}

// optional .valhalla.Directions directions = 3;
bool Api::has_directions() const {
  return !_is_default_instance_ && directions_ != NULL;
}
void Api::clear_directions() {
  if (GetArenaNoVirtual() == NULL && directions_ != NULL) delete directions_;
  directions_ = NULL;
}
const ::valhalla::Directions& Api::directions() const {
  // @@protoc_insertion_point(field_get:valhalla.Api.directions)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return directions_ != NULL ? *directions_ : *default_instance().directions_;
#else
  return directions_ != NULL ? *directions_ : *default_instance_->directions_;
#endif
}
::valhalla::Directions* Api::mutable_directions() {
  
  if (directions_ == NULL) {
    directions_ = new ::valhalla::Directions;
  }
  // @@protoc_insertion_point(field_mutable:valhalla.Api.directions)
  return directions_;
}
::valhalla::Directions* Api::release_directions() {
  // @@protoc_insertion_point(field_release:valhalla.Api.directions)
  
  ::valhalla::Directions* temp = directions_;
  directions_ = NULL;
  return temp;
}
void Api::set_allocated_directions(::valhalla::Directions* directions) {
  delete directions_;
  directions_ = directions;
  if (directions) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:valhalla.Api.directions)
}

// optional .valhalla.Status status = 4;
bool Api::has_status() const {
  return !_is_default_instance_ && status_ != NULL;
}
void Api::clear_status() {
  if (GetArenaNoVirtual() == NULL && status_ != NULL) delete status_;
  status_ = NULL;
}
const ::valhalla::Status& Api::status() const {
  // @@protoc_insertion_point(field_get:valhalla.Api.status)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return status_ != NULL ? *status_ : *default_instance().status_;
#else
  return status_ != NULL ? *status_ : *default_instance_->status_;
#endif
}
::valhalla::Status* Api::mutable_status() {
  
  if (status_ == NULL) {
    status_ = new ::valhalla::Status;
  }
  // @@protoc_insertion_point(field_mutable:valhalla.Api.status)
  return status_;
}
::valhalla::Status* Api::release_status() {
  // @@protoc_insertion_point(field_release:valhalla.Api.status)
  
  ::valhalla::Status* temp = status_;
  status_ = NULL;
  return temp;
}
void Api::set_allocated_status(::valhalla::Status* status) {
  delete status_;
  status_ = status;
  if (status) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:valhalla.Api.status)
}

// optional .valhalla.Info info = 20;
bool Api::has_info() const {
  return !_is_default_instance_ && info_ != NULL;
}
void Api::clear_info() {
  if (GetArenaNoVirtual() == NULL && info_ != NULL) delete info_;
  info_ = NULL;
}
const ::valhalla::Info& Api::info() const {
  // @@protoc_insertion_point(field_get:valhalla.Api.info)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return info_ != NULL ? *info_ : *default_instance().info_;
#else
  return info_ != NULL ? *info_ : *default_instance_->info_;
#endif
}
::valhalla::Info* Api::mutable_info() {
  
  if (info_ == NULL) {
    info_ = new ::valhalla::Info;
  }
  // @@protoc_insertion_point(field_mutable:valhalla.Api.info)
  return info_;
}
::valhalla::Info* Api::release_info() {
  // @@protoc_insertion_point(field_release:valhalla.Api.info)
  
  ::valhalla::Info* temp = info_;
  info_ = NULL;
  return temp;
}
void Api::set_allocated_info(::valhalla::Info* info) {
  delete info_;
  info_ = info;
  if (info) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:valhalla.Api.info)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace valhalla

// @@protoc_insertion_point(global_scope)