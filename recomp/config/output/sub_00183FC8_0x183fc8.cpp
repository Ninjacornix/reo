#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00183FC8
// Address: 0x183fc8 - 0x1840e0
void sub_00183FC8_0x183fc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00183FC8_0x183fc8");
#endif

    switch (ctx->pc) {
        case 0x183fe4u: goto label_183fe4;
        case 0x184000u: goto label_184000;
        case 0x184008u: goto label_184008;
        case 0x1840a8u: goto label_1840a8;
        case 0x1840b4u: goto label_1840b4;
        default: break;
    }

    ctx->pc = 0x183fc8u;

    // 0x183fc8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x183fc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x183fcc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x183fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x183fd0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x183fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x183fd4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x183fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x183fd8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x183fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x183fdc: 0xc062210  jal         func_188840
    ctx->pc = 0x183FDCu;
    SET_GPR_U32(ctx, 31, 0x183FE4u);
    ctx->pc = 0x183FE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183FDCu;
            // 0x183fe0: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183FE4u; }
        if (ctx->pc != 0x183FE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183FE4u; }
        if (ctx->pc != 0x183FE4u) { return; }
    }
    ctx->pc = 0x183FE4u;
label_183fe4:
    // 0x183fe4: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x183FE4u;
    {
        const bool branch_taken_0x183fe4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x183fe4) {
            ctx->pc = 0x183FE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183FE4u;
            // 0x183fe8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183FF8u;
            goto label_183ff8;
        }
    }
    ctx->pc = 0x183FECu;
    // 0x183fec: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183fecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183ff0: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x183FF0u;
    {
        const bool branch_taken_0x183ff0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x183FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183FF0u;
            // 0x183ff4: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183ff0) {
            ctx->pc = 0x1840C8u;
            goto label_1840c8;
        }
    }
    ctx->pc = 0x183FF8u;
label_183ff8:
    // 0x183ff8: 0xc061af8  jal         func_186BE0
    ctx->pc = 0x183FF8u;
    SET_GPR_U32(ctx, 31, 0x184000u);
    ctx->pc = 0x183FFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183FF8u;
            // 0x183ffc: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186BE0u;
    if (runtime->hasFunction(0x186BE0u)) {
        auto targetFn = runtime->lookupFunction(0x186BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184000u; }
        if (ctx->pc != 0x184000u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186BE0_0x186be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184000u; }
        if (ctx->pc != 0x184000u) { return; }
    }
    ctx->pc = 0x184000u;
label_184000:
    // 0x184000: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x184000u;
    {
        const bool branch_taken_0x184000 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184000u;
            // 0x184004: 0x8fa80004  lw          $t0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184000) {
            ctx->pc = 0x184018u;
            goto label_184018;
        }
    }
    ctx->pc = 0x184008u;
label_184008:
    // 0x184008: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184008u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18400c: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x18400Cu;
    {
        const bool branch_taken_0x18400c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18400Cu;
            // 0x184010: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18400c) {
            ctx->pc = 0x1840C8u;
            goto label_1840c8;
        }
    }
    ctx->pc = 0x184014u;
    // 0x184014: 0x0  nop
    ctx->pc = 0x184014u;
    // NOP
label_184018:
    // 0x184018: 0x24030898  addiu       $v1, $zero, 0x898
    ctx->pc = 0x184018u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x18401c: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x18401cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x184020: 0x2431818  mult        $v1, $s2, $v1
    ctx->pc = 0x184020u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x184024: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x184024u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x184028: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x184028u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x18402c: 0x88001a  div         $zero, $a0, $t0
    ctx->pc = 0x18402cu;
    { int32_t divisor = GPR_S32(ctx, 8);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x184030: 0x24425b48  addiu       $v0, $v0, 0x5B48
    ctx->pc = 0x184030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23368));
    // 0x184034: 0x24460004  addiu       $a2, $v0, 0x4
    ctx->pc = 0x184034u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x184038: 0x24470808  addiu       $a3, $v0, 0x808
    ctx->pc = 0x184038u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 2056));
    // 0x18403c: 0x24640890  addiu       $a0, $v1, 0x890
    ctx->pc = 0x18403cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2192));
    // 0x184040: 0x24650800  addiu       $a1, $v1, 0x800
    ctx->pc = 0x184040u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 2048));
    // 0x184044: 0xa65021  addu        $t2, $a1, $a2
    ctx->pc = 0x184044u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x184048: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x184048u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x18404c: 0x824821  addu        $t1, $a0, $v0
    ctx->pc = 0x18404cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x184050: 0x862021  addu        $a0, $a0, $a2
    ctx->pc = 0x184050u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x184054: 0x673821  addu        $a3, $v1, $a3
    ctx->pc = 0x184054u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x184058: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x184058u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18405c: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x18405cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x184060: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x184060u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x184064: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x184064u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184068: 0xacab0000  sw          $t3, 0x0($a1)
    ctx->pc = 0x184068u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 11));
    // 0x18406c: 0xad4b0000  sw          $t3, 0x0($t2)
    ctx->pc = 0x18406cu;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 11));
    // 0x184070: 0xad200000  sw          $zero, 0x0($t1)
    ctx->pc = 0x184070u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 0));
    // 0x184074: 0xac60088c  sw          $zero, 0x88C($v1)
    ctx->pc = 0x184074u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 2188), GPR_U32(ctx, 0));
    // 0x184078: 0x24c517c8  addiu       $a1, $a2, 0x17C8
    ctx->pc = 0x184078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 6088));
    // 0x18407c: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x18407cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x184080: 0x80a30001  lb          $v1, 0x1($a1)
    ctx->pc = 0x184080u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x184084: 0xa0e20000  sb          $v0, 0x0($a3)
    ctx->pc = 0x184084u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x184088: 0xa0e30001  sb          $v1, 0x1($a3)
    ctx->pc = 0x184088u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x18408c: 0x51000001  beql        $t0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x18408Cu;
    {
        const bool branch_taken_0x18408c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        if (branch_taken_0x18408c) {
            ctx->pc = 0x184090u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18408Cu;
            // 0x184090: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x184094u;
            goto label_184094;
        }
    }
    ctx->pc = 0x184094u;
label_184094:
    // 0x184094: 0x8812  mflo        $s1
    ctx->pc = 0x184094u;
    SET_GPR_U64(ctx, 17, ctx->lo);
    // 0x184098: 0x1a20000b  blez        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x184098u;
    {
        const bool branch_taken_0x184098 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x18409Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184098u;
            // 0x18409c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184098) {
            ctx->pc = 0x1840C8u;
            goto label_1840c8;
        }
    }
    ctx->pc = 0x1840A0u;
    // 0x1840a0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1840a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1840a4: 0x0  nop
    ctx->pc = 0x1840a4u;
    // NOP
label_1840a8:
    // 0x1840a8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1840a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1840ac: 0xc0621ae  jal         func_1886B8
    ctx->pc = 0x1840ACu;
    SET_GPR_U32(ctx, 31, 0x1840B4u);
    ctx->pc = 0x1840B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1840ACu;
            // 0x1840b0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1886B8u;
    if (runtime->hasFunction(0x1886B8u)) {
        auto targetFn = runtime->lookupFunction(0x1886B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1840B4u; }
        if (ctx->pc != 0x1840B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001886B8_0x1886b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1840B4u; }
        if (ctx->pc != 0x1840B4u) { return; }
    }
    ctx->pc = 0x1840B4u;
label_1840b4:
    // 0x1840b4: 0x1040ffd4  beqz        $v0, . + 4 + (-0x2C << 2)
    ctx->pc = 0x1840B4u;
    {
        const bool branch_taken_0x1840b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1840B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1840B4u;
            // 0x1840b8: 0x211182a  slt         $v1, $s0, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1840b4) {
            ctx->pc = 0x184008u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184008;
        }
    }
    ctx->pc = 0x1840BCu;
    // 0x1840bc: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1840BCu;
    {
        const bool branch_taken_0x1840bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1840C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1840BCu;
            // 0x1840c0: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1840bc) {
            ctx->pc = 0x1840A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1840a8;
        }
    }
    ctx->pc = 0x1840C4u;
    // 0x1840c4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1840c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1840c8:
    // 0x1840c8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1840c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1840cc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1840ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1840d0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1840d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1840d4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1840d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1840d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1840D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1840DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1840D8u;
            // 0x1840dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x183FE4u: goto label_183fe4;
            case 0x183FF8u: goto label_183ff8;
            case 0x184000u: goto label_184000;
            case 0x184008u: goto label_184008;
            case 0x184018u: goto label_184018;
            case 0x184094u: goto label_184094;
            case 0x1840A8u: goto label_1840a8;
            case 0x1840B4u: goto label_1840b4;
            case 0x1840C8u: goto label_1840c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1840E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
