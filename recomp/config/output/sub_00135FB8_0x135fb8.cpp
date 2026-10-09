#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135FB8
// Address: 0x135fb8 - 0x136a80
void sub_00135FB8_0x135fb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135FB8_0x135fb8");
#endif

    switch (ctx->pc) {
        case 0x135ff4u: goto label_135ff4;
        case 0x13601cu: goto label_13601c;
        case 0x136034u: goto label_136034;
        case 0x136048u: goto label_136048;
        case 0x13605cu: goto label_13605c;
        case 0x1360bcu: goto label_1360bc;
        case 0x1360e4u: goto label_1360e4;
        case 0x1360fcu: goto label_1360fc;
        case 0x136110u: goto label_136110;
        case 0x136128u: goto label_136128;
        case 0x136160u: goto label_136160;
        case 0x136190u: goto label_136190;
        case 0x1361ecu: goto label_1361ec;
        case 0x136210u: goto label_136210;
        case 0x136220u: goto label_136220;
        case 0x136228u: goto label_136228;
        case 0x136258u: goto label_136258;
        case 0x136270u: goto label_136270;
        case 0x136298u: goto label_136298;
        case 0x1362a8u: goto label_1362a8;
        case 0x136308u: goto label_136308;
        case 0x136328u: goto label_136328;
        case 0x136338u: goto label_136338;
        case 0x136388u: goto label_136388;
        case 0x1363c8u: goto label_1363c8;
        case 0x1363e8u: goto label_1363e8;
        case 0x1363f8u: goto label_1363f8;
        case 0x13644cu: goto label_13644c;
        case 0x136474u: goto label_136474;
        case 0x13648cu: goto label_13648c;
        case 0x1364a0u: goto label_1364a0;
        case 0x1364b4u: goto label_1364b4;
        case 0x1364f8u: goto label_1364f8;
        case 0x136518u: goto label_136518;
        case 0x136530u: goto label_136530;
        case 0x136544u: goto label_136544;
        case 0x13655cu: goto label_13655c;
        case 0x1365acu: goto label_1365ac;
        case 0x1365c0u: goto label_1365c0;
        case 0x1365d8u: goto label_1365d8;
        case 0x1365e8u: goto label_1365e8;
        case 0x136620u: goto label_136620;
        case 0x136644u: goto label_136644;
        case 0x1366c4u: goto label_1366c4;
        case 0x1366dcu: goto label_1366dc;
        case 0x1366f4u: goto label_1366f4;
        case 0x13670cu: goto label_13670c;
        case 0x136714u: goto label_136714;
        case 0x136734u: goto label_136734;
        case 0x136778u: goto label_136778;
        case 0x136798u: goto label_136798;
        case 0x1367a8u: goto label_1367a8;
        case 0x1367f4u: goto label_1367f4;
        case 0x13681cu: goto label_13681c;
        case 0x136834u: goto label_136834;
        case 0x136848u: goto label_136848;
        case 0x13685cu: goto label_13685c;
        case 0x1368b4u: goto label_1368b4;
        case 0x1368dcu: goto label_1368dc;
        case 0x1368f4u: goto label_1368f4;
        case 0x136908u: goto label_136908;
        case 0x13691cu: goto label_13691c;
        case 0x136974u: goto label_136974;
        case 0x13699cu: goto label_13699c;
        case 0x1369b4u: goto label_1369b4;
        case 0x1369c8u: goto label_1369c8;
        case 0x1369dcu: goto label_1369dc;
        case 0x136a10u: goto label_136a10;
        case 0x136a40u: goto label_136a40;
        default: break;
    }

    ctx->pc = 0x135fb8u;

    // 0x135fb8: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x135fb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x135fbc: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x135fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x135fc0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x135fc0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135fc4: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x135fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x135fc8: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x135FC8u;
    {
        const bool branch_taken_0x135fc8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x135FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135FC8u;
            // 0x135fcc: 0xffbf0270  sd          $ra, 0x270($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135fc8) {
            ctx->pc = 0x135FE0u;
            goto label_135fe0;
        }
    }
    ctx->pc = 0x135FD0u;
    // 0x135fd0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135fd4: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x135FD4u;
    {
        const bool branch_taken_0x135fd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135FD4u;
            // 0x135fd8: 0x2484baf0  addiu       $a0, $a0, -0x4510 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949616));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135fd4) {
            ctx->pc = 0x136054u;
            goto label_136054;
        }
    }
    ctx->pc = 0x135FDCu;
    // 0x135fdc: 0x0  nop
    ctx->pc = 0x135fdcu;
    // NOP
label_135fe0:
    // 0x135fe0: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x135fe0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x135fe4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x135fe4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135fe8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x135fe8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135fec: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x135FECu;
    SET_GPR_U32(ctx, 31, 0x135FF4u);
    ctx->pc = 0x135FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135FECu;
            // 0x135ff0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135FF4u; }
        if (ctx->pc != 0x135FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135FF4u; }
        if (ctx->pc != 0x135FF4u) { return; }
    }
    ctx->pc = 0x135FF4u;
label_135ff4:
    // 0x135ff4: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x135ff4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x135ff8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x135FF8u;
    {
        const bool branch_taken_0x135ff8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135FF8u;
            // 0x135ffc: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135ff8) {
            ctx->pc = 0x136010u;
            goto label_136010;
        }
    }
    ctx->pc = 0x136000u;
    // 0x136000: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136000u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136004: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x136004u;
    {
        const bool branch_taken_0x136004 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136004u;
            // 0x136008: 0x2484baf0  addiu       $a0, $a0, -0x4510 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949616));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136004) {
            ctx->pc = 0x136054u;
            goto label_136054;
        }
    }
    ctx->pc = 0x13600Cu;
    // 0x13600c: 0x0  nop
    ctx->pc = 0x13600cu;
    // NOP
label_136010:
    // 0x136010: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136010u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136014: 0xc04d622  jal         func_135888
    ctx->pc = 0x136014u;
    SET_GPR_U32(ctx, 31, 0x13601Cu);
    ctx->pc = 0x136018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136014u;
            // 0x136018: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13601Cu; }
        if (ctx->pc != 0x13601Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13601Cu; }
        if (ctx->pc != 0x13601Cu) { return; }
    }
    ctx->pc = 0x13601Cu;
label_13601c:
    // 0x13601c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13601cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136020: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136020u;
    {
        const bool branch_taken_0x136020 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136020) {
            ctx->pc = 0x136024u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136020u;
            // 0x136024: 0x8e020008  lw          $v0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136038u;
            goto label_136038;
        }
    }
    ctx->pc = 0x136028u;
    // 0x136028: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136028u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13602c: 0xc04d480  jal         func_135200
    ctx->pc = 0x13602Cu;
    SET_GPR_U32(ctx, 31, 0x136034u);
    ctx->pc = 0x136030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13602Cu;
            // 0x136030: 0x2484bb40  addiu       $a0, $a0, -0x44C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949696));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136034u; }
        if (ctx->pc != 0x136034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136034u; }
        if (ctx->pc != 0x136034u) { return; }
    }
    ctx->pc = 0x136034u;
label_136034:
    // 0x136034: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x136034u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_136038:
    // 0x136038: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136038u;
    {
        const bool branch_taken_0x136038 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136038) {
            ctx->pc = 0x13603Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136038u;
            // 0x13603c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136050u;
            goto label_136050;
        }
    }
    ctx->pc = 0x136040u;
    // 0x136040: 0x40f809  jalr        $v0
    ctx->pc = 0x136040u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136048u);
        ctx->pc = 0x136044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136040u;
            // 0x136044: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136048u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136048u; }
            if (ctx->pc != 0x136048u) { return; }
        }
        }
    }
    ctx->pc = 0x136048u;
label_136048:
    // 0x136048: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x136048u;
    {
        const bool branch_taken_0x136048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13604Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136048u;
            // 0x13604c: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136048) {
            ctx->pc = 0x136064u;
            goto label_136064;
        }
    }
    ctx->pc = 0x136050u;
label_136050:
    // 0x136050: 0x2484bb68  addiu       $a0, $a0, -0x4498
    ctx->pc = 0x136050u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949736));
label_136054:
    // 0x136054: 0xc04d480  jal         func_135200
    ctx->pc = 0x136054u;
    SET_GPR_U32(ctx, 31, 0x13605Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13605Cu; }
        if (ctx->pc != 0x13605Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13605Cu; }
        if (ctx->pc != 0x13605Cu) { return; }
    }
    ctx->pc = 0x13605Cu;
label_13605c:
    // 0x13605c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13605cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136060: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x136060u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_136064:
    // 0x136064: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136064u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136068: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x136068u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x13606c: 0x3e00008  jr          $ra
    ctx->pc = 0x13606Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13606Cu;
            // 0x136070: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136074u;
    // 0x136074: 0x0  nop
    ctx->pc = 0x136074u;
    // NOP
    // 0x136078: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136078u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x13607c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13607cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136080: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136080u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136084: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x136084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x136088: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x136088u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13608c: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x13608cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136090: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136090u;
    {
        const bool branch_taken_0x136090 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x136094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136090u;
            // 0x136094: 0xffbf0278  sd          $ra, 0x278($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136090) {
            ctx->pc = 0x1360A8u;
            goto label_1360a8;
        }
    }
    ctx->pc = 0x136098u;
    // 0x136098: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136098u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13609c: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x13609Cu;
    {
        const bool branch_taken_0x13609c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1360A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13609Cu;
            // 0x1360a0: 0x2484bb88  addiu       $a0, $a0, -0x4478 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13609c) {
            ctx->pc = 0x136120u;
            goto label_136120;
        }
    }
    ctx->pc = 0x1360A4u;
    // 0x1360a4: 0x0  nop
    ctx->pc = 0x1360a4u;
    // NOP
label_1360a8:
    // 0x1360a8: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x1360a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x1360ac: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1360acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1360b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360b4: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1360B4u;
    SET_GPR_U32(ctx, 31, 0x1360BCu);
    ctx->pc = 0x1360B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1360B4u;
            // 0x1360b8: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360BCu; }
        if (ctx->pc != 0x1360BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360BCu; }
        if (ctx->pc != 0x1360BCu) { return; }
    }
    ctx->pc = 0x1360BCu;
label_1360bc:
    // 0x1360bc: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x1360bcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1360c0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1360C0u;
    {
        const bool branch_taken_0x1360c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1360C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1360C0u;
            // 0x1360c4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1360c0) {
            ctx->pc = 0x1360D8u;
            goto label_1360d8;
        }
    }
    ctx->pc = 0x1360C8u;
    // 0x1360c8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1360c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1360cc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1360CCu;
    {
        const bool branch_taken_0x1360cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1360D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1360CCu;
            // 0x1360d0: 0x2484bb88  addiu       $a0, $a0, -0x4478 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1360cc) {
            ctx->pc = 0x136120u;
            goto label_136120;
        }
    }
    ctx->pc = 0x1360D4u;
    // 0x1360d4: 0x0  nop
    ctx->pc = 0x1360d4u;
    // NOP
label_1360d8:
    // 0x1360d8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1360d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360dc: 0xc04d622  jal         func_135888
    ctx->pc = 0x1360DCu;
    SET_GPR_U32(ctx, 31, 0x1360E4u);
    ctx->pc = 0x1360E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1360DCu;
            // 0x1360e0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360E4u; }
        if (ctx->pc != 0x1360E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360E4u; }
        if (ctx->pc != 0x1360E4u) { return; }
    }
    ctx->pc = 0x1360E4u;
label_1360e4:
    // 0x1360e4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1360e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1360e8: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1360E8u;
    {
        const bool branch_taken_0x1360e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1360e8) {
            ctx->pc = 0x1360ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1360E8u;
            // 0x1360ec: 0x8e02005c  lw          $v0, 0x5C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 92)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136100u;
            goto label_136100;
        }
    }
    ctx->pc = 0x1360F0u;
    // 0x1360f0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1360f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1360f4: 0xc04d480  jal         func_135200
    ctx->pc = 0x1360F4u;
    SET_GPR_U32(ctx, 31, 0x1360FCu);
    ctx->pc = 0x1360F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1360F4u;
            // 0x1360f8: 0x2484bbe0  addiu       $a0, $a0, -0x4420 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360FCu; }
        if (ctx->pc != 0x1360FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1360FCu; }
        if (ctx->pc != 0x1360FCu) { return; }
    }
    ctx->pc = 0x1360FCu;
label_1360fc:
    // 0x1360fc: 0x8e02005c  lw          $v0, 0x5C($s0)
    ctx->pc = 0x1360fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 92)));
label_136100:
    // 0x136100: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136100u;
    {
        const bool branch_taken_0x136100 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136100u;
            // 0x136104: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136100) {
            ctx->pc = 0x136118u;
            goto label_136118;
        }
    }
    ctx->pc = 0x136108u;
    // 0x136108: 0x40f809  jalr        $v0
    ctx->pc = 0x136108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136110u);
        ctx->pc = 0x13610Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136108u;
            // 0x13610c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136110u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136110u; }
            if (ctx->pc != 0x136110u) { return; }
        }
        }
    }
    ctx->pc = 0x136110u;
label_136110:
    // 0x136110: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x136110u;
    {
        const bool branch_taken_0x136110 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136110u;
            // 0x136114: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136110) {
            ctx->pc = 0x136130u;
            goto label_136130;
        }
    }
    ctx->pc = 0x136118u;
label_136118:
    // 0x136118: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136118u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13611c: 0x2484bc08  addiu       $a0, $a0, -0x43F8
    ctx->pc = 0x13611cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949896));
label_136120:
    // 0x136120: 0xc04d480  jal         func_135200
    ctx->pc = 0x136120u;
    SET_GPR_U32(ctx, 31, 0x136128u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136128u; }
        if (ctx->pc != 0x136128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136128u; }
        if (ctx->pc != 0x136128u) { return; }
    }
    ctx->pc = 0x136128u;
label_136128:
    // 0x136128: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x136128u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13612c: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x13612cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_136130:
    // 0x136130: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136130u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136134: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x136134u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x136138: 0xdfbf0278  ld          $ra, 0x278($sp)
    ctx->pc = 0x136138u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x13613c: 0x3e00008  jr          $ra
    ctx->pc = 0x13613Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13613Cu;
            // 0x136140: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136144u;
    // 0x136144: 0x0  nop
    ctx->pc = 0x136144u;
    // NOP
    // 0x136148: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136148u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13614c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13614Cu;
    {
        const bool branch_taken_0x13614c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13614Cu;
            // 0x136150: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13614c) {
            ctx->pc = 0x136168u;
            goto label_136168;
        }
    }
    ctx->pc = 0x136154u;
    // 0x136154: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136154u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136158: 0xc04d480  jal         func_135200
    ctx->pc = 0x136158u;
    SET_GPR_U32(ctx, 31, 0x136160u);
    ctx->pc = 0x13615Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136158u;
            // 0x13615c: 0x2484bc28  addiu       $a0, $a0, -0x43D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136160u; }
        if (ctx->pc != 0x136160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136160u; }
        if (ctx->pc != 0x136160u) { return; }
    }
    ctx->pc = 0x136160u;
label_136160:
    // 0x136160: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x136160u;
    {
        const bool branch_taken_0x136160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136160u;
            // 0x136164: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136160) {
            ctx->pc = 0x136198u;
            goto label_136198;
        }
    }
    ctx->pc = 0x136168u;
label_136168:
    // 0x136168: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13616c: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x13616cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x136170: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x136170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x136174: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136174u;
    {
        const bool branch_taken_0x136174 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136174u;
            // 0x136178: 0x3463ffff  ori         $v1, $v1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x136174) {
            ctx->pc = 0x136194u;
            goto label_136194;
        }
    }
    ctx->pc = 0x13617Cu;
    // 0x13617c: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x13617cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x136180: 0x2405012c  addiu       $a1, $zero, 0x12C
    ctx->pc = 0x136180u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x136184: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136184u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136188: 0x40f809  jalr        $v0
    ctx->pc = 0x136188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136190u);
        ctx->pc = 0x13618Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136188u;
            // 0x13618c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136190u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136190u; }
            if (ctx->pc != 0x136190u) { return; }
        }
        }
    }
    ctx->pc = 0x136190u;
label_136190:
    // 0x136190: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x136190u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136194:
    // 0x136194: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x136194u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_136198:
    // 0x136198: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136198u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13619c: 0x3e00008  jr          $ra
    ctx->pc = 0x13619Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1361A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13619Cu;
            // 0x1361a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1361A4u;
    // 0x1361a4: 0x0  nop
    ctx->pc = 0x1361a4u;
    // NOP
    // 0x1361a8: 0x27bdfe90  addiu       $sp, $sp, -0x170
    ctx->pc = 0x1361a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966928));
    // 0x1361ac: 0xffb00130  sd          $s0, 0x130($sp)
    ctx->pc = 0x1361acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 16));
    // 0x1361b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1361b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1361b4: 0xffb40150  sd          $s4, 0x150($sp)
    ctx->pc = 0x1361b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 336), GPR_U64(ctx, 20));
    // 0x1361b8: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1361b8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1361bc: 0xffb10138  sd          $s1, 0x138($sp)
    ctx->pc = 0x1361bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 312), GPR_U64(ctx, 17));
    // 0x1361c0: 0xffb20140  sd          $s2, 0x140($sp)
    ctx->pc = 0x1361c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 320), GPR_U64(ctx, 18));
    // 0x1361c4: 0xffb30148  sd          $s3, 0x148($sp)
    ctx->pc = 0x1361c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 328), GPR_U64(ctx, 19));
    // 0x1361c8: 0xffb50158  sd          $s5, 0x158($sp)
    ctx->pc = 0x1361c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 344), GPR_U64(ctx, 21));
    // 0x1361cc: 0xffb60160  sd          $s6, 0x160($sp)
    ctx->pc = 0x1361ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 352), GPR_U64(ctx, 22));
    // 0x1361d0: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1361D0u;
    {
        const bool branch_taken_0x1361d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1361D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1361D0u;
            // 0x1361d4: 0xffbf0168  sd          $ra, 0x168($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 360), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1361d0) {
            ctx->pc = 0x1361E4u;
            goto label_1361e4;
        }
    }
    ctx->pc = 0x1361D8u;
    // 0x1361d8: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1361d8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1361dc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1361DCu;
    {
        const bool branch_taken_0x1361dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1361dc) {
            ctx->pc = 0x136208u;
            goto label_136208;
        }
    }
    ctx->pc = 0x1361E4u;
label_1361e4:
    // 0x1361e4: 0xc04d706  jal         func_135C18
    ctx->pc = 0x1361E4u;
    SET_GPR_U32(ctx, 31, 0x1361ECu);
    ctx->pc = 0x1361E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1361E4u;
            // 0x1361e8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135C18u;
    if (runtime->hasFunction(0x135C18u)) {
        auto targetFn = runtime->lookupFunction(0x135C18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1361ECu; }
        if (ctx->pc != 0x1361ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135C18_0x135c18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1361ECu; }
        if (ctx->pc != 0x1361ECu) { return; }
    }
    ctx->pc = 0x1361ECu;
label_1361ec:
    // 0x1361ec: 0x83a20000  lb          $v0, 0x0($sp)
    ctx->pc = 0x1361ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1361f0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1361F0u;
    {
        const bool branch_taken_0x1361f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1361f0) {
            ctx->pc = 0x136220u;
            goto label_136220;
        }
    }
    ctx->pc = 0x1361F8u;
    // 0x1361f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1361f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1361fc: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1361FCu;
    {
        const bool branch_taken_0x1361fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1361FCu;
            // 0x136200: 0x2484bc58  addiu       $a0, $a0, -0x43A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949976));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1361fc) {
            ctx->pc = 0x1362A0u;
            goto label_1362a0;
        }
    }
    ctx->pc = 0x136204u;
    // 0x136204: 0x0  nop
    ctx->pc = 0x136204u;
    // NOP
label_136208:
    // 0x136208: 0xc042c56  jal         func_10B158
    ctx->pc = 0x136208u;
    SET_GPR_U32(ctx, 31, 0x136210u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136210u; }
        if (ctx->pc != 0x136210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136210u; }
        if (ctx->pc != 0x136210u) { return; }
    }
    ctx->pc = 0x136210u;
label_136210:
    // 0x136210: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x136210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136214: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136214u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136218: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x136218u;
    SET_GPR_U32(ctx, 31, 0x136220u);
    ctx->pc = 0x13621Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136218u;
            // 0x13621c: 0x24460001  addiu       $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136220u; }
        if (ctx->pc != 0x136220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136220u; }
        if (ctx->pc != 0x136220u) { return; }
    }
    ctx->pc = 0x136220u;
label_136220:
    // 0x136220: 0xc042c56  jal         func_10B158
    ctx->pc = 0x136220u;
    SET_GPR_U32(ctx, 31, 0x136228u);
    ctx->pc = 0x136224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136220u;
            // 0x136224: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136228u; }
        if (ctx->pc != 0x136228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136228u; }
        if (ctx->pc != 0x136228u) { return; }
    }
    ctx->pc = 0x136228u;
label_136228:
    // 0x136228: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x136228u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13622c: 0x5e400004  bgtzl       $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13622Cu;
    {
        const bool branch_taken_0x13622c = (GPR_S64(ctx, 18) > 0);
        if (branch_taken_0x13622c) {
            ctx->pc = 0x136230u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13622Cu;
            // 0x136230: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136240u;
            goto label_136240;
        }
    }
    ctx->pc = 0x136234u;
    // 0x136234: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136234u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136238: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x136238u;
    {
        const bool branch_taken_0x136238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13623Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136238u;
            // 0x13623c: 0x2484bc58  addiu       $a0, $a0, -0x43A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949976));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136238) {
            ctx->pc = 0x1362A0u;
            goto label_1362a0;
        }
    }
    ctx->pc = 0x136240u;
label_136240:
    // 0x136240: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x136240u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136244: 0x2453206c  addiu       $s3, $v0, 0x206C
    ctx->pc = 0x136244u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x136248: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x136248u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x13624c: 0x2675fffc  addiu       $s5, $s3, -0x4
    ctx->pc = 0x13624cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
    // 0x136250: 0x118100  sll         $s0, $s1, 4
    ctx->pc = 0x136250u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x136254: 0x0  nop
    ctx->pc = 0x136254u;
    // NOP
label_136258:
    // 0x136258: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x136258u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x13625c: 0x2132821  addu        $a1, $s0, $s3
    ctx->pc = 0x13625cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x136260: 0x2158021  addu        $s0, $s0, $s5
    ctx->pc = 0x136260u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 21)));
    // 0x136264: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136268: 0xc042d10  jal         func_10B440
    ctx->pc = 0x136268u;
    SET_GPR_U32(ctx, 31, 0x136270u);
    ctx->pc = 0x13626Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136268u;
            // 0x13626c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136270u; }
        if (ctx->pc != 0x136270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136270u; }
        if (ctx->pc != 0x136270u) { return; }
    }
    ctx->pc = 0x136270u;
label_136270:
    // 0x136270: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x136270u;
    {
        const bool branch_taken_0x136270 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x136270) {
            ctx->pc = 0x136274u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136270u;
            // 0x136274: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1362B4u;
            goto label_1362b4;
        }
    }
    ctx->pc = 0x136278u;
    // 0x136278: 0x8e100000  lw          $s0, 0x0($s0)
    ctx->pc = 0x136278u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13627c: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13627Cu;
    {
        const bool branch_taken_0x13627c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x136280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13627Cu;
            // 0x136280: 0x26c4bc80  addiu       $a0, $s6, -0x4380 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294950016));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13627c) {
            ctx->pc = 0x1362A0u;
            goto label_1362a0;
        }
    }
    ctx->pc = 0x136284u;
    // 0x136284: 0x8e10000c  lw          $s0, 0xC($s0)
    ctx->pc = 0x136284u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x136288: 0x5200000a  beql        $s0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x136288u;
    {
        const bool branch_taken_0x136288 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x136288) {
            ctx->pc = 0x13628Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136288u;
            // 0x13628c: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1362B4u;
            goto label_1362b4;
        }
    }
    ctx->pc = 0x136290u;
    // 0x136290: 0x200f809  jalr        $s0
    ctx->pc = 0x136290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 16);
        SET_GPR_U32(ctx, 31, 0x136298u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136298u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136298u; }
            if (ctx->pc != 0x136298u) { return; }
        }
        }
    }
    ctx->pc = 0x136298u;
label_136298:
    // 0x136298: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x136298u;
    {
        const bool branch_taken_0x136298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13629Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136298u;
            // 0x13629c: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136298) {
            ctx->pc = 0x1362B0u;
            goto label_1362b0;
        }
    }
    ctx->pc = 0x1362A0u;
label_1362a0:
    // 0x1362a0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1362A0u;
    SET_GPR_U32(ctx, 31, 0x1362A8u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1362A8u; }
        if (ctx->pc != 0x1362A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1362A8u; }
        if (ctx->pc != 0x1362A8u) { return; }
    }
    ctx->pc = 0x1362A8u;
label_1362a8:
    // 0x1362a8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1362A8u;
    {
        const bool branch_taken_0x1362a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1362ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362A8u;
            // 0x1362ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1362a8) {
            ctx->pc = 0x1362C0u;
            goto label_1362c0;
        }
    }
    ctx->pc = 0x1362B0u;
label_1362b0:
    // 0x1362b0: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x1362b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
label_1362b4:
    // 0x1362b4: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1362B4u;
    {
        const bool branch_taken_0x1362b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1362B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362B4u;
            // 0x1362b8: 0x118100  sll         $s0, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1362b4) {
            ctx->pc = 0x136258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_136258;
        }
    }
    ctx->pc = 0x1362BCu;
    // 0x1362bc: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x1362bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1362c0:
    // 0x1362c0: 0xdfb00130  ld          $s0, 0x130($sp)
    ctx->pc = 0x1362c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1362c4: 0xdfb10138  ld          $s1, 0x138($sp)
    ctx->pc = 0x1362c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 312)));
    // 0x1362c8: 0xdfb20140  ld          $s2, 0x140($sp)
    ctx->pc = 0x1362c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x1362cc: 0xdfb30148  ld          $s3, 0x148($sp)
    ctx->pc = 0x1362ccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 328)));
    // 0x1362d0: 0xdfb40150  ld          $s4, 0x150($sp)
    ctx->pc = 0x1362d0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 336)));
    // 0x1362d4: 0xdfb50158  ld          $s5, 0x158($sp)
    ctx->pc = 0x1362d4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 344)));
    // 0x1362d8: 0xdfb60160  ld          $s6, 0x160($sp)
    ctx->pc = 0x1362d8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 352)));
    // 0x1362dc: 0xdfbf0168  ld          $ra, 0x168($sp)
    ctx->pc = 0x1362dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 360)));
    // 0x1362e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1362E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1362E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362E0u;
            // 0x1362e4: 0x27bd0170  addiu       $sp, $sp, 0x170 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 368));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1362E8u;
    // 0x1362e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1362e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1362ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1362ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1362f0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1362f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1362f4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1362F4u;
    {
        const bool branch_taken_0x1362f4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1362F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362F4u;
            // 0x1362f8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1362f4) {
            ctx->pc = 0x136310u;
            goto label_136310;
        }
    }
    ctx->pc = 0x1362FCu;
    // 0x1362fc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1362fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136300: 0xc04d480  jal         func_135200
    ctx->pc = 0x136300u;
    SET_GPR_U32(ctx, 31, 0x136308u);
    ctx->pc = 0x136304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136300u;
            // 0x136304: 0x2484bca0  addiu       $a0, $a0, -0x4360 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136308u; }
        if (ctx->pc != 0x136308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136308u; }
        if (ctx->pc != 0x136308u) { return; }
    }
    ctx->pc = 0x136308u;
label_136308:
    // 0x136308: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136308u;
    {
        const bool branch_taken_0x136308 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13630Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136308u;
            // 0x13630c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136308) {
            ctx->pc = 0x13633Cu;
            goto label_13633c;
        }
    }
    ctx->pc = 0x136310u;
label_136310:
    // 0x136310: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136310u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136314: 0x8c420030  lw          $v0, 0x30($v0)
    ctx->pc = 0x136314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x136318: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136318u;
    {
        const bool branch_taken_0x136318 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136318) {
            ctx->pc = 0x13631Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136318u;
            // 0x13631c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136330u;
            goto label_136330;
        }
    }
    ctx->pc = 0x136320u;
    // 0x136320: 0x40f809  jalr        $v0
    ctx->pc = 0x136320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136328u);
        ctx->pc = 0x136324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136320u;
            // 0x136324: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136328u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136328u; }
            if (ctx->pc != 0x136328u) { return; }
        }
        }
    }
    ctx->pc = 0x136328u;
label_136328:
    // 0x136328: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x136328u;
    {
        const bool branch_taken_0x136328 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13632Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136328u;
            // 0x13632c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136328) {
            ctx->pc = 0x136338u;
            goto label_136338;
        }
    }
    ctx->pc = 0x136330u;
label_136330:
    // 0x136330: 0xc04d480  jal         func_135200
    ctx->pc = 0x136330u;
    SET_GPR_U32(ctx, 31, 0x136338u);
    ctx->pc = 0x136334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136330u;
            // 0x136334: 0x2484bcc0  addiu       $a0, $a0, -0x4340 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136338u; }
        if (ctx->pc != 0x136338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136338u; }
        if (ctx->pc != 0x136338u) { return; }
    }
    ctx->pc = 0x136338u;
label_136338:
    // 0x136338: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x136338u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_13633c:
    // 0x13633c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13633cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136340: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136340u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136344: 0x3e00008  jr          $ra
    ctx->pc = 0x136344u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136344u;
            // 0x136348: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13634Cu;
    // 0x13634c: 0x0  nop
    ctx->pc = 0x13634cu;
    // NOP
    // 0x136350: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136354: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136354u;
    {
        const bool branch_taken_0x136354 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136354u;
            // 0x136358: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136354) {
            ctx->pc = 0x136370u;
            goto label_136370;
        }
    }
    ctx->pc = 0x13635Cu;
    // 0x13635c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13635cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136360: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136360u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136364: 0x2484bce0  addiu       $a0, $a0, -0x4320
    ctx->pc = 0x136364u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950112));
    // 0x136368: 0x804d480  j           func_135200
    ctx->pc = 0x136368u;
    ctx->pc = 0x13636Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136368u;
            // 0x13636c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x136370u;
label_136370:
    // 0x136370: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136374: 0x8c420034  lw          $v0, 0x34($v0)
    ctx->pc = 0x136374u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x136378: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x136378u;
    {
        const bool branch_taken_0x136378 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136378) {
            ctx->pc = 0x13637Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136378u;
            // 0x13637c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136398u;
            goto label_136398;
        }
    }
    ctx->pc = 0x136380u;
    // 0x136380: 0x40f809  jalr        $v0
    ctx->pc = 0x136380u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136388u);
        ctx->pc = 0x136384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136380u;
            // 0x136384: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136388u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136388u; }
            if (ctx->pc != 0x136388u) { return; }
        }
        }
    }
    ctx->pc = 0x136388u;
label_136388:
    // 0x136388: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13638c: 0x3e00008  jr          $ra
    ctx->pc = 0x13638Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13638Cu;
            // 0x136390: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136394u;
    // 0x136394: 0x0  nop
    ctx->pc = 0x136394u;
    // NOP
label_136398:
    // 0x136398: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136398u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13639c: 0x2484bd00  addiu       $a0, $a0, -0x4300
    ctx->pc = 0x13639cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950144));
    // 0x1363a0: 0x804d480  j           func_135200
    ctx->pc = 0x1363A0u;
    ctx->pc = 0x1363A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1363A0u;
            // 0x1363a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1363A8u;
    // 0x1363a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1363a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1363ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1363acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1363b0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1363b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1363b4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1363B4u;
    {
        const bool branch_taken_0x1363b4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1363B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363B4u;
            // 0x1363b8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1363b4) {
            ctx->pc = 0x1363D0u;
            goto label_1363d0;
        }
    }
    ctx->pc = 0x1363BCu;
    // 0x1363bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1363bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1363c0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1363C0u;
    SET_GPR_U32(ctx, 31, 0x1363C8u);
    ctx->pc = 0x1363C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1363C0u;
            // 0x1363c4: 0x2484bd20  addiu       $a0, $a0, -0x42E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363C8u; }
        if (ctx->pc != 0x1363C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363C8u; }
        if (ctx->pc != 0x1363C8u) { return; }
    }
    ctx->pc = 0x1363C8u;
label_1363c8:
    // 0x1363c8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1363C8u;
    {
        const bool branch_taken_0x1363c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1363CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363C8u;
            // 0x1363cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1363c8) {
            ctx->pc = 0x1363FCu;
            goto label_1363fc;
        }
    }
    ctx->pc = 0x1363D0u;
label_1363d0:
    // 0x1363d0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1363d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1363d4: 0x8c420038  lw          $v0, 0x38($v0)
    ctx->pc = 0x1363d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1363d8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1363D8u;
    {
        const bool branch_taken_0x1363d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1363d8) {
            ctx->pc = 0x1363DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1363D8u;
            // 0x1363dc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1363F0u;
            goto label_1363f0;
        }
    }
    ctx->pc = 0x1363E0u;
    // 0x1363e0: 0x40f809  jalr        $v0
    ctx->pc = 0x1363E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1363E8u);
        ctx->pc = 0x1363E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363E0u;
            // 0x1363e4: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1363E8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1363E8u; }
            if (ctx->pc != 0x1363E8u) { return; }
        }
        }
    }
    ctx->pc = 0x1363E8u;
label_1363e8:
    // 0x1363e8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1363E8u;
    {
        const bool branch_taken_0x1363e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1363ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1363E8u;
            // 0x1363ec: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1363e8) {
            ctx->pc = 0x1363F8u;
            goto label_1363f8;
        }
    }
    ctx->pc = 0x1363F0u;
label_1363f0:
    // 0x1363f0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1363F0u;
    SET_GPR_U32(ctx, 31, 0x1363F8u);
    ctx->pc = 0x1363F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1363F0u;
            // 0x1363f4: 0x2484bd40  addiu       $a0, $a0, -0x42C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363F8u; }
        if (ctx->pc != 0x1363F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1363F8u; }
        if (ctx->pc != 0x1363F8u) { return; }
    }
    ctx->pc = 0x1363F8u;
label_1363f8:
    // 0x1363f8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1363f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1363fc:
    // 0x1363fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1363fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136400: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136400u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136404: 0x3e00008  jr          $ra
    ctx->pc = 0x136404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136404u;
            // 0x136408: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13640Cu;
    // 0x13640c: 0x0  nop
    ctx->pc = 0x13640cu;
    // NOP
    // 0x136410: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x136414: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x136414u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136418: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136418u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13641c: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x13641cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136420: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136420u;
    {
        const bool branch_taken_0x136420 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x136424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136420u;
            // 0x136424: 0xffbf0270  sd          $ra, 0x270($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136420) {
            ctx->pc = 0x136438u;
            goto label_136438;
        }
    }
    ctx->pc = 0x136428u;
    // 0x136428: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136428u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13642c: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x13642Cu;
    {
        const bool branch_taken_0x13642c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13642Cu;
            // 0x136430: 0x2484bd60  addiu       $a0, $a0, -0x42A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950240));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13642c) {
            ctx->pc = 0x1364ACu;
            goto label_1364ac;
        }
    }
    ctx->pc = 0x136434u;
    // 0x136434: 0x0  nop
    ctx->pc = 0x136434u;
    // NOP
label_136438:
    // 0x136438: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x136438u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x13643c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13643cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136440: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x136440u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136444: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x136444u;
    SET_GPR_U32(ctx, 31, 0x13644Cu);
    ctx->pc = 0x136448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136444u;
            // 0x136448: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13644Cu; }
        if (ctx->pc != 0x13644Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13644Cu; }
        if (ctx->pc != 0x13644Cu) { return; }
    }
    ctx->pc = 0x13644Cu;
label_13644c:
    // 0x13644c: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x13644cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x136450: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136450u;
    {
        const bool branch_taken_0x136450 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x136454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136450u;
            // 0x136454: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136450) {
            ctx->pc = 0x136468u;
            goto label_136468;
        }
    }
    ctx->pc = 0x136458u;
    // 0x136458: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136458u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13645c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x13645Cu;
    {
        const bool branch_taken_0x13645c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13645Cu;
            // 0x136460: 0x2484bd60  addiu       $a0, $a0, -0x42A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950240));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13645c) {
            ctx->pc = 0x1364ACu;
            goto label_1364ac;
        }
    }
    ctx->pc = 0x136464u;
    // 0x136464: 0x0  nop
    ctx->pc = 0x136464u;
    // NOP
label_136468:
    // 0x136468: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13646c: 0xc04d622  jal         func_135888
    ctx->pc = 0x13646Cu;
    SET_GPR_U32(ctx, 31, 0x136474u);
    ctx->pc = 0x136470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13646Cu;
            // 0x136470: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136474u; }
        if (ctx->pc != 0x136474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136474u; }
        if (ctx->pc != 0x136474u) { return; }
    }
    ctx->pc = 0x136474u;
label_136474:
    // 0x136474: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x136474u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136478: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136478u;
    {
        const bool branch_taken_0x136478 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136478) {
            ctx->pc = 0x13647Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136478u;
            // 0x13647c: 0x8e02003c  lw          $v0, 0x3C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136490u;
            goto label_136490;
        }
    }
    ctx->pc = 0x136480u;
    // 0x136480: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136480u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136484: 0xc04d480  jal         func_135200
    ctx->pc = 0x136484u;
    SET_GPR_U32(ctx, 31, 0x13648Cu);
    ctx->pc = 0x136488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136484u;
            // 0x136488: 0x2484bdb0  addiu       $a0, $a0, -0x4250 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13648Cu; }
        if (ctx->pc != 0x13648Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13648Cu; }
        if (ctx->pc != 0x13648Cu) { return; }
    }
    ctx->pc = 0x13648Cu;
label_13648c:
    // 0x13648c: 0x8e02003c  lw          $v0, 0x3C($s0)
    ctx->pc = 0x13648cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
label_136490:
    // 0x136490: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136490u;
    {
        const bool branch_taken_0x136490 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136490) {
            ctx->pc = 0x136494u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136490u;
            // 0x136494: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1364A8u;
            goto label_1364a8;
        }
    }
    ctx->pc = 0x136498u;
    // 0x136498: 0x40f809  jalr        $v0
    ctx->pc = 0x136498u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1364A0u);
        ctx->pc = 0x13649Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136498u;
            // 0x13649c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1364A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1364A0u; }
            if (ctx->pc != 0x1364A0u) { return; }
        }
        }
    }
    ctx->pc = 0x1364A0u;
label_1364a0:
    // 0x1364a0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1364A0u;
    {
        const bool branch_taken_0x1364a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1364A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1364A0u;
            // 0x1364a4: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1364a0) {
            ctx->pc = 0x1364BCu;
            goto label_1364bc;
        }
    }
    ctx->pc = 0x1364A8u;
label_1364a8:
    // 0x1364a8: 0x2484bdd8  addiu       $a0, $a0, -0x4228
    ctx->pc = 0x1364a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950360));
label_1364ac:
    // 0x1364ac: 0xc04d480  jal         func_135200
    ctx->pc = 0x1364ACu;
    SET_GPR_U32(ctx, 31, 0x1364B4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364B4u; }
        if (ctx->pc != 0x1364B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364B4u; }
        if (ctx->pc != 0x1364B4u) { return; }
    }
    ctx->pc = 0x1364B4u;
label_1364b4:
    // 0x1364b4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1364b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1364b8: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x1364b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_1364bc:
    // 0x1364bc: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x1364bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x1364c0: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x1364c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x1364c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1364C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1364C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1364C4u;
            // 0x1364c8: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1364CCu;
    // 0x1364cc: 0x0  nop
    ctx->pc = 0x1364ccu;
    // NOP
    // 0x1364d0: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x1364d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x1364d4: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x1364d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x1364d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1364d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1364dc: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x1364dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x1364e0: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x1364e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x1364e4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1364e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1364e8: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1364e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1364ec: 0xffbf0270  sd          $ra, 0x270($sp)
    ctx->pc = 0x1364ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
    // 0x1364f0: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1364F0u;
    SET_GPR_U32(ctx, 31, 0x1364F8u);
    ctx->pc = 0x1364F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1364F0u;
            // 0x1364f4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364F8u; }
        if (ctx->pc != 0x1364F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1364F8u; }
        if (ctx->pc != 0x1364F8u) { return; }
    }
    ctx->pc = 0x1364F8u;
label_1364f8:
    // 0x1364f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1364f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1364fc: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x1364fcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x136500: 0x2484bdf8  addiu       $a0, $a0, -0x4208
    ctx->pc = 0x136500u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950392));
    // 0x136504: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x136504u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136508: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x136508u;
    {
        const bool branch_taken_0x136508 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13650Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136508u;
            // 0x13650c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136508) {
            ctx->pc = 0x136554u;
            goto label_136554;
        }
    }
    ctx->pc = 0x136510u;
    // 0x136510: 0xc04d622  jal         func_135888
    ctx->pc = 0x136510u;
    SET_GPR_U32(ctx, 31, 0x136518u);
    ctx->pc = 0x136514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136510u;
            // 0x136514: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136518u; }
        if (ctx->pc != 0x136518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136518u; }
        if (ctx->pc != 0x136518u) { return; }
    }
    ctx->pc = 0x136518u;
label_136518:
    // 0x136518: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136518u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13651c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13651cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136520: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x136520u;
    {
        const bool branch_taken_0x136520 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x136524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136520u;
            // 0x136524: 0x2484be48  addiu       $a0, $a0, -0x41B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950472));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136520) {
            ctx->pc = 0x136530u;
            goto label_136530;
        }
    }
    ctx->pc = 0x136528u;
    // 0x136528: 0xc04d480  jal         func_135200
    ctx->pc = 0x136528u;
    SET_GPR_U32(ctx, 31, 0x136530u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136530u; }
        if (ctx->pc != 0x136530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136530u; }
        if (ctx->pc != 0x136530u) { return; }
    }
    ctx->pc = 0x136530u;
label_136530:
    // 0x136530: 0x8e020040  lw          $v0, 0x40($s0)
    ctx->pc = 0x136530u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x136534: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x136534u;
    {
        const bool branch_taken_0x136534 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136534) {
            ctx->pc = 0x136538u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136534u;
            // 0x136538: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136550u;
            goto label_136550;
        }
    }
    ctx->pc = 0x13653Cu;
    // 0x13653c: 0x40f809  jalr        $v0
    ctx->pc = 0x13653Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136544u);
        ctx->pc = 0x136540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13653Cu;
            // 0x136540: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136544u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136544u; }
            if (ctx->pc != 0x136544u) { return; }
        }
        }
    }
    ctx->pc = 0x136544u;
label_136544:
    // 0x136544: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x136544u;
    {
        const bool branch_taken_0x136544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136544u;
            // 0x136548: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136544) {
            ctx->pc = 0x136564u;
            goto label_136564;
        }
    }
    ctx->pc = 0x13654Cu;
    // 0x13654c: 0x0  nop
    ctx->pc = 0x13654cu;
    // NOP
label_136550:
    // 0x136550: 0x2484be70  addiu       $a0, $a0, -0x4190
    ctx->pc = 0x136550u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950512));
label_136554:
    // 0x136554: 0xc04d480  jal         func_135200
    ctx->pc = 0x136554u;
    SET_GPR_U32(ctx, 31, 0x13655Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13655Cu; }
        if (ctx->pc != 0x13655Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13655Cu; }
        if (ctx->pc != 0x13655Cu) { return; }
    }
    ctx->pc = 0x13655Cu;
label_13655c:
    // 0x13655c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13655cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136560: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x136560u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_136564:
    // 0x136564: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136564u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136568: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x136568u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x13656c: 0x3e00008  jr          $ra
    ctx->pc = 0x13656Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13656Cu;
            // 0x136570: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136574u;
    // 0x136574: 0x0  nop
    ctx->pc = 0x136574u;
    // NOP
    // 0x136578: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x136578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x13657c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x13657cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136580: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x136580u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136584: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x136584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x136588: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x136588u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13658c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x13658cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x136590: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x136590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x136594: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x136594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x136598: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x136598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x13659c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x13659cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1365a0: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x1365a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x1365a4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1365A4u;
    SET_GPR_U32(ctx, 31, 0x1365ACu);
    ctx->pc = 0x1365A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1365A4u;
            // 0x1365a8: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365ACu; }
        if (ctx->pc != 0x1365ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365ACu; }
        if (ctx->pc != 0x1365ACu) { return; }
    }
    ctx->pc = 0x1365ACu;
label_1365ac:
    // 0x1365ac: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x1365acu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1365b0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1365b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1365b4: 0x2453206c  addiu       $s3, $v0, 0x206C
    ctx->pc = 0x1365b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x1365b8: 0x2676fffc  addiu       $s6, $s3, -0x4
    ctx->pc = 0x1365b8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
    // 0x1365bc: 0x118100  sll         $s0, $s1, 4
    ctx->pc = 0x1365bcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_1365c0:
    // 0x1365c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1365c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1365c4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1365c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1365c8: 0x2132821  addu        $a1, $s0, $s3
    ctx->pc = 0x1365c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x1365cc: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x1365ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1365d0: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1365D0u;
    SET_GPR_U32(ctx, 31, 0x1365D8u);
    ctx->pc = 0x1365D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1365D0u;
            // 0x1365d4: 0x2168021  addu        $s0, $s0, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365D8u; }
        if (ctx->pc != 0x1365D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365D8u; }
        if (ctx->pc != 0x1365D8u) { return; }
    }
    ctx->pc = 0x1365D8u;
label_1365d8:
    // 0x1365d8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1365D8u;
    {
        const bool branch_taken_0x1365d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1365DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1365D8u;
            // 0x1365dc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1365d8) {
            ctx->pc = 0x136650u;
            goto label_136650;
        }
    }
    ctx->pc = 0x1365E0u;
    // 0x1365e0: 0xc04dbe6  jal         func_136F98
    ctx->pc = 0x1365E0u;
    SET_GPR_U32(ctx, 31, 0x1365E8u);
    ctx->pc = 0x1365E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1365E0u;
            // 0x1365e4: 0x8e100000  lw          $s0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x136F98u;
    if (runtime->hasFunction(0x136F98u)) {
        auto targetFn = runtime->lookupFunction(0x136F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365E8u; }
        if (ctx->pc != 0x1365E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00136F98_0x136f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365E8u; }
        if (ctx->pc != 0x1365E8u) { return; }
    }
    ctx->pc = 0x1365E8u;
label_1365e8:
    // 0x1365e8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1365E8u;
    {
        const bool branch_taken_0x1365e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1365e8) {
            ctx->pc = 0x136628u;
            goto label_136628;
        }
    }
    ctx->pc = 0x1365F0u;
    // 0x1365f0: 0x12000018  beqz        $s0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1365F0u;
    {
        const bool branch_taken_0x1365f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1365F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1365F0u;
            // 0x1365f4: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1365f0) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x1365F8u;
    // 0x1365f8: 0x8e020060  lw          $v0, 0x60($s0)
    ctx->pc = 0x1365f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1365fc: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1365FCu;
    {
        const bool branch_taken_0x1365fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1365FCu;
            // 0x136600: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1365fc) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x136604u;
    // 0x136604: 0xafb20004  sw          $s2, 0x4($sp)
    ctx->pc = 0x136604u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 18));
    // 0x136608: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13660c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x13660cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x136610: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136610u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136614: 0x8e020060  lw          $v0, 0x60($s0)
    ctx->pc = 0x136614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x136618: 0x40f809  jalr        $v0
    ctx->pc = 0x136618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136620u);
        ctx->pc = 0x13661Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136618u;
            // 0x13661c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136620u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136620u; }
            if (ctx->pc != 0x136620u) { return; }
        }
        }
    }
    ctx->pc = 0x136620u;
label_136620:
    // 0x136620: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x136620u;
    {
        const bool branch_taken_0x136620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136620u;
            // 0x136624: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136620) {
            ctx->pc = 0x13665Cu;
            goto label_13665c;
        }
    }
    ctx->pc = 0x136628u;
label_136628:
    // 0x136628: 0x1200000a  beqz        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x136628u;
    {
        const bool branch_taken_0x136628 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13662Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136628u;
            // 0x13662c: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x136628) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x136630u;
    // 0x136630: 0x8e100044  lw          $s0, 0x44($s0)
    ctx->pc = 0x136630u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x136634: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136634u;
    {
        const bool branch_taken_0x136634 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x136634) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x13663Cu;
    // 0x13663c: 0x200f809  jalr        $s0
    ctx->pc = 0x13663Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 16);
        SET_GPR_U32(ctx, 31, 0x136644u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136644u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136644u; }
            if (ctx->pc != 0x136644u) { return; }
        }
        }
    }
    ctx->pc = 0x136644u;
label_136644:
    // 0x136644: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x136644u;
    {
        const bool branch_taken_0x136644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136644u;
            // 0x136648: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136644) {
            ctx->pc = 0x13665Cu;
            goto label_13665c;
        }
    }
    ctx->pc = 0x13664Cu;
    // 0x13664c: 0x0  nop
    ctx->pc = 0x13664cu;
    // NOP
label_136650:
    // 0x136650: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x136650u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
label_136654:
    // 0x136654: 0x1440ffda  bnez        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x136654u;
    {
        const bool branch_taken_0x136654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x136658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136654u;
            // 0x136658: 0x118100  sll         $s0, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136654) {
            ctx->pc = 0x1365C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1365c0;
        }
    }
    ctx->pc = 0x13665Cu;
label_13665c:
    // 0x13665c: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x13665cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136660: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136660u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136664: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136664u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136668: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x136668u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13666c: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x13666cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x136670: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x136670u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x136674: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x136674u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x136678: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x136678u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13667c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x13667cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x136680: 0x3e00008  jr          $ra
    ctx->pc = 0x136680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136680u;
            // 0x136684: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136688u;
    // 0x136688: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x136688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x13668c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13668cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136690: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136694: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x136694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136698: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x136698u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x13669c: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x13669cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x1366a0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1366a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366a4: 0xffb30278  sd          $s3, 0x278($sp)
    ctx->pc = 0x1366a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 19));
    // 0x1366a8: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1366a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366ac: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1366acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1366b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366b4: 0xffb40280  sd          $s4, 0x280($sp)
    ctx->pc = 0x1366b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 20));
    // 0x1366b8: 0xffbf0288  sd          $ra, 0x288($sp)
    ctx->pc = 0x1366b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 648), GPR_U64(ctx, 31));
    // 0x1366bc: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1366BCu;
    SET_GPR_U32(ctx, 31, 0x1366C4u);
    ctx->pc = 0x1366C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1366BCu;
            // 0x1366c0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366C4u; }
        if (ctx->pc != 0x1366C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366C4u; }
        if (ctx->pc != 0x1366C4u) { return; }
    }
    ctx->pc = 0x1366C4u;
label_1366c4:
    // 0x1366c4: 0x83a20000  lb          $v0, 0x0($sp)
    ctx->pc = 0x1366c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1366c8: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1366c8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366cc: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1366CCu;
    {
        const bool branch_taken_0x1366cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1366D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1366CCu;
            // 0x1366d0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1366cc) {
            ctx->pc = 0x136700u;
            goto label_136700;
        }
    }
    ctx->pc = 0x1366D4u;
    // 0x1366d4: 0xc04d706  jal         func_135C18
    ctx->pc = 0x1366D4u;
    SET_GPR_U32(ctx, 31, 0x1366DCu);
    ctx->pc = 0x135C18u;
    if (runtime->hasFunction(0x135C18u)) {
        auto targetFn = runtime->lookupFunction(0x135C18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366DCu; }
        if (ctx->pc != 0x1366DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135C18_0x135c18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366DCu; }
        if (ctx->pc != 0x1366DCu) { return; }
    }
    ctx->pc = 0x1366DCu;
label_1366dc:
    // 0x1366dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1366dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1366e0: 0x83a20000  lb          $v0, 0x0($sp)
    ctx->pc = 0x1366e0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1366e4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1366E4u;
    {
        const bool branch_taken_0x1366e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1366E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1366E4u;
            // 0x1366e8: 0x2484be20  addiu       $a0, $a0, -0x41E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950432));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1366e4) {
            ctx->pc = 0x136700u;
            goto label_136700;
        }
    }
    ctx->pc = 0x1366ECu;
    // 0x1366ec: 0xc04d480  jal         func_135200
    ctx->pc = 0x1366ECu;
    SET_GPR_U32(ctx, 31, 0x1366F4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366F4u; }
        if (ctx->pc != 0x1366F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366F4u; }
        if (ctx->pc != 0x1366F4u) { return; }
    }
    ctx->pc = 0x1366F4u;
label_1366f4:
    // 0x1366f4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1366F4u;
    {
        const bool branch_taken_0x1366f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1366F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1366F4u;
            // 0x1366f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1366f4) {
            ctx->pc = 0x13673Cu;
            goto label_13673c;
        }
    }
    ctx->pc = 0x1366FCu;
    // 0x1366fc: 0x0  nop
    ctx->pc = 0x1366fcu;
    // NOP
label_136700:
    // 0x136700: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136700u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136704: 0xc04dbfa  jal         func_136FE8
    ctx->pc = 0x136704u;
    SET_GPR_U32(ctx, 31, 0x13670Cu);
    ctx->pc = 0x136708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136704u;
            // 0x136708: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x136FE8u;
    if (runtime->hasFunction(0x136FE8u)) {
        auto targetFn = runtime->lookupFunction(0x136FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13670Cu; }
        if (ctx->pc != 0x13670Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00136FE8_0x136fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13670Cu; }
        if (ctx->pc != 0x13670Cu) { return; }
    }
    ctx->pc = 0x13670Cu;
label_13670c:
    // 0x13670c: 0xc04d558  jal         func_135560
    ctx->pc = 0x13670Cu;
    SET_GPR_U32(ctx, 31, 0x136714u);
    ctx->pc = 0x136710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13670Cu;
            // 0x136710: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136714u; }
        if (ctx->pc != 0x136714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136714u; }
        if (ctx->pc != 0x136714u) { return; }
    }
    ctx->pc = 0x136714u;
label_136714:
    // 0x136714: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x136714u;
    {
        const bool branch_taken_0x136714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136714) {
            ctx->pc = 0x136718u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136714u;
            // 0x136718: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13673Cu;
            goto label_13673c;
        }
    }
    ctx->pc = 0x13671Cu;
    // 0x13671c: 0x8c420048  lw          $v0, 0x48($v0)
    ctx->pc = 0x13671cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x136720: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136720u;
    {
        const bool branch_taken_0x136720 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136720u;
            // 0x136724: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136720) {
            ctx->pc = 0x136738u;
            goto label_136738;
        }
    }
    ctx->pc = 0x136728u;
    // 0x136728: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x136728u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13672c: 0x40f809  jalr        $v0
    ctx->pc = 0x13672Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136734u);
        ctx->pc = 0x136730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13672Cu;
            // 0x136730: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136734u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136734u; }
            if (ctx->pc != 0x136734u) { return; }
        }
        }
    }
    ctx->pc = 0x136734u;
label_136734:
    // 0x136734: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x136734u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136738:
    // 0x136738: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x136738u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_13673c:
    // 0x13673c: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x13673cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x136740: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136740u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136744: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x136744u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x136748: 0xdfb30278  ld          $s3, 0x278($sp)
    ctx->pc = 0x136748u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x13674c: 0xdfb40280  ld          $s4, 0x280($sp)
    ctx->pc = 0x13674cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x136750: 0xdfbf0288  ld          $ra, 0x288($sp)
    ctx->pc = 0x136750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 648)));
    // 0x136754: 0x3e00008  jr          $ra
    ctx->pc = 0x136754u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136754u;
            // 0x136758: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13675Cu;
    // 0x13675c: 0x0  nop
    ctx->pc = 0x13675cu;
    // NOP
    // 0x136760: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136764: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136764u;
    {
        const bool branch_taken_0x136764 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136764u;
            // 0x136768: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136764) {
            ctx->pc = 0x136780u;
            goto label_136780;
        }
    }
    ctx->pc = 0x13676Cu;
    // 0x13676c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13676cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136770: 0xc04d480  jal         func_135200
    ctx->pc = 0x136770u;
    SET_GPR_U32(ctx, 31, 0x136778u);
    ctx->pc = 0x136774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136770u;
            // 0x136774: 0x2484be90  addiu       $a0, $a0, -0x4170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950544));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136778u; }
        if (ctx->pc != 0x136778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136778u; }
        if (ctx->pc != 0x136778u) { return; }
    }
    ctx->pc = 0x136778u;
label_136778:
    // 0x136778: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136778u;
    {
        const bool branch_taken_0x136778 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13677Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136778u;
            // 0x13677c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136778) {
            ctx->pc = 0x1367ACu;
            goto label_1367ac;
        }
    }
    ctx->pc = 0x136780u;
label_136780:
    // 0x136780: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136784: 0x8c42004c  lw          $v0, 0x4C($v0)
    ctx->pc = 0x136784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 76)));
    // 0x136788: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136788u;
    {
        const bool branch_taken_0x136788 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136788) {
            ctx->pc = 0x13678Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136788u;
            // 0x13678c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1367A0u;
            goto label_1367a0;
        }
    }
    ctx->pc = 0x136790u;
    // 0x136790: 0x40f809  jalr        $v0
    ctx->pc = 0x136790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136798u);
        ctx->pc = 0x136794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136790u;
            // 0x136794: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136798u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136798u; }
            if (ctx->pc != 0x136798u) { return; }
        }
        }
    }
    ctx->pc = 0x136798u;
label_136798:
    // 0x136798: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x136798u;
    {
        const bool branch_taken_0x136798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13679Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136798u;
            // 0x13679c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136798) {
            ctx->pc = 0x1367B0u;
            goto label_1367b0;
        }
    }
    ctx->pc = 0x1367A0u;
label_1367a0:
    // 0x1367a0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1367A0u;
    SET_GPR_U32(ctx, 31, 0x1367A8u);
    ctx->pc = 0x1367A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1367A0u;
            // 0x1367a4: 0x2484beb8  addiu       $a0, $a0, -0x4148 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367A8u; }
        if (ctx->pc != 0x1367A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367A8u; }
        if (ctx->pc != 0x1367A8u) { return; }
    }
    ctx->pc = 0x1367A8u;
label_1367a8:
    // 0x1367a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1367a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1367ac:
    // 0x1367ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1367acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1367b0:
    // 0x1367b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1367B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1367B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367B0u;
            // 0x1367b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1367B8u;
    // 0x1367b8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1367b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1367bc: 0xffb00060  sd          $s0, 0x60($sp)
    ctx->pc = 0x1367bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 16));
    // 0x1367c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1367c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1367c4: 0xffb10068  sd          $s1, 0x68($sp)
    ctx->pc = 0x1367c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 17));
    // 0x1367c8: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1367C8u;
    {
        const bool branch_taken_0x1367c8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1367CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367C8u;
            // 0x1367cc: 0xffbf0070  sd          $ra, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1367c8) {
            ctx->pc = 0x1367E0u;
            goto label_1367e0;
        }
    }
    ctx->pc = 0x1367D0u;
    // 0x1367d0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1367d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1367d4: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1367D4u;
    {
        const bool branch_taken_0x1367d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1367D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367D4u;
            // 0x1367d8: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1367d4) {
            ctx->pc = 0x136854u;
            goto label_136854;
        }
    }
    ctx->pc = 0x1367DCu;
    // 0x1367dc: 0x0  nop
    ctx->pc = 0x1367dcu;
    // NOP
label_1367e0:
    // 0x1367e0: 0x27b10030  addiu       $s1, $sp, 0x30
    ctx->pc = 0x1367e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1367e4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1367e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1367e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1367e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1367ec: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1367ECu;
    SET_GPR_U32(ctx, 31, 0x1367F4u);
    ctx->pc = 0x1367F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1367ECu;
            // 0x1367f0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367F4u; }
        if (ctx->pc != 0x1367F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367F4u; }
        if (ctx->pc != 0x1367F4u) { return; }
    }
    ctx->pc = 0x1367F4u;
label_1367f4:
    // 0x1367f4: 0x83a20030  lb          $v0, 0x30($sp)
    ctx->pc = 0x1367f4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1367f8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1367F8u;
    {
        const bool branch_taken_0x1367f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1367FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367F8u;
            // 0x1367fc: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1367f8) {
            ctx->pc = 0x136810u;
            goto label_136810;
        }
    }
    ctx->pc = 0x136800u;
    // 0x136800: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136800u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136804: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x136804u;
    {
        const bool branch_taken_0x136804 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136804u;
            // 0x136808: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136804) {
            ctx->pc = 0x136854u;
            goto label_136854;
        }
    }
    ctx->pc = 0x13680Cu;
    // 0x13680c: 0x0  nop
    ctx->pc = 0x13680cu;
    // NOP
label_136810:
    // 0x136810: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136810u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136814: 0xc04d622  jal         func_135888
    ctx->pc = 0x136814u;
    SET_GPR_U32(ctx, 31, 0x13681Cu);
    ctx->pc = 0x136818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136814u;
            // 0x136818: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13681Cu; }
        if (ctx->pc != 0x13681Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13681Cu; }
        if (ctx->pc != 0x13681Cu) { return; }
    }
    ctx->pc = 0x13681Cu;
label_13681c:
    // 0x13681c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13681cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136820: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136820u;
    {
        const bool branch_taken_0x136820 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136820) {
            ctx->pc = 0x136824u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136820u;
            // 0x136824: 0x8e020050  lw          $v0, 0x50($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136838u;
            goto label_136838;
        }
    }
    ctx->pc = 0x136828u;
    // 0x136828: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136828u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13682c: 0xc04d480  jal         func_135200
    ctx->pc = 0x13682Cu;
    SET_GPR_U32(ctx, 31, 0x136834u);
    ctx->pc = 0x136830u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13682Cu;
            // 0x136830: 0x2484bf30  addiu       $a0, $a0, -0x40D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136834u; }
        if (ctx->pc != 0x136834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136834u; }
        if (ctx->pc != 0x136834u) { return; }
    }
    ctx->pc = 0x136834u;
label_136834:
    // 0x136834: 0x8e020050  lw          $v0, 0x50($s0)
    ctx->pc = 0x136834u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
label_136838:
    // 0x136838: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136838u;
    {
        const bool branch_taken_0x136838 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136838) {
            ctx->pc = 0x13683Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136838u;
            // 0x13683c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136850u;
            goto label_136850;
        }
    }
    ctx->pc = 0x136840u;
    // 0x136840: 0x40f809  jalr        $v0
    ctx->pc = 0x136840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136848u);
        ctx->pc = 0x136844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136840u;
            // 0x136844: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136848u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136848u; }
            if (ctx->pc != 0x136848u) { return; }
        }
        }
    }
    ctx->pc = 0x136848u;
label_136848:
    // 0x136848: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x136848u;
    {
        const bool branch_taken_0x136848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13684Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136848u;
            // 0x13684c: 0xdfb00060  ld          $s0, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136848) {
            ctx->pc = 0x136864u;
            goto label_136864;
        }
    }
    ctx->pc = 0x136850u;
label_136850:
    // 0x136850: 0x2484bf50  addiu       $a0, $a0, -0x40B0
    ctx->pc = 0x136850u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950736));
label_136854:
    // 0x136854: 0xc04d480  jal         func_135200
    ctx->pc = 0x136854u;
    SET_GPR_U32(ctx, 31, 0x13685Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13685Cu; }
        if (ctx->pc != 0x13685Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13685Cu; }
        if (ctx->pc != 0x13685Cu) { return; }
    }
    ctx->pc = 0x13685Cu;
label_13685c:
    // 0x13685c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x13685cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136860: 0xdfb00060  ld          $s0, 0x60($sp)
    ctx->pc = 0x136860u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_136864:
    // 0x136864: 0xdfb10068  ld          $s1, 0x68($sp)
    ctx->pc = 0x136864u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x136868: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x136868u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x13686c: 0x3e00008  jr          $ra
    ctx->pc = 0x13686Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13686Cu;
            // 0x136870: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136874u;
    // 0x136874: 0x0  nop
    ctx->pc = 0x136874u;
    // NOP
    // 0x136878: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x13687c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13687cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136880: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136880u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136884: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x136884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136888: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136888u;
    {
        const bool branch_taken_0x136888 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13688Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136888u;
            // 0x13688c: 0xffbf0270  sd          $ra, 0x270($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136888) {
            ctx->pc = 0x1368A0u;
            goto label_1368a0;
        }
    }
    ctx->pc = 0x136890u;
    // 0x136890: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136890u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136894: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x136894u;
    {
        const bool branch_taken_0x136894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136894u;
            // 0x136898: 0x2484bf70  addiu       $a0, $a0, -0x4090 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136894) {
            ctx->pc = 0x136914u;
            goto label_136914;
        }
    }
    ctx->pc = 0x13689Cu;
    // 0x13689c: 0x0  nop
    ctx->pc = 0x13689cu;
    // NOP
label_1368a0:
    // 0x1368a0: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x1368a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x1368a4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1368a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368a8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1368a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368ac: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1368ACu;
    SET_GPR_U32(ctx, 31, 0x1368B4u);
    ctx->pc = 0x1368B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1368ACu;
            // 0x1368b0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368B4u; }
        if (ctx->pc != 0x1368B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368B4u; }
        if (ctx->pc != 0x1368B4u) { return; }
    }
    ctx->pc = 0x1368B4u;
label_1368b4:
    // 0x1368b4: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x1368b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x1368b8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1368B8u;
    {
        const bool branch_taken_0x1368b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1368BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1368B8u;
            // 0x1368bc: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1368b8) {
            ctx->pc = 0x1368D0u;
            goto label_1368d0;
        }
    }
    ctx->pc = 0x1368C0u;
    // 0x1368c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1368c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1368c4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1368C4u;
    {
        const bool branch_taken_0x1368c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1368C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1368C4u;
            // 0x1368c8: 0x2484bf70  addiu       $a0, $a0, -0x4090 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1368c4) {
            ctx->pc = 0x136914u;
            goto label_136914;
        }
    }
    ctx->pc = 0x1368CCu;
    // 0x1368cc: 0x0  nop
    ctx->pc = 0x1368ccu;
    // NOP
label_1368d0:
    // 0x1368d0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1368d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368d4: 0xc04d622  jal         func_135888
    ctx->pc = 0x1368D4u;
    SET_GPR_U32(ctx, 31, 0x1368DCu);
    ctx->pc = 0x1368D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1368D4u;
            // 0x1368d8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368DCu; }
        if (ctx->pc != 0x1368DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368DCu; }
        if (ctx->pc != 0x1368DCu) { return; }
    }
    ctx->pc = 0x1368DCu;
label_1368dc:
    // 0x1368dc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1368dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1368e0: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1368E0u;
    {
        const bool branch_taken_0x1368e0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1368e0) {
            ctx->pc = 0x1368E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1368E0u;
            // 0x1368e4: 0x8e020054  lw          $v0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1368F8u;
            goto label_1368f8;
        }
    }
    ctx->pc = 0x1368E8u;
    // 0x1368e8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1368e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1368ec: 0xc04d480  jal         func_135200
    ctx->pc = 0x1368ECu;
    SET_GPR_U32(ctx, 31, 0x1368F4u);
    ctx->pc = 0x1368F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1368ECu;
            // 0x1368f0: 0x2484bfc0  addiu       $a0, $a0, -0x4040 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950848));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368F4u; }
        if (ctx->pc != 0x1368F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1368F4u; }
        if (ctx->pc != 0x1368F4u) { return; }
    }
    ctx->pc = 0x1368F4u;
label_1368f4:
    // 0x1368f4: 0x8e020054  lw          $v0, 0x54($s0)
    ctx->pc = 0x1368f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
label_1368f8:
    // 0x1368f8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1368F8u;
    {
        const bool branch_taken_0x1368f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1368f8) {
            ctx->pc = 0x1368FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1368F8u;
            // 0x1368fc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136910u;
            goto label_136910;
        }
    }
    ctx->pc = 0x136900u;
    // 0x136900: 0x40f809  jalr        $v0
    ctx->pc = 0x136900u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136908u);
        ctx->pc = 0x136904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136900u;
            // 0x136904: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136908u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136908u; }
            if (ctx->pc != 0x136908u) { return; }
        }
        }
    }
    ctx->pc = 0x136908u;
label_136908:
    // 0x136908: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x136908u;
    {
        const bool branch_taken_0x136908 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13690Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136908u;
            // 0x13690c: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136908) {
            ctx->pc = 0x136924u;
            goto label_136924;
        }
    }
    ctx->pc = 0x136910u;
label_136910:
    // 0x136910: 0x2484bfe8  addiu       $a0, $a0, -0x4018
    ctx->pc = 0x136910u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950888));
label_136914:
    // 0x136914: 0xc04d480  jal         func_135200
    ctx->pc = 0x136914u;
    SET_GPR_U32(ctx, 31, 0x13691Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13691Cu; }
        if (ctx->pc != 0x13691Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13691Cu; }
        if (ctx->pc != 0x13691Cu) { return; }
    }
    ctx->pc = 0x13691Cu;
label_13691c:
    // 0x13691c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x13691cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136920: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x136920u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_136924:
    // 0x136924: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136924u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136928: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x136928u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x13692c: 0x3e00008  jr          $ra
    ctx->pc = 0x13692Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13692Cu;
            // 0x136930: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136934u;
    // 0x136934: 0x0  nop
    ctx->pc = 0x136934u;
    // NOP
    // 0x136938: 0x27bdfd80  addiu       $sp, $sp, -0x280
    ctx->pc = 0x136938u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966656));
    // 0x13693c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13693cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136940: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136940u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136944: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x136944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136948: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136948u;
    {
        const bool branch_taken_0x136948 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13694Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136948u;
            // 0x13694c: 0xffbf0270  sd          $ra, 0x270($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136948) {
            ctx->pc = 0x136960u;
            goto label_136960;
        }
    }
    ctx->pc = 0x136950u;
    // 0x136950: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136950u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136954: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x136954u;
    {
        const bool branch_taken_0x136954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136954u;
            // 0x136958: 0x2484c008  addiu       $a0, $a0, -0x3FF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950920));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136954) {
            ctx->pc = 0x1369D4u;
            goto label_1369d4;
        }
    }
    ctx->pc = 0x13695Cu;
    // 0x13695c: 0x0  nop
    ctx->pc = 0x13695cu;
    // NOP
label_136960:
    // 0x136960: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x136960u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x136964: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136964u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136968: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x136968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13696c: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x13696Cu;
    SET_GPR_U32(ctx, 31, 0x136974u);
    ctx->pc = 0x136970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13696Cu;
            // 0x136970: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136974u; }
        if (ctx->pc != 0x136974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136974u; }
        if (ctx->pc != 0x136974u) { return; }
    }
    ctx->pc = 0x136974u;
label_136974:
    // 0x136974: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x136974u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x136978: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136978u;
    {
        const bool branch_taken_0x136978 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13697Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136978u;
            // 0x13697c: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136978) {
            ctx->pc = 0x136990u;
            goto label_136990;
        }
    }
    ctx->pc = 0x136980u;
    // 0x136980: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136980u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136984: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x136984u;
    {
        const bool branch_taken_0x136984 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136984u;
            // 0x136988: 0x2484c008  addiu       $a0, $a0, -0x3FF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950920));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136984) {
            ctx->pc = 0x1369D4u;
            goto label_1369d4;
        }
    }
    ctx->pc = 0x13698Cu;
    // 0x13698c: 0x0  nop
    ctx->pc = 0x13698cu;
    // NOP
label_136990:
    // 0x136990: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136990u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136994: 0xc04d622  jal         func_135888
    ctx->pc = 0x136994u;
    SET_GPR_U32(ctx, 31, 0x13699Cu);
    ctx->pc = 0x136998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136994u;
            // 0x136998: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13699Cu; }
        if (ctx->pc != 0x13699Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13699Cu; }
        if (ctx->pc != 0x13699Cu) { return; }
    }
    ctx->pc = 0x13699Cu;
label_13699c:
    // 0x13699c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13699cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1369a0: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1369A0u;
    {
        const bool branch_taken_0x1369a0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1369a0) {
            ctx->pc = 0x1369A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1369A0u;
            // 0x1369a4: 0x8e020058  lw          $v0, 0x58($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1369B8u;
            goto label_1369b8;
        }
    }
    ctx->pc = 0x1369A8u;
    // 0x1369a8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1369a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1369ac: 0xc04d480  jal         func_135200
    ctx->pc = 0x1369ACu;
    SET_GPR_U32(ctx, 31, 0x1369B4u);
    ctx->pc = 0x1369B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1369ACu;
            // 0x1369b0: 0x2484c058  addiu       $a0, $a0, -0x3FA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369B4u; }
        if (ctx->pc != 0x1369B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369B4u; }
        if (ctx->pc != 0x1369B4u) { return; }
    }
    ctx->pc = 0x1369B4u;
label_1369b4:
    // 0x1369b4: 0x8e020058  lw          $v0, 0x58($s0)
    ctx->pc = 0x1369b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
label_1369b8:
    // 0x1369b8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1369B8u;
    {
        const bool branch_taken_0x1369b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1369b8) {
            ctx->pc = 0x1369BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1369B8u;
            // 0x1369bc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1369D0u;
            goto label_1369d0;
        }
    }
    ctx->pc = 0x1369C0u;
    // 0x1369c0: 0x40f809  jalr        $v0
    ctx->pc = 0x1369C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1369C8u);
        ctx->pc = 0x1369C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369C0u;
            // 0x1369c4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1369C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1369C8u; }
            if (ctx->pc != 0x1369C8u) { return; }
        }
        }
    }
    ctx->pc = 0x1369C8u;
label_1369c8:
    // 0x1369c8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1369C8u;
    {
        const bool branch_taken_0x1369c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1369CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369C8u;
            // 0x1369cc: 0xdfb00260  ld          $s0, 0x260($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1369c8) {
            ctx->pc = 0x1369E4u;
            goto label_1369e4;
        }
    }
    ctx->pc = 0x1369D0u;
label_1369d0:
    // 0x1369d0: 0x2484c080  addiu       $a0, $a0, -0x3F80
    ctx->pc = 0x1369d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951040));
label_1369d4:
    // 0x1369d4: 0xc04d480  jal         func_135200
    ctx->pc = 0x1369D4u;
    SET_GPR_U32(ctx, 31, 0x1369DCu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369DCu; }
        if (ctx->pc != 0x1369DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1369DCu; }
        if (ctx->pc != 0x1369DCu) { return; }
    }
    ctx->pc = 0x1369DCu;
label_1369dc:
    // 0x1369dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1369dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1369e0: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x1369e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
label_1369e4:
    // 0x1369e4: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x1369e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x1369e8: 0xdfbf0270  ld          $ra, 0x270($sp)
    ctx->pc = 0x1369e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x1369ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1369ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1369F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369ECu;
            // 0x1369f0: 0x27bd0280  addiu       $sp, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1369F4u;
    // 0x1369f4: 0x0  nop
    ctx->pc = 0x1369f4u;
    // NOP
    // 0x1369f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1369f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1369fc: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1369FCu;
    {
        const bool branch_taken_0x1369fc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369FCu;
            // 0x136a00: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1369fc) {
            ctx->pc = 0x136A18u;
            goto label_136a18;
        }
    }
    ctx->pc = 0x136A04u;
    // 0x136a04: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136a04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136a08: 0xc04d480  jal         func_135200
    ctx->pc = 0x136A08u;
    SET_GPR_U32(ctx, 31, 0x136A10u);
    ctx->pc = 0x136A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136A08u;
            // 0x136a0c: 0x2484c0a0  addiu       $a0, $a0, -0x3F60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136A10u; }
        if (ctx->pc != 0x136A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136A10u; }
        if (ctx->pc != 0x136A10u) { return; }
    }
    ctx->pc = 0x136A10u;
label_136a10:
    // 0x136a10: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x136A10u;
    {
        const bool branch_taken_0x136a10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A10u;
            // 0x136a14: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136a10) {
            ctx->pc = 0x136A70u;
            goto label_136a70;
        }
    }
    ctx->pc = 0x136A18u;
label_136a18:
    // 0x136a18: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x136a18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x136a1c: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x136a1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136a20: 0x24432068  addiu       $v1, $v0, 0x2068
    ctx->pc = 0x136a20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 8296));
    // 0x136a24: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136a24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136a28: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x136a28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x136a2c: 0x1044000d  beq         $v0, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x136A2Cu;
    {
        const bool branch_taken_0x136a2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x136A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A2Cu;
            // 0x136a30: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136a2c) {
            ctx->pc = 0x136A64u;
            goto label_136a64;
        }
    }
    ctx->pc = 0x136A34u;
    // 0x136a34: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x136a34u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136a38: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x136a38u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x136a3c: 0x0  nop
    ctx->pc = 0x136a3cu;
    // NOP
label_136a40:
    // 0x136a40: 0x62900  sll         $a1, $a2, 4
    ctx->pc = 0x136a40u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x136a44: 0x28c20020  slti        $v0, $a2, 0x20
    ctx->pc = 0x136a44u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x136a48: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136A48u;
    {
        const bool branch_taken_0x136a48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A48u;
            // 0x136a4c: 0xa71821  addu        $v1, $a1, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136a48) {
            ctx->pc = 0x136A64u;
            goto label_136a64;
        }
    }
    ctx->pc = 0x136A50u;
    // 0x136a50: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x136a50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x136a54: 0x0  nop
    ctx->pc = 0x136a54u;
    // NOP
    // 0x136a58: 0x0  nop
    ctx->pc = 0x136a58u;
    // NOP
    // 0x136a5c: 0x5444fff8  bnel        $v0, $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x136A5Cu;
    {
        const bool branch_taken_0x136a5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x136a5c) {
            ctx->pc = 0x136A60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136A5Cu;
            // 0x136a60: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136A40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_136a40;
        }
    }
    ctx->pc = 0x136A64u;
label_136a64:
    // 0x136a64: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x136a64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x136a68: 0x2442206c  addiu       $v0, $v0, 0x206C
    ctx->pc = 0x136a68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x136a6c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x136a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_136a70:
    // 0x136a70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136a70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136a74: 0x3e00008  jr          $ra
    ctx->pc = 0x136A74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A74u;
            // 0x136a78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135FE0u: goto label_135fe0;
            case 0x135FF4u: goto label_135ff4;
            case 0x136010u: goto label_136010;
            case 0x13601Cu: goto label_13601c;
            case 0x136034u: goto label_136034;
            case 0x136038u: goto label_136038;
            case 0x136048u: goto label_136048;
            case 0x136050u: goto label_136050;
            case 0x136054u: goto label_136054;
            case 0x13605Cu: goto label_13605c;
            case 0x136064u: goto label_136064;
            case 0x1360A8u: goto label_1360a8;
            case 0x1360BCu: goto label_1360bc;
            case 0x1360D8u: goto label_1360d8;
            case 0x1360E4u: goto label_1360e4;
            case 0x1360FCu: goto label_1360fc;
            case 0x136100u: goto label_136100;
            case 0x136110u: goto label_136110;
            case 0x136118u: goto label_136118;
            case 0x136120u: goto label_136120;
            case 0x136128u: goto label_136128;
            case 0x136130u: goto label_136130;
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            case 0x1361E4u: goto label_1361e4;
            case 0x1361ECu: goto label_1361ec;
            case 0x136208u: goto label_136208;
            case 0x136210u: goto label_136210;
            case 0x136220u: goto label_136220;
            case 0x136228u: goto label_136228;
            case 0x136240u: goto label_136240;
            case 0x136258u: goto label_136258;
            case 0x136270u: goto label_136270;
            case 0x136298u: goto label_136298;
            case 0x1362A0u: goto label_1362a0;
            case 0x1362A8u: goto label_1362a8;
            case 0x1362B0u: goto label_1362b0;
            case 0x1362B4u: goto label_1362b4;
            case 0x1362C0u: goto label_1362c0;
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            case 0x1363C8u: goto label_1363c8;
            case 0x1363D0u: goto label_1363d0;
            case 0x1363E8u: goto label_1363e8;
            case 0x1363F0u: goto label_1363f0;
            case 0x1363F8u: goto label_1363f8;
            case 0x1363FCu: goto label_1363fc;
            case 0x136438u: goto label_136438;
            case 0x13644Cu: goto label_13644c;
            case 0x136468u: goto label_136468;
            case 0x136474u: goto label_136474;
            case 0x13648Cu: goto label_13648c;
            case 0x136490u: goto label_136490;
            case 0x1364A0u: goto label_1364a0;
            case 0x1364A8u: goto label_1364a8;
            case 0x1364ACu: goto label_1364ac;
            case 0x1364B4u: goto label_1364b4;
            case 0x1364BCu: goto label_1364bc;
            case 0x1364F8u: goto label_1364f8;
            case 0x136518u: goto label_136518;
            case 0x136530u: goto label_136530;
            case 0x136544u: goto label_136544;
            case 0x136550u: goto label_136550;
            case 0x136554u: goto label_136554;
            case 0x13655Cu: goto label_13655c;
            case 0x136564u: goto label_136564;
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            case 0x1368A0u: goto label_1368a0;
            case 0x1368B4u: goto label_1368b4;
            case 0x1368D0u: goto label_1368d0;
            case 0x1368DCu: goto label_1368dc;
            case 0x1368F4u: goto label_1368f4;
            case 0x1368F8u: goto label_1368f8;
            case 0x136908u: goto label_136908;
            case 0x136910u: goto label_136910;
            case 0x136914u: goto label_136914;
            case 0x13691Cu: goto label_13691c;
            case 0x136924u: goto label_136924;
            case 0x136960u: goto label_136960;
            case 0x136974u: goto label_136974;
            case 0x136990u: goto label_136990;
            case 0x13699Cu: goto label_13699c;
            case 0x1369B4u: goto label_1369b4;
            case 0x1369B8u: goto label_1369b8;
            case 0x1369C8u: goto label_1369c8;
            case 0x1369D0u: goto label_1369d0;
            case 0x1369D4u: goto label_1369d4;
            case 0x1369DCu: goto label_1369dc;
            case 0x1369E4u: goto label_1369e4;
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136A7Cu;
    // 0x136a7c: 0x0  nop
    ctx->pc = 0x136a7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
