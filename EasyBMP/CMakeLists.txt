cmake_minimum_required (VERSION 2.8)
project ("EasyBMP")

include_directories ("include")

add_library (
	"EasyBMP"
	"include/EasyBMP.h"
	"include/EasyBMP_BMP.h"
	"include/EasyBMP_DataStructures.h"
	"include/EasyBMP_VariousBMPUtilities.h"
	"src/EasyBMP.cpp"
)
