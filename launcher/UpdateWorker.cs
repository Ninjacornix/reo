using System.Diagnostics;
using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;
public static class UpdateWorker {
    record Change(string Path, bool Existed);
    public static void InstallFiles(string source, string target, string backup, Version version,
                                    Action<int>? checkpoint = null) {
        var incoming = Updates.Validate(source, version);
        var previous = Updates.Inventory(target);
        var wanted = incoming.Select(f => f.Path)
                         .Append("package-manifest.json")
                         .ToHashSet(StringComparer.OrdinalIgnoreCase);
        var obsolete = previous
                           .Where(f => !wanted.Contains(f.Path) &&
                                       File.Exists(Updates.SafePath(target, f.Path)) &&
                                       Updates.Sha(Updates.SafePath(target, f.Path))
                                           .Equals(f.Sha256, StringComparison.OrdinalIgnoreCase))
                           .Select(f => f.Path)
                           .ToList();
        var paths = wanted.Concat(obsolete).Distinct(StringComparer.OrdinalIgnoreCase).ToList();
        Directory.CreateDirectory(backup);
        var changes = new List<Change>();
        foreach (string relative in paths) {
            string path = Updates.SafePath(target, relative);
            bool exists = File.Exists(path);
            if (exists) {
                string saved = Updates.SafePath(backup, relative);
                Directory.CreateDirectory(Path.GetDirectoryName(saved)!);
                File.Copy(path, saved);
            }
            changes.Add(new(relative, exists));
        }
        File.WriteAllText(Path.Combine(Path.GetDirectoryName(backup)!, "rollback.json"),
                          JsonSerializer.Serialize(changes, Updates.Json));
        var applied = new List<Change>();
        try {
            // Publish metadata last. Each replacement is atomic; the backup covers the transaction.
            var ordered = paths
                              .OrderBy(p => p == "package-manifest.json" ? 2
                                            : p == "distribution.json"   ? 1
                                                                         : 0)
                              .ToList();
            foreach (string relative in ordered) {
                string destination = Updates.SafePath(target, relative);
                if (wanted.Contains(relative)) {
                    string input = Updates.SafePath(source, relative);
                    Directory.CreateDirectory(Path.GetDirectoryName(destination)!);
                    string temporary = destination + ".reo-new-" + Guid.NewGuid().ToString("N");
                    try {
                        File.Copy(input, temporary);
                        File.Move(temporary, destination, true);
                    } finally {
                        if (File.Exists(temporary))
                            File.Delete(temporary);
                    }
                } else
                    File.Delete(destination);
                applied.Add(changes.First(c => c.Path == relative));
                checkpoint?.Invoke(applied.Count);
            }
            Updates.Validate(target, version);
        } catch (Exception error) {
            var failures = new List<Exception>();
            foreach (var change in applied.AsEnumerable().Reverse()) {
                try {
                    string destination = Updates.SafePath(target, change.Path);
                    if (change.Existed)
                        File.Copy(Updates.SafePath(backup, change.Path), destination, true);
                    else if (File.Exists(destination))
                        File.Delete(destination);
                } catch (Exception restore) {
                    failures.Add(restore);
                }
            }
            if (failures.Count > 0)
                throw new AggregateException(
                    "Update failed; some files could not be restored. The previous files are in " +
                        backup,
                    new[] { error }.Concat(failures));
            throw;
        }
    }
    static UpdatePlan ReadPlan(string file) {
        var plan = JsonSerializer.Deserialize<UpdatePlan>(File.ReadAllText(file), Updates.Json) ??
                   throw new IOException("Missing update plan.");
        string work = Path.GetFullPath(plan.Work), home = Path.GetFullPath(Updates.Home);
        if (!string.Equals(Path.GetDirectoryName(work), home, StringComparison.OrdinalIgnoreCase) ||
            !Guid.TryParseExact(Path.GetFileName(work), "N", out _) ||
            Path.GetFullPath(file) != Path.Combine(work, "plan.json") ||
            Path.GetFullPath(plan.Source) != Path.Combine(work, "new"))
            throw new IOException("Update plan is outside the owned staging directory.");
        Updates.SafePath(home, Path.GetFileName(work) + "/plan.json");
        if (File.Exists(Path.Combine(plan.Target, "CMakeLists.txt")) ||
            !AppLayout.Packaged(plan.Target) ||
            plan.Target.StartsWith(work, StringComparison.OrdinalIgnoreCase))
            throw new IOException(
                "The updater cannot replace a source checkout or staging directory.");
        if (Updates.ParseVersion(plan.Version) <= Updates.InstalledVersion(plan.Target))
            throw new IOException("Update would not install a newer version.");
        return plan;
    }
    public static async Task<int> Run(string file) {
        UpdatePlan? plan = null;
        bool parentExited = false, restored = true;
        string? failure = null;
        try {
            plan = ReadPlan(file);
            Updates.Validate(plan.Source, Updates.ParseVersion(plan.Version));
            using (var installLock = new FileStream(
                       Updates.SafePath(plan.Target, ".reo-update.lock"), FileMode.OpenOrCreate,
                       FileAccess.ReadWrite, FileShare.None)) {
                File.WriteAllText(Path.Combine(plan.Work, "ready.json"),
                                  JsonSerializer.Serialize(new { pid = Environment.ProcessId }));
                try {
                    using var parent = Process.GetProcessById(plan.ParentPid);
                    if (parent.StartTime.ToUniversalTime().Ticks == plan.ParentStarted) {
                        using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(90));
                        var exit = parent.WaitForExitAsync(timeout.Token);
                        while (!exit.IsCompleted) {
                            if (File.Exists(Path.Combine(plan.Work, "cancel.json")))
                                return 2;
                            await Task.WhenAny(exit, Task.Delay(200, timeout.Token))
                                .ConfigureAwait(false);
                            timeout.Token.ThrowIfCancellationRequested();
                        }
                        await exit.ConfigureAwait(false);
                    }
                } catch (ArgumentException) {
                }
                parentExited = true;
                if (!File.Exists(Path.Combine(plan.Work, "commit.json")))
                    return 2;
                await Task
                    .Run(() => InstallFiles(plan.Source, plan.Target,
                                            Path.Combine(plan.Work, "backup"),
                                            Updates.ParseVersion(plan.Version)))
                    .ConfigureAwait(false);
            }
        } catch (Exception error) {
            failure = error.Message;
            restored = error is not AggregateException;
            if (plan == null) {
                Directory.CreateDirectory(Updates.Home);
                File.WriteAllText(Path.Combine(Updates.Home, "worker-error.txt"), error.ToString());
                return 1;
            }
        }
        string receipt = Path.Combine(plan.Work, "result.json");
        File.WriteAllText(receipt, JsonSerializer.Serialize(
                                       new { success = failure == null, version = plan.Version,
                                             error = failure, rollbackSucceeded = restored,
                                             backup = Path.Combine(plan.Work, "backup"),
                                             target = plan.Target, utc = DateTime.UtcNow },
                                       Updates.Json));
        if (parentExited) {
            var start = new ProcessStartInfo(Path.Combine(plan.Target, "Outbreak.Launcher.exe")) {
                UseShellExecute = false, CreateNoWindow = true, WorkingDirectory = plan.Target
            };
            start.ArgumentList.Add(failure == null ? "--update-complete" : "--update-failed");
            start.ArgumentList.Add(receipt);
            using var restarted = Process.Start(start);
            if (restarted != null)
                File.WriteAllText(Path.Combine(plan.Work, "restart.json"),
                                  JsonSerializer.Serialize(
                                      new { pid = restarted.Id, executable = start.FileName }));
        }
        return failure == null ? 0 : 1;
    }
}
