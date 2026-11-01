using Avalonia.Animation.Easings;
using Avalonia.Automation;

namespace Outbreak.Launcher.Desktop;

// Port of RC1 MainWindow.Navigation.cs.
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
            var button = (Button)FindName("Nav" + page);
            button.IsEnabled = installed;
            AutomationProperties.SetHelpText(button,
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
                      !staticCapture && PageContent.ActualWidth > 0 && PageContent.ActualHeight > 0;
        // All pages share one fade.
        ++pageTransitionVersion;
        PageContent.StopAnimation(OpacityProperty);
        OutgoingPage.Source = null;
        OutgoingPage.StopAnimation(OpacityProperty);
        pageTransition = false;
        if (currentPage == "Controller") CancelCapture(this, new());
        if (currentPage == "Play") playScrollOffset = SettingsScroll.VerticalOffset;
        currentPage = name;
        PageContent.Opacity = animatePage ? .65 : 1;
        return true;
    }

    void AnimatePageChange() {
        if (!animatePage) return;
        pageTransition = true;
        int version = pageTransitionVersion;
        PageContent.Animate(OpacityProperty, .65, 1, TimeSpan.FromMilliseconds(300), completed: () => {
            if (version != pageTransitionVersion) return;
            PageContent.StopAnimation(OpacityProperty);
            PageContent.Opacity = 1;
            pageTransition = false;
        });
    }
}
