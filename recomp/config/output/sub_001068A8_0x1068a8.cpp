#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001068A8
// Address: 0x1068a8 - 0x106ad8
void sub_001068A8_0x1068a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001068A8_0x1068a8");
#endif

    switch (ctx->pc) {
        case 0x1068e4u: goto label_1068e4;
        case 0x106900u: goto label_106900;
        case 0x106918u: goto label_106918;
        case 0x106940u: goto label_106940;
        case 0x106980u: goto label_106980;
        case 0x10698cu: goto label_10698c;
        case 0x1069c0u: goto label_1069c0;
        case 0x106a00u: goto label_106a00;
        case 0x106a10u: goto label_106a10;
        case 0x106a48u: goto label_106a48;
        case 0x106a60u: goto label_106a60;
        default: break;
    }

    ctx->pc = 0x1068a8u;

label_1068a8:
    // 0x1068a8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1068a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1068ac: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1068acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1068b0: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x1068b0u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x1068b4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1068b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1068b8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1068b8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1068bc: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x1068bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x1068c0: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1068c0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1068c4: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x1068c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x1068c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1068c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1068cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1068ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1068d0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1068d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1068d4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1068d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1068d8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1068d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1068dc: 0xc0413b8  jal         func_104EE0
    ctx->pc = 0x1068DCu;
    SET_GPR_U32(ctx, 31, 0x1068E4u);
    ctx->pc = 0x1068E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1068DCu;
            // 0x1068e0: 0xc0b82d  daddu       $s7, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x104EE0u;
    if (runtime->hasFunction(0x104EE0u)) {
        auto targetFn = runtime->lookupFunction(0x104EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1068E4u; }
        if (ctx->pc != 0x1068E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EE0_0x104ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1068E4u; }
        if (ctx->pc != 0x1068E4u) { return; }
    }
    ctx->pc = 0x1068E4u;
label_1068e4:
    // 0x1068e4: 0x8ea294f8  lw          $v0, -0x6B08($s5)
    ctx->pc = 0x1068e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294939896)));
    // 0x1068e8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1068e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1068ec: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1068ECu;
    {
        const bool branch_taken_0x1068ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1068F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1068ECu;
            // 0x1068f0: 0x260802d  daddu       $s0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1068ec) {
            ctx->pc = 0x106920u;
            goto label_106920;
        }
    }
    ctx->pc = 0x1068F4u;
    // 0x1068f4: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1068F4u;
    {
        const bool branch_taken_0x1068f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1068F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1068F4u;
            // 0x1068f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1068f4) {
            ctx->pc = 0x1069C4u;
            goto label_1069c4;
        }
    }
    ctx->pc = 0x1068FCu;
    // 0x1068fc: 0x0  nop
    ctx->pc = 0x1068fcu;
    // NOP
label_106900:
    // 0x106900: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x106900u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106904: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x106904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x106908: 0x2221023  subu        $v0, $s1, $v0
    ctx->pc = 0x106908u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x10690c: 0x21083  sra         $v0, $v0, 2
    ctx->pc = 0x10690cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 2));
    // 0x106910: 0xc0413ba  jal         func_104EE8
    ctx->pc = 0x106910u;
    SET_GPR_U32(ctx, 31, 0x106918u);
    ctx->pc = 0x106914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106910u;
            // 0x106914: 0xaee20000  sw          $v0, 0x0($s7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x104EE8u;
    if (runtime->hasFunction(0x104EE8u)) {
        auto targetFn = runtime->lookupFunction(0x104EE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106918u; }
        if (ctx->pc != 0x106918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EE8_0x104ee8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106918u; }
        if (ctx->pc != 0x106918u) { return; }
    }
    ctx->pc = 0x106918u;
label_106918:
    // 0x106918: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x106918u;
    {
        const bool branch_taken_0x106918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10691Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106918u;
            // 0x10691c: 0x26020001  addiu       $v0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106918) {
            ctx->pc = 0x1069C4u;
            goto label_1069c4;
        }
    }
    ctx->pc = 0x106920u;
label_106920:
    // 0x106920: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x106920u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106924: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x106924u;
    {
        const bool branch_taken_0x106924 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x106928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106924u;
            // 0x106928: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106924) {
            ctx->pc = 0x106964u;
            goto label_106964;
        }
    }
    ctx->pc = 0x10692Cu;
    // 0x10692c: 0x2402003d  addiu       $v0, $zero, 0x3D
    ctx->pc = 0x10692cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
    // 0x106930: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x106930u;
    {
        const bool branch_taken_0x106930 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x106934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106930u;
            // 0x106934: 0x8ea294f8  lw          $v0, -0x6B08($s5) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294939896)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106930) {
            ctx->pc = 0x106968u;
            goto label_106968;
        }
    }
    ctx->pc = 0x106938u;
    // 0x106938: 0x2403003d  addiu       $v1, $zero, 0x3D
    ctx->pc = 0x106938u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
    // 0x10693c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x10693cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_106940:
    // 0x106940: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x106940u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106944: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x106944u;
    {
        const bool branch_taken_0x106944 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106944u;
            // 0x106948: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106944) {
            ctx->pc = 0x106964u;
            goto label_106964;
        }
    }
    ctx->pc = 0x10694Cu;
    // 0x10694c: 0x0  nop
    ctx->pc = 0x10694cu;
    // NOP
    // 0x106950: 0x0  nop
    ctx->pc = 0x106950u;
    // NOP
    // 0x106954: 0x0  nop
    ctx->pc = 0x106954u;
    // NOP
    // 0x106958: 0x0  nop
    ctx->pc = 0x106958u;
    // NOP
    // 0x10695c: 0x5443fff8  bnel        $v0, $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10695Cu;
    {
        const bool branch_taken_0x10695c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x10695c) {
            ctx->pc = 0x106960u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10695Cu;
            // 0x106960: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106940u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106940;
        }
    }
    ctx->pc = 0x106964u;
label_106964:
    // 0x106964: 0x8ea294f8  lw          $v0, -0x6B08($s5)
    ctx->pc = 0x106964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294939896)));
label_106968:
    // 0x106968: 0x8c510000  lw          $s1, 0x0($v0)
    ctx->pc = 0x106968u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10696c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x10696cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x106970: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x106970u;
    {
        const bool branch_taken_0x106970 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x106970) {
            ctx->pc = 0x1069B8u;
            goto label_1069b8;
        }
    }
    ctx->pc = 0x106978u;
    // 0x106978: 0x2414003d  addiu       $s4, $zero, 0x3D
    ctx->pc = 0x106978u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
    // 0x10697c: 0x0  nop
    ctx->pc = 0x10697cu;
    // NOP
label_106980:
    // 0x106980: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x106980u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106984: 0xc042d10  jal         func_10B440
    ctx->pc = 0x106984u;
    SET_GPR_U32(ctx, 31, 0x10698Cu);
    ctx->pc = 0x106988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106984u;
            // 0x106988: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10698Cu; }
        if (ctx->pc != 0x10698Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10698Cu; }
        if (ctx->pc != 0x10698Cu) { return; }
    }
    ctx->pc = 0x10698Cu;
label_10698c:
    // 0x10698c: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x10698Cu;
    {
        const bool branch_taken_0x10698c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10698c) {
            ctx->pc = 0x106990u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10698Cu;
            // 0x106990: 0x26310004  addiu       $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1069ACu;
            goto label_1069ac;
        }
    }
    ctx->pc = 0x106994u;
    // 0x106994: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x106994u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x106998: 0x528021  addu        $s0, $v0, $s2
    ctx->pc = 0x106998u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x10699c: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x10699cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1069a0: 0x1074ffd7  beq         $v1, $s4, . + 4 + (-0x29 << 2)
    ctx->pc = 0x1069A0u;
    {
        const bool branch_taken_0x1069a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 20));
        ctx->pc = 0x1069A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1069A0u;
            // 0x1069a4: 0x8ea394f8  lw          $v1, -0x6B08($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294939896)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1069a0) {
            ctx->pc = 0x106900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106900;
        }
    }
    ctx->pc = 0x1069A8u;
    // 0x1069a8: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x1069a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_1069ac:
    // 0x1069ac: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1069acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1069b0: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1069B0u;
    {
        const bool branch_taken_0x1069b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1069B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1069B0u;
            // 0x1069b4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1069b0) {
            ctx->pc = 0x106980u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106980;
        }
    }
    ctx->pc = 0x1069B8u;
label_1069b8:
    // 0x1069b8: 0xc0413ba  jal         func_104EE8
    ctx->pc = 0x1069B8u;
    SET_GPR_U32(ctx, 31, 0x1069C0u);
    ctx->pc = 0x1069BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1069B8u;
            // 0x1069bc: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x104EE8u;
    if (runtime->hasFunction(0x104EE8u)) {
        auto targetFn = runtime->lookupFunction(0x104EE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1069C0u; }
        if (ctx->pc != 0x1069C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EE8_0x104ee8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1069C0u; }
        if (ctx->pc != 0x1069C0u) { return; }
    }
    ctx->pc = 0x1069C0u;
label_1069c0:
    // 0x1069c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1069c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1069c4:
    // 0x1069c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1069c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1069c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1069c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1069cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1069ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1069d0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1069d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1069d4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1069d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1069d8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1069d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1069dc: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1069dcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1069e0: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x1069e0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1069e4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1069e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1069e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1069E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1069ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1069E8u;
            // 0x1069ec: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1068A8u: goto label_1068a8;
            case 0x1068E4u: goto label_1068e4;
            case 0x106900u: goto label_106900;
            case 0x106918u: goto label_106918;
            case 0x106920u: goto label_106920;
            case 0x106940u: goto label_106940;
            case 0x106964u: goto label_106964;
            case 0x106968u: goto label_106968;
            case 0x106980u: goto label_106980;
            case 0x10698Cu: goto label_10698c;
            case 0x1069ACu: goto label_1069ac;
            case 0x1069B8u: goto label_1069b8;
            case 0x1069C0u: goto label_1069c0;
            case 0x1069C4u: goto label_1069c4;
            case 0x106A00u: goto label_106a00;
            case 0x106A10u: goto label_106a10;
            case 0x106A48u: goto label_106a48;
            case 0x106A60u: goto label_106a60;
            case 0x106A68u: goto label_106a68;
            case 0x106A78u: goto label_106a78;
            case 0x106A7Cu: goto label_106a7c;
            case 0x106A80u: goto label_106a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1069F0u;
    // 0x1069f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1069f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1069f4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1069f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1069f8: 0xc041a2a  jal         func_1068A8
    ctx->pc = 0x1069F8u;
    SET_GPR_U32(ctx, 31, 0x106A00u);
    ctx->pc = 0x1069FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1069F8u;
            // 0x1069fc: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1068A8u;
    goto label_1068a8;
    ctx->pc = 0x106A00u;
label_106a00:
    // 0x106a00: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x106a00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106a04: 0x3e00008  jr          $ra
    ctx->pc = 0x106A04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A04u;
            // 0x106a08: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1068A8u: goto label_1068a8;
            case 0x1068E4u: goto label_1068e4;
            case 0x106900u: goto label_106900;
            case 0x106918u: goto label_106918;
            case 0x106920u: goto label_106920;
            case 0x106940u: goto label_106940;
            case 0x106964u: goto label_106964;
            case 0x106968u: goto label_106968;
            case 0x106980u: goto label_106980;
            case 0x10698Cu: goto label_10698c;
            case 0x1069ACu: goto label_1069ac;
            case 0x1069B8u: goto label_1069b8;
            case 0x1069C0u: goto label_1069c0;
            case 0x1069C4u: goto label_1069c4;
            case 0x106A00u: goto label_106a00;
            case 0x106A10u: goto label_106a10;
            case 0x106A48u: goto label_106a48;
            case 0x106A60u: goto label_106a60;
            case 0x106A68u: goto label_106a68;
            case 0x106A78u: goto label_106a78;
            case 0x106A7Cu: goto label_106a7c;
            case 0x106A80u: goto label_106a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106A0Cu;
    // 0x106a0c: 0x0  nop
    ctx->pc = 0x106a0cu;
    // NOP
label_106a10:
    // 0x106a10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x106a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x106a14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106a14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106a18: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x106a18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106a1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106a20: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x106a20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a24: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x106a24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x106a28: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x106a28u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a2c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x106a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x106a30: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x106a30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106a34: 0x12000010  beqz        $s0, . + 4 + (0x10 << 2)
    ctx->pc = 0x106A34u;
    {
        const bool branch_taken_0x106a34 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x106A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A34u;
            // 0x106a38: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a34) {
            ctx->pc = 0x106A78u;
            goto label_106a78;
        }
    }
    ctx->pc = 0x106A3Cu;
    // 0x106a3c: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x106a3cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x106a40: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x106A40u;
    SET_GPR_U32(ctx, 31, 0x106A48u);
    ctx->pc = 0x106A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106A40u;
            // 0x106a44: 0x26657910  addiu       $a1, $s3, 0x7910 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 30992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A48u; }
        if (ctx->pc != 0x106A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A48u; }
        if (ctx->pc != 0x106A48u) { return; }
    }
    ctx->pc = 0x106A48u;
label_106a48:
    // 0x106a48: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x106a48u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x106a4c: 0x24a57900  addiu       $a1, $a1, 0x7900
    ctx->pc = 0x106a4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 30976));
    // 0x106a50: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x106A50u;
    {
        const bool branch_taken_0x106a50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A50u;
            // 0x106a54: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a50) {
            ctx->pc = 0x106A68u;
            goto label_106a68;
        }
    }
    ctx->pc = 0x106A58u;
    // 0x106a58: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x106A58u;
    SET_GPR_U32(ctx, 31, 0x106A60u);
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A60u; }
        if (ctx->pc != 0x106A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A60u; }
        if (ctx->pc != 0x106A60u) { return; }
    }
    ctx->pc = 0x106A60u;
label_106a60:
    // 0x106a60: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x106A60u;
    {
        const bool branch_taken_0x106a60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A60u;
            // 0x106a64: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a60) {
            ctx->pc = 0x106A80u;
            goto label_106a80;
        }
    }
    ctx->pc = 0x106A68u;
label_106a68:
    // 0x106a68: 0xae300034  sw          $s0, 0x34($s1)
    ctx->pc = 0x106a68u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 16));
    // 0x106a6c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x106A6Cu;
    {
        const bool branch_taken_0x106a6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A6Cu;
            // 0x106a70: 0xae320030  sw          $s2, 0x30($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106a6c) {
            ctx->pc = 0x106A7Cu;
            goto label_106a7c;
        }
    }
    ctx->pc = 0x106A74u;
    // 0x106a74: 0x0  nop
    ctx->pc = 0x106a74u;
    // NOP
label_106a78:
    // 0x106a78: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x106a78u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
label_106a7c:
    // 0x106a7c: 0x26627910  addiu       $v0, $s3, 0x7910
    ctx->pc = 0x106a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 30992));
label_106a80:
    // 0x106a80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106a80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106a84: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106a84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106a88: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x106a88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106a8c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x106a8cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x106a90: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x106a90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x106a94: 0x3e00008  jr          $ra
    ctx->pc = 0x106A94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A94u;
            // 0x106a98: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1068A8u: goto label_1068a8;
            case 0x1068E4u: goto label_1068e4;
            case 0x106900u: goto label_106900;
            case 0x106918u: goto label_106918;
            case 0x106920u: goto label_106920;
            case 0x106940u: goto label_106940;
            case 0x106964u: goto label_106964;
            case 0x106968u: goto label_106968;
            case 0x106980u: goto label_106980;
            case 0x10698Cu: goto label_10698c;
            case 0x1069ACu: goto label_1069ac;
            case 0x1069B8u: goto label_1069b8;
            case 0x1069C0u: goto label_1069c0;
            case 0x1069C4u: goto label_1069c4;
            case 0x106A00u: goto label_106a00;
            case 0x106A10u: goto label_106a10;
            case 0x106A48u: goto label_106a48;
            case 0x106A60u: goto label_106a60;
            case 0x106A68u: goto label_106a68;
            case 0x106A78u: goto label_106a78;
            case 0x106A7Cu: goto label_106a7c;
            case 0x106A80u: goto label_106a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106A9Cu;
    // 0x106a9c: 0x0  nop
    ctx->pc = 0x106a9cu;
    // NOP
    // 0x106aa0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x106aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x106aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x106AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106AA4u;
            // 0x106aa8: 0x244278d0  addiu       $v0, $v0, 0x78D0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30928));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1068A8u: goto label_1068a8;
            case 0x1068E4u: goto label_1068e4;
            case 0x106900u: goto label_106900;
            case 0x106918u: goto label_106918;
            case 0x106920u: goto label_106920;
            case 0x106940u: goto label_106940;
            case 0x106964u: goto label_106964;
            case 0x106968u: goto label_106968;
            case 0x106980u: goto label_106980;
            case 0x10698Cu: goto label_10698c;
            case 0x1069ACu: goto label_1069ac;
            case 0x1069B8u: goto label_1069b8;
            case 0x1069C0u: goto label_1069c0;
            case 0x1069C4u: goto label_1069c4;
            case 0x106A00u: goto label_106a00;
            case 0x106A10u: goto label_106a10;
            case 0x106A48u: goto label_106a48;
            case 0x106A60u: goto label_106a60;
            case 0x106A68u: goto label_106a68;
            case 0x106A78u: goto label_106a78;
            case 0x106A7Cu: goto label_106a7c;
            case 0x106A80u: goto label_106a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106AACu;
    // 0x106aac: 0x0  nop
    ctx->pc = 0x106aacu;
    // NOP
    // 0x106ab0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x106ab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x106ab4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x106ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106ab8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x106ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x106abc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x106abcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ac0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x106ac0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ac4: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x106ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106ac8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x106ac8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106acc: 0x8041a84  j           func_106A10
    ctx->pc = 0x106ACCu;
    ctx->pc = 0x106AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106ACCu;
            // 0x106ad0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106A10u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_106a10;
    ctx->pc = 0x106AD4u;
    // 0x106ad4: 0x0  nop
    ctx->pc = 0x106ad4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
