using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

// Turns a failed build step log into a reason a player can act on. The full log
// stays in the build cache; this only adds the known causes and the last error.
internal static class BuildFailure {
    const string Folder = "Game files → Storage folder";

    internal static string? Explain(string log) {
        // Older recompilers open files in the Windows ANSI code page; a user folder
        // such as "El Pão" then fails with this message (or Python cannot print it).
        if (log.Contains("Could not load ELF file", StringComparison.Ordinal) ||
            log.Contains("UnicodeEncodeError", StringComparison.Ordinal))
            return "The build could not use a folder whose name has letters such as ã, é or Cyrillic. " +
                   $"Choose a storage folder with a plain name such as C:\\Outbreak ({Folder}).";
        // Windows reports a path over 260 characters as "path not found" (3) or (206).
        if (Regex.IsMatch(log, @"\[WinError (3|206)\]") && Regex.IsMatch(log, @"'[^'\r\n]{240,}'"))
            return "A build path is longer than Windows allows. " +
                   $"Choose a storage folder with a short path such as C:\\Outbreak ({Folder}).";
        return null;
    }

    // Last line that states an error, for the message shown in the launcher.
    internal static string? LastError(string log) =>
        log.Split('\n')
            .Select(line => line.Trim())
            .LastOrDefault(line => Regex.IsMatch(line, @"^(\w+\.)*\w*(Error|Exception)\b"));

    internal static string Message(string stepName, int code, string cache, string? log) {
        string message = $"Local build failed during {stepName} (exit {code}).";
        if (log != null) {
            if (Explain(log) is { } reason)
                message += " " + reason;
            if (LastError(log) is { } error)
                message += " Error: " + (error.Length > 300 ? error[..300] + "…" : error);
        }
        return message + " The completed game was not replaced. Build logs: " + cache;
    }
}
