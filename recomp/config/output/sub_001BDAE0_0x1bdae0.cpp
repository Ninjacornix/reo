#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BDAE0
// Address: 0x1bdae0 - 0x1bdc24
void sub_001BDAE0_0x1bdae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BDAE0_0x1bdae0");
#endif

    switch (ctx->pc) {
        case 0x1bdb08u: goto label_1bdb08;
        case 0x1bdb18u: goto label_1bdb18;
        case 0x1bdb30u: goto label_1bdb30;
        case 0x1bdb44u: goto label_1bdb44;
        case 0x1bdb54u: goto label_1bdb54;
        case 0x1bdb5cu: goto label_1bdb5c;
        case 0x1bdb94u: goto label_1bdb94;
        case 0x1bdba4u: goto label_1bdba4;
        case 0x1bdbb8u: goto label_1bdbb8;
        case 0x1bdbd0u: goto label_1bdbd0;
        case 0x1bdbe4u: goto label_1bdbe4;
        case 0x1bdbf4u: goto label_1bdbf4;
        case 0x1bdbfcu: goto label_1bdbfc;
        default: break;
    }

    ctx->pc = 0x1bdae0u;

    // 0x1bdae0: 0x27bdfec0  addiu       $sp, $sp, -0x140
    ctx->pc = 0x1bdae0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x1bdae4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bdae4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bdae8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1bdae8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1bdaec: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1bdaecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1bdaf0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bdaf0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bdaf4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bdaf4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bdaf8: 0x8c254fe8  lw          $a1, 0x4FE8($at)
    ctx->pc = 0x1bdaf8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20456)));
    // 0x1bdafc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1bdafcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdb00: 0xc06f904  jal         func_1BE410
    ctx->pc = 0x1BDB00u;
    SET_GPR_U32(ctx, 31, 0x1BDB08u);
    ctx->pc = 0x1BDB04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB00u;
            // 0x1bdb04: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE410u;
    if (runtime->hasFunction(0x1BE410u)) {
        auto targetFn = runtime->lookupFunction(0x1BE410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB08u; }
        if (ctx->pc != 0x1BDB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE410_0x1be410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB08u; }
        if (ctx->pc != 0x1BDB08u) { return; }
    }
    ctx->pc = 0x1BDB08u;
label_1bdb08:
    // 0x1bdb08: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1bdb08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1bdb0c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1bdb0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bdb10: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BDB10u;
    SET_GPR_U32(ctx, 31, 0x1BDB18u);
    ctx->pc = 0x1BDB14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB10u;
            // 0x1bdb14: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB18u; }
        if (ctx->pc != 0x1BDB18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB18u; }
        if (ctx->pc != 0x1BDB18u) { return; }
    }
    ctx->pc = 0x1BDB18u;
label_1bdb18:
    // 0x1bdb18: 0x440003c  bltz        $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x1BDB18u;
    {
        const bool branch_taken_0x1bdb18 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BDB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB18u;
            // 0x1bdb1c: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdb18) {
            ctx->pc = 0x1BDC0Cu;
            goto label_1bdc0c;
        }
    }
    ctx->pc = 0x1BDB20u;
    // 0x1bdb20: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1bdb20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdb24: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bdb24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdb28: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1BDB28u;
    SET_GPR_U32(ctx, 31, 0x1BDB30u);
    ctx->pc = 0x1BDB2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB28u;
            // 0x1bdb2c: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB30u; }
        if (ctx->pc != 0x1BDB30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB30u; }
        if (ctx->pc != 0x1BDB30u) { return; }
    }
    ctx->pc = 0x1BDB30u;
label_1bdb30:
    // 0x1bdb30: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1bdb30u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdb34: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1bdb34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdb38: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bdb38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdb3c: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1BDB3Cu;
    SET_GPR_U32(ctx, 31, 0x1BDB44u);
    ctx->pc = 0x1BDB40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB3Cu;
            // 0x1bdb40: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB44u; }
        if (ctx->pc != 0x1BDB44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB44u; }
        if (ctx->pc != 0x1BDB44u) { return; }
    }
    ctx->pc = 0x1BDB44u;
label_1bdb44:
    // 0x1bdb44: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x1bdb44u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1bdb48: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1bdb48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdb4c: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x1BDB4Cu;
    SET_GPR_U32(ctx, 31, 0x1BDB54u);
    ctx->pc = 0x1BDB50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB4Cu;
            // 0x1bdb50: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB54u; }
        if (ctx->pc != 0x1BDB54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB54u; }
        if (ctx->pc != 0x1BDB54u) { return; }
    }
    ctx->pc = 0x1BDB54u;
label_1bdb54:
    // 0x1bdb54: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BDB54u;
    SET_GPR_U32(ctx, 31, 0x1BDB5Cu);
    ctx->pc = 0x1BDB58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB54u;
            // 0x1bdb58: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB5Cu; }
        if (ctx->pc != 0x1BDB5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB5Cu; }
        if (ctx->pc != 0x1BDB5Cu) { return; }
    }
    ctx->pc = 0x1BDB5Cu;
label_1bdb5c:
    // 0x1bdb5c: 0x2623003f  addiu       $v1, $s1, 0x3F
    ctx->pc = 0x1bdb5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 63));
    // 0x1bdb60: 0xae110030  sw          $s1, 0x30($s0)
    ctx->pc = 0x1bdb60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 17));
    // 0x1bdb64: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BDB64u;
    {
        const bool branch_taken_0x1bdb64 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BDB68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB64u;
            // 0x1bdb68: 0x31183  sra         $v0, $v1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdb64) {
            ctx->pc = 0x1BDB74u;
            goto label_1bdb74;
        }
    }
    ctx->pc = 0x1BDB6Cu;
    // 0x1bdb6c: 0x2462003f  addiu       $v0, $v1, 0x3F
    ctx->pc = 0x1bdb6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1bdb70: 0x21183  sra         $v0, $v0, 6
    ctx->pc = 0x1bdb70u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 6));
label_1bdb74:
    // 0x1bdb74: 0x21980  sll         $v1, $v0, 6
    ctx->pc = 0x1bdb74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x1bdb78: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bdb78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bdb7c: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1bdb7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1bdb80: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bdb80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bdb84: 0xae02003c  sw          $v0, 0x3C($s0)
    ctx->pc = 0x1bdb84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 2));
    // 0x1bdb88: 0x8c254ff0  lw          $a1, 0x4FF0($at)
    ctx->pc = 0x1bdb88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20464)));
    // 0x1bdb8c: 0xc06f904  jal         func_1BE410
    ctx->pc = 0x1BDB8Cu;
    SET_GPR_U32(ctx, 31, 0x1BDB94u);
    ctx->pc = 0x1BDB90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB8Cu;
            // 0x1bdb90: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE410u;
    if (runtime->hasFunction(0x1BE410u)) {
        auto targetFn = runtime->lookupFunction(0x1BE410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB94u; }
        if (ctx->pc != 0x1BDB94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE410_0x1be410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDB94u; }
        if (ctx->pc != 0x1BDB94u) { return; }
    }
    ctx->pc = 0x1BDB94u;
label_1bdb94:
    // 0x1bdb94: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1bdb94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1bdb98: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1bdb98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bdb9c: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BDB9Cu;
    SET_GPR_U32(ctx, 31, 0x1BDBA4u);
    ctx->pc = 0x1BDBA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDB9Cu;
            // 0x1bdba0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBA4u; }
        if (ctx->pc != 0x1BDBA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBA4u; }
        if (ctx->pc != 0x1BDBA4u) { return; }
    }
    ctx->pc = 0x1BDBA4u;
label_1bdba4:
    // 0x1bdba4: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BDBA4u;
    {
        const bool branch_taken_0x1bdba4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BDBA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDBA4u;
            // 0x1bdba8: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdba4) {
            ctx->pc = 0x1BDBC0u;
            goto label_1bdbc0;
        }
    }
    ctx->pc = 0x1BDBACu;
    // 0x1bdbac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1bdbacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdbb0: 0xc06f660  jal         func_1BD980
    ctx->pc = 0x1BDBB0u;
    SET_GPR_U32(ctx, 31, 0x1BDBB8u);
    ctx->pc = 0x1BDBB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDBB0u;
            // 0x1bdbb4: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD980u;
    if (runtime->hasFunction(0x1BD980u)) {
        auto targetFn = runtime->lookupFunction(0x1BD980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBB8u; }
        if (ctx->pc != 0x1BDBB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD980_0x1bd980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBB8u; }
        if (ctx->pc != 0x1BDBB8u) { return; }
    }
    ctx->pc = 0x1BDBB8u;
label_1bdbb8:
    // 0x1bdbb8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1BDBB8u;
    {
        const bool branch_taken_0x1bdbb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDBBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDBB8u;
            // 0x1bdbbc: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bdbb8) {
            ctx->pc = 0x1BDC10u;
            goto label_1bdc10;
        }
    }
    ctx->pc = 0x1BDBC0u;
label_1bdbc0:
    // 0x1bdbc0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1bdbc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdbc4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bdbc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdbc8: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1BDBC8u;
    SET_GPR_U32(ctx, 31, 0x1BDBD0u);
    ctx->pc = 0x1BDBCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDBC8u;
            // 0x1bdbcc: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBD0u; }
        if (ctx->pc != 0x1BDBD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBD0u; }
        if (ctx->pc != 0x1BDBD0u) { return; }
    }
    ctx->pc = 0x1BDBD0u;
label_1bdbd0:
    // 0x1bdbd0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1bdbd0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdbd4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bdbd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdbd8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bdbd8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdbdc: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1BDBDCu;
    SET_GPR_U32(ctx, 31, 0x1BDBE4u);
    ctx->pc = 0x1BDBE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDBDCu;
            // 0x1bdbe0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBE4u; }
        if (ctx->pc != 0x1BDBE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBE4u; }
        if (ctx->pc != 0x1BDBE4u) { return; }
    }
    ctx->pc = 0x1BDBE4u;
label_1bdbe4:
    // 0x1bdbe4: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x1bdbe4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x1bdbe8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bdbe8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bdbec: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x1BDBECu;
    SET_GPR_U32(ctx, 31, 0x1BDBF4u);
    ctx->pc = 0x1BDBF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDBECu;
            // 0x1bdbf0: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBF4u; }
        if (ctx->pc != 0x1BDBF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBF4u; }
        if (ctx->pc != 0x1BDBF4u) { return; }
    }
    ctx->pc = 0x1BDBF4u;
label_1bdbf4:
    // 0x1bdbf4: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BDBF4u;
    SET_GPR_U32(ctx, 31, 0x1BDBFCu);
    ctx->pc = 0x1BDBF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDBF4u;
            // 0x1bdbf8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBFCu; }
        if (ctx->pc != 0x1BDBFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDBFCu; }
        if (ctx->pc != 0x1BDBFCu) { return; }
    }
    ctx->pc = 0x1BDBFCu;
label_1bdbfc:
    // 0x1bdbfc: 0xae120040  sw          $s2, 0x40($s0)
    ctx->pc = 0x1bdbfcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 18));
    // 0x1bdc00: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1bdc00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bdc04: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bdc04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bdc08: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1bdc08u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
label_1bdc0c:
    // 0x1bdc0c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1bdc0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1bdc10:
    // 0x1bdc10: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1bdc10u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bdc14: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bdc14u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bdc18: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bdc18u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bdc1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BDC1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BDC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDC1Cu;
            // 0x1bdc20: 0x27bd0140  addiu       $sp, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BDB08u: goto label_1bdb08;
            case 0x1BDB18u: goto label_1bdb18;
            case 0x1BDB30u: goto label_1bdb30;
            case 0x1BDB44u: goto label_1bdb44;
            case 0x1BDB54u: goto label_1bdb54;
            case 0x1BDB5Cu: goto label_1bdb5c;
            case 0x1BDB74u: goto label_1bdb74;
            case 0x1BDB94u: goto label_1bdb94;
            case 0x1BDBA4u: goto label_1bdba4;
            case 0x1BDBB8u: goto label_1bdbb8;
            case 0x1BDBC0u: goto label_1bdbc0;
            case 0x1BDBD0u: goto label_1bdbd0;
            case 0x1BDBE4u: goto label_1bdbe4;
            case 0x1BDBF4u: goto label_1bdbf4;
            case 0x1BDBFCu: goto label_1bdbfc;
            case 0x1BDC0Cu: goto label_1bdc0c;
            case 0x1BDC10u: goto label_1bdc10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BDC24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
