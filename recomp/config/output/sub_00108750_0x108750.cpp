#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108750
// Address: 0x108750 - 0x1088e0
void sub_00108750_0x108750(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108750_0x108750");
#endif

    switch (ctx->pc) {
        case 0x108780u: goto label_108780;
        case 0x108794u: goto label_108794;
        case 0x1087ccu: goto label_1087cc;
        case 0x108800u: goto label_108800;
        case 0x108858u: goto label_108858;
        case 0x1088a0u: goto label_1088a0;
        default: break;
    }

    ctx->pc = 0x108750u;

    // 0x108750: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x108750u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x108754: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x108754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x108758: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x108758u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10875c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10875cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x108760: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x108760u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108764: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x108764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x108768: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x108768u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10876c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10876cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108770: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x108770u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x108774: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x108774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x108778: 0xc0421ba  jal         func_1086E8
    ctx->pc = 0x108778u;
    SET_GPR_U32(ctx, 31, 0x108780u);
    ctx->pc = 0x10877Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108778u;
            // 0x10877c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1086E8u;
    if (runtime->hasFunction(0x1086E8u)) {
        auto targetFn = runtime->lookupFunction(0x1086E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108780u; }
        if (ctx->pc != 0x108780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001086E8_0x1086e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108780u; }
        if (ctx->pc != 0x108780u) { return; }
    }
    ctx->pc = 0x108780u;
label_108780:
    // 0x108780: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x108780u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108784: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x108784u;
    {
        const bool branch_taken_0x108784 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x108788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108784u;
            // 0x108788: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108784) {
            ctx->pc = 0x1087A8u;
            goto label_1087a8;
        }
    }
    ctx->pc = 0x10878Cu;
    // 0x10878c: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x10878Cu;
    SET_GPR_U32(ctx, 31, 0x108794u);
    ctx->pc = 0x108790u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10878Cu;
            // 0x108790: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108794u; }
        if (ctx->pc != 0x108794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108794u; }
        if (ctx->pc != 0x108794u) { return; }
    }
    ctx->pc = 0x108794u;
label_108794:
    // 0x108794: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x108794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x108798: 0x40582d  daddu       $t3, $v0, $zero
    ctx->pc = 0x108798u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10879c: 0xad630010  sw          $v1, 0x10($t3)
    ctx->pc = 0x10879cu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 16), GPR_U32(ctx, 3));
    // 0x1087a0: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1087A0u;
    {
        const bool branch_taken_0x1087a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1087A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1087A0u;
            // 0x1087a4: 0xad600014  sw          $zero, 0x14($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1087a0) {
            ctx->pc = 0x1088C4u;
            goto label_1088c4;
        }
    }
    ctx->pc = 0x1087A8u;
label_1087a8:
    // 0x1087a8: 0x6030005  bgezl       $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1087A8u;
    {
        const bool branch_taken_0x1087a8 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x1087a8) {
            ctx->pc = 0x1087ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1087A8u;
            // 0x1087ac: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1087C0u;
            goto label_1087c0;
        }
    }
    ctx->pc = 0x1087B0u;
    // 0x1087b0: 0x220582d  daddu       $t3, $s1, $zero
    ctx->pc = 0x1087b0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1087b4: 0x240882d  daddu       $s1, $s2, $zero
    ctx->pc = 0x1087b4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1087b8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1087b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1087bc: 0x160902d  daddu       $s2, $t3, $zero
    ctx->pc = 0x1087bcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
label_1087c0:
    // 0x1087c0: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x1087c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1087c4: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x1087C4u;
    SET_GPR_U32(ctx, 31, 0x1087CCu);
    ctx->pc = 0x1087C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1087C4u;
            // 0x1087c8: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1087CCu; }
        if (ctx->pc != 0x1087CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1087CCu; }
        if (ctx->pc != 0x1087CCu) { return; }
    }
    ctx->pc = 0x1087CCu;
label_1087cc:
    // 0x1087cc: 0x26280014  addiu       $t0, $s1, 0x14
    ctx->pc = 0x1087ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x1087d0: 0x40582d  daddu       $t3, $v0, $zero
    ctx->pc = 0x1087d0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1087d4: 0x26490014  addiu       $t1, $s2, 0x14
    ctx->pc = 0x1087d4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
    // 0x1087d8: 0xad70000c  sw          $s0, 0xC($t3)
    ctx->pc = 0x1087d8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 12), GPR_U32(ctx, 16));
    // 0x1087dc: 0x25670014  addiu       $a3, $t3, 0x14
    ctx->pc = 0x1087dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 11), 20));
    // 0x1087e0: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1087e0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1087e4: 0x8e2c0010  lw          $t4, 0x10($s1)
    ctx->pc = 0x1087e4u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1087e8: 0x8e420010  lw          $v0, 0x10($s2)
    ctx->pc = 0x1087e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1087ec: 0xc1880  sll         $v1, $t4, 2
    ctx->pc = 0x1087ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 12), 2));
    // 0x1087f0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1087f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1087f4: 0x1036821  addu        $t5, $t0, $v1
    ctx->pc = 0x1087f4u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1087f8: 0x1223021  addu        $a2, $t1, $v0
    ctx->pc = 0x1087f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x1087fc: 0x0  nop
    ctx->pc = 0x1087fcu;
    // NOP
label_108800:
    // 0x108800: 0x8d050000  lw          $a1, 0x0($t0)
    ctx->pc = 0x108800u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x108804: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x108804u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x108808: 0x8d220000  lw          $v0, 0x0($t1)
    ctx->pc = 0x108808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x10880c: 0x25290004  addiu       $t1, $t1, 0x4
    ctx->pc = 0x10880cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
    // 0x108810: 0x30a3ffff  andi        $v1, $a1, 0xFFFF
    ctx->pc = 0x108810u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x108814: 0x52c02  srl         $a1, $a1, 16
    ctx->pc = 0x108814u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x108818: 0x3044ffff  andi        $a0, $v0, 0xFFFF
    ctx->pc = 0x108818u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x10881c: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x10881cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x108820: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x108820u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x108824: 0xa22823  subu        $a1, $a1, $v0
    ctx->pc = 0x108824u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x108828: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x108828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x10882c: 0x126102b  sltu        $v0, $t1, $a2
    ctx->pc = 0x10882cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x108830: 0x35403  sra         $t2, $v1, 16
    ctx->pc = 0x108830u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 3), 16));
    // 0x108834: 0xa4e30000  sh          $v1, 0x0($a3)
    ctx->pc = 0x108834u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x108838: 0xaa2821  addu        $a1, $a1, $t2
    ctx->pc = 0x108838u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
    // 0x10883c: 0xa4e50002  sh          $a1, 0x2($a3)
    ctx->pc = 0x10883cu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 2), (uint16_t)GPR_U32(ctx, 5));
    // 0x108840: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x108840u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x108844: 0x1440ffee  bnez        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x108844u;
    {
        const bool branch_taken_0x108844 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x108848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108844u;
            // 0x108848: 0x55403  sra         $t2, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108844) {
            ctx->pc = 0x108800u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108800;
        }
    }
    ctx->pc = 0x10884Cu;
    // 0x10884c: 0x10d102b  sltu        $v0, $t0, $t5
    ctx->pc = 0x10884cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 13)) ? 1 : 0);
    // 0x108850: 0x5040000f  beql        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x108850u;
    {
        const bool branch_taken_0x108850 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x108850) {
            ctx->pc = 0x108854u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108850u;
            // 0x108854: 0x24e7fffc  addiu       $a3, $a3, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967292));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108890u;
            goto label_108890;
        }
    }
    ctx->pc = 0x108858u;
label_108858:
    // 0x108858: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x108858u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x10885c: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x10885cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x108860: 0x10d202b  sltu        $a0, $t0, $t5
    ctx->pc = 0x108860u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 13)) ? 1 : 0);
    // 0x108864: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x108864u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x108868: 0x21402  srl         $v0, $v0, 16
    ctx->pc = 0x108868u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x10886c: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x10886cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x108870: 0x35403  sra         $t2, $v1, 16
    ctx->pc = 0x108870u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 3), 16));
    // 0x108874: 0xa4e30000  sh          $v1, 0x0($a3)
    ctx->pc = 0x108874u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x108878: 0x4a2821  addu        $a1, $v0, $t2
    ctx->pc = 0x108878u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x10887c: 0xa4e50002  sh          $a1, 0x2($a3)
    ctx->pc = 0x10887cu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 2), (uint16_t)GPR_U32(ctx, 5));
    // 0x108880: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x108880u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x108884: 0x1480fff4  bnez        $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x108884u;
    {
        const bool branch_taken_0x108884 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x108888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108884u;
            // 0x108888: 0x55403  sra         $t2, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108884) {
            ctx->pc = 0x108858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108858;
        }
    }
    ctx->pc = 0x10888Cu;
    // 0x10888c: 0x24e7fffc  addiu       $a3, $a3, -0x4
    ctx->pc = 0x10888cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967292));
label_108890:
    // 0x108890: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x108890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x108894: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x108894u;
    {
        const bool branch_taken_0x108894 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x108894) {
            ctx->pc = 0x108898u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108894u;
            // 0x108898: 0xad6c0010  sw          $t4, 0x10($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 16), GPR_U32(ctx, 12));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1088C0u;
            goto label_1088c0;
        }
    }
    ctx->pc = 0x10889Cu;
    // 0x10889c: 0x0  nop
    ctx->pc = 0x10889cu;
    // NOP
label_1088a0:
    // 0x1088a0: 0x24e7fffc  addiu       $a3, $a3, -0x4
    ctx->pc = 0x1088a0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967292));
    // 0x1088a4: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x1088a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1088a8: 0x0  nop
    ctx->pc = 0x1088a8u;
    // NOP
    // 0x1088ac: 0x0  nop
    ctx->pc = 0x1088acu;
    // NOP
    // 0x1088b0: 0x0  nop
    ctx->pc = 0x1088b0u;
    // NOP
    // 0x1088b4: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1088B4u;
    {
        const bool branch_taken_0x1088b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1088B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1088B4u;
            // 0x1088b8: 0x258cffff  addiu       $t4, $t4, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1088b4) {
            ctx->pc = 0x1088A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1088a0;
        }
    }
    ctx->pc = 0x1088BCu;
    // 0x1088bc: 0xad6c0010  sw          $t4, 0x10($t3)
    ctx->pc = 0x1088bcu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 16), GPR_U32(ctx, 12));
label_1088c0:
    // 0x1088c0: 0x160102d  daddu       $v0, $t3, $zero
    ctx->pc = 0x1088c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
label_1088c4:
    // 0x1088c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1088c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1088c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1088c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1088cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1088ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1088d0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1088d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1088d4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1088d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1088d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1088D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1088DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1088D8u;
            // 0x1088dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108780u: goto label_108780;
            case 0x108794u: goto label_108794;
            case 0x1087A8u: goto label_1087a8;
            case 0x1087C0u: goto label_1087c0;
            case 0x1087CCu: goto label_1087cc;
            case 0x108800u: goto label_108800;
            case 0x108858u: goto label_108858;
            case 0x108890u: goto label_108890;
            case 0x1088A0u: goto label_1088a0;
            case 0x1088C0u: goto label_1088c0;
            case 0x1088C4u: goto label_1088c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1088E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
