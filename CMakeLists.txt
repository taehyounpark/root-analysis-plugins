
project(RAnalysis)
include_directories("${PROJECT_SOURCE_DIR}")

ROOT_GENERATE_DICTIONARY( RAnalysisDict RAnalysis/*.h ...
   LINKDEF Root/LinkDef.h
   MODULE RAnalysis
)