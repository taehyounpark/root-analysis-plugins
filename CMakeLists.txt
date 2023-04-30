################################################################################
# Project: RAnalysis
# ATLAS xAOD-specific classes for RAnalysis
################################################################################

# AnalysisBase

atlas_subdir( RAnalysis )

find_package( ROOT REQUIRED COMPONENTS Core Imt RIO Net Hist Graf Graf3d Gpad ROOTVecOps Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread MultiProc ROOTDataFrame )
find_package( Eigen )

atlas_add_root_dictionary( 
  RAnalysis RAnalysisDictInput
  ROOT_HEADERS RAnalysis/*.h Root/LinkDef.h
  EXTERNAL_PACKAGES ROOT
)

atlas_add_library( 
  RAnalysis RAnalysis/*.h Root/*.cxx ${RAnalysisDictInput}

  PUBLIC_HEADERS RAnalysis

  PRIVATE_INCLUDE_DIRS ${ROOT_INCLUDE_DIRS} 

  PRIVATE_LINK_LIBRARIES ${ROOT_LIBRARIES}

  LINK_LIBRARIES
  ana
  xAODBase
  xAODCore 
  xAODRootAccess
  xAODMetaData 
  xAODMetaDataCnv
  xAODCutFlow 
  xAODEventInfo
  xAODJet
  xAODTau
  xAODTruth
  AsgTools 
)

# message(${})
atlas_add_executable( hww_example examples/hww_example.cxx
   INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/ana ${ROOT_INCLUDE_DIRS}
   LINK_LIBRARIES ana RAnalysis 
   )


#atlas_install_python_modules( python/*.py )
#atlas_install_scripts( scripts/*.py )