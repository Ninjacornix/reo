using Outbreak.Launcher;
using System.Text.Json;

static class PlatformPathsTests {
    internal static void Run(Action<bool, string> check) {
        string previousHome = Settings.Home;
        string previousRoot = PlatformPaths.FindRoot(AppContext.BaseDirectory);
        string root = Path.Combine(previousHome, "path-fixture");
        string home = Path.Combine(root, "custom-storage");
        Directory.CreateDirectory(home);
        Storage.Configure(root, home);
        try {
            foreach (string game in new[] { "file1", "file2" }) {
                string name = game == "file1" ? "reo_recomp" : "reo_recomp_file2";
                string expected = Path.Combine(
                    root,
                    OperatingSystem.IsWindows() ? "build-ninja" : "build-" + PlatformPaths.Platform,
                    "recomp", name + (OperatingSystem.IsWindows() ? ".exe" : ""));
                check(AppLayout.Native(root, game) == expected,
                      game + " developer executable keeps its build directory");
            }
            var saved = new Settings { Exe = "custom-file1", SecondExe = "custom-file2" };
            saved.Save();
            var developer = Settings.Load(root);
            check(developer.Exe == saved.Exe && developer.SecondExe == saved.SecondExe,
                  "Developer checkout preserves explicitly selected executables");

            string nativeFolder =
                Path.Combine(root, OperatingSystem.IsMacOS() ? "build-macos"
                                                             : "build-" + PlatformPaths.Platform);
            Directory.CreateDirectory(nativeFolder);
            File.WriteAllText(Path.Combine(nativeFolder, "native-file1"),
                              "Native fixture; never executed.");
            File.WriteAllText(Path.Combine(nativeFolder, "native-file2"),
                              "Native fixture; never executed.");
            File.WriteAllText(Path.Combine(nativeFolder, OperatingSystem.IsMacOS()
                                                             ? "macos-build.json"
                                                             : "native-build.json"),
                              JsonSerializer.Serialize(new { executable = "native-file1",
                                                             file2Executable = "native-file2" }));
            check(AppLayout.Native(root, "file1") == Path.Combine(nativeFolder, "native-file1") &&
                      AppLayout.Native(root, "file2") == Path.Combine(nativeFolder, "native-file2"),
                  "Native build records retain their executable paths");

            File.WriteAllText(
                Path.Combine(root, "distribution.json"),
                JsonSerializer.Serialize(
                    new { kitSha256 = new string('a', 64), file2KitSha256 = new string('b', 64) }));
            var packaged = Settings.Load(root);
            foreach (string game in new[] { "file1", "file2" }) {
                if (!OperatingSystem.IsWindows()) {
                    check(packaged.GetExe(game) == Path.Combine(nativeFolder, "native-" + game),
                          game + " native package retains its shipped executable");
                    continue;
                }
                string expected = LocalGameBuild.TargetPath(root, game);
                check(
                    packaged.GetExe(game) == expected &&
                        expected.StartsWith(Path.Combine(home, "local-games", game)),
                    game +
                        " Windows package resolves the current kit in custom storage, overriding stale saved/native paths");
                check(!File.Exists(packaged.GetExe(game)),
                      game + " unbuilt package stays unavailable");
                Directory.CreateDirectory(Path.GetDirectoryName(expected)!);
                File.WriteAllText(expected, "Synthetic game fixture; never executed.");
                check(File.Exists(packaged.GetExe(game)),
                      game + " completed build is detected without restarting");
            }
            packaged.Save();
            var reopened = Settings.Load(root);
            check(reopened.Exe == packaged.Exe && reopened.SecondExe == packaged.SecondExe &&
                      File.Exists(reopened.Exe) && File.Exists(reopened.SecondExe),
                  "Reopening a package retains both completed games");
            if (OperatingSystem.IsWindows()) {
                File.WriteAllText(
                    Path.Combine(root, "distribution.json"),
                    JsonSerializer.Serialize(new { kitSha256 = new string('c', 64),
                                                   file2KitSha256 = new string('d', 64) }));
                var updated = Settings.Load(root);
                check(updated.Exe != reopened.Exe && updated.SecondExe != reopened.SecondExe &&
                          !File.Exists(updated.Exe) && !File.Exists(updated.SecondExe),
                      "A new build kit does not reuse a previous release's readiness");
            }
        } finally {
            Storage.Configure(previousRoot, previousHome);
        }
    }
}
