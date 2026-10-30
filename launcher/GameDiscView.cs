using System.Globalization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;

namespace Outbreak.Launcher;

// Render the physical DVD once at 3x the screen's pixel density. WPF's live 3D texture
// filtering is rough at footer sizes; downsampling also smooths the rim and centre hole.
// Selection fades the cached image, keeping geometry rendering off the animation path.
public sealed class GameDiscView : Grid {
    public static readonly DependencyProperty ArtworkProperty = DependencyProperty.Register(
        nameof(Artwork), typeof(BitmapSource), typeof(GameDiscView), new PropertyMetadata(null, (d, _) => ((GameDiscView)d).RefreshArtwork()));
    public static readonly DependencyProperty EditionProperty = DependencyProperty.Register(
        nameof(Edition), typeof(int), typeof(GameDiscView), new PropertyMetadata(1, (d, _) => ((GameDiscView)d).RefreshArtwork()));
    public static readonly DependencyProperty IsAvailableProperty = DependencyProperty.Register(
        nameof(IsAvailable), typeof(bool), typeof(GameDiscView), new PropertyMetadata(false, (d, _) => ((GameDiscView)d).UpdateLighting()));
    public static readonly DependencyProperty IsSelectedProperty = DependencyProperty.Register(
        nameof(IsSelected), typeof(bool), typeof(GameDiscView), new PropertyMetadata(false, (d, _) => ((GameDiscView)d).UpdateLighting()));
    static readonly DependencyProperty LightProperty = DependencyProperty.Register(
        "Light", typeof(double), typeof(GameDiscView), new PropertyMetadata(0d, (d, _) => ((GameDiscView)d).ApplyLighting()));
    static readonly DependencyProperty SelectionLevelProperty = DependencyProperty.Register(
        "SelectionLevel", typeof(double), typeof(GameDiscView), new PropertyMetadata(0d, (d, _) => ((GameDiscView)d).ApplyLighting()));
    public BitmapSource? Artwork { get => (BitmapSource?)GetValue(ArtworkProperty); set => SetValue(ArtworkProperty, value); }
    public int Edition { get => (int)GetValue(EditionProperty); set => SetValue(EditionProperty, value); }
    public bool IsAvailable { get => (bool)GetValue(IsAvailableProperty); set => SetValue(IsAvailableProperty, value); }
    public bool IsSelected { get => (bool)GetValue(IsSelectedProperty); set => SetValue(IsSelectedProperty, value); }
    internal double Illumination => (double)GetValue(LightProperty);
    readonly OrthographicCamera camera = new() { LookDirection = new(0, 0, -5), UpDirection = new(0, 1, 0) };
    readonly GeometryModel3D face = new() { Geometry = Ring(.20, .962, 0) };
    readonly Viewport3D viewport;
    readonly Image surface = new() { Stretch = Stretch.Fill };
    readonly TranslateTransform discOffset = new();
    readonly System.Windows.Shapes.Ellipse glow;
    bool held, renderDirty = true;
    internal int RenderCount { get; private set; }
    internal int RasterWidth => (surface.Source as BitmapSource)?.PixelWidth ?? 0;
    internal double VerticalOffset => discOffset.Y;
    internal double DiscOpacity => surface.Opacity;

    public GameDiscView() {
        IsHitTestVisible = false;
        Focusable = false;
        ClipToBounds = true;
        RenderOptions.SetBitmapScalingMode(surface, BitmapScalingMode.HighQuality);
        surface.RenderTransform = discOffset;
        glow = new() { Height = 100, VerticalAlignment = VerticalAlignment.Bottom, Opacity = 0,
            Fill = new RadialGradientBrush(Palette.WithAlpha(Palette.WarmIvory, 25), Colors.Transparent),
            RenderTransform = discOffset };
        Children.Add(glow);
        var metal = new MaterialGroup();
        var silver = new LinearGradientBrush { StartPoint = new(0, 0), EndPoint = new(1, 1) };
        silver.GradientStops.Add(new(Color.FromRgb(185, 190, 195), 0));
        silver.GradientStops.Add(new(Color.FromRgb(132, 139, 145), .25));
        silver.GradientStops.Add(new(Color.FromRgb(224, 226, 228), .50));
        silver.GradientStops.Add(new(Color.FromRgb(107, 114, 120), .75));
        silver.GradientStops.Add(new(Color.FromRgb(185, 190, 195), 1));
        metal.Children.Add(new DiffuseMaterial(silver));
        metal.Children.Add(new SpecularMaterial(new SolidColorBrush(Color.FromArgb(85, 255, 255, 255)), 48));
        metal.Freeze();
        var disc = new Model3DGroup();
        disc.Children.Add(face);
        // Replace the scan's baked-in rim and hub with continuous physical surfaces.
        disc.Children.Add(new GeometryModel3D(Ring(.962, .994, -.001), metal));
        disc.Children.Add(new GeometryModel3D(Ring(.994, 1, -.004), metal));
        disc.Children.Add(new GeometryModel3D(Ring(.125, .20, .001), metal));
        disc.Children.Add(new GeometryModel3D(Edge(1, -.02, -.004), metal));
        disc.Children.Add(new GeometryModel3D(Edge(.125, -.02, .001), metal));
        var rotation = new Transform3DGroup();
        rotation.Children.Add(new RotateTransform3D(new AxisAngleRotation3D(new(1, 0, 0), 3)));
        rotation.Children.Add(new RotateTransform3D(new AxisAngleRotation3D(new(0, 1, 0), -2)));
        disc.Transform = rotation;
        var scene = new Model3DGroup();
        scene.Children.Add(new AmbientLight(Color.FromRgb(178, 178, 178)));
        scene.Children.Add(new DirectionalLight(Color.FromRgb(56, 56, 56), new(-.3, -.4, -1)));
        scene.Children.Add(disc);
        viewport = new Viewport3D { Camera = camera, IsHitTestVisible = false };
        viewport.Children.Add(new ModelVisual3D { Content = scene });
        Children.Add(surface);
        Loaded += (_, _) => { RefreshArtwork(); UpdateLighting(); Frame(); };
        SizeChanged += (_, _) => Frame();
        Unloaded += (_, _) => {
            BeginAnimation(LightProperty, null);
            BeginAnimation(SelectionLevelProperty, null);
        };
        RefreshArtwork();
        ApplyLighting();
    }
    protected override Size MeasureOverride(Size available) {
        double width = double.IsFinite(available.Width) ? available.Width : 440;
        var size = new Size(width, Math.Min(290, width * .5 + 4));
        base.MeasureOverride(size);
        return size;
    }
    void Frame() {
        if (!IsLoaded || ActualHeight <= 0 || ActualWidth <= 0) return;
        var dpi = VisualTreeHelper.GetDpi(this);
        // Bound the cache even if this control is reused in a much larger layout.
        double scale = Math.Min(3 * Math.Max(dpi.DpiScaleX, dpi.DpiScaleY), 2048 / Math.Max(ActualWidth, ActualHeight));
        int width = Math.Max(1, (int)Math.Ceiling(ActualWidth * scale));
        int heightPixels = Math.Max(1, (int)Math.Ceiling(ActualHeight * scale));
        if (!renderDirty && surface.Source is BitmapSource prior && prior.PixelWidth == width && prior.PixelHeight == heightPixels)
            return;
        camera.Width = Math.Max(2.04, ActualWidth / ActualHeight * 1.015);
        double height = camera.Width * ActualHeight / ActualWidth;
        camera.Position = new(0, height / 2, 5);
        var size = new Size(ActualWidth, ActualHeight);
        viewport.Measure(size);
        viewport.Arrange(new Rect(size));
        viewport.UpdateLayout();
        var bitmap = new RenderTargetBitmap(width, heightPixels, 96 * scale, 96 * scale, PixelFormats.Pbgra32);
        bitmap.Render(viewport);
        bitmap.Freeze();
        surface.Source = bitmap;
        renderDirty = false;
        RenderCount++;
    }
    protected override void OnDpiChanged(DpiScale oldDpi, DpiScale newDpi) {
        base.OnDpiChanged(oldDpi, newDpi);
        renderDirty = true;
        Frame();
    }
    void RefreshArtwork() {
        Brush label;
        if (Artwork != null) label = new ImageBrush(Artwork) { Stretch = Stretch.Fill };
        else {
            var drawing = new DrawingGroup();
            using (var context = drawing.Open()) {
                context.DrawRectangle(new LinearGradientBrush(Color.FromRgb(49, 44, 43), Color.FromRgb(17, 16, 16), 90), null, new Rect(0, 0, 512, 512));
                var text = new FormattedText("OUTBREAK\nFILE #" + Edition, CultureInfo.InvariantCulture,
                    FlowDirection.LeftToRight, new Typeface("Segoe UI"), 32, Brushes.LightGray, 1) { TextAlignment = TextAlignment.Center };
                context.DrawText(text, new Point(256, 110));
            }
            label = new DrawingBrush(drawing) { Stretch = Stretch.Fill };
        }
        RenderOptions.SetBitmapScalingMode(label, BitmapScalingMode.HighQuality);
        label.Freeze();
        var material = new MaterialGroup();
        material.Children.Add(new DiffuseMaterial(label));
        material.Children.Add(new SpecularMaterial(new SolidColorBrush(Color.FromArgb(10, 255, 255, 255)), 36));
        material.Freeze();
        face.Material = material;
        renderDirty = true;
        Frame();
    }
    void UpdateLighting() {
        void Transition(DependencyProperty property, double target) {
            if (IsLoaded && !held && SystemParameters.ClientAreaAnimation)
                BeginAnimation(property, new DoubleAnimation(target, TimeSpan.FromMilliseconds(220)) {
                    EasingFunction = new CubicEase { EasingMode = EasingMode.EaseInOut }
                });
            else { BeginAnimation(property, null); SetValue(property, target); }
        }
        Transition(LightProperty, IsSelected && IsAvailable ? 1 : 0);
        Transition(SelectionLevelProperty, IsSelected ? 1 : 0);
        ApplyLighting();
    }
    void ApplyLighting() {
        double light = Illumination;
        double baseline = IsAvailable ? .48 : .20;
        surface.Opacity = baseline + (1 - baseline) * light;
        discOffset.Y = 12 * (1 - (double)GetValue(SelectionLevelProperty));
        glow.Opacity = IsAvailable ? light : 0;
    }
    internal void Hold(bool value) { held = value; UpdateLighting(); }
    internal static MeshGeometry3D Ring(double inner, double outer, double z) {
        var mesh = new MeshGeometry3D();
        const int segments = 512;
        for (int i = 0; i <= segments; i++) {
            double angle = 2 * Math.PI * i / segments, x = Math.Cos(angle), y = Math.Sin(angle);
            foreach (double radius in new[] { outer, inner }) {
                mesh.Positions.Add(new(x * radius, y * radius, z));
                mesh.Normals.Add(new(0, 0, 1));
                mesh.TextureCoordinates.Add(new(.5 + x * radius / 2, .5 - y * radius / 2));
            }
            if (i < segments) { int n = i * 2; foreach (int index in new[] { n, n + 2, n + 1, n + 1, n + 2, n + 3 }) mesh.TriangleIndices.Add(index); }
        }
        mesh.Freeze();
        return mesh;
    }
    static MeshGeometry3D Edge(double radius, double back, double front) {
        var mesh = new MeshGeometry3D();
        const int segments = 512;
        for (int i = 0; i <= segments; i++) {
            double angle = 2 * Math.PI * i / segments, x = Math.Cos(angle), y = Math.Sin(angle);
            foreach (double z in new[] { back, front }) { mesh.Positions.Add(new(x * radius, y * radius, z)); mesh.Normals.Add(new(x, y, 0)); }
            if (i < segments) { int n = i * 2; foreach (int index in new[] { n, n + 1, n + 2, n + 1, n + 3, n + 2 }) mesh.TriangleIndices.Add(index); }
        }
        mesh.Freeze();
        return mesh;
    }
}
