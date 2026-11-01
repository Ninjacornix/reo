using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text.Json;

namespace Outbreak.Launcher;

internal static class PlatformRuntime {
    static readonly string[] Ps2={"Select","L3","R3","Start","Up","Right","Down","Left","L2","R2","L1","R1","Triangle","Circle","Cross","Square"};
    static readonly Dictionary<int,int> MacKeys=new() {
        [0]=256,['A']=0,['S']=1,['D']=2,['F']=3,['H']=4,['G']=5,['Z']=6,['X']=7,['C']=8,['V']=9,['B']=11,
        ['Q']=12,['W']=13,['E']=14,['R']=15,['Y']=16,['T']=17,['1']=18,['2']=19,['3']=20,['4']=21,
        ['6']=22,['5']=23,['9']=25,['7']=26,['8']=28,['0']=29,['O']=31,['U']=32,['I']=34,['P']=35,
        [13]=36,['L']=37,['J']=38,['K']=40,['N']=45,['M']=46,[9]=48,[32]=49,[8]=51,[27]=53,
        [37]=123,[39]=124,[40]=125,[38]=126,[112]=122,[113]=120,[114]=99,[115]=118,[116]=96,[117]=97,
        [118]=98,[119]=100,[120]=101,[121]=109,[122]=103,[123]=111,
        [186]=41,[187]=24,[188]=43,[189]=27,[190]=47,[191]=44,[192]=50,[219]=33,[220]=42,[221]=30,[222]=39
    };
    internal static int MacKey(int virtualKey)=>MacKeys.TryGetValue(virtualKey,out var key)?key:
        throw new IOException($"Key {virtualKey} has no macOS hardware mapping. Choose another key in Controls.");
    [DllImport("/System/Library/Frameworks/CoreGraphics.framework/CoreGraphics")]static extern int CGGetOnlineDisplayList(uint capacity,[Out]uint[]? displays,out uint count);
    [DllImport("/System/Library/Frameworks/CoreGraphics.framework/CoreGraphics")]static extern uint CGDisplayIsAsleep(uint display);
    internal static bool DisplayAvailable() {
        if(!OperatingSystem.IsMacOS())return true;
        if(CGGetOnlineDisplayList(0,null,out uint count)!=0||count==0)return false;
        var displays=new uint[count];if(CGGetOnlineDisplayList(count,displays,out count)!=0)return false;
        return displays.Take((int)count).Any(d=>CGDisplayIsAsleep(d)==0);
    }
    internal static void Configure(ProcessStartInfo start,string root,Settings settings,Controller controller,string logs) {
        start.Environment["REO_FULLSCREEN"]=settings.Fullscreen?"1":"0";
        if(OperatingSystem.IsWindows())return;
        start.Environment["REO_MACOS_LIVE_SETTINGS"]=Path.Combine(logs,"live-settings.txt");
        PublishLive(logs,settings);
        if(!OperatingSystem.IsMacOS())return;
        if(!DisplayAvailable())throw new IOException("No awake display is available. Wake the display and launch the game again.");
        var record=PlatformPaths.NativeRecord(root);
        string driver=record?.GetValueOrDefault("driver") ?? new[]{Path.Combine(AppContext.BaseDirectory,"native","libMoltenVK.dylib"),"/opt/homebrew/lib/libMoltenVK.dylib","/usr/local/lib/libMoltenVK.dylib"}.FirstOrDefault(File.Exists)
            ?? throw new IOException("The bundled MoltenVK driver is missing.");
        start.Environment["GRANITE_VULKAN_LIBRARY"]=driver;
        start.Environment["REO_PARALLEL_GS_DESCRIPTOR_BUFFER"]="0";
        start.Environment["REO_MACOS_KEYS"]=string.Join(',',Ps2.Select(name=>MacKey(settings.Keyboard[name])));
        start.Environment["REO_MACOS_CAMERA_KEYS"]=string.Join(',',InputMapping.Camera.Select(a=>MacKey(settings.Keyboard[a.Id])));
        var profile=controller.SelectedDevice.Kind=="playstation"?settings.PlayStation:settings.Xbox;
        start.Environment["REO_MACOS_DEADZONE"]=profile.DeadZone.ToString();
        start.Environment["REO_MACOS_SWAP_STICKS"]=profile.SwapSticks?"1":"0";
        start.Environment["REO_MACOS_INVERT_RIGHT_Y"]=profile.InvertRightY?"1":"0";
        start.Environment["REO_MACOS_RUMBLE"]=settings.RumbleEnabled?"1":"0";
        start.Environment["REO_MACOS_INPUT_DEVICE"]=controller.SelectedDevice.Kind=="keyboard"?"keyboard":controller.SelectedDevice.Id.StartsWith("xbox:")?controller.SelectedDevice.Id[5..]:"auto";
        start.Environment["REO_MACOS_PAD_MAPPING"]=string.Join(',',Ps2.Select(name=>{
            int code=profile.Buttons.GetValueOrDefault(name,InputMapping.PadDefaults()[name]);
            string? source=InputMapping.Actions.FirstOrDefault(a=>a.Code==code).Id;
            int index=Array.IndexOf(Ps2,source);return index<0?16:index;
        }));
    }
    internal static void PublishLive(string logs,Settings settings) {
        string target=Path.Combine(logs,"live-settings.txt"),temporary=target+"."+Guid.NewGuid().ToString("N");
        try { File.WriteAllText(temporary,AudioLevels.From(settings).LaunchValue+"\n"+(settings.ShowSubtitles?"1":"0")+"\n");File.Move(temporary,target,true); }
        finally {if(File.Exists(temporary))File.Delete(temporary);}
    }
    [DllImport("libc",SetLastError=true)]static extern int kill(int pid,int signal);
    internal static async Task Stop(Process process) {
        if(process.HasExited)return;
        if(OperatingSystem.IsWindows())process.CloseMainWindow();
        else if(kill(process.Id,15)!=0)throw new System.ComponentModel.Win32Exception(Marshal.GetLastWin32Error());
        using var deadline=new CancellationTokenSource(TimeSpan.FromSeconds(10));
        try{await process.WaitForExitAsync(deadline.Token);}catch(OperationCanceledException){if(!process.HasExited)process.Kill(true);}
    }
}
