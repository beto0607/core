import bpy
import struct
import mathutils

class Mesh():
    meshname = 0
    vertexcant = 0
    facescant  = 0
    materialcant = 0
    position = 0
    rotation = 0
    scale = 0
    vertex = 0
    normal = []
    faces  = 0
    material = []
    texture_vertex = []
    def addVertex(self,vert):
        self.vertex = vert
    def addNormal(self,norm):
        self.normal.append(norm)   
    def addTextureVertex(self,tv):
        self.texture_vertex.append(tv)
    def addFace(self,face):       
        self.faces = face  
    def addMaterial(self,materialname):
        self.material.append(materialname)    
    def getVertexCountString(self):
        return "%s" % self.vertexcant    
    def getNormalCountString(self):
        return "%s" % self.vertexcant    
    def getFacesCountString(self):
        return "%s" % self.facescant
    def getMaterialCountString(self):
        return "%s" % len(self.material)    
    def getTextureVertexCountString(self):
        return "%s" % len(self.texture_vertex)
    def getVertexBuffer(self):
        return self.vertex    
    def saveVertex(self,f):
        uv = self.texture_vertex
        for i,v in enumerate(self.vertex):
            f.write("%d " % i)
            f.write("%.2f " % v.co.x)
            f.write("%.2f " % v.co.y)
            f.write("%.2f " % v.co.z)
            f.write("%.2f " % v.normal.x)
            f.write("%.2f " % v.normal.y)
            f.write("%.2f " % v.normal.z)
            try:
                f.write("%.2f " % uv[i][0])
                f.write("%.2f\n" % (1.0 - uv[i][1])) 
            except IndexError:
                f.write("0.0 ")
                f.write("0.0\n") 
    def saveFaces(self,f):
        for i,fa in enumerate(self.faces):
            f.write("%d " % i)
            f.write("%d " % fa.vertices[0])
            f.write("%d " % fa.vertices[1])
            f.write("%d\n" % fa.vertices[2])
    def saveMaterials(self,f):
        for mat in self.material:
            f.write("%s " % mat.split(".",1)[0])        
            
class Objeto:
    mesh = []
    meshcount = 0
    def print(self):
        print("\n\n Preparing Object \n\n")
        print("Mesh Count: "+"%s" % self.meshcount)
        for m in self.mesh:
            print("Vertex Count: "+m.getVertexCountString())
            print("Normals Count: "+m.getNormalCountString())
            print("UV Coord Count: "+m.getTextureVertexCountString())
            print("Index Count: "+m.getFacesCountString())
    
    def addMesh(self,_mesh):
        self.mesh.append(_mesh)
        self.meshcount+=1
        
    def saveObject(self,f):
        f.write('SOURCE Blender Python Script Exporter\n')
        f.write('MESHES '+"%s"%len(self.mesh)+'\n')
        f.write('JOINTS 0\n')
        self.saveMeshs(f)
        
    def saveMeshs(self,f):  
        for m in self.mesh:
            f.write('MESH '+m.meshname+' ')
            f.write(m.getVertexCountString()+' ')
            f.write(m.getFacesCountString()+'\n')
            m.saveVertex(f)
            m.saveFaces(f)
            m.saveMaterials(f)
            f.write('MATERIAL '+m.getMaterialCountString()+'\n')
            m.saveMaterials(f)
                
def scaleVertex(v,s):
    m = mathutils.Matrix()
    m[0][0]=s[0]
    m[1][1]=s[1]
    m[2][2]=s[2]
    return v * m

def exportarDatosDeMalla(obj):
    objects = bpy.data.objects
    for o in objects:
        if o.type == 'MESH':
            auxmesh = Mesh()
            auxmesh.meshname = o.name
            auxmesh.position = o.location
            auxmesh.rotation = o.rotation_euler
            auxmesh.scale = o.scale
            # get Mesh Vertex in a list, whit Vertex i have normal and coordinates
            vertices = o.data.vertices
            auxmesh.vertexcant = len(vertices)
            auxmesh.addVertex(vertices)
            # get Mesh Faces in a list
            faces = o.data.polygons
            auxmesh.facescant = len(faces)
            auxmesh.addFace(faces)
            # get UV Map, if it exists
            if len(o.data.uv_layers) != 0:
                print("tiene texturas\n")
                aux_tex = o.data.uv_layers.active.data
                textures = dict()
                for i,p in enumerate(faces):
                    textures[p.vertices[0]] = aux_tex[i*3]
                    textures[p.vertices[1]] = aux_tex[i*3+1]
                    textures[p.vertices[2]] = aux_tex[i*3+2] 
                for k,t in textures.items():
                    auxmesh.addTextureVertex(t.uv)
            if(len(o.data.materials) != 0):        
                if(hasattr(o.data.materials[0].active_texture,'image')):
                    auxmesh.addMaterial(o.data.materials[0].active_texture.image.name)                       
            obj.addMesh(auxmesh)
                
def createFile(obj,file,filepath):
    obj.print()
    obj.saveObject(file)  
            
def write_some_data(context, filepath, mesh):
    print("Creating mesh file: " + filepath)
    o = Objeto()    
    if mesh:
        exportarDatosDeMalla(o)            
    f = open(filepath, 'w')         
    createFile(o,f,filepath)
    f.close()
    return {'FINISHED'}


# ExportHelper is a helper class, defines filename and
# invoke() function which calls the file selector.
from bpy_extras.io_utils import ExportHelper
from bpy.props import StringProperty, BoolProperty, EnumProperty
from bpy.types import Operator


class ExportSomeData(Operator, ExportHelper):
    """This appears in the tooltip of the operator and in the generated docs"""
    bl_idname = "export_test.some_data"  # important since its how bpy.ops.import_test.some_data is constructed
    bl_label = "Exportar Kaikai mesh"

    # ExportHelper mixin class uses this
    filename_ext = ".kkm"

    filter_glob = StringProperty(
            default="*.kkm",
            options={'HIDDEN'},
            )

    # List of operator properties, the attributes will be assigned
    # to the class instance from the operator settings before calling.
    mesh = BoolProperty(
            name="Mesh",
            description="Exporta la malla del objeto",
            default=True,
            )         

    def execute(self, context):
        return write_some_data(context, self.filepath, self.mesh)


# Only needed if you want to add into a dynamic menu
def menu_func_export(self, context):
    self.layout.operator(ExportSomeData.bl_idname, text="Text Export Operator")


def register():
    bpy.utils.register_class(ExportSomeData)
    bpy.types.INFO_MT_file_export.append(menu_func_export)


def unregister():
    bpy.utils.unregister_class(ExportSomeData)
    bpy.types.INFO_MT_file_export.remove(menu_func_export)


if __name__ == "__main__":
    register()

    # test call
    bpy.ops.export_test.some_data('INVOKE_DEFAULT')
