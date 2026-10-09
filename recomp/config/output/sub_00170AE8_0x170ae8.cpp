#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170AE8
// Address: 0x170ae8 - 0x170b60
void sub_00170AE8_0x170ae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170AE8_0x170ae8");
#endif

    switch (ctx->pc) {
        case 0x170b3cu: goto label_170b3c;
        case 0x170b48u: goto label_170b48;
        default: break;
    }

    ctx->pc = 0x170ae8u;

    // 0x170ae8: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x170ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x170aec: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x170aecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x170af0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x170af0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x170af4: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x170af4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x170af8: 0xc23024  and         $a2, $a2, $v0
    ctx->pc = 0x170af8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x170afc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x170afcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x170b00: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x170b00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x170b04: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170b04u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170b08: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x170b08u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x170b0c: 0x752c0  sll         $t2, $a3, 11
    ctx->pc = 0x170b0cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 7), 11));
    // 0x170b10: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x170b10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x170b14: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x170b14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170b18: 0xae090054  sw          $t1, 0x54($s0)
    ctx->pc = 0x170b18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 9));
    // 0x170b1c: 0xae0a0018  sw          $t2, 0x18($s0)
    ctx->pc = 0x170b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 10));
    // 0x170b20: 0xae070008  sw          $a3, 0x8($s0)
    ctx->pc = 0x170b20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
    // 0x170b24: 0xae050000  sw          $a1, 0x0($s0)
    ctx->pc = 0x170b24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
    // 0x170b28: 0xae080050  sw          $t0, 0x50($s0)
    ctx->pc = 0x170b28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 8));
    // 0x170b2c: 0xae060004  sw          $a2, 0x4($s0)
    ctx->pc = 0x170b2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 6));
    // 0x170b30: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x170b30u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x170b34: 0xc045188  jal         func_114620
    ctx->pc = 0x170B34u;
    SET_GPR_U32(ctx, 31, 0x170B3Cu);
    ctx->pc = 0x170B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170B34u;
            // 0x170b38: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170B3Cu; }
        if (ctx->pc != 0x170B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170B3Cu; }
        if (ctx->pc != 0x170B3Cu) { return; }
    }
    ctx->pc = 0x170B3Cu;
label_170b3c:
    // 0x170b3c: 0xae020040  sw          $v0, 0x40($s0)
    ctx->pc = 0x170b3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 2));
    // 0x170b40: 0xc05c2d8  jal         func_170B60
    ctx->pc = 0x170B40u;
    SET_GPR_U32(ctx, 31, 0x170B48u);
    ctx->pc = 0x170B44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170B40u;
            // 0x170b44: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170B60u;
    if (runtime->hasFunction(0x170B60u)) {
        auto targetFn = runtime->lookupFunction(0x170B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170B48u; }
        if (ctx->pc != 0x170B48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170B60_0x170b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170B48u; }
        if (ctx->pc != 0x170B48u) { return; }
    }
    ctx->pc = 0x170B48u;
label_170b48:
    // 0x170b48: 0xfe000048  sd          $zero, 0x48($s0)
    ctx->pc = 0x170b48u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 0));
    // 0x170b4c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x170b4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x170b50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x170b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x170b54: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x170b54u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x170b58: 0x3e00008  jr          $ra
    ctx->pc = 0x170B58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170B58u;
            // 0x170b5c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170B3Cu: goto label_170b3c;
            case 0x170B48u: goto label_170b48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170B60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
