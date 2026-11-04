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

## Windows releases from version tags

A release is published only when a maintainer pushes a version tag. Merges and
branch pushes never create a tag, prerelease or release, and CI never creates or
moves tags. To release, tag the exact commit and push the tag:

```
git tag v1.0.20-rc3 <commit>
git push origin v1.0.20-rc3
```

The tag push starts **Prepare Windows release** for that commit. A suffix
(`v1.0.20-rc3`) makes a testing prerelease that is never marked Latest; no suffix
(`v1.0.20`) makes a stable release, which is refused unless the tagged commit is
on `main`. The tag's numeric version must match the committed launcher
`DefaultVersion`. The game kits are reused from the release named by the
repository variable `RELEASE_INPUTS`, or `v1.0.20-rc2-hotfix` when it is unset.

**Actions → Prepare Windows release → Run workflow** remains available as a
validate-only dry run. It packages and checks the selected branch but never
creates a tag or release:

| Input | Meaning |
| --- | --- |
| `tag` | Version to validate, such as `v1.0.20-rc3` or `v1.0.20`. |
| `prerelease` | Validate as a prerelease (requires a suffix) or as stable (no suffix, branch `main`). |
| `inputs_release` | Existing published release supplying both verified game kits and the matching dependency source archive. Defaults to `v1.0.20-rc2-hotfix`. |
| `notes` | Optional release notes preview. CI appends the source commit, reused input release and validation limits. |

The workflow verifies GitHub's SHA-256 asset digests, the player package inventory,
both sealed kit inventories and edition identities. Reuse is limited to unchanged
game build inputs: changes to native/runtime code, SDK patches, build recipes or
generation metadata stop the workflow and require freshly prepared, validated kits.
It rebuilds the launcher, exports the current source-only server, produces the
complete Windows player ZIP and dependency-source ZIP with checksums, and tests
the extracted player package. It does not compile owned games or rerun gameplay;
missing game validation receipts remain pending rather than inheriting old passes.

The publication job runs only for a pushed version tag, after successful
packaging and UI checks. It verifies that the tag still names the validated
commit, uploads to a draft release, verifies all uploaded asset hashes, then
publishes it. Published release assets are not replaced on reruns; a failed
upload can leave a draft for manual recovery. The normal token has repository
write access only in that publication job; an optional `RELEASE_TOKEN` can be
used instead.

This prepares Windows player releases only. macOS launcher validation and source
build instructions do not constitute an automated Mac player-package pipeline.
