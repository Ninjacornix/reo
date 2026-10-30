# REO divergences (Milestone 1 log)

**Milestone 1 COMPLETE (2026-10-11):** the user accepted synchronized, clean audio and confirmed menu responsiveness/fades with "Yes, close Milestone 1". Historical checkpoint statuses below are superseded by this acceptance and the final D52 entry.

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

## D30: IPU (MPEG decoder) — IMPLEMENTED; picture output OPEN

- Stack dump at 75 s (`REO_STACKDUMP_AT`): a guest thread holds the guest lock in `sub_00145B58` → `0x1458D8` → `0x1453C0`. That is the libmpeg IPU path: it writes `IPU_CMD` and polls `IPU_CMD` bit 63 (busy) / `IPU_CTRL` bit 14. The main thread spins in `sub_0012AA60` waiting for worker flag `0x210484`; the workers wait for the lock.
- PS2Recomp only stores IPU register values (`ps2_memory.cpp` `0x10002000..0x10002030`); nothing decodes. The intro movies and the menu's movie background need a real IPU (BDEC/IDEC/VDEC/FDEC/SETIQ/SETVQ/CSC, IPU0/IPU1 DMA channels 3/4).
- Commands used by the game's libmpeg (found by scanning the ELF for stores to `0x10002000`):
  - BCLR, FDEC (`0x4…`), VDEC (`0x3…`), SETIQ (`0x50000000/0x58000000`), SETVQ, SETTH;
  - BDEC (`0x2…`, built in `sub_00144A08`), CSC (`0x7…`, including `0x700003FF`).
  - No IDEC or PACK.
- Implemented in PS2Recomp `ps2xRuntime/src/lib/ipu/` (PS2Recomp patch 0017), written from ISO/IEC 13818-2 rather than vendored:
  - an IN FIFO filled lazily from DMA channel 4 (normal and source-chain tags);
  - transactional commands that roll back and retry when input runs dry;
  - an OUT FIFO drained through DMA channel 3, with `D_STAT` and DMAC IRQ on completion;
  - BUSY held while more than 8 quadwords of output are pending;
  - VLC lookup tables (B.1–B.4, B.9–B.15);
  - dequantisation with MPEG-1 oddification or MPEG-2 mismatch control, zigzag or alternate scan, and the linear or non-linear quantiser scale;
  - a double-precision IDCT;
  - BT.601 CSC to RGB32 or RGB16 (with dithering and alpha thresholds).
  - Copying Play!'s IPU source in was blocked by the session's auto-mode policy; its tables served only as a test oracle.
- Verification:
  - Every VLC table is prefix-free with the expected Kraft sum, and all entries match an independent implementation's tables (offline script).
  - `tools/ipu_selftest/run.bat` runs hand-built bitstreams through a fake DMA host, all PASS:
    - BDEC intra DC (Y/Cb/Cr 138/125/133);
    - BDEC non-intra AC (horizontal cosine: 4 4 2 1 −1 −2 −4 −4, rows equal);
    - FDEC peek;
    - VDEC MBAI `011` → `0x00030002` with BP=3;
    - CSC grey → 130/130/130;
    - DMA3/DMA4 completion.
- In-game:
  - libmpeg/Sofdec initialisation (SETIQ ×2, SETVQ, SETTH, BCLR) is accepted.
  - One run decoded 2,600 macroblocks (BDEC/VDEC/FDEC/CSC) without VLC errors.
  - Another reached presentation, but the frames are solid green: the colour conversion received all-zero macroblocks. The BDEC → RAM → CSC data path is still to be checked.

## D31: GS SIGNAL/FINISH events never raised the GS interrupt — FIXED

- Intermittent freeze on the SNAP logo. The main thread spins in `FUN_0018d650` until the frame-busy flag `0x29F704[cur^1]` clears. In its GS path (`FUN_0018d470` case 2) the game unmasks FINISH (`GS_CSR = 2`, `GS_IMR` bit 9 = 0), and its GS interrupt handler clears the flag.
- PS2Recomp set `GS_CSR.FINISH`/`SIGNAL` but never raised INTC line 0, so frames that completed through that path never finished.
- Fix (patch 0017): `ps2_syscalls::raiseIntcInterrupt(cause)`. The interrupt worker latches `INTC_STAT` and runs the INTC handlers. GS FINISH/SIGNAL raise cause 0 unless masked by `GS_IMR` bits 9/8.
- Observed: 3 of 3 runs pass the SNAP screen (it froze intermittently before).

## D32: movie routines merged into one Ghidra function — FIXED (extra unit)

- The game called eight libmpeg per-macroblock routines through the pointer table at `0x22A6B8`: `0x1431D8`, `0x143250`, `0x143470`, `0x143520`, `0x1437D0`, `0x143870`, `0x143AE8`, `0x143BC0`. Ghidra had merged them into `sub_00142FB8`, giving about 3,700 "Function not found" warnings and a black screen.
- `recomp/config/extra_functions.csv` plus `tools/extra_recomp.py` compile them into `recomp/config/output_extra/` (`x_` names, own header), registered after the main table. This avoids regenerating the main output, whose shared header would force a full rebuild. To be folded into the main map at the next full regeneration.
- 2026-10-10: the table holds **16** routines; the other 8 (`0x1432E8`, `0x1433A0`, `0x1435D8`, `0x1436D0`, `0x143920`, `0x143A00`, `0x143C90`, `0x143DB0`, each after a `jr ra`) were still inside the D32 ranges. That caused about 2,500 warnings per run once the movie started. The CSV now lists all 16, and run `mv-a` logs 0 warnings and still reaches the menu. The title movie is still uniform green, so these routines were not the cause.

## D33: Sofdec intro movie stalls (intermittent) — superseded by D34

- Symptom: black screen after the CAPCOM logo; main thread at `0x12AAC0` (server handshake).
- The "busy" decoder (`0xDE6E20` in state 1 with a pending request) and the end-of-playback hypothesis below were consequences of D34, not its cause.
- Original notes: server group 6 (`0x264820`, worker thread 7, `0x12AE50`) runs only the Sofdec decode server `sub_00163E20`, which reported "busy" for millions of passes. The end-of-playback checks are `0x1731A0`/`0x173210`/`0x1732D8`/`0x173330`.

## D34: WakeupThread queued a wakeup for a sleeping+suspended thread instead of releasing it — FIXED

- **Symptom:** black/green screen after the content warning; main at `0x12AAC0` inside CRI's server handshake `FUN_0012aa60`. Before 0019 it reproduced in every clean run (2/2 `base-a`/`base-b`).
- **Mechanism (raw disassembly, not just decompiler output):**
  - The player's seamless start (`0x1625D0` → `0x15F270` → `0x15F2F0` → `FUN_001643b0`) closes the Sofdec decode gate (`0x22DE58+0x24`). It then runs one server-group-6 pass synchronously through `FUN_0012ab38` → `FUN_0012aa60(worker 7, 25)`.
  - `FUN_0012aa60` sets `0x210484 = 1` and raises worker 7 to priority 1. It then loops: `ReferThreadStatus`, then `WakeupThread` if the status is WAIT(4)/WAITSUSPEND(0xC), then `ResumeThread` if the status is SUSPEND(8)/WAITSUSPEND, until `0x210484 == 0`.
  - The worker loop (`0x12AE50`) runs a pass. If `0x210484 == 1` it clears the flag and **sleeps** (`0x12AED8`). Otherwise it loops again without sleeping while the pass reports busy. With the gate closed, the freshly created decoder (state 1, request pending) is always busy.
  - Worker 7 sleeps while suspended (WAITSUSPEND). Our `WakeupThread` released only status WAIT, so for WAITSUSPEND it *queued* a wakeup count. That stale count made the worker's handshake `SleepThread` return immediately. The worker then spun busy at priority 1 and starved main (priority 24), so main never saw the cleared flag.
- **Reference (PCSX2 2.x, same ISO, PINE probe `pcsx2_sfd_probe.py`):**
  - The same decoder address `0xDE6E20` is created with `+0x44=1, +0x48=1`.
  - The pause's pass returns while the decoder is still pending: pass counter `0x22A610` 1647 → 1648, then player state `+0x13C = 2`.
  - The next pass steps the decoder (`+0x44=0, +0x48=2`, counter 1649).
  - The worker does not spin: about one pass per sample.
- **Fix (PS2Recomp patch 0019):** `WakeupThread`/`iWakeupThread` release a sleeper whose status is WAIT *or* WAITSUSPEND; it becomes SUSPEND, as on the EE kernel.
- **Also in 0019 (opt-in, not needed for the checkpoint):** `REO_IMMEDIATE_SWITCH=1` makes WakeupThread, ResumeThread and ChangeThreadPriority hand the CPU to a newly ready thread of strictly higher priority before returning. PS2Tek documents this as "forces a thread reschedule". The A/B run `rs-noswitch` reached the menu without it.
- **Earlier wrong turn:** I first assumed equal-priority starvation under the CRI lock. The heartbeat (`t1=24`) disproved it. The `REO_SPIN_ROTATE` heuristic remains opt-in and should not be used.
- **Diagnostics:**
  - `REO_SFD_DIAG` (Sofdec lifecycle, server pass, decoder step, server sleep/wake);
  - `REO_THREAD_LOG` (priority changes, thread erasures, `[THOP]` wake/resume/suspend/sleep of thread 7);
  - heartbeat `pc5/6/7` (live PC of the CRI threads; `[hot]` samples only the main thread's context).

## D35: DMAC interrupts could not be delivered while an INTC handler busy-waited — FIXED

- SNAP-logo freeze, second cause. The VBLANK handler `FUN_0019f600` → `FUN_001a0350` (frame flip) → `FUN_0018d650` busy-waits for the frame-busy flag `0x29F704`, which the DMAC completion handler clears. The EE takes INTC (INT0) and DMAC (INT1) on separate lines. PS2Recomp's single interrupt worker could not deliver the DMAC interrupt while the VBLANK handler spun.
- Fix (patch 0018): at guest preemption checkpoints on the interrupt worker, pending DMAC interrupts are delivered nested (`serviceNestedDmac`), on a separate handler stack. Using the same stack overwrote the interrupted handler's frame and broke VBLANK wake-ups.
- Observed: no SNAP freeze in 2/2 clean runs plus 6/6 instrumented runs. The memory-card prompt and logos work.

## D36: sound-driver RPC HLE zeroed EE RAM over the game's code — FIXED (Codex session, patch 0020)

- **Symptom:** the title movie rendered as uniform green.
- **Cause:** libmpeg's write-back (`FUN_00142fb8`, store loop at `0x143F28`) clamps 16-bit samples with a constant at `0x143F70` (`0x00FF` lanes). The runtime's sound-driver HLE (`RPC.cpp::checkSoundDriverMemoryUnlocked`) allocated and zeroed its synthetic IOP-side state at `0x120000`–`0x17D000` **in EE RAM**, which wiped that constant (and other game code/data). Every pixel was then clamped to 0, and CSC turns all-zero YCbCr into green.
- **Evidence:**
  - A hardware write watch on `0x143F70` caught the zeroing from `rpcZeroRdram` during sound init (guest PC `0x1179E8`).
  - In PCSX2 (PINE) the constant stays intact and the picture buffers are nonzero.
- **Fix:** sound-driver state and transfers use IOP RAM (`getIOPRAM()`), with bounds and ownership checks. Codex's details are in `HANDOFF_CODEX_M1_VIDEO.md`.
- **Related, in the same patch:**
  - Scratchpad DMA channels 8/9 are implemented (normal and chain mode, completion interrupt); libmpeg uses `toSPR` chains for motion-compensation reference blocks.
  - Tag extraction is corrected for SPR and IPU DMA.
  - IPU BDEC now publishes the coded-block pattern.
- **Possibly related:** the earlier sporadic `ResetEE` calls (from interrupt context, `pc=0x1148d4 ra=0x1a0454`; `ResetEE` has no callers in the binary) appeared while this corruption was live. Recheck now that it is fixed.

## D37: title movie at ~10 fps: software GS ran under the guest CPU lock — IMPROVED (patch 0020)

- **Measurement:** the new `[perf]` heartbeat line gives host ms per 60 vsyncs, movie frames (CSC) and macroblocks (BDEC), each guest thread's CPU hold/wait time, and sprite pixels by kind. Profiling uses `REO_STACKDUMP_AT` with `REO_STACKDUMP_N` and the symbolized link map.
- **Before:**
  - ~10 movie frames/s.
  - The main thread held the CPU ~650–790 ms/s, of which ~3/4 was software GS drawing (`drawSprite` → `writePixel` per pixel), inside a DMA-start store at `0x1033e8`.
  - The Sofdec worker (thread 7, priority 25) waited ~700–800 ms/s for the CPU.
  - GS load: ~14–20 M untextured px/s (clears) plus ~7 M 1:1 textured px/s (movie blit); 6–12 M bilinear 1:1 px/s during the logos.
- **Fix:** `drawSprite` fast paths for frames without blending in PSMCT32/24:
  - untextured fills;
  - FST 1:1 PSMCT32/24 textured sprites, point or bilinear (at 1:1 the bilinear weights are exactly 0).
  Both reproduce `writePixel` exactly (alpha test, AFAIL, FBA, FBMSK). `REO_GS_NO_FASTPATH=1` restores the generic path.
- **Verified:**
  - Five static screens (memory card, logos, notices) are hash-identical with and without the fast path (runs `gs3-fast`/`gs3-slow`).
  - Fast-only frames are clean fade frames.
- **After:**
  - **~17–23 movie frames/s**.
  - Main thread ~310–450 ms/s; decoder ~600 ms/s.
  - The movie is reached at ~43 s host time with `REO_TURBO`, versus ~58 s.
- **Remaining:**
  - Untextured fills still cost a swizzle address per pixel.
  - The decoder needs ~30 ms of CPU per frame (IPU emulation plus libmpeg) and still waits ~450 ms/s.
  - The main thread blocks on GS `m_stateMutex` while holding the guest and IO locks (~8% of samples; likely contention with present).
  - A GS worker thread (MTGS-style) would remove GS work from the guest CPU entirely.
- **Test-only:** `REO_TURBO=<factor>` speeds the vblank clock (boot logos); `REO_TURBO_UNTIL=0x22F18C` returns to normal speed when the Sofdec decoder exists.
- **GS worker thread (patch 0021) — full speed reached.**
  - `GS::processGIFPacket`/`writeRegister` now queue their input; a worker thread replays them in order. Readers (present/latch, store-image readback, framebuffer clears, display queries, reset) first wait for everything queued before them. GS processing only calls `raiseIntcInterrupt`/`GetCurrentVSyncTick`, so these waits cannot deadlock.
  - Main thread's guest-CPU time: ~400 → ~75 ms/s.
  - **Movie: 29.1–29.3 fps average** over the whole playback (steady 30–32 frames per heartbeat). The streams declare 29.97 fps.
  - First movie frame at ~46 s with no fast-forward (was ~58 s).
  - The main menu is reached in all runs (`gt-a`, `gt-b`, `gt-def`, `gst3`); identical frames across runs where the movie phase matched.
  - Default on; `REO_GS_THREAD=0` restores synchronous GS.
- **Also:** DMA completions on channels with no enabled game handler no longer wake the interrupt worker (~25k/s during the movie; the pending bit is still latched for the next tick).

## D38: unknown syscall fell back to $v0 and ran ResetEE — FIXED (patch 0021)

- **Symptom:** `ResetEE` called repeatedly from interrupt context (`pc=0x1148d4`, `ra=0x1a0454`), even though nothing in the binary calls the `ResetEE` stub.
- **Cause:** the VBlank flip code calls `iFlushCache(0)` via the stub at `0x1148d0` (`li v1,-0x68; syscall`). The dispatcher had no case for `-0x68`. It then tried `$v0` (which held 1) and dispatched syscall 1, `ResetEE`. Its HLE is a no-op, so the effect was log noise; any other unknown syscall could have run an arbitrary call the same way.
- **Fix:** `-0x68` maps to `FlushCache`. Any remaining `$v0` fallback is logged (`[syscall] unknown $v1=...`); none seen since.

## D39: ~23 s "freeze" on the Sofdec/ADX logo screen (GS worker backlog) — FIXED (patch 0022)

- **Symptom (user):** the window froze on the Sofdec/ADX logo, then jumped ahead to the menu. In every run one heartbeat took 23–31 s.
- **Cause:** with the GS worker (D37), a GIF DMA "completes" as soon as it is queued. The logo screens draw heavy fades (up to ~144 M untextured and ~76 M alpha-blended pixels per heartbeat), so the game queued ~23 s of drawing ahead. Present drains the queue, so the window waited on a stale frame while the game moved on. Stack samples during the stall: GS worker 100% busy in `drawSprite`/`sampleTexture`/`lookupCLUT`; all game threads idle.
- **Fixes:**
  - **Pacing:** a GS submission waits until the GS has executed everything queued before the previous vblank, so it never lags more than ~1 frame. Real hardware cannot run ahead either.
  - **Fast paths cover alpha blending:** same A/B/C/D/FIX/PABE arithmetic as `writePixel`.
  - **Per-sprite palette cache:** `lookupCLUT` once per index instead of per texel sample, only when the frame cannot overwrite the palette.
  - **Row-band parallel drawing** of sprites of 32k+ pixels on a small worker pool. Bit-identical: one write per pixel, and blending reads only its own destination. Textured sprites go parallel only without texture/frame overlap. `REO_GS_NO_PARALLEL=1` disables it.
- **Verification:** `tools/gs_fastpath_check` draws 4,000 randomized sprites (blend modes, alpha test, FBA, FBMSK, PABE, CT32/24/T8 textures, point/bilinear, 1:1 forward/reverse and scaled, small and up to 600×450). VRAM hash is identical across fast parallel, fast sequential and generic paths.
- **Result:** longest logo-phase heartbeat 23 s → ~2.5 s; the logo screens are still slower than real time (low fps during fades).

## D40: presentation cadence and purple first frame — FIXED (patch 0022)

- **Stutter:** the window loop used raylib's 60 fps limiter and latched whatever the registers and VRAM held when it woke. Against the game's own vblank clock, an image was shown for 1 or 3 window frames about once a second (`[present]` histogram).
- **Fix:** at each vblank the interrupt worker snapshots the display registers (PMODE, SMODE2, DISPFB1/2, DISPLAY1/2, BGCOLOR) and the GS queue position. The window loop presents once per snapshot, drained only up to that point, with raylib's limiter off. This matches hardware scanout.
- **Note:** the title screen's scan-line overlay changes every field (60 Hz) while its movie changes at 30 Hz, so consecutive vblanks legitimately differ (`REO_PRESENT_DUMP_AT=<s>` dumps 4 consecutive presents).
- **Purple first frame:** the placeholder before the first latched frame was `MAGENTA`; it is now black.

## D41: flicker / "dithering" and flashing memory-card text: present showed the buffer being redrawn — FIXED (patch 0023)

- **Symptom (user):** text on the memory-card screen flashed between white and dark; the title flickered.
- **Evidence:** dumps of consecutive presents (`REO_PRESENT_DUMP_AT`) showed the same display buffer (`fbp 112`) with text in one vblank and cleared in the next.
- **Cause:** D40's snapshot was taken at vblank **before** the game's VBLANK handler (`FUN_0019f600` → `FUN_001a0350`) flipped DISPFB. Present therefore showed the old front buffer, which the game had already started clearing and redrawing.
- **Fix:** take the display snapshot right after the VBLANK_START handlers (`ps2GsSnapshotDisplay`). Raw consecutive presents of the memory-card screen are now identical; buffers alternate cleanly at 30 fps.
- **Movie cadence:** ~29–30 frames shown for exactly 2 vblanks per second, ~1 shown for 1, none for 3.
- **Blend deinterlacing:** opt-in only (`REO_DEINTERLACE=1`); it greyed the text.

## D42: dragging/resizing the window froze the picture — FIXED (patch 0023)

- **Cause:** Windows runs a modal loop inside `DispatchMessage` while a window is dragged, so the raylib/GLFW loop stopped presenting. The game itself kept running.
- **Fix:** `Kernel/Host/Win32ModalRender.cpp` subclasses the window procedure. Between `WM_ENTERSIZEMOVE` and `WM_EXITSIZEMOVE` a 10 ms timer draws and swaps the current frame. It deliberately does not call `EndDrawing`, whose event poll would steal the modal loop's mouse messages.
- **Measured:** 310 frames drawn during an 8.6 s modal move (16 ms timer; now 10 ms). The heartbeat's `modalPresents` counts these frames.

## D43: logo fades choppy (GS below real time) — FIXED (patch 0024)

- **Symptom (user):** some logo fade-outs were choppy; the logo phase ran at low fps.
- **Profile:** about half of the GS worker's samples were idle. The busy half was dominated by the **generic scaled sprite path** (bilinear `sampleTexture`/`lerpChannel`, `writePixel`) of zooming and fading logos, which ran on one thread.
- **Fix:** that path also draws large sprites (32k+ px) in row bands on the worker pool. It uses the same no-overlap rule (texture vs. frame and palette vs. frame page ranges), and band threads get a copy of the sprite's palette cache. `tools/gs_fastpath_check` still produces identical VRAM.
- **Result:** every logo-phase heartbeat is now ~1.03–1.05 s (real time; before up to 2.5–3.7 s). Fades show a steady 2-vblank (30 fps) cadence.

## D44: flicker and hitches at menu / video transitions - FIXED (patch 0026)

- **Symptom (user):** brief flicker when switching menus or leaving the movie; slow at the start of a transition (e.g. Circle out of a menu), then normal.
- **Measured** with `REO_PRESENT_LOG=<from>,<to>`: one line per present (snapshot sequence, swap time, tick, buffers, brightness, hash).
- **Causes and fixes:**
  1. **Flash of a half-drawn frame:** upstream's latch replaced an all-black FBP-0 display with a drawing context's frame, i.e. the buffer being drawn during fades. Now opt-in (`REO_BLACK_FRAME_FALLBACK=1`).
  2. **GS pacing slack:** with one frame of slack, a heavy frame made the game thread wait while holding the guest lock, delaying the VBLANK handler. Now two frames.
  3. **Once-per-second hitch from the diagnostics heartbeat:** dozens of unbuffered `std::cerr` writes stalled the present thread ~50 ms (3 snapshots skipped). The heartbeat now writes to a local buffer and outputs once. Redirecting `std::cerr` itself raced with other threads and hung, so it is not used.
  4. **Present jitter:** the present loop polled with 500 µs sleeps, which Windows rounds up, so presents alternated ~10/23 ms. It now waits on a condition variable signalled by each vblank snapshot.
- **Result:** 2,097 of 2,100 presents show exactly one new snapshot; present interval median 17 ms (p10 15, p90 18). No single-frame brightness outliers or wrong-source frames.
- **Remaining:** the slow VBLANK dispatches seen (`[vblank-slow]`) happen during boot loading only.

## D45: CRI DTX mailboxes stalled forever — SifInitRpc re-init wiped the emulated IOP-side DTX server — FIXED (patch 0028)

- **Symptom (blocker for M1 audio):** both DTX mailboxes (ch0 SJX @ EE `0x229d40`, ch1 PS2RNA @ EE `0x223ec0`, 0x880-byte packets) ran only ~8–10 rounds during startup — all with empty packets — then went silent for the rest of the run. No SJX data and no PS2RNA START were ever sent; no CRI errors.
- **Transport reverse-engineered (Ghidra, `/ps2/SLUS_207.65`):**
  - `DTX_Create` `FUN_00138f78` builds 0x44-byte objects in the table at `0x21c430` (8 slots): +0x0C EE work, +0x14 uncached footer address (work+size−0x40 | 0x20000000), +0x18 IOP addr, +0x1C size, +0x20 send-cb, +0x28 recv-cb; the ADXT init (`FUN_0013e2b8`/`FUN_00141280`) installs the real callbacks (SJX fill `0x140fb8`, PS2RNA fill `0x13e000`).
  - The pump `FUN_00139198` (driven by `FUN_00139568` from the CRI main `FUN_00132c08`, twice per pass via `FUN_001389d8`+`FUN_00141268`) waits for the **footer ticket word** (work+size−4, read through the uncached alias) to exceed the local ticket (+0x08) before it recycles a packet, and only sends while word0 byte2 (enabled) is set and gate `0x21c41c` is 1.
  - The clock: the game's vblank handler `FUN_0019f600` → `FUN_001a9040` → `FUN_0012bdb8` wakes CRI threads 5/6 every vblank (thread 5 runs scheduler group 2 = the CRI audio main). Thread 5 sleeps via `SleepThread` between passes; its busy flag is `0x210488`, loop counter `0x2104b0`.
- **Runtime evidence (`REO_PEEK`):** the vblank tick, thread 5, the scheduler and the DTX pump all kept running (pump counter +4/tick), but the objects stuck at word0 = `0x10101` (created + **in-flight** + enabled) with **local ticket == footer ticket** — i.e. the pump had queued the next packet (wrote the footer) but its `sceSifSetDma` never ACKed: no `[DTX_ACK]`, no `[DTX_MISS]`, no failure line.
- **PCSX2 reference (PINE probe of the same globals):** on the real IOP the mailboxes cycle **continuously** — ~2 packets/vblank/channel (~120/s), footer = local+1, for the whole run. The native stall is a divergence, not CRI behavior.
- **Root cause:** `SifInitRpc` (RPC.cpp) called `resetDtxRpcStateUnlocked()` on **every re-init**, wiping `g_dtx_transfer_by_id` (the DTX_CREATE-registered mailboxes) and all SJX/PS2RNA/SJRMT handles. The game re-calls `SifInitRpc` from 12 sites (e.g. file/movie init `FUN_001ab560`, twice) — each call after CRI init killed the transport. Afterwards every mailbox DMA silently no-oped because `noteDtxSifDmaTransfer`'s miss log is suppressed when `knownTransfers == 0`, so the footer ticket never advanced and the pump waited forever. On hardware an EE-side `sceSifInitRpc` re-call only refreshes the EE RPC layer; the IOP-side DTX server objects outlive it, and the guest never re-registers them.
- **Fix (patch `0028-sifinitrpc-keep-dtx-server-state.patch`):** keep the DTX server state across `SifInitRpc` re-inits (log each re-init), and make a wiped table visible — `[DTX_MISS]` now also logs for DTX-shaped transfers (≥0x80 bytes, 64-byte aligned) when the transfer table is empty. The sound-driver state keeps its D36-tested lazy re-init.
- **Result:** `[SifInitRpc] re-init` fires repeatedly and harmlessly; ACKs run to the 32-line cap; tickets advance for the whole run (final footer `0x580c` vs `0x15` before) at the PCSX2 cadence; `DTX_MISS` shows one benign line (the 0x570C0-byte overlay load).
- **Remaining:** every mailbox packet is still **empty** (`REO_DTX_DUMP` produced no non-empty dumps; no `[SJX-cmd]`/`[PS2RNA-cmd]`). The transport is healthy but no audio data enters it: the SFD/game sound layer never queues SJX chunks or starts PS2RNA. Next: compare the SJX uni-stream byte counters (`0x21bc08` table, +0x3C per entry), PS2RNA play-switches (`0x223880`+0x24) and game stream states (`0x20f3c8`+1) against PCSX2 during the title-screen demo video (the user's audio repro: the demo plays with sound on real hardware).

## Milestone-1 checkpoint (observed)

- `REO_SHOT_AT` frame captures (512x448, the frame the runtime presents) at 15/30/58 s show the game's **memory-card check screen**: "memory card (8MB) (for PlayStation(R)2) cannot be found in MEMORY CARD slot 1 ... Start the game without saving? YES/NO" (text, colours and highlight correct). It's the first rendered game screen.

## Milestone-1 checkpoint — main menu reached (2026-10-10)

- **Commit:** this commit (base `3ac9e61`) with PS2Recomp patches 0001–0019. ISO: `Resident Evil - Outbreak (v2.00).iso`, SLUS-20765 (sha256 prefix `69ae2c48e6f01e26`). Windows 11, MSVC 19.43, Ninja Release build.
- **Command:**
  ```
  tools\smoke_test.ps1 -Iso <iso> -Seconds 130 -Label m1-a -Env 'REO_NATURAL=1;REO_PAD_SCRIPT=21:LEFT:0.5,24:CROSS:0.5,85:START:0.3,88:START:0.3,...,112:START:0.3;REO_SHOT_AT=80,100,115,125'
  ```
  The script presses Start every 3 s from 85 s to 112 s. LEFT+CROSS answers the memory-card prompt.

| run | 80 s | 100 s | 115 s | 125 s | main at end |
|---|---|---|---|---|---|
| m1-a | `618d8e04` movie (green) | `2cf69504` **main menu** | `2cf69504` | `2cf69504` | frame loop `0x1033e8` |
| m1-b | `618d8e04` | `2cf69504` **main menu** | `2cf69504` | `2cf69504` | frame loop `0x1033e8` |
| rs-a, rs-b, rs-noswitch | same | same | same | same | same |

- **Main menu frame:** SINGLE PLAY / NETWORK PLAY / COLLECTION / CHARACTER LOG / OPTIONS / HDD INSTALL plus the Capcom copyright lines, over the title movie.
- **With two Start presses only (100 s and 110 s):** 2 of 3 runs reached the menu (`ws-a`, `ws-c`). In the others the presses landed during a title-movie cross-fade; that is input timing, not a hang.
- **Not yet correct:** the title movie shows a uniform green frame (picture buffers never written). Each run logs about 2,500 `Function at address ... not found` warnings for eight mid-function CRI entry points: `0x1432e8`, `0x1433a0`, `0x1435d8`, `0x1436d0`, `0x143920`, `0x143a00`, `0x143c90`, `0x143db0`. They are next to the D32 extra functions and are the first candidates for the movie path.
- **Menu input:** selecting a menu entry has not been tested yet; that is the start of Milestone 2.

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

## D46: PRESS START BUTTON had zero opacity - FIXED (0029)

Overlay 1 0x57FED0 calls guest sine 0x192190 -> 0x18F340 and submits the prompt through 0x5807C0 -> 0x1AB860. Fresh contexts left VF00.w=0, so the math produced zero opacity. Initialize VF00=(0,0,0,1) in fresh contexts. Screenshot 20261011-021422-codex-title-vf00-fix/shot_55.bmp shows the original prompt. Generated sine regression passes for 127 phase values. REO_TITLE_DIAG is read-only and opt-in.

## D47: SJX chunk recycling and missing PCM output - FIXED (0030), audio accepted

SJX_CREATE's fourth argument is the EE registration record. Callback 0x1410C8 dereferences reply field +4 as that record; returning an IOP SJX handle prevented chunk recycling after the initial batch. The EE has already decoded ADX into planar PCM16 at 48 kHz. Stream complete chunks to the host and delay replies until the callback consumes them. SJRMT's 0x100-byte work region describes the separate 0x4000-byte sample buffer. The user confirmed sound; full runs measured continuous host output with zero underruns. General SPU2 banks are outside this streaming fix. Prior empty-packet observations concern the title background, not the attract demo; SJUNI +0x3C is unreliable because of guest counter bookkeeping.

## D48: loud distorted ADX predictor - FIXED (0031), PCM validated and audio accepted

The user's loud/glitchy report reproduces with input PCM saturation despite zero host underruns. Native left RMS was 23,928. Original coefficient routine 0x126510 uses R5900 SQRT.S words 0x46160504 at 0x12652C and 0x460C0004 at 0x1265E8. R5900 reads Ft; the generator read Fs, taking square roots of stale f0 and yielding unstable coefficients 8554/-4465.

Patch 0031 corrects the generator and adds opcode regression coverage. tools/repair_generated_sqrt.py refreshes only stale opcode-matched statements; no shared headers change. The generated coefficient arithmetic passes at 24, 44.1 and 48 kHz. Natural 105-second run 20261011-122151-codex-cri-sqrt-fix passes with zero host underruns. Eight seconds per channel (384,000 samples each) match an independent CRI-compatible decode exactly: zero mismatches; RMS left 4,624.017/right 4,210.887; clipped samples 1/0 (also in reference). No arbitrary gain reduction was used. The user subsequently accepts audio as synchronized and clean after 0033/0034; final menu/presentation acceptance remains.

References: [PCSX2 SQRT_S](https://github.com/PCSX2/pcsx2/blob/master/pcsx2/FPU.cpp), [FFmpeg ADX decoder](https://github.com/FFmpeg/FFmpeg/blob/master/libavcodec/adxdec.c). Include original CRI scale+1 when comparing samples. PCM captures and extracted ADX are ignored and never committed.

## D49: audio underrun recovery and device buffering (0032), completed with D50-D51

A loaded timing test overlapped a build and PCSX2, producing 59,744 missing output frames. Resuming the old PCM left ~1.27 s permanent audio lag. Keep missed source-sample debt, skip late stereo pairs upon refill, count real skipped bytes toward SJX acknowledgements, preserve fractional rates and clear stale debt on pause. Focused checks pass 31/31, including deterministic starvation/recovery and 8 kHz phase. This loaded test does not establish the cause of the user's original small lag.

PRIVATE raylib definitions request two 5 ms Windows device periods; this machine's WASAPI driver clamps to 960 frames / 20 ms, down from 1440 / 30 ms. No shared headers or generated target definitions change. Patch chain 0001..0032 applies and matches source. Isolated 185-second playback completes with zero underruns and skipped samples across both attract demos.

User feedback after that build: audio is now ahead, probably by a fixed offset; the user requests an objective measurement. M1 stays OPEN. Compare timestamped latched presented frames with the original PS2demo03/04.sfd and consumed audio samples; raw decoder +F08/+F0C clock alone cannot establish the displayed frame. REO_CRI_SYNC_LOG records read-only timing evidence. Screenshot timestamps are added to the existing opt-in REO_SHOT_AT path. Assets and analysis output remain ignored.

## D50: measured picture drift; IPU IDCT acceleration (0033), drift removed in measured run

Timestamped presented-frame matching against the original PS2demo03.sfd reveals audio lead growing 368 -> 1333 ms over 16 checkpoints with zero underruns. Native video averages 28.0468 fps versus the source's 29.97. Motion-region correlation >=0.99757 distinguishes reference frames with high confidence. Host-latency estimate is explicitly 20 ms; uncertainty of a few device/frame intervals cannot explain ~1 second drift. Tool: tools/analyze_av_sync.py; ignored report: build-ninja/av-sync-battle-baseline.json.

Patch 0033 vectorizes the IPU IDCT in independent SSE2 double lanes and replaces costly scalar lround calls with exact truncation/fractional tie tests, retaining accumulation order and scalar fallback. Full DC range, MPEG mismatch control, deterministic dense/sparse spectra and rounding-boundary probes pass: 28,192 blocks / 1,804,288 samples exactly equal the prior scalar definition. Transform benchmark improves ~6.44x; original IPU pipeline tests remain passing. Minimal rebuild/relink and chain 0001..0033 validation pass. Identical isolated post-fix run delivers 29.8976 fps with lead 346 -> 384 ms, instead of progressively reaching 1333 ms; correlation >=0.99755. Remaining startup offset is investigated in D51. M1 remains OPEN.

## D51: IPU bit-reader cost held video behind at startup - FIXED (0034), audio accepted

Original PCSX2 displayed-frame versus movie-clock matching measures roughly 83-116 ms battle presentation lag; decoded +F00/+F04 keeps up with the movie clock. This comparison does not measure reference speaker latency. Native 0033 still has approximately 0.38 s audio lead despite stable video rate. Patch 0034 replaces repeated per-bit extraction with a bounded byte window, preserving zero padding, bit order and negative-position fallback. 924,858 boundary comparisons exactly match the prior implementation, and the reader benchmark improves ~3.59x. Existing IPU pipeline/IDCT checks and build/relink pass; patch chain 0001..0034 applies and matches source.

Isolated 105-second run 20261011-131311-codex-av-bitreader-measurement matches 15 battle frames with correlation >=0.99814. Estimated lead drops 187 -> 103 -> 43 -> 13 ms, then remains between -19 and +20.4 ms. Decoded picture time catches up to the original movie clock; no audio delay or guest timing override is added. Report: build-ninja/av-sync-battle-bitreader.json. Longer run 20261011-131710-codex-av-full-cycle passes with zero underruns/skips across 176 logged intervals. Sixteen matched battle checkpoints (correlation >=0.99778) show a startup peak of 231 ms, settling to 11-64 ms after the first four seconds; two hint checkpoints measure 48/60 ms (correlation >=0.99928). Device latency remains an explicit 20 ms estimate, not a speaker recording. The user confirms "Sounds synchronized and clean". Reports: build-ninja/av-sync-battle-full-cycle.json and av-sync-hint-full-cycle.json. All media and reports remain ignored. M1 is now COMPLETE following final presentation/menu acceptance.

## D52: scenario responsiveness and Circle/title dark fade - reference verified

Corrected ordinary input in native run `20261011-132431-codex-scenario-cross-measurement` reaches SCENARIO twice (shots 58/79). Menu/submenu heartbeat intervals remain 998-1002 ms with approximately 30 CSC frames and 60 vblanks per second. There is no measured CPU stall in this run after the IDCT/bit-reader fixes. Cross confirms SINGLE PLAY; Start does not. Pad-script and screenshot clocks have different origins.

Visible PCSX2 evidence: `build-ninja/pcsx2-menu-fade-visible/timeline.jsonl`, `frame_*.png`, `comparison.png`. Foreground ownership is verified for every capture; ordinary WM_KEY input targets only the owned reference window. Read-only PINE samples frontend pointer 0x5D4898, state and timer. Cross at 60 s reaches steady SCENARIO at 60.707 s (state 0x020202). Circle at 65 s reaches steady main menu at 68.531 s (0x050501). Circle at 70 s reaches steady title at 72.767 s (0x030200). Screenshots show the original black transition followed by PRESS START over dark opening frames of the restarted title movie, matching the native sequence.

Original overlay-1 routines 0x57F620 (main menu), 0x5811F0 (scenario submenu) and 0x580110 (title) implement deliberate stop/restart waits of 20/10/20 frames. No additional timing/fade override is justified. Earlier desktop-obscured / PrintWindow-black captures are invalid visual evidence. The owned reference exited and its INI was restored byte-for-byte. Technical comparison is complete. The user accepted menu responsiveness and fades with **"Yes, close Milestone 1"**; M1 is COMPLETE. Subsequent M2 work is recorded below.

## D53: black screen after confirming SCENARIO - initial blocker fixed

M2 baseline `20261011-135128-m2-scenario-baseline` stays black with PC/RA0x588338 consuming almost a full CPU second per second. The overlay sprite function0x588200 was truncated at0x588440 instead of its original0x588478 epilogue. Overlay MWo3 text/data sizes exclude the0x40-byte header; the old ELF wrapper omitted that header from its executable segment. Nine owned images confirm the same header size, and only this mapped function crosses the old executable boundary. Correct the wrapper and narrowly regenerate the original sprite plus the skipped saved-progress poll0x1F73B0, checking original instruction coverage and required continuation registration. No success stub or state jump replaces either function.

Focused original-function checks PASS for packet submission, disabled draw path, RA/SP and saved-register restoration, and progress cold/cached/payload/busy/success/error behavior. Native `20261011-140113-m2-scenario-tail-fix` reaches original scenario, Kevin, difficulty and opening cinematic. The sustained initial black-screen loop is fixed; room loading/gameplay remains unverified. The ordinary-input testing helper reaches scenario selection at21.208s with accelerated boot, preserving guest initialization.

## D54: idle character-select text loss and slow presentation - reproduced, fix under validation

`20261011-140755-m2-character-text-perf-burst` captures190 frames over18.917s (~9.99fps), with header/name/detail losses while Kevin is idle. The original brief selection blink does not explain these losses. A production GS queue regression proves old display registers can be paired with newer VRAM after a later clear. Candidate ordered immutable pixel capture passes that regression, but full-game accelerated boot exposes excessive capture queueing and producer starvation; normal-speed validation also shows audio underruns. The rendering agent is bounding capture/pacing before acceptance. Host perf ticks count presentation iterations; actual guest VBLANK continues about60/sec, so a scheduler rewrite is not justified by that counter.

## D55: missing menu effects and character voices - confirmed missing bank playback

The former SOUND-DRIVER RPC path updated compatibility status but emitted no bank voices. Owned Tsnd/HSYN decompilation establishes actual SE framing, bank-load opcodes4D/4E, reversed SCEI tags, indexed program/sample metadata and a240Hz TQ timer. Captured original HD/BD/TQ banks and requests are available from `20261011-142604-m2-normal-boot-sound-capture`. Generic sequence/voice output is now connected to the existing CriAudio host callback; sample decoding/cache population happens outside the callback. Captured menu and stereo speech probes pass, including callback-size equality. Actual selected-character cue and native output quality remain to validate while rendering pressure is repaired. The accepted M1 CRI stream fix does not cover this path. No character-specific WAV fallback is used. Investigation: docs/M2_AUDIO_INVESTIGATION.md.

## D56: original nonzero memset corruption falsely skips Kevin model loading

PCPYH generated code sourced rs instead of rt. Original memset0x107C68 therefore produced zero aligned blocks for nonzero fill bytes, falsely marking Kevin's model cached. Correct the generator and exactly three original opcode-matched emitted expressions; no shared generated headers change. Original-memset4224-case regression and generator45/45 tests pass. Native `20261011-152531-m2-pcpyh-tile-room-validation` loads the same Kevin skeleton root0x4F8FB0 as PCSX2 and reaches gameplay phase2. The picture remains black because the separate VU interpreter submits malformed graphics packets. This resolves the demonstrated loading traversal stall, not the room-rendering milestone.

D54 updated validation: bounded ordered capture plus drawing-only pacing, identical-CRT conversion and proven nonalias T8/T4 per-sprite tiles produce59.99 host presents/sec and29.63 decoded backdrop frames/sec in the latest stationary Kevin burst, with zero missing glyphs/underruns in120 captures. Generic/parallel/sequential4000-case comparisons remain byte-identical, including TEXCLUT.COV palette/frame feedback. Wider menu/logo checks remain pending.

D55 updated validation: the actual Kevin confirm port12/seq8 request emits both original sample layers; independent captured-packet tests pass active/finished queries and callback-partition equality. Fully isolated character/opening playback has zero measured underruns. An earlier cutscene test overlapped compilation and is invalid as a clean audio control. First-room VU/GS overload currently causes a separate stall and must be fixed before overall quality acceptance.


## D57: original VIF/VU instruction decoding submits false geometry ? corrected, bounded original-stream validation

Original SQI81E4FB7D was decoded as XGKICK, while real XGKICK was decoded as another operation. Upper-I pairs also skipped or executed the wrong lower instruction. Faithful instruction tables, integer-register fields, immediate ordering and TOP/ITOP latches are corrected. Focused VU14/14 and VIF13/13 pass; original combined first256-callback replay emits228 EOP-complete packets/368832bytes, maximum2464bytes, each ending normally. Patches0040/0041 reproduce private runtime changes. Native reaches original phase2 and renders the room. This does not claim full VU pipeline parity. Corrected upstream VIF tests pass individually; the complete old memory suite has a separate detached-GS-worker lifetime defect.

## D58: ADC vertices leave stale primitive history ? corrected

Non-drawing vertices must consume list/strip/fan history even though they suppress rasterization. Former early return retained stale/nonadjacent vertices. Production regression fails all7 supported primitive histories before the fix and passes7/7 after, byte-identical to explicitly assembled valid geometry. Patch0042.

## D59: CTC2 VI2 alias corrupts original trigonometric range reduction ? correction in progress

Generator mistakes integerVI2 for VPU status. General low-VI selector emission is corrected (VI0 immutable, VI1..15 low16-bit writes). Original emitted single sine/cosine expressions18F37C/18F4AC are repaired; exact yaw wrappers3700C0/370100 recovered from owned overlay bytes. Original131086 angle cases pass unchanged0.003 tolerance; generator46/46 passes. Patch0043 plus reproducible original-generated repair tools. Reachable combined sine/cosine18F570 has the same originalPC18F5B0 bug, used by floor probes and world/skeletal transforms; its narrow correction and extended original-function regression are now being integrated.

## D60: triangle STQ interpolation divides perspective coordinates before interpolation ? corrected

Original varying-Q triangles need linearly interpolatedS,T,Q followed by a single divide. Former implementation interpolatedS/Q andT/Q, producing821/821 wrong interior pixels in each of3 cases. Corrected production regression passes all5 cases, preserving constant-Q/FST controls and both winding/sign cases. Patch0044 applies and matches normalized source exactly. No new backface-culling rule is introduced.

## D61: GS pixel depth and destination-alpha tests are absent ? active rendering defect

The former pixel writer stores ZBUF but has no depth read/compare/write, and ignores destination-alpha testing. Native room actors are fragmented with black/missing-looking surfaces. Faithful Z formats, TEST comparisons, ZMSK and alpha-fail write masks are being implemented and checked against original PS2/PCSX2 behavior. Do not treat this source diagnosis as a complete explanation of every black polygon. Native room audio also starves during rendering pressure; long wait signatures vary between runs and require separately correlated host stacks/queue evidence.


D59 update: original combinedsine/cosine18F570 exactPC18F5B0 repaired;131072combined cases/262144lanes pass unchanged tolerance, alongside131086single cases. Low-VI audit accounts for23unique sites; remaining20contexthelper sites lackcurrentexecutionevidence and requireadditional CFC2/VUmemory work ifreached.

D61 implementation update: productiondepth/DATE90/90, ADC7/7, STQ5/5, runtime31/31, immutablecapture and4000-case fast/generic tests all pass. Patch0045reproducesprivatechanges. Initial Z32fixtureaddress wasincorrect and repaired transparently; detailed independent swizzle derivation and alias/overflow coverage are in docs/M2_GS_DEPTH_INVESTIGATION.md. Nativepicture/audio/controlvalidation stillawaitscompleteexecutable rebuild. Fogomission and CT24destination-alpha blend factor are independentlyidentified gaps, withcurrentblack-polygoncausation unproven; do not claim everysurface isfixed.

## D62: successful thread wake returns zero instead of target ID — corrected, native validation pending

Original caller12BF98 clears audio-service pending21049C only when WakeupThread/iWakeupThread returns its target ID. Runtime formerly returned zero on success, leaving that handshake set. Correct only successful WakeupThread return; preserve error codes, suspension, wake counts and scheduling. Actual original-caller/kernel regression is28/34 before and34/34 after; broader runtime31/31 passes. Patch0049. This does not establish that long GS/IRQ backpressure or native audio starvation is resolved. See tools/thread_wakeup_check/README.md and docs/M2_AUDIO_INVESTIGATION.md.

## D63: texture CLAMP modes ignored — corrected, native visual validation pending

Actual room packets request repeat and use coordinates outside the texture range; former sampling always clamped to the edge. Patch0051 implements all four GS modes per tap, including sprite shortcuts. Region modes preserve sequential framebuffer/texture alias feedback. Old-library focused regression fails109/131; corrected and generic paths each pass131/131. Depth90, STQ5, ADC7, immutable scanout and4000-case fast/generic parity remain passing. The native build is linked; remaining dark patches and rendering stalls still require visual and timing evidence.

## D64: reached character ERSQRT instruction missing — corrected, visual causation unproven

Weighted character shader begins01E10003/000002FF, distinct from the static-world program previously captured.256 actual weighted traces execute lowerERSQRT selector7BD at PCs3A8/888 a total2851 times. The former decoder left P unchanged before later MFP use. Patch0056 implements the instruction;18 semantic checks and78 actual float32 ERSQRT/MFP results pass exactly. Both sampled output GIF packets remain byte-identical: point-light coefficients are zero in all161 identified Kevin captures. This corrects reached ISA behavior without establishing a dark-patch or flicker fix.

## D65: transient black room windows and global green flash — investigation open

The user reports black reflected-window frames, a disappearing ceiling lamp and brief whole-screen green tint. A600-frame native burst captures loss of lamp/mirror/ashtray detail in actual immutable CPU publication at102.746930s/tick9985/FBP0, followed by normal content on the same framebuffer. The actor/camera pose is unchanged. Sampled PCSX2 room lighting remains stable. No global-green candidate was captured. Both experimental triangle palette caching and early-depth rejection are disabled in this reproduction. Patch0060 adds matched publication/VRAM/command-history diagnostics; no causal calculation or fix is established yet.

## D66: music stutters during graphics stalls — measured, unresolved

Latest user correction identifies music as the stuttering sound and confirms other sounds are OK; this supersedes the earlier voice/effect attribution. Per-path counters in0059 distinguish stereo CRI starvation from independently continuing bank contributions, but individual asset identity remains unverified. The0062 state-only exemption fails and remains disabled. Normal-speed203549 with0064 safe dispatcher pacing fixes character-selection music: the user confirms it, and12 reports have zero starvation. Gameplay music remains unresolved:44.92% of contained active room CRI frames are missing,56.60% before pause. Main-guest CPU ownership is82.3% before pause; recorded IRQ admission has a161918us median despite handler holds no longer exceeding148us. Integrated0065 safe in-place backedge pacing and0066 VU NOP dispatch optimization have passed their independent controls; changed native validation is underway. Audio gain, clocks and M1 recovery remain unchanged.

210014 update: selection remains clean (456960/456960 frames), while the active room still misses373312/935520 frames,39.904%. Main ownership is64.1%; IRQ admission median113715us/max137663us despite handler holds at most156us. Moving-room copied-publication markers change5.023/s and sampled images4.072/s. The route differs from203549, so this does not isolate a performance gain. Over25.689765 seconds, actual consumed PCM including catchup discard spans25.690000 seconds;479936 samples arrived too late to play. This supports burst lateness over the measured interval. Original ADX producer priority16 and variable chunk-drain semantics are verified; no priority/buffer/gain change is justified.0067 VIF copying and0068 packed VU math pass focused full-output comparisons; changed native assessment remains pending.

Completed normal-speed221700 adds a whole-DMA measurement to D66:64 main-thread
VIF writes at PC1033E8/RA18D57C take median113.34ms (maximum121.98ms).
The63 completely bracketed outer VBlank admission waits overlap these writes
by median99.68%;34 of36 selected late left-channel PCM gaps overlap a recorded
write. Original IRQ/audio servers still run near60 calls/s, so a missing clock
or permanently locked priority does not explain the starvation. Strict active
room intervals miss406784/1118880 requested samples (36.356%). Selection and
separate results-stream intervals remain clean. Safe boundary admission0069
and atomic capture0070 have not solved the long synchronous write. The next
bounded observer aggregates VU time/cycles inside the same write; worker
ownership and exact-code compiled VU blocks are isolated candidates, not fixes
already present in the native build.

## D67: detached shutdown workers access destroyed runtime storage — corrected, native closure validated

Closing193458 during GS backpressure detaches guest workers and ends with an access violation. Patch0061 signals and joins guest/IRQ/alarm/GS/raster workers before clearing registries or freeing storage, with loop/queue cancellation. Root bootstrap diagnostics also become joined and cancellable. Corrected Release runtime builds, five actual normal-return destruction/reinitialization passes succeed,31 runtime checks pass and4000 GS cases preserve full-VRAM parity. Native195738,200325 and201223 close normally with exit0 and activeThreads0, cancelling and joining future diagnostics, without an access violation or detach. This change does not resolve normal-playback rendering or audio stalls.

## D68: post-quit movie never signals completion — repaired and validated on quit route

210014 accepts original inventory/options/YES/quit actions, then remains black after PS2youdead.sfd. The file reader finishes and the owned asset contains its MPEG end marker, but seamless playback requires input EOF notification. Guest movie setup calls resident1627A8, which is absent from generated registration; logged recovery skips that call. Feed mode stays1 instead of transitioning to0 and arming pending EOF. A private entry bridge reproduces the original prologue and15FFC0 validation, then resumes existing generated1627BC code, preserving error and suspension paths. It writes no invented completion flags. Bounded default-off EOF observers are included for the next changed native run; frontend return is not yet proven.

212955 validates the repair: feed0/pending1, original173F28 input EOF, PLAYEND3 and cleared movie object. Shots150/170 show the original YOU DIED results page waiting for ordinary Cross confirmation. The black movie-completion hang is resolved on this route; main-menu return and a separate skipped results-asset entry1D3BC0 remain follow-up work. Room music still misses33.696% of active frames and clean observed image changes stay about4/s. See HANDOFF_CODEX_M2.md for producer timing, observer exclusions and exact reproduction.

Completed221700 validates the remaining return path. A faithful1D3BC0 entry
loads the original results asset before resuming generated1D3C50; corrected
test input waits for settled facing and ordinary message/options/results/card
states. The original interaction message1C appears at102.270s, quit is accepted
at118.370s, results Cross at136.846s, and known card-terminal acknowledgment plus
ordinary LEFT/Cross chooses EXIT. Fresh overlay2/frontend57F1F0 mode1/sub5 is
proved at142.922s; shot150 visibly shows SINGLE PLAY. The250s run exits0 with
activeThreads0. This resolves the observed post-quit black return route;
pickup and a room transition are not proved by this run.

## D69: normal-speed logo fades lose parallel rendering — restored and user accepted

The depth/DATE safety gate0045 disables the former sprite row-parallel path,
and0051 conservatively excludes region CLAMP modes from its texture-page proof.
Reached startup states include depth-writing clears (TEST3200F/30003) and
depth-reading masked-GE T4/T8 textured logo sprites (TEST5000F), with T4 region2/2.
Large sprites therefore use the full serial CPU sampler/writer after the
correctness repairs, reducing native startup publication to16–22/s in most
selected windows. Removing startup turbo does not affect this serial raster cost.

0075/0076 restore opt-in row bands only with complete nonwrapping/disjoint FB/Z
output proof and every CLAMP-resolved texture plus actual CLUT read outside
both outputs. Original sampler order, raw sprite Z, alpha/depth operations,
TLS isolation and joined primitive ordering remain.128 complete4MiB comparisons
pass with435baseline/508candidate assertions and three partial-stop image
oracles in each shared-worker control. The relevant textured draw benchmark
improves3.91–3.94x. Corrected native224923 publishes55–57/s over most9–45s startup
windows, shows the visible main menu at60/80s and closes normally at90s.
On the explicitly requested unchanged-build rerun the user confirms: smooth
normal-speed fade-in/fade-out. tools/play.ps1 now defaults the validated
REO_GS_SPRITE_DEPTH_PARALLEL option to1 while honoring/restoring caller overrides.
This resolves the logo regression; room music, slow simulation and rendering
defects remain distinct open M2 work.

## D70: native memory-card storage and host window shortcuts

File #1 uses libmc2 through DBCMAN, rather than the older MCSERV RPC API. Its
original request worker, semaphore and completion processing remain guest code;
filesystem backends (183290, 184360, 184828, 185280, 1858C8, 185E40, 1860B0,
186230, 186798, 1868C8, 186A88, plus explicit format/unformat) now use bounded
folder-backed PS2 cards. Directory layout, libmc2 error codes and the 56-byte
public / 512-byte internal directory entries were established from the owned
SLUS-20765 ELF. The older MCSERV bridge now implements the PS2SDK wire contract
instead of returning fabricated success. The selected root is passed through
REO_MC0_ROOT and existing default saves remain in place. Raw .ps2 images and save
states are not supported. File #2's libmc2 addresses are not mapped or validated.

The game created BASLUS-20765NETBIO (261320 bytes), icon.sys and both icon files
in an isolated selected card, reported successful saving, and read the entire
system data back after process restart before reaching the main menu. Storage
checks cover persistence, separate cards, capacity, traversal, directory
continuation, read-only handles, rename and preservation before explicit format.
Both games share the same selected launcher card, which is locked while a
session uses it. Upgrades preserve old edition-specific folders as named cards. Backups and readiness use the selected card.

The host window uses Alt+F4/WM_CLOSE for exit; raylib's Escape exit key is disabled.
Ctrl+Enter toggles borderless fullscreen and restores the previous placement.
The input layer reserves Enter until release so this chord cannot press Start.
The current integration patch 0093 carries these runtime window changes without
an ABI change. The earlier focused 0094 is retained in `ps2recomp-history/`.

## Native online networking

With an explicit `REO_COOP_HOST` and native platform mode, SNIOPINT RPC calls use
real Winsock TCP/UDP and the selected server's address. Console-only DNAS setup
is omitted for this native backend; the original openSNAP account challenge and
password verification remain server-controlled. Launcher username selection is
an original account-editor result, not account creation or authentication.

Two original SDK clock readers need advancing native time. The Count getter at
1EA000 reads a 294.912 MHz, wrapping 32-bit counter derived from monotonic host
time; the original SDK conversion and send delays remain intact. The accumulated
seconds reader at 1C8850 otherwise reads a stored-only HBlank MMIO counter that
never advances. Its native adapter returns real elapsed seconds in FPR0,
preserves the original initialization/reset flag and accumulated offset, and
updates the original seconds value. Neither adapter changes completion or
readiness flags. Offline launches retain the original clock readers.

Four isolated native clients completed authentication, room entry, the opening
introduction and timed movement replication in a local loopback test. Packet
delivery and read-only actor snapshots were checked separately. Item sharing,
door transitions, reconnects, LAN/WAN behavior and sustained Internet play are
not established by that test. See [networking](NETWORKING.md) for current setup
and the separately licensed server roster patch.
