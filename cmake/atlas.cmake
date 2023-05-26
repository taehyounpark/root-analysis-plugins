################################################################################
# Project: rootana
# ATLAS xAOD-specific classes for rootana
################################################################################

# AnalysisBase

atlas_subdir( rootana )

find_package( ROOT REQUIRED COMPONENTS Core Imt RIO Net Hist Graf Graf3d Gpad ROOTVecOps Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread MultiProc ROOTDataFrame )
find_library( ROOT_TREEPLAYER_LIBRARY TreePlayer HINTS ${ROOT_LIBRARY_DIR} REQUIRED )
find_library( ROOT_RVECOPS_LIBRARY ROOTVecOps HINTS ${ROOT_LIBRARY_DIR} REQUIRED )

atlas_add_root_dictionary( 
  rootana rootana_dict_input
  ROOT_HEADERS rootana/*.h Root/LinkDef.h
  EXTERNAL_PACKAGES ROOT
)

atlas_add_library( 
  rootana rootana/*.h Root/*.cxx ${rootana_dict_input}
  PUBLIC_HEADERS rootana
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

atlas_add_executable( 
  tree_example examples/tree_example.cxx 
  INCLUDE_DIRS ${ROOT_INCLUDE_DIR} ${ROOT_LIBRARY_DIR}
  LINK_LIBRARIES ana rootana ${ROOT_LIBRARIES}
)

atlas_add_executable( 
  xaod_example examples/xaod_example.cxx 
  INCLUDE_DIRS ${ROOT_INCLUDE_DIR} ${ROOT_LIBRARY_DIR}
  LINK_LIBRARIES ana rootana ${ROOT_LIBRARIES} xAODMuon xAODEventInfo
)

#atlas_install_data( share/* )
#atlas_install_python_modules( python/*.py )
#atlas_install_scripts( scripts/*.py )