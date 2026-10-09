#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B260
// Address: 0x12b260 - 0x12b2e8
void sub_0012B260_0x12b260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B260_0x12b260");
#endif

    switch (ctx->pc) {
        case 0x12b2b4u: goto label_12b2b4;
        case 0x12b2c8u: goto label_12b2c8;
        case 0x12b2d8u: goto label_12b2d8;
        default: break;
    }

    ctx->pc = 0x12b260u;

    // 0x12b260: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b260u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b264: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12b264u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12b268: 0x8c477d78  lw          $a3, 0x7D78($v0)
    ctx->pc = 0x12b268u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32120)));
    // 0x12b26c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x12b26cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x12b270: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12b270u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12b274: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b274u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b278: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b27c: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12b27cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12b280: 0x24630d70  addiu       $v1, $v1, 0xD70
    ctx->pc = 0x12b280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3440));
    // 0x12b284: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12b284u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b288: 0x24061000  addiu       $a2, $zero, 0x1000
    ctx->pc = 0x12b288u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x12b28c: 0x24a5abf8  addiu       $a1, $a1, -0x5408
    ctx->pc = 0x12b28cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945784));
    // 0x12b290: 0x24421cf0  addiu       $v0, $v0, 0x1CF0
    ctx->pc = 0x12b290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7408));
    // 0x12b294: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12b294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12b298: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x12b298u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x12b29c: 0x261004dc  addiu       $s0, $s0, 0x4DC
    ctx->pc = 0x12b29cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1244));
    // 0x12b2a0: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x12b2a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x12b2a4: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x12b2a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x12b2a8: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12b2a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12b2ac: 0xc045108  jal         func_114420
    ctx->pc = 0x12B2ACu;
    SET_GPR_U32(ctx, 31, 0x12B2B4u);
    ctx->pc = 0x12B2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B2ACu;
            // 0x12b2b0: 0xafa20010  sw          $v0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B2B4u; }
        if (ctx->pc != 0x12B2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B2B4u; }
        if (ctx->pc != 0x12B2B4u) { return; }
    }
    ctx->pc = 0x12B2B4u;
label_12b2b4:
    // 0x12b2b4: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12b2b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12b2b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12b2b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b2bc: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12b2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b2c0: 0xc045110  jal         func_114440
    ctx->pc = 0x12B2C0u;
    SET_GPR_U32(ctx, 31, 0x12B2C8u);
    ctx->pc = 0x12B2C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B2C0u;
            // 0x12b2c4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B2C8u; }
        if (ctx->pc != 0x12B2C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B2C8u; }
        if (ctx->pc != 0x12B2C8u) { return; }
    }
    ctx->pc = 0x12B2C8u;
label_12b2c8:
    // 0x12b2c8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b2c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b2cc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b2ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b2d0: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B2D0u;
    SET_GPR_U32(ctx, 31, 0x12B2D8u);
    ctx->pc = 0x12B2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B2D0u;
            // 0x12b2d4: 0x8c450468  lw          $a1, 0x468($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1128)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B2D8u; }
        if (ctx->pc != 0x12B2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B2D8u; }
        if (ctx->pc != 0x12B2D8u) { return; }
    }
    ctx->pc = 0x12B2D8u;
label_12b2d8:
    // 0x12b2d8: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b2d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b2dc: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12b2dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b2e0: 0x3e00008  jr          $ra
    ctx->pc = 0x12B2E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B2E0u;
            // 0x12b2e4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B2B4u: goto label_12b2b4;
            case 0x12B2C8u: goto label_12b2c8;
            case 0x12B2D8u: goto label_12b2d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B2E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
