# Continuous integration

`Windows validation` runs on every pull request targeting `develop` or `main`,
on pushes to those branches, and through manual dispatch once the workflow is
on the default branch. There are no path filters on its required checks.

| Check | Coverage |
| --- | --- |
| Source checks | Publication-input audit, Python local-build and asset-tool tests using synthetic inputs, native pipeline-cache checks on Ubuntu |
| Windows launcher | Clean launcher/native helper build, asset-free launcher self-checks, both games' audio IPC bridges, native cheat and File #2 unlock fixtures, self-contained Windows x64 publish and published self-checks |

The Windows build pins Vulkan-Headers v1.4.321 by commit. It needs only those
headers, Visual Studio/Windows SDK tools and .NET 8. It does not install the full
Vulkan SDK, initialize the patched game SDK submodule, use a GPU or load game
assets. Actions are pinned by full commit. PR jobs use read-only repository
permissions and do not receive repository secrets.

Passing runs upload `launcher-preview-win-x64`, a ZIP containing the launcher,
its .NET runtime, native helpers and notices. It is explicitly a launcher preview:
it omits game build kits and cannot install/play games as a complete release
would. Reports and previews expire after seven days. Release publishing remains
manual through the existing sealed-kit package process.

Both `Source checks` and `Windows launcher` are required before merging PRs into
`develop` and `main`, including administrator merges. Branches must be up to date;
force pushes and branch deletion are disabled. Keep those job names stable. A normal
feature goes through a PR into `develop`; release integration goes through a PR
from `develop` into `main`. No outside approving reviewer is required for the
single-maintainer workflow.

To run Windows checks locally, use a fresh output directory:

```powershell
./tools/ci/windows.ps1 -VulkanHeaders <Vulkan-Headers-checkout> -Output <new-output-directory>
```

Full native game builds, owned-disc PCM/resource tests, interactive WPF/GPU
checks, scenario routes and final RC1 package validation remain separate. A green
CI run establishes only the coverage above. The existing Linux portable
foundations workflow remains available for its focused Linux checks.
