#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138C90
// Address: 0x138c90 - 0x138d60
void sub_00138C90_0x138c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138C90_0x138c90");
#endif

    switch (ctx->pc) {
        case 0x138cb4u: goto label_138cb4;
        case 0x138cecu: goto label_138cec;
        case 0x138d00u: goto label_138d00;
        case 0x138d3cu: goto label_138d3c;
        case 0x138d44u: goto label_138d44;
        default: break;
    }

    ctx->pc = 0x138c90u;

    // 0x138c90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x138c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x138c94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138c98: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x138c98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138c9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x138c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x138ca0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x138ca0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ca4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x138ca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x138ca8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x138ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x138cac: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x138CACu;
    SET_GPR_U32(ctx, 31, 0x138CB4u);
    ctx->pc = 0x138CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138CACu;
            // 0x138cb0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138CB4u; }
        if (ctx->pc != 0x138CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138CB4u; }
        if (ctx->pc != 0x138CB4u) { return; }
    }
    ctx->pc = 0x138CB4u;
label_138cb4:
    // 0x138cb4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x138cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x138cb8: 0x12020007  beq         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x138CB8u;
    {
        const bool branch_taken_0x138cb8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x138CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138CB8u;
            // 0x138cbc: 0x2e030002  sltiu       $v1, $s0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x138cb8) {
            ctx->pc = 0x138CD8u;
            goto label_138cd8;
        }
    }
    ctx->pc = 0x138CC0u;
    // 0x138cc0: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x138CC0u;
    {
        const bool branch_taken_0x138cc0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x138CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138CC0u;
            // 0x138cc4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138cc0) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138CC8u;
    // 0x138cc8: 0x1202000b  beq         $s0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x138CC8u;
    {
        const bool branch_taken_0x138cc8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x138CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138CC8u;
            // 0x138ccc: 0x2602fc00  addiu       $v0, $s0, -0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294966272));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138cc8) {
            ctx->pc = 0x138CF8u;
            goto label_138cf8;
        }
    }
    ctx->pc = 0x138CD0u;
    // 0x138cd0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x138CD0u;
    {
        const bool branch_taken_0x138cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x138CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138CD0u;
            // 0x138cd4: 0x21880  sll         $v1, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138cd0) {
            ctx->pc = 0x138D08u;
            goto label_138d08;
        }
    }
    ctx->pc = 0x138CD8u;
label_138cd8:
    // 0x138cd8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x138cd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x138cdc: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x138cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x138ce0: 0x8e260008  lw          $a2, 0x8($s1)
    ctx->pc = 0x138ce0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x138ce4: 0xc04e3de  jal         func_138F78
    ctx->pc = 0x138CE4u;
    SET_GPR_U32(ctx, 31, 0x138CECu);
    ctx->pc = 0x138CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138CE4u;
            // 0x138ce8: 0x8e27000c  lw          $a3, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138F78u;
    if (runtime->hasFunction(0x138F78u)) {
        auto targetFn = runtime->lookupFunction(0x138F78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138CECu; }
        if (ctx->pc != 0x138CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138F78_0x138f78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138CECu; }
        if (ctx->pc != 0x138CECu) { return; }
    }
    ctx->pc = 0x138CECu;
label_138cec:
    // 0x138cec: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x138CECu;
    {
        const bool branch_taken_0x138cec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x138CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138CECu;
            // 0x138cf0: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138cec) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138CF4u;
    // 0x138cf4: 0x0  nop
    ctx->pc = 0x138cf4u;
    // NOP
label_138cf8:
    // 0x138cf8: 0xc04e444  jal         func_139110
    ctx->pc = 0x138CF8u;
    SET_GPR_U32(ctx, 31, 0x138D00u);
    ctx->pc = 0x138CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138CF8u;
            // 0x138cfc: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139110u;
    if (runtime->hasFunction(0x139110u)) {
        auto targetFn = runtime->lookupFunction(0x139110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D00u; }
        if (ctx->pc != 0x138D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139110_0x139110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D00u; }
        if (ctx->pc != 0x138D00u) { return; }
    }
    ctx->pc = 0x138D00u;
label_138d00:
    // 0x138d00: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x138D00u;
    {
        const bool branch_taken_0x138d00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x138d00) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138D08u;
label_138d08:
    // 0x138d08: 0x2c420040  sltiu       $v0, $v0, 0x40
    ctx->pc = 0x138d08u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)64) ? 1 : 0);
    // 0x138d0c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x138D0Cu;
    {
        const bool branch_taken_0x138d0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x138d0c) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138D14u;
    // 0x138d14: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138d14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138d18: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x138d18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x138d1c: 0x8c42c9e0  lw          $v0, -0x3620($v0)
    ctx->pc = 0x138d1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294953440)));
    // 0x138d20: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x138D20u;
    {
        const bool branch_taken_0x138d20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x138D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138D20u;
            // 0x138d24: 0x123082  srl         $a2, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138d20) {
            ctx->pc = 0x138D3Cu;
            goto label_138d3c;
        }
    }
    ctx->pc = 0x138D28u;
    // 0x138d28: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x138d28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x138d2c: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x138d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x138d30: 0x8c84cae0  lw          $a0, -0x3520($a0)
    ctx->pc = 0x138d30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294953696)));
    // 0x138d34: 0x40f809  jalr        $v0
    ctx->pc = 0x138D34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x138D3Cu);
        ctx->pc = 0x138D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138D34u;
            // 0x138d38: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x138D3Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138CB4u: goto label_138cb4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF8u: goto label_138cf8;
            case 0x138D00u: goto label_138d00;
            case 0x138D08u: goto label_138d08;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D44u: goto label_138d44;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x138D3Cu; }
            if (ctx->pc != 0x138D3Cu) { return; }
        }
        }
    }
    ctx->pc = 0x138D3Cu;
label_138d3c:
    // 0x138d3c: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x138D3Cu;
    SET_GPR_U32(ctx, 31, 0x138D44u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D44u; }
        if (ctx->pc != 0x138D44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D44u; }
        if (ctx->pc != 0x138D44u) { return; }
    }
    ctx->pc = 0x138D44u;
label_138d44:
    // 0x138d44: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x138d44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138d48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138d48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138d4c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x138d4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138d50: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x138d50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138d54: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x138d54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138d58: 0x3e00008  jr          $ra
    ctx->pc = 0x138D58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138D58u;
            // 0x138d5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138CB4u: goto label_138cb4;
            case 0x138CD8u: goto label_138cd8;
            case 0x138CECu: goto label_138cec;
            case 0x138CF8u: goto label_138cf8;
            case 0x138D00u: goto label_138d00;
            case 0x138D08u: goto label_138d08;
            case 0x138D3Cu: goto label_138d3c;
            case 0x138D44u: goto label_138d44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138D60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
