# Portable prerelease preparation

**Current status:** the bulky v1.0.1 download is withdrawn. The next package is
being simplified around the [end-user requirements](../REQUIREMENTS.md), with
no automatic dependency downloads. The v1.0.1 packaging details below describe
the previous bundle and must not be reused as the smaller replacement unchanged.

The next version is **v1.0.1**, marked **prerelease** on GitHub. The withdrawn
v1.0.0 package must not be restored or reused. This guide covers the repository
and distribution as a whole; multiplayer is an experimental feature, not a
separate release milestone.

## Public repository

- Keep README, build instructions, changelog, supported game revision and platform
  limits consistent. File #2 remains a placeholder; native Linux is unfinished.
- Preserve GPL-3.0-only project licensing, inherited notices, original asset
  provenance and the dependency patch series. A dirty local dependency is not
  a published dependency update.
- Keep game data, generated instruction code, translated shaders, captures,
  handoffs, saves, credentials and service databases outside tracked sources.
- Use a new commit and version for release preparation. Do not rewrite public
  history, force-push a branch or repoint an existing tag as a cleanup shortcut.

The source-only publication audits are `tools/check_repository.py` and
`tools/publication_audit.py`. They inspect tracked publication inputs; they do
not execute the game or establish ownership rights over repository history.

## Portable Windows artifact

The package contains the self-contained launcher, original application icons,
controller adapter, independent runtime sources, pinned LLVM/MinGW tools and
their matching headers/libraries. Include corresponding dependency sources and
licences. The optional hosting component includes its AGPL source and Python
dependency notices, without an account database or development environment.

The user extracts the archive, opens `Outbreak.Launcher.exe`, and selects their
own **NTSC-U v2.00 / SLUS-20765 ISO** under **Game files**. Generation and
compilation happen locally; subsequent launches reuse the private cache. No
Windows installer, system compiler installation, BIOS or ISO mount is required.
The ISO remains available for direct sector reads. A Vulkan-capable GPU driver
is required.

Do not include a prebuilt game executable, game objects, generated game bodies
or shaders, extracted assets, memory cards, developer caches or captures.

Follow [local build kits](LOCAL_BUILDS.md) to export the independent inputs and
seal their manifest. Normally the packager requires completed build/room-route
records for that exact kit. For v1.0.1, the user requested no further gameplay
runs: `-BuildOnlyPrerelease` admits a completed build with independently verified
input correspondence, records the absent gameplay validation in distribution
metadata and requires the omission to be stated in release notes. Portable
compilation has completed. Do not fabricate a packaged setup or room-route pass.

Package from a committed source revision:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File launcher/package-local.ps1 `
  -Kit '<sealed independent kit>' -Server '<portable server component>' `
  -ValidationReport '<matching kit receipt.json>' `
  -Output 'dist/RE-Outbreak-v1.0.1-Windows-x64' -Version 1.0.1 -Zip `
  -BuildOnlyPrerelease
```

The resulting artifacts are `RE-Outbreak-v1.0.1-Windows-x64.zip` and its
`.zip.sha256` checksum. Keep `distribution.json`, the package inventory and
corresponding-source archives inside the package. This name is recognized by
the updater. Prerelease installations can discover newer prereleases; stable
installations remain on the stable channel. Source-only releases are not
installable launcher updates.

## GitHub publication

Create the release from the intended committed revision using tag `v1.0.1` and
GitHub's prerelease flag. Start with a draft, use the
[release notes template](../.github/RELEASE_TEMPLATE.md), and attach only the
completed platform archive and its checksum. Do not attach private developer
executables or an incomplete Linux build. Publish after the artifact inventory,
source notices and documented setup match the files being uploaded.

Source-only distribution reduces bundled game-content exposure but is not a
guarantee against copyright complaints or takedown requests.
