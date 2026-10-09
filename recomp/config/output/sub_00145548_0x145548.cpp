#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00145548
// Address: 0x145548 - 0x1457b8
void sub_00145548_0x145548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00145548_0x145548");
#endif

    switch (ctx->pc) {
        case 0x1455b8u: goto label_1455b8;
        case 0x1455d0u: goto label_1455d0;
        case 0x1456a0u: goto label_1456a0;
        case 0x1456b0u: goto label_1456b0;
        case 0x1456e0u: goto label_1456e0;
        case 0x14571cu: goto label_14571c;
        default: break;
    }

    ctx->pc = 0x145548u;

    // 0x145548: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x145548u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x14554c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x14554cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x145550: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x145550u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x145554: 0x34422010  ori         $v0, $v0, 0x2010
    ctx->pc = 0x145554u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8208);
    // 0x145558: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x145558u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x14555c: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x14555cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x145560: 0xffbe00a0  sd          $fp, 0xA0($sp)
    ctx->pc = 0x145560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x145564: 0x34634000  ori         $v1, $v1, 0x4000
    ctx->pc = 0x145564u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16384);
    // 0x145568: 0xffb70090  sd          $s7, 0x90($sp)
    ctx->pc = 0x145568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x14556c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x14556cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145570: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x145570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x145574: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x145574u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145578: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x145578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x14557c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x14557cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145580: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x145580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x145584: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x145584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x145588: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x145588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x14558c: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x14558cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x145590: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x145590u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145594: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x145594u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x145598: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x145598u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x14559c: 0x14c2001c  bne         $a2, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x14559Cu;
    {
        const bool branch_taken_0x14559c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x1455A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14559Cu;
            // 0x1455a0: 0x58e80  sll         $s1, $a1, 26 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 5), 26));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14559c) {
            ctx->pc = 0x145610u;
            goto label_145610;
        }
    }
    ctx->pc = 0x1455A4u;
    // 0x1455a4: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x1455a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x1455a8: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1455A8u;
    {
        const bool branch_taken_0x1455a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1455ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1455A8u;
            // 0x1455ac: 0x3c120023  lui         $s2, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1455a8) {
            ctx->pc = 0x145614u;
            goto label_145614;
        }
    }
    ctx->pc = 0x1455B0u;
    // 0x1455b0: 0x58e80  sll         $s1, $a1, 26
    ctx->pc = 0x1455b0u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 5), 26));
    // 0x1455b4: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1455b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_1455b8:
    // 0x1455b8: 0x28421389  slti        $v0, $v0, 0x1389
    ctx->pc = 0x1455b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5001) ? 1 : 0);
    // 0x1455bc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1455BCu;
    {
        const bool branch_taken_0x1455bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1455C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1455BCu;
            // 0x1455c0: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1455bc) {
            ctx->pc = 0x1455D8u;
            goto label_1455d8;
        }
    }
    ctx->pc = 0x1455C4u;
    // 0x1455c4: 0x8e040870  lw          $a0, 0x870($s0)
    ctx->pc = 0x1455c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x1455c8: 0xc051ff8  jal         func_147FE0
    ctx->pc = 0x1455C8u;
    SET_GPR_U32(ctx, 31, 0x1455D0u);
    ctx->pc = 0x1455CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1455C8u;
            // 0x1455cc: 0x7fa80010  sq          $t0, 0x10($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147FE0u;
    if (runtime->hasFunction(0x147FE0u)) {
        auto targetFn = runtime->lookupFunction(0x147FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1455D0u; }
        if (ctx->pc != 0x1455D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1455D0u; }
        if (ctx->pc != 0x1455D0u) { return; }
    }
    ctx->pc = 0x1455D0u;
label_1455d0:
    // 0x1455d0: 0x7ba80010  lq          $t0, 0x10($sp)
    ctx->pc = 0x1455d0u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1455d4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1455d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1455d8:
    // 0x1455d8: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1455d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1455dc: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1455dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1455e0: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x1455e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x1455e4: 0x34844000  ori         $a0, $a0, 0x4000
    ctx->pc = 0x1455e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)16384);
    // 0x1455e8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1455e8u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1455ec: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x1455ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1455f0: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x1455f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x1455f4: 0x14450008  bne         $v0, $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1455F4u;
    {
        const bool branch_taken_0x1455f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x1455F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1455F4u;
            // 0x1455f8: 0x3c033000  lui         $v1, 0x3000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)12288 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1455f4) {
            ctx->pc = 0x145618u;
            goto label_145618;
        }
    }
    ctx->pc = 0x1455FCu;
    // 0x1455fc: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x1455fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145600: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x145600u;
    {
        const bool branch_taken_0x145600 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x145604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145600u;
            // 0x145604: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145600) {
            ctx->pc = 0x1455B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1455b8;
        }
    }
    ctx->pc = 0x145608u;
    // 0x145608: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x145608u;
    {
        const bool branch_taken_0x145608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14560Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145608u;
            // 0x14560c: 0x3c041000  lui         $a0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145608) {
            ctx->pc = 0x14561Cu;
            goto label_14561c;
        }
    }
    ctx->pc = 0x145610u;
label_145610:
    // 0x145610: 0x3c120023  lui         $s2, 0x23
    ctx->pc = 0x145610u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
label_145614:
    // 0x145614: 0x3c033000  lui         $v1, 0x3000
    ctx->pc = 0x145614u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)12288 << 16));
label_145618:
    // 0x145618: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x145618u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
label_14561c:
    // 0x14561c: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x14561cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x145620: 0x34842000  ori         $a0, $a0, 0x2000
    ctx->pc = 0x145620u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8192);
    // 0x145624: 0x31703  sra         $v0, $v1, 28
    ctx->pc = 0x145624u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 28));
    // 0x145628: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x145628u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14562c: 0x2645a6f8  addiu       $a1, $s2, -0x5908
    ctx->pc = 0x14562cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 4294944504));
    // 0x145630: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x145630u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x145634: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x145634u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x145638: 0xdc860000  ld          $a2, 0x0($a0)
    ctx->pc = 0x145638u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14563c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14563cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145640: 0x4c1003a  bgez        $a2, . + 4 + (0x3A << 2)
    ctx->pc = 0x145640u;
    {
        const bool branch_taken_0x145640 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x145644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145640u;
            // 0x145644: 0xae030830  sw          $v1, 0x830($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2096), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145640) {
            ctx->pc = 0x14572Cu;
            goto label_14572c;
        }
    }
    ctx->pc = 0x145648u;
    // 0x145648: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x145648u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x14564c: 0x3c131000  lui         $s3, 0x1000
    ctx->pc = 0x14564cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)4096 << 16));
    // 0x145650: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x145650u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x145654: 0x3c121000  lui         $s2, 0x1000
    ctx->pc = 0x145654u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)4096 << 16));
    // 0x145658: 0x34422010  ori         $v0, $v0, 0x2010
    ctx->pc = 0x145658u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8208);
    // 0x14565c: 0x3c141000  lui         $s4, 0x1000
    ctx->pc = 0x14565cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)4096 << 16));
    // 0x145660: 0x3c151000  lui         $s5, 0x1000
    ctx->pc = 0x145660u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)4096 << 16));
    // 0x145664: 0x3c16fffe  lui         $s6, 0xFFFE
    ctx->pc = 0x145664u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)65534 << 16));
    // 0x145668: 0x3c171000  lui         $s7, 0x1000
    ctx->pc = 0x145668u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)4096 << 16));
    // 0x14566c: 0x3c1e1000  lui         $fp, 0x1000
    ctx->pc = 0x14566cu;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)4096 << 16));
    // 0x145670: 0x3c111000  lui         $s1, 0x1000
    ctx->pc = 0x145670u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)4096 << 16));
    // 0x145674: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x145674u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x145678: 0x3673f590  ori         $s3, $s3, 0xF590
    ctx->pc = 0x145678u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)62864);
    // 0x14567c: 0x3652f520  ori         $s2, $s2, 0xF520
    ctx->pc = 0x14567cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)62752);
    // 0x145680: 0x3694b400  ori         $s4, $s4, 0xB400
    ctx->pc = 0x145680u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | (uint64_t)(uint16_t)46080);
    // 0x145684: 0x36b5b000  ori         $s5, $s5, 0xB000
    ctx->pc = 0x145684u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) | (uint64_t)(uint16_t)45056);
    // 0x145688: 0x36d6ffff  ori         $s6, $s6, 0xFFFF
    ctx->pc = 0x145688u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | (uint64_t)(uint16_t)65535);
    // 0x14568c: 0x36f7b020  ori         $s7, $s7, 0xB020
    ctx->pc = 0x14568cu;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)45088);
    // 0x145690: 0x37deb420  ori         $fp, $fp, 0xB420
    ctx->pc = 0x145690u;
    SET_GPR_U64(ctx, 30, GPR_U64(ctx, 30) | (uint64_t)(uint16_t)46112);
    // 0x145694: 0x36312000  ori         $s1, $s1, 0x2000
    ctx->pc = 0x145694u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)8192);
    // 0x145698: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x145698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x14569c: 0x0  nop
    ctx->pc = 0x14569cu;
    // NOP
label_1456a0:
    // 0x1456a0: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1456A0u;
    {
        const bool branch_taken_0x1456a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1456A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1456A0u;
            // 0x1456a4: 0x100102d  daddu       $v0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1456a0) {
            ctx->pc = 0x145700u;
            goto label_145700;
        }
    }
    ctx->pc = 0x1456A8u;
    // 0x1456a8: 0xc047598  jal         func_11D660
    ctx->pc = 0x1456A8u;
    SET_GPR_U32(ctx, 31, 0x1456B0u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1456B0u; }
        if (ctx->pc != 0x1456B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1456B0u; }
        if (ctx->pc != 0x1456B0u) { return; }
    }
    ctx->pc = 0x1456B0u;
label_1456b0:
    // 0x1456b0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1456b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1456b4: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x1456b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x1456b8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1456b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1456bc: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x1456bcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1456c0: 0xae800000  sw          $zero, 0x0($s4)
    ctx->pc = 0x1456c0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x1456c4: 0xaea00000  sw          $zero, 0x0($s5)
    ctx->pc = 0x1456c4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x1456c8: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1456c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1456cc: 0x761824  and         $v1, $v1, $s6
    ctx->pc = 0x1456ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 22));
    // 0x1456d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1456D0u;
    {
        const bool branch_taken_0x1456d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1456D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1456D0u;
            // 0x1456d4: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1456d0) {
            ctx->pc = 0x1456E0u;
            goto label_1456e0;
        }
    }
    ctx->pc = 0x1456D8u;
    // 0x1456d8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1456D8u;
    SET_GPR_U32(ctx, 31, 0x1456E0u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1456E0u; }
        if (ctx->pc != 0x1456E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1456E0u; }
        if (ctx->pc != 0x1456E0u) { return; }
    }
    ctx->pc = 0x1456E0u;
label_1456e0:
    // 0x1456e0: 0xaee00000  sw          $zero, 0x0($s7)
    ctx->pc = 0x1456e0u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 0));
    // 0x1456e4: 0x3c044000  lui         $a0, 0x4000
    ctx->pc = 0x1456e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16384 << 16));
    // 0x1456e8: 0xafc00000  sw          $zero, 0x0($fp)
    ctx->pc = 0x1456e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x1456ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1456ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1456f0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1456f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1456f4: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1456f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1456f8: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1456F8u;
    {
        const bool branch_taken_0x1456f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1456FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1456F8u;
            // 0x1456fc: 0xdfbf00b0  ld          $ra, 0xB0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1456f8) {
            ctx->pc = 0x145788u;
            goto label_145788;
        }
    }
    ctx->pc = 0x145700u;
label_145700:
    // 0x145700: 0x28421389  slti        $v0, $v0, 0x1389
    ctx->pc = 0x145700u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5001) ? 1 : 0);
    // 0x145704: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x145704u;
    {
        const bool branch_taken_0x145704 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x145708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145704u;
            // 0x145708: 0x25080001  addiu       $t0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145704) {
            ctx->pc = 0x145720u;
            goto label_145720;
        }
    }
    ctx->pc = 0x14570Cu;
    // 0x14570c: 0x8e040870  lw          $a0, 0x870($s0)
    ctx->pc = 0x14570cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x145710: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x145710u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145714: 0xc051ff8  jal         func_147FE0
    ctx->pc = 0x145714u;
    SET_GPR_U32(ctx, 31, 0x14571Cu);
    ctx->pc = 0x145718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145714u;
            // 0x145718: 0x7fa80010  sq          $t0, 0x10($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147FE0u;
    if (runtime->hasFunction(0x147FE0u)) {
        auto targetFn = runtime->lookupFunction(0x147FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14571Cu; }
        if (ctx->pc != 0x14571Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14571Cu; }
        if (ctx->pc != 0x14571Cu) { return; }
    }
    ctx->pc = 0x14571Cu;
label_14571c:
    // 0x14571c: 0x7ba80010  lq          $t0, 0x10($sp)
    ctx->pc = 0x14571cu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_145720:
    // 0x145720: 0xde260000  ld          $a2, 0x0($s1)
    ctx->pc = 0x145720u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x145724: 0x4c2ffde  bltzl       $a2, . + 4 + (-0x22 << 2)
    ctx->pc = 0x145724u;
    {
        const bool branch_taken_0x145724 = (GPR_S64(ctx, 6) < 0);
        if (branch_taken_0x145724) {
            ctx->pc = 0x145728u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x145724u;
            // 0x145728: 0x8e0210a0  lw          $v0, 0x10A0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1456A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1456a0;
        }
    }
    ctx->pc = 0x14572Cu;
label_14572c:
    // 0x14572c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x14572cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x145730: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x145730u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x145734: 0xdc842030  ld          $a0, 0x2030($a0)
    ctx->pc = 0x145734u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 4), 8240)));
    // 0x145738: 0x34422020  ori         $v0, $v0, 0x2020
    ctx->pc = 0x145738u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8224);
    // 0x14573c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x14573cu;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x145740: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x145740u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x145744: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x145744u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x145748: 0x4810005  bgez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x145748u;
    {
        const bool branch_taken_0x145748 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x14574Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145748u;
            // 0x14574c: 0xae030850  sw          $v1, 0x850($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2128), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145748) {
            ctx->pc = 0x145760u;
            goto label_145760;
        }
    }
    ctx->pc = 0x145750u;
    // 0x145750: 0x3042001f  andi        $v0, $v0, 0x1F
    ctx->pc = 0x145750u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
    // 0x145754: 0x21023  negu        $v0, $v0
    ctx->pc = 0x145754u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x145758: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x145758u;
    {
        const bool branch_taken_0x145758 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14575Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145758u;
            // 0x14575c: 0x3042001f  andi        $v0, $v0, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x145758) {
            ctx->pc = 0x145764u;
            goto label_145764;
        }
    }
    ctx->pc = 0x145760u;
label_145760:
    // 0x145760: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x145760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_145764:
    // 0x145764: 0xae020854  sw          $v0, 0x854($s0)
    ctx->pc = 0x145764u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2132), GPR_U32(ctx, 2));
    // 0x145768: 0x6183c  dsll32      $v1, $a2, 0
    ctx->pc = 0x145768u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) << (32 + 0));
    // 0x14576c: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x14576cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x145770: 0x30c2ffff  andi        $v0, $a2, 0xFFFF
    ctx->pc = 0x145770u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x145774: 0x2c630001  sltiu       $v1, $v1, 0x1
    ctx->pc = 0x145774u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x145778: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x145778u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x14577c: 0xae030134  sw          $v1, 0x134($s0)
    ctx->pc = 0x14577cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 308), GPR_U32(ctx, 3));
    // 0x145780: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x145780u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x145784: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x145784u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
label_145788:
    // 0x145788: 0xdfbe00a0  ld          $fp, 0xA0($sp)
    ctx->pc = 0x145788u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x14578c: 0xdfb70090  ld          $s7, 0x90($sp)
    ctx->pc = 0x14578cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x145790: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x145790u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x145794: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x145794u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x145798: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x145798u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x14579c: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x14579cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1457a0: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1457a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1457a4: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x1457a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1457a8: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1457a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1457ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1457ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1457B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1457ACu;
            // 0x1457b0: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1455B8u: goto label_1455b8;
            case 0x1455D0u: goto label_1455d0;
            case 0x1455D8u: goto label_1455d8;
            case 0x145610u: goto label_145610;
            case 0x145614u: goto label_145614;
            case 0x145618u: goto label_145618;
            case 0x14561Cu: goto label_14561c;
            case 0x1456A0u: goto label_1456a0;
            case 0x1456B0u: goto label_1456b0;
            case 0x1456E0u: goto label_1456e0;
            case 0x145700u: goto label_145700;
            case 0x14571Cu: goto label_14571c;
            case 0x145720u: goto label_145720;
            case 0x14572Cu: goto label_14572c;
            case 0x145760u: goto label_145760;
            case 0x145764u: goto label_145764;
            case 0x145788u: goto label_145788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1457B4u;
    // 0x1457b4: 0x0  nop
    ctx->pc = 0x1457b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
