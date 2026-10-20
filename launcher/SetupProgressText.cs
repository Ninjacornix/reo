namespace Outbreak.Launcher;

internal static class SetupProgressText {
    internal static string Counts(ImportProgress value) {
        if (value.Total <= 0)
            return "";
        long completed = Math.Clamp(value.Completed, 0, value.Total);
        string units = (value.Stage.StartsWith("Downloading", StringComparison.Ordinal) ||
                        value.Stage == "Importing existing build")
                           ? $"{completed / 1048576.0:0.0} / {value.Total / 1048576.0:0.0} MiB"
                           : $"{completed:N0} / {value.Total:N0}";
        return $"{units} \u00b7 {Math.Clamp(value.Percent, 0, 100):0}%";
    }
}
