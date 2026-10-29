# DualSense discovery and Bluetooth input: issue #28

Implemented on `fix/issue-28-dualsense-bluetooth`, based on the published
`v1.0.20-rc0` commit `9e0048b`, separately from the PAK and issue #27 branches.

## Evidence and changes

[Issue #28](https://github.com/Ninjacornix/reo/issues/28) reports a missing DualSense
while only keyboard and a disconnected saved Xbox device are available. Its image
shows rc0's Controls page, the saved-disconnected choice and Xbox binding labels.
The screenshot cannot establish the connection method or whether another program
is hiding the physical HID device. The user also reports Bluetooth not working.

Three concrete code problems are corrected:

1. rc0 discovers a DualSense only after an accepted input report and hides it
   after two seconds without another report. `RawInputPads` now enumerates Windows
   Raw Input devices at startup and every 500 ms. Device arrival/removal messages
   also update presence. A quiet connected controller remains selectable; a
   removed controller releases its controls. Enumeration failures retain the last
   successful presence snapshot, and present handles survive transient metadata
   query failures.
2. The old filter requires USB-style `VID_054C` and `PID_0CE6`/`PID_0DF2` text in
   the path. Discovery now uses numeric vendor/product IDs and joystick/gamepad
   usage from `RIDI_DEVICE_INFO_HID`, independent of path spelling. Bluetooth path
   hints affect the display/output transport only; accepted reports establish the
   transport when no hint is available. LEDs/rumble wait for a known transport.
3. Basic Bluetooth report ID `0x01` can be 10 bytes or padded to 78 bytes. rc0
   treated the padded form as an enhanced packet and read the wrong button and
   trigger offsets. Both basic lengths now share the compact layout. USB `0x01`
   remains 64 bytes; enhanced Bluetooth `0x31` remains 78 bytes. Unexpected sizes
   are rejected. Changing report format also refreshes the device picker's label.

Saved device choices are preserved. A disconnected saved Xbox controller does
not suppress discovery of a DualSense; the user selects the DualSense once in
Controls. A reconnect starts neutral and resumes input without restarting the game.
No native game rebuild or additional driver is required for these launcher changes.
Windows must expose the controller to the launcher; this cannot bypass software
that intentionally hides a physical HID device.

Primary references:

- [Microsoft GetRawInputDeviceList](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getrawinputdevicelist)
- [Microsoft RID_DEVICE_INFO_HID](https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-rid_device_info_hid)
- [SDL's PS5 packet definitions and report dispatch](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_ps5.c)

## Validation

- Self-contained Windows x64 launcher publishes successfully and passes **731**
  self-test checks with system-only PATH and nonexistent .NET lookup roots.
  The compressed single-file test launcher also passes all 731 checks under those
  conditions (72,070,449 bytes). It is a local test artifact, not a published release.
- New regressions cover both Sony product IDs, wrong vendors/usages, discovery
  before input, ten seconds without reports, a saved disconnected Xbox choice,
  transient enumeration/metadata failures, removal and reconnect with a new handle.
- Fabricated USB, 10-byte basic Bluetooth, 78-byte padded basic Bluetooth and
  enhanced Bluetooth reports pass through the production controller mapper and
  actual native XInput adapter. Buttons, triggers and axes reach the native feed;
  removal clears all controls and reconnect resumes input. Every truncated
  enhanced Bluetooth length is rejected. These are simulated packet/lifecycle
  checks, not physical Bluetooth validation.
- A **real USB DualSense** is present on the test machine. A windowless discovery
  check lists it immediately and after 10.024 seconds with **zero input reports**.
  This directly verifies that presence no longer depends on recent input.
- A real WPF probe receives 1,034 USB reports in approximately four seconds,
  selects `DualSense (USB)` and exposes connected input through the native adapter.
- A WPF UI Automation check starts with saved `xbox:3`, opens the actual picker,
  finds DualSense, keyboard and the saved disconnected entry, selects the DualSense
  and verifies the saved physical selection. This uses an isolated settings folder.
  A new launcher process restores that selection and detects the physical USB pad.
- After the user connects the same controller over **real Bluetooth**, Windows
  exposes its Bluetooth HID interface and the patched single-file launcher selects
  `DualSense (Bluetooth)`. The initial probe receives 2,892 reports and the native
  XInput adapter reports connected status.
- A 45.031-second live WPF/Raw Input test receives **31,483 Bluetooth reports**.
  User-operated Cross/Circle/Triangle, D-pad in all four directions and both
  shoulder buttons are observed (`buttonsSeen=B30F`). Both triggers reach 255 and
  all four stick axes exceed 30,000 in magnitude. Every sampled normalized input
  matches the production native XInput adapter, with **zero mismatches and zero
  unavailable-device samples**. All buttons, triggers and axes finish at zero.
  Receipts are `physical-bt-probe-first.json` and `physical-bt-live.json`.

Private build, hardware receipts and UI checks remain under the worktree's ignored
`build-ninja/` directory. Original game data and personal launcher settings are
unchanged. Physical USB and Bluetooth discovery/input are now verified. Bluetooth
used the user's existing pairing; a physical power-cycle/reconnect, rumble/light
output correctness and a full game session were not tested in this Bluetooth run.
Reconnect behavior retains the simulated/native-adapter coverage above. Universal
controller compatibility is not claimed.
