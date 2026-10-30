using System.IO;
using System.IO.Compression;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestMemoryCardsUi(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        var checks = new List<string>();
        void Check(bool condition, string message) {
            if (!condition) throw new IOException(message);
            checks.Add(message);
        }
        Settings Stored() => JsonSerializer.Deserialize<Settings>(File.ReadAllText(path))!;
        void Invoke(Button button) => ((IInvokeProvider)new ButtonAutomationPeer(button)
            .GetPattern(PatternInterface.Invoke)!).Invoke();
        void Create() => Invoke(CreateCardButton);
        async Task WaitFor(Func<bool> condition) {
            for (int i = 0; i < 150 && !condition(); i++) await Task.Delay(20);
            if (!condition()) throw new IOException($"Card UI did not settle: selected={SelectedCardName.Text}; deleteEnabled={DeleteCardButton.IsEnabled}; question={DeleteCardQuestion.Text}");
        }
        void Select(MemoryCardOption card) {
            CardSelection.ScrollIntoView(card); UpdateLayout();
            ((ISelectionItemProvider)new ListBoxItemAutomationPeer(card, new ListBoxAutomationPeer(CardSelection))
                .GetPattern(PatternInterface.SelectionItem)!).Select();
        }
        void Capture(string name) {
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home"), "Memory card diagnostics require an isolated data home");
            timer.Stop();
            settings.MemoryCards = new(); settings.MemoryCard = settings.MemoryCardFile1 = settings.MemoryCardFile2 = "";
            GamePicker.SelectedValue = "file1";
            ShowPage("Saves"); await Task.Delay(650);
            Check(CardSelection.Items.Count == 1 && SelectedCardName.Text == "Default memory card" &&
                FindName("CardEditionLabel") == null && CardPath.IsVisible,
                "The shared default card has no edition label and its location is always visible");
            Check(!DeleteCardButton.IsEnabled, "The default entry is kept as a fallback card");
            NewCardName.Text = " "; Create(); await Task.Delay(100);
            Check(CardCreateError.IsVisible && CardSelection.Items.Count == 1,
                "An empty name shows an inline error without creating a card");
            NewCardName.Text = "Kevin"; Create(); await Task.Delay(120);
            var kevin = (MemoryCardOption)CardSelection.SelectedItem;
            Check(kevin.Name == "Kevin" && Directory.Exists(kevin.Folder) &&
                Stored().MemoryCardFile1 == kevin.Folder && !CardCreateError.IsVisible && NewCardName.Text.Length == 0,
                "Creating a named profile creates its real data folder, selects it and persists the selection");
            NewCardName.Text = "Alyssa"; Create(); await Task.Delay(120);
            var alyssa = (MemoryCardOption)CardSelection.SelectedItem;
            Check(CardSelection.Items.Count == 3 && SelectedCardName.Text == "Alyssa" && SaveCount.Text == "Empty card",
                "Multiple profiles become individual entries and the selected card details update immediately");
            byte[] payload = Enumerable.Range(0, 257).Select(i => (byte)i).ToArray();
            Directory.CreateDirectory(Path.Combine(kevin.Folder, "BASLUS-20765"));
            File.WriteAllBytes(Path.Combine(kevin.Folder, "BASLUS-20765", "data"), payload);
            Select(kevin); await Task.Delay(100);
            Check(Stored().MemoryCardFile1 == kevin.Folder && SelectedCardName.Text == "Kevin" && SaveCount.Text == "1 file stored",
                "Selecting a profile through UI automation switches the real saved selection and file count");
            var items = CardSelection.ItemsSource; RefreshCards();
            Check(ReferenceEquals(items, CardSelection.ItemsSource), "Refreshing unchanged cards preserves list items and keyboard focus");
            GamePicker.SelectedValue = "file2"; await Task.Delay(100);
            Check(SelectedCardName.Text == "Kevin" && ReferenceEquals(items, CardSelection.ItemsSource),
                "Switching to File #2 preserves the same card list and selected profile");
            Select(alyssa); await Task.Delay(100);
            Check(Stored().MemoryCardFile2 == alyssa.Folder && Stored().MemoryCardFile1 == alyssa.Folder && Stored().MemoryCard == alyssa.Folder,
                "Selecting a card in File #2 persists the same selection for both games");
            GamePicker.SelectedValue = "file1"; await Task.Delay(100);
            Check(SelectedCardName.Text == "Alyssa" && settings.CardFolder(root) == alyssa.Folder,
                "File #1 uses the same card selected in File #2");
            Select(kevin);
            string archive = Path.Combine(output, "profile-backup.zip");
            await Task.Run(() => MemoryCards.Backup(settings.CardFolder(root), archive));
            using (var zip = ZipFile.OpenRead(archive)) {
                using var content = zip.GetEntry("BASLUS-20765/data")!.Open();
                using var bytes = new MemoryStream(); content.CopyTo(bytes);
                Check(bytes.ToArray().SequenceEqual(payload), "The existing backup service archives the selected profile's exact save bytes");
            }
            backingUp = true; RefreshCards();
            Check(!CardControls.IsEnabled && CardBusyHint.IsVisible, "Card switching and creation are disabled during backup");
            backingUp = false; launching = true; RefreshCards();
            Check(!CardControls.IsEnabled, "Card switching and creation are disabled during launch preparation");
            launching = false; RefreshCards();
            Check(CardControls.IsEnabled && !CardBusyHint.IsVisible, "Card controls recover when the busy operation ends");
            ShowPage("Audio"); ShowPage("Saves"); await Task.Delay(400);
            Check(currentPage == "Saves" && !pageTransition && PageContent.Opacity == 1 &&
                SelectedCardName.Text == "Kevin", "Rapid navigation completes the latest page's fade and preserves card selection");
            Capture("memory-cards");
            Width = MinWidth; Height = MinHeight; await Task.Delay(400); UpdateLayout();
            Check(CardSelection.ActualWidth >= 240 && SelectedCardName.ActualWidth >= 280 &&
                SelectedCardName.TranslatePoint(new Point(SelectedCardName.ActualWidth, 0), PageContent).X <= PageContent.ActualWidth,
                "The card list and details fit at the launcher's minimum window width");
            Capture("memory-cards-compact");
            for (int i = 0; i < 10; i++) settings.MemoryCards.Add(MemoryCards.Create("Profile " + (i + 1)));
            RefreshCards(); await Task.Delay(150);
            Select(settings.MemoryCards[^1]);
            Check(CardSelection.ActualHeight <= 312 && SelectedCardName.Text == "Profile 10" &&
                Stored().MemoryCardFile1 == settings.MemoryCards[^1].Folder,
                "A long profile list scrolls within its section and its last entry remains selectable");
            Capture("memory-cards-many");
            Width = 1320; Height = 920; await Task.Delay(200);
            Select(kevin); Invoke(DeleteCardButton); await WaitFor(() => DeleteCardPanel.IsVisible);
            Check(DeleteCardPanel.IsVisible && Directory.Exists(kevin.Folder) && Stored().MemoryCard == kevin.Folder,
                "Delete first displays a confirmation without touching the card or settings");
            Capture("memory-card-delete-confirmation");
            Invoke(CancelDeleteCardButton); await WaitFor(() => !DeleteCardPanel.IsVisible);
            Check(!DeleteCardPanel.IsVisible && File.ReadAllBytes(Path.Combine(kevin.Folder, "BASLUS-20765", "data")).SequenceEqual(payload),
                "Cancel keeps the card's exact save bytes and selected profile");
            bool locked = false;
            using (MemoryCards.Acquire(kevin.Folder)) {
                try { MemoryCards.DeleteProfile(settings, root, kevin); }
                catch (IOException) { locked = true; }
            }
            Check(locked && Directory.Exists(kevin.Folder) && Stored().MemoryCard == kevin.Folder,
                "An active card lease prevents deletion before any profile or save data changes");
            bool blocked = false;
            using (new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.Read)) {
                try { MemoryCards.DeleteProfile(settings, root, kevin); }
                catch (Exception error) when (error is IOException or UnauthorizedAccessException) { blocked = true; }
            }
            Check(blocked && settings.MemoryCards.Contains(kevin) && settings.CardFolder(root) == kevin.Folder &&
                File.ReadAllBytes(Path.Combine(kevin.Folder, "BASLUS-20765", "data")).SequenceEqual(payload),
                "A settings-save failure rolls back selection and keeps the card's original save bytes");
            Invoke(DeleteCardButton); await WaitFor(() => DeleteCardPanel.IsVisible);
            Invoke(ConfirmDeleteCardButton); await WaitFor(() => !DeleteCardPanel.IsVisible && !Directory.Exists(kevin.Folder));
            Check(!Directory.Exists(kevin.Folder) && !Stored().MemoryCards.Any(c => c.Folder == kevin.Folder) &&
                Stored().MemoryCard == Settings.DefaultCardFolder(root) && SelectedCardName.Text == "Default memory card",
                "Confirm sends a managed card to the Recycle Bin, removes its entry and selects the shared default");
            string external = Path.Combine(Settings.Home, "external-card-fixture", Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(external); File.WriteAllBytes(Path.Combine(external, "save"), payload);
            AddCard(new("Existing folder", external));
            Invoke(DeleteCardButton); await WaitFor(() => DeleteCardPanel.IsVisible && DeleteCardQuestion.Text.Contains("Existing folder"));
            Check(DeleteCardQuestion.Text.Contains("will be kept") && (string)ConfirmDeleteCardButton.Content == "Remove card",
                "An external folder is clearly removed from the list while preserving its saved data");
            Invoke(ConfirmDeleteCardButton); await WaitFor(() => !DeleteCardPanel.IsVisible);
            Check(File.ReadAllBytes(Path.Combine(external, "save")).SequenceEqual(payload) &&
                !Stored().MemoryCards.Any(c => c.Folder == external),
                "Removing an external card preserves its exact save bytes");
            Check(!MemoryCards.CanRecycle(Settings.Home) && !MemoryCards.CanRecycle(root) &&
                !MemoryCards.CanRecycle(Settings.DefaultCardFolder(root)),
                "Recycle ownership excludes the storage home, repository and default card");

            var legacy = new Settings { SelectedGame = "file2", MemoryCardFile1 = alyssa.Folder, MemoryCardFile2 = external };
            legacy.UpgradeMemoryCards(root);
            legacy.SelectedGame = "file1";
            Check(legacy.CardFolder(root) == external && legacy.CardOptions(root).Any(c => c.Folder == alyssa.Folder) &&
                legacy.CardOptions(root).Any(c => c.Folder == external) && File.ReadAllBytes(Path.Combine(external, "save")).SequenceEqual(payload),
                "Upgrading preserves both previous edition cards and keeps the active one shared without moving save data");
            legacy.UpgradeMemoryCards(root);
            Check(legacy.MemoryCards.Select(c => c.Folder).Distinct(StringComparer.OrdinalIgnoreCase).Count() == legacy.MemoryCards.Count,
                "Repeated upgrades keep one entry per card folder");
            string oldFirst = GameSession.LegacySaveFolder(root, "file1"), oldSecond = GameSession.LegacySaveFolder(root, "file2");
            Directory.CreateDirectory(oldFirst); Directory.CreateDirectory(oldSecond);
            string firstProof = Path.Combine(oldFirst, "migration-proof-" + Guid.NewGuid().ToString("N"));
            string secondProof = Path.Combine(oldSecond, "migration-proof-" + Guid.NewGuid().ToString("N"));
            try {
                File.WriteAllBytes(firstProof, payload); File.WriteAllBytes(secondProof, payload);
                var oldDefaults = new Settings { SelectedGame = "file2" };
                oldDefaults.UpgradeMemoryCards(root);
                oldDefaults.SelectedGame = "file1";
                Check(oldDefaults.CardFolder(root) == oldSecond && oldDefaults.CardOptions(root).Any(c => c.Folder == oldFirst) &&
                    oldDefaults.CardOptions(root).Any(c => c.Folder == oldSecond) &&
                    File.ReadAllBytes(firstProof).SequenceEqual(payload) && File.ReadAllBytes(secondProof).SequenceEqual(payload),
                    "Legacy default saves from both editions remain selectable and unchanged while the active card becomes shared");
                var removedLegacy = new Settings { MemoryCard = Settings.DefaultCardFolder(root) };
                removedLegacy.UpgradeMemoryCards(root);
                Check(removedLegacy.CardOptions(root).Length == 1,
                    "An already upgraded profile list does not restore old entries the user removed");
            } finally { File.Delete(firstProof); File.Delete(secondProof); }
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = true, checks, inputMethod = "Real WPF button and list-selection automation; isolated data home; actual profile persistence and ZIP contents."
            }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = false, checks, error = error.ToString()
            }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            backingUp = launching = false;
            timer.Stop(); audioSaveTimer.Stop(); colorSaveTimer.Stop();
            Close();
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
        }
    }
}
