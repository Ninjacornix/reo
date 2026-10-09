#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101E30
// Address: 0x101e30 - 0x101e90
void sub_00101E30_0x101e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101E30_0x101e30");
#endif

    switch (ctx->pc) {
        case 0x101e44u: goto label_101e44;
        default: break;
    }

    ctx->pc = 0x101e30u;

    // 0x101e30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x101e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x101e34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x101e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x101e38: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x101e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x101e3c: 0xc0407d8  jal         func_101F60
    ctx->pc = 0x101E3Cu;
    SET_GPR_U32(ctx, 31, 0x101E44u);
    ctx->pc = 0x101E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101E3Cu;
            // 0x101e40: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101F60u;
    if (runtime->hasFunction(0x101F60u)) {
        auto targetFn = runtime->lookupFunction(0x101F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101E44u; }
        if (ctx->pc != 0x101E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101F60_0x101f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101E44u; }
        if (ctx->pc != 0x101E44u) { return; }
    }
    ctx->pc = 0x101E44u;
label_101e44:
    // 0x101e44: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x101e44u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101e48: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x101e48u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x101e4c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x101E4Cu;
    {
        const bool branch_taken_0x101e4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101E4Cu;
            // 0x101e50: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101e4c) {
            ctx->pc = 0x101E7Cu;
            goto label_101e7c;
        }
    }
    ctx->pc = 0x101E54u;
    // 0x101e54: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x101e54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x101e58: 0x244276c0  addiu       $v0, $v0, 0x76C0
    ctx->pc = 0x101e58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30400));
    // 0x101e5c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x101e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x101e60: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x101e60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x101e64: 0x800008  jr          $a0
    ctx->pc = 0x101E64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101E6Cu;
label_101e6c:
    // 0x101e6c: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x101e6cu;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x101e70: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x101e70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x101e74: 0x48c2e000  ctc2.ni     $v0, $vi28
    ctx->pc = 0x101e74u;
    ctx->vu0_itop = GPR_U32(ctx, 2) & 0x3FF;
label_101e78:
    // 0x101e78: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x101e78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_101e7c:
    // 0x101e7c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101e7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101e80: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x101e80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101e84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x101e84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x101e88: 0x3e00008  jr          $ra
    ctx->pc = 0x101E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101E88u;
            // 0x101e8c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101E44u: goto label_101e44;
            case 0x101E6Cu: goto label_101e6c;
            case 0x101E78u: goto label_101e78;
            case 0x101E7Cu: goto label_101e7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101E90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
