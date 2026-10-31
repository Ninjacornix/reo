using Outbreak.Launcher;
using System.Text.Json;
string root=PlatformPaths.FindRoot(AppContext.BaseDirectory);
string home=Path.Combine(Path.GetTempPath(),"reo-common-tests-"+Guid.NewGuid().ToString("N"));
Storage.Configure(root,home);
int passed=0;var failures=new List<string>();
void Check(bool ok,string message){if(ok)passed++;else failures.Add(message);}
try {
try{GraphicsOptionsTests.Run(Check);}catch(Exception e){failures.Add("GraphicsOptions: "+e);}
try{ModsTests.Run(Check);}catch(Exception e){failures.Add("Mods: "+e);}
try{DiscImportTests.Run(Check);}catch(Exception e){failures.Add("DiscImport: "+e);}
try{MemoryCardBackupTests.Run(Check);}catch(Exception e){failures.Add("MemoryCardBackup: "+e);}
try{GlobalWeaponMotionsTests.Run(Check);}catch(Exception e){failures.Add("GlobalWeaponMotions: "+e);}
try{GamePreviewAssetsTests.Run(Check);}catch(Exception e){failures.Add("GamePreviewAssets: "+e);}
try{GamePreviewAnimationTests.Run(Check);}catch(Exception e){failures.Add("GamePreviewAnimation: "+e);}
try{GamePreviewWeaponTests.Run(Check);}catch(Exception e){failures.Add("GamePreviewWeapon: "+e);}
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
