;; Auto-generated. Do not edit!


(when (boundp 'piraterover::DriveCmd)
  (if (not (find-package "PIRATEROVER"))
    (make-package "PIRATEROVER"))
  (shadow 'DriveCmd (find-package "PIRATEROVER")))
(unless (find-package "PIRATEROVER::DRIVECMD")
  (make-package "PIRATEROVER::DRIVECMD"))

(in-package "ROS")
;;//! \htmlinclude DriveCmd.msg.html


(defclass piraterover::DriveCmd
  :super ros::object
  :slots (_Lwheel _Rwheel ))

(defmethod piraterover::DriveCmd
  (:init
   (&key
    ((:Lwheel __Lwheel) 0.0)
    ((:Rwheel __Rwheel) 0.0)
    )
   (send-super :init)
   (setq _Lwheel (float __Lwheel))
   (setq _Rwheel (float __Rwheel))
   self)
  (:Lwheel
   (&optional __Lwheel)
   (if __Lwheel (setq _Lwheel __Lwheel)) _Lwheel)
  (:Rwheel
   (&optional __Rwheel)
   (if __Rwheel (setq _Rwheel __Rwheel)) _Rwheel)
  (:serialization-length
   ()
   (+
    ;; float32 _Lwheel
    4
    ;; float32 _Rwheel
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _Lwheel
       (sys::poke _Lwheel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Rwheel
       (sys::poke _Rwheel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _Lwheel
     (setq _Lwheel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Rwheel
     (setq _Rwheel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get piraterover::DriveCmd :md5sum-) "86370d25863b5f8035b2d42b9f7b496c")
(setf (get piraterover::DriveCmd :datatype-) "piraterover/DriveCmd")
(setf (get piraterover::DriveCmd :definition-)
      "# Message format for sending drive commands to rover.

float32 Lwheel   # -100 to 100
float32 Rwheel   # -100 to 100

")



(provide :piraterover/DriveCmd "86370d25863b5f8035b2d42b9f7b496c")


