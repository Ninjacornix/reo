using System.IO;

namespace Outbreak.Launcher;
public record MemoryCardOption(string Name, string Folder) {
    public override string ToString() => Name;
}
public sealed partial class Settings {
    public string MemoryCardFile1 { get; set; } = "";
    public string MemoryCardFile2 { get; set; } = "";
    public List<MemoryCardOption> MemoryCards { get; set; } = new();
    public string CardFolder(string root) => Path.GetFullPath(
        (Game.Id == "file2" ? MemoryCardFile2 : MemoryCardFile1) is { Length : > 0 } selected
            ? selected
            : GameSession.SaveFolder(root, Game.Id));
    public void SelectCard(string folder) {
        if (Game.Id == "file2")
            MemoryCardFile2 = folder;
        else
            MemoryCardFile1 = folder;
    }
    public MemoryCardOption[] CardOptions(string root) {
        var existing =
            new MemoryCardOption("Default memory card", GameSession.SaveFolder(root, Game.Id));
        return new[] { existing }
            .Concat(MemoryCards ?? new())
            .DistinctBy(c => Path.GetFullPath(c.Folder), StringComparer.OrdinalIgnoreCase)
            .ToArray();
    }
}
public static class MemoryCards {
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
