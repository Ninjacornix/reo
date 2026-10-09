#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102F78
// Address: 0x102f78 - 0x103000
void sub_00102F78_0x102f78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102F78_0x102f78");
#endif

    switch (ctx->pc) {
        case 0x102fb8u: goto label_102fb8;
        case 0x102fc8u: goto label_102fc8;
        case 0x102fd0u: goto label_102fd0;
        default: break;
    }

    ctx->pc = 0x102f78u;

    // 0x102f78: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x102f78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x102f7c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x102f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x102f80: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x102f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x102f84: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x102f84u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102f88: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102f88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102f8c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x102f8cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102f90: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x102f90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x102f94: 0x3c100100  lui         $s0, 0x100
    ctx->pc = 0x102f94u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)256 << 16));
    // 0x102f98: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x102f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x102f9c: 0xc6800b  movn        $s0, $a2, $a2
    ctx->pc = 0x102f9cu;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 6));
    // 0x102fa0: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x102fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x102fa4: 0x52102b  sltu        $v0, $v0, $s2
    ctx->pc = 0x102fa4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x102fa8: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x102FA8u;
    {
        const bool branch_taken_0x102fa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102FA8u;
            // 0x102fac: 0x3c130023  lui         $s3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102fa8) {
            ctx->pc = 0x102FE0u;
            goto label_102fe0;
        }
    }
    ctx->pc = 0x102FB0u;
    // 0x102fb0: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x102fb0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x102fb4: 0x0  nop
    ctx->pc = 0x102fb4u;
    // NOP
label_102fb8:
    // 0x102fb8: 0x6010005  bgez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x102FB8u;
    {
        const bool branch_taken_0x102fb8 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x102fb8) {
            ctx->pc = 0x102FD0u;
            goto label_102fd0;
        }
    }
    ctx->pc = 0x102FC0u;
    // 0x102fc0: 0xc045a12  jal         func_116848
    ctx->pc = 0x102FC0u;
    SET_GPR_U32(ctx, 31, 0x102FC8u);
    ctx->pc = 0x102FC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102FC0u;
            // 0x102fc4: 0x266476f8  addiu       $a0, $s3, 0x76F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 30456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102FC8u; }
        if (ctx->pc != 0x102FC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102FC8u; }
        if (ctx->pc != 0x102FC8u) { return; }
    }
    ctx->pc = 0x102FC8u;
label_102fc8:
    // 0x102fc8: 0xc040da8  jal         func_1036A0
    ctx->pc = 0x102FC8u;
    SET_GPR_U32(ctx, 31, 0x102FD0u);
    ctx->pc = 0x102FCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102FC8u;
            // 0x102fcc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1036A0u;
    if (runtime->hasFunction(0x1036A0u)) {
        auto targetFn = runtime->lookupFunction(0x1036A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102FD0u; }
        if (ctx->pc != 0x102FD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001036A0_0x1036a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102FD0u; }
        if (ctx->pc != 0x102FD0u) { return; }
    }
    ctx->pc = 0x102FD0u;
label_102fd0:
    // 0x102fd0: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x102fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x102fd4: 0x52102b  sltu        $v0, $v0, $s2
    ctx->pc = 0x102fd4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x102fd8: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x102FD8u;
    {
        const bool branch_taken_0x102fd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102FD8u;
            // 0x102fdc: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102fd8) {
            ctx->pc = 0x102FB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_102fb8;
        }
    }
    ctx->pc = 0x102FE0u;
label_102fe0:
    // 0x102fe0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x102fe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x102fe4: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x102fe4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x102fe8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x102fe8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102fec: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x102fecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102ff0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102ff0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102ff4: 0x3e00008  jr          $ra
    ctx->pc = 0x102FF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102FF4u;
            // 0x102ff8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102FB8u: goto label_102fb8;
            case 0x102FC8u: goto label_102fc8;
            case 0x102FD0u: goto label_102fd0;
            case 0x102FE0u: goto label_102fe0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102FFCu;
    // 0x102ffc: 0x0  nop
    ctx->pc = 0x102ffcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
