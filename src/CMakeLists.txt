cmake_minimum_required (VERSION 3.0)

SET(LIBSRC libbrent)
	
PROJECT(Brent)
ADD_LIBRARY(brent SHARED ${LIBSRC})
ADD_EXECUTABLE(Brent brent.cpp)
TARGET_LINK_LIBRARIES(Brent ${LIBSRC})
