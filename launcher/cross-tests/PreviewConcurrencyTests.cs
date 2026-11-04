using System.Numerics;
using Outbreak.Launcher;

internal static class PreviewConcurrencyTests {
    internal static void Run(Action<bool, string> check) {
        // Synthetic geometry keeps this regression independent of installed games and owned assets.
        static GamePreviewScene Scene() {
            Vector3[] positions = [new(-.4f, 0, 0), new(.4f, 0, 0), new(0, 1.8f, 0)];
            Vector3[] normals = [Vector3.UnitZ, Vector3.UnitZ, Vector3.UnitZ];
            var mesh = new PreviewMesh(positions, normals, [Vector2.Zero, Vector2.UnitX, Vector2.UnitY],
                Enumerable.Range(0, 128).SelectMany(_ => new[] { 0, 1, 2, 2, 1, 0 }).ToArray(), 0);
            var skin = new GamePreviewScene.Skin(positions.ToArray(), normals.ToArray(), positions, normals,
                Enumerable.Range(0, 3).Select(_ => new[] { new GamePreviewScene.Influence(0, 1) }).ToArray());
            return new([mesh], [new(1, 1, [255, 160, 80, 255])],
                [new(-1, Vector3.Zero, Quaternion.Identity, Vector3.One)], [skin], "synthetic");
        }
        var options = new PreviewRenderOptions(1, false, 1, "Off", "4:3", false, "Fit", false, 100, 1);
        var renderer = new GameScenePreviewRenderer();
        var scene = Scene();
        // Settle the room cache before comparing frames: the first zoom frame uses a wider room.
        renderer.Render(scene, options, 0, 96, 128);
        renderer.Render(scene, options, 0, 96, 128);
        var inputs = Enumerable.Range(0, 6).Select(i => (Options: options with { Brightness = 75 + i * 10 },
            Yaw: i * .3f, Width: 96 + i * 8, Height: 128 + i * 5)).ToArray();
        var expected = inputs.Select(input => renderer.Render(scene, input.Options, 0, input.Width, input.Height, input.Yaw)).ToArray();
        check(!expected[0].Bgra.SequenceEqual(expected[^1].Bgra), "Preview fixture exercises different rendered frames");
        using var start = new Barrier(inputs.Length);
        var workers = inputs.Select((input, index) => Task.Factory.StartNew(() => {
            start.SignalAndWait();
            for (int frame = 0; frame < 4; frame++) {
                var actual = renderer.Render(scene, input.Options, frame / 60.0, input.Width, input.Height, input.Yaw);
                if (actual.Width != expected[index].Width || actual.Height != expected[index].Height ||
                    !actual.Bgra.SequenceEqual(expected[index].Bgra))
                    throw new InvalidOperationException("Overlapping preview frames corrupted their output.");
            }
        }, CancellationToken.None, TaskCreationOptions.LongRunning, TaskScheduler.Default)).ToArray();
        try {
            Task.WhenAll(workers).GetAwaiter().GetResult();
            check(true, "Concurrent preview frames match isolated rendering without sharing mutable output");
        } catch (Exception error) {
            check(false, "Concurrent preview frames: " + error);
        }
    }
}
