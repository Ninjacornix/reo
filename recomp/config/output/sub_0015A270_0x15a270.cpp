#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015A270
// Address: 0x15a270 - 0x15a860
void sub_0015A270_0x15a270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015A270_0x15a270");
#endif

    switch (ctx->pc) {
        case 0x15a2b8u: goto label_15a2b8;
        case 0x15a718u: goto label_15a718;
        case 0x15a758u: goto label_15a758;
        case 0x15a810u: goto label_15a810;
        case 0x15a828u: goto label_15a828;
        case 0x15a840u: goto label_15a840;
        default: break;
    }

    ctx->pc = 0x15a270u;

    // 0x15a270: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15a270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15a274: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x15a274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15a278: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15a278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15a27c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15a27cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a280: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15a280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15a284: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15a284u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a288: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15a288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15a28c: 0x26120348  addiu       $s2, $s0, 0x348
    ctx->pc = 0x15a28cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 840));
    // 0x15a290: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x15a290u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x15a294: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x15a294u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x15a298: 0xae020384  sw          $v0, 0x384($s0)
    ctx->pc = 0x15a298u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 900), GPR_U32(ctx, 2));
    // 0x15a29c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15a29cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15a2a0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15a2a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15a2a4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15a2a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a2a8: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x15a2a8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x15a2ac: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x15a2acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15a2b0: 0x40f809  jalr        $v0
    ctx->pc = 0x15A2B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A2B8u);
        ctx->pc = 0x15A2B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A2B0u;
            // 0x15a2b4: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A2B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A2B8u: goto label_15a2b8;
            case 0x15A350u: goto label_15a350;
            case 0x15A3C8u: goto label_15a3c8;
            case 0x15A3D4u: goto label_15a3d4;
            case 0x15A410u: goto label_15a410;
            case 0x15A420u: goto label_15a420;
            case 0x15A450u: goto label_15a450;
            case 0x15A454u: goto label_15a454;
            case 0x15A490u: goto label_15a490;
            case 0x15A498u: goto label_15a498;
            case 0x15A4D0u: goto label_15a4d0;
            case 0x15A4DCu: goto label_15a4dc;
            case 0x15A518u: goto label_15a518;
            case 0x15A528u: goto label_15a528;
            case 0x15A598u: goto label_15a598;
            case 0x15A5A0u: goto label_15a5a0;
            case 0x15A5D0u: goto label_15a5d0;
            case 0x15A5D4u: goto label_15a5d4;
            case 0x15A610u: goto label_15a610;
            case 0x15A618u: goto label_15a618;
            case 0x15A63Cu: goto label_15a63c;
            case 0x15A6A0u: goto label_15a6a0;
            case 0x15A6A8u: goto label_15a6a8;
            case 0x15A6D8u: goto label_15a6d8;
            case 0x15A6DCu: goto label_15a6dc;
            case 0x15A718u: goto label_15a718;
            case 0x15A720u: goto label_15a720;
            case 0x15A728u: goto label_15a728;
            case 0x15A74Cu: goto label_15a74c;
            case 0x15A758u: goto label_15a758;
            case 0x15A7A4u: goto label_15a7a4;
            case 0x15A7C8u: goto label_15a7c8;
            case 0x15A7E0u: goto label_15a7e0;
            case 0x15A810u: goto label_15a810;
            case 0x15A828u: goto label_15a828;
            case 0x15A840u: goto label_15a840;
            case 0x15A844u: goto label_15a844;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A2B8u; }
            if (ctx->pc != 0x15A2B8u) { return; }
        }
        }
    }
    ctx->pc = 0x15A2B8u;
label_15a2b8:
    // 0x15a2b8: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x15a2b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x15a2bc: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x15a2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x15a2c0: 0x260901d0  addiu       $t1, $s0, 0x1D0
    ctx->pc = 0x15a2c0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 464));
    // 0x15a2c4: 0x624024  and         $t0, $v1, $v0
    ctx->pc = 0x15a2c4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x15a2c8: 0x681823  subu        $v1, $v1, $t0
    ctx->pc = 0x15a2c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x15a2cc: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x15a2ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x15a2d0: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a2d0u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a2d4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a2d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a2d8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a2d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a2dc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a2dcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a2e0: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a2e0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a2e4: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x15a2e4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a2e8: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a2e8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a2ec: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a2ecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a2f0: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a2f0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a2f4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a2f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a2f8: 0x328c0  sll         $a1, $v1, 3
    ctx->pc = 0x15a2f8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x15a2fc: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x15a2fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x15a300: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a300u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a304: 0x28a30020  slti        $v1, $a1, 0x20
    ctx->pc = 0x15a304u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15a308: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a308u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a30c: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x15A30Cu;
    {
        const bool branch_taken_0x15a30c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A30Cu;
            // 0x15a310: 0x25080001  addiu       $t0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a30c) {
            ctx->pc = 0x15A350u;
            goto label_15a350;
        }
    }
    ctx->pc = 0x15A314u;
    // 0x15a314: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a314u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a318: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a318u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a31c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a31cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a320: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a320u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a324: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a324u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a328: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a328u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a32c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a32cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a330: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a330u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a334: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a334u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a338: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a338u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a33c: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a33cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a340: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x15a340u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x15a344: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a344u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a348: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a348u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a34c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a34cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
label_15a350:
    // 0x15a350: 0xa61804  sllv        $v1, $a2, $a1
    ctx->pc = 0x15a350u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x15a354: 0x38a20000  xori        $v0, $a1, 0x0
    ctx->pc = 0x15a354u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)0);
    // 0x15a358: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a358u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a35c: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a35cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a360: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a360u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a364: 0x62380b  movn        $a3, $v1, $v0
    ctx->pc = 0x15a364u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 3));
    // 0x15a368: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a368u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a36c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a36cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a370: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a370u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a374: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a374u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a378: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a378u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a37c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a37cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a380: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a380u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a384: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a384u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a388: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a388u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a38c: 0x28a40016  slti        $a0, $a1, 0x16
    ctx->pc = 0x15a38cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)22) ? 1 : 0);
    // 0x15a390: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a390u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a394: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a394u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a398: 0x1480001d  bnez        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x15A398u;
    {
        const bool branch_taken_0x15a398 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A39Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A398u;
            // 0x15a39c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a398) {
            ctx->pc = 0x15A410u;
            goto label_15a410;
        }
    }
    ctx->pc = 0x15A3A0u;
    // 0x15a3a0: 0x24a5ffea  addiu       $a1, $a1, -0x16
    ctx->pc = 0x15a3a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967274));
    // 0x15a3a4: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15A3A4u;
    {
        const bool branch_taken_0x15a3a4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A3A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A3A4u;
            // 0x15a3a8: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a3a4) {
            ctx->pc = 0x15A3C8u;
            goto label_15a3c8;
        }
    }
    ctx->pc = 0x15A3ACu;
    // 0x15a3ac: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x15a3acu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15a3b0: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x15a3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x15a3b4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15a3b4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x15a3b8: 0x71d82  srl         $v1, $a3, 22
    ctx->pc = 0x15a3b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), 22));
    // 0x15a3bc: 0xa63804  sllv        $a3, $a2, $a1
    ctx->pc = 0x15a3bcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x15a3c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15A3C0u;
    {
        const bool branch_taken_0x15a3c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A3C0u;
            // 0x15a3c4: 0xad230014  sw          $v1, 0x14($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a3c0) {
            ctx->pc = 0x15A3D4u;
            goto label_15a3d4;
        }
    }
    ctx->pc = 0x15A3C8u;
label_15a3c8:
    // 0x15a3c8: 0x71582  srl         $v0, $a3, 22
    ctx->pc = 0x15a3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 22));
    // 0x15a3cc: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a3ccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a3d0: 0xad220014  sw          $v0, 0x14($t1)
    ctx->pc = 0x15a3d0u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 20), GPR_U32(ctx, 2));
label_15a3d4:
    // 0x15a3d4: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a3d4u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a3d8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a3d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a3dc: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a3dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a3e0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a3e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a3e4: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a3e4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a3e8: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a3e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a3ec: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a3ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a3f0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a3f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a3f4: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a3f4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a3f8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a3f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a3fc: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a3fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a400: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a400u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a404: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a404u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a408: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15A408u;
    {
        const bool branch_taken_0x15a408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A40Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A408u;
            // 0x15a40c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a408) {
            ctx->pc = 0x15A420u;
            goto label_15a420;
        }
    }
    ctx->pc = 0x15A410u;
label_15a410:
    // 0x15a410: 0x71582  srl         $v0, $a3, 22
    ctx->pc = 0x15a410u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 22));
    // 0x15a414: 0x73a80  sll         $a3, $a3, 10
    ctx->pc = 0x15a414u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 10));
    // 0x15a418: 0xad220014  sw          $v0, 0x14($t1)
    ctx->pc = 0x15a418u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 20), GPR_U32(ctx, 2));
    // 0x15a41c: 0x24a5000a  addiu       $a1, $a1, 0xA
    ctx->pc = 0x15a41cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10));
label_15a420:
    // 0x15a420: 0x28a2001d  slti        $v0, $a1, 0x1D
    ctx->pc = 0x15a420u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x15a424: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x15A424u;
    {
        const bool branch_taken_0x15a424 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A424u;
            // 0x15a428: 0x72742  srl         $a0, $a3, 29 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a424) {
            ctx->pc = 0x15A490u;
            goto label_15a490;
        }
    }
    ctx->pc = 0x15A42Cu;
    // 0x15a42c: 0x24a5ffe3  addiu       $a1, $a1, -0x1D
    ctx->pc = 0x15a42cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967267));
    // 0x15a430: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15A430u;
    {
        const bool branch_taken_0x15a430 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A430u;
            // 0x15a434: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a430) {
            ctx->pc = 0x15A450u;
            goto label_15a450;
        }
    }
    ctx->pc = 0x15A438u;
    // 0x15a438: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x15a438u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15a43c: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x15a43cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x15a440: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15a440u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x15a444: 0x72742  srl         $a0, $a3, 29
    ctx->pc = 0x15a444u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 29));
    // 0x15a448: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x15A448u;
    {
        const bool branch_taken_0x15a448 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A44Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A448u;
            // 0x15a44c: 0xa63804  sllv        $a3, $a2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a448) {
            ctx->pc = 0x15A454u;
            goto label_15a454;
        }
    }
    ctx->pc = 0x15A450u;
label_15a450:
    // 0x15a450: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a450u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_15a454:
    // 0x15a454: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a454u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a458: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a458u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a45c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a45cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a460: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a460u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a464: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a464u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a468: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a468u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a46c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a46cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a470: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a470u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a474: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a474u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a478: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a478u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a47c: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a47cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a480: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a480u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a484: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a484u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a488: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15A488u;
    {
        const bool branch_taken_0x15a488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A488u;
            // 0x15a48c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a488) {
            ctx->pc = 0x15A498u;
            goto label_15a498;
        }
    }
    ctx->pc = 0x15A490u;
label_15a490:
    // 0x15a490: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x15a490u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x15a494: 0x24a50003  addiu       $a1, $a1, 0x3
    ctx->pc = 0x15a494u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_15a498:
    // 0x15a498: 0x28a20010  slti        $v0, $a1, 0x10
    ctx->pc = 0x15a498u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x15a49c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x15A49Cu;
    {
        const bool branch_taken_0x15a49c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A4A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A49Cu;
            // 0x15a4a0: 0xad240018  sw          $a0, 0x18($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 24), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a49c) {
            ctx->pc = 0x15A518u;
            goto label_15a518;
        }
    }
    ctx->pc = 0x15A4A4u;
    // 0x15a4a4: 0x24a5fff0  addiu       $a1, $a1, -0x10
    ctx->pc = 0x15a4a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967280));
    // 0x15a4a8: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x15A4A8u;
    {
        const bool branch_taken_0x15a4a8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A4ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A4A8u;
            // 0x15a4ac: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a4a8) {
            ctx->pc = 0x15A4D0u;
            goto label_15a4d0;
        }
    }
    ctx->pc = 0x15A4B0u;
    // 0x15a4b0: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x15a4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15a4b4: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x15a4b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x15a4b8: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15a4b8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x15a4bc: 0x71c02  srl         $v1, $a3, 16
    ctx->pc = 0x15a4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x15a4c0: 0xa63804  sllv        $a3, $a2, $a1
    ctx->pc = 0x15a4c0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x15a4c4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15A4C4u;
    {
        const bool branch_taken_0x15a4c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A4C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A4C4u;
            // 0x15a4c8: 0xae030290  sw          $v1, 0x290($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 656), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a4c4) {
            ctx->pc = 0x15A4DCu;
            goto label_15a4dc;
        }
    }
    ctx->pc = 0x15A4CCu;
    // 0x15a4cc: 0x0  nop
    ctx->pc = 0x15a4ccu;
    // NOP
label_15a4d0:
    // 0x15a4d0: 0x71402  srl         $v0, $a3, 16
    ctx->pc = 0x15a4d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x15a4d4: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a4d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a4d8: 0xae020290  sw          $v0, 0x290($s0)
    ctx->pc = 0x15a4d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 656), GPR_U32(ctx, 2));
label_15a4dc:
    // 0x15a4dc: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a4dcu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a4e0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a4e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a4e4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a4e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a4e8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a4e8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a4ec: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a4ecu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a4f0: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a4f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a4f4: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a4f4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a4f8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a4f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a4fc: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a4fcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a500: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a500u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a504: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a504u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a508: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a508u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a50c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a50cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a510: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15A510u;
    {
        const bool branch_taken_0x15a510 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A510u;
            // 0x15a514: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a510) {
            ctx->pc = 0x15A528u;
            goto label_15a528;
        }
    }
    ctx->pc = 0x15A518u;
label_15a518:
    // 0x15a518: 0x71402  srl         $v0, $a3, 16
    ctx->pc = 0x15a518u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x15a51c: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x15a51cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x15a520: 0xae020290  sw          $v0, 0x290($s0)
    ctx->pc = 0x15a520u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 656), GPR_U32(ctx, 2));
    // 0x15a524: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x15a524u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
label_15a528:
    // 0x15a528: 0x8d2a0018  lw          $t2, 0x18($t1)
    ctx->pc = 0x15a528u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 24)));
    // 0x15a52c: 0x2542fffe  addiu       $v0, $t2, -0x2
    ctx->pc = 0x15a52cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967294));
    // 0x15a530: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x15a530u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x15a534: 0x10400041  beqz        $v0, . + 4 + (0x41 << 2)
    ctx->pc = 0x15A534u;
    {
        const bool branch_taken_0x15a534 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A534u;
            // 0x15a538: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a534) {
            ctx->pc = 0x15A63Cu;
            goto label_15a63c;
        }
    }
    ctx->pc = 0x15A53Cu;
    // 0x15a53c: 0x260902c4  addiu       $t1, $s0, 0x2C4
    ctx->pc = 0x15a53cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 708));
    // 0x15a540: 0x717c2  srl         $v0, $a3, 31
    ctx->pc = 0x15a540u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 31));
    // 0x15a544: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x15a544u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x15a548: 0x14a30013  bne         $a1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x15A548u;
    {
        const bool branch_taken_0x15a548 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x15A54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A548u;
            // 0x15a54c: 0xad220000  sw          $v0, 0x0($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a548) {
            ctx->pc = 0x15A598u;
            goto label_15a598;
        }
    }
    ctx->pc = 0x15A550u;
    // 0x15a550: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a550u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a554: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a554u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a558: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a558u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a55c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15a55cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a560: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a560u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a564: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a564u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a568: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a568u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a56c: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a56cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a570: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a570u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a574: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a574u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a578: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a578u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a57c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a57cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a580: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a580u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a584: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a584u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a588: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a588u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a58c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15A58Cu;
    {
        const bool branch_taken_0x15a58c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A58Cu;
            // 0x15a590: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a58c) {
            ctx->pc = 0x15A5A0u;
            goto label_15a5a0;
        }
    }
    ctx->pc = 0x15A594u;
    // 0x15a594: 0x0  nop
    ctx->pc = 0x15a594u;
    // NOP
label_15a598:
    // 0x15a598: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15a598u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15a59c: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x15a59cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
label_15a5a0:
    // 0x15a5a0: 0x28a2001d  slti        $v0, $a1, 0x1D
    ctx->pc = 0x15a5a0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x15a5a4: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x15A5A4u;
    {
        const bool branch_taken_0x15a5a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A5A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A5A4u;
            // 0x15a5a8: 0x72742  srl         $a0, $a3, 29 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a5a4) {
            ctx->pc = 0x15A610u;
            goto label_15a610;
        }
    }
    ctx->pc = 0x15A5ACu;
    // 0x15a5ac: 0x24a5ffe3  addiu       $a1, $a1, -0x1D
    ctx->pc = 0x15a5acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967267));
    // 0x15a5b0: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15A5B0u;
    {
        const bool branch_taken_0x15a5b0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A5B0u;
            // 0x15a5b4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a5b0) {
            ctx->pc = 0x15A5D0u;
            goto label_15a5d0;
        }
    }
    ctx->pc = 0x15A5B8u;
    // 0x15a5b8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x15a5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15a5bc: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x15a5bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x15a5c0: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15a5c0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x15a5c4: 0x72742  srl         $a0, $a3, 29
    ctx->pc = 0x15a5c4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 29));
    // 0x15a5c8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x15A5C8u;
    {
        const bool branch_taken_0x15a5c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A5CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A5C8u;
            // 0x15a5cc: 0xa63804  sllv        $a3, $a2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a5c8) {
            ctx->pc = 0x15A5D4u;
            goto label_15a5d4;
        }
    }
    ctx->pc = 0x15A5D0u;
label_15a5d0:
    // 0x15a5d0: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a5d0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_15a5d4:
    // 0x15a5d4: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a5d4u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a5d8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a5d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a5dc: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a5dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a5e0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a5e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a5e4: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a5e4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a5e8: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a5e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a5ec: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a5ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a5f0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a5f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a5f4: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a5f4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a5f8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a5f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a5fc: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a5fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a600: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a600u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a604: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a604u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a608: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15A608u;
    {
        const bool branch_taken_0x15a608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A608u;
            // 0x15a60c: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a608) {
            ctx->pc = 0x15A618u;
            goto label_15a618;
        }
    }
    ctx->pc = 0x15A610u;
label_15a610:
    // 0x15a610: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x15a610u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x15a614: 0x24a50003  addiu       $a1, $a1, 0x3
    ctx->pc = 0x15a614u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_15a618:
    // 0x15a618: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15a618u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x15a61c: 0x2402001b  addiu       $v0, $zero, 0x1B
    ctx->pc = 0x15a61cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x15a620: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15a620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15a624: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x15a624u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x15a628: 0x831804  sllv        $v1, $v1, $a0
    ctx->pc = 0x15a628u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x15a62c: 0xad220008  sw          $v0, 0x8($t1)
    ctx->pc = 0x15a62cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 8), GPR_U32(ctx, 2));
    // 0x15a630: 0xad23000c  sw          $v1, 0xC($t1)
    ctx->pc = 0x15a630u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 12), GPR_U32(ctx, 3));
    // 0x15a634: 0xad240004  sw          $a0, 0x4($t1)
    ctx->pc = 0x15a634u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4), GPR_U32(ctx, 4));
    // 0x15a638: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x15a638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_15a63c:
    // 0x15a63c: 0x55420043  bnel        $t2, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x15A63Cu;
    {
        const bool branch_taken_0x15a63c = (GPR_U64(ctx, 10) != GPR_U64(ctx, 2));
        if (branch_taken_0x15a63c) {
            ctx->pc = 0x15A640u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15A63Cu;
            // 0x15a640: 0x8e0202b4  lw          $v0, 0x2B4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 692)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15A74Cu;
            goto label_15a74c;
        }
    }
    ctx->pc = 0x15A644u;
    // 0x15a644: 0x260902e8  addiu       $t1, $s0, 0x2E8
    ctx->pc = 0x15a644u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 744));
    // 0x15a648: 0x717c2  srl         $v0, $a3, 31
    ctx->pc = 0x15a648u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), 31));
    // 0x15a64c: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x15a64cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x15a650: 0x14a30013  bne         $a1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x15A650u;
    {
        const bool branch_taken_0x15a650 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x15A654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A650u;
            // 0x15a654: 0xad220000  sw          $v0, 0x0($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a650) {
            ctx->pc = 0x15A6A0u;
            goto label_15a6a0;
        }
    }
    ctx->pc = 0x15A658u;
    // 0x15a658: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a658u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a65c: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a65cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a660: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a660u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a664: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15a664u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a668: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a668u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a66c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a66cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a670: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a670u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a674: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a674u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a678: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a678u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a67c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a67cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a680: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a680u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a684: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a684u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a688: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a688u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a68c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a68cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a690: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a690u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a694: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15A694u;
    {
        const bool branch_taken_0x15a694 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A694u;
            // 0x15a698: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a694) {
            ctx->pc = 0x15A6A8u;
            goto label_15a6a8;
        }
    }
    ctx->pc = 0x15A69Cu;
    // 0x15a69c: 0x0  nop
    ctx->pc = 0x15a69cu;
    // NOP
label_15a6a0:
    // 0x15a6a0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15a6a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15a6a4: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x15a6a4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
label_15a6a8:
    // 0x15a6a8: 0x28a2001d  slti        $v0, $a1, 0x1D
    ctx->pc = 0x15a6a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x15a6ac: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x15A6ACu;
    {
        const bool branch_taken_0x15a6ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15A6B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A6ACu;
            // 0x15a6b0: 0x72742  srl         $a0, $a3, 29 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a6ac) {
            ctx->pc = 0x15A720u;
            goto label_15a720;
        }
    }
    ctx->pc = 0x15A6B4u;
    // 0x15a6b4: 0x24a5ffe3  addiu       $a1, $a1, -0x1D
    ctx->pc = 0x15a6b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967267));
    // 0x15a6b8: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15A6B8u;
    {
        const bool branch_taken_0x15a6b8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A6BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A6B8u;
            // 0x15a6bc: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a6b8) {
            ctx->pc = 0x15A6D8u;
            goto label_15a6d8;
        }
    }
    ctx->pc = 0x15A6C0u;
    // 0x15a6c0: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x15a6c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15a6c4: 0x461006  srlv        $v0, $a2, $v0
    ctx->pc = 0x15a6c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), GPR_U32(ctx, 2) & 0x1F));
    // 0x15a6c8: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15a6c8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x15a6cc: 0x72742  srl         $a0, $a3, 29
    ctx->pc = 0x15a6ccu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 29));
    // 0x15a6d0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x15A6D0u;
    {
        const bool branch_taken_0x15a6d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A6D0u;
            // 0x15a6d4: 0xa63804  sllv        $a3, $a2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a6d0) {
            ctx->pc = 0x15A6DCu;
            goto label_15a6dc;
        }
    }
    ctx->pc = 0x15A6D8u;
label_15a6d8:
    // 0x15a6d8: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x15a6d8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_15a6dc:
    // 0x15a6dc: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a6dcu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a6e0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a6e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a6e4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a6e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a6e8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a6e8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a6ec: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a6ecu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a6f0: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a6f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a6f4: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a6f4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a6f8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a6f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a6fc: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a6fcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a700: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a700u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a704: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a704u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a708: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a708u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a70c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a70cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a710: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15A710u;
    {
        const bool branch_taken_0x15a710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A710u;
            // 0x15a714: 0xc23025  or          $a2, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a710) {
            ctx->pc = 0x15A728u;
            goto label_15a728;
        }
    }
    ctx->pc = 0x15A718u;
label_15a718:
    // 0x15a718: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x15A718u;
    {
        const bool branch_taken_0x15a718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A71Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A718u;
            // 0x15a71c: 0x25080004  addiu       $t0, $t0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a718) {
            ctx->pc = 0x15A7E0u;
            goto label_15a7e0;
        }
    }
    ctx->pc = 0x15A720u;
label_15a720:
    // 0x15a720: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x15a720u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x15a724: 0x24a50003  addiu       $a1, $a1, 0x3
    ctx->pc = 0x15a724u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_15a728:
    // 0x15a728: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x15a728u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x15a72c: 0x2402001b  addiu       $v0, $zero, 0x1B
    ctx->pc = 0x15a72cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x15a730: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15a730u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15a734: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x15a734u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x15a738: 0x831804  sllv        $v1, $v1, $a0
    ctx->pc = 0x15a738u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x15a73c: 0xad220008  sw          $v0, 0x8($t1)
    ctx->pc = 0x15a73cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 8), GPR_U32(ctx, 2));
    // 0x15a740: 0xad23000c  sw          $v1, 0xC($t1)
    ctx->pc = 0x15a740u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 12), GPR_U32(ctx, 3));
    // 0x15a744: 0xad240004  sw          $a0, 0x4($t1)
    ctx->pc = 0x15a744u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4), GPR_U32(ctx, 4));
    // 0x15a748: 0x8e0202b4  lw          $v0, 0x2B4($s0)
    ctx->pc = 0x15a748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 692)));
label_15a74c:
    // 0x15a74c: 0xae0202ac  sw          $v0, 0x2AC($s0)
    ctx->pc = 0x15a74cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 684), GPR_U32(ctx, 2));
    // 0x15a750: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x15A750u;
    {
        const bool branch_taken_0x15a750 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A750u;
            // 0x15a754: 0x8e090348  lw          $t1, 0x348($s0) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 840)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a750) {
            ctx->pc = 0x15A7C8u;
            goto label_15a7c8;
        }
    }
    ctx->pc = 0x15A758u;
label_15a758:
    // 0x15a758: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x15a758u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15a75c: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x15A75Cu;
    {
        const bool branch_taken_0x15a75c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15a75c) {
            ctx->pc = 0x15A760u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15A75Cu;
            // 0x15a760: 0x73a40  sll         $a3, $a3, 9 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 9));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15A7A4u;
            goto label_15a7a4;
        }
    }
    ctx->pc = 0x15A764u;
    // 0x15a764: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x15a764u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x15a768: 0xa63804  sllv        $a3, $a2, $a1
    ctx->pc = 0x15a768u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 6), GPR_U32(ctx, 5) & 0x1F));
    // 0x15a76c: 0x81060000  lb          $a2, 0x0($t0)
    ctx->pc = 0x15a76cu;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a770: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a770u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a774: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a774u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a778: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a778u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a77c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a77cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a780: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x15a780u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a784: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a784u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x15a788: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a788u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a78c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a78cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a790: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15a790u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15a794: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x15a794u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x15a798: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15a798u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15a79c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x15a79cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x15a7a0: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x15a7a0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
label_15a7a4:
    // 0x15a7a4: 0x24a30007  addiu       $v1, $a1, 0x7
    ctx->pc = 0x15a7a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
    // 0x15a7a8: 0x8e04034c  lw          $a0, 0x34C($s0)
    ctx->pc = 0x15a7a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 844)));
    // 0x15a7ac: 0x318c3  sra         $v1, $v1, 3
    ctx->pc = 0x15a7acu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 3));
    // 0x15a7b0: 0x1031821  addu        $v1, $t0, $v1
    ctx->pc = 0x15a7b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x15a7b4: 0x2463fff8  addiu       $v1, $v1, -0x8
    ctx->pc = 0x15a7b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967288));
    // 0x15a7b8: 0x691823  subu        $v1, $v1, $t1
    ctx->pc = 0x15a7b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x15a7bc: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x15a7bcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x15a7c0: 0x10600020  beqz        $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x15A7C0u;
    {
        const bool branch_taken_0x15a7c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x15A7C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A7C0u;
            // 0x15a7c4: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15a7c0) {
            ctx->pc = 0x15A844u;
            goto label_15a844;
        }
    }
    ctx->pc = 0x15A7C8u;
label_15a7c8:
    // 0x15a7c8: 0x4e2ffe3  bltzl       $a3, . + 4 + (-0x1D << 2)
    ctx->pc = 0x15A7C8u;
    {
        const bool branch_taken_0x15a7c8 = (GPR_S64(ctx, 7) < 0);
        if (branch_taken_0x15a7c8) {
            ctx->pc = 0x15A7CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15A7C8u;
            // 0x15a7cc: 0x24a50009  addiu       $a1, $a1, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15A758u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15a758;
        }
    }
    ctx->pc = 0x15A7D0u;
    // 0x15a7d0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x15a7d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15a7d4: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x15a7d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15a7d8: 0x5040ffcf  beql        $v0, $zero, . + 4 + (-0x31 << 2)
    ctx->pc = 0x15A7D8u;
    {
        const bool branch_taken_0x15a7d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15a7d8) {
            ctx->pc = 0x15A7DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15A7D8u;
            // 0x15a7dc: 0x24a5ffe0  addiu       $a1, $a1, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15A718u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15a718;
        }
    }
    ctx->pc = 0x15A7E0u;
label_15a7e0:
    // 0x15a7e0: 0x30a20007  andi        $v0, $a1, 0x7
    ctx->pc = 0x15a7e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)7);
    // 0x15a7e4: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x15a7e4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a7e8: 0xa22823  subu        $a1, $a1, $v0
    ctx->pc = 0x15a7e8u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x15a7ec: 0xae020350  sw          $v0, 0x350($s0)
    ctx->pc = 0x15a7ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 848), GPR_U32(ctx, 2));
    // 0x15a7f0: 0x24a50007  addiu       $a1, $a1, 0x7
    ctx->pc = 0x15a7f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
    // 0x15a7f4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x15a7f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a7f8: 0x528c3  sra         $a1, $a1, 3
    ctx->pc = 0x15a7f8u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 3));
    // 0x15a7fc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x15a7fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a800: 0x1052821  addu        $a1, $t0, $a1
    ctx->pc = 0x15a800u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x15a804: 0x24a5fff8  addiu       $a1, $a1, -0x8
    ctx->pc = 0x15a804u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967288));
    // 0x15a808: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x15A808u;
    SET_GPR_U32(ctx, 31, 0x15A810u);
    ctx->pc = 0x15A80Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15A808u;
            // 0x15a80c: 0xa92823  subu        $a1, $a1, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A810u; }
        if (ctx->pc != 0x15A810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15A810u; }
        if (ctx->pc != 0x15A810u) { return; }
    }
    ctx->pc = 0x15A810u;
label_15a810:
    // 0x15a810: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15a810u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15a814: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x15a814u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a818: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15a818u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a81c: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15a81cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15a820: 0x40f809  jalr        $v0
    ctx->pc = 0x15A820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A828u);
        ctx->pc = 0x15A824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A820u;
            // 0x15a824: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A828u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A2B8u: goto label_15a2b8;
            case 0x15A350u: goto label_15a350;
            case 0x15A3C8u: goto label_15a3c8;
            case 0x15A3D4u: goto label_15a3d4;
            case 0x15A410u: goto label_15a410;
            case 0x15A420u: goto label_15a420;
            case 0x15A450u: goto label_15a450;
            case 0x15A454u: goto label_15a454;
            case 0x15A490u: goto label_15a490;
            case 0x15A498u: goto label_15a498;
            case 0x15A4D0u: goto label_15a4d0;
            case 0x15A4DCu: goto label_15a4dc;
            case 0x15A518u: goto label_15a518;
            case 0x15A528u: goto label_15a528;
            case 0x15A598u: goto label_15a598;
            case 0x15A5A0u: goto label_15a5a0;
            case 0x15A5D0u: goto label_15a5d0;
            case 0x15A5D4u: goto label_15a5d4;
            case 0x15A610u: goto label_15a610;
            case 0x15A618u: goto label_15a618;
            case 0x15A63Cu: goto label_15a63c;
            case 0x15A6A0u: goto label_15a6a0;
            case 0x15A6A8u: goto label_15a6a8;
            case 0x15A6D8u: goto label_15a6d8;
            case 0x15A6DCu: goto label_15a6dc;
            case 0x15A718u: goto label_15a718;
            case 0x15A720u: goto label_15a720;
            case 0x15A728u: goto label_15a728;
            case 0x15A74Cu: goto label_15a74c;
            case 0x15A758u: goto label_15a758;
            case 0x15A7A4u: goto label_15a7a4;
            case 0x15A7C8u: goto label_15a7c8;
            case 0x15A7E0u: goto label_15a7e0;
            case 0x15A810u: goto label_15a810;
            case 0x15A828u: goto label_15a828;
            case 0x15A840u: goto label_15a840;
            case 0x15A844u: goto label_15a844;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A828u; }
            if (ctx->pc != 0x15A828u) { return; }
        }
        }
    }
    ctx->pc = 0x15A828u;
label_15a828:
    // 0x15a828: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x15a828u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x15a82c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15a82cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15a830: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15a830u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15a834: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x15a834u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15a838: 0x40f809  jalr        $v0
    ctx->pc = 0x15A838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15A840u);
        ctx->pc = 0x15A83Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A838u;
            // 0x15a83c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15A840u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A2B8u: goto label_15a2b8;
            case 0x15A350u: goto label_15a350;
            case 0x15A3C8u: goto label_15a3c8;
            case 0x15A3D4u: goto label_15a3d4;
            case 0x15A410u: goto label_15a410;
            case 0x15A420u: goto label_15a420;
            case 0x15A450u: goto label_15a450;
            case 0x15A454u: goto label_15a454;
            case 0x15A490u: goto label_15a490;
            case 0x15A498u: goto label_15a498;
            case 0x15A4D0u: goto label_15a4d0;
            case 0x15A4DCu: goto label_15a4dc;
            case 0x15A518u: goto label_15a518;
            case 0x15A528u: goto label_15a528;
            case 0x15A598u: goto label_15a598;
            case 0x15A5A0u: goto label_15a5a0;
            case 0x15A5D0u: goto label_15a5d0;
            case 0x15A5D4u: goto label_15a5d4;
            case 0x15A610u: goto label_15a610;
            case 0x15A618u: goto label_15a618;
            case 0x15A63Cu: goto label_15a63c;
            case 0x15A6A0u: goto label_15a6a0;
            case 0x15A6A8u: goto label_15a6a8;
            case 0x15A6D8u: goto label_15a6d8;
            case 0x15A6DCu: goto label_15a6dc;
            case 0x15A718u: goto label_15a718;
            case 0x15A720u: goto label_15a720;
            case 0x15A728u: goto label_15a728;
            case 0x15A74Cu: goto label_15a74c;
            case 0x15A758u: goto label_15a758;
            case 0x15A7A4u: goto label_15a7a4;
            case 0x15A7C8u: goto label_15a7c8;
            case 0x15A7E0u: goto label_15a7e0;
            case 0x15A810u: goto label_15a810;
            case 0x15A828u: goto label_15a828;
            case 0x15A840u: goto label_15a840;
            case 0x15A844u: goto label_15a844;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15A840u; }
            if (ctx->pc != 0x15A840u) { return; }
        }
        }
    }
    ctx->pc = 0x15A840u;
label_15a840:
    // 0x15a840: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15a840u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15a844:
    // 0x15a844: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15a844u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15a848: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15a848u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15a84c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15a84cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15a850: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15a850u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15a854: 0x3e00008  jr          $ra
    ctx->pc = 0x15A854u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15A858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15A854u;
            // 0x15a858: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15A2B8u: goto label_15a2b8;
            case 0x15A350u: goto label_15a350;
            case 0x15A3C8u: goto label_15a3c8;
            case 0x15A3D4u: goto label_15a3d4;
            case 0x15A410u: goto label_15a410;
            case 0x15A420u: goto label_15a420;
            case 0x15A450u: goto label_15a450;
            case 0x15A454u: goto label_15a454;
            case 0x15A490u: goto label_15a490;
            case 0x15A498u: goto label_15a498;
            case 0x15A4D0u: goto label_15a4d0;
            case 0x15A4DCu: goto label_15a4dc;
            case 0x15A518u: goto label_15a518;
            case 0x15A528u: goto label_15a528;
            case 0x15A598u: goto label_15a598;
            case 0x15A5A0u: goto label_15a5a0;
            case 0x15A5D0u: goto label_15a5d0;
            case 0x15A5D4u: goto label_15a5d4;
            case 0x15A610u: goto label_15a610;
            case 0x15A618u: goto label_15a618;
            case 0x15A63Cu: goto label_15a63c;
            case 0x15A6A0u: goto label_15a6a0;
            case 0x15A6A8u: goto label_15a6a8;
            case 0x15A6D8u: goto label_15a6d8;
            case 0x15A6DCu: goto label_15a6dc;
            case 0x15A718u: goto label_15a718;
            case 0x15A720u: goto label_15a720;
            case 0x15A728u: goto label_15a728;
            case 0x15A74Cu: goto label_15a74c;
            case 0x15A758u: goto label_15a758;
            case 0x15A7A4u: goto label_15a7a4;
            case 0x15A7C8u: goto label_15a7c8;
            case 0x15A7E0u: goto label_15a7e0;
            case 0x15A810u: goto label_15a810;
            case 0x15A828u: goto label_15a828;
            case 0x15A840u: goto label_15a840;
            case 0x15A844u: goto label_15a844;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15A85Cu;
    // 0x15a85c: 0x0  nop
    ctx->pc = 0x15a85cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
