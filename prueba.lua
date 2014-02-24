-- Ejemplo simple de LUA

function onMouseMoved(x,y)
	render = Core.getRenderable("rec1");
	print(render.getX)
	render.setX("rec3",x)
	render.setY("rec3",y)
	return 0
end

function onMouseKeyDown()
	print("jamaica")
	return 0
end

function funcion()
	print("jamaica")
	return 0
end

