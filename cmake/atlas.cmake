################################################################################
# Project: RAnalysis
# ATLAS xAOD-specific classes for RAnalysis
################################################################################

# AnalysisBase

atlas_subdir( RAnalysis )

find_package( ROOT REQUIRED COMPONENTS Core Imt RIO Net Hist Graf Graf3d Gpad ROOTVecOps Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread MultiProc ROOTDataFrame )
find_library( ROOT_TREEPLAYER_LIBRARY TreePlayer HINTS ${ROOT_LIBRARY_DIR} REQUIRED )
find_library( ROOT_RVECOPS_LIBRARY ROOTVecOps HINTS ${ROOT_LIBRARY_DIR} REQUIRED )

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
# UPDATE: the above is not true, it was just a linking thing
# however, it does fail for another reason: the operator definitions for delayed columns are not working
# TODO: fix this
# atlas_add_executable( 
#   tree_example examples/tree_example.cxx 
#   INCLUDE_DIRS ${ROOT_INCLUDE_DIR} ${ROOT_LIBRARY_DIR}
#   LINK_LIBRARIES ana RAnalysis ${ROOT_LIBRARIES}
# )

#atlas_install_data( share/* )
#atlas_install_python_modules( python/*.py )
#atlas_install_scripts( scripts/*.py )