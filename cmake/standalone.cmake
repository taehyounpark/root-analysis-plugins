
project(RAnalysis)

file(GLOB RAnalysisHeaders RAnalysis/*.h)
file(GLOB RAnalysisSources Root/*.cxx)
list(FILTER RAnalysisHeaders EXCLUDE REGEX ".*RAnalysis/Event\.h$")
list(FILTER RAnalysisSources EXCLUDE REGEX ".*Root/Event\.cxx$")

message(${RAnalysisSources})

add_library( RAnalysis SHARED ${RAnalysisSources} ${RAnalysisHeaders})

target_include_directories(
  RAnalysis
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${ANA_INCLUDE_DIRS}
)

target_compile_features(RAnalysis PRIVATE cxx_std_17)

find_package( ROOT REQUIRED COMPONENTS Core Imt RIO Net Hist Graf Graf3d Gpad ROOTVecOps Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread MultiProc ROOTDataFrame )
find_library(ROOT_TREEPLAYER_LIBRARY TreePlayer HINTS ${ROOT_LIBRARY_DIR} REQUIRED)
find_library(ROOT_RDATAFRAME_LIBRARY ROOTDataFrame HINTS ${ROOT_LIBRARY_DIR} REQUIRED)
target_link_libraries(RAnalysis ana ROOT::Core ROOT::RIO ROOT::Hist ROOT::Tree ROOT::TreePlayer ROOT::Imt ROOT::ROOTVecOps ROOT::ROOTDataFrame)

ROOT_GENERATE_DICTIONARY(
  RAnalysisDict ${RAnalysisHeaders}
  LINKDEF Root/LinkDef.h
  MODULE RAnalysis
)

export(PACKAGE RAnalysis)
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/RAnalysis" )
set(CONF_LIBRARY_DIRS "${PROJECT_BINARY_DIR}")
set(CONF_LIBRARIES    RAnalysis)
configure_file(config.cmake.in
  "${PROJECT_BINARY_DIR}/config.cmake" @ONLY)

set(RANALYSIS_PYTHONPATH ${CMAKE_CURRENT_BINARY_DIR})
set(RANALYSIS_LD_LIBRARY_PATH ${CMAKE_CURRENT_BINARY_DIR})

install(DIRECTORY
  "${CMAKE_CURRENT_BINARY_DIR}/RAnalysis"
  EXPORT RAnalysisConfig
  DESTINATION lib
  )

#file(COPY_FILE examples/hww_mc.root ${PROJECT_BINARY_DIR}/hww_mc.root ONLY_IF_DIFFERENT)
#add_executable(hww_example examples/hww_example.cxx)
#target_compile_features(hww_example PRIVATE cxx_std_17)
#target_include_directories(hww_example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${ROOT_INCLUDE_DIRS} ${ANA_INCLUDE_DIRS})
#target_link_libraries(hww_example RAnalysis ana ROOT::Gpad ROOT::Graf ROOT::Core ROOT::RIO ROOT::Hist ROOT::Tree ROOT::TreePlayer ROOT::Imt ROOT::ROOTVecOps ROOT::Physics ROOT::MathCore ROOT::ROOTDataFrame)
#
#file(COPY_FILE benchmarks/dimuon.csv ${PROJECT_BINARY_DIR}/dimuon.csv ONLY_IF_DIFFERENT)
#add_executable(csv_benchmark benchmarks/csv_benchmark.cxx)
#target_compile_features(csv_benchmark PRIVATE cxx_std_17)
#target_include_directories(csv_benchmark PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${ROOT_INCLUDE_DIRS} ${ANA_INCLUDE_DIRS})
#target_link_libraries(csv_benchmark RAnalysis ana ROOT::Gpad ROOT::Graf ROOT::Core ROOT::RIO ROOT::Hist ROOT::Tree ROOT::TreePlayer ROOT::Imt ROOT::ROOTVecOps ROOT::Physics ROOT::MathCore ROOT::ROOTDataFrame)

set(SETUP ${CMAKE_CURRENT_BINARY_DIR}/setup.sh)
file(WRITE ${SETUP} "#!/bin/bash\n")
file(APPEND ${SETUP} "ulimit -S -s unlimited\n" )
file(APPEND ${SETUP} "export LD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${RANALYSIS_LD_LIBRARY_PATH}\n")
file(APPEND ${SETUP} "export DYLD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${RANALYSIS_LD_LIBRARY_PATH}\n")
file(APPEND ${SETUP} "export DYLD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:${RANALYSIS_LD_LIBRARY_PATH}\n")

