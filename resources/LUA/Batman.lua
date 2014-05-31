batman = Core:getRenderable("batman_model")

pos_x = 0
pos_y = 0
angx = 0
angy = 0
angz = 0

function keyARROWUPdown()	
        pos_y = pos_y - 8
end

function keyARROWDOWNdown()	
        pos_y = pos_y + 8
end

function keyARROWLEFTdown()	
        pos_x = pos_x - 8
end

function keyARROWRIGHTdown()	
        pos_x = pos_x + 8
end

function keyARROWUPup()	
        pos_y = pos_y + 8
end

function keyARROWDOWNup()	
        pos_y = pos_y - 8
end

function keyARROWLEFTup()	
        pos_x = pos_x + 8
end

function keyARROWRIGHTup()	
        pos_x = pos_x - 8
end

function keyJdown()	
    angx = 150.0;
end

function keyJup()	
     angx = 0.0;
end

function keyKdown()	
    angy = 150.0;
end

function keyKup()	
     angy = 0.0;
end

function keyLdown()	
    angz = 150.0;
end

function keyLup()	
     angz = 0.0;
end

function update(t)
	Core.setX(batman, Core.getX(batman) + (pos_x*t))
	Core.setZ(batman, Core.getZ(batman) + (pos_y*t))
        Core.setAngleX(batman, Core.getAngleX(batman) + (angx*t))
        Core.setAngleY(batman, Core.getAngleY(batman) + (angy*t))
        Core.setAngleZ(batman, Core.getAngleZ(batman) + (angz*t))
        --print(Core.getZ(megaman))
end