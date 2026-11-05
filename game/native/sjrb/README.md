# Standalone native SJRB ring owner

This library owns one physical byte ring plus its wrap extension. It implements
two-pool Get/Put/Unget/peek/count/reset and transfer totals, with explicit
serialized guard/error hooks. It has no guest RAM, pointers, register context,
runtime/engine or device dependency. It does not implement the global 256-record
SJRB module, a decoder or a complete ADXT player.

```powershell
cmake -S game/native/sjrb -B build-native-sjuni/sjrb-cmake -G Ninja
cmake --build build-native-sjuni/sjrb-cmake
ctest --test-dir build-native-sjuni/sjrb-cmake --output-on-failure
```

Construction validates the whole positive geometry and allocates storage once.
`Chunk` retains that actual storage; checked read/write copies expose no raw
pointer. A chunk remains readable after the Ring is destroyed. Reset invalidates
prior chunks without clearing physical bytes. Foreign/stale/out-of-backing
positive spans refuse before guard hooks or ring effects. Nonpositive/null
Put/Unget remain original no-ops before guard entry.

The original API is numerically permissive: current in-backing spans need not
have been acquired and repeated returns are not rejected. This core preserves
that behavior. `make_span` is explicit numeric admission, **not** a linear lease.
A future window owner must separately track exactly-once borrow/publication and
stop lifetimes. Negative Get is excluded because it could make the next ring
position unsafe; signed peek/count and wrapping counters remain explicit.

Callers serialize every Ring/chunk access. There is no internal mutex, atomics
protocol, scheduler or claimed lock-free SPSC behavior. Guard hooks observe only;
error callbacks may observe and edit the active chunk length as documented.
Mutating Ring reentry refuses. Do not destroy the Ring or callback context in
an enclosing call. A guard mutation detected after entry returns
`callback_contract_violation`, which is **not** a safe original-call fallback.

Implementation was authored after the original oracle was generated/seen, then
frozen in `frozen_identity.json` before comparator development. That JSON records
the historical freeze stage. Qualification and exact domain exclusions are in
[SJRB_IMPLEMENTATION.md](../../../docs/native-media/SJRB_IMPLEMENTATION.md).

Compare against the retained original fixture into new directories:

```powershell
python game/native/sjrb/compare_original.py --compiler g++ --output build-native-sjuni/sjrb-parity-new/gcc
python game/native/sjrb/compare_original.py --compiler clang++ --output build-native-sjuni/sjrb-parity-new/llvm
```

The comparator checks frozen implementation and original fixture/input hashes.
GCC and LLVM each pass 30 admitted cases / 165 calls against the current v4 fixture, plus
the standalone native unit checks; exact evidence paths are in the document above.
V4 adds the actual PCM **16384+192 byte** geometry. The earlier 8192+192 case
was a smaller synthetic test and had been mislabeled actual PCM geometry;
all v3 evidence and earlier receipts are preserved. The native core is unchanged.
Only input transcripts generate native commands; expected observations never
enter the C++ runner. The runner's synthetic address mapping terminates at its
transport boundary and is not part of the library. Original init/create seed
the standalone owner's initial state; their global module/pool calls are not
compared. Guest backing-pointer/UUID return addresses and guest ABI/stack writes
have no typed-layout equivalent and are excluded explicitly. Complete physical
backing, descriptor words, numeric state/returns and guard/error observations
are compared for admitted operations.
