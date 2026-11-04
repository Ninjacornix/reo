using System.Runtime.InteropServices;
namespace Outbreak.Launcher;

// The Win32 service is independent of WPF and can attach to Avalonia's HWND.
internal sealed class NativeWindowMessages {
    internal delegate nint Hook(nint window,int message,nint wp,nint lp,ref bool handled);
    delegate nint Subclass(nint window,uint message,nint wp,nint lp,nuint id,nuint data);
    readonly nint window;
    readonly Subclass callback;
    Hook? hook;
    NativeWindowMessages(nint window) {this.window=window;callback=Dispatch;}
    internal static NativeWindowMessages FromHwnd(nint window)=>new(window);
    internal void AddHook(Hook value) {
        hook=value;
        if(!SetWindowSubclass(window,callback,0x52454f,0))throw new System.ComponentModel.Win32Exception();
    }
    internal void RemoveHook(Hook value) {RemoveWindowSubclass(window,callback,0x52454f);hook=null;}
    nint Dispatch(nint window,uint message,nint wp,nint lp,nuint id,nuint data) {
        bool handled=false;var result=hook?.Invoke(window,(int)message,wp,lp,ref handled)??0;
        return handled?result:DefSubclassProc(window,message,wp,lp);
    }
    [DllImport("comctl32")]static extern bool SetWindowSubclass(nint window,Subclass callback,nuint id,nuint data);
    [DllImport("comctl32")]static extern bool RemoveWindowSubclass(nint window,Subclass callback,nuint id);
    [DllImport("comctl32")]static extern nint DefSubclassProc(nint window,uint message,nint wp,nint lp);
}
