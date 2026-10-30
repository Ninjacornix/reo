namespace Outbreak.Launcher;
public partial class MainWindow {
    sealed record AddressChoice(string Address, string Label) {
        public override string ToString() => Label;
    }
    CancellationTokenSource? publicLookup;
    string internetAddress = "";
    bool internetLookupAttempted;
    // Used only by isolated UI diagnostics; normal lookups use the existing address service.
    Func<CancellationToken, Task<string>>? publicAddressLookup;

    void RefreshHostAddresses(string? extra = null, string? extraLabel = null) {
        if (extra != null) internetAddress = extra;
        var choices = HostNetworking.LocalAddresses().Select(a => new AddressChoice(a.Address, a.Label)).ToList();
        if (internetAddress.Length > 0 && choices.All(c => c.Address != internetAddress))
            choices.Add(new(internetAddress, extraLabel ?? internetAddress + " (internet)"));
        string saved = settings.HostAddress;
        if (OnlineOptions.TryHost(saved, out _) && choices.All(c => c.Address != saved))
            choices.Add(new(saved, saved + " (saved)"));
        if (choices.Count == 0)
            choices.Add(new("127.0.0.1", "127.0.0.1 (this PC only: no network found)"));
        bool wasInitialized = initialized;
        initialized = false;
        try {
            HostAddressPicker.ItemsSource = choices;
            HostAddressPicker.SelectedItem = choices.FirstOrDefault(c => c.Address == saved) ?? choices[0];
            if (settings.HostAddress.Length == 0) settings.HostAddress = ((AddressChoice)HostAddressPicker.SelectedItem).Address;
        } finally { initialized = wasInitialized; }
    }

    async Task LookupPublicAddress() {
        if (publicLookup != null || (CoopUiDiagnostics && publicAddressLookup == null)) return;
        using var cancel = new CancellationTokenSource();
        publicLookup = cancel;
        internetLookupAttempted = true;
        PublicAddressStatus.Text = "";
        RefreshHostAddresses();
        try {
            string address = await (CoopUiDiagnostics ? publicAddressLookup!(cancel.Token) : HostNetworking.PublicAddress(cancel.Token));
            if (!OnlineOptions.TryHost(address, out address)) throw new System.IO.IOException("Invalid address response.");
            internetAddress = address;
        } catch (OperationCanceledException) when (cancel.IsCancellationRequested) {
        } catch {
            PublicAddressStatus.Text = "Internet address unavailable.";
        } finally {
            if (publicLookup == cancel) publicLookup = null;
            if (!cancel.IsCancellationRequested) RefreshHostAddresses();
        }
    }
}
