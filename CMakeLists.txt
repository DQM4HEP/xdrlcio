#################################################
# cmake file for building xdrlcio package
# @author Eté Rémi
CMAKE_MINIMUM_REQUIRED( VERSION 2.6 FATAL_ERROR )
#################################################

# project name
PROJECT( xdrlcio )

SET( ${PROJECT_NAME}_VERSION_MAJOR 1 )
SET( ${PROJECT_NAME}_VERSION_MINOR 0 )
SET( ${PROJECT_NAME}_VERSION_PATCH 1 )

MACRO( BUILD_TEST _testname )
	ADD_EXECUTABLE( ${_testname} source/tests/${_testname}.cc )
	TARGET_LINK_LIBRARIES( ${_testname} ${PROJECT_NAME} )

	INSTALL( 
	    TARGETS ${_testname}
	    RUNTIME DESTINATION bin/tests
	)
ENDMACRO()

# --------------- dependencies -----------
LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

# load default settings
INCLUDE( default_settings )

OPTION( INSTALL_DOC "Whether to build Doxygen documentation" OFF )
OPTION( BUILD_TESTS "Whether to build tests" OFF )

IF( INSTALL_DOC )
	ADD_SUBDIRECTORY( doc )	
ENDIF()

# ---- find packages ----
FIND_PACKAGE( xdrstream REQUIRED )
FIND_PACKAGE( LCIO REQUIRED )

FOREACH( pkg xdrstream LCIO )
	INCLUDE_DIRECTORIES( ${${pkg}_INCLUDE_DIRS} )
	LINK_LIBRARIES( ${${pkg}_LIBRARIES} )
	ADD_DEFINITIONS ( ${${pkg}_DEFINITIONS} )
ENDFOREACH()

###############################
# Generate xdrlcioConfig.h 
CONFIGURE_FILE( "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.h.cmake.in"
    "${PROJECT_SOURCE_DIR}/source/include/${PROJECT_NAME}Config.h" @ONLY )

###############################
# include directories
INCLUDE_DIRECTORIES( source/include )

# require proper c++
ADD_DEFINITIONS( "-pedantic -Wunused-value -O2" )
ADD_DEFINITIONS("-Wno-long-long -Wreturn-type")

AUX_SOURCE_DIRECTORY( ./source/src/ SRC_FILES )

ADD_SHARED_LIBRARY( ${PROJECT_NAME} ${SRC_FILES} )

INSTALL( 
    TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
)

INSTALL( DIRECTORY source/include DESTINATION . PATTERN *.h )

IF( BUILD_TESTS )
	BUILD_TEST( xdrlcio_test_calohit )
ENDIF()

###############################
# display some variables and write them to cache
DISPLAY_STD_VARIABLES()

###############################
# generate and install following configuration files
GENERATE_PACKAGE_CONFIGURATION_FILES( ${PROJECT_NAME}Config.cmake ${PROJECT_NAME}ConfigVersion.cmake ${PROJECT_NAME}LibDeps.cmake )

