using Avalonia.Headless;
using Avalonia.VisualTree;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow {
    internal void CheckActivityOverlay(Action<bool, string> check, string output) {
        double width = Width, height = Height;
        string pageBefore = currentPage;
        try {
            foreach (var size in new[] { (1320, 920), (980, 690) }) {
                Width = size.Item1;
                Height = size.Item2;
                foreach (string page in new[] { "Play", "Graphics", "Audio", "Controller", "Saves",
                                                "Coop", "Mods", "Cheats", "Setup", "Launcher",
                                                "Logs", "Developer" }) {
                    ShowPage(page);
                    Status.Text = "Preparing game...";
                    var progress = BeginDiscImport();
                    progress.Report(new(1, 2, "Downloading build tools", "Preparing game"));
                    Dispatcher.UIThread.RunJobs();
                    check(!StatusToast.IsVisible,
                          $"Setup progress duplicates the progress bar in a toast on {page}.");
                    check(!ImportState.IsVisible,
                          "Active setup progress must not be duplicated above Game files.");
                    // Progress also updates inline status text on Game files. Hold that text
                    // constant so this comparison measures only the overlay's layout effect.
                    ImportActivity.IsVisible = false;
                    UpdateLayout();
                    var content = PageContent.Bounds;
                    var footer = LauncherFooter.Bounds;
                    var viewport = SettingsScroll.Viewport;
                    ImportActivity.IsVisible = true;
                    UpdateLayout();
                    // Hit testing uses the rendered scene, including its size after a resize.
                    using var overlayFrame = this.CaptureRenderedFrame();
                    var detailTop = SetupDetail.TranslatePoint(default, this)!.Value.Y;
                    var timingTop = ImportTiming.TranslatePoint(default, this)!.Value.Y;
                    var barBottom =
                        DiscProgress.TranslatePoint(new Point(0, DiscProgress.Bounds.Height),
                                                    this)!.Value.Y;
                    check(Math.Abs(detailTop - timingTop) < 1 && detailTop >= barBottom &&
                              SetupDetail.Bounds.Right <= ImportTiming.Bounds.Left,
                          $"Setup detail and timing must share one row below the bar at {size}.");
                    check(PageContent.Bounds == content && LauncherFooter.Bounds == footer &&
                              SettingsScroll.Viewport == viewport,
                          $"Setup progress shifts or shrinks {page} at {size}.");
                    check(ImportActivity.IsEffectivelyVisible && ImportActivity.Bounds.Height > 0,
                          $"Setup progress is hidden on {page} at {size}.");
                    var button = Action_CancelImport_114;
                    var point = button.TranslatePoint(
                        new Point(button.Bounds.Width / 2, button.Bounds.Height / 2), this);
                    var hit = point is {}
                    position ? this.InputHitTest(position) as Visual : null;
                    check(hit != null &&
                              (hit == button || hit.GetVisualAncestors().Contains(button)),
                          $"Page content covers the setup cancel button on {page} at {size}.");
                    if (page == "Setup" && size.Item1 == 1320) {
                        overlayFrame!.Save(Path.Combine(output, "Setup-progress-overlay.png"));
                        Status.Text = "Game imported. Ready to play.";
                        check(StatusToast.IsVisible,
                              "Import completion must remain visible before setup ends.");
                        Status.Text = "Could not import: test failure.";
                        check(StatusToast.IsVisible && StatusToastTitle.Text == Status.Text,
                              "Import errors must remain visible before setup ends.");
                        HideStatusToast();
                    }
                    button.RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
                    check(importCancellation!.IsCancellationRequested,
                          $"Setup cannot be cancelled from {page} at {size}.");
                    EndDiscImport();
                    check(ImportState.IsVisible,
                          "Game-files guidance must return when setup ends.");
                }
            }
        } finally {
            if (importCancellation != null)
                EndDiscImport();
            Width = width;
            Height = height;
            ShowPage(pageBefore);
            UpdateLayout();
        }
    }
}
