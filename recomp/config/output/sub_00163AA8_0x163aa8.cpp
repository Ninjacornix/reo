#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163AA8
// Address: 0x163aa8 - 0x163b30
void sub_00163AA8_0x163aa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163AA8_0x163aa8");
#endif

    switch (ctx->pc) {
        case 0x163ac0u: goto label_163ac0;
        case 0x163ad4u: goto label_163ad4;
        case 0x163aecu: goto label_163aec;
        case 0x163b04u: goto label_163b04;
        default: break;
    }

    ctx->pc = 0x163aa8u;

    // 0x163aa8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163aa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163aac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163ab0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163ab0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163ab4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x163ab8: 0xc05d4be  jal         func_1752F8
    ctx->pc = 0x163AB8u;
    SET_GPR_U32(ctx, 31, 0x163AC0u);
    ctx->pc = 0x163ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163AB8u;
            // 0x163abc: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1752F8u;
    if (runtime->hasFunction(0x1752F8u)) {
        auto targetFn = runtime->lookupFunction(0x1752F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AC0u; }
        if (ctx->pc != 0x163AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001752F8_0x1752f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AC0u; }
        if (ctx->pc != 0x163AC0u) { return; }
    }
    ctx->pc = 0x163AC0u;
label_163ac0:
    // 0x163ac0: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x163ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x163ac4: 0x14430016  bne         $v0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x163AC4u;
    {
        const bool branch_taken_0x163ac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x163AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163AC4u;
            // 0x163ac8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163ac4) {
            ctx->pc = 0x163B20u;
            goto label_163b20;
        }
    }
    ctx->pc = 0x163ACCu;
    // 0x163acc: 0xc057ba2  jal         func_15EE88
    ctx->pc = 0x163ACCu;
    SET_GPR_U32(ctx, 31, 0x163AD4u);
    ctx->pc = 0x15EE88u;
    if (runtime->hasFunction(0x15EE88u)) {
        auto targetFn = runtime->lookupFunction(0x15EE88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AD4u; }
        if (ctx->pc != 0x163AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EE88_0x15ee88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AD4u; }
        if (ctx->pc != 0x163AD4u) { return; }
    }
    ctx->pc = 0x163AD4u;
label_163ad4:
    // 0x163ad4: 0x82030072  lb          $v1, 0x72($s0)
    ctx->pc = 0x163ad4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 114)));
    // 0x163ad8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x163ad8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163adc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x163ADCu;
    {
        const bool branch_taken_0x163adc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x163AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163ADCu;
            // 0x163ae0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163adc) {
            ctx->pc = 0x163AECu;
            goto label_163aec;
        }
    }
    ctx->pc = 0x163AE4u;
    // 0x163ae4: 0xc057cfc  jal         func_15F3F0
    ctx->pc = 0x163AE4u;
    SET_GPR_U32(ctx, 31, 0x163AECu);
    ctx->pc = 0x15F3F0u;
    if (runtime->hasFunction(0x15F3F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F3F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AECu; }
        if (ctx->pc != 0x163AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F3F0_0x15f3f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163AECu; }
        if (ctx->pc != 0x163AECu) { return; }
    }
    ctx->pc = 0x163AECu;
label_163aec:
    // 0x163aec: 0x82030070  lb          $v1, 0x70($s0)
    ctx->pc = 0x163aecu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x163af0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163af4: 0x5462000b  bnel        $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x163AF4u;
    {
        const bool branch_taken_0x163af4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x163af4) {
            ctx->pc = 0x163AF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163AF4u;
            // 0x163af8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163B24u;
            goto label_163b24;
        }
    }
    ctx->pc = 0x163AFCu;
    // 0x163afc: 0xc059f5c  jal         func_167D70
    ctx->pc = 0x163AFCu;
    SET_GPR_U32(ctx, 31, 0x163B04u);
    ctx->pc = 0x163B00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163AFCu;
            // 0x163b00: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D70u;
    if (runtime->hasFunction(0x167D70u)) {
        auto targetFn = runtime->lookupFunction(0x167D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B04u; }
        if (ctx->pc != 0x163B04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D70_0x167d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163B04u; }
        if (ctx->pc != 0x163B04u) { return; }
    }
    ctx->pc = 0x163B04u;
label_163b04:
    // 0x163b04: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163b04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x163b08: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x163B08u;
    {
        const bool branch_taken_0x163b08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x163B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163B08u;
            // 0x163b0c: 0x248404a0  addiu       $a0, $a0, 0x4A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1184));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163b08) {
            ctx->pc = 0x163B20u;
            goto label_163b20;
        }
    }
    ctx->pc = 0x163B10u;
    // 0x163b10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163b10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163b14: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163b14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163b18: 0x8058dd4  j           func_163750
    ctx->pc = 0x163B18u;
    ctx->pc = 0x163B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163B18u;
            // 0x163b1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163B20u;
label_163b20:
    // 0x163b20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163b20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_163b24:
    // 0x163b24: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163b24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163b28: 0x3e00008  jr          $ra
    ctx->pc = 0x163B28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163B28u;
            // 0x163b2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163AC0u: goto label_163ac0;
            case 0x163AD4u: goto label_163ad4;
            case 0x163AECu: goto label_163aec;
            case 0x163B04u: goto label_163b04;
            case 0x163B20u: goto label_163b20;
            case 0x163B24u: goto label_163b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163B30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
