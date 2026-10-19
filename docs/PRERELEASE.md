# Portable prerelease preparation

The former v1.0.0 binary prerelease is withdrawn. No replacement playable
package is being published by this source update.

The next Windows package uses the independent launcher, runtime sources and a
portable LLVM/MinGW toolchain. On first launch, the user selects the supported
NTSC-U v2.00 ISO. Generation and compilation happen locally; subsequent launches
reuse the private cache. No system compiler installation or ISO mounting is
intended. The ISO remains available for sector reads.

Include the original application icons, independent dependency sources and
licences, the controller adapter and the separately licensed portable server.
Exclude game executables, generated game bodies and shaders, extracted assets,
memory cards, server databases, credentials, developer caches and captures.

The package exporter requires a sealed, hashed kit and a matching completed
local-build/room-route record. Do not substitute developer gameplay evidence for
a successful build made from the exact packaged kit. The portable Windows build
is still in progress; Linux packaging and feature parity remain unfinished.

Current co-op evidence includes a two-client original-login, shared waiting-room
and first-room retest, separate automatic-account/native-login checks, and older
local movement checks. It does not establish Internet play, reconnects, item
sharing or transitions. The latest follow-up test was interrupted. Testing was
stopped at the user's request; no further pass is implied.

Source-only distribution reduces bundled game-content exposure but is not a
guarantee against copyright complaints or takedown requests.
