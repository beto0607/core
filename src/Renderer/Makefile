
RENDERER_INCLUDE= -Iinclude

# librender.a
all: renderer	

invisible_draw_strategy.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/RenderableStrategies/InvisibleDraw.cpp -o build/Renderer/invisible_draw_strategy.o

wireframe_draw_strategy.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/RenderableStrategies/WireframeDraw.cpp -o build/Renderer/wireframe_draw_strategy.o

solid_draw_strategy.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/RenderableStrategies/SolidDraw.cpp -o build/Renderer/solid_draw_strategy.o

draw_strategy.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/RenderableStrategies/DrawStrategy.cpp -o build/Renderer/draw_strategy.o
	
kkmeshloader.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/KKMeshLoader.cpp -o build/Renderer/kkmeshloader.o

renderer_builder.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/RenderBuilder.cpp -o build/Renderer/renderer_builder.o
	
actor.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Actor.cpp -o build/Renderer/actor.o	
	
model2d.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Model2D.cpp -o build/Renderer/model2d.o

model3d.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Model3D.cpp -o build/Renderer/model3d.o

rectangle.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Rectangle.cpp -o build/Renderer/rectangle.o

mesh.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Mesh.cpp -o build/Renderer/mesh.o

text.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Text.cpp -o build/Renderer/text.o

renderer.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Render.cpp -o build/Renderer/render.o

rendererable.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Renderable.cpp -o build/Renderer/renderable.o

renderer: renderer.o actor.o model3d.o model2d.o rectangle.o rendererable.o mesh.o text.o renderer_builder.o kkmeshloader.o draw_strategy.o solid_draw_strategy.o wireframe_draw_strategy.o invisible_draw_strategy.o
	ar -r  -s build/lib/librenderer.a build/Renderer/model2d.o build/Renderer/mesh.o build/Renderer/actor.o build/Renderer/model3d.o build/Renderer/rectangle.o build/Renderer/render.o build/Renderer/renderable.o build/Renderer/text.o build/Renderer/kkmeshloader.o build/Renderer/draw_strategy.o build/Renderer/solid_draw_strategy.o build/Renderer/wireframe_draw_strategy.o build/Renderer/invisible_draw_strategy.o

# end of librender.a