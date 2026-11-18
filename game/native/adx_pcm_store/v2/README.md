# Phased PCM store

See the [contract](../../../../docs/native-media/ADX_PCM_STORE_V2_CONTRACT.md)
and [qualification](../../../../docs/native-media/ADX_PCM_STORE_V2_IMPLEMENTATION.md).

`reserve -> stage -> publish` exposes the actual raw-PCM-before-input-credit and
output-publication-after-input-credit boundary. Between stage and publish,
producer credit remains held and PCM mutations refuse. No automatic rollback,
publication, token credit return, guest dependency or device fence exists.

V1 remains frozen separately. This version is the storage component intended
for Window2; complete decoder and game integration are still pending.
