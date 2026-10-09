#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6370
// Address: 0x1d6370 - 0x1d64c8
void sub_001D6370_0x1d6370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6370_0x1d6370");
#endif

    switch (ctx->pc) {
        case 0x1d6414u: goto label_1d6414;
        case 0x1d6450u: goto label_1d6450;
        default: break;
    }

    ctx->pc = 0x1d6370u;

    // 0x1d6370: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d6370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d6374: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d6374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d6378: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1d6378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1d637c: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x1d637cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x1d6380: 0x30b10022  andi        $s1, $a1, 0x22
    ctx->pc = 0x1d6380u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)34);
    // 0x1d6384: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1d6384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1d6388: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1d6388u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d638c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1d638cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1d6390: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1d6390u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6394: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d6394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d6398: 0x30f0ffff  andi        $s0, $a3, 0xFFFF
    ctx->pc = 0x1d6398u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
    // 0x1d639c: 0x10820011  beq         $a0, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1D639Cu;
    {
        const bool branch_taken_0x1d639c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D63A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D639Cu;
            // 0x1d63a0: 0x11882b  sltu        $s1, $zero, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 17, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d639c) {
            ctx->pc = 0x1D63E4u;
            goto label_1d63e4;
        }
    }
    ctx->pc = 0x1D63A4u;
    // 0x1d63a4: 0x28820002  slti        $v0, $a0, 0x2
    ctx->pc = 0x1d63a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1d63a8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D63A8u;
    {
        const bool branch_taken_0x1d63a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d63a8) {
            ctx->pc = 0x1D63ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D63A8u;
            // 0x1d63ac: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D63C0u;
            goto label_1d63c0;
        }
    }
    ctx->pc = 0x1D63B0u;
    // 0x1d63b0: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D63B0u;
    {
        const bool branch_taken_0x1d63b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D63B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D63B0u;
            // 0x1d63b4: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d63b0) {
            ctx->pc = 0x1D63D0u;
            goto label_1d63d0;
        }
    }
    ctx->pc = 0x1D63B8u;
    // 0x1d63b8: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D63B8u;
    {
        const bool branch_taken_0x1d63b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d63b8) {
            ctx->pc = 0x1D640Cu;
            goto label_1d640c;
        }
    }
    ctx->pc = 0x1D63C0u;
label_1d63c0:
    // 0x1d63c0: 0x1082000d  beq         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1D63C0u;
    {
        const bool branch_taken_0x1d63c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D63C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D63C0u;
            // 0x1d63c4: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d63c0) {
            ctx->pc = 0x1D63F8u;
            goto label_1d63f8;
        }
    }
    ctx->pc = 0x1D63C8u;
    // 0x1d63c8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D63C8u;
    {
        const bool branch_taken_0x1d63c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d63c8) {
            ctx->pc = 0x1D640Cu;
            goto label_1d640c;
        }
    }
    ctx->pc = 0x1D63D0u;
label_1d63d0:
    // 0x1d63d0: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1d63d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1d63d4: 0x111a40  sll         $v1, $s1, 9
    ctx->pc = 0x1d63d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 9));
    // 0x1d63d8: 0x24426f58  addiu       $v0, $v0, 0x6F58
    ctx->pc = 0x1d63d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28504));
    // 0x1d63dc: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1D63DCu;
    {
        const bool branch_taken_0x1d63dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D63E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D63DCu;
            // 0x1d63e0: 0x629021  addu        $s2, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d63dc) {
            ctx->pc = 0x1D6414u;
            goto label_1d6414;
        }
    }
    ctx->pc = 0x1D63E4u;
label_1d63e4:
    // 0x1d63e4: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1d63e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1d63e8: 0x111a40  sll         $v1, $s1, 9
    ctx->pc = 0x1d63e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 9));
    // 0x1d63ec: 0x24427358  addiu       $v0, $v0, 0x7358
    ctx->pc = 0x1d63ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29528));
    // 0x1d63f0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D63F0u;
    {
        const bool branch_taken_0x1d63f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D63F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D63F0u;
            // 0x1d63f4: 0x629021  addu        $s2, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d63f0) {
            ctx->pc = 0x1D6414u;
            goto label_1d6414;
        }
    }
    ctx->pc = 0x1D63F8u;
label_1d63f8:
    // 0x1d63f8: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1d63f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1d63fc: 0x111a40  sll         $v1, $s1, 9
    ctx->pc = 0x1d63fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 9));
    // 0x1d6400: 0x24427758  addiu       $v0, $v0, 0x7758
    ctx->pc = 0x1d6400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30552));
    // 0x1d6404: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6404u;
    {
        const bool branch_taken_0x1d6404 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6404u;
            // 0x1d6408: 0x629021  addu        $s2, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6404) {
            ctx->pc = 0x1D6414u;
            goto label_1d6414;
        }
    }
    ctx->pc = 0x1D640Cu;
label_1d640c:
    // 0x1d640c: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D640Cu;
    SET_GPR_U32(ctx, 31, 0x1D6414u);
    ctx->pc = 0x1D6410u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D640Cu;
            // 0x1d6410: 0x24846f40  addiu       $a0, $a0, 0x6F40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6414u; }
        if (ctx->pc != 0x1D6414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6414u; }
        if (ctx->pc != 0x1D6414u) { return; }
    }
    ctx->pc = 0x1D6414u;
label_1d6414:
    // 0x1d6414: 0x12000025  beqz        $s0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1D6414u;
    {
        const bool branch_taken_0x1d6414 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6414u;
            // 0x1d6418: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6414) {
            ctx->pc = 0x1D64ACu;
            goto label_1d64ac;
        }
    }
    ctx->pc = 0x1D641Cu;
    // 0x1d641c: 0x2e020100  sltiu       $v0, $s0, 0x100
    ctx->pc = 0x1d641cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1d6420: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6420u;
    {
        const bool branch_taken_0x1d6420 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D6424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6420u;
            // 0x1d6424: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6420) {
            ctx->pc = 0x1D6430u;
            goto label_1d6430;
        }
    }
    ctx->pc = 0x1D6428u;
    // 0x1d6428: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1D6428u;
    {
        const bool branch_taken_0x1d6428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D642Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6428u;
            // 0x1d642c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6428) {
            ctx->pc = 0x1D64ACu;
            goto label_1d64ac;
        }
    }
    ctx->pc = 0x1D6430u;
label_1d6430:
    // 0x1d6430: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x1d6430u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x1d6434: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1d6434u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1d6438: 0x94450000  lhu         $a1, 0x0($v0)
    ctx->pc = 0x1d6438u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d643c: 0x14a30006  bne         $a1, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D643Cu;
    {
        const bool branch_taken_0x1d643c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D6440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D643Cu;
            // 0x1d6440: 0x34028000  ori         $v0, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d643c) {
            ctx->pc = 0x1D6458u;
            goto label_1d6458;
        }
    }
    ctx->pc = 0x1D6444u;
    // 0x1d6444: 0x326400ff  andi        $a0, $s3, 0xFF
    ctx->pc = 0x1d6444u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d6448: 0xc075932  jal         func_1D64C8
    ctx->pc = 0x1D6448u;
    SET_GPR_U32(ctx, 31, 0x1D6450u);
    ctx->pc = 0x1D644Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6448u;
            // 0x1d644c: 0x320500ff  andi        $a1, $s0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D64C8u;
    if (runtime->hasFunction(0x1D64C8u)) {
        auto targetFn = runtime->lookupFunction(0x1D64C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6450u; }
        if (ctx->pc != 0x1D6450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D64C8_0x1d64c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6450u; }
        if (ctx->pc != 0x1D6450u) { return; }
    }
    ctx->pc = 0x1D6450u;
label_1d6450:
    // 0x1d6450: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d6450u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6454: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x1d6454u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
label_1d6458:
    // 0x1d6458: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x1D6458u;
    {
        const bool branch_taken_0x1d6458 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d6458) {
            ctx->pc = 0x1D645Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6458u;
            // 0x1d645c: 0x36058000  ori         $a1, $s0, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D6460u;
            goto label_1d6460;
        }
    }
    ctx->pc = 0x1D6460u;
label_1d6460:
    // 0x1d6460: 0x24a2ff9f  addiu       $v0, $a1, -0x61
    ctx->pc = 0x1d6460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967199));
    // 0x1d6464: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1d6464u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1d6468: 0x2c42001a  sltiu       $v0, $v0, 0x1A
    ctx->pc = 0x1d6468u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)26) ? 1 : 0);
    // 0x1d646c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D646Cu;
    {
        const bool branch_taken_0x1d646c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D646Cu;
            // 0x1d6470: 0x32620002  andi        $v0, $s3, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d646c) {
            ctx->pc = 0x1D6480u;
            goto label_1d6480;
        }
    }
    ctx->pc = 0x1D6474u;
    // 0x1d6474: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D6474u;
    {
        const bool branch_taken_0x1d6474 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6474u;
            // 0x1d6478: 0x24a2ffe0  addiu       $v0, $a1, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6474) {
            ctx->pc = 0x1D6480u;
            goto label_1d6480;
        }
    }
    ctx->pc = 0x1D647Cu;
    // 0x1d647c: 0x3045ffff  andi        $a1, $v0, 0xFFFF
    ctx->pc = 0x1d647cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1d6480:
    // 0x1d6480: 0x24a2ffbf  addiu       $v0, $a1, -0x41
    ctx->pc = 0x1d6480u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967231));
    // 0x1d6484: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1d6484u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1d6488: 0x2c42001a  sltiu       $v0, $v0, 0x1A
    ctx->pc = 0x1d6488u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)26) ? 1 : 0);
    // 0x1d648c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D648Cu;
    {
        const bool branch_taken_0x1d648c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D648Cu;
            // 0x1d6490: 0x32620002  andi        $v0, $s3, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d648c) {
            ctx->pc = 0x1D64A8u;
            goto label_1d64a8;
        }
    }
    ctx->pc = 0x1D6494u;
    // 0x1d6494: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D6494u;
    {
        const bool branch_taken_0x1d6494 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D6498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6494u;
            // 0x1d6498: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6494) {
            ctx->pc = 0x1D64ACu;
            goto label_1d64ac;
        }
    }
    ctx->pc = 0x1D649Cu;
    // 0x1d649c: 0x12200002  beqz        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D649Cu;
    {
        const bool branch_taken_0x1d649c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D64A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D649Cu;
            // 0x1d64a0: 0x24a20020  addiu       $v0, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d649c) {
            ctx->pc = 0x1D64A8u;
            goto label_1d64a8;
        }
    }
    ctx->pc = 0x1D64A4u;
    // 0x1d64a4: 0x3045ffff  andi        $a1, $v0, 0xFFFF
    ctx->pc = 0x1d64a4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1d64a8:
    // 0x1d64a8: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1d64a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1d64ac:
    // 0x1d64ac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d64acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d64b0: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x1d64b0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d64b4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1d64b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d64b8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1d64b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d64bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1d64bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d64c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D64C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D64C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D64C0u;
            // 0x1d64c4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D63C0u: goto label_1d63c0;
            case 0x1D63D0u: goto label_1d63d0;
            case 0x1D63E4u: goto label_1d63e4;
            case 0x1D63F8u: goto label_1d63f8;
            case 0x1D640Cu: goto label_1d640c;
            case 0x1D6414u: goto label_1d6414;
            case 0x1D6430u: goto label_1d6430;
            case 0x1D6450u: goto label_1d6450;
            case 0x1D6458u: goto label_1d6458;
            case 0x1D6460u: goto label_1d6460;
            case 0x1D6480u: goto label_1d6480;
            case 0x1D64A8u: goto label_1d64a8;
            case 0x1D64ACu: goto label_1d64ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D64C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
