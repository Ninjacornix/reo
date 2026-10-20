using System.IO;
using System.Windows;
using System.Windows.Media;

namespace Outbreak.Launcher;

public partial class MainWindow {
    readonly HostedServer hostedServer = new();
    bool serverStarting;
    CancellationTokenSource? accountPreparation;
    string? preparedAccount;
    async void AccountConfirmed(object sender, RoutedEventArgs e) => await PrepareLauncherAccount();
    async void AccountKeyDown(object sender, System.Windows.Input.KeyEventArgs e) {
        if (e.Key != System.Windows.Input.Key.Enter)
            return;
        e.Handled = true;
        await PrepareLauncherAccount();
    }
    async void CreateAccountClicked(object sender, RoutedEventArgs e) {
        if (!initialized || game.Running || launching)
            return;
        if (!OnlineOptions.Configured(settings)) {
            AccountStatus.Text =
                OnlineOptions.Error(settings) ?? "Enter the server address and a username first.";
            return;
        }
        await PrepareLauncherAccount();
    }
    async Task PrepareLauncherAccount() {
        if (!initialized || !OnlineOptions.Configured(settings) || game.Running || launching)
            return;
        OnlineOptions.TryHost(settings.CoopHost, out string host);
        string username = settings.AccountUsername;
        string identity = host + "\n" + username;
        if (preparedAccount == identity)
            return;
        accountPreparation?.Cancel();
        using var cancel = new CancellationTokenSource();
        accountPreparation = cancel;
        AccountStatus.Text = "Preparing account...";
        CreateAccountButton.IsEnabled = false;
        try {
            // Hosting: register with our own server directly on this PC. Many routers cannot reach their own
            // public address from inside (no NAT loopback), so the advertised address may fail here even
            // though friends can use it. The saved credential stays keyed to the advertised address.
            Uri? endpoint =
                settings.HostServer && hostedServer.Running && host == hostedServer.Address
                    ? new Uri("http://127.0.0.1/reweb/signup/create_id.html")
                    : null;
            await AutomaticAccount.Provision(Settings.Home, host, username, cancel.Token, endpoint);
            if (!cancel.IsCancellationRequested) {
                preparedAccount = identity;
                AccountStatus.Text = "Account ready. Login is automatic when you enter Network.";
            }
        } catch (OperationCanceledException) when (cancel.IsCancellationRequested) {
        } catch (Exception error) {
            if (!cancel.IsCancellationRequested)
                AccountStatus.Text = error switch {
                    AccountNameTakenException => error.Message,
                    System.Net.Http.HttpRequestException {
                        HttpRequestError : System.Net.Http.HttpRequestError.ConnectionError
                    } or TaskCanceledException =>
                        settings.HostServer && !hostedServer.Running
                            ? "Your server is not running yet. Press Start server above, then Create account."
                            : $"No server answered at {host}. Check the address, and that the host has started their server.",
                    _ => "Could not prepare the account: " + error.Message.TrimEnd('.') +
                         ". Press Create account to retry."
                };
        } finally {
            CreateAccountButton.IsEnabled = true;
            if (accountPreparation == cancel)
                accountPreparation = null;
        }
    }
    void InitializeOnline() {
        HostServer.IsChecked = settings.HostServer;
        CoopHost.Text = settings.CoopHost;
        AccountUsername.Text = settings.AccountUsername;
        AccountUsername.MaxLength = OnlineOptions.MaxUsernameLength;
        HostAddress.Text = string.IsNullOrEmpty(settings.HostAddress)
                               ? HostedServer.SuggestedAddress()
                               : settings.HostAddress;
        AutoForward.IsChecked = settings.AutoForward;
        PortList.Text = HostNetworking.PortList;
        RefreshDetectedAddresses();
        _ = RefreshFirewallStatus();
    }

    void RefreshDetectedAddresses() {
        DetectedAddresses.Children.Clear();
        var addresses = HostNetworking.LocalAddresses();
        if (addresses.Count == 0) {
            DetectedAddresses.Children.Add(
                new System.Windows.Controls.TextBlock { Text = "No network connection found.",
                                                        Style = (Style)FindResource("Hint") });
            return;
        }
        foreach (var address in addresses) {
            var button = new System.Windows.Controls.Button { Content = address.Label,
                                                              Margin = new Thickness(0, 0, 8, 6),
                                                              Tag = address.Address };
            button.Click += (_, _) => HostAddress.Text = (string)button.Tag;
            DetectedAddresses.Children.Add(button);
        }
    }

    CancellationTokenSource? publicLookup;
    string? publicAddress;
    async void FindPublicAddress(object sender, RoutedEventArgs e) {
        publicLookup?.Cancel();
        using var cancel = new CancellationTokenSource();
        publicLookup = cancel;
        PublicAddressButton.IsEnabled = false;
        PublicAddressStatus.Text = "Asking api.ipify.org...";
        try {
            publicAddress = await HostNetworking.PublicAddress(cancel.Token);
            PublicAddressStatus.Text = "Your internet address is " + publicAddress + ".";
            var use = new System.Windows.Controls.Button { Content = publicAddress + " (internet)",
                                                           Margin = new Thickness(0, 0, 8, 6) };
            string chosen = publicAddress;
            use.Click += (_, _) => HostAddress.Text = chosen;
            RefreshDetectedAddresses();
            DetectedAddresses.Children.Add(use);
        } catch (OperationCanceledException) when (cancel.IsCancellationRequested) {
        } catch {
            PublicAddressStatus.Text =
                "Could not reach the address service. Check your internet connection.";
        } finally {
            if (publicLookup == cancel)
                publicLookup = null;
            PublicAddressButton.IsEnabled = true;
        }
    }

    async Task RefreshFirewallStatus() {
        bool present = await Task.Run(HostNetworking.FirewallRulesPresent);
        FirewallStatus.Text = present ? "Allowed." : "Not added yet. Windows may block friends.";
        FirewallButton.IsEnabled = !present;
    }

    async void AllowFirewall(object sender, RoutedEventArgs e) {
        FirewallButton.IsEnabled = false;
        FirewallStatus.Text = "Waiting for administrator approval...";
        bool added = await HostNetworking.AddFirewallRules();
        FirewallStatus.Text = added ? "Allowed." : "Not added (approval declined or failed).";
        FirewallButton.IsEnabled = !added;
    }

    bool portsForwarded;
    async Task UpdateRouterForwarding() {
        if (!hostedServer.Running || !settings.AutoForward) {
            if (portsForwarded) {
                portsForwarded = false;
                await HostNetworking.ClosePorts();
                ReachStatus.Text =
                    settings.AutoForward ? "" : "Automatic router forwarding turned off.";
            }
            return;
        }
        var home = HostNetworking.LocalAddresses().FirstOrDefault(
            a => a.Kind == HostNetworking.AddressKind.Home);
        if (home == null) {
            ReachStatus.Text =
                "No home network address found, so router forwarding is not possible.";
            return;
        }
        ReachStatus.Text = "Asking your router to open the ports...";
        var result = await HostNetworking.OpenPorts(home.Address);
        portsForwarded = result.Opened;
        if (!result.Opened)
            ReachStatus.Text = result.Message;
        else if (HostNetworking.BehindAnotherNat(result.RouterAddress))
            ReachStatus.Text =
                "Router ports opened, but your router itself is behind your provider's network " +
                $"(router address {result.RouterAddress}). Friends over the internet probably " +
                "cannot reach you; use a VPN such as Tailscale or ZeroTier instead.";
        else
            ReachStatus.Text =
                result.Message + (result.RouterAddress != null
                                      ? " Router internet address: " + result.RouterAddress + "."
                                      : "");
    }

    async void OnlineSettingChanged(object sender, RoutedEventArgs e) {
        if (!initialized)
            return;
        accountPreparation?.Cancel();
        preparedAccount = null;
        AccountStatus.Text = "";
        settings.HostServer = HostServer.IsChecked == true;
        if (settings.HostServer && (sender == HostServer || sender == HostAddress))
            CoopHost.Text = HostAddress.Text.Trim();
        settings.HostAddress = HostAddress.Text.Trim();
        bool forwardChanged = settings.AutoForward != (AutoForward.IsChecked == true);
        settings.AutoForward = AutoForward.IsChecked == true;
        settings.CoopHost = CoopHost.Text.Trim();
        settings.AccountUsername = AccountUsername.Text;
        try {
            settings.Save();
            Status.Text = "Saved · Changes apply on the next launch";
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
        RefreshGameUi();
        if (sender == HostServer) {
            if (settings.HostServer)
                await StartHostedServer();
            else {
                hostedServer.Dispose();
                HostStatus.Text = "Server stopped";
                CopyServerButton.IsEnabled = false;
                await UpdateRouterForwarding();
            }
        } else if (forwardChanged)
            await UpdateRouterForwarding();
    }
    async void StartServerClicked(object sender, RoutedEventArgs e) {
        if (serverStarting) {
            hostedServer.Dispose();
            return;
        }
        await StartHostedServer();
    }
    async Task StartHostedServer() {
        if (serverStarting || hostedServer.Running)
            return;
        if (game.Running || launching) {
            HostStatus.Text = "Close the game before starting or changing the hosted server.";
            return;
        }
        serverStarting = true;
        StartServerButton.IsEnabled = true;
        StartServerButton.Content = "Cancel";
        HostServer.IsEnabled = false;
        HostAddress.IsEnabled = false;
        HostStatus.Text = "Starting server...";
        HostSetupActivity.Visibility = Visibility.Visible;
        HostSetupProgress.IsIndeterminate = true;
        HostSetupStage.Text = "Preparing server";
        HostSetupDetail.Text = "Checking hosting files";
        try {
            await hostedServer.Start(
                root, HostAddress.Text,
                progress: new Progress<string>(stage => HostStatus.Text = stage),
                setupProgress: new Progress<ImportProgress>(value => {
                    if (!serverStarting)
                        return;
                    ReportHostSetup(value);
                }));
            bool localOnly =
                System.Net.IPAddress.IsLoopback(System.Net.IPAddress.Parse(hostedServer.Address));
            HostStatus.Text = localOnly
                                  ? "Local server only. Choose a LAN or VPN address for friends."
                                  : "Friends connect to: " + hostedServer.Address;
            CopyServerButton.IsEnabled = !localOnly;
            // Your own game must use the address the server actually started on, never a stale value.
            if (CoopHost.Text.Trim() != hostedServer.Address) {
                CoopHost.Text = hostedServer.Address;
                settings.CoopHost = hostedServer.Address;
                try {
                    settings.Save();
                } catch (Exception error)
                    when (error is IOException or UnauthorizedAccessException) {
                }
                preparedAccount = null;
            }
            await UpdateRouterForwarding();
            await PrepareLauncherAccount();
        } catch (OperationCanceledException) {
            HostStatus.Text = "Server setup cancelled. Click Start server to retry.";
            CopyServerButton.IsEnabled = false;
        } catch (Exception error) {
            HostStatus.Text = "Server not started: " + error.Message;
            CopyServerButton.IsEnabled = false;
        } finally {
            serverStarting = false;
            HostSetupActivity.Visibility = Visibility.Collapsed;
            HostSetupProgress.IsIndeterminate = false;
            StartServerButton.Content = "Start server";
            StartServerButton.IsEnabled = !hostedServer.Running;
            HostServer.IsEnabled = true;
            HostAddress.IsEnabled = !hostedServer.Running;
        }
    }
    void ReportHostSetup(ImportProgress value) {
        HostSetupProgress.IsIndeterminate = value.Total <= 0;
        HostSetupProgress.Value = Math.Clamp(value.Percent, 0, 100);
        string counts = SetupProgressText.Counts(value);
        HostSetupStage.Text = value.Stage + (counts.Length > 0 ? " - " + counts : "");
        HostSetupDetail.Text = value.File;
    }
    void CancelServerSetup(object sender, RoutedEventArgs e) {
        if (serverStarting)
            hostedServer.Dispose();
    }
    void CopyServerAddress(object sender, RoutedEventArgs e) {
        if (hostedServer.Running)
            Clipboard.SetText(hostedServer.Address);
    }

    void RefreshOnlineUi() {
        bool supported = settings.Game.Id == "file1";
        CoopControls.IsEnabled =
            supported && !updating && !updateRestarting && !game.Running && !launching;
        CoopUnavailable.Visibility = supported ? Visibility.Collapsed : Visibility.Visible;
        HostOptions.Visibility = settings.HostServer ? Visibility.Visible : Visibility.Collapsed;
        CoopHost.IsEnabled = !settings.HostServer;
        if (CopyServerButton.IsEnabled && !hostedServer.Running) {
            HostStatus.Text = "Server stopped unexpectedly. See the hosted-server logs.";
            CopyServerButton.IsEnabled = false;
            StartServerButton.IsEnabled = true;
            HostAddress.IsEnabled = true;
        }
        string? error = OnlineOptions.Error(settings);
        CoopValidation.Text = error ?? "";
        CoopValidation.Visibility = error == null ? Visibility.Collapsed : Visibility.Visible;
        CoopValidation.Foreground = (Brush)FindResource("Accent");
        PlayNetworkSummary.Text = OnlineOptions.Configured(settings)
                                      ? "Network / " + settings.CoopHost
                                      : "Network not configured";
        if (!game.Running && !launching)
            LaunchButton.Content = "Play";
    }
}
