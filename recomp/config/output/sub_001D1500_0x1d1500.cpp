#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1500
// Address: 0x1d1500 - 0x1d16b8
void sub_001D1500_0x1d1500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1500_0x1d1500");
#endif

    switch (ctx->pc) {
        case 0x1d1570u: goto label_1d1570;
        case 0x1d15acu: goto label_1d15ac;
        case 0x1d1604u: goto label_1d1604;
        case 0x1d160cu: goto label_1d160c;
        case 0x1d163cu: goto label_1d163c;
        default: break;
    }

    ctx->pc = 0x1d1500u;

    // 0x1d1500: 0x27bdfee0  addiu       $sp, $sp, -0x120
    ctx->pc = 0x1d1500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x1d1504: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1504u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1508: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1d1508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1d150c: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1d150cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1d1510: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1d1510u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1d1514: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1d1514u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d1518: 0x120b82d  daddu       $s7, $t1, $zero
    ctx->pc = 0x1d1518u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d151c: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d151cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d1520: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1d1520u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1524: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d1524u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d1528: 0x2405ffc0  addiu       $a1, $zero, -0x40
    ctx->pc = 0x1d1528u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1d152c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d152cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d1530: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1d1530u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1534: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d1534u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1538: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1538u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d153c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d153cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1540: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d1540u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1544: 0xafa600fc  sw          $a2, 0xFC($sp)
    ctx->pc = 0x1d1544u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 252), GPR_U32(ctx, 6));
    // 0x1d1548: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x1d1548u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d154c: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x1d154cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1d1550: 0x8c26440c  lw          $a2, 0x440C($at)
    ctx->pc = 0x1d1550u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1554: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d1554u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d1558: 0xafa300d0  sw          $v1, 0xD0($sp)
    ctx->pc = 0x1d1558u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 3));
    // 0x1d155c: 0xc81821  addu        $v1, $a2, $t0
    ctx->pc = 0x1d155cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1d1560: 0x2463003f  addiu       $v1, $v1, 0x3F
    ctx->pc = 0x1d1560u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
    // 0x1d1564: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1d1564u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1d1568: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1D1568u;
    {
        const bool branch_taken_0x1d1568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D156Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1568u;
            // 0x1d156c: 0xafa300c0  sw          $v1, 0xC0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1568) {
            ctx->pc = 0x1D1678u;
            goto label_1d1678;
        }
    }
    ctx->pc = 0x1D1570u;
label_1d1570:
    // 0x1d1570: 0x8fa300d0  lw          $v1, 0xD0($sp)
    ctx->pc = 0x1d1570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1d1574: 0x203082b  sltu        $at, $s0, $v1
    ctx->pc = 0x1d1574u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1d1578: 0x10200043  beqz        $at, . + 4 + (0x43 << 2)
    ctx->pc = 0x1D1578u;
    {
        const bool branch_taken_0x1d1578 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1578) {
            ctx->pc = 0x1D1688u;
            goto label_1d1688;
        }
    }
    ctx->pc = 0x1D1580u;
    // 0x1d1580: 0x8e1e0000  lw          $fp, 0x0($s0)
    ctx->pc = 0x1d1580u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d1584: 0x13c0003a  beqz        $fp, . + 4 + (0x3A << 2)
    ctx->pc = 0x1D1584u;
    {
        const bool branch_taken_0x1d1584 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D1588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1584u;
            // 0x1d1588: 0x26830001  addiu       $v1, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1584) {
            ctx->pc = 0x1D1670u;
            goto label_1d1670;
        }
    }
    ctx->pc = 0x1D158Cu;
    // 0x1d158c: 0x8fa300fc  lw          $v1, 0xFC($sp)
    ctx->pc = 0x1d158cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 252)));
    // 0x1d1590: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d1590u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1594: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1d1594u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d1598: 0xafa300b0  sw          $v1, 0xB0($sp)
    ctx->pc = 0x1d1598u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 3));
    // 0x1d159c: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1d159cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1d15a0: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1d15a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1d15a4: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1D15A4u;
    {
        const bool branch_taken_0x1d15a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D15A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15A4u;
            // 0x1d15a8: 0xafa300e0  sw          $v1, 0xE0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 224), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d15a4) {
            ctx->pc = 0x1D165Cu;
            goto label_1d165c;
        }
    }
    ctx->pc = 0x1D15ACu;
label_1d15ac:
    // 0x1d15ac: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d15acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d15b0: 0x32880  sll         $a1, $v1, 2
    ctx->pc = 0x1d15b0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d15b4: 0x8fa300e0  lw          $v1, 0xE0($sp)
    ctx->pc = 0x1d15b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x1d15b8: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1d15b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1d15bc: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d15bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d15c0: 0x10640024  beq         $v1, $a0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1D15C0u;
    {
        const bool branch_taken_0x1d15c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1D15C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15C0u;
            // 0x1d15c4: 0x223a821  addu        $s5, $s1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d15c0) {
            ctx->pc = 0x1D1654u;
            goto label_1d1654;
        }
    }
    ctx->pc = 0x1D15C8u;
    // 0x1d15c8: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x1d15c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1d15cc: 0x14640009  bne         $v1, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D15CCu;
    {
        const bool branch_taken_0x1d15cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1d15cc) {
            ctx->pc = 0x1D15F4u;
            goto label_1d15f4;
        }
    }
    ctx->pc = 0x1D15D4u;
    // 0x1d15d4: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x1d15d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1d15d8: 0x8ea40004  lw          $a0, 0x4($s5)
    ctx->pc = 0x1d15d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4)));
    // 0x1d15dc: 0x2431821  addu        $v1, $s2, $v1
    ctx->pc = 0x1d15dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1d15e0: 0x2e31821  addu        $v1, $s7, $v1
    ctx->pc = 0x1d15e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
    // 0x1d15e4: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1d15e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d15e8: 0x2c31821  addu        $v1, $s6, $v1
    ctx->pc = 0x1d15e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
    // 0x1d15ec: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1D15ECu;
    {
        const bool branch_taken_0x1d15ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D15F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15ECu;
            // 0x1d15f0: 0xa4640004  sh          $a0, 0x4($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d15ec) {
            ctx->pc = 0x1D1654u;
            goto label_1d1654;
        }
    }
    ctx->pc = 0x1D15F4u;
label_1d15f4:
    // 0x1d15f4: 0x8fa500c0  lw          $a1, 0xC0($sp)
    ctx->pc = 0x1d15f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1d15f8: 0x27a40100  addiu       $a0, $sp, 0x100
    ctx->pc = 0x1d15f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x1d15fc: 0xc074d54  jal         func_1D3550
    ctx->pc = 0x1D15FCu;
    SET_GPR_U32(ctx, 31, 0x1D1604u);
    ctx->pc = 0x1D1600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D15FCu;
            // 0x1d1600: 0x2a0302d  daddu       $a2, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3550u;
    if (runtime->hasFunction(0x1D3550u)) {
        auto targetFn = runtime->lookupFunction(0x1D3550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1604u; }
        if (ctx->pc != 0x1D1604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3550_0x1d3550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1604u; }
        if (ctx->pc != 0x1D1604u) { return; }
    }
    ctx->pc = 0x1D1604u;
label_1d1604:
    // 0x1d1604: 0xc064940  jal         func_192500
    ctx->pc = 0x1D1604u;
    SET_GPR_U32(ctx, 31, 0x1D160Cu);
    ctx->pc = 0x1D1608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1604u;
            // 0x1d1608: 0x27a40100  addiu       $a0, $sp, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192500u;
    if (runtime->hasFunction(0x192500u)) {
        auto targetFn = runtime->lookupFunction(0x192500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D160Cu; }
        if (ctx->pc != 0x1D160Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192500_0x192500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D160Cu; }
        if (ctx->pc != 0x1D160Cu) { return; }
    }
    ctx->pc = 0x1D160Cu;
label_1d160c:
    // 0x1d160c: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x1d160cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1d1610: 0x2431821  addu        $v1, $s2, $v1
    ctx->pc = 0x1d1610u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1d1614: 0x2e31821  addu        $v1, $s7, $v1
    ctx->pc = 0x1d1614u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
    // 0x1d1618: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1d1618u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1d161c: 0x2c32021  addu        $a0, $s6, $v1
    ctx->pc = 0x1d161cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
    // 0x1d1620: 0x24830004  addiu       $v1, $a0, 0x4
    ctx->pc = 0x1d1620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1d1624: 0xafa300a0  sw          $v1, 0xA0($sp)
    ctx->pc = 0x1d1624u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 3));
    // 0x1d1628: 0x94830004  lhu         $v1, 0x4($a0)
    ctx->pc = 0x1d1628u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d162c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D162Cu;
    {
        const bool branch_taken_0x1d162c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D1630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D162Cu;
            // 0x1d1630: 0x3052ffff  andi        $s2, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d162c) {
            ctx->pc = 0x1D163Cu;
            goto label_1d163c;
        }
    }
    ctx->pc = 0x1D1634u;
    // 0x1d1634: 0xc064968  jal         func_1925A0
    ctx->pc = 0x1D1634u;
    SET_GPR_U32(ctx, 31, 0x1D163Cu);
    ctx->pc = 0x1D1638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1634u;
            // 0x1d1638: 0x3064ffff  andi        $a0, $v1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1925A0u;
    if (runtime->hasFunction(0x1925A0u)) {
        auto targetFn = runtime->lookupFunction(0x1925A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D163Cu; }
        if (ctx->pc != 0x1D163Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001925A0_0x1925a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D163Cu; }
        if (ctx->pc != 0x1D163Cu) { return; }
    }
    ctx->pc = 0x1D163Cu;
label_1d163c:
    // 0x1d163c: 0x8fa300a0  lw          $v1, 0xA0($sp)
    ctx->pc = 0x1d163cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1d1640: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d1640u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d1644: 0xa4720000  sh          $s2, 0x0($v1)
    ctx->pc = 0x1d1644u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 18));
    // 0x1d1648: 0x3243ffff  andi        $v1, $s2, 0xFFFF
    ctx->pc = 0x1d1648u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d164c: 0xaea40000  sw          $a0, 0x0($s5)
    ctx->pc = 0x1d164cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 4));
    // 0x1d1650: 0xaea30004  sw          $v1, 0x4($s5)
    ctx->pc = 0x1d1650u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 3));
label_1d1654:
    // 0x1d1654: 0x26630001  addiu       $v1, $s3, 0x1
    ctx->pc = 0x1d1654u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d1658: 0x3073ffff  andi        $s3, $v1, 0xFFFF
    ctx->pc = 0x1d1658u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_1d165c:
    // 0x1d165c: 0x3272ffff  andi        $s2, $s3, 0xFFFF
    ctx->pc = 0x1d165cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1d1660: 0x25e182b  sltu        $v1, $s2, $fp
    ctx->pc = 0x1d1660u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 30)) ? 1 : 0);
    // 0x1d1664: 0x1460ffd1  bnez        $v1, . + 4 + (-0x2F << 2)
    ctx->pc = 0x1D1664u;
    {
        const bool branch_taken_0x1d1664 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D1668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1664u;
            // 0x1d1668: 0x3263ffff  andi        $v1, $s3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1664) {
            ctx->pc = 0x1D15ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d15ac;
        }
    }
    ctx->pc = 0x1D166Cu;
    // 0x1d166c: 0x26830001  addiu       $v1, $s4, 0x1
    ctx->pc = 0x1d166cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_1d1670:
    // 0x1d1670: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x1d1670u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1d1674: 0x3074ffff  andi        $s4, $v1, 0xFFFF
    ctx->pc = 0x1d1674u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_1d1678:
    // 0x1d1678: 0x3284ffff  andi        $a0, $s4, 0xFFFF
    ctx->pc = 0x1d1678u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)65535);
    // 0x1d167c: 0x28830008  slti        $v1, $a0, 0x8
    ctx->pc = 0x1d167cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1d1680: 0x1460ffbb  bnez        $v1, . + 4 + (-0x45 << 2)
    ctx->pc = 0x1D1680u;
    {
        const bool branch_taken_0x1d1680 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d1680) {
            ctx->pc = 0x1D1570u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d1570;
        }
    }
    ctx->pc = 0x1D1688u;
label_1d1688:
    // 0x1d1688: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1d1688u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1d168c: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1d168cu;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1d1690: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1d1690u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1d1694: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1d1694u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d1698: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d1698u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d169c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d169cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d16a0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d16a0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d16a4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d16a4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d16a8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d16a8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d16ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d16acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d16b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D16B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D16B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D16B0u;
            // 0x1d16b4: 0x27bd0120  addiu       $sp, $sp, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 288));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1570u: goto label_1d1570;
            case 0x1D15ACu: goto label_1d15ac;
            case 0x1D15F4u: goto label_1d15f4;
            case 0x1D1604u: goto label_1d1604;
            case 0x1D160Cu: goto label_1d160c;
            case 0x1D163Cu: goto label_1d163c;
            case 0x1D1654u: goto label_1d1654;
            case 0x1D165Cu: goto label_1d165c;
            case 0x1D1670u: goto label_1d1670;
            case 0x1D1678u: goto label_1d1678;
            case 0x1D1688u: goto label_1d1688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D16B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
