#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161EE0
// Address: 0x161ee0 - 0x161f50
void sub_00161EE0_0x161ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161EE0_0x161ee0");
#endif

    switch (ctx->pc) {
        case 0x161f04u: goto label_161f04;
        case 0x161f18u: goto label_161f18;
        default: break;
    }

    ctx->pc = 0x161ee0u;

    // 0x161ee0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x161ee4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x161ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x161ee8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x161ee8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161eec: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x161eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x161ef0: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x161ef0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ef4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x161ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x161ef8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x161ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x161efc: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161EFCu;
    SET_GPR_U32(ctx, 31, 0x161F04u);
    ctx->pc = 0x161F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161EFCu;
            // 0x161f00: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F04u; }
        if (ctx->pc != 0x161F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F04u; }
        if (ctx->pc != 0x161F04u) { return; }
    }
    ctx->pc = 0x161F04u;
label_161f04:
    // 0x161f04: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x161f04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161f08: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161f08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161f0c: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x161f0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x161f10: 0xc05f512  jal         func_17D448
    ctx->pc = 0x161F10u;
    SET_GPR_U32(ctx, 31, 0x161F18u);
    ctx->pc = 0x161F14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161F10u;
            // 0x161f14: 0x27a70008  addiu       $a3, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D448u;
    if (runtime->hasFunction(0x17D448u)) {
        auto targetFn = runtime->lookupFunction(0x17D448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F18u; }
        if (ctx->pc != 0x161F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D448_0x17d448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F18u; }
        if (ctx->pc != 0x161F18u) { return; }
    }
    ctx->pc = 0x161F18u;
label_161f18:
    // 0x161f18: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x161f18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161f1c: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x161f1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161f20: 0x38430001  xori        $v1, $v0, 0x1
    ctx->pc = 0x161f20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x161f24: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x161f24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x161f28: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x161f28u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x161f2c: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x161f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
    // 0x161f30: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x161f30u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x161f34: 0xae450000  sw          $a1, 0x0($s2)
    ctx->pc = 0x161f34u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 5));
    // 0x161f38: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x161f38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161f3c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x161f3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161f40: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x161f40u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x161f44: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x161f44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x161f48: 0x3e00008  jr          $ra
    ctx->pc = 0x161F48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161F48u;
            // 0x161f4c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161F04u: goto label_161f04;
            case 0x161F18u: goto label_161f18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161F50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
