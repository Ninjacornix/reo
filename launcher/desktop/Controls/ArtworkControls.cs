using Avalonia;
using Avalonia.Controls;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using System.Globalization;

namespace Outbreak.Launcher.Desktop.Controls;

public class GameDiscView:Control {
    protected override Size MeasureOverride(Size available) {
        double width=double.IsFinite(available.Width)?available.Width:440;
        return new Size(width,Math.Min(290,width*.5+4));
    }
    public static readonly StyledProperty<int> EditionProperty=AvaloniaProperty.Register<GameDiscView,int>(nameof(Edition),1);
    public int Edition{get=>GetValue(EditionProperty);set=>SetValue(EditionProperty,value);}
    public bool IsAvailable{get;set;}
    public bool IsSelected{get;set;}
    public IImage? Artwork{get;set;}
    public override void Render(DrawingContext context) {
        double cameraWidth=Math.Max(2.04,Bounds.Width/Math.Max(1,Bounds.Height)*1.015),radius=Bounds.Width/cameraWidth;
        var center=new Point(Bounds.Width/2,Bounds.Height+(IsSelected?0:12));
        double cosineX=Math.Cos(3*Math.PI/180),cosineY=Math.Cos(-2*Math.PI/180),shear=Math.Sin(3*Math.PI/180)*Math.Sin(-2*Math.PI/180);
        var silver=new LinearGradientBrush{StartPoint=new(0,0,RelativeUnit.Relative),EndPoint=new(1,1,RelativeUnit.Relative),GradientStops=new(){new(Color.FromRgb(185,190,195),0),new(Color.FromRgb(132,139,145),.25),new(Color.FromRgb(224,226,228),.5),new(Color.FromRgb(107,114,120),.75),new(Color.FromRgb(185,190,195),1)}};
        using(context.PushClip(new Rect(Bounds.Size))) {
            if(IsAvailable&&IsSelected)context.DrawEllipse(new RadialGradientBrush{GradientStops=new(){new(Color.FromArgb(25,243,236,223),0),new(Colors.Transparent,1)}},null,new Point(center.X,Bounds.Height),Bounds.Width/2,50);
            using(context.PushTransform(new Matrix(cosineY,0,shear,cosineX,center.X*(1-cosineY)-center.Y*shear,center.Y*(1-cosineX)))) {
                context.DrawEllipse(silver,null,center,radius,radius);
                var rect=new Rect(center.X-radius*.962,center.Y-radius*.962,radius*1.924,radius*1.924);
                using(context.PushGeometryClip(new EllipseGeometry(rect))) {
                    if(Artwork is {} image){using(context.PushOpacity(.918))context.DrawImage(image,rect);}
                    else context.DrawRectangle(new SolidColorBrush(Color.Parse("#312C2B")),null,rect);
                }
                context.DrawEllipse(silver,null,center,radius*.20,radius*.20);
                context.DrawEllipse(new SolidColorBrush(Color.Parse("#141210")),null,center,radius*.125,radius*.125);
            }
        }
    }
}
public class GraphicsPreviewHost:Image { }
public class StickPlot:Control {
    public Pad Pad {get;set;}=new();
    public bool Right {get;set;}
    public int DeadZone {get;set;}=12;
    public override void Render(DrawingContext context) {
        double radius=Math.Min(Bounds.Width,Bounds.Height-22)/2-8;
        if(radius<1)return;
        var center=new Point(Bounds.Width/2,radius+5);
        var pen=new Pen(new SolidColorBrush(Color.Parse("#66F3ECDF")),1);
        context.DrawEllipse(new SolidColorBrush(Color.Parse("#141210")),pen,center,radius,radius);
        context.DrawLine(pen,center-new Vector(radius,0),center+new Vector(radius,0));
        context.DrawLine(pen,center-new Vector(0,radius),center+new Vector(0,radius));
        context.DrawEllipse(new SolidColorBrush(Color.Parse("#64DB6A22")),new Pen(new SolidColorBrush(Color.Parse("#DB6A22")),1),center,radius*DeadZone/100,radius*DeadZone/100);
        context.DrawEllipse(new SolidColorBrush(Color.Parse("#F3ECDF")),null,center+new Vector((Right?Pad.RX:Pad.LX)/32768d*radius,-(Right?Pad.RY:Pad.LY)/32768d*radius),3,3);
        var text=new FormattedText(Right?"Right stick":"Left stick",CultureInfo.CurrentUICulture,FlowDirection.LeftToRight,new Typeface(FontFamily.Default),11,new SolidColorBrush(Color.Parse("#B3A898")));
        context.DrawText(text,new Point(center.X-text.Width/2,radius*2+14-text.Height/2));
    }
}
public class CalibrationPreview:Control {
    public double Brightness{get;set;}=100;
    public double Gamma{get;set;}=1;
    public override void Render(DrawingContext context) {
        for(int i=0;i<16;i++) {
            byte value=(byte)Math.Clamp(Math.Round(Math.Pow(Math.Clamp(i/15d*Brightness/100,0,1),1/Gamma)*255),0,255);
            context.DrawRectangle(new SolidColorBrush(Color.FromRgb(value,value,value)),null,new Rect(i*Bounds.Width/16,0,Bounds.Width/16,Bounds.Height));
        }
    }
}
