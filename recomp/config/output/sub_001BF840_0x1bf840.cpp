#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BF840
// Address: 0x1bf840 - 0x1bfa50
void sub_001BF840_0x1bf840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BF840_0x1bf840");
#endif

    switch (ctx->pc) {
        case 0x1bf880u: goto label_1bf880;
        case 0x1bf8c0u: goto label_1bf8c0;
        case 0x1bf8d8u: goto label_1bf8d8;
        case 0x1bf91cu: goto label_1bf91c;
        case 0x1bf94cu: goto label_1bf94c;
        case 0x1bf9ccu: goto label_1bf9cc;
        default: break;
    }

    ctx->pc = 0x1bf840u;

    // 0x1bf840: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bf840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bf844: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bf844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bf848: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bf848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bf84c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bf84cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bf850: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1bf850u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bf854: 0x1062002f  beq         $v1, $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x1BF854u;
    {
        const bool branch_taken_0x1bf854 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BF858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF854u;
            // 0x1bf858: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf854) {
            ctx->pc = 0x1BF914u;
            goto label_1bf914;
        }
    }
    ctx->pc = 0x1BF85Cu;
    // 0x1bf85c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bf85cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bf860: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BF860u;
    {
        const bool branch_taken_0x1bf860 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1bf860) {
            ctx->pc = 0x1BF89Cu;
            goto label_1bf89c;
        }
    }
    ctx->pc = 0x1BF868u;
    // 0x1bf868: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BF868u;
    {
        const bool branch_taken_0x1bf868 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bf868) {
            ctx->pc = 0x1BF878u;
            goto label_1bf878;
        }
    }
    ctx->pc = 0x1BF870u;
    // 0x1bf870: 0x10000070  b           . + 4 + (0x70 << 2)
    ctx->pc = 0x1BF870u;
    {
        const bool branch_taken_0x1bf870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF870u;
            // 0x1bf874: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf870) {
            ctx->pc = 0x1BFA34u;
            goto label_1bfa34;
        }
    }
    ctx->pc = 0x1BF878u;
label_1bf878:
    // 0x1bf878: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BF878u;
    SET_GPR_U32(ctx, 31, 0x1BF880u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF880u; }
        if (ctx->pc != 0x1BF880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF880u; }
        if (ctx->pc != 0x1BF880u) { return; }
    }
    ctx->pc = 0x1BF880u;
label_1bf880:
    // 0x1bf880: 0x440006b  bltz        $v0, . + 4 + (0x6B << 2)
    ctx->pc = 0x1BF880u;
    {
        const bool branch_taken_0x1bf880 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bf880) {
            ctx->pc = 0x1BFA30u;
            goto label_1bfa30;
        }
    }
    ctx->pc = 0x1BF888u;
    // 0x1bf888: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1bf888u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bf88c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1bf88cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1bf890: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bf890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bf894: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1bf894u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1bf898: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x1bf898u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
label_1bf89c:
    // 0x1bf89c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bf89cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf8a0: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bf8a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bf8a4: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1bf8a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1bf8a8: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bf8a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bf8ac: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bf8acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bf8b0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bf8b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bf8b4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bf8b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bf8b8: 0xc060418  jal         func_181060
    ctx->pc = 0x1BF8B8u;
    SET_GPR_U32(ctx, 31, 0x1BF8C0u);
    ctx->pc = 0x1BF8BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF8B8u;
            // 0x1bf8bc: 0x24a56ae8  addiu       $a1, $a1, 0x6AE8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181060u;
    if (runtime->hasFunction(0x181060u)) {
        auto targetFn = runtime->lookupFunction(0x181060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF8C0u; }
        if (ctx->pc != 0x1BF8C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181060_0x181060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF8C0u; }
        if (ctx->pc != 0x1BF8C0u) { return; }
    }
    ctx->pc = 0x1BF8C0u;
label_1bf8c0:
    // 0x1bf8c0: 0x4410010  bgez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1BF8C0u;
    {
        const bool branch_taken_0x1bf8c0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bf8c0) {
            ctx->pc = 0x1BF904u;
            goto label_1bf904;
        }
    }
    ctx->pc = 0x1BF8C8u;
    // 0x1bf8c8: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x1bf8c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bf8cc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bf8ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bf8d0: 0x1c400057  bgtz        $v0, . + 4 + (0x57 << 2)
    ctx->pc = 0x1BF8D0u;
    {
        const bool branch_taken_0x1bf8d0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1BF8D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF8D0u;
            // 0x1bf8d4: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf8d0) {
            ctx->pc = 0x1BFA30u;
            goto label_1bfa30;
        }
    }
    ctx->pc = 0x1BF8D8u;
label_1bf8d8:
    // 0x1bf8d8: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bf8d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bf8dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1bf8dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bf8e0: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bf8e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf8e4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bf8e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bf8e8: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1bf8e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1bf8ec: 0xac600028  sw          $zero, 0x28($v1)
    ctx->pc = 0x1bf8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 40), GPR_U32(ctx, 0));
    // 0x1bf8f0: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bf8f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf8f4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bf8f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bf8f8: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1bf8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1bf8fc: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1BF8FCu;
    {
        const bool branch_taken_0x1bf8fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF8FCu;
            // 0x1bf900: 0xac600034  sw          $zero, 0x34($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf8fc) {
            ctx->pc = 0x1BFA34u;
            goto label_1bfa34;
        }
    }
    ctx->pc = 0x1BF904u;
label_1bf904:
    // 0x1bf904: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bf904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bf908: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bf908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bf90c: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1BF90Cu;
    {
        const bool branch_taken_0x1bf90c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF90Cu;
            // 0x1bf910: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf90c) {
            ctx->pc = 0x1BFA30u;
            goto label_1bfa30;
        }
    }
    ctx->pc = 0x1BF914u;
label_1bf914:
    // 0x1bf914: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BF914u;
    SET_GPR_U32(ctx, 31, 0x1BF91Cu);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF91Cu; }
        if (ctx->pc != 0x1BF91Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BF91Cu; }
        if (ctx->pc != 0x1BF91Cu) { return; }
    }
    ctx->pc = 0x1BF91Cu;
label_1bf91c:
    // 0x1bf91c: 0x4400044  bltz        $v0, . + 4 + (0x44 << 2)
    ctx->pc = 0x1BF91Cu;
    {
        const bool branch_taken_0x1bf91c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bf91c) {
            ctx->pc = 0x1BFA30u;
            goto label_1bfa30;
        }
    }
    ctx->pc = 0x1BF924u;
    // 0x1bf924: 0x9603001c  lhu         $v1, 0x1C($s0)
    ctx->pc = 0x1bf924u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bf928: 0x2402002f  addiu       $v0, $zero, 0x2F
    ctx->pc = 0x1bf928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1bf92c: 0x10620022  beq         $v1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1BF92Cu;
    {
        const bool branch_taken_0x1bf92c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BF930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF92Cu;
            // 0x1bf930: 0x34029003  ori         $v0, $zero, 0x9003 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36867);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf92c) {
            ctx->pc = 0x1BF9B8u;
            goto label_1bf9b8;
        }
    }
    ctx->pc = 0x1BF934u;
    // 0x1bf934: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1BF934u;
    {
        const bool branch_taken_0x1bf934 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1bf934) {
            ctx->pc = 0x1BF998u;
            goto label_1bf998;
        }
    }
    ctx->pc = 0x1BF93Cu;
    // 0x1bf93c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BF93Cu;
    {
        const bool branch_taken_0x1bf93c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF93Cu;
            // 0x1bf940: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf93c) {
            ctx->pc = 0x1BF94Cu;
            goto label_1bf94c;
        }
    }
    ctx->pc = 0x1BF944u;
    // 0x1bf944: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1BF944u;
    {
        const bool branch_taken_0x1bf944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF944u;
            // 0x1bf948: 0x8e020020  lw          $v0, 0x20($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf944) {
            ctx->pc = 0x1BFA04u;
            goto label_1bfa04;
        }
    }
    ctx->pc = 0x1BF94Cu;
label_1bf94c:
    // 0x1bf94c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bf94cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bf950: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bf950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bf954: 0x8c236ae8  lw          $v1, 0x6AE8($at)
    ctx->pc = 0x1bf954u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27368)));
    // 0x1bf958: 0x1462ffdf  bne         $v1, $v0, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1BF958u;
    {
        const bool branch_taken_0x1bf958 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1BF95Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF958u;
            // 0x1bf95c: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf958) {
            ctx->pc = 0x1BF8D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bf8d8;
        }
    }
    ctx->pc = 0x1BF960u;
    // 0x1bf960: 0x8c226aec  lw          $v0, 0x6AEC($at)
    ctx->pc = 0x1bf960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27372)));
    // 0x1bf964: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1BF964u;
    {
        const bool branch_taken_0x1bf964 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bf964) {
            ctx->pc = 0x1BF9B8u;
            goto label_1bf9b8;
        }
    }
    ctx->pc = 0x1BF96Cu;
    // 0x1bf96c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1bf96cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf970: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bf970u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bf974: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1bf974u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1bf978: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1bf978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1bf97c: 0xac450028  sw          $a1, 0x28($v0)
    ctx->pc = 0x1bf97cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 40), GPR_U32(ctx, 5));
    // 0x1bf980: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1bf980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf984: 0x8c236af0  lw          $v1, 0x6AF0($at)
    ctx->pc = 0x1bf984u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27376)));
    // 0x1bf988: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1bf988u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1bf98c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1bf98cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1bf990: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1BF990u;
    {
        const bool branch_taken_0x1bf990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF990u;
            // 0x1bf994: 0xac430034  sw          $v1, 0x34($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf990) {
            ctx->pc = 0x1BFA18u;
            goto label_1bfa18;
        }
    }
    ctx->pc = 0x1BF998u;
label_1bf998:
    // 0x1bf998: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bf998u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf99c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bf99cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bf9a0: 0x8e020040  lw          $v0, 0x40($s0)
    ctx->pc = 0x1bf9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1bf9a4: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1bf9a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bf9a8: 0x641804  sllv        $v1, $a0, $v1
    ctx->pc = 0x1bf9a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 3) & 0x1F));
    // 0x1bf9ac: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1bf9acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1bf9b0: 0x1000ffe6  b           . + 4 + (-0x1A << 2)
    ctx->pc = 0x1BF9B0u;
    {
        const bool branch_taken_0x1bf9b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF9B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF9B0u;
            // 0x1bf9b4: 0xae020040  sw          $v0, 0x40($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf9b0) {
            ctx->pc = 0x1BF94Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bf94c;
        }
    }
    ctx->pc = 0x1BF9B8u;
label_1bf9b8:
    // 0x1bf9b8: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x1bf9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bf9bc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bf9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bf9c0: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BF9C0u;
    {
        const bool branch_taken_0x1bf9c0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1BF9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF9C0u;
            // 0x1bf9c4: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf9c0) {
            ctx->pc = 0x1BF9D8u;
            goto label_1bf9d8;
        }
    }
    ctx->pc = 0x1BF9C8u;
    // 0x1bf9c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1bf9c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bf9cc:
    // 0x1bf9cc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1bf9ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1bf9d0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BF9D0u;
    {
        const bool branch_taken_0x1bf9d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BF9D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF9D0u;
            // 0x1bf9d4: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf9d0) {
            ctx->pc = 0x1BFA34u;
            goto label_1bfa34;
        }
    }
    ctx->pc = 0x1BF9D8u;
label_1bf9d8:
    // 0x1bf9d8: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1bf9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf9dc: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1bf9dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1bf9e0: 0x24031f40  addiu       $v1, $zero, 0x1F40
    ctx->pc = 0x1bf9e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8000));
    // 0x1bf9e4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1bf9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1bf9e8: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1bf9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1bf9ec: 0xac440028  sw          $a0, 0x28($v0)
    ctx->pc = 0x1bf9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 40), GPR_U32(ctx, 4));
    // 0x1bf9f0: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1bf9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bf9f4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1bf9f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1bf9f8: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1bf9f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1bf9fc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BF9FCu;
    {
        const bool branch_taken_0x1bf9fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BF9FCu;
            // 0x1bfa00: 0xac430034  sw          $v1, 0x34($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bf9fc) {
            ctx->pc = 0x1BFA18u;
            goto label_1bfa18;
        }
    }
    ctx->pc = 0x1BFA04u;
label_1bfa04:
    // 0x1bfa04: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1bfa04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1bfa08: 0x1840ffb3  blez        $v0, . + 4 + (-0x4D << 2)
    ctx->pc = 0x1BFA08u;
    {
        const bool branch_taken_0x1bfa08 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1BFA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFA08u;
            // 0x1bfa0c: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfa08) {
            ctx->pc = 0x1BF8D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bf8d8;
        }
    }
    ctx->pc = 0x1BFA10u;
    // 0x1bfa10: 0x1000ffee  b           . + 4 + (-0x12 << 2)
    ctx->pc = 0x1BFA10u;
    {
        const bool branch_taken_0x1bfa10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFA10u;
            // 0x1bfa14: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfa10) {
            ctx->pc = 0x1BF9CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bf9cc;
        }
    }
    ctx->pc = 0x1BFA18u;
label_1bfa18:
    // 0x1bfa18: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfa18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfa1c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1bfa1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bfa20: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1bfa20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1bfa24: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1bfa24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1bfa28: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BFA28u;
    {
        const bool branch_taken_0x1bfa28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFA28u;
            // 0x1bfa2c: 0x8c420028  lw          $v0, 0x28($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfa28) {
            ctx->pc = 0x1BFA34u;
            goto label_1bfa34;
        }
    }
    ctx->pc = 0x1BFA30u;
label_1bfa30:
    // 0x1bfa30: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1bfa30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1bfa34:
    // 0x1bfa34: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bfa34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bfa38: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bfa38u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bfa3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BFA3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BFA40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFA3Cu;
            // 0x1bfa40: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BF878u: goto label_1bf878;
            case 0x1BF880u: goto label_1bf880;
            case 0x1BF89Cu: goto label_1bf89c;
            case 0x1BF8C0u: goto label_1bf8c0;
            case 0x1BF8D8u: goto label_1bf8d8;
            case 0x1BF904u: goto label_1bf904;
            case 0x1BF914u: goto label_1bf914;
            case 0x1BF91Cu: goto label_1bf91c;
            case 0x1BF94Cu: goto label_1bf94c;
            case 0x1BF998u: goto label_1bf998;
            case 0x1BF9B8u: goto label_1bf9b8;
            case 0x1BF9CCu: goto label_1bf9cc;
            case 0x1BF9D8u: goto label_1bf9d8;
            case 0x1BFA04u: goto label_1bfa04;
            case 0x1BFA18u: goto label_1bfa18;
            case 0x1BFA30u: goto label_1bfa30;
            case 0x1BFA34u: goto label_1bfa34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BFA44u;
    // 0x1bfa44: 0x0  nop
    ctx->pc = 0x1bfa44u;
    // NOP
    // 0x1bfa48: 0x0  nop
    ctx->pc = 0x1bfa48u;
    // NOP
    // 0x1bfa4c: 0x0  nop
    ctx->pc = 0x1bfa4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
