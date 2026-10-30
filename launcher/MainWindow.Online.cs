using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Outbreak.Launcher;

public partial class MainWindow {
    readonly HostedServer hostedServer = new();
    bool serverStarting;
    CancellationTokenSource? accountPreparation;
    string? preparedAccount;
    LanDiscovery.Responder? lanResponder;
    volatile bool hostRoomReady;
    CancellationTokenSource? gameSearch;
    readonly HashSet<string> searchedGameEditions = new(StringComparer.Ordinal);
    Func<CancellationToken, string, Task<List<LanDiscovery.Game>>>? gameSearchLookup;
    string onlineEdition = "";
    List<LanDiscovery.Game> foundGames = new();
    // UI diagnostics exercise real controls/settings without starting services,
    // broadcasting discovery packets or changing this PC's network setup.
    bool CoopUiDiagnostics => args.Contains("--test-coop-ui");

    // Checks the player name on the chosen server before the game starts, so problems show here
    // instead of inside the game. The game repeats this automatically when it signs in.
    async Task<bool> PrepareLauncherAccount() {
        if (!OnlineOptions.Configured(settings))
            return false;
        OnlineOptions.TryHost(settings.CoopHost, out string host);
        string username = settings.AccountUsername;
        string identity = settings.Game.Id + "\n" + host + "\n" + username;
        if (preparedAccount == identity)
            return true;
        accountPreparation?.Cancel();
        using var cancel = new CancellationTokenSource();
        accountPreparation = cancel;
        AccountStatus.Text = "Checking your player name...";
        AccountStatus.Foreground = (Brush)FindResource("Muted");
        try {
            // Hosting: sign up with our own server directly on this PC. Many routers cannot reach
            // their own public address from inside (no NAT loopback).
            Uri? endpoint = SignupEndpoint(settings, hostedServer.Running ? hostedServer.Address : null);
            await AutomaticAccount.Provision(Settings.Home, host, username, cancel.Token, endpoint);
            preparedAccount = identity;
            AccountStatus.Text = "";
            return true;
        } catch (OperationCanceledException) when (cancel.IsCancellationRequested) {
            return false;
        } catch (Exception error) {
            if (!cancel.IsCancellationRequested) {
                AccountStatus.Text = error switch {
                    AccountNameTakenException =>
                        "Another player already uses that name in this game. Choose another name.",
                    System.Net.Http.HttpRequestException {
                        HttpRequestError : System.Net.Http.HttpRequestError.ConnectionError
                    } or TaskCanceledException =>
                        settings.ResolvedCoopMode == "host"
                            ? "Your game is not open yet. Wait for it, or press Try again."
                            : $"No game answered at {host}. Check the address, and that your friend chose Host a game.",
                    _ => "Could not check your player name: " + error.Message.TrimEnd('.') + "."
                };
                AccountStatus.Foreground = (Brush)FindResource("Danger");
            }
            return false;
        } finally {
            if (accountPreparation == cancel)
                accountPreparation = null;
        }
    }

    // Hosts sign up with their own server on this PC: many routers cannot reach their own public
    // address from inside. Joiners use the port their host announced, if any.
    internal static Uri? SignupEndpoint(Settings settings, string? hostedAddress) {
        OnlineOptions.TryHost(settings.CoopHost, out string host);
        if (settings.ResolvedCoopMode == "host" && (hostedAddress == null || hostedAddress == host))
            return AutomaticAccount.SignupEndpoint("127.0.0.1", settings.SignupPort);
        return settings.ResolvedCoopMode == "join" && settings.JoinSignupPort > 0
                   ? AutomaticAccount.SignupEndpoint(host, settings.JoinSignupPort)
                   : null;
    }

    void ShowPorts() {
        HostNetworking.Current = new(settings.SignupPort, settings.GamePort);
        SignupPortBox.Text = settings.SignupPort.ToString();
        GamePortBox.Text = settings.GamePort.ToString();
    }
    void PortKeyDown(object sender, System.Windows.Input.KeyEventArgs e) {
        if (e.Key == System.Windows.Input.Key.Enter)
            PortsChanged(sender, e);
    }
    void ResetPorts(object sender, RoutedEventArgs e) {
        SignupPortBox.Text = HostNetworking.SignupPort.ToString();
        GamePortBox.Text = HostNetworking.GamePort.ToString();
        PortsChanged(sender, e);
    }
    async void PortsChanged(object sender, RoutedEventArgs e) {
        if (!initialized)
            return;
        if (!int.TryParse(SignupPortBox.Text.Trim(), out int signup) ||
            !int.TryParse(GamePortBox.Text.Trim(), out int gamePort)) {
            PortStatus.Text = "Ports must be numbers from 1024 to 65535.";
            PortStatus.Foreground = (Brush)FindResource("Danger");
            return;
        }
        string? error = HostNetworking.PortError(signup, gamePort);
        if (error != null) {
            PortStatus.Text = error;
            PortStatus.Foreground = (Brush)FindResource("Danger");
            return;
        }
        PortStatus.Text = "";
        if (signup == settings.SignupPort && gamePort == settings.GamePort)
            return;
        settings.SignupPort = signup;
        settings.GamePort = gamePort;
        SaveOnlineSettings();
        ShowPorts();
        preparedAccount = null;
        _ = RefreshFirewallStatus();
        if (settings.ResolvedCoopMode == "host" && (hostedServer.Running || serverStarting)) {
            await StopHosting();
            await StartHosting();
        }
        PortStatus.Text = "Ports saved.";
        PortStatus.Foreground = (Brush)FindResource("Muted");
    }

    void InitializeOnline() {
        string mode = settings.ResolvedCoopMode;
        settings.CoopMode = mode;
        (mode switch { "host" => ModeHost, "join" => ModeJoin, _ => ModeOffline }).IsChecked = true;
        CoopHost.Text = mode == "join" ? settings.CoopHost : "";
        AccountUsername.Text = settings.AccountUsername;
        AccountUsername.MaxLength = OnlineOptions.MaxUsernameLength;
        AutoLobby.IsChecked = settings.AutoLobby;
        AutoForward.IsChecked = settings.AutoForward;
        InitializeLobbySettings();
        ShowPorts();
        RefreshHostAddresses();
        _ = RefreshFirewallStatus();
    }

    async void CoopModeChanged(object sender, RoutedEventArgs e) {
        if (!initialized || sender is not RadioButton { Tag: string mode })
            return;
        settings.CoopMode = mode;
        settings.HostServer = mode == "host";
        settings.CoopHost = mode == "host" ? settings.HostAddress : CoopHost.Text.Trim();
        preparedAccount = null;
        AccountStatus.Text = "";
        SaveOnlineSettings();
        RefreshGameUi();
        if (mode == "host")
            await StartHosting();
        else
            await StopHosting();
    }

    async void OnlineSettingChanged(object sender, RoutedEventArgs e) {
        if (!initialized)
            return;
        accountPreparation?.Cancel();
        preparedAccount = null;
        AccountStatus.Text = "";
        settings.AccountUsername = AccountUsername.Text.Trim();
        settings.AutoLobby = AutoLobby.IsChecked == true;
        bool forwardChanged = settings.AutoForward != (AutoForward.IsChecked == true);
        settings.AutoForward = AutoForward.IsChecked == true;
        if (settings.ResolvedCoopMode == "join" && sender == CoopHost) {
            settings.CoopHost = CoopHost.Text.Trim();
            var picked = foundGames.FirstOrDefault(g => g.Address == settings.CoopHost);
            settings.JoinHostName = picked?.Name ?? "";
            settings.JoinSignupPort = picked?.Signup ?? 0;
            settings.JoinRoomName = picked?.RoomTitle ?? "";
            ShowFoundGames();
        }
        SaveOnlineSettings();
        RefreshGameUi();
        if (forwardChanged)
            await UpdateRouterForwarding();
    }

    void SaveOnlineSettings() {
        try {
            settings.Save();
        } catch (Exception error) when (error is IOException or UnauthorizedAccessException) {
            Status.Text = "Settings could not be saved: " + error.Message;
        }
    }

    async void HostAddressChanged(object sender, SelectionChangedEventArgs e) {
        if (!initialized || HostAddressPicker.SelectedItem is not AddressChoice choice ||
            choice.Address == settings.HostAddress)
            return;
        settings.HostAddress = choice.Address;
        if (settings.ResolvedCoopMode == "host")
            settings.CoopHost = choice.Address;
        preparedAccount = null;
        SaveOnlineSettings();
        // The server tells players where to connect, so a new address needs a restart.
        if (settings.ResolvedCoopMode == "host" && (hostedServer.Running || serverStarting)) {
            await StopHosting();
            await StartHosting();
        }
        RefreshGameUi();
    }

    async void StartServerClicked(object sender, RoutedEventArgs e) => await StartHosting();

    async Task StartHosting() {
        if (CoopUiDiagnostics) return;
        if (serverStarting || !OnlineOptions.Supported(settings.Game.Id))
            return;
        if (hostedServer.Running && hostedServer.GameId == settings.Game.Id)
            return;
        if (game.Running || launching) {
            HostStatus.Text = "Close the game to open your game for friends.";
            return;
        }
        if (hostedServer.Running) await StopHosting();
        serverStarting = true;
        StartServerButton.Visibility = Visibility.Collapsed;
        HostStatus.Text = "Opening your game...";
        HostDetail.Text = "";
        HostSetupActivity.Visibility = Visibility.Visible;
        HostSetupProgress.IsIndeterminate = true;
        HostSetupStage.Text = "Preparing hosting";
        HostSetupDetail.Text = "Checking hosting files";
        try {
            await hostedServer.Start(
                root, settings.HostAddress,
                progress: new Progress<string>(stage => HostDetail.Text = stage),
                setupProgress: new Progress<ImportProgress>(value => {
                    if (serverStarting)
                        ReportHostSetup(value);
                }), game: settings.Game.Id);
            bool localOnly =
                System.Net.IPAddress.IsLoopback(System.Net.IPAddress.Parse(hostedServer.Address));
            HostStatus.Text = localOnly ? "Your game is open on this PC only"
                                        : "Your game is open for friends";
            HostDetail.Text = localOnly ? "No network was found, so friends cannot join yet."
                                        : "Press Play. Friends choose Join a game.";
            CopyServerButton.IsEnabled = !localOnly;
            // Your own game must use the address the server actually started on.
            if (settings.CoopHost != hostedServer.Address) {
                settings.CoopHost = hostedServer.Address;
                SaveOnlineSettings();
                preparedAccount = null;
            }
            try {
                lanResponder ??= new LanDiscovery.Responder(DescribeHostedGame,
                    () => game.Running ? game.HostRandomizerConfiguration : null);
            } catch (System.Net.Sockets.SocketException) {
                hostedServer.Dispose();
                throw new IOException("UDP port 10129 is already in use. Close the other hosting launcher and try again; this port carries shared game settings.");
            }
            await UpdateRouterForwarding();
        } catch (OperationCanceledException) {
            HostStatus.Text = "Hosting cancelled";
            HostDetail.Text = "";
            StartServerButton.Visibility = Visibility.Visible;
            CopyServerButton.IsEnabled = false;
        } catch (Exception error) {
            HostStatus.Text = "Your game could not be opened";
            HostDetail.Text = error.Message;
            if (error.Message.StartsWith("Ports already in use", StringComparison.Ordinal))
                HostPortSettings.BringIntoView();
            StartServerButton.Visibility = Visibility.Visible;
            CopyServerButton.IsEnabled = false;
        } finally {
            serverStarting = false;
            HostSetupActivity.Visibility = Visibility.Collapsed;
            HostSetupProgress.IsIndeterminate = false;
            RefreshGameUi();
        }
    }

    LanDiscovery.Game DescribeHostedGame() =>
        new(OnlineOptions.ValidUsername(settings.AccountUsername) ? settings.AccountUsername : "Host",
            hostedServer.Address, Updates.DefaultVersion, hostRoomReady && game.Running,
            settings.SignupPort, hostedServer.GameId,
            settings.AutoLobby && LobbySettings.ValidTitle(settings.ResolvedRoomName) ? settings.ResolvedRoomName : "");

    async Task StopHosting() {
        lanResponder?.Dispose();
        lanResponder = null;
        hostedServer.Dispose();
        HostStatus.Text = "";
        HostDetail.Text = "";
        CopyServerButton.IsEnabled = false;
        await UpdateRouterForwarding();
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

    // ---- Joining: games on the local network ----
    void SearchGamesClicked(object sender, RoutedEventArgs e) => SearchGames();
    async void SearchGames() {
        if (CoopUiDiagnostics && gameSearchLookup == null) return;
        if (!OnlineOptions.Supported(settings.Game.Id) || gameSearch != null || settings.ResolvedCoopMode != "join" || game.Running)
            return;
        string edition = settings.Game.Id;
        using var cancel = new CancellationTokenSource();
        gameSearch = cancel;
        searchedGameEditions.Add(edition);
        SearchGamesButton.IsEnabled = false;
        if (foundGames.Count == 0)
            SearchStatus.Text = "Searching...";
        try {
            var discovered = await (CoopUiDiagnostics ? gameSearchLookup!(cancel.Token, edition) :
                LanDiscovery.Search(TimeSpan.FromSeconds(1.5), cancel.Token, edition));
            if (settings.Game.Id != edition) return;
            foundGames = discovered;
            SearchStatus.Text = foundGames.Count == 0
                                    ? "No games found."
                                    : "";
            var chosen = foundGames.FirstOrDefault(g => g.Address == settings.CoopHost);
            if (chosen != null && (chosen.Name != settings.JoinHostName ||
                                   chosen.Signup != settings.JoinSignupPort || chosen.RoomTitle != settings.JoinRoomName)) {
                settings.JoinHostName = chosen.Name;
                settings.JoinSignupPort = chosen.Signup;
                settings.JoinRoomName = chosen.RoomTitle;
                SaveOnlineSettings();
            }
        } catch (Exception error) when (error is OperationCanceledException or
                                            System.Net.Sockets.SocketException) {
            SearchStatus.Text = "Could not search your network.";
        } finally {
            gameSearch = null;
            SearchGamesButton.IsEnabled = true;
            ShowFoundGames();
        }
    }

    void ShowFoundGames() {
        FoundGames.Children.Clear();
        foreach (var found in foundGames.Where(g => g.GameId == settings.Game.Id)) {
            bool selected = found.Address == settings.CoopHost;
            var text = new StackPanel();
            var heading = new Grid();
            heading.ColumnDefinitions.Add(new());
            heading.ColumnDefinitions.Add(new() { Width = GridLength.Auto });
            heading.Children.Add(new TextBlock { Text = found.Name + "'s game", FontSize = 17,
                Margin = new Thickness(0, 0, 12, 0) });
            if (selected) {
                var marker = new TextBlock { Text = "SELECTED", FontSize = 11,
                    Foreground = (Brush)FindResource("Muted"), VerticalAlignment = VerticalAlignment.Center };
                Grid.SetColumn(marker, 1); heading.Children.Add(marker);
            }
            text.Children.Add(heading);
            text.Children.Add(new TextBlock {
                Text = found.Address + (found.Version == Updates.DefaultVersion
                                            ? ""
                                            : " · different launcher version (" + found.Version + ")"),
                Style = (Style)FindResource("Hint"), FontSize = 14, Margin = new Thickness(0, 6, 0, 0) });
            text.Children.Add(new TextBlock { Text = found.RoomReady ? "Waiting room open" : "Waiting for a room",
                Foreground = (Brush)FindResource("Muted"), FontSize = 12, Margin = new Thickness(0, 7, 0, 0) });
            if (found.RoomTitle.Length > 0)
                text.Children.Add(new TextBlock { Text = found.RoomTitle, FontSize = 14,
                    Foreground = (Brush)FindResource("Muted"), Margin = new Thickness(0, 5, 0, 0) });
            var button = new Button { Content = text, HorizontalContentAlignment = HorizontalAlignment.Left,
                                      Margin = new Thickness(0, 0, 0, 8), Tag = found,
                                      Style = (Style)FindResource("CoopGameChoice"),
                                      Background = selected ? Palette.Brush(Palette.Accent, 22) : Brushes.Transparent,
                                      BorderBrush = selected ? (Brush)FindResource("Accent") : Brushes.Transparent };
            System.Windows.Automation.AutomationProperties.SetName(button, "Join " + found.Name + "'s game");
            button.Click += (_, _) => {
                var game = (LanDiscovery.Game)button.Tag;
                if (game.GameId != settings.Game.Id) return;
                CoopHost.Text = game.Address; // saves through OnlineSettingChanged
            };
            FoundGames.Children.Add(button);
        }
    }

    // ---- Reaching the host ----
    async Task RefreshFirewallStatus() {
        bool present = await Task.Run(HostNetworking.FirewallRulesPresent);
        FirewallStatus.Text = present ? "Windows Firewall allows friends." : "Windows may block friends.";
        FirewallButton.Visibility = present ? Visibility.Collapsed : Visibility.Visible;
    }

    async void AllowFirewall(object sender, RoutedEventArgs e) {
        FirewallButton.IsEnabled = false;
        FirewallStatus.Text = "Waiting for administrator approval...";
        bool added = await HostNetworking.AddFirewallRules();
        FirewallStatus.Text = added ? "Windows Firewall allows friends." : "Not allowed (approval declined or failed).";
        FirewallButton.IsEnabled = true;
        FirewallButton.Visibility = added ? Visibility.Collapsed : Visibility.Visible;
    }

    bool portsForwarded;
    async Task UpdateRouterForwarding() {
        if (!hostedServer.Running || !settings.AutoForward) {
            if (portsForwarded) {
                portsForwarded = false;
                await HostNetworking.ClosePorts();
            }
            ReachStatus.Text = settings.AutoForward ? "Requested when hosting starts. Your router must support UPnP." : "";
            return;
        }
        var home = HostNetworking.LocalAddresses().FirstOrDefault(
            a => a.Kind == HostNetworking.AddressKind.Home);
        if (home == null) {
            ReachStatus.Text =
                "No home network address found, so router forwarding is not possible.";
            return;
        }
        ReachStatus.Text = "Requesting port forwarding from your router...";
        var result = await HostNetworking.OpenPorts(home.Address);
        portsForwarded = result.Opened;
        if (!result.Opened)
            ReachStatus.Text = result.Message;
        else if (HostNetworking.BehindAnotherNat(result.RouterAddress))
            ReachStatus.Text =
                "Your router accepted the request, but is behind another network. Internet access is not confirmed.";
        else
            ReachStatus.Text =
                "Your router accepted the request. Internet access is not confirmed.";
    }

    // Lobby steering for the next launch, when the player asked for it.
    LobbyAutomation.Options? LobbyOptions() {
        if (!settings.AutoLobby || !OnlineOptions.Configured(settings))
            return null;
        if (settings.ResolvedCoopMode == "host")
            return new(true, settings.ResolvedRoomName, hostedServer.Address,
                       ready => hostRoomReady = ready, settings.Game.Id,
                       settings.ResolvedRoomMaxPlayers, settings.ResolvedRoomWaitMinutes);
        return new(false, settings.JoinRoomName.Length > 0 ? settings.JoinRoomName : settings.JoinHostName,
                   settings.CoopHost, Game: settings.Game.Id);
    }

    // A host typed by address may still answer discovery directly: learn its name and sign-up port.
    async Task RefreshJoinHost() {
        if (settings.ResolvedCoopMode != "join")
            return;
        try {
            string edition = settings.Game.Id;
            var host = await LanDiscovery.Ask(settings.CoopHost, TimeSpan.FromSeconds(1.5),
                                              CancellationToken.None, edition);
            if (settings.Game.Id != edition) return;
            if (host != null && (host.Name != settings.JoinHostName ||
                                 host.Signup != settings.JoinSignupPort || host.RoomTitle != settings.JoinRoomName)) {
                settings.JoinHostName = host.Name;
                settings.JoinSignupPort = host.Signup;
                settings.JoinRoomName = host.RoomTitle;
                preparedAccount = null;
                SaveOnlineSettings();
            }
        } catch (System.Net.Sockets.SocketException) {
        }
    }

    void RefreshOnlineUi() {
        if (onlineEdition != settings.Game.Id) {
            if (onlineEdition.Length > 0) {
                gameSearch?.Cancel();
                accountPreparation?.Cancel();
                foundGames.Clear();
                SearchStatus.Text = searchedGameEditions.Contains(settings.Game.Id) ? "Press Search again to look for games." : "";
                settings.JoinHostName = "";
                settings.JoinSignupPort = 0;
                settings.JoinRoomName = "";
                preparedAccount = null;
                AccountStatus.Text = "";
            }
            onlineEdition = settings.Game.Id;
            ShowFoundGames();
        }
        bool supported = OnlineOptions.Supported(settings.Game.Id);
        string mode = settings.ResolvedCoopMode;
        CoopControls.IsEnabled =
            supported && !updating && !updateRestarting && !game.Running && !launching;
        CoopUnavailable.Visibility = supported ? Visibility.Collapsed : Visibility.Visible;
        OnlinePanel.Visibility = mode == "offline" ? Visibility.Collapsed : Visibility.Visible;
        OfflinePanel.Visibility = mode == "offline" ? Visibility.Visible : Visibility.Collapsed;
        HostOptions.Visibility = mode == "host" ? Visibility.Visible : Visibility.Collapsed;
        JoinOptions.Visibility = mode == "join" ? Visibility.Visible : Visibility.Collapsed;
        RefreshLobbySettings();
        if (mode == "host" && PageCoop.IsVisible && !internetLookupAttempted &&
            (!CoopUiDiagnostics || publicAddressLookup != null)) _ = LookupPublicAddress();
        if (mode == "host" && CopyServerButton.IsEnabled && !hostedServer.Running) {
            HostStatus.Text = "Your game closed unexpectedly";
            HostDetail.Text = "See the hosted-server logs, or press Try again.";
            CopyServerButton.IsEnabled = false;
            StartServerButton.Visibility = Visibility.Visible;
        }
        if (supported && mode == "join" && PageCoop.Visibility == Visibility.Visible && !game.Running &&
            !searchedGameEditions.Contains(settings.Game.Id))
            SearchGames();
        string? error = OnlineOptions.Error(settings);
        CoopValidation.Text = error ?? "";
        bool awaitingHostAddress = mode == "join" && string.IsNullOrWhiteSpace(settings.CoopHost) &&
            OnlineOptions.ValidUsername(settings.AccountUsername);
        CoopValidation.Visibility = error == null || awaitingHostAddress ? Visibility.Collapsed : Visibility.Visible;
        CoopValidation.Foreground = (Brush)FindResource("Danger");
        PlayNetworkSummary.Text =
            mode == "offline" ? "Single player"
            : !OnlineOptions.Configured(settings) ? "Co-op not set up yet (see Co-op)"
            : mode == "host" ? (hostedServer.Running ? "Hosting at " + hostedServer.Address
                                                      : "Hosting (opening your game...)")
            : "Joining " + (settings.JoinHostName.Length > 0 ? settings.JoinHostName + " at " : "") +
                  settings.CoopHost;
        if (!game.Running && !launching)
            LaunchButton.Content = PlayButtonLabel;
    }
}
