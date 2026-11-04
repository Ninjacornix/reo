namespace Outbreak.Launcher.Desktop.Controls;

// Port of RC1 BackgroundVideoPlayer.cs.
// Two passive surfaces overlap while the next clip opens. No transport controls,
// focus, input handlers or user-driven seeking are attached to either surface.
internal sealed class BackgroundVideoPlayer : IDisposable {
    readonly VideoSurface[] players;
    readonly DispatcherTimer timer = new() { Interval = TimeSpan.FromMilliseconds(100) };
    readonly Action changed;
    readonly HashSet<int> failed = new();
    sealed record Bookmark(string File, TimeSpan Position);
    readonly Dictionary<string, Bookmark> bookmarks = new(StringComparer.Ordinal);
    TimeSpan pendingPosition;
    string[] playlist = Array.Empty<string>();
    int active = -1, pending = -1, clip = -1, pendingClip = -1, generation;
    bool suspended, disposed, blending, held;
    DateTime opening;
    internal string Game { get; private set; } = "";
    internal int Transitions { get; private set; }
    internal bool HasVideo => active >= 0;
    internal double Position => active < 0 ? 0 : players[active].Position.TotalSeconds;
    internal string CurrentFile => active < 0 ? "" : players[active].MediaPath ?? "";
    internal string LastError { get; private set; } = "";
    internal bool IsBlending => blending;

    internal BackgroundVideoPlayer(VideoSurface first, VideoSurface second, Action changed) {
        players = new[] { first, second };
        this.changed = changed;
        foreach (var player in players) {
            player.IsHitTestVisible = false;
            player.Focusable = false;
            player.MediaOpened += Opened;
            player.MediaEnded += Ended;
            player.MediaFailed += Failed;
        }
        timer.Tick += (_, _) => Tick();
        timer.Start();
    }
    internal void SetPlaylist(string game, string[] paths) {
        if (disposed || Game == game && playlist.SequenceEqual(paths, StringComparer.OrdinalIgnoreCase)) return;
        RememberPosition();
        Reset(); // release the previous edition immediately, including pending decoders
        Game = game;
        playlist = paths.ToArray();
        failed.Clear();
        LastError = "";
        if (!suspended) Next();
    }
    internal void Suspend(bool value) {
        if (disposed || suspended == value) return;
        suspended = value;
        if (value) { RememberPosition(); Reset(); }
        else Next();
    }
    // Pauses playback in place (for example while the window is moved or resized) without
    // releasing the decoders; Hold(false) continues from the same frame.
    internal void Hold(bool value) {
        if (disposed || held == value) return;
        held = value;
        foreach (var player in players) {
            if (player.MediaPath == null) continue;
            if (value) player.Pause(); else player.Play();
        }
        // Time spent held does not count towards the opening timeout.
        if (!value) opening = DateTime.UtcNow;
    }
    void RememberPosition() {
        if (active < 0 || Game.Length == 0 || players[active].MediaPath == null) return;
        bookmarks[Game] = new(players[active].MediaPath!, players[active].Position);
    }
    void Reset() {
        generation++;
        active = pending = clip = pendingClip = -1;
        blending = false;
        pendingPosition = TimeSpan.Zero;
        foreach (var player in players) Close(player);
        changed();
    }
    static void Close(VideoSurface player) {
        player.StopAnimation(Visual.OpacityProperty);
        player.Opacity = 0;
        player.Close();
    }
    void Next() {
        if (disposed || suspended || pending >= 0 || blending || playlist.Length == 0) return;
        int next = -1;
        pendingPosition = TimeSpan.Zero;
        if (active < 0 && bookmarks.TryGetValue(Game, out var saved)) {
            int savedClip = Array.FindIndex(playlist, path => string.Equals(path, saved.File, StringComparison.OrdinalIgnoreCase));
            if (savedClip >= 0 && !failed.Contains(savedClip)) {
                next = savedClip;
                pendingPosition = saved.Position;
            }
        }
        for (int i = 1; next < 0 && i <= playlist.Length; i++) {
            int candidate = (clip + i) % playlist.Length;
            if (!failed.Contains(candidate)) { next = candidate; break; }
        }
        if (next < 0) return;
        pending = active == 0 ? 1 : 0;
        pendingClip = next;
        var player = players[pending];
        Close(player);
        opening = DateTime.UtcNow;
        try {
            player.Open(playlist[next]);
            player.Play();
            if (held) player.Pause();
        } catch (Exception error) when (error is InvalidOperationException or ArgumentException or IOException) {
            Reject(player, error.Message);
        }
    }
    void Opened(object? sender, EventArgs e) {
        if (disposed || suspended || pending < 0 || !ReferenceEquals(sender, players[pending])) return;
        var incoming = players[pending];
        if (!incoming.HasVideo || incoming.NaturalDuration is not { } duration || duration.TotalSeconds < 1) {
            Reject(incoming, "The background clip has no playable video.");
            return;
        }
        if (pendingPosition > TimeSpan.Zero) {
            incoming.Position = TimeSpan.FromSeconds(Math.Clamp(pendingPosition.TotalSeconds, 0,
                duration.TotalSeconds - 0.1));
            pendingPosition = TimeSpan.Zero;
        }
        int previous = active, current = pending, ticket = generation;
        incoming.ZIndex = 2;
        if (previous >= 0) players[previous].ZIndex = 1;
        active = pending;
        clip = pendingClip;
        pending = pendingClip = -1;
        blending = true;
        // Keep the outgoing frame opaque beneath the incoming fade. Fading both
        // exposes the still image midway through every transition.
        incoming.Animate(Visual.OpacityProperty, 0, 1, TimeSpan.FromMilliseconds(800), completed: () => {
            if (generation != ticket || active != current) return;
            incoming.StopAnimation(Visual.OpacityProperty);
            incoming.Opacity = 1;
            if (previous >= 0) { Close(players[previous]); Transitions++; }
            blending = false;
            changed();
        });
        changed();
    }
    void Ended(object? sender, EventArgs e) {
        if (active >= 0 && ReferenceEquals(sender, players[active])) Next();
    }
    void Failed(object? sender, string message) {
        if (sender is VideoSurface player) Reject(player, message);
    }
    void Reject(VideoSurface player, string message) {
        int index = Array.IndexOf(players, player);
        if (index != active && index != pending) return;
        LastError = message;
        if (index == pending) { failed.Add(pendingClip); pending = pendingClip = -1; }
        if (index == active) { failed.Add(clip); Reset(); }
        Close(player);
        changed();
        // The timer tries another clip once; failed clips stay excluded for this playlist.
    }
    void Tick() {
        if (disposed || suspended || held) return;
        if (pending >= 0 && DateTime.UtcNow - opening > TimeSpan.FromSeconds(12))
            Reject(players[pending], "Opening the background video timed out.");
        if (active < 0) { Next(); return; }
        var player = players[active];
        if (player.NaturalDuration is { } duration &&
            duration - player.Position <= TimeSpan.FromSeconds(1.3)) Next();
    }
    public void Dispose() {
        if (disposed) return;
        disposed = true;
        timer.Stop();
        Reset();
        foreach (var player in players) {
            player.MediaOpened -= Opened;
            player.MediaEnded -= Ended;
            player.MediaFailed -= Failed;
        }
    }
}
