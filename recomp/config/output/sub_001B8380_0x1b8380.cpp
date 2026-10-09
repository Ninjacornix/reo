#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8380
// Address: 0x1b8380 - 0x1b86c0
void sub_001B8380_0x1b8380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8380_0x1b8380");
#endif

    switch (ctx->pc) {
        case 0x1b841cu: goto label_1b841c;
        case 0x1b8434u: goto label_1b8434;
        case 0x1b8464u: goto label_1b8464;
        case 0x1b848cu: goto label_1b848c;
        case 0x1b84a0u: goto label_1b84a0;
        case 0x1b84bcu: goto label_1b84bc;
        case 0x1b8530u: goto label_1b8530;
        case 0x1b854cu: goto label_1b854c;
        case 0x1b8580u: goto label_1b8580;
        case 0x1b8598u: goto label_1b8598;
        case 0x1b85ccu: goto label_1b85cc;
        case 0x1b85e8u: goto label_1b85e8;
        case 0x1b861cu: goto label_1b861c;
        case 0x1b864cu: goto label_1b864c;
        case 0x1b866cu: goto label_1b866c;
        case 0x1b8684u: goto label_1b8684;
        default: break;
    }

    ctx->pc = 0x1b8380u;

    // 0x1b8380: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x1b8380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x1b8384: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b8384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b8388: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b8388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b838c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b838cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8390: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b8390u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b8394: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b8394u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b8398: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b8398u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b839c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b839cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b83a0: 0x80236558  lb          $v1, 0x6558($at)
    ctx->pc = 0x1b83a0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 25944)));
    // 0x1b83a4: 0x1062004b  beq         $v1, $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x1B83A4u;
    {
        const bool branch_taken_0x1b83a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B83A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B83A4u;
            // 0x1b83a8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b83a4) {
            ctx->pc = 0x1B84D4u;
            goto label_1b84d4;
        }
    }
    ctx->pc = 0x1B83ACu;
    // 0x1b83ac: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b83acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b83b0: 0x10620049  beq         $v1, $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x1B83B0u;
    {
        const bool branch_taken_0x1b83b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B83B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B83B0u;
            // 0x1b83b4: 0x641021  addu        $v0, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b83b0) {
            ctx->pc = 0x1B84D8u;
            goto label_1b84d8;
        }
    }
    ctx->pc = 0x1B83B8u;
    // 0x1b83b8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b83b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b83bc: 0x10620045  beq         $v1, $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1B83BCu;
    {
        const bool branch_taken_0x1b83bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B83C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B83BCu;
            // 0x1b83c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b83bc) {
            ctx->pc = 0x1B84D4u;
            goto label_1b84d4;
        }
    }
    ctx->pc = 0x1B83C4u;
    // 0x1b83c4: 0x10620043  beq         $v1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1B83C4u;
    {
        const bool branch_taken_0x1b83c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b83c4) {
            ctx->pc = 0x1B84D4u;
            goto label_1b84d4;
        }
    }
    ctx->pc = 0x1B83CCu;
    // 0x1b83cc: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B83CCu;
    {
        const bool branch_taken_0x1b83cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b83cc) {
            ctx->pc = 0x1B83DCu;
            goto label_1b83dc;
        }
    }
    ctx->pc = 0x1B83D4u;
    // 0x1b83d4: 0x100000b0  b           . + 4 + (0xB0 << 2)
    ctx->pc = 0x1B83D4u;
    {
        const bool branch_taken_0x1b83d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B83D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B83D4u;
            // 0x1b83d8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b83d4) {
            ctx->pc = 0x1B8698u;
            goto label_1b8698;
        }
    }
    ctx->pc = 0x1B83DCu;
label_1b83dc:
    // 0x1b83dc: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x1b83dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b83e0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B83E0u;
    {
        const bool branch_taken_0x1b83e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B83E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B83E0u;
            // 0x1b83e4: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b83e0) {
            ctx->pc = 0x1B83F0u;
            goto label_1b83f0;
        }
    }
    ctx->pc = 0x1B83E8u;
    // 0x1b83e8: 0x100000ac  b           . + 4 + (0xAC << 2)
    ctx->pc = 0x1B83E8u;
    {
        const bool branch_taken_0x1b83e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B83ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B83E8u;
            // 0x1b83ec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b83e8) {
            ctx->pc = 0x1B869Cu;
            goto label_1b869c;
        }
    }
    ctx->pc = 0x1B83F0u;
label_1b83f0:
    // 0x1b83f0: 0x2403ffc0  addiu       $v1, $zero, -0x40
    ctx->pc = 0x1b83f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1b83f4: 0x8c22440c  lw          $v0, 0x440C($at)
    ctx->pc = 0x1b83f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1b83f8: 0x3c010008  lui         $at, 0x8
    ctx->pc = 0x1b83f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)8 << 16));
    // 0x1b83fc: 0x412021  addu        $a0, $v0, $at
    ctx->pc = 0x1b83fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
    // 0x1b8400: 0x3c01000c  lui         $at, 0xC
    ctx->pc = 0x1b8400u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)12 << 16));
    // 0x1b8404: 0x2484003f  addiu       $a0, $a0, 0x3F
    ctx->pc = 0x1b8404u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 63));
    // 0x1b8408: 0x411021  addu        $v0, $v0, $at
    ctx->pc = 0x1b8408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
    // 0x1b840c: 0x832024  and         $a0, $a0, $v1
    ctx->pc = 0x1b840cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1b8410: 0x2442003f  addiu       $v0, $v0, 0x3F
    ctx->pc = 0x1b8410u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x1b8414: 0xc06b52c  jal         func_1AD4B0
    ctx->pc = 0x1B8414u;
    SET_GPR_U32(ctx, 31, 0x1B841Cu);
    ctx->pc = 0x1B8418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8414u;
            // 0x1b8418: 0x432824  and         $a1, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD4B0u;
    if (runtime->hasFunction(0x1AD4B0u)) {
        auto targetFn = runtime->lookupFunction(0x1AD4B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B841Cu; }
        if (ctx->pc != 0x1B841Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD4B0_0x1ad4b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B841Cu; }
        if (ctx->pc != 0x1B841Cu) { return; }
    }
    ctx->pc = 0x1B841Cu;
label_1b841c:
    // 0x1b841c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b841cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b8420: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b8420u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b8424: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b8424u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b8428: 0x24a50148  addiu       $a1, $a1, 0x148
    ctx->pc = 0x1b8428u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 328));
    // 0x1b842c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1B842Cu;
    SET_GPR_U32(ctx, 31, 0x1B8434u);
    ctx->pc = 0x1B8430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B842Cu;
            // 0x1b8430: 0x24c60160  addiu       $a2, $a2, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8434u; }
        if (ctx->pc != 0x1B8434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8434u; }
        if (ctx->pc != 0x1B8434u) { return; }
    }
    ctx->pc = 0x1B8434u;
label_1b8434:
    // 0x1b8434: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b8434u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b8438: 0x27b10050  addiu       $s1, $sp, 0x50
    ctx->pc = 0x1b8438u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b843c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1b843cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1b8440: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x1b8440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1b8444: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1b8444u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8448: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b8448u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b844c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b844cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8450: 0x24634000  addiu       $v1, $v1, 0x4000
    ctx->pc = 0x1b8450u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16384));
    // 0x1b8454: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1b8454u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1b8458: 0x629024  and         $s2, $v1, $v0
    ctx->pc = 0x1b8458u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1b845c: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1B845Cu;
    SET_GPR_U32(ctx, 31, 0x1B8464u);
    ctx->pc = 0x1B8460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B845Cu;
            // 0x1b8460: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8464u; }
        if (ctx->pc != 0x1B8464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8464u; }
        if (ctx->pc != 0x1B8464u) { return; }
    }
    ctx->pc = 0x1B8464u;
label_1b8464:
    // 0x1b8464: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1b8464u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8468: 0x1e600003  bgtz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B8468u;
    {
        const bool branch_taken_0x1b8468 = (GPR_S64(ctx, 19) > 0);
        ctx->pc = 0x1B846Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8468u;
            // 0x1b846c: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8468) {
            ctx->pc = 0x1B8478u;
            goto label_1b8478;
        }
    }
    ctx->pc = 0x1B8470u;
    // 0x1b8470: 0x1000008a  b           . + 4 + (0x8A << 2)
    ctx->pc = 0x1B8470u;
    {
        const bool branch_taken_0x1b8470 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8470u;
            // 0x1b8474: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8470) {
            ctx->pc = 0x1B869Cu;
            goto label_1b869c;
        }
    }
    ctx->pc = 0x1B8478u;
label_1b8478:
    // 0x1b8478: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b8478u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b847c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b847cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8480: 0x24a50178  addiu       $a1, $a1, 0x178
    ctx->pc = 0x1b8480u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 376));
    // 0x1b8484: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1B8484u;
    SET_GPR_U32(ctx, 31, 0x1B848Cu);
    ctx->pc = 0x1B8488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8484u;
            // 0x1b8488: 0x24c60160  addiu       $a2, $a2, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B848Cu; }
        if (ctx->pc != 0x1B848Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B848Cu; }
        if (ctx->pc != 0x1B848Cu) { return; }
    }
    ctx->pc = 0x1B848Cu;
label_1b848c:
    // 0x1b848c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1b848cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8490: 0x2532821  addu        $a1, $s2, $s3
    ctx->pc = 0x1b8490u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    // 0x1b8494: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1b8494u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8498: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1B8498u;
    SET_GPR_U32(ctx, 31, 0x1B84A0u);
    ctx->pc = 0x1B849Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8498u;
            // 0x1b849c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B84A0u; }
        if (ctx->pc != 0x1B84A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B84A0u; }
        if (ctx->pc != 0x1B84A0u) { return; }
    }
    ctx->pc = 0x1B84A0u;
label_1b84a0:
    // 0x1b84a0: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B84A0u;
    {
        const bool branch_taken_0x1b84a0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1B84A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B84A0u;
            // 0x1b84a4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b84a0) {
            ctx->pc = 0x1B84B0u;
            goto label_1b84b0;
        }
    }
    ctx->pc = 0x1B84A8u;
    // 0x1b84a8: 0x1000007c  b           . + 4 + (0x7C << 2)
    ctx->pc = 0x1B84A8u;
    {
        const bool branch_taken_0x1b84a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B84ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B84A8u;
            // 0x1b84ac: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b84a8) {
            ctx->pc = 0x1B869Cu;
            goto label_1b869c;
        }
    }
    ctx->pc = 0x1B84B0u;
label_1b84b0:
    // 0x1b84b0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1b84b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b84b4: 0xc06b504  jal         func_1AD410
    ctx->pc = 0x1B84B4u;
    SET_GPR_U32(ctx, 31, 0x1B84BCu);
    ctx->pc = 0x1B84B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B84B4u;
            // 0x1b84b8: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD410u;
    if (runtime->hasFunction(0x1AD410u)) {
        auto targetFn = runtime->lookupFunction(0x1AD410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B84BCu; }
        if (ctx->pc != 0x1B84BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD410_0x1ad410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B84BCu; }
        if (ctx->pc != 0x1B84BCu) { return; }
    }
    ctx->pc = 0x1B84BCu;
label_1b84bc:
    // 0x1b84bc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b84bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b84c0: 0x80226558  lb          $v0, 0x6558($at)
    ctx->pc = 0x1b84c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 25944)));
    // 0x1b84c4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b84c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b84c8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b84c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b84cc: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1B84CCu;
    {
        const bool branch_taken_0x1b84cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B84D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B84CCu;
            // 0x1b84d0: 0xa0226558  sb          $v0, 0x6558($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 25944), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b84cc) {
            ctx->pc = 0x1B8698u;
            goto label_1b8698;
        }
    }
    ctx->pc = 0x1B84D4u;
label_1b84d4:
    // 0x1b84d4: 0x641021  addu        $v0, $v1, $a0
    ctx->pc = 0x1b84d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_1b84d8:
    // 0x1b84d8: 0x9043ffff  lbu         $v1, -0x1($v0)
    ctx->pc = 0x1b84d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x1b84dc: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B84DCu;
    {
        const bool branch_taken_0x1b84dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B84E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B84DCu;
            // 0x1b84e0: 0x2c62003a  sltiu       $v0, $v1, 0x3A (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)58) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b84dc) {
            ctx->pc = 0x1B84FCu;
            goto label_1b84fc;
        }
    }
    ctx->pc = 0x1B84E4u;
    // 0x1b84e4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b84e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b84e8: 0x80226558  lb          $v0, 0x6558($at)
    ctx->pc = 0x1b84e8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 25944)));
    // 0x1b84ec: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b84ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b84f0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b84f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b84f4: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1B84F4u;
    {
        const bool branch_taken_0x1b84f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B84F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B84F4u;
            // 0x1b84f8: 0xa0226558  sb          $v0, 0x6558($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 25944), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b84f4) {
            ctx->pc = 0x1B8698u;
            goto label_1b8698;
        }
    }
    ctx->pc = 0x1B84FCu;
label_1b84fc:
    // 0x1b84fc: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1B84FCu;
    {
        const bool branch_taken_0x1b84fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b84fc) {
            ctx->pc = 0x1B8538u;
            goto label_1b8538;
        }
    }
    ctx->pc = 0x1B8504u;
    // 0x1b8504: 0x3c020039  lui         $v0, 0x39
    ctx->pc = 0x1b8504u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)57 << 16));
    // 0x1b8508: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b8508u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b850c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b850cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b8510: 0x24428be4  addiu       $v0, $v0, -0x741C
    ctx->pc = 0x1b8510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937572));
    // 0x1b8514: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8518: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b8518u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b851c: 0x8c470000  lw          $a3, 0x0($v0)
    ctx->pc = 0x1b851cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b8520: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b8520u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b8524: 0x24a50188  addiu       $a1, $a1, 0x188
    ctx->pc = 0x1b8524u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 392));
    // 0x1b8528: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1B8528u;
    SET_GPR_U32(ctx, 31, 0x1B8530u);
    ctx->pc = 0x1B852Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8528u;
            // 0x1b852c: 0x24c60160  addiu       $a2, $a2, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8530u; }
        if (ctx->pc != 0x1B8530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8530u; }
        if (ctx->pc != 0x1B8530u) { return; }
    }
    ctx->pc = 0x1B8530u;
label_1b8530:
    // 0x1b8530: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1B8530u;
    {
        const bool branch_taken_0x1b8530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8530) {
            ctx->pc = 0x1B864Cu;
            goto label_1b864c;
        }
    }
    ctx->pc = 0x1B8538u;
label_1b8538:
    // 0x1b8538: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b8538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b853c: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B853Cu;
    {
        const bool branch_taken_0x1b853c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B8540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B853Cu;
            // 0x1b8540: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b853c) {
            ctx->pc = 0x1B8588u;
            goto label_1b8588;
        }
    }
    ctx->pc = 0x1B8544u;
    // 0x1b8544: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B8544u;
    SET_GPR_U32(ctx, 31, 0x1B854Cu);
    ctx->pc = 0x1B8548u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8544u;
            // 0x1b8548: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B854Cu; }
        if (ctx->pc != 0x1B854Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B854Cu; }
        if (ctx->pc != 0x1B854Cu) { return; }
    }
    ctx->pc = 0x1B854Cu;
label_1b854c:
    // 0x1b854c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b854cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b8550: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b8550u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b8554: 0x3c020039  lui         $v0, 0x39
    ctx->pc = 0x1b8554u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)57 << 16));
    // 0x1b8558: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1b8558u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1b855c: 0x24428cc4  addiu       $v0, $v0, -0x733C
    ctx->pc = 0x1b855cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937796));
    // 0x1b8560: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b8560u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b8564: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8568: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b8568u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b856c: 0x8c470000  lw          $a3, 0x0($v0)
    ctx->pc = 0x1b856cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b8570: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b8570u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b8574: 0x24a50188  addiu       $a1, $a1, 0x188
    ctx->pc = 0x1b8574u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 392));
    // 0x1b8578: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1B8578u;
    SET_GPR_U32(ctx, 31, 0x1B8580u);
    ctx->pc = 0x1B857Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8578u;
            // 0x1b857c: 0x24c60160  addiu       $a2, $a2, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8580u; }
        if (ctx->pc != 0x1B8580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8580u; }
        if (ctx->pc != 0x1B8580u) { return; }
    }
    ctx->pc = 0x1B8580u;
label_1b8580:
    // 0x1b8580: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1B8580u;
    {
        const bool branch_taken_0x1b8580 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8580) {
            ctx->pc = 0x1B864Cu;
            goto label_1b864c;
        }
    }
    ctx->pc = 0x1B8588u;
label_1b8588:
    // 0x1b8588: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B8588u;
    {
        const bool branch_taken_0x1b8588 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B858Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8588u;
            // 0x1b858c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8588) {
            ctx->pc = 0x1B85D4u;
            goto label_1b85d4;
        }
    }
    ctx->pc = 0x1B8590u;
    // 0x1b8590: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B8590u;
    SET_GPR_U32(ctx, 31, 0x1B8598u);
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8598u; }
        if (ctx->pc != 0x1B8598u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8598u; }
        if (ctx->pc != 0x1B8598u) { return; }
    }
    ctx->pc = 0x1B8598u;
label_1b8598:
    // 0x1b8598: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b8598u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b859c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b859cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b85a0: 0x3c020039  lui         $v0, 0x39
    ctx->pc = 0x1b85a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)57 << 16));
    // 0x1b85a4: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1b85a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1b85a8: 0x24428cb4  addiu       $v0, $v0, -0x734C
    ctx->pc = 0x1b85a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937780));
    // 0x1b85ac: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b85acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b85b0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b85b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b85b4: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b85b4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b85b8: 0x8c470000  lw          $a3, 0x0($v0)
    ctx->pc = 0x1b85b8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b85bc: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b85bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b85c0: 0x24a50188  addiu       $a1, $a1, 0x188
    ctx->pc = 0x1b85c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 392));
    // 0x1b85c4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1B85C4u;
    SET_GPR_U32(ctx, 31, 0x1B85CCu);
    ctx->pc = 0x1B85C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B85C4u;
            // 0x1b85c8: 0x24c60160  addiu       $a2, $a2, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B85CCu; }
        if (ctx->pc != 0x1B85CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B85CCu; }
        if (ctx->pc != 0x1B85CCu) { return; }
    }
    ctx->pc = 0x1B85CCu;
label_1b85cc:
    // 0x1b85cc: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1B85CCu;
    {
        const bool branch_taken_0x1b85cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b85cc) {
            ctx->pc = 0x1B864Cu;
            goto label_1b864c;
        }
    }
    ctx->pc = 0x1B85D4u;
label_1b85d4:
    // 0x1b85d4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b85d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b85d8: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B85D8u;
    {
        const bool branch_taken_0x1b85d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B85DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B85D8u;
            // 0x1b85dc: 0x3c020039  lui         $v0, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)57 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b85d8) {
            ctx->pc = 0x1B8624u;
            goto label_1b8624;
        }
    }
    ctx->pc = 0x1B85E0u;
    // 0x1b85e0: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B85E0u;
    SET_GPR_U32(ctx, 31, 0x1B85E8u);
    ctx->pc = 0x1B85E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B85E0u;
            // 0x1b85e4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B85E8u; }
        if (ctx->pc != 0x1B85E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B85E8u; }
        if (ctx->pc != 0x1B85E8u) { return; }
    }
    ctx->pc = 0x1B85E8u;
label_1b85e8:
    // 0x1b85e8: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b85e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b85ec: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b85ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b85f0: 0x3c020039  lui         $v0, 0x39
    ctx->pc = 0x1b85f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)57 << 16));
    // 0x1b85f4: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1b85f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1b85f8: 0x24428cbc  addiu       $v0, $v0, -0x7344
    ctx->pc = 0x1b85f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937788));
    // 0x1b85fc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b85fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b8600: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8604: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b8604u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b8608: 0x8c470000  lw          $a3, 0x0($v0)
    ctx->pc = 0x1b8608u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b860c: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b860cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b8610: 0x24a50188  addiu       $a1, $a1, 0x188
    ctx->pc = 0x1b8610u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 392));
    // 0x1b8614: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1B8614u;
    SET_GPR_U32(ctx, 31, 0x1B861Cu);
    ctx->pc = 0x1B8618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8614u;
            // 0x1b8618: 0x24c60160  addiu       $a2, $a2, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B861Cu; }
        if (ctx->pc != 0x1B861Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B861Cu; }
        if (ctx->pc != 0x1B861Cu) { return; }
    }
    ctx->pc = 0x1B861Cu;
label_1b861c:
    // 0x1b861c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B861Cu;
    {
        const bool branch_taken_0x1b861c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b861c) {
            ctx->pc = 0x1B864Cu;
            goto label_1b864c;
        }
    }
    ctx->pc = 0x1B8624u;
label_1b8624:
    // 0x1b8624: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b8624u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b8628: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b8628u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b862c: 0x24428cac  addiu       $v0, $v0, -0x7354
    ctx->pc = 0x1b862cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937772));
    // 0x1b8630: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8634: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1b8634u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1b8638: 0x8c470000  lw          $a3, 0x0($v0)
    ctx->pc = 0x1b8638u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b863c: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b863cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b8640: 0x24a50188  addiu       $a1, $a1, 0x188
    ctx->pc = 0x1b8640u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 392));
    // 0x1b8644: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1B8644u;
    SET_GPR_U32(ctx, 31, 0x1B864Cu);
    ctx->pc = 0x1B8648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8644u;
            // 0x1b8648: 0x24c60160  addiu       $a2, $a2, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B864Cu; }
        if (ctx->pc != 0x1B864Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B864Cu; }
        if (ctx->pc != 0x1B864Cu) { return; }
    }
    ctx->pc = 0x1B864Cu;
label_1b864c:
    // 0x1b864c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b864cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b8650: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b8650u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b8654: 0x8c22440c  lw          $v0, 0x440C($at)
    ctx->pc = 0x1b8654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1b8658: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1b8658u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b865c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b865cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8660: 0x24514000  addiu       $s1, $v0, 0x4000
    ctx->pc = 0x1b8660u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 16384));
    // 0x1b8664: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1B8664u;
    SET_GPR_U32(ctx, 31, 0x1B866Cu);
    ctx->pc = 0x1B8668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8664u;
            // 0x1b8668: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B866Cu; }
        if (ctx->pc != 0x1B866Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B866Cu; }
        if (ctx->pc != 0x1B866Cu) { return; }
    }
    ctx->pc = 0x1B866Cu;
label_1b866c:
    // 0x1b866c: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B866Cu;
    {
        const bool branch_taken_0x1b866c = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1B8670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B866Cu;
            // 0x1b8670: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b866c) {
            ctx->pc = 0x1B867Cu;
            goto label_1b867c;
        }
    }
    ctx->pc = 0x1B8674u;
    // 0x1b8674: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B8674u;
    {
        const bool branch_taken_0x1b8674 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8674u;
            // 0x1b8678: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8674) {
            ctx->pc = 0x1B869Cu;
            goto label_1b869c;
        }
    }
    ctx->pc = 0x1B867Cu;
label_1b867c:
    // 0x1b867c: 0xc06b538  jal         func_1AD4E0
    ctx->pc = 0x1B867Cu;
    SET_GPR_U32(ctx, 31, 0x1B8684u);
    ctx->pc = 0x1AD4E0u;
    if (runtime->hasFunction(0x1AD4E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AD4E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8684u; }
        if (ctx->pc != 0x1B8684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD4E0_0x1ad4e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8684u; }
        if (ctx->pc != 0x1B8684u) { return; }
    }
    ctx->pc = 0x1B8684u;
label_1b8684:
    // 0x1b8684: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b8684u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b8688: 0x80226558  lb          $v0, 0x6558($at)
    ctx->pc = 0x1b8688u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 25944)));
    // 0x1b868c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b868cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b8690: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b8690u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b8694: 0xa0226558  sb          $v0, 0x6558($at)
    ctx->pc = 0x1b8694u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 25944), (uint8_t)GPR_U32(ctx, 2));
label_1b8698:
    // 0x1b8698: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1b8698u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b869c:
    // 0x1b869c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b869cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b86a0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b86a0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b86a4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b86a4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b86a8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b86a8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b86ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b86acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b86b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B86B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B86B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B86B0u;
            // 0x1b86b4: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B83DCu: goto label_1b83dc;
            case 0x1B83F0u: goto label_1b83f0;
            case 0x1B841Cu: goto label_1b841c;
            case 0x1B8434u: goto label_1b8434;
            case 0x1B8464u: goto label_1b8464;
            case 0x1B8478u: goto label_1b8478;
            case 0x1B848Cu: goto label_1b848c;
            case 0x1B84A0u: goto label_1b84a0;
            case 0x1B84B0u: goto label_1b84b0;
            case 0x1B84BCu: goto label_1b84bc;
            case 0x1B84D4u: goto label_1b84d4;
            case 0x1B84D8u: goto label_1b84d8;
            case 0x1B84FCu: goto label_1b84fc;
            case 0x1B8530u: goto label_1b8530;
            case 0x1B8538u: goto label_1b8538;
            case 0x1B854Cu: goto label_1b854c;
            case 0x1B8580u: goto label_1b8580;
            case 0x1B8588u: goto label_1b8588;
            case 0x1B8598u: goto label_1b8598;
            case 0x1B85CCu: goto label_1b85cc;
            case 0x1B85D4u: goto label_1b85d4;
            case 0x1B85E8u: goto label_1b85e8;
            case 0x1B861Cu: goto label_1b861c;
            case 0x1B8624u: goto label_1b8624;
            case 0x1B864Cu: goto label_1b864c;
            case 0x1B866Cu: goto label_1b866c;
            case 0x1B867Cu: goto label_1b867c;
            case 0x1B8684u: goto label_1b8684;
            case 0x1B8698u: goto label_1b8698;
            case 0x1B869Cu: goto label_1b869c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B86B8u;
    // 0x1b86b8: 0x0  nop
    ctx->pc = 0x1b86b8u;
    // NOP
    // 0x1b86bc: 0x0  nop
    ctx->pc = 0x1b86bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
