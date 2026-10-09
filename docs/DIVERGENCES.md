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
