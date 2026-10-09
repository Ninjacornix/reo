#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132C08
// Address: 0x132c08 - 0x132cf0
void sub_00132C08_0x132c08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132C08_0x132c08");
#endif

    switch (ctx->pc) {
        case 0x132c2cu: goto label_132c2c;
        case 0x132c60u: goto label_132c60;
        case 0x132c68u: goto label_132c68;
        case 0x132c70u: goto label_132c70;
        case 0x132c88u: goto label_132c88;
        case 0x132c9cu: goto label_132c9c;
        case 0x132cb8u: goto label_132cb8;
        default: break;
    }

    ctx->pc = 0x132c08u;

label_132c08:
    // 0x132c08: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x132c08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x132c0c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x132c0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x132c10: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x132c10u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x132c14: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x132c14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x132c18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x132c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x132c1c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x132c1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x132c20: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x132c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x132c24: 0xc049938  jal         func_1264E0
    ctx->pc = 0x132C24u;
    SET_GPR_U32(ctx, 31, 0x132C2Cu);
    ctx->pc = 0x132C28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132C24u;
            // 0x132c28: 0x2671b754  addiu       $s1, $s3, -0x48AC (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 4294948692));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C2Cu; }
        if (ctx->pc != 0x132C2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C2Cu; }
        if (ctx->pc != 0x132C2Cu) { return; }
    }
    ctx->pc = 0x132C2Cu;
label_132c2c:
    // 0x132c2c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x132c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x132c30: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x132C30u;
    {
        const bool branch_taken_0x132c30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x132C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132C30u;
            // 0x132c34: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132c30) {
            ctx->pc = 0x132C50u;
            goto label_132c50;
        }
    }
    ctx->pc = 0x132C38u;
    // 0x132c38: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x132c38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132c3c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x132c3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132c40: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x132c40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x132c44: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x132c44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x132c48: 0x804993e  j           func_1264F8
    ctx->pc = 0x132C48u;
    ctx->pc = 0x132C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132C48u;
            // 0x132c4c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132C50u;
label_132c50:
    // 0x132c50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x132c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x132c54: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x132c54u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x132c58: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x132C58u;
    SET_GPR_U32(ctx, 31, 0x132C60u);
    ctx->pc = 0x132C5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132C58u;
            // 0x132c5c: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C60u; }
        if (ctx->pc != 0x132C60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C60u; }
        if (ctx->pc != 0x132C60u) { return; }
    }
    ctx->pc = 0x132C60u;
label_132c60:
    // 0x132c60: 0xc049938  jal         func_1264E0
    ctx->pc = 0x132C60u;
    SET_GPR_U32(ctx, 31, 0x132C68u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C68u; }
        if (ctx->pc != 0x132C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C68u; }
        if (ctx->pc != 0x132C68u) { return; }
    }
    ctx->pc = 0x132C68u;
label_132c68:
    // 0x132c68: 0xc04b59e  jal         func_12D678
    ctx->pc = 0x132C68u;
    SET_GPR_U32(ctx, 31, 0x132C70u);
    ctx->pc = 0x12D678u;
    if (runtime->hasFunction(0x12D678u)) {
        auto targetFn = runtime->lookupFunction(0x12D678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C70u; }
        if (ctx->pc != 0x132C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D678_0x12d678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C70u; }
        if (ctx->pc != 0x132C70u) { return; }
    }
    ctx->pc = 0x132C70u;
label_132c70:
    // 0x132c70: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x132c70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x132c74: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x132c74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x132c78: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x132c78u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x132c7c: 0x2470f3c8  addiu       $s0, $v1, -0xC38
    ctx->pc = 0x132c7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294964168));
    // 0x132c80: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x132c80u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x132c84: 0x0  nop
    ctx->pc = 0x132c84u;
    // NOP
label_132c88:
    // 0x132c88: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x132c88u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x132c8c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x132C8Cu;
    {
        const bool branch_taken_0x132c8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x132c8c) {
            ctx->pc = 0x132C90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x132C8Cu;
            // 0x132c90: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x132CA0u;
            goto label_132ca0;
        }
    }
    ctx->pc = 0x132C94u;
    // 0x132c94: 0xc04d316  jal         func_134C58
    ctx->pc = 0x132C94u;
    SET_GPR_U32(ctx, 31, 0x132C9Cu);
    ctx->pc = 0x132C98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132C94u;
            // 0x132c98: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134C58u;
    if (runtime->hasFunction(0x134C58u)) {
        auto targetFn = runtime->lookupFunction(0x134C58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C9Cu; }
        if (ctx->pc != 0x132C9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134C58_0x134c58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132C9Cu; }
        if (ctx->pc != 0x132C9Cu) { return; }
    }
    ctx->pc = 0x132C9Cu;
label_132c9c:
    // 0x132c9c: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x132c9cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_132ca0:
    // 0x132ca0: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x132CA0u;
    {
        const bool branch_taken_0x132ca0 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x132CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132CA0u;
            // 0x132ca4: 0x261000c4  addiu       $s0, $s0, 0xC4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 196));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132ca0) {
            ctx->pc = 0x132C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_132c88;
        }
    }
    ctx->pc = 0x132CA8u;
    // 0x132ca8: 0x2670b754  addiu       $s0, $s3, -0x48AC
    ctx->pc = 0x132ca8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294948692));
    // 0x132cac: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x132cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x132cb0: 0xc04b1e6  jal         func_12C798
    ctx->pc = 0x132CB0u;
    SET_GPR_U32(ctx, 31, 0x132CB8u);
    ctx->pc = 0x132CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132CB0u;
            // 0x132cb4: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C798u;
    if (runtime->hasFunction(0x12C798u)) {
        auto targetFn = runtime->lookupFunction(0x12C798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132CB8u; }
        if (ctx->pc != 0x132CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C798_0x12c798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132CB8u; }
        if (ctx->pc != 0x132CB8u) { return; }
    }
    ctx->pc = 0x132CB8u;
label_132cb8:
    // 0x132cb8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x132cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x132cbc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x132cbcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132cc0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132cc0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132cc4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x132cc4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132cc8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x132cc8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x132ccc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x132cccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x132cd0: 0x804993e  j           func_1264F8
    ctx->pc = 0x132CD0u;
    ctx->pc = 0x132CD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132CD0u;
            // 0x132cd4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132CD8u;
    // 0x132cd8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132cd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132cdc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132cdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132ce0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132ce0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132ce4: 0x804cb02  j           func_132C08
    ctx->pc = 0x132CE4u;
    ctx->pc = 0x132CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132CE4u;
            // 0x132ce8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132C08u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_132c08;
    ctx->pc = 0x132CECu;
    // 0x132cec: 0x0  nop
    ctx->pc = 0x132cecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
