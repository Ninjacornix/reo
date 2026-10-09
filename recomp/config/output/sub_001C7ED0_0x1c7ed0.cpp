#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7ED0
// Address: 0x1c7ed0 - 0x1c8080
void sub_001C7ED0_0x1c7ed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7ED0_0x1c7ed0");
#endif

    switch (ctx->pc) {
        case 0x1c7f18u: goto label_1c7f18;
        case 0x1c7f44u: goto label_1c7f44;
        case 0x1c7f5cu: goto label_1c7f5c;
        case 0x1c7f68u: goto label_1c7f68;
        case 0x1c7fc0u: goto label_1c7fc0;
        case 0x1c7ff0u: goto label_1c7ff0;
        case 0x1c8008u: goto label_1c8008;
        case 0x1c8018u: goto label_1c8018;
        default: break;
    }

    ctx->pc = 0x1c7ed0u;

    // 0x1c7ed0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1c7ed0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1c7ed4: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1c7ed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1c7ed8: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1c7ed8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1c7edc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c7edcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c7ee0: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x1c7ee0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7ee4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c7ee4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c7ee8: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x1c7ee8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7eec: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c7eecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c7ef0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c7ef0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c7ef4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1c7ef4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7ef8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7ef8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7efc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1c7efcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7f00: 0x16a0002b  bnez        $s5, . + 4 + (0x2B << 2)
    ctx->pc = 0x1C7F00u;
    {
        const bool branch_taken_0x1c7f00 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7F00u;
            // 0x1c7f04: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7f00) {
            ctx->pc = 0x1C7FB0u;
            goto label_1c7fb0;
        }
    }
    ctx->pc = 0x1C7F08u;
    // 0x1c7f08: 0x16800012  bnez        $s4, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C7F08u;
    {
        const bool branch_taken_0x1c7f08 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7F0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7F08u;
            // 0x1c7f0c: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7f08) {
            ctx->pc = 0x1C7F54u;
            goto label_1c7f54;
        }
    }
    ctx->pc = 0x1C7F10u;
    // 0x1c7f10: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C7F10u;
    {
        const bool branch_taken_0x1c7f10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7F10u;
            // 0x1c7f14: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7f10) {
            ctx->pc = 0x1C7F38u;
            goto label_1c7f38;
        }
    }
    ctx->pc = 0x1C7F18u;
label_1c7f18:
    // 0x1c7f18: 0x0  nop
    ctx->pc = 0x1c7f18u;
    // NOP
    // 0x1c7f1c: 0x0  nop
    ctx->pc = 0x1c7f1cu;
    // NOP
    // 0x1c7f20: 0x0  nop
    ctx->pc = 0x1c7f20u;
    // NOP
    // 0x1c7f24: 0x0  nop
    ctx->pc = 0x1c7f24u;
    // NOP
    // 0x1c7f28: 0x0  nop
    ctx->pc = 0x1c7f28u;
    // NOP
    // 0x1c7f2c: 0x0  nop
    ctx->pc = 0x1c7f2cu;
    // NOP
    // 0x1c7f30: 0x0  nop
    ctx->pc = 0x1c7f30u;
    // NOP
    // 0x1c7f34: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c7f34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1c7f38:
    // 0x1c7f38: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c7f38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7f3c: 0xc0471de  jal         func_11C778
    ctx->pc = 0x1C7F3Cu;
    SET_GPR_U32(ctx, 31, 0x1C7F44u);
    ctx->pc = 0x1C7F40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7F3Cu;
            // 0x1c7f40: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C778u;
    if (runtime->hasFunction(0x11C778u)) {
        auto targetFn = runtime->lookupFunction(0x11C778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7F44u; }
        if (ctx->pc != 0x1C7F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C778_0x11c778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7F44u; }
        if (ctx->pc != 0x1C7F44u) { return; }
    }
    ctx->pc = 0x1C7F44u;
label_1c7f44:
    // 0x1c7f44: 0x440fff4  bltz        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1C7F44u;
    {
        const bool branch_taken_0x1c7f44 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c7f44) {
            ctx->pc = 0x1C7F18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c7f18;
        }
    }
    ctx->pc = 0x1C7F4Cu;
    // 0x1c7f4c: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x1C7F4Cu;
    {
        const bool branch_taken_0x1c7f4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7f4c) {
            ctx->pc = 0x1C8058u;
            goto label_1c8058;
        }
    }
    ctx->pc = 0x1C7F54u;
label_1c7f54:
    // 0x1c7f54: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1C7F54u;
    {
        const bool branch_taken_0x1c7f54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7F54u;
            // 0x1c7f58: 0x274182a  slt         $v1, $s3, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7f54) {
            ctx->pc = 0x1C7FA0u;
            goto label_1c7fa0;
        }
    }
    ctx->pc = 0x1C7F5Cu;
label_1c7f5c:
    // 0x1c7f5c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c7f5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7f60: 0xc0471de  jal         func_11C778
    ctx->pc = 0x1C7F60u;
    SET_GPR_U32(ctx, 31, 0x1C7F68u);
    ctx->pc = 0x1C7F64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7F60u;
            // 0x1c7f64: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C778u;
    if (runtime->hasFunction(0x11C778u)) {
        auto targetFn = runtime->lookupFunction(0x11C778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7F68u; }
        if (ctx->pc != 0x1C7F68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C778_0x11c778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7F68u; }
        if (ctx->pc != 0x1C7F68u) { return; }
    }
    ctx->pc = 0x1C7F68u;
label_1c7f68:
    // 0x1c7f68: 0x40082a  slt         $at, $v0, $zero
    ctx->pc = 0x1c7f68u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1c7f6c: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7F6Cu;
    {
        const bool branch_taken_0x1c7f6c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c7f6c) {
            ctx->pc = 0x1C7F7Cu;
            goto label_1c7f7c;
        }
    }
    ctx->pc = 0x1C7F74u;
    // 0x1c7f74: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1C7F74u;
    {
        const bool branch_taken_0x1c7f74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7F74u;
            // 0x1c7f78: 0xdfbf0060  ld          $ra, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7f74) {
            ctx->pc = 0x1C805Cu;
            goto label_1c805c;
        }
    }
    ctx->pc = 0x1C7F7Cu;
label_1c7f7c:
    // 0x1c7f7c: 0x0  nop
    ctx->pc = 0x1c7f7cu;
    // NOP
    // 0x1c7f80: 0x0  nop
    ctx->pc = 0x1c7f80u;
    // NOP
    // 0x1c7f84: 0x0  nop
    ctx->pc = 0x1c7f84u;
    // NOP
    // 0x1c7f88: 0x0  nop
    ctx->pc = 0x1c7f88u;
    // NOP
    // 0x1c7f8c: 0x0  nop
    ctx->pc = 0x1c7f8cu;
    // NOP
    // 0x1c7f90: 0x0  nop
    ctx->pc = 0x1c7f90u;
    // NOP
    // 0x1c7f94: 0x0  nop
    ctx->pc = 0x1c7f94u;
    // NOP
    // 0x1c7f98: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1c7f98u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1c7f9c: 0x274182a  slt         $v1, $s3, $s4
    ctx->pc = 0x1c7f9cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
label_1c7fa0:
    // 0x1c7fa0: 0x1460ffee  bnez        $v1, . + 4 + (-0x12 << 2)
    ctx->pc = 0x1C7FA0u;
    {
        const bool branch_taken_0x1c7fa0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7FA0u;
            // 0x1c7fa4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7fa0) {
            ctx->pc = 0x1C7F5Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c7f5c;
        }
    }
    ctx->pc = 0x1C7FA8u;
    // 0x1c7fa8: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1C7FA8u;
    {
        const bool branch_taken_0x1c7fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7fa8) {
            ctx->pc = 0x1C8058u;
            goto label_1c8058;
        }
    }
    ctx->pc = 0x1C7FB0u;
label_1c7fb0:
    // 0x1c7fb0: 0x16800013  bnez        $s4, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C7FB0u;
    {
        const bool branch_taken_0x1c7fb0 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7FB0u;
            // 0x1c7fb4: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7fb0) {
            ctx->pc = 0x1C8000u;
            goto label_1c8000;
        }
    }
    ctx->pc = 0x1C7FB8u;
    // 0x1c7fb8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C7FB8u;
    {
        const bool branch_taken_0x1c7fb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7FB8u;
            // 0x1c7fbc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7fb8) {
            ctx->pc = 0x1C7FE0u;
            goto label_1c7fe0;
        }
    }
    ctx->pc = 0x1C7FC0u;
label_1c7fc0:
    // 0x1c7fc0: 0x0  nop
    ctx->pc = 0x1c7fc0u;
    // NOP
    // 0x1c7fc4: 0x0  nop
    ctx->pc = 0x1c7fc4u;
    // NOP
    // 0x1c7fc8: 0x0  nop
    ctx->pc = 0x1c7fc8u;
    // NOP
    // 0x1c7fcc: 0x0  nop
    ctx->pc = 0x1c7fccu;
    // NOP
    // 0x1c7fd0: 0x0  nop
    ctx->pc = 0x1c7fd0u;
    // NOP
    // 0x1c7fd4: 0x0  nop
    ctx->pc = 0x1c7fd4u;
    // NOP
    // 0x1c7fd8: 0x0  nop
    ctx->pc = 0x1c7fd8u;
    // NOP
    // 0x1c7fdc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c7fdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1c7fe0:
    // 0x1c7fe0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c7fe0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7fe4: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1c7fe4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7fe8: 0xc0471e6  jal         func_11C798
    ctx->pc = 0x1C7FE8u;
    SET_GPR_U32(ctx, 31, 0x1C7FF0u);
    ctx->pc = 0x1C7FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7FE8u;
            // 0x1c7fec: 0x2a0382d  daddu       $a3, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C798u;
    if (runtime->hasFunction(0x11C798u)) {
        auto targetFn = runtime->lookupFunction(0x11C798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7FF0u; }
        if (ctx->pc != 0x1C7FF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C798_0x11c798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7FF0u; }
        if (ctx->pc != 0x1C7FF0u) { return; }
    }
    ctx->pc = 0x1C7FF0u;
label_1c7ff0:
    // 0x1c7ff0: 0x440fff3  bltz        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1C7FF0u;
    {
        const bool branch_taken_0x1c7ff0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c7ff0) {
            ctx->pc = 0x1C7FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c7fc0;
        }
    }
    ctx->pc = 0x1C7FF8u;
    // 0x1c7ff8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1C7FF8u;
    {
        const bool branch_taken_0x1c7ff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c7ff8) {
            ctx->pc = 0x1C8058u;
            goto label_1c8058;
        }
    }
    ctx->pc = 0x1C8000u;
label_1c8000:
    // 0x1c8000: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1C8000u;
    {
        const bool branch_taken_0x1c8000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8000u;
            // 0x1c8004: 0x274182a  slt         $v1, $s3, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8000) {
            ctx->pc = 0x1C8050u;
            goto label_1c8050;
        }
    }
    ctx->pc = 0x1C8008u;
label_1c8008:
    // 0x1c8008: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c8008u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c800c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1c800cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8010: 0xc0471e6  jal         func_11C798
    ctx->pc = 0x1C8010u;
    SET_GPR_U32(ctx, 31, 0x1C8018u);
    ctx->pc = 0x1C8014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8010u;
            // 0x1c8014: 0x2a0382d  daddu       $a3, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C798u;
    if (runtime->hasFunction(0x11C798u)) {
        auto targetFn = runtime->lookupFunction(0x11C798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8018u; }
        if (ctx->pc != 0x1C8018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C798_0x11c798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8018u; }
        if (ctx->pc != 0x1C8018u) { return; }
    }
    ctx->pc = 0x1C8018u;
label_1c8018:
    // 0x1c8018: 0x40082a  slt         $at, $v0, $zero
    ctx->pc = 0x1c8018u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1c801c: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C801Cu;
    {
        const bool branch_taken_0x1c801c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c801c) {
            ctx->pc = 0x1C802Cu;
            goto label_1c802c;
        }
    }
    ctx->pc = 0x1C8024u;
    // 0x1c8024: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1C8024u;
    {
        const bool branch_taken_0x1c8024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c8024) {
            ctx->pc = 0x1C8058u;
            goto label_1c8058;
        }
    }
    ctx->pc = 0x1C802Cu;
label_1c802c:
    // 0x1c802c: 0x0  nop
    ctx->pc = 0x1c802cu;
    // NOP
    // 0x1c8030: 0x0  nop
    ctx->pc = 0x1c8030u;
    // NOP
    // 0x1c8034: 0x0  nop
    ctx->pc = 0x1c8034u;
    // NOP
    // 0x1c8038: 0x0  nop
    ctx->pc = 0x1c8038u;
    // NOP
    // 0x1c803c: 0x0  nop
    ctx->pc = 0x1c803cu;
    // NOP
    // 0x1c8040: 0x0  nop
    ctx->pc = 0x1c8040u;
    // NOP
    // 0x1c8044: 0x0  nop
    ctx->pc = 0x1c8044u;
    // NOP
    // 0x1c8048: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1c8048u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1c804c: 0x274182a  slt         $v1, $s3, $s4
    ctx->pc = 0x1c804cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
label_1c8050:
    // 0x1c8050: 0x1460ffed  bnez        $v1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1C8050u;
    {
        const bool branch_taken_0x1c8050 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C8054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8050u;
            // 0x1c8054: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8050) {
            ctx->pc = 0x1C8008u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c8008;
        }
    }
    ctx->pc = 0x1C8058u;
label_1c8058:
    // 0x1c8058: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1c8058u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_1c805c:
    // 0x1c805c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1c805cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c8060: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c8060u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c8064: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c8064u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c8068: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c8068u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c806c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c806cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c8070: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c8070u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8074: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8074u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8074u;
            // 0x1c8078: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7F18u: goto label_1c7f18;
            case 0x1C7F38u: goto label_1c7f38;
            case 0x1C7F44u: goto label_1c7f44;
            case 0x1C7F54u: goto label_1c7f54;
            case 0x1C7F5Cu: goto label_1c7f5c;
            case 0x1C7F68u: goto label_1c7f68;
            case 0x1C7F7Cu: goto label_1c7f7c;
            case 0x1C7FA0u: goto label_1c7fa0;
            case 0x1C7FB0u: goto label_1c7fb0;
            case 0x1C7FC0u: goto label_1c7fc0;
            case 0x1C7FE0u: goto label_1c7fe0;
            case 0x1C7FF0u: goto label_1c7ff0;
            case 0x1C8000u: goto label_1c8000;
            case 0x1C8008u: goto label_1c8008;
            case 0x1C8018u: goto label_1c8018;
            case 0x1C802Cu: goto label_1c802c;
            case 0x1C8050u: goto label_1c8050;
            case 0x1C8058u: goto label_1c8058;
            case 0x1C805Cu: goto label_1c805c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C807Cu;
    // 0x1c807c: 0x0  nop
    ctx->pc = 0x1c807cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
