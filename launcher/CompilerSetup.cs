using System.Diagnostics;
using System.IO;
using System.Windows;

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

    public static async Task Ensure(string kit, string cache, CancellationToken cancel) {
        if (await Available(cancel))
            return;
        var app =
            Application.Current ?? throw new IOException("Microsoft C++ Build Tools are required.");
        bool install = await app.Dispatcher.InvokeAsync(
            () =>
                MessageBox.Show(
                    "The first build needs Microsoft C++ Build Tools and the Windows SDK. " +
                        "Setup downloads several GB and may ask for administrator access. " +
                        "Microsoft's installer will let you review its terms and installation choices.\n\n" +
                        "Open setup now?",
                    "Build tools", MessageBoxButton.YesNo,
                    MessageBoxImage.Question) == MessageBoxResult.Yes);
        if (!install)
            throw new OperationCanceledException("Compiler setup was not started.", cancel);
        string setup = LocalGameBuild.Inside(kit, "tools/local_build/setup_compiler.ps1");
        string powershell =
            Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.System),
                         "WindowsPowerShell", "v1.0", "powershell.exe");
        var start = new ProcessStartInfo(
            powershell) { UseShellExecute = false, CreateNoWindow = true,
                          RedirectStandardOutput = true, RedirectStandardError = true };
        foreach (string argument in new[] { "-NoProfile", "-ExecutionPolicy", "Bypass", "-File",
                                            setup, "-Cache",
                                            Path.Combine(cache, "compiler-setup") })
            start.ArgumentList.Add(argument);
        using var process =
            Process.Start(start) ?? throw new IOException("Cannot open compiler setup.");
        var stdout = process.StandardOutput.ReadToEndAsync();
        var stderr = process.StandardError.ReadToEndAsync();
        // Microsoft's interactive installer owns its own cancellation and UAC.
        // Do not kill it midway through installing shared system components.
        await process.WaitForExitAsync();
        File.WriteAllText(Path.Combine(cache, "compiler-setup.log"), await stdout + await stderr);
        cancel.ThrowIfCancellationRequested();
        if (process.ExitCode == 3010)
            throw new IOException("Restart Windows to finish compiler setup, then launch again.");
        if (process.ExitCode != 0 || !await Available(cancel))
            throw new IOException("Compiler setup did not finish. See " +
                                  Path.Combine(cache, "compiler-setup.log"));
    }
}
