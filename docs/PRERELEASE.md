# Prerelease packaging

The current target is **v1.0.2**, marked prerelease on GitHub. v1.0.0 and v1.0.1
binary downloads are withdrawn. The user requested separately installed
requirements instead of bundled system dependencies; see [requirements](../REQUIREMENTS.md).

Export compact inputs with `tools/local_build/export_slim_inputs.py` from the
frozen independent kit. This omits the compiler and moves exact dependency
sources to a separate release asset. Runtime/header/metadata inputs needed to
build from the user's ISO stay in `build-inputs.zip` and unpack into Local AppData.

Commit corresponding sources, then use `launcher/package-slim.ps1 -Inputs ...
-KitManifest ... -Output ... -Version 1.0.2`. It publishes a framework-dependent
single-file launcher without language folders or a self-contained .NET runtime.
Use the asset name `RE-Outbreak-v1.0.2-Windows-x64.zip`. The updater recognizes
this layout and retains path, file-count, size and SHA-256 checks.

Publish the corresponding independent SDK source ZIP as
`RE-Outbreak-v1.0.2-Dependency-Sources.zip`, alongside the main download, and
retain upstream/project licences. Provide the portable server separately as
`RE-Outbreak-v1.0.2-Server.zip`, rooted at `network-server/`, for optional hosting.
The launcher does not fetch either system dependencies or the server itself.

Keep game binaries, original instruction code, extracted assets, saves,
credentials, handoffs and developer caches out of all public artifacts. Inspect
nested input/source archives as well as the outer package. The dirty dependency
checkout is preserved; matching frozen dependency sources accompany the binaries.

Use [release notes](../.github/RELEASE_TEMPLATE.md), disclose omitted validation,
and publish from the intended committed revision using a new tag. Do not replace
existing tags or manufacture a game/setup pass. The reference native build
compiled successfully; the revised external-compiler setup and gameplay were not
rerun. Linux remains unfinished and is not an asset in this release.
