using Microsoft.Win32;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Outbreak.Launcher;
public partial class MainWindow {
    bool refreshingCards;
    bool deletingCard;
    MemoryCardOption? cardToDelete;
    void RefreshCards() {
        refreshingCards = true;
        try {
            var choices = settings.CardOptions(root);
            if (CardSelection.ItemsSource is not MemoryCardOption[] previous || !previous.SequenceEqual(choices))
                CardSelection.ItemsSource = choices;
            CardSelection.SelectedItem = choices.FirstOrDefault(
                c => string.Equals(Path.GetFullPath(c.Folder), settings.CardFolder(root),
                                   StringComparison.OrdinalIgnoreCase));
            CardPath.Text = settings.CardFolder(root);
            SelectedCardName.Text = (CardSelection.SelectedItem as MemoryCardOption)?.Name ?? "Current memory card";
            if (cardToDelete != null && cardToDelete != CardSelection.SelectedItem as MemoryCardOption) CancelDeleteCard(this, new());
        } finally {
            refreshingCards = false;
        }
        RefreshCardAvailability();
    }
    void RefreshCardAvailability() {
        CardControls.IsEnabled = !updating && !game.Running && !launching && !backingUp;
        DeleteCardButton.IsEnabled = CardControls.IsEnabled && CardSelection.SelectedItem is MemoryCardOption card &&
            settings.MemoryCards.Any(c => c.Folder.Equals(card.Folder, StringComparison.OrdinalIgnoreCase)) &&
            !Path.GetFullPath(card.Folder).Equals(Path.GetFullPath(Settings.DefaultCardFolder(root)), StringComparison.OrdinalIgnoreCase);
        DeleteCardButton.Content = CardSelection.SelectedItem is MemoryCardOption selected && !MemoryCards.CanRecycle(selected.Folder)
            ? "Remove card" : "Delete card";
        DeleteCardPanel.IsEnabled = CardControls.IsEnabled;
        CardBusyHint.Visibility = CardControls.IsEnabled ? Visibility.Collapsed : Visibility.Visible;
        CardBusyHint.Text = deletingCard ? "Deleting this card..." : backingUp ? "Backing up this card..." : updating ? "Wait for the update to finish." : "Close the game to switch cards.";
    }
    void CardChanged(object sender, SelectionChangedEventArgs e) {
        if (!initialized || refreshingCards || game.Running || launching || backingUp ||
            CardSelection.SelectedItem is not MemoryCardOption card)
            return;
        string previous = settings.CardFolder(root);
        settings.SelectCard(card.Folder);
        try {
            settings.Save();
            UpdateSaves();
            RefreshReadyCheck();
            Status.Text = "Memory card selected.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            settings.SelectCard(previous);
            RefreshCards();
            Status.Text = error.Message;
        }
    }
    void AddCard(MemoryCardOption card) {
        settings.MemoryCards ??= new();
        var previousCards = settings.MemoryCards.ToList();
        string previous = settings.CardFolder(root);
        if (!settings.MemoryCards.Any(
                c => string.Equals(c.Folder, card.Folder, StringComparison.OrdinalIgnoreCase)))
            settings.MemoryCards.Add(card);
        settings.SelectCard(card.Folder);
        try { settings.Save(); }
        catch {
            settings.MemoryCards = previousCards;
            settings.SelectCard(previous);
            throw;
        }
        UpdateSaves();
        RefreshReadyCheck();
    }
    void CreateCard(object sender, RoutedEventArgs e) {
        if (game.Running || launching || backingUp)
            return;
        try {
            CardCreateError.Visibility = Visibility.Collapsed;
            AddCard(MemoryCards.Create(NewCardName.Text));
            NewCardName.Clear();
            Status.Text = "Memory card created.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            CardCreateError.Text = error.Message;
            CardCreateError.Visibility = Visibility.Visible;
            Status.Text = error.Message;
        }
    }
    void CardNameKeyDown(object sender, KeyEventArgs e) {
        if (e.Key != Key.Enter) return;
        CreateCard(sender, e);
        e.Handled = true;
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
    void AskDeleteCard(object sender, RoutedEventArgs e) {
        if (!DeleteCardButton.IsEnabled || CardSelection.SelectedItem is not MemoryCardOption card) return;
        cardToDelete = card;
        bool recycle = MemoryCards.CanRecycle(card.Folder);
        DeleteCardQuestion.Text = recycle ? $"Move “{card.Name}” and its save data to the Recycle Bin?" :
            $"Remove “{card.Name}” from the launcher? Its folder and save data will be kept.";
        ConfirmDeleteCardButton.Content = recycle ? "Move to Recycle Bin" : "Remove card";
        DeleteCardPanel.Visibility = Visibility.Visible;
        CancelDeleteCardButton.Focus();
    }
    void CancelDeleteCard(object sender, RoutedEventArgs e) {
        cardToDelete = null;
        DeleteCardPanel.Visibility = Visibility.Collapsed;
    }
    void ConfirmDeleteCard(object sender, RoutedEventArgs e) {
        if (cardToDelete is not { } card || !CardControls.IsEnabled) return;
        backingUp = deletingCard = true;
        RefreshCardAvailability();
        try {
            bool recycled = MemoryCards.CanRecycle(card.Folder);
            MemoryCards.DeleteProfile(settings, root, card);
            CancelDeleteCard(sender, e);
            UpdateSaves(); RefreshReadyCheck();
            Status.Text = recycled ? "Memory card moved to the Recycle Bin." : "Memory card removed. Its folder was kept.";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException or OperationCanceledException) {
            Status.Text = error.Message;
        } finally {
            backingUp = deletingCard = false;
            RefreshCards();
        }
    }
}
