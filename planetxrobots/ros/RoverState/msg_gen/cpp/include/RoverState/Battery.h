/* Auto-generated by genmsg_cpp for file /opt/planetxrobots/ros/RoverState/msg/Battery.msg */
#ifndef ROVERSTATE_MESSAGE_BATTERY_H
#define ROVERSTATE_MESSAGE_BATTERY_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace RoverState
{
template <class ContainerAllocator>
struct Battery_ {
  typedef Battery_<ContainerAllocator> Type;

  Battery_()
  : header()
  , batteryVoltagePercentage(0)
  , depleted(false)
  {
  }

  Battery_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , batteryVoltagePercentage(0)
  , depleted(false)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _batteryVoltagePercentage_type;
  uint8_t batteryVoltagePercentage;

  typedef uint8_t _depleted_type;
  uint8_t depleted;


  typedef boost::shared_ptr< ::RoverState::Battery_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::RoverState::Battery_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Battery
typedef  ::RoverState::Battery_<std::allocator<void> > Battery;

typedef boost::shared_ptr< ::RoverState::Battery> BatteryPtr;
typedef boost::shared_ptr< ::RoverState::Battery const> BatteryConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::RoverState::Battery_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::RoverState::Battery_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace RoverState

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::RoverState::Battery_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::RoverState::Battery_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::RoverState::Battery_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a52748706e7d98341080d239099bf112";
  }

  static const char* value(const  ::RoverState::Battery_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa52748706e7d9834ULL;
  static const uint64_t static_value2 = 0x1080d239099bf112ULL;
};

template<class ContainerAllocator>
struct DataType< ::RoverState::Battery_<ContainerAllocator> > {
  static const char* value() 
  {
    return "RoverState/Battery";
  }

  static const char* value(const  ::RoverState::Battery_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::RoverState::Battery_<ContainerAllocator> > {
  static const char* value() 
  {
    return "#\n\
# the state of the battery\n\
#\n\
Header header\n\
uint8 batteryVoltagePercentage\n\
bool depleted\n\
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

  static const char* value(const  ::RoverState::Battery_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::RoverState::Battery_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::RoverState::Battery_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::RoverState::Battery_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.batteryVoltagePercentage);
    stream.next(m.depleted);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Battery_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::RoverState::Battery_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::RoverState::Battery_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "batteryVoltagePercentage: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.batteryVoltagePercentage);
    s << indent << "depleted: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.depleted);
  }
};


} // namespace message_operations
} // namespace ros

#endif // ROVERSTATE_MESSAGE_BATTERY_H
