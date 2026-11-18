# File #1 game handle admission

The new `native_adxt/handle_profile.h` reader prepares a bounded handle description
for the future guest adapter. It does not install a hook, acquire guest RAM, or
authorize attachment from matching bytes. Its caller must first qualify the
runtime/image incarnation and serialized guest access, then retain native source
ownership through original destruction and slot reuse.

The original constructors and service envelope establish independent domains:

| Record | Base / stride | Capacity | Native binding use |
| --- | --- | --- | --- |
| ADXT handle | `20F3C8 / C4` | 16 | Stable handle and audio service stream index |
| ADXB outer | `217D88 / 9C` | 16 | Decoder service index |
| File descriptor | `21A8C0 / 5C` | **40** | Source descriptor ownership, separately retained |
| RNA group | `223880 / 60` | 16 | RNA service index and opaque route UID at `+20` |
| DTR transfer | `21BC08 / 40` | 32 | One original record per channel |
| Paired stream | `221480 / 18` | Up to 32 configured | DTR destination relationship |

The file descriptor index must not be passed as native `Indices.stream`. The
audio service visits the 16 ADXT records; the file server separately visits its
40 descriptors. This was checked against the complete original file-pool clear,
descriptor initializer and audio service bodies before constructing the binding.

Admission checks active child records, channel agreement, input/output stream
relationships, both channels' DTR source/destination links, paired-stream count,
and the actual opaque IOP route domain. Child pool indices need not match the
ADXT slot. The first stereo profile requires adjacent DTR slots; the eventual
binding must reserve both slots while using the qualified native paired copy.
Separated/interleaved transfer schedules are explicitly unsupported by this
first profile. They are not silently coalesced into a claimed original schedule.

Both compilers pass 210 read-only shape checks over declared RAM, including file
descriptors beyond index 15 and index 39, mono transfer index 31, foreign/stale
children and nonadjacent stereo transfers. Three deliberate faults are detected
on each compiler. Seven complete original intervals are checked word-for-word
against the owned ELF, with exact range/source hashes retained in the receipts.
This is source provenance and declared-layout admission, not execution of the
original constructors or proof that an actual game handle has been admitted.

Actual guest ABI/source/control/callback/reset hooks, summation/service ordering,
stop/destroy fences and live game validation remain required. This reader changes
no launcher or game selection.
