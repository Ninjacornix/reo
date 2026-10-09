#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160938
// Address: 0x160938 - 0x16099c
void sub_00160938_0x160938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160938_0x160938");
#endif

    ctx->pc = 0x160938u;

    // 0x160938: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160938u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16093c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16093cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160940: 0x10800013  beqz        $a0, . + 4 + (0x13 << 2)
    ctx->pc = 0x160940u;
    {
        const bool branch_taken_0x160940 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x160944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160940u;
            // 0x160944: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160940) {
            ctx->pc = 0x160990u;
            goto label_160990;
        }
    }
    ctx->pc = 0x160948u;
    // 0x160948: 0x8c820044  lw          $v0, 0x44($a0)
    ctx->pc = 0x160948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x16094c: 0x8c83004c  lw          $v1, 0x4C($a0)
    ctx->pc = 0x16094cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x160950: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x160950u;
    {
        const bool branch_taken_0x160950 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160950u;
            // 0x160954: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160950) {
            ctx->pc = 0x160980u;
            goto label_160980;
        }
    }
    ctx->pc = 0x160958u;
    // 0x160958: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x160958u;
    {
        const bool branch_taken_0x160958 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16095Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160958u;
            // 0x16095c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160958) {
            ctx->pc = 0x160990u;
            goto label_160990;
        }
    }
    ctx->pc = 0x160960u;
    // 0x160960: 0x8c620028  lw          $v0, 0x28($v1)
    ctx->pc = 0x160960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x160964: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x160964u;
    {
        const bool branch_taken_0x160964 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x160968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160964u;
            // 0x160968: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160964) {
            ctx->pc = 0x160978u;
            goto label_160978;
        }
    }
    ctx->pc = 0x16096Cu;
    // 0x16096c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16096cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160970: 0x805916a  j           func_1645A8
    ctx->pc = 0x160970u;
    ctx->pc = 0x160974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160970u;
            // 0x160974: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1645A8u;
    if (runtime->hasFunction(0x1645A8u)) {
        auto targetFn = runtime->lookupFunction(0x1645A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001645A8_0x1645a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160978u;
label_160978:
    // 0x160978: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x160978u;
    {
        const bool branch_taken_0x160978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16097Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160978u;
            // 0x16097c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160978) {
            ctx->pc = 0x160990u;
            goto label_160990;
        }
    }
    ctx->pc = 0x160980u;
label_160980:
    // 0x160980: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160980u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160984: 0x805916a  j           func_1645A8
    ctx->pc = 0x160984u;
    ctx->pc = 0x160988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160984u;
            // 0x160988: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1645A8u;
    if (runtime->hasFunction(0x1645A8u)) {
        auto targetFn = runtime->lookupFunction(0x1645A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001645A8_0x1645a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16098Cu;
    // 0x16098c: 0x0  nop
    ctx->pc = 0x16098cu;
    // NOP
label_160990:
    // 0x160990: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160990u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160994: 0x3e00008  jr          $ra
    ctx->pc = 0x160994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160994u;
            // 0x160998: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160978u: goto label_160978;
            case 0x160980u: goto label_160980;
            case 0x160990u: goto label_160990;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16099Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
