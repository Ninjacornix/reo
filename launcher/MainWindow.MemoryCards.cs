using Microsoft.Win32;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace Outbreak.Launcher;
public partial class MainWindow {
    bool refreshingCards;
    void RefreshCards() {
        refreshingCards = true;
        try {
            var choices = settings.CardOptions(root);
            CardSelection.ItemsSource = choices;
            CardSelection.SelectedItem = choices.FirstOrDefault(
                c => string.Equals(Path.GetFullPath(c.Folder), settings.CardFolder(root),
                                   StringComparison.OrdinalIgnoreCase));
            CardPath.Text = settings.CardFolder(root);
        } finally {
            refreshingCards = false;
        }
        CardControls.IsEnabled = !game.Running && !launching && !backingUp;
    }
    void CardChanged(object sender, SelectionChangedEventArgs e) {
        if (!initialized || refreshingCards || game.Running || launching ||
            CardSelection.SelectedItem is not MemoryCardOption card)
            return;
        settings.SelectCard(card.Folder);
        try {
            settings.Save();
            UpdateSaves();
            RefreshReadyCheck();
            Status.Text = "Memory card selected.";
        } catch (IOException error) {
            Status.Text = error.Message;
        }
    }
    void AddCard(MemoryCardOption card) {
        settings.MemoryCards ??= new();
        if (!settings.MemoryCards.Any(
                c => string.Equals(c.Folder, card.Folder, StringComparison.OrdinalIgnoreCase)))
            settings.MemoryCards.Add(card);
        settings.SelectCard(card.Folder);
        settings.Save();
        UpdateSaves();
        RefreshReadyCheck();
    }
    void CreateCard(object sender, RoutedEventArgs e) {
        if (game.Running || launching || backingUp)
            return;
        try {
            AddCard(MemoryCards.Create(NewCardName.Text));
            NewCardName.Clear();
            Status.Text = "Memory card created.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
    }
    void BrowseCard(object sender, RoutedEventArgs e) {
        if (game.Running || launching || backingUp)
            return;
        var dialog = new OpenFolderDialog { Title = "Choose a folder-backed PS2 memory card",
                                            Multiselect = false };
        if (dialog.ShowDialog(this) != true)
            return;
        try {
            AddCard(new MemoryCardOption(new DirectoryInfo(dialog.FolderName).Name,
                                         Path.GetFullPath(dialog.FolderName)));
            Status.Text = "Memory card selected.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = error.Message;
        }
    }
}
