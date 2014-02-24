
RENDERER_INCLUDE= -Iinclude

# librender.a
all: renderer	
	
renderer_builder.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/RenderBuilder.cpp -o build/Renderer/renderer_builder.o
	
model2d.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Model2D.cpp -o build/Renderer/model2d.o

rectangle.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Rectangle.cpp -o build/Renderer/rectangle.o

text.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Text.cpp -o build/Renderer/text.o

renderer.o:
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Render.cpp -o build/Renderer/render.o

rendererable.o: 
	g++ -O2 $(RENDERER_INCLUDE) -c src/Renderer/Renderable.cpp -o build/Renderer/renderable.o

renderer: renderer.o model2d.o rectangle.o rendererable.o text.o renderer_builder.o
	ar -r  -s build/lib/librenderer.a build/Renderer/model2d.o build/Renderer/rectangle.o build/Renderer/render.o build/Renderer/renderable.o build/Renderer/text.o

# end of librender.a