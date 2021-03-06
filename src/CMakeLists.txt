ADD_SUBDIRECTORY(geoformat)

FILE(GLOB HEADER *.h)
FILE(GLOB SOURCE *.cpp)

INCLUDE_DIRECTORIES($ENV{GDAL_INC} $ENV{PROTO_INC} $ENV{MPI_INC} ./geoformat)
LINK_DIRECTORIES($ENV{GDAL_LIB} $ENV{PROTO_LIB} $ENV{MPI_LIB} )

ADD_EXECUTABLE(hpgc ${HEADER} ${SOURCE})

IF(WIN32)
	TARGET_LINK_LIBRARIES(hpgc gdal_i libprotoc libprotobuf mpi cxx GeoFormat)
ELSE()
SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -O2")
	TARGET_LINK_LIBRARIES(hpgc gdal protoc protobuf mpi mpi_cxx GeoFormat)
ENDIF()

SET_TARGET_PROPERTIES( hpgc 
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
) 