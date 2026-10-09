#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018D470
// Address: 0x18d470 - 0x18d650
void sub_0018D470_0x18d470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018D470_0x18d470");
#endif

    switch (ctx->pc) {
        case 0x18d4ecu: goto label_18d4ec;
        case 0x18d56cu: goto label_18d56c;
        case 0x18d57cu: goto label_18d57c;
        case 0x18d5d8u: goto label_18d5d8;
        case 0x18d620u: goto label_18d620;
        case 0x18d62cu: goto label_18d62c;
        default: break;
    }

    ctx->pc = 0x18d470u;

    // 0x18d470: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18d470u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18d474: 0x3c03002a  lui         $v1, 0x2A
    ctx->pc = 0x18d474u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)42 << 16));
    // 0x18d478: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x18d478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x18d47c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18d47cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18d480: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18d480u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18d484: 0x2463f704  addiu       $v1, $v1, -0x8FC
    ctx->pc = 0x18d484u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294964996));
    // 0x18d488: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18d488u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18d48c: 0x3c12002a  lui         $s2, 0x2A
    ctx->pc = 0x18d48cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)42 << 16));
    // 0x18d490: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18d490u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18d494: 0xac20f724  sw          $zero, -0x8DC($at)
    ctx->pc = 0x18d494u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965028), GPR_U32(ctx, 0));
    // 0x18d498: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18d498u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18d49c: 0xac20f728  sw          $zero, -0x8D8($at)
    ctx->pc = 0x18d49cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965032), GPR_U32(ctx, 0));
    // 0x18d4a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18d4a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18d4a4: 0x8c25fdb4  lw          $a1, -0x24C($at)
    ctx->pc = 0x18d4a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
    // 0x18d4a8: 0x58080  sll         $s0, $a1, 2
    ctx->pc = 0x18d4a8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x18d4ac: 0x38a40001  xori        $a0, $a1, 0x1
    ctx->pc = 0x18d4acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)1);
    // 0x18d4b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18d4b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18d4b4: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x18d4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x18d4b8: 0xac24fdb4  sw          $a0, -0x24C($at)
    ctx->pc = 0x18d4b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966708), GPR_U32(ctx, 4));
    // 0x18d4bc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x18d4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18d4c0: 0x1060005a  beqz        $v1, . + 4 + (0x5A << 2)
    ctx->pc = 0x18D4C0u;
    {
        const bool branch_taken_0x18d4c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D4C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D4C0u;
            // 0x18d4c4: 0x2652f6f0  addiu       $s2, $s2, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294964976));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d4c0) {
            ctx->pc = 0x18D62Cu;
            goto label_18d62c;
        }
    }
    ctx->pc = 0x18D4C8u;
    // 0x18d4c8: 0x2121021  addu        $v0, $s0, $s2
    ctx->pc = 0x18d4c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x18d4cc: 0x3c03002a  lui         $v1, 0x2A
    ctx->pc = 0x18d4ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)42 << 16));
    // 0x18d4d0: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x18d4d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d4d4: 0x2463fd74  addiu       $v1, $v1, -0x28C
    ctx->pc = 0x18d4d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966644));
    // 0x18d4d8: 0x8c44000c  lw          $a0, 0xC($v0)
    ctx->pc = 0x18d4d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x18d4dc: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x18d4dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x18d4e0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x18d4e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18d4e4: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x18D4E4u;
    SET_GPR_U32(ctx, 31, 0x18D4ECu);
    ctx->pc = 0x18D4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D4E4u;
            // 0x18d4e8: 0x8c510000  lw          $s1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D4ECu; }
        if (ctx->pc != 0x18D4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D4ECu; }
        if (ctx->pc != 0x18D4ECu) { return; }
    }
    ctx->pc = 0x18D4ECu;
label_18d4ec:
    // 0x18d4ec: 0x2122021  addu        $a0, $s0, $s2
    ctx->pc = 0x18d4ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x18d4f0: 0x3c03f000  lui         $v1, 0xF000
    ctx->pc = 0x18d4f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)61440 << 16));
    // 0x18d4f4: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x18d4f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x18d4f8: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x18d4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x18d4fc: 0x442021  addu        $a0, $v0, $a0
    ctx->pc = 0x18d4fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18d500: 0x8c900000  lw          $s0, 0x0($a0)
    ctx->pc = 0x18d500u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18d504: 0x2031824  and         $v1, $s0, $v1
    ctx->pc = 0x18d504u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x18d508: 0x31f02  srl         $v1, $v1, 28
    ctx->pc = 0x18d508u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 28));
    // 0x18d50c: 0x2c610006  sltiu       $at, $v1, 0x6
    ctx->pc = 0x18d50cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x18d510: 0x10200046  beqz        $at, . + 4 + (0x46 << 2)
    ctx->pc = 0x18D510u;
    {
        const bool branch_taken_0x18d510 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D510u;
            // 0x18d514: 0xae50002c  sw          $s0, 0x2C($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d510) {
            ctx->pc = 0x18D62Cu;
            goto label_18d62c;
        }
    }
    ctx->pc = 0x18D518u;
    // 0x18d518: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x18d518u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x18d51c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18d51cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18d520: 0x24841c30  addiu       $a0, $a0, 0x1C30
    ctx->pc = 0x18d520u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7216));
    // 0x18d524: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18d524u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18d528: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x18d528u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18d52c: 0x600008  jr          $v1
    ctx->pc = 0x18D52Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D534u: goto label_18d534;
            case 0x18D584u: goto label_18d584;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D534u;
label_18d534:
    // 0x18d534: 0x92270000  lbu         $a3, 0x0($s1)
    ctx->pc = 0x18d534u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18d538: 0x2405ffbf  addiu       $a1, $zero, -0x41
    ctx->pc = 0x18d538u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x18d53c: 0x64060040  daddiu      $a2, $zero, 0x40
    ctx->pc = 0x18d53cu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)64);
    // 0x18d540: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x18d540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x18d544: 0x64030080  daddiu      $v1, $zero, 0x80
    ctx->pc = 0x18d544u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)128);
    // 0x18d548: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18d548u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d54c: 0xe52824  and         $a1, $a3, $a1
    ctx->pc = 0x18d54cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x18d550: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x18d550u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x18d554: 0xa2250000  sb          $a1, 0x0($s1)
    ctx->pc = 0x18d554u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x18d558: 0x92250000  lbu         $a1, 0x0($s1)
    ctx->pc = 0x18d558u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18d55c: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x18d55cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x18d560: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18d560u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18d564: 0xc045228  jal         func_1148A0
    ctx->pc = 0x18D564u;
    SET_GPR_U32(ctx, 31, 0x18D56Cu);
    ctx->pc = 0x18D568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D564u;
            // 0x18d568: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D56Cu; }
        if (ctx->pc != 0x18D56Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D56Cu; }
        if (ctx->pc != 0x18D56Cu) { return; }
    }
    ctx->pc = 0x18D56Cu;
label_18d56c:
    // 0x18d56c: 0x10293c  dsll32      $a1, $s0, 4
    ctx->pc = 0x18d56cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 4));
    // 0x18d570: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x18d570u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d574: 0xc040ce4  jal         func_103390
    ctx->pc = 0x18D574u;
    SET_GPR_U32(ctx, 31, 0x18D57Cu);
    ctx->pc = 0x18D578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D574u;
            // 0x18d578: 0x5293e  dsrl32      $a1, $a1, 4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D57Cu; }
        if (ctx->pc != 0x18D57Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D57Cu; }
        if (ctx->pc != 0x18D57Cu) { return; }
    }
    ctx->pc = 0x18D57Cu;
label_18d57c:
    // 0x18d57c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x18D57Cu;
    {
        const bool branch_taken_0x18d57c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D57Cu;
            // 0x18d580: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d57c) {
            ctx->pc = 0x18D630u;
            goto label_18d630;
        }
    }
    ctx->pc = 0x18D584u;
label_18d584:
    // 0x18d584: 0x10813c  dsll32      $s0, $s0, 4
    ctx->pc = 0x18d584u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 4));
    // 0x18d588: 0x2402fdff  addiu       $v0, $zero, -0x201
    ctx->pc = 0x18d588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966783));
    // 0x18d58c: 0x10813e  dsrl32      $s0, $s0, 4
    ctx->pc = 0x18d58cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 4));
    // 0x18d590: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d590u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d594: 0x8e050080  lw          $a1, 0x80($s0)
    ctx->pc = 0x18d594u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x18d598: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18d598u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18d59c: 0x70021389  pcpyld      $v0, $zero, $v0
    ctx->pc = 0x18d59cu;
    SET_GPR_VEC(ctx, 2, PS2_PCPYLD(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x18d5a0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18d5a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d5a4: 0xac254148  sw          $a1, 0x4148($at)
    ctx->pc = 0x18d5a4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16712), GPR_U32(ctx, 5));
    // 0x18d5a8: 0x8e050084  lw          $a1, 0x84($s0)
    ctx->pc = 0x18d5a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x18d5ac: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d5acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d5b0: 0xac254150  sw          $a1, 0x4150($at)
    ctx->pc = 0x18d5b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16720), GPR_U32(ctx, 5));
    // 0x18d5b4: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d5b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d5b8: 0xfc231000  sd          $v1, 0x1000($at)
    ctx->pc = 0x18d5b8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4096), GPR_U64(ctx, 3));
    // 0x18d5bc: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d5bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d5c0: 0xdc231010  ld          $v1, 0x1010($at)
    ctx->pc = 0x18d5c0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 4112)));
    // 0x18d5c4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d5c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d5c8: 0xfc234158  sd          $v1, 0x4158($at)
    ctx->pc = 0x18d5c8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 16728), GPR_U64(ctx, 3));
    // 0x18d5cc: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d5ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d5d0: 0xc04545a  jal         func_115168
    ctx->pc = 0x18D5D0u;
    SET_GPR_U32(ctx, 31, 0x18D5D8u);
    ctx->pc = 0x18D5D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D5D0u;
            // 0x18d5d4: 0xfc221010  sd          $v0, 0x1010($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115168u;
    if (runtime->hasFunction(0x115168u)) {
        auto targetFn = runtime->lookupFunction(0x115168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D5D8u; }
        if (ctx->pc != 0x18D5D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115168_0x115168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D5D8u; }
        if (ctx->pc != 0x18D5D8u) { return; }
    }
    ctx->pc = 0x18D5D8u;
label_18d5d8:
    // 0x18d5d8: 0x8e470030  lw          $a3, 0x30($s2)
    ctx->pc = 0x18d5d8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x18d5dc: 0x30020001  andi        $v0, $zero, 0x1
    ctx->pc = 0x18d5dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) & (uint64_t)(uint16_t)1);
    // 0x18d5e0: 0x2405ffbf  addiu       $a1, $zero, -0x41
    ctx->pc = 0x18d5e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x18d5e4: 0x23180  sll         $a2, $v0, 6
    ctx->pc = 0x18d5e4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x18d5e8: 0x219c0  sll         $v1, $v0, 7
    ctx->pc = 0x18d5e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x18d5ec: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18d5ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d5f0: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x18d5f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x18d5f4: 0x34e70001  ori         $a3, $a3, 0x1
    ctx->pc = 0x18d5f4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1);
    // 0x18d5f8: 0xae470030  sw          $a3, 0x30($s2)
    ctx->pc = 0x18d5f8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 7));
    // 0x18d5fc: 0x92270000  lbu         $a3, 0x0($s1)
    ctx->pc = 0x18d5fcu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18d600: 0xe52824  and         $a1, $a3, $a1
    ctx->pc = 0x18d600u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x18d604: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x18d604u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x18d608: 0xa2250000  sb          $a1, 0x0($s1)
    ctx->pc = 0x18d608u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x18d60c: 0x92250000  lbu         $a1, 0x0($s1)
    ctx->pc = 0x18d60cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18d610: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x18d610u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x18d614: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18d614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18d618: 0xc045228  jal         func_1148A0
    ctx->pc = 0x18D618u;
    SET_GPR_U32(ctx, 31, 0x18D620u);
    ctx->pc = 0x18D61Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D618u;
            // 0x18d61c: 0xa2220000  sb          $v0, 0x0($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D620u; }
        if (ctx->pc != 0x18D620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D620u; }
        if (ctx->pc != 0x18D620u) { return; }
    }
    ctx->pc = 0x18D620u;
label_18d620:
    // 0x18d620: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x18d620u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d624: 0xc040ce4  jal         func_103390
    ctx->pc = 0x18D624u;
    SET_GPR_U32(ctx, 31, 0x18D62Cu);
    ctx->pc = 0x18D628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D624u;
            // 0x18d628: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D62Cu; }
        if (ctx->pc != 0x18D62Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D62Cu; }
        if (ctx->pc != 0x18D62Cu) { return; }
    }
    ctx->pc = 0x18D62Cu;
label_18d62c:
    // 0x18d62c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x18d62cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_18d630:
    // 0x18d630: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18d630u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18d634: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18d634u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18d638: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18d638u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18d63c: 0x3e00008  jr          $ra
    ctx->pc = 0x18D63Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D63Cu;
            // 0x18d640: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D4ECu: goto label_18d4ec;
            case 0x18D534u: goto label_18d534;
            case 0x18D56Cu: goto label_18d56c;
            case 0x18D57Cu: goto label_18d57c;
            case 0x18D584u: goto label_18d584;
            case 0x18D5D8u: goto label_18d5d8;
            case 0x18D620u: goto label_18d620;
            case 0x18D62Cu: goto label_18d62c;
            case 0x18D630u: goto label_18d630;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D644u;
    // 0x18d644: 0x0  nop
    ctx->pc = 0x18d644u;
    // NOP
    // 0x18d648: 0x0  nop
    ctx->pc = 0x18d648u;
    // NOP
    // 0x18d64c: 0x0  nop
    ctx->pc = 0x18d64cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
