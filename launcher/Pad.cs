namespace Outbreak.Launcher;

public record Pad(ushort Buttons = 0, byte LT = 0, byte RT = 0, short LX = 0, short LY = 0,
                  short RX = 0, short RY = 0);
