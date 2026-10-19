using System.Diagnostics;
using System.IO;

namespace Outbreak.Launcher;

public static class CompilerSetup {
    static readonly string Vswhere =
        Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86),
                     "Microsoft Visual Studio", "Installer", "vswhere.exe");

    public static async Task<bool> Available(CancellationToken cancel = default) {
        if (!File.Exists(Vswhere))
            return false;
        var start = new ProcessStartInfo(Vswhere) { UseShellExecute = false, CreateNoWindow = true,
                                                    RedirectStandardOutput = true };
        foreach (string argument in new[] { "-latest", "-products", "*", "-version", "[17.13,18.0)",
                                            "-requires",
                                            "Microsoft.VisualStudio.Component.VC.Tools.x86.x64",
                                            "-property", "installationPath" })
            start.ArgumentList.Add(argument);
        using var process = Process.Start(start);
        if (process == null)
            return false;
        string installation = (await process.StandardOutput.ReadToEndAsync(cancel)).Trim();
        await process.WaitForExitAsync(cancel);
        string sdk =
            Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86),
                         "Windows Kits", "10", "Lib");
        return process.ExitCode == 0 &&
               File.Exists(
                   Path.Combine(installation, "VC", "Auxiliary", "Build", "vcvars64.bat")) &&
               Directory.Exists(sdk) &&
               Directory.GetDirectories(sdk).Any(
                   path => File.Exists(Path.Combine(path, "um", "x64", "kernel32.lib")) &&
                           File.Exists(Path.Combine(path, "ucrt", "x64", "ucrt.lib")));
    }

    public static async Task Ensure(CancellationToken cancel) {
        if (await Available(cancel))
            return;
        throw new IOException(
            "This development build kit requires existing Microsoft C++ tools. " +
            "Portable compiler support is not ready yet. No installer will be launched.");
    }
}
