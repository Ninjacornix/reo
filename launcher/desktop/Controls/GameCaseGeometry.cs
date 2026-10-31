using Avalonia;
using Avalonia.Media;
using Point3DCollection = System.Collections.Generic.List<Outbreak.Launcher.Desktop.Controls.Point3D>;
using PointCollection = System.Collections.Generic.List<Avalonia.Point>;
using Int32Collection = System.Collections.Generic.List<int>;
using Vector = Outbreak.Launcher.Desktop.Controls.UnitVector;
namespace Outbreak.Launcher.Desktop.Controls;

public partial class GameCaseView {
    void RefreshAppearance() {
        bool available = IsAvailable && IsEnabled;
        Opacity = available ? 1 : 0.58;
        meshes.Clear();
        var plastic = Surface(Palette.SoftBlack);
        var edge = Surface(Palette.SoftBlackRaised);
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
        InvalidateVisual();
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
    void Cap(List<Point3D> ring, SceneSurface brush) {
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
        public void Add(GameCaseView view, SceneSurface brush) {
            if (positions.Count > 0)
                view.Mesh(positions, uv, indices, brush);
        }
    }

    void Mesh(Point3DCollection positions,PointCollection uv,Int32Collection indices,SceneSurface brush,bool specular=true) =>
        meshes.Add(new(positions.ToArray(),uv.ToArray(),indices.ToArray(),brush,specular));
    void Face(Point3D a,Point3D b,Point3D c,Point3D d,SceneSurface brush,bool specular=true)=>
        Mesh(new(){a,b,c,d},new(){new(0,1),new(1,1),new(1,0),new(0,0)},new(){0,1,2,0,2,3},brush,specular);
    void Glare(Point3D a,Point3D b,Point3D c,Point3D d,SceneSurface brush)=>Face(a,b,c,d,brush);
}
