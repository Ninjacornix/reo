#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001731A0
// Address: 0x1731a0 - 0x173210
void sub_001731A0_0x1731a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001731A0_0x1731a0");
#endif

    switch (ctx->pc) {
        case 0x1731d4u: goto label_1731d4;
        case 0x1731f4u: goto label_1731f4;
        default: break;
    }

    ctx->pc = 0x1731a0u;

    // 0x1731a0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1731a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1731a4: 0x248309a0  addiu       $v1, $a0, 0x9A0
    ctx->pc = 0x1731a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 2464));
    // 0x1731a8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1731a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1731ac: 0x2405fffc  addiu       $a1, $zero, -0x4
    ctx->pc = 0x1731acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1731b0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1731b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1731b4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1731b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1731b8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1731b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1731bc: 0x8c700050  lw          $s0, 0x50($v1)
    ctx->pc = 0x1731bcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 80)));
    // 0x1731c0: 0x1205000d  beq         $s0, $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x1731C0u;
    {
        const bool branch_taken_0x1731c0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 5));
        ctx->pc = 0x1731C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1731C0u;
            // 0x1731c4: 0x8c710054  lw          $s1, 0x54($v1) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 84)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1731c0) {
            ctx->pc = 0x1731F8u;
            goto label_1731f8;
        }
    }
    ctx->pc = 0x1731C8u;
    // 0x1731c8: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x1731c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x1731cc: 0xc05d8d4  jal         func_176350
    ctx->pc = 0x1731CCu;
    SET_GPR_U32(ctx, 31, 0x1731D4u);
    ctx->pc = 0x1731D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1731CCu;
            // 0x1731d0: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176350u;
    if (runtime->hasFunction(0x176350u)) {
        auto targetFn = runtime->lookupFunction(0x176350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1731D4u; }
        if (ctx->pc != 0x1731D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176350_0x176350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1731D4u; }
        if (ctx->pc != 0x1731D4u) { return; }
    }
    ctx->pc = 0x1731D4u;
label_1731d4:
    // 0x1731d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1731d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1731d8: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1731d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1731dc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1731dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1731e0: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x1731e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1731e4: 0x4600004  bltz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1731E4u;
    {
        const bool branch_taken_0x1731e4 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1731E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1731E4u;
            // 0x1731e8: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1731e4) {
            ctx->pc = 0x1731F8u;
            goto label_1731f8;
        }
    }
    ctx->pc = 0x1731ECu;
    // 0x1731ec: 0xc05407a  jal         func_1501E8
    ctx->pc = 0x1731ECu;
    SET_GPR_U32(ctx, 31, 0x1731F4u);
    ctx->pc = 0x1731F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1731ECu;
            // 0x1731f0: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1501E8u;
    if (runtime->hasFunction(0x1501E8u)) {
        auto targetFn = runtime->lookupFunction(0x1501E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1731F4u; }
        if (ctx->pc != 0x1731F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001501E8_0x1501e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1731F4u; }
        if (ctx->pc != 0x1731F4u) { return; }
    }
    ctx->pc = 0x1731F4u;
label_1731f4:
    // 0x1731f4: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1731f4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_1731f8:
    // 0x1731f8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1731f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1731fc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1731fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x173200: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x173200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x173204: 0x3e00008  jr          $ra
    ctx->pc = 0x173204u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173204u;
            // 0x173208: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1731D4u: goto label_1731d4;
            case 0x1731F4u: goto label_1731f4;
            case 0x1731F8u: goto label_1731f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17320Cu;
    // 0x17320c: 0x0  nop
    ctx->pc = 0x17320cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
