-- Ejecutable: testdemo, Classe: Player, ID: megaman

rec1 = Core:getRenderable("rec1")

function onMouseMoved(x,y)
    Core.setX(rec1,x)
    Core.setY(rec1,y)
end