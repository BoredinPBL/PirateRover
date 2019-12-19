// Auto-generated. Do not edit!

// (in-package piraterover.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class DriveCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Lwheel = null;
      this.Rwheel = null;
    }
    else {
      if (initObj.hasOwnProperty('Lwheel')) {
        this.Lwheel = initObj.Lwheel
      }
      else {
        this.Lwheel = 0.0;
      }
      if (initObj.hasOwnProperty('Rwheel')) {
        this.Rwheel = initObj.Rwheel
      }
      else {
        this.Rwheel = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DriveCmd
    // Serialize message field [Lwheel]
    bufferOffset = _serializer.float32(obj.Lwheel, buffer, bufferOffset);
    // Serialize message field [Rwheel]
    bufferOffset = _serializer.float32(obj.Rwheel, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DriveCmd
    let len;
    let data = new DriveCmd(null);
    // Deserialize message field [Lwheel]
    data.Lwheel = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Rwheel]
    data.Rwheel = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'piraterover/DriveCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '86370d25863b5f8035b2d42b9f7b496c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Message format for sending drive commands to rover.
    
    float32 Lwheel   # -100 to 100
    float32 Rwheel   # -100 to 100
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DriveCmd(null);
    if (msg.Lwheel !== undefined) {
      resolved.Lwheel = msg.Lwheel;
    }
    else {
      resolved.Lwheel = 0.0
    }

    if (msg.Rwheel !== undefined) {
      resolved.Rwheel = msg.Rwheel;
    }
    else {
      resolved.Rwheel = 0.0
    }

    return resolved;
    }
};

module.exports = DriveCmd;
