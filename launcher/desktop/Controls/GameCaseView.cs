using Avalonia;
using Avalonia.Controls;
using Avalonia.Input;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Avalonia.Threading;
using System.Diagnostics;
using System.Globalization;
using System.Numerics;
using Avalonia.VisualTree;
using Vector = Avalonia.Vector;

namespace Outbreak.Launcher.Desktop.Controls;

internal readonly record struct Point3D(double X,double Y,double Z) {
    internal Vector3 Vector=>new((float)X,(float)Y,(float)Z);
}
internal struct UnitVector(double x,double y) {
    internal double X=x,Y=y;
    internal void Normalize(){double length=Math.Sqrt(X*X+Y*Y);if(length>0){X/=length;Y/=length;}}
    public static UnitVector operator +(UnitVector a,UnitVector b)=>new(a.X+b.X,a.Y+b.Y);
}
internal sealed record SceneSurface(Color Color,IImage? Image=null,bool Glare=false);
internal sealed record CaseMesh(Point3D[] Positions,Point[] Uv,int[] Indices,SceneSurface Surface,bool Specular);

public partial class GameCaseView:Control {
    public static readonly StyledProperty<int> EditionProperty=AvaloniaProperty.Register<GameCaseView,int>(nameof(Edition),1);
    public static readonly StyledProperty<bool> IsAvailableProperty=AvaloniaProperty.Register<GameCaseView,bool>(nameof(IsAvailable));
    public static readonly StyledProperty<bool> IsSelectedProperty=AvaloniaProperty.Register<GameCaseView,bool>(nameof(IsSelected));
    public static readonly StyledProperty<double> SpotlightLevelProperty=AvaloniaProperty.Register<GameCaseView,double>(nameof(SpotlightLevel));
    public int Edition{get=>GetValue(EditionProperty);set=>SetValue(EditionProperty,value);}
    public bool IsAvailable{get=>GetValue(IsAvailableProperty);set=>SetValue(IsAvailableProperty,value);}
    public bool IsSelected{get=>GetValue(IsSelectedProperty);set=>SetValue(IsSelectedProperty,value);}
    public double SpotlightLevel{get=>GetValue(SpotlightLevelProperty);set=>SetValue(SpotlightLevelProperty,value);}
    IImage? cover,back,spine;
    public IImage? Cover{get=>cover;set{cover=value;RefreshAppearance();}}
    public IImage? BackCover{get=>back;set{back=value;RefreshAppearance();}}
    public IImage? SpineCover{get=>spine;set{spine=value;RefreshAppearance();}}
    readonly List<CaseMesh> meshes=[];
    readonly Dictionary<(IImage,bool),IImage> textures=[];
    readonly SceneSurface frontGlare=new(Colors.White,null,true),backGlare=new(Colors.White,null,true);
    readonly Stopwatch clock=Stopwatch.StartNew();
    readonly DispatcherTimer timer=new(){Interval=TimeSpan.FromMilliseconds(1000d/30)};
    double yaw=24,pitch=-5,velocity,pressedYaw,pressedPitch,lastDrag;
    Point origin,lastPoint;
    bool dragging,manual,held;
    double releasedAt;
    public GameCaseView() {
        ClipToBounds=false;Focusable=false;
        RenderOptions.SetBitmapInterpolationMode(this,BitmapInterpolationMode.None);
        timer.Tick+=(_,_)=>Animate();
        AttachedToVisualTree+=(_,_)=>timer.Start();
        DetachedFromVisualTree+=(_,_)=>timer.Stop();
        PointerPressed+=BeginDrag;PointerMoved+=Drag;PointerReleased+=EndDrag;
        PointerCaptureLost+=(_,_)=>dragging=false;
        RefreshAppearance();
    }
    protected override void OnPropertyChanged(AvaloniaPropertyChangedEventArgs change) {
        base.OnPropertyChanged(change);
        if(change.Property==IsAvailableProperty||change.Property==EditionProperty||change.Property==IsEnabledProperty)RefreshAppearance();
        if(change.Property==IsSelectedProperty){SpotlightLevel=IsSelected?1:0;InvalidateVisual();}
        if(change.Property==SpotlightLevelProperty)InvalidateVisual();
    }
    internal void Hold(bool value){held=value;}
    void Animate() {
        if(held||!IsVisible||!IsEnabled||!this.GetVisualAncestors().OfType<Control>().All(p=>p.IsVisible)||TopLevel.GetTopLevel(this) is Window {WindowState:WindowState.Minimized})return;
        double seconds=clock.Elapsed.TotalSeconds;
        if(dragging)return;
        if(manual) {
            if(Math.Abs(velocity)>.2){yaw+=velocity/30;velocity*=.94;releasedAt=seconds;}
            else if(seconds-releasedAt>4) {
                double target=Edition==2?18:26;
                double difference=(target-yaw%360+540)%360-180;
                yaw+=difference*.12;pitch+=(-5-pitch)*.12;
                if(Math.Abs(difference)<.2&&Math.Abs(pitch+5)<.2){manual=false;clock.Restart();}
            }
        } else if(IsAvailable) {
            double lower=Edition==2?18:-4;
            yaw=24+((Edition==2?48:-4)-24)*(1-Math.Cos(seconds*Math.PI/4))/2;
        }
        SpotlightLevel=IsSelected?Flicker(seconds%12):0;
        if(IsAvailable||manual||IsSelected)InvalidateVisual();
    }
    static double Flicker(double time) {
        (double Time,double Level)[] keys=[(0,1),(1.4,1),(1.46,.24),(1.52,1),(1.61,.38),(1.67,.96),(1.8,.22),(1.88,1),(4.2,1),(4.27,.3),(4.34,1),(4.44,.45),(4.52,1),(7.1,1),(7.17,.22),(7.27,.22),(7.34,1),(7.44,.36),(7.51,.98),(7.64,.25),(7.72,1),(10.1,1),(10.23,.5),(10.48,1),(12,1)];
        for(int i=1;i<keys.Length;i++)if(time<=keys[i].Time)return keys[i-1].Level+(keys[i].Level-keys[i-1].Level)*(time-keys[i-1].Time)/(keys[i].Time-keys[i-1].Time);
        return 1;
    }
    void BeginDrag(object? sender,PointerPressedEventArgs e) {
        if(!e.GetCurrentPoint(this).Properties.IsLeftButtonPressed)return;
        if(this.GetVisualAncestors().OfType<ListBoxItem>().FirstOrDefault() is {} item){item.IsSelected=true;item.Focus();}
        if(e.ClickCount==2){manual=false;yaw=Edition==2?18:26;pitch=-5;clock.Restart();InvalidateVisual();return;}
        dragging=manual=true;velocity=0;origin=lastPoint=e.GetPosition(this);pressedYaw=yaw;pressedPitch=pitch;lastDrag=clock.Elapsed.TotalSeconds;
        e.Pointer.Capture(this);e.Handled=true;
    }
    void Drag(object? sender,PointerEventArgs e) {
        if(!dragging)return;
        Point point=e.GetPosition(this);double seconds=clock.Elapsed.TotalSeconds;
        yaw=pressedYaw+(point.X-origin.X)*.75;pitch=Math.Clamp(pressedPitch+(point.Y-origin.Y)*.5,-75,75);
        if(seconds-lastDrag>.001)velocity=Math.Clamp((point.X-lastPoint.X)*.75/(seconds-lastDrag),-720,720);
        lastPoint=point;lastDrag=seconds;InvalidateVisual();e.Handled=true;
    }
    void EndDrag(object? sender,PointerReleasedEventArgs e) {
        if(!dragging)return;
        dragging=false;releasedAt=clock.Elapsed.TotalSeconds;e.Pointer.Capture(null);e.Handled=true;
    }
    static SceneSurface Surface(Rgba color)=>new(Color.FromArgb(color.A,color.R,color.G,color.B));
    SceneSurface Artwork(IImage? image,bool available,bool isSpine=false) {
        if(image==null)image=Fallback(isSpine);
        if(!textures.TryGetValue((image,available),out var texture)) {
            texture=ArtworkLoader.Ps2Texture(image,available);
            textures[(image,available)]=texture;
        }
        return new(Colors.White,texture);
    }
    IImage Fallback(bool isSpine) {
        int width=isSpine?36:256;
        var bitmap=new RenderTargetBitmap(new PixelSize(width,360),new Vector(96,96));
        using(var dc=bitmap.CreateDrawingContext()) {
            dc.DrawRectangle(new SolidColorBrush(Color.Parse("#141210")),null,new Rect(0,0,width,360));
            dc.DrawRectangle(new SolidColorBrush(IsAvailable?Color.Parse("#DB6A22"):Color.Parse("#B3A898")),null,new Rect(0,0,width,6));
            var text=new FormattedText(isSpine?$"OUTBREAK   /   FILE #{Edition}":$"OUTBREAK\nFILE #{Edition}",CultureInfo.InvariantCulture,FlowDirection.LeftToRight,new Typeface("Segoe UI"),isSpine?18:30,new SolidColorBrush(Color.Parse("#F3ECDF"))){TextAlignment=TextAlignment.Center};
            if(isSpine){using(dc.PushTransform(Matrix.CreateRotation(Math.PI/2)*Matrix.CreateTranslation(width/2,180)))dc.DrawText(text,new Point(0,-text.Height/2));}
            else dc.DrawText(text,new Point(width/2,180-text.Height/2));
        }
        return bitmap;
    }
    public override void Render(DrawingContext dc) {
        base.Render(dc);RenderFloor(dc);RenderCase(dc);
    }
}
