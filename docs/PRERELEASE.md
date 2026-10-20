# Prerelease packaging

The current target is **v1.0.4**, marked prerelease on GitHub. Earlier binary
downloads are withdrawn. .NET and the compiler remain separately installed
[requirements](../REQUIREMENTS.md); the local server is bundled.

Export compact inputs with tools/local_build/export_slim_inputs.py from the frozen
independent kit, passing --version 1.0.4. This omits the compiler and places exact
dependency sources in a separate release asset. Required runtime/header/metadata
inputs stay in build-inputs.zip and unpack into Local AppData.

Commit corresponding sources, then use launcher/package-slim.ps1 with -Inputs,
-KitManifest, -Server, -Output and -Version 1.0.4. Supply the frozen, manifested
portable server directory. Only its hash-verified declared files are copied into
network-server/; developer databases and configuration are excluded.

The main asset is RE-Outbreak-v1.0.4-Windows-x64.zip. It contains a framework-dependent
single-file launcher and the server, without a compiler, language folders or a
self-contained .NET runtime. ZIP entries must be relative, use / separators and
have no enclosing package-name directory. The launcher must appear at the archive
root. Extract into a fresh directory and verify every inventory entry's path,
length and SHA-256, including the server manifest and nested build inputs. Reject
backslashes, absolute paths, traversal, drive prefixes, duplicate names and
unexpected files.

Run `launcher/check-package-startup.ps1 -Root <extracted-folder> -Output <new-folder>`
on the extracted final ZIP. It starts the actual single-file executable from a
different working directory, renders the Graphics page and requires a successful
exit plus a PNG screenshot. No game, local server or full setup is launched.
Keep its receipt outside the package. Compilation or self-tests alone do not
verify WPF resources in the single-file layout.

Publish the exact corresponding SDK sources as
RE-Outbreak-v1.0.4-Dependency-Sources.zip, alongside the main download and checksums.
Retain upstream/project licences. There is no separate server asset. The launcher
does not download system dependencies.

Keep game binaries, original instruction code, extracted assets, saves,
credentials, handoffs and developer caches out of every public artifact. Inspect
nested input/source archives too. Preserve the dirty dependency checkout; matching
frozen dependency sources accompany the distributed independent binaries.

Use the [release notes](../.github/RELEASE_TEMPLATE.md), disclose omitted validation,
and publish the intended full commit SHA under a new tag. Do not replace existing
tags or claim a game/setup pass. The reference native build compiled successfully;
the external-compiler setup and gameplay were not rerun. Linux is not a release
asset. Compare uploaded asset sizes and SHA-256 digests before publication.
