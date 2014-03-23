
SCENE_INCLUDE= -Iinclude

# libscene.a
all: scene

scenenull.o:	
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/SceneNull.cpp -o build/Scene/scenenull.o 

scenereal.o:	
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/SceneReal.cpp -o build/Scene/scenereal.o 
	
scenemanager.o:	
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/SceneManager.cpp -o build/Scene/scenemanager.o 

material_null.o: 	
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/MaterialNull.cpp -o build/Scene/materialnull.o 

material_text.o: 	
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/TextMaterial.cpp -o build/Scene/textmaterial.o 

material.o: 	
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Material.cpp -o build/Scene/material.o 

scene.o: 	
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Scene.cpp -o build/Scene/scene.o 
	
projectionmatrix.o: 
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/ProjectionMatrix.cpp -o build/Scene/projectionmatrix.o 

camera.o: 
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Camera/Camera.cpp -o build/Scene/camera.o 

camera_strategy.o: 
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Camera/CameraStrategy.cpp -o build/Scene/camera_strategy.o 

camera_folower_strategy.o: 
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Camera/FollowerCameraStrategy.cpp -o build/Scene/camera_folower_strategy.o 

camera_free_camera_strategy.o: 
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Camera/FreeCameraStrategy.cpp -o build/Scene/camera_free_camera_strategy.o 

ligth.o: 
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Ligth.cpp -o build/Scene/light.o 
	
scene: scenenull.o scenereal.o scenemanager.o material_null.o material.o scene.o projectionmatrix.o camera_folower_strategy.o camera.o ligth.o material_text.o camera_strategy.o camera_free_camera_strategy.o
	ar -r  -s build/lib/libscene.a build/Scene/scenereal.o build/Scene/scenenull.o build/Scene/camera_folower_strategy.o build/Scene/scenemanager.o build/Scene/materialnull.o build/Scene/material.o build/Scene/scene.o build/Scene/projectionmatrix.o build/Scene/camera.o build/Scene/light.o build/Scene/textmaterial.o build/Scene/camera_free_camera_strategy.o build/Scene/camera_strategy.o
	
# end of libscene.a