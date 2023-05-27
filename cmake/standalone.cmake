
project(rootana)

file(GLOB rootana_headers rootana/*.h)
file(GLOB rootana_sources rootana/*.cxx)
list(FILTER rootana_headers EXCLUDE REGEX ".*rootana/LinkDef\.h$")
list(FILTER rootana_headers EXCLUDE REGEX ".*rootana/Event\.h$")
list(FILTER rootana_sources EXCLUDE REGEX ".*rootana/Event\.cxx$")
#message(${rootana_sources})

add_library( rootana SHARED ${rootana_sources} ${rootana_headers})

target_include_directories(rootana PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../ana/include)

target_compile_features(rootana PRIVATE cxx_std_17)

find_package( ROOT REQUIRED COMPONENTS Core Imt RIO Net Hist Graf Graf3d Gpad ROOTVecOps Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread MultiProc ROOTDataFrame )
find_library(ROOT_TREEPLAYER_LIBRARY TreePlayer HINTS ${ROOT_LIBRARY_DIR} REQUIRED)
find_library(ROOT_RDATAFRAME_LIBRARY ROOTDataFrame HINTS ${ROOT_LIBRARY_DIR} REQUIRED)
target_link_libraries(rootana ana ROOT::Core ROOT::RIO ROOT::Hist ROOT::Tree ROOT::TreePlayer ROOT::Imt ROOT::ROOTVecOps ROOT::ROOTDataFrame ROOT::Physics)

ROOT_GENERATE_DICTIONARY(
  rootana_dict ${rootana_headers}
  LINKDEF rootana/LinkDef.h
  MODULE rootana
)

export(PACKAGE rootana)
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/rootana" )
set(CONF_LIBRARY_DIRS "${PROJECT_BINARY_DIR}")
set(CONF_LIBRARIES    rootana)
configure_file(config.cmake.in
  "${PROJECT_BINARY_DIR}/config.cmake" @ONLY)

set(ROOTANA_PYTHONPATH ${CMAKE_CURRENT_BINARY_DIR})
set(ROOTANA_LD_LIBRARY_PATH ${CMAKE_CURRENT_BINARY_DIR})

install(DIRECTORY
  "${CMAKE_CURRENT_BINARY_DIR}/rootana"
  EXPORT rootanaConfig
  DESTINATION lib
  )

set(SETUP ${CMAKE_CURRENT_BINARY_DIR}/setup.sh)
file(WRITE ${SETUP} "#!/bin/bash\n")
file(APPEND ${SETUP} "ulimit -S -s unlimited\n" )
file(APPEND ${SETUP} "export LD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${ROOTANA_LD_LIBRARY_PATH}\n")
file(APPEND ${SETUP} "export DYLD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${ROOTANA_LD_LIBRARY_PATH}\n")
file(APPEND ${SETUP} "export DYLD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${ROOTANA_LD_LIBRARY_PATH}\n")

