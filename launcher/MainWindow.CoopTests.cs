using System.IO;
using System.Text.Json;
using System.Windows;
using System.Windows.Automation.Peers;
using System.Windows.Automation.Provider;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace Outbreak.Launcher;
public partial class MainWindow {
    async Task TestCoopUi(string output) {
        Directory.CreateDirectory(output);
        string path = Path.Combine(Settings.Home, "settings.json");
        byte[]? saved = File.Exists(path) ? File.ReadAllBytes(path) : null;
        var checks = new List<string>();
        void Check(bool condition, string message) {
            if (!condition) throw new IOException(message);
            checks.Add(message);
        }
        async Task Wait(Func<bool> condition) {
            for (int i = 0; i < 150 && !condition(); i++) await Task.Delay(20);
            if (!condition()) throw new IOException("Co-op UI did not settle.");
            UpdateLayout();
        }
        Settings Stored() => JsonSerializer.Deserialize<Settings>(File.ReadAllText(path))!;
        void Mode(RadioButton button) => ((ISelectionItemProvider)new RadioButtonAutomationPeer(button)
            .GetPattern(PatternInterface.SelectionItem)!).Select();
        void Text(TextBox box, string value) => ((IValueProvider)new TextBoxAutomationPeer(box)
            .GetPattern(PatternInterface.Value)!).SetValue(value);
        void Invoke(Button button) => ((IInvokeProvider)new ButtonAutomationPeer(button)
            .GetPattern(PatternInterface.Invoke)!).Invoke();
        void Toggle(CheckBox box) => ((IToggleProvider)new CheckBoxAutomationPeer(box)
            .GetPattern(PatternInterface.Toggle)!).Toggle();
        void Enter(TextBox box) {
            box.Focus();
            box.RaiseEvent(new KeyEventArgs(Keyboard.PrimaryDevice, PresentationSource.FromVisual(this),
                Environment.TickCount, Key.Enter) { RoutedEvent = Keyboard.KeyDownEvent });
        }
        void Capture(string name) {
            StatusToast.Visibility = Visibility.Collapsed;
            UpdateLayout();
            var bitmap = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
            bitmap.Render(this);
            if (HostAddressPicker.IsDropDownOpen && HostAddressPicker.Template.FindName("PART_Popup", HostAddressPicker) is Popup { Child: FrameworkElement menu }) {
                var visual = new DrawingVisual();
                using (var drawing = visual.RenderOpen()) {
                    drawing.DrawImage(bitmap, new Rect(0, 0, ActualWidth, ActualHeight));
                    var position = HostAddressPicker.TranslatePoint(new Point(0, HostAddressPicker.ActualHeight), this);
                    var brush = new VisualBrush(menu) { ViewboxUnits = BrushMappingMode.Absolute,
                        Viewbox = new Rect(0, 0, menu.ActualWidth, menu.ActualHeight), Stretch = Stretch.Fill };
                    drawing.DrawRectangle(brush, null, new Rect(position.X, position.Y, menu.ActualWidth, menu.ActualHeight));
                }
                var combined = new RenderTargetBitmap((int)ActualWidth, (int)ActualHeight, 96, 96, PixelFormats.Pbgra32);
                combined.Render(visual); bitmap = combined;
            }
            var encoder = new PngBitmapEncoder(); encoder.Frames.Add(BitmapFrame.Create(bitmap));
            using var file = File.Create(Path.Combine(output, name + ".png")); encoder.Save(file);
        }
        try {
            Check(args.Contains("--data-home") && CoopUiDiagnostics,
                "Co-op UI checks use an isolated data home and disable external networking actions");
            timer.Stop(); gameSearch?.Cancel();
            initialized = false;
            settings.SelectedGame = "file1"; settings.CoopMode = "offline"; settings.HostServer = false;
            settings.AutoForward = settings.AutoLobby = false;
            settings.RoomName = settings.JoinRoomName = ""; settings.RoomMaxPlayers = 4; settings.RoomWaitMinutes = 5;
            InitializeLobbySettings();
            settings.AccountUsername = settings.CoopHost = settings.HostAddress = "";
            ModeOffline.IsChecked = true; AutoLobby.IsChecked = AutoForward.IsChecked = false;
            CoopHost.Text = AccountUsername.Text = "";
            settings.HostAddress = "192.0.2.10";
            var addresses = new[] { new AddressChoice("192.0.2.10", "192.0.2.10 (local network)"),
                new AddressChoice("198.51.100.10", "198.51.100.10 (private network)") };
            HostAddressPicker.ItemsSource = addresses; HostAddressPicker.SelectedItem = addresses[0];
            initialized = true;
            RefreshGameUi(); ShowPage("Coop"); await Task.Delay(500);
            Check(ModeOffline.IsChecked == true && OfflinePanel.IsVisible && !OnlinePanel.IsVisible,
                "Play alone shows the offline session and hides connection settings");
            var barPosition = CoopModeBar.TranslatePoint(new Point(), PageCoop);
            Capture("coop-offline");

            Mode(ModeHost); await Wait(() => HostOptions.IsVisible && settings.ResolvedCoopMode == "host");
            Check(Stored().HostServer && Stored().CoopHost == addresses[0].Address && !JoinOptions.IsVisible &&
                !OfflinePanel.IsVisible && !hostedServer.Running,
                "Host selection saves the invite address and shows hosting controls without starting diagnostic services");
            Text(AccountUsername, "Kevin");
            Toggle(AutoLobby); await Wait(() => Stored().AutoLobby);
            Check(Stored().AccountUsername == "Kevin" && OnlineOptions.Configured(settings) && RoomSettings.IsVisible && RoomSettings.IsEnabled,
                "Player name and automatic waiting-room entry persist through native controls");
            Text(RoomName, "RaccoonCrew_123");
            RoomPlayers.SelectedValue = 2; RoomWait.SelectedValue = 10;
            var lobby = LobbyOptions();
            Check(Stored().RoomName == "RaccoonCrew_123" && Stored().RoomMaxPlayers == 2 && Stored().RoomWaitMinutes == 10 &&
                lobby is { Title: "RaccoonCrew_123", MaxPlayers: 2, WaitMinutes: 10 },
                "Room name, player count and waiting time persist and reach the actual lobby automation options");
            UpdateLayout();
            Check(RoomPlayers.SelectionBoxItem.ToString() == "2 players" && RoomWait.SelectionBoxItem.ToString() == "10 minutes" &&
                RoomPlayers.ActualHeight < 50 && RoomWait.ActualHeight < 50 && RoomName.ActualHeight <= 40 && AccountUsername.ActualHeight <= 40,
                "Room dropdowns render concise selected labels at the standard control height");
            Check(DescribeHostedGame().RoomTitle == "RaccoonCrew_123", "Hosts advertise their custom room title so joiners can find it");
            Text(RoomName, "bad title");
            Check(CoopValidation.IsVisible && CoopValidation.Text.StartsWith("Room name"),
                "Unsupported room-name characters show validation before launch");
            Text(RoomName, "");
            Check(LobbyOptions()?.Title == "Kevin" && !CoopValidation.IsVisible,
                "Leaving the room name blank uses the player name");
            Text(RoomName, "RaccoonCrew");
            Toggle(AutoLobby); await Wait(() => !Stored().AutoLobby);
            Check(!RoomSettings.IsEnabled && LobbyOptions() == null && Stored().RoomMaxPlayers == 2,
                "Disabling automatic entry keeps room preferences while disabling automatic setup");
            Toggle(AutoLobby); await Wait(() => Stored().AutoLobby);
            HostAddressPicker.SelectedItem = addresses[1];
            Check(Stored().HostAddress == addresses[1].Address && Stored().CoopHost == addresses[1].Address,
                "Changing the invite address updates the address used by the hosted session");
            HostStatus.Text = "Opening your game..."; HostDetail.Text = "Preparing hosting";
            SettingsScroll.ScrollToTop(); Capture("coop-host");

            Check(HostPortSettings.IsVisible && SignupPortBox.IsVisible && GamePortBox.IsVisible &&
                FindName("PortOptions") == null && FindName("InternetOptions") == null && FindName("PublicAddressButton") == null,
                "Forwarding and port controls are visible directly, with both submenus and the separate address button removed");
            int originalSignup = settings.SignupPort, originalGame = settings.GamePort;
            Text(SignupPortBox, "wrong"); Enter(SignupPortBox);
            Check(PortStatus.IsVisible && PortStatus.Text.Contains("numbers") && settings.SignupPort == originalSignup && settings.GamePort == originalGame,
                "Invalid port text shows an inline error without overwriting the saved ports");
            Text(SignupPortBox, (HostNetworking.SignupPort + 100).ToString());
            Text(GamePortBox, (HostNetworking.GamePort + 100).ToString()); Enter(GamePortBox);
            Check(Stored().SignupPort == HostNetworking.SignupPort + 100 &&
                Stored().GamePort == HostNetworking.GamePort + 100 && FindName("PortList") == null,
                "Advanced port edits persist without repeating the router port list");
            Invoke(ResetPortsButton); await Wait(() => settings.SignupPort == HostNetworking.SignupPort && settings.GamePort == HostNetworking.GamePort);
            Check(Stored().SignupPort == HostNetworking.SignupPort && Stored().GamePort == HostNetworking.GamePort,
                "The port reset button restores both defaults through the existing handler");
            HostPortSettings.BringIntoView(); Capture("coop-ports");
            int addressRequests = 0;
            string selectedAddress = settings.HostAddress;
            var pendingAddress = new TaskCompletionSource<string>();
            RefreshHostAddresses("203.0.113.17");
            publicAddressLookup = _ => { addressRequests++; return pendingAddress.Task; };
            RefreshOnlineUi();
            Check(addressRequests == 1 && settings.HostAddress == selectedAddress &&
                HostAddressPicker.Items.Cast<AddressChoice>().All(c => OnlineOptions.TryHost(c.Address, out _)),
                "The invite dropdown contains only addresses while its one automatic internet lookup runs");
            HostAddressPicker.SelectedItem = HostAddressPicker.Items.Cast<AddressChoice>().Single(c => c.Address == "203.0.113.17");
            pendingAddress.SetResult("203.0.113.18");
            await Wait(() => HostAddressPicker.Items.Cast<AddressChoice>().Any(c => c.Address == "203.0.113.18"));
            Check(settings.HostAddress == "203.0.113.17" && Stored().HostAddress == "203.0.113.17" &&
                HostAddressPicker.SelectedItem is AddressChoice { Address: "203.0.113.17" },
                "The automatic lookup adds the internet address while preserving a selection made during the request");
            RefreshOnlineUi(); RefreshHostAddresses();
            Check(addressRequests == 1 && HostAddressPicker.Items.Cast<AddressChoice>().All(c => OnlineOptions.TryHost(c.Address, out _)) &&
                HostAddressPicker.Items.Cast<AddressChoice>().Any(c => c.Address == "203.0.113.18"),
                "Address refreshes retain the internet address with no manual refresh entry or repeated lookup");
            SettingsScroll.ScrollToTop(); HostAddressPicker.IsDropDownOpen = true; await Task.Delay(80);
            Capture("coop-invite-dropdown"); HostAddressPicker.IsDropDownOpen = false;
            Toggle(AutoForward); await Wait(() => Stored().AutoForward);
            Check(!portsForwarded && FirewallButton.IsEnabled &&
                ReachStatus.Text.Contains("Requested when hosting starts"),
                "Router forwarding preference persists while UI diagnostics leave router and firewall rules untouched");
            HostStatus.Text = "Your game could not be opened"; HostDetail.Text = "The selected address is unavailable.";
            StartServerButton.Visibility = Visibility.Visible; SettingsScroll.ScrollToTop(); Capture("coop-host-options");
            Check(HostStatus.IsVisible && HostDetail.IsVisible && StartServerButton.IsVisible,
                "Hosting failure text and retry remain visible in the redesigned connection column");

            var searches = new Dictionary<string, int>();
            gameSearchLookup = (_, edition) => {
                searches[edition] = searches.GetValueOrDefault(edition) + 1;
                return Task.FromResult(new List<LanDiscovery.Game>());
            };
            Mode(ModeJoin); await Wait(() => JoinOptions.IsVisible && settings.ResolvedCoopMode == "join" && searches.GetValueOrDefault("file1") == 1);
            Check(!HostOptions.IsVisible && !Stored().HostServer && !RoomSettings.IsVisible && !CoopValidation.IsVisible,
                "Join mode hides host settings and the empty-address validation prompt");
            Check(SearchStatus.Text == "No games found.", "An empty first search shows concise results without promising automatic updates");
            for (int i = 0; i < 8; i++) RefreshOnlineUi();
            ShowPage("Audio"); ShowPage("Coop"); await Task.Delay(350);
            Check(searches["file1"] == 1, "Routine refreshes and reopening Co-op do not repeat the initial discovery search");
            Invoke(SearchGamesButton); await Wait(() => searches["file1"] == 2);
            Check(searches["file1"] == 2, "Search again explicitly starts one further discovery request");
            SettingsScroll.ScrollToTop(); Capture("coop-join-empty");
            foundGames = new() {
                new("Cindy", "192.0.2.21", Updates.DefaultVersion, true, HostNetworking.SignupPort + 12, "file1", "CindyRoom"),
                new("Mark", "192.0.2.22", "0.0.1", false, HostNetworking.SignupPort, "file1"),
                new("Yoko", "198.51.100.21", Updates.DefaultVersion, true, HostNetworking.SignupPort, "file2")
            };
            SearchStatus.Text = ""; ShowFoundGames();
            Check(FoundGames.Children.Count == 2 && !SearchStatus.IsVisible,
                "Discovery rows show only the selected edition and empty status text occupies no space");
            Invoke((Button)FoundGames.Children[0]); await Wait(() => settings.CoopHost == "192.0.2.21");
            Check(Stored().JoinHostName == "Cindy" && Stored().JoinSignupPort == HostNetworking.SignupPort + 12 &&
                Stored().JoinRoomName == "CindyRoom" && LobbyOptions()?.Title == "CindyRoom" && OnlineOptions.Configured(settings),
                "Selecting a discovered game persists its address, room title, host name and advertised sign-up port");
            var selectedRow = (Button)FoundGames.Children[0];
            Check(selectedRow.BorderBrush is SolidColorBrush brush && brush.Color == Palette.Accent,
                "The selected discovered game receives the launcher's orange selection marker");
            SettingsScroll.ScrollToTop(); Capture("coop-join");
            Text(CoopHost, "192.0.2.30");
            Check(Stored().CoopHost == "192.0.2.30" && Stored().JoinHostName == "" && Stored().JoinSignupPort == 0 && Stored().JoinRoomName == "",
                "Manual host entry clears stale discovery metadata and persists the typed address");
            Text(CoopHost, "bad address");
            Check(CoopValidation.IsVisible && !OnlineOptions.Configured(settings),
                "An invalid manual address shows validation and cannot become a configured session");
            Text(CoopHost, "192.0.2.30"); Text(AccountUsername, "bad name");
            Check(CoopValidation.IsVisible && CoopValidation.Text.Contains("Player name"),
                "Player-name validation remains connected to the real settings rules");
            Text(AccountUsername, "Kevin");
            Check(!CoopValidation.IsVisible && AccountStatus.Visibility == Visibility.Collapsed,
                "Valid settings clear inline validation and empty account status");

            Width = MinWidth; Height = MinHeight; await Task.Delay(250); UpdateLayout();
            Check(AccountUsername.ActualWidth >= 200 && CoopHost.ActualWidth >= 290 &&
                CoopHost.TranslatePoint(new Point(CoopHost.ActualWidth, 0), PageContent).X <= PageContent.ActualWidth,
                "Player and connection columns fit at the launcher's minimum window width");
            Check(new[] { ModeOffline, ModeHost, ModeJoin }.All(mode => mode.ActualWidth >= 180),
                "All three mode selectors retain usable hit targets at minimum width");
            SettingsScroll.ScrollToTop(); Capture("coop-compact");
            launching = true; RefreshOnlineUi();
            Check(!CoopControls.IsEnabled && !ModeHost.IsEnabled && !CoopHost.IsEnabled && !AutoLobby.IsEnabled,
                "Session settings disable while a game launch is being prepared");
            launching = false; RefreshOnlineUi();
            Check(CoopControls.IsEnabled, "Co-op controls recover after launch preparation ends");

            GamePicker.SelectedValue = "file2"; await Task.Delay(80);
            Check(settings.Game.Id == "file2" && FoundGames.Children.Count == 0 && settings.JoinHostName == "",
                "Changing editions clears discovery results and stale host identity");
            Mode(ModeHost); await Wait(() => RoomSettings.IsVisible);
            RoomWait.SelectedValue = 3;
            Check(Stored().RoomWaitMinutes == 3 && LobbyOptions()?.WaitMinutes == 3,
                "File #2 exposes its original three-minute waiting time");
            GamePicker.SelectedValue = "file1"; await Task.Delay(50);
            Check((int)RoomWait.SelectedValue == 5 && LobbyOptions()?.WaitMinutes == 5 && Stored().RoomWaitMinutes == 3,
                "File #1 uses a supported five-minute wait while retaining the File #2 preference");
            GamePicker.SelectedValue = "file2"; await Task.Delay(50);
            Check((int)RoomWait.SelectedValue == 3, "Returning to File #2 restores its three-minute selection");
            Check(searches.GetValueOrDefault("file2") == 1 && searches["file1"] == 2,
                "Each edition receives one initial discovery request; returning to it needs the Search again button");
            Mode(ModeJoin); await Wait(() => JoinOptions.IsVisible);
            foundGames = new() { new("Yoko", "198.51.100.21", Updates.DefaultVersion, true, HostNetworking.SignupPort, "file2") };
            ShowFoundGames(); Invoke((Button)FoundGames.Children[0]); await Wait(() => settings.JoinHostName == "Yoko");
            Check(Stored().CoopHost == "198.51.100.21" && OnlineOptions.Configured(settings),
                "File #2 uses the same redesigned joining controls and persisted host selection");
            Mode(ModeOffline); await Wait(() => OfflinePanel.IsVisible && settings.ResolvedCoopMode == "offline");
            Check(!OnlinePanel.IsVisible && !Stored().HostServer && OnlineOptions.LaunchEnvironment(settings).Count == 0,
                "Returning to Play alone removes online launch settings while retaining player preferences");
            Width = 1320; Height = 920; await Task.Delay(150);
            Check(CoopModeBar.TranslatePoint(new Point(), PageCoop) == barPosition,
                "The mode selector stays in place across offline, hosting and joining states");
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = true, checks,
                inputMethod = "Real WPF radio, value, toggle, button and expander automation; persisted settings; fixture discovery rows and hosting status. No servers started, real LAN queries, firewall edits or router changes."
            }, new JsonSerializerOptions { WriteIndented = true }));
        } catch (Exception error) {
            await File.WriteAllTextAsync(Path.Combine(output, "result.json"), JsonSerializer.Serialize(new {
                passed = false, checks, error = error.ToString()
            }, new JsonSerializerOptions { WriteIndented = true }));
            Environment.ExitCode = 1;
        } finally {
            launching = false; timer.Stop(); audioSaveTimer.Stop(); colorSaveTimer.Stop();
            gameSearch?.Cancel(); accountPreparation?.Cancel(); Close();
            if (saved == null) File.Delete(path); else File.WriteAllBytes(path, saved);
        }
    }
}
