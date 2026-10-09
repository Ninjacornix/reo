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
