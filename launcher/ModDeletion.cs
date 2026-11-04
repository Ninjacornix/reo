using System.IO;

namespace Outbreak.Launcher;
public static partial class Mods {
    internal static void Delete(Settings settings, InstalledMod mod, bool missing = false) {
        string folder = Path.GetFullPath(FolderFor(settings.Game.Id));
        string? path = missing ? null : Path.GetFullPath(mod.File);
        if (path != null) {
            if (!string.Equals(Path.GetDirectoryName(path), folder, StringComparison.OrdinalIgnoreCase) ||
                !Path.GetExtension(path).Equals(".json", StringComparison.OrdinalIgnoreCase))
                throw new IOException("Choose a package in the selected game's mods folder.");
            for (var entry = new DirectoryInfo(folder); entry != null; entry = entry.Parent) {
                if (entry.Exists && entry.Attributes.HasFlag(FileAttributes.ReparsePoint))
                    throw new IOException("Cannot delete a mod through a symbolic link.");
                if (entry.FullName.Equals(Path.GetFullPath(Settings.Home), StringComparison.OrdinalIgnoreCase)) break;
            }
            if (File.Exists(path) && File.GetAttributes(path).HasFlag(FileAttributes.ReparsePoint))
                throw new IOException("Cannot delete a mod through a symbolic link.");
        }
        string? id = mod.Manifest?.Id;
        bool anotherPackage = id != null && Load(game: settings.Game.Id).Any(other =>
            other.Manifest?.Id == id && !string.Equals(other.File, path, StringComparison.OrdinalIgnoreCase));
        bool removePreferences = id != null && !anotherPackage;
        var previousMods = settings.ActiveMods.ToList();
        settings.ModConfigurations ??= new();
        bool hadConfigurations = settings.ModConfigurations.TryGetValue(settings.Game.Id, out var configurations);
        var previousConfigurations = configurations == null ? null : new Dictionary<string, ModConfiguration>(configurations);
        bool changed = false;
        if (removePreferences) {
            changed = settings.ActiveMods.RemoveAll(value => value == id) > 0;
            changed |= configurations?.Remove(id!) == true;
        }
        void Restore() {
            settings.ActiveMods = previousMods;
            if (hadConfigurations && previousConfigurations != null)
                settings.ModConfigurations[settings.Game.Id] = previousConfigurations;
            else settings.ModConfigurations.Remove(settings.Game.Id);
        }
        try { if (changed) settings.Save(); }
        catch { Restore(); throw; }
        try {
            if (path != null && File.Exists(path))
                Microsoft.VisualBasic.FileIO.FileSystem.DeleteFile(path,
                    Microsoft.VisualBasic.FileIO.UIOption.OnlyErrorDialogs,
                    Microsoft.VisualBasic.FileIO.RecycleOption.SendToRecycleBin,
                    Microsoft.VisualBasic.FileIO.UICancelOption.ThrowException);
        } catch {
            Restore();
            if (changed) settings.Save();
            throw;
        }
    }
}
