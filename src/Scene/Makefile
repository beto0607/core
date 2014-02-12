
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
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Camera.cpp -o build/Scene/camera.o 

ligth.o: 
	g++ -O2 $(SCENE_INCLUDE) -c src/Scene/Ligth.cpp -o build/Scene/light.o 
	
scene: scenenull.o scenereal.o scenemanager.o material_null.o material.o scene.o projectionmatrix.o camera.o ligth.o material_text.o
	ar -r  -s build/lib/libscene.a build/Scene/scenereal.o build/Scene/scenenull.o build/Scene/scenemanager.o build/Scene/materialnull.o build/Scene/material.o build/Scene/scene.o build/Scene/projectionmatrix.o build/Scene/camera.o build/Scene/light.o build/Scene/textmaterial.o
	
# end of libscene.a