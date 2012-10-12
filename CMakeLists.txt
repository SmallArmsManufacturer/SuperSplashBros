cmake_minimum_required (VERSION 2.8)
project ("SuperSplashBros")

add_subdirectory ("EasyBMP")

find_package ("Box2D" REQUIRED)
find_package ("OpenGL" REQUIRED)
find_package ("GLUT" REQUIRED)

find_path(BOX2D_INCLUDE_DIR Box2D/Box2D.h)
include_directories ("include" "EasyBMP/include" ${BOX2D_INCLUDE_DIR})

add_executable (
	"SuperSplashBros"
	"include/common.h"
	"include/component.h"
	"include/emittercomponent.h"
	"include/entity.h"
	"include/entityfactory.h"
	"include/game.h"
	"include/inputcomponent.h"
	"include/level.h"
	"include/levelloader.h"
	"include/physicscomponent.h"
	"src/component.cpp"
	"src/emittercomponent.cpp"
	"src/entity.cpp"
	"src/entityfactory.cpp"
	"src/game.cpp"
	"src/inputcomponent.cpp"
	"src/level.cpp"
	"src/levelloader.cpp"
	"src/main.cpp"
	"src/physicscomponent.cpp"
	"src/renderingcomponent.cpp"
)

target_link_libraries (
	"SuperSplashBros"
	"EasyBMP"
	"Box2D"
	${OPENGL_LIBRARY}
	${GLUT_LIBRARY}
)
