#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114BE8
// Address: 0x114be8 - 0x114c68
void sub_00114BE8_0x114be8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114BE8_0x114be8");
#endif

    switch (ctx->pc) {
        case 0x114c28u: goto label_114c28;
        case 0x114c40u: goto label_114c40;
        default: break;
    }

    ctx->pc = 0x114be8u;

    // 0x114be8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x114be8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x114bec: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x114becu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x114bf0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x114bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x114bf4: 0x2c840002  sltiu       $a0, $a0, 0x2
    ctx->pc = 0x114bf4u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x114bf8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x114bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x114bfc: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x114bfcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114c00: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x114c00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x114c04: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x114c04u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114c08: 0x1080000f  beqz        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x114C08u;
    {
        const bool branch_taken_0x114c08 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x114C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114C08u;
            // 0x114c0c: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114c08) {
            ctx->pc = 0x114C48u;
            goto label_114c48;
        }
    }
    ctx->pc = 0x114C10u;
    // 0x114c10: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x114c10u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x114c14: 0x8e029d30  lw          $v0, -0x62D0($s0)
    ctx->pc = 0x114c14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942000)));
    // 0x114c18: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x114C18u;
    {
        const bool branch_taken_0x114c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x114C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114C18u;
            // 0x114c1c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114c18) {
            ctx->pc = 0x114C38u;
            goto label_114c38;
        }
    }
    ctx->pc = 0x114C20u;
    // 0x114c20: 0xc04578c  jal         func_115E30
    ctx->pc = 0x114C20u;
    SET_GPR_U32(ctx, 31, 0x114C28u);
    ctx->pc = 0x115E30u;
    if (runtime->hasFunction(0x115E30u)) {
        auto targetFn = runtime->lookupFunction(0x115E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114C28u; }
        if (ctx->pc != 0x114C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115E30_0x115e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114C28u; }
        if (ctx->pc != 0x114C28u) { return; }
    }
    ctx->pc = 0x114C28u;
label_114c28:
    // 0x114c28: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x114C28u;
    {
        const bool branch_taken_0x114c28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x114C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114C28u;
            // 0x114c2c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114c28) {
            ctx->pc = 0x114C48u;
            goto label_114c48;
        }
    }
    ctx->pc = 0x114C30u;
    // 0x114c30: 0xae029d30  sw          $v0, -0x62D0($s0)
    ctx->pc = 0x114c30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294942000), GPR_U32(ctx, 2));
    // 0x114c34: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x114c34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_114c38:
    // 0x114c38: 0xc0456fa  jal         func_115BE8
    ctx->pc = 0x114C38u;
    SET_GPR_U32(ctx, 31, 0x114C40u);
    ctx->pc = 0x114C3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x114C38u;
            // 0x114c3c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115BE8u;
    if (runtime->hasFunction(0x115BE8u)) {
        auto targetFn = runtime->lookupFunction(0x115BE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114C40u; }
        if (ctx->pc != 0x114C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115BE8_0x115be8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114C40u; }
        if (ctx->pc != 0x114C40u) { return; }
    }
    ctx->pc = 0x114C40u;
label_114c40:
    // 0x114c40: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x114C40u;
    {
        const bool branch_taken_0x114c40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x114C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114C40u;
            // 0x114c44: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114c40) {
            ctx->pc = 0x114C50u;
            goto label_114c50;
        }
    }
    ctx->pc = 0x114C48u;
label_114c48:
    // 0x114c48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x114c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x114c4c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x114c4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_114c50:
    // 0x114c50: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x114c50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x114c54: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x114c54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x114c58: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x114c58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x114c5c: 0x3e00008  jr          $ra
    ctx->pc = 0x114C5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114C5Cu;
            // 0x114c60: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114C28u: goto label_114c28;
            case 0x114C38u: goto label_114c38;
            case 0x114C40u: goto label_114c40;
            case 0x114C48u: goto label_114c48;
            case 0x114C50u: goto label_114c50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114C64u;
    // 0x114c64: 0x0  nop
    ctx->pc = 0x114c64u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
