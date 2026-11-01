using Avalonia.Animation.Easings;
using Avalonia.Media.Imaging;
using System.Globalization;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher.Desktop.Controls;

// Port of RC1 GameDiscView.cs. RC1 renders a lit Viewport3D disc with an orthographic camera.
// The disc is planar and the light directional, so its projection is an affine transform and
// its lighting is one constant per material; both are applied here exactly.
public sealed class GameDiscView : Control {
    public static readonly StyledProperty<IImage?> ArtworkProperty = AvaloniaProperty.Register<GameDiscView, IImage?>(nameof(Artwork));
    public static readonly StyledProperty<int> EditionProperty = AvaloniaProperty.Register<GameDiscView, int>(nameof(Edition), 1);
    public static readonly StyledProperty<bool> IsAvailableProperty = AvaloniaProperty.Register<GameDiscView, bool>(nameof(IsAvailable));
    public static readonly StyledProperty<bool> IsSelectedProperty = AvaloniaProperty.Register<GameDiscView, bool>(nameof(IsSelected));
    static readonly StyledProperty<double> LightProperty = AvaloniaProperty.Register<GameDiscView, double>("Light");
    static readonly StyledProperty<double> SelectionLevelProperty = AvaloniaProperty.Register<GameDiscView, double>("SelectionLevel");
    public IImage? Artwork { get => GetValue(ArtworkProperty); set => SetValue(ArtworkProperty, value); }
    public int Edition { get => GetValue(EditionProperty); set => SetValue(EditionProperty, value); }
    public bool IsAvailable { get => GetValue(IsAvailableProperty); set => SetValue(IsAvailableProperty, value); }
    public bool IsSelected { get => GetValue(IsSelectedProperty); set => SetValue(IsSelectedProperty, value); }
    internal double Illumination => GetValue(LightProperty);
    internal double VerticalOffset => 12 * (1 - GetValue(SelectionLevelProperty));
    internal double DiscOpacity => (IsAvailable ? .48 : .20) + (1 - (IsAvailable ? .48 : .20)) * Illumination;

    // Viewport3D lighting: AmbientLight(178) + DirectionalLight(56, direction -.3,-.4,-1) on the face
    // normal after RotateX(3°) then RotateY(-2°); orthographic view along -Z.
    static readonly double Diffuse, FaceSpecular, MetalSpecular;
    static readonly double ShearX = Math.Sin(3 * Math.PI / 180) * -Math.Sin(-2 * Math.PI / 180);
    static readonly double ScaleX = Math.Cos(-2 * Math.PI / 180), ScaleY = Math.Cos(3 * Math.PI / 180);
    static GameDiscView() {
        double a = 3 * Math.PI / 180, b = -2 * Math.PI / 180;
        // n = Ry(b) * Rx(a) * (0,0,1)
        double ny = -Math.Sin(a), nz0 = Math.Cos(a);
        double nx = nz0 * Math.Sin(b), nz = nz0 * Math.Cos(b);
        double lx = .3, ly = .4, lz = 1, length = Math.Sqrt(lx * lx + ly * ly + lz * lz);
        lx /= length; ly /= length; lz /= length;
        double ndotl = Math.Max(0, nx * lx + ny * ly + nz * lz);
        double hx = lx, hy = ly, hz = lz + 1, h = Math.Sqrt(hx * hx + hy * hy + hz * hz);
        double ndoth = Math.Max(0, (nx * hx + ny * hy + nz * hz) / h);
        double light = 56 / 255.0;
        Diffuse = 178 / 255.0 + light * ndotl;
        FaceSpecular = 10 / 255.0 * light * Math.Pow(ndoth, 36);
        MetalSpecular = 85 / 255.0 * light * Math.Pow(ndoth, 48);
        AffectsRender<GameDiscView>(ArtworkProperty, EditionProperty, IsAvailableProperty, IsSelectedProperty, LightProperty, SelectionLevelProperty);
    }
    static Color Lit(Color color, double specular) => Color.FromRgb(
        (byte)Math.Clamp(Math.Round(color.R * Diffuse + 255 * specular), 0, 255),
        (byte)Math.Clamp(Math.Round(color.G * Diffuse + 255 * specular), 0, 255),
        (byte)Math.Clamp(Math.Round(color.B * Diffuse + 255 * specular), 0, 255));
    static readonly GradientStops Silver = new() {
        new(Lit(Color.FromRgb(185, 190, 195), MetalSpecular), 0), new(Lit(Color.FromRgb(132, 139, 145), MetalSpecular), .25),
        new(Lit(Color.FromRgb(224, 226, 228), MetalSpecular), .50), new(Lit(Color.FromRgb(107, 114, 120), MetalSpecular), .75),
        new(Lit(Color.FromRgb(185, 190, 195), MetalSpecular), 1) };

    IImage? label;
    bool held;
    public GameDiscView() {
        IsHitTestVisible = false;
        Focusable = false;
        ClipToBounds = true;
        AttachedToVisualTree += (_, _) => { RefreshArtwork(); UpdateLighting(); };
        DetachedFromVisualTree += (_, _) => { this.StopAnimation(LightProperty); this.StopAnimation(SelectionLevelProperty); };
        RefreshArtwork();
    }
    protected override void OnPropertyChanged(AvaloniaPropertyChangedEventArgs change) {
        base.OnPropertyChanged(change);
        if (change.Property == ArtworkProperty || change.Property == EditionProperty) RefreshArtwork();
        if (change.Property == IsAvailableProperty || change.Property == IsSelectedProperty) UpdateLighting();
    }
    protected override Size MeasureOverride(Size available) {
        double width = double.IsFinite(available.Width) ? available.Width : 440;
        return new Size(width, Math.Min(290, width * .5 + 4));
    }
    void RefreshArtwork() {
        var old = label;
        label = LitLabel(Artwork ?? Placeholder(Edition));
        if (!ReferenceEquals(old, label)) (old as IDisposable)?.Dispose();
        InvalidateVisual();
    }
    static IImage Placeholder(int edition) {
        var bitmap = new RenderTargetBitmap(new PixelSize(512, 512), new Vector(96, 96));
        using (var context = bitmap.CreateDrawingContext()) {
            context.DrawRectangle(new LinearGradientBrush {
                StartPoint = new RelativePoint(0, 0, RelativeUnit.Relative), EndPoint = new RelativePoint(0, 1, RelativeUnit.Relative),
                GradientStops = { new(Color.FromRgb(49, 44, 43), 0), new(Color.FromRgb(17, 16, 16), 1) } }, null, new Rect(0, 0, 512, 512));
            var text = new FormattedText("OUTBREAK\nFILE #" + edition, CultureInfo.InvariantCulture,
                FlowDirection.LeftToRight, new Typeface(OperatingSystem.IsWindows() ? "Segoe UI" : "Segoe UI, Helvetica Neue, DejaVu Sans"), 32, Brushes.LightGray) { TextAlignment = TextAlignment.Center };
            context.DrawText(text, new Point(256 - text.Width / 2, 110));
        }
        return bitmap;
    }
    // The label's DiffuseMaterial and faint SpecularMaterial, baked once per artwork.
    static IImage LitLabel(IImage source) {
        int size = (int)Math.Clamp(Math.Max(source.Size.Width, source.Size.Height), 64, 1024);
        using var raster = new RenderTargetBitmap(new PixelSize(size, size), new Vector(96, 96));
        using (var context = raster.CreateDrawingContext())
        using (context.PushRenderOptions(new RenderOptions { BitmapInterpolationMode = BitmapInterpolationMode.HighQuality }))
            context.DrawImage(source, new Rect(source.Size), new Rect(0, 0, size, size));
        var result = new WriteableBitmap(new PixelSize(size, size), new Vector(96, 96),
            Avalonia.Platform.PixelFormat.Bgra8888, Avalonia.Platform.AlphaFormat.Premul);
        using (var pixels = result.Lock()) {
            raster.CopyPixels(pixels);
            byte[] bytes = new byte[pixels.RowBytes * size];
            Marshal.Copy(pixels.Address, bytes, 0, bytes.Length);
            for (int y = 0; y < size; y++)
                for (int x = 0; x < size; x++) {
                    int i = y * pixels.RowBytes + x * 4;
                    double alpha = bytes[i + 3] / 255.0;
                    for (int c = 0; c < 3; c++)
                        bytes[i + c] = (byte)Math.Clamp(Math.Round(bytes[i + c] * Diffuse + 255 * FaceSpecular * alpha), 0, bytes[i + 3]);
                }
            Marshal.Copy(bytes, 0, pixels.Address, bytes.Length);
        }
        return result;
    }
    void UpdateLighting() {
        void Transition(StyledProperty<double> property, double target) {
            if (IsLoaded && !held && SystemParameters.ClientAreaAnimation)
                this.Animate(property, null, target, TimeSpan.FromMilliseconds(220), new CubicEaseInOut());
            else { this.StopAnimation(property); SetValue(property, target); }
        }
        Transition(LightProperty, IsSelected && IsAvailable ? 1 : 0);
        Transition(SelectionLevelProperty, IsSelected ? 1 : 0);
    }
    internal void Hold(bool value) { held = value; UpdateLighting(); }
    static Geometry Ring(Point center, double inner, double outer) => new GeometryGroup {
        FillRule = FillRule.EvenOdd,
        Children = { new EllipseGeometry(new Rect(center.X - outer, center.Y - outer, outer * 2, outer * 2)),
                     new EllipseGeometry(new Rect(center.X - inner, center.Y - inner, inner * 2, inner * 2)) } };
    public override void Render(DrawingContext context) {
        double width = Bounds.Width, height = Bounds.Height;
        if (width <= 0 || height <= 0) return;
        double cameraWidth = Math.Max(2.04, width / height * 1.015), scale = width / cameraWidth;
        double offset = VerticalOffset, light = Illumination;
        var center = new Point(width / 2, height + offset);
        if (IsAvailable && light > 0) {
            var glow = new Rect(0, height - 100 + offset, width, 100);
            using (context.PushOpacity(light))
                context.DrawRectangle(new RadialGradientBrush {
                    GradientStops = { new(VisualPalette.ColorOf(Palette.WarmIvory, 25), 0), new(Colors.Transparent, 1) } }, null, glow);
        }
        // Screen y points down, so RC1's world-space shear changes sign.
        var transform = Matrix.CreateTranslation(-center.X, -center.Y) *
                        new Matrix(ScaleX, 0, ShearX, ScaleY, 0, 0) *
                        Matrix.CreateTranslation(center.X, center.Y);
        using (context.PushOpacity(DiscOpacity))
        using (context.PushTransform(transform)) {
            var box = new Rect(center.X - scale, center.Y - scale, scale * 2, scale * 2);
            var metal = new LinearGradientBrush {
                StartPoint = new RelativePoint(box.TopLeft, RelativeUnit.Absolute),
                EndPoint = new RelativePoint(box.BottomRight, RelativeUnit.Absolute), GradientStops = Silver };
            context.DrawGeometry(metal, null, Ring(center, scale * .962, scale));
            context.DrawGeometry(metal, null, Ring(center, scale * .125, scale * .20));
            if (label != null)
                using (context.PushGeometryClip(Ring(center, scale * .20, scale * .962)))
                    context.DrawImage(label, new Rect(label.Size), box);
        }
    }
}
