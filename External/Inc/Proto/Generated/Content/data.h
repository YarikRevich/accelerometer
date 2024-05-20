/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: Content/data.proto
 */

// This file is generated. Please do not edit!
#ifndef CONTENT_DATA_H
#define CONTENT_DATA_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions

namespace accelerometer {

enum class DataType : uint32_t
{
  DataNone = 0,
  Raw = 1
};

class DataBusRequestContent final: public ::EmbeddedProto::MessageInterface
{
  public:
    DataBusRequestContent() = default;
    DataBusRequestContent(const DataBusRequestContent& rhs )
    {
      set_dataType(rhs.get_dataType());
    }

    DataBusRequestContent(const DataBusRequestContent&& rhs ) noexcept
    {
      set_dataType(rhs.get_dataType());
    }

    ~DataBusRequestContent() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      DATATYPE = 1
    };

    DataBusRequestContent& operator=(const DataBusRequestContent& rhs)
    {
      set_dataType(rhs.get_dataType());
      return *this;
    }

    DataBusRequestContent& operator=(const DataBusRequestContent&& rhs) noexcept
    {
      set_dataType(rhs.get_dataType());
      return *this;
    }

    static constexpr char const* DATATYPE_NAME = "dataType";
    inline void clear_dataType() { dataType_.clear(); }
    inline void set_dataType(const DataType& value) { dataType_ = value; }
    inline void set_dataType(const DataType&& value) { dataType_ = value; }
    inline const DataType& get_dataType() const { return dataType_.get(); }
    inline DataType dataType() const { return dataType_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<DataType>(0) != dataType_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = dataType_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DATATYPE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::DATATYPE:
            return_value = dataType_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_dataType();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::DATATYPE:
          name = DATATYPE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = dataType_.to_string(left_chars, indent_level + 2, DATATYPE_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<DataType> dataType_ = static_cast<DataType>(0);

};

class RawDataTypeValue final: public ::EmbeddedProto::MessageInterface
{
  public:
    RawDataTypeValue() = default;
    RawDataTypeValue(const RawDataTypeValue& rhs )
    {
      set_x(rhs.get_x());
      set_y(rhs.get_y());
      set_z(rhs.get_z());
    }

    RawDataTypeValue(const RawDataTypeValue&& rhs ) noexcept
    {
      set_x(rhs.get_x());
      set_y(rhs.get_y());
      set_z(rhs.get_z());
    }

    ~RawDataTypeValue() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      X = 1,
      Y = 2,
      Z = 3
    };

    RawDataTypeValue& operator=(const RawDataTypeValue& rhs)
    {
      set_x(rhs.get_x());
      set_y(rhs.get_y());
      set_z(rhs.get_z());
      return *this;
    }

    RawDataTypeValue& operator=(const RawDataTypeValue&& rhs) noexcept
    {
      set_x(rhs.get_x());
      set_y(rhs.get_y());
      set_z(rhs.get_z());
      return *this;
    }

    static constexpr char const* X_NAME = "x";
    inline void clear_x() { x_.clear(); }
    inline void set_x(const int32_t& value) { x_ = value; }
    inline void set_x(const int32_t&& value) { x_ = value; }
    inline int32_t& mutable_x() { return x_.get(); }
    inline const int32_t& get_x() const { return x_.get(); }
    inline int32_t x() const { return x_.get(); }

    static constexpr char const* Y_NAME = "y";
    inline void clear_y() { y_.clear(); }
    inline void set_y(const int32_t& value) { y_ = value; }
    inline void set_y(const int32_t&& value) { y_ = value; }
    inline int32_t& mutable_y() { return y_.get(); }
    inline const int32_t& get_y() const { return y_.get(); }
    inline int32_t y() const { return y_.get(); }

    static constexpr char const* Z_NAME = "z";
    inline void clear_z() { z_.clear(); }
    inline void set_z(const int32_t& value) { z_ = value; }
    inline void set_z(const int32_t&& value) { z_ = value; }
    inline int32_t& mutable_z() { return z_.get(); }
    inline const int32_t& get_z() const { return z_.get(); }
    inline int32_t z() const { return z_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != x_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = x_.serialize_with_id(static_cast<uint32_t>(FieldNumber::X), buffer, false);
      }

      if((0 != y_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = y_.serialize_with_id(static_cast<uint32_t>(FieldNumber::Y), buffer, false);
      }

      if((0 != z_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = z_.serialize_with_id(static_cast<uint32_t>(FieldNumber::Z), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::X:
            return_value = x_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::Y:
            return_value = y_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::Z:
            return_value = z_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_x();
      clear_y();
      clear_z();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::X:
          name = X_NAME;
          break;
        case FieldNumber::Y:
          name = Y_NAME;
          break;
        case FieldNumber::Z:
          name = Z_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = x_.to_string(left_chars, indent_level + 2, X_NAME, true);
      left_chars = y_.to_string(left_chars, indent_level + 2, Y_NAME, false);
      left_chars = z_.to_string(left_chars, indent_level + 2, Z_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 x_ = 0;
      EmbeddedProto::int32 y_ = 0;
      EmbeddedProto::int32 z_ = 0;

};

class DataBusResponseContent final: public ::EmbeddedProto::MessageInterface
{
  public:
    DataBusResponseContent() = default;
    DataBusResponseContent(const DataBusResponseContent& rhs )
    {
      set_deviceId(rhs.get_deviceId());
      set_dataType(rhs.get_dataType());
      set_nonce(rhs.get_nonce());
      set_suspended(rhs.get_suspended());
      if(rhs.get_which_value() != which_value_)
      {
        // First delete the old object in the oneof.
        clear_value();
      }

      switch(rhs.get_which_value())
      {
        case FieldNumber::RAW:
          set_raw(rhs.get_raw());
          break;

        default:
          break;
      }

    }

    DataBusResponseContent(const DataBusResponseContent&& rhs ) noexcept
    {
      set_deviceId(rhs.get_deviceId());
      set_dataType(rhs.get_dataType());
      set_nonce(rhs.get_nonce());
      set_suspended(rhs.get_suspended());
      if(rhs.get_which_value() != which_value_)
      {
        // First delete the old object in the oneof.
        clear_value();
      }

      switch(rhs.get_which_value())
      {
        case FieldNumber::RAW:
          set_raw(rhs.get_raw());
          break;

        default:
          break;
      }

    }

    ~DataBusResponseContent() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      DEVICEID = 1,
      DATATYPE = 2,
      NONCE = 3,
      SUSPENDED = 4,
      RAW = 5
    };

    DataBusResponseContent& operator=(const DataBusResponseContent& rhs)
    {
      set_deviceId(rhs.get_deviceId());
      set_dataType(rhs.get_dataType());
      set_nonce(rhs.get_nonce());
      set_suspended(rhs.get_suspended());
      if(rhs.get_which_value() != which_value_)
      {
        // First delete the old object in the oneof.
        clear_value();
      }

      switch(rhs.get_which_value())
      {
        case FieldNumber::RAW:
          set_raw(rhs.get_raw());
          break;

        default:
          break;
      }

      return *this;
    }

    DataBusResponseContent& operator=(const DataBusResponseContent&& rhs) noexcept
    {
      set_deviceId(rhs.get_deviceId());
      set_dataType(rhs.get_dataType());
      set_nonce(rhs.get_nonce());
      set_suspended(rhs.get_suspended());
      if(rhs.get_which_value() != which_value_)
      {
        // First delete the old object in the oneof.
        clear_value();
      }

      switch(rhs.get_which_value())
      {
        case FieldNumber::RAW:
          set_raw(rhs.get_raw());
          break;

        default:
          break;
      }

      return *this;
    }

    static constexpr char const* DEVICEID_NAME = "deviceId";
    inline void clear_deviceId() { deviceId_.clear(); }
    inline void set_deviceId(const uint32_t& value) { deviceId_ = value; }
    inline void set_deviceId(const uint32_t&& value) { deviceId_ = value; }
    inline uint32_t& mutable_deviceId() { return deviceId_.get(); }
    inline const uint32_t& get_deviceId() const { return deviceId_.get(); }
    inline uint32_t deviceId() const { return deviceId_.get(); }

    static constexpr char const* DATATYPE_NAME = "dataType";
    inline void clear_dataType() { dataType_.clear(); }
    inline void set_dataType(const DataType& value) { dataType_ = value; }
    inline void set_dataType(const DataType&& value) { dataType_ = value; }
    inline const DataType& get_dataType() const { return dataType_.get(); }
    inline DataType dataType() const { return dataType_.get(); }

    static constexpr char const* NONCE_NAME = "nonce";
    inline void clear_nonce() { nonce_.clear(); }
    inline void set_nonce(const int32_t& value) { nonce_ = value; }
    inline void set_nonce(const int32_t&& value) { nonce_ = value; }
    inline int32_t& mutable_nonce() { return nonce_.get(); }
    inline const int32_t& get_nonce() const { return nonce_.get(); }
    inline int32_t nonce() const { return nonce_.get(); }

    static constexpr char const* SUSPENDED_NAME = "suspended";
    inline void clear_suspended() { suspended_.clear(); }
    inline void set_suspended(const int32_t& value) { suspended_ = value; }
    inline void set_suspended(const int32_t&& value) { suspended_ = value; }
    inline int32_t& mutable_suspended() { return suspended_.get(); }
    inline const int32_t& get_suspended() const { return suspended_.get(); }
    inline int32_t suspended() const { return suspended_.get(); }

    FieldNumber get_which_value() const { return which_value_; }

    static constexpr char const* RAW_NAME = "raw";
    inline bool has_raw() const
    {
      return FieldNumber::RAW == which_value_;
    }
    inline void clear_raw()
    {
      if(FieldNumber::RAW == which_value_)
      {
        which_value_ = FieldNumber::NOT_SET;
        value_.raw_.~RawDataTypeValue();
      }
    }
    inline void set_raw(const RawDataTypeValue& value)
    {
      if(FieldNumber::RAW != which_value_)
      {
        init_value(FieldNumber::RAW);
      }
      value_.raw_ = value;
    }
    inline void set_raw(const RawDataTypeValue&& value)
    {
      if(FieldNumber::RAW != which_value_)
      {
        init_value(FieldNumber::RAW);
      }
      value_.raw_ = value;
    }
    inline RawDataTypeValue& mutable_raw()
    {
      if(FieldNumber::RAW != which_value_)
      {
        init_value(FieldNumber::RAW);
      }
      return value_.raw_;
    }
    inline const RawDataTypeValue& get_raw() const { return value_.raw_; }
    inline const RawDataTypeValue& raw() const { return value_.raw_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != deviceId_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = deviceId_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DEVICEID), buffer, false);
      }

      if((static_cast<DataType>(0) != dataType_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = dataType_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DATATYPE), buffer, false);
      }

      if((0 != nonce_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = nonce_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NONCE), buffer, false);
      }

      if((0 != suspended_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = suspended_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SUSPENDED), buffer, false);
      }

      switch(which_value_)
      {
        case FieldNumber::RAW:
          if(has_raw() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = value_.raw_.serialize_with_id(static_cast<uint32_t>(FieldNumber::RAW), buffer, true);
          }
          break;

        default:
          break;
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::DEVICEID:
            return_value = deviceId_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::DATATYPE:
            return_value = dataType_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NONCE:
            return_value = nonce_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SUSPENDED:
            return_value = suspended_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::RAW:
            return_value = deserialize_value(id_tag, buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_deviceId();
      clear_dataType();
      clear_nonce();
      clear_suspended();
      clear_value();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::DEVICEID:
          name = DEVICEID_NAME;
          break;
        case FieldNumber::DATATYPE:
          name = DATATYPE_NAME;
          break;
        case FieldNumber::NONCE:
          name = NONCE_NAME;
          break;
        case FieldNumber::SUSPENDED:
          name = SUSPENDED_NAME;
          break;
        case FieldNumber::RAW:
          name = RAW_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = deviceId_.to_string(left_chars, indent_level + 2, DEVICEID_NAME, true);
      left_chars = dataType_.to_string(left_chars, indent_level + 2, DATATYPE_NAME, false);
      left_chars = nonce_.to_string(left_chars, indent_level + 2, NONCE_NAME, false);
      left_chars = suspended_.to_string(left_chars, indent_level + 2, SUSPENDED_NAME, false);
      left_chars = to_string_value(left_chars, indent_level + 2, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::uint32 deviceId_ = 0U;
      EmbeddedProto::enumeration<DataType> dataType_ = static_cast<DataType>(0);
      EmbeddedProto::int32 nonce_ = 0;
      EmbeddedProto::int32 suspended_ = 0;

      FieldNumber which_value_ = FieldNumber::NOT_SET;
      union value
      {
        value() {}
        ~value() {}
        RawDataTypeValue raw_;
      };
      value value_;

      void init_value(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_value_)
        {
          // First delete the old object in the oneof.
          clear_value();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::RAW:
            new(&value_.raw_) RawDataTypeValue;
            break;

          default:
            break;
         }

         which_value_ = field_id;
      }

      void clear_value()
      {
        switch(which_value_)
        {
          case FieldNumber::RAW:
            ::EmbeddedProto::destroy_at(&value_.raw_);
            break;
          default:
            break;
        }
        which_value_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_value(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_value_)
        {
          init_value(field_id);
        }

        switch(which_value_)
        {
          case FieldNumber::RAW:
            return_value = value_.raw_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_value();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_value(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_value_)
        {
          case FieldNumber::RAW:
            left_chars = value_.raw_.to_string(left_chars, indent_level, RAW_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

} // End of namespace accelerometer
#endif // CONTENT_DATA_H