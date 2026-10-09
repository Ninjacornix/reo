#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171AC8
// Address: 0x171ac8 - 0x171b38
void sub_00171AC8_0x171ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171AC8_0x171ac8");
#endif

    switch (ctx->pc) {
        case 0x171aecu: goto label_171aec;
        default: break;
    }

    ctx->pc = 0x171ac8u;

    // 0x171ac8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x171ac8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x171acc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x171accu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171ad0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x171ad0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171ad4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x171ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x171ad8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x171ad8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171adc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x171adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x171ae0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x171ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x171ae4: 0xc05c54c  jal         func_171530
    ctx->pc = 0x171AE4u;
    SET_GPR_U32(ctx, 31, 0x171AECu);
    ctx->pc = 0x171AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171AE4u;
            // 0x171ae8: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171530u;
    if (runtime->hasFunction(0x171530u)) {
        auto targetFn = runtime->lookupFunction(0x171530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171AECu; }
        if (ctx->pc != 0x171AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171530_0x171530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171AECu; }
        if (ctx->pc != 0x171AECu) { return; }
    }
    ctx->pc = 0x171AECu;
label_171aec:
    // 0x171aec: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x171aecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171af0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x171AF0u;
    {
        const bool branch_taken_0x171af0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x171AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171AF0u;
            // 0x171af4: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x171af0) {
            ctx->pc = 0x171B18u;
            goto label_171b18;
        }
    }
    ctx->pc = 0x171AF8u;
    // 0x171af8: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x171af8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171afc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171afcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171b00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171b00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171b04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x171b04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171b08: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x171b08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x171b0c: 0x3e00008  jr          $ra
    ctx->pc = 0x171B0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171B0Cu;
            // 0x171b10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171AECu: goto label_171aec;
            case 0x171B18u: goto label_171b18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171B14u;
    // 0x171b14: 0x0  nop
    ctx->pc = 0x171b14u;
    // NOP
label_171b18:
    // 0x171b18: 0x8e441b30  lw          $a0, 0x1B30($s2)
    ctx->pc = 0x171b18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 6960)));
    // 0x171b1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171b1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171b20: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171b20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171b24: 0x24840a48  addiu       $a0, $a0, 0xA48
    ctx->pc = 0x171b24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2632));
    // 0x171b28: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x171b28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171b2c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x171b2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x171b30: 0x805c620  j           func_171880
    ctx->pc = 0x171B30u;
    ctx->pc = 0x171B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171B30u;
            // 0x171b34: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171880u;
    if (runtime->hasFunction(0x171880u)) {
        auto targetFn = runtime->lookupFunction(0x171880u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00171880_0x171880(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x171B38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
