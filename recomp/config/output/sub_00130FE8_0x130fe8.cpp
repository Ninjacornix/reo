#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130FE8
// Address: 0x130fe8 - 0x131088
void sub_00130FE8_0x130fe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130FE8_0x130fe8");
#endif

    switch (ctx->pc) {
        case 0x131030u: goto label_131030;
        case 0x131038u: goto label_131038;
        case 0x131048u: goto label_131048;
        default: break;
    }

    ctx->pc = 0x130fe8u;

    // 0x130fe8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x130fe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x130fec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130ff0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x130ff0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130ff4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x130ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130ff8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x130ff8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x130ffc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x130ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x131000: 0x8e02004c  lw          $v0, 0x4C($s0)
    ctx->pc = 0x131000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x131004: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x131004u;
    {
        const bool branch_taken_0x131004 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x131004) {
            ctx->pc = 0x131008u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131004u;
            // 0x131008: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13105Cu;
            goto label_13105c;
        }
    }
    ctx->pc = 0x13100Cu;
    // 0x13100c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x13100cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131010: 0x54400012  bnel        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x131010u;
    {
        const bool branch_taken_0x131010 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x131010) {
            ctx->pc = 0x131014u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131010u;
            // 0x131014: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13105Cu;
            goto label_13105c;
        }
    }
    ctx->pc = 0x131018u;
    // 0x131018: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x131018u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13101c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13101cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x131020: 0xa2020041  sb          $v0, 0x41($s0)
    ctx->pc = 0x131020u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 65), (uint8_t)GPR_U32(ctx, 2));
    // 0x131024: 0x2471a8b0  addiu       $s1, $v1, -0x5750
    ctx->pc = 0x131024u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944944));
    // 0x131028: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x131028u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13102c: 0x0  nop
    ctx->pc = 0x13102cu;
    // NOP
label_131030:
    // 0x131030: 0xc050864  jal         func_142190
    ctx->pc = 0x131030u;
    SET_GPR_U32(ctx, 31, 0x131038u);
    ctx->pc = 0x131034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131030u;
            // 0x131034: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142190u;
    if (runtime->hasFunction(0x142190u)) {
        auto targetFn = runtime->lookupFunction(0x142190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131038u; }
        if (ctx->pc != 0x131038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142190_0x142190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131038u; }
        if (ctx->pc != 0x131038u) { return; }
    }
    ctx->pc = 0x131038u;
label_131038:
    // 0x131038: 0x14520004  bne         $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x131038u;
    {
        const bool branch_taken_0x131038 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        ctx->pc = 0x13103Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131038u;
            // 0x13103c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131038) {
            ctx->pc = 0x13104Cu;
            goto label_13104c;
        }
    }
    ctx->pc = 0x131040u;
    // 0x131040: 0xc04c2de  jal         func_130B78
    ctx->pc = 0x131040u;
    SET_GPR_U32(ctx, 31, 0x131048u);
    ctx->pc = 0x130B78u;
    if (runtime->hasFunction(0x130B78u)) {
        auto targetFn = runtime->lookupFunction(0x130B78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131048u; }
        if (ctx->pc != 0x131048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130B78_0x130b78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131048u; }
        if (ctx->pc != 0x131048u) { return; }
    }
    ctx->pc = 0x131048u;
label_131048:
    // 0x131048: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x131048u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
label_13104c:
    // 0x13104c: 0x82020041  lb          $v0, 0x41($s0)
    ctx->pc = 0x13104cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x131050: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x131050u;
    {
        const bool branch_taken_0x131050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x131050) {
            ctx->pc = 0x131030u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131030;
        }
    }
    ctx->pc = 0x131058u;
    // 0x131058: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131058u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13105c:
    // 0x13105c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13105cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131060: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131060u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131064: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x131064u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131068: 0x3e00008  jr          $ra
    ctx->pc = 0x131068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13106Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131068u;
            // 0x13106c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131030u: goto label_131030;
            case 0x131038u: goto label_131038;
            case 0x131048u: goto label_131048;
            case 0x13104Cu: goto label_13104c;
            case 0x13105Cu: goto label_13105c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131070u;
    // 0x131070: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131070u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131074: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x131074u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131078: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x131078u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13107c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13107cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131080: 0x804a034  j           func_1280D0
    ctx->pc = 0x131080u;
    ctx->pc = 0x131084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131080u;
            // 0x131084: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131088u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
