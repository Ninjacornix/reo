#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FC28
// Address: 0x12fc28 - 0x12fc90
void sub_0012FC28_0x12fc28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FC28_0x12fc28");
#endif

    switch (ctx->pc) {
        case 0x12fc70u: goto label_12fc70;
        default: break;
    }

    ctx->pc = 0x12fc28u;

    // 0x12fc28: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12fc28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12fc2c: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x12fc2cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12fc30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12fc34: 0x247002d7  addiu       $s0, $v1, 0x2D7
    ctx->pc = 0x12fc34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 727));
    // 0x12fc38: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12fc38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12fc3c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12fc3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc40: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12fc40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12fc44: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12fc44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fc48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12fc48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc4c: 0x806202d6  lb          $v0, 0x2D6($v1)
    ctx->pc = 0x12fc4cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 726)));
    // 0x12fc50: 0x10460005  beq         $v0, $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x12FC50u;
    {
        const bool branch_taken_0x12fc50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        ctx->pc = 0x12FC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC50u;
            // 0x12fc54: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fc50) {
            ctx->pc = 0x12FC68u;
            goto label_12fc68;
        }
    }
    ctx->pc = 0x12FC58u;
    // 0x12fc58: 0x8c620048  lw          $v0, 0x48($v1)
    ctx->pc = 0x12fc58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 72)));
    // 0x12fc5c: 0xa06602d6  sb          $a2, 0x2D6($v1)
    ctx->pc = 0x12fc5cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 726), (uint8_t)GPR_U32(ctx, 6));
    // 0x12fc60: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x12fc60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x12fc64: 0xac620048  sw          $v0, 0x48($v1)
    ctx->pc = 0x12fc64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 72), GPR_U32(ctx, 2));
label_12fc68:
    // 0x12fc68: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12FC68u;
    SET_GPR_U32(ctx, 31, 0x12FC70u);
    ctx->pc = 0x12FC6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC68u;
            // 0x12fc6c: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FC70u; }
        if (ctx->pc != 0x12FC70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FC70u; }
        if (ctx->pc != 0x12FC70u) { return; }
    }
    ctx->pc = 0x12FC70u;
label_12fc70:
    // 0x12fc70: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12fc70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc74: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x12fc74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc78: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12fc78u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12fc7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12fc7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fc80: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x12fc80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12fc84: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12fc84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12fc88: 0x8042d7e  j           func_10B5F8
    ctx->pc = 0x12FC88u;
    ctx->pc = 0x12FC8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FC88u;
            // 0x12fc8c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12FC90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
