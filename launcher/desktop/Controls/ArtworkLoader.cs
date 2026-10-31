using Avalonia;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Avalonia.Platform;
using System.Runtime.InteropServices;
using System.Text.Json;

namespace Outbreak.Launcher.Desktop.Controls;

internal static class ArtworkLoader {
    internal sealed record Case(IImage Front,IImage? Back,IImage? Spine);
    sealed record Layout(int[] Front,int[] Back,int[] Spine);
    internal static Case? LoadCase(int edition,string iso) {
        var id=GameArtwork.DiscIdentity(edition,iso);
        string[] stems=[id.Serial,$"file{edition}-{id.Region}",$"file{edition}",$"file{edition}-ntsc-u"];
        string[] folders=[GameArtwork.Folder,GameArtwork.DownloadFolder];
        foreach(string stem in stems.Distinct())foreach(string folder in folders) {
            foreach(string extension in new[]{".jpg",".png"}) {
                string path=Path.Combine(folder,stem+"-wrap"+extension);
                if(Load(path) is not {} bitmap)continue;
                int width=bitmap.PixelSize.Width,height=bitmap.PixelSize.Height;
                if(width<=height)continue;
                Layout? layout;
                string metadata=Path.ChangeExtension(path,".json");
                if(File.Exists(metadata))layout=JsonSerializer.Deserialize<Layout>(File.ReadAllText(metadata),new JsonSerializerOptions{PropertyNameCaseInsensitive=true});
                else {int spine=(int)Math.Round(width*14d/284),back=(width-spine)/2;layout=new([back+spine,0,width-back-spine,height],[0,0,back,height],[back,0,spine,height]);}
                bool Valid(int[]? p)=>p is {Length:4}&&p[0]>=0&&p[1]>=0&&p[2]>0&&p[3]>0&&(long)p[0]+p[2]<=width&&(long)p[1]+p[3]<=height;
                if(layout==null||!Valid(layout.Front)||!Valid(layout.Back)||!Valid(layout.Spine))continue;
                IImage Crop(int[] p)=>new CroppedBitmap{Source=bitmap,SourceRect=new PixelRect(p[0],p[1],p[2],p[3])};
                return new(Crop(layout.Front),Crop(layout.Back),Crop(layout.Spine));
            }
            var front=Load(Path.Combine(folder,stem+"-cover.jpg"))??Load(Path.Combine(folder,stem+"-cover.png"));
            if(front==null)continue;
            IImage? Part(string name)=>folders.SelectMany(f=>new[]{Path.Combine(f,stem+"-"+name+".jpg"),Path.Combine(f,stem+"-"+name+".png")}).Select(Load).FirstOrDefault(b=>b!=null);
            return new(front,Part("back"),Part("spine"));
        }
        return null;
    }
    internal static Bitmap? LoadDisc(int edition,string iso) {
        var id=GameArtwork.DiscIdentity(edition,iso);
        foreach(string folder in new[]{GameArtwork.Folder,GameArtwork.DownloadFolder})
            foreach(string stem in new[]{id.Serial,$"file{edition}-{id.Region}",$"file{edition}",$"file{edition}-ntsc-u"}.Distinct())
                foreach(string extension in new[]{".png",".jpg"})
                    if(Load(Path.Combine(folder,stem+"-disc"+extension)) is {} image)return image;
        return null;
    }
    internal static Bitmap? Load(string path) {
        try {if(!File.Exists(path)||new FileInfo(path).Length>32*1024*1024)return null;return new Bitmap(path);}
        catch(Exception e)when(e is IOException or ArgumentException or NotSupportedException){return null;}
    }
    internal static IImage Ps2Texture(IImage image,bool available) {
        double scale=Math.Min(1,512/image.Size.Height);
        int width=Math.Max(1,(int)Math.Round(image.Size.Width*scale)),height=Math.Max(1,(int)Math.Round(image.Size.Height*scale));
        using var raster=new RenderTargetBitmap(new PixelSize(width,height),new Vector(96,96));
        using(var context=raster.CreateDrawingContext())context.DrawImage(image,new Rect(0,0,width,height));
        var result=new WriteableBitmap(new PixelSize(width,height),new Vector(96,96),PixelFormat.Bgra8888,AlphaFormat.Premul);
        using(var pixels=result.Lock()) {
            raster.CopyPixels(pixels);
            byte[] bytes=new byte[pixels.RowBytes*height];Marshal.Copy(pixels.Address,bytes,0,bytes.Length);
            int[] bayer=[0,8,2,10,12,4,14,6,3,11,1,9,15,7,13,5];
            for(int y=0;y<height;y++)for(int x=0;x<width;x++) {
                int offset=bayer[(y&3)*4+(x&3)]>>1,i=y*pixels.RowBytes+x*4;
                for(int c=0;c<3;c++){int value=Math.Clamp(bytes[i+c]+offset,0,255)&0xf8;bytes[i+c]=(byte)(value|value>>5);}
                if(!available){byte gray=(byte)Math.Clamp(Math.Round(bytes[i+2]*.299+bytes[i+1]*.587+bytes[i]*.114),0,255);bytes[i]=bytes[i+1]=bytes[i+2]=gray;}
            }
            Marshal.Copy(bytes,0,pixels.Address,bytes.Length);
        }
        return result;
    }
    internal static IImage Backdrop(IImage image) {
        double width=image.Size.Width,height=image.Size.Height,crop=width*.72;
        var bitmap=new RenderTargetBitmap(new PixelSize(Math.Max(1,(int)crop),Math.Max(1,(int)height)),new Vector(96,96));
        using(var dc=bitmap.CreateDrawingContext())dc.DrawImage(image,new Rect(width*.14,0,crop,height),new Rect(bitmap.Size));
        return bitmap;
    }
    internal static WriteableBitmap FromBgra(byte[] bytes,int width,int height) {
        var bitmap=new WriteableBitmap(new PixelSize(width,height),new Vector(96,96),PixelFormat.Bgra8888,AlphaFormat.Unpremul);
        using(var frame=bitmap.Lock())for(int y=0;y<height;y++)Marshal.Copy(bytes,y*width*4,frame.Address+y*frame.RowBytes,width*4);
        return bitmap;
    }
}
