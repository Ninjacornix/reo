# Continuous integration

`Windows validation` runs on every pull request targeting `develop` or `main`,
on pushes to those branches, and through manual dispatch once the workflow is
on the default branch. There are no path filters on its required checks.

`Universal launcher` checks Windows, Linux and macOS and compares the Windows
launcher against the published RC1 reference. New commits cancel superseded runs
for the same pull request or branch, reducing redundant work and runner demand.
macOS jobs can still fail before starting when GitHub has insufficient hosted
ARM runner capacity; retry the affected job once capacity is available.

Pull requests retain visual-comparison captures as `launcher-parity` artifacts.
Only non-PR runs with captured results publish to `ci/parity-results`, and
cancelled runs do not publish. Fork PRs therefore never need write access to the
results branch. Artifact upload still runs after a failed comparison.

| Check | Coverage |
| --- | --- |
| Source checks | Publication-input audit, Python local-build and asset-tool tests using synthetic inputs, native pipeline-cache checks on Ubuntu |
| Windows launcher | Clean launcher/native helper build, asset-free universal-launcher checks for all 12 pages and Windows service/adapter tests, both games' audio IPC bridges, native cheat and File #2 unlock fixtures, self-contained Windows x64 folder/single-file publish, published UI checks and updater process tests |

The Windows build pins Vulkan-Headers v1.4.321 by commit. It needs only those
headers, Visual Studio/Windows SDK tools and .NET 10. It does not install the full
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

Full native game builds, owned-disc PCM/resource tests, interactive GPU/gameplay
checks, scenario routes and final RC1 package validation remain separate. A green
CI run establishes only the coverage above. The existing Linux portable
foundations workflow remains available for its focused Linux checks.

## Windows releases and automatic tags

`Prepare Windows release` is a manual workflow. Once `release.yml` is on the
repository's default branch, select **Actions → Prepare Windows release → Run
workflow**. Select the source branch: `develop` for testing prereleases or `main`
for stable releases. The run uses that branch's exact dispatched commit.

| Input | Meaning |
| --- | --- |
| `tag` | Full version, such as `v1.0.20-rc3` or `v1.0.20`. Its numeric version must match the committed launcher `DefaultVersion`. |
| `prerelease` | Defaults to true. Prereleases require a version suffix and are never marked Latest. Stable versions require no suffix and must be prepared from `main`. |
| `create_tag` | Defaults to true. Creates the tag at the validated commit only in draft/publish mode. Existing tags are never overwritten. Disable this to use an existing tag pointing to exactly that commit. |
| `publication` | Defaults to **validate-only**, which uploads CI artifacts without creating any GitHub tag or release. **draft** creates the tag and an unpublished release; **publish** publishes it after upload verification. |
| `inputs_release` | Existing published release supplying both verified game kits and the matching dependency source archive. Defaults to `v1.0.20-rc2-hotfix`. |
| `notes` | Optional release notes. CI appends the source commit, reused input release and validation limits. |

The workflow verifies GitHub's SHA-256 asset digests, the player package inventory,
both sealed kit inventories and edition identities. Reuse is limited to unchanged
game build inputs: changes to native/runtime code, SDK patches, build recipes or
generation metadata stop the workflow and require freshly prepared, validated kits.
It rebuilds the launcher, exports the current source-only server, produces the
complete Windows player ZIP and dependency-source ZIP with checksums, and tests
the extracted player package. It does not compile owned games or rerun gameplay;
missing game validation receipts remain pending rather than inheriting old passes.

The publication job tags only after successful packaging and UI checks, verifies
all uploaded asset hashes while the release is still a draft, then applies the
selected publication/prerelease state. Tags and published release assets are not
replaced on reruns. A failed upload can leave a tag or draft for manual recovery.
The normal token has repository write access only in that publication job. An
optional `RELEASE_TOKEN` with the required contents/workflows permissions supports
tagging source commits whose workflows differ from the default branch.

This prepares Windows player releases only. macOS launcher validation and source
build instructions do not constitute an automated Mac player-package pipeline.
