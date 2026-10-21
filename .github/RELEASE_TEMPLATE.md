# RE: Outbreak 1.0 Alpha (v1.0.12) prerelease

<!-- reo:requires-rebuild -->

The first alpha. Its new build files make future updates much faster: after this one
last full build, an update recompiles only the parts of the game that changed. That
means **the game is built once more after updating** (the launcher asks first).

**Important fix:** games built from earlier release downloads could not start: they
stopped during startup with a GPU movie error, and some GPU helper shaders were never
shipped. Both are fixed; the game built by this release starts and plays its movies on
the GPU.

## Easier first setup

- The **Play** page tells you the next step: choose your ISO, build the game, play.
- A **Before you play** checklist marks what is ready and what is missing, with a
  button for each fix (graphics driver page, storage settings, Choose ISO, Controls).
- Choosing an ISO no longer starts the build. The disc is checked first and a green ✓
  enables **Import**. Unsupported discs show the reason.
- **Use existing build** is available to everyone.
- **Remove game** in Game files deletes the imported data, built game and compile
  cache (optionally saves and build tools). Your ISO stays.
- After building, temporary generated sources are deleted automatically; only a
  compile cache (about 1.2 GB) is kept for fast future updates.
- Clearer, higher-contrast controls; File #2 is shown as coming later.

## Simpler co-op

- **Co-op** now offers **Play alone**, **Host a game** and **Join a game**, with a
  player name and no Create account step.
- Hosts get their game opened automatically and a **Copy address** button. Internet
  options (VPN advice, UPnP, port list) are tucked away under **Playing over the
  internet**.
- Joiners see games hosted on their network, or type an address.
- **Take me to the waiting room automatically** (on by default) signs in and brings
  everyone to the host's room after Play. Press any button to take over.
- Player sign-up moved from TCP 80 to **TCP 10128**; it and the game server port can
  be changed under **Ports**. Busy ports are reported with the program using them.
- Hosting reuses an installed Python 3.12 instead of downloading one.

Co-op remains experimental. Two local clients reached the same waiting room through
the new automation; the full path from the Play button and internet play have not
been validated yet.

## First setup

1. Install .NET 8 Desktop Runtime x64 if needed, and keep your Vulkan driver current.
2. Extract RE-Outbreak-v1.0.12-Windows-x64.zip into a new folder and open Outbreak.Launcher.exe.
3. Follow the Play page: choose your own **Outbreak File #1 NTSC-U v2.00 ISO (SLUS-20765)**, then **Build game**.

Keep build-inputs.zip beside the launcher. First compilation still takes substantial
time (over an hour on the test PC) and about 10 GB of free space. PAL, Japanese,
File #2 and unsupported/modified executable revisions are not supported.
