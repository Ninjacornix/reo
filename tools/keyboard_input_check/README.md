# Keyboard input regression check

Run with .NET 8 or newer:

```sh
dotnet run --project tools/keyboard_input_check
```

This console checker compiles the production `Pad` and `InputMapping` code directly.
It requires no WPF, display, controller, ISO or native adapter. It covers digital
D-pad input with neutral analog sticks, independent right-stick voice commands,
opposing directions, arrow-key reassignment, clearing, saved bindings, the
reserved fullscreen chord and rejected invalid captures.

The same checks run in the Windows launcher self-test. `ControllerInputTests`
additionally checks keyboard output through the real native XInput adapter on
Windows. The owned-disc `--test-controls-ui` diagnostics exercise the right-stick
buttons, persisted remapping/clearing, conflict removal, missing-artwork fallback
and switching to a physical-controller profile.

`InputMapping.Windows.cs` holds only WPF key-name formatting; mapper behavior
lives in the portable file. The launcher still targets Windows/.NET 8.
