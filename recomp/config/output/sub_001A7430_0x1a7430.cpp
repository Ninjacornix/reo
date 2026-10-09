#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7430
// Address: 0x1a7430 - 0x1a7550
void sub_001A7430_0x1a7430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7430_0x1a7430");
#endif

    switch (ctx->pc) {
        case 0x1a7468u: goto label_1a7468;
        case 0x1a74f4u: goto label_1a74f4;
        default: break;
    }

    ctx->pc = 0x1a7430u;

    // 0x1a7430: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7430u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7434: 0x3c02007f  lui         $v0, 0x7F
    ctx->pc = 0x1a7434u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
    // 0x1a7438: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7438u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a743c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a743cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7440: 0x8c2c0a70  lw          $t4, 0xA70($at)
    ctx->pc = 0x1a7440u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2672)));
    // 0x1a7444: 0x34477f7f  ori         $a3, $v0, 0x7F7F
    ctx->pc = 0x1a7444u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32639);
    // 0x1a7448: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7448u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a744c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1a744cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a7450: 0x875824  and         $t3, $a0, $a3
    ctx->pc = 0x1a7450u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 4) & GPR_U64(ctx, 7));
    // 0x1a7454: 0x3c057f00  lui         $a1, 0x7F00
    ctx->pc = 0x1a7454u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32512 << 16));
    // 0x1a7458: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7458u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a745c: 0x8c2a0a68  lw          $t2, 0xA68($at)
    ctx->pc = 0x1a745cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7460: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1A7460u;
    {
        const bool branch_taken_0x1a7460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7460u;
            // 0x1a7464: 0x24420a80  addiu       $v0, $v0, 0xA80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7460) {
            ctx->pc = 0x1A74A8u;
            goto label_1a74a8;
        }
    }
    ctx->pc = 0x1A7468u;
label_1a7468:
    // 0x1a7468: 0x146b0008  bne         $v1, $t3, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A7468u;
    {
        const bool branch_taken_0x1a7468 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 11));
        ctx->pc = 0x1A746Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7468u;
            // 0x1a746c: 0x25830001  addiu       $v1, $t4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7468) {
            ctx->pc = 0x1A748Cu;
            goto label_1a748c;
        }
    }
    ctx->pc = 0x1A7470u;
    // 0x1a7470: 0x81e03  sra         $v1, $t0, 24
    ctx->pc = 0x1a7470u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 8), 24));
    // 0x1a7474: 0x14660003  bne         $v1, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A7474u;
    {
        const bool branch_taken_0x1a7474 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        if (branch_taken_0x1a7474) {
            ctx->pc = 0x1A7484u;
            goto label_1a7484;
        }
    }
    ctx->pc = 0x1A747Cu;
    // 0x1a747c: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1A747Cu;
    {
        const bool branch_taken_0x1a747c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A747Cu;
            // 0x1a7480: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a747c) {
            ctx->pc = 0x1A7538u;
            goto label_1a7538;
        }
    }
    ctx->pc = 0x1A7484u;
label_1a7484:
    // 0x1a7484: 0xad250000  sw          $a1, 0x0($t1)
    ctx->pc = 0x1a7484u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 5));
    // 0x1a7488: 0x25830001  addiu       $v1, $t4, 0x1
    ctx->pc = 0x1a7488u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
label_1a748c:
    // 0x1a748c: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A748Cu;
    {
        const bool branch_taken_0x1a748c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A748Cu;
            // 0x1a7490: 0x306c001f  andi        $t4, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 12, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a748c) {
            ctx->pc = 0x1A74A0u;
            goto label_1a74a0;
        }
    }
    ctx->pc = 0x1A7494u;
    // 0x1a7494: 0x11800002  beqz        $t4, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7494u;
    {
        const bool branch_taken_0x1a7494 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7494) {
            ctx->pc = 0x1A74A0u;
            goto label_1a74a0;
        }
    }
    ctx->pc = 0x1A749Cu;
    // 0x1a749c: 0x258cffe0  addiu       $t4, $t4, -0x20
    ctx->pc = 0x1a749cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967264));
label_1a74a0:
    // 0x1a74a0: 0x118a0009  beq         $t4, $t2, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A74A0u;
    {
        const bool branch_taken_0x1a74a0 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 10));
        ctx->pc = 0x1A74A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A74A0u;
            // 0x1a74a4: 0xa1840  sll         $v1, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a74a0) {
            ctx->pc = 0x1A74C8u;
            goto label_1a74c8;
        }
    }
    ctx->pc = 0x1A74A8u;
label_1a74a8:
    // 0x1a74a8: 0xc1840  sll         $v1, $t4, 1
    ctx->pc = 0x1a74a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x1a74ac: 0x6c1821  addu        $v1, $v1, $t4
    ctx->pc = 0x1a74acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x1a74b0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a74b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a74b4: 0x434821  addu        $t1, $v0, $v1
    ctx->pc = 0x1a74b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a74b8: 0x8d280000  lw          $t0, 0x0($t1)
    ctx->pc = 0x1a74b8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1a74bc: 0x501ffea  bgez        $t0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1A74BCu;
    {
        const bool branch_taken_0x1a74bc = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x1A74C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A74BCu;
            // 0x1a74c0: 0x1071824  and         $v1, $t0, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) & GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a74bc) {
            ctx->pc = 0x1A7468u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a7468;
        }
    }
    ctx->pc = 0x1A74C4u;
    // 0x1a74c4: 0xa1840  sll         $v1, $t2, 1
    ctx->pc = 0x1a74c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
label_1a74c8:
    // 0x1a74c8: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a74c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a74cc: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x1a74ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x1a74d0: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a74d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a74d4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a74d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a74d8: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1a74d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a74dc: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1a74dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a74e0: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A74E0u;
    {
        const bool branch_taken_0x1a74e0 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A74E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A74E0u;
            // 0x1a74e4: 0x41a3c  dsll32      $v1, $a0, 8 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a74e0) {
            ctx->pc = 0x1A74FCu;
            goto label_1a74fc;
        }
    }
    ctx->pc = 0x1A74E8u;
    // 0x1a74e8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a74e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a74ec: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A74ECu;
    SET_GPR_U32(ctx, 31, 0x1A74F4u);
    ctx->pc = 0x1A74F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A74ECu;
            // 0x1a74f0: 0x248420f0  addiu       $a0, $a0, 0x20F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A74F4u; }
        if (ctx->pc != 0x1A74F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A74F4u; }
        if (ctx->pc != 0x1A74F4u) { return; }
    }
    ctx->pc = 0x1A74F4u;
label_1a74f4:
    // 0x1a74f4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1A74F4u;
    {
        const bool branch_taken_0x1a74f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A74F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A74F4u;
            // 0x1a74f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a74f4) {
            ctx->pc = 0x1A7538u;
            goto label_1a7538;
        }
    }
    ctx->pc = 0x1A74FCu;
label_1a74fc:
    // 0x1a74fc: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a74fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7500: 0x8c240a68  lw          $a0, 0xA68($at)
    ctx->pc = 0x1a7500u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7504: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7504u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7508: 0x3c020800  lui         $v0, 0x800
    ctx->pc = 0x1a7508u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2048 << 16));
    // 0x1a750c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a750cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a7510: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1a7510u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1a7514: 0x24830001  addiu       $v1, $a0, 0x1
    ctx->pc = 0x1a7514u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a7518: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7518u;
    {
        const bool branch_taken_0x1a7518 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A751Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7518u;
            // 0x1a751c: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7518) {
            ctx->pc = 0x1A752Cu;
            goto label_1a752c;
        }
    }
    ctx->pc = 0x1A7520u;
    // 0x1a7520: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7520u;
    {
        const bool branch_taken_0x1a7520 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7520) {
            ctx->pc = 0x1A752Cu;
            goto label_1a752c;
        }
    }
    ctx->pc = 0x1A7528u;
    // 0x1a7528: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a752c:
    // 0x1a752c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a752cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7530: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7530u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7534: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7534u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7538:
    // 0x1a7538: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7538u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a753c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A753Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A753Cu;
            // 0x1a7540: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7468u: goto label_1a7468;
            case 0x1A7484u: goto label_1a7484;
            case 0x1A748Cu: goto label_1a748c;
            case 0x1A74A0u: goto label_1a74a0;
            case 0x1A74A8u: goto label_1a74a8;
            case 0x1A74C8u: goto label_1a74c8;
            case 0x1A74F4u: goto label_1a74f4;
            case 0x1A74FCu: goto label_1a74fc;
            case 0x1A752Cu: goto label_1a752c;
            case 0x1A7538u: goto label_1a7538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7544u;
    // 0x1a7544: 0x0  nop
    ctx->pc = 0x1a7544u;
    // NOP
    // 0x1a7548: 0x0  nop
    ctx->pc = 0x1a7548u;
    // NOP
    // 0x1a754c: 0x0  nop
    ctx->pc = 0x1a754cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
