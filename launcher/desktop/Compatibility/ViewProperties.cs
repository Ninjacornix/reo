using Avalonia;
using Avalonia.Controls;
using Avalonia.Media;
using Avalonia.VisualTree;

namespace Outbreak.Launcher.Desktop.Compatibility;

// Small source-migration adapters for RC1's programmatically constructed rows.
// Every control is an Avalonia control; there is no WPF runtime dependency.
public enum Visibility {Visible,Hidden,Collapsed}
public sealed record Style(string Key);
public static class ViewProperties {
    extension(Control control) {
        public Visibility Visibility {
            get=>!control.IsVisible?Visibility.Collapsed:control.Opacity==0?Visibility.Hidden:Visibility.Visible;
            set {control.IsVisible=value!=Visibility.Collapsed;if(value==Visibility.Hidden)control.Opacity=0;else if(control.Opacity==0)control.Opacity=1;}
        }
        public double ActualWidth=>control.Bounds.Width;
        public double ActualHeight=>control.Bounds.Height;
        public bool IsLoaded=>TopLevel.GetTopLevel(control)!=null;
        public object? ToolTip {get=>Avalonia.Controls.ToolTip.GetTip(control);set=>Avalonia.Controls.ToolTip.SetTip(control,value);}
        public Style? Style {
            get=>control.Classes.Count>0?new(control.Classes[0]):null;
            set {
                if(value==null)return;
                control.Classes.Add(value.Key);
                if(value.Key=="ModOption")control.Classes.Add("CheatOption");
                if(value.Key=="GameFilePath")control.Classes.Add("CoopTextInput");
            }
        }
    }
}
public static class VisualPalette {
    public static SolidColorBrush Brush(Rgba color,byte alpha=255) {
        var mixed=Palette.WithAlpha(color,alpha);
        return new(Color.FromArgb(mixed.A,mixed.R,mixed.G,mixed.B));
    }
}
