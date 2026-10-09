#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8560
// Address: 0x1d8560 - 0x1d8720
void sub_001D8560_0x1d8560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8560_0x1d8560");
#endif

    switch (ctx->pc) {
        case 0x1d8598u: goto label_1d8598;
        case 0x1d85ccu: goto label_1d85cc;
        case 0x1d85e0u: goto label_1d85e0;
        case 0x1d8610u: goto label_1d8610;
        case 0x1d86a8u: goto label_1d86a8;
        case 0x1d86f0u: goto label_1d86f0;
        default: break;
    }

    ctx->pc = 0x1d8560u;

    // 0x1d8560: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1d8560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1d8564: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1d8564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1d8568: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d8568u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d856c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d856cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d8570: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1d8570u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8574: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d8574u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d8578: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1d8578u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d857c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d857cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d8580: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1d8580u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8584: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d8584u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d8588: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1d8588u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d858c: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x1d858cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8590: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8590u;
    SET_GPR_U32(ctx, 31, 0x1D8598u);
    ctx->pc = 0x1D8594u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8590u;
            // 0x1d8594: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8598u; }
        if (ctx->pc != 0x1D8598u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8598u; }
        if (ctx->pc != 0x1D8598u) { return; }
    }
    ctx->pc = 0x1D8598u;
label_1d8598:
    // 0x1d8598: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d8598u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d859c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d859cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d85a0: 0x8c2369f0  lw          $v1, 0x69F0($at)
    ctx->pc = 0x1d85a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27120)));
    // 0x1d85a4: 0x24425248  addiu       $v0, $v0, 0x5248
    ctx->pc = 0x1d85a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21064));
    // 0x1d85a8: 0x1462002d  bne         $v1, $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1D85A8u;
    {
        const bool branch_taken_0x1d85a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D85ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D85A8u;
            // 0x1d85ac: 0x3c050034  lui         $a1, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d85a8) {
            ctx->pc = 0x1D8660u;
            goto label_1d8660;
        }
    }
    ctx->pc = 0x1D85B0u;
    // 0x1d85b0: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d85b0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d85b4: 0x2404001b  addiu       $a0, $zero, 0x1B
    ctx->pc = 0x1d85b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x1d85b8: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d85b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d85bc: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d85bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d85c0: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d85c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d85c4: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D85C4u;
    SET_GPR_U32(ctx, 31, 0x1D85CCu);
    ctx->pc = 0x1D85C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D85C4u;
            // 0x1d85c8: 0x24081030  addiu       $t0, $zero, 0x1030 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D85CCu; }
        if (ctx->pc != 0x1D85CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D85CCu; }
        if (ctx->pc != 0x1D85CCu) { return; }
    }
    ctx->pc = 0x1D85CCu;
label_1d85cc:
    // 0x1d85cc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d85ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d85d0: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1d85d0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1d85d4: 0x84226298  lh          $v0, 0x6298($at)
    ctx->pc = 0x1d85d4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
    // 0x1d85d8: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1D85D8u;
    {
        const bool branch_taken_0x1d85d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D85DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D85D8u;
            // 0x1d85dc: 0x2610629c  addiu       $s0, $s0, 0x629C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 25244));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d85d8) {
            ctx->pc = 0x1D8640u;
            goto label_1d8640;
        }
    }
    ctx->pc = 0x1D85E0u;
label_1d85e0:
    // 0x1d85e0: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1d85e0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d85e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d85e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d85e8: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1D85E8u;
    {
        const bool branch_taken_0x1d85e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d85e8) {
            ctx->pc = 0x1D8640u;
            goto label_1d8640;
        }
    }
    ctx->pc = 0x1D85F0u;
    // 0x1d85f0: 0x86030002  lh          $v1, 0x2($s0)
    ctx->pc = 0x1d85f0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1d85f4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d85f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d85f8: 0x96020006  lhu         $v0, 0x6($s0)
    ctx->pc = 0x1d85f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1d85fc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d85fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8600: 0x8c2469f0  lw          $a0, 0x69F0($at)
    ctx->pc = 0x1d8600u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27120)));
    // 0x1d8604: 0x2463000c  addiu       $v1, $v1, 0xC
    ctx->pc = 0x1d8604u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 12));
    // 0x1d8608: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D8608u;
    SET_GPR_U32(ctx, 31, 0x1D8610u);
    ctx->pc = 0x1D860Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8608u;
            // 0x1d860c: 0x623021  addu        $a2, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8610u; }
        if (ctx->pc != 0x1D8610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8610u; }
        if (ctx->pc != 0x1D8610u) { return; }
    }
    ctx->pc = 0x1D8610u;
label_1d8610:
    // 0x1d8610: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x1d8610u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1d8614: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d8614u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d8618: 0x96030006  lhu         $v1, 0x6($s0)
    ctx->pc = 0x1d8618u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1d861c: 0x8c2269f0  lw          $v0, 0x69F0($at)
    ctx->pc = 0x1d861cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27120)));
    // 0x1d8620: 0x2484000c  addiu       $a0, $a0, 0xC
    ctx->pc = 0x1d8620u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1d8624: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1d8624u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d8628: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d8628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d862c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d862cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d8630: 0x2038021  addu        $s0, $s0, $v1
    ctx->pc = 0x1d8630u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1d8634: 0x1000ffea  b           . + 4 + (-0x16 << 2)
    ctx->pc = 0x1D8634u;
    {
        const bool branch_taken_0x1d8634 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D8638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8634u;
            // 0x1d8638: 0xac2269f0  sw          $v0, 0x69F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27120), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d8634) {
            ctx->pc = 0x1D85E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d85e0;
        }
    }
    ctx->pc = 0x1D863Cu;
    // 0x1d863c: 0x0  nop
    ctx->pc = 0x1d863cu;
    // NOP
label_1d8640:
    // 0x1d8640: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d8640u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d8644: 0x8c2369f0  lw          $v1, 0x69F0($at)
    ctx->pc = 0x1d8644u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27120)));
    // 0x1d8648: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d8648u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d864c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d864cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d8650: 0x24425248  addiu       $v0, $v0, 0x5248
    ctx->pc = 0x1d8650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21064));
    // 0x1d8654: 0xa4640000  sh          $a0, 0x0($v1)
    ctx->pc = 0x1d8654u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1d8658: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d8658u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d865c: 0xac2269f0  sw          $v0, 0x69F0($at)
    ctx->pc = 0x1d865cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27120), GPR_U32(ctx, 2));
label_1d8660:
    // 0x1d8660: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d8660u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d8664: 0x8c3069f0  lw          $s0, 0x69F0($at)
    ctx->pc = 0x1d8664u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27120)));
    // 0x1d8668: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d8668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d866c: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x1d866cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d8670: 0x10620017  beq         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1D8670u;
    {
        const bool branch_taken_0x1d8670 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1d8670) {
            ctx->pc = 0x1D86D0u;
            goto label_1d86d0;
        }
    }
    ctx->pc = 0x1D8678u;
    // 0x1d8678: 0xa6a30000  sh          $v1, 0x0($s5)
    ctx->pc = 0x1d8678u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d867c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d867cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8680: 0x86020002  lh          $v0, 0x2($s0)
    ctx->pc = 0x1d8680u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1d8684: 0x2605000c  addiu       $a1, $s0, 0xC
    ctx->pc = 0x1d8684u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x1d8688: 0xa6820000  sh          $v0, 0x0($s4)
    ctx->pc = 0x1d8688u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d868c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1d868cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1d8690: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x1d8690u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1d8694: 0x96020004  lhu         $v0, 0x4($s0)
    ctx->pc = 0x1d8694u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1d8698: 0xa6420000  sh          $v0, 0x0($s2)
    ctx->pc = 0x1d8698u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d869c: 0x86060002  lh          $a2, 0x2($s0)
    ctx->pc = 0x1d869cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1d86a0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D86A0u;
    SET_GPR_U32(ctx, 31, 0x1D86A8u);
    ctx->pc = 0x1D86A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D86A0u;
            // 0x1d86a4: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D86A8u; }
        if (ctx->pc != 0x1D86A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D86A8u; }
        if (ctx->pc != 0x1D86A8u) { return; }
    }
    ctx->pc = 0x1D86A8u;
label_1d86a8:
    // 0x1d86a8: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x1d86a8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1d86ac: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d86acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d86b0: 0x96030006  lhu         $v1, 0x6($s0)
    ctx->pc = 0x1d86b0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1d86b4: 0x8c2269f0  lw          $v0, 0x69F0($at)
    ctx->pc = 0x1d86b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 27120)));
    // 0x1d86b8: 0x2484000c  addiu       $a0, $a0, 0xC
    ctx->pc = 0x1d86b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1d86bc: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1d86bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d86c0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d86c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d86c4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d86c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d86c8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D86C8u;
    {
        const bool branch_taken_0x1d86c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D86CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D86C8u;
            // 0x1d86cc: 0xac2269f0  sw          $v0, 0x69F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27120), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d86c8) {
            ctx->pc = 0x1D86E8u;
            goto label_1d86e8;
        }
    }
    ctx->pc = 0x1D86D0u;
label_1d86d0:
    // 0x1d86d0: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1d86d0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d86d4: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d86d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d86d8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1d86d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1d86dc: 0x24425248  addiu       $v0, $v0, 0x5248
    ctx->pc = 0x1d86dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21064));
    // 0x1d86e0: 0x118c3f  dsra32      $s1, $s1, 16
    ctx->pc = 0x1d86e0u;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
    // 0x1d86e4: 0x0  nop
    ctx->pc = 0x1d86e4u;
    // NOP
label_1d86e8:
    // 0x1d86e8: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D86E8u;
    SET_GPR_U32(ctx, 31, 0x1D86F0u);
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D86F0u; }
        if (ctx->pc != 0x1D86F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D86F0u; }
        if (ctx->pc != 0x1D86F0u) { return; }
    }
    ctx->pc = 0x1D86F0u;
label_1d86f0:
    // 0x1d86f0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1d86f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d86f4: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1d86f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d86f8: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d86f8u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d86fc: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d86fcu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d8700: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d8700u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d8704: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d8704u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d8708: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d8708u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d870c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d870cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8710: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8710u;
            // 0x1d8714: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8598u: goto label_1d8598;
            case 0x1D85CCu: goto label_1d85cc;
            case 0x1D85E0u: goto label_1d85e0;
            case 0x1D8610u: goto label_1d8610;
            case 0x1D8640u: goto label_1d8640;
            case 0x1D8660u: goto label_1d8660;
            case 0x1D86A8u: goto label_1d86a8;
            case 0x1D86D0u: goto label_1d86d0;
            case 0x1D86E8u: goto label_1d86e8;
            case 0x1D86F0u: goto label_1d86f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8718u;
    // 0x1d8718: 0x0  nop
    ctx->pc = 0x1d8718u;
    // NOP
    // 0x1d871c: 0x0  nop
    ctx->pc = 0x1d871cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
