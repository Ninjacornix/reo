using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Outbreak.Launcher;

internal static class StorageProgressWindow {
    internal static Task<bool> Run(Window? owner, string title,
        Func<IProgress<StorageProgress>, CancellationToken, Task> operation) {
        var completion = new TaskCompletionSource<bool>(TaskCreationOptions.RunContinuationsAsynchronously);
        var cancel = new CancellationTokenSource();
        var heading = new TextBlock { Text = "Copying and verifying your launcher data…", TextWrapping = TextWrapping.Wrap };
        var detail = new TextBlock { Margin = new(0, 12, 0, 0), TextTrimming = TextTrimming.CharacterEllipsis };
        var bar = new ProgressBar { Height = 10, Margin = new(0, 18, 0, 18), IsIndeterminate = true, Maximum = 100 };
        var button = new Button { Content = "Cancel", HorizontalAlignment = HorizontalAlignment.Right, Padding = new(22, 7, 22, 7) };
        var panel = new StackPanel { Margin = new(24) };
        panel.Children.Add(heading); panel.Children.Add(detail); panel.Children.Add(bar); panel.Children.Add(button);
        var dialog = new Window { Title = title, Content = panel, Width = 520, SizeToContent = SizeToContent.Height,
            ResizeMode = ResizeMode.NoResize, WindowStartupLocation = owner == null ? WindowStartupLocation.CenterScreen : WindowStartupLocation.CenterOwner,
            Background = new SolidColorBrush(Color.FromRgb(28, 30, 32)), Foreground = Brushes.White, Owner = owner };
        bool finished = false, cancelled = false;
        Exception? failure = null;
        void Cancel() { cancel.Cancel(); button.IsEnabled = false; heading.Text = "Cancelling… Your original files are safe."; }
        button.Click += (_, _) => Cancel();
        dialog.Closing += (_, e) => { if (!finished) { e.Cancel = true; Cancel(); } };
        var progress = new Progress<StorageProgress>(p => {
            bar.IsIndeterminate = p.Total == 0;
            if (p.Total > 0) bar.Value = Math.Min(100, 100.0 * p.Copied / p.Total);
            detail.Text = p.File;
        });
        dialog.Loaded += async (_, _) => {
            try { await Task.Run(() => operation(progress, cancel.Token)); }
            catch (OperationCanceledException) { cancelled = true; }
            catch (Exception error) { failure = error; }
            finally { finished = true; dialog.Close(); }
        };
        dialog.Closed += (_, _) => {
            if (owner != null) { owner.IsEnabled = true; owner.Activate(); }
            cancel.Dispose();
            if (failure != null) completion.TrySetException(failure);
            else completion.TrySetResult(!cancelled);
        };
        if (owner != null) owner.IsEnabled = false;
        dialog.Show();
        return completion.Task;
    }
}
