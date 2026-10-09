#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188BC0
// Address: 0x188bc0 - 0x188c30
void sub_00188BC0_0x188bc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188BC0_0x188bc0");
#endif

    switch (ctx->pc) {
        case 0x188c04u: goto label_188c04;
        case 0x188c18u: goto label_188c18;
        default: break;
    }

    ctx->pc = 0x188bc0u;

    // 0x188bc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x188bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x188bc4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188bc8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188bc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x188bcc: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188bccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188bd0: 0x3c100029  lui         $s0, 0x29
    ctx->pc = 0x188bd0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)41 << 16));
    // 0x188bd4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x188bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x188bd8: 0x26070c00  addiu       $a3, $s0, 0xC00
    ctx->pc = 0x188bd8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 3072));
    // 0x188bdc: 0x34a51304  ori         $a1, $a1, 0x1304
    ctx->pc = 0x188bdcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4868);
    // 0x188be0: 0xace40004  sw          $a0, 0x4($a3)
    ctx->pc = 0x188be0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 4));
    // 0x188be4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x188be4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188be8: 0x24440b88  addiu       $a0, $v0, 0xB88
    ctx->pc = 0x188be8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 2952));
    // 0x188bec: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x188becu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x188bf0: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x188bf0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188bf4: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x188bf4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188bf8: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x188bf8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x188bfc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x188BFCu;
    SET_GPR_U32(ctx, 31, 0x188C04u);
    ctx->pc = 0x188C00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188BFCu;
            // 0x188c00: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188C04u; }
        if (ctx->pc != 0x188C04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188C04u; }
        if (ctx->pc != 0x188C04u) { return; }
    }
    ctx->pc = 0x188C04u;
label_188c04:
    // 0x188c04: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x188C04u;
    {
        const bool branch_taken_0x188c04 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x188C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188C04u;
            // 0x188c08: 0x8e020c00  lw          $v0, 0xC00($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3072)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188c04) {
            ctx->pc = 0x188C1Cu;
            goto label_188c1c;
        }
    }
    ctx->pc = 0x188C0Cu;
    // 0x188c0c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x188c0cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x188c10: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x188C10u;
    SET_GPR_U32(ctx, 31, 0x188C18u);
    ctx->pc = 0x188C14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188C10u;
            // 0x188c14: 0x24841900  addiu       $a0, $a0, 0x1900 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188C18u; }
        if (ctx->pc != 0x188C18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188C18u; }
        if (ctx->pc != 0x188C18u) { return; }
    }
    ctx->pc = 0x188C18u;
label_188c18:
    // 0x188c18: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x188c18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_188c1c:
    // 0x188c1c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x188c1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188c20: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188c20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x188c24: 0x3e00008  jr          $ra
    ctx->pc = 0x188C24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188C24u;
            // 0x188c28: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188C04u: goto label_188c04;
            case 0x188C18u: goto label_188c18;
            case 0x188C1Cu: goto label_188c1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188C2Cu;
    // 0x188c2c: 0x0  nop
    ctx->pc = 0x188c2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
