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

## D12: CRI DTX/SJX/PS2RNA server (sid 0x90000200) — runtime emulation enabled

- `DTX_Init` (EE `0x1392F8`) binds sid `0x90000200` (read from `0x21C414`); `DTX_Create` (`0x138DE8`) calls fn 2 and needs a non-zero remote handle, then the SJX/PS2RNA URPC commands `0x400-0x4FF` follow (`SJX_CREATE` `0x400`, `SJRMT_UNI_CREATE` `0x422`, `PS2RNA_REINIT` `0x40A`, ...).
- PS2Recomp already emulates this protocol (written for Code: Veronica X) once a `PS2DtxCompatLayout` names the sid. `reo_override.cpp` now configures `rpcSid = 0x90000200` with no guest URPC tables, so the runtime's fallback emulation is used. An init-only stub in `reo_hw_bridge` was tried first and removed, because the bridge runs before the runtime emulation and shadowed it.
- Handle range `urpcObjBase/Limit = 0x1E0000-0x1EFF00` (opaque ids, never dereferenced). Without it every SJX/SJRMT create returned handle 1 (5 streams aliased).
- Result: `DTX_Create`, `SJUNI_CreateRmt` and the PS2RNA IOP allocations succeed; **state machine `0x316598` becomes 1 for the first time**.
- Validation: init path only. Audio data flow is not verified.

## D13: runtime HLE pools inside the game heap — FIXED (pending run)

- PS2Recomp keeps its own guest-RAM pools at `0x01F00000-0x01F31000` (RPC packets, zeroed on every RPC; RPC server slots, which also hold the DTX remote handle `0x1F10580`; TLS; boot-mode data). They assumed `kGuestHeapHardLimit = 0x01F00000`.
- Patch 0005 (D5) correctly lets `SetupHeap(-1)` run the user heap up to the main stack, as on PCSX2 (sbrk reaches `0x01FBC000`). From then on the pools overlapped live game heap.
- Fix (runtime, patch 0011): the pools move to the EE kernel region `0x00010000-0x00041000`. A scan of SLUS-20765 for kernel-RAM references finds real use only at `0x74000-0x77000` (libkernel patches copied to `0x80074000/75000/76000`); the other low hits are constants.
- Confirmed by construction (address ranges), not by an observed symptom. The jump to PC `0x1` it was suspected of causing persists (see Open).

## D14: async callback stacks overlapped the main stack — FIXED (by construction)

- Interrupt, alarm and GS-vsync callbacks get 16 KB stacks carved downward from `m_asyncCallbackStackTop = PS2_RAM_SIZE`. The first vblank handler therefore ran at `sp = 0x1FFFFF0`, over `0x1FFC000-0x1FFFFF0`, which is where patch 0005 places the main thread's stack (`0x1FF0000-0x1FFF000`).
- Fix (patch 0011): carve them from `0x00042000-0x00070000` (on hardware, handlers run on the kernel stack in kernel RAM), below the libkernel patch area. Exhaustion is now logged (`[asyncStack] region exhausted`) instead of silently falling back to the top of RAM.

## D15: intermittent host crash (heap corruption) — race on PS2Memory::m_ioRegisters — FIXED (probable)

- Symptom: about half of the natural runs died with an access violation after ~10 s (Application event log: `reo_recomp.exe` RVA `0x2a052e3`). A new crash handler (`reo_bootstrap.cpp`, unhandled-exception filter) prints the fault plus the unwound stack as exe RVAs, which a `/MAP` link resolves. Result: `unordered_map<uint32_t,uint32_t>::operator[]` in `PS2Runtime::run()` (`s_pcHist`, a map only that thread touches), reading `0xFFFFFFFFFFFFFFFF`. So the host heap was being corrupted elsewhere.
- Cause found by review: `PS2Memory::m_ioRegisters` (an `unordered_map`) is mutated without any lock from the guest threads, the interrupt/vsync worker (which by design runs **without** the guest-execution lock) and DMA processing. Concurrent inserts and rehashes corrupt the heap.
- Fix (patch 0011): a recursive mutex in `ps2_memory.cpp` around `read64/write8/write16/writeIORegister/readIORegister/processPendingTransfers`, with no header change, so no full rebuild was needed.
- Evidence: before the fix, 2 of 4 natural runs crashed; after it, 0 of 3 (45 s each), with no deadlock and identical end state. An ASan build of all hand-written code (`-DREO_ASAN=ON`, runtime from `out/build-asan`) reported nothing in 2×60 s. Status: probable; recheck if the crash recurs.

## Tooling fixes in this round
- `tools/smoke_test.ps1`: a single `-Env NAME=VALUE` was unrolled by PowerShell into two strings, so **the variable was never set**. Every single-entry run (e.g. `-Env 'REO_NATURAL=1'`) silently ran the stub-override mode. Fixed with `@(...)`. An apparent timing-dependent "malloc stall" turned out to be this artifact; multi-entry runs were unaffected.
- `REO_ASAN` CMake option (default OFF): instruments only hand-written sources (`/fsanitize=address`, STL annotations disabled to mix with uninstrumented objects). It needs `clang_rt.asan_dynamic-x86_64.dll` next to the exe. Toggling it recompiles about 14 files.
- Runtime syscall guard: any syscall that returns with a changed `$ra`/`$sp` is logged (`[syscall:ra/sp changed]`). None observed so far.


### Also in this round
- `tools/ghidra_fill_gaps.py` re-run: 72 more functions (map 5,658). `0x13A180`, a pointer-called function (ra `0x136FD0`) previously refused by Ghidra, now exists. 6 gaps remain.

## D16: no EE thread-priority scheduling (time-slicing instead) — FIXED

- Evidence: CRI ADX (`ADXPS2 Ver 2.45`, setup `0x12B638`) implements its lock by raising the caller to priority 1 and resuming a priority-8 busy thread (thread 4, `0x12ABA0`). Lower-priority ADX threads (5/6/7 at 16/18/25; main at 24) therefore cannot run inside the lock. The runtime released the guest lock after every dispatched step and every 64–100 loop back-edges, so any woken thread ran inside main's critical section (owner tid at `0x217D74` flipped 1→6→5 while the nest count at `0x210480` interleaved).
- Fix (patch 0012, `ps2_guest_sched.h`): EE kernel semantics on the guest-execution lock. A thread keeps the CPU across steps and yields only when it blocks, is suspended, or a strictly higher-priority thread (or an interrupt/alarm worker) is waiting. Back-edge preemption now fires only in that case.
- `SuspendThread(other)` really stops the target; `ChangeThreadPriority` returns the **previous** priority (ADX stores it at `0x217D70` and restores it on unlock; with `KE_OK` (0) main stayed at priority 1 forever).
- Lock-order fix: every blocking syscall re-took the guest lock while still holding its host mutex (sema/thread/vsync), a deadlock against a running thread needing that mutex. Now `waitReleasingGuest()` drops the mutex first and re-checks the predicate.
- Verified: ADX lock owners now change in clean sequence; the saved priorities are 24/16/18 as ADX expects.

## D17: jump to PC 0x1 — vsync flag registration not one-shot — FIXED (root cause)

- libgraph's wait-vsync (`0x114B40`) calls `SetVSyncFlag(&flag, &count)` on **its own stack frame**, spins until `flag != 0` and returns without unregistering. The runtime kept the registration forever and wrote `1` to that dead stack slot on every vblank.
- Found with a hardware watchpoint (`REO_HW_WATCH`, below) on guest `0x1FFEF90`: the write came from `ps2_syscalls::interruptWorkerMain → writeGuestU32NoThrow`. That slot was `0x1CC260`'s saved `ra` (`0x1AC670`), which became `1`, so its `jr ra` jumped to `0x1`. Earlier hypotheses (D13/D14 layout overlaps, scheduling) were real bugs but not this one.
- Fix (patch 0012): a vsync registration is consumed on delivery. Verified: no jump to `0x1` in 60 s runs.

## D18: interrupt/alarm handlers ran in parallel with guest threads — FIXED

- On hardware a handler runs atomically while the interrupted thread is paused. The runtime ran INTC/DMAC handlers and alarm callbacks lock-free on worker threads, in parallel with guest code, which breaks LIFO lock nesting (e.g. CRI SVM locks).
- Fix (patch 0012): handlers take the guest-execution lock. The scheduler treats waiting workers as more urgent than any guest thread, so a spinning thread yields at its next preemption point (which is what the old lock-free design was protecting).

## D19: diagnostics added this round
- `REO_HW_WATCH=<guest addr>` (`reo_bootstrap.cpp`): x64 debug-register write watchpoint on the host bytes backing a guest word, armed on all threads. It prints each new value plus the writer's host stack as exe RVAs (resolve with a `/MAP` link of the same objects).
- `[hot-ra]` heartbeat line: histogram of the main thread's `$ra` next to the PC histogram (shows callers of hot leaf functions).
- Temporary instrumentation of generated files was used and reverted (byte-identical to generated output).

## D20: 42 real stores nopped by the upstream config ("potential self-modifying code") — FIXED

- `recomp/config/outbreak.toml` (generated by "ElfAnalyzer") replaced 42 instructions with `0x0`. Classified against the ELF: 38 are `sw` to game **data** (none target code); 4 store through pointer registers. Examples: `0x128A04` ADXF temp-buffer pointer (`0x20D238`), `0x12B744` ADX thread-creation priority (`0x217D78`), `0x1003AC` libcdvd helper-thread id.
- Symptom chain: `0x20D238` stayed 0, so `ADXF_GetPtStat` compared address 0 with `"AFS"` and failed with `E0040701 not AFS`, then `E0041303 'ptid'` every frame. Found by watchpoint (no write ever reached `0x20D238`) plus the generated code showing `nop` where Ghidra shows the store.
- Fix: all 42 removed; the affected generated files were regenerated. Result: the three ADX partitions (`NETBIO00-02.DAT`, AFS with 13/10/5 files) load.

## D21: CD access (libcdvd → cdvdfsv) — FIXED

- `PollSema` returned `KE_OK`; libcdvd `sceCdSearchFile` (`0x100838`) proceeds only if `PollSema(id) == id`, so every disc search failed without any RPC (chain: dvCi filelist → cvFs → ADXF stm → `'adxf' is NULL`).
- Bridge now serves cdvdfsv `0x80000593/595/596/597/59A/59C`, with layouts from Play! (`Source/iop/Iop_Cdvdfsv.cpp`). `reo::CDVD` reads raw sectors from `REO_ISO` and resolves real LSNs through ISO9660.
- Kernel return values aligned with Play! `PS2OS.cpp`: `PollSema`/`WaitSema`/`SignalSema` return the semaphore id; `SuspendThread`/`ResumeThread` return the thread id (patches 0013/0014). `ChangeThreadPriority` (old priority), one-shot `SetVSyncFlag` and no time-slicing (D16/D17) are confirmed by the same source.

## D22: DMA completion interrupts / CHCR TAG — FIXED

- The game's graphics packet manager (`0x18CE30`) double-buffers VIF1 packets and frees a buffer in its DMAC handler `0x18D160`. The runtime raised DMAC interrupts only for SIF, so the frame loop waited forever in `0x18D650`.
- Patch 0014: `raiseDmacCompletion(ch)` queues the cause; the interrupt worker runs the handlers atomically (VIF1 at kick, GIF when path 3 completes). On completion `CHCR = (CHCR & ~STR) | (last DMAtag[31:16])`: the handler only releases the buffer when CHCR bit 31 (the last tag's IRQ bit) is set.
- Result: frames cycle (DMA kicks 75 → 400+ per minute).

## D23: VU1 microprogram start address — FIXED; VU1 execution — OPEN

- reo bridge `MSCAL`/`MSCALF` used `imm*8` unmasked (`0x2A00*8 = 0x15000`, outside 16 KB). PCSX2 `vu1ExecMicro`: `TPC = addr & 0x7FF`, `<< 3`. Fixed.
- Programs now start at `0x1000`, then reo's VU1 interpreter jumps to `0xFFFFF510` (out of bounds). Next: compare its branch/jump semantics against PCSX2.

## Diagnostics added
- `REO_STACKDUMP_AT=<s>`: after N seconds, every thread's host stack (exe RVAs). It showed the apparent "hang" was the interrupt worker running VIF1/VU1 work, not a deadlock.

## D24: graphics now run on the upstream PS2Recomp pipeline (VIF1 → VU1 → GIF → GS)

- Research: the PS2Recomp submodule already has `ps2_vif1_interpreter.cpp`, `ps2_vu1.cpp`, `ps2_gif_arbiter.cpp`, `ps2_gs_gpu.cpp` and `ps2_gs_rasterizer.cpp`. reo's bridge ran a second, duplicate VIF1/VU1/GS path, and the window showed that one. reo's VU interpreter decodes lower instructions with the wrong opcode map and immediate bits (checked against PCSX2 `VUops.cpp`: `0x20` B, `0x24` JR, `0x28` IBEQ, imm11 in bits 10:0, VU1 targets `& 0x3FFF`). Upstream's `ps2_vu1.cpp` matches PCSX2.
- reo bridge: `REO_GFX` selects the pipeline (default `upstream`; `bridge` keeps the old path for comparison). In upstream mode the bridge registers no DMA/GS hooks and no framebuffer provider. VU0 `VCALLMS` stays on the bridge.
- Upstream VIF1 `MSCAL`: `addr & 0x7FF` (PCSX2 `vu1ExecMicro`).

## D25: VIF DMAtag upper halves dropped for REF/REFE/REFS — FIXED

- With `CHCR.TTE` the upper 64 bits (two VIFcodes) of **every** VIF DMAtag go to the VIF. The chain flattener added them only for cnt/next/call/ret/end. For texture uploads the `DIRECTHL` in a REF tag was lost and the image payload parsed as VIFcodes (an independent Python VIF parser over `REO_VIF1_DUMP` buffers showed `DIRECTHL 7` = A+D + IMAGE(nloop 4) followed by bare CLUT data).

## D26: GIF IMAGE transfers were not a stream — FIXED

- An IMAGE tag's NLOOP data may arrive in later packets (separate REF tags, later DIRECTs). The GS parsed every packet independently, so `processImageData` ran ~400k times with 0 bytes and uploads were applied to the previous transfer (e.g. 108 KB into the 8x2 CLUT rect). Now the remaining IMAGE byte count carries over to the next packet. Upstream's VIF-side workaround (treating the VIF stream after a short DIRECT as image data) is removed: with D25 the continuation arrives in later DIRECTs.
- Found via heartbeat counters (`path1/2/3`, `gsPkts`, `prims`, `img/bytes`, `px/sc/at`), per-primitive TEX0 logging, and glyph texel sampling (every texel was the same `0x13000000` before the fix).

## D27: heartbeat crash (heap use-after-free in `run()`) — FIXED

- ASan (`REO_ASAN`): use-after-free between `s_pcHist.clear()` and the next `operator[]`, both in `PS2Runtime::run()`. It is the same site as the earlier intermittent AV. The diagnostic histograms are now fixed-size, heap-free tables. No crash in 60-90 s runs since.

## D28: controller input — libpad2 records over dbcman (HLE) — IMPLEMENTED (scripted)

- The game uses libpad2/libdbc, not libpad. `scePad2CreateSocket` (EE `0x180378`) asks dbcman (RPC `0x80001301`) for a socket and hands it an EE buffer of two 0x80-byte records. The IOP refreshes these records and the EE reads the one with the higher sequence word at `+0x7C`. `sceDbcSetWorkAddr` (RPC `0x80001304`) supplies the per-port "connected" words that `sceDbcGetDepNumber` checks.
- dbcman sockets are device-generic. Class 1 is the pad (libpad2). Class 2 is the memory card (libmc2, EE `0x187970`, buffer `0x28D980`), so it must not receive pad records.
- The record format was taken from the disc's own DualShock2 driver `ds2u_s1` (`IOP/MODULES/DRIVE.DAT`, module 3, `FUN_00001170`, imported into Ghidra as `/iop/03_pdman.irx`). In digital mode (SIO id `0x41`) the driver writes:
  - `+1 = 6`, `+2 = 2` (data length), `+3 = 4` (profile length);
  - profile `F9 FF 00 00` (no L3/R3);
  - the raw active-low SIO bytes repacked in button-id order: `d0 = (b0&1) | ((b0&0xF8)>>2) | (b1<<6)`, `d1 = b1>>2`.
  An earlier guess (raw bytes with profile `FF FF 00 00`) delivered input but scrambled the meaning of the buttons.
- Evidence chain: pad struct `0x2B0A10` → action word `0x2B0A38` (mapping table `0x2B0900`, copied from `0x2310D0`) → key struct `[0x2AFFA8]` → per-player `0x324300` → system keys `0x324210/18/28` (`sub_001B0DB0`). The memory-card manager (`sub_001C2940`, state struct `[0x326F10]`, substate handler `FUN_001C2D00` case 3) reads the trigger word: `0x10` confirms, `0x4` moves the cursor to YES and `0x8` moves it back. Readers were found with `REO_HW_WATCH` + `REO_HW_WATCH_RW=1` + `REO_HW_WATCH_AFTER`.
- Observed: `REO_PAD_SCRIPT=21:LEFT,24:CROSS` gives LEFT → `0x4` and CROSS → `0x10`. The manager substate goes 3 → 4 and the boot sequence continues (Sofdec/ADX, ACCESS AVE-TCP and "Play online with SNAP" screens captured).
- Not yet: live keyboard/gamepad input (the same feeder can take it), analog/DualShock2 mode (`0x79`, 18 raw bytes), and libmc2 (no card is reported; there is no memory-card HLE).

## D29: code overlays (BIN/*.DAT) were not recompiled — IN PROGRESS

- After the logos the game loads `BIN\1.DAT` ("demo.bin") to `0x570000` and calls `0x57F1F0`. That address isn't in the function table, so the dispatcher fell back to `ra` and the screen stayed black. Only `0.DAT` (`0x370000`, "submain.bin") existed, as an old PCSX2 dump.
- Nine overlays exist. Each has an `MWo3` header: +4 id, +8 load base, +0xC text size, +0x10 data size, a name at +0x1C, and 0x80 bytes in total.
  - `0.DAT` → `0x370000`.
  - `1/2/3.DAT` → `0x570000` (same address).
  - `4/5/6.DAT` → `0x6E0000`, uncompressed.
  - `8/9.DAT` → `0x810000`.
- Files that start with `02 00` are LZ-compressed and decompressed in place by the game. The format was derived by comparing `0.DAT` with the game-decompressed image in an EE RAM dump: 16-bit control words consumed MSB first; literal halfwords; tokens copying `T>>11` halfwords from `T&0x7FF` halfwords back, where 0 means an extended count in the next halfword and distance 0 ends the stream. `tools/overlay_extract.py` reproduces `0.DAT`'s 64,832 text bytes exactly as they sit in EE RAM.
- Pipeline:
  1. `tools/overlay_extract.py`: image plus an EE ELF wrapper.
  2. Ghidra import (`/ovl/ovl<n>.elf`) and `tools/ghidra_fill_gaps.py --elf/--program`.
  3. `tools/overlay_recomp.py`: `o<n>_` names, generated into `recomp/config/output_ovl/o<n>/`.
  4. PS2Recomp `registerOverlayFunction(base, 'MWo3', 4, id, addr, fn)`: lookups in a slot range use the overlay id resident at `base+4` (patch 0016). Slots can overlap (2.DAT covers `0x570000`–`0x708540`, which includes the `0x6E0000` slot), so a miss continues to the next slot.
- Generated code (about 11,700 files, 237 MB) is not committed. It is regenerated from the user's ISO with the committed maps in `recomp/config/overlay_maps/`: `overlay_extract.py <iso> <dir>`, then `overlay_recomp.py <dir> <ps2_recomp.exe> --maps recomp/config/overlay_maps 0 1 2 3 4 5 6 8 9`.
- `REO_OVL_SKIP=o0,o5` leaves the listed overlays unregistered (diagnostic).
- Observed with only 1.DAT recompiled (plus the old 0.DAT dump):
  - CAPCOM logo (55 s) and content warning (50 s);
  - START → main menu (SINGLE PLAY / NETWORK PLAY / COLLECTION / CHARACTER LOG / OPTIONS / HDD INSTALL) at 68 s;
  - START → SCENARIO submenu at 78 s.
  The menu backgrounds were black.
- With all overlays the game stops at a black screen after the CAPCOM logo. This is not an overlay bug. The old 0.DAT dump lacked `0x37A9B0/0x37AF90/0x37B150`, so the movie start was silently skipped ("Function ... not found"). The new o0 runs it, and the game reaches the MPEG player → D30.

## D30: IPU (MPEG decoder) not emulated — OPEN, current blocker

- Stack dump at 75 s (`REO_STACKDUMP_AT`): a guest thread holds the guest lock in `sub_00145B58` → `0x1458D8` → `0x1453C0`. That is the libmpeg IPU path: it writes `IPU_CMD` and polls `IPU_CMD` bit 63 (busy) / `IPU_CTRL` bit 14. The main thread spins in `sub_0012AA60` waiting for worker flag `0x210484`; the workers wait for the lock.
- PS2Recomp only stores IPU register values (`ps2_memory.cpp` `0x10002000..0x10002030`); nothing decodes. The intro movies and the menu's movie background need a real IPU (BDEC/IDEC/VDEC/FDEC/SETIQ/SETVQ/CSC, IPU0/IPU1 DMA channels 3/4).
- Plan: port an existing open-source IPU implementation behind the IPU registers and DMA channels 3/4, rather than skipping movies (skipping would be a synthetic bypass).

## Milestone-1 checkpoint (observed)

- `REO_SHOT_AT` frame captures (512x448, the frame the runtime presents) at 15/30/58 s show the game's **memory-card check screen**: "memory card (8MB) (for PlayStation(R)2) cannot be found in MEMORY CARD slot 1 ... Start the game without saving? YES/NO" (text, colours and highlight correct). It's the first rendered game screen.

## Open (as of D30)
- IPU / MPEG movies (D30): current blocker after the CAPCOM logo.
- Live keyboard/gamepad input into the libpad2 feeder (D28). `runtime/input` exists, but it only feeds the unused `padman` HLE path.
- Memory card: the game uses libmc2 over dbcman socket class 2 (not `mcserv`); no card is reported. Answering the prompt with YES continues without saving.

## Open (as of D27, superseded)
- Memory card: no `mcserv` HLE. The game reports no card and waits for YES/NO; input or a memory-card HLE is needed to proceed toward the title screen.
- VU1 microprograms: none were started yet (path1 = 0); the next screens with 3D/VU1 rendering will exercise upstream `ps2_vu1.cpp`.

## Open (as of D11, superseded where noted)
- CRI middleware: `[EE-TTY] DTX_Create: can't create DTX of server` / `E0100302: SJX_Init can't create DTX`, IOP server `0x90000200` (unhandled, func 2). The runtime has a configurable "DTX compat" layer to investigate.
- Unhandled sid `0x00000001` func 16 (sound-driver state sid in the runtime's table).
- Hot loop at `0x141380` with `st@2B0EC0=1` after the above.
