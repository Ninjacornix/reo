#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8930
// Address: 0x1b8930 - 0x1b89bc
void sub_001B8930_0x1b8930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8930_0x1b8930");
#endif

    switch (ctx->pc) {
        case 0x1b8950u: goto label_1b8950;
        case 0x1b8978u: goto label_1b8978;
        case 0x1b89a0u: goto label_1b89a0;
        default: break;
    }

    ctx->pc = 0x1b8930u;

    // 0x1b8930: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b8930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b8934: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b8934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b8938: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b8938u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b893c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b893cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b8940: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1b8940u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8944: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1b8944u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8948: 0xc06e21c  jal         func_1B8870
    ctx->pc = 0x1B8948u;
    SET_GPR_U32(ctx, 31, 0x1B8950u);
    ctx->pc = 0x1B894Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8948u;
            // 0x1b894c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8870u;
    if (runtime->hasFunction(0x1B8870u)) {
        auto targetFn = runtime->lookupFunction(0x1B8870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8950u; }
        if (ctx->pc != 0x1B8950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8870_0x1b8870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8950u; }
        if (ctx->pc != 0x1B8950u) { return; }
    }
    ctx->pc = 0x1B8950u;
label_1b8950:
    // 0x1b8950: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b8950u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8954: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1b8954u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b8958: 0x12030013  beq         $s0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B8958u;
    {
        const bool branch_taken_0x1b8958 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b8958) {
            ctx->pc = 0x1B89A8u;
            goto label_1b89a8;
        }
    }
    ctx->pc = 0x1B8960u;
    // 0x1b8960: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B8960u;
    {
        const bool branch_taken_0x1b8960 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B8964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8960u;
            // 0x1b8964: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8960) {
            ctx->pc = 0x1B8984u;
            goto label_1b8984;
        }
    }
    ctx->pc = 0x1B8968u;
    // 0x1b8968: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b8968u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b896c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b896cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8970: 0xc06e4ec  jal         func_1B93B0
    ctx->pc = 0x1B8970u;
    SET_GPR_U32(ctx, 31, 0x1B8978u);
    ctx->pc = 0x1B8974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8970u;
            // 0x1b8974: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8978u; }
        if (ctx->pc != 0x1B8978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8978u; }
        if (ctx->pc != 0x1B8978u) { return; }
    }
    ctx->pc = 0x1B8978u;
label_1b8978:
    // 0x1b8978: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b8978u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b897c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B897Cu;
    {
        const bool branch_taken_0x1b897c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B897Cu;
            // 0x1b8980: 0xa4306550  sh          $s0, 0x6550($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 25936), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b897c) {
            ctx->pc = 0x1B89A8u;
            goto label_1b89a8;
        }
    }
    ctx->pc = 0x1B8984u;
label_1b8984:
    // 0x1b8984: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b8984u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b8988: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b8988u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b898c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b898cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8990: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8990u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8994: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8994u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8998: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8998u;
    SET_GPR_U32(ctx, 31, 0x1B89A0u);
    ctx->pc = 0x1B899Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8998u;
            // 0x1b899c: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89A0u; }
        if (ctx->pc != 0x1B89A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B89A0u; }
        if (ctx->pc != 0x1B89A0u) { return; }
    }
    ctx->pc = 0x1B89A0u;
label_1b89a0:
    // 0x1b89a0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b89a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b89a4: 0xa4306550  sh          $s0, 0x6550($at)
    ctx->pc = 0x1b89a4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 25936), (uint16_t)GPR_U32(ctx, 16));
label_1b89a8:
    // 0x1b89a8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b89a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b89ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b89acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b89b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b89b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b89b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B89B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B89B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B89B4u;
            // 0x1b89b8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8950u: goto label_1b8950;
            case 0x1B8978u: goto label_1b8978;
            case 0x1B8984u: goto label_1b8984;
            case 0x1B89A0u: goto label_1b89a0;
            case 0x1B89A8u: goto label_1b89a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B89BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
