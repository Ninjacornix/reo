using Avalonia;
using Avalonia.Controls;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Avalonia.Platform;
using System.Numerics;
using System.Runtime.InteropServices;
using Vector = Avalonia.Vector;

namespace Outbreak.Launcher.Desktop.Controls;

public partial class GameCaseView {
    sealed record Texture(int Width,int Height,int[] Pixels);
    readonly Dictionary<IImage,Texture> rasterTextures=[];
    WriteableBitmap? raster;
    int[] colors=[];
    float[] depths=[];
    readonly record struct Vertex(float X,float Y,float InvZ,float U,float V,float Light,float Specular);
    void RenderCase(DrawingContext dc) {
        if(Bounds.Width<=0||Bounds.Height<=0)return;
        double windowHeight=(TopLevel.GetTopLevel(this) as Window)?.Bounds.Height??Bounds.Height*2.5;
        double scale=Math.Clamp(720/Math.Max(1,windowHeight),.15,1);
        int width=Math.Max(1,(int)Math.Ceiling(Bounds.Width*scale)),height=Math.Max(1,(int)Math.Ceiling(Bounds.Height*scale));
        if(raster==null||raster.PixelSize!=new PixelSize(width,height)) {
            raster?.Dispose();raster=new(new PixelSize(width,height),new Vector(96,96),PixelFormat.Bgra8888,AlphaFormat.Unpremul);
            colors=new int[width*height];depths=new float[colors.Length];
        }
        Array.Clear(colors);Array.Clear(depths);
        const double tan=.3057306814586604;
        double vertical=Math.Atan(tan*Bounds.Height/Bounds.Width);
        float distance=(float)(1.169/Math.Sin(Math.Min(17*Math.PI/180,vertical))*1.08);
        float focal=(float)(width/(2*tan));
        var rotation=Matrix4x4.CreateRotationX((float)(pitch*Math.PI/180))*Matrix4x4.CreateRotationY((float)(yaw*Math.PI/180));
        float level=(float)Math.Clamp(SpotlightLevel,0,1);
        var fill=Vector3.Normalize(new Vector3(1,.4f,2));
        var lamp=new Vector3(0,5,4);var camera=new Vector3(0,.02f,distance);
        var half=Vector3.Normalize(Vector3.Normalize(lamp)+Vector3.Normalize(camera));
        var across=Vector3.TransformNormal(Vector3.UnitX,rotation);var up=Vector3.TransformNormal(Vector3.UnitY,rotation);
        float glareX=.5f+2.2f*Vector3.Dot(across,half),glareY=.5f-2.2f*Vector3.Dot(up,half);
        foreach(var mesh in meshes) {
            Texture? texture=mesh.Surface.Image is {} image?ReadTexture(image):null;
            var positions=mesh.Positions.Select(p=>Vector3.Transform(p.Vector,rotation)).ToArray();
            for(int i=0;i<mesh.Indices.Length;i+=3) {
                int ia=mesh.Indices[i],ib=mesh.Indices[i+1],ic=mesh.Indices[i+2];
                var a=positions[ia];var b=positions[ib];var c=positions[ic];
                var normal=Vector3.Normalize(Vector3.Cross(b-a,c-a));
                if(!float.IsFinite(normal.X))continue;
                bool backFace=Vector3.Dot(normal,camera-(a+b+c)/3)<0;
                if(mesh.Surface.Glare&&backFace)continue;
                if(backFace)normal=-normal;
                Vertex Project(Vector3 point,Point uv) {
                    float inv=1/(distance-point.Z);
                    var light=Vector3.Normalize(lamp-point);
                    float cone=Vector3.Dot(light,Vector3.Normalize(lamp));
                    float falloff=Math.Clamp((cone-MathF.Cos(26*MathF.PI/180))/(MathF.Cos(14*MathF.PI/180)-MathF.Cos(26*MathF.PI/180)),0,1);
                    float amount=.11f+.26f*level+(.08f+.11f*level)*Math.Max(0,Vector3.Dot(normal,fill))+level*falloff*Math.Max(0,Vector3.Dot(normal,light));
                    var h=Vector3.Normalize(light+Vector3.Normalize(camera-point));
                    float specular=mesh.Specular?MathF.Pow(Math.Max(0,Vector3.Dot(normal,h)),48)*35/255f*level:0;
                    return new(width/2f+point.X*focal*inv,height/2f-(point.Y-.02f)*focal*inv,inv,(float)uv.X,(float)uv.Y,amount,specular);
                }
                float glareStrength=MathF.Pow(Math.Max(0,Vector3.Dot(normal,half)),12)*level;
                Triangle(Project(a,mesh.Uv[ia]),Project(b,mesh.Uv[ib]),Project(c,mesh.Uv[ic]),mesh.Surface,texture,width,height,glareX,glareY,glareStrength);
            }
        }
        using(var pixels=raster.Lock()) {
            if(pixels.RowBytes==width*4)Marshal.Copy(colors,0,pixels.Address,colors.Length);
            else for(int y=0;y<height;y++)Marshal.Copy(colors,y*width,pixels.Address+y*pixels.RowBytes,width);
        }
        dc.DrawImage(raster,new Rect(Bounds.Size));
    }
    Texture ReadTexture(IImage image) {
        if(rasterTextures.TryGetValue(image,out var texture))return texture;
        int width=Math.Max(1,(int)Math.Ceiling(image.Size.Width)),height=Math.Max(1,(int)Math.Ceiling(image.Size.Height));
        using var source=new RenderTargetBitmap(new PixelSize(width,height),new Vector(96,96));
        using(var context=source.CreateDrawingContext())context.DrawImage(image,new Rect(0,0,width,height));
        using var bitmap=new WriteableBitmap(new PixelSize(width,height),new Vector(96,96),PixelFormat.Bgra8888,AlphaFormat.Unpremul);
        int[] pixels=new int[width*height];
        using(var frame=bitmap.Lock()){source.CopyPixels(frame);for(int y=0;y<height;y++)Marshal.Copy(frame.Address+y*frame.RowBytes,pixels,y*width,width);}
        texture=new(width,height,pixels);rasterTextures[image]=texture;return texture;
    }
    void Triangle(Vertex a,Vertex b,Vertex c,SceneSurface material,Texture? texture,int width,int height,float glareX,float glareY,float glareStrength) {
        static float Edge(Vertex a,Vertex b,float x,float y)=>(x-a.X)*(b.Y-a.Y)-(y-a.Y)*(b.X-a.X);
        float area=Edge(a,b,c.X,c.Y);if(Math.Abs(area)<1e-7)return;
        int left=Math.Clamp((int)Math.Floor(Math.Min(a.X,Math.Min(b.X,c.X))),0,width-1),right=Math.Clamp((int)Math.Ceiling(Math.Max(a.X,Math.Max(b.X,c.X))),0,width-1);
        int top=Math.Clamp((int)Math.Floor(Math.Min(a.Y,Math.Min(b.Y,c.Y))),0,height-1),bottom=Math.Clamp((int)Math.Ceiling(Math.Max(a.Y,Math.Max(b.Y,c.Y))),0,height-1);
        for(int y=top;y<=bottom;y++)for(int x=left;x<=right;x++) {
            float w0=Edge(b,c,x+.5f,y+.5f)/area,w1=Edge(c,a,x+.5f,y+.5f)/area,w2=1-w0-w1;
            if(w0<0||w1<0||w2<0)continue;
            float z=w0*a.InvZ+w1*b.InvZ+w2*c.InvZ;int at=y*width+x;
            if(z<=depths[at])continue;
            float u=(w0*a.U*a.InvZ+w1*b.U*b.InvZ+w2*c.U*c.InvZ)/z,v=(w0*a.V*a.InvZ+w1*b.V*b.InvZ+w2*c.V*c.InvZ)/z;
            if(material.Glare) {
                float gx=(u-glareX)/.24f,gy=(v-glareY)/(.24f*(float)((ArtWidth+CaseWidth-Profile(SideProfile,CaseDepth))/(2*ArtHeight)));
                float radius=MathF.Sqrt(gx*gx+gy*gy);
                if(radius>=1)continue;
                float alpha=(radius<.3f?210+(150-210)*radius/.3f:radius<.65f?150+(40-150)*(radius-.3f)/.35f:40*(1-radius)/.35f)/255f*glareStrength;
                int prior=colors[at];int Blend(int shift,int value)=>(int)(((prior>>shift)&255)*(1-alpha)+value*alpha);
                colors[at]=unchecked((int)0xff000000)|Blend(16,243)<<16|Blend(8,236)<<8|Blend(0,223);continue;
            }
            float light=(w0*a.Light*a.InvZ+w1*b.Light*b.InvZ+w2*c.Light*c.InvZ)/z;
            float spec=(w0*a.Specular*a.InvZ+w1*b.Specular*b.InvZ+w2*c.Specular*c.InvZ)/z;
            int red=material.Color.R,green=material.Color.G,blue=material.Color.B;
            if(texture!=null) {
                int tx=Math.Clamp((int)(u*texture.Width),0,texture.Width-1),ty=Math.Clamp((int)(v*texture.Height),0,texture.Height-1);
                int pixel=texture.Pixels[ty*texture.Width+tx];red=(pixel>>16)&255;green=(pixel>>8)&255;blue=pixel&255;
            }
            red=(int)Math.Clamp(red*light+243*spec,0,255);green=(int)Math.Clamp(green*light+236*spec,0,255);blue=(int)Math.Clamp(blue*light+223*spec,0,255);
            colors[at]=unchecked((int)0xff000000)|red<<16|green<<8|blue;depths[at]=z;
        }
    }
}
