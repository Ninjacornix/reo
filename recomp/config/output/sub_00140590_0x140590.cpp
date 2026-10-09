#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140590
// Address: 0x140590 - 0x1406d4
void sub_00140590_0x140590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140590_0x140590");
#endif

    switch (ctx->pc) {
        case 0x1405d0u: goto label_1405d0;
        case 0x1405f8u: goto label_1405f8;
        case 0x14066cu: goto label_14066c;
        default: break;
    }

    ctx->pc = 0x140590u;

    // 0x140590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x140594: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x140594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x140598: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x140598u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14059c: 0x2e420004  sltiu       $v0, $s2, 0x4
    ctx->pc = 0x14059cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1405a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1405a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1405a4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1405a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1405a8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1405a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1405ac: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1405acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1405b0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1405B0u;
    {
        const bool branch_taken_0x1405b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1405B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1405B0u;
            // 0x1405b4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1405b0) {
            ctx->pc = 0x1405D8u;
            goto label_1405d8;
        }
    }
    ctx->pc = 0x1405B8u;
    // 0x1405b8: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x1405b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1405bc: 0x50400040  beql        $v0, $zero, . + 4 + (0x40 << 2)
    ctx->pc = 0x1405BCu;
    {
        const bool branch_taken_0x1405bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1405bc) {
            ctx->pc = 0x1405C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1405BCu;
            // 0x1405c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405C4u;
    // 0x1405c4: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x1405c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1405c8: 0x40f809  jalr        $v0
    ctx->pc = 0x1405C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1405D0u);
        ctx->pc = 0x1405CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1405C8u;
            // 0x1405cc: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1405D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1405D0u; }
            if (ctx->pc != 0x1405D0u) { return; }
        }
        }
    }
    ctx->pc = 0x1405D0u;
label_1405d0:
    // 0x1405d0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1405D0u;
    {
        const bool branch_taken_0x1405d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1405D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1405D0u;
            // 0x1405d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1405d0) {
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405D8u;
label_1405d8:
    // 0x1405d8: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1405d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1405dc: 0x58400038  blezl       $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x1405DCu;
    {
        const bool branch_taken_0x1405dc = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1405dc) {
            ctx->pc = 0x1405E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1405DCu;
            // 0x1405e0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405E4u;
    // 0x1405e4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1405e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1405e8: 0x50400035  beql        $v0, $zero, . + 4 + (0x35 << 2)
    ctx->pc = 0x1405E8u;
    {
        const bool branch_taken_0x1405e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1405e8) {
            ctx->pc = 0x1405ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1405E8u;
            // 0x1405ec: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406C0u;
            goto label_1406c0;
        }
    }
    ctx->pc = 0x1405F0u;
    // 0x1405f0: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x1405F0u;
    SET_GPR_U32(ctx, 31, 0x1405F8u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1405F8u; }
        if (ctx->pc != 0x1405F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1405F8u; }
        if (ctx->pc != 0x1405F8u) { return; }
    }
    ctx->pc = 0x1405F8u;
label_1405f8:
    // 0x1405f8: 0x122880  sll         $a1, $s2, 2
    ctx->pc = 0x1405f8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1405fc: 0x26080008  addiu       $t0, $s0, 0x8
    ctx->pc = 0x1405fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x140600: 0x82020005  lb          $v0, 0x5($s0)
    ctx->pc = 0x140600u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x140604: 0xa81821  addu        $v1, $a1, $t0
    ctx->pc = 0x140604u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x140608: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x140608u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14060c: 0x1444000e  bne         $v0, $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x14060Cu;
    {
        const bool branch_taken_0x14060c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x140610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14060Cu;
            // 0x140610: 0x8c660010  lw          $a2, 0x10($v1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14060c) {
            ctx->pc = 0x140648u;
            goto label_140648;
        }
    }
    ctx->pc = 0x140614u;
    // 0x140614: 0x50c0000d  beql        $a2, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x140614u;
    {
        const bool branch_taken_0x140614 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x140614) {
            ctx->pc = 0x140618u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140614u;
            // 0x140618: 0x8e060014  lw          $a2, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14064Cu;
            goto label_14064c;
        }
    }
    ctx->pc = 0x14061Cu;
    // 0x14061c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x14061cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x140620: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x140620u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x140624: 0x8cc30008  lw          $v1, 0x8($a2)
    ctx->pc = 0x140624u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x140628: 0x871021  addu        $v0, $a0, $a3
    ctx->pc = 0x140628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x14062c: 0x54430007  bnel        $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x14062Cu;
    {
        const bool branch_taken_0x14062c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x14062c) {
            ctx->pc = 0x140630u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14062Cu;
            // 0x140630: 0x8e060014  lw          $a2, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14064Cu;
            goto label_14064c;
        }
    }
    ctx->pc = 0x140634u;
    // 0x140634: 0x8cc2000c  lw          $v0, 0xC($a2)
    ctx->pc = 0x140634u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x140638: 0xacc40008  sw          $a0, 0x8($a2)
    ctx->pc = 0x140638u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 4));
    // 0x14063c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x14063cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x140640: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x140640u;
    {
        const bool branch_taken_0x140640 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140640u;
            // 0x140644: 0xacc2000c  sw          $v0, 0xC($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140640) {
            ctx->pc = 0x1406A4u;
            goto label_1406a4;
        }
    }
    ctx->pc = 0x140648u;
label_140648:
    // 0x140648: 0x8e060014  lw          $a2, 0x14($s0)
    ctx->pc = 0x140648u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_14064c:
    // 0x14064c: 0x54c0000a  bnel        $a2, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x14064Cu;
    {
        const bool branch_taken_0x14064c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x14064c) {
            ctx->pc = 0x140650u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14064Cu;
            // 0x140650: 0x8cc20000  lw          $v0, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140678u;
            goto label_140678;
        }
    }
    ctx->pc = 0x140654u;
    // 0x140654: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140658: 0x50400013  beql        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x140658u;
    {
        const bool branch_taken_0x140658 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140658) {
            ctx->pc = 0x14065Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140658u;
            // 0x14065c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1406A8u;
            goto label_1406a8;
        }
    }
    ctx->pc = 0x140660u;
    // 0x140660: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x140660u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140664: 0x40f809  jalr        $v0
    ctx->pc = 0x140664u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x14066Cu);
        ctx->pc = 0x140668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140664u;
            // 0x140668: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x14066Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x14066Cu; }
            if (ctx->pc != 0x14066Cu) { return; }
        }
        }
    }
    ctx->pc = 0x14066Cu;
label_14066c:
    // 0x14066c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x14066Cu;
    {
        const bool branch_taken_0x14066c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14066Cu;
            // 0x140670: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14066c) {
            ctx->pc = 0x1406A8u;
            goto label_1406a8;
        }
    }
    ctx->pc = 0x140674u;
    // 0x140674: 0x0  nop
    ctx->pc = 0x140674u;
    // NOP
label_140678:
    // 0x140678: 0x24a30010  addiu       $v1, $a1, 0x10
    ctx->pc = 0x140678u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x14067c: 0x1031821  addu        $v1, $t0, $v1
    ctx->pc = 0x14067cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x140680: 0x6a240007  ldl         $a0, 0x7($s1)
    ctx->pc = 0x140680u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x140684: 0x6e240000  ldr         $a0, 0x0($s1)
    ctx->pc = 0x140684u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x140688: 0xb0c4000f  sdl         $a0, 0xF($a2)
    ctx->pc = 0x140688u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14068c: 0xb4c40008  sdr         $a0, 0x8($a2)
    ctx->pc = 0x14068cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140690: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x140690u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x140694: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x140694u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x140698: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x140698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14069c: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x14069cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x1406a0: 0xac660000  sw          $a2, 0x0($v1)
    ctx->pc = 0x1406a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6));
label_1406a4:
    // 0x1406a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1406a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1406a8:
    // 0x1406a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1406a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1406ac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1406acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1406b0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1406b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1406b4: 0x804fc9c  j           func_13F270
    ctx->pc = 0x1406B4u;
    ctx->pc = 0x1406B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1406B4u;
            // 0x1406b8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1406BCu;
    // 0x1406bc: 0x0  nop
    ctx->pc = 0x1406bcu;
    // NOP
label_1406c0:
    // 0x1406c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1406c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1406c4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1406c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1406c8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1406c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1406cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1406CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1406D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1406CCu;
            // 0x1406d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1405D0u: goto label_1405d0;
            case 0x1405D8u: goto label_1405d8;
            case 0x1405F8u: goto label_1405f8;
            case 0x140648u: goto label_140648;
            case 0x14064Cu: goto label_14064c;
            case 0x14066Cu: goto label_14066c;
            case 0x140678u: goto label_140678;
            case 0x1406A4u: goto label_1406a4;
            case 0x1406A8u: goto label_1406a8;
            case 0x1406C0u: goto label_1406c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1406D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
