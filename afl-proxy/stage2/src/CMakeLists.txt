project(apstage2)

if (${LLVM_PACKAGE_VERSION} VERSION_LESS "8.0")
    add_llvm_loadable_module( libapstage2
        apstage2.cpp

        DEPENDS
        PLUGIN_TOOL
        opt
        )
elseif( ${LLVM_PACKAGE_VERSION} VERSION_LESS "14.0" )
    add_llvm_library( libapstage2 MODULE
        apstage2.cpp

        DEPENDS
        PLUGIN_TOOL
        opt
        )
else()
    add_llvm_pass_plugin(libapstage2 apstage2.cpp)
endif()

target_compile_features(libapstage2 PRIVATE cxx_range_for cxx_auto_type)

if ( CMAKE_SYSTEM_NAME MATCHES "Darwin")
    llvm_map_components_to_libnames(llvm_libs bitwriter
        core ipo irreader instcombine instrumentation target linker analysis
        scalaropts support )
    target_link_libraries( libapstage2 ${llvm_libs})
else()
    target_link_libraries( libapstage2 )
endif()

