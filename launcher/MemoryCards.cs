using System.IO;

namespace Outbreak.Launcher;
public record MemoryCardOption(string Name, string Folder) {
    public override string ToString() => Name;
}
public sealed partial class Settings {
    // Legacy fields remain readable for upgrades and older launcher versions.
    public string MemoryCardFile1 { get; set; } = "";
    public string MemoryCardFile2 { get; set; } = "";
    public string MemoryCard { get; set; } = "";
    public List<MemoryCardOption> MemoryCards { get; set; } = new();
    public static string DefaultCardFolder(string root) =>
        Path.Combine(Home, "memory-cards", "default", "data");
    public string CardFolder(string root) => Path.GetFullPath(
        MemoryCard.Length > 0 ? MemoryCard : MemoryCardFile1.Length > 0 ? MemoryCardFile1 :
        MemoryCardFile2.Length > 0 ? MemoryCardFile2 : DefaultCardFolder(root));
    public void SelectCard(string folder) => MemoryCard = MemoryCardFile1 = MemoryCardFile2 = folder;
    public MemoryCardOption[] CardOptions(string root) =>
        new[] { new MemoryCardOption("Default memory card", DefaultCardFolder(root)) }
            .Concat(MemoryCards ?? new())
            .DistinctBy(c => Path.GetFullPath(c.Folder), StringComparer.OrdinalIgnoreCase).ToArray();

    internal void UpgradeMemoryCards(string root) {
        MemoryCards ??= new();
        MemoryCard ??= ""; MemoryCardFile1 ??= ""; MemoryCardFile2 ??= "";
        string first = MemoryCardFile1, second = MemoryCardFile2;
        string firstDefault = GameSession.LegacySaveFolder(root, "file1"), secondDefault = GameSession.LegacySaveFolder(root, "file2");
        bool HasFiles(string folder) {
            try { return Directory.Exists(folder) && Directory.EnumerateFiles(folder, "*", SearchOption.AllDirectories).Any(); }
            catch (Exception error) when (error is IOException or UnauthorizedAccessException) { return Directory.Exists(folder); }
        }
        void Keep(string folder, string name) {
            if (folder.Length == 0 || Path.GetFullPath(folder).Equals(Path.GetFullPath(DefaultCardFolder(root)), StringComparison.OrdinalIgnoreCase)) return;
            if (!MemoryCards.Any(c => Path.GetFullPath(c.Folder).Equals(Path.GetFullPath(folder), StringComparison.OrdinalIgnoreCase)))
                MemoryCards.Add(new(name, Path.GetFullPath(folder)));
        }
        Keep(first, "Previous memory card"); Keep(second, "Previous memory card 2");
        if (MemoryCard.Length == 0) {
            if (HasFiles(firstDefault)) Keep(firstDefault, "Outbreak saves");
            if (HasFiles(secondDefault)) Keep(secondDefault, "Outbreak File 2 saves");
            string preferred = Game.Id == "file2" ? second : first, alternate = Game.Id == "file2" ? first : second;
            string preferredDefault = Game.Id == "file2" ? secondDefault : firstDefault;
            string alternateDefault = Game.Id == "file2" ? firstDefault : secondDefault;
            MemoryCard = preferred.Length > 0 ? preferred : alternate.Length > 0 ? alternate :
                HasFiles(preferredDefault) ? preferredDefault : HasFiles(alternateDefault) ? alternateDefault : DefaultCardFolder(root);
        }
        SelectCard(MemoryCard);
    }
}

public static class MemoryCards {
    internal static bool CanRecycle(string folder) {
        string managed = Path.GetFullPath(Path.Combine(Settings.Home, "memory-cards"));
        folder = Path.GetFullPath(folder);
        string[] parts = Path.GetRelativePath(managed, folder).Split(Path.DirectorySeparatorChar);
        if (parts.Length != 2 || !Guid.TryParseExact(parts[0], "N", out _) || parts[1] != "data") return false;
        for (var current = new DirectoryInfo(folder); current != null; current = current.Parent) {
            if (current.Exists && current.Attributes.HasFlag(FileAttributes.ReparsePoint)) return false;
            if (current.FullName.Equals(managed, StringComparison.OrdinalIgnoreCase)) return true;
        }
        return false;
    }

    internal static void DeleteProfile(Settings settings, string root, MemoryCardOption card) {
        string folder = Path.GetFullPath(card.Folder);
        bool Same(string path) => Path.GetFullPath(path).Equals(folder, StringComparison.OrdinalIgnoreCase);
        if (Same(Settings.DefaultCardFolder(root)) || !settings.MemoryCards.Any(c => Same(c.Folder)))
            throw new IOException("The default memory card cannot be removed.");
        bool recycle = CanRecycle(folder) && Directory.Exists(folder);
        // The lease lives beside data, so it stays held while that folder is recycled.
        using var lease = recycle ? Acquire(folder) : null;
        var previousCards = settings.MemoryCards.ToList();
        string previous = settings.CardFolder(root);
        settings.MemoryCards = settings.MemoryCards.Where(c => !Same(c.Folder)).ToList();
        if (Same(previous)) settings.SelectCard(Settings.DefaultCardFolder(root));
        try { settings.Save(); }
        catch { settings.MemoryCards = previousCards; settings.SelectCard(previous); throw; }
        try {
            if (recycle)
#if REO_CROSS_PLATFORM
            if (!OperatingSystem.IsWindows()) PlatformServices.Trash(folder); else
#endif
            Microsoft.VisualBasic.FileIO.FileSystem.DeleteDirectory(folder,
                Microsoft.VisualBasic.FileIO.UIOption.OnlyErrorDialogs,
                Microsoft.VisualBasic.FileIO.RecycleOption.SendToRecycleBin,
                Microsoft.VisualBasic.FileIO.UICancelOption.ThrowException);
        } catch {
            settings.MemoryCards = previousCards; settings.SelectCard(previous); settings.Save();
            throw;
        }
    }
    public static void Backup(string folder, string destination) {
        folder = Path.TrimEndingDirectorySeparator(Path.GetFullPath(folder));
        destination = Path.GetFullPath(destination);
        if (destination.Equals(folder, StringComparison.OrdinalIgnoreCase) ||
            destination.StartsWith(folder + Path.DirectorySeparatorChar, StringComparison.OrdinalIgnoreCase))
            throw new IOException("Choose a backup location outside the memory-card folder.");
        if (!Directory.Exists(folder))
            throw new IOException("The selected memory-card folder is missing.");
        using var lease = Acquire(folder);
        string temporary = destination + "." + Guid.NewGuid().ToString("N") + ".tmp";
        try {
            // Include runtime metadata so extracting the ZIP preserves the whole card.
            System.IO.Compression.ZipFile.CreateFromDirectory(folder, temporary);
            File.Move(temporary, destination, true);
        } finally {
            if (File.Exists(temporary)) File.Delete(temporary);
        }
    }
    public static MemoryCardOption Create(string name, string? home = null) {
        name = name.Trim();
        if (name.Length == 0 || name.Length > 64)
            throw new IOException("Enter a card name of 1–64 characters.");
        string folder = Path.Combine(home ?? Path.Combine(Settings.Home, "memory-cards"),
                                     Guid.NewGuid().ToString("N"), "data");
        Directory.CreateDirectory(folder);
        return new(name, folder);
    }
    public static FileStream Acquire(string folder) {
        Directory.CreateDirectory(folder);
        return new FileStream(folder.TrimEnd(Path.DirectorySeparatorChar) + ".reo-lock",
                              FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.None);
    }
}
