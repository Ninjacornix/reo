# Retained AFS source ranges

Independent read-only index and range preparation. See the
[contract](../../../docs/native-media/AFS_SOURCE_RANGE_CONTRACT.md) and
[qualification](../../../docs/native-media/AFS_SOURCE_RANGE_IMPLEMENTATION.md).

`Archive::open` admits a bounded contiguous AFS layout on an immutable parent
ByteView. `member` returns logical metadata and a retained view of its real
sector extent. No synthetic padding or neighboring unadmitted bytes are read.

`prepare_open` is original arithmetic evidence, not permission to perform I/O:
the sentinel branch can return `inside_backend=false`. The caller must reject
that result. The member-view API checks actual parent bounds independently.

No loader worker, LSC control, decoder, device or guest ABI is included. The
standalone CMake target and parent native suite have no PS2Recomp dependency.
