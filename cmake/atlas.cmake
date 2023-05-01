################################################################################
# Project: RAnalysis
# ATLAS xAOD-specific classes for RAnalysis
################################################################################

# AnalysisBase

atlas_subdir( RAnalysis )

find_package( ROOT REQUIRED COMPONENTS Core Imt RIO Net Hist Graf Graf3d Gpad ROOTVecOps Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread MultiProc ROOTDataFrame )

atlas_add_root_dictionary( 
  RAnalysis RADictInput
  ROOT_HEADERS RAnalysis/*.h Root/LinkDef.h
  EXTERNAL_PACKAGES ROOT
)

atlas_add_library( 
  RAnalysis RAnalysis/*.h Root/*.cxx ${RADictInput}
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

# for some reason, template instantations fail for analysis<Tree>
# but are accessible from ROOT interpreter session through the linked dictionary
# maybe it's a G++ problem
# atlas_add_executable( 
#   hww_example examples/hww_example.cxx 
#   INCLUDE_DIRS ${ROOT_INCLUDE_DIRS}
#   LINK_LIBRARIES ana RAnalysis
# )

#atlas_install_data( share/* )
#atlas_install_python_modules( python/*.py )
#atlas_install_scripts( scripts/*.py )