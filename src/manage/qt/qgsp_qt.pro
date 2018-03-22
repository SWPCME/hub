TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    ../hub \
    ../hub/core \
    ../hub/core/cls \
    ../hub/core/ccs \
    ../hub/core/sys \
    ../hub/core/ogr \
    ../hub/wrap \
    ../hub/wrap/ust \
    ../hub/wrap/vtr \
    ../bsn \
    ../ui \
    ../../include/gdal

LIBS += \
    ../../output/gdal.dll

SOURCES += \
    ../main.cpp \
    ../bsn/bsn_ctl.cpp \
    ../bsn/bsn_uniqueid.cpp \
    ../hub/core/ccs/ccs_ctl.cpp \
    ../hub/core/ccs/ccs_typectl.cpp \
    ../hub/core/cls/cls_ctl.cpp \
    ../hub/core/cls/cls_ioctl.cpp \
    ../hub/core/cls/cls_memoryctl.cpp \
    ../hub/core/cls/cls_stringctl.cpp \
    ../hub/core/cls/cls_unictl.cpp \
    ../hub/core/ogr/ogr_ctl.cpp \
    ../hub/core/ogr/ogr_datasrcctl.cpp \
    ../hub/core/ogr/ogr_featurectl.cpp \
    ../hub/core/ogr/ogr_featuredefnctl.cpp \
    ../hub/core/ogr/ogr_featuresctl.cpp \
    ../hub/core/ogr/ogr_fieldctl.cpp \
    ../hub/core/ogr/ogr_fielddefnctl.cpp \
    ../hub/core/ogr/ogr_geometryctl.cpp \
    ../hub/core/ogr/ogr_geomfielddefnctl.cpp \
    ../hub/core/ogr/ogr_layerctl.cpp \
    ../hub/core/sys/sys_ctl.cpp \
    ../hub/core/sys/sys_filectl.cpp \
    ../hub/core/sys/sys_filetreectl.cpp \
    ../hub/core/sys/sys_filetwctl.cpp \
    ../hub/core/sys/sys_processctl.cpp \
    ../hub/core/sys/sys_threadattrctl.cpp \
    ../hub/core/sys/sys_threadctl.cpp \
    ../hub/core/core_ctl.cpp \
    ../hub/wrap/ust/ust_ctl.cpp \
    ../hub/wrap/ust/ust_filesctl.cpp \
    ../hub/wrap/ust/ust_filestype.cpp \
    ../hub/wrap/ust/ust_stringctl.cpp \
    ../hub/wrap/ust/ust_stringtype.cpp \
    ../hub/wrap/vtr/vtr_ctl.cpp \
    ../hub/wrap/vtr/vtr_datasrcctl.cpp \
    ../hub/wrap/vtr/vtr_layerbase.cpp \
    ../hub/wrap/vtr/vtr_layerctl.cpp \
    ../hub/wrap/vtr/vtr_layerread.cpp \
    ../hub/wrap/vtr/vtr_layerwrite.cpp \
    ../hub/wrap/wrap_ctl.cpp \
    ../hub/hub_ctl.cpp \
    ../hub/hub_modulectl.cpp \
    ../ui/ui_ctl.cpp

HEADERS += \
    ../main.hpp \
    ../bsn/bsn_base.hpp \
    ../bsn/bsn_ctl.hpp \
    ../bsn/bsn_uniqueid.hpp \
    ../hub/core/ccs/ccs_base.h \
    ../hub/core/ccs/ccs_ctl.hpp \
    ../hub/core/ccs/ccs_listctl.hpp \
    ../hub/core/ccs/ccs_listctl_cpp.hpp \
    ../hub/core/ccs/ccs_mapctl.hpp \
    ../hub/core/ccs/ccs_mapctl_cpp.hpp \
    ../hub/core/ccs/ccs_typectl.hpp \
    ../hub/core/cls/cls_argctl.hpp \
    ../hub/core/cls/cls_base.h \
    ../hub/core/cls/cls_ctl.hpp \
    ../hub/core/cls/cls_ioctl.hpp \
    ../hub/core/cls/cls_memoryctl.hpp \
    ../hub/core/cls/cls_stringctl.hpp \
    ../hub/core/cls/cls_unictl.hpp \
    ../hub/core/ogr/ogr_base.h \
    ../hub/core/ogr/ogr_ctl.hpp \
    ../hub/core/ogr/ogr_datasrcctl.hpp \
    ../hub/core/ogr/ogr_featurectl.hpp \
    ../hub/core/ogr/ogr_featuredefnctl.hpp \
    ../hub/core/ogr/ogr_featuresctl.hpp \
    ../hub/core/ogr/ogr_fieldctl.hpp \
    ../hub/core/ogr/ogr_fielddefnctl.hpp \
    ../hub/core/ogr/ogr_geometryctl.hpp \
    ../hub/core/ogr/ogr_geomfielddefnctl.hpp \
    ../hub/core/ogr/ogr_layerctl.hpp \
    ../hub/core/sys/sys_base.h \
    ../hub/core/sys/sys_ctl.hpp \
    ../hub/core/sys/sys_filebase.h \
    ../hub/core/sys/sys_filectl.hpp \
    ../hub/core/sys/sys_filetreectl.hpp \
    ../hub/core/sys/sys_filetwctl.hpp \
    ../hub/core/sys/sys_processbase.hpp \
    ../hub/core/sys/sys_processctl.hpp \
    ../hub/core/sys/sys_threadattrctl.hpp \
    ../hub/core/sys/sys_threadctl.hpp \
    ../hub/core/core_base.h \
    ../hub/core/core_ctl.hpp \
    ../hub/wrap/ust/ust_base.h \
    ../hub/wrap/ust/ust_containerbase.h \
    ../hub/wrap/ust/ust_containerctl.hpp \
    ../hub/wrap/ust/ust_containerctl_cpp.hpp \
    ../hub/wrap/ust/ust_containertype.hpp \
    ../hub/wrap/ust/ust_containertype_cpp.hpp \
    ../hub/wrap/ust/ust_ctl.hpp \
    ../hub/wrap/ust/ust_filesbase.h \
    ../hub/wrap/ust/ust_filesctl.hpp \
    ../hub/wrap/ust/ust_filestype.hpp \
    ../hub/wrap/ust/ust_stringbase.h \
    ../hub/wrap/ust/ust_stringctl.hpp \
    ../hub/wrap/ust/ust_stringtype.hpp \
    ../hub/wrap/vtr/vtr_base.h \
    ../hub/wrap/vtr/vtr_ctl.hpp \
    ../hub/wrap/vtr/vtr_datasrcctl.hpp \
    ../hub/wrap/vtr/vtr_geometryctl.h \
    ../hub/wrap/vtr/vtr_layerbase.hpp \
    ../hub/wrap/vtr/vtr_layerctl.hpp \
    ../hub/wrap/vtr/vtr_layerread.hpp \
    ../hub/wrap/vtr/vtr_layerwrite.hpp \
    ../hub/wrap/wrap_base.h \
    ../hub/wrap/wrap_ctl.hpp \
    ../hub/hub_base.h \
    ../hub/hub_ctl.hpp \
    ../hub/hub_modulectl.hpp \
    ../ui/ui_base.hpp \
    ../ui/ui_ctl.hpp
