#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188348
// Address: 0x188348 - 0x1886b8
void sub_00188348_0x188348(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188348_0x188348");
#endif

    switch (ctx->pc) {
        case 0x1883acu: goto label_1883ac;
        case 0x1883e4u: goto label_1883e4;
        case 0x188404u: goto label_188404;
        case 0x18848cu: goto label_18848c;
        case 0x1884a4u: goto label_1884a4;
        case 0x1884b0u: goto label_1884b0;
        case 0x1884c0u: goto label_1884c0;
        case 0x1884d4u: goto label_1884d4;
        case 0x1884fcu: goto label_1884fc;
        case 0x188594u: goto label_188594;
        case 0x1885bcu: goto label_1885bc;
        case 0x188630u: goto label_188630;
        case 0x188640u: goto label_188640;
        case 0x188654u: goto label_188654;
        case 0x188678u: goto label_188678;
        default: break;
    }

    ctx->pc = 0x188348u;

    // 0x188348: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x188348u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18834c: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18834cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x188350: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x188350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x188354: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x188354u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188358: 0x1610c0  sll         $v0, $s6, 3
    ctx->pc = 0x188358u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 3));
    // 0x18835c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x18835cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x188360: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x188360u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x188364: 0x561023  subu        $v0, $v0, $s6
    ctx->pc = 0x188364u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x188368: 0x2473b8c8  addiu       $s3, $v1, -0x4738
    ctx->pc = 0x188368u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949064));
    // 0x18836c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x18836cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x188370: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x188370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x188374: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x188374u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188378: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x188378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x18837c: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x18837cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188380: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x188380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x188384: 0x26630004  addiu       $v1, $s3, 0x4
    ctx->pc = 0x188384u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x188388: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x18838c: 0x29080  sll         $s2, $v0, 2
    ctx->pc = 0x18838cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x188390: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x188390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x188394: 0x243f021  addu        $fp, $s2, $v1
    ctx->pc = 0x188394u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x188398: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x188398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x18839c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x18839cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x1883a0: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x1883a0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x1883a4: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x1883A4u;
    SET_GPR_U32(ctx, 31, 0x1883ACu);
    ctx->pc = 0x1883A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1883A4u;
            // 0x1883a8: 0x8fc40000  lw          $a0, 0x0($fp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1883ACu; }
        if (ctx->pc != 0x1883ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1883ACu; }
        if (ctx->pc != 0x1883ACu) { return; }
    }
    ctx->pc = 0x1883ACu;
label_1883ac:
    // 0x1883ac: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1883acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1883b0: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1883B0u;
    {
        const bool branch_taken_0x1883b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1883B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1883B0u;
            // 0x1883b4: 0x26630008  addiu       $v1, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1883b0) {
            ctx->pc = 0x1883C0u;
            goto label_1883c0;
        }
    }
    ctx->pc = 0x1883B8u;
    // 0x1883b8: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1883B8u;
    {
        const bool branch_taken_0x1883b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1883BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1883B8u;
            // 0x1883bc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1883b8) {
            ctx->pc = 0x188508u;
            goto label_188508;
        }
    }
    ctx->pc = 0x1883C0u;
label_1883c0:
    // 0x1883c0: 0x243a021  addu        $s4, $s2, $v1
    ctx->pc = 0x1883c0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1883c4: 0x8e820000  lw          $v0, 0x0($s4)
    ctx->pc = 0x1883c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1883c8: 0x551018  mult        $v0, $v0, $s5
    ctx->pc = 0x1883c8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1883cc: 0x2c422001  sltiu       $v0, $v0, 0x2001
    ctx->pc = 0x1883ccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)8193) ? 1 : 0);
    // 0x1883d0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1883D0u;
    {
        const bool branch_taken_0x1883d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1883D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1883D0u;
            // 0x1883d4: 0x3c110029  lui         $s1, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1883d0) {
            ctx->pc = 0x1883F0u;
            goto label_1883f0;
        }
    }
    ctx->pc = 0x1883D8u;
    // 0x1883d8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1883d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1883dc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1883DCu;
    SET_GPR_U32(ctx, 31, 0x1883E4u);
    ctx->pc = 0x1883E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1883DCu;
            // 0x1883e0: 0x24841848  addiu       $a0, $a0, 0x1848 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1883E4u; }
        if (ctx->pc != 0x1883E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1883E4u; }
        if (ctx->pc != 0x1883E4u) { return; }
    }
    ctx->pc = 0x1883E4u;
label_1883e4:
    // 0x1883e4: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1883E4u;
    {
        const bool branch_taken_0x1883e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1883E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1883E4u;
            // 0x1883e8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1883e4) {
            ctx->pc = 0x188508u;
            goto label_188508;
        }
    }
    ctx->pc = 0x1883ECu;
    // 0x1883ec: 0x0  nop
    ctx->pc = 0x1883ecu;
    // NOP
label_1883f0:
    // 0x1883f0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1883f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1883f4: 0x2630b900  addiu       $s0, $s1, -0x4700
    ctx->pc = 0x1883f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294949120));
    // 0x1883f8: 0x24062080  addiu       $a2, $zero, 0x2080
    ctx->pc = 0x1883f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x1883fc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1883FCu;
    SET_GPR_U32(ctx, 31, 0x188404u);
    ctx->pc = 0x188400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1883FCu;
            // 0x188400: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188404u; }
        if (ctx->pc != 0x188404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188404u; }
        if (ctx->pc != 0x188404u) { return; }
    }
    ctx->pc = 0x188404u;
label_188404:
    // 0x188404: 0xae170000  sw          $s7, 0x0($s0)
    ctx->pc = 0x188404u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 23));
    // 0x188408: 0x2721021  addu        $v0, $s3, $s2
    ctx->pc = 0x188408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x18840c: 0x3c120023  lui         $s2, 0x23
    ctx->pc = 0x18840cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
    // 0x188410: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x188410u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188414: 0x8c47000c  lw          $a3, 0xC($v0)
    ctx->pc = 0x188414u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x188418: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x188418u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x18841c: 0x60482d  daddu       $t1, $v1, $zero
    ctx->pc = 0x18841cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188420: 0x8e880000  lw          $t0, 0x0($s4)
    ctx->pc = 0x188420u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x188424: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x188424u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188428: 0x47001a  div         $zero, $v0, $a3
    ctx->pc = 0x188428u;
    { int32_t divisor = GPR_S32(ctx, 7);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x18842c: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x18842cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x188430: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x188430u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x188434: 0x26040028  addiu       $a0, $s0, 0x28
    ctx->pc = 0x188434u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x188438: 0xae07000c  sw          $a3, 0xC($s0)
    ctx->pc = 0x188438u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 7));
    // 0x18843c: 0x3c0982d  daddu       $s3, $fp, $zero
    ctx->pc = 0x18843cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188440: 0xae080008  sw          $t0, 0x8($s0)
    ctx->pc = 0x188440u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 8));
    // 0x188444: 0x3c170018  lui         $s7, 0x18
    ctx->pc = 0x188444u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)24 << 16));
    // 0x188448: 0xae150004  sw          $s5, 0x4($s0)
    ctx->pc = 0x188448u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 21));
    // 0x18844c: 0x50e00001  beql        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x18844Cu;
    {
        const bool branch_taken_0x18844c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x18844c) {
            ctx->pc = 0x188450u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18844Cu;
            // 0x188450: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x188454u;
            goto label_188454;
        }
    }
    ctx->pc = 0x188454u;
label_188454:
    // 0x188454: 0x1812  mflo        $v1
    ctx->pc = 0x188454u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x188458: 0x1150018  mult        $zero, $t0, $s5
    ctx->pc = 0x188458u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x18845c: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18845cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x188460: 0x2463fffe  addiu       $v1, $v1, -0x2
    ctx->pc = 0x188460u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967294));
    // 0x188464: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x188464u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x188468: 0x8d220014  lw          $v0, 0x14($t1)
    ctx->pc = 0x188468u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 20)));
    // 0x18846c: 0xae030018  sw          $v1, 0x18($s0)
    ctx->pc = 0x18846cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 3));
    // 0x188470: 0x3012  mflo        $a2
    ctx->pc = 0x188470u;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x188474: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x188474u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x188478: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x188478u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x18847c: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x18847cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x188480: 0x3c100029  lui         $s0, 0x29
    ctx->pc = 0x188480u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)41 << 16));
    // 0x188484: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x188484u;
    SET_GPR_U32(ctx, 31, 0x18848Cu);
    ctx->pc = 0x188488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188484u;
            // 0x188488: 0x2610d980  addiu       $s0, $s0, -0x2680 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294957440));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18848Cu; }
        if (ctx->pc != 0x18848Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18848Cu; }
        if (ctx->pc != 0x18848Cu) { return; }
    }
    ctx->pc = 0x18848Cu;
label_18848c:
    // 0x18848c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18848cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188490: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x188490u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x188494: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x188494u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188498: 0x24022080  addiu       $v0, $zero, 0x2080
    ctx->pc = 0x188498u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x18849c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x18849Cu;
    SET_GPR_U32(ctx, 31, 0x1884A4u);
    ctx->pc = 0x1884A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18849Cu;
            // 0x1884a0: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884A4u; }
        if (ctx->pc != 0x1884A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884A4u; }
        if (ctx->pc != 0x1884A4u) { return; }
    }
    ctx->pc = 0x1884A4u;
label_1884a4:
    // 0x1884a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1884a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1884a8: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x1884A8u;
    SET_GPR_U32(ctx, 31, 0x1884B0u);
    ctx->pc = 0x1884ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1884A8u;
            // 0x1884ac: 0x248500ff  addiu       $a1, $a0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884B0u; }
        if (ctx->pc != 0x1884B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884B0u; }
        if (ctx->pc != 0x1884B0u) { return; }
    }
    ctx->pc = 0x1884B0u;
label_1884b0:
    // 0x1884b0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1884b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1884b4: 0xae42fd24  sw          $v0, -0x2DC($s2)
    ctx->pc = 0x1884b4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294966564), GPR_U32(ctx, 2));
    // 0x1884b8: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x1884b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1884bc: 0x0  nop
    ctx->pc = 0x1884bcu;
    // NOP
label_1884c0:
    // 0x1884c0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1884c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1884c4: 0x8e45fd24  lw          $a1, -0x2DC($s2)
    ctx->pc = 0x1884c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294966564)));
    // 0x1884c8: 0x2627b900  addiu       $a3, $s1, -0x4700
    ctx->pc = 0x1884c8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 4294949120));
    // 0x1884cc: 0xc062560  jal         func_189580
    ctx->pc = 0x1884CCu;
    SET_GPR_U32(ctx, 31, 0x1884D4u);
    ctx->pc = 0x1884D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1884CCu;
            // 0x1884d0: 0x26e87808  addiu       $t0, $s7, 0x7808 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 23), 30728));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189580u;
    if (runtime->hasFunction(0x189580u)) {
        auto targetFn = runtime->lookupFunction(0x189580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884D4u; }
        if (ctx->pc != 0x1884D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884D4u; }
        if (ctx->pc != 0x1884D4u) { return; }
    }
    ctx->pc = 0x1884D4u;
label_1884d4:
    // 0x1884d4: 0x5454fffa  bnel        $v0, $s4, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1884D4u;
    {
        const bool branch_taken_0x1884d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        if (branch_taken_0x1884d4) {
            ctx->pc = 0x1884D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1884D4u;
            // 0x1884d8: 0x8e640000  lw          $a0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1884C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1884c0;
        }
    }
    ctx->pc = 0x1884DCu;
    // 0x1884dc: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x1884dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1884e0: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x1884e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x1884e4: 0x761023  subu        $v0, $v1, $s6
    ctx->pc = 0x1884e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
    // 0x1884e8: 0x2483b8c8  addiu       $v1, $a0, -0x4738
    ctx->pc = 0x1884e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949064));
    // 0x1884ec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1884ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1884f0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1884f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1884f4: 0xc061db2  jal         func_1876C8
    ctx->pc = 0x1884F4u;
    SET_GPR_U32(ctx, 31, 0x1884FCu);
    ctx->pc = 0x1884F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1884F4u;
            // 0x1884f8: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1876C8u;
    if (runtime->hasFunction(0x1876C8u)) {
        auto targetFn = runtime->lookupFunction(0x1876C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884FCu; }
        if (ctx->pc != 0x1884FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1884FCu; }
        if (ctx->pc != 0x1884FCu) { return; }
    }
    ctx->pc = 0x1884FCu;
label_1884fc:
    // 0x1884fc: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1884fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x188500: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x188500u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188504: 0x2a3100b  movn        $v0, $s5, $v1
    ctx->pc = 0x188504u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 21));
label_188508:
    // 0x188508: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188508u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18850c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x18850cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x188510: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x188510u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188514: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x188514u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x188518: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x188518u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18851c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x18851cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x188520: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x188520u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x188524: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x188524u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x188528: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x188528u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18852c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x18852cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x188530: 0x3e00008  jr          $ra
    ctx->pc = 0x188530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188530u;
            // 0x188534: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1883ACu: goto label_1883ac;
            case 0x1883C0u: goto label_1883c0;
            case 0x1883E4u: goto label_1883e4;
            case 0x1883F0u: goto label_1883f0;
            case 0x188404u: goto label_188404;
            case 0x188454u: goto label_188454;
            case 0x18848Cu: goto label_18848c;
            case 0x1884A4u: goto label_1884a4;
            case 0x1884B0u: goto label_1884b0;
            case 0x1884C0u: goto label_1884c0;
            case 0x1884D4u: goto label_1884d4;
            case 0x1884FCu: goto label_1884fc;
            case 0x188508u: goto label_188508;
            case 0x188594u: goto label_188594;
            case 0x1885A8u: goto label_1885a8;
            case 0x1885BCu: goto label_1885bc;
            case 0x188630u: goto label_188630;
            case 0x188640u: goto label_188640;
            case 0x188654u: goto label_188654;
            case 0x188678u: goto label_188678;
            case 0x188684u: goto label_188684;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188538u;
    // 0x188538: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x188538u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18853c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x18853cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188540: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x188540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x188544: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x188544u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188548: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x188548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x18854c: 0x1488c0  sll         $s1, $s4, 3
    ctx->pc = 0x18854cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 20), 3));
    // 0x188550: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x188550u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x188554: 0x2453b8c8  addiu       $s3, $v0, -0x4738
    ctx->pc = 0x188554u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949064));
    // 0x188558: 0x2341023  subu        $v0, $s1, $s4
    ctx->pc = 0x188558u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
    // 0x18855c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x18855cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x188560: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x188560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x188564: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x188564u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188568: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x188568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x18856c: 0x26630004  addiu       $v1, $s3, 0x4
    ctx->pc = 0x18856cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x188570: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x188570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x188574: 0xc0f02d  daddu       $fp, $a2, $zero
    ctx->pc = 0x188574u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188578: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x18857c: 0x29080  sll         $s2, $v0, 2
    ctx->pc = 0x18857cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x188580: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x188580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x188584: 0x243b021  addu        $s6, $s2, $v1
    ctx->pc = 0x188584u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x188588: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x188588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x18858c: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x18858Cu;
    SET_GPR_U32(ctx, 31, 0x188594u);
    ctx->pc = 0x188590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18858Cu;
            // 0x188590: 0x8ec40000  lw          $a0, 0x0($s6) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188594u; }
        if (ctx->pc != 0x188594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188594u; }
        if (ctx->pc != 0x188594u) { return; }
    }
    ctx->pc = 0x188594u;
label_188594:
    // 0x188594: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x188594u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x188598: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x188598u;
    {
        const bool branch_taken_0x188598 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x18859Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188598u;
            // 0x18859c: 0x3c170029  lui         $s7, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188598) {
            ctx->pc = 0x1885A8u;
            goto label_1885a8;
        }
    }
    ctx->pc = 0x1885A0u;
    // 0x1885a0: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1885A0u;
    {
        const bool branch_taken_0x1885a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1885A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1885A0u;
            // 0x1885a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1885a0) {
            ctx->pc = 0x188684u;
            goto label_188684;
        }
    }
    ctx->pc = 0x1885A8u;
label_1885a8:
    // 0x1885a8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1885a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1885ac: 0x26f0b900  addiu       $s0, $s7, -0x4700
    ctx->pc = 0x1885acu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 4294949120));
    // 0x1885b0: 0x24062080  addiu       $a2, $zero, 0x2080
    ctx->pc = 0x1885b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x1885b4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1885B4u;
    SET_GPR_U32(ctx, 31, 0x1885BCu);
    ctx->pc = 0x1885B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1885B4u;
            // 0x1885b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1885BCu; }
        if (ctx->pc != 0x1885BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1885BCu; }
        if (ctx->pc != 0x1885BCu) { return; }
    }
    ctx->pc = 0x1885BCu;
label_1885bc:
    // 0x1885bc: 0xae150000  sw          $s5, 0x0($s0)
    ctx->pc = 0x1885bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 21));
    // 0x1885c0: 0x2723021  addu        $a2, $s3, $s2
    ctx->pc = 0x1885c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x1885c4: 0x3c120023  lui         $s2, 0x23
    ctx->pc = 0x1885c4u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
    // 0x1885c8: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x1885c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1885cc: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x1885ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x1885d0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1885d0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1885d4: 0x8c470008  lw          $a3, 0x8($v0)
    ctx->pc = 0x1885d4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1885d8: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1885d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1885dc: 0x8cc20014  lw          $v0, 0x14($a2)
    ctx->pc = 0x1885dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x1885e0: 0x8c68000c  lw          $t0, 0xC($v1)
    ctx->pc = 0x1885e0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1885e4: 0x2484d980  addiu       $a0, $a0, -0x2680
    ctx->pc = 0x1885e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957440));
    // 0x1885e8: 0x8ca30010  lw          $v1, 0x10($a1)
    ctx->pc = 0x1885e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x1885ec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1885ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1885f0: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x1885f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x1885f4: 0x24022080  addiu       $v0, $zero, 0x2080
    ctx->pc = 0x1885f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8320));
    // 0x1885f8: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1885f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1885fc: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1885fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x188600: 0xae070008  sw          $a3, 0x8($s0)
    ctx->pc = 0x188600u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
    // 0x188604: 0x2c0982d  daddu       $s3, $s6, $zero
    ctx->pc = 0x188604u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188608: 0xae08000c  sw          $t0, 0xC($s0)
    ctx->pc = 0x188608u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 8));
    // 0x18860c: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x18860cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188610: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x188610u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x188614: 0x3c160018  lui         $s6, 0x18
    ctx->pc = 0x188614u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)24 << 16));
    // 0x188618: 0xae1e0004  sw          $fp, 0x4($s0)
    ctx->pc = 0x188618u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 30));
    // 0x18861c: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x18861cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x188620: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x188620u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x188624: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x188624u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x188628: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x188628u;
    SET_GPR_U32(ctx, 31, 0x188630u);
    ctx->pc = 0x18862Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188628u;
            // 0x18862c: 0xae000020  sw          $zero, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188630u; }
        if (ctx->pc != 0x188630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188630u; }
        if (ctx->pc != 0x188630u) { return; }
    }
    ctx->pc = 0x188630u;
label_188630:
    // 0x188630: 0x2403000b  addiu       $v1, $zero, 0xB
    ctx->pc = 0x188630u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x188634: 0xae43fd24  sw          $v1, -0x2DC($s2)
    ctx->pc = 0x188634u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294966564), GPR_U32(ctx, 3));
    // 0x188638: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x188638u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x18863c: 0x0  nop
    ctx->pc = 0x18863cu;
    // NOP
label_188640:
    // 0x188640: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x188640u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188644: 0x8e45fd24  lw          $a1, -0x2DC($s2)
    ctx->pc = 0x188644u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294966564)));
    // 0x188648: 0x26e7b900  addiu       $a3, $s7, -0x4700
    ctx->pc = 0x188648u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), 4294949120));
    // 0x18864c: 0xc062560  jal         func_189580
    ctx->pc = 0x18864Cu;
    SET_GPR_U32(ctx, 31, 0x188654u);
    ctx->pc = 0x188650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18864Cu;
            // 0x188650: 0x26c87808  addiu       $t0, $s6, 0x7808 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 22), 30728));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189580u;
    if (runtime->hasFunction(0x189580u)) {
        auto targetFn = runtime->lookupFunction(0x189580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188654u; }
        if (ctx->pc != 0x188654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188654u; }
        if (ctx->pc != 0x188654u) { return; }
    }
    ctx->pc = 0x188654u;
label_188654:
    // 0x188654: 0x5455fffa  bnel        $v0, $s5, . + 4 + (-0x6 << 2)
    ctx->pc = 0x188654u;
    {
        const bool branch_taken_0x188654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 21));
        if (branch_taken_0x188654) {
            ctx->pc = 0x188658u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x188654u;
            // 0x188658: 0x8e640000  lw          $a0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x188640u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188640;
        }
    }
    ctx->pc = 0x18865Cu;
    // 0x18865c: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18865cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x188660: 0x2341023  subu        $v0, $s1, $s4
    ctx->pc = 0x188660u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
    // 0x188664: 0x2483b8c8  addiu       $v1, $a0, -0x4738
    ctx->pc = 0x188664u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949064));
    // 0x188668: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x188668u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18866c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x18866cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x188670: 0xc061db2  jal         func_1876C8
    ctx->pc = 0x188670u;
    SET_GPR_U32(ctx, 31, 0x188678u);
    ctx->pc = 0x188674u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188670u;
            // 0x188674: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1876C8u;
    if (runtime->hasFunction(0x1876C8u)) {
        auto targetFn = runtime->lookupFunction(0x1876C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188678u; }
        if (ctx->pc != 0x188678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188678u; }
        if (ctx->pc != 0x188678u) { return; }
    }
    ctx->pc = 0x188678u;
label_188678:
    // 0x188678: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x188678u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x18867c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18867cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188680: 0x3c3100b  movn        $v0, $fp, $v1
    ctx->pc = 0x188680u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 30));
label_188684:
    // 0x188684: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x188684u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x188688: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x188688u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x18868c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x18868cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188690: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x188690u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x188694: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x188694u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x188698: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x188698u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x18869c: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x18869cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1886a0: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x1886a0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1886a4: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x1886a4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1886a8: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x1886a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1886ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1886ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1886B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1886ACu;
            // 0x1886b0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1883ACu: goto label_1883ac;
            case 0x1883C0u: goto label_1883c0;
            case 0x1883E4u: goto label_1883e4;
            case 0x1883F0u: goto label_1883f0;
            case 0x188404u: goto label_188404;
            case 0x188454u: goto label_188454;
            case 0x18848Cu: goto label_18848c;
            case 0x1884A4u: goto label_1884a4;
            case 0x1884B0u: goto label_1884b0;
            case 0x1884C0u: goto label_1884c0;
            case 0x1884D4u: goto label_1884d4;
            case 0x1884FCu: goto label_1884fc;
            case 0x188508u: goto label_188508;
            case 0x188594u: goto label_188594;
            case 0x1885A8u: goto label_1885a8;
            case 0x1885BCu: goto label_1885bc;
            case 0x188630u: goto label_188630;
            case 0x188640u: goto label_188640;
            case 0x188654u: goto label_188654;
            case 0x188678u: goto label_188678;
            case 0x188684u: goto label_188684;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1886B4u;
    // 0x1886b4: 0x0  nop
    ctx->pc = 0x1886b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
