# REO divergences (Milestone 1 log)

Each entry records the first observed divergence from real hardware/PCSX2 at a boot checkpoint, the evidence, the smallest fix, and its validation. Newest at the bottom.

Game: `SLUS-20765` NTSC-U v2.00, ELF SHA-256 `06BD5FD7…B4CA46`. Branch `baseline/pivot-selfexec`. Run mode `REO_NATURAL=1` (no PCSX2 snapshot injection) unless stated.

---

## D1: IOP reboot never completes; boot hangs in `SifIopSync` — FIXED (HLE)

Date: 2026-10-09. Category: **IOP SIF/HLE** (missing IOP side of a reset handshake).

### Observed (before)
`tools\smoke_test.ps1 -Env REO_NATURAL=1 -Label natural`, run `build-ninja\smoke\20261009-121008-natural`:

| tick (≈1/60 s) | hot PCs | dma/gif |
|---|---|---|
| 60 | `0x113af4`, `0x11d7b4` | 2 |
| 120 | `0x113a38`, `0x114af0` (display init) | 36 |
| 180 → 1800 | `0x114a34` (`sceSifGetReg`), called from `0x11cc68` | 36 (no progress) |

Every poll returned `[sceSifGetReg] reg=0x4 value=0x20000`.

### Analysis (Ghidra `/ps2/SLUS_207.65`, R5900 language; confidence: confirmed by disassembly + runtime log)

| Address | Proposed name | Evidence |
|---|---|---|
| `0x0011CAD8` | `SifIopReset(const char *arg, int mode)` | Builds a 0x68-byte SIF command: cid `0x80000003` (`SIF_CMD_RESET`) at +0x08, arg length +0x10, mode +0x14, arg string +0x18. Sends via `0x001149E0` (syscall 0x77 `sceSifSetDma`), then `sceSifSetReg(4, 0x40000)`, `(4, 0x10000)`, `(4, 0x20000)`, `(0x80000002, 0)`, `(0x80000000, 0)`. Matches PS2SDK `SifIopReset`. |
| `0x0011CC58` | `SifIopSync()` | `if (sceSifGetReg(4) & 0x40000) { sub_00114AA0(); sub_0011F7D0(1,1); sub_0011F7D0(0,1); return 1; } return 0;` |
| `0x00114A20` / `0x00114A30` | `sceSifSetReg` / `sceSifGetReg` | syscall wrappers (0x79/0x7A) |
| `0x00116FD0` | `SyncDCache` | `cache DHWBIN` loop |

SMFLAG (SIF reg 4, `SBUS_F230`) bits: `0x10000` SIFINIT, `0x20000` CMDINIT, `0x40000` BOOTEND. On hardware the EE clears bits by writing them (PCSX2 `pcsx2/HwWrite.cpp`: `mcase(SBUS_F230): psHu32(mem) &= ~value;`), and the rebooted IOP sets them again.

**Divergence:** the PS2Recomp runtime (`ps2xRuntime/src/lib/Kernel/Stubs/SIF.cpp`):
1. `sceSifSetDma` copied the reset packet but never acted on `SIF_CMD_RESET`, so no IOP reboot happened.
2. Only the startup seed (`0x60000`) set SMFLAG bits, so BOOTEND never came back.
3. `sceSifSetReg(4, v)` stored `v` (assignment) instead of clearing bits.

### Fix
`third_party/patches/ps2recomp/0001-sif-hle-iop-reboot-and-smflag-w1c.patch` (applied by `tools/setup_deps.ps1`):
- `sceSifSetDma`: a transfer whose header cid == `0x80000003` sets `g_iopRebootPending` and logs the reset arg.
- `sceSifGetReg(4)`: if a reboot is pending, `SMFLAG |= SIFINIT|CMDINIT|BOOTEND` (the HLE IOP finishes rebooting by the EE's next poll, i.e. after `SifIopReset`'s own clears, as on hardware).
- `sceSifSetReg(4, v)`: `SMFLAG = prev & ~v` (write-1-to-clear).

HLE status: the reboot is **instant**, and the IOP modules named by the reset arg are **not** emulated or loaded. Only the handshake bits are modelled. The real IOP's timing (milliseconds) and module side effects are not reproduced. Validation: handshake only.

### Observed (after)
Run `build-ninja\smoke\20261009-122735-natural-iopreboot`, same command:

```
[SIF] IOP reset command #1 (SIF_CMD_RESET) arg='rom0:UDNL cdrom0:\IOP\MODULES\DNAS280.IMG;1'
[SIF] IOP reboot #1 complete: SMFLAG |= SIFINIT|CMDINIT|BOOTEND -> 0x70000
[sceSifSetReg] reg=0x4 prev=0x60000 value=0x40000 …   (-> 0x20000, W1C)
```
- `SifIopSync` returns. From tick 180 the hot PCs move to `0x114644`/`0x114664`, `0x1188a8`, `0x118xxx`, `0x117080`/`0x117818` (`sceSifBindRpc`/`sceSifCallRpc` bindings → runtime HLE).
- About 128 `WaitSema`/`SignalSema` pairs on semaphores 8/9 (the log cap): repeated RPC request/complete cycles.
- Still `tasks=0`, `dma=36`: no new GS work yet. Process alive at 60 s.

Result: **PASS** for the D1 exit criterion (leave `SifIopSync`). The game is not yet at the title screen.

### Next (D2 candidate)
Identify the RPC loop: which server IDs and function numbers the game calls repeatedly around `0x1188a8`/`0x114644`, and what replies it expects. Likely IOP module loading (`DNAS280.IMG` IOPRP and the modules from `cdrom0:\IOP\MODULES\`) via the loadfile RPC. Reference: PCSX2 with PINE (verified working), US BIOS `scph39001.bin`. Compare the RPC sequence and the first differing reply.

---

## D2: SIF RPC mis-bound; FILEIO unserved; boot loops in `fioInit` — FIXED (HLE), next blocker found

Date: 2026-10-09. Category: **bad HLE override** + **IOP SIF/HLE** (missing IOP server).

### Observed (before)
After D1, run `…-natural-iopreboot`: the hot PCs cycle through `0x1188a8` (inside `0x1187A0`), `0x117080`/`0x117818` and the semaphore syscalls `0x114644`/`0x114664`. About 128 `WaitSema`/`SignalSema` pairs on mutex semaphores 8/9. No `[SifCallRpc]`/`[sceSifSendCmd]` HLE log line at all.

### Analysis (Ghidra + PCSX2/PINE reference; confidence: **confirmed**)

| Address | Name | Evidence |
|---|---|---|
| `0x00117080` | `SifInitRpc(mode)` | Sets the init flag `0x209D50`, calls `SifInitCmd` (`0x116920`), and builds the RPC packet pool at `0x25C9C0` (table at +0x4, **count 0x20 at +0x8**). Registers cmd handlers `0x80000008/9/A/C`, then the MSCOM handshake (`0x80000002`). |
| `0x00117248` | `_rpc_get_packet` | Scans the pool; returns NULL when count == 0. |
| `0x001179E8` | `SifCallRpc` | Gets a packet (returns **-1** if NULL), then sends `SIF_CMD_RPC_CALL` `0x8000000A` via the game's `SifSendCmd` (`0x116e08`) and waits on a semaphore for the IOP reply. |
| `0x001187A0` | `fioInit` (EE fileio client) | `SifInitRpc`; adds cmd handlers `0x80000011`/`0x80000013`; `SifBindRpc(client, 0x80000001 /*FILEIO*/)`; clears a 0x200-byte table (the hot `0x1188a8`); `SifCallRpc(fno 0xFF, send 8, recv 8)`. Stores reply word0 at `0x25E168`; sets `0x209DE0 = (word1 == 2)`. |
| `0x001189A8` | fileio version check | `memcmp` of the reply word0 against `"2800"` (`0x209D2C`, the tail of `"PsIIlibkernl2800"` at `0x209D20`) |

**PCSX2 reference** (2.2.0, same ISO, read over PINE while running):
- `0x25C9C8` (pool count) = **32**
- `0x25E168` = **`"2800"`**
- `0x209DE0` = **1** (reply word1 == 2)
- `0x209DDC` = 1

In reo:
- **Upstream bound `0x117080` to `sceSifBindRpc`** (comment "the RPC init/handshake"). The pool was never initialized, so `SifCallRpc` returned -1 and `fioInit` retried forever.
- Even with a pool, the game's raw SIF command transport is not emulated.
- The runtime's IOP HLE serves only the sound driver and `libsd`. The runtime never called `HwBridgeVtable::onSifRpc`, so reo's bridge servers (CDVD/PAD/MC) were dead code, and **no FILEIO server existed**.

### Fix
- `recomp/overrides/reo_override.cpp`: `0x117080` → `ps2_syscalls::SifInitRpc` (HLE); `0x1179E8` → `ps2_syscalls::sceSifCallRpc` (HLE). The libsif RPC family (init/bind/call) now consistently uses the runtime HLE.
- `recomp/config/outbreak.toml`: `sub_001179E8` added to `skip` so direct calls hit the stub and its binding. `sub_001179E8_0x1179e8.cpp` is replaced with the pinned recompiler's stub output; headers are unchanged (the declaration already exists in `ps2_recompiled_functions.h`).
- `third_party/patches/ps2recomp/0002-…`: the runtime `SifCallRpc` falls back to `HwBridgeVtable::onSifRpc` when its own IOP HLE does not handle a server.
- `recomp/overrides/reo_hw_bridge.cpp`: new FILEIO server (`0x80000001`). `fno 0xFF` replies `{"2800", 2}` (matches PCSX2). Every call is logged with hex + text; other functions return -1 (no fake success).

HLE status: FILEIO init only. Open/read/etc. are **not implemented**; they fail explicitly.

### Observed (after)
Run `build-ninja\smoke\20261009-125501-natural-d2b` (`REO_NATURAL=1`, 60 s):
```
[SifInitRpc] Initialized
[SifCallRpc] sid=0x80000592 rpcNum=0x0 → [HW-BRIDGE:CDVD] cdInit          (bridge reachable)
[SifCallRpc] sid=0x80000001 rpcNum=0xff → [HW-BRIDGE:FIO] fno=0xFF       (once; version check passes)
[HW-BRIDGE:FIO] fno=0x0 send=0x0025CA40/1048 recv=0x0025D680/4 data=[0B 00 00 00 50 FE FE 01 04 00 00 00 01 00 00 00 00 00 00 00 …]
                "cdrom0:\IOP\MODULES\DRIVE.DAT;1"
[CreateSema] id=11 init=0 … [WaitSema:block] tid=1 sid=11 pc=0x114664 ra=0x118c68
```
Result: **PASS** for D2 (`fioInit` completes once, matching PCSX2's state; the game proceeds to its first file open).

### Next (D3)
FILEIO open of `cdrom0:\IOP\MODULES\DRIVE.DAT;1`. Request layout to decode: word0 `0x0B`, `0x01FEFE50` (EE address), `4`, `1`, `0`, path at +0x14. After the call the EE blocks on semaphore 11 (`ra 0x118c68`). It is presumably signaled by the fileio cmd handlers registered in `fioInit` (`0x80000011` at `0x118268`, `0x80000013` at `0x118758`) when the IOP reports completion. Implement open/read/lseek/close against the disc (reo `CDVD` maps 85 disc files) and the completion signal, verified against PCSX2 (`DRIVE.DAT` contents/size and the reply layout).

---

## D3: FILEIO open/lseek/read/close unserved — FIXED (HLE); first disc file loads

Date: 2026-10-09. Category: **IOP SIF/HLE** (missing FILEIO operations).

### Protocol (EE side, Ghidra; confidence: probable — consistent with every observed request)
EE fileio requests (`0x118A70` open, plus siblings) use a common header in the send buffer at `0x25CA40`: `+0` completion semaphore (created per call), `+4` EE address of the 4-byte result, `+8` result size, then arguments. The RPC reply `recv[0] != 0` means "accepted". The EE then `WaitSema`s. On hardware the IOP completes via cmd `0x80000011` (handler `0x118268`: copy payload to the EE address, then `iSignalSema`).

| fno | op | arguments (after +0xC) |
|---|---|---|
| 0x0 | open | +0xC flags, +0x10 mode, +0x14 path (≤0x400) |
| 0x1 | close | +0xC fd |
| 0x2 | read | +0xC fd, +0x10 EE buffer, +0x14 size |
| 0x4 | lseek | +0xC fd, +0x10 offset, +0x14 whence |

### Fix
- PS2Recomp patch `0003`: public `ps2_syscalls::hleSignalSema(id)` (wraps the runtime's `signalRpcCompletionSema`) so host-side IOP servers can complete async requests.
- `reo_hw_bridge`: FILEIO open (disc files via `reo::CDVD::resolve_path`, read-only; non-`O_RDONLY` → -30), lseek (`_fseeki64`), read (bounds-checked direct write into EE RAM), close. Up to 32 fds; results are written to the EE result address, then the semaphore is signaled. Errors use negative errno-style values.

HLE status: the read path skips the hardware's aligned-DMA + head/tail cmd split and writes the final bytes directly. Equivalent end state for the EE buffer, but the cmd `0x80000011` handler bookkeeping is not exercised. Validation: sizes match the disc file; the game proceeds to the next stage. Byte-level comparison with PCSX2 memory: TODO.

### Observed (after)
Run `build-ninja\smoke\20261009-130227-natural-d3c`:
```
open  "cdrom0:\IOP\MODULES\DRIVE.DAT;1" -> fd 0
lseek fd=0 (SEEK_END) -> 356544
lseek fd=0 (SEEK_SET) -> 0
read  fd=0 buf=0x01000000 size=356544 -> 356544
close fd=0 -> 0
[HW-BRIDGE:SIF] unhandled sid=0x80000003 func=1      (SIFHEAP: IOP heap alloc)
[HW-BRIDGE:SIF] unhandled sid=0x80000006 func=255    (LOADFILE: init)
```
Afterwards the game polls (hot PCs `0x11be..`–`0x11c1..`) rather than blocking. Result: **PASS** for D3.

### Next (D4)
IOP heap (`0x80000003`) + LOADFILE (`0x80000006`): `DRIVE.DAT` (356,544 bytes, now at EE `0x01000000`) is most likely a bundle of IRX modules for `SifLoadModuleBuffer`-style loading. Decode the requests and replies against PCSX2, and record which modules the game loads and the results/IDs it expects.

---

## D4: IOP heap + LOADFILE unserved; HDD probe hung; reboots leaked IOP state — FIXED (HLE)

Date: 2026-10-09. Category: **IOP SIF/HLE**.

### Analysis (Ghidra + PCSX2/PINE; confidence: confirmed for the replies, probable for request layouts)
- `0x1AB560` = game IOP init: `sceSifRebootIop("…DNAS280.IMG")` (`0x11CCA8`) + `SifIopSync`. Reads `DRIVE.DAT` into EE `0x01000000`, `SifAllocIopHeap` (`0x11B8B0`), DMAs it to IOP, waits on `SifDmaStat`. Relocates the archive table (magic `"MUU-"`, 11 entries), then loads each module via `SifLoadModuleBuffer` (`0x11BF40` → LOADFILE fno 6) and frees the heap. Then HDD setup (`0x1BCF60`) and path loads (`0x18D770`).
- LOADFILE init check `0x11BE78` compares the reply word with `"2800"` (like FILEIO).
- PCSX2 reference: LOADFILE init reply `"2800"`; a later heap alloc returned IOP `0x00081200`; last module reply id `0x29`, result 2.
- EE `0x88000–0xFFFFF` is unused in PCSX2 (`0x80000–0x87FFF` holds data). The runtime's `sceSifSetDma` aliases IOP destinations onto EE RAM, so the HLE IOP heap lives there.
- `devctl("hdd0:", HDIOC_STATUS 0x4807)` (FILEIO fno 0x17, client `0x11B248`, request 0x81C bytes) waited forever because unknown fnos were "accepted" but never completed.

### Fix (`reo_hw_bridge`, PS2Recomp patch 0004)
- SIFHEAP `0x80000003`: alloc (bump allocator, IOP `0x88000–0xFFFFF`, fails loudly when exhausted), free (accepted).
- LOADFILE `0x80000006`: init `"2800"`; fno 6 (buffer) and fno 0 (path) return fresh ids, result 0 (`RESIDENT_END`). Modules are **not executed**; their services are HLE servers.
- FILEIO: devctl → `-ENODEV` (no HDD/network device); any other fno completes with -48 + sema signal (logged `** UNIMPLEMENTED`).
- Patch 0004 exposes `ps2_stubs::hleIopRebootCount()`; the bridge resets the HLE heap and open fds on every IOP reboot.

### Observed (after)
Every IOP boot cycle completes: 11 `DRIVE.DAT` modules (ELF magic at the aliased heap addresses, proving the DMA), `ATAD/HDD/PFS.IRX`, HDD probe → -19, `pfs0:` fno 0x14 → -48, `NETBIO00.DAT` opened + sized (907,040,768 bytes), `USBD/USBKB.IRX`. But the game then **restarted from the ELF entry** repeatedly (see D5/D6).

---

## D5: EE heap limit and main stack placement wrong in runtime — FIXED

Category: **runtime kernel HLE**. Confidence: confirmed.

- Entry `0x100008`: `SetupThread(gp 0x261CF0, stack -1, size 0x10000)`, `SetupHeap(0x8AA380, -1)`.
- `0x114D20` = `sbrk`: `if (EndOfHeap() < heap_ptr(0x209D34) + incr) { errno = ENOMEM; return -1; }`. `0x106EE0` = `malloc` (newlib: lock / `_malloc_r` `0x1071D8` / unlock), extend-top `0x106F80`.
- `0x19F430` mallocs `0x160003F` (22 MB) and fails boot if NULL.
- Runtime bugs: `EndOfHeap` returned the runtime allocator's *current* end (≈ heap base), not the limit. `SetupThread(stack=-1)` returned `sp = RAM - size` (the stack bottom), so the stack grew down into the heap. The runtime's own `guestMalloc` (HLE stubs, auto thread stacks) shared the game's heap range.
- PCSX2 reference: the game's final `sbrk` pointer is `0x01FBC000` (23.07 of 23.27 MB used; 208 KB free below the stack at `0x1FF0000`). Stack activity is at `0x1FFD000–0x1FFEFFF`, nothing above `0x1FFF000`.
- Fix (patch 0005): stack `[RAM-size, RAM)` with `sp = RAM - 0x1000`; `SetupHeap(base, -1)` → user heap `[base, stackBottom - 128 KB)`, runtime reserve `[stackBottom - 128 KB, stackBottom)`; `EndOfHeap` returns the user limit.
- Verified: after D6, reo's `sbrk` pointer reaches **`0x01FBC000`, identical to PCSX2**.

## D6: function-pointer-only functions not recompiled → silent restart — PARTIAL (1 of many)

Category: **recompilation coverage**. Confidence: confirmed.

- `REO_PEEK` change-log (patch 0006, new tool) showed `malloc` succeeding at tick 134 and the init marker `0x29FDAC` being cleared at tick 151. The log between them:
  `Function at address 0x115f30 not found` → `[dispatch:first-bad-pc] bad=0x115f30 ra=0x1167b0` → `[dispatch:recover-pc] … fallback=0x100008`. The runtime "recovers" by **restarting at the ELF entry**: BSS is cleared but the `sbrk` pointer (in .data) survives, so every restart's 22 MB malloc fails → endless reboot loop.
- `0x115F30` is a putchar-style console function referenced only as data (function pointer stored by `0x116848`). The analyzer merged it into `sub_00115EF0` (`0x115EF0–0x116018`), so no entry was registered.
- Fix: `recomp/overrides/reo_extra_functions.cpp` holds the recompiler's own code for `0x115F30–0x115FE0`, extracted verbatim from `sub_00115EF0`. It gets a new entry header; 4 jr-switch cases for labels outside the range were dropped (default path returns to the dispatcher). It is registered via `registerFunction` in every mode.
- Result (run `…-natural-d6a`): **no restart loop** (1 IOP reset, 1 SetupHeap), `sbrk` = `0x01FBC000` (= PCSX2), console output path runs. Next stop: indirect call to **`0x131070`** (same class), then a resume at `0x1351F0` (mid-function return address, unsupported by old codegen).
- **Scale:** Ghidra (R5900 language) lists **4,824** function starts in the main ELF; **1,082** have no registered recompiled entry (e.g. `0x115F30`, `0x131070`). Per-function extraction does not scale.

### Recommended next step
Regenerate `recomp/config/output/` with the pinned `ps2_recomp` using `ghidra_output` (a full Ghidra function-map CSV). This registers all known entries and brings the pinned codegen everywhere: resume entries, 64-bit branch compares, no all-labels jr switches. Preconditions: keep the 3 HLE-skipped libsif functions + `sub_001F73B0` (runaway) in `skip`, carry over the one remaining hand edit (`entry_1cb9a0` printf; inventory first), full rebuild (~1–2 h), re-run D1–D6 checks.

---

## D7: full regeneration with a Ghidra function map (branch `m1/ghidra-regen`)

Category: **recompilation coverage + codegen correctness**. Supersedes the per-function extraction in D6.

- `tools/ghidra_export_functions.py` exports Ghidra's function list (R5900 language) via ghidra-mcp HTTP (read-only) into `recomp/config/outbreak_ghidra_functions.csv`, which `outbreak.toml` feeds to `ps2_recomp` as `ghidra_output`. Names use the `sub_XXXXXXXX` convention so hand-written code keeps linking.
- **Pitfall found:** 16 Ghidra functions have non-contiguous bodies (shared tails). Using `body_end` produced overlapping functions up to 114 KB long → generated files up to 178 MB (1.5 GB total). Fix: clamp each end to the next function's start → 75 MB total, largest file 1 MB.
- **Coverage:** 4,824 → 20,122 registered entries, including resume entries for mid-function return addresses (e.g. `0x1351F0`), which the old codegen could not resume at. The pinned codegen also brings 64-bit branch compares everywhere.
- Regeneration is deterministic (in-place output == scratch output, byte-identical).

## D8: VU0 macro-mode multiply-accumulate translations wrong (PS2Recomp codegen) — FIXED

Category: **recompiler codegen**. Confidence: confirmed against the VU instruction set semantics.

- Compile error: generated code used `PS2_VOPMUL`, which the runtime never defined.
- An audit of all 30 VU0 ACC-related translators against the rule "only the A-forms (ADDA/SUBA/MADDA/MSUBA/MULA/OPMULA) write ACC, under the dest mask; vd-forms never write ACC" found:
  - `VMULA` used the outer product; `VMSUB` used the outer product and wrote ACC; `VOPMSUB` used an element-wise product and wrote ACC (patch 0007; `PS2_VOPMUL = a.yzx * b.zxy`).
  - `MADD`, `MADDx/y/z/w`, `MADDq/i`, `MSUBx/y/z/w`, `MSUBq/i` overwrote ACC: **222 call sites** in the game's matrix/vector code (patch 0008).
  - 19 A-forms wrote ACC without the dest mask (patch 0009).
- After the fixes: 0 violations. Only the files using these instructions changed (4 + 41 + 41).
- Validation status: semantic (spec + audit). No bit-level comparison against PCSX2 VU0 yet; that is the next step if 3D math diverges.

## D9: stub-era overrides intercept direct calls in the new codegen — FIXED

- With regenerated code, reo's `bind()` overrides also catch direct calls. Upstream's 80 stub-era bindings then shadowed real code, e.g. `0x107D28`/`0x107DA8` = malloc lock/unlock bound to `reo_ret0`. Boot stalled in `_malloc_r` with the sbrk pointer zeroed.
- Fix: in `REO_NATURAL`/`REO_NO_OVERRIDES` only the libsif HLE bindings (D2) apply.
- Result: boot again matches PCSX2 (sbrk pointer `0x01FBC000`), 1 IOP reboot, no "function not found" at `0x131070`.

## D10: DECI2 debug channel unrouted; `libdbc` version check — FIXED (HLE)

- Syscall `0x7C` (`Deci2Call`) was not dispatched. The game's TTY writer `0x115BE8` sends via `sceDeci2ReqSend`, then loops on `sceDeci2Poll` until a "write done" event that no host delivers. Patch 0010: dispatch `0x7C`; `kputs` and `ReqSend` payloads print as `[EE-TTY]`; `ReqSend` fails (retail behaviour, no host), so the writer returns.
- The game's own TTY then reported `libdbc: Module version mismatch`. `libdbc` init (`0x188938`) binds `dbcman` servers `0x80001300/0x8000131B/0x8000131C` and needs `(version >> 8) == 3` from rpc `0x80001363` (`0x1888E0`). The bridge answers `0x0300` (minor unverified); other dbcman calls are logged and answered with zeros.

## D11: undefined pointer-only functions (Ghidra gaps) — FIXED (pending build verification)

- The next run hit `Function at address 0x139810 not found` (ra `0x13547c`): a 24-byte gap between Ghidra functions.
- `tools/ghidra_fill_gaps.py` scans the ELF for non-zero code between mapped functions and has Ghidra create functions there, iterating until convergence. 8 rounds created **748 functions** (map: 5,586 functions, 20,832 registered entries). 21 gaps remain (creation rejected; likely data or switch-case tails: `0x102bf0, 0x12b5d0, 0x12fb98, 0x134db8, 0x13a058, 0x13a078, 0x13a180, 0x13eba8, 0x13f0f0, 0x13f1e0, 0x147e38, 0x148078, 0x15cc80, 0x164410, 0x164580, 0x164820, 0x176c78, 0x191660, 0x197480, 0x1b2120`, …).
- `recomp/CMakeLists.txt` globs now use `CONFIGURE_DEPENDS` (new generated files were not picked up without a reconfigure).

## Open (as of D11)
- CRI middleware: `[EE-TTY] DTX_Create: can't create DTX of server` / `E0100302: SJX_Init can't create DTX`, IOP server `0x90000200` (unhandled, func 2). The runtime has a configurable "DTX compat" layer to investigate.
- Unhandled sid `0x00000001` func 16 (sound-driver state sid in the runtime's table).
- Hot loop at `0x141380` with `st@2B0EC0=1` after the above.
