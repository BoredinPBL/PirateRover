// Generated by gencpp from file piraterover/DriveCmd.msg
// DO NOT EDIT!


#ifndef PIRATEROVER_MESSAGE_DRIVECMD_H
#define PIRATEROVER_MESSAGE_DRIVECMD_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace piraterover
{
template <class ContainerAllocator>
struct DriveCmd_
{
  typedef DriveCmd_<ContainerAllocator> Type;

  DriveCmd_()
    : Lwheel(0.0)
    , Rwheel(0.0)  {
    }
  DriveCmd_(const ContainerAllocator& _alloc)
    : Lwheel(0.0)
    , Rwheel(0.0)  {
  (void)_alloc;
    }



   typedef float _Lwheel_type;
  _Lwheel_type Lwheel;

   typedef float _Rwheel_type;
  _Rwheel_type Rwheel;





  typedef boost::shared_ptr< ::piraterover::DriveCmd_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::piraterover::DriveCmd_<ContainerAllocator> const> ConstPtr;

}; // struct DriveCmd_

typedef ::piraterover::DriveCmd_<std::allocator<void> > DriveCmd;

typedef boost::shared_ptr< ::piraterover::DriveCmd > DriveCmdPtr;
typedef boost::shared_ptr< ::piraterover::DriveCmd const> DriveCmdConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::piraterover::DriveCmd_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::piraterover::DriveCmd_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace piraterover

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'piraterover': ['/home/pirate/GitKracked/ws_FinalPirateRover/src/piraterover/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::piraterover::DriveCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::piraterover::DriveCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::piraterover::DriveCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::piraterover::DriveCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::piraterover::DriveCmd_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::piraterover::DriveCmd_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::piraterover::DriveCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "86370d25863b5f8035b2d42b9f7b496c";
  }

  static const char* value(const ::piraterover::DriveCmd_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x86370d25863b5f80ULL;
  static const uint64_t static_value2 = 0x35b2d42b9f7b496cULL;
};

template<class ContainerAllocator>
struct DataType< ::piraterover::DriveCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "piraterover/DriveCmd";
  }

  static const char* value(const ::piraterover::DriveCmd_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::piraterover::DriveCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Message format for sending drive commands to rover.\n\
\n\
float32 Lwheel   # -100 to 100\n\
float32 Rwheel   # -100 to 100\n\
";
  }

  static const char* value(const ::piraterover::DriveCmd_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::piraterover::DriveCmd_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Lwheel);
      stream.next(m.Rwheel);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DriveCmd_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::piraterover::DriveCmd_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::piraterover::DriveCmd_<ContainerAllocator>& v)
  {
    s << indent << "Lwheel: ";
    Printer<float>::stream(s, indent + "  ", v.Lwheel);
    s << indent << "Rwheel: ";
    Printer<float>::stream(s, indent + "  ", v.Rwheel);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PIRATEROVER_MESSAGE_DRIVECMD_H
