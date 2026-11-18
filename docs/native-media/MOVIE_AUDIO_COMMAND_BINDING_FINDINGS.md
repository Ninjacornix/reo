# Movie audio command binding: source findings

Static follow-up to the connected buffering qualification, 2026-11-07.
Owned File #1 ELF SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The ranges below were checked against every owned instruction word. No game,
audio device, movie playback or new audio command implementation was run.

The timing controller's `(component 7, command 8, mode, 0)` call reaches
`177BE0`, which indexes that component's actual interface. In the prepared
standard audio graph, interface `240600` slot 8 contains `166630`. That wrapper
checks property 6 for **nonzero**, then redispatches command 8 to component 3.
The ADX interface `2405A8` slot 8 contains `165E00`. A native binding must preserve
this enabled/absent-component policy; interpreting component 7 itself as the
ADX decoder skips a real dispatch boundary. Interface/graph construction remains
a separate owner obligation; these two table entries do not prove every possible
movie configuration uses this graph.

`165E00` mode 0 clears the residual before attempting temporary unpause. Mode 1
applies temporary pause. Mode 2 checks ADXT readiness, obtains sample frequency,
converts the `176DE8` frame ratio through `15BA80`, adds the prior residual, calls
`133058`, stores the low-word difference, then applies `177E58` to the filter
using the frame quantity and frequency. Other modes return zero. The input to
`165FC8` is the original frame ratio, not the current presentation timestamp.

Requested pause (`165EF0`, child+2C) and temporary pause (`165F40`) differ:
requested unpause is suppressed only when main pause equals exactly 1;
temporary unpause is suppressed only when requested pause equals exactly 1.
Actual `165F88` calls ADXT pause before setting the matching filter pause word.
Values other than 0 and 1 must retain the original raw-word policy.

The original `133058` **does not return a consumed sample position**. Its incoming
second argument is unused. In its paused branch it saves `12C8B0`'s result;
that wrapper reaches `13F158`, which invokes a diagnostic and then explicitly
returns zero. `133058` preserves that saved zero as its result after servicing
and rebasing. Its unpaused branch also returns zero. Consequently, a candidate
must not replace this result with current played/decoded samples or interpret
the incoming argument as a seek request. Runtime overrides and a future native
binding still need their own joined qualification. The existing standalone
serviced-discard implementation supplies a reusable service/rebase operation;
its control-success status is separate from this original zero result.

Next implementation boundary: join the existing owned Session pause/discard
operations and the *same* movie filter owner to this dispatch policy. Qualify
requested/temporary pause, nested buffering, frame steps and partial failures;
then bind video/frame ownership and validate construction, stop/rebuild and
real movie transitions. Stage 3 remains open.

| Start | End (exclusive) | Owned bytes SHA-256 |
| --- | --- | --- |
| `0x177be0` | `0x177c30` | `4f35232db38aa599555f49d0548b7e3268c554c14c21f679fb259bbcf461c6b4` |
| `0x166630` | `0x166688` | `991d8c26d04cf81631d022927b2e0cfe39badc0f761e797e96c053fd06939666` |
| `0x165e00` | `0x165ef0` | `ce30d8633eb7f04977067db01aa751fbceb44d1ca2cc7b895a9ae9fe86ffd10f` |
| `0x165ef0` | `0x165f40` | `3aefe2cbe1442cc68489150b944ad9a7958d6522cc55407250348b6a2727a3ce` |
| `0x165f40` | `0x165f88` | `dda5cd8290f4a254650d36b4cc47de54991ab3c15405013c27d2bc2f11eee5dd` |
| `0x165f88` | `0x165fc8` | `8d14a65d341bb163621d68646a1b2ee66608ac24dbfb035ebcd4aad74437376d` |
| `0x165fc8` | `0x166018` | `cff99f89d024abd650fcd0a12689bee80c290c24039e2897b77cdf35ad7c31e2` |
| `0x133058` | `0x133140` | `22f5c7225560891800811ce9b972475e8255552e0a5505aeb7a81a1735bdbe57` |
| `0x12c8b0` | `0x12c8c8` | `92482965d3a02bffc25d6714c327f80978eac8907fe3bc4cfbf96817e0959063` |
| `0x13f158` | `0x13f180` | `441b4982ffffcdab95293c5046767afdfbc1c2908de47cffcbe06cd8a207a31c` |
