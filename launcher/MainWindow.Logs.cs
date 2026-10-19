using Microsoft.Win32;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Outbreak.Launcher;
public partial class MainWindow {
    record LogSession(string Name, string Directory) {
        public override string ToString() => Name;
    }
    bool logUiUpdating;
    string? manualLog;
    string lastLogPath = "";
    long lastLogLength = -1;
    DateTime lastLogWrite;
    string CurrentLogPath =>
        manualLog ??
        (LogSessionPicker.SelectedItem is LogSession session
             ? Path.Combine(session.Directory,
                            LogStreamPicker.SelectedIndex == 1 ? "stdout.log" : "stderr.log")
             : "");
    void RefreshLogSessions() {
        string? prior = (LogSessionPicker.SelectedItem as LogSession)?.Directory;
        string folder = Path.Combine(Settings.Home, "sessions");
        var items = Directory.Exists(folder)
                        ? Directory.EnumerateDirectories(folder)
                              .OrderDescending()
                              .Take(40)
                              .Select(d => new LogSession(Path.GetFileName(d), d))
                              .ToList()
                        : new List<LogSession>();
        string existing = Path.Combine(root, "build-ninja", "play");
        if (File.Exists(Path.Combine(existing, "stderr.log")))
            items.Add(new("Existing game logs", existing));
        logUiUpdating = true;
        LogSessionPicker.ItemsSource = items;
        LogSessionPicker.SelectedItem =
            items.FirstOrDefault(s => s.Directory == (game.Logs ?? prior)) ??
            items.FirstOrDefault();
        if (LogStreamPicker.SelectedIndex < 0)
            LogStreamPicker.SelectedIndex = 0;
        logUiUpdating = false;
        lastLogPath = "";
        RefreshLog();
    }
    void LogSelectionChanged(object sender, SelectionChangedEventArgs e) {
        if (!initialized || logUiUpdating)
            return;
        manualLog = null;
        lastLogPath = "";
        RefreshLog();
    }
    void BrowseLog(object sender, RoutedEventArgs e) {
        var dialog = new OpenFileDialog { Title = "Open game log",
                                          Filter = "Log files|*.log;*.txt|All files|*.*",
                                          CheckFileExists = true };
        if (dialog.ShowDialog(this) != true)
            return;
        manualLog = dialog.FileName;
        lastLogPath = "";
        RefreshLog();
    }
    void RefreshLog() {
        string path = CurrentLogPath;
        if (path.Length == 0 || !File.Exists(path)) {
            DebugLog.Text = "No log available.";
            LogInfo.Text = "Start the game or open an existing log file.";
            return;
        }
        try {
            var info = new FileInfo(path);
            if (lastLogPath == path && lastLogLength == info.Length &&
                lastLogWrite == info.LastWriteTimeUtc)
                return;
            double offset = DebugLog.VerticalOffset;
            DebugLog.Text = LogTail.Read(path);
            if (FollowLog.IsChecked == true)
                DebugLog.Dispatcher.BeginInvoke(
                    System.Windows.Threading.DispatcherPriority.Background, new Action(() => {
                        if (FollowLog.IsChecked == true)
                            DebugLog.ScrollToEnd();
                    }));
            else
                DebugLog.ScrollToVerticalOffset(offset);
            lastLogPath = path;
            lastLogLength = info.Length;
            lastLogWrite = info.LastWriteTimeUtc;
            LogInfo.Text = Path.GetFileName(path) + " / latest 128 KB / " +
                           info.Length.ToString("N0") + " bytes";
            LogInfo.ToolTip = path;
        } catch (IOException) {
            LogInfo.Text = "Waiting for the log writer...";
        } catch (UnauthorizedAccessException) {
            LogInfo.Text = "Cannot read this log file.";
        }
    }
}
