using System.Windows.Input;

namespace Outbreak.Launcher;

public static partial class InputMapping {
    public static string SourceName(int code, string kind) {
        if (code == 0)
            return "Unbound";
        if (kind == "keyboard" && code >= '0' && code <= '9')
            return ((char)code).ToString();
        if (kind == "keyboard")
            return code switch {
                32 => "Space",
                13 => "Enter",
                8 => "Backspace",
                27 => "Esc",
                37 => "Left arrow",
                38 => "Up arrow",
                39 => "Right arrow",
                40 => "Down arrow",
                _ => KeyInterop.KeyFromVirtualKey(code).ToString()
            };
        return code switch {
            0x1000 => kind == "xbox" ? "A" : "Cross",
            0x2000 => kind == "xbox" ? "B" : "Circle",
            0x4000 => kind == "xbox" ? "X" : "Square",
            0x8000 => kind == "xbox" ? "Y" : "Triangle",
            0x100 => kind == "xbox" ? "LB" : "L1",
            0x200 => kind == "xbox" ? "RB" : "R1",
            LeftTrigger => kind == "xbox" ? "LT" : "L2",
            RightTrigger => kind == "xbox" ? "RT" : "R2",
            0x10 => kind == "xbox" ? "Menu" : "Options",
            0x20 => kind == "xbox" ? "View" : "Create",
            _ => Actions.FirstOrDefault(a => a.Code == code).Label ?? "Unknown"
        };
    }
}
