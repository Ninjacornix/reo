using Avalonia.Controls;

namespace Outbreak.Launcher.Desktop;

public partial class MainWindow {
    internal void CheckMovieDecoderSettings(Action<bool, string> check) {
        var previousProbe = movieDecoder;
        bool previousEnabled = settings.GpuMovies;
        bool? previousChoice = settings.GpuMoviesChoice;
        try {
            var verified = new MovieDecoderChoice(true, "Verified GPU", "Hardware MPEG-2 decoder available");
            var unverified = new MovieDecoderChoice(false, "Unverified GPU", "Movie decoding is untested");
            settings.GpuMovies = true;
            settings.GpuMoviesChoice = null;
            ApplyMovieDecoderChoice(verified);
            check(GpuMovies.IsEnabled && GpuMovies.IsChecked == true && settings.GpuMoviesChoice == null,
                  "Verified GPUs start checked without saving an explicit preference.");
            ApplyMovieDecoderChoice(unverified);
            check(GpuMovies.IsEnabled && GpuMovies.IsChecked == false && settings.GpuMoviesChoice == null,
                  "Previously CPU GPUs stay unchecked and available for manual opt-in.");
            GpuMovies.IsChecked = true;
            check(Settings.Load(root).GpuMoviesChoice == true,
                  "Manually enabling unverified GPU movies persists an explicit user choice.");
            ApplyMovieDecoderChoice(new(false, "", "Movie decoder check failed"));
            check(GpuMovies.IsEnabled && GpuMovies.IsChecked == true,
                  "A late or failed probe cannot overwrite a manual GPU choice.");
            GpuMovies.IsChecked = false;
            ApplyMovieDecoderChoice(verified);
            check(GpuMovies.IsEnabled && GpuMovies.IsChecked == false && Settings.Load(root).GpuMoviesChoice == false,
                  "An explicit CPU choice stays unchecked even on a verified GPU.");
        } finally {
            settings.GpuMovies = previousEnabled;
            settings.GpuMoviesChoice = previousChoice;
            ApplyMovieDecoderChoice(previousProbe ?? new(false, "", "Movie decoder check pending"));
            settings.Save();
        }
    }
}
