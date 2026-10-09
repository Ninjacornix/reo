#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001681E8
// Address: 0x1681e8 - 0x1682e0
void sub_001681E8_0x1681e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001681E8_0x1681e8");
#endif

    switch (ctx->pc) {
        case 0x168210u: goto label_168210;
        case 0x168220u: goto label_168220;
        case 0x1682c8u: goto label_1682c8;
        default: break;
    }

    ctx->pc = 0x1681e8u;

    // 0x1681e8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1681e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1681ec: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1681ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1681f0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1681f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1681f4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1681f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1681f8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1681f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1681fc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1681fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x168200: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x168200u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168204: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x168204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x168208: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x168208u;
    SET_GPR_U32(ctx, 31, 0x168210u);
    ctx->pc = 0x16820Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168208u;
            // 0x16820c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168210u; }
        if (ctx->pc != 0x168210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168210u; }
        if (ctx->pc != 0x168210u) { return; }
    }
    ctx->pc = 0x168210u;
label_168210:
    // 0x168210: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168210u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168214: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x168214u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168218: 0xc05a0b8  jal         func_1682E0
    ctx->pc = 0x168218u;
    SET_GPR_U32(ctx, 31, 0x168220u);
    ctx->pc = 0x16821Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168218u;
            // 0x16821c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1682E0u;
    if (runtime->hasFunction(0x1682E0u)) {
        auto targetFn = runtime->lookupFunction(0x1682E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168220u; }
        if (ctx->pc != 0x168220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001682E0_0x1682e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168220u; }
        if (ctx->pc != 0x168220u) { return; }
    }
    ctx->pc = 0x168220u;
label_168220:
    // 0x168220: 0x8e480008  lw          $t0, 0x8($s2)
    ctx->pc = 0x168220u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x168224: 0x15000008  bnez        $t0, . + 4 + (0x8 << 2)
    ctx->pc = 0x168224u;
    {
        const bool branch_taken_0x168224 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x168228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168224u;
            // 0x168228: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168224) {
            ctx->pc = 0x168248u;
            goto label_168248;
        }
    }
    ctx->pc = 0x16822Cu;
    // 0x16822c: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x16822cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x168230: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x168230u;
    {
        const bool branch_taken_0x168230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168230u;
            // 0x168234: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168230) {
            ctx->pc = 0x16824Cu;
            goto label_16824c;
        }
    }
    ctx->pc = 0x168238u;
    // 0x168238: 0x8e430010  lw          $v1, 0x10($s2)
    ctx->pc = 0x168238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x16823c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x16823cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x168240: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x168240u;
    {
        const bool branch_taken_0x168240 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x168244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168240u;
            // 0x168244: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168240) {
            ctx->pc = 0x168254u;
            goto label_168254;
        }
    }
    ctx->pc = 0x168248u;
label_168248:
    // 0x168248: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x168248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_16824c:
    // 0x16824c: 0xa2420000  sb          $v0, 0x0($s2)
    ctx->pc = 0x16824cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x168250: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x168250u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
label_168254:
    // 0x168254: 0x24420860  addiu       $v0, $v0, 0x860
    ctx->pc = 0x168254u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2144));
    // 0x168258: 0x14820013  bne         $a0, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x168258u;
    {
        const bool branch_taken_0x168258 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x168258) {
            ctx->pc = 0x1682A8u;
            goto label_1682a8;
        }
    }
    ctx->pc = 0x168260u;
    // 0x168260: 0x8e440014  lw          $a0, 0x14($s2)
    ctx->pc = 0x168260u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x168264: 0x8e450018  lw          $a1, 0x18($s2)
    ctx->pc = 0x168264u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x168268: 0x2482000f  addiu       $v0, $a0, 0xF
    ctx->pc = 0x168268u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 15));
    // 0x16826c: 0x2484001e  addiu       $a0, $a0, 0x1E
    ctx->pc = 0x16826cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30));
    // 0x168270: 0x24a3000f  addiu       $v1, $a1, 0xF
    ctx->pc = 0x168270u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x168274: 0x24a5001e  addiu       $a1, $a1, 0x1E
    ctx->pc = 0x168274u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 30));
    // 0x168278: 0x28460000  slti        $a2, $v0, 0x0
    ctx->pc = 0x168278u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16827c: 0x28670000  slti        $a3, $v1, 0x0
    ctx->pc = 0x16827cu;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x168280: 0x86100b  movn        $v0, $a0, $a2
    ctx->pc = 0x168280u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x168284: 0xa7180b  movn        $v1, $a1, $a3
    ctx->pc = 0x168284u;
    if (GPR_U64(ctx, 7) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
    // 0x168288: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x168288u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x16828c: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x16828cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x168290: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x168290u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x168294: 0x28420655  slti        $v0, $v0, 0x655
    ctx->pc = 0x168294u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)1621) ? 1 : 0);
    // 0x168298: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x168298u;
    {
        const bool branch_taken_0x168298 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x168298) {
            ctx->pc = 0x1682A8u;
            goto label_1682a8;
        }
    }
    ctx->pc = 0x1682A0u;
    // 0x1682a0: 0xae400008  sw          $zero, 0x8($s2)
    ctx->pc = 0x1682a0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 0));
    // 0x1682a4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1682a4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1682a8:
    // 0x1682a8: 0x15000004  bnez        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1682A8u;
    {
        const bool branch_taken_0x1682a8 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1682ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1682A8u;
            // 0x1682ac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1682a8) {
            ctx->pc = 0x1682BCu;
            goto label_1682bc;
        }
    }
    ctx->pc = 0x1682B0u;
    // 0x1682b0: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x1682b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1682b4: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1682B4u;
    {
        const bool branch_taken_0x1682b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1682B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1682B4u;
            // 0x1682b8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1682b4) {
            ctx->pc = 0x1682C0u;
            goto label_1682c0;
        }
    }
    ctx->pc = 0x1682BCu;
label_1682bc:
    // 0x1682bc: 0xa2420001  sb          $v0, 0x1($s2)
    ctx->pc = 0x1682bcu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 2));
label_1682c0:
    // 0x1682c0: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1682C0u;
    SET_GPR_U32(ctx, 31, 0x1682C8u);
    ctx->pc = 0x1682C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1682C0u;
            // 0x1682c4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1682C8u; }
        if (ctx->pc != 0x1682C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1682C8u; }
        if (ctx->pc != 0x1682C8u) { return; }
    }
    ctx->pc = 0x1682C8u;
label_1682c8:
    // 0x1682c8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1682c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1682cc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1682ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1682d0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1682d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1682d4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1682d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1682d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1682D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1682DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1682D8u;
            // 0x1682dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168210u: goto label_168210;
            case 0x168220u: goto label_168220;
            case 0x168248u: goto label_168248;
            case 0x16824Cu: goto label_16824c;
            case 0x168254u: goto label_168254;
            case 0x1682A8u: goto label_1682a8;
            case 0x1682BCu: goto label_1682bc;
            case 0x1682C0u: goto label_1682c0;
            case 0x1682C8u: goto label_1682c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1682E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
