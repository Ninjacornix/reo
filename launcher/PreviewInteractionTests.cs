using System.Windows;
using System.Windows.Controls;
using System.Runtime.InteropServices;

namespace Outbreak.Launcher;

internal static class PreviewInteractionTests {
    internal static void Run(Action<bool, string> check) {
        check(Marshal.SizeOf<GpuPreviewOptions>() == 80 && Marshal.SizeOf<GpuPreviewStats>() == 40,
            "The managed GPU option and statistic layouts match their native ABI");
        var rotation = new PreviewRotation();
        check(!rotation.Move(new(90, 40)) && rotation.Yaw == 0 && rotation.Pitch == 0,
            "Kevin's preview stays still without a drag");
        rotation.Begin(new(10, 10)); rotation.Move(new(110, 30));
        check(Math.Abs(rotation.Yaw - 60) < .001 && rotation.Pitch == 0,
            "Dragging rotates Kevin around the vertical axis while keeping him upright");
        check(!rotation.Move(new(110, 130)) && rotation.Pitch == 0 && Math.Abs(rotation.Yaw - 60) < .001,
            "Vertical dragging does not tilt Kevin");
        rotation.End(); float yaw = rotation.Yaw, pitch = rotation.Pitch;
        check(!rotation.Move(new(400, 300)) && rotation.Yaw == yaw && rotation.Pitch == pitch,
            "Releasing Kevin's preview stops rotation without velocity or drift");
        rotation.Begin(new(0, 0)); rotation.Move(new(10000, -10000));
        check(Math.Abs(rotation.Yaw) < 360 && rotation.Pitch == 0, "Kevin stays upright through large drags");
        rotation.Scroll(120); check(rotation.Zoom > 1, "Scrolling up zooms Kevin in");
        rotation.Scroll(-120); check(Math.Abs(rotation.Zoom - 1) < .001, "Scrolling down reverses zoom");
        rotation.Scroll(12000); check(rotation.Zoom == 2.5, "Kevin's zoom has a maximum inspection distance");
        rotation.Scroll(-12000); check(rotation.Zoom == .65f, "Kevin's zoom has a minimum inspection distance");
        rotation.Reset(); check(!rotation.Dragging && rotation.Yaw == 0 && rotation.Pitch == 0,
            "Reset restores Kevin's default inspection angle");
        check(rotation.Zoom == 1, "Reset restores Kevin's default zoom");
        check(!ToolTipService.GetIsEnabled(new Button { ToolTip = "Hover help" }) &&
              !ToolTipService.GetIsEnabled(new TextBox { ToolTip = "Hover help" }) &&
              !ToolTipService.GetIsEnabled(new MenuItem { ToolTip = "Hover help" }),
            "Launcher buttons, text fields and menu items suppress hover tooltips globally");
    }
}
