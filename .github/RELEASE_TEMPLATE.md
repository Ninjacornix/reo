# RE: Outbreak 1.0 RC2 (v1.0.20-rc2) prerelease

Testing release of the universal launcher and updated game runtime inputs.

<!-- reo:requires-rebuild -->

**The game rebuilds after this update.** Keep about 10 GB free for setup. Keep
your ISO, imported data, settings and saves in their existing storage folder.

## Changes

- Use the shared Avalonia/.NET 10 launcher. The Windows release includes its
  runtime; players do not need to install .NET separately.
- Integrate macOS launch focus, native fullscreen, hidden developer panel and
  GPU fallback from unsupported 4x rendering to 2x.
- Update File #2 VU program selection and the speech-tail handling policy.
- Support full RC-tag comparison in the new updater and include the runtime by
  default when packaging Windows releases.
- Add mod-controlled timed examine messages for both games.

## Upgrading from an older release

RC0/RC1's installed updater cannot handle later RC tags correctly. Close the
launcher and game, extract the complete new Windows ZIP into the existing
installation, and replace application files. Preserve `data`, `storage.json`
and any separately selected storage folder. v1.0.19 users should also upgrade
manually because their updater does not recognize the new package layout.

## First setup

1. Keep your Vulkan graphics driver current.
2. Extract `RE-Outbreak-v1.0.20-rc2-Windows-x64.zip` and open
   `Outbreak.Launcher.exe`.
3. Select your own supported NTSC-U ISO: File #1 v2.00 (SLUS-20765) or
   File #2 v1.05 (SLUS-20984). Choose **Build game** and then **Play**.

Keep both build-input ZIPs, native helpers and supplied examples beside the
launcher. PAL, Japanese and modified executable revisions are unsupported.
Game data and precompiled Windows game executables are not included.

## Verification and limits

Before publishing, replace this paragraph with receipts for the exact assembled
RC2 packages: sealed-kit identities, cold builds, cached launches, actual
game/scenario checks and target-machine macOS results. Distinguish launcher CI
and controlled regressions from gameplay verification. Disclose skipped checks,
signing/notarization status and remaining
multiplayer limitations. Do not reuse RC1's gameplay claims for changed inputs.

Publish matching dependency-source archives and SHA-256 checksums. Players need
the application download for their platform, not the dependency sources.
