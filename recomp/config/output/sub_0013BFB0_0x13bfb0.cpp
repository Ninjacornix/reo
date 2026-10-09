#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BFB0
// Address: 0x13bfb0 - 0x13c008
void sub_0013BFB0_0x13bfb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BFB0_0x13bfb0");
#endif

    switch (ctx->pc) {
        case 0x13bfd4u: goto label_13bfd4;
        case 0x13bfe0u: goto label_13bfe0;
        default: break;
    }

    ctx->pc = 0x13bfb0u;

    // 0x13bfb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13bfb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13bfb4: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x13bfb4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x13bfb8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13bfb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13bfbc: 0x58e00  sll         $s1, $a1, 24
    ctx->pc = 0x13bfbcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x13bfc0: 0x118e03  sra         $s1, $s1, 24
    ctx->pc = 0x13bfc0u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 24));
    // 0x13bfc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13bfc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13bfc8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13bfc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13bfcc: 0xc04efe6  jal         func_13BF98
    ctx->pc = 0x13BFCCu;
    SET_GPR_U32(ctx, 31, 0x13BFD4u);
    ctx->pc = 0x13BFD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BFCCu;
            // 0x13bfd0: 0x42603  sra         $a0, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BF98u;
    if (runtime->hasFunction(0x13BF98u)) {
        auto targetFn = runtime->lookupFunction(0x13BF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BFD4u; }
        if (ctx->pc != 0x13BFD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BF98_0x13bf98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BFD4u; }
        if (ctx->pc != 0x13BFD4u) { return; }
    }
    ctx->pc = 0x13BFD4u;
label_13bfd4:
    // 0x13bfd4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13bfd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bfd8: 0xc04efe6  jal         func_13BF98
    ctx->pc = 0x13BFD8u;
    SET_GPR_U32(ctx, 31, 0x13BFE0u);
    ctx->pc = 0x13BFDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BFD8u;
            // 0x13bfdc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BF98u;
    if (runtime->hasFunction(0x13BF98u)) {
        auto targetFn = runtime->lookupFunction(0x13BF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BFE0u; }
        if (ctx->pc != 0x13BFE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BF98_0x13bf98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BFE0u; }
        if (ctx->pc != 0x13BFE0u) { return; }
    }
    ctx->pc = 0x13BFE0u;
label_13bfe0:
    // 0x13bfe0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x13bfe0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x13bfe4: 0x2028026  xor         $s0, $s0, $v0
    ctx->pc = 0x13bfe4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 2));
    // 0x13bfe8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13bfe8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bfec: 0x70100b  movn        $v0, $v1, $s0
    ctx->pc = 0x13bfecu;
    if (GPR_U64(ctx, 16) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x13bff0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13bff0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13bff4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13bff4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13bff8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13bff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13bffc: 0x3e00008  jr          $ra
    ctx->pc = 0x13BFFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BFFCu;
            // 0x13c000: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13BFD4u: goto label_13bfd4;
            case 0x13BFE0u: goto label_13bfe0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C004u;
    // 0x13c004: 0x0  nop
    ctx->pc = 0x13c004u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
