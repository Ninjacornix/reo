using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow
{
    int slowUiTick;
    string backdropGame = "";
    bool backdropTransition;
    void RefreshBackdrop()
    {
        if (backdropTransition || backdropGame == settings.Game.Id) return;
        bool first = backdropGame.Length == 0;
        backdropGame = settings.Game.Id;
        string artwork = backdropGame == "file2" ? "edition2-background.png" : "edition1-background.png";
        var next = new BitmapImage(new Uri("pack://application:,,,/Assets/" + artwork));
        if (first || !SystemParameters.ClientAreaAnimation) { Backdrop.Source = next; return; }
        backdropTransition = true;
        OutgoingBackdrop.Source = Backdrop.Source;
        Backdrop.Source = next;
        var duration = TimeSpan.FromMilliseconds(450);
        var easing = new CubicEase { EasingMode = EasingMode.EaseInOut };
        var fadeOut = new DoubleAnimation(1, 0, duration) { EasingFunction = easing };
        fadeOut.Completed += (_, _) =>
        {
            OutgoingBackdrop.Source = null;
            OutgoingBackdrop.BeginAnimation(OpacityProperty, null);
            Backdrop.BeginAnimation(OpacityProperty, null);
            backdropTransition = false;
            RefreshBackdrop(); // Honor the latest selection if it changed during the fade.
        };
        Backdrop.BeginAnimation(OpacityProperty, new DoubleAnimation(0, 1, duration) { EasingFunction = easing });
        OutgoingBackdrop.BeginAnimation(OpacityProperty, fadeOut);
    }
    void SelectGame(object sender, RoutedEventArgs e)
    {
        if (!initialized || game.Running || launching) return;
        settings.SelectedGame = (string)((Button)sender).Tag;
        try { settings.Save(); } catch (System.IO.IOException error) { Status.Text = error.Message; }
        RefreshGameUi(); UpdateSaves();
    }
    void ConfigureGame(object sender, RoutedEventArgs e)
    {
        if (game.Running || launching) return;
        SelectGame(sender, e);
        ShowPage("Setup");
    }
    void RefreshGameUi()
    {
        ExePath.Text = settings.GetExe(); IsoPath.Text = settings.GetIso(); ElfPath.Text = settings.GetElf(root);
        bool present = settings.FilesPresent(root);
        SelectedGameLabel.Text = settings.Game.Name;
        RefreshBackdrop();
        foreach (int n in new[] { 1, 2 })
        {
            string id = "file" + n;
            bool selected = settings.Game.Id == id;
            ((Border)FindName("GameCard" + n)).BorderBrush = (System.Windows.Media.Brush)FindResource(selected ? "Accent" : "Line");
            ((TextBlock)FindName("GameStatus" + n)).Text = settings.FilesPresent(root, id)
                ? n == 2 ? "Game files configured." : "Ready to play."
                : "Game files not configured.";
            var select = (Button)FindName("SelectGame" + n);
            select.Content = selected ? "Selected" : "Select";
            select.Background = (System.Windows.Media.Brush)FindResource(selected ? "SelectedSurface" : "Surface");
            select.IsEnabled = !game.Running && !launching;
            System.Windows.Automation.AutomationProperties.SetName(select, (selected ? "Selected: " : "Select: ") + GameDefinition.Find(id).Name);
            ((Button)FindName("ConfigureGame" + n)).IsEnabled = !game.Running && !launching;
        }
        LaunchButton.IsEnabled = present && !game.Running && !launching && !backingUp;
        PlayDisplaySummary.Text = (settings.Fullscreen ? "Borderless" : new[] { "1024 x 768", "1280 x 960", "1600 x 1200" }[settings.WindowSize]) + " / " + (settings.LinearFilter ? "Bilinear" : "Nearest");
        PlayInputSummary.Text = controller.SelectedDevice.Name;
        RefreshReadyCheck();
    }
    void StopGame(object sender, RoutedEventArgs e)
    {
        if (!game.Running) return;
        Status.Text = game.Process!.CloseMainWindow() ? "Closing game..." : "Waiting for the game window...";
    }
}
