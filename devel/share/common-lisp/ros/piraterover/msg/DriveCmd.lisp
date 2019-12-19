; Auto-generated. Do not edit!


(cl:in-package piraterover-msg)


;//! \htmlinclude DriveCmd.msg.html

(cl:defclass <DriveCmd> (roslisp-msg-protocol:ros-message)
  ((Lwheel
    :reader Lwheel
    :initarg :Lwheel
    :type cl:float
    :initform 0.0)
   (Rwheel
    :reader Rwheel
    :initarg :Rwheel
    :type cl:float
    :initform 0.0))
)

(cl:defclass DriveCmd (<DriveCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DriveCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DriveCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name piraterover-msg:<DriveCmd> is deprecated: use piraterover-msg:DriveCmd instead.")))

(cl:ensure-generic-function 'Lwheel-val :lambda-list '(m))
(cl:defmethod Lwheel-val ((m <DriveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piraterover-msg:Lwheel-val is deprecated.  Use piraterover-msg:Lwheel instead.")
  (Lwheel m))

(cl:ensure-generic-function 'Rwheel-val :lambda-list '(m))
(cl:defmethod Rwheel-val ((m <DriveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader piraterover-msg:Rwheel-val is deprecated.  Use piraterover-msg:Rwheel instead.")
  (Rwheel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DriveCmd>) ostream)
  "Serializes a message object of type '<DriveCmd>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Lwheel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Rwheel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DriveCmd>) istream)
  "Deserializes a message object of type '<DriveCmd>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Lwheel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Rwheel) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DriveCmd>)))
  "Returns string type for a message object of type '<DriveCmd>"
  "piraterover/DriveCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DriveCmd)))
  "Returns string type for a message object of type 'DriveCmd"
  "piraterover/DriveCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DriveCmd>)))
  "Returns md5sum for a message object of type '<DriveCmd>"
  "86370d25863b5f8035b2d42b9f7b496c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DriveCmd)))
  "Returns md5sum for a message object of type 'DriveCmd"
  "86370d25863b5f8035b2d42b9f7b496c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DriveCmd>)))
  "Returns full string definition for message of type '<DriveCmd>"
  (cl:format cl:nil "# Message format for sending drive commands to rover.~%~%float32 Lwheel   # -100 to 100~%float32 Rwheel   # -100 to 100~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DriveCmd)))
  "Returns full string definition for message of type 'DriveCmd"
  (cl:format cl:nil "# Message format for sending drive commands to rover.~%~%float32 Lwheel   # -100 to 100~%float32 Rwheel   # -100 to 100~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DriveCmd>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DriveCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'DriveCmd
    (cl:cons ':Lwheel (Lwheel msg))
    (cl:cons ':Rwheel (Rwheel msg))
))
