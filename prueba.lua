-- Ejemplo simple de LUA

function onMouseMoved(x,y)
	render = Core.getRenderable("rec1");
	render.setX("rec1",x)
	render.setY("rec1",y)
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

