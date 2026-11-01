using Avalonia.Media.Imaging;
using Avalonia.VisualTree;
using System.Globalization;
using System.Numerics;
using Vector = Avalonia.Vector;

namespace Outbreak.Launcher.Desktop.Controls;

internal readonly record struct Point3D(double X,double Y,double Z) {
    internal Vector3 Vector=>new((float)X,(float)Y,(float)Z);
}
internal struct UnitVector(double x,double y) {
    internal double X=x,Y=y;
    internal void Normalize(){double length=Math.Sqrt(X*X+Y*Y);if(length>0){X/=length;Y/=length;}}
    public static UnitVector operator +(UnitVector a,UnitVector b)=>new(a.X+b.X,a.Y+b.Y);
}
internal sealed record SceneSurface(Color Color,IImage? Image=null,bool Glare=false,bool Back=false);
internal sealed record CaseMesh(Point3D[] Positions,Point[] Uv,int[] Indices,SceneSurface Surface,bool Specular);

// Port of RC1 GameCaseView.cs: the same keepcase, camera, lights, spotlight flicker, idle swing,
// drag/fling/return behavior and PS2-resolution rendering. RC1 draws it through WPF 3D into a
// bitmap cache; CaseRaster draws the identical scene into the same low-resolution bitmap.
public partial class GameCaseView : Control {
    public static readonly StyledProperty<int> EditionProperty = AvaloniaProperty.Register<GameCaseView, int>(nameof(Edition), 1);
    public static readonly StyledProperty<bool> IsAvailableProperty = AvaloniaProperty.Register<GameCaseView, bool>(nameof(IsAvailable));
    public static readonly StyledProperty<bool> IsSelectedProperty = AvaloniaProperty.Register<GameCaseView, bool>(nameof(IsSelected));
    public static readonly StyledProperty<double> SpotlightLevelProperty = AvaloniaProperty.Register<GameCaseView, double>(nameof(SpotlightLevel));
    public static readonly StyledProperty<IImage?> CoverProperty = AvaloniaProperty.Register<GameCaseView, IImage?>(nameof(Cover));
    public static readonly StyledProperty<IImage?> BackCoverProperty = AvaloniaProperty.Register<GameCaseView, IImage?>(nameof(BackCover));
    public static readonly StyledProperty<IImage?> SpineCoverProperty = AvaloniaProperty.Register<GameCaseView, IImage?>(nameof(SpineCover));
    public int Edition { get => GetValue(EditionProperty); set => SetValue(EditionProperty, value); }
    public bool IsAvailable { get => GetValue(IsAvailableProperty); set => SetValue(IsAvailableProperty, value); }
    public bool IsSelected { get => GetValue(IsSelectedProperty); set => SetValue(IsSelectedProperty, value); }
    // Shared with the beam and cast shadow so every part flickers together.
    public double SpotlightLevel { get => GetValue(SpotlightLevelProperty); private set => SetValue(SpotlightLevelProperty, value); }
    public IImage? Cover { get => GetValue(CoverProperty); set => SetValue(CoverProperty, value); }
    public IImage? BackCover { get => GetValue(BackCoverProperty); set => SetValue(BackCoverProperty, value); }
    public IImage? SpineCover { get => GetValue(SpineCoverProperty); set => SetValue(SpineCoverProperty, value); }

    readonly List<CaseMesh> meshes = [];
    readonly Dictionary<(IImage, bool), IImage> textures = [];
    readonly SceneSurface frontGlare = new(Colors.White, null, true), backGlare = new(Colors.White, null, true, true);
    // RC1 AxisAngleRotation3D turn (Y, 24°) and tilt (X, -5°).
    double turn = 24, tilt = -5;
    readonly DispatcherTimer idleReturnTimer = new() { Interval = TimeSpan.FromSeconds(4) };
    readonly DispatcherTimer frames = new(DispatcherPriority.Render) { Interval = TimeSpan.FromMilliseconds(16) };
    Window? owner;
    bool held, animated, dragging, manuallyRotated, returning, coasting;
    int motionEpoch, lightingEpoch;
    Point dragOrigin;
    double dragYaw, dragPitch;
    Point lastDragPoint;
    long lastDragStamp;
    Vector dragVelocity;

    // A WPF DoubleAnimation subset: From/To, duration, easing, AutoReverse, RepeatBehavior.Forever.
    sealed class Tween {
        public required double From, To;
        public required TimeSpan Duration;
        public Func<double, double> Ease = t => t;
        public bool AutoReverse, Forever;
        public Func<double, double>? Frames; // keyframe track sampled in seconds
        public double FrameRate; // Timeline.DesiredFrameRate; 0 = every frame
        public Action? Completed;
        public long Started = Stopwatch.GetTimestamp();
        public double Sample(out bool done) {
            double elapsed = Stopwatch.GetElapsedTime(Started).TotalSeconds, length = Duration.TotalSeconds;
            if (FrameRate > 0) elapsed = Math.Floor(elapsed * FrameRate) / FrameRate;
            double cycle = AutoReverse ? 2 * length : length;
            done = !Forever && elapsed >= cycle;
            double time = Forever ? elapsed % cycle : Math.Min(elapsed, cycle);
            if (Frames != null) return Frames(time);
            double t = length <= 0 ? 1 : time <= length ? time / length : 2 - time / length;
            if (done) t = AutoReverse ? 0 : 1;
            return From + (To - From) * Ease(Math.Clamp(t, 0, 1));
        }
    }
    Tween? turnMotion, tiltMotion, lightMotion;

    public GameCaseView() {
        Cursor = new Cursor(StandardCursorType.Arrow);
        Avalonia.Automation.AutomationProperties.SetHelpText(this,
            "Drag to inspect, or fling to spin. It returns to idle after slowing down and a short pause. Double-click to reset.");
        // Hard polygon edges at roughly PS2 output resolution, enlarged without smoothing.
        RenderOptions.SetBitmapInterpolationMode(this, BitmapInterpolationMode.None);
        frames.Tick += (_, _) => Step();
        AttachedToVisualTree += (_, _) => {
            owner = TopLevel.GetTopLevel(this) as Window;
            if (owner != null) {
                owner.PropertyChanged += OwnerChanged;
                owner.Deactivated += WindowDeactivated;
            }
            UpdateLighting();
            UpdateMotion();
        };
        DetachedFromVisualTree += (_, _) => {
            if (owner != null) {
                owner.PropertyChanged -= OwnerChanged;
                owner.Deactivated -= WindowDeactivated;
            }
            CancelDrag(null);
            owner = null;
            idleReturnTimer.Stop();
            UpdateSpotlightMotion();
            StopMotion();
        };
        AddHandler(PointerPressedEvent, BeginDrag, RoutingStrategies.Tunnel);
        AddHandler(PointerMovedEvent, Drag, RoutingStrategies.Tunnel);
        AddHandler(PointerReleasedEvent, EndDrag, RoutingStrategies.Tunnel);
        PointerCaptureLost += (_, _) => {
            if (dragging) {
                CancelDrag(null);
                UpdateMotion();
            }
        };
        idleReturnTimer.Tick += (_, _) => ReturnToIdle();
        RefreshAppearance();
    }
    bool Visible => IsLoaded && IsEffectivelyVisible && IsEffectivelyEnabled && owner?.WindowState != WindowState.Minimized;
    protected override void OnPropertyChanged(AvaloniaPropertyChangedEventArgs change) {
        base.OnPropertyChanged(change);
        if (change.Property == CoverProperty || change.Property == BackCoverProperty || change.Property == SpineCoverProperty ||
            change.Property == IsAvailableProperty || change.Property == EditionProperty)
            RefreshAppearance();
        if (change.Property == IsEnabledProperty || change.Property == IsEffectivelyEnabledProperty) { UpdateSpotlightMotion(); RefreshAppearance(); }
        if (change.Property == IsSelectedProperty) UpdateLighting();
        if (change.Property == IsVisibleProperty) { UpdateSpotlightMotion(); UpdateMotion(); }
        if (change.Property == SpotlightLevelProperty) InvalidateVisual();
    }
    void OwnerChanged(object? sender, AvaloniaPropertyChangedEventArgs e) {
        if (e.Property == Window.WindowStateProperty) { UpdateSpotlightMotion(); UpdateMotion(); }
        if (e.Property == BoundsProperty) InvalidateVisual();
    }
    void WindowDeactivated(object? sender, EventArgs e) {
        CancelDrag(null);
        UpdateMotion();
    }
    // Holds the case still with a steady light, e.g. while the window is moved or resized, so
    // the cached case is not redrawn every frame; animation resumes from the held pose.
    internal void Hold(bool value) {
        if (held == value)
            return;
        held = value;
        UpdateSpotlightMotion();
        UpdateMotion();
    }
    void UpdateLighting() => UpdateSpotlightMotion();
    void UpdateSpotlightMotion() {
        int epoch = ++lightingEpoch;
        double current = SpotlightLevel;
        lightMotion = null;
        double target = IsSelected ? 1 : 0;
        SpotlightLevel = target;
        if (held || !Visible || !SystemParameters.ClientAreaAnimation)
            return;
        if (!IsSelected) {
            // FillBehavior.Stop: the level returns to its base value, 0, when the fade ends.
            lightMotion = new() { From = current, To = 0, Duration = TimeSpan.FromMilliseconds(220) };
            Animate();
            return;
        }
        // Short, irregular flicker bursts separated by steady light.
        var flicker = new Tween { From = 1, To = 1, Duration = TimeSpan.FromSeconds(12), Forever = true, Frames = Flicker, FrameRate = 30 };
        lightMotion = new() { From = current, To = 1, Duration = TimeSpan.FromMilliseconds(280), Completed = () => {
            if (lightingEpoch == epoch) { flicker.Started = Stopwatch.GetTimestamp(); lightMotion = flicker; }
        } };
        Animate();
    }
    static readonly (double Time, double Level)[] FlickerFrames = {
        (0, 1), (1.4, 1), (1.46, .24), (1.52, 1), (1.61, .38), (1.67, .96), (1.8, .22), (1.88, 1),
        (4.2, 1), (4.27, .3), (4.34, 1), (4.44, .45), (4.52, 1),
        (7.1, 1), (7.17, .22), (7.27, .22), (7.34, 1), (7.44, .36), (7.51, .98), (7.64, .25), (7.72, 1),
        (10.1, 1), (10.23, .5), (10.48, 1), (12, 1) };
    static double Flicker(double time) {
        for (int i = 1; i < FlickerFrames.Length; i++)
            if (time <= FlickerFrames[i].Time)
                return FlickerFrames[i - 1].Level + (FlickerFrames[i].Level - FlickerFrames[i - 1].Level) *
                       (time - FlickerFrames[i - 1].Time) / (FlickerFrames[i].Time - FlickerFrames[i - 1].Time);
        return 1;
    }
    void Animate() { if (!frames.IsEnabled) frames.Start(); Step(); }
    void Step() {
        if (!Visible) { RefreshVisibility(); frames.Stop(); return; }
        bool changed = false;
        // Only redraw when the pose changes; idle motion samples at 30 frames per second.
        if (turnMotion is { } spin) {
            double next = spin.Sample(out bool done); changed |= next != turn; turn = next;
            if (done && ReferenceEquals(turnMotion, spin)) { turnMotion = null; spin.Completed?.Invoke(); }
        }
        if (tiltMotion is { } pitch) {
            double next = pitch.Sample(out bool done); changed |= next != tilt; tilt = next;
            if (done && ReferenceEquals(tiltMotion, pitch)) { tiltMotion = null; pitch.Completed?.Invoke(); }
        }
        if (lightMotion is { } light) {
            double level = light.Sample(out bool done);
            if (done && ReferenceEquals(lightMotion, light)) {
                lightMotion = null;
                level = IsSelected ? 1 : 0;
                light.Completed?.Invoke();
            }
            if (lightMotion != null || light.Completed == null) SetValue(SpotlightLevelProperty, level);
        }
        if (changed) InvalidateVisual();
        if (turnMotion == null && tiltMotion == null && lightMotion == null) frames.Stop();
    }
    void BeginDrag(object? sender, PointerPressedEventArgs e) {
        if (!e.GetCurrentPoint(this).Properties.IsLeftButtonPressed) return;
        // Keep the normal game-selection behavior when the artwork is clicked.
        if (this.GetVisualAncestors().OfType<ListBoxItem>().FirstOrDefault() is { } item) {
            item.SetCurrentValue(ListBoxItem.IsSelectedProperty, true);
            item.Focus();
        }
        e.Handled = true;
        idleReturnTimer.Stop();
        if (e.ClickCount == 2) {
            CancelDrag(e.Pointer);
            manuallyRotated = false;
            StopMotion();
            turn = Edition == 2 ? 18 : 26;
            tilt = -5;
            InvalidateVisual();
            UpdateMotion();
            return;
        }
        StopMotion();
        dragOrigin = e.GetPosition(this);
        lastDragPoint = dragOrigin;
        lastDragStamp = Stopwatch.GetTimestamp();
        dragVelocity = default;
        dragYaw = turn;
        dragPitch = tilt;
        e.Pointer.Capture(this);
        dragging = e.Pointer.Captured == this;
        if (!dragging)
            UpdateMotion();
    }
    void Drag(object? sender, PointerEventArgs e) {
        if (!dragging)
            return;
        if (!e.GetCurrentPoint(this).Properties.IsLeftButtonPressed) {
            CancelDrag(e.Pointer);
            UpdateMotion();
            return;
        }
        Point position = e.GetPosition(this);
        TrackDragVelocity(position);
        Vector delta = position - dragOrigin;
        // SystemParameters.MinimumHorizontal/VerticalDragDistance.
        if (!manuallyRotated && Math.Abs(delta.X) < 4 && Math.Abs(delta.Y) < 4)
            return;
        manuallyRotated = true;
        turn = (dragYaw + delta.X * 1.2) % 360;
        tilt = Math.Clamp(dragPitch - delta.Y * 0.6, -45, 45);
        InvalidateVisual();
        e.Handled = true;
    }
    void EndDrag(object? sender, PointerReleasedEventArgs e) {
        if (!dragging)
            return;
        Vector velocity = ReleaseVelocity();
        CancelDrag(e.Pointer);
        if (!StartCoasting(velocity))
            UpdateMotion();
        e.Handled = true;
    }
    void CancelDrag(IPointer? pointer) {
        bool wasDragging = dragging;
        dragging = false;
        dragVelocity = default;
        lastDragStamp = 0;
        if (wasDragging && pointer?.Captured == this) pointer.Capture(null);
    }
    void TrackDragVelocity(Point position) {
        if (position == lastDragPoint)
            return;
        long now = Stopwatch.GetTimestamp();
        double seconds = (now - lastDragStamp) / (double)Stopwatch.Frequency;
        if (lastDragStamp != 0 && seconds > 0) {
            Vector distance = position - lastDragPoint;
            var sample = new Vector(distance.X * 1.2 / seconds, -distance.Y * 0.6 / seconds);
            double blend = 1 - Math.Exp(-seconds / 0.035);
            dragVelocity += (sample - dragVelocity) * blend;
        }
        lastDragPoint = position;
        lastDragStamp = now;
    }
    Vector ReleaseVelocity() {
        // Holding the case still before releasing must not fling it using an old sample.
        if (!manuallyRotated || lastDragStamp == 0 ||
            Stopwatch.GetElapsedTime(lastDragStamp).TotalSeconds > 0.12)
            return default;
        return new Vector(Math.Clamp(dragVelocity.X, -1800, 1800),
                          Math.Clamp(dragVelocity.Y, -600, 600));
    }
    // WPF ExponentialEase EaseOut.
    static Func<double, double> ExponentialOut(double exponent) => t =>
        1 - (Math.Exp(exponent * (1 - t)) - 1) / (Math.Exp(exponent) - 1);
    static double SineInOut(double t) => (1 - Math.Cos(Math.PI * t)) / 2;
    static double CubicInOut(double t) => t < .5 ? 4 * t * t * t : 1 - Math.Pow(2 - 2 * t, 3) / 2;
    bool StartCoasting(Vector velocity) {
        if ((tilt >= 45 && velocity.Y > 0) || (tilt <= -45 && velocity.Y < 0))
            velocity = velocity.WithY(0);
        if (velocity.Length < 70 || !Visible || !SystemParameters.ClientAreaAnimation)
            return false;
        StopMotion();
        idleReturnTimer.Stop();
        manuallyRotated = coasting = true;
        int epoch = motionEpoch;
        const double friction = 2.4;
        double seconds = Math.Min(3, Math.Log(velocity.Length / 8) / friction);
        double travel = (1 - Math.Exp(-friction * seconds)) / friction;
        var duration = TimeSpan.FromSeconds(seconds);
        var easing = ExponentialOut(friction * seconds);
        tiltMotion = new() { From = tilt, To = Math.Clamp(tilt + velocity.Y * travel, -45, 45), Duration = duration, Ease = easing };
        turnMotion = new() { From = turn, To = turn + velocity.X * travel, Duration = duration, Ease = easing, Completed = () => {
            if (epoch != motionEpoch || dragging)
                return;
            StopMotion();
            // Normalize only after the spin; this keeps multiple turns continuous.
            turn = (turn % 360 + 360) % 360;
            UpdateMotion();
        } };
        Animate();
        return true;
    }
    void StopMotion() {
        turnMotion = tiltMotion = null;
        animated = false;
        returning = false;
        coasting = false;
        ++motionEpoch;
    }
    void UpdateMotion() {
        if (!Visible || held) {
            CancelDrag(null);
            idleReturnTimer.Stop();
            StopMotion();
            return;
        }
        if (dragging)
            return;
        if (coasting) {
            if (SystemParameters.ClientAreaAnimation)
                return;
            StopMotion();
        }
        if (manuallyRotated) {
            if (returning && !SystemParameters.ClientAreaAnimation) {
                ReturnToIdle();
                return;
            }
            if (!returning && !idleReturnTimer.IsEnabled)
                idleReturnTimer.Start();
            return;
        }
        if (!IsAvailable || !SystemParameters.ClientAreaAnimation) {
            StopMotion();
            return;
        }
        if (animated)
            return;
        animated = true;
        double lower = Edition == 2 ? 18 : -4;
        double upper = lower + 30;
        // Resume toward the farther end, including after a pause at an endpoint.
        // Reusing one fixed destination could create a zero-distance loop forever.
        double destination = Math.Abs(turn - lower) >= Math.Abs(turn - upper) ? lower : upper;
        turnMotion = new() { From = turn, To = destination, Duration = TimeSpan.FromSeconds(4),
            AutoReverse = true, Forever = true, Ease = SineInOut, FrameRate = 30 };
        Animate();
    }
    void ReturnToIdle() {
        idleReturnTimer.Stop();
        if (dragging || !Visible)
            return;
        StopMotion();
        double home = Edition == 2 ? 18 : 26;
        if (!SystemParameters.ClientAreaAnimation) {
            turn = home;
            tilt = -5;
            manuallyRotated = false;
            InvalidateVisual();
            return;
        }
        // Return by the shortest arc instead of unwinding a complete revolution.
        double normalized = (turn % 360 + 360) % 360;
        double target = turn + (home - normalized + 540) % 360 - 180;
        int epoch = motionEpoch;
        returning = true;
        var duration = TimeSpan.FromMilliseconds(850);
        tiltMotion = new() { From = tilt, To = -5, Duration = duration, Ease = CubicInOut };
        turnMotion = new() { From = turn, To = target, Duration = duration, Ease = CubicInOut, Completed = () => {
            if (epoch != motionEpoch || dragging)
                return;
            tiltMotion = null;
            turn = home;
            tilt = -5;
            returning = false;
            manuallyRotated = false;
            InvalidateVisual();
            UpdateMotion();
        } };
        Animate();
    }
    static SceneSurface Surface(Rgba color) => new(Color.FromArgb(color.A, color.R, color.G, color.B));
    SceneSurface Artwork(IImage? image, bool available, bool isSpine = false) {
        if (image == null) {
            // The placeholder is drawn, not a photo: RC1 does not quantize or grey it.
            var fallback = Fallback(isSpine, available);
            return new(Colors.White, fallback);
        }
        if (!textures.TryGetValue((image, available), out var texture)) {
            texture = ArtworkLoader.Ps2Texture(image, available);
            textures[(image, available)] = texture;
        }
        return new(Colors.White, texture);
    }
    IImage Fallback(bool spine, bool available) {
        int width = spine ? 36 : 256, height = 360;
        var bitmap = new RenderTargetBitmap(new PixelSize(width, height), new Vector(96, 96));
        // RC1 draws the placeholder into a DrawingBrush: greyscale text antialiasing, no ClearType.
        using (var dc = bitmap.CreateDrawingContext())
        using (dc.PushRenderOptions(new RenderOptions { TextRenderingMode = TextRenderingMode.Antialias })) {
            dc.DrawRectangle(VisualPalette.Brush(Palette.SoftBlack), null, new Rect(0, 0, width, height));
            dc.DrawRectangle(VisualPalette.Brush(available ? Palette.BurntOrange : Palette.WarmIvoryMuted), null, new Rect(0, 0, width, 6));
            var text = new FormattedText(spine ? $"OUTBREAK   /   FILE #{Edition}" : $"OUTBREAK\nFILE #{Edition}",
                CultureInfo.InvariantCulture, FlowDirection.LeftToRight,
                new Typeface(OperatingSystem.IsWindows() ? "Segoe UI" : "Segoe UI, Helvetica Neue, DejaVu Sans"),
                spine ? 18 : 30, VisualPalette.Brush(Palette.WarmIvory)) { TextAlignment = TextAlignment.Center };
            // WPF centers TextAlignment.Center text on the origin's x coordinate.
            if (spine) {
                using (dc.PushTransform(Matrix.CreateRotation(Math.PI / 2) * Matrix.CreateTranslation(width / 2.0, height / 2.0)))
                    dc.DrawText(text, new Point(-text.Width / 2, -text.Height / 2));
            } else
                dc.DrawText(text, new Point(width / 2.0 - text.Width / 2, height / 2.0 - text.Height / 2));
        }
        return bitmap;
    }
    public override void Render(DrawingContext dc) {
        base.Render(dc);
        RenderCase(dc);
    }
    // RC1 reacts to IsVisibleChanged, which includes a hidden ancestor (another page shown).
    bool shownBefore;
    internal void RefreshVisibility() {
        if (shownBefore == Visible) return;
        shownBefore = Visible;
        UpdateSpotlightMotion();
        UpdateMotion();
    }
}
