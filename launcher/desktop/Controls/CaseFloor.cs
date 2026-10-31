using Avalonia;
using Avalonia.Media;
using System.Numerics;
namespace Outbreak.Launcher.Desktop.Controls;
public partial class GameCaseView {
    void RenderFloor(DrawingContext context) {
        if(Bounds.Width<=0||Bounds.Height<=0)return;
        const double ground=-.97,tan=.3057306814586604;
        double vertical=Math.Atan(tan*Bounds.Height/Bounds.Width),distance=1.169/Math.Sin(Math.Min(17*Math.PI/180,vertical))*1.08,focal=Bounds.Width/(2*tan);
        Point Project(Vector3 point)=>new(Bounds.Width/2+point.X*focal/(distance-point.Z),Bounds.Height/2-(point.Y-.02)*focal/(distance-point.Z));
        Point floor=Project(new(0,(float)ground,0));double width=Project(new(.675f,(float)ground,0)).X-Project(new(-.675f,(float)ground,0)).X;
        RadialGradientBrush Soft(Color center,Color edge)=>new(){GradientStops=new GradientStops{new(center,0),new(edge,1)}};
        double level=Math.Clamp(SpotlightLevel,0,1);
        using(context.PushOpacity(level))context.DrawEllipse(Soft(Color.FromArgb(72,243,236,223),Colors.Transparent),null,floor,width*1.1,width*.25);
        context.DrawEllipse(Soft(Color.FromArgb(240,0,0,0),Colors.Transparent),null,floor,width*.55,Math.Max(10,width*.18)/2);
        var rotation=Matrix4x4.CreateRotationX((float)(pitch*Math.PI/180))*Matrix4x4.CreateRotationY((float)(yaw*Math.PI/180));var lamp=new Vector3(0,5,4);
        var projected=(from x in new[]{-.675f,.675f} from y in new[]{-.95f,.95f} from z in new[]{-.07f,.07f} select Vector3.Transform(new Vector3(x,y,z),rotation)).Select(p=>Project(lamp+(p-lamp)*(float)((ground-lamp.Y)/(p.Y-lamp.Y)))).OrderBy(p=>p.X).ThenBy(p=>p.Y).ToArray();
        static double Cross(Point a,Point b,Point c)=>(b.X-a.X)*(c.Y-a.Y)-(b.Y-a.Y)*(c.X-a.X);
        var hull=new List<Point>();foreach(var p in projected){while(hull.Count>=2&&Cross(hull[^2],hull[^1],p)<=0)hull.RemoveAt(hull.Count-1);hull.Add(p);}int lower=hull.Count;
        foreach(var p in projected.Reverse().Skip(1)){while(hull.Count>lower&&Cross(hull[^2],hull[^1],p)<=0)hull.RemoveAt(hull.Count-1);hull.Add(p);}if(hull.Count>1)hull.RemoveAt(hull.Count-1);
        if(hull.Count>=3){var geometry=new StreamGeometry();using(var drawing=geometry.Open()){drawing.BeginFigure(hull[0],true);foreach(var p in hull.Skip(1))drawing.LineTo(p);drawing.EndFigure(true);}using(context.PushOpacity(level))context.DrawGeometry(new LinearGradientBrush{StartPoint=new(0,0,RelativeUnit.Relative),EndPoint=new(0,1,RelativeUnit.Relative),GradientStops=new(){new(Colors.Transparent,0),new(Color.FromArgb(190,0,0,0),1)}},null,geometry);}
    }
}
