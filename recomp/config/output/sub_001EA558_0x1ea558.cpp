#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EA558
// Address: 0x1ea558 - 0x1eaa1c
void sub_001EA558_0x1ea558(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EA558_0x1ea558");
#endif

    switch (ctx->pc) {
        case 0x1ea590u: goto label_1ea590;
        case 0x1ea5b8u: goto label_1ea5b8;
        case 0x1ea728u: goto label_1ea728;
        case 0x1ea750u: goto label_1ea750;
        case 0x1ea768u: goto label_1ea768;
        case 0x1ea778u: goto label_1ea778;
        case 0x1ea78cu: goto label_1ea78c;
        case 0x1ea79cu: goto label_1ea79c;
        case 0x1ea7c4u: goto label_1ea7c4;
        case 0x1ea934u: goto label_1ea934;
        case 0x1ea95cu: goto label_1ea95c;
        case 0x1ea974u: goto label_1ea974;
        case 0x1ea988u: goto label_1ea988;
        case 0x1ea9a0u: goto label_1ea9a0;
        case 0x1ea9b0u: goto label_1ea9b0;
        case 0x1ea9d4u: goto label_1ea9d4;
        case 0x1ea9e8u: goto label_1ea9e8;
        case 0x1eaa00u: goto label_1eaa00;
        default: break;
    }

    ctx->pc = 0x1ea558u;

    // 0x1ea558: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1ea558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1ea55c: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x1ea55cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x1ea560: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x1ea560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x1ea564: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1ea564u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea568: 0x27c30050  addiu       $v1, $fp, 0x50
    ctx->pc = 0x1ea568u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 80));
    // 0x1ea56c: 0x27828058  addiu       $v0, $gp, -0x7FA8
    ctx->pc = 0x1ea56cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934616));
    // 0x1ea570: 0x68440007  ldl         $a0, 0x7($v0)
    ctx->pc = 0x1ea570u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1ea574: 0x6c440000  ldr         $a0, 0x0($v0)
    ctx->pc = 0x1ea574u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1ea578: 0xb0640007  sdl         $a0, 0x7($v1)
    ctx->pc = 0x1ea578u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1ea57c: 0xb4640000  sdr         $a0, 0x0($v1)
    ctx->pc = 0x1ea57cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1ea580: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1ea580u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1ea584: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea584u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea588: 0xc040742  jal         func_101D08
    ctx->pc = 0x1EA588u;
    SET_GPR_U32(ctx, 31, 0x1EA590u);
    ctx->pc = 0x101D08u;
    if (runtime->hasFunction(0x101D08u)) {
        auto targetFn = runtime->lookupFunction(0x101D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA590u; }
        if (ctx->pc != 0x1EA590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101D08_0x101d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA590u; }
        if (ctx->pc != 0x1EA590u) { return; }
    }
    ctx->pc = 0x1EA590u;
label_1ea590:
    // 0x1ea590: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x1ea590u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ea594: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1ea594u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ea598: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1EA598u;
    {
        const bool branch_taken_0x1ea598 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ea598) {
            ctx->pc = 0x1EA5C4u;
            goto label_1ea5c4;
        }
    }
    ctx->pc = 0x1EA5A0u;
    // 0x1ea5a0: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1ea5a0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ea5a4: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea5a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea5a8: 0x248480e8  addiu       $a0, $a0, -0x7F18
    ctx->pc = 0x1ea5a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934760));
    // 0x1ea5ac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1ea5acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea5b0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA5B0u;
    SET_GPR_U32(ctx, 31, 0x1EA5B8u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA5B8u; }
        if (ctx->pc != 0x1EA5B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA5B8u; }
        if (ctx->pc != 0x1EA5B8u) { return; }
    }
    ctx->pc = 0x1EA5B8u;
label_1ea5b8:
    // 0x1ea5b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ea5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ea5bc: 0x10000111  b           . + 4 + (0x111 << 2)
    ctx->pc = 0x1EA5BCu;
    {
        const bool branch_taken_0x1ea5bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ea5bc) {
            ctx->pc = 0x1EAA04u;
            goto label_1eaa04;
        }
    }
    ctx->pc = 0x1EA5C4u;
label_1ea5c4:
    // 0x1ea5c4: 0x93c20017  lbu         $v0, 0x17($fp)
    ctx->pc = 0x1ea5c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 23)));
    // 0x1ea5c8: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea5cc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea5ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea5d0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea5d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea5d4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea5d8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea5d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea5dc: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea5e0: 0x93c20017  lbu         $v0, 0x17($fp)
    ctx->pc = 0x1ea5e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 23)));
    // 0x1ea5e4: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea5e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea5e8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea5e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea5ec: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea5f0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ea5f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ea5f4: 0x93c20016  lbu         $v0, 0x16($fp)
    ctx->pc = 0x1ea5f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 22)));
    // 0x1ea5f8: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea5fc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea5fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea600: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea600u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea604: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea604u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea608: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea608u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea60c: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea60cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea610: 0x93c20016  lbu         $v0, 0x16($fp)
    ctx->pc = 0x1ea610u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 22)));
    // 0x1ea614: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea618: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea618u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea61c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea61cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea620: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ea620u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ea624: 0x93c20015  lbu         $v0, 0x15($fp)
    ctx->pc = 0x1ea624u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 21)));
    // 0x1ea628: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea628u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea62c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea62cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea630: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea630u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea634: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea634u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea638: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea63c: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea63cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea640: 0x93c20015  lbu         $v0, 0x15($fp)
    ctx->pc = 0x1ea640u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 21)));
    // 0x1ea644: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea648: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea648u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea64c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea64cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea650: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ea650u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ea654: 0x93c20013  lbu         $v0, 0x13($fp)
    ctx->pc = 0x1ea654u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 19)));
    // 0x1ea658: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea658u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea65c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea65cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea660: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea660u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea664: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea664u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea668: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea66c: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea66cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea670: 0x93c20013  lbu         $v0, 0x13($fp)
    ctx->pc = 0x1ea670u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 19)));
    // 0x1ea674: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea674u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea678: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea67c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea67cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea680: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ea680u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ea684: 0x93c20012  lbu         $v0, 0x12($fp)
    ctx->pc = 0x1ea684u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 18)));
    // 0x1ea688: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea688u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea68c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea68cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea690: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea690u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea694: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea694u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea698: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea69c: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea69cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea6a0: 0x93c20012  lbu         $v0, 0x12($fp)
    ctx->pc = 0x1ea6a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 18)));
    // 0x1ea6a4: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea6a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea6a8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea6a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea6ac: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea6acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea6b0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ea6b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ea6b4: 0x93c20011  lbu         $v0, 0x11($fp)
    ctx->pc = 0x1ea6b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 17)));
    // 0x1ea6b8: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea6bc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea6bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea6c0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea6c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea6c4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea6c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea6c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea6c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea6cc: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea6ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea6d0: 0x93c20011  lbu         $v0, 0x11($fp)
    ctx->pc = 0x1ea6d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 17)));
    // 0x1ea6d4: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea6d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea6d8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea6d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea6dc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea6e0: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ea6e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ea6e4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ea6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea6e8: 0x2c420046  sltiu       $v0, $v0, 0x46
    ctx->pc = 0x1ea6e8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)70) ? 1 : 0);
    // 0x1ea6ec: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1EA6ECu;
    {
        const bool branch_taken_0x1ea6ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ea6ec) {
            ctx->pc = 0x1EA708u;
            goto label_1ea708;
        }
    }
    ctx->pc = 0x1EA6F4u;
    // 0x1ea6f4: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ea6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea6f8: 0x244207d0  addiu       $v0, $v0, 0x7D0
    ctx->pc = 0x1ea6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2000));
    // 0x1ea6fc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ea6fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ea700: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1EA700u;
    {
        const bool branch_taken_0x1ea700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ea700) {
            ctx->pc = 0x1EA714u;
            goto label_1ea714;
        }
    }
    ctx->pc = 0x1EA708u;
label_1ea708:
    // 0x1ea708: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ea708u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea70c: 0x2442076c  addiu       $v0, $v0, 0x76C
    ctx->pc = 0x1ea70cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1900));
    // 0x1ea710: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ea710u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_1ea714:
    // 0x1ea714: 0x27c20040  addiu       $v0, $fp, 0x40
    ctx->pc = 0x1ea714u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 64));
    // 0x1ea718: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea718u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea71c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ea71cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea720: 0xc07a80b  jal         func_1EA02C
    ctx->pc = 0x1EA720u;
    SET_GPR_U32(ctx, 31, 0x1EA728u);
    ctx->pc = 0x1EA02Cu;
    if (runtime->hasFunction(0x1EA02Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EA02Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA728u; }
        if (ctx->pc != 0x1EA728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EA02C_0x1ea02c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA728u; }
        if (ctx->pc != 0x1EA728u) { return; }
    }
    ctx->pc = 0x1EA728u;
label_1ea728:
    // 0x1ea728: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea728u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea72c: 0x24848100  addiu       $a0, $a0, -0x7F00
    ctx->pc = 0x1ea72cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934784));
    // 0x1ea730: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1ea730u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea734: 0x8fc60024  lw          $a2, 0x24($fp)
    ctx->pc = 0x1ea734u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ea738: 0x8fc70028  lw          $a3, 0x28($fp)
    ctx->pc = 0x1ea738u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ea73c: 0x8fc8002c  lw          $t0, 0x2C($fp)
    ctx->pc = 0x1ea73cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ea740: 0x8fc90030  lw          $t1, 0x30($fp)
    ctx->pc = 0x1ea740u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ea744: 0x8fca0034  lw          $t2, 0x34($fp)
    ctx->pc = 0x1ea744u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ea748: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA748u;
    SET_GPR_U32(ctx, 31, 0x1EA750u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA750u; }
        if (ctx->pc != 0x1EA750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA750u; }
        if (ctx->pc != 0x1EA750u) { return; }
    }
    ctx->pc = 0x1EA750u;
label_1ea750:
    // 0x1ea750: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea750u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea754: 0x24848130  addiu       $a0, $a0, -0x7ED0
    ctx->pc = 0x1ea754u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934832));
    // 0x1ea758: 0xdfc50040  ld          $a1, 0x40($fp)
    ctx->pc = 0x1ea758u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ea75c: 0xdfc60048  ld          $a2, 0x48($fp)
    ctx->pc = 0x1ea75cu;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1ea760: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA760u;
    SET_GPR_U32(ctx, 31, 0x1EA768u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA768u; }
        if (ctx->pc != 0x1EA768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA768u; }
        if (ctx->pc != 0x1EA768u) { return; }
    }
    ctx->pc = 0x1EA768u;
label_1ea768:
    // 0x1ea768: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea768u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea76c: 0x24848148  addiu       $a0, $a0, -0x7EB8
    ctx->pc = 0x1ea76cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934856));
    // 0x1ea770: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA770u;
    SET_GPR_U32(ctx, 31, 0x1EA778u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA778u; }
        if (ctx->pc != 0x1EA778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA778u; }
        if (ctx->pc != 0x1EA778u) { return; }
    }
    ctx->pc = 0x1EA778u;
label_1ea778:
    // 0x1ea778: 0x27c20050  addiu       $v0, $fp, 0x50
    ctx->pc = 0x1ea778u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 80));
    // 0x1ea77c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea77cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea780: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ea780u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea784: 0xc079fb4  jal         func_1E7ED0
    ctx->pc = 0x1EA784u;
    SET_GPR_U32(ctx, 31, 0x1EA78Cu);
    ctx->pc = 0x1E7ED0u;
    if (runtime->hasFunction(0x1E7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1E7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA78Cu; }
        if (ctx->pc != 0x1EA78Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7ED0_0x1e7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA78Cu; }
        if (ctx->pc != 0x1EA78Cu) { return; }
    }
    ctx->pc = 0x1EA78Cu;
label_1ea78c:
    // 0x1ea78c: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1ea78cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1ea790: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea790u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea794: 0xc040742  jal         func_101D08
    ctx->pc = 0x1EA794u;
    SET_GPR_U32(ctx, 31, 0x1EA79Cu);
    ctx->pc = 0x101D08u;
    if (runtime->hasFunction(0x101D08u)) {
        auto targetFn = runtime->lookupFunction(0x101D08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA79Cu; }
        if (ctx->pc != 0x1EA79Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101D08_0x101d08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA79Cu; }
        if (ctx->pc != 0x1EA79Cu) { return; }
    }
    ctx->pc = 0x1EA79Cu;
label_1ea79c:
    // 0x1ea79c: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x1ea79cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ea7a0: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1ea7a0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ea7a4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1EA7A4u;
    {
        const bool branch_taken_0x1ea7a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ea7a4) {
            ctx->pc = 0x1EA7D0u;
            goto label_1ea7d0;
        }
    }
    ctx->pc = 0x1EA7ACu;
    // 0x1ea7ac: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1ea7acu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1ea7b0: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea7b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea7b4: 0x248480e8  addiu       $a0, $a0, -0x7F18
    ctx->pc = 0x1ea7b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934760));
    // 0x1ea7b8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1ea7b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea7bc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA7BCu;
    SET_GPR_U32(ctx, 31, 0x1EA7C4u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA7C4u; }
        if (ctx->pc != 0x1EA7C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA7C4u; }
        if (ctx->pc != 0x1EA7C4u) { return; }
    }
    ctx->pc = 0x1EA7C4u;
label_1ea7c4:
    // 0x1ea7c4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ea7c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ea7c8: 0x1000008e  b           . + 4 + (0x8E << 2)
    ctx->pc = 0x1EA7C8u;
    {
        const bool branch_taken_0x1ea7c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ea7c8) {
            ctx->pc = 0x1EAA04u;
            goto label_1eaa04;
        }
    }
    ctx->pc = 0x1EA7D0u;
label_1ea7d0:
    // 0x1ea7d0: 0x93c20017  lbu         $v0, 0x17($fp)
    ctx->pc = 0x1ea7d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 23)));
    // 0x1ea7d4: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea7d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea7d8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea7d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea7dc: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea7dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea7e0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea7e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea7e4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea7e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea7e8: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea7e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea7ec: 0x93c20017  lbu         $v0, 0x17($fp)
    ctx->pc = 0x1ea7ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 23)));
    // 0x1ea7f0: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea7f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea7f4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea7f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea7f8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea7fc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ea7fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ea800: 0x93c20016  lbu         $v0, 0x16($fp)
    ctx->pc = 0x1ea800u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 22)));
    // 0x1ea804: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea804u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea808: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea808u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea80c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea80cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea810: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea810u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea814: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea814u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea818: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea818u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea81c: 0x93c20016  lbu         $v0, 0x16($fp)
    ctx->pc = 0x1ea81cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 22)));
    // 0x1ea820: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea820u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea824: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea824u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea828: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea828u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea82c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1ea82cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1ea830: 0x93c20015  lbu         $v0, 0x15($fp)
    ctx->pc = 0x1ea830u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 21)));
    // 0x1ea834: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea834u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea838: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea838u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea83c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea83cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea840: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea840u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea844: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea848: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea848u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea84c: 0x93c20015  lbu         $v0, 0x15($fp)
    ctx->pc = 0x1ea84cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 21)));
    // 0x1ea850: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea850u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea854: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea854u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea858: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea85c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1ea85cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1ea860: 0x93c20013  lbu         $v0, 0x13($fp)
    ctx->pc = 0x1ea860u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 19)));
    // 0x1ea864: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea864u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea868: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea868u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea86c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea86cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea870: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea870u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea874: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea878: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea878u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea87c: 0x93c20013  lbu         $v0, 0x13($fp)
    ctx->pc = 0x1ea87cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 19)));
    // 0x1ea880: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea880u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea884: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea884u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea888: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea888u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea88c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1ea88cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1ea890: 0x93c20012  lbu         $v0, 0x12($fp)
    ctx->pc = 0x1ea890u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 18)));
    // 0x1ea894: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea894u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea898: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea898u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea89c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea89cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea8a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea8a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea8a4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea8a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea8a8: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea8a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea8ac: 0x93c20012  lbu         $v0, 0x12($fp)
    ctx->pc = 0x1ea8acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 18)));
    // 0x1ea8b0: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea8b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea8b4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea8b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea8b8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea8bc: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1ea8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1ea8c0: 0x93c20011  lbu         $v0, 0x11($fp)
    ctx->pc = 0x1ea8c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 17)));
    // 0x1ea8c4: 0x21102  srl         $v0, $v0, 4
    ctx->pc = 0x1ea8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
    // 0x1ea8c8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1ea8c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea8cc: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1ea8ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea8d0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ea8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ea8d4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ea8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ea8d8: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x1ea8d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1ea8dc: 0x93c20011  lbu         $v0, 0x11($fp)
    ctx->pc = 0x1ea8dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 17)));
    // 0x1ea8e0: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1ea8e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1ea8e4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1ea8e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1ea8e8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1ea8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ea8ec: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1ea8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1ea8f0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ea8f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea8f4: 0x2c420046  sltiu       $v0, $v0, 0x46
    ctx->pc = 0x1ea8f4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)70) ? 1 : 0);
    // 0x1ea8f8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1EA8F8u;
    {
        const bool branch_taken_0x1ea8f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ea8f8) {
            ctx->pc = 0x1EA914u;
            goto label_1ea914;
        }
    }
    ctx->pc = 0x1EA900u;
    // 0x1ea900: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ea900u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea904: 0x244207d0  addiu       $v0, $v0, 0x7D0
    ctx->pc = 0x1ea904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2000));
    // 0x1ea908: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ea908u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1ea90c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1EA90Cu;
    {
        const bool branch_taken_0x1ea90c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ea90c) {
            ctx->pc = 0x1EA920u;
            goto label_1ea920;
        }
    }
    ctx->pc = 0x1EA914u;
label_1ea914:
    // 0x1ea914: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1ea914u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea918: 0x2442076c  addiu       $v0, $v0, 0x76C
    ctx->pc = 0x1ea918u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1900));
    // 0x1ea91c: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1ea91cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_1ea920:
    // 0x1ea920: 0x27c20040  addiu       $v0, $fp, 0x40
    ctx->pc = 0x1ea920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 64));
    // 0x1ea924: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea924u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea928: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ea928u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea92c: 0xc07a80b  jal         func_1EA02C
    ctx->pc = 0x1EA92Cu;
    SET_GPR_U32(ctx, 31, 0x1EA934u);
    ctx->pc = 0x1EA02Cu;
    if (runtime->hasFunction(0x1EA02Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EA02Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA934u; }
        if (ctx->pc != 0x1EA934u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EA02C_0x1ea02c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA934u; }
        if (ctx->pc != 0x1EA934u) { return; }
    }
    ctx->pc = 0x1EA934u;
label_1ea934:
    // 0x1ea934: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea934u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea938: 0x24848100  addiu       $a0, $a0, -0x7F00
    ctx->pc = 0x1ea938u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934784));
    // 0x1ea93c: 0x8fc50020  lw          $a1, 0x20($fp)
    ctx->pc = 0x1ea93cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ea940: 0x8fc60024  lw          $a2, 0x24($fp)
    ctx->pc = 0x1ea940u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1ea944: 0x8fc70028  lw          $a3, 0x28($fp)
    ctx->pc = 0x1ea944u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ea948: 0x8fc8002c  lw          $t0, 0x2C($fp)
    ctx->pc = 0x1ea948u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1ea94c: 0x8fc90030  lw          $t1, 0x30($fp)
    ctx->pc = 0x1ea94cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ea950: 0x8fca0034  lw          $t2, 0x34($fp)
    ctx->pc = 0x1ea950u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1ea954: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA954u;
    SET_GPR_U32(ctx, 31, 0x1EA95Cu);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA95Cu; }
        if (ctx->pc != 0x1EA95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA95Cu; }
        if (ctx->pc != 0x1EA95Cu) { return; }
    }
    ctx->pc = 0x1EA95Cu;
label_1ea95c:
    // 0x1ea95c: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea95cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea960: 0x24848130  addiu       $a0, $a0, -0x7ED0
    ctx->pc = 0x1ea960u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934832));
    // 0x1ea964: 0xdfc50040  ld          $a1, 0x40($fp)
    ctx->pc = 0x1ea964u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ea968: 0xdfc60048  ld          $a2, 0x48($fp)
    ctx->pc = 0x1ea968u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1ea96c: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA96Cu;
    SET_GPR_U32(ctx, 31, 0x1EA974u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA974u; }
        if (ctx->pc != 0x1EA974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA974u; }
        if (ctx->pc != 0x1EA974u) { return; }
    }
    ctx->pc = 0x1EA974u;
label_1ea974:
    // 0x1ea974: 0x27c20040  addiu       $v0, $fp, 0x40
    ctx->pc = 0x1ea974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 64));
    // 0x1ea978: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea978u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea97c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ea97cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea980: 0xc07a80b  jal         func_1EA02C
    ctx->pc = 0x1EA980u;
    SET_GPR_U32(ctx, 31, 0x1EA988u);
    ctx->pc = 0x1EA02Cu;
    if (runtime->hasFunction(0x1EA02Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EA02Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA988u; }
        if (ctx->pc != 0x1EA988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EA02C_0x1ea02c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA988u; }
        if (ctx->pc != 0x1EA988u) { return; }
    }
    ctx->pc = 0x1EA988u;
label_1ea988:
    // 0x1ea988: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea988u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea98c: 0x24848130  addiu       $a0, $a0, -0x7ED0
    ctx->pc = 0x1ea98cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934832));
    // 0x1ea990: 0xdfc50040  ld          $a1, 0x40($fp)
    ctx->pc = 0x1ea990u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ea994: 0xdfc60048  ld          $a2, 0x48($fp)
    ctx->pc = 0x1ea994u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1ea998: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA998u;
    SET_GPR_U32(ctx, 31, 0x1EA9A0u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9A0u; }
        if (ctx->pc != 0x1EA9A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9A0u; }
        if (ctx->pc != 0x1EA9A0u) { return; }
    }
    ctx->pc = 0x1EA9A0u;
label_1ea9a0:
    // 0x1ea9a0: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea9a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea9a4: 0x24848158  addiu       $a0, $a0, -0x7EA8
    ctx->pc = 0x1ea9a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934872));
    // 0x1ea9a8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA9A8u;
    SET_GPR_U32(ctx, 31, 0x1EA9B0u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9B0u; }
        if (ctx->pc != 0x1EA9B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9B0u; }
        if (ctx->pc != 0x1EA9B0u) { return; }
    }
    ctx->pc = 0x1EA9B0u;
label_1ea9b0:
    // 0x1ea9b0: 0xafc00050  sw          $zero, 0x50($fp)
    ctx->pc = 0x1ea9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 80), GPR_U32(ctx, 0));
    // 0x1ea9b4: 0x3c021dcd  lui         $v0, 0x1DCD
    ctx->pc = 0x1ea9b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)7629 << 16));
    // 0x1ea9b8: 0x34426500  ori         $v0, $v0, 0x6500
    ctx->pc = 0x1ea9b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)25856);
    // 0x1ea9bc: 0xafc20054  sw          $v0, 0x54($fp)
    ctx->pc = 0x1ea9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 84), GPR_U32(ctx, 2));
    // 0x1ea9c0: 0x27c20050  addiu       $v0, $fp, 0x50
    ctx->pc = 0x1ea9c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 80));
    // 0x1ea9c4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea9c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea9c8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ea9c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea9cc: 0xc079fb4  jal         func_1E7ED0
    ctx->pc = 0x1EA9CCu;
    SET_GPR_U32(ctx, 31, 0x1EA9D4u);
    ctx->pc = 0x1E7ED0u;
    if (runtime->hasFunction(0x1E7ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1E7ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9D4u; }
        if (ctx->pc != 0x1EA9D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7ED0_0x1e7ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9D4u; }
        if (ctx->pc != 0x1EA9D4u) { return; }
    }
    ctx->pc = 0x1EA9D4u;
label_1ea9d4:
    // 0x1ea9d4: 0x27c20040  addiu       $v0, $fp, 0x40
    ctx->pc = 0x1ea9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 64));
    // 0x1ea9d8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ea9d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea9dc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ea9dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ea9e0: 0xc07a80b  jal         func_1EA02C
    ctx->pc = 0x1EA9E0u;
    SET_GPR_U32(ctx, 31, 0x1EA9E8u);
    ctx->pc = 0x1EA02Cu;
    if (runtime->hasFunction(0x1EA02Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EA02Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9E8u; }
        if (ctx->pc != 0x1EA9E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EA02C_0x1ea02c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EA9E8u; }
        if (ctx->pc != 0x1EA9E8u) { return; }
    }
    ctx->pc = 0x1EA9E8u;
label_1ea9e8:
    // 0x1ea9e8: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1ea9e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1ea9ec: 0x24848130  addiu       $a0, $a0, -0x7ED0
    ctx->pc = 0x1ea9ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934832));
    // 0x1ea9f0: 0xdfc50040  ld          $a1, 0x40($fp)
    ctx->pc = 0x1ea9f0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1ea9f4: 0xdfc60048  ld          $a2, 0x48($fp)
    ctx->pc = 0x1ea9f4u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1ea9f8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1EA9F8u;
    SET_GPR_U32(ctx, 31, 0x1EAA00u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAA00u; }
        if (ctx->pc != 0x1EAA00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAA00u; }
        if (ctx->pc != 0x1EAA00u) { return; }
    }
    ctx->pc = 0x1EAA00u;
label_1eaa00:
    // 0x1eaa00: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1eaa00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1eaa04:
    // 0x1eaa04: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eaa04u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eaa08: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x1eaa08u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1eaa0c: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x1eaa0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1eaa10: 0x27bd0070  addiu       $sp, $sp, 0x70
    ctx->pc = 0x1eaa10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1eaa14: 0x3e00008  jr          $ra
    ctx->pc = 0x1EAA14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EA590u: goto label_1ea590;
            case 0x1EA5B8u: goto label_1ea5b8;
            case 0x1EA5C4u: goto label_1ea5c4;
            case 0x1EA708u: goto label_1ea708;
            case 0x1EA714u: goto label_1ea714;
            case 0x1EA728u: goto label_1ea728;
            case 0x1EA750u: goto label_1ea750;
            case 0x1EA768u: goto label_1ea768;
            case 0x1EA778u: goto label_1ea778;
            case 0x1EA78Cu: goto label_1ea78c;
            case 0x1EA79Cu: goto label_1ea79c;
            case 0x1EA7C4u: goto label_1ea7c4;
            case 0x1EA7D0u: goto label_1ea7d0;
            case 0x1EA914u: goto label_1ea914;
            case 0x1EA920u: goto label_1ea920;
            case 0x1EA934u: goto label_1ea934;
            case 0x1EA95Cu: goto label_1ea95c;
            case 0x1EA974u: goto label_1ea974;
            case 0x1EA988u: goto label_1ea988;
            case 0x1EA9A0u: goto label_1ea9a0;
            case 0x1EA9B0u: goto label_1ea9b0;
            case 0x1EA9D4u: goto label_1ea9d4;
            case 0x1EA9E8u: goto label_1ea9e8;
            case 0x1EAA00u: goto label_1eaa00;
            case 0x1EAA04u: goto label_1eaa04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EAA1Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
