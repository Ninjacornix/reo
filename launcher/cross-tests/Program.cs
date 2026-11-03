using Outbreak.Launcher;
using System.Text.Json;
// A UI-free restart/parent fixture for the real Windows updater process check.
if (args.Length == 2 && args[0] == "--update-parent-check") {
    using var timeout = new CancellationTokenSource(TimeSpan.FromSeconds(90));
    while (!File.Exists(args[1])) await Task.Delay(50, timeout.Token);
    return 0;
}
if ((args.Length == 2 || args.Length == 4 && args[2] == "--data-home") &&
    args[0] is "--update-complete" or "--update-failed") {
    string receipt = File.ReadAllText(args[1]);
    using var result = JsonDocument.Parse(receipt);
    string storage = args.Length == 4 ? args[3] :
        Storage.Resolve(result.RootElement.GetProperty("target").GetString()!);
    string restarted = Path.Combine(Environment.CurrentDirectory, "restart-check.json");
    File.WriteAllText(restarted + ".tmp",
                      JsonSerializer.Serialize(new { arguments = args, receipt, storage }));
    File.Move(restarted + ".tmp", restarted);
    return 0;
}
string root=PlatformPaths.FindRoot(AppContext.BaseDirectory);
string home=Path.Combine(Path.GetTempPath(),"reo-common-tests-"+Guid.NewGuid().ToString("N"));
Storage.Configure(root,home);
int passed=0;var failures=new List<string>();
void Check(bool ok,string message){if(ok)passed++;else failures.Add(message);}
try {
try{PlatformPathsTests.Run(Check);}catch(Exception e){failures.Add("PlatformPaths: "+e);}
if(args.Contains("--windows-services-check"))try{await WindowsServiceChecks.Run(Check);}catch(Exception e){failures.Add("WindowsServices: "+e);}
try{await PlatformServicesTests.Run(Check);}catch(Exception e){failures.Add("PlatformServices: "+e);}
if(OperatingSystem.IsWindows())try{UpdateTests.Run(Check);}catch(Exception e){failures.Add("Updates: "+e);}
try{KeyboardInputTests.Run(Check);}catch(Exception e){failures.Add("KeyboardInput: "+e);}
try{await OnlineUnlockTests.Run(Check);}catch(Exception e){failures.Add("OnlineUnlocks: "+e);}
try{GraphicsOptionsTests.Run(Check);}catch(Exception e){failures.Add("GraphicsOptions: "+e);}
try{ModsTests.Run(Check);}catch(Exception e){failures.Add("Mods: "+e);}
try{DiscImportTests.Run(Check);}catch(Exception e){failures.Add("DiscImport: "+e);}
try{MemoryCardBackupTests.Run(Check);}catch(Exception e){failures.Add("MemoryCardBackup: "+e);}
try{GlobalWeaponMotionsTests.Run(Check);}catch(Exception e){failures.Add("GlobalWeaponMotions: "+e);}
try{GamePreviewAssetsTests.Run(Check);}catch(Exception e){failures.Add("GamePreviewAssets: "+e);}
try{GamePreviewAnimationTests.Run(Check);}catch(Exception e){failures.Add("GamePreviewAnimation: "+e);}
try{GamePreviewWeaponTests.Run(Check);}catch(Exception e){failures.Add("GamePreviewWeapon: "+e);}
try{PreviewConcurrencyTests.Run(Check);}catch(Exception e){failures.Add("PreviewConcurrency: "+e);}
try{await HostingReadinessTests.Run(Check);}catch(Exception e){failures.Add("HostingReadiness: "+e);}
try{RandomizerSeedsTests.Run(Check);}catch(Exception e){failures.Add("RandomizerSeeds: "+e);}
try{ExecutableStringTests.Run(Check);}catch(Exception e){failures.Add("ExecutableString: "+e);}
try{ElfStringReferenceTests.Run(Check);}catch(Exception e){failures.Add("ElfStringReference: "+e);}
try{OnlineOptionsTests.Run(Check);}catch(Exception e){failures.Add("OnlineOptions: "+e);}
try{LobbyRoomSettingsTests.Run(Check);}catch(Exception e){failures.Add("LobbyRoomSettings: "+e);}
try{AssetPakTests.Run(Check);}catch(Exception e){failures.Add("AssetPak: "+e);}
try{GamePakTests.Run(Check);}catch(Exception e){failures.Add("GamePak: "+e);}
try{await BackgroundVideoTests.Run(Check);}catch(Exception e){failures.Add("BackgroundVideo: "+e);}
try{await RandomizerSessionTests.Run(Check);}catch(Exception e){failures.Add("RandomizerSession: "+e);}
Console.WriteLine(JsonSerializer.Serialize(new{passed,failures},new JsonSerializerOptions{WriteIndented=true}));
return failures.Count==0?0:1;
} finally {Storage.Close();if(Directory.Exists(home))Directory.Delete(home,true);}
