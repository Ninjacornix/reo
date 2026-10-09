#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131AE8
// Address: 0x131ae8 - 0x131b48
void sub_00131AE8_0x131ae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131AE8_0x131ae8");
#endif

    switch (ctx->pc) {
        case 0x131b10u: goto label_131b10;
        case 0x131b24u: goto label_131b24;
        default: break;
    }

    ctx->pc = 0x131ae8u;

    // 0x131ae8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x131ae8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x131aec: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x131aecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x131af0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x131af0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x131af4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131af4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131af8: 0x2450f3c8  addiu       $s0, $v0, -0xC38
    ctx->pc = 0x131af8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964168));
    // 0x131afc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131b00: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x131b00u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x131b04: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x131b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x131b08: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x131b08u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131b0c: 0x0  nop
    ctx->pc = 0x131b0cu;
    // NOP
label_131b10:
    // 0x131b10: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x131b10u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x131b14: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x131B14u;
    {
        const bool branch_taken_0x131b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x131b14) {
            ctx->pc = 0x131B18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131B14u;
            // 0x131b18: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131B28u;
            goto label_131b28;
        }
    }
    ctx->pc = 0x131B1Cu;
    // 0x131b1c: 0xc04c646  jal         func_131918
    ctx->pc = 0x131B1Cu;
    SET_GPR_U32(ctx, 31, 0x131B24u);
    ctx->pc = 0x131B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131B1Cu;
            // 0x131b20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131918u;
    if (runtime->hasFunction(0x131918u)) {
        auto targetFn = runtime->lookupFunction(0x131918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131B24u; }
        if (ctx->pc != 0x131B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131918_0x131918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131B24u; }
        if (ctx->pc != 0x131B24u) { return; }
    }
    ctx->pc = 0x131B24u;
label_131b24:
    // 0x131b24: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x131b24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_131b28:
    // 0x131b28: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x131B28u;
    {
        const bool branch_taken_0x131b28 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x131B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131B28u;
            // 0x131b2c: 0x261000c4  addiu       $s0, $s0, 0xC4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 196));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131b28) {
            ctx->pc = 0x131B10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131b10;
        }
    }
    ctx->pc = 0x131B30u;
    // 0x131b30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131b30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131b34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131b34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131b38: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131b38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131b3c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x131b3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131b40: 0x3e00008  jr          $ra
    ctx->pc = 0x131B40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131B40u;
            // 0x131b44: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131B10u: goto label_131b10;
            case 0x131B24u: goto label_131b24;
            case 0x131B28u: goto label_131b28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131B48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
