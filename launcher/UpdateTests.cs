using System.IO;
using System.IO.Compression;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Text.Json;

namespace Outbreak.Launcher;
static class UpdateTests {
    sealed class HttpFixture : HttpMessageHandler {
        public Dictionary<string, byte[]> Files = new();
        protected override Task<HttpResponseMessage> SendAsync(HttpRequestMessage request,
                                                               CancellationToken cancel) {
            cancel.ThrowIfCancellationRequested();
            return Task.FromResult(
                Files.TryGetValue(request.RequestUri!.AbsoluteUri, out var data)
                    ? new HttpResponseMessage(HttpStatusCode.OK) { Content =
                                                                       new ByteArrayContent(data) }
                    : new HttpResponseMessage(HttpStatusCode.NotFound));
        }
    }
    static void Fixture(string root, string version, bool obsolete = false, bool legacy = false) {
        Directory.CreateDirectory(root);
        foreach (string relative in new[] { "Outbreak.Launcher.exe", "Outbreak.Launcher.dll",
                                            "Outbreak.Launcher.deps.json",
                                            "Outbreak.Launcher.runtimeconfig.json", "coreclr.dll",
                                            "hostfxr.dll", "build-kit/build-kit.json",
                                            "new-file.txt" }) {
            string path = Updates.SafePath(root, relative);
            Directory.CreateDirectory(Path.GetDirectoryName(path)!);
            File.WriteAllText(path, version + ":" + relative);
        }
        if (obsolete) {
            File.WriteAllText(Path.Combine(root, "obsolete.txt"), "old managed file");
            File.WriteAllText(Path.Combine(root, "modified-old.txt"), "old managed file");
        }
        File.WriteAllText(Path.Combine(root, "distribution.json"),
                          JsonSerializer.Serialize(
                              new { format = legacy ? 1 : 2, updateFormat = legacy ? 1 : 2,
                                    installMode = legacy ? "precompiled" : "local-build", version,
                                    platform = "win-x64", source = Updates.Repository }));
        var files =
            Directory.EnumerateFiles(root, "*", SearchOption.AllDirectories)
                .Select(p => new PackageFile(Path.GetRelativePath(root, p).Replace('\\', '/'),
                                             new FileInfo(p).Length, Updates.Sha(p)))
                .ToList();
        File.WriteAllText(Path.Combine(root, "package-manifest.json"),
                          JsonSerializer.Serialize(files));
    }
    public static void Run(Action<bool, string> check) {
        void Refuses(Action action, string label) {
            bool failed = false;
            try {
                action();
            } catch (Exception error) when (
                error is IOException or UnauthorizedAccessException or OperationCanceledException) {
                failed = true;
            }
            check(failed, label);
        }
        string root =
            Path.Combine(Path.GetTempPath(), "reo-update-tests-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try {
            check(Updates.ParseVersion("v0.1") == Updates.ParseVersion("0.1.0"),
                  "Legacy release tags compare with full versions");
            check(Updates.ParseVersion("v0.10.0") > Updates.ParseVersion("v0.2.0"),
                  "Update versions compare numerically");
            Refuses(() => Updates.ParseVersion("v1.0-rc1"), "Unrecognized stable tag refused");
            foreach (string bad in new[] { "../outside.txt", "C:/outside.txt", "dir/../../outside",
                                           "dir/aux.txt", "dir/name:stream", "dir/name.",
                                           "dir\\outside" })
                Refuses(() => Updates.SafePath(root, bad), "Unsafe update path refused: " + bad);
            string source = Path.Combine(root, "new"), target = Path.Combine(root, "installed");
            Fixture(source, "0.2.0");
            Fixture(target, "0.1.0", true);
            string legacy = Path.Combine(root, "legacy-precompiled");
            Fixture(legacy, "0.2.0", legacy: true);
            Refuses(() => Updates.Validate(legacy, Updates.ParseVersion("0.2.0")),
                    "Precompiled-game distribution format is refused");
            string malformed = Path.Combine(root, "malformed");
            Directory.CreateDirectory(malformed);
            File.WriteAllText(Path.Combine(malformed, "package-manifest.json"), "[null]");
            Refuses(() => Updates.Inventory(malformed), "Empty inventory entries fail cleanly");
            File.WriteAllText(Path.Combine(malformed, "distribution.json"), "{}");
            Refuses(() => Updates.Validate(malformed, Updates.ParseVersion("0.2.0")),
                    "Missing release identity fails cleanly");
            var original =
                Directory.EnumerateFiles(target, "*", SearchOption.AllDirectories)
                    .ToDictionary(p => Path.GetRelativePath(target, p), File.ReadAllBytes);
            int files = Updates.Validate(source, Updates.ParseVersion("0.2.0")).Count;
            check(files > 5, "Complete update fixture validates");
            Refuses(() => Updates.Validate(source, Updates.ParseVersion("0.3.0")),
                    "Release tag must match package version");
            try {
                UpdateWorker.InstallFiles(source, target, Path.Combine(root, "failed-backup"),
                                          Updates.ParseVersion("0.2.0"), count => {
                                              if (count == 3)
                                                  throw new IOException(
                                                      "Simulated interrupted replacement");
                                          });
            } catch (IOException) {
            }
            check(
                original.All(
                    kv => File.ReadAllBytes(Path.Combine(target, kv.Key)).SequenceEqual(kv.Value)),
                "Partial installation rolls back all changed files");
            using (var held = new FileStream(Path.Combine(target, "Outbreak.Launcher.dll"),
                                             FileMode.Open, FileAccess.Read, FileShare.Read)) {
                Refuses(() => UpdateWorker.InstallFiles(source, target,
                                                        Path.Combine(root, "locked-backup"),
                                                        Updates.ParseVersion("0.2.0")),
                        "Locked installation file fails safely");
            }
            check(
                original.All(
                    kv => File.ReadAllBytes(Path.Combine(target, kv.Key)).SequenceEqual(kv.Value)),
                "Locked-file rollback restores the earlier version");
            Directory.CreateDirectory(Path.Combine(target, "memory-cards", "mine"));
            File.WriteAllText(Path.Combine(target, "memory-cards", "mine", "save"), "keep save");
            File.WriteAllText(Path.Combine(target, "my-notes.txt"), "keep unknown file");
            File.WriteAllText(Path.Combine(target, "modified-old.txt"), "user edit");
            UpdateWorker.InstallFiles(source, target, Path.Combine(root, "backup"),
                                      Updates.ParseVersion("0.2.0"));
            check(Updates.InstalledVersion(target) == Updates.ParseVersion("0.2.0"),
                  "Installer publishes the new version");
            check(!File.Exists(Path.Combine(target, "obsolete.txt")) &&
                      File.ReadAllText(Path.Combine(target, "modified-old.txt")) == "user edit",
                  "Only unchanged obsolete package files are removed");
            check(File.ReadAllText(Path.Combine(target, "memory-cards", "mine", "save")) ==
                          "keep save" &&
                      File.Exists(Path.Combine(target, "my-notes.txt")),
                  "User saves and unknown files survive updating");
            string zip = Path.Combine(root, "release.zip");
            ZipFile.CreateFromDirectory(source, zip);
            string extracted = Updates.Extract(zip, Path.Combine(root, "extracted"));
            check(Updates.Validate(extracted, Updates.ParseVersion("0.2.0")).Count == files,
                  "Downloaded archive expands and verifies");
            File.WriteAllText(Path.Combine(extracted, "Outbreak.Launcher.dll"), "tampered");
            Refuses(() => Updates.Validate(extracted, Updates.ParseVersion("0.2.0")),
                    "Per-file tampering is detected");
            string hostile = Path.Combine(root, "traversal.zip");
            using (var archive = ZipFile.Open(hostile, ZipArchiveMode.Create)) {
                using (var writer = new StreamWriter(
                           archive.CreateEntry("distribution.json").Open())) writer.Write("{}");
                using (var writer = new StreamWriter(archive.CreateEntry("../escaped.txt").Open()))
                    writer.Write("bad");
            }
            Refuses(() => Updates.Extract(hostile, Path.Combine(root, "unsafe")),
                    "ZIP traversal is refused before escape");
            check(!File.Exists(Path.Combine(root, "escaped.txt")),
                  "Archive cannot create files outside staging");
            string assetName = "RE-Outbreak-v0.2.0-Windows-x64.zip",
                   url = Updates.Repository + "/releases/download/v0.2.0/" + assetName,
                   sha = Updates.Sha(zip);
            string Release(string digest, bool draft = false, bool prerelease = false) =>
                JsonSerializer.Serialize(
                    new { tag_name = "v0.2.0", draft, prerelease,
                          assets = new[] { new { name = assetName, browser_download_url = url,
                                                 size = new FileInfo(zip).Length, digest } } });
            var release =
                Updates.ParseRelease(Release("sha256:" + sha), Updates.ParseVersion("0.1.0"))!;
            check(release.Package.Name == assetName, "Latest release selects its Windows package");
            check(Updates.ParseRelease(Release("sha256:" + sha), Updates.ParseVersion("0.2.0")) ==
                          null &&
                      Updates.ParseRelease(Release("sha256:" + sha, true),
                                           Updates.ParseVersion("0.1.0")) == null &&
                      Updates.ParseRelease(Release("sha256:" + sha, false, true),
                                           Updates.ParseVersion("0.1.0")) == null,
                  "Same-version, draft and prerelease builds are not installed");
            Refuses(() => Updates.ParseRelease(Release(""), Updates.ParseVersion("0.1.0")),
                    "Releases without a trusted digest or checksum cannot install");
            var http = new HttpFixture();
            using var client = new HttpClient(http);
            check(Updates.Check(client, Updates.ParseVersion("0.1.0"), default)
                          .GetAwaiter()
                          .GetResult() == null,
                  "GitHub 404 means no published release");
            http.Files[Updates.LatestApi] = Encoding.UTF8.GetBytes(Release("sha256:" + sha));
            http.Files[url] = File.ReadAllBytes(zip);
            check(Updates.Check(client, Updates.ParseVersion("0.1.0"), default)
                          .GetAwaiter()
                          .GetResult()!.Tag == "v0.2.0",
                  "Release API response discovers the update");
            var downloaded =
                Updates.Download(client, release, Path.Combine(root, "download"), null, default)
                    .GetAwaiter()
                    .GetResult();
            check(Updates.Sha(downloaded) == sha, "Streaming update download verifies SHA-256");
            Refuses(
                () => Updates
                          .Download(client,
                                    release with { Package =
                                                       release.Package with {
                                                           Digest = "sha256:" + new string('0', 64)
                                                       } },
                                    Path.Combine(root, "bad-hash"), null, default)
                          .GetAwaiter()
                          .GetResult(),
                "Wrong archive digest refuses installation");
            using var canceled = new CancellationTokenSource();
            canceled.Cancel();
            Refuses(() => Updates
                              .Download(client, release, Path.Combine(root, "canceled"), null,
                                        canceled.Token)
                              .GetAwaiter()
                              .GetResult(),
                    "Canceled downloads cannot install");
        } finally {
            // Only this test's absolute, uniquely named temporary directory is removed.
            if (Path.GetDirectoryName(Path.GetFullPath(root)) ==
                    Path.GetFullPath(Path.GetTempPath()).TrimEnd(Path.DirectorySeparatorChar) &&
                Path.GetFileName(root).StartsWith("reo-update-tests-", StringComparison.Ordinal))
                Directory.Delete(root, true);
        }
    }
}
