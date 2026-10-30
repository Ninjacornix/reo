using System.IO;
using System.IO.MemoryMappedFiles;
using System.IO.Pipes;
using System.Runtime.InteropServices;
using System.Text.Json;

namespace Outbreak.Launcher;
static class SelfTest {
    [StructLayout(LayoutKind.Sequential)]
    struct XState {
        public uint Packet;
        public ushort Buttons;
        public byte LT, RT;
        public short LX, LY, RX, RY;
    }
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    delegate uint GetState(uint index, out XState state);
    [DllImport("kernel32", CharSet = CharSet.Ansi)]
    static extern nint GetProcAddress(nint module, nint ordinal);
    public static object Probe(Controller controller) {
        controller.SessionEnabled = true;
        controller.Publish();
        Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", controller.MapName);
        nint library = NativeLibrary.Load(Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll"));
        var get = Marshal.GetDelegateForFunctionPointer<GetState>(GetProcAddress(library, 2));
        uint status = get(0, out var state);
        var result = new { status,
                           packet = state.Packet,
                           buttons = state.Buttons,
                           leftTrigger = state.LT,
                           rightTrigger = state.RT,
                           leftX = state.LX,
                           leftY = state.LY,
                           rightX = state.RX,
                           rightY = state.RY };
        NativeLibrary.Free(library);
        return result;
    }
    sealed class UndispatchedContext : SynchronizationContext {
        public int Posts;
        public override void Post(SendOrPostCallback callback,
                                  object? state) => Interlocked.Increment(ref Posts);
    }
    public static void Run() {
        int checks = 0;
        void Check(bool condition, string message) {
            if (!condition)
                throw new Exception(message);
            checks++;
        }
        Task.Run(() => StorageTests.Run(Check)).GetAwaiter().GetResult();
        DiscImportTests.Run(Check);
        Task.Run(() => BackgroundVideoTests.Run(Check)).GetAwaiter().GetResult();
        GameArtworkTests.Run(Check);
        GameControllerArtworkTests.Run(Check);
        GameFontTests.Run(Check);
        PaletteTests.Run(Check);
        GameArtworkDownloadTests.Run(Check);
        GraphicsOptionsTests.Run(Check);
        GamePreviewAssetsTests.Run(Check);
        GamePreviewAnimationTests.Run(Check);
        GamePreviewWeaponTests.Run(Check);
        PreviewInteractionTests.Run(Check);
        ModsTests.Run(Check);
        RandomizerSeedsTests.Run(Check);
        Task.Run(() => RandomizerSessionTests.Run(Check)).GetAwaiter().GetResult();
        OnlineOptionsTests.Run(Check);
        CoopAutomationTests.Run(Check);
        CoopSmokeOptionsTests.Run(Check);
        File2LobbyTests.Run(Check);
        LobbyRoomSettingsTests.Run(Check);
        ControllerLightTests.Run(Check);
        ControllerRumbleTests.Run(Check);
        ControllerInputTests.Run(Check);
        MemoryCardBackupTests.Run(Check);
        GlobalWeaponMotionsTests.Run(Check);
        AudioMixerTests.Run(Check);
        AudioOutputTests.Run(Check);
        CheatCompatibilityTests.Run(Check);
        SubtitleControlTests.Run(Check);
        NetworkTraceTests.Run(Check);
        DeveloperOptionsTests.Run(Check);
        GameImageCacheTests.Run(Check);
        Task.Run(() => AutomaticAccountTests.Run(Check)).GetAwaiter().GetResult();
        Task.Run(() => UpdateTests.Run(Check)).GetAwaiter().GetResult();
        Task.Run(() => LocalGameBuildTests.Run(Check)).GetAwaiter().GetResult();
        Task.Run(() => File2LauncherTests.Run(Check)).GetAwaiter().GetResult();
        Task.Run(() => ExistingGameBuildTests.Run(Check)).GetAwaiter().GetResult();
        string pipeName = "reo-log-check-" + Guid.NewGuid().ToString("N"),
               pipeOutput = Path.GetTempFileName();
        using (var pipeReader = new NamedPipeServerStream(
                   pipeName, PipeDirection.In, 1, PipeTransmissionMode.Byte,
                   PipeOptions.Asynchronous)) using (var pipeWriter =
                                                         new NamedPipeClientStream(
                                                             ".", pipeName, PipeDirection.Out,
                                                             PipeOptions.Asynchronous)) {
            var connection = pipeReader.WaitForConnectionAsync();
            pipeWriter.Connect(3000);
            connection.Wait();
            var oldContext = SynchronizationContext.Current;
            var blockedUi = new UndispatchedContext();
            try {
                SynchronizationContext.SetSynchronizationContext(blockedUi);
                var drain =
                    GameSession.Pump(new StreamReader(pipeReader), new StreamWriter(pipeOutput));
                var write = Task.Run(() => {
                    using var writer = new StreamWriter(pipeWriter);
                    for (int i = 0; i < 2000; i++)
                        writer.WriteLine(new string('x', 200));
                });
                Check(Task.WaitAll(new[] { drain, write }, 5000) && blockedUi.Posts == 0,
                      "Large game log pipes drain even while the UI cannot dispatch messages");
                Check(new FileInfo(pipeOutput).Length >= 400000,
                      "The complete native log stream reaches disk");
            } finally {
                SynchronizationContext.SetSynchronizationContext(oldContext);
                File.Delete(pipeOutput);
            }
        }
        var builtinCheats = Cheats.Builtins("file1");
        Check(builtinCheats.Count == 6 &&
                  builtinCheats.All(g => g.Supported && g.Writes.Count == 0),
              "Built-in toggles work without imported cheat files");
        Check(builtinCheats.Select(g => g.Id).Distinct().Count() == 6 &&
                  Cheats.Builtins("file2").Count == 5 &&
                  Cheats.Builtins("file2").All(g => g.Id.StartsWith("builtin.file2.")),
              "Built-ins have stable separate identities for each game");
        Check(builtinCheats.Any(g => g.Builtin == "health") &&
                  builtinCheats.Any(g => g.Builtin == "infection") &&
                  builtinCheats.Any(g => g.Builtin == "ammo") &&
                  builtinCheats.Any(g => g.Builtin == "unlock") &&
                  builtinCheats.Any(g => g.Builtin == "points") &&
                  builtinCheats.Any(g => g.Builtin == "escape"),
              "Health, infection, ammunition, progression unlocks, results points and escape time are built in");
        var cheatGroups = Cheats.Parse("[Health]\npatch=1,EE,004A5C40,word,000003E8\n[" +
                                           "Unsupported]\npatch=1,EE,D04A5C40,extended,00000001",
                                       "test.pnach");
        Check(cheatGroups.Count == 2 && cheatGroups[0].Supported && !cheatGroups[1].Supported,
              "Unsupported cheat groups fail atomically");
        Check(Cheats.Parse("patch=2,EE,204A5C40,extended,000003E8", "test")[0].Writes[0] ==
                  new CheatWrite(2, 0x4a5c40, 4, 1000),
              "RAW word decoding");
        Check(Cheats.Parse("patch=1,EE,804A5C40,short,03E8", "test")[0].Writes[0].Address ==
                  0x4a5c40,
              "EE address alias decoding");
        Check(!Cheats.Parse("patch=1,EE,00100000,word,00000000", "test")[0].Supported,
              "Native instruction patches refused");
        Check(!Cheats.Parse("patch=1,IOP,004A5C40,word,00000000", "test")[0].Supported,
              "IOP cheats refused");
        Check(!Cheats.Parse("patch=1,EE,004A5C40,byte,100", "test")[0].Supported,
              "Overflow refused");
        Check(!Cheats.Parse("patch=1,EE,00580000,word,00000000", "test")[0].Supported,
              "Overlay patch refused");
        Check(!Cheats.DataAddress(0x1fcffff, 8) && !Cheats.DataAddress(0x56ffff, 8),
              "Range crossing refused");
        Check(!Cheats
                   .Parse("[Mixed]\npatch=1,EE,004A5C40,word,00000001\npatch=1,EE,E0010000," +
                              "extended,004A5C40",
                          "test")[0]
                   .Supported,
              "Valid lines cannot partially enable an unsupported group");
        Check(Cheats.Export(new Settings { CheatsEnabled = false }, Path.GetTempPath()) == "",
              "Disabled cheats never export");
        string unlockFixture = Path.Combine(Path.GetTempPath(), "reo-unlock-export-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(unlockFixture);
        try {
            var unlockSettings = new Settings { SelectedGame = "file1", CheatsEnabled = true,
                EnabledCheats = new() { "builtin.file1.unlock" } };
            string unlockFile = Cheats.Export(unlockSettings, unlockFixture);
            Check(File.ReadAllLines(unlockFile).SequenceEqual(new[] { "REO-CHEATS-2", "builtin unlock" }),
                  "Unlock selection exports only the progression builtin");
            unlockSettings.CheatsEnabled = false;
            Check(Cheats.Export(unlockSettings, unlockFixture) == "",
                  "Unlock selection still respects the master cheat switch");
            var secondCheats = new Settings { SelectedGame = "file2", CoopMode = "offline",
                CheatsEnabled = true, EnabledCheats = new() { "builtin.file1.unlock", "builtin.file1.health" } };
            Check(Cheats.Export(secondCheats, unlockFixture) == "",
                  "File #1 selections never apply to File #2");
            secondCheats.EnabledCheats.AddRange(Cheats.Builtins("file2").Select(g => g.Id));
            string secondFile = Cheats.Export(secondCheats, unlockFixture);
            Check(File.ReadAllLines(secondFile).SequenceEqual(new[] {
                      "REO-CHEATS-2", "builtin health", "builtin infection", "builtin ammo", "builtin points", "builtin escape" }),
                  "File #2 exports its own health, infection, ammunition, results points and escape time selections");
            secondCheats.SelectedGame = "file1";
            secondCheats.EnabledCheats = Cheats.Builtins("file2").Select(g => g.Id).ToList();
            Check(Cheats.Export(secondCheats, unlockFixture) == "",
                  "File #2 selections never apply to File #1");
            secondCheats.SelectedGame = "file2";
            secondCheats.CheatsEnabled = false;
            Check(Cheats.Export(secondCheats, unlockFixture) == "",
                  "File #2 respects the master cheat switch");
            secondCheats.CheatsEnabled = true;
            secondCheats.CoopMode = "host";
            bool blockedOnlineCheats = false;
            try { Cheats.Export(secondCheats, unlockFixture); }
            catch (IOException) { blockedOnlineCheats = true; }
            Check(blockedOnlineCheats, "File #2 cheats cannot be enabled in co-op");
        } finally { Directory.Delete(unlockFixture, true); }
        var usb = new byte[64];
        usb[0] = 1;
        Array.Fill(usb, (byte)128, 1, 4);
        usb[8] = 8;
        Check(Controller.TryParse(usb, 12, out var neutral) && neutral == new Pad(),
              "USB neutral report");
        usb[8] = 0xF1;
        usb[9] = 0xF3;
        usb[5] = 200;
        usb[6] = 240;
        usb[1] = 255;
        usb[2] = 0;
        Check(Controller.TryParse(usb, 12, out var held), "USB held report");
        Check(held.Buttons == 0xF3F9 && held.LT == 200 && held.RT == 240,
              "Face/dpad/system/shoulder mapping");
        Check(held.LX == 32767 && held.LY == 32767, "Analog extrema and Y orientation");
        var bt = new byte[78];
        bt[0] = 0x31;
        usb.AsSpan(1).CopyTo(bt.AsSpan(2));
        Check(Controller.TryParse(bt, 12, out var bluetooth) && bluetooth == held,
              "Bluetooth enhanced parity");
        var simple = new byte[] { 1, 128, 128, 128, 128, 0x28, 0x20, 0, 42, 43 };
        Check(Controller.TryParse(simple, 12, out var basic) && basic.Buttons == 0x1010 &&
                  basic.LT == 42 && basic.RT == 43,
              "Bluetooth simple report");
        Check(!Controller.TryParse(new byte[3], 12, out _), "Truncated report rejected");
        usb[0] = 0x55;
        Check(!Controller.TryParse(usb, 12, out _), "Foreign report rejected");
        var inside = InputMapping.FilterStick(1500, 1500, 12);
        Check(inside == (0, 0), "Circular dead zone removes small diagonal drift");
        var beyond = InputMapping.FilterStick(4000, 4000, 12);
        Check(beyond.X > 0 && beyond.X == beyond.Y && beyond.X < 4000,
              "Circular boundary keeps direction and rescales");
        var maximum = InputMapping.FilterStick(32767, 0, 30);
        Check(maximum == (32767, 0), "Dead zone preserves full travel");
        var profile = new PadProfile();
        profile.Buttons["Cross"] = 0x2000;
        profile.Buttons["Circle"] = 0;
        profile.Buttons["R2"] = InputMapping.LeftTrigger;
        var remapped = InputMapping.RemapPad(new(0x2000, 123, 0, 20000, 0), profile);
        Check(remapped.Buttons == 0x1000 && remapped.RT == 123,
              "Remap buttons and analog triggers without leaking old binding");
        profile.SwapSticks = true;
        profile.InvertRightY = true;
        var swapped = InputMapping.RemapPad(new(0, 0, 0, 0, 20000), profile);
        Check(swapped.LY == 0 && swapped.RY < 0, "Stick swap and right Y inversion");
        var stickFeedbackProfile = new PadProfile { DeadZone = 0 };
        var leftFeedback = new StickPlot(); var rightFeedback = new StickPlot();
        void UpdateStickFeedback(Pad physical) {
            var mapped = InputMapping.RemapPad(physical, stickFeedbackProfile);
            leftFeedback.Update(mapped, stickFeedbackProfile.DeadZone, false);
            rightFeedback.Update(mapped, stickFeedbackProfile.DeadZone, true);
        }
        UpdateStickFeedback(new(0, 0, 0, 16384, -8192));
        Check(leftFeedback.Position == new System.Windows.Point(.5, .25) && rightFeedback.Position == default,
            "Moving only the physical left stick updates only the left game-input plot");
        stickFeedbackProfile.SwapSticks = true;
        UpdateStickFeedback(new(0, 0, 0, 16384, -8192));
        Check(leftFeedback.Position == default && rightFeedback.Position == new System.Windows.Point(.5, .25),
            "Swapping sticks moves left-stick feedback to the right plot without a duplicate raw marker");
        UpdateStickFeedback(new(0, 0, 0, 0, 0, 16384, -8192));
        Check(leftFeedback.Position == new System.Windows.Point(.5, .25) && rightFeedback.Position == default,
            "Swapping sticks moves right-stick feedback to the left plot only");
        stickFeedbackProfile.InvertRightY = true;
        UpdateStickFeedback(new(0, 0, 0, 16384, -8192));
        Check(leftFeedback.Position == default && rightFeedback.Position == new System.Windows.Point(.5, -.25),
            "Right-Y inversion affects only the mapped right game-input plot");
        Check(InputMapping.Keyboard(InputMapping.KeyboardDefaults(), k => k == 13).Buttons == 0x10,
              "Enter still maps to Start");
        Check(InputMapping.Keyboard(InputMapping.KeyboardDefaults(), k => k == 13 || k == 17)
                      .Buttons == 0,
              "Ctrl+Enter is reserved for fullscreen");
        var chord = new FullscreenChord();
        Check(chord.SuppressEnter(true, true), "Fullscreen chord captures Enter");
        Check(chord.SuppressEnter(true, false), "Releasing Control first cannot press Start");
        Check(!chord.SuppressEnter(false, false) && !chord.SuppressEnter(true, false),
              "Ordinary Enter resumes after release");
        string cardHome =
            Path.Combine(Path.GetTempPath(), "reo-card-test-" + Guid.NewGuid().ToString("N"));
        var cardA = MemoryCards.Create("Test card A", cardHome);
        var cardB = MemoryCards.Create("Test card B", cardHome);
        Check(cardA.Folder != cardB.Folder && Directory.Exists(cardA.Folder),
              "Separate named cards have separate storage");
        var cardSettings = new Settings();
        cardSettings.SelectCard(cardA.Folder);
        Check(cardSettings.CardFolder(cardHome) == cardA.Folder, "Selected card used for File 1");
        cardSettings.SelectedGame = "file2";
        Check(cardSettings.CardFolder(cardHome) == cardA.Folder,
              "File 2 shares the selected memory card");
        cardSettings.SelectCard(cardB.Folder);
        cardSettings.SelectedGame = "file1";
        Check(cardSettings.CardFolder(cardHome) == cardB.Folder,
              "Selecting a card in either game changes the shared selection");
        using (var lease = MemoryCards.Acquire(cardA.Folder)) {
            bool rejected = false;
            try {
                using var second = MemoryCards.Acquire(cardA.Folder);
            } catch (IOException) {
                rejected = true;
            }
            Check(rejected, "Active card cannot be acquired by two sessions");
        }
        using (var reopened = MemoryCards.Acquire(cardA.Folder))
            Check(reopened.CanWrite, "Card lock released after session");
        var keyboard = InputMapping.KeyboardDefaults();
        keyboard["Cross"] = 'K';
        var keys = InputMapping.Keyboard(keyboard, k => k == 'K' || k == 'W');
        Check(keys.Buttons == 0x1001 && keys.LY == 32767, "Keyboard remap and movement");
        Check(InputMapping.Keyboard(keyboard, k => k == 'W' || k == 'S').LY == 0,
              "Opposite keyboard movement cancels");
        keyboard["Cross"] = 0;
        Check(InputMapping.Keyboard(keyboard, k => k == 'K').Buttons == 0,
              "Cleared key cannot produce stale action");
        Pad? simulatedXbox = new Pad(0x4000, 77, 89, 16384, -16384);
        using (var devices = new Controller(slot => slot == 2 ? simulatedXbox : null)) {
            var config = new Settings { InputDeviceId = "xbox:2" };
            devices.Configure(config);
            devices.Poll();
            Check(devices.AvailableDevices.Count == 2 && devices.XboxCount == 1 &&
                      devices.SelectedDevice.Kind == "xbox",
                  "Detect connected Xbox slot and keyboard without phantom slots");
            Check(devices.RawState == simulatedXbox && devices.State.Buttons == 0x4000 &&
                      devices.State.LT == 77,
                  "Selected Xbox state reaches normalized game input");
            simulatedXbox = null;
            devices.Poll();
            Check(!devices.Connected && devices.State == new Pad(),
                  "Selected Xbox disconnect releases controls without falling back");
            simulatedXbox = new Pad(0x1000);
            devices.Select("keyboard");
            devices.Poll();
            Check(devices.State.Buttons != 0x1000 && devices.SelectedDevice.Kind == "keyboard",
                  "Keyboard selection ignores unselected Xbox");
            config.Xbox.Buttons["Cross"] = 0x4000;
            string json = JsonSerializer.Serialize(config);
            var restored = JsonSerializer.Deserialize<Settings>(json)!;
            Check(restored.InputDeviceId == "keyboard" && restored.Xbox.Buttons["Cross"] == 0x4000,
                  "Selection and independent layouts persist");
        }
        var games = new Settings { Exe = "first.exe", Iso = "first.iso", SecondExe = "second.exe",
                                   SecondIso = "second.iso", SelectedGame = "file2" };
        Check(games.GetExe() == "second.exe" && games.GetIso() == "second.iso" &&
                  games.GetElf("C:\\games").EndsWith("game_data_file2\\SLUS_209.84"),
              "Game selection uses independent executable, ISO and ELF");
        Check(GameSession.SaveFolder("C:\\games", "file1") ==
                  GameSession.SaveFolder("C:\\games", "file2"),
              "Both games use the same default memory-card folder");
        games.SelectedGame = "file1";
        Check(games.GetExe() == "first.exe" && games.GetIso() == "first.iso",
              "Switching back preserves first game configuration");
        Check(DisplayOptions.Size(0) == new OutputSize(1024, 768) &&
                  DisplayOptions.Size(2) == new OutputSize(1600, 1200),
              "Existing resolution settings retain their original dimensions");
        Check(DisplayOptions.Size(4) == new OutputSize(1920, 1080) &&
                  DisplayOptions.Size(6) == new OutputSize(3840, 2160),
              "1080p and 4K use the selected output aspect ratio");
        Check(DisplayOptions.MenuSizes[0] == new OutputSize(512, 448) &&
                  DisplayOptions.MenuSizes.Take(5).Select(s => s.Height)
                      .SequenceEqual(new[] { 448, 720, 1080, 1440, 2160 }) &&
                  Array.IndexOf(DisplayOptions.Sizes, DisplayOptions.MenuSizes[2]) == 4,
              "Named resolution presets include Native through 4K without changing saved indices");
        Check(DisplayOptions.Size(-5) == DisplayOptions.Sizes[0] &&
                  DisplayOptions.Size(99) == DisplayOptions.Sizes[^1],
              "Invalid resolution settings are bounded");
        var graphics = new Settings { Fullscreen = true, WindowSize = 4, TextureLinear = true,
                                      AntiAliasing = true };
        var graphicsRoundtrip =
            JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(graphics))!;
        Check(!JsonSerializer.Deserialize<Settings>("{}")!.PerformanceOverlay &&
                  JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(
                      new Settings { PerformanceOverlay = true }))!.PerformanceOverlay,
              "Performance overlay defaults off and its saved toggle survives serialization");
        Check(JsonSerializer.Deserialize<Settings>("{}")!.ResolvedInternalResolution == 1 &&
                  new Settings { InternalResolution = -1 }.ResolvedInternalResolution == 1 &&
                  new Settings { InternalResolution = 8 }.ResolvedInternalResolution == 1,
              "Old and invalid internal resolution settings use Native");
        Check(JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(
                  new Settings { InternalResolution = 2 }))!.ResolvedInternalResolution == 2,
              "2x internal resolution survives serialization");
        Check(JsonSerializer.Deserialize<Settings>(JsonSerializer.Serialize(
                  new Settings { InternalResolution = 4 }))!.ResolvedInternalResolution == 4,
              "4x internal resolution survives serialization");
        var preparingGraphics = new GameSession();
        preparingGraphics.ObserveGraphicsLine("[INFO]: [SHADER-WARMUP] progress 16/64");
        Check(preparingGraphics.GraphicsStatus == "Preparing graphics · 25%",
              "Actual shader progress is shown in the launcher");
        preparingGraphics.ObserveGraphicsLine("[SHADER-WARMUP] progress 2/0");
        preparingGraphics.ObserveGraphicsLine("[SHADER-WARMUP] progress 80/64");
        Check(preparingGraphics.GraphicsStatus == "Preparing graphics · 25%",
              "Malformed shader progress cannot replace the last valid status");
        preparingGraphics.ObserveGraphicsLine("[SHADER-WARMUP] ready");
        Check(preparingGraphics.GraphicsStatus == null &&
                  preparingGraphics.WaitForGraphicsReadyAsync(TimeSpan.FromSeconds(1)).IsCompletedSuccessfully,
              "Completed shader preparation clears the startup status");
        Check(JsonSerializer.Deserialize<Settings>("{\"Anisotropy\":16}")!.ResolvedAnisotropy ==
                      16 &&
                  new Settings { Anisotropy = 3 }.ResolvedAnisotropy == 1 &&
                  new Settings().ResolvedAnisotropy == 1,
              "Anisotropic filtering persists supported levels and defaults invalid/old settings " +
                  "to off");
        Check(graphicsRoundtrip.Fullscreen && graphicsRoundtrip.WindowSize == 4 &&
                  graphicsRoundtrip.TextureLinear && graphicsRoundtrip.AntiAliasing,
              "Display and startup preferences survive serialization");
        {
            var kind = (string a, string adapter) =>
                HostNetworking.Classify(System.Net.IPAddress.Parse(a), adapter);
            Check(kind("192.168.1.20", "Ethernet") == HostNetworking.AddressKind.Home &&
                      kind("10.0.0.5", "Wi-Fi") == HostNetworking.AddressKind.Home &&
                      kind("172.16.4.1", "Ethernet") == HostNetworking.AddressKind.Home &&
                      kind("172.32.0.1", "Ethernet") == HostNetworking.AddressKind.Public &&
                      kind("100.101.102.103", "Tailscale") == HostNetworking.AddressKind.Vpn &&
                      kind("25.1.2.3", "Hamachi") == HostNetworking.AddressKind.Vpn &&
                      kind("8.8.8.8", "Ethernet") == HostNetworking.AddressKind.Public,
                  "Hosting addresses are classified as home network, VPN or internet");
            Check(HostNetworking.IsVirtualAdapter("vEthernet (WSL (Hyper-V firewall))") &&
                      HostNetworking.IsVirtualAdapter("VirtualBox Host-Only Ethernet Adapter") &&
                      !HostNetworking.IsVirtualAdapter("Ethernet Realtek PCIe GbE") &&
                      !HostNetworking.IsVirtualAdapter("Hamachi LogMeIn Hamachi Virtual Ethernet"),
                  "Virtual machine adapters are not offered as hosting addresses");
            Check(
                HostNetworking.BehindAnotherNat("100.70.1.2") &&
                    HostNetworking.BehindAnotherNat("192.168.0.1") &&
                    !HostNetworking.BehindAnotherNat("93.184.216.34") &&
                    !HostNetworking.BehindAnotherNat(null),
                "A router with a non-public internet address is reported as behind another network");
            Check(HostNetworking.Ports.Select(p => p.Number + p.Protocol)
                          .SequenceEqual(new[] { "10128TCP", "10127TCP", "9090UDP", "9091UDP",
                                                 "10129UDP" }) &&
                      HostNetworking.PortList.Contains("9091 UDP"),
                  "Hosting lists the server and discovery ports, without port 80");
            var forward = JsonSerializer.Deserialize<Settings>(
                JsonSerializer.Serialize(new Settings { AutoForward = true }))!;
            Check(forward.AutoForward && !new Settings().AutoForward,
                  "Automatic router forwarding is opt-in and persists");
        }
        var feedbackProfile = new PadProfile();
        feedbackProfile.Buttons["Cross"] = 0x2000;
        feedbackProfile.Buttons["Circle"] = 0;
        var feedbackPad = InputMapping.RemapPad(new Pad(0x2000, 30, 31), feedbackProfile);
        Check(InputMapping.ActionPressed(feedbackPad, "Cross") &&
                  !InputMapping.ActionPressed(feedbackPad, "Circle"),
              "Input feedback follows remapped actions and leaves unbound actions inactive");
        Check(!InputMapping.ActionPressed(feedbackPad, "L2") &&
                  InputMapping.ActionPressed(feedbackPad, "R2"),
              "Input feedback uses the same trigger threshold as game button input");
        var feedbackKeys = InputMapping.Keyboard(InputMapping.KeyboardDefaults(),
                                                key => key is 32 or 38);
        Check(InputMapping.ActionPressed(feedbackKeys, "Cross") &&
                  InputMapping.ActionPressed(feedbackKeys, "CameraUp") &&
                  !InputMapping.ActionPressed(feedbackKeys, "CameraDown") &&
                  !InputMapping.ActionPressed(new Pad(), "Cross"),
              "Keyboard feedback covers simultaneous buttons and camera keys and clears on release");
        var feedbackButton = new System.Windows.Controls.Button {
            Style = (System.Windows.Style)System.Windows.Application.Current.FindResource(
                typeof(System.Windows.Controls.Button))
        };
        feedbackButton.ApplyTemplate();
        var feedbackFrame = (System.Windows.Controls.Border)feedbackButton.Template.FindName(
            "Frame", feedbackButton);
        var idleBackground = feedbackFrame.Background;
        InputFeedback.SetIsActive(feedbackButton, true);
        Check(feedbackFrame.Background == System.Windows.Application.Current.FindResource("Accent"),
              "Held input lights the binding button using the real launcher template");
        InputFeedback.SetIsActive(feedbackButton, false);
        Check(feedbackFrame.Background == idleBackground,
              "Releasing input restores the binding button background");
        var colorSettings =
            JsonSerializer.Deserialize<Settings>("{\"Brightness\":125,\"Gamma\":1.25}")!;
        Check(colorSettings.Brightness == 125 && colorSettings.Gamma == 1.25,
              "Brightness and gamma retain their saved values");
        var effect = new ColorPreviewEffect { Gain = 1.25, Gamma = 1.25 };
        Check(effect.Gain == 1.25 && effect.Gamma == 1.25,
              "Preview shader loads with both adjustment constants");
        Check(JsonSerializer.Deserialize<Settings>(
                                "{\"AntiAliasing\":false}")!.ResolvedAntiAliasing == "off",
              "Legacy disabled AA remains off");
        Check(JsonSerializer.Deserialize<Settings>(
                                "{\"AntiAliasing\":true}")!.ResolvedAntiAliasing == "fxaa",
              "Legacy enabled AA remains FXAA");
        Check(
            JsonSerializer
                    .Deserialize<Settings>("{\"AntiAliasing\":true,\"AntiAliasingMode\":\"smaa\"}")!
                    .ResolvedAntiAliasing == "smaa",
            "SMAA selection survives settings serialization");
        Check(new Settings().ResolvedAspect == "4:3" && new Settings().ResolvedFit == "fit",
              "Existing installations preserve original 4:3 fit");
        var layout = JsonSerializer.Deserialize<Settings>(
            "{\"AspectRatio\":\"16:9\",\"ScreenFit\":\"center\"}")!;
        Check(layout.ResolvedAspect == "16:9" && layout.ResolvedFit == "center",
              "Aspect and centered sizing survive settings loading");
        Check(DisplayOptions.Aspects.All(aspect => new Settings { AspectRatio = aspect }.ResolvedAspect == aspect),
              "Every listed aspect ratio, including ultrawide, survives settings loading");
        Check(!new Settings { AspectRatio = "16:9" }.ResolvedWidescreen &&
                  !new Settings { AspectRatio = "4:3", WidescreenCamera = true }.ResolvedWidescreen &&
                  JsonSerializer.Deserialize<Settings>("{\"AspectRatio\":\"21:9\",\"WidescreenCamera\":true}")!.ResolvedWidescreen &&
                  DisplayOptions.AspectChoices.Distinct().Count() == DisplayOptions.AspectChoices.Length,
              "Existing 16:9 stays stretched; widescreen camera needs a wide ratio and survives loading");
        string deep = @"C:\Users\Player Name\AppData\Local\OutbreakRecomp\launcher\local-games\file1\" +
                      new string('0', 64) + @"\work\project\build-ninja\parallel-gs-source\Granite\third_party\spirv-tools\test\opt\loop_optimizations\pch_test_opt_loop.h";
        string longPath = "shutil.Error: [('" + deep + "', '" + deep + "', '[WinError 3] The system cannot find the path specified')]";
        string unicodePath = "Recompiler failed for main (exit 1):\n  Error: Could not load ELF file: C:/Users/Jo\u00e3o/disc/SLUS_207.65\n" +
                             "subprocess.CalledProcessError: Command '['ps2_recomp.exe']' returned non-zero exit status 1.";
        Check(BuildFailure.Explain(longPath)!.Contains("longer than Windows allows") &&
                  BuildFailure.Explain(unicodePath)!.Contains("letters such as") &&
                  BuildFailure.Explain("[WinError 3] 'C:\\short\\missing.h'") == null &&
                  BuildFailure.LastError(unicodePath)!.StartsWith("subprocess.CalledProcessError") &&
                  BuildFailure.Message("generate", 1, "cache", longPath).Contains("Error: shutil.Error"),
              "Build failures name long paths and non-ASCII folders and quote the last error");
        var calibration = CalibrationPreview.Create();
        byte Grey(int x, int y) {
            var pixel = new byte[4];
            calibration.CopyPixels(new System.Windows.Int32Rect(x, y, 1, 1), pixel, 4, 0);
            return pixel[0];
        }
        Check(calibration.PixelWidth == CalibrationPreview.Width && calibration.PixelHeight == CalibrationPreview.Height &&
                  Enumerable.Range(0, CalibrationPreview.Shadows.Length).All(i =>
                      Grey(40 + 24 + i * 64 + 24, 116 + 48) == CalibrationPreview.Shadows[i] &&
                      Grey(CalibrationPreview.Width - 40 - 420 + 24 + i * 64 + 24, 116 + 48) == CalibrationPreview.Highlights[i]),
              "Brightness calibration preview draws its exact shadow and highlight levels");
        Check(new Settings { AspectRatio = "invalid", ScreenFit = "invalid" }.ResolvedAspect ==
                      "4:3" &&
                  new Settings { ScreenFit = "invalid" }.ResolvedFit == "fit",
              "Invalid display modes fall back safely");
        Check(DisplayOptions.Fits.Distinct().Count() == 4 &&
                  DisplayOptions.FitName("stretch") == "Stretched",
              "Screen fit choices have distinct persisted values");
        string logFixture = Path.GetTempFileName();
        try {
            File.WriteAllText(logFixture,
                              string.Concat(Enumerable.Repeat("earlier diagnostic row\n", 1000)) +
                                  "last diagnostic row\n");
            string tail = LogTail.Read(logFixture, 512);
            Check(tail.Length <= 512 && tail.EndsWith("last diagnostic row\n"),
                  "Debug log tail is bounded and includes latest complete row");
            File.WriteAllText(logFixture, new string('x', 4096));
            Check(LogTail.Read(logFixture, 512).Length == 512,
                  "Long unbroken diagnostic line stays visible");
            using var writer =
                new FileStream(logFixture, FileMode.Open, FileAccess.Write, FileShare.ReadWrite);
            Check(LogTail.Read(logFixture, 512).Length == 512,
                  "Tail can read while the game writer holds its file");
        } finally {
            File.Delete(logFixture);
        }
        string name = "Local\\REO-Test-" + Guid.NewGuid().ToString("N");
        using var map = MemoryMappedFile.CreateNew(name, 64);
        using var view = map.CreateViewAccessor();
        view.Write(0, Controller.Magic);
        view.Write(4, 2);
        view.Write(8, 1);
        view.Write(12, unchecked((uint)Environment.TickCount));
        view.Write(16, 123u);
        view.Write(20, held.Buttons);
        view.Write(22, held.LT);
        view.Write(23, held.RT);
        view.Write(24, held.LX);
        view.Write(26, held.LY);
        Environment.SetEnvironmentVariable("REO_LAUNCHER_PAD_MAP", name);
        nint library = NativeLibrary.Load(Path.Combine(AppContext.BaseDirectory, "XINPUT1_4.dll"));
        nint function = GetProcAddress(library, 2);
        Check(function != 0 && function == NativeLibrary.GetExport(library, "XInputGetState"),
              "Game import ordinal2 matches named export");
        var get = Marshal.GetDelegateForFunctionPointer<GetState>(function);
        Check(get(0, out var result) == 0 && result.Packet == 123 &&
                  result.Buttons == held.Buttons && result.LX == held.LX && result.LY == held.LY,
              "C# shared memory -> native XInput ABI");
        view.Write(12, unchecked((uint)Environment.TickCount - 1000));
        Check(get(0, out var stale) == 0 && stale.Buttons == 0 && stale.LX == 0,
              "Stale producer releases held controls");
        view.Write(12, unchecked((uint)Environment.TickCount));
        Check(get(0, out var resumed) == 0 && resumed.Buttons == held.Buttons,
              "Reconnect resumes without game reinitialization");
        ControllerRumbleTests.RunNative(Check, library, view);
        Directory.CreateDirectory(Path.Combine(AppContext.BaseDirectory, "test-results"));
        File.WriteAllText(Path.Combine(AppContext.BaseDirectory, "test-results", "self-test.json"),
                          JsonSerializer.Serialize(new { passed = true, checks }));
        NativeLibrary.Free(library);
    }
}
