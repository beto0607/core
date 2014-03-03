-- Ejecutable: testdemo, Classe: Player, ID: megaman

camera = Core:getActiveCamera()

function keyARROWUPdown()
        
end

function keyARROWDOWNdown()
        
end

function keyARROWLEFTdown()
        Core:setCameraX(camera, Core:getCameraX(camera) - 50)
end

function keyARROWRIGHTdown()
        Core:setCameraX(camera, Core:getCameraX(camera) + 50)
end

function update(t)
        print(t)
end