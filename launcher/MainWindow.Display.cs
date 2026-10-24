using System.Windows;
namespace Outbreak.Launcher;
public partial class MainWindow {
    void UpdateScreenFitHint() {
        AspectRatio.IsEnabled = settings.ResolvedFit != "stretch";
        if (FindName("ScreenFitHint") is not System.Windows.Controls.TextBlock hint)
            return;
        hint.Text = settings.ResolvedFit switch {
            "stretch" => "Fills the window. Picture proportions follow the window size.",
            "center" =>
                "Keeps the original pixel height, centered. Shrinks only when needed to fit.",
            "fill" => "Fills the window at the selected ratio. Edges may be cropped.",
            _ => "Centers the picture at the selected ratio, with black borders where needed."
        };
        if (settings.ResolvedAspect == "16:9" && settings.ResolvedFit != "stretch")
            hint.Text += " 16:9 reshapes the picture; the camera is unchanged.";
    }
}
