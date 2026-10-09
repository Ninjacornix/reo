#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001810F0
// Address: 0x1810f0 - 0x181230
void sub_001810F0_0x1810f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001810F0_0x1810f0");
#endif

    switch (ctx->pc) {
        case 0x181130u: goto label_181130;
        case 0x181160u: goto label_181160;
        case 0x181188u: goto label_181188;
        case 0x181190u: goto label_181190;
        case 0x1811dcu: goto label_1811dc;
        case 0x181218u: goto label_181218;
        default: break;
    }

    ctx->pc = 0x1810f0u;

    // 0x1810f0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1810f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1810f4: 0x27bdfdd0  addiu       $sp, $sp, -0x230
    ctx->pc = 0x1810f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966736));
    // 0x1810f8: 0x8c67fa10  lw          $a3, -0x5F0($v1)
    ctx->pc = 0x1810f8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x1810fc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1810fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181100: 0xffb10208  sd          $s1, 0x208($sp)
    ctx->pc = 0x181100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 520), GPR_U64(ctx, 17));
    // 0x181104: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x181104u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181108: 0xffb20210  sd          $s2, 0x210($sp)
    ctx->pc = 0x181108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 528), GPR_U64(ctx, 18));
    // 0x18110c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x18110cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181110: 0xffb30218  sd          $s3, 0x218($sp)
    ctx->pc = 0x181110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 536), GPR_U64(ctx, 19));
    // 0x181114: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x181114u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181118: 0xffb00200  sd          $s0, 0x200($sp)
    ctx->pc = 0x181118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 512), GPR_U64(ctx, 16));
    // 0x18111c: 0x34428001  ori         $v0, $v0, 0x8001
    ctx->pc = 0x18111cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
    // 0x181120: 0x10e0001c  beqz        $a3, . + 4 + (0x1C << 2)
    ctx->pc = 0x181120u;
    {
        const bool branch_taken_0x181120 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x181124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181120u;
            // 0x181124: 0xffbf0220  sd          $ra, 0x220($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 544), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181120) {
            ctx->pc = 0x181194u;
            goto label_181194;
        }
    }
    ctx->pc = 0x181128u;
    // 0x181128: 0xc061e90  jal         func_187A40
    ctx->pc = 0x181128u;
    SET_GPR_U32(ctx, 31, 0x181130u);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181130u; }
        if (ctx->pc != 0x181130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181130u; }
        if (ctx->pc != 0x181130u) { return; }
    }
    ctx->pc = 0x181130u;
label_181130:
    // 0x181130: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x181130u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x181134: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181134u;
    {
        const bool branch_taken_0x181134 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181134u;
            // 0x181138: 0x24709500  addiu       $s0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181134) {
            ctx->pc = 0x181148u;
            goto label_181148;
        }
    }
    ctx->pc = 0x18113Cu;
    // 0x18113c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18113cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181140: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x181140u;
    {
        const bool branch_taken_0x181140 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x181144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181140u;
            // 0x181144: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181140) {
            ctx->pc = 0x181194u;
            goto label_181194;
        }
    }
    ctx->pc = 0x181148u;
label_181148:
    // 0x181148: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x181148u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x18114c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18114cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181150: 0x14600010  bnez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x181150u;
    {
        const bool branch_taken_0x181150 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x181154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181150u;
            // 0x181154: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181150) {
            ctx->pc = 0x181194u;
            goto label_181194;
        }
    }
    ctx->pc = 0x181158u;
    // 0x181158: 0xc042c56  jal         func_10B158
    ctx->pc = 0x181158u;
    SET_GPR_U32(ctx, 31, 0x181160u);
    ctx->pc = 0x18115Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181158u;
            // 0x18115c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181160u; }
        if (ctx->pc != 0x181160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181160u; }
        if (ctx->pc != 0x181160u) { return; }
    }
    ctx->pc = 0x181160u;
label_181160:
    // 0x181160: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x181160u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181164: 0x2c430080  sltiu       $v1, $v0, 0x80
    ctx->pc = 0x181164u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x181168: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x181168u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18116c: 0x2604041c  addiu       $a0, $s0, 0x41C
    ctx->pc = 0x18116cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1052));
    // 0x181170: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x181170u;
    {
        const bool branch_taken_0x181170 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x181174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181170u;
            // 0x181174: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181170) {
            ctx->pc = 0x181194u;
            goto label_181194;
        }
    }
    ctx->pc = 0x181178u;
    // 0x181178: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x181178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18117c: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x18117cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x181180: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x181180u;
    SET_GPR_U32(ctx, 31, 0x181188u);
    ctx->pc = 0x181184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181180u;
            // 0x181184: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181188u; }
        if (ctx->pc != 0x181188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181188u; }
        if (ctx->pc != 0x181188u) { return; }
    }
    ctx->pc = 0x181188u;
label_181188:
    // 0x181188: 0xc062228  jal         func_1888A0
    ctx->pc = 0x181188u;
    SET_GPR_U32(ctx, 31, 0x181190u);
    ctx->pc = 0x18118Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181188u;
            // 0x18118c: 0xae13000c  sw          $s3, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181190u; }
        if (ctx->pc != 0x181190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181190u; }
        if (ctx->pc != 0x181190u) { return; }
    }
    ctx->pc = 0x181190u;
label_181190:
    // 0x181190: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x181190u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_181194:
    // 0x181194: 0xdfb00200  ld          $s0, 0x200($sp)
    ctx->pc = 0x181194u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 512)));
    // 0x181198: 0xdfb10208  ld          $s1, 0x208($sp)
    ctx->pc = 0x181198u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 520)));
    // 0x18119c: 0xdfb20210  ld          $s2, 0x210($sp)
    ctx->pc = 0x18119cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x1811a0: 0xdfb30218  ld          $s3, 0x218($sp)
    ctx->pc = 0x1811a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 536)));
    // 0x1811a4: 0xdfbf0220  ld          $ra, 0x220($sp)
    ctx->pc = 0x1811a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x1811a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1811A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1811ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1811A8u;
            // 0x1811ac: 0x27bd0230  addiu       $sp, $sp, 0x230 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 560));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181130u: goto label_181130;
            case 0x181148u: goto label_181148;
            case 0x181160u: goto label_181160;
            case 0x181188u: goto label_181188;
            case 0x181190u: goto label_181190;
            case 0x181194u: goto label_181194;
            case 0x1811DCu: goto label_1811dc;
            case 0x1811F8u: goto label_1811f8;
            case 0x181218u: goto label_181218;
            case 0x18121Cu: goto label_18121c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1811B0u;
    // 0x1811b0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1811b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1811b4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1811b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1811b8: 0x8c65fa10  lw          $a1, -0x5F0($v1)
    ctx->pc = 0x1811b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x1811bc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1811bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1811c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1811c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1811c4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1811c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1811c8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1811c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1811cc: 0x10a00013  beqz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1811CCu;
    {
        const bool branch_taken_0x1811cc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1811D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1811CCu;
            // 0x1811d0: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1811cc) {
            ctx->pc = 0x18121Cu;
            goto label_18121c;
        }
    }
    ctx->pc = 0x1811D4u;
    // 0x1811d4: 0xc061e90  jal         func_187A40
    ctx->pc = 0x1811D4u;
    SET_GPR_U32(ctx, 31, 0x1811DCu);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1811DCu; }
        if (ctx->pc != 0x1811DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1811DCu; }
        if (ctx->pc != 0x1811DCu) { return; }
    }
    ctx->pc = 0x1811DCu;
label_1811dc:
    // 0x1811dc: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x1811dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x1811e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1811E0u;
    {
        const bool branch_taken_0x1811e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1811E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1811E0u;
            // 0x1811e4: 0x24649500  addiu       $a0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1811e0) {
            ctx->pc = 0x1811F8u;
            goto label_1811f8;
        }
    }
    ctx->pc = 0x1811E8u;
    // 0x1811e8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1811e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1811ec: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1811ECu;
    {
        const bool branch_taken_0x1811ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1811F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1811ECu;
            // 0x1811f0: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1811ec) {
            ctx->pc = 0x18121Cu;
            goto label_18121c;
        }
    }
    ctx->pc = 0x1811F4u;
    // 0x1811f4: 0x0  nop
    ctx->pc = 0x1811f4u;
    // NOP
label_1811f8:
    // 0x1811f8: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1811f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1811fc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1811fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181200: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x181200u;
    {
        const bool branch_taken_0x181200 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x181204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181200u;
            // 0x181204: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181200) {
            ctx->pc = 0x18121Cu;
            goto label_18121c;
        }
    }
    ctx->pc = 0x181208u;
    // 0x181208: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x181208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x18120c: 0xac900000  sw          $s0, 0x0($a0)
    ctx->pc = 0x18120cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x181210: 0xc062228  jal         func_1888A0
    ctx->pc = 0x181210u;
    SET_GPR_U32(ctx, 31, 0x181218u);
    ctx->pc = 0x181214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181210u;
            // 0x181214: 0xac820004  sw          $v0, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181218u; }
        if (ctx->pc != 0x181218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181218u; }
        if (ctx->pc != 0x181218u) { return; }
    }
    ctx->pc = 0x181218u;
label_181218:
    // 0x181218: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x181218u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18121c:
    // 0x18121c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18121cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181220: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x181220u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x181224: 0x3e00008  jr          $ra
    ctx->pc = 0x181224u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181224u;
            // 0x181228: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181130u: goto label_181130;
            case 0x181148u: goto label_181148;
            case 0x181160u: goto label_181160;
            case 0x181188u: goto label_181188;
            case 0x181190u: goto label_181190;
            case 0x181194u: goto label_181194;
            case 0x1811DCu: goto label_1811dc;
            case 0x1811F8u: goto label_1811f8;
            case 0x181218u: goto label_181218;
            case 0x18121Cu: goto label_18121c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18122Cu;
    // 0x18122c: 0x0  nop
    ctx->pc = 0x18122cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
