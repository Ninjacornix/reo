# Owned raw common sine helper and lobby completion callbacks

Static File #1 US review, 2026-11-05. Five complete catalogue intervals were
decoded directly from the owned overlay files. Their generated C++ remains
absent; the links below deliberately point to the real catalogue. This adds
role evidence without inventing source files or repairing the runtime.
All 118 original instruction words were read, including branch delay slots.
No game, network, build, process attachment or executable operation occurred.

Owned o0 SHA-256: `bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2`,
base `370000`, runtime overlay ID 1. Owned o3 SHA-256:
`5d23ef8bf97c107421f4bcf8589cf8941f3305ae5f6715573ed68837b9511dfb`,
base `570000`, runtime overlay ID 4. Addresses below are hexadecimal.

| Guest entry / catalogue | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o0 0x370080](../recomp/config/overlay_maps/ovl0.csv) | `sine_of_unsigned_byte_times_pi_over_four_candidate` | Confirmed complete raw body and scale; inherited sine approximation | Masks a0 to FF, converts to float, multiplies original float38B298, tailjumps192190 in multiplication delay slot. Owned scale bytes DB0F493F =0.7853981852531433, approximately pi/4. The negative conversion branch is unreachable after masking; it remains in the original bytes. Preserves caller RA and SP; downstream192190/18F340 retains original VU approximation, not a host-sin equivalence claim. No input clamp to7. |
| [o3 0x57A6A0](../recomp/config/overlay_maps/ovl3.csv) | `complete_lobby_stage_twelve_for_zero_or_minus_one_result_unless_mode_six` | Confirmed complete raw callback and connected registration | Copies all12 input bytes to stack through three FP load/store pairs before admission. If signed mode6D8DB0!=6 AND unsigned marker6D91DB==C AND signed first copied byte is0 or-1, clears6D91DB and6D8DC0, increments signed6D8DBF and stores low8 bits. Other results leave globals. Callback passed by5789C0 to584C50; exact remote result enum remains unknown. No normalized integer return. |
| [o3 0x57A730](../recomp/config/overlay_maps/ovl3.csv) | `latch_lobby_member_event_for_local_flag_and_modes_four_eleven_thirteen` | Confirmed complete raw callback and shared latch consumer | If signed8AA2B3==0, sets6D9201=1 only for signed mode6D8DB0==B orD. If flag nonzero, sets it only for mode4. Other cases preserve latch. No input-record read and no text decoding or transport send. Shared57ACF0 tests latch before admitting its distinct event; exact event enum remains unknown. |
| [o3 0x57B690](../recomp/config/overlay_maps/ovl3.csv) | `advance_lobby_text_stage_on_zero_result_or_select_stage_seven_unless_mode_six` | Confirmed complete raw callback and connected registration | Copies12 input bytes before mode check. Mode6 returns. Otherwise signed result byte0==0 increments signed6D8DBF modulo stored byte; every nonzero result sets6D8DBF=7. Does not clear6D8DC0 here. Callback passed by578800 to584E00; zero-result semantics are not assumed to prove network success. No normalized integer return. |
| [o3 0x585930](../recomp/config/overlay_maps/ovl3.csv) | `publish_leave_room_completion_one_for_zero_result_else_two` | Confirmed complete raw callback and connected controller | Copies12 input bytes to stack; signed first byte0==0 writes1 to645066, all other values write2. No mode gate. Connected585980 passes this callback to587C50 and587330, then consumes shared marker at controller+22. No room cleanup, serialization or transport operation occurs in this callback. No normalized integer return. |

The byte helper narrows the previously unknown `370080(E & 7)` calls in
[effect coefficient oscillation](SYMBOLS_MOTION_TIME_REMAP_AND_TRANSIENT_STYLE_CURVES.md):
those callers supply an eight-phase sine input. Its general contract still
accepts all 256 low-byte values. This is static behavior, not a measured effect,
speed change or runtime frequency finding.

The callback links resolve source gaps in [member callbacks](SYMBOLS_O3_MEMBER_CALLBACKS.md),
[lobby connection controllers](SYMBOLS_O3_LOBBY_CONNECTION.md) and
[transport completion](SYMBOLS_O3_TRANSPORT_REQUESTS.md).
The input copy reads all12 bytes even when mode6 suppresses later writes.
Do not replace that contract with an assumed one-byte pointer without a
separate admission review. Signed byte loads and low-byte stores are explicit;
neither an enum label nor a working online service is established.

The full owned-word listing follows. `beq zero,zero` is an unconditional branch;
the next instruction executes in its delay slot. FP load/store pairs copy
record bits without arithmetic. Each digest covers the complete original
catalogue interval. Source-less coverage remains recorded as source-less.

### o0 00370080..003700C0

64 bytes; SHA-256 `e164e7b9effb6b38a96e9a0c4a1eb637bd3bccd8979180117e3b5fe88e4414a4`.

```text
00370080: 308200FF andi $v0,$a0,0xff
00370084: 04400004 bltz $v0,0x370098
00370088: 00021842 srl $v1,$v0,1
0037008C: 44820000 mtc1 $v0,$f0
00370090: 10000007 beq $zero,$zero,0x3700b0
00370094: 46800060 cvt.s.w $f1,$f0
00370098: 30420001 andi $v0,$v0,0x1
0037009C: 00621825 or $v1,$v1,$v0
003700A0: 44830000 mtc1 $v1,$f0
003700A4: 00000000 nop
003700A8: 46800060 cvt.s.w $f1,$f0
003700AC: 46010840 add.s $f1,$f1,$f1
003700B0: 3C010039 lui $at,0x39
003700B4: C420B298 lwc1 $f0,-0x4d68($at)
003700B8: 08064864 j 0x192190 
003700BC: 46010302 mul.s $f12,$f0,$f1
```

### o3 0057A6A0..0057A724

132 bytes; SHA-256 `5df4f9acba464611e84b4f6bb226b0d67a938feb7a18fbd4c1317fbed5632f14`.

```text
0057A6A0: C4820000 lwc1 $f2,0x0($a0)
0057A6A4: 27BDFFF0 addiu $sp,$sp,-0x10
0057A6A8: C4810004 lwc1 $f1,0x4($a0)
0057A6AC: 27A50000 addiu $a1,$sp,0x0
0057A6B0: C4800008 lwc1 $f0,0x8($a0)
0057A6B4: 3C01006E lui $at,0x6e
0057A6B8: 24030006 addiu $v1,$zero,0x6
0057A6BC: E4A20000 swc1 $f2,0x0($a1)
0057A6C0: E4A10004 swc1 $f1,0x4($a1)
0057A6C4: E4A00008 swc1 $f0,0x8($a1)
0057A6C8: 80248DB0 lb $a0,-0x7250($at)
0057A6CC: 10830013 beq $a0,$v1,0x57a71c
0057A6D0: 3C01006E lui $at,0x6e
0057A6D4: 2403000C addiu $v1,$zero,0xc
0057A6D8: 902491DB lbu $a0,-0x6e25($at)
0057A6DC: 1483000F bne $a0,$v1,0x57a71c
0057A6E0: 00000000 nop
0057A6E4: 83A40000 lb $a0,0x0($sp)
0057A6E8: 10800004 beq $a0,$zero,0x57a6fc
0057A6EC: 3C01006E lui $at,0x6e
0057A6F0: 2403FFFF addiu $v1,$zero,-0x1
0057A6F4: 14830009 bne $a0,$v1,0x57a71c
0057A6F8: 00000000 nop
0057A6FC: A02091DB sb $zero,-0x6e25($at)
0057A700: 3C01006E lui $at,0x6e
0057A704: A0208DC0 sb $zero,-0x7240($at)
0057A708: 3C01006E lui $at,0x6e
0057A70C: 80238DBF lb $v1,-0x7241($at)
0057A710: 24630001 addiu $v1,$v1,0x1
0057A714: 3C01006E lui $at,0x6e
0057A718: A0238DBF sb $v1,-0x7241($at)
0057A71C: 03E00008 jr $ra
0057A720: 27BD0010 addiu $sp,$sp,0x10
```

### o3 0057A730..0057A790

96 bytes; SHA-256 `5070df71dde605e23dea83302e2b8fef188ad8e20e4d60129cee120978a2fc50`.

```text
0057A730: 3C01008B lui $at,0x8b
0057A734: 8023A2B3 lb $v1,-0x5d4d($at)
0057A738: 1460000D bne $v1,$zero,0x57a770
0057A73C: 3C01006E lui $at,0x6e
0057A740: 3C01006E lui $at,0x6e
0057A744: 2403000B addiu $v1,$zero,0xb
0057A748: 80248DB0 lb $a0,-0x7250($at)
0057A74C: 10830005 beq $a0,$v1,0x57a764
0057A750: 24030001 addiu $v1,$zero,0x1
0057A754: 2403000D addiu $v1,$zero,0xd
0057A758: 1483000B bne $a0,$v1,0x57a788
0057A75C: 00000000 nop
0057A760: 24030001 addiu $v1,$zero,0x1
0057A764: 3C01006E lui $at,0x6e
0057A768: 10000007 beq $zero,$zero,0x57a788
0057A76C: A0239201 sb $v1,-0x6dff($at)
0057A770: 24030004 addiu $v1,$zero,0x4
0057A774: 80248DB0 lb $a0,-0x7250($at)
0057A778: 14830003 bne $a0,$v1,0x57a788
0057A77C: 24030001 addiu $v1,$zero,0x1
0057A780: 3C01006E lui $at,0x6e
0057A784: A0239201 sb $v1,-0x6dff($at)
0057A788: 03E00008 jr $ra
0057A78C: 00000000 nop
```

### o3 0057B690..0057B6F8

104 bytes; SHA-256 `9b6bd3e608f5e85f7b58c20286768325f35d0f445384df8d1b2e4bad87bf8bce`.

```text
0057B690: C4820000 lwc1 $f2,0x0($a0)
0057B694: 27BDFFF0 addiu $sp,$sp,-0x10
0057B698: C4810004 lwc1 $f1,0x4($a0)
0057B69C: 27A50000 addiu $a1,$sp,0x0
0057B6A0: C4800008 lwc1 $f0,0x8($a0)
0057B6A4: 3C01006E lui $at,0x6e
0057B6A8: 24030006 addiu $v1,$zero,0x6
0057B6AC: E4A20000 swc1 $f2,0x0($a1)
0057B6B0: E4A10004 swc1 $f1,0x4($a1)
0057B6B4: E4A00008 swc1 $f0,0x8($a1)
0057B6B8: 80248DB0 lb $a0,-0x7250($at)
0057B6BC: 1083000C beq $a0,$v1,0x57b6f0
0057B6C0: 00000000 nop
0057B6C4: 83A30000 lb $v1,0x0($sp)
0057B6C8: 14600007 bne $v1,$zero,0x57b6e8
0057B6CC: 24030007 addiu $v1,$zero,0x7
0057B6D0: 3C01006E lui $at,0x6e
0057B6D4: 80238DBF lb $v1,-0x7241($at)
0057B6D8: 24630001 addiu $v1,$v1,0x1
0057B6DC: 3C01006E lui $at,0x6e
0057B6E0: 10000003 beq $zero,$zero,0x57b6f0
0057B6E4: A0238DBF sb $v1,-0x7241($at)
0057B6E8: 3C01006E lui $at,0x6e
0057B6EC: A0238DBF sb $v1,-0x7241($at)
0057B6F0: 03E00008 jr $ra
0057B6F4: 27BD0010 addiu $sp,$sp,0x10
```

### o3 00585930..0058597C

76 bytes; SHA-256 `60ebd97c6cc3f46fcbdec5d499678b9c8bee2080d5694a0461690c883cb9542b`.

```text
00585930: C4820000 lwc1 $f2,0x0($a0)
00585934: 27BDFFF0 addiu $sp,$sp,-0x10
00585938: C4810004 lwc1 $f1,0x4($a0)
0058593C: 27A30000 addiu $v1,$sp,0x0
00585940: C4800008 lwc1 $f0,0x8($a0)
00585944: E4620000 swc1 $f2,0x0($v1)
00585948: E4610004 swc1 $f1,0x4($v1)
0058594C: E4600008 swc1 $f0,0x8($v1)
00585950: 83A30000 lb $v1,0x0($sp)
00585954: 14600005 bne $v1,$zero,0x58596c
00585958: 24030002 addiu $v1,$zero,0x2
0058595C: 24030001 addiu $v1,$zero,0x1
00585960: 3C010064 lui $at,0x64
00585964: 10000003 beq $zero,$zero,0x585974
00585968: A0235066 sb $v1,0x5066($at)
0058596C: 3C010064 lui $at,0x64
00585970: A0235066 sb $v1,0x5066($at)
00585974: 03E00008 jr $ra
00585978: 27BD0010 addiu $sp,$sp,0x10
```
