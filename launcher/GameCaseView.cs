using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Threading;

namespace Outbreak.Launcher;

// A small native 3D case; cover images remain optional and user-local.
public sealed class GameCaseView : Grid {
    public static readonly DependencyProperty CoverProperty = DependencyProperty.Register(
        nameof(Cover), typeof(BitmapSource), typeof(GameCaseView),
        new PropertyMetadata(null, AppearanceChanged));
    public static readonly DependencyProperty EditionProperty = DependencyProperty.Register(
        nameof(Edition), typeof(int), typeof(GameCaseView),
        new PropertyMetadata(1, AppearanceChanged));
    public static readonly DependencyProperty BackCoverProperty = DependencyProperty.Register(
        nameof(BackCover), typeof(BitmapSource), typeof(GameCaseView),
        new PropertyMetadata(null, AppearanceChanged));
    public static readonly DependencyProperty SpineCoverProperty = DependencyProperty.Register(
        nameof(SpineCover), typeof(BitmapSource), typeof(GameCaseView),
        new PropertyMetadata(null, AppearanceChanged));
    public static readonly DependencyProperty IsAvailableProperty = DependencyProperty.Register(
        nameof(IsAvailable), typeof(bool), typeof(GameCaseView),
        new PropertyMetadata(false, AppearanceChanged));
    public static readonly DependencyProperty IsSelectedProperty = DependencyProperty.Register(
        nameof(IsSelected), typeof(bool), typeof(GameCaseView),
        new PropertyMetadata(false, (target, _) => ((GameCaseView)target).UpdateLighting()));
    public static readonly DependencyProperty SpotlightLevelProperty = DependencyProperty.Register(
        nameof(SpotlightLevel), typeof(double), typeof(GameCaseView),
        new PropertyMetadata(0d, (target, _) => ((GameCaseView)target).ApplySpotlight()));
    // Shared with the beam and cast shadow so every part flickers together.
    public double SpotlightLevel => (double)GetValue(SpotlightLevelProperty);
    public BitmapSource? Cover {
        get => (BitmapSource?)GetValue(CoverProperty);
        set => SetValue(CoverProperty, value);
    }
    public int Edition {
        get => (int)GetValue(EditionProperty);
        set => SetValue(EditionProperty, value);
    }
    public BitmapSource? BackCover {
        get => (BitmapSource?)GetValue(BackCoverProperty);
        set => SetValue(BackCoverProperty, value);
    }
    public BitmapSource? SpineCover {
        get => (BitmapSource?)GetValue(SpineCoverProperty);
        set => SetValue(SpineCoverProperty, value);
    }
    public bool IsAvailable {
        get => (bool)GetValue(IsAvailableProperty);
        set => SetValue(IsAvailableProperty, value);
    }
    public bool IsSelected {
        get => (bool)GetValue(IsSelectedProperty);
        set => SetValue(IsSelectedProperty, value);
    }
    readonly Model3DGroup model = new();
    readonly AxisAngleRotation3D turn = new(new Vector3D(0, 1, 0), 24);
    readonly AxisAngleRotation3D tilt = new(new Vector3D(1, 0, 0), -5);
    readonly PerspectiveCamera camera = new(new Point3D(0, 0.02, 4.4),
        new Vector3D(0, 0, -1), new Vector3D(0, 1, 0), 34);
    readonly AmbientLight ambient = new(Palette.Scale(Palette.WarmIvory, 0.11));
    readonly DirectionalLight fill = new(Palette.Scale(Palette.WarmIvory, 0.08), new Vector3D(-1, -0.4, -2));
    readonly SpotLight lamp = new() {
        Color = Colors.Black, Position = new Point3D(0, 5, 4),
        Direction = new Vector3D(0, -5, -4), InnerConeAngle = 14, OuterConeAngle = 26,
        Range = 12, ConstantAttenuation = 1
    };
    readonly DispatcherTimer idleReturnTimer = new() { Interval = TimeSpan.FromSeconds(4) };
    readonly Canvas floorLayer = new() { IsHitTestVisible = false };
    readonly System.Windows.Shapes.Path shadow = new() {
        Opacity = 0, IsHitTestVisible = false,
        // Shadows are black: soft black is the window colour and could not darken it.
        Fill = new LinearGradientBrush(Color.FromArgb(0, 0, 0, 0), Color.FromArgb(190, 0, 0, 0), 90),
        Effect = new System.Windows.Media.Effects.BlurEffect { Radius = 5 }
    };
    // Where the spotlight beam from above lands on the floor. A shadow needs light around it
    // to show against the near-black room.
    readonly System.Windows.Shapes.Ellipse pool = new() {
        Opacity = 0, IsHitTestVisible = false,
        Fill = new RadialGradientBrush(Palette.WithAlpha(Palette.WarmIvory, 72), Palette.WithAlpha(Palette.WarmIvory, 0)),
        Effect = new System.Windows.Media.Effects.BlurEffect { Radius = 10 }
    };
    // Glare on the clear sleeve over each cover: the lamp's round reflection in ivory light,
    // updated as the case turns.
    readonly RadialGradientBrush frontGlare = GlareBrush(), backGlare = GlareBrush();
    static RadialGradientBrush GlareBrush() {
        var brush = new RadialGradientBrush();
        foreach (double offset in new[] { 0, 0.3, 0.65, 1.0 })
            brush.GradientStops.Add(new GradientStop(Palette.WithAlpha(Palette.WarmIvory, 0), offset));
        return brush;
    }
    // A soft dark patch where the case meets the floor. The lamp's cast shadow falls behind the
    // case, where the nearly level camera barely sees it.
    readonly System.Windows.Shapes.Ellipse contact = new() {
        Opacity = 0.45, IsHitTestVisible = false,
        Fill = new RadialGradientBrush(Color.FromArgb(240, 0, 0, 0), Color.FromArgb(0, 0, 0, 0)),
        Effect = new System.Windows.Media.Effects.BlurEffect { Radius = 8 }
    };
    Window? owner;
    bool held, animated, dragging, manuallyRotated, returning, coasting;
    int motionEpoch;
    int lightingEpoch;
    Point dragOrigin;
    double dragYaw, dragPitch;
    Point lastDragPoint;
    long lastDragStamp;
    Vector dragVelocity;

    public GameCaseView() {
        Background = Brushes.Transparent;
        Cursor = Cursors.Arrow;
        System.Windows.Automation.AutomationProperties.SetHelpText(this,
            "Drag to inspect, or fling to spin. It returns to idle after slowing down and a short pause. Double-click to reset.");
        var viewport = new Viewport3D { Camera = camera };
        // Draw the case (and its shadow) at roughly PS2 output resolution with hard polygon
        // edges, then enlarge it without smoothing; UpdateFraming sets the scale.
        RenderOptions.SetEdgeMode(viewport, EdgeMode.Aliased);
        RenderOptions.SetBitmapScalingMode(this, BitmapScalingMode.NearestNeighbor);
        CacheMode = new BitmapCache();
        var transforms = new Transform3DGroup();
        transforms.Children.Add(new RotateTransform3D(tilt));
        transforms.Children.Add(new RotateTransform3D(turn));
        model.Transform = transforms;
        var scene = new Model3DGroup();
        scene.Children.Add(ambient);
        scene.Children.Add(fill);
        scene.Children.Add(lamp);
        scene.Children.Add(model);
        viewport.Children.Add(new ModelVisual3D { Content = scene });
        // The pool and contact patch only change size when the framing does, so their blurs are
        // cached; flicker changes their opacity, which is applied to the cached bitmap.
        pool.CacheMode = new BitmapCache();
        contact.CacheMode = new BitmapCache();
        floorLayer.Children.Add(pool);
        floorLayer.Children.Add(contact);
        floorLayer.Children.Add(shadow);
        Children.Add(floorLayer);
        Children.Add(viewport);
        turn.Changed += (_, _) => { UpdateShadow(); UpdateGlare(); };
        tilt.Changed += (_, _) => { UpdateShadow(); UpdateGlare(); };
        Loaded += (_, _) => {
            owner = Window.GetWindow(this);
            if (owner != null) {
                owner.StateChanged += WindowStateChanged;
                owner.Deactivated += WindowDeactivated;
            }
            SystemParameters.StaticPropertyChanged += SystemSettingChanged;
            UpdateFraming();
            UpdateLighting();
            UpdateMotion();
        };
        Unloaded += (_, _) => {
            if (owner != null) {
                owner.StateChanged -= WindowStateChanged;
                owner.Deactivated -= WindowDeactivated;
            }
            CancelDrag();
            owner = null;
            SystemParameters.StaticPropertyChanged -= SystemSettingChanged;
            idleReturnTimer.Stop();
            UpdateSpotlightMotion();
            StopMotion();
        };
        IsVisibleChanged += (_, _) => { UpdateSpotlightMotion(); UpdateMotion(); };
        IsEnabledChanged += (_, _) => { UpdateSpotlightMotion(); RefreshAppearance(); };
        PreviewMouseLeftButtonDown += BeginDrag;
        PreviewMouseMove += Drag;
        PreviewMouseLeftButtonUp += EndDrag;
        LostMouseCapture += (_, _) => {
            if (dragging && !IsMouseCaptured) {
                CancelDrag();
                UpdateMotion();
            }
        };
        SizeChanged += (_, _) => UpdateFraming();
        idleReturnTimer.Tick += (_, _) => ReturnToIdle();
        RefreshAppearance();
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
    void ApplySpotlight() {
        double level = Math.Clamp(SpotlightLevel, 0, 1);
        // All three lights are warm ivory at different strengths.
        ambient.Color = Palette.Scale(Palette.WarmIvory, 0.11 + 0.26 * level);
        fill.Color = Palette.Scale(Palette.WarmIvory, 0.08 + 0.11 * level);
        lamp.Color = Palette.Scale(Palette.WarmIvory, level);
        shadow.Opacity = level;
        // Always faintly grounded; darker under the spotlight.
        contact.Opacity = 0.45 + 0.55 * level;
        pool.Opacity = level;
        UpdateGlare();
    }
    void UpdateSpotlightMotion() {
        int epoch = ++lightingEpoch;
        double current = SpotlightLevel;
        BeginAnimation(SpotlightLevelProperty, null);
        double target = IsSelected ? 1 : 0;
        SetValue(SpotlightLevelProperty, target);
        if (held || !IsLoaded || !IsVisible || !IsEnabled || owner?.WindowState == WindowState.Minimized ||
            !SystemParameters.ClientAreaAnimation)
            return;
        if (!IsSelected) {
            BeginAnimation(SpotlightLevelProperty, new DoubleAnimation(current, 0,
                TimeSpan.FromMilliseconds(220)) { FillBehavior = FillBehavior.Stop });
            return;
        }
        // Short, irregular flicker bursts separated by steady light.
        var flicker = new DoubleAnimationUsingKeyFrames { RepeatBehavior = RepeatBehavior.Forever };
        Timeline.SetDesiredFrameRate(flicker, 30);
        foreach (var frame in new[] { (0d, 1d), (1.4, 1d), (1.46, .24), (1.52, 1d),
                     (1.61, .38), (1.67, .96), (1.8, .22), (1.88, 1d),
                     (4.2, 1d), (4.27, .3), (4.34, 1d), (4.44, .45), (4.52, 1d),
                     (7.1, 1d), (7.17, .22), (7.27, .22), (7.34, 1d),
                     (7.44, .36), (7.51, .98), (7.64, .25), (7.72, 1d),
                     (10.1, 1d), (10.23, .5), (10.48, 1d), (12d, 1d) })
            flicker.KeyFrames.Add(new LinearDoubleKeyFrame(frame.Item2, KeyTime.FromTimeSpan(TimeSpan.FromSeconds(frame.Item1))));
        var fade = new DoubleAnimation(current, 1, TimeSpan.FromMilliseconds(280));
        fade.Completed += (_, _) => {
            if (lightingEpoch == epoch)
                BeginAnimation(SpotlightLevelProperty, flicker);
        };
        BeginAnimation(SpotlightLevelProperty, fade);
    }
    void UpdateFraming() {
        if (ActualWidth <= 0 || ActualHeight <= 0)
            return;
        // Enclose the whole case in a sphere, then fit that sphere to the tighter
        // camera angle. This remains safe at every yaw/pitch, even in a narrow tile.
        const double radius = 1.169;
        double horizontal = camera.FieldOfView * Math.PI / 360;
        double vertical = Math.Atan(Math.Tan(horizontal) * ActualHeight / ActualWidth);
        double distance = radius / Math.Sin(Math.Min(horizontal, vertical)) * 1.08;
        camera.Position = new Point3D(0, 0.02, distance);
        // About 720 lines for the whole window: just above a 480p PS2 frame, pixels still visible.
        double windowHeight = owner?.ActualHeight > 0 ? owner.ActualHeight : ActualHeight * 2.5;
        if (CacheMode is BitmapCache cache)
            cache.RenderAtScale = Math.Clamp(720 / windowHeight, 0.15, 1);
        UpdateShadow();
        UpdateGlare();
    }
    void UpdateShadow() {
        if (ActualWidth <= 0 || ActualHeight <= 0)
            return;
        // Cast the transformed case's eight corners onto a ground plane using
        // the actual lamp position, then view that silhouette through the case camera.
        var corners = (from x in new[] { -0.675, 0.675 }
                       from y in new[] { -0.95, 0.95 }
                       from z in new[] { -0.07, 0.07 }
                       select model.Transform.Transform(new Point3D(x, y, z))).ToArray();
        // Keep the floor fixed in world space. Following the lowest rotated corner
        // made the light pool rise and fall when the case was tilted.
        const double ground = -0.97;
        double focal = ActualWidth / (2 * Math.Tan(camera.FieldOfView * Math.PI / 360));
        Point Project(Point3D point) => new(
            ActualWidth / 2 + (point.X - camera.Position.X) * focal / (camera.Position.Z - point.Z),
            ActualHeight / 2 - (point.Y - camera.Position.Y) * focal / (camera.Position.Z - point.Z));
        // The floor light and contact shadow are fixed to the floor beneath the case, sized from
        // the case's resting width, so they stay put while the case turns.
        Point floor = Project(new Point3D(0, ground, 0));
        double width = Project(new Point3D(0.675, ground, 0)).X - Project(new Point3D(-0.675, ground, 0)).X;
        contact.Width = width * 1.1;
        contact.Height = Math.Max(10, width * 0.18);
        Canvas.SetLeft(contact, floor.X - contact.Width / 2);
        Canvas.SetTop(contact, floor.Y - contact.Height / 2);
        pool.Width = width * 2.2;
        pool.Height = width * 0.5;
        Canvas.SetLeft(pool, floor.X - pool.Width / 2);
        Canvas.SetTop(pool, floor.Y - pool.Height / 2);
        var lampPosition = lamp.Position;
        var projected = corners.Select(point => {
            double ray = (ground - lampPosition.Y) / (point.Y - lampPosition.Y);
            return Project(lampPosition + (point - lampPosition) * ray);
        }).OrderBy(point => point.X).ThenBy(point => point.Y).ToArray();
        // Convex hull avoids overlapping faces and self-intersections at every yaw.
        static double Cross(Point a, Point b, Point c) => Vector.CrossProduct(b - a, c - a);
        var hull = new List<Point>();
        foreach (var point in projected) {
            while (hull.Count >= 2 && Cross(hull[^2], hull[^1], point) <= 0)
                hull.RemoveAt(hull.Count - 1);
            hull.Add(point);
        }
        int lower = hull.Count;
        foreach (var point in projected.Reverse().Skip(1)) {
            while (hull.Count > lower && Cross(hull[^2], hull[^1], point) <= 0)
                hull.RemoveAt(hull.Count - 1);
            hull.Add(point);
        }
        if (hull.Count > 1)
            hull.RemoveAt(hull.Count - 1);
        static StreamGeometry Polygon(IEnumerable<Point> points) {
            var geometry = new StreamGeometry();
            var vertices = points.ToArray();
            if (vertices.Length >= 3) {
                using var context = geometry.Open();
                context.BeginFigure(vertices[0], true, true);
                context.PolyLineTo(vertices.Skip(1).ToArray(), true, false);
            }
            geometry.Freeze();
            return geometry;
        }
        shadow.Data = Polygon(hull);
    }
    void BeginDrag(object sender, MouseButtonEventArgs e) {
        // Keep the normal game-selection behavior when the artwork is clicked.
        for (DependencyObject? parent = VisualTreeHelper.GetParent(this); parent != null;
             parent = VisualTreeHelper.GetParent(parent)) {
            if (parent is not ListBoxItem item)
                continue;
            item.SetCurrentValue(ListBoxItem.IsSelectedProperty, true);
            item.Focus();
            break;
        }
        e.Handled = true;
        idleReturnTimer.Stop();
        if (e.ClickCount == 2) {
            CancelDrag();
            manuallyRotated = false;
            StopMotion();
            turn.Angle = Edition == 2 ? 18 : 26;
            tilt.Angle = -5;
            UpdateMotion();
            return;
        }
        StopMotion();
        dragOrigin = e.GetPosition(this);
        lastDragPoint = dragOrigin;
        lastDragStamp = Stopwatch.GetTimestamp();
        dragVelocity = default;
        dragYaw = turn.Angle;
        dragPitch = tilt.Angle;
        dragging = CaptureMouse();
        if (!dragging)
            UpdateMotion();
    }
    void Drag(object sender, MouseEventArgs e) {
        if (!dragging)
            return;
        if (e.LeftButton != MouseButtonState.Pressed) {
            CancelDrag();
            UpdateMotion();
            return;
        }
        Point position = e.GetPosition(this);
        TrackDragVelocity(position);
        Vector delta = position - dragOrigin;
        if (!manuallyRotated && Math.Abs(delta.X) < SystemParameters.MinimumHorizontalDragDistance &&
            Math.Abs(delta.Y) < SystemParameters.MinimumVerticalDragDistance)
            return;
        manuallyRotated = true;
        turn.Angle = (dragYaw + delta.X * 1.2) % 360;
        tilt.Angle = Math.Clamp(dragPitch - delta.Y * 0.6, -45, 45);
        e.Handled = true;
    }
    void EndDrag(object sender, MouseButtonEventArgs e) {
        if (!dragging)
            return;
        Vector velocity = ReleaseVelocity();
        CancelDrag();
        if (!StartCoasting(velocity))
            UpdateMotion();
        e.Handled = true;
    }
    void CancelDrag() {
        dragging = false;
        dragVelocity = default;
        lastDragStamp = 0;
        if (IsMouseCaptured)
            ReleaseMouseCapture();
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
    bool StartCoasting(Vector velocity) {
        if ((tilt.Angle >= 45 && velocity.Y > 0) || (tilt.Angle <= -45 && velocity.Y < 0))
            velocity.Y = 0;
        if (velocity.Length < 70 || !IsLoaded || !IsVisible || !IsEnabled ||
            owner?.WindowState == WindowState.Minimized || !SystemParameters.ClientAreaAnimation)
            return false;
        StopMotion();
        idleReturnTimer.Stop();
        manuallyRotated = coasting = true;
        int epoch = motionEpoch;
        const double friction = 2.4;
        double seconds = Math.Min(3, Math.Log(velocity.Length / 8) / friction);
        double travel = (1 - Math.Exp(-friction * seconds)) / friction;
        var duration = TimeSpan.FromSeconds(seconds);
        var easing = new ExponentialEase { Exponent = friction * seconds, EasingMode = EasingMode.EaseOut };
        var spin = new DoubleAnimation(turn.Angle, turn.Angle + velocity.X * travel, duration) { EasingFunction = easing };
        spin.Completed += (_, _) => {
            if (epoch != motionEpoch || dragging)
                return;
            StopMotion();
            // Normalize only after the spin; this keeps multiple turns continuous.
            turn.Angle = (turn.Angle % 360 + 360) % 360;
            UpdateMotion();
        };
        tilt.BeginAnimation(AxisAngleRotation3D.AngleProperty,
            new DoubleAnimation(tilt.Angle, Math.Clamp(tilt.Angle + velocity.Y * travel, -45, 45), duration) {
                EasingFunction = easing
            });
        turn.BeginAnimation(AxisAngleRotation3D.AngleProperty, spin);
        return true;
    }
    static void AppearanceChanged(DependencyObject target, DependencyPropertyChangedEventArgs e) =>
        ((GameCaseView)target).RefreshAppearance();
    void WindowStateChanged(object? sender, EventArgs e) { UpdateSpotlightMotion(); UpdateMotion(); }
    void WindowDeactivated(object? sender, EventArgs e) {
        CancelDrag();
        UpdateMotion();
    }
    void SystemSettingChanged(object? sender, PropertyChangedEventArgs e) {
        if (e.PropertyName == nameof(SystemParameters.ClientAreaAnimation)) {
            UpdateLighting();
            UpdateMotion();
        }
    }
    void StopMotion() {
        double angle = turn.Angle;
        double pitch = tilt.Angle;
        turn.BeginAnimation(AxisAngleRotation3D.AngleProperty, null);
        tilt.BeginAnimation(AxisAngleRotation3D.AngleProperty, null);
        animated = false;
        returning = false;
        coasting = false;
        ++motionEpoch;
        turn.Angle = angle;
        tilt.Angle = pitch;
    }
    void UpdateMotion() {
        bool visible = IsLoaded && IsVisible && IsEnabled && owner?.WindowState != WindowState.Minimized;
        if (!visible || held) {
            CancelDrag();
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
        double destination = Math.Abs(turn.Angle - lower) >= Math.Abs(turn.Angle - upper) ? lower : upper;
        var idle = new DoubleAnimation(turn.Angle, destination,
                TimeSpan.FromSeconds(4)) {
                AutoReverse = true, RepeatBehavior = RepeatBehavior.Forever,
                EasingFunction = new SineEase { EasingMode = EasingMode.EaseInOut }
            };
        Timeline.SetDesiredFrameRate(idle, 30);
        turn.BeginAnimation(AxisAngleRotation3D.AngleProperty, idle);
    }
    void ReturnToIdle() {
        idleReturnTimer.Stop();
        if (dragging || !IsLoaded || !IsVisible || !IsEnabled || owner?.WindowState == WindowState.Minimized)
            return;
        StopMotion();
        double home = Edition == 2 ? 18 : 26;
        if (!SystemParameters.ClientAreaAnimation) {
            turn.Angle = home;
            tilt.Angle = -5;
            manuallyRotated = false;
            return;
        }
        // Return by the shortest arc instead of unwinding a complete revolution.
        double normalized = (turn.Angle % 360 + 360) % 360;
        double target = turn.Angle + (home - normalized + 540) % 360 - 180;
        int epoch = motionEpoch;
        returning = true;
        var duration = TimeSpan.FromMilliseconds(850);
        var easing = new CubicEase { EasingMode = EasingMode.EaseInOut };
        var rotation = new DoubleAnimation(turn.Angle, target, duration) { EasingFunction = easing };
        rotation.Completed += (_, _) => {
            if (epoch != motionEpoch || dragging)
                return;
            turn.BeginAnimation(AxisAngleRotation3D.AngleProperty, null);
            tilt.BeginAnimation(AxisAngleRotation3D.AngleProperty, null);
            turn.Angle = home;
            tilt.Angle = -5;
            returning = false;
            manuallyRotated = false;
            UpdateMotion();
        };
        tilt.BeginAnimation(AxisAngleRotation3D.AngleProperty,
            new DoubleAnimation(tilt.Angle, -5, duration) { EasingFunction = easing });
        turn.BeginAnimation(AxisAngleRotation3D.AngleProperty, rotation);
    }
    void RefreshAppearance() {
        if (model == null)
            return;
        bool available = IsAvailable && IsEnabled;
        Opacity = available ? 1 : 0.58;
        model.Children.Clear();
        var plastic = Palette.Brush(Palette.SoftBlack);
        var edge = Palette.Brush(Palette.SoftBlackRaised);
        // Shape measured from a CC-BY 4.0 reference model of a DVD/PS2 keepcase (MacDrawz,
        // sketchfab.com/3d-models/dvdps2wii-case-60c2e703f9764cd6885811452802b3aa); no assets are used.
        // 1 scene unit = 100 mm. The mid-thickness outline is a 135 x 190 mm rounded rectangle;
        // each ring through the 14 mm thickness pulls that outline inward by the edge profile.
        var outline = Outline();
        int count = outline.Count;
        var normals = new Vector[count];
        for (int i = 0; i < count; i++) {
            // Outward for a counter-clockwise outline; vertices average their two edges.
            static Vector Normal(Point a, Point b) { var n = new Vector(b.Y - a.Y, a.X - b.X); n.Normalize(); return n; }
            var sum = Normal(outline[(i + count - 1) % count], outline[i]) + Normal(outline[i], outline[(i + 1) % count]);
            sum.Normalize();
            normals[i] = sum;
        }
        bool Spine(int i) => outline[i].X <= -CaseWidth + CornerRadius + 1e-9;
        Point3D Ring(int i, double z) {
            Point p = outline[i];
            double sides = Profile(SideProfile, z), ends = Profile(EndProfile, z);
            double inset = sides + (ends - sides) * Math.Abs(normals[i].Y);
            if (Math.Abs(z) < 1e-9 && !Spine(i))
                inset += SeamDepth;
            if (p.X >= CaseWidth - 1e-9 && Math.Abs(z) < NotchHalfHeight) {
                // The thumb notch: a C-shaped scoop between the two lips of the opening edge.
                double along = Math.Clamp((NotchHalfLength - Math.Abs(p.Y)) / NotchRamp, 0, 1);
                inset += NotchDepth * Math.Sqrt(1 - z * z / (NotchHalfHeight * NotchHalfHeight)) * along * along * (3 - 2 * along);
            }
            return new(p.X - normals[i].X * inset, p.Y - normals[i].Y * inset, z);
        }
        var shell = new MeshBuilder();
        var seam = new MeshBuilder();
        var spine = new MeshBuilder();
        for (int k = 0; k + 1 < RingDepths.Length; k++) {
            double z0 = RingDepths[k], z1 = RingDepths[k + 1];
            bool seamStrip = Math.Abs(z0) < 1e-9 || Math.Abs(z1) < 1e-9;
            for (int i = 0; i < count; i++) {
                int j = (i + 1) % count;
                Point3D a = Ring(i, z0), b = Ring(i, z1), c = Ring(j, z1), d = Ring(j, z0);
                if (Spine(i) && Spine(j) && Math.Abs(outline[i].Y) <= ArtHeight + 1e-9 && Math.Abs(outline[j].Y) <= ArtHeight + 1e-9) {
                    // One printed sheet wraps front, spine and back with the same top and bottom margin;
                    // the rounded corners beyond it are plain plastic.
                    Point Uv(int index, double z) => new((z + CaseDepth) / (2 * CaseDepth), (ArtHeight - outline[index].Y) / (2 * ArtHeight));
                    spine.Quad(a, b, c, d, Uv(i, z0), Uv(i, z1), Uv(j, z1), Uv(j, z0));
                } else
                    (seamStrip ? seam : shell).Quad(a, b, c, d);
            }
        }
        Cap(Enumerable.Range(0, count).Select(i => Ring(i, CaseDepth)).ToList(), plastic);
        Cap(Enumerable.Range(0, count).Select(i => Ring(i, -CaseDepth)).ToList(), plastic);
        shell.Add(this, edge);
        // The seam groove is darker so it still reads at the reduced render resolution.
        seam.Add(this, plastic);
        spine.Add(this, Artwork(SpineCover, available, true));
        // The covers lie on the flat part of each face, 0.05 mm above the plastic. On the spine
        // side they reach the edge of that flat part, where the spine art takes over.
        double spineEdge = -CaseWidth + Profile(SideProfile, CaseDepth);
        Face(new(spineEdge, -ArtHeight, CaseDepth + 0.0005), new(ArtWidth, -ArtHeight, CaseDepth + 0.0005),
             new(ArtWidth, ArtHeight, CaseDepth + 0.0005), new(spineEdge, ArtHeight, CaseDepth + 0.0005), Artwork(Cover, available));
        Face(new(ArtWidth, -ArtHeight, -CaseDepth - 0.0005), new(spineEdge, -ArtHeight, -CaseDepth - 0.0005),
             new(spineEdge, ArtHeight, -CaseDepth - 0.0005), new(ArtWidth, ArtHeight, -CaseDepth - 0.0005), Artwork(BackCover, available));
        // The sleeve glare goes last so it adds light over the covers.
        Glare(new(spineEdge, -ArtHeight, CaseDepth + 0.001), new(ArtWidth, -ArtHeight, CaseDepth + 0.001),
              new(ArtWidth, ArtHeight, CaseDepth + 0.001), new(spineEdge, ArtHeight, CaseDepth + 0.001), frontGlare);
        Glare(new(ArtWidth, -ArtHeight, -CaseDepth - 0.001), new(spineEdge, -ArtHeight, -CaseDepth - 0.001),
              new(spineEdge, ArtHeight, -CaseDepth - 0.001), new(ArtWidth, ArtHeight, -CaseDepth - 0.001), backGlare);
        UpdateGlare();
        UpdateMotion();
    }
    void Glare(Point3D a, Point3D b, Point3D c, Point3D d, Brush brush) {
        var mesh = new MeshGeometry3D {
            Positions = new Point3DCollection { a, b, c, d },
            TextureCoordinates = new PointCollection { new(0, 1), new(1, 1), new(1, 0), new(0, 0) },
            TriangleIndices = new Int32Collection { 0, 1, 2, 0, 2, 3 }
        };
        mesh.Freeze();
        // Emissive only: the glare adds light and is invisible from inside the case.
        model.Children.Add(new GeometryModel3D(mesh, new EmissiveMaterial(brush)));
    }
    void UpdateGlare() {
        if (model == null)
            return;
        static Vector3D Unit(Vector3D v) { v.Normalize(); return v; }
        var transform = model.Transform.Value;
        var center = transform.Transform(new Point3D(0, 0, 0));
        var half = Unit(Unit(lamp.Position - center) + Unit(camera.Position - center));
        var normal = Unit(transform.Transform(new Vector3D(0, 0, 1)));
        var across = Unit(transform.Transform(new Vector3D(1, 0, 0)));
        var up = Unit(transform.Transform(new Vector3D(0, 1, 0)));
        double level = Math.Clamp(SpotlightLevel, 0, 1);
        Set(frontGlare, Vector3D.DotProduct(normal, half), Vector3D.DotProduct(across, half));
        Set(backGlare, -Vector3D.DotProduct(normal, half), -Vector3D.DotProduct(across, half));
        void Set(RadialGradientBrush brush, double facing, double sideways) {
            // Strongest where the sleeve mirrors the lamp into the camera, fading within about
            // 30 degrees; the hotspot slides across the cover as the angle changes.
            double strength = Math.Pow(Math.Max(0, facing), 12) * level;
            // Brush space runs 0..1 across the cover with y downward.
            var middle = new Point(0.5 + 2.2 * sideways, 0.5 - 2.2 * Vector3D.DotProduct(up, half));
            brush.Center = brush.GradientOrigin = middle;
            // A circle on the cover, not an oval: scale the vertical radius by the cover's proportions.
            brush.RadiusX = 0.24;
            brush.RadiusY = 0.24 * (ArtWidth + CaseWidth - Profile(SideProfile, CaseDepth)) / (2 * ArtHeight);
            // A firm bright core with a soft falloff, like a lamp seen in glossy plastic.
            brush.GradientStops[0].Color = Palette.WithAlpha(Palette.WarmIvory, (byte)(210 * strength));
            brush.GradientStops[1].Color = Palette.WithAlpha(Palette.WarmIvory, (byte)(150 * strength));
            brush.GradientStops[2].Color = Palette.WithAlpha(Palette.WarmIvory, (byte)(40 * strength));
        }
    }
    const double CaseWidth = 0.675, CaseHeight = 0.95, CaseDepth = 0.07, CornerRadius = 0.07;
    // The insert's top and bottom margin matches the corner radius, so the spine art ends where the corners begin.
    const double ArtWidth = 0.62, ArtHeight = CaseHeight - CornerRadius;
    const double SeamHalfWidth = 0.006, SeamDepth = 0.008;
    const double NotchHalfLength = 0.315, NotchRamp = 0.015, NotchDepth = 0.037, NotchHalfHeight = 0.034;
    // How far each ring is pulled in at a given |z|, in scene units. The spine and opening edges
    // are flat across the middle and bevel into the covers; the top and bottom are fully rounded.
    static readonly (double Z, double Inset)[] SideProfile =
        { (0, 0), (0.040, 0), (0.051, 0.005), (0.059, 0.014), (0.065, 0.025), (0.0685, 0.035), (0.070, 0.045) };
    static readonly (double Z, double Inset)[] EndProfile =
        { (0, 0), (0.0154, 0.0009), (0.0228, 0.0026), (0.0321, 0.0056), (0.043, 0.0107), (0.0524, 0.0164),
          (0.0599, 0.022), (0.066, 0.0274), (0.0686, 0.0362), (0.070, 0.060) };
    static double Profile((double Z, double Inset)[] profile, double z) {
        z = Math.Abs(z);
        for (int i = 1; i < profile.Length; i++)
            if (z <= profile[i].Z)
                return profile[i - 1].Inset + (profile[i].Inset - profile[i - 1].Inset) *
                       (z - profile[i - 1].Z) / (profile[i].Z - profile[i - 1].Z);
        return profile[^1].Inset;
    }
    // Front cover to back cover: a coarse approximation, with layers where the shape turns.
    static readonly double[] RingDepths = BuildRingDepths();
    static double[] BuildRingDepths() {
        double[] half = { SeamHalfWidth, 0.022, NotchHalfHeight, 0.046, 0.059, 0.066, CaseDepth };
        return half.Reverse().Concat(new[] { 0d }).Concat(half.Select(z => -z)).ToArray();
    }
    // The mid-thickness silhouette, counter-clockwise seen from the front: a rounded rectangle
    // with extra points along the opening edge for the thumb notch.
    static List<Point> Outline() {
        const int steps = 4;
        var points = new List<Point>();
        foreach (var (cx, cy, start) in new[] { (CaseWidth - CornerRadius, CaseHeight - CornerRadius, 0d),
                                                (-CaseWidth + CornerRadius, CaseHeight - CornerRadius, 90d),
                                                (-CaseWidth + CornerRadius, -CaseHeight + CornerRadius, 180d),
                                                (CaseWidth - CornerRadius, -CaseHeight + CornerRadius, 270d) })
            for (int s = 0; s <= steps; s++) {
                double angle = (start + 90.0 * s / steps) * Math.PI / 180;
                points.Add(new(cx + CornerRadius * Math.Cos(angle), cy + CornerRadius * Math.Sin(angle)));
            }
        // The opening edge runs upward from the last corner back to the first.
        foreach (double y in new[] { -NotchHalfLength, -NotchHalfLength + NotchRamp, -0.15, 0, 0.15, NotchHalfLength - NotchRamp, NotchHalfLength })
            points.Add(new(CaseWidth, y));
        return points;
    }
    // A cover filling a closed ring of points; z > 0 faces the front.
    void Cap(List<Point3D> ring, Brush brush) {
        double z = ring[0].Z;
        var cap = new MeshBuilder();
        var center = new Point3D(0, 0, z);
        for (int i = 0; i < ring.Count; i++) {
            Point3D a = ring[i], b = ring[(i + 1) % ring.Count];
            if (z > 0) cap.Triangle(center, a, b); else cap.Triangle(center, b, a);
        }
        cap.Add(this, brush);
    }
    // Collects quads that share one material into a single mesh.
    sealed class MeshBuilder {
        readonly Point3DCollection positions = new();
        readonly PointCollection uv = new();
        readonly Int32Collection indices = new();
        public void Triangle(Point3D a, Point3D b, Point3D c) {
            int start = positions.Count;
            foreach (var p in new[] { a, b, c }) { positions.Add(p); uv.Add(new(0, 0)); }
            indices.Add(start); indices.Add(start + 1); indices.Add(start + 2);
        }
        public void Quad(Point3D a, Point3D b, Point3D c, Point3D d, Point ua = default, Point ub = default,
                         Point uc = default, Point ud = default) {
            int start = positions.Count;
            positions.Add(a); positions.Add(b); positions.Add(c); positions.Add(d);
            uv.Add(ua); uv.Add(ub); uv.Add(uc); uv.Add(ud);
            foreach (int index in new[] { 0, 1, 2, 0, 2, 3 })
                indices.Add(start + index);
        }
        public void Add(GameCaseView view, Brush brush) {
            if (positions.Count > 0)
                view.Mesh(positions, uv, indices, brush);
        }
    }
    Brush Artwork(BitmapSource? cover, bool available, bool spine = false) {
        if (cover != null) {
            BitmapSource image = Ps2Texture(cover);
            if (!available) {
                image = new FormatConvertedBitmap(image, PixelFormats.Gray8, null, 0);
                image.Freeze();
            }
            // Absolute units keep texture coordinates continuous across a panel's strips.
            var brush = new ImageBrush(image) { Stretch = Stretch.Fill,
                ViewportUnits = BrushMappingMode.Absolute, Viewport = new Rect(0, 0, 1, 1) };
            RenderOptions.SetBitmapScalingMode(brush, BitmapScalingMode.NearestNeighbor);
            brush.Freeze();
            return brush;
        }
        var drawing = new DrawingGroup();
        double width = spine ? 36 : 256, height = 360;
        using (var dc = drawing.Open()) {
            dc.DrawRectangle(Palette.Brush(Palette.SoftBlack), null,
                             new Rect(0, 0, width, height));
            var accent = Palette.Brush(available ? Palette.BurntOrange : Palette.WarmIvoryMuted);
            dc.DrawRectangle(accent, null, new Rect(0, 0, width, 6));
            if (spine) {
                dc.PushTransform(new TranslateTransform(width / 2, height / 2));
                dc.PushTransform(new RotateTransform(90));
            }
            var text = new FormattedText(spine ? $"OUTBREAK   /   FILE #{Edition}"
                                              : $"OUTBREAK\nFILE #{Edition}",
                CultureInfo.InvariantCulture, FlowDirection.LeftToRight,
                new Typeface("Segoe UI"), spine ? 18 : 30, Palette.Brush(Palette.WarmIvory), 1) {
                TextAlignment = TextAlignment.Center
            };
            dc.DrawText(text, spine ? new Point(0, -text.Height / 2)
                                   : new Point(width / 2, height / 2 - text.Height / 2));
            if (spine) { dc.Pop(); dc.Pop(); }
        }
        drawing.Freeze();
        var result = new DrawingBrush(drawing) { Stretch = Stretch.Fill,
            ViewportUnits = BrushMappingMode.Absolute, Viewport = new Rect(0, 0, 1, 1) };
        result.Freeze();
        return result;
    }
    // Cover art as a PS2 game would hold it: at most 512 texels tall, 16-bit colour with
    // the GS's 4x4 ordered dither.
    static BitmapSource Ps2Texture(BitmapSource source) {
        double scale = Math.Min(1, 512.0 / source.PixelHeight);
        BitmapSource scaled = scale < 1 ? new TransformedBitmap(source, new ScaleTransform(scale, scale)) : source;
        var bgra = new FormatConvertedBitmap(scaled, PixelFormats.Bgra32, null, 0);
        int width = bgra.PixelWidth, height = bgra.PixelHeight, stride = width * 4;
        var pixels = new byte[stride * height];
        bgra.CopyPixels(pixels, stride, 0);
        int[] bayer = { 0, 8, 2, 10, 12, 4, 14, 6, 3, 11, 1, 9, 15, 7, 13, 5 };
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++) {
                int offset = bayer[(y & 3) * 4 + (x & 3)] >> 1, i = y * stride + x * 4;
                for (int channel = 0; channel < 3; channel++) {
                    int value = Math.Clamp(pixels[i + channel] + offset, 0, 255) & 0xF8;
                    pixels[i + channel] = (byte)(value | value >> 5);
                }
            }
        var result = BitmapSource.Create(width, height, 96, 96, PixelFormats.Bgra32, null, pixels, stride);
        result.Freeze();
        return result;
    }
    void Face(Point3D a, Point3D b, Point3D c, Point3D d, Brush brush, bool specular = true) =>
        Mesh(new() { a, b, c, d }, new() { new(0, 1), new(1, 1), new(1, 0), new(0, 0) },
             new() { 0, 1, 2, 0, 2, 3 }, brush, specular);
    void Mesh(Point3DCollection positions, PointCollection uv, Int32Collection indices, Brush brush,
              bool specular = true) {
        var mesh = new MeshGeometry3D { Positions = positions, TextureCoordinates = uv, TriangleIndices = indices };
        mesh.Freeze();
        var material = new MaterialGroup();
        material.Children.Add(new DiffuseMaterial(brush));
        if (specular)
            material.Children.Add(new SpecularMaterial(Palette.Brush(Palette.WarmIvory, 35), 48));
        material.Freeze();
        model.Children.Add(new GeometryModel3D(mesh, material) { BackMaterial = material });
    }
}
