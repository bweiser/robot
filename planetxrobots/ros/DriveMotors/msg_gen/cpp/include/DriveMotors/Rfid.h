/* Auto-generated by genmsg_cpp for file /opt/projects/adler/planetxrobots/ros/DriveMotors/msg/Rfid.msg */
#ifndef DRIVEMOTORS_MESSAGE_RFID_H
#define DRIVEMOTORS_MESSAGE_RFID_H
#include <string>
#include <vector>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/message.h"
#include "ros/time.h"

#include "std_msgs/Header.h"

namespace DriveMotors
{
template <class ContainerAllocator>
struct Rfid_ : public ros::Message
{
  typedef Rfid_<ContainerAllocator> Type;

  Rfid_()
  : header()
  , rfidTag()
  {
  }

  Rfid_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , rfidTag(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _rfidTag_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  rfidTag;


private:
  static const char* __s_getDataType_() { return "DriveMotors/Rfid"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "e2a6fe4bc703b89049bf2e73727c10e3"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "#\n\
# the tag ID number for an RFID tag\n\
#\n\
Header header\n\
string rfidTag\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, header);
    ros::serialization::serialize(stream, rfidTag);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, header);
    ros::serialization::deserialize(stream, rfidTag);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(header);
    size += ros::serialization::serializationLength(rfidTag);
    return size;
  }

  typedef boost::shared_ptr< ::DriveMotors::Rfid_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::DriveMotors::Rfid_<ContainerAllocator>  const> ConstPtr;
}; // struct Rfid
typedef  ::DriveMotors::Rfid_<std::allocator<void> > Rfid;

typedef boost::shared_ptr< ::DriveMotors::Rfid> RfidPtr;
typedef boost::shared_ptr< ::DriveMotors::Rfid const> RfidConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::DriveMotors::Rfid_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::DriveMotors::Rfid_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace DriveMotors

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator>
struct MD5Sum< ::DriveMotors::Rfid_<ContainerAllocator> > {
  static const char* value() 
  {
    return "e2a6fe4bc703b89049bf2e73727c10e3";
  }

  static const char* value(const  ::DriveMotors::Rfid_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xe2a6fe4bc703b890ULL;
  static const uint64_t static_value2 = 0x49bf2e73727c10e3ULL;
};

template<class ContainerAllocator>
struct DataType< ::DriveMotors::Rfid_<ContainerAllocator> > {
  static const char* value() 
  {
    return "DriveMotors/Rfid";
  }

  static const char* value(const  ::DriveMotors::Rfid_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::DriveMotors::Rfid_<ContainerAllocator> > {
  static const char* value() 
  {
    return "#\n\
# the tag ID number for an RFID tag\n\
#\n\
Header header\n\
string rfidTag\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::DriveMotors::Rfid_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::DriveMotors::Rfid_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::DriveMotors::Rfid_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::DriveMotors::Rfid_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.rfidTag);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Rfid_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::DriveMotors::Rfid_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::DriveMotors::Rfid_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "rfidTag: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.rfidTag);
  }
};


} // namespace message_operations
} // namespace ros

#endif // DRIVEMOTORS_MESSAGE_RFID_H

