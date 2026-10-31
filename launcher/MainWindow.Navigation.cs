using System.Windows;
using System.Windows.Media.Animation;

namespace Outbreak.Launcher;
public partial class MainWindow {
    static readonly string[] GamePages = { "Graphics", "Audio", "Controller", "Saves", "Coop", "Mods", "Cheats", "Developer" };
    bool gameNavigationAvailable;
    string currentPage = "";
    bool pageTransition, animatePage;
    double playScrollOffset;
    int pageTransitionVersion;

    void UpdateNavigationAvailability(bool installed) {
        bool removedLastGame = gameNavigationAvailable && !installed;
        gameNavigationAvailable = installed;
        foreach (string page in GamePages) {
            var button = (System.Windows.Controls.Button)FindName("Nav" + page);
            button.IsEnabled = installed;
            System.Windows.Automation.AutomationProperties.SetHelpText(button,
                installed ? "" : "Install a game in Game files to use this section.");
        }
        if (removedLastGame && GamePages.Contains(currentPage)) {
            ShowPage("Play");
            NavPlay.Focus();
        }
    }

    bool PreparePageChange(string name) {
        if (name == currentPage) return false;
        animatePage = IsLoaded && currentPage.Length != 0 && SystemParameters.ClientAreaAnimation &&
                      PageContent.ActualWidth > 0 && PageContent.ActualHeight > 0;
        // All pages share one fade. HWNDs ignore WPF opacity, so the native
        // preview receives this same value in its final GPU presentation pass.
        // No snapshots of live video/native surfaces on the UI thread.
        ++pageTransitionVersion;
        PageContent.BeginAnimation(OpacityProperty, null);
        OutgoingPage.Source = null;
        OutgoingPage.BeginAnimation(OpacityProperty, null);
        pageTransition = false;
        if (currentPage == "Controller") CancelCapture(this, new());
        if (currentPage == "Play") playScrollOffset = SettingsScroll.VerticalOffset;
        currentPage = name;
        // Set before activating the native surface, including its first frame.
        PageContent.Opacity = animatePage ? .65 : 1;
        return true;
    }

    void AnimatePageChange() {
        if (!animatePage) return;
        pageTransition = true;
        int version = pageTransitionVersion;
        var fade = new DoubleAnimation(.65, 1, TimeSpan.FromMilliseconds(300));
        fade.Completed += (_, _) => {
            if (version != pageTransitionVersion) return;
            PageContent.BeginAnimation(OpacityProperty, null);
            PageContent.Opacity = 1;
            pageTransition = false;
        };
        PageContent.BeginAnimation(OpacityProperty, fade);
    }
}
