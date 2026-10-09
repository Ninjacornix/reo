#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B74D0
// Address: 0x1b74d0 - 0x1b78a0
void sub_001B74D0_0x1b74d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B74D0_0x1b74d0");
#endif

    switch (ctx->pc) {
        case 0x1b7510u: goto label_1b7510;
        case 0x1b7588u: goto label_1b7588;
        case 0x1b7670u: goto label_1b7670;
        case 0x1b76e0u: goto label_1b76e0;
        case 0x1b7730u: goto label_1b7730;
        default: break;
    }

    ctx->pc = 0x1b74d0u;

    // 0x1b74d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b74d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b74d4: 0x5293c  dsll32      $a1, $a1, 4
    ctx->pc = 0x1b74d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 4));
    // 0x1b74d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b74d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b74dc: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x1b74dcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x1b74e0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b74e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b74e4: 0x3c02f000  lui         $v0, 0xF000
    ctx->pc = 0x1b74e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)61440 << 16));
    // 0x1b74e8: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1b74e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x1b74ec: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1b74ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b74f0: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x1b74f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1b74f4: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x1b74f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x1b74f8: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x1b74f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1b74fc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1b74fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7500: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x1b7500u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x1b7504: 0x24e7f6f0  addiu       $a3, $a3, -0x910
    ctx->pc = 0x1b7504u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
    // 0x1b7508: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x1B7508u;
    SET_GPR_U32(ctx, 31, 0x1B7510u);
    ctx->pc = 0x1B750Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7508u;
            // 0x1b750c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7510u; }
        if (ctx->pc != 0x1B7510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7510u; }
        if (ctx->pc != 0x1B7510u) { return; }
    }
    ctx->pc = 0x1B7510u;
label_1b7510:
    // 0x1b7510: 0x26020010  addiu       $v0, $s0, 0x10
    ctx->pc = 0x1b7510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1b7514: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b7514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7518: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7518u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b751c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B751Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B751Cu;
            // 0x1b7520: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7524u;
    // 0x1b7524: 0x0  nop
    ctx->pc = 0x1b7524u;
    // NOP
    // 0x1b7528: 0x0  nop
    ctx->pc = 0x1b7528u;
    // NOP
    // 0x1b752c: 0x0  nop
    ctx->pc = 0x1b752cu;
    // NOP
    // 0x1b7530: 0x27bdff10  addiu       $sp, $sp, -0xF0
    ctx->pc = 0x1b7530u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x1b7534: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1b7534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1b7538: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1b7538u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1b753c: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1b753cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1b7540: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1b7540u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1b7544: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1b7544u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1b7548: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b7548u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b754c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b754cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b7550: 0x3c14002c  lui         $s4, 0x2C
    ctx->pc = 0x1b7550u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)44 << 16));
    // 0x1b7554: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b7554u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b7558: 0x2694aa40  addiu       $s4, $s4, -0x55C0
    ctx->pc = 0x1b7558u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294945344));
    // 0x1b755c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b755cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b7560: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b7560u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7564: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7564u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7568: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1b7568u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b756c: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B756Cu;
    {
        const bool branch_taken_0x1b756c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B756Cu;
            // 0x1b7570: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b756c) {
            ctx->pc = 0x1B757Cu;
            goto label_1b757c;
        }
    }
    ctx->pc = 0x1B7574u;
    // 0x1b7574: 0x10000084  b           . + 4 + (0x84 << 2)
    ctx->pc = 0x1B7574u;
    {
        const bool branch_taken_0x1b7574 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7574u;
            // 0x1b7578: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7574) {
            ctx->pc = 0x1B7788u;
            goto label_1b7788;
        }
    }
    ctx->pc = 0x1B757Cu;
label_1b757c:
    // 0x1b757c: 0x8e970070  lw          $s7, 0x70($s4)
    ctx->pc = 0x1b757cu;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x1b7580: 0x8e9e0074  lw          $fp, 0x74($s4)
    ctx->pc = 0x1b7580u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x1b7584: 0x8e93004c  lw          $s3, 0x4C($s4)
    ctx->pc = 0x1b7584u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 76)));
label_1b7588:
    // 0x1b7588: 0x92450000  lbu         $a1, 0x0($s2)
    ctx->pc = 0x1b7588u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b758c: 0x10a0007c  beqz        $a1, . + 4 + (0x7C << 2)
    ctx->pc = 0x1B758Cu;
    {
        const bool branch_taken_0x1b758c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B758Cu;
            // 0x1b7590: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b758c) {
            ctx->pc = 0x1B7780u;
            goto label_1b7780;
        }
    }
    ctx->pc = 0x1B7594u;
    // 0x1b7594: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1b7594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1b7598: 0x14a20010  bne         $a1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B7598u;
    {
        const bool branch_taken_0x1b7598 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b7598) {
            ctx->pc = 0x1B75DCu;
            goto label_1b75dc;
        }
    }
    ctx->pc = 0x1B75A0u;
    // 0x1b75a0: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B75A0u;
    {
        const bool branch_taken_0x1b75a0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b75a0) {
            ctx->pc = 0x1B75C0u;
            goto label_1b75c0;
        }
    }
    ctx->pc = 0x1B75A8u;
    // 0x1b75a8: 0xae970070  sw          $s7, 0x70($s4)
    ctx->pc = 0x1b75a8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 23));
    // 0x1b75ac: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x1b75acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x1b75b0: 0x8e820074  lw          $v0, 0x74($s4)
    ctx->pc = 0x1b75b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x1b75b4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b75b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b75b8: 0x1000fff3  b           . + 4 + (-0xD << 2)
    ctx->pc = 0x1B75B8u;
    {
        const bool branch_taken_0x1b75b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B75BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B75B8u;
            // 0x1b75bc: 0xae820074  sw          $v0, 0x74($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b75b8) {
            ctx->pc = 0x1B7588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7588;
        }
    }
    ctx->pc = 0x1B75C0u;
label_1b75c0:
    // 0x1b75c0: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x1b75c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x1b75c4: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x1b75c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x1b75c8: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x1b75c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x1b75cc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1b75ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b75d0: 0xae820070  sw          $v0, 0x70($s4)
    ctx->pc = 0x1b75d0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
    // 0x1b75d4: 0x1000ffec  b           . + 4 + (-0x14 << 2)
    ctx->pc = 0x1B75D4u;
    {
        const bool branch_taken_0x1b75d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B75D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B75D4u;
            // 0x1b75d8: 0xae9e0074  sw          $fp, 0x74($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b75d4) {
            ctx->pc = 0x1B7588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7588;
        }
    }
    ctx->pc = 0x1B75DCu;
label_1b75dc:
    // 0x1b75dc: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x1b75dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x1b75e0: 0x2ca30080  sltiu       $v1, $a1, 0x80
    ctx->pc = 0x1b75e0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b75e4: 0xafa200e0  sw          $v0, 0xE0($sp)
    ctx->pc = 0x1b75e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 224), GPR_U32(ctx, 2));
    // 0x1b75e8: 0x8e820074  lw          $v0, 0x74($s4)
    ctx->pc = 0x1b75e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x1b75ec: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B75ECu;
    {
        const bool branch_taken_0x1b75ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B75F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B75ECu;
            // 0x1b75f0: 0xafa200d0  sw          $v0, 0xD0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b75ec) {
            ctx->pc = 0x1B7600u;
            goto label_1b7600;
        }
    }
    ctx->pc = 0x1B75F4u;
    // 0x1b75f4: 0x2ca100a0  sltiu       $at, $a1, 0xA0
    ctx->pc = 0x1b75f4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b75f8: 0x14200007  bnez        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B75F8u;
    {
        const bool branch_taken_0x1b75f8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b75f8) {
            ctx->pc = 0x1B7618u;
            goto label_1b7618;
        }
    }
    ctx->pc = 0x1B7600u;
label_1b7600:
    // 0x1b7600: 0x2ca200e0  sltiu       $v0, $a1, 0xE0
    ctx->pc = 0x1b7600u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
    // 0x1b7604: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B7604u;
    {
        const bool branch_taken_0x1b7604 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7604u;
            // 0x1b7608: 0x30a400ff  andi        $a0, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7604) {
            ctx->pc = 0x1B7668u;
            goto label_1b7668;
        }
    }
    ctx->pc = 0x1B760Cu;
    // 0x1b760c: 0x2ca10100  sltiu       $at, $a1, 0x100
    ctx->pc = 0x1b760cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b7610: 0x10200015  beqz        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B7610u;
    {
        const bool branch_taken_0x1b7610 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7610) {
            ctx->pc = 0x1B7668u;
            goto label_1b7668;
        }
    }
    ctx->pc = 0x1B7618u;
label_1b7618:
    // 0x1b7618: 0x92440000  lbu         $a0, 0x0($s2)
    ctx->pc = 0x1b7618u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b761c: 0x10800058  beqz        $a0, . + 4 + (0x58 << 2)
    ctx->pc = 0x1B761Cu;
    {
        const bool branch_taken_0x1b761c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B761Cu;
            // 0x1b7620: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b761c) {
            ctx->pc = 0x1B7780u;
            goto label_1b7780;
        }
    }
    ctx->pc = 0x1B7624u;
    // 0x1b7624: 0x51a00  sll         $v1, $a1, 8
    ctx->pc = 0x1b7624u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1b7628: 0x34028141  ori         $v0, $zero, 0x8141
    ctx->pc = 0x1b7628u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33089);
    // 0x1b762c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1b762cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1b7630: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1B7630u;
    {
        const bool branch_taken_0x1b7630 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B7634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7630u;
            // 0x1b7634: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7630) {
            ctx->pc = 0x1B7660u;
            goto label_1b7660;
        }
    }
    ctx->pc = 0x1B7638u;
    // 0x1b7638: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x1b7638u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x1b763c: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x1b763cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x1b7640: 0x31842  srl         $v1, $v1, 1
    ctx->pc = 0x1b7640u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1b7644: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b7644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7648: 0xae820070  sw          $v0, 0x70($s4)
    ctx->pc = 0x1b7648u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
    // 0x1b764c: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x1b764cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x1b7650: 0x8e820074  lw          $v0, 0x74($s4)
    ctx->pc = 0x1b7650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x1b7654: 0x31842  srl         $v1, $v1, 1
    ctx->pc = 0x1b7654u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1b7658: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1b7658u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b765c: 0xae820074  sw          $v0, 0x74($s4)
    ctx->pc = 0x1b765cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
label_1b7660:
    // 0x1b7660: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B7660u;
    {
        const bool branch_taken_0x1b7660 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7660u;
            // 0x1b7664: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7660) {
            ctx->pc = 0x1B7678u;
            goto label_1b7678;
        }
    }
    ctx->pc = 0x1B7668u;
label_1b7668:
    // 0x1b7668: 0xc06d960  jal         func_1B6580
    ctx->pc = 0x1B7668u;
    SET_GPR_U32(ctx, 31, 0x1B7670u);
    ctx->pc = 0x1B766Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7668u;
            // 0x1b766c: 0x8e850008  lw          $a1, 0x8($s4) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6580u;
    if (runtime->hasFunction(0x1B6580u)) {
        auto targetFn = runtime->lookupFunction(0x1B6580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7670u; }
        if (ctx->pc != 0x1B7670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6580_0x1b6580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7670u; }
        if (ctx->pc != 0x1B7670u) { return; }
    }
    ctx->pc = 0x1B7670u;
label_1b7670:
    // 0x1b7670: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x1b7670u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b7674: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1b7674u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1b7678:
    // 0x1b7678: 0x220b02d  daddu       $s6, $s1, $zero
    ctx->pc = 0x1b7678u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b767c: 0x8e880018  lw          $t0, 0x18($s4)
    ctx->pc = 0x1b767cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 24)));
    // 0x1b7680: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1b7680u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1b7684: 0x8e930080  lw          $s3, 0x80($s4)
    ctx->pc = 0x1b7684u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 128)));
    // 0x1b7688: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b7688u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b768c: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x1b768cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x1b7690: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x1b7690u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7694: 0x2a0382d  daddu       $a3, $s5, $zero
    ctx->pc = 0x1b7694u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7698: 0x2288821  addu        $s1, $s1, $t0
    ctx->pc = 0x1b7698u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 8)));
    // 0x1b769c: 0xafa200c0  sw          $v0, 0xC0($sp)
    ctx->pc = 0x1b769cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 2));
    // 0x1b76a0: 0x8e820074  lw          $v0, 0x74($s4)
    ctx->pc = 0x1b76a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x1b76a4: 0xafa200b0  sw          $v0, 0xB0($sp)
    ctx->pc = 0x1b76a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 2));
    // 0x1b76a8: 0x8e820078  lw          $v0, 0x78($s4)
    ctx->pc = 0x1b76a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 120)));
    // 0x1b76ac: 0xafa200a0  sw          $v0, 0xA0($sp)
    ctx->pc = 0x1b76acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 2));
    // 0x1b76b0: 0x2631024  and         $v0, $s3, $v1
    ctx->pc = 0x1b76b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 3));
    // 0x1b76b4: 0xae820080  sw          $v0, 0x80($s4)
    ctx->pc = 0x1b76b4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 128), GPR_U32(ctx, 2));
    // 0x1b76b8: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x1b76b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x1b76bc: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1b76bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1b76c0: 0xae820070  sw          $v0, 0x70($s4)
    ctx->pc = 0x1b76c0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
    // 0x1b76c4: 0x8e820074  lw          $v0, 0x74($s4)
    ctx->pc = 0x1b76c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x1b76c8: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1b76c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1b76cc: 0xae820074  sw          $v0, 0x74($s4)
    ctx->pc = 0x1b76ccu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
    // 0x1b76d0: 0x8e820078  lw          $v0, 0x78($s4)
    ctx->pc = 0x1b76d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 120)));
    // 0x1b76d4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1b76d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1b76d8: 0xc06dc74  jal         func_1B71D0
    ctx->pc = 0x1B76D8u;
    SET_GPR_U32(ctx, 31, 0x1B76E0u);
    ctx->pc = 0x1B76DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B76D8u;
            // 0x1b76dc: 0xae820078  sw          $v0, 0x78($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 120), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B71D0u;
    if (runtime->hasFunction(0x1B71D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B71D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B76E0u; }
        if (ctx->pc != 0x1B76E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B71D0_0x1b71d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B76E0u; }
        if (ctx->pc != 0x1B76E0u) { return; }
    }
    ctx->pc = 0x1B76E0u;
label_1b76e0:
    // 0x1b76e0: 0xae930080  sw          $s3, 0x80($s4)
    ctx->pc = 0x1b76e0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 128), GPR_U32(ctx, 19));
    // 0x1b76e4: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1b76e4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b76e8: 0x8fa200c0  lw          $v0, 0xC0($sp)
    ctx->pc = 0x1b76e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1b76ec: 0xae820070  sw          $v0, 0x70($s4)
    ctx->pc = 0x1b76ecu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
    // 0x1b76f0: 0x8fa200b0  lw          $v0, 0xB0($sp)
    ctx->pc = 0x1b76f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1b76f4: 0xae820074  sw          $v0, 0x74($s4)
    ctx->pc = 0x1b76f4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
    // 0x1b76f8: 0x8fa200a0  lw          $v0, 0xA0($sp)
    ctx->pc = 0x1b76f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1b76fc: 0xae820078  sw          $v0, 0x78($s4)
    ctx->pc = 0x1b76fcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 120), GPR_U32(ctx, 2));
    // 0x1b7700: 0x8e820064  lw          $v0, 0x64($s4)
    ctx->pc = 0x1b7700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 100)));
    // 0x1b7704: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b7704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b7708: 0xae820064  sw          $v0, 0x64($s4)
    ctx->pc = 0x1b7708u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 100), GPR_U32(ctx, 2));
    // 0x1b770c: 0x8e830064  lw          $v1, 0x64($s4)
    ctx->pc = 0x1b770cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 100)));
    // 0x1b7710: 0x8e820060  lw          $v0, 0x60($s4)
    ctx->pc = 0x1b7710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 96)));
    // 0x1b7714: 0x62082b  sltu        $at, $v1, $v0
    ctx->pc = 0x1b7714u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1b7718: 0x10200019  beqz        $at, . + 4 + (0x19 << 2)
    ctx->pc = 0x1B7718u;
    {
        const bool branch_taken_0x1b7718 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B771Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7718u;
            // 0x1b771c: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7718) {
            ctx->pc = 0x1B7780u;
            goto label_1b7780;
        }
    }
    ctx->pc = 0x1B7720u;
    // 0x1b7720: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x1b7720u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7724: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b7724u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7728: 0xc06dc74  jal         func_1B71D0
    ctx->pc = 0x1B7728u;
    SET_GPR_U32(ctx, 31, 0x1B7730u);
    ctx->pc = 0x1B772Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7728u;
            // 0x1b772c: 0x2a0382d  daddu       $a3, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B71D0u;
    if (runtime->hasFunction(0x1B71D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B71D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7730u; }
        if (ctx->pc != 0x1B7730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B71D0_0x1b71d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7730u; }
        if (ctx->pc != 0x1B7730u) { return; }
    }
    ctx->pc = 0x1B7730u;
label_1b7730:
    // 0x1b7730: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1b7730u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7734: 0x8e820064  lw          $v0, 0x64($s4)
    ctx->pc = 0x1b7734u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 100)));
    // 0x1b7738: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b7738u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b773c: 0xae820064  sw          $v0, 0x64($s4)
    ctx->pc = 0x1b773cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 100), GPR_U32(ctx, 2));
    // 0x1b7740: 0x8fa200e0  lw          $v0, 0xE0($sp)
    ctx->pc = 0x1b7740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x1b7744: 0xae820070  sw          $v0, 0x70($s4)
    ctx->pc = 0x1b7744u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
    // 0x1b7748: 0x8fa200d0  lw          $v0, 0xD0($sp)
    ctx->pc = 0x1b7748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1b774c: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B774Cu;
    {
        const bool branch_taken_0x1b774c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B7750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B774Cu;
            // 0x1b7750: 0xae820074  sw          $v0, 0x74($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b774c) {
            ctx->pc = 0x1B776Cu;
            goto label_1b776c;
        }
    }
    ctx->pc = 0x1B7754u;
    // 0x1b7754: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x1b7754u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x1b7758: 0x8e820070  lw          $v0, 0x70($s4)
    ctx->pc = 0x1b7758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 112)));
    // 0x1b775c: 0x2a31806  srlv        $v1, $v1, $s5
    ctx->pc = 0x1b775cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), GPR_U32(ctx, 21) & 0x1F));
    // 0x1b7760: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b7760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7764: 0x1000ff88  b           . + 4 + (-0x78 << 2)
    ctx->pc = 0x1B7764u;
    {
        const bool branch_taken_0x1b7764 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7764u;
            // 0x1b7768: 0xae820070  sw          $v0, 0x70($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 112), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7764) {
            ctx->pc = 0x1B7588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7588;
        }
    }
    ctx->pc = 0x1B776Cu;
label_1b776c:
    // 0x1b776c: 0x8e83006c  lw          $v1, 0x6C($s4)
    ctx->pc = 0x1b776cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 108)));
    // 0x1b7770: 0x8e820074  lw          $v0, 0x74($s4)
    ctx->pc = 0x1b7770u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 116)));
    // 0x1b7774: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b7774u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b7778: 0x1000ff83  b           . + 4 + (-0x7D << 2)
    ctx->pc = 0x1B7778u;
    {
        const bool branch_taken_0x1b7778 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B777Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7778u;
            // 0x1b777c: 0xae820074  sw          $v0, 0x74($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 116), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7778) {
            ctx->pc = 0x1B7588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b7588;
        }
    }
    ctx->pc = 0x1B7780u;
label_1b7780:
    // 0x1b7780: 0xae93004c  sw          $s3, 0x4C($s4)
    ctx->pc = 0x1b7780u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 76), GPR_U32(ctx, 19));
    // 0x1b7784: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1b7784u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1b7788:
    // 0x1b7788: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1b7788u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1b778c: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1b778cu;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1b7790: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1b7790u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1b7794: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1b7794u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1b7798: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1b7798u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b779c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b779cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b77a0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b77a0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b77a4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b77a4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b77a8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b77a8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b77ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b77acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b77b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B77B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B77B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B77B0u;
            // 0x1b77b4: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B77B8u;
    // 0x1b77b8: 0x0  nop
    ctx->pc = 0x1b77b8u;
    // NOP
    // 0x1b77bc: 0x0  nop
    ctx->pc = 0x1b77bcu;
    // NOP
    // 0x1b77c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B77C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B77C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B77C0u;
            // 0x1b77c4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B77C8u;
    // 0x1b77c8: 0x0  nop
    ctx->pc = 0x1b77c8u;
    // NOP
    // 0x1b77cc: 0x0  nop
    ctx->pc = 0x1b77ccu;
    // NOP
    // 0x1b77d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B77D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B77D8u;
    // 0x1b77d8: 0x0  nop
    ctx->pc = 0x1b77d8u;
    // NOP
    // 0x1b77dc: 0x0  nop
    ctx->pc = 0x1b77dcu;
    // NOP
    // 0x1b77e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B77E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B77E8u;
    // 0x1b77e8: 0x0  nop
    ctx->pc = 0x1b77e8u;
    // NOP
    // 0x1b77ec: 0x0  nop
    ctx->pc = 0x1b77ecu;
    // NOP
    // 0x1b77f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B77F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B77F8u;
    // 0x1b77f8: 0x0  nop
    ctx->pc = 0x1b77f8u;
    // NOP
    // 0x1b77fc: 0x0  nop
    ctx->pc = 0x1b77fcu;
    // NOP
    // 0x1b7800: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7808u;
    // 0x1b7808: 0x0  nop
    ctx->pc = 0x1b7808u;
    // NOP
    // 0x1b780c: 0x0  nop
    ctx->pc = 0x1b780cu;
    // NOP
    // 0x1b7810: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7818u;
    // 0x1b7818: 0x0  nop
    ctx->pc = 0x1b7818u;
    // NOP
    // 0x1b781c: 0x0  nop
    ctx->pc = 0x1b781cu;
    // NOP
    // 0x1b7820: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7828u;
    // 0x1b7828: 0x0  nop
    ctx->pc = 0x1b7828u;
    // NOP
    // 0x1b782c: 0x0  nop
    ctx->pc = 0x1b782cu;
    // NOP
    // 0x1b7830: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7834: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7834u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7838: 0xac64006c  sw          $a0, 0x6C($v1)
    ctx->pc = 0x1b7838u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 108), GPR_U32(ctx, 4));
    // 0x1b783c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b783cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7840: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7840u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7844: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7844u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7844u;
            // 0x1b7848: 0xac650098  sw          $a1, 0x98($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 152), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B784Cu;
    // 0x1b784c: 0x0  nop
    ctx->pc = 0x1b784cu;
    // NOP
    // 0x1b7850: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7850u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7854: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7854u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7858: 0xac640070  sw          $a0, 0x70($v1)
    ctx->pc = 0x1b7858u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 112), GPR_U32(ctx, 4));
    // 0x1b785c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b785cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7860: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7860u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7864: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7864u;
            // 0x1b7868: 0xac650074  sw          $a1, 0x74($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 116), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B786Cu;
    // 0x1b786c: 0x0  nop
    ctx->pc = 0x1b786cu;
    // NOP
    // 0x1b7870: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7870u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7874: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7874u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7878: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B787Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7878u;
            // 0x1b787c: 0xac640078  sw          $a0, 0x78($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 120), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7880u;
    // 0x1b7880: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7880u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7884: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7888: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B788Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7888u;
            // 0x1b788c: 0xac64007c  sw          $a0, 0x7C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 124), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7890u;
    // 0x1b7890: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7890u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7894: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7894u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7898: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B789Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7898u;
            // 0x1b789c: 0xac640080  sw          $a0, 0x80($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 128), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7510u: goto label_1b7510;
            case 0x1B757Cu: goto label_1b757c;
            case 0x1B7588u: goto label_1b7588;
            case 0x1B75C0u: goto label_1b75c0;
            case 0x1B75DCu: goto label_1b75dc;
            case 0x1B7600u: goto label_1b7600;
            case 0x1B7618u: goto label_1b7618;
            case 0x1B7660u: goto label_1b7660;
            case 0x1B7668u: goto label_1b7668;
            case 0x1B7670u: goto label_1b7670;
            case 0x1B7678u: goto label_1b7678;
            case 0x1B76E0u: goto label_1b76e0;
            case 0x1B7730u: goto label_1b7730;
            case 0x1B776Cu: goto label_1b776c;
            case 0x1B7780u: goto label_1b7780;
            case 0x1B7788u: goto label_1b7788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B78A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
