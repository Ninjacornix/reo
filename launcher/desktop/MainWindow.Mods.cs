using Avalonia;
using Avalonia.Layout;
using Path = System.IO.Path;
using Avalonia.Controls;
using Avalonia.Controls.Shapes;
using Avalonia.Controls.Primitives;
using Avalonia.Automation;
using Avalonia.Input;
using Avalonia.Interactivity;
using Avalonia.Media;
using Avalonia.Media.Imaging;
using Outbreak.Launcher.Desktop.Compatibility;
using BitmapSource = Avalonia.Media.Imaging.Bitmap;
using PointCollection = Avalonia.Points;
using System.Diagnostics;
using System.IO;
using System.Globalization;

namespace Outbreak.Launcher.Desktop;
public partial class MainWindow {
    string modsGame = "";
    List<InstalledAssetPak> installedAssetPaks = new();
    void RefreshAssetPakSummary() {
        int count = installedAssetPaks.Count(p => p.Manifest?.Game == Settings.Game.Id && Settings.EnabledAssetPaks.Contains(p.Manifest.Id));
        PlayModsSummary.Text = count == 0 ? ModsSummary() : ModsSummary() + " / " + count + (count == 1 ? " asset pack" : " asset packs");
    }
    sealed class ModRow {
        internal required InstalledMod Mod;
        internal required CheckBox Toggle;
        internal Expander? Options;
        internal ComboBox? SeedMode;
        internal TextBox? SeedInput;
        internal Grid? CustomSeedRow;
        internal TextBlock? SeedError, Summary;
        internal bool Missing;
        internal required string Edition;
        internal required Button Delete;
        internal Button? ConfirmDelete, CancelDelete;
        internal StackPanel? DeleteConfirmation;
    }
    readonly List<ModRow> modRows = new();
    readonly HashSet<string> expandedModOptions = new();
    readonly Dictionary<string, string> modSeedDrafts = new();
    bool updatingModState;
    bool deletingMod;
    string ModKey(string id) => Settings.Game.Id + "/" + id;
    void UpdateRandomizerSeed() {
        ModSeed.Text = game.RandomizerSeedSummary == null ? "" :
            (game.Running || busy ? "Current session / " : "Last launch / ") + game.RandomizerSeedSummary;
        ModSeed.Visibility = game.RandomizerSeedSummary == null ? Visibility.Collapsed : Visibility.Visible;
    }
    void ReloadMods(object sender, RoutedEventArgs e) => RefreshMods();
    void RefreshMods() {
        modsGame = Settings.Game.Id;
        UpdateRandomizerSeed();
        ModList.Children.Clear();
        modRows.Clear();
        try {
            if (!game.Running && !busy) {
                bool changed = Mods.ConsolidateRandomizers(Settings);
                changed = Mods.EnsureBundledRandomizer(Settings) || changed;
                if (changed) Settings.Save();
            }
            var installed = Mods.Load(game: Settings.Game.Id);
            var shown = new HashSet<string>();
            foreach (var mod in installed) {
                string? id = mod.Manifest?.Id;
                AddModRow(mod, modRows.Count + 1);
                if (id != null) shown.Add(id);
            }
            foreach (string id in Settings.ActiveMods.Where(x => !shown.Contains(x)).Distinct()) {
                AddModRow(new InstalledMod(id, new ModManifest { Id = id, Name = id },
                    "Missing or invalid package. Import the mod again or remove this entry."), modRows.Count + 1, missing: true);
            }
            var assetPaks = AssetPaks.Load();
            installedAssetPaks = assetPaks;
            RefreshAssetPakSummary();
            foreach (var pak in assetPaks) {
                var manifest = pak.Manifest;
                if (manifest != null && manifest.Game != Settings.Game.Id) continue;
                string? id = manifest?.Id;
                bool enabled = id != null && Settings.EnabledAssetPaks.Contains(id);
                var row = new StackPanel { Margin = new Thickness(0, 10, 0, 10) };
                var toggle = new CheckBox {
                    Content = manifest == null ? Path.GetFileName(pak.File) : $"{manifest.Name} · {manifest.Version} · {manifest.Replace.Count} assets · {manifest.Strings.Count} strings",
                    IsChecked = enabled, IsEnabled = manifest != null && (pak.Error.Length == 0 || enabled), Tag = id
                };
                toggle.IsCheckedChanged += AssetPakToggled;

                row.Children.Add(toggle);
                row.Children.Add(new TextBlock { Text = pak.Error.Length > 0 ? pak.Error : manifest!.Description,
                    Style = (Compatibility.Style)FindResource("Hint"), TextWrapping = TextWrapping.Wrap, Margin = new Thickness(25, 5, 0, 0) });
                ModList.Children.Add(row);
            }
            foreach (string id in Settings.EnabledAssetPaks.Where(id => !assetPaks.Any(p => p.Manifest?.Id == id)).Distinct()) {
                var toggle = new CheckBox { Content = id + " — missing or invalid asset pack; untick to disable",
                    IsChecked = true, Tag = id, Margin = new Thickness(0, 10, 0, 10) };
                toggle.IsCheckedChanged += AssetPakToggled;
                ModList.Children.Add(toggle);
            }
            if (ModList.Children.Count == 0)
                ModList.Children.Add(new TextBlock { Text = "No mods installed. Import a .pak asset pack or mod JSON file to start.",
                    TextWrapping = TextWrapping.Wrap, Margin = new Thickness(0, 16, 0, 16) });
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
        UpdateModLayout();
        UpdateModState();
    }
    void AddModRow(InstalledMod installed, int number, bool missing = false) {
        var manifest = installed.Manifest;
        string title = manifest?.Name ?? Path.GetFileName(installed.File);
        string detail = installed.Error.Length > 0 ? installed.Error : manifest!.Description;
        var content = new Grid();
        content.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(34) });
        content.ColumnDefinitions.Add(new ColumnDefinition());
        content.Children.Add(new TextBlock { Text = number.ToString("00"), FontSize = 14,
            Foreground = VisualPalette.Brush(Palette.TextMuted), VerticalAlignment = VerticalAlignment.Center });
        var text = new StackPanel(); Grid.SetColumn(text, 1); content.Children.Add(text);
        var name = new Grid();
        name.ColumnDefinitions.Add(new ColumnDefinition()); name.ColumnDefinitions.Add(new ColumnDefinition { Width = GridLength.Auto });
        name.Children.Add(new TextBlock { Text = title, FontSize = 18, TextWrapping = TextWrapping.Wrap });
        var version = new TextBlock { Text = manifest?.Version.Length > 0 ? "v" + manifest.Version : "",
            FontSize = 14, Foreground = VisualPalette.Brush(Palette.TextMuted), Margin = new Thickness(14, 0, 0, 0), VerticalAlignment = VerticalAlignment.Center };
        Grid.SetColumn(version, 1); name.Children.Add(version); text.Children.Add(name);
        text.Children.Add(new TextBlock { Text = detail, Style = (Compatibility.Style)FindResource("Hint"), FontSize = 14,
            LineHeight = 20, TextWrapping = TextWrapping.Wrap, Margin = new Thickness(0, 3, 0, 0) });
        var toggle = new CheckBox { Content = content, Tag = manifest?.Id, Style = (Compatibility.Style)FindResource("ModOption"),
            IsChecked = manifest != null && Settings.ActiveMods.Contains(manifest.Id) };
        AutomationProperties.SetName(toggle, title);
        AutomationProperties.SetHelpText(toggle, detail);
        var delete = new Button { Content = missing ? "Remove entry" : "Delete", FontSize = 14,
            Padding = new Thickness(10, 5, 10, 5), VerticalAlignment = VerticalAlignment.Top };
        AutomationProperties.SetName(delete, "Delete " + title);
        var row = new ModRow { Mod = installed, Toggle = toggle, Missing = missing, Edition = Settings.Game.Id, Delete = delete };
        modRows.Add(row);
        toggle.IsCheckedChanged += ModToggled;
        var body = new StackPanel(); body.Children.Add(toggle);
        var actions = new Grid { Margin = new Thickness(46, 0, 12, 5) };
        actions.ColumnDefinitions.Add(new()); actions.ColumnDefinitions.Add(new() { Width = GridLength.Auto });
        Grid.SetColumn(delete, 1); actions.Children.Add(delete);
        if (!missing && installed.Error.Length == 0 && manifest != null && ModConfiguration.SupportsSeed(manifest)) {
            var options = CreateModOptions(row, manifest);
            options.Margin = new Thickness(0, 0, 12, 0);
            actions.Children.Add(options);
        }
        body.Children.Add(actions);
        delete.Click += (_, _) => AskDeleteMod(row, body, title);
        ModList.Children.Add(body);
    }
    Expander CreateModOptions(ModRow row, ModManifest manifest) {
        string id = manifest.Id, key = ModKey(id);
        uint fallback = manifest.ItemRandomizer?.Seed ?? manifest.WeaponShuffle?.Seed ?? manifest.EnemyRandomizer!.Seed;
        var configuration = Settings.ConfigurationFor(id, fallback);
        var header = new Grid(); header.ColumnDefinitions.Add(new ColumnDefinition());
        header.ColumnDefinitions.Add(new ColumnDefinition { Width = GridLength.Auto });
        header.Children.Add(new TextBlock { Text = "Options", FontSize = 14 });
        row.Summary = new TextBlock { FontSize = 14, Foreground = VisualPalette.Brush(Palette.TextMuted), Margin = new Thickness(12, 0, 12, 0) };
        Grid.SetColumn(row.Summary, 1); header.Children.Add(row.Summary);
        var panel = new StackPanel();
        var modeRow = new Grid { Margin = new Thickness(0, 0, 0, 10) };
        modeRow.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(140) }); modeRow.ColumnDefinitions.Add(new ColumnDefinition());
        modeRow.Children.Add(new TextBlock { Text = "Seed", FontSize = 16, VerticalAlignment = VerticalAlignment.Center });
        row.SeedMode = new ComboBox { ItemsSource = new[] { "New seed each launch", "Custom seed" },
            SelectedIndex = configuration.UseCustomSeed ? 1 : 0, HorizontalAlignment = HorizontalAlignment.Left, MinWidth = 250 };
        AutomationProperties.SetName(row.SeedMode, manifest.Name + " seed mode");
        Grid.SetColumn(row.SeedMode, 1); modeRow.Children.Add(row.SeedMode); panel.Children.Add(modeRow);
        row.CustomSeedRow = new Grid { Margin = new Thickness(0, 0, 0, 8) };
        row.CustomSeedRow.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(140) }); row.CustomSeedRow.ColumnDefinitions.Add(new ColumnDefinition());
        row.CustomSeedRow.Children.Add(new TextBlock { Text = "Seed value", FontSize = 16, VerticalAlignment = VerticalAlignment.Center });
        row.SeedInput = new TextBox { Text = modSeedDrafts.TryGetValue(key, out var draft) ? draft : configuration.Seed.ToString(CultureInfo.InvariantCulture),
            Width = 250, MaxLength = 10, HorizontalAlignment = HorizontalAlignment.Left };
        AutomationProperties.SetName(row.SeedInput, manifest.Name + " custom seed");
        AutomationProperties.SetHelpText(row.SeedInput, "A whole number from 0 to 4294967295. The same seed is used for this mod's item, weapon and enemy randomizers.");
        Grid.SetColumn(row.SeedInput, 1); row.CustomSeedRow.Children.Add(row.SeedInput); panel.Children.Add(row.CustomSeedRow);
        row.SeedError = new TextBlock { FontSize = 14, Foreground = VisualPalette.Brush(Palette.Accent), TextWrapping = TextWrapping.Wrap, Margin = new Thickness(0, 0, 0, 6) };
        panel.Children.Add(row.SeedError);
        panel.Children.Add(new TextBlock { Text = "Use the same seed and mod Settings to repeat a run. Joining players use the host's seed.",
            Style = (Compatibility.Style)FindResource("Hint"), FontSize = 14, TextWrapping = TextWrapping.Wrap });
        var options = new Expander { Header = header, Content = panel, Style = (Compatibility.Style)FindResource("ModOptionsDropdown"),
            Margin = new Thickness(46, 0, 0, 5), IsExpanded = expandedModOptions.Contains(key) };
        AutomationProperties.SetName(options, manifest.Name + " options"); row.Options = options;
        options.Expanded += (_, _) => expandedModOptions.Add(key);
        options.Collapsed += (_, _) => expandedModOptions.Remove(key);
        row.SeedMode.SelectionChanged += (_, _) => {
            if (game.Running || busy) return;
            var previous = Settings.ConfigurationFor(id, fallback);
            Settings.SetConfiguration(id, new() { UseCustomSeed = row.SeedMode.SelectedIndex == 1, Seed = previous.Seed });
            SaveModPreferences(); UpdateModSeedControls(row, fallback);
        };
        row.SeedInput.TextChanged += (_, _) => {
            if (game.Running || busy) return;
            modSeedDrafts[key] = row.SeedInput.Text;
            if (ModConfiguration.TrySeed(row.SeedInput.Text, out uint seed)) {
                var previous = Settings.ConfigurationFor(id, fallback);
                Settings.SetConfiguration(id, new() { UseCustomSeed = previous.UseCustomSeed, Seed = seed });
                SaveModPreferences();
            }
            UpdateModSeedControls(row, fallback);
        };
        row.SeedInput.KeyDown += (_, e) => { if (e.Key == Key.Enter) { e.Handled = true; if (ModConfiguration.TrySeed(row.SeedInput.Text, out uint _)) options.Focus(); } };
        UpdateModSeedControls(row, fallback);
        return options;
    }
    void UpdateModSeedControls(ModRow row, uint fallback) {
        var options = Settings.ConfigurationFor(row.Mod.Manifest!.Id, fallback);
        bool valid = ModConfiguration.TrySeed(row.SeedInput!.Text, out _);
        row.CustomSeedRow!.Visibility = options.UseCustomSeed ? Visibility.Visible : Visibility.Collapsed;
        row.SeedInput.IsEnabled = options.UseCustomSeed;
        row.SeedError!.Text = "Enter a whole number from 0 to 4294967295. The last saved seed is preserved.";
        row.SeedError.Visibility = options.UseCustomSeed && !valid ? Visibility.Visible : Visibility.Collapsed;
        row.Summary!.Text = options.UseCustomSeed ? valid ? "Custom seed / " + options.Seed : "Invalid seed" : "New seed each launch";
    }
    void UpdateModLayout() {
        bool compact = (Bounds.Height > 0 ? Bounds.Height : Height) < 760;
        foreach (var row in modRows) {
            row.Toggle.MinHeight = compact ? 54 : 64;
            row.Toggle.Padding = new Thickness(12, compact ? 5 : 9, 12, compact ? 5 : 9);
        }
    }
    void UpdateModState() {
        bool locked = game.Running || busy;
        ModControls.IsEnabled = !locked && !deletingMod;
        ModGame.Text = Settings.Game.Id == "file1" ? "FILE #1" : "FILE #2";
        bool joining = Settings.ResolvedCoopMode == "join";
        ModSessionNote.Visibility = locked || joining ? Visibility.Visible : Visibility.Collapsed;
        ModSessionNote.Text = locked ? "Stop the game to change mods. Your Settings are preserved."
            : "Joining uses the host's mods and seed. Your local Settings are kept for solo play or hosting.";
        ModSelectionState.Text = $"{Settings.ActiveMods.Distinct().Count()} enabled";
        updatingModState = true;
        foreach (var row in modRows) {
            row.Toggle.IsChecked = row.Mod.Manifest != null && Settings.ActiveMods.Contains(row.Mod.Manifest.Id);
            row.Toggle.IsEnabled = row.Mod.Manifest != null &&
                ((!row.Missing && row.Mod.Error.Length == 0) || row.Toggle.IsChecked == true);
        }
        updatingModState = false;
    }
    void SaveModPreferences() {
        try { Settings.Save(); RefreshGameUi(); }
        catch (Exception error) when (error is IOException or UnauthorizedAccessException) { Status.Text = "Mod Settings could not be saved: " + error.Message; }
    }
    void AskDeleteMod(ModRow row, StackPanel body, string title) {
        if (game.Running || busy || deletingMod || row.Edition != Settings.Game.Id) return;
        if (row.DeleteConfirmation != null) {
            row.DeleteConfirmation.Visibility = Visibility.Visible;
            row.CancelDelete!.Focus();
            return;
        }
        var panel = new StackPanel { Margin = new Thickness(46, 10, 12, 14) };
        panel.Children.Add(new TextBlock { Text = row.Missing ? $"Remove the missing entry “{title}”?" :
            $"Move “{title}” to the Recycle Bin?", FontSize = 15, TextWrapping = TextWrapping.Wrap });
        var buttons = new WrapPanel { Margin = new Thickness(0, 12, 0, 0) };
        row.ConfirmDelete = new Button { Content = row.Missing ? "Remove entry" : "Delete mod",
            FontSize = 14, Margin = new Thickness(0, 0, 8, 0), Background = VisualPalette.Brush(Palette.AccentDeep),
            BorderBrush = VisualPalette.Brush(Palette.Accent) };
        row.CancelDelete = new Button { Content = "Cancel", FontSize = 14 };
        AutomationProperties.SetName(row.ConfirmDelete, "Confirm deletion of " + title);
        row.CancelDelete.Click += (_, _) => { panel.Visibility = Visibility.Collapsed; row.Delete.Focus(); };
        row.ConfirmDelete.Click += (_, _) => DeleteMod(row);
        buttons.Children.Add(row.ConfirmDelete); buttons.Children.Add(row.CancelDelete);
        panel.Children.Add(buttons); row.DeleteConfirmation = panel; body.Children.Add(panel);
        row.CancelDelete.Focus();
    }
    void DeleteMod(ModRow row) {
        if (game.Running || busy || deletingMod || row.Edition != Settings.Game.Id || !modRows.Contains(row)) return;
        deletingMod = true; UpdateModState();
        try {
            Mods.Delete(Settings, row.Mod, row.Missing);
            if (row.Mod.Manifest is { } manifest && !Mods.Load(game: Settings.Game.Id).Any(m => m.Manifest?.Id == manifest.Id)) {
                modSeedDrafts.Remove(ModKey(manifest.Id)); expandedModOptions.Remove(ModKey(manifest.Id));
            }
            RefreshMods(); RefreshGameUi();
            Status.Text = row.Missing ? "Missing mod entry removed." : "Mod moved to the Recycle Bin.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or OperationCanceledException) {
            Status.Text = "Could not delete mod: " + error.Message;
        } finally { deletingMod = false; UpdateModState(); }
    }
    string? ModConfigurationProblem() {
        if (Settings.ResolvedCoopMode == "join") return null;
        foreach (string id in Settings.ActiveMods) {
            if (Settings.ConfigurationFor(id).UseCustomSeed && modSeedDrafts.TryGetValue(ModKey(id), out string? text) && !ModConfiguration.TrySeed(text, out _))
                return "Correct the custom seed in Mods before busy. Use a whole number from 0 to 4294967295.";
        }
        return null;
    }
    void AssetPakToggled(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || busy || ((CheckBox)sender).Tag is not string id) return;
        Settings.EnabledAssetPaks.RemoveAll(value => value == id);
        if (((CheckBox)sender).IsChecked == true) Settings.EnabledAssetPaks.Add(id);
        try { Settings.Save(); Status.Text = "Asset packs saved. Changes apply on next solo launch."; }
        catch (IOException error) { Status.Text = error.Message; }
        RefreshMods();
    }
    void ModToggled(object sender, RoutedEventArgs e) {
        if (!initialized || updatingModState || game.Running || busy) return;
        var box = (CheckBox)sender;
        if (box.Tag is not string id) return;
        Settings.ActiveMods.RemoveAll(x => x == id);
        if (box.IsChecked == true) Settings.ActiveMods.Add(id);
        try {
            Settings.Save(); UpdateModState(); RefreshGameUi();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) { Status.Text = error.Message; }
    }
    async void ImportMod(object sender, RoutedEventArgs e) {
        if (game.Running || busy || busy || busy || busy || importCancellation != null) return;
        var dialog = new OpenFileDialog { Filter = "Outbreak mods (*.pak;*.json)|*.pak;*.json|Asset packs (*.pak)|*.pak|JSON mods (*.json)|*.json" };
        if (await dialog.ShowDialog(this) != true) return;
        string source = dialog.FileName;
        SetLaunching(true);
        try {
            var progress = BeginDiscImport(); RefreshGameUi();
            progress.Report(new(0, 0, "Reading edited assets and translations", "Importing mod"));
            var cancel = importCancellation!.Token;
            await Task.Run(() => {
                if (Path.GetExtension(source).Equals(".pak", StringComparison.OrdinalIgnoreCase)) AssetPaks.Import(source, cancel: cancel);
                else Mods.Import(source, game: Settings.Game.Id);
            }, cancel);
            Status.Text = "Mod imported. Tick it to enable.";
        } catch (OperationCanceledException) { Status.Text = "Mod import canceled. Previous mods are kept.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        } finally { SetLaunching(false); EndDiscImport(); RefreshGameUi(); }
        RefreshMods();
    }
    void OpenModFolder(object sender, RoutedEventArgs e) {
        try {
            Directory.CreateDirectory(Mods.FolderFor(Settings.Game.Id));
            Directory.CreateDirectory(AssetPaks.Folder);
            Process.Start(new ProcessStartInfo(Path.GetDirectoryName(AssetPaks.Folder)!) { UseShellExecute = true });
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or System.ComponentModel.Win32Exception) {
            Status.Text = error.Message;
        }
    }
}
