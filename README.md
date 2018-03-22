# hub readme # {#hub_readme}

## describe
   The target of project support this attribute:
   - Optimization: none.
   - Muti-platform: unix, windows.
   - Muti-thread: safe and utility.
   - Network-mode: server and client mode.
   - Muti-language: c/cxx, java.
   - Database System: none.
   - Raster: GeoTif, Asc, Landscape.
   - Vector: ESRI Shape, Tab, Sqlite, Excel.

   In the next version v0.0.2, it will support:
   - Ai: Add ai library.
   - quantized-mesh-1.0: The format support for cesium, you could easily
   build the dem to this format.

## dependency
   The dependency of hub.

   - prj: The default projecment, you could pull it down from the github.
   - cmake: The cmake projecment.
   - autotools: The autotools projecment.
   - gnulibc: The default library.
   - gdal: The optoins library.
   - curl: The options library.
   - plplot: The options library.

## project management

### prj
    The "prj" is the default project management, the configure file is in directory of "opt".

    - configure:
        + build: src/opt/opt_base.lst, the "BUILD_DIR" is the attribute for the
        build directory.
        + install: src/opt/opt_base.lst, the "INSTALL_DIR" is the attribute for
        the install directory.
        + cross compile: src/opt/opt_base.lst, the "TARGET_OS" is the target os
        which you specified.

    - compile: 
    Compile this project, command is "make -C hub compile".

    - install: 
    Compile and install this project, command is "make -C hub".

    - document:
    Generate this project, command is "make -C hub doc".
    
### cmake
    Now is not support cmake.

### autotools
    Now is not support cmake.
