# Private USB keyboard check

`run.bat` builds an isolated C++20 check and exercises two independent private
report files. It does not read or inject the Windows global keyboard.

The original USBKB RPC service is `0x80000211`. The original request/reply ABI is
byte-oriented, unlike the separate SNIOPINT socket service:

| RPC | Request | Response |
| --- | --- | --- |
| 1 | none | capacity byte0, attached count byte1, per-slot flags byte2 onward |
| 2 | slot byte0 | LED byte0, report length byte1 (0xff disconnected), raw HID at+2 |
| 3 | slot byte0 | seven-byte physical location; virtual source returns failure zeros |
| 4 | slot byte0, LED byte1 | echoed LED, complemented on invalid slot |
| 5 | slot byte0, automatic lock-LED mode byte1 | echoed mode, complemented on failure |
| 6 | slot byte0 | clears this source's report queue |

Original EE calls use 16-byte requests; reply sizes are 0x90 for enumeration,
0x50 for read, 16 for other commands. Only a validated configured private source
attaches slot0. Empty reads report length0; one poll consumes at most one complete
eight-byte USB boot report. Original EE key translation and repeat remain intact.

Private source format, little endian: u32 magic `0x52454F4B`, u32 sequence,
u32 report count, then `count * 8` raw HID bytes. Maximum512 reports and exact file
length are enforced. Publish through atomic replacement. Each key needs down and
release reports. The service writes `<source>.ack` as a text sequence number only
after the full batch has been consumed (or explicitly cleared through original
RPC6). Initial sequence0/count0 is acknowledged when attached.

Writers must wait for the acknowledgement of the previous sequence before replacing
it. A premature new sequence is held until the existing queue drains. It never
replaces an unconsumed release or repeats an acknowledged sequence. The service is
owned by one game instance; use distinct files for each player's process.

Original modifier-edge contract: EE libusbkb completion `0x1D5A88` compares the
incoming modifier byte with its cached modifier at `0x34284C`. A change is emitted
as state-only/key-zero, suppressing keys in that same report. The frontend reads
that result through `0x1D4F90`, captures modifiers/key in `0x5C5F50`, and checks
Shift with the standard `0x22` mask in `0x5C68B0`; changing the modifier bit would
be incorrect. A simultaneous Shift+letter then neutral pair therefore loses the
letter. The harness supplies four reports for shifted characters: Shift-only,
Shift+key, Shift-only key release, then neutral modifier release. Unshifted keys
retain their down/up pair. The provider preserves all reports without merging
modifier transitions or altering original EE translation. Tests cover this order
and acknowledgement only after the final modifier release; Python regressions
reproduce the old `CoopTest` → `oopest` loss and preserve mixed case afterward.
