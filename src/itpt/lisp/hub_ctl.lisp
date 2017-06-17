;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; $Id: hub_ctl.cpp 2016-08 $
;
; Project:  Hub.
; Purpose:  Hub ctl.
; Author:   Weiwei Huang, 898687324@qq.com
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Copyright (c) 2016 ~ 2017 Weiwei Huang
;
; This program is free software; you can redistribute it and/or modify it 
; under the terms of the GNU General Public License as published by the Free 
; Software Foundation, either version 3 of the License, or (at your option) 
; any later version.
;
; This program is distributed in the hope that it will be useful, but WITHOUT 
; ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
; FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
; more details.
;
; You should have received a copy of the GNU General Public License along 
; with this program.  If not, see <http://www.gnu.org/licenses/>.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Hub Control.
(defclass HubCtl ()
  ((Module :accessor Module)
   )
  )

;; Hub Module.
(defmethod Module ((object HubCtl))
  (write-line "Module!")
  )

;; Set Value.
(defun Test()
  (defvar hubCtl (make-instance 'HubCtl))
  (Module hubctl)
  )

;; Display value.
(Test)
(Module hubCtl)
;; (format t "Module of HubCtl: ~s~%" (Module hubCtl))
