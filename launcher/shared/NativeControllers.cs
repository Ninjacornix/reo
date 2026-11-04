using System.Collections.Concurrent;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal static class NativeControllers {
    [StructLayout(LayoutKind.Sequential)]struct State {
        public ushort Buttons;public byte LT,RT;public short LX,LY,RX,RY;
    }
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]delegate int ReadState(int index,out State state);
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]delegate void SetRumble(int index,ushort left,ushort right);
    static readonly ReadState? read;
    static readonly SetRumble? rumble;
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]delegate int Yield(int pid);
    static readonly Yield? yieldActivation;
    static readonly ConcurrentDictionary<int,bool> keys=new();
    static NativeControllers() {
        string file=OperatingSystem.IsMacOS()?"libReo.Platform.dylib":"libReo.Platform.so";
        foreach(string path in new[]{Path.Combine(AppContext.BaseDirectory,file),Path.Combine(PlatformPaths.FindRoot(AppContext.BaseDirectory),"build-macos","launcher-tools",file)}) {
            if(!NativeLibrary.TryLoad(path,out var library))continue;
            read=Marshal.GetDelegateForFunctionPointer<ReadState>(NativeLibrary.GetExport(library,"reo_controller_read"));
            rumble=Marshal.GetDelegateForFunctionPointer<SetRumble>(NativeLibrary.GetExport(library,"reo_controller_rumble"));
            if(NativeLibrary.TryGetExport(library,"reo_yield_activation",out var yieldExport))
                yieldActivation=Marshal.GetDelegateForFunctionPointer<Yield>(yieldExport);
            break;
        }
    }
    public static Pad? Read(uint index)=>read!=null&&read((int)index,out var value)!=0?new(value.Buttons,value.LT,value.RT,value.LX,value.LY,value.RX,value.RY):null;
    public static void Rumble(uint index,ushort left,ushort right)=>rumble?.Invoke((int)index,left,right);
    public static bool YieldActivation(int pid)=>yieldActivation?.Invoke(pid)!=0&&yieldActivation!=null;
    public static void SetKey(int key,bool down)=>keys[key]=down;
    public static bool KeyDown(int key)=>keys.TryGetValue(key,out bool down)&&down;
    public static void ClearKeys()=>keys.Clear();
}
