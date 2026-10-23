using System.Buffers.Binary;

namespace Outbreak.Launcher;

internal static class ControllerLightTests {
    public static void Run(Action<bool, string> check) {
        PadLight Health(int hp, int max = 1000) => ControllerHealth.Color(new(2, 0, true, hp, max));
        check(Health(1000) == PadLight.Green && Health(501) == PadLight.Green &&
              Health(500) == PadLight.Yellow && Health(250) == PadLight.Yellow &&
              Health(249) == PadLight.Red && Health(0) == PadLight.Red,
              "Health colour includes exact half/quarter boundaries and zero HP");
        check(Health(751, 1500) == PadLight.Green && Health(750, 1500) == PadLight.Yellow &&
              Health(374, 1500) == PadLight.Red,
              "Health light scales to each character's maximum HP");
        check(Health(-1) == PadLight.Blue && Health(1001) == PadLight.Blue &&
              Health(0, 0) == PadLight.Blue && Health(1, 32767) == PadLight.Blue &&
              ControllerHealth.Color(new(0, 0, true, 100, 1000)) == PadLight.Blue &&
              ControllerHealth.Color(new(2, 4, true, 100, 1000)) == PadLight.Blue &&
              ControllerHealth.Color(new(2, 0, false, 100, 1000)) == PadLight.Blue,
              "Menus, missing actors and invalid health fall back to blue");
        var usb = DualSenseLight.Report(false, new(17, 34, 51));
        var expected = new byte[48];
        expected[0] = 2; expected[2] = 4; expected[45] = 17; expected[46] = 34; expected[47] = 51;
        check(usb.SequenceEqual(expected),
              "USB LED report changes only colour-enable and RGB, leaving haptics/audio untouched");
        var reset = DualSenseLight.Report(false, PadLight.Blue, reset: true);
        check(reset.Length == 48 && reset[0] == 2 && reset[2] == 8 &&
              reset.Where((_, i) => i != 0 && i != 2).All(b => b == 0),
              "LED reset does not request rumble, trigger or microphone changes");
        var bt = DualSenseLight.Report(true, new(17, 34, 51));
        check(bt.Length == 78 && bt[0] == 0x31 && bt[1] == 2 && bt[3] == 4 &&
              bt[46] == 17 && bt[47] == 34 && bt[48] == 51 &&
              BinaryPrimitives.ReadUInt32LittleEndian(bt.AsSpan(74)) == 0x85299cd0u,
              "Bluetooth LED output has its own framing and independently checked CRC32");
    }
}
