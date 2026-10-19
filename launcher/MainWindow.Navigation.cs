using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    string currentPage = "", pendingPage = "";
    bool pageTransition, animatePage;

    bool PreparePageChange(string name) {
        if (pageTransition) {
            pendingPage = name;
            return false;
        }
        if (name == currentPage)
            return false;
        animatePage = IsLoaded && currentPage.Length != 0 && SystemParameters.ClientAreaAnimation &&
                      PageContent.ActualWidth > 0 && PageContent.ActualHeight > 0;
        if (animatePage) {
            OutgoingPage.Source = SnapshotPageArea(PageContent);
            OutgoingHeader.Source = SnapshotPageArea(PageHeader);
        }
        if (currentPage == "Controller")
            CancelCapture(this, new());
        currentPage = name;
        return true;
    }

    BitmapSource SnapshotPageArea(FrameworkElement area) {
        var bounds = new Rect(0, 0, area.ActualWidth, area.ActualHeight);
        // Include the background beneath the old page. Dissolving this opaque
        // image over the new page avoids the brightness dip from two alpha fades.
        var brush = new VisualBrush(this) {
            ViewboxUnits = BrushMappingMode.Absolute,
            Viewbox = area.TransformToAncestor(this).TransformBounds(bounds), Stretch = Stretch.Fill
        };
        var visual = new DrawingVisual();
        using (var drawing = visual.RenderOpen()) drawing.DrawRectangle(brush, null, bounds);
        var dpi = VisualTreeHelper.GetDpi(this);
        var snapshot =
            new RenderTargetBitmap((int)Math.Ceiling(bounds.Width * dpi.DpiScaleX),
                                   (int)Math.Ceiling(bounds.Height * dpi.DpiScaleY),
                                   dpi.PixelsPerInchX, dpi.PixelsPerInchY, PixelFormats.Pbgra32);
        snapshot.Render(visual);
        snapshot.Freeze();
        return snapshot;
    }

    void AnimatePageChange() {
        if (!animatePage)
            return;
        pageTransition = true;
        var duration = TimeSpan.FromMilliseconds(450);
        var easing = new CubicEase { EasingMode = EasingMode.EaseInOut };
        var outgoing = new DoubleAnimation(1, 0, duration) { EasingFunction = easing };
        outgoing.Completed += (_, _) => {
            OutgoingPage.Source = null;
            OutgoingHeader.Source = null;
            OutgoingPage.BeginAnimation(OpacityProperty, null);
            OutgoingHeader.BeginAnimation(OpacityProperty, null);
            pageTransition = false;
            string next = pendingPage;
            pendingPage = "";
            if (next.Length != 0 && next != currentPage)
                ShowPage(next);
        };
        OutgoingHeader.BeginAnimation(
            OpacityProperty, new DoubleAnimation(1, 0, duration) { EasingFunction = easing });
        OutgoingPage.BeginAnimation(OpacityProperty, outgoing);
    }
}
