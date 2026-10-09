#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134BC0
// Address: 0x134bc0 - 0x134c58
void sub_00134BC0_0x134bc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134BC0_0x134bc0");
#endif

    switch (ctx->pc) {
        case 0x134be4u: goto label_134be4;
        case 0x134c20u: goto label_134c20;
        case 0x134c34u: goto label_134c34;
        case 0x134c48u: goto label_134c48;
        default: break;
    }

    ctx->pc = 0x134bc0u;

    // 0x134bc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134bc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x134bc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x134bc8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x134bc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134bcc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x134bccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x134bd0: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x134bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x134bd4: 0x5040001d  beql        $v0, $zero, . + 4 + (0x1D << 2)
    ctx->pc = 0x134BD4u;
    {
        const bool branch_taken_0x134bd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134bd4) {
            ctx->pc = 0x134BD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134BD4u;
            // 0x134bd8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134C4Cu;
            goto label_134c4c;
        }
    }
    ctx->pc = 0x134BDCu;
    // 0x134bdc: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x134BDCu;
    SET_GPR_U32(ctx, 31, 0x134BE4u);
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134BE4u; }
        if (ctx->pc != 0x134BE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134BE4u; }
        if (ctx->pc != 0x134BE4u) { return; }
    }
    ctx->pc = 0x134BE4u;
label_134be4:
    // 0x134be4: 0x50400019  beql        $v0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x134BE4u;
    {
        const bool branch_taken_0x134be4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134be4) {
            ctx->pc = 0x134BE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134BE4u;
            // 0x134be8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134C4Cu;
            goto label_134c4c;
        }
    }
    ctx->pc = 0x134BECu;
    // 0x134bec: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x134becu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x134bf0: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x134bf0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x134bf4: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x134BF4u;
    {
        const bool branch_taken_0x134bf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134bf4) {
            ctx->pc = 0x134BF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134BF4u;
            // 0x134bf8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134C4Cu;
            goto label_134c4c;
        }
    }
    ctx->pc = 0x134BFCu;
    // 0x134bfc: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x134bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x134c00: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x134c00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x134c04: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x134c04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x134c08: 0x8c63b730  lw          $v1, -0x48D0($v1)
    ctx->pc = 0x134c08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294948656)));
    // 0x134c0c: 0x600008  jr          $v1
    ctx->pc = 0x134C0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134C18u: goto label_134c18;
            case 0x134C40u: goto label_134c40;
            case 0x134C48u: goto label_134c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134C14u;
    // 0x134c14: 0x0  nop
    ctx->pc = 0x134c14u;
    // NOP
label_134c18:
    // 0x134c18: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x134C18u;
    SET_GPR_U32(ctx, 31, 0x134C20u);
    ctx->pc = 0x134C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134C18u;
            // 0x134c1c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134C20u; }
        if (ctx->pc != 0x134C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134C20u; }
        if (ctx->pc != 0x134C20u) { return; }
    }
    ctx->pc = 0x134C20u;
label_134c20:
    // 0x134c20: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x134c20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x134c24: 0x54430009  bnel        $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x134C24u;
    {
        const bool branch_taken_0x134c24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x134c24) {
            ctx->pc = 0x134C28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134C24u;
            // 0x134c28: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134C4Cu;
            goto label_134c4c;
        }
    }
    ctx->pc = 0x134C2Cu;
    // 0x134c2c: 0xc04b314  jal         func_12CC50
    ctx->pc = 0x134C2Cu;
    SET_GPR_U32(ctx, 31, 0x134C34u);
    ctx->pc = 0x134C30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134C2Cu;
            // 0x134c30: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CC50u;
    if (runtime->hasFunction(0x12CC50u)) {
        auto targetFn = runtime->lookupFunction(0x12CC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134C34u; }
        if (ctx->pc != 0x134C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CC50_0x12cc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134C34u; }
        if (ctx->pc != 0x134C34u) { return; }
    }
    ctx->pc = 0x134C34u;
label_134c34:
    // 0x134c34: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x134C34u;
    {
        const bool branch_taken_0x134c34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134C38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134C34u;
            // 0x134c38: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134c34) {
            ctx->pc = 0x134C4Cu;
            goto label_134c4c;
        }
    }
    ctx->pc = 0x134C3Cu;
    // 0x134c3c: 0x0  nop
    ctx->pc = 0x134c3cu;
    // NOP
label_134c40:
    // 0x134c40: 0xc04b314  jal         func_12CC50
    ctx->pc = 0x134C40u;
    SET_GPR_U32(ctx, 31, 0x134C48u);
    ctx->pc = 0x134C44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134C40u;
            // 0x134c44: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CC50u;
    if (runtime->hasFunction(0x12CC50u)) {
        auto targetFn = runtime->lookupFunction(0x12CC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134C48u; }
        if (ctx->pc != 0x134C48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CC50_0x12cc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134C48u; }
        if (ctx->pc != 0x134C48u) { return; }
    }
    ctx->pc = 0x134C48u;
label_134c48:
    // 0x134c48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x134c48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_134c4c:
    // 0x134c4c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x134c4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x134c50: 0x3e00008  jr          $ra
    ctx->pc = 0x134C50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134C54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134C50u;
            // 0x134c54: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134BE4u: goto label_134be4;
            case 0x134C18u: goto label_134c18;
            case 0x134C20u: goto label_134c20;
            case 0x134C34u: goto label_134c34;
            case 0x134C40u: goto label_134c40;
            case 0x134C48u: goto label_134c48;
            case 0x134C4Cu: goto label_134c4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134C58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
