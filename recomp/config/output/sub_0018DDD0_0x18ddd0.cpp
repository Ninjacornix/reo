#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DDD0
// Address: 0x18ddd0 - 0x18de40
void sub_0018DDD0_0x18ddd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DDD0_0x18ddd0");
#endif

    switch (ctx->pc) {
        case 0x18de1cu: goto label_18de1c;
        default: break;
    }

    ctx->pc = 0x18ddd0u;

    // 0x18ddd0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x18ddd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18ddd4: 0x24a2ffff  addiu       $v0, $a1, -0x1
    ctx->pc = 0x18ddd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x18ddd8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18ddd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18dddc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18dddcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18dde0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18dde0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18dde4: 0x403027  not         $a2, $v0
    ctx->pc = 0x18dde4u;
    SET_GPR_U64(ctx, 6, ~(GPR_U64(ctx, 2) | GPR_U64(ctx, 0)));
    // 0x18dde8: 0x8c27fdc0  lw          $a3, -0x240($at)
    ctx->pc = 0x18dde8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966720)));
    // 0x18ddec: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18ddecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ddf0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18ddf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18ddf4: 0xe51021  addu        $v0, $a3, $a1
    ctx->pc = 0x18ddf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x18ddf8: 0x8c23fdbc  lw          $v1, -0x244($at)
    ctx->pc = 0x18ddf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966716)));
    // 0x18ddfc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18ddfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18de00: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x18de00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x18de04: 0x442021  addu        $a0, $v0, $a0
    ctx->pc = 0x18de04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18de08: 0x64082b  sltu        $at, $v1, $a0
    ctx->pc = 0x18de08u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x18de0c: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x18DE0Cu;
    {
        const bool branch_taken_0x18de0c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x18de0c) {
            ctx->pc = 0x18DE28u;
            goto label_18de28;
        }
    }
    ctx->pc = 0x18DE14u;
    // 0x18de14: 0xc063594  jal         func_18D650
    ctx->pc = 0x18DE14u;
    SET_GPR_U32(ctx, 31, 0x18DE1Cu);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DE1Cu; }
        if (ctx->pc != 0x18DE1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DE1Cu; }
        if (ctx->pc != 0x18DE1Cu) { return; }
    }
    ctx->pc = 0x18DE1Cu;
label_18de1c:
    // 0x18de1c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18de1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18de20: 0x8c22fdb8  lw          $v0, -0x248($at)
    ctx->pc = 0x18de20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966712)));
    // 0x18de24: 0x502021  addu        $a0, $v0, $s0
    ctx->pc = 0x18de24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_18de28:
    // 0x18de28: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18de28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18de2c: 0xac24fdc0  sw          $a0, -0x240($at)
    ctx->pc = 0x18de2cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966720), GPR_U32(ctx, 4));
    // 0x18de30: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18de30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18de34: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18de34u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18de38: 0x3e00008  jr          $ra
    ctx->pc = 0x18DE38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DE38u;
            // 0x18de3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DE1Cu: goto label_18de1c;
            case 0x18DE28u: goto label_18de28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DE40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
