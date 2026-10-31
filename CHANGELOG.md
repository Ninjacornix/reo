# Changelog

## Unreleased

## v1.0.20-rc1 prerelease - 2026-10-31

- Redesign the launcher settings pages, disc selectors, memory-card profiles, mod configuration and logs. Add a GPU-rendered animated graphics preview and separate launcher appearance settings.
- Add native asset PAK exports and replacements, executable-string edits and PAK game sources for both editions.
- Add File #2 progression unlocks and separate Master, Music, Sound effects, Voice and UI audio channels. Support Windows output-device selection and optional spoken subtitles while preserving interaction prompts.
- Add maximum result points and infinite escape time cheats for both games. Include the File #2 Randomizer in the launcher.
- Integrate scenario runtime, DualSense Bluetooth and build-path fixes. Stop launcher background movies while the game runs and disable game settings before installation.
- Add required source and Windows launcher CI checks and protect develop/main. Fix portable C audio-provider compilation through the pinned clang++ driver.

## v1.0.19 prerelease - 2026-10-24

- Keep compiled VU geometry active when later rooms append independent microcode to the bank. Check every byte covering the optimized blocks and native routines, reject routines outside that coverage, and interpret appended code normally. A captured-bank regression replay improved from 7.48 to 30.00 game updates/sec; full-room and scenario coverage remains limited.

## v1.0.18 prerelease - 2026-10-24

- Add 4× internal scene rendering at 2048×1792, alongside Native and 2×. Preserve distinct samples through scanout and report unsupported GPU sampling modes.
- Offer named Native, HD, FHD, QHD / 2K and 4K window resolutions independently of internal rendering. Preserve existing saved window sizes; fullscreen uses the desktop resolution.
- Prepare the selected resolution's shader pipelines before gameplay, show preparation progress and reuse the persistent pipeline cache. Limit preparation to two workers and finish compiler work before entering the game.
- Request precise Windows timers and opt out of process power throttling during gameplay, restoring the previous policy on shutdown.
- Verify the launcher with 450 assertions and actual Native / 2× / 4× scanout detail. Latest fullscreen 2× testing measured a 33.34 ms median game update and 35.44 ms at the 99th percentile; occasional spikes up to 52.55 ms remain. Full-scenario stability and new multiplayer validation are not claimed.

## v1.0.17 prerelease - 2026-10-24

- Add a saved performance counter toggle in Graphics. Draw display FPS, average frame time and original gameplay updates per second in the top-right corner using the existing final GPU pass.
- Simplify Mods and Cheats text and keep the four main readiness checks on Play.
- Add saved Native / 2× internal resolution independently of the window size. Preserve a 1024×896 scanout for File #1, guard uninitialized startup display registers and retain GPU command checkpoints at 2× as an RX 570 compatibility workaround. Log GPU memory budgets in 2× sessions.
- Roll a fresh 32-bit randomizer seed for every solo/host game launch, show it in the running-game status and record it in session logs. Joining players keep the host's immutable seed; editable item/enemy pools stay unchanged.
- Add saved Master, Music, Sound effects, Voice and UI volume sliders with live game updates and a reset button. Keep cinematic sound that mixes speech and music under Master volume.
- Add game-driven controller rumble through File #1's native libpad2 actuator commands, preserving motor strength and timing.
- Route vibration to the selected DualSense or XInput controller. Combine PS5 rumble with health light colours and stop motors on stale output, disconnect, device changes and shutdown.
- Add a saved **Rumble** on/off switch in Controls that applies immediately during gameplay.
- Hide the cursor over the focused fullscreen game, including Ctrl+Enter changes; restore it in windowed mode, when switching apps and on exit.
- Load missing weapon motions from the imported disc when randomizing pickups, fixing the grenade launcher's broken ready pose and shots that consumed ammunition without completing. Preserve room animations and native motion-table limits.

## v1.0.16 prerelease - 2026-10-23

- Add an offline **Unlock everything** cheat for all five File #1 scenarios, difficulties, costumes, NPC characters and purchased collection extras. Preserve reward points, options, inventory and completion records; require an updated native build.
- Fix infinite ammunition for ordinary and randomized guns, including the rocket launcher, while excluding ammunition boxes, healing, keys and melee items. Verify health/infection restoration and repeated firing in offline gameplay.
- Build the complete enemy replacement plan from the host's synchronized seed before actors load. Apply room-family limits in spawn-ID order so client loading order and room visits cannot reroll enemies; require version 3 session support on every peer.
- Load randomized floor models from the imported scenario banks. Keep model geometry paired with its hierarchy and omit unused materials to prevent invisible pickups and corrupted character or room textures.
- Use native free-flight behavior for replacement crows and wasps, activate G embryos, preserve foreign-room Neptune height, and register the original G/Thanatos grab-reaction continuations.
- Draw weapons, ammunition and common items from separate seeded global pools across all five File #1 scenarios. Keep keys, Daylight, the lighter, owned items and starting equipment fixed.
- Expand the editable enemy pool to 56 profiles across 19 native families, with per-room animation-family reservations. Full-scenario and boss compatibility remain experimental.
- Show local player health on DualSense light bars: green above half HP, yellow at 25–50%, red below 25%, and blue outside gameplay.
- Route controller input through the launcher adapter for both LLVM/MinGW and MSVC game builds.
- Keep game cards dark while selection is disabled and show the active game as running.
- Keep scripted enemy spawns in their original family after entrances finish, preserving later scenario state commands. Shuffle their zombie models and health before construction; ordinary sources retain seeded species choices.
- Fix scripted enemies receiving different maximum health when network reconstruction clears their entrance behavior on only one client. Preserve their original scripted identity throughout the scenario. Two-client first-room retesting found matching maximum health and eventual damage agreement; delayed combat updates, later rooms and mixed-species combat remain experimental.

## v1.0.15 prerelease - 2026-10-22

- Add one **Randomizer** mod for ordinary items, guns, ammunition and supported enemy spawns.
- Consolidate legacy sample selections and preserve their seeds and pools; remove Practice Mode.
- Add editable mod imports and host-published randomizer settings adopted automatically by joining players.
- Preserve original enemy entrances before species handoff and retain choices across rooms.
- Add an optional native enemy asset bank and matching CPU, disc and DMA memory support.
- Restore plain generated game code for ordinary gameplay; make per-instruction source auditing an explicit developer option.
- Skip unused instruction and memory-write witnesses during ordinary CPU gameplay; preserve enabled source audits and stopped-owner checks.
- Verify that scenario keys and personal equipment retain their complete original pickup records across randomizer seeds.
- Ship updated build inputs; existing installations rebuild the game after updating.
- Randomizer remains experimental: full scenario completion, save/resume and mixed-enemy co-op gameplay are unverified.

## v1.0.10 prerelease

- Select games by clicking their cards or with the keyboard; remove Select buttons.
- Import a compatible completed launcher build with its receipt and companion files to skip compilation.
- Validate build-kit/game/architecture identity, file integrity and PE format before cache admission; preserve previous builds on failure/cancellation.
- Document measured compilation samples and future optimization candidates; keep existing game optimization flags and cache identities.


## v1.0.9 prerelease

- Detect compatible LLVM/MinGW installations on PATH and in common folders before downloading.
- Keep import/download/build progress visible across launcher pages, with MiB/counts and cancellation.
- Show progress for hosting-tool downloads and live activity during Python/package preparation.
- Select up to four compile workers from CPU and available memory; preserve existing game/object caches.


## v1.0.8 prerelease — 2026-10-20

- Make compiler setup automatic during ISO import: download the pinned official
  LLVM/MinGW archive, verify SHA-256, and prepare only Windows x64 components in
  Local AppData. No manual extraction, PATH change or environment variable is needed.
- Add download/preparation progress, cancellation, cached verification and reuse;
  pass the resolved compiler directly to build steps without changing user settings.
- Simplify player instructions to opening the launcher and choosing a supported
  ISO. First compilation still takes time; completed game-build cache is preserved.

## v1.0.7 prerelease — 2026-10-20

- Identify the ISO's actual BOOT2 target and known Outbreak game/region serials
  before extraction; distinguish unsupported regions, File #2, unknown games,
  missing boot files and unsupported/modified executable revisions.
- Keep executable SHA-256 as the authoritative revision check. ISO filenames and
  SYSTEM.CNF VER metadata cannot bypass compatibility checks.
- Show the required NTSC-U v2.00 edition and validation result beside the ISO controls.
- Add isolated synthetic-disc checks and a read-only --check-iso diagnostic.

## v1.0.6 prerelease — 2026-10-20

- Automatically prepare Python and the listed server packages on first hosting;
  cache the private environment in Local AppData and reuse it on later starts.
- Add setup progress, cancellation and retry; verify the downloaded setup tool
  against pinned SHA-256 hashes and keep installations outside the application folder.
- Keep server source-only packaging and consolidated notices. Remove the duplicate
  project-source TAR asset; use GitHub's source archives for the release tag.

## v1.0.5 prerelease — 2026-10-20

- Ship server source and requirements.txt without Python, installed pip packages,
  wheels or dependency source archives in the application download.
- Detect an external server Python environment in Local AppData or via
  REO_SERVER_PYTHON; check version/imports before starting hosting services.
- Consolidate the top-level licence folder into THIRD-PARTY-NOTICES.txt and offer
  project/dependency source archives separately from the normal download.
- Retain compressed build inputs needed for local ISO recompilation and the
  single-file startup fix. Document hosting setup and the build-input ZIP.

## v1.0.4 prerelease — 2026-10-20

- Fix startup of the published single-file launcher: load the window icon as an
  embedded WPF resource rather than registering it as external WPF content too.
- Keep the separate icon for the game window without WPF content-file metadata.
- Show the underlying startup error and log location instead of a generic XAML error.
- Add an extracted-package startup check that renders the Graphics page from a
  different working directory, without starting a game or server.
- Withdraw v1.0.3; retain the bundled server and external compiler/.NET requirements.

## v1.0.3 prerelease — 2026-10-20

- Include the local co-op server and its required Python runtime in the main download.
- Write ZIP entries as relative paths with standard `/` separators and place the
  launcher at the archive root, without an enclosing package-name folder.
- Keep .NET and the compiler external; no separate server download is needed.
- Withdraw v1.0.2 and require the bundled server files during update validation.

## v1.0.2 prerelease — 2026-10-20

- Move local-build verification and cached-output hashing off the launcher UI
  thread so setup does not block rendering or cancellation.
- Document end-user dependencies for a smaller package without automatic
  dependency downloads.
- Publish a framework-dependent single-file launcher, compressed first-run
  inputs, and separate optional hosting/dependency-source assets.
- Add elapsed time and approximate stage ETAs; use sequential ISO reads and
  buffered writes without a forced disk flush after every extracted file.
- Withdraw the oversized v1.0.1 download while replacement packaging is prepared.

## v1.0.1 prerelease — 2026-10-20

- Prepare v1.0.1 metadata and GitHub prerelease update discovery, preserving
  the stable update channel for stable installations.
- Align portable packaging/setup instructions, add a release notes template,
  and preserve existing dependency files during setup.
- Portable first-run build tooling generates game code from the user's ISO.
  All 2,381 units compiled and linked; the package is a build-only preview
  without a repeated packaged setup/gameplay run.
- Launcher-managed local server hosting, account creation and automatic native
  login, with user-scoped credential storage.
- GPU movie decoding enabled for normal launches and co-op playtests.
- Faster isolated login/lobby/scenario drivers; two clients reached the first
  room in the latest local retest. Further network behavior remains experimental.
- Original application icons and immutable per-runtime launcher caches.
- Native Linux launcher and Vulkan portability foundations, not a playable
  Linux release.

## v1.0.0 prerelease — 2026-10-19

Withdrawn: the former downloadable game executable contained game-derived code.
The following describes the historical package, not a currently available download.

- Downloadable Windows x64 package; official cover art and current launcher screenshots.
- Main README includes first-run ISO and co-op joining/hosting instructions.
- One-time ISO import without mounting and self-contained Windows packaging.
- Fullscreen switching, aspect/fit modes, texture and anisotropic filtering,
  FXAA/SMAA, brightness/gamma preview and direct logo skipping to PRESS START.
- Folder-backed PS2 memory-card selection, built-in cheats and compatible PCSX2
  data-cheat imports.
- GitHub release checks and verified package updates with rollback.
- Launcher Co-op server and username settings, native SN/ACCESS transport and
  original account authentication through a separate openSNAP server.
- Four-client local room, scenario and movement verification; original SDK
  clocks now advance using monotonic host time in native online mode.
- A separately licensed openSNAP patch for File #1 current-room roster queries.
- Bounded login/lobby automation and read-only actor snapshots for playtesting.

Room creation remains in-game. Launcher hosting/room management, item sharing,
door transitions, reconnects and LAN/WAN behavior are not validated release
features. File #2 and mods remain placeholders. The full native source build
still needs local game-code generation and matching graphics dependencies.

## v0.1 — 2026-10-19

Developer preview of the launcher and public-source layout.

- Standalone Windows launcher with game selection, settings, input remapping, save backups and logs.
- Original GPLv3 background artwork; no bundled game covers or custom app icons.
- Console-free game launch, smoother submenu transitions and separate game configurations.
- GPLv3 licensing with upstream/dependency notices, contribution guidance and formatting rules.
- Generated game code, private notes and captures excluded from the current source tree.

Gameplay and GPU integration remain experimental. File #2, online co-op, mods, cheats, intro skipping and automatic update installation are not validated release features. Ongoing local gameplay/runtime work is separate from this cleanup commit. Historical commits still require review before publishing a formerly private repository.
