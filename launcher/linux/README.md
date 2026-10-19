# Linux portable launcher

This is an implementation in progress, not a playable Linux release. It does not
run the Windows game through Wine and never installs a system compiler. The
Windows launcher remains WPF; this frontend uses Qt Widgets and the same supported
disc revision, source-generation metadata and runtime options.

Implemented:

- Mount-free ISO9660 import with executable revision verification, extraction
  bounds, safe names, cancellation and hashed import receipts.
- Linux-native compiler/archive/link worker with resumable object receipts and
  explicit Linux flags and dependency archives. Windows plans are rejected.
- Portable-kit verification, native ELF checks, first-run build admission, owned
  process cancellation, separate persistent memory cards and game logs.
- Play, graphics, saves and log screens; resolution, aspect, filtering, AA,
  brightness, gamma and intro-skip settings.
- AppImage packaging with an explicit non-playable launcher-preview mode.
- Linux CI for synthetic native compilation/linking, cache IO and offscreen UI.

Still required before a playable release:

- Build and audit the actual native Linux runtime/dependency kit, including its
  portable Clang/sysroot/Python and corresponding source/licence material.
- Replace the Windows DXGI presentation and GPU movie-decoding integrations.
- Finish controller/remapping, fullscreen, online, cheats, update and memory-card
  selection parity with Windows. These are not advertised as working Linux controls.
- Run the same ISO-to-room route on Linux hardware, compare rendering/audio/timing
  with Windows, and verify controllers, save/load, movie transitions and cached launch.

## Development

On Linux, create a development virtual environment and install
`requirements-build.txt`, then run `python launcher/linux/main.py`. A source
checkout without `launcher/build-kit/build-kit.json` opens as a preview with Play
disabled. The user-facing AppImage bundles its GUI/Python; users must not be asked
to install a virtual environment or compiler.

Run shared tests with `python -m unittest discover -s tools/local_build -p 'test_*.py'`
and UI tests with `python -m unittest discover -s launcher/linux -p 'test_ui.py'`.
The native compile/link test requires Linux Clang and llvm-ar; it is skipped on
Windows. CI uses synthetic sources, never a commercial ISO.

`build_appimage.py --output NEW_DIRECTORY --appimagetool PATH --launcher-only`
creates a non-playable development preview on Linux. Release mode instead requires
`--kit` and `--validation`; it refuses packaging without exact-kit proof of local
compilation, room gameplay, GPU presentation/movies, audio, save/load, controllers
and Windows parity. No passing report has been produced yet.

The Linux kit uses manifest format 1, `architecture: linux-x64`,
`toolchain: portable-clang`, the same ELF SHA-256 as Windows, and a versioned
`runtimeAbi`. Its inventory must cover every compiler/runtime input and native
`tools/ps2_recomp`, `tools/python/bin/python3` and `compile-plan-linux.json`.
The plan names its bundled `compiler` and `archiver` beneath `{kit}`. It otherwise
uses the existing local plan's units/source groups, authored source replacements,
independent library hashes, output copies and explicit compile/link flags. Do not
translate `.lib` names to `.a` or reuse Windows objects.

Run `tools/local_build/seal_linux.py --kit PATH` only after auditing that native
kit. Linux CRT startup objects belong under the audited `toolchain/` inventory;
game objects never do. Compiler/Python source and licence material belongs in the
independent SDK source archive too.

Persistent data follows XDG locations under `OutbreakRecomp`. It is kept outside
the read-only AppImage; replacing the AppImage must not replace saves or imports.

Packaging references: [AppImage AppDir format](https://docs.appimage.org/packaging-guide/manual.html)
and [Qt/PyInstaller deployment](https://doc.qt.io/qtforpython-6/deployment/deployment-pyinstaller.html).
