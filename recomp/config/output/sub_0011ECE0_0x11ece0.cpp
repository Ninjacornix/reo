#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011ECE0
// Address: 0x11ece0 - 0x11edac
void sub_0011ECE0_0x11ece0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011ECE0_0x11ece0");
#endif

    switch (ctx->pc) {
        case 0x11ed0cu: goto label_11ed0c;
        case 0x11ed44u: goto label_11ed44;
        case 0x11ed60u: goto label_11ed60;
        case 0x11ed8cu: goto label_11ed8c;
        default: break;
    }

    ctx->pc = 0x11ece0u;

    // 0x11ece0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11ece0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11ece4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ece4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ece8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11ece8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ecec: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11ececu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11ecf0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11ecf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ecf4: 0x111282  srl         $v0, $s1, 10
    ctx->pc = 0x11ecf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 10));
    // 0x11ecf8: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11ecf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11ecfc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11ecfcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ed00: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11ed00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11ed04: 0xc047598  jal         func_11D660
    ctx->pc = 0x11ED04u;
    SET_GPR_U32(ctx, 31, 0x11ED0Cu);
    ctx->pc = 0x11ED08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED04u;
            // 0x11ed08: 0x28180  sll         $s0, $v0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED0Cu; }
        if (ctx->pc != 0x11ED0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED0Cu; }
        if (ctx->pc != 0x11ED0Cu) { return; }
    }
    ctx->pc = 0x11ED0Cu;
label_11ed0c:
    // 0x11ed0c: 0x6200009  bltz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x11ED0Cu;
    {
        const bool branch_taken_0x11ed0c = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x11ED10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED0Cu;
            // 0x11ed10: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed0c) {
            ctx->pc = 0x11ED34u;
            goto label_11ed34;
        }
    }
    ctx->pc = 0x11ED14u;
    // 0x11ed14: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x11ed14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11ed18: 0x322203ff  andi        $v0, $s1, 0x3FF
    ctx->pc = 0x11ed18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1023);
    // 0x11ed1c: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x11ED1Cu;
    {
        const bool branch_taken_0x11ed1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x11ED20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED1Cu;
            // 0x11ed20: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed1c) {
            ctx->pc = 0x11ED34u;
            goto label_11ed34;
        }
    }
    ctx->pc = 0x11ED24u;
    // 0x11ed24: 0x2442b3e8  addiu       $v0, $v0, -0x4C18
    ctx->pc = 0x11ed24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947816));
    // 0x11ed28: 0x8c43001c  lw          $v1, 0x1C($v0)
    ctx->pc = 0x11ed28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x11ed2c: 0x54710007  bnel        $v1, $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11ED2Cu;
    {
        const bool branch_taken_0x11ed2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 17));
        if (branch_taken_0x11ed2c) {
            ctx->pc = 0x11ED30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED2Cu;
            // 0x11ed30: 0x8e02000c  lw          $v0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11ED4Cu;
            goto label_11ed4c;
        }
    }
    ctx->pc = 0x11ED34u;
label_11ed34:
    // 0x11ed34: 0x12600016  beqz        $s3, . + 4 + (0x16 << 2)
    ctx->pc = 0x11ED34u;
    {
        const bool branch_taken_0x11ed34 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED34u;
            // 0x11ed38: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed34) {
            ctx->pc = 0x11ED90u;
            goto label_11ed90;
        }
    }
    ctx->pc = 0x11ED3Cu;
    // 0x11ed3c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11ED3Cu;
    SET_GPR_U32(ctx, 31, 0x11ED44u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED44u; }
        if (ctx->pc != 0x11ED44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED44u; }
        if (ctx->pc != 0x11ED44u) { return; }
    }
    ctx->pc = 0x11ED44u;
label_11ed44:
    // 0x11ed44: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x11ED44u;
    {
        const bool branch_taken_0x11ed44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED44u;
            // 0x11ed48: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed44) {
            ctx->pc = 0x11ED90u;
            goto label_11ed90;
        }
    }
    ctx->pc = 0x11ED4Cu;
label_11ed4c:
    // 0x11ed4c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x11ed4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x11ed50: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x11ED50u;
    {
        const bool branch_taken_0x11ed50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED50u;
            // 0x11ed54: 0xde110018  ld          $s1, 0x18($s0) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed50) {
            ctx->pc = 0x11ED78u;
            goto label_11ed78;
        }
    }
    ctx->pc = 0x11ED58u;
    // 0x11ed58: 0xc0479e8  jal         func_11E7A0
    ctx->pc = 0x11ED58u;
    SET_GPR_U32(ctx, 31, 0x11ED60u);
    ctx->pc = 0x11E7A0u;
    if (runtime->hasFunction(0x11E7A0u)) {
        auto targetFn = runtime->lookupFunction(0x11E7A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED60u; }
        if (ctx->pc != 0x11ED60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E7A0_0x11e7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED60u; }
        if (ctx->pc != 0x11ED60u) { return; }
    }
    ctx->pc = 0x11ED60u;
label_11ed60:
    // 0x11ed60: 0xde030010  ld          $v1, 0x10($s0)
    ctx->pc = 0x11ed60u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x11ed64: 0xfe120018  sd          $s2, 0x18($s0)
    ctx->pc = 0x11ed64u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 18));
    // 0x11ed68: 0x43182f  dsubu       $v1, $v0, $v1
    ctx->pc = 0x11ed68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x11ed6c: 0xfe020010  sd          $v0, 0x10($s0)
    ctx->pc = 0x11ed6cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 16), GPR_U64(ctx, 2));
    // 0x11ed70: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11ED70u;
    {
        const bool branch_taken_0x11ed70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED70u;
            // 0x11ed74: 0x223882d  daddu       $s1, $s1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed70) {
            ctx->pc = 0x11ED7Cu;
            goto label_11ed7c;
        }
    }
    ctx->pc = 0x11ED78u;
label_11ed78:
    // 0x11ed78: 0xfe120018  sd          $s2, 0x18($s0)
    ctx->pc = 0x11ed78u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 18));
label_11ed7c:
    // 0x11ed7c: 0x12600004  beqz        $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x11ED7Cu;
    {
        const bool branch_taken_0x11ed7c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ED80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ED7Cu;
            // 0x11ed80: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ed7c) {
            ctx->pc = 0x11ED90u;
            goto label_11ed90;
        }
    }
    ctx->pc = 0x11ED84u;
    // 0x11ed84: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11ED84u;
    SET_GPR_U32(ctx, 31, 0x11ED8Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED8Cu; }
        if (ctx->pc != 0x11ED8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ED8Cu; }
        if (ctx->pc != 0x11ED8Cu) { return; }
    }
    ctx->pc = 0x11ED8Cu;
label_11ed8c:
    // 0x11ed8c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x11ed8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_11ed90:
    // 0x11ed90: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11ed90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11ed94: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11ed94u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11ed98: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11ed98u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11ed9c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ed9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11eda0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11eda0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11eda4: 0x3e00008  jr          $ra
    ctx->pc = 0x11EDA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EDA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EDA4u;
            // 0x11eda8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11ED0Cu: goto label_11ed0c;
            case 0x11ED34u: goto label_11ed34;
            case 0x11ED44u: goto label_11ed44;
            case 0x11ED4Cu: goto label_11ed4c;
            case 0x11ED60u: goto label_11ed60;
            case 0x11ED78u: goto label_11ed78;
            case 0x11ED7Cu: goto label_11ed7c;
            case 0x11ED8Cu: goto label_11ed8c;
            case 0x11ED90u: goto label_11ed90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EDACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
