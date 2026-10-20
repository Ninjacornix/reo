using System.Diagnostics;
using System.IO;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class PortableCompilerSetupTests {
    sealed class Progress(Action<ImportProgress> report) : IProgress<ImportProgress> {
        public void Report(ImportProgress value) => report(value);
    }
    internal static async Task Run(string home, string receipt) {
        home = Path.GetFullPath(home);
        if (Directory.Exists(home))
            throw new IOException("Use a fresh compiler test folder.");
        Directory.CreateDirectory(home);
        using var limit = new CancellationTokenSource(TimeSpan.FromMinutes(8));
        int checks = 0;
        void Check(bool valid, string message) {
            if (!valid)
                throw new IOException(message);
            checks++;
        }
        string? original = Environment.GetEnvironmentVariable("REO_LLVM_MINGW");
        bool downloaded = false;
        var progress = new Progress(value => {
            downloaded |= value.Stage == "Downloading compiler";
            if (value.Total == 0 || value.Completed == 0 || value.Completed == value.Total)
                File.AppendAllText(Path.Combine(home, "progress.log"),
                                   value.Stage + ": " + value.File + "\n");
        });
        string compiler = await PortableCompilerSetup.Ensure(PortableCompilerSetup.CompilerHash,
                                                             progress, limit.Token, home);
        Check(downloaded, "Clean setup did not exercise downloading");
        Check(!Directory.Exists(Path.Combine(compiler, "python")) &&
                  !Directory.Exists(Path.Combine(compiler, "aarch64-w64-mingw32")),
              "Unused compiler components were extracted");
        Check(Environment.GetEnvironmentVariable("REO_LLVM_MINGW") == original,
              "User environment was modified");
        async Task<string> Run(string executable, params string[] arguments) {
            var start = new ProcessStartInfo(executable) {
                UseShellExecute = false, CreateNoWindow = true, WorkingDirectory = home,
                RedirectStandardOutput = true, RedirectStandardError = true
            };
            foreach (string argument in arguments)
                start.ArgumentList.Add(argument);
            using var process =
                Process.Start(start) ?? throw new IOException("Compiler probe did not start.");
            Task<string> output = process.StandardOutput.ReadToEndAsync(),
                         errors = process.StandardError.ReadToEndAsync();
            try {
                await process.WaitForExitAsync(limit.Token);
            } catch (OperationCanceledException) {
                if (!process.HasExited)
                    process.Kill(entireProcessTree: true);
                throw;
            }
            string details = (await output) + (await errors);
            Check(process.ExitCode == 0, "Native compiler/tool probe failed: " + details);
            return details;
        }
        string driver = Path.Combine(compiler, "bin/x86_64-w64-mingw32-clang++.exe");
        Check((await Run(driver, "--version")).Contains("clang version"),
              "Compiler version did not run");
        await File.WriteAllTextAsync(
            Path.Combine(home, "probe.cpp"),
            "#include <windows.h>\n#include <vector>\n#include <thread>\n#include <immintrin.h>\nint main(){ std::vector<int> v{1,2}; std::thread t([&]{v[0]+=v[1];}); t.join(); __m128 a=_mm_set1_ps(1); return v[0]==3 && GetCurrentProcessId()!=0 && _mm_cvtss_f32(a)==1 ? 0:1; }\n");
        await Run(driver, "-std=c++20", "-O1", "-pthread", "-c", "probe.cpp", "-o", "probe.obj");
        await File.WriteAllTextAsync(Path.Combine(home, "probe.rc"), "1 RCDATA { 1, 2, 3 }\n");
        await Run(Path.Combine(compiler, "bin/x86_64-w64-mingw32-windres.exe"), "-i", "probe.rc",
                  "-o", "probe.res", "-O", "coff");
        await Run(Path.Combine(compiler, "bin/llvm-ar.exe"), "rcs", "probe.lib", "probe.obj");
        await Run(driver, "probe.obj", "probe.res", "-static", "-pthread", "-o", "probe.exe");
        await Run(Path.Combine(home, "probe.exe"));
        downloaded = false;
        Check(await PortableCompilerSetup.Ensure(PortableCompilerSetup.CompilerHash, progress,
                                                 limit.Token, home) == compiler,
              "Cached compiler path changed");
        Check(!downloaded, "Cached setup downloaded again");
        bool cancelled = false;
        using (var cancellation = new CancellationTokenSource()) {
            cancellation.Cancel();
            try {
                await PortableCompilerSetup.Ensure(PortableCompilerSetup.CompilerHash, progress,
                                                   cancellation.Token, home);
            } catch (OperationCanceledException) {
                cancelled = true;
            }
        }
        Check(cancelled, "Cancelled setup did not stop");
        await File.WriteAllTextAsync(receipt, JsonSerializer.Serialize(new {
            passed = true, checks, coldDownload = true, nativeCompileLinkRun = true,
            cachedReuse = true, gameBuildRun = false, compilerFolder = compiler
        }));
    }
}
