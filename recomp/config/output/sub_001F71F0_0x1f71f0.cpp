#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F71F0
// Address: 0x1f71f0 - 0x1f7380
void sub_001F71F0_0x1f71f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F71F0_0x1f71f0");
#endif

    switch (ctx->pc) {
        case 0x1f7240u: goto label_1f7240;
        case 0x1f7264u: goto label_1f7264;
        case 0x1f727cu: goto label_1f727c;
        case 0x1f7288u: goto label_1f7288;
        case 0x1f72c0u: goto label_1f72c0;
        case 0x1f72f0u: goto label_1f72f0;
        case 0x1f7360u: goto label_1f7360;
        default: break;
    }

    ctx->pc = 0x1f71f0u;

    // 0x1f71f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1f71f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1f71f4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1f71f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1f71f8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1f71f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1f71fc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f71fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f7200: 0x3c130037  lui         $s3, 0x37
    ctx->pc = 0x1f7200u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)55 << 16));
    // 0x1f7204: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f7204u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f7208: 0x2673f080  addiu       $s3, $s3, -0xF80
    ctx->pc = 0x1f7208u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294963328));
    // 0x1f720c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f720cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f7210: 0x8e630014  lw          $v1, 0x14($s3)
    ctx->pc = 0x1f7210u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 20)));
    // 0x1f7214: 0x10600052  beqz        $v1, . + 4 + (0x52 << 2)
    ctx->pc = 0x1F7214u;
    {
        const bool branch_taken_0x1f7214 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7214u;
            // 0x1f7218: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7214) {
            ctx->pc = 0x1F7360u;
            goto label_1f7360;
        }
    }
    ctx->pc = 0x1F721Cu;
    // 0x1f721c: 0x3c110036  lui         $s1, 0x36
    ctx->pc = 0x1f721cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)54 << 16));
    // 0x1f7220: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f7220u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f7224: 0x26317080  addiu       $s1, $s1, 0x7080
    ctx->pc = 0x1f7224u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 28800));
    // 0x1f7228: 0x24a59c00  addiu       $a1, $a1, -0x6400
    ctx->pc = 0x1f7228u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941696));
    // 0x1f722c: 0x8e300008  lw          $s0, 0x8($s1)
    ctx->pc = 0x1f722cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1f7230: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f7230u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f7234: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1f7234u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f7238: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1F7238u;
    SET_GPR_U32(ctx, 31, 0x1F7240u);
    ctx->pc = 0x1F723Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7238u;
            // 0x1f723c: 0x2631000c  addiu       $s1, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7240u; }
        if (ctx->pc != 0x1F7240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7240u; }
        if (ctx->pc != 0x1F7240u) { return; }
    }
    ctx->pc = 0x1F7240u;
label_1f7240:
    // 0x1f7240: 0x14400047  bnez        $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x1F7240u;
    {
        const bool branch_taken_0x1f7240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f7240) {
            ctx->pc = 0x1F7360u;
            goto label_1f7360;
        }
    }
    ctx->pc = 0x1F7248u;
    // 0x1f7248: 0x1200000d  beqz        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F7248u;
    {
        const bool branch_taken_0x1f7248 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F724Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7248u;
            // 0x1f724c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7248) {
            ctx->pc = 0x1F7280u;
            goto label_1f7280;
        }
    }
    ctx->pc = 0x1F7250u;
    // 0x1f7250: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1f7250u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1f7254: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1f7254u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f7258: 0x248465a8  addiu       $a0, $a0, 0x65A8
    ctx->pc = 0x1f7258u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26024));
    // 0x1f725c: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1F725Cu;
    SET_GPR_U32(ctx, 31, 0x1F7264u);
    ctx->pc = 0x1F7260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F725Cu;
            // 0x1f7260: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7264u; }
        if (ctx->pc != 0x1F7264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7264u; }
        if (ctx->pc != 0x1F7264u) { return; }
    }
    ctx->pc = 0x1F7264u;
label_1f7264:
    // 0x1f7264: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7264u;
    {
        const bool branch_taken_0x1f7264 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F7268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7264u;
            // 0x1f7268: 0x3c040031  lui         $a0, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7264) {
            ctx->pc = 0x1F727Cu;
            goto label_1f727c;
        }
    }
    ctx->pc = 0x1F726Cu;
    // 0x1f726c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1f726cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f7270: 0x248465a8  addiu       $a0, $a0, 0x65A8
    ctx->pc = 0x1f7270u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26024));
    // 0x1f7274: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1F7274u;
    SET_GPR_U32(ctx, 31, 0x1F727Cu);
    ctx->pc = 0x1F7278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7274u;
            // 0x1f7278: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F727Cu; }
        if (ctx->pc != 0x1F727Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F727Cu; }
        if (ctx->pc != 0x1F727Cu) { return; }
    }
    ctx->pc = 0x1F727Cu;
label_1f727c:
    // 0x1f727c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1f727cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f7280:
    // 0x1f7280: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1F7280u;
    {
        const bool branch_taken_0x1f7280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7280u;
            // 0x1f7284: 0x3c048000  lui         $a0, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7280) {
            ctx->pc = 0x1F734Cu;
            goto label_1f734c;
        }
    }
    ctx->pc = 0x1F7288u;
label_1f7288:
    // 0x1f7288: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1f7288u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1f728c: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x1f728cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1f7290: 0x8e250008  lw          $a1, 0x8($s1)
    ctx->pc = 0x1f7290u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1f7294: 0x16420020  bne         $s2, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1F7294u;
    {
        const bool branch_taken_0x1f7294 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F7298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7294u;
            // 0x1f7298: 0x2631000c  addiu       $s1, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7294) {
            ctx->pc = 0x1F7318u;
            goto label_1f7318;
        }
    }
    ctx->pc = 0x1F729Cu;
    // 0x1f729c: 0xa41024  and         $v0, $a1, $a0
    ctx->pc = 0x1f729cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1f72a0: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1F72A0u;
    {
        const bool branch_taken_0x1f72a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F72A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F72A0u;
            // 0x1f72a4: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f72a0) {
            ctx->pc = 0x1F72E8u;
            goto label_1f72e8;
        }
    }
    ctx->pc = 0x1F72A8u;
    // 0x1f72a8: 0x8e280000  lw          $t0, 0x0($s1)
    ctx->pc = 0x1f72a8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1f72ac: 0x5187c  dsll32      $v1, $a1, 1
    ctx->pc = 0x1f72acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 1));
    // 0x1f72b0: 0x3187e  dsrl32      $v1, $v1, 1
    ctx->pc = 0x1f72b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 1));
    // 0x1f72b4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f72b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f72b8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F72B8u;
    {
        const bool branch_taken_0x1f72b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F72BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F72B8u;
            // 0x1f72bc: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f72b8) {
            ctx->pc = 0x1F72D4u;
            goto label_1f72d4;
        }
    }
    ctx->pc = 0x1F72C0u;
label_1f72c0:
    // 0x1f72c0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1f72c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1f72c4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1f72c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1f72c8: 0xa0e20000  sb          $v0, 0x0($a3)
    ctx->pc = 0x1f72c8u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f72cc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1f72ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1f72d0: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1f72d0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1f72d4:
    // 0x1f72d4: 0xa3102a  slt         $v0, $a1, $v1
    ctx->pc = 0x1f72d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1f72d8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1F72D8u;
    {
        const bool branch_taken_0x1f72d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f72d8) {
            ctx->pc = 0x1F72C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f72c0;
        }
    }
    ctx->pc = 0x1F72E0u;
    // 0x1f72e0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1F72E0u;
    {
        const bool branch_taken_0x1f72e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F72E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F72E0u;
            // 0x1f72e4: 0x26230003  addiu       $v1, $s1, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f72e0) {
            ctx->pc = 0x1F7334u;
            goto label_1f7334;
        }
    }
    ctx->pc = 0x1F72E8u;
label_1f72e8:
    // 0x1f72e8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1F72E8u;
    {
        const bool branch_taken_0x1f72e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F72ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F72E8u;
            // 0x1f72ec: 0x65102a  slt         $v0, $v1, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f72e8) {
            ctx->pc = 0x1F7308u;
            goto label_1f7308;
        }
    }
    ctx->pc = 0x1F72F0u;
label_1f72f0:
    // 0x1f72f0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x1f72f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1f72f4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1f72f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1f72f8: 0xa0e20000  sb          $v0, 0x0($a3)
    ctx->pc = 0x1f72f8u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f72fc: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1f72fcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1f7300: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1f7300u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1f7304: 0x65102a  slt         $v0, $v1, $a1
    ctx->pc = 0x1f7304u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
label_1f7308:
    // 0x1f7308: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1F7308u;
    {
        const bool branch_taken_0x1f7308 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f7308) {
            ctx->pc = 0x1F72F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f72f0;
        }
    }
    ctx->pc = 0x1F7310u;
    // 0x1f7310: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1F7310u;
    {
        const bool branch_taken_0x1f7310 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f7310) {
            ctx->pc = 0x1F7330u;
            goto label_1f7330;
        }
    }
    ctx->pc = 0x1F7318u;
label_1f7318:
    // 0x1f7318: 0xa41024  and         $v0, $a1, $a0
    ctx->pc = 0x1f7318u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1f731c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F731Cu;
    {
        const bool branch_taken_0x1f731c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f731c) {
            ctx->pc = 0x1F732Cu;
            goto label_1f732c;
        }
    }
    ctx->pc = 0x1F7324u;
    // 0x1f7324: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F7324u;
    {
        const bool branch_taken_0x1f7324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7324u;
            // 0x1f7328: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7324) {
            ctx->pc = 0x1F7330u;
            goto label_1f7330;
        }
    }
    ctx->pc = 0x1F732Cu;
label_1f732c:
    // 0x1f732c: 0x2258821  addu        $s1, $s1, $a1
    ctx->pc = 0x1f732cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
label_1f7330:
    // 0x1f7330: 0x26230003  addiu       $v1, $s1, 0x3
    ctx->pc = 0x1f7330u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 3));
label_1f7334:
    // 0x1f7334: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F7334u;
    {
        const bool branch_taken_0x1f7334 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1F7338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7334u;
            // 0x1f7338: 0x31083  sra         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7334) {
            ctx->pc = 0x1F7344u;
            goto label_1f7344;
        }
    }
    ctx->pc = 0x1F733Cu;
    // 0x1f733c: 0x24620003  addiu       $v0, $v1, 0x3
    ctx->pc = 0x1f733cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1f7340: 0x21083  sra         $v0, $v0, 2
    ctx->pc = 0x1f7340u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 2));
label_1f7344:
    // 0x1f7344: 0x28880  sll         $s1, $v0, 2
    ctx->pc = 0x1f7344u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1f7348: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f7348u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1f734c:
    // 0x1f734c: 0xd0102a  slt         $v0, $a2, $s0
    ctx->pc = 0x1f734cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1f7350: 0x1440ffcd  bnez        $v0, . + 4 + (-0x33 << 2)
    ctx->pc = 0x1F7350u;
    {
        const bool branch_taken_0x1f7350 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f7350) {
            ctx->pc = 0x1F7288u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f7288;
        }
    }
    ctx->pc = 0x1F7358u;
    // 0x1f7358: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1F7358u;
    SET_GPR_U32(ctx, 31, 0x1F7360u);
    ctx->pc = 0x1F735Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7358u;
            // 0x1f735c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7360u; }
        if (ctx->pc != 0x1F7360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7360u; }
        if (ctx->pc != 0x1F7360u) { return; }
    }
    ctx->pc = 0x1F7360u;
label_1f7360:
    // 0x1f7360: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1f7360u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1f7364: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1f7364u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f7368: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f7368u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f736c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f736cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f7370: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f7370u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f7374: 0x3e00008  jr          $ra
    ctx->pc = 0x1F7374u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F7378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7374u;
            // 0x1f7378: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F7240u: goto label_1f7240;
            case 0x1F7264u: goto label_1f7264;
            case 0x1F727Cu: goto label_1f727c;
            case 0x1F7280u: goto label_1f7280;
            case 0x1F7288u: goto label_1f7288;
            case 0x1F72C0u: goto label_1f72c0;
            case 0x1F72D4u: goto label_1f72d4;
            case 0x1F72E8u: goto label_1f72e8;
            case 0x1F72F0u: goto label_1f72f0;
            case 0x1F7308u: goto label_1f7308;
            case 0x1F7318u: goto label_1f7318;
            case 0x1F732Cu: goto label_1f732c;
            case 0x1F7330u: goto label_1f7330;
            case 0x1F7334u: goto label_1f7334;
            case 0x1F7344u: goto label_1f7344;
            case 0x1F734Cu: goto label_1f734c;
            case 0x1F7360u: goto label_1f7360;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F737Cu;
    // 0x1f737c: 0x0  nop
    ctx->pc = 0x1f737cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
