#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164740
// Address: 0x164740 - 0x164900
void sub_00164740_0x164740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164740_0x164740");
#endif

    switch (ctx->pc) {
        case 0x164790u: goto label_164790;
        case 0x164878u: goto label_164878;
        case 0x164884u: goto label_164884;
        case 0x16488cu: goto label_16488c;
        default: break;
    }

    ctx->pc = 0x164740u;

    // 0x164740: 0x24020120  addiu       $v0, $zero, 0x120
    ctx->pc = 0x164740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 288));
    // 0x164744: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164744u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164748: 0x28a50120  slti        $a1, $a1, 0x120
    ctx->pc = 0x164748u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)288) ? 1 : 0);
    // 0x16474c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16474cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164750: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x164750u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x164754: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x164754u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164758: 0x14a0000e  bnez        $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x164758u;
    {
        const bool branch_taken_0x164758 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x16475Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164758u;
            // 0x16475c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164758) {
            ctx->pc = 0x164794u;
            goto label_164794;
        }
    }
    ctx->pc = 0x164760u;
    // 0x164760: 0x90c40000  lbu         $a0, 0x0($a2)
    ctx->pc = 0x164760u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x164764: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x164764u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x164768: 0x5483000b  bnel        $a0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x164768u;
    {
        const bool branch_taken_0x164768 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x164768) {
            ctx->pc = 0x16476Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164768u;
            // 0x16476c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164798u;
            goto label_164798;
        }
    }
    ctx->pc = 0x164770u;
    // 0x164770: 0x90c30001  lbu         $v1, 0x1($a2)
    ctx->pc = 0x164770u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x164774: 0x54600008  bnel        $v1, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x164774u;
    {
        const bool branch_taken_0x164774 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x164774) {
            ctx->pc = 0x164778u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164774u;
            // 0x164778: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164798u;
            goto label_164798;
        }
    }
    ctx->pc = 0x16477Cu;
    // 0x16477c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x16477cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x164780: 0x24c4011a  addiu       $a0, $a2, 0x11A
    ctx->pc = 0x164780u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 282));
    // 0x164784: 0x24a505f8  addiu       $a1, $a1, 0x5F8
    ctx->pc = 0x164784u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1528));
    // 0x164788: 0xc042d10  jal         func_10B440
    ctx->pc = 0x164788u;
    SET_GPR_U32(ctx, 31, 0x164790u);
    ctx->pc = 0x16478Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164788u;
            // 0x16478c: 0x24060006  addiu       $a2, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164790u; }
        if (ctx->pc != 0x164790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164790u; }
        if (ctx->pc != 0x164790u) { return; }
    }
    ctx->pc = 0x164790u;
label_164790:
    // 0x164790: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x164790u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_164794:
    // 0x164794: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164794u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_164798:
    // 0x164798: 0x3e00008  jr          $ra
    ctx->pc = 0x164798u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16479Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164798u;
            // 0x16479c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164790u: goto label_164790;
            case 0x164794u: goto label_164794;
            case 0x164798u: goto label_164798;
            case 0x1647D4u: goto label_1647d4;
            case 0x164878u: goto label_164878;
            case 0x164884u: goto label_164884;
            case 0x16488Cu: goto label_16488c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1647A0u;
    // 0x1647a0: 0x24020012  addiu       $v0, $zero, 0x12
    ctx->pc = 0x1647a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1647a4: 0x28a50012  slti        $a1, $a1, 0x12
    ctx->pc = 0x1647a4u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x1647a8: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x1647a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x1647ac: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1647acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1647b0: 0x14a00008  bnez        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1647B0u;
    {
        const bool branch_taken_0x1647b0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1647B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1647B0u;
            // 0x1647b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1647b0) {
            ctx->pc = 0x1647D4u;
            goto label_1647d4;
        }
    }
    ctx->pc = 0x1647B8u;
    // 0x1647b8: 0x90c40000  lbu         $a0, 0x0($a2)
    ctx->pc = 0x1647b8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1647bc: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x1647bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1647c0: 0x14830004  bne         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1647C0u;
    {
        const bool branch_taken_0x1647c0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1647c0) {
            ctx->pc = 0x1647D4u;
            goto label_1647d4;
        }
    }
    ctx->pc = 0x1647C8u;
    // 0x1647c8: 0x90c20001  lbu         $v0, 0x1($a2)
    ctx->pc = 0x1647c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x1647cc: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1647ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1647d0: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1647d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_1647d4:
    // 0x1647d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1647D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164790u: goto label_164790;
            case 0x164794u: goto label_164794;
            case 0x164798u: goto label_164798;
            case 0x1647D4u: goto label_1647d4;
            case 0x164878u: goto label_164878;
            case 0x164884u: goto label_164884;
            case 0x16488Cu: goto label_16488c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1647DCu;
    // 0x1647dc: 0x0  nop
    ctx->pc = 0x1647dcu;
    // NOP
    // 0x1647e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1647e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1647e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1647e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1647e8: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x1647e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x1647ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1647ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1647f0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1647f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1647f4: 0x804c98e  j           func_132638
    ctx->pc = 0x1647F4u;
    ctx->pc = 0x1647F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1647F4u;
            // 0x1647f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132638u;
    if (runtime->hasFunction(0x132638u)) {
        auto targetFn = runtime->lookupFunction(0x132638u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132638_0x132638(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1647FCu;
    // 0x1647fc: 0x0  nop
    ctx->pc = 0x1647fcu;
    // NOP
    // 0x164800: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164804: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164808: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x164808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x16480c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16480cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164810: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x164810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x164814: 0x804c9bc  j           func_1326F0
    ctx->pc = 0x164814u;
    ctx->pc = 0x164818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164814u;
            // 0x164818: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1326F0u;
    if (runtime->hasFunction(0x1326F0u)) {
        auto targetFn = runtime->lookupFunction(0x1326F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001326F0_0x1326f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16481Cu;
    // 0x16481c: 0x0  nop
    ctx->pc = 0x16481cu;
    // NOP
    // 0x164820: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164824: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164828: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x164828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x16482c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16482cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164830: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x164830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x164834: 0x804c9ee  j           func_1327B8
    ctx->pc = 0x164834u;
    ctx->pc = 0x164838u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164834u;
            // 0x164838: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1327B8u;
    if (runtime->hasFunction(0x1327B8u)) {
        auto targetFn = runtime->lookupFunction(0x1327B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001327B8_0x1327b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16483Cu;
    // 0x16483c: 0x0  nop
    ctx->pc = 0x16483cu;
    // NOP
    // 0x164840: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164844: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164848: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x164848u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x16484c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16484cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164850: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x164850u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x164854: 0x804ca08  j           func_132820
    ctx->pc = 0x164854u;
    ctx->pc = 0x164858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164854u;
            // 0x164858: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132820u;
    if (runtime->hasFunction(0x132820u)) {
        auto targetFn = runtime->lookupFunction(0x132820u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132820_0x132820(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16485Cu;
    // 0x16485c: 0x0  nop
    ctx->pc = 0x16485cu;
    // NOP
    // 0x164860: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164864: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x164864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164868: 0x24901b6c  addiu       $s0, $a0, 0x1B6C
    ctx->pc = 0x164868u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 7020));
    // 0x16486c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16486cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x164870: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x164870u;
    SET_GPR_U32(ctx, 31, 0x164878u);
    ctx->pc = 0x164874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164870u;
            // 0x164874: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164878u; }
        if (ctx->pc != 0x164878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164878u; }
        if (ctx->pc != 0x164878u) { return; }
    }
    ctx->pc = 0x164878u;
label_164878:
    // 0x164878: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x164878u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16487c: 0xc0489aa  jal         func_1226A8
    ctx->pc = 0x16487Cu;
    SET_GPR_U32(ctx, 31, 0x164884u);
    ctx->pc = 0x1226A8u;
    if (runtime->hasFunction(0x1226A8u)) {
        auto targetFn = runtime->lookupFunction(0x1226A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164884u; }
        if (ctx->pc != 0x164884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001226A8_0x1226a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164884u; }
        if (ctx->pc != 0x164884u) { return; }
    }
    ctx->pc = 0x164884u;
label_164884:
    // 0x164884: 0xc04491c  jal         func_112470
    ctx->pc = 0x164884u;
    SET_GPR_U32(ctx, 31, 0x16488Cu);
    ctx->pc = 0x164888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164884u;
            // 0x164888: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16488Cu; }
        if (ctx->pc != 0x16488Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16488Cu; }
        if (ctx->pc != 0x16488Cu) { return; }
    }
    ctx->pc = 0x16488Cu;
label_16488c:
    // 0x16488c: 0x3c0140dd  lui         $at, 0x40DD
    ctx->pc = 0x16488cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16605 << 16));
    // 0x164890: 0x34210c54  ori         $at, $at, 0xC54
    ctx->pc = 0x164890u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)3156);
    // 0x164894: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x164894u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x164898: 0x3c0144d8  lui         $at, 0x44D8
    ctx->pc = 0x164898u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17624 << 16));
    // 0x16489c: 0x3421677d  ori         $at, $at, 0x677D
    ctx->pc = 0x16489cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)26493);
    // 0x1648a0: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x1648a0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x1648a4: 0x46020001  sub.s       $f0, $f0, $f2
    ctx->pc = 0x1648a4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x1648a8: 0x3c013c23  lui         $at, 0x3C23
    ctx->pc = 0x1648a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)15395 << 16));
    // 0x1648ac: 0x3421d70a  ori         $at, $at, 0xD70A
    ctx->pc = 0x1648acu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)55050);
    // 0x1648b0: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x1648b0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1648b4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1648b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1648b8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1648b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1648bc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1648bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1648c0: 0x46030002  mul.s       $f0, $f0, $f3
    ctx->pc = 0x1648c0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x1648c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1648c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1648c8: 0x46010042  mul.s       $f1, $f0, $f1
    ctx->pc = 0x1648c8u;
    ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1648cc: 0x460000a4  .word       0x460000A4                   # cvt.w.s     $f2, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1648ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x1648d0: 0x44031000  mfc1        $v1, $f2
    ctx->pc = 0x1648d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1648d4: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1648d4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1648d8: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x1648d8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1648dc: 0x23040  sll         $a2, $v0, 1
    ctx->pc = 0x1648dcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1648e0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1648e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1648e4: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1648e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1648e8: 0x630c0  sll         $a2, $a2, 3
    ctx->pc = 0x1648e8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1648ec: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1648ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1648f0: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1648f0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1648f4: 0x663023  subu        $a2, $v1, $a2
    ctx->pc = 0x1648f4u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1648f8: 0x804cbf8  j           func_132FE0
    ctx->pc = 0x1648F8u;
    ctx->pc = 0x1648FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1648F8u;
            // 0x1648fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132FE0u;
    if (runtime->hasFunction(0x132FE0u)) {
        auto targetFn = runtime->lookupFunction(0x132FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132FE0_0x132fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164900u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
