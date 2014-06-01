// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: request.taskinfo.proto

#ifndef PROTOBUF_request_2etaskinfo_2eproto__INCLUDED
#define PROTOBUF_request_2etaskinfo_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace hpgc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_request_2etaskinfo_2eproto();
void protobuf_AssignDesc_request_2etaskinfo_2eproto();
void protobuf_ShutdownFile_request_2etaskinfo_2eproto();

class TaskInfo;

enum TaskType {
  OK = 0,
  WRONG = 1
};
bool TaskType_IsValid(int value);
const TaskType TaskType_MIN = OK;
const TaskType TaskType_MAX = WRONG;
const int TaskType_ARRAYSIZE = TaskType_MAX + 1;

const ::google::protobuf::EnumDescriptor* TaskType_descriptor();
inline const ::std::string& TaskType_Name(TaskType value) {
  return ::google::protobuf::internal::NameOfEnum(
    TaskType_descriptor(), value);
}
inline bool TaskType_Parse(
    const ::std::string& name, TaskType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TaskType>(
    TaskType_descriptor(), name, value);
}
// ===================================================================

class TaskInfo : public ::google::protobuf::Message {
 public:
  TaskInfo();
  virtual ~TaskInfo();

  TaskInfo(const TaskInfo& from);

  inline TaskInfo& operator=(const TaskInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TaskInfo& default_instance();

  void Swap(TaskInfo* other);

  // implements Message ----------------------------------------------

  TaskInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TaskInfo& from);
  void MergeFrom(const TaskInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .hpgc.TaskType Type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::hpgc::TaskType type() const;
  inline void set_type(::hpgc::TaskType value);

  // required int32 DataIndex = 2;
  inline bool has_dataindex() const;
  inline void clear_dataindex();
  static const int kDataIndexFieldNumber = 2;
  inline ::google::protobuf::int32 dataindex() const;
  inline void set_dataindex(::google::protobuf::int32 value);

  // required double StartTime = 3;
  inline bool has_starttime() const;
  inline void clear_starttime();
  static const int kStartTimeFieldNumber = 3;
  inline double starttime() const;
  inline void set_starttime(double value);

  // required double EndTime = 4;
  inline bool has_endtime() const;
  inline void clear_endtime();
  static const int kEndTimeFieldNumber = 4;
  inline double endtime() const;
  inline void set_endtime(double value);

  // @@protoc_insertion_point(class_scope:hpgc.TaskInfo)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_dataindex();
  inline void clear_has_dataindex();
  inline void set_has_starttime();
  inline void clear_has_starttime();
  inline void set_has_endtime();
  inline void clear_has_endtime();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  int type_;
  ::google::protobuf::int32 dataindex_;
  double starttime_;
  double endtime_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_request_2etaskinfo_2eproto();
  friend void protobuf_AssignDesc_request_2etaskinfo_2eproto();
  friend void protobuf_ShutdownFile_request_2etaskinfo_2eproto();

  void InitAsDefaultInstance();
  static TaskInfo* default_instance_;
};
// ===================================================================


// ===================================================================

// TaskInfo

// required .hpgc.TaskType Type = 1;
inline bool TaskInfo::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TaskInfo::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TaskInfo::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TaskInfo::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::hpgc::TaskType TaskInfo::type() const {
  return static_cast< ::hpgc::TaskType >(type_);
}
inline void TaskInfo::set_type(::hpgc::TaskType value) {
  assert(::hpgc::TaskType_IsValid(value));
  set_has_type();
  type_ = value;
}

// required int32 DataIndex = 2;
inline bool TaskInfo::has_dataindex() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TaskInfo::set_has_dataindex() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TaskInfo::clear_has_dataindex() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TaskInfo::clear_dataindex() {
  dataindex_ = 0;
  clear_has_dataindex();
}
inline ::google::protobuf::int32 TaskInfo::dataindex() const {
  return dataindex_;
}
inline void TaskInfo::set_dataindex(::google::protobuf::int32 value) {
  set_has_dataindex();
  dataindex_ = value;
}

// required double StartTime = 3;
inline bool TaskInfo::has_starttime() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TaskInfo::set_has_starttime() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TaskInfo::clear_has_starttime() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void TaskInfo::clear_starttime() {
  starttime_ = 0;
  clear_has_starttime();
}
inline double TaskInfo::starttime() const {
  return starttime_;
}
inline void TaskInfo::set_starttime(double value) {
  set_has_starttime();
  starttime_ = value;
}

// required double EndTime = 4;
inline bool TaskInfo::has_endtime() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void TaskInfo::set_has_endtime() {
  _has_bits_[0] |= 0x00000008u;
}
inline void TaskInfo::clear_has_endtime() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void TaskInfo::clear_endtime() {
  endtime_ = 0;
  clear_has_endtime();
}
inline double TaskInfo::endtime() const {
  return endtime_;
}
inline void TaskInfo::set_endtime(double value) {
  set_has_endtime();
  endtime_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace hpgc

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::hpgc::TaskType>() {
  return ::hpgc::TaskType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_request_2etaskinfo_2eproto__INCLUDED