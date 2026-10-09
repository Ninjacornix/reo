#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106A10
// Address: 0x106a10 - 0x106a9c
void sub_00106A10_0x106a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106A10_0x106a10");
#endif

    switch (ctx->pc) {
        case 0x106a48u: goto label_106a48;
        case 0x106a60u: goto label_106a60;
        default: break;
    }

    ctx->pc = 0x106a10u;

    // 0x106a10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x106a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x106a14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106a14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106a18: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x106a18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106a1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106a20: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x106a20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a24: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x106a24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x106a28: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x106a28u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a2c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x106a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x106a30: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x106a30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a34: 0x12000010  beqz        $s0, . + 4 + (0x10 << 2)
    ctx->pc = 0x106A34u;
    {
        const bool branch_taken_0x106a34 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x106A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A34u;
            // 0x106a38: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a34) {
            ctx->pc = 0x106A78u;
            goto label_106a78;
        }
    }
    ctx->pc = 0x106A3Cu;
    // 0x106a3c: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x106a3cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x106a40: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x106A40u;
    SET_GPR_U32(ctx, 31, 0x106A48u);
    ctx->pc = 0x106A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106A40u;
            // 0x106a44: 0x26657910  addiu       $a1, $s3, 0x7910 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 30992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A48u; }
        if (ctx->pc != 0x106A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A48u; }
        if (ctx->pc != 0x106A48u) { return; }
    }
    ctx->pc = 0x106A48u;
label_106a48:
    // 0x106a48: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x106a48u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x106a4c: 0x24a57900  addiu       $a1, $a1, 0x7900
    ctx->pc = 0x106a4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 30976));
    // 0x106a50: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x106A50u;
    {
        const bool branch_taken_0x106a50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A50u;
            // 0x106a54: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a50) {
            ctx->pc = 0x106A68u;
            goto label_106a68;
        }
    }
    ctx->pc = 0x106A58u;
    // 0x106a58: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x106A58u;
    SET_GPR_U32(ctx, 31, 0x106A60u);
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A60u; }
        if (ctx->pc != 0x106A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A60u; }
        if (ctx->pc != 0x106A60u) { return; }
    }
    ctx->pc = 0x106A60u;
label_106a60:
    // 0x106a60: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x106A60u;
    {
        const bool branch_taken_0x106a60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A60u;
            // 0x106a64: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a60) {
            ctx->pc = 0x106A80u;
            goto label_106a80;
        }
    }
    ctx->pc = 0x106A68u;
label_106a68:
    // 0x106a68: 0xae300034  sw          $s0, 0x34($s1)
    ctx->pc = 0x106a68u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 16));
    // 0x106a6c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x106A6Cu;
    {
        const bool branch_taken_0x106a6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A6Cu;
            // 0x106a70: 0xae320030  sw          $s2, 0x30($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a6c) {
            ctx->pc = 0x106A7Cu;
            goto label_106a7c;
        }
    }
    ctx->pc = 0x106A74u;
    // 0x106a74: 0x0  nop
    ctx->pc = 0x106a74u;
    // NOP
label_106a78:
    // 0x106a78: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x106a78u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
label_106a7c:
    // 0x106a7c: 0x26627910  addiu       $v0, $s3, 0x7910
    ctx->pc = 0x106a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 30992));
label_106a80:
    // 0x106a80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106a80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106a84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106a84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106a88: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x106a88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106a8c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x106a8cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x106a90: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x106a90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x106a94: 0x3e00008  jr          $ra
    ctx->pc = 0x106A94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A94u;
            // 0x106a98: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106A48u: goto label_106a48;
            case 0x106A60u: goto label_106a60;
            case 0x106A68u: goto label_106a68;
            case 0x106A78u: goto label_106a78;
            case 0x106A7Cu: goto label_106a7c;
            case 0x106A80u: goto label_106a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106A9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
