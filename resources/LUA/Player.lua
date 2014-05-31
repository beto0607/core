-- Ejecutable: testdemo, Classe: Player, ID: megaman

megaman = Core:getRenderable("megaman")
mono = Core.getRenderable("batman_model")

pos_x = 0
pos_y = 0
flip = 0
playing = 0

function keyWdown()	
        Core.setAnimation(megaman,"walk")
        playing = playing + 1
	pos_y = pos_y - 8
end

function keySdown()
        Core.setAnimation(megaman,"walk")
        playing = playing + 1
	pos_y = pos_y + 8
        -- Core.setX(background,Core.getX(background) + 200)
end

function keyAdown()
        if flip == 0 then
            Core.flipX(megaman)
            flip = 1
        end    
        Core.setAnimation(megaman,"walk")
        playing = playing + 1
	pos_x = pos_x - 8
end

function keyDdown()
        if flip == 1 then
            Core.flipX(megaman)
            flip = 0
        end 
        Core.setAnimation(megaman,"walk")
        playing = playing + 1
	pos_x = pos_x + 8
end

function update(t)
	Core.setX(megaman, Core.getX(megaman) + (pos_x*t))
	Core.setZ(megaman, Core.getZ(megaman) + (pos_y*t))
        --print(Core.getZ(megaman))
end

function keyWup()
        playing = playing -1
        if playing == 0 then    
            Core.setAnimation(megaman,"stand")
        end    
	pos_y = pos_y + 8
end

function keySup()
        playing = playing -1
        if playing == 0 then
            Core.setAnimation(megaman,"stand")
        end 
        pos_y = pos_y - 8
end

function keyAup()
        playing = playing -1
        if playing == 0 then
            Core.setAnimation(megaman,"stand")
        end
        pos_x = pos_x + 8
end

function keyDup()
        playing = playing -1
        if playing == 0 then
            Core.setAnimation(megaman,"stand")
        end 
        pos_x = pos_x - 8
end
