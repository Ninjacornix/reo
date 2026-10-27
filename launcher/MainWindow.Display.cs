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
        if (settings.ResolvedAspect != "4:3" && settings.ResolvedFit != "stretch")
            hint.Text += settings.ResolvedWidescreen
                ? " Widescreen shows more of each room; menus, the HUD and text are stretched, movies stay 4:3."
                : " Stretched widens the original 4:3 picture; the camera view is unchanged.";
    }
}
