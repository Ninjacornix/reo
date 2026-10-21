using System.Globalization;
using System.IO;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;

namespace Outbreak.Launcher;

public static partial class OnlineOptions {
    public static bool Configured(Settings settings) => settings.Game.Id == "file1" &&
                                                        settings.ResolvedCoopMode != "offline" &&
                                                        TryHost(settings.CoopHost, out _) &&
                                                        ValidUsername(settings.AccountUsername);
    public const int MinUsernameLength = 4;
    public const int MaxUsernameLength = 10;
    public const string HostProfileMarker = "REO native host profile provider v1";

    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    private static extern bool CreateDirectoryW(string path, nint securityAttributes);

    // Current openSNAP registration rules; not a claimed original ROM limit.
    [GeneratedRegex(@"\A(?!_)(?!.*__)(?!.*_$)[A-Za-z0-9_]{4,10}\z", RegexOptions.CultureInvariant)]
    private static partial Regex UsernamePattern();

    public static bool ValidUsername(string? username) => username != null &&
                                                          UsernamePattern().IsMatch(username);

    public static bool TryHost(string? input, out string host) {
        host = "";
        var parts = (input ?? "").Trim().Split('.');
        if (parts.Length != 4)
            return false;
        var octets = new byte[4];
        for (int i = 0; i < parts.Length; ++i)
            if (parts[i].Length is < 1 or > 3 || parts[i].Any(c => c is < '0' or > '9') ||
                !byte.TryParse(parts[i], NumberStyles.None, CultureInfo.InvariantCulture,
                               out octets[i]))
                return false;
        if (octets[0] is 0 or >= 224)
            return false;
        host = string.Join('.', octets);
        return true;
    }

    public static string? Error(Settings settings) {
        if (settings.ResolvedCoopMode == "offline")
            return null;
        if (string.IsNullOrWhiteSpace(settings.CoopHost) &&
            string.IsNullOrWhiteSpace(settings.AccountUsername))
            return null;
        if (settings.Game.Id != "file1")
            return "Online play is available for File #1 only.";
        if (!ValidUsername(settings.AccountUsername))
            return "Player name: use 4–10 letters, numbers or underscores. Underscores cannot " +
                   "start, end or repeat.";
        if (!TryHost(settings.CoopHost, out _))
            return settings.ResolvedCoopMode == "host"
                       ? "Choose the address friends will use."
                       : "Pick a game from the list, or enter the host's address, such as 192.168.1.20.";
        return null;
    }

    public static Dictionary<string, string> LaunchEnvironment(Settings settings) {
        if (!Configured(settings))
            return new();
        TryHost(settings.CoopHost, out string host);
        return new() { ["REO_COOP_HOST"] = host, ["REO_COOP_PLATFORM_AUTH"] = "native",
                       ["REO_COOP_USERNAME"] = settings.AccountUsername,
                       ["REO_COOP_AUTO_ACCOUNT"] = "1" };
    }

    public static string PrepareMemoryCard(Settings settings, string folder, FileStream? lease) {
        if (!Configured(settings))
            return "offline";
        string card = Path.GetFullPath(folder);
        string lockPath = card.TrimEnd(Path.DirectorySeparatorChar) + ".reo-lock";
        if (lease == null || !lease.CanWrite ||
            !Path.GetFullPath(lease.Name).Equals(lockPath, StringComparison.OrdinalIgnoreCase))
            throw new IOException(
                "The selected memory card must be locked before preparing its online profile.");
        if (!Directory.Exists(card))
            throw new IOException("The selected memory card folder is missing.");
        string directory = Path.Combine(card, "BWNETCNF");
        if (Directory.Exists(directory))
            return ExistingProfileDirectory(directory);
        // Atomic creation distinguishes our new directory from an existing one.
        if (!CreateDirectoryW(directory, 0)) {
            int error = Marshal.GetLastWin32Error();
            if (error == 183 && Directory.Exists(directory))
                return ExistingProfileDirectory(directory);
            throw new IOException(
                "Could not prepare the online profile on the selected memory card: " +
                new Win32Exception(error).Message);
        }
        try {
            using var marker = new FileStream(Path.Combine(directory, "BWNETDCNF"),
                                              FileMode.CreateNew, FileAccess.Write, FileShare.None);
            marker.Write(Encoding.UTF8.GetBytes(HostProfileMarker));
            marker.Flush(true);
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            // This branch owns the directory created above. Remove only that
            // directory, non-recursively, if no file appeared inside it.
            RemoveEmptyCreatedProfileDirectory(directory);
            throw new IOException(
                "Could not write the online profile marker on the selected memory card.", error);
        }
        return "created-host-profile-marker";
    }

    static string ExistingProfileDirectory(string directory) {
        if (!Directory.EnumerateFileSystemEntries(directory).Any())
            throw new IOException("The selected card has an empty BWNETCNF folder. Choose " +
                                  "another card or remove that empty folder before online launch.");
        return "existing-profile-directory";
    }

    internal static void RemoveEmptyCreatedProfileDirectory(string directory) {
        try {
            if (Directory.Exists(directory) &&
                (File.GetAttributes(directory) & FileAttributes.ReparsePoint) == 0 &&
                !Directory.EnumerateFileSystemEntries(directory).Any())
                Directory.Delete(directory, false);
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            System.Diagnostics.Debug.WriteLine(error);
        }
    }
}
