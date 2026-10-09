#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116218
// Address: 0x116218 - 0x116810
void sub_00116218_0x116218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116218_0x116218");
#endif

    switch (ctx->pc) {
        case 0x116248u: goto label_116248;
        case 0x116258u: goto label_116258;
        case 0x116270u: goto label_116270;
        case 0x116274u: goto label_116274;
        case 0x116278u: goto label_116278;
        case 0x116308u: goto label_116308;
        case 0x116334u: goto label_116334;
        case 0x116398u: goto label_116398;
        case 0x1163d8u: goto label_1163d8;
        case 0x1163ecu: goto label_1163ec;
        case 0x116450u: goto label_116450;
        case 0x116498u: goto label_116498;
        case 0x1164acu: goto label_1164ac;
        case 0x116520u: goto label_116520;
        case 0x116530u: goto label_116530;
        case 0x116538u: goto label_116538;
        case 0x116554u: goto label_116554;
        case 0x116588u: goto label_116588;
        case 0x11659cu: goto label_11659c;
        case 0x116608u: goto label_116608;
        case 0x116610u: goto label_116610;
        case 0x11662cu: goto label_11662c;
        case 0x116658u: goto label_116658;
        case 0x11666cu: goto label_11666c;
        case 0x11668cu: goto label_11668c;
        case 0x1166b4u: goto label_1166b4;
        case 0x1166c4u: goto label_1166c4;
        case 0x1166ccu: goto label_1166cc;
        case 0x1166fcu: goto label_1166fc;
        case 0x116708u: goto label_116708;
        case 0x116714u: goto label_116714;
        case 0x116720u: goto label_116720;
        case 0x11672cu: goto label_11672c;
        case 0x116738u: goto label_116738;
        case 0x116750u: goto label_116750;
        case 0x116764u: goto label_116764;
        case 0x116798u: goto label_116798;
        case 0x1167b0u: goto label_1167b0;
        case 0x1167e4u: goto label_1167e4;
        default: break;
    }

    ctx->pc = 0x116218u;

    // 0x116218: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x116218u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x11621c: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x11621cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x116220: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x116220u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x116224: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x116224u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116228: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x116228u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11622c: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x11622cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x116230: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x116230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x116234: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x116234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x116238: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x116238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x11623c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x11623cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x116240: 0xc047598  jal         func_11D660
    ctx->pc = 0x116240u;
    SET_GPR_U32(ctx, 31, 0x116248u);
    ctx->pc = 0x116244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116240u;
            // 0x116244: 0xffb10030  sd          $s1, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116248u; }
        if (ctx->pc != 0x116248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116248u; }
        if (ctx->pc != 0x116248u) { return; }
    }
    ctx->pc = 0x116248u;
label_116248:
    // 0x116248: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x116248u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11624c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x11624cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x116250: 0x10400160  beqz        $v0, . + 4 + (0x160 << 2)
    ctx->pc = 0x116250u;
    {
        const bool branch_taken_0x116250 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x116254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116250u;
            // 0x116254: 0x92030000  lbu         $v1, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116250) {
            ctx->pc = 0x1167D4u;
            goto label_1167d4;
        }
    }
    ctx->pc = 0x116258u;
label_116258:
    // 0x116258: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x116258u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11625c: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x11625cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116260: 0x22603  sra         $a0, $v0, 24
    ctx->pc = 0x116260u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 2), 24));
    // 0x116264: 0x24020025  addiu       $v0, $zero, 0x25
    ctx->pc = 0x116264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x116268: 0x1482014d  bne         $a0, $v0, . + 4 + (0x14D << 2)
    ctx->pc = 0x116268u;
    {
        const bool branch_taken_0x116268 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x11626Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116268u;
            // 0x11626c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116268) {
            ctx->pc = 0x1167A0u;
            goto label_1167a0;
        }
    }
    ctx->pc = 0x116270u;
label_116270:
    // 0x116270: 0x26120001  addiu       $s2, $s0, 0x1
    ctx->pc = 0x116270u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_116274:
    // 0x116274: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x116274u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_116278:
    // 0x116278: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x116278u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11627c: 0x2442ffd0  addiu       $v0, $v0, -0x30
    ctx->pc = 0x11627cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967248));
    // 0x116280: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x116280u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x116284: 0x22603  sra         $a0, $v0, 24
    ctx->pc = 0x116284u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 2), 24));
    // 0x116288: 0x2c830049  sltiu       $v1, $a0, 0x49
    ctx->pc = 0x116288u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)73) ? 1 : 0);
    // 0x11628c: 0x1060014a  beqz        $v1, . + 4 + (0x14A << 2)
    ctx->pc = 0x11628Cu;
    {
        const bool branch_taken_0x11628c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x116290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11628Cu;
            // 0x116290: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11628c) {
            ctx->pc = 0x1167B8u;
            goto label_1167b8;
        }
    }
    ctx->pc = 0x116294u;
    // 0x116294: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x116294u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x116298: 0x244289f0  addiu       $v0, $v0, -0x7610
    ctx->pc = 0x116298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937072));
    // 0x11629c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x11629cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1162a0: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1162a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1162a4: 0x800008  jr          $a0
    ctx->pc = 0x1162A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1162ACu: goto label_1162ac;
            case 0x116330u: goto label_116330;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x116400u: goto label_116400;
            case 0x1164C0u: goto label_1164c0;
            case 0x1165B0u: goto label_1165b0;
            case 0x116680u: goto label_116680;
            case 0x1166D4u: goto label_1166d4;
            case 0x116778u: goto label_116778;
            case 0x1167C0u: goto label_1167c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1162ACu;
label_1162ac:
    // 0x1162ac: 0x82430001  lb          $v1, 0x1($s2)
    ctx->pc = 0x1162acu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0x1162b0: 0x2465ffd0  addiu       $a1, $v1, -0x30
    ctx->pc = 0x1162b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967248));
    // 0x1162b4: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1162b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1162b8: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x1162b8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1162bc: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1162BCu;
    {
        const bool branch_taken_0x1162bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1162C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1162BCu;
            // 0x1162c0: 0x82460002  lb          $a2, 0x2($s2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1162bc) {
            ctx->pc = 0x116334u;
            goto label_116334;
        }
    }
    ctx->pc = 0x1162C4u;
    // 0x1162c4: 0x24c2ffd0  addiu       $v0, $a2, -0x30
    ctx->pc = 0x1162c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967248));
    // 0x1162c8: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x1162c8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1162cc: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1162CCu;
    {
        const bool branch_taken_0x1162cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1162D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1162CCu;
            // 0x1162d0: 0x2403000a  addiu       $v1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1162cc) {
            ctx->pc = 0x1162F4u;
            goto label_1162f4;
        }
    }
    ctx->pc = 0x1162D4u;
    // 0x1162d4: 0x2404001f  addiu       $a0, $zero, 0x1F
    ctx->pc = 0x1162d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1162d8: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x1162d8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1162dc: 0x26500002  addiu       $s0, $s2, 0x2
    ctx->pc = 0x1162dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x1162e0: 0x2463ffd0  addiu       $v1, $v1, -0x30
    ctx->pc = 0x1162e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967248));
    // 0x1162e4: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x1162e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1162e8: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x1162e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1162ec: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1162ECu;
    {
        const bool branch_taken_0x1162ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1162F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1162ECu;
            // 0x1162f0: 0x82280a  movz        $a1, $a0, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1162ec) {
            ctx->pc = 0x1162F8u;
            goto label_1162f8;
        }
    }
    ctx->pc = 0x1162F4u;
label_1162f4:
    // 0x1162f4: 0x26500001  addiu       $s0, $s2, 0x1
    ctx->pc = 0x1162f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1162f8:
    // 0x1162f8: 0x27a2001f  addiu       $v0, $sp, 0x1F
    ctx->pc = 0x1162f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
    // 0x1162fc: 0x18a0ffdc  blez        $a1, . + 4 + (-0x24 << 2)
    ctx->pc = 0x1162FCu;
    {
        const bool branch_taken_0x1162fc = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x116300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1162FCu;
            // 0x116300: 0x45a023  subu        $s4, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1162fc) {
            ctx->pc = 0x116270u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116270;
        }
    }
    ctx->pc = 0x116304u;
    // 0x116304: 0x26120001  addiu       $s2, $s0, 0x1
    ctx->pc = 0x116304u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_116308:
    // 0x116308: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x116308u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x11630c: 0x24040030  addiu       $a0, $zero, 0x30
    ctx->pc = 0x11630cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x116310: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x116310u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x116314: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x116314u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x116318: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x116318u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x11631c: 0xa0640000  sb          $a0, 0x0($v1)
    ctx->pc = 0x11631cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x116320: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x116320u;
    {
        const bool branch_taken_0x116320 = (GPR_S64(ctx, 5) > 0);
        if (branch_taken_0x116320) {
            ctx->pc = 0x116308u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116308;
        }
    }
    ctx->pc = 0x116328u;
    // 0x116328: 0x1000ffd3  b           . + 4 + (-0x2D << 2)
    ctx->pc = 0x116328u;
    {
        const bool branch_taken_0x116328 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11632Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116328u;
            // 0x11632c: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116328) {
            ctx->pc = 0x116278u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116278;
        }
    }
    ctx->pc = 0x116330u;
label_116330:
    // 0x116330: 0x2407006c  addiu       $a3, $zero, 0x6C
    ctx->pc = 0x116330u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
label_116334:
    // 0x116334: 0x1000ffcf  b           . + 4 + (-0x31 << 2)
    ctx->pc = 0x116334u;
    {
        const bool branch_taken_0x116334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116334u;
            // 0x116338: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116334) {
            ctx->pc = 0x116274u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116274;
        }
    }
    ctx->pc = 0x11633Cu;
label_11633c:
    // 0x11633c: 0x1000fffd  b           . + 4 + (-0x3 << 2)
    ctx->pc = 0x11633Cu;
    {
        const bool branch_taken_0x11633c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11633Cu;
            // 0x116340: 0x24070068  addiu       $a3, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11633c) {
            ctx->pc = 0x116334u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116334;
        }
    }
    ctx->pc = 0x116344u;
label_116344:
    // 0x116344: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x116344u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x116348: 0x14e20004  bne         $a3, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x116348u;
    {
        const bool branch_taken_0x116348 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x11634Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116348u;
            // 0x11634c: 0x24020068  addiu       $v0, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116348) {
            ctx->pc = 0x11635Cu;
            goto label_11635c;
        }
    }
    ctx->pc = 0x116350u;
    // 0x116350: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x116350u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x116354: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x116354u;
    {
        const bool branch_taken_0x116354 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116354u;
            // 0x116358: 0xde71fff8  ld          $s1, -0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116354) {
            ctx->pc = 0x116370u;
            goto label_116370;
        }
    }
    ctx->pc = 0x11635Cu;
label_11635c:
    // 0x11635c: 0x14e20003  bne         $a3, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11635Cu;
    {
        const bool branch_taken_0x11635c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x116360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11635Cu;
            // 0x116360: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11635c) {
            ctx->pc = 0x11636Cu;
            goto label_11636c;
        }
    }
    ctx->pc = 0x116364u;
    // 0x116364: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x116364u;
    {
        const bool branch_taken_0x116364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116364u;
            // 0x116368: 0x9671fff8  lhu         $s1, -0x8($s3) (Delay Slot)
        SET_GPR_U32(ctx, 17, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116364) {
            ctx->pc = 0x116370u;
            goto label_116370;
        }
    }
    ctx->pc = 0x11636Cu;
label_11636c:
    // 0x11636c: 0x9e71fff8  lwu         $s1, -0x8($s3)
    ctx->pc = 0x11636cu;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 19), 4294967288)));
label_116370:
    // 0x116370: 0x27b0001f  addiu       $s0, $sp, 0x1F
    ctx->pc = 0x116370u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
    // 0x116374: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x116374u;
    {
        const bool branch_taken_0x116374 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x116378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116374u;
            // 0x116378: 0xa3a0001f  sb          $zero, 0x1F($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116374) {
            ctx->pc = 0x116390u;
            goto label_116390;
        }
    }
    ctx->pc = 0x11637Cu;
    // 0x11637c: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x11637cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x116380: 0x27b0001e  addiu       $s0, $sp, 0x1E
    ctx->pc = 0x116380u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 30));
    // 0x116384: 0xa3a2001e  sb          $v0, 0x1E($sp)
    ctx->pc = 0x116384u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x116388: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x116388u;
    {
        const bool branch_taken_0x116388 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11638Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116388u;
            // 0x11638c: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116388) {
            ctx->pc = 0x1163B8u;
            goto label_1163b8;
        }
    }
    ctx->pc = 0x116390u;
label_116390:
    // 0x116390: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x116390u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x116394: 0x0  nop
    ctx->pc = 0x116394u;
    // NOP
label_116398:
    // 0x116398: 0x32220007  andi        $v0, $s1, 0x7
    ctx->pc = 0x116398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)7);
    // 0x11639c: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x11639cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x1163a0: 0x64420030  daddiu      $v0, $v0, 0x30
    ctx->pc = 0x1163a0u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)48);
    // 0x1163a4: 0x1188fa  dsrl        $s1, $s1, 3
    ctx->pc = 0x1163a4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) >> 3);
    // 0x1163a8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1163a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1163ac: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1163acu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1163b0: 0x1620fff9  bnez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1163B0u;
    {
        const bool branch_taken_0x1163b0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1163b0) {
            ctx->pc = 0x116398u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116398;
        }
    }
    ctx->pc = 0x1163B8u;
label_1163b8:
    // 0x1163b8: 0x12800002  beqz        $s4, . + 4 + (0x2 << 2)
    ctx->pc = 0x1163B8u;
    {
        const bool branch_taken_0x1163b8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x1163BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1163B8u;
            // 0x1163bc: 0x290102b  sltu        $v0, $s4, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1163b8) {
            ctx->pc = 0x1163C4u;
            goto label_1163c4;
        }
    }
    ctx->pc = 0x1163C0u;
    // 0x1163c0: 0x282800b  movn        $s0, $s4, $v0
    ctx->pc = 0x1163c0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 20));
label_1163c4:
    // 0x1163c4: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1163c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1163c8: 0x104000fe  beqz        $v0, . + 4 + (0xFE << 2)
    ctx->pc = 0x1163C8u;
    {
        const bool branch_taken_0x1163c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1163CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1163C8u;
            // 0x1163cc: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1163c8) {
            ctx->pc = 0x1167C4u;
            goto label_1167c4;
        }
    }
    ctx->pc = 0x1163D0u;
    // 0x1163d0: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x1163d0u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x1163d4: 0x0  nop
    ctx->pc = 0x1163d4u;
    // NOP
label_1163d8:
    // 0x1163d8: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x1163d8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x1163dc: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x1163dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x1163e0: 0x42603  sra         $a0, $a0, 24
    ctx->pc = 0x1163e0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0x1163e4: 0x40f809  jalr        $v0
    ctx->pc = 0x1163E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1163ECu);
        ctx->pc = 0x1163E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1163E4u;
            // 0x1163e8: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1163ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1163ECu; }
            if (ctx->pc != 0x1163ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1163ECu;
label_1163ec:
    // 0x1163ec: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1163ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1163f0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1163F0u;
    {
        const bool branch_taken_0x1163f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1163F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1163F0u;
            // 0x1163f4: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1163f0) {
            ctx->pc = 0x1163D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1163d8;
        }
    }
    ctx->pc = 0x1163F8u;
    // 0x1163f8: 0x100000f3  b           . + 4 + (0xF3 << 2)
    ctx->pc = 0x1163F8u;
    {
        const bool branch_taken_0x1163f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1163FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1163F8u;
            // 0x1163fc: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1163f8) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x116400u;
label_116400:
    // 0x116400: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x116400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x116404: 0x14e20004  bne         $a3, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x116404u;
    {
        const bool branch_taken_0x116404 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x116408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116404u;
            // 0x116408: 0x24020068  addiu       $v0, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116404) {
            ctx->pc = 0x116418u;
            goto label_116418;
        }
    }
    ctx->pc = 0x11640Cu;
    // 0x11640c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x11640cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x116410: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x116410u;
    {
        const bool branch_taken_0x116410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116410u;
            // 0x116414: 0xde71fff8  ld          $s1, -0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116410) {
            ctx->pc = 0x11642Cu;
            goto label_11642c;
        }
    }
    ctx->pc = 0x116418u;
label_116418:
    // 0x116418: 0x14e20003  bne         $a3, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x116418u;
    {
        const bool branch_taken_0x116418 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x11641Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116418u;
            // 0x11641c: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116418) {
            ctx->pc = 0x116428u;
            goto label_116428;
        }
    }
    ctx->pc = 0x116420u;
    // 0x116420: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x116420u;
    {
        const bool branch_taken_0x116420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116420u;
            // 0x116424: 0x9671fff8  lhu         $s1, -0x8($s3) (Delay Slot)
        SET_GPR_U32(ctx, 17, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116420) {
            ctx->pc = 0x11642Cu;
            goto label_11642c;
        }
    }
    ctx->pc = 0x116428u;
label_116428:
    // 0x116428: 0x9e71fff8  lwu         $s1, -0x8($s3)
    ctx->pc = 0x116428u;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 19), 4294967288)));
label_11642c:
    // 0x11642c: 0x27b0001f  addiu       $s0, $sp, 0x1F
    ctx->pc = 0x11642cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
    // 0x116430: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x116430u;
    {
        const bool branch_taken_0x116430 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x116434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116430u;
            // 0x116434: 0xa3a0001f  sb          $zero, 0x1F($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116430) {
            ctx->pc = 0x11644Cu;
            goto label_11644c;
        }
    }
    ctx->pc = 0x116438u;
    // 0x116438: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x116438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x11643c: 0x27b0001e  addiu       $s0, $sp, 0x1E
    ctx->pc = 0x11643cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 30));
    // 0x116440: 0xa3a2001e  sb          $v0, 0x1E($sp)
    ctx->pc = 0x116440u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x116444: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x116444u;
    {
        const bool branch_taken_0x116444 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116444u;
            // 0x116448: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116444) {
            ctx->pc = 0x116478u;
            goto label_116478;
        }
    }
    ctx->pc = 0x11644Cu;
label_11644c:
    // 0x11644c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x11644cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_116450:
    // 0x116450: 0x3223000f  andi        $v1, $s1, 0xF
    ctx->pc = 0x116450u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
    // 0x116454: 0x2c62000a  sltiu       $v0, $v1, 0xA
    ctx->pc = 0x116454u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x116458: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x116458u;
    {
        const bool branch_taken_0x116458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11645Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116458u;
            // 0x11645c: 0x64620030  daddiu      $v0, $v1, 0x30 (Delay Slot)
        SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 3) + (int64_t)(int32_t)48);
        ctx->in_delay_slot = false;
        if (branch_taken_0x116458) {
            ctx->pc = 0x116464u;
            goto label_116464;
        }
    }
    ctx->pc = 0x116460u;
    // 0x116460: 0x64620057  daddiu      $v0, $v1, 0x57
    ctx->pc = 0x116460u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 3) + (int64_t)(int32_t)87);
label_116464:
    // 0x116464: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x116464u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x116468: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x116468u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x11646c: 0x11893a  dsrl        $s1, $s1, 4
    ctx->pc = 0x11646cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) >> 4);
    // 0x116470: 0x1620fff7  bnez        $s1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x116470u;
    {
        const bool branch_taken_0x116470 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x116474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116470u;
            // 0x116474: 0xa2020000  sb          $v0, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116470) {
            ctx->pc = 0x116450u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116450;
        }
    }
    ctx->pc = 0x116478u;
label_116478:
    // 0x116478: 0x12800002  beqz        $s4, . + 4 + (0x2 << 2)
    ctx->pc = 0x116478u;
    {
        const bool branch_taken_0x116478 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x11647Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116478u;
            // 0x11647c: 0x290102b  sltu        $v0, $s4, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x116478) {
            ctx->pc = 0x116484u;
            goto label_116484;
        }
    }
    ctx->pc = 0x116480u;
    // 0x116480: 0x282800b  movn        $s0, $s4, $v0
    ctx->pc = 0x116480u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 20));
label_116484:
    // 0x116484: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x116484u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x116488: 0x104000ce  beqz        $v0, . + 4 + (0xCE << 2)
    ctx->pc = 0x116488u;
    {
        const bool branch_taken_0x116488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11648Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116488u;
            // 0x11648c: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116488) {
            ctx->pc = 0x1167C4u;
            goto label_1167c4;
        }
    }
    ctx->pc = 0x116490u;
    // 0x116490: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x116490u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x116494: 0x0  nop
    ctx->pc = 0x116494u;
    // NOP
label_116498:
    // 0x116498: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x116498u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x11649c: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x11649cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x1164a0: 0x42603  sra         $a0, $a0, 24
    ctx->pc = 0x1164a0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0x1164a4: 0x40f809  jalr        $v0
    ctx->pc = 0x1164A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1164ACu);
        ctx->pc = 0x1164A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164A4u;
            // 0x1164a8: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1164ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1164ACu; }
            if (ctx->pc != 0x1164ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1164ACu;
label_1164ac:
    // 0x1164ac: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1164acu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1164b0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1164B0u;
    {
        const bool branch_taken_0x1164b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1164B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164B0u;
            // 0x1164b4: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1164b0) {
            ctx->pc = 0x116498u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116498;
        }
    }
    ctx->pc = 0x1164B8u;
    // 0x1164b8: 0x100000c3  b           . + 4 + (0xC3 << 2)
    ctx->pc = 0x1164B8u;
    {
        const bool branch_taken_0x1164b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1164BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164B8u;
            // 0x1164bc: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1164b8) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x1164C0u;
label_1164c0:
    // 0x1164c0: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1164c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1164c4: 0x14e20004  bne         $a3, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1164C4u;
    {
        const bool branch_taken_0x1164c4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x1164C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164C4u;
            // 0x1164c8: 0x24020068  addiu       $v0, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1164c4) {
            ctx->pc = 0x1164D8u;
            goto label_1164d8;
        }
    }
    ctx->pc = 0x1164CCu;
    // 0x1164cc: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x1164ccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x1164d0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1164D0u;
    {
        const bool branch_taken_0x1164d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1164D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164D0u;
            // 0x1164d4: 0xde71fff8  ld          $s1, -0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1164d0) {
            ctx->pc = 0x1164ECu;
            goto label_1164ec;
        }
    }
    ctx->pc = 0x1164D8u;
label_1164d8:
    // 0x1164d8: 0x14e20003  bne         $a3, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1164D8u;
    {
        const bool branch_taken_0x1164d8 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x1164DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164D8u;
            // 0x1164dc: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1164d8) {
            ctx->pc = 0x1164E8u;
            goto label_1164e8;
        }
    }
    ctx->pc = 0x1164E0u;
    // 0x1164e0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1164E0u;
    {
        const bool branch_taken_0x1164e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1164E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164E0u;
            // 0x1164e4: 0x8671fff8  lh          $s1, -0x8($s3) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1164e0) {
            ctx->pc = 0x1164ECu;
            goto label_1164ec;
        }
    }
    ctx->pc = 0x1164E8u;
label_1164e8:
    // 0x1164e8: 0x8e71fff8  lw          $s1, -0x8($s3)
    ctx->pc = 0x1164e8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4294967288)));
label_1164ec:
    // 0x1164ec: 0x27b0001f  addiu       $s0, $sp, 0x1F
    ctx->pc = 0x1164ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
    // 0x1164f0: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1164F0u;
    {
        const bool branch_taken_0x1164f0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1164F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1164F0u;
            // 0x1164f4: 0xa3a0001f  sb          $zero, 0x1F($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1164f0) {
            ctx->pc = 0x116508u;
            goto label_116508;
        }
    }
    ctx->pc = 0x1164F8u;
    // 0x1164f8: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x1164f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1164fc: 0x27b0001e  addiu       $s0, $sp, 0x1E
    ctx->pc = 0x1164fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 30));
    // 0x116500: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x116500u;
    {
        const bool branch_taken_0x116500 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116500u;
            // 0x116504: 0xa3a2001e  sb          $v0, 0x1E($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 30), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116500) {
            ctx->pc = 0x116568u;
            goto label_116568;
        }
    }
    ctx->pc = 0x116508u;
label_116508:
    // 0x116508: 0x6210005  bgez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x116508u;
    {
        const bool branch_taken_0x116508 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x11650Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116508u;
            // 0x11650c: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116508) {
            ctx->pc = 0x116520u;
            goto label_116520;
        }
    }
    ctx->pc = 0x116510u;
    // 0x116510: 0x11882f  dsubu       $s1, $zero, $s1
    ctx->pc = 0x116510u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 0) - GPR_U64(ctx, 17));
    // 0x116514: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x116514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116518: 0x40f809  jalr        $v0
    ctx->pc = 0x116518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x116520u);
        ctx->pc = 0x11651Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116518u;
            // 0x11651c: 0x2404002d  addiu       $a0, $zero, 0x2D (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116520u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116520u; }
            if (ctx->pc != 0x116520u) { return; }
        }
        }
    }
    ctx->pc = 0x116520u;
label_116520:
    // 0x116520: 0x12200012  beqz        $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0x116520u;
    {
        const bool branch_taken_0x116520 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x116524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116520u;
            // 0x116524: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116520) {
            ctx->pc = 0x11656Cu;
            goto label_11656c;
        }
    }
    ctx->pc = 0x116528u;
    // 0x116528: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x116528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11652c: 0x0  nop
    ctx->pc = 0x11652cu;
    // NOP
label_116530:
    // 0x116530: 0xc04406c  jal         func_1101B0
    ctx->pc = 0x116530u;
    SET_GPR_U32(ctx, 31, 0x116538u);
    ctx->pc = 0x116534u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116530u;
            // 0x116534: 0x2405000a  addiu       $a1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1101B0u;
    if (runtime->hasFunction(0x1101B0u)) {
        auto targetFn = runtime->lookupFunction(0x1101B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116538u; }
        if (ctx->pc != 0x116538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001101B0_0x1101b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116538u; }
        if (ctx->pc != 0x116538u) { return; }
    }
    ctx->pc = 0x116538u;
label_116538:
    // 0x116538: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x116538u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x11653c: 0x64420030  daddiu      $v0, $v0, 0x30
    ctx->pc = 0x11653cu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)48);
    // 0x116540: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x116540u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116544: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x116544u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x116548: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x116548u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x11654c: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x11654Cu;
    SET_GPR_U32(ctx, 31, 0x116554u);
    ctx->pc = 0x116550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11654Cu;
            // 0x116550: 0xa2020000  sb          $v0, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116554u; }
        if (ctx->pc != 0x116554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116554u; }
        if (ctx->pc != 0x116554u) { return; }
    }
    ctx->pc = 0x116554u;
label_116554:
    // 0x116554: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x116554u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116558: 0x1620fff5  bnez        $s1, . + 4 + (-0xB << 2)
    ctx->pc = 0x116558u;
    {
        const bool branch_taken_0x116558 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x11655Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116558u;
            // 0x11655c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116558) {
            ctx->pc = 0x116530u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116530;
        }
    }
    ctx->pc = 0x116560u;
    // 0x116560: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x116560u;
    {
        const bool branch_taken_0x116560 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x116560) {
            ctx->pc = 0x11656Cu;
            goto label_11656c;
        }
    }
    ctx->pc = 0x116568u;
label_116568:
    // 0x116568: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x116568u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_11656c:
    // 0x11656c: 0x12800002  beqz        $s4, . + 4 + (0x2 << 2)
    ctx->pc = 0x11656Cu;
    {
        const bool branch_taken_0x11656c = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x116570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11656Cu;
            // 0x116570: 0x290102b  sltu        $v0, $s4, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11656c) {
            ctx->pc = 0x116578u;
            goto label_116578;
        }
    }
    ctx->pc = 0x116574u;
    // 0x116574: 0x282800b  movn        $s0, $s4, $v0
    ctx->pc = 0x116574u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 20));
label_116578:
    // 0x116578: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x116578u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11657c: 0x10400091  beqz        $v0, . + 4 + (0x91 << 2)
    ctx->pc = 0x11657Cu;
    {
        const bool branch_taken_0x11657c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x116580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11657Cu;
            // 0x116580: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11657c) {
            ctx->pc = 0x1167C4u;
            goto label_1167c4;
        }
    }
    ctx->pc = 0x116584u;
    // 0x116584: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x116584u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
label_116588:
    // 0x116588: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x116588u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x11658c: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x11658cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116590: 0x42603  sra         $a0, $a0, 24
    ctx->pc = 0x116590u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0x116594: 0x40f809  jalr        $v0
    ctx->pc = 0x116594u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x11659Cu);
        ctx->pc = 0x116598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116594u;
            // 0x116598: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11659Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11659Cu; }
            if (ctx->pc != 0x11659Cu) { return; }
        }
        }
    }
    ctx->pc = 0x11659Cu;
label_11659c:
    // 0x11659c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x11659cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1165a0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1165A0u;
    {
        const bool branch_taken_0x1165a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1165A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165A0u;
            // 0x1165a4: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165a0) {
            ctx->pc = 0x116588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116588;
        }
    }
    ctx->pc = 0x1165A8u;
    // 0x1165a8: 0x10000087  b           . + 4 + (0x87 << 2)
    ctx->pc = 0x1165A8u;
    {
        const bool branch_taken_0x1165a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1165ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165A8u;
            // 0x1165ac: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165a8) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x1165B0u;
label_1165b0:
    // 0x1165b0: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1165b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1165b4: 0x14e20004  bne         $a3, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1165B4u;
    {
        const bool branch_taken_0x1165b4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x1165B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165B4u;
            // 0x1165b8: 0x24020068  addiu       $v0, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165b4) {
            ctx->pc = 0x1165C8u;
            goto label_1165c8;
        }
    }
    ctx->pc = 0x1165BCu;
    // 0x1165bc: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x1165bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x1165c0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1165C0u;
    {
        const bool branch_taken_0x1165c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1165C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165C0u;
            // 0x1165c4: 0xde71fff8  ld          $s1, -0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165c0) {
            ctx->pc = 0x1165DCu;
            goto label_1165dc;
        }
    }
    ctx->pc = 0x1165C8u;
label_1165c8:
    // 0x1165c8: 0x14e20003  bne         $a3, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1165C8u;
    {
        const bool branch_taken_0x1165c8 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x1165CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165C8u;
            // 0x1165cc: 0x26730008  addiu       $s3, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165c8) {
            ctx->pc = 0x1165D8u;
            goto label_1165d8;
        }
    }
    ctx->pc = 0x1165D0u;
    // 0x1165d0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1165D0u;
    {
        const bool branch_taken_0x1165d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1165D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165D0u;
            // 0x1165d4: 0x9671fff8  lhu         $s1, -0x8($s3) (Delay Slot)
        SET_GPR_U32(ctx, 17, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165d0) {
            ctx->pc = 0x1165DCu;
            goto label_1165dc;
        }
    }
    ctx->pc = 0x1165D8u;
label_1165d8:
    // 0x1165d8: 0x9e71fff8  lwu         $s1, -0x8($s3)
    ctx->pc = 0x1165d8u;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 19), 4294967288)));
label_1165dc:
    // 0x1165dc: 0x27b0001f  addiu       $s0, $sp, 0x1F
    ctx->pc = 0x1165dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 31));
    // 0x1165e0: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1165E0u;
    {
        const bool branch_taken_0x1165e0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1165E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165E0u;
            // 0x1165e4: 0xa3a0001f  sb          $zero, 0x1F($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 31), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165e0) {
            ctx->pc = 0x1165FCu;
            goto label_1165fc;
        }
    }
    ctx->pc = 0x1165E8u;
    // 0x1165e8: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x1165e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1165ec: 0x27b0001e  addiu       $s0, $sp, 0x1E
    ctx->pc = 0x1165ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 30));
    // 0x1165f0: 0xa3a2001e  sb          $v0, 0x1E($sp)
    ctx->pc = 0x1165f0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 30), (uint8_t)GPR_U32(ctx, 2));
    // 0x1165f4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1165F4u;
    {
        const bool branch_taken_0x1165f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1165F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1165F4u;
            // 0x1165f8: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1165f4) {
            ctx->pc = 0x116638u;
            goto label_116638;
        }
    }
    ctx->pc = 0x1165FCu;
label_1165fc:
    // 0x1165fc: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1165fcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x116600: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x116600u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116604: 0x0  nop
    ctx->pc = 0x116604u;
    // NOP
label_116608:
    // 0x116608: 0xc044370  jal         func_110DC0
    ctx->pc = 0x116608u;
    SET_GPR_U32(ctx, 31, 0x116610u);
    ctx->pc = 0x11660Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116608u;
            // 0x11660c: 0x2405000a  addiu       $a1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110DC0u;
    if (runtime->hasFunction(0x110DC0u)) {
        auto targetFn = runtime->lookupFunction(0x110DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116610u; }
        if (ctx->pc != 0x116610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110DC0_0x110dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116610u; }
        if (ctx->pc != 0x116610u) { return; }
    }
    ctx->pc = 0x116610u;
label_116610:
    // 0x116610: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x116610u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x116614: 0x64420030  daddiu      $v0, $v0, 0x30
    ctx->pc = 0x116614u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)48);
    // 0x116618: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x116618u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11661c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x11661cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x116620: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x116620u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x116624: 0xc044210  jal         func_110840
    ctx->pc = 0x116624u;
    SET_GPR_U32(ctx, 31, 0x11662Cu);
    ctx->pc = 0x116628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116624u;
            // 0x116628: 0xa2020000  sb          $v0, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110840u;
    if (runtime->hasFunction(0x110840u)) {
        auto targetFn = runtime->lookupFunction(0x110840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11662Cu; }
        if (ctx->pc != 0x11662Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110840_0x110840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11662Cu; }
        if (ctx->pc != 0x11662Cu) { return; }
    }
    ctx->pc = 0x11662Cu;
label_11662c:
    // 0x11662c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11662cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116630: 0x1620fff5  bnez        $s1, . + 4 + (-0xB << 2)
    ctx->pc = 0x116630u;
    {
        const bool branch_taken_0x116630 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x116634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116630u;
            // 0x116634: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116630) {
            ctx->pc = 0x116608u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116608;
        }
    }
    ctx->pc = 0x116638u;
label_116638:
    // 0x116638: 0x12800002  beqz        $s4, . + 4 + (0x2 << 2)
    ctx->pc = 0x116638u;
    {
        const bool branch_taken_0x116638 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x11663Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116638u;
            // 0x11663c: 0x290102b  sltu        $v0, $s4, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x116638) {
            ctx->pc = 0x116644u;
            goto label_116644;
        }
    }
    ctx->pc = 0x116640u;
    // 0x116640: 0x282800b  movn        $s0, $s4, $v0
    ctx->pc = 0x116640u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 20));
label_116644:
    // 0x116644: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x116644u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x116648: 0x1040005e  beqz        $v0, . + 4 + (0x5E << 2)
    ctx->pc = 0x116648u;
    {
        const bool branch_taken_0x116648 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11664Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116648u;
            // 0x11664c: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116648) {
            ctx->pc = 0x1167C4u;
            goto label_1167c4;
        }
    }
    ctx->pc = 0x116650u;
    // 0x116650: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x116650u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x116654: 0x0  nop
    ctx->pc = 0x116654u;
    // NOP
label_116658:
    // 0x116658: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x116658u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x11665c: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x11665cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116660: 0x42603  sra         $a0, $a0, 24
    ctx->pc = 0x116660u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0x116664: 0x40f809  jalr        $v0
    ctx->pc = 0x116664u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x11666Cu);
        ctx->pc = 0x116668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116664u;
            // 0x116668: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11666Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11666Cu; }
            if (ctx->pc != 0x11666Cu) { return; }
        }
        }
    }
    ctx->pc = 0x11666Cu;
label_11666c:
    // 0x11666c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x11666cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x116670: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x116670u;
    {
        const bool branch_taken_0x116670 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x116674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116670u;
            // 0x116674: 0x92040000  lbu         $a0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116670) {
            ctx->pc = 0x116658u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116658;
        }
    }
    ctx->pc = 0x116678u;
    // 0x116678: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x116678u;
    {
        const bool branch_taken_0x116678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11667Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116678u;
            // 0x11667c: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116678) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x116680u;
label_116680:
    // 0x116680: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x116680u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x116684: 0xc04491c  jal         func_112470
    ctx->pc = 0x116684u;
    SET_GPR_U32(ctx, 31, 0x11668Cu);
    ctx->pc = 0x116688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116684u;
            // 0x116688: 0xde64fff8  ld          $a0, -0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 4294967288)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11668Cu; }
        if (ctx->pc != 0x11668Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11668Cu; }
        if (ctx->pc != 0x11668Cu) { return; }
    }
    ctx->pc = 0x11668Cu;
label_11668c:
    // 0x11668c: 0x46000306  mov.s       $f12, $f0
    ctx->pc = 0x11668cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[0]);
    // 0x116690: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x116690u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x116694: 0x46006032  c.eq.s      $f12, $f0
    ctx->pc = 0x116694u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x116698: 0x0  nop
    ctx->pc = 0x116698u;
    // NOP
    // 0x11669c: 0x45000007  bc1f        . + 4 + (0x7 << 2)
    ctx->pc = 0x11669Cu;
    {
        const bool branch_taken_0x11669c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1166A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11669Cu;
            // 0x1166a0: 0x3c150021  lui         $s5, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11669c) {
            ctx->pc = 0x1166BCu;
            goto label_1166bc;
        }
    }
    ctx->pc = 0x1166A4u;
    // 0x1166a4: 0x24040030  addiu       $a0, $zero, 0x30
    ctx->pc = 0x1166a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1166a8: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x1166a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x1166ac: 0x40f809  jalr        $v0
    ctx->pc = 0x1166ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1166B4u);
        ctx->pc = 0x1166B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1166ACu;
            // 0x1166b0: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1166B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1166B4u; }
            if (ctx->pc != 0x1166B4u) { return; }
        }
        }
    }
    ctx->pc = 0x1166B4u;
label_1166b4:
    // 0x1166b4: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1166B4u;
    {
        const bool branch_taken_0x1166b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1166B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1166B4u;
            // 0x1166b8: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1166b4) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x1166BCu;
label_1166bc:
    // 0x1166bc: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x1166BCu;
    SET_GPR_U32(ctx, 31, 0x1166C4u);
    ctx->pc = 0x1166C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1166BCu;
            // 0x1166c0: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1166C4u; }
        if (ctx->pc != 0x1166C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1166C4u; }
        if (ctx->pc != 0x1166C4u) { return; }
    }
    ctx->pc = 0x1166C4u;
label_1166c4:
    // 0x1166c4: 0xc04582c  jal         func_1160B0
    ctx->pc = 0x1166C4u;
    SET_GPR_U32(ctx, 31, 0x1166CCu);
    ctx->pc = 0x1166C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1166C4u;
            // 0x1166c8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1160B0u;
    if (runtime->hasFunction(0x1160B0u)) {
        auto targetFn = runtime->lookupFunction(0x1160B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1166CCu; }
        if (ctx->pc != 0x1166CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001160B0_0x1160b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1166CCu; }
        if (ctx->pc != 0x1166CCu) { return; }
    }
    ctx->pc = 0x1166CCu;
label_1166cc:
    // 0x1166cc: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1166CCu;
    {
        const bool branch_taken_0x1166cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1166D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1166CCu;
            // 0x1166d0: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1166cc) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x1166D4u;
label_1166d4:
    // 0x1166d4: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x1166d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x1166d8: 0x8e63fff8  lw          $v1, -0x8($s3)
    ctx->pc = 0x1166d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4294967288)));
    // 0x1166dc: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x1166dcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1166e0: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1166E0u;
    {
        const bool branch_taken_0x1166e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1166E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1166E0u;
            // 0x1166e4: 0x90640000  lbu         $a0, 0x0($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1166e0) {
            ctx->pc = 0x116740u;
            goto label_116740;
        }
    }
    ctx->pc = 0x1166E8u;
    // 0x1166e8: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x1166e8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x1166ec: 0x24040028  addiu       $a0, $zero, 0x28
    ctx->pc = 0x1166ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1166f0: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x1166f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x1166f4: 0x40f809  jalr        $v0
    ctx->pc = 0x1166F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1166FCu);
        ctx->pc = 0x1166F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1166F4u;
            // 0x1166f8: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1166FCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1166FCu; }
            if (ctx->pc != 0x1166FCu) { return; }
        }
        }
    }
    ctx->pc = 0x1166FCu;
label_1166fc:
    // 0x1166fc: 0x8ea39d44  lw          $v1, -0x62BC($s5)
    ctx->pc = 0x1166fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116700: 0x60f809  jalr        $v1
    ctx->pc = 0x116700u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x116708u);
        ctx->pc = 0x116704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116700u;
            // 0x116704: 0x2404006e  addiu       $a0, $zero, 0x6E (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 110));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116708u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116708u; }
            if (ctx->pc != 0x116708u) { return; }
        }
        }
    }
    ctx->pc = 0x116708u;
label_116708:
    // 0x116708: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x116708u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x11670c: 0x40f809  jalr        $v0
    ctx->pc = 0x11670Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x116714u);
        ctx->pc = 0x116710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11670Cu;
            // 0x116710: 0x24040075  addiu       $a0, $zero, 0x75 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 117));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116714u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116714u; }
            if (ctx->pc != 0x116714u) { return; }
        }
        }
    }
    ctx->pc = 0x116714u;
label_116714:
    // 0x116714: 0x8ea39d44  lw          $v1, -0x62BC($s5)
    ctx->pc = 0x116714u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116718: 0x60f809  jalr        $v1
    ctx->pc = 0x116718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x116720u);
        ctx->pc = 0x11671Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116718u;
            // 0x11671c: 0x2404006c  addiu       $a0, $zero, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116720u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116720u; }
            if (ctx->pc != 0x116720u) { return; }
        }
        }
    }
    ctx->pc = 0x116720u;
label_116720:
    // 0x116720: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x116720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116724: 0x40f809  jalr        $v0
    ctx->pc = 0x116724u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x11672Cu);
        ctx->pc = 0x116728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116724u;
            // 0x116728: 0x2404006c  addiu       $a0, $zero, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11672Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11672Cu; }
            if (ctx->pc != 0x11672Cu) { return; }
        }
        }
    }
    ctx->pc = 0x11672Cu;
label_11672c:
    // 0x11672c: 0x8ea39d44  lw          $v1, -0x62BC($s5)
    ctx->pc = 0x11672cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116730: 0x60f809  jalr        $v1
    ctx->pc = 0x116730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x116738u);
        ctx->pc = 0x116734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116730u;
            // 0x116734: 0x24040029  addiu       $a0, $zero, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 41));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116738u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116738u; }
            if (ctx->pc != 0x116738u) { return; }
        }
        }
    }
    ctx->pc = 0x116738u;
label_116738:
    // 0x116738: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x116738u;
    {
        const bool branch_taken_0x116738 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11673Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116738u;
            // 0x11673c: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116738) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x116740u;
label_116740:
    // 0x116740: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x116740u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116744: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x116744u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x116748: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x116748u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x11674c: 0x0  nop
    ctx->pc = 0x11674cu;
    // NOP
label_116750:
    // 0x116750: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x116750u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x116754: 0x8ea39d44  lw          $v1, -0x62BC($s5)
    ctx->pc = 0x116754u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116758: 0x42603  sra         $a0, $a0, 24
    ctx->pc = 0x116758u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
    // 0x11675c: 0x60f809  jalr        $v1
    ctx->pc = 0x11675Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x116764u);
        ctx->pc = 0x116760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11675Cu;
            // 0x116760: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116764u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116764u; }
            if (ctx->pc != 0x116764u) { return; }
        }
        }
    }
    ctx->pc = 0x116764u;
label_116764:
    // 0x116764: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x116764u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x116768: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x116768u;
    {
        const bool branch_taken_0x116768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11676Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116768u;
            // 0x11676c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116768) {
            ctx->pc = 0x116750u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116750;
        }
    }
    ctx->pc = 0x116770u;
    // 0x116770: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x116770u;
    {
        const bool branch_taken_0x116770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116770u;
            // 0x116774: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116770) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x116778u;
label_116778:
    // 0x116778: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x116778u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x11677c: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x11677cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x116780: 0x8271fff8  lb          $s1, -0x8($s3)
    ctx->pc = 0x116780u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 4294967288)));
    // 0x116784: 0x8ea29d44  lw          $v0, -0x62BC($s5)
    ctx->pc = 0x116784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942020)));
    // 0x116788: 0x11203c  dsll32      $a0, $s1, 0
    ctx->pc = 0x116788u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 0));
    // 0x11678c: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x11678cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x116790: 0x40f809  jalr        $v0
    ctx->pc = 0x116790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x116798u);
        ctx->pc = 0x116794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116790u;
            // 0x116794: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x116798u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x116798u; }
            if (ctx->pc != 0x116798u) { return; }
        }
        }
    }
    ctx->pc = 0x116798u;
label_116798:
    // 0x116798: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x116798u;
    {
        const bool branch_taken_0x116798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11679Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116798u;
            // 0x11679c: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116798) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x1167A0u;
label_1167a0:
    // 0x1167a0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1167a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1167a4: 0x8c439d44  lw          $v1, -0x62BC($v0)
    ctx->pc = 0x1167a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942020)));
    // 0x1167a8: 0x60f809  jalr        $v1
    ctx->pc = 0x1167A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1167B0u);
        ctx->pc = 0x1167ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1167A8u;
            // 0x1167ac: 0x26120001  addiu       $s2, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1167B0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1167B0u; }
            if (ctx->pc != 0x1167B0u) { return; }
        }
        }
    }
    ctx->pc = 0x1167B0u;
label_1167b0:
    // 0x1167b0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1167B0u;
    {
        const bool branch_taken_0x1167b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1167B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1167B0u;
            // 0x1167b4: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1167b0) {
            ctx->pc = 0x1167C8u;
            goto label_1167c8;
        }
    }
    ctx->pc = 0x1167B8u;
label_1167b8:
    // 0x1167b8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1167B8u;
    {
        const bool branch_taken_0x1167b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1167BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1167B8u;
            // 0x1167bc: 0x26120001  addiu       $s2, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1167b8) {
            ctx->pc = 0x1167C4u;
            goto label_1167c4;
        }
    }
    ctx->pc = 0x1167C0u;
label_1167c0:
    // 0x1167c0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1167c0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1167c4:
    // 0x1167c4: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x1167c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1167c8:
    // 0x1167c8: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1167c8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1167cc: 0x1440fea2  bnez        $v0, . + 4 + (-0x15E << 2)
    ctx->pc = 0x1167CCu;
    {
        const bool branch_taken_0x1167cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1167D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1167CCu;
            // 0x1167d0: 0x92030000  lbu         $v1, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1167cc) {
            ctx->pc = 0x116258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116258;
        }
    }
    ctx->pc = 0x1167D4u;
label_1167d4:
    // 0x1167d4: 0x12c00004  beqz        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x1167D4u;
    {
        const bool branch_taken_0x1167d4 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1167D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1167D4u;
            // 0x1167d8: 0xdfbf0090  ld          $ra, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1167d4) {
            ctx->pc = 0x1167E8u;
            goto label_1167e8;
        }
    }
    ctx->pc = 0x1167DCu;
    // 0x1167dc: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1167DCu;
    SET_GPR_U32(ctx, 31, 0x1167E4u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1167E4u; }
        if (ctx->pc != 0x1167E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1167E4u; }
        if (ctx->pc != 0x1167E4u) { return; }
    }
    ctx->pc = 0x1167E4u;
label_1167e4:
    // 0x1167e4: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1167e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1167e8:
    // 0x1167e8: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x1167e8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1167ec: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x1167ecu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1167f0: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x1167f0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1167f4: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x1167f4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1167f8: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1167f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1167fc: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x1167fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x116800: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x116800u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116804: 0x3e00008  jr          $ra
    ctx->pc = 0x116804u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116804u;
            // 0x116808: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116248u: goto label_116248;
            case 0x116258u: goto label_116258;
            case 0x116270u: goto label_116270;
            case 0x116274u: goto label_116274;
            case 0x116278u: goto label_116278;
            case 0x1162ACu: goto label_1162ac;
            case 0x1162F4u: goto label_1162f4;
            case 0x1162F8u: goto label_1162f8;
            case 0x116308u: goto label_116308;
            case 0x116330u: goto label_116330;
            case 0x116334u: goto label_116334;
            case 0x11633Cu: goto label_11633c;
            case 0x116344u: goto label_116344;
            case 0x11635Cu: goto label_11635c;
            case 0x11636Cu: goto label_11636c;
            case 0x116370u: goto label_116370;
            case 0x116390u: goto label_116390;
            case 0x116398u: goto label_116398;
            case 0x1163B8u: goto label_1163b8;
            case 0x1163C4u: goto label_1163c4;
            case 0x1163D8u: goto label_1163d8;
            case 0x1163ECu: goto label_1163ec;
            case 0x116400u: goto label_116400;
            case 0x116418u: goto label_116418;
            case 0x116428u: goto label_116428;
            case 0x11642Cu: goto label_11642c;
            case 0x11644Cu: goto label_11644c;
            case 0x116450u: goto label_116450;
            case 0x116464u: goto label_116464;
            case 0x116478u: goto label_116478;
            case 0x116484u: goto label_116484;
            case 0x116498u: goto label_116498;
            case 0x1164ACu: goto label_1164ac;
            case 0x1164C0u: goto label_1164c0;
            case 0x1164D8u: goto label_1164d8;
            case 0x1164E8u: goto label_1164e8;
            case 0x1164ECu: goto label_1164ec;
            case 0x116508u: goto label_116508;
            case 0x116520u: goto label_116520;
            case 0x116530u: goto label_116530;
            case 0x116538u: goto label_116538;
            case 0x116554u: goto label_116554;
            case 0x116568u: goto label_116568;
            case 0x11656Cu: goto label_11656c;
            case 0x116578u: goto label_116578;
            case 0x116588u: goto label_116588;
            case 0x11659Cu: goto label_11659c;
            case 0x1165B0u: goto label_1165b0;
            case 0x1165C8u: goto label_1165c8;
            case 0x1165D8u: goto label_1165d8;
            case 0x1165DCu: goto label_1165dc;
            case 0x1165FCu: goto label_1165fc;
            case 0x116608u: goto label_116608;
            case 0x116610u: goto label_116610;
            case 0x11662Cu: goto label_11662c;
            case 0x116638u: goto label_116638;
            case 0x116644u: goto label_116644;
            case 0x116658u: goto label_116658;
            case 0x11666Cu: goto label_11666c;
            case 0x116680u: goto label_116680;
            case 0x11668Cu: goto label_11668c;
            case 0x1166B4u: goto label_1166b4;
            case 0x1166BCu: goto label_1166bc;
            case 0x1166C4u: goto label_1166c4;
            case 0x1166CCu: goto label_1166cc;
            case 0x1166D4u: goto label_1166d4;
            case 0x1166FCu: goto label_1166fc;
            case 0x116708u: goto label_116708;
            case 0x116714u: goto label_116714;
            case 0x116720u: goto label_116720;
            case 0x11672Cu: goto label_11672c;
            case 0x116738u: goto label_116738;
            case 0x116740u: goto label_116740;
            case 0x116750u: goto label_116750;
            case 0x116764u: goto label_116764;
            case 0x116778u: goto label_116778;
            case 0x116798u: goto label_116798;
            case 0x1167A0u: goto label_1167a0;
            case 0x1167B0u: goto label_1167b0;
            case 0x1167B8u: goto label_1167b8;
            case 0x1167C0u: goto label_1167c0;
            case 0x1167C4u: goto label_1167c4;
            case 0x1167C8u: goto label_1167c8;
            case 0x1167D4u: goto label_1167d4;
            case 0x1167E4u: goto label_1167e4;
            case 0x1167E8u: goto label_1167e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11680Cu;
    // 0x11680c: 0x0  nop
    ctx->pc = 0x11680cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
